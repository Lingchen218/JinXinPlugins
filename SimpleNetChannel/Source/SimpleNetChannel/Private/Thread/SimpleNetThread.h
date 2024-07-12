// Copyright (C) RenZhai.2021.All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "HAL/Runnable.h"
#include "HAL/RunnableThread.h"

class SIMPLENETCHANNEL_API FSimpleNetThread :public FRunnable,public TSharedFromThis<FSimpleNetThread,ESPMode::ThreadSafe>
{
public:
	FSimpleNetThread();
	FSimpleNetThread(FSimpleDelegate InDelegate);
	~FSimpleNetThread();

	void Bind(FSimpleDelegate InDelegate);
	static void Kill(FSimpleNetThread* InNetThread);

	//唤醒
	virtual void Trigger();

	//运行
	virtual uint32 Run();

	//释放
	virtual void Kill();
	
	bool IsBusy() const { return Delegate.IsBound(); }

	bool IsStopThread() const { return bStopThread; }

private:
	FString RunnableName;
	FRunnableThread* Thread;
	FSimpleDelegate Delegate;
	FEvent* ThreadEvent;
	bool bStopThread;
};