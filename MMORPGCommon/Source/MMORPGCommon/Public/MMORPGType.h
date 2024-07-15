
#pragma once

#include "CoreMinimal.h"

enum ELoginType
{
	LOGIN_DB_SERVER_ERROR,		//db服务器错误
	LOGIN_SUCCESS,				//登录成功
	LOGIN_ACCOUNT_WRONG,		//账户错误
	LOGIN_WRONG_PASSWORD,		//密码错误
};