// Copyright (C) RenZhai.2021.All Rights Reserved.

#include "Connetion/Core/SimpleConnetion.h"
#include "SocketSubsystem.h"
#include "Channel/SimpleChannel.h"
#include "Protocols/SimpleNetProtocols.h"
#include "Global/SimpleNetGlobalInfo.h"
#include "Log/SimpleNetChannelLog.h"
#include "SimpleNetManage.h"
#include "Core/EncryptionAndDecryption/SimpleEncryptionAndDecryption.h"
#include "Thread/SimpleNetThreadManage.h"

#if PLATFORM_WINDOWS
#pragma optimize("",off) 
#endif

FSimpleConnetion::FSimpleConnetion()
	:State(ESimpleConnetionLinkType::LINK_UNINITIALIZED)
	, Socket(NULL)
	, bLock(false)
	, HeartTime(0.0)
	, LastTime(0.0)
	, RequiredReconnectionTime(0.0)
	, TimeoutLink(0.0)
	, GroupID(INDEX_NONE)
	, Manage(nullptr)
{
	bIntoOutTime = false;
	bStopListen = true;

	ConnetionType = ESimpleConnetionType::CONNETION_LISTEN;

	Channels.SetNum(FSimpleNetGlobalInfo::Get()->GetInfo().MaxChannels);//Pre allocation strategy

	if (ISocketSubsystem* SocketSubsystem = GetSocketSubsystem())
	{
		LocalAddr = SocketSubsystem->CreateInternetAddr();
		RemoteAddr = SocketSubsystem->CreateInternetAddr();
	}
}

void FSimpleConnetion::SetConnetionType(ESimpleConnetionType InType)
{
	ConnetionType = InType;
}

void FSimpleConnetion::SetManage(FSimpleNetManage* InManage)
{
	Manage = InManage;
}

void FSimpleConnetion::GetChannelActiveID(TArray<FGuid>& InIDs)
{
	for(int32 i = 0;i < Channels.Num();i++)
	{
		if (Channels[i].IsValid())
		{
			InIDs.Add(Channels[i].GetGuid());
		}
	}
}

void FSimpleConnetion::Init()
{
	auto Init_Connetion = [&]()
	{
		for (auto& Tmp : Channels)
		{
			Tmp.SetConnetion(this->AsShared());
		}

		//Register the main channel first
		if (FSimpleChannel* MainChannel = GetMainChannel())
		{
			MainChannel->SpawnController();
			MainChannel->Init();
		}
	};


	if (IsInGameThread())
	{
		Init_Connetion();
	}
	else
	{
		FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([Init_Connetion]()
		{
			Init_Connetion();
		}, TStatId(), nullptr, ENamedThreads::GameThread);

		//等待主线程完成 功能性注册
		FTaskGraphInterface::Get().WaitUntilTaskCompletes(Task);
	}	
}

void FSimpleConnetion::Close()
{
	auto OnClose = [&]()
	{
		//Pre closing
		for (auto& Tmp : Channels)
		{
			Tmp.PreClose();
		}

		//Send broken link
		if (FSimpleChannel* Channel = GetMainChannel())
		{
			//Client request disconnect
			SIMPLE_PROTOCOLS_SEND(SP_Close)
		}

		UE_LOG(LogSimpleNetChannel,
			Display,
			TEXT("[Close] Connetion Close.Socket :[IP:%s Port:%d]"),
			*GetAddr()->ToString(false),
			GetAddr()->GetPort());

		HeartTime = 0.0;
		bHeartBeat = false;
		bIntoOutTime = false;

		//Turn off channels first
		for (auto& Tmp : Channels)
		{
			Tmp.Close();
		}

		State = ESimpleConnetionLinkType::LINK_UNINITIALIZED;

		//Release the last one
		if (ISocketSubsystem* SocketSubsystem = GetSocketSubsystem())
		{
			LocalAddr = SocketSubsystem->CreateInternetAddr();
		}

		if (Manage->IsHighConcurrency())
		{
			CloseSocket();
		}
	};

	if (IsInGameThread())
	{
		OnClose();
	}
	else
	{
		FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([this, OnClose]()
		{
			OnClose();
		},TStatId(), NULL, ENamedThreads::GameThread);

		FTaskGraphInterface::Get().WaitUntilTaskCompletes(Task);
	}
}

void FSimpleConnetion::Tick(float DeltaSeconds)
{
	for (auto &Tmp : Channels)
	{
		if (Tmp.IsValid())
		{
			Tmp.Tick(DeltaSeconds);
		}
	}

	//Time overflow
	if (LinkState == ESimpleNetLinkState::LINKSTATE_LISTEN)
	{
		if (ConnetionType == ESimpleConnetionType::CONNETION_LISTEN) //Non main channel
		{
			CheckTimeOut();
		}
	}
	else
	{
		if (State == ESimpleConnetionLinkType::LINK_JOIN)
		{
			if (bHeartBeat)
			{
				HeartTime += DeltaSeconds;
				if (HeartTime >= FSimpleNetGlobalInfo::Get()->GetInfo().HeartBeatTimeTnterval)
				{
					HeartTime = 0.0;

					SendHeartBeat();
				}
			}
		}
	}
}

void FSimpleConnetion::CheckLoginTimeout(float DeltaSeconds)
{
	if (LinkState == ESimpleNetLinkState::LINKSTATE_CONNET)
	{
		if (State != ESimpleConnetionLinkType::LINK_JOIN && //Is the connection successful
			State != ESimpleConnetionLinkType::LINK_UNINITIALIZED)//It's an empty one
		{
			RequiredReconnectionTime += DeltaSeconds;
			if (RequiredReconnectionTime >= FSimpleNetGlobalInfo::Get()->GetInfo().HeartBeatTimeTnterval)
			{
				RequiredReconnectionTime = 0.0;

				ConnectVerification();

				UE_LOG(LogSimpleNetChannel,
					Display,
					TEXT("Client trying to link [Hello] to the server[IP:%s Port:%i]."),
					*LocalAddr->ToString(false),
					LocalAddr->GetPort());
			}

			TimeoutLink += DeltaSeconds;
			if (TimeoutLink >= FSimpleNetGlobalInfo::Get()->GetInfo().OutTimeLink)
			{
				TimeoutLink = 0.0;

				FString ErrorString = FString::Printf(TEXT("The server is not responding,Maybe the link address is wrong or the server is wrong [IP:%s Port:%i]"),
					*LocalAddr->ToString(false),
					LocalAddr->GetPort());

				UE_LOG(LogSimpleNetChannel, Error, TEXT("%s"), *ErrorString);

				//Callback
				if (Manage)
				{
					Manage->LinkTimeout(ErrorString);
				}
			}
		}
		else
		{
			RequiredReconnectionTime = 0.0;
			TimeoutLink = 0.0;
		}
	}

}

void FSimpleConnetion::ActivateListen()
{
	FSimpleNetThreadManage::Get()->AddTask(FSimpleDelegate::CreateRaw(this,&FSimpleConnetion::Listen));
}

ISocketSubsystem* FSimpleConnetion::GetSocketSubsystem()
{
	return ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM);
}

TSharedRef<FInternetAddr> FSimpleConnetion::GetAddr()
{
	return LocalAddr.ToSharedRef();
}

TSharedRef<FInternetAddr> FSimpleConnetion::GetRemoteAddr()
{
	return RemoteAddr.ToSharedRef();
}

void FSimpleConnetion::StartSendHeartBeat()
{
	bHeartBeat = true;
}

void FSimpleConnetion::SendHeartBeat()
{
	if (FSimpleChannel* Channel = GetMainChannel())
	{
		if (Channel->IsValid())
		{
			SIMPLE_PROTOCOLS_SEND(SP_HeartBeat)

			if (FSimpleNetGlobalInfo::Get()->GetInfo().bPrintHeartBeat)
			{
				UE_LOG(LogSimpleNetChannel,
					Display,
					TEXT("[HeartBeat] Send heartbeat. Server [IP:%s Port:%d]"),
					*GetRemoteAddr()->ToString(false),
					GetRemoteAddr()->GetPort());
			}
		}
	}
}

void FSimpleConnetion::CheckTimeOut()
{
	double CurrentTime = FPlatformTime::Seconds();

	HeartBeatReadWrite.ReadLock();
	if (CurrentTime - LastTime > FSimpleNetGlobalInfo::Get()->GetInfo().OutTimeLink)
	{
		HeartBeatReadWrite.ReadUnlock();

		if (Manage->IsHighConcurrency())
		{
			if (!bIntoOutTime)
			{
				//因为超时而断开链接 给自己发一个关闭包 针对异步环境下 不要直接关闭确保那边受到关闭包再做决定
				if (FSimpleChannel* Channel = Manage->GetChannel())
				{
					uint32 OutAddr = 0;
					LocalAddr->GetIp(OutAddr);
					if (OutAddr == 0)
					{
						bool bIsValid = false;
						LocalAddr->SetIp(TEXT("127.0.0.1"), bIsValid);

						if (!bIsValid)
						{
							UE_LOG(LogSimpleNetChannel,
								Error,
								TEXT("Failed to set local address.127.0.0.1"));
						}
					}

					FString LocalAddrIPPortString = LocalAddr->ToString(true);

					UE_LOG(LogSimpleNetChannel,
						Display,
						TEXT("Preparing to close the current address:%s"),
						*LocalAddrIPPortString);

					SIMPLE_PROTOCOLS_SEND_ADDR(SP_Close, LocalAddr)

					//防止无限进入
					bIntoOutTime = true;
				}
			}	
		}
		else
		{
			Close();
		}
	}
	else
	{
		HeartBeatReadWrite.ReadUnlock();
	}
}

void FSimpleConnetion::Send(TArray<uint8>& InData)
{
	SimpleEncryptionAndDecryption::Encryption(InData);
}

void FSimpleConnetion::Send(TArray<uint8>& InData, TSharedPtr<FInternetAddr> InNewAddr)
{
	SimpleEncryptionAndDecryption::Encryption(InData);
}
//
//void FSimpleConnetion::Receive(const FGuid& InChannelID,TArray<uint8>& InData)
//{
//	for (auto &Tmp : Channels)
//	{
//		if (Tmp.IsValid())
//		{
//			if (Tmp.GetGuid() == InChannelID)
//			{
//				Tmp.AddMsg(InData);
//				break;
//			}
//		}
//	}
//}

void FSimpleConnetion::ResetHeartBeat()
{
	HeartBeatReadWrite.WriteLock();

	LastTime = FPlatformTime::Seconds();

	HeartBeatReadWrite.WriteUnlock();
}

void FSimpleConnetion::Analysis(uint8* InData, int32 BytesNumber)//Location of system resolution
{
	FSimpleBunchHead Head = *(FSimpleBunchHead*)InData;
	if (BytesNumber >= sizeof(FSimpleBunchHead))
	{
		//Update our upper business
		auto UpdateObject = [&]()
		{
			if (FSimpleChannel* Channel = GetChannel(Head.ChannelID))
			{
				FGuid NewMsgGuid = FGuid::NewGuid();
				if (Head.ParamNum > 0)
				{
					TArray<uint8> InNewData(InData, BytesNumber);
					Channel->AddMsg(NewMsgGuid,InNewData);
				}

				//方便提取和查询
				Channel->SetMsgQueueGuid(NewMsgGuid);

				if (GetLinkState() == ESimpleNetLinkState::LINKSTATE_LISTEN)
				{
					Channel->ResetTagBackups(Head.Tag);
					{
						Channel->RecvProtocol(Head.ProtocolsNumber);
					}
					Channel->ResetTagBackups(0ll);
				}
				else if (!Head.bAsynchronous)			
				{
					Channel->RemoveSynchronizeTag(Head.Tag);
				}
				else
				{
					Channel->RecvProtocol(Head.ProtocolsNumber);
				}
			}
		};

		if (GetLinkState() == ESimpleNetLinkState::LINKSTATE_LISTEN)
		{
			switch (Head.ProtocolsNumber)
			{
				case SP_PingRequest:
				{
					if (FSimpleChannel* Channel = GetMainChannel())
					{
						SIMPLE_PROTOCOLS_RECEIVE(SP_PingRequest);

						ESimpleNetManagePingType PingType = ESimpleNetManagePingType::OK;
						SIMPLE_PROTOCOLS_SEND(SP_PingResponse, PingType);
					}

					break;
				}
				case SP_HeartBeat:
				{
					ResetHeartBeat();

					if (FSimpleNetGlobalInfo::Get()->GetInfo().bPrintHeartBeat)
					{
						UE_LOG(LogSimpleNetChannel,
							Display,
							TEXT("[HeartBeat] Recv heartbeat. Client [IP:%s Port:%d]"),
							*GetAddr()->ToString(false),
							GetAddr()->GetPort());
					}

					break;
				}
				case SP_Close:
				{
					bStopListen = true;

					Close();
					
					break;
				}
				default:
				{
					UpdateObject();
					break;
				}
			}
		}
		else if (GetLinkState() == ESimpleNetLinkState::LINKSTATE_CONNET)
		{
			switch (Head.ProtocolsNumber)
			{
				case SP_HeartBeat:
				{

					break;
				}
				default:
				{
					//UE_LOG(LogSimpleNetChannel, Log, TEXT("recv %s byte"), BytesNumber);
					UpdateObject();
					break;
				}
			}
		}
	}
}

void FSimpleConnetion::SetState(ESimpleConnetionLinkType InState)
{
	State = InState;
}

void FSimpleConnetion::RequestSocketAddressRequest()
{
	if (FSimpleChannel* Channel = GetMainChannel())
	{
		SIMPLE_PROTOCOLS_SEND(SP_SocketAddressRequest);

		UE_LOG(LogSimpleNetChannel,
			Display,
			TEXT("The client sends [RequestSocketAddressRequest] to the server[IP:%s Port:%i]."),
			*GetRemoteAddr()->ToString(false),
			GetRemoteAddr()->GetPort());
	}
}

void FSimpleConnetion::ConnectVerification()
{
	if (FSimpleChannel *Channel = GetMainChannel())
	{
		FString LocalVersion = FSimpleNetGlobalInfo::Get()->GetInfo().Version;
		SIMPLE_PROTOCOLS_SEND(SP_Hello,LocalVersion);
		
		SetState(ESimpleConnetionLinkType::LINK_VERIFICATION);
		
		UE_LOG(LogSimpleNetChannel,
			Display,
			TEXT("The client sends [Hello] to the server[IP:%s Port:%i]."),
			*GetRemoteAddr()->ToString(false),
			GetRemoteAddr()->GetPort());
	}
}

void FSimpleConnetion::SetSocket(FSocket* InSocket)
{
	Socket = InSocket;
}

FSimpleChannel* FSimpleConnetion::GetMainChannel()
{
	if (Channels.IsValidIndex(0))
	{
		return &Channels[0];
	}

	return NULL;
}

FSimpleChannel* FSimpleConnetion::GetChannel(const FGuid& InChannelGuid)
{
	for (auto &Tmp : Channels)
	{
		if (Tmp.GetGuid() == InChannelGuid)
		{
			return &Tmp;
		}
	}

	return NULL;
}

void FSimpleConnetion::SetLinkState(ESimpleNetLinkState NewLinkState)
{
	LinkState = NewLinkState;
}

bool FSimpleConnetion::CloseSocket()
{
	CacheManage.Reset();

	return false;
}

void FSimpleConnetion::SetRemoteAddr(TSharedPtr<FInternetAddr> InAddr)
{
	RemoteAddr = InAddr;
}

void FSimpleConnetion::SetLocalAddr(TSharedPtr<FInternetAddr> InAddr)
{
	LocalAddr = InAddr;
}

bool FSimpleConnetion::IsCompletePackage(
	int32 InRecvNum,
	uint8* InData, 
	FGuid& OutGUID,
	uint8*& OutData, int32& OutLen)
{
	if (InRecvNum != 0)
	{
		bool bShowCompletePackProtocolInfo = FSimpleNetGlobalInfo::Get()->GetInfo().bShowCompletePackProtocolInfo;
		bool bSlidingWindow = FSimpleNetGlobalInfo::Get()->GetInfo().bSlidingWindow;
		if (bSlidingWindow)
		{
			FSimplePackageHead PackageHead = *(FSimplePackageHead*)InData;
			if (PackageHead.bForceSend)
			{
				if (FSimpleNetCacheManage::FCache* InCache = CacheManage.Find(PackageHead.PackageID))
				{
					CacheManage.Remove(PackageHead.PackageID);

					if (bShowCompletePackProtocolInfo)
					{
						UE_LOG(LogSimpleNetChannel, Display, TEXT("ForceRecv PackageID=%s"),
							*PackageHead.PackageID.ToString());
					}
				}
				else
				{
					//Remove the head
					CacheManage.Add(PackageHead.PackageID, FSimpleNetCacheManage::FCache());

					if (FSimpleNetCacheManage::FCache* InUPDCache = CacheManage.Find(PackageHead.PackageID))
					{
						int32 BoySize = InRecvNum - sizeof(FSimplePackageHead);
						InData += sizeof(FSimplePackageHead);
						int32 Pos = InUPDCache->Cache.AddUninitialized(BoySize);
						FMemory::Memcpy(&InUPDCache->Cache[Pos], InData, BoySize);
						OutData = InUPDCache->Cache.GetData();
						OutLen = InUPDCache->Cache.Num();
						OutGUID = PackageHead.PackageID;

						if (bShowCompletePackProtocolInfo)
						{
							UE_LOG(LogSimpleNetChannel, Display, TEXT("ForceRecv PackageID=%s RecvSize = %i BoySize = %i"),
								*PackageHead.PackageID.ToString(),
								InRecvNum,
								BoySize);
						}
					}
					else
					{
						UE_LOG(LogSimpleNetChannel, Error, TEXT("ForceRecv not found PackageID = %s "), *PackageHead.PackageID.ToString());
					}
				}
			}
			else
			{
				switch (PackageHead.Protocol)
				{
				case SP_HandshaketoSend:
				{
					PackageHead.Protocol = SP_ReadytoAccept;
					TArray<uint8> MyData;

					FSimpleIOStream IOStream(MyData);
					IOStream << PackageHead;

					//Create accepted cache pool
					CacheManage.Add(PackageHead.PackageID, FSimpleNetCacheManage::FCache());
					CacheManage[PackageHead.PackageID].TotalSize = PackageHead.PackageSize;

					Send(MyData);

					if (bShowCompletePackProtocolInfo)
					{
						UE_LOG(LogSimpleNetChannel, Display, TEXT("[SP_HandshaketoSend] PackageHead.PackageID=%s, ReadyRecv=%i"),
							*PackageHead.PackageID.ToString(),
							CacheManage[PackageHead.PackageID].TotalSize);
					}
					break;
				}
				case SP_ReadytoAccept:
				{
					if (FSimpleChannel* InChannel = GetChannel(PackageHead.ChannelID))
					{
						InChannel->SendBatch(PackageHead.PackageID, PackageHead.PackageIndex, SP_Recv);

						if (bShowCompletePackProtocolInfo)
						{
							UE_LOG(LogSimpleNetChannel, Display, TEXT("[SP_ReadytoAccept] PackageHead.ChannelID=%s,PackageHead.PackageIndex=%i"),
								*PackageHead.ChannelID.ToString(),
								PackageHead.PackageIndex);
						}
					}
					else
					{
						UE_LOG(LogSimpleNetChannel, Error, TEXT("[SP_ReadytoAccept] Not found PackageHead.ChannelID=%s"),
							*PackageHead.ChannelID.ToString());
					}

					break;
				}
				case SP_RecvComplete:
				{
					if (FSimpleChannel* InChannel = GetChannel(PackageHead.ChannelID))
					{
						InChannel->AcceptSuccess(PackageHead.PackageID, PackageHead.PackageIndex - 1, true, true);

						if (bShowCompletePackProtocolInfo)
						{
							UE_LOG(LogSimpleNetChannel, Display, TEXT("[SP_RecvComplete] PackageHead.ChannelID=%s,PackageHead.PackageIndex=%i"),
								*PackageHead.ChannelID.ToString(),
								PackageHead.PackageIndex);
						}
					}
					else
					{
						UE_LOG(LogSimpleNetChannel, Error, TEXT("[SP_RecvComplete] Not found PackageHead.ChannelID=%s"),
							*PackageHead.ChannelID.ToString());
					}

					break;
				}
				case SP_Send:
				{
					if (FSimpleChannel* InChannel = GetChannel(PackageHead.ChannelID))
					{
						//Last package accepted successfully
						InChannel->AcceptSuccess(PackageHead.PackageID, PackageHead.PackageIndex - 1, true);

						//Send the next packet
						InChannel->SendBatch(PackageHead.PackageID, PackageHead.PackageIndex, SP_Recv);

						if (bShowCompletePackProtocolInfo)
						{
							UE_LOG(LogSimpleNetChannel, Display, TEXT("[SP_Send] PackageHead.ChannelID=%s,PackageHead.PackageIndex=%i"),
								*PackageHead.ChannelID.ToString(),
								PackageHead.PackageIndex);
						}
					}
					else
					{
						UE_LOG(LogSimpleNetChannel, Error, TEXT("[SP_Send] Not found PackageHead.ChannelID=%s"),
							*PackageHead.ChannelID.ToString());
					}

					break;
				}
				case SP_Recv:
				{
					if (FSimpleNetCacheManage::FCache* InCache = CacheManage.Find(PackageHead.PackageID))
					{
						int32 InDataSize = InRecvNum - sizeof(FSimplePackageHead);
						int32 Pos = InCache->Cache.AddUninitialized(InDataSize);

						InData += sizeof(FSimplePackageHead);

						FMemory::Memcpy(&InCache->Cache[Pos], InData, InDataSize);

						TArray<uint8> MyData;
						if (InCache->Cache.Num() < (int32)InCache->TotalSize)//Representative data not accepted
						{
							//Continue sending
							PackageHead.Protocol = SP_Send;
							PackageHead.PackageIndex++;
						}
						else
						{
							PackageHead.Protocol = SP_RecvComplete;
							OutData = InCache->Cache.GetData();
							OutLen = InCache->Cache.Num();
							OutGUID = PackageHead.PackageID;
						}

						FSimpleIOStream IOStream(MyData);
						IOStream << PackageHead;

						Send(MyData);

						if (bShowCompletePackProtocolInfo)
						{
							UE_LOG(LogSimpleNetChannel, Display, TEXT("[SP_Recv] PackageHead.ChannelID=%s,PackageHead.PackageIndex=%i Protocol=%s"),
								*PackageHead.PackageID.ToString(),
								PackageHead.PackageIndex,
								PackageHead.Protocol == SP_Send ? TEXT("SP_Send") :
								PackageHead.Protocol == SP_RecvComplete ? TEXT("SP_RecvComplete") : TEXT("ERROR"));
						}
					}

					break;
				}
				}
			}
		}
		else
		{
			OutData = InData;
			OutLen = InRecvNum;
		}
	}

	return OutData != nullptr && OutLen != 0;
}

void FSimpleConnetion::HandleMergePackage(int32 InRecvNum, uint8* InData, TSharedPtr<FInternetAddr> InAddr)
{
	FGuid InGUID;
	uint8* NewRecvData = nullptr;
	int32 NewRecvLen = 0;
	if (IsCompletePackage(InRecvNum, InData, InGUID, NewRecvData, NewRecvLen))
	{
		if (State == ESimpleConnetionLinkType::LINK_JOIN)
		{
			Analysis(NewRecvData, NewRecvLen);//Analysis
		}
		else
		{
			VerificatioConnetionInfo(NewRecvData, NewRecvLen, InAddr);
		}
	}

	if (InGUID != FGuid())
	{
		if (Socket)
		{
			CacheManage.Remove(InGUID);
		}
	}
}

void FSimpleConnetion::VerificatioConnetionInfo(uint8* InData, int32 InByteNumber, TSharedPtr<FInternetAddr> InAddr)
{
	FSimpleBunchHead Head = *(FSimpleBunchHead*)InData;
	if (InByteNumber >= sizeof(FSimpleBunchHead))
	{
		if (FSimpleChannel* Channel = GetMainChannel())
		{
			if (Head.ParamNum > 0)
			{
				TArray<uint8> InNewData(InData, InByteNumber);

				FGuid InNewGuid = FGuid::NewGuid();

				Channel->SetMsgQueueGuid(InNewGuid);
				Channel->AddMsg(InNewGuid, InNewData);
			}

			if (LinkState == ESimpleNetLinkState::LINKSTATE_LISTEN)
			{
				switch (Head.ProtocolsNumber)
				{
				case SP_Hello:
				{
					FString RemoteVersion;
					SIMPLE_PROTOCOLS_RECEIVE(SP_Hello, RemoteVersion);
					if (!RemoteVersion.IsEmpty())
					{
						if (FSimpleNetGlobalInfo::Get()->GetInfo().Version == RemoteVersion)
						{
							SIMPLE_PROTOCOLS_SEND(SP_Challenge);
							SetState(ESimpleConnetionLinkType::LINK_VERIFICATION);

							//Reset heartbeat time
							ResetHeartBeat();

							UE_LOG(LogSimpleNetChannel,
								Display,
								TEXT("[Challenge] Version Verification succeeded. The server sent a challenge protocol. Client[IP:%s Port:%d]"),
								*GetRemoteAddr()->ToString(false),
								GetRemoteAddr()->GetPort());

							UE_LOG(LogSimpleNetChannel, Display,
								TEXT("[Challenge] Reset new hop time of client."));
						}
						else
						{
							FString Error = FString::Printf(TEXT("The server version is [%s] ,current client version is [%s]")
								, *(FSimpleNetGlobalInfo::Get()->GetInfo().Version), *RemoteVersion);

							SIMPLE_PROTOCOLS_SEND(SP_Upgrade, Error);
							Close();

							UE_LOG(LogSimpleNetChannel,
								Display,
								TEXT("[Challenge] %s. Client[IP:%s Port:%d]"),
								*Error,
								*GetRemoteAddr()->ToString(false),
								GetRemoteAddr()->GetPort());

							Manage->ExecuteNetManageMsgDelegate(ESimpleNetErrorType::HAND_SHAKE_FAIL, Error);
						}
					}
					else
					{
						FString Error = TEXT("The version passed by the client is empty .");
						SIMPLE_PROTOCOLS_SEND(SP_Upgrade, Error);
						Close();

						UE_LOG(LogSimpleNetChannel,
							Display,
							TEXT("[Challenge] %s. Client[IP:%s Port:%d]"),
							*Error,
							*GetRemoteAddr()->ToString(false),
							GetRemoteAddr()->GetPort());

						Manage->ExecuteNetManageMsgDelegate(ESimpleNetErrorType::HAND_SHAKE_FAIL, Error);
					}
					break;
				}
				case SP_Login:
				{
					TArray<FGuid> ChannelIDs;
					int32 NewGroupID = INDEX_NONE;
					SIMPLE_PROTOCOLS_RECEIVE(SP_Login, ChannelIDs, NewGroupID);
					if (ChannelIDs.Num() >= 1)
					{
						GetMainChannel()->SetGuid(ChannelIDs[0]);
						SetGroupID(NewGroupID);

						SetState(ESimpleConnetionLinkType::LINK_LOGIN);

						SIMPLE_PROTOCOLS_SEND(SP_Welcom);

						UE_LOG(LogSimpleNetChannel,
							Display,
							TEXT("[Welcom] Accept the login request sent by the client and pass the verification. \
The server sends a welcome message to the client. Client [IP:%s Port:%d]"),
*GetAddr()->ToString(false),
GetAddr()->GetPort());
					}
					else
					{
						FString Error = TEXT("Client ID is empty");
						SIMPLE_PROTOCOLS_SEND(SP_Failure, Error);

						Manage->ExecuteNetManageMsgDelegate(ESimpleNetErrorType::HAND_SHAKE_FAIL, Error);

						Close();
					}

					break;
				}
				case SP_Join:
				{
					SetState(ESimpleConnetionLinkType::LINK_JOIN);
					GetMainChannel()->InitController();

					if (!(Manage->IsHighConcurrency()))
					{
						SetRemoteAddr(InAddr);
					}

					UE_LOG(LogSimpleNetChannel,
						Display,
						TEXT("[Join] The current client joined successfully and began to prepare the business logic. Client [IP:%s Port:%d]"),
						*GetRemoteAddr()->ToString(false),
						GetRemoteAddr()->GetPort());

					Manage->ExecuteNetManageMsgDelegate(ESimpleNetErrorType::HAND_SHAKE_SUCCESS, TEXT(""));

					break;
				}
				case SP_PingRequest://针对服务器 接受ping的请求后处理
				{
					SIMPLE_PROTOCOLS_RECEIVE(SP_PingRequest);

					ESimpleNetManagePingType PingType = ESimpleNetManagePingType::UNREGISTERED;
					SIMPLE_PROTOCOLS_SEND(SP_PingResponse, PingType);

					break;
				}
				default:
					break;
				}
			}
			else if (LinkState == ESimpleNetLinkState::LINKSTATE_CONNET)
			{
				switch (Head.ProtocolsNumber)
				{
				case SP_Challenge:
				{
					TArray<FGuid> ChannelIDs;
					GetChannelActiveID(ChannelIDs);
					int32 InGroupID = GetGroupID();

					SIMPLE_PROTOCOLS_SEND(SP_Login, ChannelIDs, InGroupID);

					SetState(ESimpleConnetionLinkType::LINK_LOGIN);

					UE_LOG(LogSimpleNetChannel,
						Display,
						TEXT("[Login] Accept the server version Verification success, send login request to the server. Server [IP:%s Port:%d]"),
						*GetRemoteAddr()->ToString(false),
						GetRemoteAddr()->GetPort());

					break;
				}
				case SP_Welcom:
				{
					SetState(ESimpleConnetionLinkType::LINK_JOIN);

					SIMPLE_PROTOCOLS_SEND(SP_Join);

					if (!(Manage->IsHighConcurrency()))
					{
						SetRemoteAddr(InAddr);
					}

					//Send heartbeat
					StartSendHeartBeat();

					UE_LOG(LogSimpleNetChannel,
						Display,
						TEXT("[Join] The client receives the welcon message and starts to send heartbeat to the server and [join] request to the server. Server [IP:%s Port:%d]"),
						*GetRemoteAddr()->ToString(false),
						GetRemoteAddr()->GetPort());

					Manage->ExecuteNetManageMsgDelegate(ESimpleNetErrorType::HAND_SHAKE_SUCCESS, TEXT(""));

					break;
				}
				case SP_Upgrade:
				{
					FString ErrorMsg;
					SIMPLE_PROTOCOLS_RECEIVE(SP_Upgrade, ErrorMsg);
					UE_LOG(LogSimpleNetChannel, Error, TEXT("Server sends error message: %s"), *ErrorMsg);

					Manage->ExecuteNetManageMsgDelegate(ESimpleNetErrorType::HAND_SHAKE_FAIL, ErrorMsg);

					Close();
					break;
				}
				case SP_Failure:
				{
					FString ErrorMsg;
					SIMPLE_PROTOCOLS_RECEIVE(SP_Failure, ErrorMsg);
					UE_LOG(LogSimpleNetChannel, Error, TEXT("Server sends error message: %s"), *ErrorMsg);

					Manage->ExecuteNetManageMsgDelegate(ESimpleNetErrorType::HAND_SHAKE_FAIL, ErrorMsg);

					Close();
				}
				case SP_PingResponse://针对客户端 自己给自己一个通知
				{
					Channel->RecvProtocol(Head.ProtocolsNumber);
					break;
				}
				default:
					break;
				}
			}
		}
	}
}

void FSimpleConnetion::RecvByRemote(int32 InBytesSize, uint8* InData)
{
	SimpleEncryptionAndDecryption::Decryption(InData, InBytesSize);

	HandleMergePackage(InBytesSize,InData,RemoteAddr);
}

void FSimpleConnetion::Lock()
{
	bLock = true;
}

void FSimpleConnetion::UnLock()
{
	bLock = false;
}

#if PLATFORM_WINDOWS
#pragma optimize("",on) 
#endif