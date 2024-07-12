// Copyright (C) RenZhai.2021.All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SimpleNetChannelType.generated.h"

UENUM(BlueprintType)
enum class ESimpleNetManagePingType :uint8
{
	OK						=0	,//链接
	UNBOUND						,//未绑定
	UNREGISTERED				,//未注册
	INCOMPLETELINK				,//未完成链接
	OUTTIME						,//超时
};

UENUM(BlueprintType)
enum class ESimpleNetManageCallType :uint8
{
	INPROGRESS,
	PROGRESS_COMPLETE
};

UENUM(BlueprintType)
enum class ESimpleNetLinkState :uint8
{
	LINKSTATE_LISTEN,
	LINKSTATE_CONNET,
};

UENUM(BlueprintType)
enum class ESimpleConnetionType :uint8
{
	CONNETION_MAIN_LISTEN,
	CONNETION_LISTEN,
};

UENUM(BlueprintType)
enum class ESimpleSocketType :uint8
{
	SIMPLESOCKETTYPE_UDP,
	SIMPLESOCKETTYPE_TCP,
};

UENUM(BlueprintType)
enum class ESimpleConnetionLinkType :uint8
{
	LINK_UNINITIALIZED,//
	LINK_VERIFICATION, //
	LINK_LOGIN, //
	LINK_JOIN, //
};

struct SIMPLENETCHANNEL_API FSimplePackageHead
{
	FSimplePackageHead();

	uint32 Protocol;//
	uint32 PackageIndex;
	uint32 PackageSize;
	bool bAck;
	bool bForceSend;
	uint64 Tag;//针对同步
	FGuid PackageID;
	FGuid ChannelID;
};

struct SIMPLENETCHANNEL_API FSimpleBunchHead
{
	FSimpleBunchHead();

	FGuid ChannelID;
	uint64 Tag;//针对本次同步标志
	uint32 ProtocolsNumber;//协议号
	uint8 ParamNum;
	bool bAsynchronous;//异步
};

USTRUCT(BlueprintType, Meta = (Proto))
struct SIMPLENETCHANNEL_API FSimpleAddr
{
	GENERATED_BODY()

	FSimpleAddr();
	FSimpleAddr(const FString& InIP, uint32 InPort);

	UPROPERTY()
	int64 IP;

	UPROPERTY()
	int64 Port;

	friend inline uint32 GetTypeHash(const FSimpleAddr& InKey)
	{
		uint32 Hash = 0;
		Hash = HashCombine(Hash, GetTypeHash(InKey.IP + InKey.Port));
		return Hash;
	}
};

inline bool operator==(const FSimpleAddr& L, const FSimpleAddr& R)
{
	return L.IP == R.IP && L.Port == R.Port;
}

USTRUCT(BlueprintType,Meta = (Proto))
struct SIMPLENETCHANNEL_API FSimpleAddrInfo
{
	FSimpleAddrInfo();

	GENERATED_BODY()

	UPROPERTY()
	FSimpleAddr Addr;

	UPROPERTY()
	FGuid ChannelID;
};

inline bool operator==(const FSimpleAddrInfo& L, const FSimpleAddrInfo& R)
{
	return L.Addr == R.Addr && L.ChannelID == R.ChannelID;
}

USTRUCT(BlueprintType)
struct SIMPLENETCHANNEL_API FSimpleConfigInfo
{
	GENERATED_BODY()

	FSimpleConfigInfo();

	UPROPERTY(Config)
	FString Version;

	UPROPERTY(Config)
	FString URL;

	UPROPERTY(Config)
	int32 Port;

	UPROPERTY(Config)
	FIntVector2 PortRange;

	UPROPERTY(Config)
	int32 RecvDataNumber;

	UPROPERTY(Config)
	int32 SendDataNumber;

	UPROPERTY(Config)
	int32 MaxConnections;

	UPROPERTY(Config)
	int32 MaxChannels;

	UPROPERTY(Config)
	int32 RepackagingFrequency;

	//指定线程池应该有多少线程
	UPROPERTY(Config)
	int32 NumberThreads;

	UPROPERTY(Config)
	bool bPrintHeartBeat;

	UPROPERTY(Config)
	bool bSlidingWindow;

	UPROPERTY(Config)
	bool bRepackaging;

	UPROPERTY(Config)
	bool bShowCompletePackProtocolInfo;

	UPROPERTY(Config)
	bool bShowSendDebug;

	UPROPERTY(Config)
	float RepackagingTime;

	UPROPERTY(Config)
	float OutTimeLink;

	UPROPERTY(Config)
	float OutTimeSynchronizationTime;

	UPROPERTY(Config)
	float HeartBeatTimeTnterval;

	UPROPERTY(Config)
	float PingMaxOutTime;

	UPROPERTY(Config)
	FString PublicIP;
	 
	UPROPERTY(Config)
	FString SecretKey;
};

UENUM(BlueprintType)
enum ESimpleNetErrorType
{
	NET_NONE,
	TIME_OUT,
	INIT_FAIL,
	INIT_SUCCESS,
	HAND_SHAKE_SUCCESS,
	HAND_SHAKE_FAIL,
	INVALID_VALIDATION,
};	

namespace SimpleNetChannel
{
	//记录并且打印时间
	struct SIMPLENETCHANNEL_API FTimeCount
	{
		FTimeCount(const FString& InLogContent);
		~FTimeCount();

	protected:
		FString LogContent;
		double Time;
	};
}