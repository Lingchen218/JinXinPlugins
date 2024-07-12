// Copyright (C) RenZhai.2021.All Rights Reserved.

#pragma once
#include "CoreMinimal.h"

//主要针对将包传递过来后存储在本地，方便逻辑那边取出里面的数据
//这个类是用来管理这些

class FSimpleConnetion;

class SIMPLENETCHANNEL_API FSimpleNetMsgBatchPackageManage
{
public:
	struct FMsgBatchPackage
	{
		FMsgBatchPackage();

		void Tick(float DeltaSeconds);

		float CurrentTime;
		bool bOutTime;

		TArray<uint8> Data;
	};

public:
	FSimpleNetMsgBatchPackageManage();
	virtual ~FSimpleNetMsgBatchPackageManage();

public:
	FSimpleNetMsgBatchPackageManage::FMsgBatchPackage& operator[](const FGuid& InGuid)
	{
		return MsgQueue[InGuid];
	}

public:
	void SetMsgQueueGuid(const FGuid& InNewGuid);
	void SetConnetion(TWeakPtr<FSimpleConnetion> InConnetionPtr);
	virtual void Tick(float DeltaSeconds);

	void Add(const FGuid& InGuid, TArray<uint8>& InData);
	bool Receive(TArray<uint8>& InData);

	void Reset();

protected:
	TWeakPtr<FSimpleConnetion> ConnetionPtr;
	FGuid MsgQueueGuid;
	TMap<FGuid, FSimpleNetMsgBatchPackageManage::FMsgBatchPackage> MsgQueue;
	FCriticalSection ThreadCritical;//对资源上锁 防止读取和写入 导致数据错乱
};