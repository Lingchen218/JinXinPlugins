// Copyright (C) RenZhai.2021.All Rights Reserved.

#pragma once
#include "CoreMinimal.h"

//主要针对发送的散包，比如大型文章，无法一口气发送好几兆的数据，我们需要把数据切成一段段的，batch就是这一段
//这个类是用来管理这些

class FSimpleConnetion;

class SIMPLENETCHANNEL_API FSimpleNetBatchManage
{
public:
	struct FBatch
	{
		FBatch()
			:bAck(false)
		{}
		struct FElement
		{
			FElement()
				:bStartUpRepackaging(false)
				, bAck(false)
				, RepeatCount(0)
				, CurrentTime(0.f)
			{}

			bool bStartUpRepackaging;//
			bool bAck;
			uint8 RepeatCount;//
			float CurrentTime;

			TArray<uint8> Package;
		};

		bool bAck;
		TMap<int32, FElement> Sequence;
	};

public:
	FSimpleNetBatchManage();
	virtual ~FSimpleNetBatchManage();

public:
	FSimpleNetBatchManage::FBatch& operator[](const FGuid& InGuid)
	{
		return Batchs[InGuid];
	}

public:
	void SetConnetion(TWeakPtr<FSimpleConnetion> InConnetionPtr);
	virtual void Tick(float DeltaSeconds);

	void Add(const FGuid& InGuid, const FSimpleNetBatchManage::FBatch& InCache);
	FSimpleNetBatchManage::FBatch* Find(const FGuid& InGuid);
	void Remove(const FGuid& InGuid);
	void Reset();

protected:
	TWeakPtr<FSimpleConnetion> ConnetionPtr;
	TMap<FGuid, FBatch> Batchs;
	FCriticalSection BatchsReadWrite;//针对缓存锁 
};