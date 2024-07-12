#include "Cache/SimpleNetBatchManage.h"
#include "Log/SimpleNetChannelLog.h"
#include "Global/SimpleNetGlobalInfo.h"
#include "Connetion/Core/SimpleConnetion.h"
#include "Misc/ScopeLock.h"

FSimpleNetBatchManage::FSimpleNetBatchManage()
{
}

FSimpleNetBatchManage::~FSimpleNetBatchManage()
{
}

void FSimpleNetBatchManage::SetConnetion(TWeakPtr<FSimpleConnetion> InConnetionPtr)
{
	ConnetionPtr = InConnetionPtr;
}

void FSimpleNetBatchManage::Tick(float DeltaSeconds)
{
	FScopeLock ScopeLock(&BatchsReadWrite);

	if (ConnetionPtr.IsValid())
	{
		TArray<FGuid> RemoveBatchID;
		
		for (auto& Tmp : Batchs)
		{
			if (Tmp.Value.bAck)
			{
				RemoveBatchID.Add(Tmp.Key);
			}
			else
			{
				if (FSimpleNetGlobalInfo::Get()->GetInfo().bRepackaging)
				{
					for (auto& TmpSequence : Tmp.Value.Sequence)
					{
						//Do you want to start the packet replenishment test
						if (TmpSequence.Value.bStartUpRepackaging)
						{
							//Do you complete the repackaging
							if (!TmpSequence.Value.bAck)
							{
								TmpSequence.Value.CurrentTime += DeltaSeconds;
								if (TmpSequence.Value.CurrentTime >= FSimpleNetGlobalInfo::Get()->GetInfo().RepackagingTime)
								{
									TmpSequence.Value.CurrentTime = 0.f;
									TmpSequence.Value.RepeatCount++;

									//Repackaging
									ConnetionPtr.Pin()->Send(TmpSequence.Value.Package);

									if (TmpSequence.Value.RepeatCount >= FSimpleNetGlobalInfo::Get()->GetInfo().RepackagingFrequency)
									{
										//Start cleaning to prevent protocol attacks
										Tmp.Value.bAck = true;

										UE_LOG(LogSimpleNetChannel, Error, TEXT("Unable to get client acceptance confirmation,Please check whether the local sending buffer is too large, or the opposite receiving buffer is too small, or whether the other party is offline."));
										break;
									}
								}
							}
						}
					}
				}
			}
		}

		for (auto& Tmp : RemoveBatchID)
		{
			Batchs.Remove(Tmp);
		}
	}
}

void FSimpleNetBatchManage::Add(const FGuid& InGuid, const FSimpleNetBatchManage::FBatch& InCache)
{
	FScopeLock ScopeLock(&BatchsReadWrite);

	Batchs.Add(InGuid, InCache);
}

FSimpleNetBatchManage::FBatch* FSimpleNetBatchManage::Find(const FGuid& InGuid)
{
	FScopeLock ScopeLock(&BatchsReadWrite);

	FSimpleNetBatchManage::FBatch* InBatch = nullptr;

	InBatch = Batchs.Find(InGuid);

	return InBatch;
}

void FSimpleNetBatchManage::Remove(const FGuid& InGuid)
{
	FScopeLock ScopeLock(&BatchsReadWrite);

	Batchs.Remove(InGuid);
}

void FSimpleNetBatchManage::Reset()
{
	FScopeLock ScopeLock(&BatchsReadWrite);

	Batchs.Empty();
}