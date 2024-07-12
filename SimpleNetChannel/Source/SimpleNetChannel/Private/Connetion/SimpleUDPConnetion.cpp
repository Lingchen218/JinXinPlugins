// Copyright (C) RenZhai.2021.All Rights Reserved.

#include "SimpleUDPConnetion.h"
#include "Sockets.h"
#include "SocketSubsystem.h"
#include "Log/SimpleNetChannelLog.h"
#include "Global/SimpleNetGlobalInfo.h"
#include "SimpleNetManage.h"
#include "Protocols/SimpleNetProtocols.h"
#include "Core/EncryptionAndDecryption/SimpleEncryptionAndDecryption.h"

#if PLATFORM_WINDOWS
#pragma optimize("",off) 
#endif

void FSimpleUDPConnetion::ConnectVerification()
{
	Super::ConnectVerification();
}

void FSimpleUDPConnetion::Analysis(uint8* InData, int32 BytesNumber)
{
	Super::Analysis(InData, BytesNumber);
	//char* String = (char*)InData;
	
//	UE_LOG(LogSimpleNetChannel, Display, TEXT("Analysis Data = [%s],Number = [%i]"), UTF8_TO_TCHAR(String),BytesNumber);
}

void FSimpleUDPConnetion::Send(TArray<uint8>& InData, TSharedPtr<FInternetAddr> InNewAddr)
{
	//针对异步情况下 和主线程竞争发送资源
	FScopeLock SocketLock(&SocketMutex);

	FSimpleConnetion::Send(InData, InNewAddr);

	if (Socket)
	{
		int32 BytesSend = 0;
		if (Socket->SendTo(InData.GetData(), InData.Num(), BytesSend,*InNewAddr))
		{
			if (FSimpleNetGlobalInfo::Get()->GetInfo().bShowSendDebug)
			{
				UE_LOG(LogSimpleNetChannel, Display, TEXT("SendTo %i Bytes"), BytesSend);
			}	
		}
		else
		{
			UE_LOG(LogSimpleNetChannel, Error, TEXT(" Send Error!,Please check whether the peer address is correct"));
		}
	}
}

void FSimpleUDPConnetion::Send(TArray<uint8>& InData)
{
	Send(InData,GetRemoteAddr());
}

void FSimpleUDPConnetion::Listen()
{
	bool bInitRemoteAddr = false;
	while (Socket && !bStopListen && Manage)
	{
		if (!Socket)
		{
			bStopListen = true;
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
		ISocketSubsystem* SocketSubsystem = FSimpleConnetion::GetSocketSubsystem();
		TSharedPtr<FInternetAddr> InRemoteAddr = SocketSubsystem->CreateInternetAddr();
		bool bRecvFrom = Socket->RecvFrom(Data, RecvDataNumber, BytesRead, *InRemoteAddr);
		if (bRecvFrom)
		{
			if (bInitRemoteAddr)
			{
				//必须保证加入
				if (FSimpleNetManage::AddrEquation(RemoteAddr, InRemoteAddr))
				{
					RecvByRemote(BytesRead, Data);
				}
				else
				{
					UE_LOG(LogSimpleNetChannel,
						Error,
						TEXT("There is an illegal IP link. Client[IP:%s Port:%d]"),
						*InRemoteAddr->ToString(false),
						InRemoteAddr->GetPort());
				}
			}
			else
			{
				if (FSimpleChannel* Channel = GetMainChannel())
				{
					int32 PackageHeadSize = sizeof(FSimplePackageHead);

					FSimplePackageHead PackageHead = *(FSimplePackageHead*)Data;
					FSimpleBunchHead InHead = *(FSimpleBunchHead*)&Data[PackageHeadSize];

					FGuid InNewGuid = FGuid::NewGuid();
					Channel->SetMsgQueueGuid(InNewGuid);

					if (InHead.ParamNum > 0)
					{
						TArray<uint8> InNewData(&Data[PackageHeadSize], BytesRead - PackageHeadSize);

						Channel->AddMsg(InNewGuid, InNewData);
					}

					switch (PackageHead.Protocol)
					{
						case SP_BindingAddressRequest:
						{
							FSimpleAddr InLastKey;//用于验证
							SIMPLE_PROTOCOLS_RECEIVE(SP_BindingAddressRequest, InLastKey);

							if (TSharedPtr<FInternetAddr> InLastwRemoteAddr = FSimpleNetManage::GetInternetAddr(InLastKey))
							{
								if (FSimpleNetManage::AddrEquation(RemoteAddr, InLastwRemoteAddr))
								{
									//重置远端地址到新的客户端
									SetRemoteAddr(InRemoteAddr);

									SIMPLE_PROTOCOLS_SEND(SP_BindingAddressResponse);

									bInitRemoteAddr = true;

									UE_LOG(LogSimpleNetChannel,
										Display,
										TEXT("Address binding successful."));
								}
								else
								{
									UE_LOG(LogSimpleNetChannel,
										Error,
										TEXT("Error in obtaining server socket."));
								}
							}
							else
							{
								UE_LOG(LogSimpleNetChannel,
									Error,
									TEXT("Failed to obtain new address without establishing a valid link."));
							}

							break;
						}
						case SP_PingRequest:
						{
							SIMPLE_PROTOCOLS_RECEIVE(SP_PingRequest);

							ESimpleNetManagePingType PingType = ESimpleNetManagePingType::UNBOUND;
							SIMPLE_PROTOCOLS_SEND(SP_PingResponse, PingType);
						}
					}
				}
			}
		}
	}
}

FSocket *FSimpleUDPConnetion::CreateSocket(const uint32& InIP,uint32 &InPort,bool bBlocking)
{
	if (Manage)
	{
		ISocketSubsystem* SocketSubsystem = FSimpleConnetion::GetSocketSubsystem();
		if (!SocketSubsystem)
		{
			FString ErrorInfo = TEXT("Failed to create socketSubsystem.");
			Manage->ExecuteNetManageMsgDelegate(ESimpleNetErrorType::INIT_FAIL, ErrorInfo);
			UE_LOG(LogSimpleNetChannel, Error, TEXT("%s"), *ErrorInfo);

			return nullptr;
		}

		if (!CloseSocket())
		{
			//UE_LOG(LogSimpleNetChannel, Display, TEXT("Failed to close the socket. It may have been closed. This message can be ignored."));
		}

		Socket = SocketSubsystem->CreateSocket(NAME_DGram, TEXT("RenZhai"));
		if (!Socket)
		{
			FString ErrorInfo = TEXT("Failed to create Socket.");
			Manage->ExecuteNetManageMsgDelegate(ESimpleNetErrorType::INIT_FAIL, ErrorInfo);
			UE_LOG(LogSimpleNetChannel, Error, TEXT("%s"), *ErrorInfo);

			return nullptr;
		}

		int32 RecvSize = 0;
		int32 SendSize = 0;
		Socket->SetReceiveBufferSize(FSimpleNetGlobalInfo::Get()->GetInfo().RecvDataNumber, RecvSize);
		Socket->SetSendBufferSize(FSimpleNetGlobalInfo::Get()->GetInfo().SendDataNumber, SendSize);

		switch (Manage->GetLinkState())
		{
		case ESimpleNetLinkState::LINKSTATE_LISTEN://Server
		{
			if (InIP == 0)
			{
				bool bIsValid = false;

				//对于多网卡的环境下
				if (FSimpleNetGlobalInfo::Get()->GetInfo().URL.IsEmpty() ||
					FSimpleNetGlobalInfo::Get()->GetInfo().URL.Contains(TEXT("127.0.0.1")))
				{
					GetAddr()->SetAnyAddress();
				}
				else
				{
					GetAddr()->SetIp(*FSimpleNetGlobalInfo::Get()->GetInfo().URL, bIsValid);

					if (!bIsValid)
					{
						FString ErrorInfo = TEXT("IP binding error.");
						Manage->ExecuteNetManageMsgDelegate(ESimpleNetErrorType::INIT_FAIL, ErrorInfo);

						UE_LOG(LogSimpleNetChannel, Error, TEXT("%s"), *ErrorInfo);

						SocketSubsystem->DestroySocket(Socket);
						Socket = nullptr;

						return nullptr;
					}
				}			
			}
			else
			{
				GetAddr()->SetIp(InIP);
			}

			uint32 InNewPort = InPort == 0 ? (uint32)FSimpleNetGlobalInfo::Get()->GetInfo().Port : InPort;

			LocalAddr->SetPort(InNewPort);

			int32 BoundPort = SocketSubsystem->BindNextPort(Socket, *LocalAddr, 1, 1);
			if (!BoundPort)
			{
				FString ErrorInfo = TEXT("Server failed to bind port.");
				Manage->ExecuteNetManageMsgDelegate(ESimpleNetErrorType::INIT_FAIL, ErrorInfo);

				UE_LOG(LogSimpleNetChannel, Error, TEXT("%s"), *ErrorInfo);
				SocketSubsystem->DestroySocket(Socket);
				Socket = nullptr;

				return nullptr;
			}

			InPort = InNewPort;

			break;
		}
		case ESimpleNetLinkState::LINKSTATE_CONNET://Client
		{
			bool bBindAddr = false;
			if (InIP == 0)
			{
				GetRemoteAddr()->SetIp(*FSimpleNetGlobalInfo::Get()->GetInfo().URL, bBindAddr);
			}
			else
			{
				GetRemoteAddr()->SetIp(InIP);
			}

			GetRemoteAddr()->SetPort(InPort == 0 ? FSimpleNetGlobalInfo::Get()->GetInfo().Port : InPort);
			break;
		}
		}

		if (!Socket->SetNonBlocking(!bBlocking))
		{
			FString ErrorInfo = TEXT("Setting non blocking mode failed.");
			Manage->ExecuteNetManageMsgDelegate(ESimpleNetErrorType::INIT_FAIL, ErrorInfo);

			UE_LOG(LogSimpleNetChannel, Error, TEXT("%s"), *ErrorInfo);
			SocketSubsystem->DestroySocket(Socket);

			Socket = nullptr;

			return nullptr;
		}
	}

	bStopListen = false;

	return Socket;
}

bool FSimpleUDPConnetion::CloseSocket()
{
	Super::CloseSocket();

	FScopeLock SocketLock(&SocketMutex);

	ISocketSubsystem* SocketSubsystem = FSimpleConnetion::GetSocketSubsystem();
	if (!SocketSubsystem)
	{
		bStopListen = true;

		FString ErrorInfo = TEXT("Failed to create socketSubsystem.");

		Manage->ExecuteNetManageMsgDelegate(ESimpleNetErrorType::INIT_FAIL, ErrorInfo);

		UE_LOG(LogSimpleNetChannel, Error, TEXT("%s"), *ErrorInfo);

		return false;
	}

	if (Socket)
	{
		bStopListen = true;

		SocketSubsystem->DestroySocket(Socket);
		Socket = nullptr;

		return true;
	}

	return false;
}

int32 FSimpleUDPConnetion::ResetBindPort(uint32 &InPort, ISocketSubsystem* InSocketSubsystem)
{
	LocalAddr->SetPort(InPort);

	int32 BoundPort = InSocketSubsystem->BindNextPort(Socket, *LocalAddr, 1, 1);
	if (!BoundPort)
	{
		InPort++;
		return ResetBindPort(InPort, InSocketSubsystem);
	}

	return BoundPort;
}

//void FSimpleUDPConnetion::Receive(const FGuid& InChannelID, TArray<uint8>& InData)
//{
//	FSimpleConnetion::Receive(InChannelID, InData);
//}

#if PLATFORM_WINDOWS
#pragma optimize("",on) 
#endif