// Copyright (C) RenZhai.2021.All Rights Reserved.

#include "Channel/SimpleChannel.h"
#include "Connetion/Core/SimpleConnetion.h"
#include "UObject/SimpleController.h"
#include "UObject/SimplePlayer.h"
#include "SocketSubsystem.h"
#include "Global/SimpleNetGlobalInfo.h"
#include "Protocols/SimpleNetProtocols.h"
#include "Log/SimpleNetChannelLog.h"
#include "Async/TaskGraphInterfaces.h"

 FSimpleReturnDelegate FSimpleChannel::SimpleControllerDelegate;
 FSimpleReturnDelegate FSimpleChannel::SimplePlayerDelegate;

#if PLATFORM_WINDOWS
#pragma optimize("",off) 
#endif

FSimpleChannel::FSimpleChannel()
{
	TagBackups = 0;
}

void FSimpleChannel::Init()
{

}

void FSimpleChannel::PreClose()
{
	if (Object.IsValid())
	{
		Object->Close();
	}
}

void FSimpleChannel::Close()
{	
	if (Object.IsValid())
	{
		Object->MarkAsGarbage();
		Object.Reset();
		Object = NULL;
	}

	ID = FGuid();
	BatchManage.Reset();
	BatchPackageManage.Reset();
}

void FSimpleChannel::Send(TArray<uint8>& InData, TSharedPtr<FInternetAddr> InNewAddr, bool bForceSend)
{
	if (ConnetionPtr.IsValid())
	{
		if (InData.Num())
		{
			FSimpleBunchHead *HeadPtr = (FSimpleBunchHead*)InData.GetData();
			if (!HeadPtr->bAsynchronous)
			{
				if (TagBackups != 0)
				{
					HeadPtr->Tag = TagBackups;
				}
			}

			FSimpleBunchHead Head = *HeadPtr;

			TArray<uint8> OutData;
			BuildBytes(InData, OutData, bForceSend);

			if (OutData.Num() > 0)
			{
				ConnetionPtr.Pin()->Send(OutData, InNewAddr);

				if (TagBackups != 0)//如果不等于零 说明是被发送方
				{
					//如果不等于零 代表它是接受方 无需等待
					TagBackups = 0;
				}
				else if (!Head.bAsynchronous)//如果执行到这里，代表是发送方
				{
					uint64 InTag = Head.Tag;

					SynchronizeTag.Add(InTag);
					
					FDateTime LastDataTime = FDateTime::Now();

					bool bBreakCheck = false;
					while (SynchronizeTag.Contains(InTag) && !bBreakCheck)
					{
						FPlatformProcess::Sleep(0.03f);

						FDateTime CurrentDataTime = FDateTime::Now();
						FDateTime TimeInterval = CurrentDataTime.GetTicks() - LastDataTime.GetTicks();
					
						float WaitSecond =(float)TimeInterval.GetSecond();
						if (WaitSecond >= FSimpleNetGlobalInfo::Get()->GetInfo().OutTimeSynchronizationTime)
						{
							bBreakCheck = true;
						}
					}

					SynchronizeTag.Remove(InTag);
				}		
			}
			else
			{
				ensure(0);//不应该走这里
			}
		}
	}
}

void FSimpleChannel::Send(TArray<uint8>& InData, bool bForceSend)
{
	if (ConnetionPtr.IsValid())
	{
		Send(InData, ConnetionPtr.Pin()->GetRemoteAddr(), bForceSend);
	}
}

bool FSimpleChannel::Receive(TArray<uint8>& InData)
{
	return BatchPackageManage.Receive(InData);
}

TSharedPtr<FInternetAddr> FSimpleChannel::GetLocalAddr() const
{
	return ConnetionPtr.Pin()->GetAddr();
}

TSharedPtr<FInternetAddr> FSimpleChannel::GetRemoteAddr() const
{
	return ConnetionPtr.Pin()->GetRemoteAddr();
}

void FSimpleChannel::AddMsg(const FGuid& InGuid, TArray<uint8>& InData)
{
	BatchPackageManage.Add(InGuid, InData);
}

void FSimpleChannel::InitController()
{
	if (GetNetObject())
	{
		if (IsInGameThread())
		{
			GetNetObject()->Init();
		}
		else
		{
			FFunctionGraphTask::CreateAndDispatchWhenReady([&]()
			{
				GetNetObject()->Init();
			}, TStatId(), NULL, ENamedThreads::GameThread);
		}
	}
}

USimpleNetworkObject* FSimpleChannel::GetNetObject()
{
	return Object.Get();
}

void FSimpleChannel::SpawnController()
{
	if (ConnetionPtr.IsValid())
	{
		if (ConnetionPtr.Pin()->GetManage()->NetworkObjectClass)
		{
			RegisterObject(ConnetionPtr.Pin()->GetManage()->NetworkObjectClass, USimpleController::StaticClass());
		}
		else
		{
			RegisterObject(SimpleControllerDelegate, USimpleController::StaticClass());
		}
	}
	else
	{
		RegisterObject(SimpleControllerDelegate, USimpleController::StaticClass());
	}
	
	ID = FGuid::NewGuid();
}

void FSimpleChannel::SpawnPlayer()
{
	auto SpawnMyObject = [&]()
	{
		if (ConnetionPtr.IsValid())
		{
			if (ConnetionPtr.Pin()->GetManage()->SimplePlayerClass)
			{
				RegisterObject(ConnetionPtr.Pin()->GetManage()->SimplePlayerClass, USimplePlayer::StaticClass());
			}
			else
			{
				RegisterObject(SimplePlayerDelegate, USimplePlayer::StaticClass());
			}
		}
		else
		{
			RegisterObject(SimplePlayerDelegate, USimplePlayer::StaticClass());
		}
	};

	if (IsInGameThread())
	{
		SpawnMyObject();
	}
	else
	{
		FFunctionGraphTask::CreateAndDispatchWhenReady([SpawnMyObject]()
		{
			SpawnMyObject();
		}, TStatId(), nullptr, ENamedThreads::GameThread);
	}
	
	ID = FGuid::NewGuid();
}

bool FSimpleChannel::GetLocalAddrInfo(FSimpleAddrInfo& InAddrInfo)
{
	if (ConnetionPtr.IsValid())
	{
		uint32 MyIP = 0;
		ConnetionPtr.Pin()->GetAddr()->GetIp(MyIP);
		InAddrInfo.Addr.IP = MyIP;

		InAddrInfo.Addr.Port = ConnetionPtr.Pin()->GetAddr()->GetPort();
		InAddrInfo.ChannelID = GetGuid();
		
		return true;
	}

	return false;
}

bool FSimpleChannel::GetRemoteAddrInfo(FSimpleAddrInfo& InAddrInfo)
{
	if (ConnetionPtr.IsValid())
	{
		uint32 MyIP = 0;
		ConnetionPtr.Pin()->GetRemoteAddr()->GetIp(MyIP);
		InAddrInfo.Addr.IP = MyIP;

		InAddrInfo.Addr.Port = ConnetionPtr.Pin()->GetRemoteAddr()->GetPort();
		InAddrInfo.ChannelID = GetGuid();

		return true;
	}

	return false;
}

USimpleNetworkObject* FSimpleChannel::SpawnObject(UClass* InClass)
{
	if (USimpleNetworkObject *InObject = NewObject<USimpleNetworkObject>(InClass, InClass))
	{
		return InObject;
	}

	return NULL;
}

void FSimpleChannel::RegisterObject(UClass* InClass, UClass* InObjectClass)
{
	if (Object.IsValid())
	{
		Close();
	}

	if (InClass)
	{
		Object = TStrongObjectPtr<USimpleNetworkObject>(SpawnObject(InClass));
	}
	else
	{
		Object = TStrongObjectPtr<USimpleNetworkObject>(SpawnObject(InObjectClass));
	}

	if (Object.IsValid())
	{
		Object->LinkState = ConnetionPtr.Pin()->GetLinkState();
		Object->Channel = this;
	}
}

void FSimpleChannel::RegisterObject(FSimpleReturnDelegate InDelegate, UClass* InObjectClass)
{
	if (InDelegate.IsBound())
	{
		RegisterObject(InDelegate.Execute(), InObjectClass);
	}
	else
	{
		RegisterObject(NULL, InObjectClass);
	}
}

bool FSimpleChannel::IsValid() const
{
	return ID != FGuid();
}

void FSimpleChannel::AcceptSuccess(const FGuid& InDataID, uint32 InIndex, bool bAck, bool bAllSuccessful)
{
	if (FSimpleNetBatchManage::FBatch *InBatch = BatchManage.Find(InDataID))
	{
		if (bAllSuccessful)
		{
			InBatch->bAck = true;
		}
		else
		{
			if (FSimpleNetBatchManage::FBatch::FElement *Element = InBatch->Sequence.Find(InIndex))
			{
				Element->bAck = bAck;
			}
		}
	}
}

void FSimpleChannel::SendBatch(const FGuid& InDataID, uint32 InIndex, uint32 InProtocol)
{
	if (ConnetionPtr.IsValid())
	{
		if (FSimpleNetBatchManage::FBatch* InBatch = BatchManage.Find(InDataID))
		{
			if (FSimpleNetBatchManage::FBatch::FElement* Element = InBatch->Sequence.Find(InIndex))
			{
				FSimplePackageHead *PackageHead = (FSimplePackageHead*)Element->Package.GetData();
				PackageHead->Protocol = InProtocol;

				ConnetionPtr.Pin()->Send(Element->Package);

				//Enable patch detection
				Element->bStartUpRepackaging = true;
			}
		}
	}
}

void FSimpleChannel::BuildBytes(TArray<uint8>& InBytes, TArray<uint8>& OutBytes, bool bForceSend)
{
	if (InBytes.Num())
	{
		if (FSimpleNetGlobalInfo::Get()->GetInfo().bSlidingWindow)
		{
			int32 SendDataNumber = FSimpleNetGlobalInfo::Get()->GetInfo().SendDataNumber;
			FSimpleBunchHead* Head = (FSimpleBunchHead*)InBytes.GetData();
			FSimplePackageHead PackageHead;

			PackageHead.Protocol = Head->ProtocolsNumber;
			PackageHead.PackageSize = InBytes.Num();
			PackageHead.ChannelID = Head->ChannelID;
			PackageHead.Tag = Head->Tag;

			if (!bForceSend)
			{
				BatchManage.Add(PackageHead.PackageID, FSimpleNetBatchManage::FBatch());
				FSimpleNetBatchManage::FBatch& Batch = BatchManage[PackageHead.PackageID];

				PackageHead.Protocol = SP_HandshaketoSend;

				OutBytes.Empty();

				int32 HeadSize = sizeof(FSimplePackageHead);

				OutBytes.AddUninitialized(HeadSize);

				FMemory::Memcpy(OutBytes.GetData(), &PackageHead, HeadSize);

				//包体过大开始拆分
				if (InBytes.Num() > SendDataNumber)
				{
					int32 BatchsNumber = FMath::CeilToInt((float)InBytes.Num() / (float)SendDataNumber);
					int32 LastNumber = BatchsNumber - 1;
					for (int32 i = 0; i < BatchsNumber; i++)
					{
						PackageHead.PackageIndex = i;

						Batch.Sequence.Add(i, FSimpleNetBatchManage::FBatch::FElement());
						FSimpleNetBatchManage::FBatch::FElement& Tmp = Batch.Sequence[i];

						Tmp.Package.AddUninitialized(sizeof(FSimplePackageHead));
						FMemory::Memcpy(Tmp.Package.GetData(), &PackageHead, sizeof(FSimplePackageHead));
						if (i == LastNumber)
						{
							int32 Surplus = InBytes.Num() - SendDataNumber * LastNumber;
							int32 Pos = Tmp.Package.AddUninitialized(Surplus);

							FMemory::Memcpy(&Tmp.Package[Pos], &InBytes[LastNumber * SendDataNumber], Surplus);
						}
						else
						{
							int32 Pos = Tmp.Package.AddUninitialized(SendDataNumber);
							FMemory::Memcpy(&Tmp.Package[Pos], &InBytes[i * SendDataNumber], SendDataNumber);
						}
					}
				}
				else
				{
					Batch.Sequence.Add(0, FSimpleNetBatchManage::FBatch::FElement());
					FSimpleNetBatchManage::FBatch::FElement& Tmp = Batch.Sequence[0];

					Tmp.Package.AddUninitialized(sizeof(FSimplePackageHead));
					FMemory::Memcpy(Tmp.Package.GetData(), &PackageHead, sizeof(FSimplePackageHead));

					int32 Pos = Tmp.Package.AddUninitialized(InBytes.Num());
					FMemory::Memcpy(&Tmp.Package[Pos], InBytes.GetData(), InBytes.Num());
				}
			}
			else
			{
				PackageHead.bForceSend = true;

				int32 PackageHeadSize = sizeof(FSimplePackageHead);

				int32 Pos = OutBytes.AddUninitialized(sizeof(FSimplePackageHead));
				FMemory::Memcpy(OutBytes.GetData(), &PackageHead, sizeof(FSimplePackageHead));

				Pos = OutBytes.AddUninitialized(InBytes.Num());
				FMemory::Memcpy(&OutBytes[Pos], InBytes.GetData(), InBytes.Num());
			}
		}
		else
		{
			OutBytes = MoveTemp(InBytes);
		}
	}
}

bool FSimpleChannel::RemoveSynchronizeTag(uint64 InNewTags)
{
	if (SynchronizeTag.Contains(InNewTags))
	{
		SynchronizeTag.Remove(InNewTags);

		return true;
	}

	return false;
}

void FSimpleChannel::Tick(float DeltaSeconds)
{
	BatchManage.Tick(DeltaSeconds);

	BatchPackageManage.Tick(DeltaSeconds);

	if (Object.IsValid())
	{
		Object->Tick(DeltaSeconds);
	}
}

void FSimpleChannel::RecvProtocol(uint32 InProtocolsNumber)
{
	if (Object.IsValid())
	{
		Object->RecvProtocol(InProtocolsNumber);
	}
}

const FGuid& FSimpleChannel::GetGuid() const
{
	return ID;
}

void FSimpleChannel::DestroySelf()
{
	ConnetionPtr.Pin()->Close();
}

void FSimpleChannel::SetGuid(const FGuid& NewGuid)
{
	ID = NewGuid;
}

void FSimpleChannel::SetMsgQueueGuid(const FGuid& InNewGuid)
{
	BatchPackageManage.SetMsgQueueGuid(InNewGuid);
}

void FSimpleChannel::SetConnetion(TWeakPtr<FSimpleConnetion> InConnetion)
{
	ConnetionPtr = InConnetion;

	BatchManage.SetConnetion(InConnetion);
}

TSharedPtr<FSimpleConnetion > FSimpleChannel::GetConnetion()
{
	return ConnetionPtr.Pin();
}

#if PLATFORM_WINDOWS
#pragma optimize("",on) 
#endif

