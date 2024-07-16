
#pragma once

#include "CoreMinimal.h"

enum ELoginType
{
	LOGIN_DB_SERVER_ERROR,		//db服务器错误
	LOGIN_SUCCESS,				//登录成功
	LOGIN_ACCOUNT_WRONG,		//账户错误
	LOGIN_WRONG_PASSWORD,		//密码错误
};

//用户信息的结构体
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

//网络数据解析
namespace NetDataAnalysis
{
	void UserDataToString(const FMMORPGUserData& InUserData, FString& OutString);
	void StringToUserData(const FString& InString, FMMORPGUserData& OutUserData);
}