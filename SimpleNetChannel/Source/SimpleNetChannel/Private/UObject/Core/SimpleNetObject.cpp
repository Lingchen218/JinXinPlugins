// Copyright (C) RenZhai.2021.All Rights Reserved.

#include "UObject/Core/SimpleNetObject.h"
#include "SimpleNetManage.h"
#include "Protocols/SimpleNetProtocols.h"
#include "Global/SimpleNetGlobalInfo.h"

USimpleNetworkObject::USimpleNetworkObject()
{
	bPing = false;
	PingTime = 0.f;
}

void USimpleNetworkObject::Init()
{
	
}

void USimpleNetworkObject::Tick(float DeltaTime)
{
	//检测ping是否超时
	if (bPing)
	{
		if (GetConnetion())
		{
			if (GetConnetion()->GetState() == ESimpleConnetionLinkType::LINK_JOIN)
			{
				PingTime += DeltaTime;
				if (PingTime >= FSimpleNetGlobalInfo::Get()->GetInfo().PingMaxOutTime)
				{
					//超时
					PingTime = 0.f;

					bPing = false;

					BuildUnlinked(ESimpleNetManagePingType::OUTTIME);
				}
			}
		}	
	}
}

TSharedPtr<FSimpleConnetion > USimpleNetworkObject::GetConnetion()
{
	if (Channel)
	{
		return Channel->GetConnetion();
	}

	return NULL;
}

FSimpleNetManage* USimpleNetworkObject::GetManage()
{
	if (TSharedPtr<FSimpleConnetion >ConnetionPtr = GetConnetion())
	{
		return ConnetionPtr->GetManage();
	}

	return NULL;
}

void USimpleNetworkObject::DestroySelf()
{
	if (Channel)
	{
		Channel->DestroySelf();
	}
}

void USimpleNetworkObject::Ping()
{
	if (GetConnetion()->GetState() == ESimpleConnetionLinkType::LINK_JOIN)
	{
		SIMPLE_PROTOCOLS_SEND(SP_PingRequest);

		bPing = true;
	}
	else
	{
		BuildUnlinked(ESimpleNetManagePingType::INCOMPLETELINK);
	}
}

void USimpleNetworkObject::BuildUnlinked(ESimpleNetManagePingType InType)
{
	//构建一个模拟服务器发送
	TArray<uint8> OutBytes;

	//拼一个二进制链接
	SIMPLE_PROTOCOLS_BUILD_BYTES(SP_PingResponse, OutBytes, InType);

	//接受协议后处理
	GetConnetion()->RecvByRemote(OutBytes.Num(), OutBytes.GetData());
}

bool USimpleNetworkObject::IsMainConnetion()
{
	check(GetConnetion());

	return GetConnetion()->GetConnetionType()== ESimpleConnetionType::CONNETION_MAIN_LISTEN;
}

void USimpleNetworkObject::Close()
{
	RecvDelegate.Clear();
}

bool USimpleNetworkObject::GetServerAddrInfo(FSimpleAddrInfo& InAddrInfo)
{
	return GetLocalAddrInfo(InAddrInfo);
}

bool USimpleNetworkObject::GetAddrInfo(FSimpleAddrInfo& InAddrInfo)
{
	return GetRemoteAddrInfo(InAddrInfo);
}

void USimpleNetworkObject::RecvProtocol(uint32 InProtocol)
{
	switch (InProtocol)
	{
		case SP_PingResponse:
		{
			//超时
			PingTime = 0.f;
			
			bPing = false;
			break;
		}
	}

	if (RecvDelegate.IsBound())
	{
		RecvDelegate.Broadcast(InProtocol, Channel);
	}
}

FSimpleChannel* USimpleNetworkObject::GetChannel()
{
	return Channel;
}

bool USimpleNetworkObject::GetRemoteAddrInfo(FSimpleAddrInfo& InAddrInfo)
{
	if (Channel)
	{
		return Channel->GetRemoteAddrInfo(InAddrInfo);
	}

	return false;
}

bool USimpleNetworkObject::GetLocalAddrInfo(FSimpleAddrInfo& InAddrInfo)
{
	if (GetManage() && GetManage()->GetChannel())
	{
		return GetManage()->GetChannel()->GetLocalAddrInfo(InAddrInfo);
	}

	return false;
}