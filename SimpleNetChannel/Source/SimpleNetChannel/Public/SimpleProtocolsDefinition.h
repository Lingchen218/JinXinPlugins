// Copyright (C) RenZhai.2021.All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Channel/SimpleChannel.h"
#include "Stream/SimpleIOStream.h"
#include "SimpleNetChannelType.h"


template<uint32 ProtocolsType>
class FSimpleProtocols{};

#define SNC_TIMESCOPE(ContentString) SimpleNetChannel::FTimeCount __TimeCount(ContentString);

#define DEFINITION_SIMPLE_BUFFER  \
TArray<uint8> Buffer; \
FSimpleIOStream Stream(Buffer);

#define DEFINITION_SIMPLE_HEARD(ProtocolsName,InbValue) \
FSimpleBunchHead Head; \
Head.ProtocolsNumber = (uint32)SP_##ProtocolsName;\
Head.ParamNum = (uint8)FRecursionMessageInfo::GetBuildParams(Params...); \
Head.ChannelID = InChannel->GetGuid(); \
Head.bAsynchronous = InbValue; \
Stream << Head;

class SIMPLENETCHANNEL_API FRecursionMessageInfo
{
public:
	template<typename ...ParamTypes>
	static int32 GetBuildParams(ParamTypes &...Param)
	{
		return sizeof...(Param);
	}

	template<typename ...ParamTypes>
	static void BuildSendParams(FSimpleIOStream& InStream, ParamTypes &...Param){}
	
	//Input parameters to the stream recursively
	template<class T,typename ...ParamTypes>
	static void BuildSendParams(FSimpleIOStream& InStream, T& FirstParam, ParamTypes &...Param)
	{
		InStream << FirstParam;
		BuildSendParams(InStream, Param...);
	}

	template<typename ...ParamTypes>
	static void BuildReceiveParams(FSimpleIOStream& InStream, ParamTypes &...Param) {}

	template<class T, typename ...ParamTypes>
	static void BuildReceiveParams(FSimpleIOStream& InStream, T& FirstParam, ParamTypes &...Param)
	{
		InStream >> FirstParam;
		BuildReceiveParams(InStream, Param...);
	}
};

#define DEFINITION_PROTOCOLS(ProtocolsName,ProtocolsNumber,bForceSend,bAsynchronous) \
enum{SP_##ProtocolsName = ProtocolsNumber}; \
template<> class SIMPLENETCHANNEL_API FSimpleProtocols<ProtocolsNumber> \
{ \
public: \
	template<typename ...ParamTypes> \
	static void Send(FSimpleChannel* InChannel,TSharedPtr<FInternetAddr> InAddr,ParamTypes &...Params) \
	{ \
		DEFINITION_SIMPLE_BUFFER \
		DEFINITION_SIMPLE_HEARD(ProtocolsName,bAsynchronous) \
		FRecursionMessageInfo::BuildSendParams(Stream, Params...); \
		InChannel->Send(Buffer,InAddr,bForceSend);\
	} \
	template<typename ...ParamTypes> \
	static void Receive(FSimpleChannel* InChannel,ParamTypes &...Params) \
	{ \
		DEFINITION_SIMPLE_BUFFER \
		if (InChannel->Receive(Buffer)) \
		{ \
			Stream.Seek(sizeof(FSimpleBunchHead)); \
			FRecursionMessageInfo::BuildReceiveParams(Stream,Params...); \
		} \
	} \
	template<typename ...ParamTypes> \
	static void BuildBytes(FSimpleChannel* InChannel,TArray<uint8> &OutBuffer,ParamTypes &...Params) \
	{ \
		DEFINITION_SIMPLE_BUFFER(Buffer); \
		DEFINITION_SIMPLE_HEARD(ProtocolsName,bAsynchronous) \
		FRecursionMessageInfo::BuildSendParams(Stream,Params...); \
		InChannel->BuildBytes(Buffer,OutBuffer,bForceSend);\
	} \
};

//针对异步
#define DEFINITION_SIMPLE_PROTOCOLS(ProtocolsName,ProtocolsNumber) DEFINITION_PROTOCOLS(ProtocolsName,ProtocolsNumber,false,true)
#define DEFINITION_SIMPLE_PROTOCOLS_FORCE(ProtocolsName,ProtocolsNumber) DEFINITION_PROTOCOLS(ProtocolsName,ProtocolsNumber,true,true)

//针对同步
#define DEFINITION_SIMPLE_PROTOCOLS_SYNCHRONIZE(ProtocolsName,ProtocolsNumber) DEFINITION_PROTOCOLS(ProtocolsName,ProtocolsNumber,false,false)
#define DEFINITION_SIMPLE_PROTOCOLS_FORCE_SYNCHRONIZE(ProtocolsName,ProtocolsNumber) DEFINITION_PROTOCOLS(ProtocolsName,ProtocolsNumber,true,false)

#if/* PLATFORM_IOS ||*/ PLATFORM_ANDROID
//发送当前
#define SIMPLE_PROTOCOLS_SEND(InProtocols,args...) FSimpleProtocols<InProtocols>::Send(Channel,Channel->GetRemoteAddr(),##args);
//需要提供一个地址 一般主通道 使用 也允许个人使用
#define SIMPLE_PROTOCOLS_SEND_ADDR(InProtocols,Addr,args...) FSimpleProtocols<InProtocols>::Send(Channel,Addr,##args);

#define SIMPLE_PROTOCOLS_RECEIVE(InProtocols,args...) FSimpleProtocols<InProtocols>::Receive(Channel,##args);

//用于构建参数字节
#define SIMPLE_PROTOCOLS_BUILD_BYTES(InProtocols,OutBytes,args...) FSimpleProtocols<InProtocols>::BuildBytes(Channel,OutBytes,##args);

//Make sure simplemannage is the connection side
#define SIMPLE_CLIENT_SEND(SimpleManage,InProtocols,args...) \
if (SimpleManage && SimpleManage->GetController()) \
{ \
	if (FSimpleChannel* SimpleChannel_SIMPLE = SimpleManage->GetChannel()) \
	{ \
		FSimpleProtocols<InProtocols>::Send(SimpleChannel_SIMPLE,SimpleChannel_SIMPLE->GetRemoteAddr(),##args); \
	} \
}

//Make sure simplemannage is the connection side
#define SIMPLE_CLIENT_RECV(SimpleManage,InProtocols,args...) \
if (SimpleManage && SimpleManage->GetController()) \
{ \
	if (FSimpleChannel* SimpleChannel_SIMPLE = SimpleManage->GetChannel()) \
	{ \
		FSimpleProtocols<InProtocols>::Receive(SimpleChannel_SIMPLE,##args); \
	} \
}

//To ensure simplemannage, the listening server must call our listening port through other terminals to send data to other remote terminals
#define SIMPLE_SERVER_SEND(SimpleManage,InProtocols,AddrInfo,args...) \
if (SimpleManage && SimpleManage->GetController()) \
{ \
	if (FSimpleChannel* SimpleChannel_SIMPLE = SimpleManage->GetChannel(AddrInfo.Addr.IP,AddrInfo.Addr.Port,AddrInfo.ChannelID)) \
	{ \
		FSimpleProtocols<InProtocols>::Send(SimpleChannel_SIMPLE,SimpleChannel_SIMPLE->GetRemoteAddr(),##args); \
	} \
}

//针对批量客户端(将客户端作为传输使用)回复情况 
//To ensure simplemannage, the listening server must call our listening port through other terminals to send data to other remote terminals
#define SIMPLE_SERVER_SEND_TO_CLIENTS(GroupID,InProtocols,args...) \
if (TSharedPtr<FSimpleConnetion> InSimpleConnetion = FindConnetionFree((int32)GroupID))\
{\
	if (FSimpleChannel* SimpleChannel_SIMPLE = InSimpleConnetion->GetMainChannel()) \
	{ \
		FSimpleProtocols<InProtocols>::Send(SimpleChannel_SIMPLE,SimpleChannel_SIMPLE->GetRemoteAddr(), ##args); \
	} \
}

//To ensure simplemannage, the listening server must call our listening port through other terminals to send data to other remote terminals
#define SIMPLE_SERVER_RECV(SimpleManage,InProtocols,AddrInfo,args...) \
if (SimpleManage && SimpleManage->GetController()) \
{ \
	if (FSimpleChannel* SimpleChannel_SIMPLE = SimpleManage->GetChannel(AddrInfo.IP,AddrInfo.Port,AddrInfo.ChannelID)) \
	{ \
		FSimpleProtocols<InProtocols>::Receive(SimpleChannel_SIMPLE,##args); \
	} \
}

#define SIMPLE_SERVER_MULTICAST_SEND(SimpleManage,InProtocols,InType,Code,args...) \
if (SimpleManage)\
{\
	SimpleManage->MulticastByPredicate<InProtocols,InType>(Code,##args);\
}

#else
//需要提供一个地址 一般主通道 使用 也允许个人使用
#define SIMPLE_PROTOCOLS_SEND_ADDR(InProtocols,Addr,...) FSimpleProtocols<InProtocols>::Send(Channel,Addr,##__VA_ARGS__);

//发送当前
#define SIMPLE_PROTOCOLS_SEND(InProtocols,...) FSimpleProtocols<InProtocols>::Send(Channel,Channel->GetRemoteAddr(),##__VA_ARGS__);

//用于构建参数字节
#define SIMPLE_PROTOCOLS_BUILD_BYTES(InProtocols,OutBytes,...) FSimpleProtocols<InProtocols>::BuildBytes(Channel,OutBytes,##__VA_ARGS__);

//接收
#define SIMPLE_PROTOCOLS_RECEIVE(InProtocols,...) FSimpleProtocols<InProtocols>::Receive(Channel,##__VA_ARGS__);

//Make sure simplemannage is the connection side
#define SIMPLE_CLIENT_SEND(SimpleManage,InProtocols,...) \
if (SimpleManage && SimpleManage->GetController()) \
{ \
	if (FSimpleChannel* SimpleChannel_SIMPLE = SimpleManage->GetChannel()) \
	{ \
		FSimpleProtocols<InProtocols>::Send(SimpleChannel_SIMPLE,SimpleChannel_SIMPLE->GetRemoteAddr(),##__VA_ARGS__); \
	} \
}

//针对服务端的同步接受
//Make sure simplemannage is the connection side
#define SIMPLE_CLIENT_RECV(SimpleManage,InProtocols,...) \
if (SimpleManage && SimpleManage->GetController()) \
{ \
	if (FSimpleChannel* SimpleChannel_SIMPLE = SimpleManage->GetChannel()) \
	{ \
		FSimpleProtocols<InProtocols>::Receive(SimpleChannel_SIMPLE,##__VA_ARGS__); \
	} \
}

//To ensure simplemannage, the listening server must call our listening port through other terminals to send data to other remote terminals
#define SIMPLE_SERVER_SEND(SimpleManage,InProtocols,AddrInfo,...) \
if (SimpleManage && SimpleManage->GetController()) \
{ \
	if (FSimpleChannel* SimpleChannel_SIMPLE = SimpleManage->GetChannel(AddrInfo.Addr.IP,AddrInfo.Addr.Port,AddrInfo.ChannelID)) \
	{ \
		FSimpleProtocols<InProtocols>::Send(SimpleChannel_SIMPLE,SimpleChannel_SIMPLE->GetRemoteAddr(),##__VA_ARGS__); \
	} \
}

//针对组链接发送
#define SIMPLE_GROUP_SERVER_SEND(SimpleManage,InProtocols,ServerGroupID,...) \
if (SimpleManage && SimpleManage->GetController()) \
{ \
	if (TSharedPtr<FSimpleConnetion> _InNewConnnetion = SimpleManage->FindConnetionFree(ServerGroupID))\
	{\
		if (FSimpleChannel* SimpleChannel_SIMPLE = _InNewConnnetion->GetMainChannel())\
		{\
			FSimpleProtocols<InProtocols>::Send(SimpleChannel_SIMPLE, SimpleChannel_SIMPLE->GetRemoteAddr(), ##__VA_ARGS__); \
		}\
	}\
}

//针对接受服务器的同步
//To ensure simplemannage, the listening server must call our listening port through other terminals to send data to other remote terminals
#define SIMPLE_SERVER_RECV(SimpleManage,InProtocols,AddrInfo,...) \
if (SimpleManage && SimpleManage->GetController()) \
{ \
	if (FSimpleChannel* SimpleChannel_SIMPLE = SimpleManage->GetChannel(AddrInfo.Addr.IP,AddrInfo.Addr.Port,AddrInfo.ChannelID)) \
	{ \
		FSimpleProtocols<InProtocols>::Receive(SimpleChannel_SIMPLE,SimpleChannel_SIMPLE->GetRemoteAddr(),##__VA_ARGS__); \
	} \
}

//针对批量客户端(将客户端作为传输使用)回复情况 
//To ensure simplemannage, the listening server must call our listening port through other terminals to send data to other remote terminals
#define SIMPLE_SERVER_SEND_TO_CLIENTS(GroupID,InProtocols,...) \
if (TSharedPtr<FSimpleConnetion> InSimpleConnetion = FindConnetionFree((int32)GroupID))\
{\
	if (FSimpleChannel* SimpleChannel_SIMPLE = InSimpleConnetion->GetMainChannel()) \
	{ \
		FSimpleProtocols<InProtocols>::Send(SimpleChannel_SIMPLE,SimpleChannel_SIMPLE->GetRemoteAddr(), ##__VA_ARGS__); \
	} \
}

//广播 需要指定SimpleManage 协议 和 对象类型，以及 判断是不是要广播这个对象
#define SIMPLE_SERVER_MULTICAST_SEND(SimpleManage,InProtocols,InType,Code,...) \
if (SimpleManage)\
{\
	SimpleManage->MulticastByPredicate<InProtocols,InType>(Code,##__VA_ARGS__);\
}

//例如
//GetManage()->MulticastByPredicate<SP_ChatResponses,UMMOARPGCenterServerObject>(
//	A,PlayerID, ContentString, Index);

#endif // PLATFORM_WINDOWS

//SIMPLE_PROTOCOLS_SEND(MMM_Test, 12, TEXT("Hello"), 10.f);
//SIMPLE_PROTOCOLS_SEND(SP_Hello, TEXT("asdasd"), 12, 25);
