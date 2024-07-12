// Copyright (C) RenZhai.2021.All Rights Reserved.

#include "SimpleNetManage.h"
#include "Manage/SimpleUDPManage.h"
#include "Manage/SimpleTCPManage.h"
#include "IPAddress.h"
#include "Stream/SimpleIOStream.h"
#include "Global/SimpleNetGlobalInfo.h"
#include "Protocols/SimpleNetProtocols.h"
#include "Log/SimpleNetChannelLog.h"
#include "SimpleProtocolsDefinition.h"
#include "Thread/SimpleNetThread.h"
#include "Thread/SimpleNetThreadManage.h"
#include "SocketSubsystem.h"
#include "Sockets.h"

#if PLATFORM_WINDOWS
#pragma optimize("",off) 
#endif

TMap<int32, TArray<FSimpleNetManage*>> FSimpleNetManage::Clients;

FSimpleNetManage::~FSimpleNetManage()
{

}

FSimpleNetManage *FSimpleNetManage::CreateManage(ESimpleNetLinkState InState, ESimpleSocketType InType, bool bNewHighConcurrency)
{
	switch (InType)
	{
	case ESimpleSocketType::SIMPLESOCKETTYPE_TCP:
		return new FSimpleUDPManage(InState, bNewHighConcurrency);
	case ESimpleSocketType::SIMPLESOCKETTYPE_UDP:
		return new FSimpleUDPManage(InState, bNewHighConcurrency);
	}

	return NULL;
}

bool FSimpleNetManage::Init(int32 InPort)
{
	return false;
}

bool FSimpleNetManage::Init(uint32 InIP, uint32 InPort)
{
	if (LinkState == ESimpleNetLinkState::LINKSTATE_LISTEN)
	{
		if (IsHighConcurrency())//高并发为主
		{
			if (Prots.Num() == 0)
			{
				FIntVector2 Int2Vector = FSimpleNetGlobalInfo::Get()->GetInfo().PortRange;

				//初始化端口池
				for (int32 i = Int2Vector.X; i < Int2Vector.Y; i++)
				{
					Prots.Add(i, false);
				}
			}
		}
	}

	ResetLocalConnetion();

	if (FSocket* InSocket = Net.LocalConnetion->CreateSocket(InIP, InPort, false))
	{
		Net.LocalConnetion->SetLinkState(LinkState);
		Net.LocalConnetion->Init();

		//Client ready to connect
		if (LinkState == ESimpleNetLinkState::LINKSTATE_CONNET)
		{
			bClientLink = false;

			if (IsHighConcurrency())//高并发为主
			{
				Net.LocalConnetion->RequestSocketAddressRequest();
			}
			else
			{
				Net.LocalConnetion->ConnectVerification();
			}
		}
		else if (LinkState == ESimpleNetLinkState::LINKSTATE_LISTEN)
		{
			for (int32 i = 0; i < FSimpleNetGlobalInfo::Get()->GetInfo().MaxConnections; i++)//Pre allocated memory
			{
				Net.RemoteConnetions.Add(CreateConnetion());

				TSharedPtr<FSimpleConnetion> InNewConnetion = Net.RemoteConnetions.Last();
				if (!(IsHighConcurrency()))//高并发为主
				{
					InNewConnetion->SetSocket(InSocket);

					//单线程模式下 设置所有connetion都是本地链接
					//多线程模式下 对应不同UDPSocket
					InNewConnetion->SetLocalAddr(Net.LocalConnetion->GetAddr());
				}

				InNewConnetion->SetLinkState(LinkState);
				InNewConnetion->SetManage(this);

			//	InNewConnetion->Init();
			}

			//Set up local direct join
			Net.LocalConnetion->SetState(ESimpleConnetionLinkType::LINK_JOIN);
			Net.LocalConnetion->GetMainChannel()->InitController();
		}

		bInit = true;
	}

	return true;
}

bool FSimpleNetManage::Init(const FString& InIP, uint32 InPort)
{
	return false;
}

bool FSimpleNetManage::Init(const FSimpleAddr& InAddr)
{
	return Init(InAddr.IP,InAddr.Port);
}

void FSimpleNetManage::Tick(float DeltaTime)
{
	
}

void FSimpleNetManage::Close(const FSimpleAddrInfo& InCloseConnetion)
{
	if (TSharedPtr<FSimpleConnetion> ConnetionInstance = Net[InCloseConnetion.Addr])
	{
		ConnetionInstance->Close();
	}
}

void FSimpleNetManage::ExecuteNetManageMsgDelegate(ESimpleNetErrorType InType, const FString& InError)
{
	if (IsInGameThread())
	{
		NetManageMsgDelegate.ExecuteIfBound(InType, InError);
	}
	else
	{
		FFunctionGraphTask::CreateAndDispatchWhenReady([InType, InError,this]()
		{
			NetManageMsgDelegate.ExecuteIfBound(InType, InError);
		}, TStatId(), NULL, ENamedThreads::GameThread);
	}
}

uint32 FSimpleNetManage::GetAvailPort()
{
	for (auto &Tmp: Prots)
	{
		if (!Tmp.Value)
		{
			return Tmp.Key;
		}
	}

	return 0;
}

bool FSimpleNetManage::OpenPort(uint32 InPort)
{
	if (bool* B = Prots.Find(InPort))
	{
		*B = true;

		return true;
	}

	return false;
}

bool FSimpleNetManage::ClosePort(uint32 InPort)
{
	if (bool *B = Prots.Find(InPort))
	{
		*B = false;

		return true;
	}

	return false;
}

void FSimpleNetManage::Destroy(FSimpleNetManage* InNetInstance)
{
	if (InNetInstance)
	{
		InNetInstance->Close();

		delete InNetInstance;
		InNetInstance = NULL;
	}
}

bool FSimpleNetManage::CreateCients(int32 InGroupID,const FString& InLinkIP, int32 InPort, int32 InClientNumber, UClass* InClass, bool bNewAllowSynchronization , ESimpleSocketType InType)
{
	Clients.Add(InGroupID, TArray<FSimpleNetManage*>());
	TArray<FSimpleNetManage*> &InArray = Clients[InGroupID];

	for (int32 i = 0; i < InClientNumber; i++)
	{
		if (FSimpleNetManage* InNewClientManage = CreateManage(ESimpleNetLinkState::LINKSTATE_CONNET, InType))
		{
			//绑定反射对象
			if (InClass)
			{
				InNewClientManage->NetworkObjectClass = InClass;
			}

			//是否支持同步操作
			InNewClientManage->SetAllowSynchronization(bNewAllowSynchronization);

			if (InLinkIP.IsEmpty())
			{
				if (!InNewClientManage->Init(InPort))
				{
					delete InNewClientManage;

					check(0);
					return false;
				}
			}
			else
			{
				if (!InNewClientManage->Init(InLinkIP,InPort))
				{
					delete InNewClientManage;

					check(0);
					return false;
				}
			}

			//是哪个组类别
			InNewClientManage->SetGroupID(InGroupID);

			//是否可以受到握手成功
			InNewClientManage->NetManageMsgDelegate.BindUObject(InNewClientManage->GetController(), &USimpleController::LinkServerInfo);

			InArray.Add(InNewClientManage);
		}
	}

	return true;
}

void FSimpleNetManage::DestroyClients(int32 InGroupID)
{
	if (InGroupID != INDEX_NONE)
	{
		for (auto &Tmp : Clients[InGroupID])
		{
			FSimpleNetManage::Destroy(Tmp);
		}
	}
	else
	{
		for (auto& Tmp : Clients)
		{
			for (auto &SubTmp : Tmp.Value)
			{
				FSimpleNetManage::Destroy(SubTmp);
			}
		}
	}
}

FSimpleNetManage* FSimpleNetManage::FindClientFree(int32 InGroupID)
{
	TArray<FSimpleNetManage*> &InClients = Clients[InGroupID];
	auto FindFree = [&]()->FSimpleNetManage*
	{
		for (auto& Tmp : InClients)
		{
			//暂时先这么写
			if (1)
			{
				return Tmp;
			}
		}

		return nullptr;
	};

	float FreeOutTime = 10.f;
	while (true)
	{
		if (FSimpleNetManage *InNewNetManage = FindFree())
		{
			return InNewNetManage;
		}

		FPlatformProcess::Sleep(0.1f);
		FreeOutTime += 0.1f;

		if (FreeOutTime >= 10.f)
		{
			return nullptr;
		}
	}

	return nullptr;
}

void FSimpleNetManage::TickClients(float DeltaTime)
{
	for (auto& Tmp : Clients)
	{
		for (auto& SubTmp : Tmp.Value)
		{
			SubTmp->Tick(DeltaTime);
		}
	}
}

TSharedPtr<FSimpleConnetion> FSimpleNetManage::FindConnetionFree(int32 InGroupID)
{
	float FreeOutTime = 10.f;
	while (true)
	{
		if (TSharedPtr<FSimpleConnetion> InNewConnetion = Net[InGroupID])
		{
			return InNewConnetion;
		}

		FPlatformProcess::Sleep(0.1f);
		FreeOutTime += 0.1f;

		if (FreeOutTime >= 10.f)
		{
			return nullptr;
		}
	}

	return nullptr;
}

void FSimpleNetManage::SetGroupID(int32 InNewGroupID)
{
	Net.LocalConnetion->SetGroupID(InNewGroupID);
}

TSharedPtr<FSimpleConnetion> FSimpleNetManage::FindConnetion(TSharedPtr<FInternetAddr> InAddr)
{
	return Net[InAddr];
}

USimpleController* FSimpleNetManage::GetController()
{
	if (FSimpleChannel *InChannel = GetChannel())
	{
		return InChannel->GetNetObject<USimpleController>();
	}

	return NULL;
}

USimpleNetworkObject* FSimpleNetManage::GetNetworkObject(uint32 InIP, uint32 InPort, const FGuid& InChannelID)
{
	if (FSimpleChannel * SimpleChannel = GetChannel(InIP, InPort, InChannelID))
	{
		return SimpleChannel->GetNetObject();
	}

	return nullptr;
}

FSimpleChannel* FSimpleNetManage::GetChannel()
{
	return Net.LocalConnetion->GetMainChannel();
}

FSimpleChannel* FSimpleNetManage::GetChannel(uint32 InIP, uint32 InPort, const FGuid& InChannelID)
{
	if (InPort >= 0 && InPort < 65535)
	{
		if (ISocketSubsystem* SocketSubsystem = FSimpleConnetion::GetSocketSubsystem())
		{
			TSharedRef<FInternetAddr> TempLocalAddr = SocketSubsystem->CreateInternetAddr();
			TempLocalAddr->SetIp(InIP);
			TempLocalAddr->SetPort(InPort);
			if (TSharedPtr<FSimpleConnetion> InConnetion = Net[TempLocalAddr])
			{
				return InConnetion->GetChannel(InChannelID);
			}
		}
	}
	
	return nullptr;
}

bool FSimpleNetManage::IsPortAvailable(const uint32 InPort)
{
	// 获取默认的套接字子系统
	ISocketSubsystem* SocketSubsystem = FSimpleConnetion::GetSocketSubsystem();
	if (!SocketSubsystem)
	{
		return false;
	}

	// 创建TCP套接字
	FSocket* TestSocket = SocketSubsystem->CreateSocket(NAME_Stream, TEXT("TestSocket"), false);
	if (!TestSocket)
	{
		return false;
	}

	// 设置套接字地址
	TSharedRef<FInternetAddr> Addr = SocketSubsystem->CreateInternetAddr();
	Addr->SetAnyAddress();
	Addr->SetPort(InPort);

	// 尝试绑定到指定端口，不实际监听
	bool bCanBind = TestSocket->Bind(*Addr);

	// 清理
	TestSocket->Close();
	SocketSubsystem->DestroySocket(TestSocket);

	return bCanBind;
}

void FSimpleNetManage::ResetLocalConnetion()
{

}

TSharedPtr<FSimpleConnetion> FSimpleNetManage::CreateConnetion() const
{
	return nullptr;
}

bool FSimpleNetManage::CloseSocket()
{
	return false;
}

TStatId FSimpleNetManage::GetStatId() const
{
	return TStatId();
}

void FSimpleNetManage::Close()
{
	Net.LocalConnetion->Close();

	if (LinkState == ESimpleNetLinkState::LINKSTATE_LISTEN)
	{
		for (auto &Tmp : Net.RemoteConnetions)
		{
			Tmp->Close();
		}
	}
}

void FSimpleNetManage::Close(const TSharedPtr<FInternetAddr>& InternetAddr)
{
	if (TSharedPtr<FSimpleConnetion> ConnetionInstance = Net[InternetAddr])
	{
		ConnetionInstance->Close();
	}
}

FSimpleNetManage::FSimpleNetManage()
	:NetworkObjectClass(NULL)
	,SimplePlayerClass(NULL)
	,bInit(false)
	,bClientLink(false)
{
	bAllowSynchronization = false;
}

int32 FSimpleNetManage::GetConnetionNum()
{
	int32 Num = 0;
	for (auto &Tmp : Net.RemoteConnetions)
	{
		if (Tmp->GetState() == ESimpleConnetionLinkType::LINK_JOIN)
		{
			Num++;
		}
	}

	return Num;
}

FSimpleAddr FSimpleNetManage::GetAddr()
{
	FSimpleAddr Addr;
	TSharedRef<FInternetAddr>InternetAddr = Net.LocalConnetion->GetAddr();

	//Construct addr
	uint32 MyIP = 0;
	InternetAddr->GetIp(MyIP);
	Addr.IP = MyIP;

	Addr.Port = InternetAddr->GetPort();

	return Addr;
}

void FSimpleNetManage::LinkTimeout(const FString& InTimeoutMsg)
{
	NetManageMsgDelegate.ExecuteIfBound(ESimpleNetErrorType::TIME_OUT, TEXT("Link timeout."));

	Close();
}

void FSimpleNetManage::FNet::Clear(int32 InIndex)
{
	if (InIndex >= 0 && InIndex < RemoteConnetions.Num())
	{
		RemoteConnetions[InIndex]->SetState(ESimpleConnetionLinkType::LINK_UNINITIALIZED);
	}
}

int32 FSimpleNetManage::FNet::Add(TSharedPtr<FInternetAddr> InternetAddr)
{
	for (int32 i = 0; i < RemoteConnetions.Num();i++)
	{
		if (RemoteConnetions[i]->GetState() == ESimpleConnetionLinkType::LINK_UNINITIALIZED)
		{
			RemoteConnetions[i]->Init();

			bool bBindAddr = false;
			RemoteConnetions[i]->GetRemoteAddr()->SetIp(*InternetAddr->ToString(false), bBindAddr);
			RemoteConnetions[i]->GetRemoteAddr()->SetPort(InternetAddr->GetPort());

			RemoteConnetions[i]->SetState(ESimpleConnetionLinkType::LINK_LOGIN);

			return i;
		}
	}

	return INDEX_NONE;
}

bool FSimpleNetManage::FNet::IsAddr(TSharedPtr<FInternetAddr> InternetAddr)
{
	for (auto &Connetion : RemoteConnetions)
	{
		if (*Connetion->GetRemoteAddr() == *InternetAddr)
		{
			return true;
		}
	}

	return false;
}

TSharedPtr<FSimpleConnetion> FSimpleNetManage::FNet::operator[](TSharedPtr<FInternetAddr> InternetAddr)
{
	for (auto& Connetion : RemoteConnetions)
	{
		if (*Connetion->GetRemoteAddr() == *InternetAddr)
		{
			return Connetion;
		}
	}

	return NULL;
}

TSharedPtr<FSimpleConnetion> FSimpleNetManage::FNet::operator[](const FSimpleAddr& InternetAddr)
{
	for (auto& Tmp : RemoteConnetions)
	{
		uint32 MyPort = Tmp->GetRemoteAddr()->GetPort();
		uint32 MyIP = 0;
		Tmp->GetRemoteAddr()->GetIp(MyIP);

		if (MyIP == InternetAddr.IP && MyPort == InternetAddr.Port)
		{
			return Tmp;
		}
	}

	return NULL;
}

TSharedPtr<FSimpleConnetion> FSimpleNetManage::FNet::operator[](const int32 InGroupID)
{
	for (auto& Connetion : RemoteConnetions)
	{
		if (Connetion->GetGroupID() == InGroupID)
		{
			if (true)//判定当前状态是否空闲
			{
				return Connetion;
			}		
		}
	}

	return nullptr;
}

TSharedPtr<FSimpleConnetion> FSimpleNetManage::FNet::GetEmptyConnetion(TSharedPtr<FInternetAddr> InternetAddr)
{
	for (int32 i =0 ;i < RemoteConnetions.Num();i++)
	{
		if (TSharedPtr<FSimpleConnetion> InConnetion = RemoteConnetions[i])
		{	
			if (InConnetion->GetState() == ESimpleConnetionLinkType::LINK_UNINITIALIZED)
			{
				if (!InConnetion->IsLock())
				{				
					InConnetion->SetRemoteAddr(InternetAddr);

					InConnetion->Lock();

					InConnetion->Init();

					return InConnetion;
				}
			}
		}
	}

	return NULL;
}

FString FSimpleNetManage::GetAddrString(const FSimpleAddr& InAddr)
{
	FString IPAddrString;
	if (TSharedPtr<FInternetAddr> TempLocalAddr = GetInternetAddr(InAddr))
	{
		IPAddrString = TempLocalAddr->ToString(true);
	}

	return IPAddrString;
}

TSharedPtr<FInternetAddr> FSimpleNetManage::GetInternetAddr(const FSimpleAddr& InAddr)
{
	if (ISocketSubsystem* SocketSubsystem = FSimpleConnetion::GetSocketSubsystem())
	{
		TSharedRef<FInternetAddr> TempLocalAddr = SocketSubsystem->CreateInternetAddr();
		TempLocalAddr->SetIp(InAddr.IP);
		TempLocalAddr->SetPort(InAddr.Port);

		return TempLocalAddr;
	}

	return nullptr;
}

FSimpleAddr FSimpleNetManage::GetSimpleAddr(TSharedPtr<FInternetAddr> InAddr)
{
	FSimpleAddr SimpleAddr;
	SimpleAddr.Port = InAddr->GetPort();

	uint32 MyIP = 0;
	InAddr->GetIp(MyIP);
	SimpleAddr.IP = MyIP;

	return SimpleAddr;
}

FSimpleAddr FSimpleNetManage::GetSimpleAddr(const TCHAR* InIP, uint32 InPort)
{
	FSimpleAddr Addr;
	if (ISocketSubsystem* SocketSubsystem = FSimpleConnetion::GetSocketSubsystem())
	{
		TSharedRef<FInternetAddr> TempLocalAddr = SocketSubsystem->CreateInternetAddr();
		
		bool bIsValid = false;
		TempLocalAddr->SetIp(InIP, bIsValid);
		if (bIsValid)
		{
			TempLocalAddr->SetPort(InPort);

			uint32 MyIP = 0;
			TempLocalAddr->GetIp(MyIP);
			Addr.IP = MyIP;

			Addr.Port = TempLocalAddr->GetPort();
		}
	}

	return Addr;
}

void FSimpleNetManage::GetLocalIPAndPort(FString& InIP, uint32& Port)
{
	if (FSimpleNetGlobalInfo::Get()->GetInfo().PublicIP.IsEmpty())
	{
		bool EnableBind = false;
		TSharedRef<FInternetAddr> LocalAddr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->GetLocalHostAddr(*GLog, EnableBind);

		InIP = LocalAddr->ToString(false);
	}
	else
	{
		InIP = FSimpleNetGlobalInfo::Get()->GetInfo().PublicIP;
	}

	Port = 7777;
}

bool FSimpleNetManage::AddrEquation(TSharedPtr<FInternetAddr> InAAddr, TSharedPtr<FInternetAddr> InBAddr)
{
	FSimpleAddr A = GetSimpleAddr(InAAddr);
	FSimpleAddr B = GetSimpleAddr(InAAddr);

	return A.IP == B.IP && A.Port == B.Port;
}

USimpleNetworkObject* FSimpleNetManage::GetNetManageNetworkObject(FSimpleNetManage* InSimpleNetManage, const FSimpleAddrInfo& AddrInfo)
{
	//AddrInfo 这个地址是远端还是 本地？
	if (InSimpleNetManage)
	{
		//先找远端
		if (FSimpleChannel* SimpleChannel = InSimpleNetManage->GetChannel(AddrInfo.Addr.IP, AddrInfo.Addr.Port, AddrInfo.ChannelID))
		{
			return SimpleChannel->GetNetObject();
		}
		else //也有可能是主通道 找本地
		{
			FSimpleAddrInfo InMainAddrInfo;
			InSimpleNetManage->GetChannel()->GetLocalAddrInfo(InMainAddrInfo);
			if (InMainAddrInfo == AddrInfo)
			{
				return InSimpleNetManage->GetChannel()->GetNetObject();
			}
		}
	}

	return NULL;
}

#if PLATFORM_WINDOWS
#pragma optimize("",on) 
#endif