// Copyright (C) RenZhai.2021.All Rights Reserved.
#pragma once

#include "SimpleNetChannelType.h"
#include "SimpleProtocolsDefinition.h"
#include "Channel/SimpleChannel.h"
#include "Connetion/Core/SimpleConnetion.h"
#include "UObject/Core/SimpleNetObject.h"
#include "UObject/SimpleController.h"
#include "Channel/SimpleChannel.h"
#include "Runtime/Launch/Resources/Version.h"

#define TEST_SNC false

class USimpleNetworkObject;

#ifdef PLATFORM_PROJECT
#include "Tickable.h"
#endif

DECLARE_DELEGATE_TwoParams(FSimpleNetManageMsgDelegate, ESimpleNetErrorType, const FString&);

class FSimpleConnetion;
class FInternetAddr;

class SIMPLENETCHANNEL_API FSimpleNetManage
#ifdef PLATFORM_PROJECT
	:public FTickableGameObject
#endif
{
public:
	FSimpleNetManageMsgDelegate NetManageMsgDelegate;

	UClass* NetworkObjectClass;
	UClass* SimplePlayerClass;

public:
	void LinkTimeout(const FString& InTimeoutMsg);

public:
	FSimpleNetManage();
	virtual ~FSimpleNetManage();

public:
	static FSimpleNetManage* CreateManage(ESimpleNetLinkState InState, ESimpleSocketType InType,bool bNewHighConcurrency = false);
	static void Destroy(FSimpleNetManage* InNetInstance);

	//处理多个客户端
	//创建多个客户端集合 用于中转
	//InGroupID 哪个组
	//InLinkIP 链接的IP
	//InPort 对应的断开
	//InClientNumber 创建多少个客户端
	//InClass 重写的类型
	//InType TCP 还是UDP
	static bool CreateCients(int32 InGroupID,const FString& InLinkIP,int32 InPort,int32 InClientNumber,UClass* InClass,bool bNewAllowSynchronization = false, ESimpleSocketType InType = ESimpleSocketType::SIMPLESOCKETTYPE_UDP);
	static void DestroyClients(int32 InGroupID = INDEX_NONE);

	//如果找不到，都在使用中，那么就等待 等待一定时间 还为获取，就放弃
	static FSimpleNetManage* FindClientFree(int32 InGroupID);

	static void TickClients(float DeltaTime);

public:
	//处理服务器
	TSharedPtr<FSimpleConnetion> FindConnetionFree(int32 InGroupID);
	//只针对客户端管理设置
	void SetGroupID(int32 InNewGroupID);

	TSharedPtr<FSimpleConnetion> FindConnetion(TSharedPtr<FInternetAddr> InAddr);

public:
	virtual bool Init(int32 InPort = 0);
	virtual bool Init(uint32 InIP,uint32 InPort);
	virtual bool Init(const FSimpleAddr& InAddr);
	virtual bool Init(const FString& InIP, uint32 InPort);

	virtual void Tick(float DeltaTime);
	virtual void Close();
	virtual void Close(const FSimpleAddrInfo& InCloseConnetion);
	virtual void Close(const TSharedPtr<FInternetAddr>& InternetAddr);

	USimpleController* GetController();
	USimpleNetworkObject* GetNetworkObject(uint32 InIP,uint32 InPort,const FGuid& InChannelID);

	FSimpleChannel* GetChannel();
	FSimpleChannel* GetChannel(uint32 InIP, uint32 InPort, const FGuid& InChannelID);

	int32 GetConnetionNum();
	FSimpleAddr GetAddr();//服务器本身地址

	static FString GetAddrString(const FSimpleAddr& InAddr);
	static TSharedPtr<FInternetAddr> GetInternetAddr(const FSimpleAddr& InAddr);
	static FSimpleAddr GetSimpleAddr(TSharedPtr<FInternetAddr> InAddr);
	static FSimpleAddr GetSimpleAddr(const TCHAR* InIP,uint32 InPort);
	static void GetLocalIPAndPort(FString& InIP,uint32& Port);
	static bool AddrEquation(TSharedPtr<FInternetAddr> InAAddr, TSharedPtr<FInternetAddr> InBAddr);

	//该API使用需要保证你当前的网络管理是服务器 它会遍历服务器的远端链接对象
	template<class T>
	void FindRemoteNetworkObjectByLambda(TFunction<ESimpleNetManageCallType(T*)> InImplement);

	//高效的自定义广播 前提是必须是服务器
	template<uint32 InProtocols, class T, typename ...ParamTypes>
	void MulticastByPredicate(TFunction<bool(T*)> InImplement, ParamTypes &...Param);

	//是否开启了高并发
	bool IsHighConcurrency() const { return bHighConcurrency || TEST_SNC; }

public:
	bool IsPortAvailable(const uint32 InPort);
	
	//是否支持同步 一般该功能针对客户端 服务器可以忽略
public:
	void SetAllowSynchronization(bool bNewValue) { bAllowSynchronization = bNewValue; }
	bool IsAllowSynchronization() const { return bAllowSynchronization; }

protected:
	virtual void ResetLocalConnetion();
	virtual TSharedPtr<FSimpleConnetion> CreateConnetion() const;

protected:
	virtual bool CloseSocket();

public:
	static USimpleNetworkObject* GetNetManageNetworkObject(FSimpleNetManage* InSimpleNetManage, const FSimpleAddrInfo& AddrInfo);

public:
	FORCEINLINE ESimpleNetLinkState GetLinkState() { return LinkState; }

protected:
	virtual TStatId GetStatId()const;

public:
	void ExecuteNetManageMsgDelegate(ESimpleNetErrorType InType,const FString& InError);

protected:
	ESimpleNetLinkState LinkState;

	struct FNet
	{
		bool IsAddr(TSharedPtr<FInternetAddr> InternetAddr);
		int32 Add(TSharedPtr<FInternetAddr> InternetAddr);
		void Clear(int32 InIndex);
		TSharedPtr<FSimpleConnetion> GetEmptyConnetion(TSharedPtr<FInternetAddr> InternetAddr);

	public:
		TSharedPtr<FSimpleConnetion> operator[](TSharedPtr<FInternetAddr> InternetAddr);
		TSharedPtr<FSimpleConnetion> operator[](const FSimpleAddr& InternetAddr);
		TSharedPtr<FSimpleConnetion> operator[](const int32 InGroupID);//获取组内空闲的链接

	public:
		TSharedPtr<FSimpleConnetion> LocalConnetion;
		TArray<TSharedPtr<FSimpleConnetion>> RemoteConnetions;
	}Net;

	bool bHighConcurrency;
	bool bInit;
	bool bClientLink;//只针对客户端 链接服务器
	bool bAllowSynchronization;//是否允许同步操作

	//端口
	TMap<uint32, bool> Prots; //该池指针对异步 需要配置开启 异步

	uint32 GetAvailPort();

	bool OpenPort(uint32 InPort);
	bool ClosePort(uint32 InPort);

	//用于中转
	static TMap<int32,TArray<FSimpleNetManage*>> Clients;
};

template<class T>
void FSimpleNetManage::FindRemoteNetworkObjectByLambda(TFunction<ESimpleNetManageCallType(T*)> InImplement)
{
	for (auto& Tmp : Net.RemoteConnetions)
	{
		ESimpleNetManageCallType SimpleNetManageCallType = ESimpleNetManageCallType::INPROGRESS;
		for (auto& TmpChannel : Tmp->GetChannels())
		{
			if (TmpChannel.IsValid())
			{
				SimpleNetManageCallType = InImplement(TmpChannel.GetNetObject<T>());
				if (SimpleNetManageCallType == ESimpleNetManageCallType::PROGRESS_COMPLETE)
				{
					break;
				}
			}
		}

		if (SimpleNetManageCallType == ESimpleNetManageCallType::PROGRESS_COMPLETE)
		{
			break;
		}
	}
}

//广播指定的链接端
template<uint32 InProtocols, class T, typename ...ParamTypes>
void FSimpleNetManage::MulticastByPredicate(TFunction<bool(T*)> InImplement, ParamTypes &...Param)
{
	for (auto& Tmp : Net.RemoteConnetions)
	{
		ESimpleNetManageCallType SimpleNetManageCallType = ESimpleNetManageCallType::INPROGRESS;
		for (auto& Channel : Tmp->GetChannels())
		{
			if (Channel.IsValid())
			{
				//是否满足可以广播的条件
				if (InImplement(Channel.GetNetObject<T>()))
				{
#if ENGINE_MAJOR_VERSION == 5 && ENGINE_MINOR_VERSION >= 3
					SIMPLE_PROTOCOLS_SEND(InProtocols, Param...);
#else
					FSimpleProtocols<InProtocols>::Send(&Channel, Channel.GetRemoteAddr(), Param...);
#endif 
				}
			}
		}
	}
}
