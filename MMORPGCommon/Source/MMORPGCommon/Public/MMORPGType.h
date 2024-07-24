
#pragma once

#include "CoreMinimal.h"
#include "SimpleNetChannelType.h"

enum ELoginType
{
	LOGIN_DB_SERVER_ERROR,		//db服务器错误
	LOGIN_SUCCESS,				//登录成功
	LOGIN_ACCOUNT_WRONG,		//账户错误
	LOGIN_WRONG_PASSWORD,		//密码错误
};

//玩家账户信息的结构体
struct MMORPGCOMMON_API FMMORPGUserData
{
	FMMORPGUserData()
		:ID(INDEX_NONE)
	{
	}

	int32 ID;
	FString Account;
	FString Email;
	FString Name;
	FString HeadPortraitURL;//头像url

	void Reset();
};

//玩家角色信息的结构体
struct MMORPGCOMMON_API FMMORPGCharacterAppearance
{
	FMMORPGCharacterAppearance()
		:Lv(INDEX_NONE),
		SlotPosition(INDEX_NONE),
		LegSize(0.f),
		WaistSize(0.f),
		ArmSize(0.f),
		HeadSize(0.f),
		ChestSize(0.f)
	{}

	FString Name;
	FString Date;
	int32 Lv;
	int32 SlotPosition;
	float LegSize;
	float WaistSize;
	float ArmSize;
	float HeadSize;
	float ChestSize;

	void Reset();

public:
	bool IsVaild() const { return SlotPosition != INDEX_NONE; }
};

FORCEINLINE bool operator==(const FMMORPGCharacterAppearance& Lhs, const FMMORPGCharacterAppearance& Rhs)
{
	return Lhs.SlotPosition == Rhs.SlotPosition;
}

typedef TArray<FMMORPGCharacterAppearance> FCharacterAppearacnce;

//玩家注册信息
struct MMORPGCOMMON_API FMMORPGPlayerRegistInfo
{
	FMMORPGUserData UserInfo;
	FMMORPGCharacterAppearance CAInfo;

	void Reset();
	bool IsValid();
};

//网关状态结构体
struct MMORPGCOMMON_API FMMORPGGateStatus
{
	FMMORPGGateStatus()
		:GateConnetionNum(INDEX_NONE)
	{}
	int32 GateConnetionNum;					//网关连接人数
	FSimpleAddrInfo GateServerAddrInfo;		//网关服务器地址
};

//检查名字状态的枚举
enum ECheckNameType
{
	UNKNOWN_ERROR,		//未知错误
	NAME_NOT_EXIST,		//名字不存在
	SERVER_NOT_EXIST,	//服务器不存在
	NAME_EXIST,			//名字存在
};

//网络数据解析
namespace NetDataAnalysis
{
	//用户信息
	MMORPGCOMMON_API void UserDataToString(const FMMORPGUserData& InUserData, FString& OutString);
	MMORPGCOMMON_API void StringToUserData(const FString& InString, FMMORPGUserData& OutUserData);
	//角色列表
	MMORPGCOMMON_API void CharacterAppearacnceToString(const FCharacterAppearacnce& InCA, FString& OutString);
	MMORPGCOMMON_API void StringToFCharacterAppearacnce(const FString& InString, FCharacterAppearacnce& OutCA);
	//单个角色
	MMORPGCOMMON_API void CharacterAppearacnceToString(const FMMORPGCharacterAppearance& InCA, FString& OutString);
	MMORPGCOMMON_API void StringToFCharacterAppearacnce(const FString& InString, FMMORPGCharacterAppearance& OutCA);
}