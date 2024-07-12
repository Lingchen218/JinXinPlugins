#include "Cache/SimpleNetMsgBatchPackageManage.h"
#include "Misc/ScopeLock.h"

FSimpleNetMsgBatchPackageManage::FSimpleNetMsgBatchPackageManage()
{
}

FSimpleNetMsgBatchPackageManage::~FSimpleNetMsgBatchPackageManage()
{
}

void FSimpleNetMsgBatchPackageManage::SetConnetion(TWeakPtr<FSimpleConnetion> InConnetionPtr)
{
}

void FSimpleNetMsgBatchPackageManage::Tick(float DeltaSeconds)
{
	{
		FScopeLock ScopeLock(&ThreadCritical);

		TArray<FGuid> RemoveOutTimeQueue;
		for (auto& Tmp : MsgQueue)
		{
			Tmp.Value.Tick(DeltaSeconds);

			if (Tmp.Value.bOutTime)
			{
				RemoveOutTimeQueue.Add(Tmp.Key);
			}
		}

		for (auto& Tmp : RemoveOutTimeQueue)
		{
			MsgQueue.Remove(Tmp);
		}
	}
}

void FSimpleNetMsgBatchPackageManage::Add(const FGuid& InGuid, TArray<uint8>& InData)
{
	FScopeLock ScopeLock(&ThreadCritical);

	MsgQueue.Add(InGuid, FMsgBatchPackage());

	FMsgBatchPackage& InBatchPackage = MsgQueue[InGuid];
	InBatchPackage.Data = MoveTemp(InData);
}

bool FSimpleNetMsgBatchPackageManage::Receive(TArray<uint8>& InData)
{
	FScopeLock ScopeLock(&ThreadCritical);

	//check(MsgQueueGuid.IsValid());

	if (FMsgBatchPackage* InBatchPackage = MsgQueue.Find(MsgQueueGuid))
	{
		InData = MoveTemp(InBatchPackage->Data);
		MsgQueue.Remove(MsgQueueGuid);

		return true;
	}

	return false;
}

void FSimpleNetMsgBatchPackageManage::Reset()
{
	FScopeLock ScopeLock(&ThreadCritical);

	MsgQueue.Empty();
}

void FSimpleNetMsgBatchPackageManage::SetMsgQueueGuid(const FGuid& InNewGuid)
{
	MsgQueueGuid = InNewGuid;
}

FSimpleNetMsgBatchPackageManage::FMsgBatchPackage::FMsgBatchPackage()
{
	CurrentTime = 0.f;
	bOutTime = false;
}

void FSimpleNetMsgBatchPackageManage::FMsgBatchPackage::Tick(float DeltaSeconds)
{
	if (!bOutTime)
	{
		CurrentTime += DeltaSeconds;
		if (CurrentTime >= 10.f)
		{
			bOutTime = true;
		}
	}
}