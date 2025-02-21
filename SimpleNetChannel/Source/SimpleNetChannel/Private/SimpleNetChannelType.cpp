// Copyright (C) RenZhai.2021.All Rights Reserved.

#include "SimpleNetChannelType.h"
#include "SocketSubsystem.h"
#include "Connetion/Core/SimpleConnetion.h"
#include "Log/SimpleNetChannelLog.h"

FSimpleConfigInfo::FSimpleConfigInfo()
	: Version(TEXT("1.0.1"))
	, URL(TEXT("127.0.0.1"))
	, Port(11223)
	, RecvDataNumber(10240)
	, SendDataNumber(1024)
	, MaxConnections(2000)
	, MaxChannels(5)
	, RepackagingFrequency(2000)
	, NumberThreads(100)
	, bPrintHeartBeat(false)
	, bSlidingWindow(true)
	, bRepackaging(true)
	, bShowCompletePackProtocolInfo(false)
	, bShowSendDebug(false)
	, RepackagingTime(3.f)
	, OutTimeLink(360)
	, HeartBeatTimeTnterval(30.f)
	, PublicIP(TEXT("127.0.0.1"))
{
	OutTimeSynchronizationTime = 5.f;

	PingMaxOutTime = 2.f;
	Port += 1;
	PortRange = FIntVector2(Port-1, Port);
}

FSimplePackageHead::FSimplePackageHead()
	:Protocol(0)
	,PackageIndex(0)
	,PackageSize(0)
	,bAck(false)
	,bForceSend(false)
	,PackageID(FGuid::NewGuid())
	
{
	Tag = 0.f;
}

FSimpleBunchHead::FSimpleBunchHead()
	:ProtocolsNumber(0)
	,ParamNum(0)
	,bAsynchronous(true)
{
	FGuid A = FGuid::NewGuid();
	Tag = A.A + A.B - A.C + A.D;
}

FSimpleAddrInfo::FSimpleAddrInfo()
{
}

FSimpleAddr::FSimpleAddr()
	:IP(0)
	, Port(0)
{
}

FSimpleAddr::FSimpleAddr(const FString& InIP, uint32 InPort)
	: IP(0)
	, Port(0)
{
	if (ISocketSubsystem* SocketSubsystem = FSimpleConnetion::GetSocketSubsystem())
	{
		TSharedRef<FInternetAddr> TmpAddr = SocketSubsystem->CreateInternetAddr();
		bool bIsValid = false;
		TmpAddr->SetIp(*InIP, bIsValid);

		uint32 MyIP = 0;
		TmpAddr->GetIp(MyIP);

		IP = MyIP;
		Port = InPort;
	}
}

namespace SimpleNetChannel
{
	FTimeCount::FTimeCount(const FString& InLogContent)
		:LogContent(InLogContent)
	{
		Time = FPlatformTime::Seconds();
		UE_LOG(LogSimpleNetChannel, Warning, TEXT("%s Time count start."), *InLogContent);
	}

	FTimeCount::~FTimeCount()
	{
		double Now = FPlatformTime::Seconds();
		float DeltaSenconds = Now - Time;

		UE_LOG(LogSimpleNetChannel, Warning, TEXT("%s take time :%f"), *LogContent, DeltaSenconds);
	}
}