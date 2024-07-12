// Copyright (C) RenZhai.2020.All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SimpleHTTPType.h"

namespace SimpleHTTP
{
	//如果里面包含中文字符，会进行特殊处理，防止字符因为特殊导致HTTP错误
	FString SIMPLEHTTP_API SimpleURLEncode(const TCHAR* InUnencodedString);

	FString SIMPLEHTTP_API ToSimpleHTTPVerbTypeString(ESimpleHTTPVerbType InType);
	ESimpleHTTPVerbType SIMPLEHTTP_API ToSimpleHTTPVerbTypeByName(const FString &InType);
}