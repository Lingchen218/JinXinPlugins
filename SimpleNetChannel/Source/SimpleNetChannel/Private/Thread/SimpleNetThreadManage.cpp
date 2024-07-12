#include "Thread/SimpleNetThreadManage.h"
#include "Thread/SimpleNetThread.h"
#include "Global/SimpleNetGlobalInfo.h"
#include "Log/SimpleNetChannelLog.h"
#include "Async/Async.h"

FSimpleNetThreadManage* FSimpleNetThreadManage::Instance = nullptr;

FSimpleNetThreadManage* FSimpleNetThreadManage::Get()
{
	if (!Instance)
	{
		Instance = new FSimpleNetThreadManage(FSimpleNetGlobalInfo::Get()->GetInfo().NumberThreads);
	}

	return Instance;
}

void FSimpleNetThreadManage::Destroy()
{
	if (Instance)
	{
		delete Instance;
	}
}

FSimpleNetThreadManage::FSimpleNetThreadManage(int32 InNumThreads)
{
	for (int32 i = 0; i < InNumThreads; ++i)
	{
		TaskQueue.Add(MakeShareable(new FSimpleNetThread()));
	}
}

FSimpleNetThreadManage::~FSimpleNetThreadManage()
{
	TaskQueue.Empty();
}

void FSimpleNetThreadManage::AddTask(const FSimpleDelegate &InTask)
{
	//寻找不忙的线程
	TSharedPtr<FSimpleNetThread,ESPMode::ThreadSafe> NotBusyThread;
	for (auto &Tmp : TaskQueue)
	{
		if (!Tmp->IsBusy())
		{
			NotBusyThread = Tmp;
			break;
		}
	}

	if (NotBusyThread) //找到该线程
	{
		NotBusyThread->Bind(InTask);
		NotBusyThread->Trigger();//激活
	}
	else //未找到 可能工作区已经满额 使用UE5本身的线程
	{
		AsyncTask(ENamedThreads::AnyBackgroundThreadNormalTask,
		[InTask]()
		{
			InTask.ExecuteIfBound();
		});
	}
}