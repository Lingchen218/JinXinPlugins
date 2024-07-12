// Copyright (C) RenZhai.2021.All Rights Reserved.
#pragma once

#include "SimpleNetChannelType.h"
#include "Cache/SimpleNetCacheManage.h"
#include "Channel/SimpleChannel.h"

class FSocket;
class FInternetAddr;
class FSimpleChannel;
class ISocketSubsystem;
class FSimpleNetManage;

class FSimpleConnetion :public TSharedFromThis<FSimpleConnetion>
{
protected:
	typedef FSimpleConnetion Super;

public:
	virtual ~FSimpleConnetion(){}
	FSimpleConnetion();

	virtual void Init();
	virtual void Tick(float DeltaSeconds);
	virtual void CheckLoginTimeout(float DeltaSeconds);
	virtual void Close();

	virtual void Listen(){}
	virtual void ActivateListen();

	static ISocketSubsystem* GetSocketSubsystem();
	TSharedRef<FInternetAddr> GetAddr();
	TSharedRef<FInternetAddr> GetRemoteAddr();

	void SendHeartBeat();
	void StartSendHeartBeat();

	virtual void Send(TArray<uint8>& InData);
	virtual void Send(TArray<uint8>& InData, TSharedPtr<FInternetAddr> InNewAddr);
	//virtual void Receive(const FGuid &InChannelID,TArray<uint8> &InData);

	virtual void Analysis(uint8* InData, int32 BytesNumber);

	void SetState(ESimpleConnetionLinkType InState);

	void CheckTimeOut();

	virtual void RequestSocketAddressRequest();
	virtual void ConnectVerification();
	void SetSocket(FSocket* InSocket);

	void ResetHeartBeat();

	FSimpleChannel* GetMainChannel();
	FSimpleChannel* GetChannel(const FGuid &InChannelGuid);

	void SetLinkState(ESimpleNetLinkState NewLinkState);
	void SetConnetionType(ESimpleConnetionType InType);
	void SetManage(FSimpleNetManage *InManage);

	void GetChannelActiveID(TArray<FGuid>& InIDs);

	void SetGroupID(int32 InNewGroupID) { GroupID = InNewGroupID; }
	int32 GetGroupID() { return GroupID; }

	FSocket* GetSocket()const { return Socket; }

	//socket
public:
	virtual FSocket* CreateSocket(const uint32& InIP, uint32 &InPort, bool bBlocking) { return nullptr; }
	virtual bool CloseSocket();

	void SetRemoteAddr(TSharedPtr<FInternetAddr> InAddr);
	void SetLocalAddr(TSharedPtr<FInternetAddr> InAddr);

public:
	bool IsCompletePackage(int32 InRecvNum,
		uint8* InData,
		FGuid& OutGUID,
		uint8*& OutData,
		int32& OutLen);

	void HandleMergePackage(int32 InRecvNum,uint8* InData, TSharedPtr<FInternetAddr> InAddr);
	void VerificatioConnetionInfo(uint8* InData, int32 InByteNumber, TSharedPtr<FInternetAddr> InAddr);

	//接受 并且 处理 远端
	void RecvByRemote(int32 InBytesSize,uint8 *InData);

public:
	void Lock();
	bool IsLock()const { return bLock; }
	void UnLock();

public:
	FORCEINLINE FSimpleNetManage* GetManage() { return Manage; }
	FORCEINLINE ESimpleNetLinkState GetLinkState()const { return LinkState; }
	FORCEINLINE ESimpleConnetionType GetConnetionType()const { return ConnetionType; }
	FORCEINLINE ESimpleConnetionLinkType GetState() { return State; }
	FORCEINLINE	TArray<FSimpleChannel>& GetChannels() { return Channels; }

protected:
	TArray<FSimpleChannel> Channels;//
	ESimpleConnetionLinkType State;//初始化阶段
	ESimpleNetLinkState LinkState;//Connet的状态
	ESimpleConnetionType ConnetionType;

	//考虑多Socket情况
	FSocket* Socket;//TCP UDP
	TSharedPtr<FInternetAddr> LocalAddr;//如果是服务器 那么这个地址就是服务器地址
	TSharedPtr<FInternetAddr> RemoteAddr;//主要针对服务器对应的客户端地址
	uint8 bLock : 1;
	uint8 bHeartBeat : 1;
	uint8 bStopListen : 1;
	double HeartTime;
	double LastTime;

	double RequiredReconnectionTime;
	double TimeoutLink;

	int32 GroupID;//方便验证组ID

	//缓存管理
	FSimpleNetCacheManage CacheManage;

protected: 
	FSimpleNetManage* Manage;
	FCriticalSection SocketMutex;//主要针对主线程和内部其他线程争夺

	FRWLock HeartBeatReadWrite;//针对心跳读写
	bool bIntoOutTime;
};