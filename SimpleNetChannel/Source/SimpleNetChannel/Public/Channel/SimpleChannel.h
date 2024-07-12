// Copyright (C) RenZhai.2021.All Rights Reserved.
#pragma once

#include "UObject/StrongObjectPtr.h"
#include "SimpleNetChannelType.h"
#include "Misc/ScopeLock.h"
#include "Cache/SimpleNetBatchManage.h"
#include "Cache/SimpleNetMsgBatchPackageManage.h"

DECLARE_DELEGATE_RetVal(UClass*, FSimpleReturnDelegate);

class USimpleNetworkObject;
class FSimpleConnetion;
class FInternetAddr;

class SIMPLENETCHANNEL_API FSimpleChannel
{
public:
	static FSimpleReturnDelegate SimpleControllerDelegate;
	static FSimpleReturnDelegate SimplePlayerDelegate;

	FSimpleChannel();
	virtual ~FSimpleChannel() {}

	virtual void Init();

	virtual void Tick(float DeltaSeconds);
	virtual void Close();
	virtual void PreClose();

	virtual void RecvProtocol(uint32 InProtocolsNumber);

	void Send(TArray<uint8>& InData, TSharedPtr<FInternetAddr> InNewAddr,bool bForceSend = false);
	void Send(TArray<uint8>& InData,bool bForceSend = false);

	bool Receive(TArray<uint8>& InData);

	TSharedPtr<FInternetAddr> GetLocalAddr() const;
	TSharedPtr<FInternetAddr> GetRemoteAddr() const;

	void SetConnetion(TWeakPtr<FSimpleConnetion> InConnetion);

	TSharedPtr<FSimpleConnetion >GetConnetion();

	void AddMsg(const FGuid &InGuid,TArray<uint8> &InData);

	void InitController();
	void SpawnController();
	void SpawnPlayer();

	USimpleNetworkObject* GetNetObject();

	template<class T>
	T* GetNetObject()
	{
		return Cast<T>(Object.Get());
	}
	
	bool GetLocalAddrInfo(FSimpleAddrInfo& InAddrInfo);
	bool GetRemoteAddrInfo(FSimpleAddrInfo& InAddrInfo);

	void AcceptSuccess(const FGuid &InDataID,uint32 InIndex,bool bAck,bool bAllSuccessful = false);
	void SendBatch(const FGuid& InDataID, uint32 InIndex,uint32 InProtocol);

	void BuildBytes(TArray<uint8> &InBytes,TArray<uint8>& OutBytes,bool bForce);

	bool RemoveSynchronizeTag(uint64 InNewTags);

protected:
	USimpleNetworkObject* SpawnObject(UClass *InClass);
	void RegisterObject(FSimpleReturnDelegate InDelegate,UClass *InObjectClass);
	void RegisterObject(UClass *InClass, UClass* InObjectClass);

public:
	bool IsValid()const;
	const FGuid &GetGuid() const;
	void SetGuid(const FGuid &NewGuid);
	void SetMsgQueueGuid(const FGuid& InNewGuid);
	void ResetTagBackups(uint64 InNewValue) { TagBackups = InNewValue; }

	//不要直接调用该方法 
	void DestroySelf();

protected:
	FSimpleNetBatchManage BatchManage;
	FSimpleNetMsgBatchPackageManage BatchPackageManage;

protected:
	TWeakPtr<FSimpleConnetion> ConnetionPtr;
	TStrongObjectPtr<USimpleNetworkObject> Object;
	FGuid ID;
	TArray<uint64> SynchronizeTag;//为同步考虑

	//由服务器备份
	uint64 TagBackups;
};