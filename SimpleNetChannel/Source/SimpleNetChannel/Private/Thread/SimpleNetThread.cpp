// Copyright (C) RenZhai.2021.All Rights Reserved.

#include "SimpleNetThread.h"
#include "Log/SimpleNetChannelLog.h"

#if PLATFORM_WINDOWS
#pragma optimize("",off) 
#endif

int32 ThreadCount = 0;

FSimpleNetThread::FSimpleNetThread()
	:ThreadEvent(FPlatformProcess::GetSynchEventFromPool())
	,bStopThread(false)
{
	RunnableName = *FString::Printf(TEXT("SimpleNetThread-%i"), ThreadCount);
	Thread = FRunnableThread::Create(this, *RunnableName, 0, TPri_Normal);

	UE_LOG(LogSimpleNetChannel, Display, TEXT("Thread pool creation thread [%s]"), *RunnableName);

	ThreadCount++;
}

FSimpleNetThread::FSimpleNetThread(FSimpleDelegate InDelegate)
	:Delegate(InDelegate)
	,ThreadEvent(FPlatformProcess::GetSynchEventFromPool())
	,bStopThread(false)
{
	RunnableName = *FString::Printf(TEXT("SimpleNetThread-%i"), ThreadCount);
	Thread = FRunnableThread::Create(this, *RunnableName,0, TPri_Normal);
	
	ThreadCount++;
}

FSimpleNetThread::~FSimpleNetThread()
{
	//用主线程把自己杀掉
	FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([this]()
	{
		//杀掉自己
		Kill();

		// 事件使用完毕，返回到池中
		FPlatformProcess::ReturnSynchEventToPool(ThreadEvent);

		// 确保不再使用这个指针
		ThreadEvent = nullptr;

	}, TStatId(), NULL, ENamedThreads::GameThread);

	FTaskGraphInterface::Get().WaitUntilTaskCompletes(Task);
}

void FSimpleNetThread::Bind(FSimpleDelegate InDelegate)
{
	Delegate = InDelegate;
}

void FSimpleNetThread::Kill(FSimpleNetThread* InNetThread)
{
	if (InNetThread)
	{
		InNetThread->Kill();

		delete InNetThread;
		InNetThread = nullptr;
	}
}

void FSimpleNetThread::Trigger()
{
	ThreadEvent->Trigger();
}

uint32 FSimpleNetThread::Run()
{
	while (!bStopThread && ThreadEvent)
	{
		UE_LOG(LogSimpleNetChannel, Display, TEXT("The current thread is ready to suspend [%s]"),*RunnableName);
		
		ThreadEvent->Wait();

		UE_LOG(LogSimpleNetChannel, Display, TEXT("[%s] Start executing new tasks."), *RunnableName);

		FDateTime StartTime = FDateTime::Now();

		Delegate.ExecuteIfBound();

		FTimespan Duration = FDateTime::Now() - StartTime;

		double TotalSeconds = Duration.GetTotalSeconds();

		UE_LOG(LogSimpleNetChannel, Display, TEXT("[%s] Task completed.Spent %f s"), *RunnableName,TotalSeconds);

		//解除绑定等待下一个任务来临
		Delegate.Unbind();
	}

	return true;
}

void FSimpleNetThread::Kill()
{
	bStopThread = true;

	if (Thread)
	{
		Thread->Kill();

		delete Thread;
		Thread = nullptr;
	}
}

#if PLATFORM_WINDOWS
#pragma optimize("",on) 
#endif