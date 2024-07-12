// Copyright (C) RenZhai.2021.All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

class FSimpleNetThread;

class SIMPLENETCHANNEL_API FSimpleNetThreadManage
{
public:
	static FSimpleNetThreadManage* Get();
	static void Destroy();

public:
	FSimpleNetThreadManage(int32 InNumThreads);

	~FSimpleNetThreadManage();

	void AddTask(const FSimpleDelegate& InTask);

protected:
	static FSimpleNetThreadManage *Instance;

	// 应该有一个线程安全的任务队列
    TArray<TSharedPtr<FSimpleNetThread,ESPMode::ThreadSafe>> TaskQueue;
};