// Copyright (C) RenZhai.2021.All Rights Reserved.

#include "SimpleUDPManage.h"
#include "Connetion/SimpleUDPConnetion.h"
#include "Sockets.h"
#include "SocketSubsystem.h"
#include "Log/SimpleNetChannelLog.h"
#include "Global/SimpleNetGlobalInfo.h"
#include "Thread/SimpleNetThread.h"
#include "Thread/SimpleNetThreadManage.h"
#include "Protocols/SimpleNetProtocols.h"
#include "Core/EncryptionAndDecryption/SimpleEncryptionAndDecryption.h"

#if PLATFORM_WINDOWS
#pragma optimize("",off) 
#endif

FSimpleUDPManage::FSimpleUDPManage(ESimpleNetLinkState InType,bool bNewHighConcurrency)
	:Super()
{
	bHighConcurrency = bNewHighConcurrency;

	bAllowSynchronization = false;

	bEndThread = false;

	LinkState = InType;
}

bool FSimpleUDPManage::Init(int32 InPort)
{
	return Init(0, InPort);
}

bool FSimpleUDPManage::CloseSocket()
{
	ISocketSubsystem* SocketSubsystem = FSimpleConnetion::GetSocketSubsystem();
	if (!SocketSubsystem)
	{
		FString ErrorInfo = TEXT("Failed to create socketSubsystem.");
		NetManageMsgDelegate.ExecuteIfBound(ESimpleNetErrorType::INIT_FAIL, ErrorInfo);
		UE_LOG(LogSimpleNetChannel, Error, TEXT("%s"), *ErrorInfo);

		return false;
	}

	if (Net.LocalConnetion->GetSocket())
	{
		SocketSubsystem->DestroySocket(Net.LocalConnetion->GetSocket());
		Net.LocalConnetion->SetSocket(nullptr);

		return true;
	}

	return false;
}

bool FSimpleUDPManage::Init(const FString& InIP, uint32 InPort)
{
	ISocketSubsystem* SocketSubsystem = FSimpleConnetion::GetSocketSubsystem();
	if (SocketSubsystem)
	{
		auto NewAddrTmp = SocketSubsystem->CreateInternetAddr();

		bool bBindAddr = false;
		NewAddrTmp->SetIp(*InIP, bBindAddr);

		uint32 UintIP;
		NewAddrTmp->GetIp(UintIP);

		if (Init(UintIP, InPort))
		{
			if (IsAllowSynchronization())
			{
				MainNetThread = MakeShareable(new FSimpleNetThread(FSimpleDelegate::CreateRaw(this, &FSimpleUDPManage::Run)));
				MainNetThread->Trigger();
			}

			return true;
		}
	}

	return false;
}

bool FSimpleUDPManage::Init(uint32 InIP, uint32 InPort)
{
	if (Super::Init(InIP, InPort))
	{
		if (IsAllowSynchronization())
		{
			MainNetThread = MakeShareable(new FSimpleNetThread(FSimpleDelegate::CreateRaw(this, &FSimpleUDPManage::Run)));
			MainNetThread->Trigger();
		}

		return true;
	}

	return false;
}

void FSimpleUDPManage::Tick(float DeltaTime)//Both the client and the server listen for messages
{
	Super::Tick(DeltaTime);

	if (bInit) //Initialization completed
	{
		if (Net.LocalConnetion.IsValid())
		{
			if (Net.LocalConnetion->GetSocket())
			{
				//tick
				if (Net.LocalConnetion->GetState() == ESimpleConnetionLinkType::LINK_JOIN)
				{
					Net.LocalConnetion->Tick(DeltaTime);
				}
				else //Check whether the client times out
				{
					if (LinkState == ESimpleNetLinkState::LINKSTATE_CONNET)
					{
						Net.LocalConnetion->CheckLoginTimeout(DeltaTime);
					}
				}

				for (auto& Tmp : Net.RemoteConnetions)
				{
					if (Tmp->GetState() == ESimpleConnetionLinkType::LINK_JOIN)
					{
						Tmp->Tick(DeltaTime);
					}
				}

				if (!IsAllowSynchronization())
				{
					Listen();
				}
			}
		}
	}
}

void FSimpleUDPManage::Listen()
{
	if (!Net.LocalConnetion->GetSocket())
	{
		return;
	}

	int32 RecvDataNumber = FSimpleNetGlobalInfo::Get()->GetInfo().RecvDataNumber;
#if PLATFORM_WINDOWS || PLATFORM_MAC || PLATFORM_LINUX
	uint8 Data[8196 * 1024] = { 0 };
#elif /*PLATFORM_IOS || */PLATFORM_ANDROID
	uint8 Data[8196 * 10] = { 0 };
#else
	uint8 Data[8196 * 100] = { 0 };
#endif
	int32 BytesRead = 0;
	ISocketSubsystem* InSocketSubsystem = FSimpleConnetion::GetSocketSubsystem();
	TSharedPtr<FInternetAddr> RemoteAddr = InSocketSubsystem->CreateInternetAddr();
	bool bRecvFrom = Net.LocalConnetion->GetSocket()->RecvFrom(Data, RecvDataNumber, BytesRead, *RemoteAddr);
	if (bRecvFrom)
	{
		if (IsHighConcurrency())//高并发为主
		{
			if (FSimpleChannel* Channel = Net.LocalConnetion->GetMainChannel())
			{
				SimpleEncryptionAndDecryption::Decryption(Data, BytesRead);

				FSimplePackageHead PackageHead = *(FSimplePackageHead*)Data;
				FSimpleBunchHead InHead = *(FSimpleBunchHead*)&Data[sizeof(FSimplePackageHead)];

				if (!bClientLink)
				{
					FGuid InNewGuid = FGuid::NewGuid();
					Channel->SetMsgQueueGuid(InNewGuid);

					if (InHead.ParamNum > 0)
					{
						TArray<uint8> InNewData(&Data[sizeof(FSimplePackageHead)], BytesRead - sizeof(FSimplePackageHead));

						Channel->AddMsg(InNewGuid, InNewData);
					}
				}

				switch (PackageHead.Protocol)
				{
					case SP_SocketAddressRequest://请求一个UDPSocket 地址 (服务器) Socket在异步线程
					{
						SIMPLE_PROTOCOLS_RECEIVE(SP_SocketAddressRequest);

						if (TSharedPtr<FSimpleConnetion> NewConnetion = Net[RemoteAddr])//验证
						{
							UE_LOG(LogSimpleNetChannel,
								Error,
								TEXT("The address already exists and should not be connected. Client[IP:%s Port:%d]"),
								*RemoteAddr->ToString(false),
								RemoteAddr->GetPort());
						}
						else if (TSharedPtr<FSimpleConnetion> TmpConnetion = Net.GetEmptyConnetion(RemoteAddr))//获取一个新的空链接
						{
							uint32 PortCount = GetAvailPort();
							if (PortCount != 0)
							{
								//创建Socket
								if (FSocket* UDPSocket = TmpConnetion->CreateSocket(0, PortCount, true))
								{
									OpenPort(PortCount);

									FString PublicIP = FSimpleNetGlobalInfo::Get()->GetInfo().PublicIP;
									FSimpleAddr InSimpleAddr = FSimpleNetManage::GetSimpleAddr(*PublicIP, PortCount);

									FSimpleAddr InLastKey = FSimpleNetManage::GetSimpleAddr(RemoteAddr);

									//启动监听线程
									TmpConnetion->ActivateListen();

									SIMPLE_PROTOCOLS_SEND_ADDR(SP_SocketAddressResponse, RemoteAddr, InSimpleAddr, InLastKey);

									UE_LOG(LogSimpleNetChannel,
										Display,
										TEXT("Create a new Socket as a link. IP=%s,Port=%i"),
										*PublicIP, PortCount);
								}
								else
								{
									UE_LOG(LogSimpleNetChannel,
										Error,
										TEXT("Failed to create Socket [%i]. Client[IP:%s Port:%d]"), PortCount,
										*RemoteAddr->ToString(false),
										RemoteAddr->GetPort());
								}
							}
							else
							{
								UE_LOG(LogSimpleNetChannel,Error,TEXT("The available allocated ports are already full."));
							}
						}

						break;
					}
					case SP_SocketAddressResponse://客户端 Socket在主线程
					{
						FSimpleAddr InLinkSimpleAddr;
						FSimpleAddr InLastKey;//用于验证

						SIMPLE_PROTOCOLS_RECEIVE(SP_SocketAddressResponse, InLinkSimpleAddr, InLastKey);
						if (InLinkSimpleAddr.IP != 0, InLinkSimpleAddr.Port != 0)
						{
							uint32 NewPort = InLinkSimpleAddr.Port;
							if (FSocket* InNewUPDSocekt = Net.LocalConnetion->CreateSocket(
								InLinkSimpleAddr.IP,
								NewPort,
								false))
							{
								SIMPLE_PROTOCOLS_SEND(SP_BindingAddressRequest, InLastKey);

								UE_LOG(LogSimpleNetChannel,
									Display,
									TEXT("Bind the current address to the server."));
							}
							else
							{
								UE_LOG(LogSimpleNetChannel,
									Error,
									TEXT("Link server error."));
							}
						}
						else
						{
							UE_LOG(LogSimpleNetChannel,
								Error,
								TEXT("Error in obtaining server socket."));
						}

						break;
					}
					case SP_BindingAddressResponse:
					{
						SIMPLE_PROTOCOLS_RECEIVE(SP_BindingAddressResponse);

						//向服务器发送Hello
						Net.LocalConnetion->ConnectVerification();

						bClientLink = true;

						break;
					}
					default://只针对客户端
					{
						if (LinkState == ESimpleNetLinkState::LINKSTATE_CONNET) //The client can parse the data directly
						{
							Net.LocalConnetion->HandleMergePackage(BytesRead, Data, RemoteAddr);
						}

						break;
					}
				};
			}
		}
		else
		{
			if (LinkState == ESimpleNetLinkState::LINKSTATE_LISTEN)
			{
				if (TSharedPtr<FSimpleConnetion> NewConnetion = Net[RemoteAddr])
				{	
					NewConnetion->HandleMergePackage(BytesRead, Data, RemoteAddr);
				}
				else
				{
					if (TSharedPtr<FSimpleConnetion> TmpConnetion = Net.GetEmptyConnetion(RemoteAddr))
					{
						TmpConnetion->HandleMergePackage(BytesRead, Data, RemoteAddr);
					}
					else
					{
						UE_LOG(LogSimpleNetChannel,
							Error,
							TEXT("The number of connections is full. Client[IP:%s Port:%d]"),
							*RemoteAddr->ToString(false),
							RemoteAddr->GetPort());
					}
				}
			}
			else if (LinkState == ESimpleNetLinkState::LINKSTATE_CONNET) //The client can parse the data directly
			{
				Net.LocalConnetion->HandleMergePackage(BytesRead, Data, RemoteAddr);
			}
		}	
	}
}

//#include "SocketTypes.h"
//iocp
void FSimpleUDPManage::Close()
{
	bEndThread = true;

	Super::Close();

	if (Net.LocalConnetion->GetSocket())
	{
		if (ISocketSubsystem* SocketSubsystem = FSimpleConnetion::GetSocketSubsystem())
		{
			Net.LocalConnetion->GetSocket()->Shutdown(ESocketShutdownMode::ReadWrite);

			SocketSubsystem->DestroySocket(Net.LocalConnetion->GetSocket());
			Net.LocalConnetion->SetSocket(nullptr);
		}
	}
}

void FSimpleUDPManage::Close(const FSimpleAddrInfo& InCloseConnetion)
{
	Super::Close(InCloseConnetion);

}

void FSimpleUDPManage::ResetLocalConnetion()
{
	Net.LocalConnetion = MakeShareable(new FSimpleUDPConnetion());
	Net.LocalConnetion->SetConnetionType(ESimpleConnetionType::CONNETION_MAIN_LISTEN);
	Net.LocalConnetion->SetManage(this);
}

void FSimpleUDPManage::Run()
{
	while (!bEndThread)
	{
		Listen();

		FPlatformProcess::Sleep(0.03f);
	}
}

TSharedPtr<FSimpleConnetion> FSimpleUDPManage::CreateConnetion() const
{
	return MakeShareable(new FSimpleUDPConnetion());
}

#if PLATFORM_WINDOWS
#pragma optimize("",on) 
#endif
