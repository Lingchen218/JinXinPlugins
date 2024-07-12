// Copyright (C) RenZhai.2021.All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "../../SimpleNetChannelType.h"
#include "../../Channel/SimpleChannel.h"
#include "../../Connetion/Core/SimpleConnetion.h"
#include "SimpleNetObject.generated.h"

DECLARE_MULTICAST_DELEGATE_TwoParams(FSimpleNetRecvDelegate,uint32, FSimpleChannel*)


UCLASS(Blueprintable)
class SIMPLENETCHANNEL_API USimpleNetworkObject :public UObject
{
	GENERATED_BODY()

	friend FSimpleChannel;

	UPROPERTY()
	ESimpleNetLinkState LinkState;

public:
	//Accepting proxies mainly involves calling higher-level logic
	FSimpleNetRecvDelegate RecvDelegate;

public:
	USimpleNetworkObject();

	//The network corresponding to this object passes through
	FSimpleChannel* GetChannel();

	//The network link corresponding to this object
	TSharedPtr<FSimpleConnetion > GetConnetion();

	//Main Network Driver Management
	FSimpleNetManage* GetManage();

	UE_DEPRECATED(4.25, "This method has been discarded,Please use GetRemoteAddrInfo(...) on the network object instead.")
	bool GetAddrInfo(FSimpleAddrInfo &InAddrInfo);

	UE_DEPRECATED(4.25, "This method has been discarded,Please use GetLocalAddrInfo(...) on the net network object instead.")
	bool GetServerAddrInfo(FSimpleAddrInfo& InAddrInfo);
	
	//Get the remote address of your own link
	bool GetRemoteAddrInfo(FSimpleAddrInfo& InAddrInfo);

	//Obtain the local main link address
	bool GetLocalAddrInfo(FSimpleAddrInfo& InAddrInfo);

	//If you want to close the link, please replace it with FSimpleNetManage::Destroy(your SNCManage)
	UE_DEPRECATED(5.32, "This method has been discarded,Will get stuck in the thread.Please use the current API FSimpleNetManage::Destroy(your snc) instead.")
	void DestroySelf();

	void Ping();

	void BuildUnlinked(ESimpleNetManagePingType InType);

public:
	/*Is a link the object corresponding to the main link
	*If there are multiple main links in the project, please check if multiple instances of network management have been created and linked to the same object, resulting in
	*It is possible that your link management is related to other network management objects, such as the central server, and there is also a database client within the database client
	*The main link is also true, and the local central server is also true
	*/
	bool IsMainConnetion();

	//Is it a client link or a server link
	FORCEINLINE ESimpleNetLinkState GetLinkState() { return LinkState; }

protected:
	virtual void Init();
	virtual void Tick(float DeltaTime);
	virtual void Close();

	virtual void RecvProtocol(uint32 InProtocol);

protected:
	FSimpleChannel* Channel;

private:
	bool bPing;
	float PingTime;
};
