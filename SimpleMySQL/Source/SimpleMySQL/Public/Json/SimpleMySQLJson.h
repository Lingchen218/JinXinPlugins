// Copyright (C) RenZhai.2020.All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Core/SimpleMysqlLinkType.h"

namespace SimpleMySQLJson
{
	SIMPLEMYSQL_API bool StringToArrayMysqlArrayResult(const FString& InJsonString,TArray<FSimpleMysqlResult>& OutMysqlResult);
	SIMPLEMYSQL_API bool ArrayMysqlArrayResultToString(const TArray<FSimpleMysqlResult> &InMysqlResult,FString& OutJsonString);
}