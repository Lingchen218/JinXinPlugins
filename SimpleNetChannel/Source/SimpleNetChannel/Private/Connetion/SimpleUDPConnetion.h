// Copyright (C) RenZhai.2021.All Rights Reserved.

#pragma once

#include "Connetion/Core/SimpleConnetion.h"

//一个Connetion Corresponding to a client
class FSimpleUDPConnetion :public FSimpleConnetion
{
public:

	virtual void ConnectVerification();

	virtual void Analysis(uint8* InData, int32 BytesNumber);

	virtual void Send(TArray<uint8>& InData, TSharedPtr<FInternetAddr> InNewAddr);
	virtual void Send(TArray<uint8>& InData);

	//virtual void Receive(const FGuid& InChannelID, TArray<uint8>& InData);

	//针对多Socket进行监听
	virtual void Listen();

public:
	virtual FSocket* CreateSocket(const uint32& InIP, uint32 &InPort,bool bBlocking);
	virtual bool CloseSocket();

	int32 ResetBindPort(uint32 &InPort, ISocketSubsystem* InSocketSubsystem);
};