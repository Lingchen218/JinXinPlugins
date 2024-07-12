// Copyright (C) RenZhai.2021.All Rights Reserved.
#pragma once

#include "SimpleNetManage.h"
#include "Thread/SimpleNetThread.h"

class FSocket;
class FSimpleNetThread;

class FSimpleUDPManage :public FSimpleNetManage
{
	typedef FSimpleNetManage Super;

public:	
	FSimpleUDPManage(ESimpleNetLinkState InType, bool bNewHighConcurrency);

	virtual bool Init(int32 InPort = 0) override;
	virtual bool Init(uint32 InIP, uint32 InPort) override;
	virtual bool Init(const FString& InIP, uint32 InPort) override;

	virtual void Tick(float DeltaTime) override;

	virtual void Close()override;
	virtual void Close(const FSimpleAddrInfo& InCloseConnetion)override;

	void ResetLocalConnetion();

	//Asynchronous
	void Run();

protected:
	virtual TSharedPtr<FSimpleConnetion> CreateConnetion() const;

protected:
	void Listen();

	virtual bool CloseSocket();

protected:
	TSharedPtr<FSimpleNetThread,ESPMode::ThreadSafe> MainNetThread;

protected:
	bool bEndThread;

};