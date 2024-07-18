
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
};

//玩家角色信息的结构体
struct MMORPGCOMMON_API FMMORPGCharacterAppearance
{
	FMMORPGCharacterAppearance()
		:Lv(INDEX_NONE)
	{}

	FString Name;
	int32 Lv;
};

typedef TArray<FMMORPGCharacterAppearance> FCharacterAppearacnce;

//网关状态结构体
struct MMORPGCOMMON_API FMMORPGGateStatus
{
	FMMORPGGateStatus()
		:GateConnetionNum(INDEX_NONE)
	{}
	int32 GateConnetionNum;					//网关连接人数
	FSimpleAddrInfo GateServerAddrInfo;		//网关服务器地址
};

//网络数据解析
namespace NetDataAnalysis
{
	MMORPGCOMMON_API void UserDataToString(const FMMORPGUserData& InUserData, FString& OutString);
	MMORPGCOMMON_API void StringToUserData(const FString& InString, FMMORPGUserData& OutUserData);

	MMORPGCOMMON_API void CharacterAppearacnceToString(const FCharacterAppearacnce& InCA, FString& OutString);
	MMORPGCOMMON_API void StringToFCharacterAppearacnce(const FString& InString, FCharacterAppearacnce& OutCA);
}