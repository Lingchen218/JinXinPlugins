// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../Plugins/RENZHAI_PLUGIN/SimpleMySQL/Source/SimpleMySQL/Public/Core/SimpleMysqlLinkType.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSimpleMysqlLinkType() {}

// Begin Cross Module References
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
SIMPLEMYSQL_API UEnum* Z_Construct_UEnum_SimpleMySQL_EMysqlCharset();
SIMPLEMYSQL_API UEnum* Z_Construct_UEnum_SimpleMySQL_EMysqlComparisonOperator();
SIMPLEMYSQL_API UEnum* Z_Construct_UEnum_SimpleMySQL_EMysqlDateType();
SIMPLEMYSQL_API UEnum* Z_Construct_UEnum_SimpleMySQL_EMysqlJoinType();
SIMPLEMYSQL_API UEnum* Z_Construct_UEnum_SimpleMySQL_EMysqlLogicalOperators();
SIMPLEMYSQL_API UEnum* Z_Construct_UEnum_SimpleMySQL_EMysqlQuerySaveType();
SIMPLEMYSQL_API UEnum* Z_Construct_UEnum_SimpleMySQL_EMysqlSaveEngine();
SIMPLEMYSQL_API UEnum* Z_Construct_UEnum_SimpleMySQL_EMysqlVariableType();
SIMPLEMYSQL_API UEnum* Z_Construct_UEnum_SimpleMySQL_ESimpleClientFlags();
SIMPLEMYSQL_API UScriptStruct* Z_Construct_UScriptStruct_FMysqlCreateTableParam();
SIMPLEMYSQL_API UScriptStruct* Z_Construct_UScriptStruct_FMysqlFieldType();
SIMPLEMYSQL_API UScriptStruct* Z_Construct_UScriptStruct_FSimpleMysqlAssignment();
SIMPLEMYSQL_API UScriptStruct* Z_Construct_UScriptStruct_FSimpleMysqlComparisonOperator();
SIMPLEMYSQL_API UScriptStruct* Z_Construct_UScriptStruct_FSimpleMysqlDebugResult();
SIMPLEMYSQL_API UScriptStruct* Z_Construct_UScriptStruct_FSimpleMysqlJoinParameters();
SIMPLEMYSQL_API UScriptStruct* Z_Construct_UScriptStruct_FSimpleMysqlModifyField();
SIMPLEMYSQL_API UScriptStruct* Z_Construct_UScriptStruct_FSimpleMysqlQueryOrderBy();
SIMPLEMYSQL_API UScriptStruct* Z_Construct_UScriptStruct_FSimpleMysqlQueryParameters();
SIMPLEMYSQL_API UScriptStruct* Z_Construct_UScriptStruct_FSimpleMysqlQueryStmt();
SIMPLEMYSQL_API UScriptStruct* Z_Construct_UScriptStruct_FSimpleMysqlReplaceParameters();
SIMPLEMYSQL_API UScriptStruct* Z_Construct_UScriptStruct_FSimpleMysqlResult();
SIMPLEMYSQL_API UScriptStruct* Z_Construct_UScriptStruct_FSimpleMysqlVariableSettings();
UPackage* Z_Construct_UPackage__Script_SimpleMySQL();
// End Cross Module References

// Begin Enum EMysqlVariableType
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EMysqlVariableType;
static UEnum* EMysqlVariableType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EMysqlVariableType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EMysqlVariableType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_SimpleMySQL_EMysqlVariableType, (UObject*)Z_Construct_UPackage__Script_SimpleMySQL(), TEXT("EMysqlVariableType"));
	}
	return Z_Registration_Info_UEnum_EMysqlVariableType.OuterSingleton;
}
template<> SIMPLEMYSQL_API UEnum* StaticEnum<EMysqlVariableType>()
{
	return EMysqlVariableType_StaticEnum();
}
struct Z_Construct_UEnum_SimpleMySQL_EMysqlVariableType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "//Mysql\xe6\x89\x80\xe6\x9c\x89\xe7\x9a\x84\xe5\x8f\x98\xe9\x87\x8f\xe7\xb1\xbb\xe5\x9e\x8b\n" },
		{ "ModuleRelativePath", "Public/Core/SimpleMysqlLinkType.h" },
		{ "MYSQL_BIT.Comment", "//VARCHAR\n" },
		{ "MYSQL_BIT.DisplayName", "Bit" },
		{ "MYSQL_BIT.Name", "EMysqlVariableType::MYSQL_BIT" },
		{ "MYSQL_BIT.ToolTip", "VARCHAR" },
		{ "MYSQL_BLOB.Comment", "//@@\x09\x09\x09\x09//s\n" },
		{ "MYSQL_BLOB.DisplayName", "Blob" },
		{ "MYSQL_BLOB.Name", "EMysqlVariableType::MYSQL_BLOB" },
		{ "MYSQL_BLOB.ToolTip", "@@                              s" },
		{ "MYSQL_DATE.Comment", "//MEDIUMINT\x09\x09""3 //ns\n" },
		{ "MYSQL_DATE.DisplayName", "Date" },
		{ "MYSQL_DATE.Name", "EMysqlVariableType::MYSQL_DATE" },
		{ "MYSQL_DATE.ToolTip", "MEDIUMINT               3 ns" },
		{ "MYSQL_DATETIME.Comment", "//TIME\x09\x09\x09""3\n" },
		{ "MYSQL_DATETIME.DisplayName", "Date Time" },
		{ "MYSQL_DATETIME.Name", "EMysqlVariableType::MYSQL_DATETIME" },
		{ "MYSQL_DATETIME.ToolTip", "TIME                    3" },
		{ "MYSQL_DATETIME2.DisplayName", "Date Time2" },
		{ "MYSQL_DATETIME2.Name", "EMysqlVariableType::MYSQL_DATETIME2" },
		{ "MYSQL_DECIMAL.DisplayName", "Decimal" },
		{ "MYSQL_DECIMAL.Name", "EMysqlVariableType::MYSQL_DECIMAL" },
		{ "MYSQL_DOUBLE.Comment", "//FLOAT\x09\x09\x09""4 //s\n" },
		{ "MYSQL_DOUBLE.DisplayName", "Double" },
		{ "MYSQL_DOUBLE.Name", "EMysqlVariableType::MYSQL_DOUBLE" },
		{ "MYSQL_DOUBLE.ToolTip", "FLOAT                   4 s" },
		{ "MYSQL_ENUM.Comment", "//@@\n//\n" },
		{ "MYSQL_ENUM.DisplayName", "Enum" },
		{ "MYSQL_ENUM.Name", "EMysqlVariableType::MYSQL_ENUM" },
		{ "MYSQL_FLOAT.Comment", "//INTEGER\x09\x09""4 //s\n" },
		{ "MYSQL_FLOAT.DisplayName", "Float" },
		{ "MYSQL_FLOAT.Name", "EMysqlVariableType::MYSQL_FLOAT" },
		{ "MYSQL_FLOAT.ToolTip", "INTEGER         4 s" },
		{ "MYSQL_GEOMETRY.Comment", "//@@ //CHAR/VARCHAR \n" },
		{ "MYSQL_GEOMETRY.DisplayName", "Geometry" },
		{ "MYSQL_GEOMETRY.Name", "EMysqlVariableType::MYSQL_GEOMETRY" },
		{ "MYSQL_GEOMETRY.ToolTip", "@@ CHAR/VARCHAR" },
		{ "MYSQL_INT24.Comment", "//BIGINT\x09\x09""8 //s\n" },
		{ "MYSQL_INT24.DisplayName", "Medium Int" },
		{ "MYSQL_INT24.Name", "EMysqlVariableType::MYSQL_INT24" },
		{ "MYSQL_INT24.ToolTip", "BIGINT          8 s" },
		{ "MYSQL_JSON.DisplayName", "Json" },
		{ "MYSQL_JSON.Name", "EMysqlVariableType::MYSQL_JSON" },
		{ "MYSQL_LONG.Comment", "//SHORT\x09\x09\x09""2 //s\n" },
		{ "MYSQL_LONG.DisplayName", "integer" },
		{ "MYSQL_LONG.Name", "EMysqlVariableType::MYSQL_LONG" },
		{ "MYSQL_LONG.ToolTip", "SHORT                   2 s" },
		{ "MYSQL_LONG_BLOB.Comment", "//@@\x09\x09\x09\x09//s\n" },
		{ "MYSQL_LONG_BLOB.DisplayName", "Long Blob" },
		{ "MYSQL_LONG_BLOB.Name", "EMysqlVariableType::MYSQL_LONG_BLOB" },
		{ "MYSQL_LONG_BLOB.ToolTip", "@@                              s" },
		{ "MYSQL_LONGLONG.Comment", "//TIMESTAMP\x09\x09""8\n" },
		{ "MYSQL_LONGLONG.DisplayName", "Big Int" },
		{ "MYSQL_LONGLONG.Name", "EMysqlVariableType::MYSQL_LONGLONG" },
		{ "MYSQL_LONGLONG.ToolTip", "TIMESTAMP               8" },
		{ "MYSQL_MEDIUM_BLOB.Comment", "//@@\x09\x09\x09\x09//s\n" },
		{ "MYSQL_MEDIUM_BLOB.DisplayName", "Medium Blob" },
		{ "MYSQL_MEDIUM_BLOB.Name", "EMysqlVariableType::MYSQL_MEDIUM_BLOB" },
		{ "MYSQL_MEDIUM_BLOB.ToolTip", "@@                              s" },
		{ "MYSQL_NEWDATE.Comment", "//YEAR\x09\x09\x09""1\n" },
		{ "MYSQL_NEWDATE.DisplayName", "New Date" },
		{ "MYSQL_NEWDATE.Name", "EMysqlVariableType::MYSQL_NEWDATE" },
		{ "MYSQL_NEWDATE.ToolTip", "YEAR                    1" },
		{ "MYSQL_NEWDECIMAL.Comment", "//@@\n" },
		{ "MYSQL_NEWDECIMAL.DisplayName", "New Decimal" },
		{ "MYSQL_NEWDECIMAL.Name", "EMysqlVariableType::MYSQL_NEWDECIMAL" },
		{ "MYSQL_NULL.Comment", "//DOUBLE/REAL\x09""8 //s\n" },
		{ "MYSQL_NULL.DisplayName", "Null" },
		{ "MYSQL_NULL.Name", "EMysqlVariableType::MYSQL_NULL" },
		{ "MYSQL_NULL.ToolTip", "DOUBLE/REAL     8 s" },
		{ "MYSQL_SET.Comment", "//@@\n//\n//\x09\x09\x09\x09""1 or 2   65535\xe4\xb8\xaa\n" },
		{ "MYSQL_SET.DisplayName", "Set" },
		{ "MYSQL_SET.Name", "EMysqlVariableType::MYSQL_SET" },
		{ "MYSQL_SET.ToolTip", "@@\n\n                               1 or 2   65535\xe4\xb8\xaa" },
		{ "MYSQL_SHORT.Comment", "//SMALLINT\x09\x09""2 //s\n" },
		{ "MYSQL_SHORT.DisplayName", "Short" },
		{ "MYSQL_SHORT.Name", "EMysqlVariableType::MYSQL_SHORT" },
		{ "MYSQL_SHORT.ToolTip", "SMALLINT                2 s" },
		{ "MYSQL_STRING.Comment", "//@@ //VARCHAR\n" },
		{ "MYSQL_STRING.DisplayName", "String" },
		{ "MYSQL_STRING.Name", "EMysqlVariableType::MYSQL_STRING" },
		{ "MYSQL_STRING.ToolTip", "@@ VARCHAR" },
		{ "MYSQL_TIME.Comment", "//DATE\x09\x09\x09""3\n" },
		{ "MYSQL_TIME.DisplayName", "Time" },
		{ "MYSQL_TIME.Name", "EMysqlVariableType::MYSQL_TIME" },
		{ "MYSQL_TIME.ToolTip", "DATE                    3" },
		{ "MYSQL_TIME2.DisplayName", "Time2" },
		{ "MYSQL_TIME2.Name", "EMysqlVariableType::MYSQL_TIME2" },
		{ "MYSQL_TIMESTAMP.Comment", "//NULL\n" },
		{ "MYSQL_TIMESTAMP.DisplayName", "Time Stamp" },
		{ "MYSQL_TIMESTAMP.Name", "EMysqlVariableType::MYSQL_TIMESTAMP" },
		{ "MYSQL_TIMESTAMP.ToolTip", "NULL" },
		{ "MYSQL_TIMESTAMP2.Comment", "//BIT(M)\x09\x09\x09\n" },
		{ "MYSQL_TIMESTAMP2.DisplayName", "Time Stamp2" },
		{ "MYSQL_TIMESTAMP2.Name", "EMysqlVariableType::MYSQL_TIMESTAMP2" },
		{ "MYSQL_TIMESTAMP2.ToolTip", "BIT(M)" },
		{ "MYSQL_TINY.Comment", "//DECIMAL(M,D)/NUMERIC  M > D ? M+ 2 : D+ 2\n" },
		{ "MYSQL_TINY.DisplayName", "Small Int" },
		{ "MYSQL_TINY.Name", "EMysqlVariableType::MYSQL_TINY" },
		{ "MYSQL_TINY.ToolTip", "DECIMAL(M,D)/NUMERIC  M > D ? M+ 2 : D+ 2" },
		{ "MYSQL_TINY_BLOB.Comment", "//\x09\x09\x09\x09""1,2,4,8\n" },
		{ "MYSQL_TINY_BLOB.DisplayName", "Tiny Blob" },
		{ "MYSQL_TINY_BLOB.Name", "EMysqlVariableType::MYSQL_TINY_BLOB" },
		{ "MYSQL_TINY_BLOB.ToolTip", "1,2,4,8" },
		{ "MYSQL_VAR_STRING.Comment", "//@@ \x09\x09\x09\x09//s\n" },
		{ "MYSQL_VAR_STRING.DisplayName", "VarString" },
		{ "MYSQL_VAR_STRING.Name", "EMysqlVariableType::MYSQL_VAR_STRING" },
		{ "MYSQL_VAR_STRING.ToolTip", "@@                              s" },
		{ "MYSQL_VARCHAR.Comment", "//NEWDATE\n" },
		{ "MYSQL_VARCHAR.DisplayName", "Varchar" },
		{ "MYSQL_VARCHAR.Name", "EMysqlVariableType::MYSQL_VARCHAR" },
		{ "MYSQL_VARCHAR.ToolTip", "NEWDATE" },
		{ "MYSQL_YEAR.Comment", "//DATETIME\x09\x09""8\n" },
		{ "MYSQL_YEAR.DisplayName", "Year" },
		{ "MYSQL_YEAR.Name", "EMysqlVariableType::MYSQL_YEAR" },
		{ "MYSQL_YEAR.ToolTip", "DATETIME                8" },
		{ "ToolTip", "Mysql\xe6\x89\x80\xe6\x9c\x89\xe7\x9a\x84\xe5\x8f\x98\xe9\x87\x8f\xe7\xb1\xbb\xe5\x9e\x8b" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EMysqlVariableType::MYSQL_DECIMAL", (int64)EMysqlVariableType::MYSQL_DECIMAL },
		{ "EMysqlVariableType::MYSQL_TINY", (int64)EMysqlVariableType::MYSQL_TINY },
		{ "EMysqlVariableType::MYSQL_SHORT", (int64)EMysqlVariableType::MYSQL_SHORT },
		{ "EMysqlVariableType::MYSQL_LONG", (int64)EMysqlVariableType::MYSQL_LONG },
		{ "EMysqlVariableType::MYSQL_FLOAT", (int64)EMysqlVariableType::MYSQL_FLOAT },
		{ "EMysqlVariableType::MYSQL_DOUBLE", (int64)EMysqlVariableType::MYSQL_DOUBLE },
		{ "EMysqlVariableType::MYSQL_NULL", (int64)EMysqlVariableType::MYSQL_NULL },
		{ "EMysqlVariableType::MYSQL_TIMESTAMP", (int64)EMysqlVariableType::MYSQL_TIMESTAMP },
		{ "EMysqlVariableType::MYSQL_LONGLONG", (int64)EMysqlVariableType::MYSQL_LONGLONG },
		{ "EMysqlVariableType::MYSQL_INT24", (int64)EMysqlVariableType::MYSQL_INT24 },
		{ "EMysqlVariableType::MYSQL_DATE", (int64)EMysqlVariableType::MYSQL_DATE },
		{ "EMysqlVariableType::MYSQL_TIME", (int64)EMysqlVariableType::MYSQL_TIME },
		{ "EMysqlVariableType::MYSQL_DATETIME", (int64)EMysqlVariableType::MYSQL_DATETIME },
		{ "EMysqlVariableType::MYSQL_YEAR", (int64)EMysqlVariableType::MYSQL_YEAR },
		{ "EMysqlVariableType::MYSQL_NEWDATE", (int64)EMysqlVariableType::MYSQL_NEWDATE },
		{ "EMysqlVariableType::MYSQL_VARCHAR", (int64)EMysqlVariableType::MYSQL_VARCHAR },
		{ "EMysqlVariableType::MYSQL_BIT", (int64)EMysqlVariableType::MYSQL_BIT },
		{ "EMysqlVariableType::MYSQL_TIMESTAMP2", (int64)EMysqlVariableType::MYSQL_TIMESTAMP2 },
		{ "EMysqlVariableType::MYSQL_DATETIME2", (int64)EMysqlVariableType::MYSQL_DATETIME2 },
		{ "EMysqlVariableType::MYSQL_TIME2", (int64)EMysqlVariableType::MYSQL_TIME2 },
		{ "EMysqlVariableType::MYSQL_JSON", (int64)EMysqlVariableType::MYSQL_JSON },
		{ "EMysqlVariableType::MYSQL_NEWDECIMAL", (int64)EMysqlVariableType::MYSQL_NEWDECIMAL },
		{ "EMysqlVariableType::MYSQL_ENUM", (int64)EMysqlVariableType::MYSQL_ENUM },
		{ "EMysqlVariableType::MYSQL_SET", (int64)EMysqlVariableType::MYSQL_SET },
		{ "EMysqlVariableType::MYSQL_TINY_BLOB", (int64)EMysqlVariableType::MYSQL_TINY_BLOB },
		{ "EMysqlVariableType::MYSQL_MEDIUM_BLOB", (int64)EMysqlVariableType::MYSQL_MEDIUM_BLOB },
		{ "EMysqlVariableType::MYSQL_LONG_BLOB", (int64)EMysqlVariableType::MYSQL_LONG_BLOB },
		{ "EMysqlVariableType::MYSQL_BLOB", (int64)EMysqlVariableType::MYSQL_BLOB },
		{ "EMysqlVariableType::MYSQL_VAR_STRING", (int64)EMysqlVariableType::MYSQL_VAR_STRING },
		{ "EMysqlVariableType::MYSQL_STRING", (int64)EMysqlVariableType::MYSQL_STRING },
		{ "EMysqlVariableType::MYSQL_GEOMETRY", (int64)EMysqlVariableType::MYSQL_GEOMETRY },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_SimpleMySQL_EMysqlVariableType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_SimpleMySQL,
	nullptr,
	"EMysqlVariableType",
	"EMysqlVariableType",
	Z_Construct_UEnum_SimpleMySQL_EMysqlVariableType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_SimpleMySQL_EMysqlVariableType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_SimpleMySQL_EMysqlVariableType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_SimpleMySQL_EMysqlVariableType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_SimpleMySQL_EMysqlVariableType()
{
	if (!Z_Registration_Info_UEnum_EMysqlVariableType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EMysqlVariableType.InnerSingleton, Z_Construct_UEnum_SimpleMySQL_EMysqlVariableType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EMysqlVariableType.InnerSingleton;
}
// End Enum EMysqlVariableType

// Begin Enum EMysqlSaveEngine
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EMysqlSaveEngine;
static UEnum* EMysqlSaveEngine_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EMysqlSaveEngine.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EMysqlSaveEngine.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_SimpleMySQL_EMysqlSaveEngine, (UObject*)Z_Construct_UPackage__Script_SimpleMySQL(), TEXT("EMysqlSaveEngine"));
	}
	return Z_Registration_Info_UEnum_EMysqlSaveEngine.OuterSingleton;
}
template<> SIMPLEMYSQL_API UEnum* StaticEnum<EMysqlSaveEngine>()
{
	return EMysqlSaveEngine_StaticEnum();
}
struct Z_Construct_UEnum_SimpleMySQL_EMysqlSaveEngine_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "ARCHIVE.Comment", "//|Hash based, stored in memory, useful for temporary tables\x09 |\x09YES\x09\x09|\x09NO\x09\x09\x09|NO\x09\x09|\x09NO\x09\x09|\n" },
		{ "ARCHIVE.Name", "EMysqlSaveEngine::ARCHIVE" },
		{ "ARCHIVE.ToolTip", "|Hash based, stored in memory, useful for temporary tables       |      YES             |       NO                      |NO             |       NO              |" },
		{ "BLACKHOLE.Comment", "//|Collection of identical MyISAM tables\x09\x09\x09\x09\x09\x09 |\x09YES\x09\x09|\x09NO\x09\x09\x09|NO\x09\x09|\x09NO\x09\x09|\n" },
		{ "BLACKHOLE.Name", "EMysqlSaveEngine::BLACKHOLE" },
		{ "BLACKHOLE.ToolTip", "|Collection of identical MyISAM tables                                           |      YES             |       NO                      |NO             |       NO              |" },
		{ "BlueprintType", "true" },
		{ "CSV.Comment", "//|Archive storage engine\x09\x09\x09\x09\x09\x09\x09\x09\x09\x09 |\x09YES\x09\x09|\x09NO\x09\x09\x09|NO\x09\x09|\x09NO\x09\x09|\n" },
		{ "CSV.Name", "EMysqlSaveEngine::CSV" },
		{ "CSV.ToolTip", "|Archive storage engine                                                                          |      YES             |       NO                      |NO             |       NO              |" },
		{ "FEDERATED.Comment", "//|/dev/null storage engine (anything you write to it disappears)|\x09YES\x09\x09|\x09NO\x09\x09\x09|NO\x09\x09|\x09NO\x09\x09|\n" },
		{ "FEDERATED.Name", "EMysqlSaveEngine::FEDERATED" },
		{ "FEDERATED.ToolTip", "|/dev/null storage engine (anything you write to it disappears)|        YES             |       NO                      |NO             |       NO              |" },
		{ "InnoDB.Comment", "//___________________________________________________________________________________________________________________________________\n//Engine\x09\x09\x09//|Comment\x09\x09\x09\x09\x09\x09\x09\x09\x09\x09\x09\x09\x09\x09 |Support\x09| Transactions  |XA\x09\x09|Savepoints\x09|\x09\x09\x09\n//____________________|_______________________________________________________________________________________________________________\n" },
		{ "InnoDB.Name", "EMysqlSaveEngine::InnoDB" },
		{ "InnoDB.ToolTip", "___________________________________________________________________________________________________________________________________\nEngine                 |Comment                                                                                                                 |Support       | Transactions  |XA             |Savepoints     |\n____________________|_______________________________________________________________________________________________________________" },
		{ "MEMORY.Comment", "//|MyISAM storage engine\x09\x09\x09\x09\x09\x09\x09\x09\x09\x09 |\x09""DEFAULT\x09|\x09NO\x09\x09\x09|NO\x09\x09|\x09NO\x09\x09|\n" },
		{ "MEMORY.Name", "EMysqlSaveEngine::MEMORY" },
		{ "MEMORY.ToolTip", "|MyISAM storage engine                                                                           |      DEFAULT |       NO                      |NO             |       NO              |" },
		{ "ModuleRelativePath", "Public/Core/SimpleMysqlLinkType.h" },
		{ "MRG_MYISAM.Comment", "//|Performance Schema\x09\x09\x09\x09\x09\x09\x09\x09\x09\x09\x09 |\x09YES\x09\x09|\x09NO\x09\x09\x09|NO\x09\x09|\x09NO\x09\x09|\n" },
		{ "MRG_MYISAM.Name", "EMysqlSaveEngine::MRG_MYISAM" },
		{ "MRG_MYISAM.ToolTip", "|Performance Schema                                                                                      |      YES             |       NO                      |NO             |       NO              |" },
		{ "MyISAM.Comment", "//|Supports transactions, row-level locking, and foreign keys\x09 |\x09YES\x09\x09|\x09YES\x09\x09\x09|YES\x09|\x09YES\x09\x09|\n" },
		{ "MyISAM.Name", "EMysqlSaveEngine::MyISAM" },
		{ "MyISAM.ToolTip", "|Supports transactions, row-level locking, and foreign keys      |      YES             |       YES                     |YES    |       YES             |" },
		{ "PERFORMANCE_SCHEMA.Comment", "//|CSV storage engine\x09\x09\x09\x09\x09\x09\x09\x09\x09\x09\x09 |\x09YES\x09\x09|\x09NO\x09\x09\x09|NO\x09\x09|\x09NO\x09\x09|\n" },
		{ "PERFORMANCE_SCHEMA.Name", "EMysqlSaveEngine::PERFORMANCE_SCHEMA" },
		{ "PERFORMANCE_SCHEMA.ToolTip", "|CSV storage engine                                                                                      |      YES             |       NO                      |NO             |       NO              |" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EMysqlSaveEngine::InnoDB", (int64)EMysqlSaveEngine::InnoDB },
		{ "EMysqlSaveEngine::MyISAM", (int64)EMysqlSaveEngine::MyISAM },
		{ "EMysqlSaveEngine::MEMORY", (int64)EMysqlSaveEngine::MEMORY },
		{ "EMysqlSaveEngine::ARCHIVE", (int64)EMysqlSaveEngine::ARCHIVE },
		{ "EMysqlSaveEngine::CSV", (int64)EMysqlSaveEngine::CSV },
		{ "EMysqlSaveEngine::PERFORMANCE_SCHEMA", (int64)EMysqlSaveEngine::PERFORMANCE_SCHEMA },
		{ "EMysqlSaveEngine::MRG_MYISAM", (int64)EMysqlSaveEngine::MRG_MYISAM },
		{ "EMysqlSaveEngine::BLACKHOLE", (int64)EMysqlSaveEngine::BLACKHOLE },
		{ "EMysqlSaveEngine::FEDERATED", (int64)EMysqlSaveEngine::FEDERATED },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_SimpleMySQL_EMysqlSaveEngine_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_SimpleMySQL,
	nullptr,
	"EMysqlSaveEngine",
	"EMysqlSaveEngine",
	Z_Construct_UEnum_SimpleMySQL_EMysqlSaveEngine_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_SimpleMySQL_EMysqlSaveEngine_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_SimpleMySQL_EMysqlSaveEngine_Statics::Enum_MetaDataParams), Z_Construct_UEnum_SimpleMySQL_EMysqlSaveEngine_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_SimpleMySQL_EMysqlSaveEngine()
{
	if (!Z_Registration_Info_UEnum_EMysqlSaveEngine.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EMysqlSaveEngine.InnerSingleton, Z_Construct_UEnum_SimpleMySQL_EMysqlSaveEngine_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EMysqlSaveEngine.InnerSingleton;
}
// End Enum EMysqlSaveEngine

// Begin Enum ESimpleClientFlags
static FEnumRegistrationInfo Z_Registration_Info_UEnum_ESimpleClientFlags;
static UEnum* ESimpleClientFlags_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_ESimpleClientFlags.OuterSingleton)
	{
		Z_Registration_Info_UEnum_ESimpleClientFlags.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_SimpleMySQL_ESimpleClientFlags, (UObject*)Z_Construct_UPackage__Script_SimpleMySQL(), TEXT("ESimpleClientFlags"));
	}
	return Z_Registration_Info_UEnum_ESimpleClientFlags.OuterSingleton;
}
template<> SIMPLEMYSQL_API UEnum* StaticEnum<ESimpleClientFlags>()
{
	return ESimpleClientFlags_StaticEnum();
}
struct Z_Construct_UEnum_SimpleMySQL_ESimpleClientFlags_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Client_Compress.Comment", "/* Don't allow database.table.column */" },
		{ "Client_Compress.Name", "ESimpleClientFlags::Client_Compress" },
		{ "Client_Compress.ToolTip", "Don't allow database.table.column" },
		{ "Client_Connect_With_db.Comment", "/* Get all column flags */" },
		{ "Client_Connect_With_db.Name", "ESimpleClientFlags::Client_Connect_With_db" },
		{ "Client_Connect_With_db.ToolTip", "Get all column flags" },
		{ "Client_Found_Rows.Comment", "/* new more secure passwords */" },
		{ "Client_Found_Rows.Name", "ESimpleClientFlags::Client_Found_Rows" },
		{ "Client_Found_Rows.ToolTip", "new more secure passwords" },
		{ "Client_Ignore_Sigpipe.Comment", "/* Switch to SSL after handshake */" },
		{ "Client_Ignore_Sigpipe.Name", "ESimpleClientFlags::Client_Ignore_Sigpipe" },
		{ "Client_Ignore_Sigpipe.ToolTip", "Switch to SSL after handshake" },
		{ "Client_Ignore_Space.Comment", "/* Can use LOAD DATA LOCAL */" },
		{ "Client_Ignore_Space.Name", "ESimpleClientFlags::Client_Ignore_Space" },
		{ "Client_Ignore_Space.ToolTip", "Can use LOAD DATA LOCAL" },
		{ "Client_Interactive.Comment", "/* New 4.1 protocol */" },
		{ "Client_Interactive.Name", "ESimpleClientFlags::Client_Interactive" },
		{ "Client_Interactive.ToolTip", "New 4.1 protocol" },
		{ "Client_Local_Files.Comment", "/* Odbc client */" },
		{ "Client_Local_Files.Name", "ESimpleClientFlags::Client_Local_Files" },
		{ "Client_Local_Files.ToolTip", "Odbc client" },
		{ "Client_Long_Flag.Comment", "/* Found instead of affected rows */" },
		{ "Client_Long_Flag.Name", "ESimpleClientFlags::Client_Long_Flag" },
		{ "Client_Long_Flag.ToolTip", "Found instead of affected rows" },
		{ "Client_Long_Password.Name", "ESimpleClientFlags::Client_Long_Password" },
		{ "Client_Multi_Results.Comment", "/* Enable/disable multi-stmt support */" },
		{ "Client_Multi_Results.Name", "ESimpleClientFlags::Client_Multi_Results" },
		{ "Client_Multi_Results.ToolTip", "Enable/disable multi-stmt support" },
		{ "Client_Multi_Statements.Comment", "/* Old flag for 4.1 authentication */" },
		{ "Client_Multi_Statements.Name", "ESimpleClientFlags::Client_Multi_Statements" },
		{ "Client_Multi_Statements.ToolTip", "Old flag for 4.1 authentication" },
		{ "Client_No_Schema.Comment", "/* One can specify db on connect */" },
		{ "Client_No_Schema.Name", "ESimpleClientFlags::Client_No_Schema" },
		{ "Client_No_Schema.ToolTip", "One can specify db on connect" },
		{ "Client_None.Name", "ESimpleClientFlags::Client_None" },
		{ "Client_ODBC.Comment", "/* Can use compression protocol */" },
		{ "Client_ODBC.Name", "ESimpleClientFlags::Client_ODBC" },
		{ "Client_ODBC.ToolTip", "Can use compression protocol" },
		{ "Client_Protocol_41.Comment", "/* Ignore spaces before '(' */" },
		{ "Client_Protocol_41.Name", "ESimpleClientFlags::Client_Protocol_41" },
		{ "Client_Protocol_41.ToolTip", "Ignore spaces before '('" },
		{ "Client_PS_Multi_Results.Comment", "/* Enable/disable multi-results */" },
		{ "Client_PS_Multi_Results.Name", "ESimpleClientFlags::Client_PS_Multi_Results" },
		{ "Client_PS_Multi_Results.ToolTip", "Enable/disable multi-results" },
		{ "Client_Reserved.Comment", "/* Client knows about transactions */" },
		{ "Client_Reserved.Name", "ESimpleClientFlags::Client_Reserved" },
		{ "Client_Reserved.ToolTip", "Client knows about transactions" },
		{ "Client_Reserved2.Comment", "/* Old flag for 4.1 protocol  */" },
		{ "Client_Reserved2.Name", "ESimpleClientFlags::Client_Reserved2" },
		{ "Client_Reserved2.ToolTip", "Old flag for 4.1 protocol" },
		{ "Client_SSL.Comment", "/* This is an interactive client */" },
		{ "Client_SSL.Name", "ESimpleClientFlags::Client_SSL" },
		{ "Client_SSL.ToolTip", "This is an interactive client" },
		{ "Client_Transactions.Comment", "/* IGNORE sigpipes */" },
		{ "Client_Transactions.Name", "ESimpleClientFlags::Client_Transactions" },
		{ "Client_Transactions.ToolTip", "IGNORE sigpipes" },
		{ "ModuleRelativePath", "Public/Core/SimpleMysqlLinkType.h" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "ESimpleClientFlags::Client_None", (int64)ESimpleClientFlags::Client_None },
		{ "ESimpleClientFlags::Client_Long_Password", (int64)ESimpleClientFlags::Client_Long_Password },
		{ "ESimpleClientFlags::Client_Found_Rows", (int64)ESimpleClientFlags::Client_Found_Rows },
		{ "ESimpleClientFlags::Client_Long_Flag", (int64)ESimpleClientFlags::Client_Long_Flag },
		{ "ESimpleClientFlags::Client_Connect_With_db", (int64)ESimpleClientFlags::Client_Connect_With_db },
		{ "ESimpleClientFlags::Client_No_Schema", (int64)ESimpleClientFlags::Client_No_Schema },
		{ "ESimpleClientFlags::Client_Compress", (int64)ESimpleClientFlags::Client_Compress },
		{ "ESimpleClientFlags::Client_ODBC", (int64)ESimpleClientFlags::Client_ODBC },
		{ "ESimpleClientFlags::Client_Local_Files", (int64)ESimpleClientFlags::Client_Local_Files },
		{ "ESimpleClientFlags::Client_Ignore_Space", (int64)ESimpleClientFlags::Client_Ignore_Space },
		{ "ESimpleClientFlags::Client_Protocol_41", (int64)ESimpleClientFlags::Client_Protocol_41 },
		{ "ESimpleClientFlags::Client_Interactive", (int64)ESimpleClientFlags::Client_Interactive },
		{ "ESimpleClientFlags::Client_SSL", (int64)ESimpleClientFlags::Client_SSL },
		{ "ESimpleClientFlags::Client_Ignore_Sigpipe", (int64)ESimpleClientFlags::Client_Ignore_Sigpipe },
		{ "ESimpleClientFlags::Client_Transactions", (int64)ESimpleClientFlags::Client_Transactions },
		{ "ESimpleClientFlags::Client_Reserved", (int64)ESimpleClientFlags::Client_Reserved },
		{ "ESimpleClientFlags::Client_Reserved2", (int64)ESimpleClientFlags::Client_Reserved2 },
		{ "ESimpleClientFlags::Client_Multi_Statements", (int64)ESimpleClientFlags::Client_Multi_Statements },
		{ "ESimpleClientFlags::Client_Multi_Results", (int64)ESimpleClientFlags::Client_Multi_Results },
		{ "ESimpleClientFlags::Client_PS_Multi_Results", (int64)ESimpleClientFlags::Client_PS_Multi_Results },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_SimpleMySQL_ESimpleClientFlags_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_SimpleMySQL,
	nullptr,
	"ESimpleClientFlags",
	"ESimpleClientFlags",
	Z_Construct_UEnum_SimpleMySQL_ESimpleClientFlags_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_SimpleMySQL_ESimpleClientFlags_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_SimpleMySQL_ESimpleClientFlags_Statics::Enum_MetaDataParams), Z_Construct_UEnum_SimpleMySQL_ESimpleClientFlags_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_SimpleMySQL_ESimpleClientFlags()
{
	if (!Z_Registration_Info_UEnum_ESimpleClientFlags.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ESimpleClientFlags.InnerSingleton, Z_Construct_UEnum_SimpleMySQL_ESimpleClientFlags_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_ESimpleClientFlags.InnerSingleton;
}
// End Enum ESimpleClientFlags

// Begin Enum EMysqlCharset
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EMysqlCharset;
static UEnum* EMysqlCharset_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EMysqlCharset.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EMysqlCharset.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_SimpleMySQL_EMysqlCharset, (UObject*)Z_Construct_UPackage__Script_SimpleMySQL(), TEXT("EMysqlCharset"));
	}
	return Z_Registration_Info_UEnum_EMysqlCharset.OuterSingleton;
}
template<> SIMPLEMYSQL_API UEnum* StaticEnum<EMysqlCharset>()
{
	return EMysqlCharset_StaticEnum();
}
struct Z_Construct_UEnum_SimpleMySQL_EMysqlCharset_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "armscii8.Comment", "//\n" },
		{ "armscii8.Name", "EMysqlCharset::armscii8" },
		{ "ascii.Comment", "//\n" },
		{ "ascii.Name", "EMysqlCharset::ascii" },
		{ "bebrew.Comment", "//\n" },
		{ "bebrew.Name", "EMysqlCharset::bebrew" },
		{ "big5.Comment", "//\n" },
		{ "big5.Name", "EMysqlCharset::big5" },
		{ "binary.Comment", "//\n" },
		{ "binary.Name", "EMysqlCharset::binary" },
		{ "BlueprintType", "true" },
		{ "Comment", "//\n" },
		{ "cp1250.Comment", "//\n" },
		{ "cp1250.Name", "EMysqlCharset::cp1250" },
		{ "cp1251.Comment", "//\n" },
		{ "cp1251.Name", "EMysqlCharset::cp1251" },
		{ "cp1256.Comment", "//\n" },
		{ "cp1256.Name", "EMysqlCharset::cp1256" },
		{ "cp1257.Comment", "//\n" },
		{ "cp1257.Name", "EMysqlCharset::cp1257" },
		{ "cp850.Comment", "//\n" },
		{ "cp850.Name", "EMysqlCharset::cp850" },
		{ "cp852.Comment", "//\n" },
		{ "cp852.Name", "EMysqlCharset::cp852" },
		{ "cp866.Comment", "//\n" },
		{ "cp866.Name", "EMysqlCharset::cp866" },
		{ "cp932.Comment", "//\n" },
		{ "cp932.Name", "EMysqlCharset::cp932" },
		{ "dec8.Comment", "//\n" },
		{ "dec8.Name", "EMysqlCharset::dec8" },
		{ "eucjpms.Comment", "//\n" },
		{ "eucjpms.Name", "EMysqlCharset::eucjpms" },
		{ "euckr.Comment", "//\n" },
		{ "euckr.Name", "EMysqlCharset::euckr" },
		{ "gb2312.Comment", "//\n" },
		{ "gb2312.Name", "EMysqlCharset::gb2312" },
		{ "gbk.Comment", "//\n" },
		{ "gbk.Name", "EMysqlCharset::gbk" },
		{ "geostd8.Comment", "//\n" },
		{ "geostd8.Name", "EMysqlCharset::geostd8" },
		{ "greek.Comment", "//\n" },
		{ "greek.Name", "EMysqlCharset::greek" },
		{ "hp8.Comment", "//\n" },
		{ "hp8.Name", "EMysqlCharset::hp8" },
		{ "keybcs2.Comment", "//\n" },
		{ "keybcs2.Name", "EMysqlCharset::keybcs2" },
		{ "koi8r.Comment", "//\n" },
		{ "koi8r.Name", "EMysqlCharset::koi8r" },
		{ "koi8u.Comment", "//\n" },
		{ "koi8u.Name", "EMysqlCharset::koi8u" },
		{ "latin1.Comment", "//\n" },
		{ "latin1.Name", "EMysqlCharset::latin1" },
		{ "latin2.Comment", "//\n" },
		{ "latin2.Name", "EMysqlCharset::latin2" },
		{ "latin5.Comment", "//\n" },
		{ "latin5.Name", "EMysqlCharset::latin5" },
		{ "latin7.Comment", "//\n" },
		{ "latin7.Name", "EMysqlCharset::latin7" },
		{ "macce.Comment", "//\n" },
		{ "macce.Name", "EMysqlCharset::macce" },
		{ "macroman.Comment", "//\n" },
		{ "macroman.Name", "EMysqlCharset::macroman" },
		{ "ModuleRelativePath", "Public/Core/SimpleMysqlLinkType.h" },
		{ "None.Comment", "//\n" },
		{ "None.Name", "EMysqlCharset::None" },
		{ "sjis.Comment", "//\n" },
		{ "sjis.Name", "EMysqlCharset::sjis" },
		{ "swe7.Comment", "//\n" },
		{ "swe7.Name", "EMysqlCharset::swe7" },
		{ "tis620.Comment", "//\n" },
		{ "tis620.Name", "EMysqlCharset::tis620" },
		{ "ucs2.Comment", "//\n" },
		{ "ucs2.Name", "EMysqlCharset::ucs2" },
		{ "ujis.Comment", "//\n" },
		{ "ujis.Name", "EMysqlCharset::ujis" },
		{ "utf16.Comment", "//\n" },
		{ "utf16.Name", "EMysqlCharset::utf16" },
		{ "utf32.Comment", "//\n" },
		{ "utf32.Name", "EMysqlCharset::utf32" },
		{ "utf8.Comment", "//\n" },
		{ "utf8.Name", "EMysqlCharset::utf8" },
		{ "utf8mb4.Comment", "//\n" },
		{ "utf8mb4.Name", "EMysqlCharset::utf8mb4" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EMysqlCharset::None", (int64)EMysqlCharset::None },
		{ "EMysqlCharset::armscii8", (int64)EMysqlCharset::armscii8 },
		{ "EMysqlCharset::ascii", (int64)EMysqlCharset::ascii },
		{ "EMysqlCharset::big5", (int64)EMysqlCharset::big5 },
		{ "EMysqlCharset::binary", (int64)EMysqlCharset::binary },
		{ "EMysqlCharset::cp1250", (int64)EMysqlCharset::cp1250 },
		{ "EMysqlCharset::cp1251", (int64)EMysqlCharset::cp1251 },
		{ "EMysqlCharset::cp1256", (int64)EMysqlCharset::cp1256 },
		{ "EMysqlCharset::cp1257", (int64)EMysqlCharset::cp1257 },
		{ "EMysqlCharset::cp850", (int64)EMysqlCharset::cp850 },
		{ "EMysqlCharset::cp852", (int64)EMysqlCharset::cp852 },
		{ "EMysqlCharset::cp866", (int64)EMysqlCharset::cp866 },
		{ "EMysqlCharset::cp932", (int64)EMysqlCharset::cp932 },
		{ "EMysqlCharset::dec8", (int64)EMysqlCharset::dec8 },
		{ "EMysqlCharset::eucjpms", (int64)EMysqlCharset::eucjpms },
		{ "EMysqlCharset::euckr", (int64)EMysqlCharset::euckr },
		{ "EMysqlCharset::gb2312", (int64)EMysqlCharset::gb2312 },
		{ "EMysqlCharset::gbk", (int64)EMysqlCharset::gbk },
		{ "EMysqlCharset::geostd8", (int64)EMysqlCharset::geostd8 },
		{ "EMysqlCharset::greek", (int64)EMysqlCharset::greek },
		{ "EMysqlCharset::bebrew", (int64)EMysqlCharset::bebrew },
		{ "EMysqlCharset::hp8", (int64)EMysqlCharset::hp8 },
		{ "EMysqlCharset::keybcs2", (int64)EMysqlCharset::keybcs2 },
		{ "EMysqlCharset::koi8r", (int64)EMysqlCharset::koi8r },
		{ "EMysqlCharset::koi8u", (int64)EMysqlCharset::koi8u },
		{ "EMysqlCharset::latin1", (int64)EMysqlCharset::latin1 },
		{ "EMysqlCharset::latin2", (int64)EMysqlCharset::latin2 },
		{ "EMysqlCharset::latin5", (int64)EMysqlCharset::latin5 },
		{ "EMysqlCharset::latin7", (int64)EMysqlCharset::latin7 },
		{ "EMysqlCharset::macce", (int64)EMysqlCharset::macce },
		{ "EMysqlCharset::macroman", (int64)EMysqlCharset::macroman },
		{ "EMysqlCharset::sjis", (int64)EMysqlCharset::sjis },
		{ "EMysqlCharset::swe7", (int64)EMysqlCharset::swe7 },
		{ "EMysqlCharset::tis620", (int64)EMysqlCharset::tis620 },
		{ "EMysqlCharset::ucs2", (int64)EMysqlCharset::ucs2 },
		{ "EMysqlCharset::ujis", (int64)EMysqlCharset::ujis },
		{ "EMysqlCharset::utf16", (int64)EMysqlCharset::utf16 },
		{ "EMysqlCharset::utf32", (int64)EMysqlCharset::utf32 },
		{ "EMysqlCharset::utf8", (int64)EMysqlCharset::utf8 },
		{ "EMysqlCharset::utf8mb4", (int64)EMysqlCharset::utf8mb4 },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_SimpleMySQL_EMysqlCharset_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_SimpleMySQL,
	nullptr,
	"EMysqlCharset",
	"EMysqlCharset",
	Z_Construct_UEnum_SimpleMySQL_EMysqlCharset_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_SimpleMySQL_EMysqlCharset_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_SimpleMySQL_EMysqlCharset_Statics::Enum_MetaDataParams), Z_Construct_UEnum_SimpleMySQL_EMysqlCharset_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_SimpleMySQL_EMysqlCharset()
{
	if (!Z_Registration_Info_UEnum_EMysqlCharset.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EMysqlCharset.InnerSingleton, Z_Construct_UEnum_SimpleMySQL_EMysqlCharset_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EMysqlCharset.InnerSingleton;
}
// End Enum EMysqlCharset

// Begin Enum EMysqlDateType
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EMysqlDateType;
static UEnum* EMysqlDateType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EMysqlDateType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EMysqlDateType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_SimpleMySQL_EMysqlDateType, (UObject*)Z_Construct_UPackage__Script_SimpleMySQL(), TEXT("EMysqlDateType"));
	}
	return Z_Registration_Info_UEnum_EMysqlDateType.OuterSingleton;
}
template<> SIMPLEMYSQL_API UEnum* StaticEnum<EMysqlDateType>()
{
	return EMysqlDateType_StaticEnum();
}
struct Z_Construct_UEnum_SimpleMySQL_EMysqlDateType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "//UENUM(BlueprintType)\n//enum class EMysqlDirection :uint8\n//{\n//\n//};\n" },
		{ "DAY.DisplayName", "Day" },
		{ "DAY.Name", "EMysqlDateType::DAY" },
		{ "DAY_HOUR.DisplayName", "Day Hour" },
		{ "DAY_HOUR.Name", "EMysqlDateType::DAY_HOUR" },
		{ "DAY_MICROSECOND.DisplayName", "Day Microsecond" },
		{ "DAY_MICROSECOND.Name", "EMysqlDateType::DAY_MICROSECOND" },
		{ "DAY_MINUTE.DisplayName", "Day Minute" },
		{ "DAY_MINUTE.Name", "EMysqlDateType::DAY_MINUTE" },
		{ "DAY_SECOND.DisplayName", "Day Second" },
		{ "DAY_SECOND.Name", "EMysqlDateType::DAY_SECOND" },
		{ "HOUR.DisplayName", "Hour" },
		{ "HOUR.Name", "EMysqlDateType::HOUR" },
		{ "HOUR_MICROSECOND.DisplayName", "Hour Microsecond" },
		{ "HOUR_MICROSECOND.Name", "EMysqlDateType::HOUR_MICROSECOND" },
		{ "HOUR_MINUTE.DisplayName", "Hour Minute" },
		{ "HOUR_MINUTE.Name", "EMysqlDateType::HOUR_MINUTE" },
		{ "HOUR_SECOND.DisplayName", "Hour Second" },
		{ "HOUR_SECOND.Name", "EMysqlDateType::HOUR_SECOND" },
		{ "MICROSECOND.DisplayName", "Microsecond" },
		{ "MICROSECOND.Name", "EMysqlDateType::MICROSECOND" },
		{ "MINUTE.DisplayName", "Minute" },
		{ "MINUTE.Name", "EMysqlDateType::MINUTE" },
		{ "MINUTE_MICROSECOND.DisplayName", "Minute Microsecond" },
		{ "MINUTE_MICROSECOND.Name", "EMysqlDateType::MINUTE_MICROSECOND" },
		{ "MINUTE_SECOND.DisplayName", "Minute Second" },
		{ "MINUTE_SECOND.Name", "EMysqlDateType::MINUTE_SECOND" },
		{ "ModuleRelativePath", "Public/Core/SimpleMysqlLinkType.h" },
		{ "MONTH.DisplayName", "Month" },
		{ "MONTH.Name", "EMysqlDateType::MONTH" },
		{ "QUARTER.DisplayName", "Quarter" },
		{ "QUARTER.Name", "EMysqlDateType::QUARTER" },
		{ "SECOND.DisplayName", "Second" },
		{ "SECOND.Name", "EMysqlDateType::SECOND" },
		{ "SECOND_MICROSECOND.DisplayName", "Second Microsecond" },
		{ "SECOND_MICROSECOND.Name", "EMysqlDateType::SECOND_MICROSECOND" },
		{ "ToolTip", "UENUM(BlueprintType)\nenum class EMysqlDirection :uint8\n{\n\n};" },
		{ "WEEK.DisplayName", "Week" },
		{ "WEEK.Name", "EMysqlDateType::WEEK" },
		{ "YEAR.DisplayName", "Year" },
		{ "YEAR.Name", "EMysqlDateType::YEAR" },
		{ "YEAR_MONTH.DisplayName", "Year Month" },
		{ "YEAR_MONTH.Name", "EMysqlDateType::YEAR_MONTH" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EMysqlDateType::MICROSECOND", (int64)EMysqlDateType::MICROSECOND },
		{ "EMysqlDateType::SECOND", (int64)EMysqlDateType::SECOND },
		{ "EMysqlDateType::MINUTE", (int64)EMysqlDateType::MINUTE },
		{ "EMysqlDateType::HOUR", (int64)EMysqlDateType::HOUR },
		{ "EMysqlDateType::DAY", (int64)EMysqlDateType::DAY },
		{ "EMysqlDateType::WEEK", (int64)EMysqlDateType::WEEK },
		{ "EMysqlDateType::MONTH", (int64)EMysqlDateType::MONTH },
		{ "EMysqlDateType::QUARTER", (int64)EMysqlDateType::QUARTER },
		{ "EMysqlDateType::YEAR", (int64)EMysqlDateType::YEAR },
		{ "EMysqlDateType::SECOND_MICROSECOND", (int64)EMysqlDateType::SECOND_MICROSECOND },
		{ "EMysqlDateType::MINUTE_MICROSECOND", (int64)EMysqlDateType::MINUTE_MICROSECOND },
		{ "EMysqlDateType::MINUTE_SECOND", (int64)EMysqlDateType::MINUTE_SECOND },
		{ "EMysqlDateType::HOUR_MICROSECOND", (int64)EMysqlDateType::HOUR_MICROSECOND },
		{ "EMysqlDateType::HOUR_SECOND", (int64)EMysqlDateType::HOUR_SECOND },
		{ "EMysqlDateType::HOUR_MINUTE", (int64)EMysqlDateType::HOUR_MINUTE },
		{ "EMysqlDateType::DAY_MICROSECOND", (int64)EMysqlDateType::DAY_MICROSECOND },
		{ "EMysqlDateType::DAY_SECOND", (int64)EMysqlDateType::DAY_SECOND },
		{ "EMysqlDateType::DAY_MINUTE", (int64)EMysqlDateType::DAY_MINUTE },
		{ "EMysqlDateType::DAY_HOUR", (int64)EMysqlDateType::DAY_HOUR },
		{ "EMysqlDateType::YEAR_MONTH", (int64)EMysqlDateType::YEAR_MONTH },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_SimpleMySQL_EMysqlDateType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_SimpleMySQL,
	nullptr,
	"EMysqlDateType",
	"EMysqlDateType",
	Z_Construct_UEnum_SimpleMySQL_EMysqlDateType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_SimpleMySQL_EMysqlDateType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_SimpleMySQL_EMysqlDateType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_SimpleMySQL_EMysqlDateType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_SimpleMySQL_EMysqlDateType()
{
	if (!Z_Registration_Info_UEnum_EMysqlDateType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EMysqlDateType.InnerSingleton, Z_Construct_UEnum_SimpleMySQL_EMysqlDateType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EMysqlDateType.InnerSingleton;
}
// End Enum EMysqlDateType

// Begin Enum EMysqlJoinType
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EMysqlJoinType;
static UEnum* EMysqlJoinType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EMysqlJoinType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EMysqlJoinType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_SimpleMySQL_EMysqlJoinType, (UObject*)Z_Construct_UPackage__Script_SimpleMySQL(), TEXT("EMysqlJoinType"));
	}
	return Z_Registration_Info_UEnum_EMysqlJoinType.OuterSingleton;
}
template<> SIMPLEMYSQL_API UEnum* StaticEnum<EMysqlJoinType>()
{
	return EMysqlJoinType_StaticEnum();
}
struct Z_Construct_UEnum_SimpleMySQL_EMysqlJoinType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "INNER.DisplayName", "Inner" },
		{ "INNER.Name", "EMysqlJoinType::INNER" },
		{ "LEFT.DisplayName", "Left" },
		{ "LEFT.Name", "EMysqlJoinType::LEFT" },
		{ "ModuleRelativePath", "Public/Core/SimpleMysqlLinkType.h" },
		{ "NONE.DisplayName", "None" },
		{ "NONE.Name", "EMysqlJoinType::NONE" },
		{ "RIGHT.DisplayName", "Right" },
		{ "RIGHT.Name", "EMysqlJoinType::RIGHT" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EMysqlJoinType::NONE", (int64)EMysqlJoinType::NONE },
		{ "EMysqlJoinType::INNER", (int64)EMysqlJoinType::INNER },
		{ "EMysqlJoinType::LEFT", (int64)EMysqlJoinType::LEFT },
		{ "EMysqlJoinType::RIGHT", (int64)EMysqlJoinType::RIGHT },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_SimpleMySQL_EMysqlJoinType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_SimpleMySQL,
	nullptr,
	"EMysqlJoinType",
	"EMysqlJoinType",
	Z_Construct_UEnum_SimpleMySQL_EMysqlJoinType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_SimpleMySQL_EMysqlJoinType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_SimpleMySQL_EMysqlJoinType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_SimpleMySQL_EMysqlJoinType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_SimpleMySQL_EMysqlJoinType()
{
	if (!Z_Registration_Info_UEnum_EMysqlJoinType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EMysqlJoinType.InnerSingleton, Z_Construct_UEnum_SimpleMySQL_EMysqlJoinType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EMysqlJoinType.InnerSingleton;
}
// End Enum EMysqlJoinType

// Begin Enum EMysqlQuerySaveType
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EMysqlQuerySaveType;
static UEnum* EMysqlQuerySaveType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EMysqlQuerySaveType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EMysqlQuerySaveType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_SimpleMySQL_EMysqlQuerySaveType, (UObject*)Z_Construct_UPackage__Script_SimpleMySQL(), TEXT("EMysqlQuerySaveType"));
	}
	return Z_Registration_Info_UEnum_EMysqlQuerySaveType.OuterSingleton;
}
template<> SIMPLEMYSQL_API UEnum* StaticEnum<EMysqlQuerySaveType>()
{
	return EMysqlQuerySaveType_StaticEnum();
}
struct Z_Construct_UEnum_SimpleMySQL_EMysqlQuerySaveType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Core/SimpleMysqlLinkType.h" },
		{ "STORE_RESULT.DisplayName", "Store Result" },
		{ "STORE_RESULT.Name", "EMysqlQuerySaveType::STORE_RESULT" },
		{ "USE_RESULT.DisplayName", "Use Result" },
		{ "USE_RESULT.Name", "EMysqlQuerySaveType::USE_RESULT" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EMysqlQuerySaveType::STORE_RESULT", (int64)EMysqlQuerySaveType::STORE_RESULT },
		{ "EMysqlQuerySaveType::USE_RESULT", (int64)EMysqlQuerySaveType::USE_RESULT },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_SimpleMySQL_EMysqlQuerySaveType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_SimpleMySQL,
	nullptr,
	"EMysqlQuerySaveType",
	"EMysqlQuerySaveType",
	Z_Construct_UEnum_SimpleMySQL_EMysqlQuerySaveType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_SimpleMySQL_EMysqlQuerySaveType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_SimpleMySQL_EMysqlQuerySaveType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_SimpleMySQL_EMysqlQuerySaveType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_SimpleMySQL_EMysqlQuerySaveType()
{
	if (!Z_Registration_Info_UEnum_EMysqlQuerySaveType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EMysqlQuerySaveType.InnerSingleton, Z_Construct_UEnum_SimpleMySQL_EMysqlQuerySaveType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EMysqlQuerySaveType.InnerSingleton;
}
// End Enum EMysqlQuerySaveType

// Begin Enum EMysqlComparisonOperator
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EMysqlComparisonOperator;
static UEnum* EMysqlComparisonOperator_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EMysqlComparisonOperator.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EMysqlComparisonOperator.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_SimpleMySQL_EMysqlComparisonOperator, (UObject*)Z_Construct_UPackage__Script_SimpleMySQL(), TEXT("EMysqlComparisonOperator"));
	}
	return Z_Registration_Info_UEnum_EMysqlComparisonOperator.OuterSingleton;
}
template<> SIMPLEMYSQL_API UEnum* StaticEnum<EMysqlComparisonOperator>()
{
	return EMysqlComparisonOperator_StaticEnum();
}
struct Z_Construct_UEnum_SimpleMySQL_EMysqlComparisonOperator_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BETWEEN.DisplayName", ">=min&&<=max" },
		{ "BETWEEN.Name", "EMysqlComparisonOperator::BETWEEN" },
		{ "BlueprintType", "true" },
		{ "COMPARE_NULL_VALUES.DisplayName", "<=>" },
		{ "COMPARE_NULL_VALUES.Name", "EMysqlComparisonOperator::COMPARE_NULL_VALUES" },
		{ "EQUAL.DisplayName", "=" },
		{ "EQUAL.Name", "EMysqlComparisonOperator::EQUAL" },
		{ "GREATER_THAN.DisplayName", ">" },
		{ "GREATER_THAN.Name", "EMysqlComparisonOperator::GREATER_THAN" },
		{ "GREATER_THAN_OR_EQUAL.DisplayName", ">=" },
		{ "GREATER_THAN_OR_EQUAL.Name", "EMysqlComparisonOperator::GREATER_THAN_OR_EQUAL" },
		{ "IS_NOT_NULL.DisplayName", "Is not null" },
		{ "IS_NOT_NULL.Name", "EMysqlComparisonOperator::IS_NOT_NULL" },
		{ "IS_NULL.DisplayName", "Is_null" },
		{ "IS_NULL.Name", "EMysqlComparisonOperator::IS_NULL" },
		{ "LESS_THAN.DisplayName", "<" },
		{ "LESS_THAN.Name", "EMysqlComparisonOperator::LESS_THAN" },
		{ "LESS_THAN_OR_EQUAL.DisplayName", "<=" },
		{ "LESS_THAN_OR_EQUAL.Name", "EMysqlComparisonOperator::LESS_THAN_OR_EQUAL" },
		{ "LIKE.DisplayName", "like" },
		{ "LIKE.Name", "EMysqlComparisonOperator::LIKE" },
		{ "ModuleRelativePath", "Public/Core/SimpleMysqlLinkType.h" },
		{ "NOT_BETWEEN.DisplayName", "!(>=min&&<=max)" },
		{ "NOT_BETWEEN.Name", "EMysqlComparisonOperator::NOT_BETWEEN" },
		{ "NOT_EQUAL.DisplayName", "!=" },
		{ "NOT_EQUAL.Name", "EMysqlComparisonOperator::NOT_EQUAL" },
		{ "NOT_IN.DisplayName", "Not In" },
		{ "NOT_IN.Name", "EMysqlComparisonOperator::NOT_IN" },
		{ "REGEXP_OR_RLIKE.DisplayName", "Regular matching" },
		{ "REGEXP_OR_RLIKE.Name", "EMysqlComparisonOperator::REGEXP_OR_RLIKE" },
		{ "SQL_IN.DisplayName", "In" },
		{ "SQL_IN.Name", "EMysqlComparisonOperator::SQL_IN" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EMysqlComparisonOperator::EQUAL", (int64)EMysqlComparisonOperator::EQUAL },
		{ "EMysqlComparisonOperator::GREATER_THAN", (int64)EMysqlComparisonOperator::GREATER_THAN },
		{ "EMysqlComparisonOperator::LESS_THAN", (int64)EMysqlComparisonOperator::LESS_THAN },
		{ "EMysqlComparisonOperator::GREATER_THAN_OR_EQUAL", (int64)EMysqlComparisonOperator::GREATER_THAN_OR_EQUAL },
		{ "EMysqlComparisonOperator::LESS_THAN_OR_EQUAL", (int64)EMysqlComparisonOperator::LESS_THAN_OR_EQUAL },
		{ "EMysqlComparisonOperator::NOT_EQUAL", (int64)EMysqlComparisonOperator::NOT_EQUAL },
		{ "EMysqlComparisonOperator::BETWEEN", (int64)EMysqlComparisonOperator::BETWEEN },
		{ "EMysqlComparisonOperator::NOT_BETWEEN", (int64)EMysqlComparisonOperator::NOT_BETWEEN },
		{ "EMysqlComparisonOperator::SQL_IN", (int64)EMysqlComparisonOperator::SQL_IN },
		{ "EMysqlComparisonOperator::NOT_IN", (int64)EMysqlComparisonOperator::NOT_IN },
		{ "EMysqlComparisonOperator::COMPARE_NULL_VALUES", (int64)EMysqlComparisonOperator::COMPARE_NULL_VALUES },
		{ "EMysqlComparisonOperator::LIKE", (int64)EMysqlComparisonOperator::LIKE },
		{ "EMysqlComparisonOperator::REGEXP_OR_RLIKE", (int64)EMysqlComparisonOperator::REGEXP_OR_RLIKE },
		{ "EMysqlComparisonOperator::IS_NULL", (int64)EMysqlComparisonOperator::IS_NULL },
		{ "EMysqlComparisonOperator::IS_NOT_NULL", (int64)EMysqlComparisonOperator::IS_NOT_NULL },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_SimpleMySQL_EMysqlComparisonOperator_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_SimpleMySQL,
	nullptr,
	"EMysqlComparisonOperator",
	"EMysqlComparisonOperator",
	Z_Construct_UEnum_SimpleMySQL_EMysqlComparisonOperator_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_SimpleMySQL_EMysqlComparisonOperator_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_SimpleMySQL_EMysqlComparisonOperator_Statics::Enum_MetaDataParams), Z_Construct_UEnum_SimpleMySQL_EMysqlComparisonOperator_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_SimpleMySQL_EMysqlComparisonOperator()
{
	if (!Z_Registration_Info_UEnum_EMysqlComparisonOperator.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EMysqlComparisonOperator.InnerSingleton, Z_Construct_UEnum_SimpleMySQL_EMysqlComparisonOperator_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EMysqlComparisonOperator.InnerSingleton;
}
// End Enum EMysqlComparisonOperator

// Begin Enum EMysqlLogicalOperators
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EMysqlLogicalOperators;
static UEnum* EMysqlLogicalOperators_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EMysqlLogicalOperators.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EMysqlLogicalOperators.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_SimpleMySQL_EMysqlLogicalOperators, (UObject*)Z_Construct_UPackage__Script_SimpleMySQL(), TEXT("EMysqlLogicalOperators"));
	}
	return Z_Registration_Info_UEnum_EMysqlLogicalOperators.OuterSingleton;
}
template<> SIMPLEMYSQL_API UEnum* StaticEnum<EMysqlLogicalOperators>()
{
	return EMysqlLogicalOperators_StaticEnum();
}
struct Z_Construct_UEnum_SimpleMySQL_EMysqlLogicalOperators_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "AND.DisplayName", "&&" },
		{ "AND.Name", "EMysqlLogicalOperators::AND" },
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Core/SimpleMysqlLinkType.h" },
		{ "NONE.DisplayName", "NONE" },
		{ "NONE.Name", "EMysqlLogicalOperators::NONE" },
		{ "NOT.DisplayName", "!" },
		{ "NOT.Name", "EMysqlLogicalOperators::NOT" },
		{ "OR.DisplayName", "||" },
		{ "OR.Name", "EMysqlLogicalOperators::OR" },
		{ "XOR.DisplayName", "^" },
		{ "XOR.Name", "EMysqlLogicalOperators::XOR" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EMysqlLogicalOperators::NONE", (int64)EMysqlLogicalOperators::NONE },
		{ "EMysqlLogicalOperators::NOT", (int64)EMysqlLogicalOperators::NOT },
		{ "EMysqlLogicalOperators::AND", (int64)EMysqlLogicalOperators::AND },
		{ "EMysqlLogicalOperators::OR", (int64)EMysqlLogicalOperators::OR },
		{ "EMysqlLogicalOperators::XOR", (int64)EMysqlLogicalOperators::XOR },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_SimpleMySQL_EMysqlLogicalOperators_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_SimpleMySQL,
	nullptr,
	"EMysqlLogicalOperators",
	"EMysqlLogicalOperators",
	Z_Construct_UEnum_SimpleMySQL_EMysqlLogicalOperators_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_SimpleMySQL_EMysqlLogicalOperators_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_SimpleMySQL_EMysqlLogicalOperators_Statics::Enum_MetaDataParams), Z_Construct_UEnum_SimpleMySQL_EMysqlLogicalOperators_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_SimpleMySQL_EMysqlLogicalOperators()
{
	if (!Z_Registration_Info_UEnum_EMysqlLogicalOperators.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EMysqlLogicalOperators.InnerSingleton, Z_Construct_UEnum_SimpleMySQL_EMysqlLogicalOperators_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EMysqlLogicalOperators.InnerSingleton;
}
// End Enum EMysqlLogicalOperators

// Begin ScriptStruct FMysqlFieldType
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_MysqlFieldType;
class UScriptStruct* FMysqlFieldType::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_MysqlFieldType.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_MysqlFieldType.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FMysqlFieldType, (UObject*)Z_Construct_UPackage__Script_SimpleMySQL(), TEXT("MysqlFieldType"));
	}
	return Z_Registration_Info_UScriptStruct_MysqlFieldType.OuterSingleton;
}
template<> SIMPLEMYSQL_API UScriptStruct* StaticStruct<FMysqlFieldType>()
{
	return FMysqlFieldType::StaticStruct();
}
struct Z_Construct_UScriptStruct_FMysqlFieldType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Core/SimpleMysqlLinkType.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bUnsignedVariable_MetaData[] = {
		{ "Category", "SimpleMySQL|FieldType" },
		{ "ModuleRelativePath", "Public/Core/SimpleMysqlLinkType.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VariableType_MetaData[] = {
		{ "Category", "SimpleMySQL|FieldType" },
		{ "ModuleRelativePath", "Public/Core/SimpleMysqlLinkType.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VariableLen_MetaData[] = {
		{ "Category", "SimpleMySQL|FieldType" },
		{ "ModuleRelativePath", "Public/Core/SimpleMysqlLinkType.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DecimalPoint_MetaData[] = {
		{ "Category", "SimpleMySQL|FieldType" },
		{ "ModuleRelativePath", "Public/Core/SimpleMysqlLinkType.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bNULL_MetaData[] = {
		{ "Category", "SimpleMySQL|FieldType" },
		{ "ModuleRelativePath", "Public/Core/SimpleMysqlLinkType.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultValue_MetaData[] = {
		{ "Category", "SimpleMySQL|FieldType" },
		{ "ModuleRelativePath", "Public/Core/SimpleMysqlLinkType.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAutoIncrement_MetaData[] = {
		{ "Category", "SimpleMySQL|FieldType" },
		{ "ModuleRelativePath", "Public/Core/SimpleMysqlLinkType.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Comment_MetaData[] = {
		{ "Category", "SimpleMySQL|FieldType" },
		{ "ModuleRelativePath", "Public/Core/SimpleMysqlLinkType.h" },
	};
#endif // WITH_METADATA
	static void NewProp_bUnsignedVariable_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bUnsignedVariable;
	static const UECodeGen_Private::FBytePropertyParams NewProp_VariableType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_VariableType;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_VariableLen;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_DecimalPoint;
	static void NewProp_bNULL_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bNULL;
	static const UECodeGen_Private::FStrPropertyParams NewProp_DefaultValue;
	static void NewProp_bAutoIncrement_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAutoIncrement;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Comment;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FMysqlFieldType>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
void Z_Construct_UScriptStruct_FMysqlFieldType_Statics::NewProp_bUnsignedVariable_SetBit(void* Obj)
{
	((FMysqlFieldType*)Obj)->bUnsignedVariable = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FMysqlFieldType_Statics::NewProp_bUnsignedVariable = { "bUnsignedVariable", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FMysqlFieldType), &Z_Construct_UScriptStruct_FMysqlFieldType_Statics::NewProp_bUnsignedVariable_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bUnsignedVariable_MetaData), NewProp_bUnsignedVariable_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FMysqlFieldType_Statics::NewProp_VariableType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FMysqlFieldType_Statics::NewProp_VariableType = { "VariableType", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMysqlFieldType, VariableType), Z_Construct_UEnum_SimpleMySQL_EMysqlVariableType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VariableType_MetaData), NewProp_VariableType_MetaData) }; // 1623531787
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FMysqlFieldType_Statics::NewProp_VariableLen = { "VariableLen", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMysqlFieldType, VariableLen), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VariableLen_MetaData), NewProp_VariableLen_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FMysqlFieldType_Statics::NewProp_DecimalPoint = { "DecimalPoint", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMysqlFieldType, DecimalPoint), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DecimalPoint_MetaData), NewProp_DecimalPoint_MetaData) };
void Z_Construct_UScriptStruct_FMysqlFieldType_Statics::NewProp_bNULL_SetBit(void* Obj)
{
	((FMysqlFieldType*)Obj)->bNULL = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FMysqlFieldType_Statics::NewProp_bNULL = { "bNULL", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FMysqlFieldType), &Z_Construct_UScriptStruct_FMysqlFieldType_Statics::NewProp_bNULL_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bNULL_MetaData), NewProp_bNULL_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FMysqlFieldType_Statics::NewProp_DefaultValue = { "DefaultValue", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMysqlFieldType, DefaultValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultValue_MetaData), NewProp_DefaultValue_MetaData) };
void Z_Construct_UScriptStruct_FMysqlFieldType_Statics::NewProp_bAutoIncrement_SetBit(void* Obj)
{
	((FMysqlFieldType*)Obj)->bAutoIncrement = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FMysqlFieldType_Statics::NewProp_bAutoIncrement = { "bAutoIncrement", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FMysqlFieldType), &Z_Construct_UScriptStruct_FMysqlFieldType_Statics::NewProp_bAutoIncrement_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAutoIncrement_MetaData), NewProp_bAutoIncrement_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FMysqlFieldType_Statics::NewProp_Comment = { "Comment", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMysqlFieldType, Comment), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Comment_MetaData), NewProp_Comment_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FMysqlFieldType_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMysqlFieldType_Statics::NewProp_bUnsignedVariable,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMysqlFieldType_Statics::NewProp_VariableType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMysqlFieldType_Statics::NewProp_VariableType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMysqlFieldType_Statics::NewProp_VariableLen,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMysqlFieldType_Statics::NewProp_DecimalPoint,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMysqlFieldType_Statics::NewProp_bNULL,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMysqlFieldType_Statics::NewProp_DefaultValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMysqlFieldType_Statics::NewProp_bAutoIncrement,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMysqlFieldType_Statics::NewProp_Comment,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMysqlFieldType_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FMysqlFieldType_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_SimpleMySQL,
	nullptr,
	&NewStructOps,
	"MysqlFieldType",
	Z_Construct_UScriptStruct_FMysqlFieldType_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMysqlFieldType_Statics::PropPointers),
	sizeof(FMysqlFieldType),
	alignof(FMysqlFieldType),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMysqlFieldType_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FMysqlFieldType_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FMysqlFieldType()
{
	if (!Z_Registration_Info_UScriptStruct_MysqlFieldType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_MysqlFieldType.InnerSingleton, Z_Construct_UScriptStruct_FMysqlFieldType_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_MysqlFieldType.InnerSingleton;
}
// End ScriptStruct FMysqlFieldType

// Begin ScriptStruct FMysqlCreateTableParam
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_MysqlCreateTableParam;
class UScriptStruct* FMysqlCreateTableParam::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_MysqlCreateTableParam.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_MysqlCreateTableParam.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FMysqlCreateTableParam, (UObject*)Z_Construct_UPackage__Script_SimpleMySQL(), TEXT("MysqlCreateTableParam"));
	}
	return Z_Registration_Info_UScriptStruct_MysqlCreateTableParam.OuterSingleton;
}
template<> SIMPLEMYSQL_API UScriptStruct* StaticStruct<FMysqlCreateTableParam>()
{
	return FMysqlCreateTableParam::StaticStruct();
}
struct Z_Construct_UScriptStruct_FMysqlCreateTableParam_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Core/SimpleMysqlLinkType.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SaveEngine_MetaData[] = {
		{ "Category", "SimpleMySQL|CreateTableParam" },
		{ "ModuleRelativePath", "Public/Core/SimpleMysqlLinkType.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Charset_MetaData[] = {
		{ "Category", "SimpleMySQL|CreateTableParam" },
		{ "ModuleRelativePath", "Public/Core/SimpleMysqlLinkType.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_SaveEngine_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_SaveEngine;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Charset_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Charset;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FMysqlCreateTableParam>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FMysqlCreateTableParam_Statics::NewProp_SaveEngine_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FMysqlCreateTableParam_Statics::NewProp_SaveEngine = { "SaveEngine", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMysqlCreateTableParam, SaveEngine), Z_Construct_UEnum_SimpleMySQL_EMysqlSaveEngine, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SaveEngine_MetaData), NewProp_SaveEngine_MetaData) }; // 2142121027
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FMysqlCreateTableParam_Statics::NewProp_Charset_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FMysqlCreateTableParam_Statics::NewProp_Charset = { "Charset", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMysqlCreateTableParam, Charset), Z_Construct_UEnum_SimpleMySQL_EMysqlCharset, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Charset_MetaData), NewProp_Charset_MetaData) }; // 200248681
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FMysqlCreateTableParam_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMysqlCreateTableParam_Statics::NewProp_SaveEngine_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMysqlCreateTableParam_Statics::NewProp_SaveEngine,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMysqlCreateTableParam_Statics::NewProp_Charset_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMysqlCreateTableParam_Statics::NewProp_Charset,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMysqlCreateTableParam_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FMysqlCreateTableParam_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_SimpleMySQL,
	nullptr,
	&NewStructOps,
	"MysqlCreateTableParam",
	Z_Construct_UScriptStruct_FMysqlCreateTableParam_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMysqlCreateTableParam_Statics::PropPointers),
	sizeof(FMysqlCreateTableParam),
	alignof(FMysqlCreateTableParam),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMysqlCreateTableParam_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FMysqlCreateTableParam_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FMysqlCreateTableParam()
{
	if (!Z_Registration_Info_UScriptStruct_MysqlCreateTableParam.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_MysqlCreateTableParam.InnerSingleton, Z_Construct_UScriptStruct_FMysqlCreateTableParam_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_MysqlCreateTableParam.InnerSingleton;
}
// End ScriptStruct FMysqlCreateTableParam

// Begin ScriptStruct FSimpleMysqlResult
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_SimpleMysqlResult;
class UScriptStruct* FSimpleMysqlResult::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_SimpleMysqlResult.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_SimpleMysqlResult.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSimpleMysqlResult, (UObject*)Z_Construct_UPackage__Script_SimpleMySQL(), TEXT("SimpleMysqlResult"));
	}
	return Z_Registration_Info_UScriptStruct_SimpleMysqlResult.OuterSingleton;
}
template<> SIMPLEMYSQL_API UScriptStruct* StaticStruct<FSimpleMysqlResult>()
{
	return FSimpleMysqlResult::StaticStruct();
}
struct Z_Construct_UScriptStruct_FSimpleMysqlResult_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Core/SimpleMysqlLinkType.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Rows_MetaData[] = {
		{ "Category", "SimpleMySQL|MysqlResult" },
		{ "ModuleRelativePath", "Public/Core/SimpleMysqlLinkType.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_Rows_ValueProp;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Rows_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_Rows;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSimpleMysqlResult>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FSimpleMysqlResult_Statics::NewProp_Rows_ValueProp = { "Rows", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FSimpleMysqlResult_Statics::NewProp_Rows_Key_KeyProp = { "Rows_Key", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UScriptStruct_FSimpleMysqlResult_Statics::NewProp_Rows = { "Rows", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSimpleMysqlResult, Rows), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Rows_MetaData), NewProp_Rows_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSimpleMysqlResult_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSimpleMysqlResult_Statics::NewProp_Rows_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSimpleMysqlResult_Statics::NewProp_Rows_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSimpleMysqlResult_Statics::NewProp_Rows,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSimpleMysqlResult_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSimpleMysqlResult_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_SimpleMySQL,
	nullptr,
	&NewStructOps,
	"SimpleMysqlResult",
	Z_Construct_UScriptStruct_FSimpleMysqlResult_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSimpleMysqlResult_Statics::PropPointers),
	sizeof(FSimpleMysqlResult),
	alignof(FSimpleMysqlResult),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSimpleMysqlResult_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FSimpleMysqlResult_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FSimpleMysqlResult()
{
	if (!Z_Registration_Info_UScriptStruct_SimpleMysqlResult.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_SimpleMysqlResult.InnerSingleton, Z_Construct_UScriptStruct_FSimpleMysqlResult_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_SimpleMysqlResult.InnerSingleton;
}
// End ScriptStruct FSimpleMysqlResult

// Begin ScriptStruct FSimpleMysqlDebugResult
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_SimpleMysqlDebugResult;
class UScriptStruct* FSimpleMysqlDebugResult::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_SimpleMysqlDebugResult.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_SimpleMysqlDebugResult.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSimpleMysqlDebugResult, (UObject*)Z_Construct_UPackage__Script_SimpleMySQL(), TEXT("SimpleMysqlDebugResult"));
	}
	return Z_Registration_Info_UScriptStruct_SimpleMysqlDebugResult.OuterSingleton;
}
template<> SIMPLEMYSQL_API UScriptStruct* StaticStruct<FSimpleMysqlDebugResult>()
{
	return FSimpleMysqlDebugResult::StaticStruct();
}
struct Z_Construct_UScriptStruct_FSimpleMysqlDebugResult_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Core/SimpleMysqlLinkType.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bPrintToScreen_MetaData[] = {
		{ "Category", "SimpleMySQL|DebugResult" },
		{ "EditCondition", "bDebug" },
		{ "ModuleRelativePath", "Public/Core/SimpleMysqlLinkType.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bPrintToLog_MetaData[] = {
		{ "Category", "SimpleMySQL|DebugResult" },
		{ "EditCondition", "bDebug" },
		{ "ModuleRelativePath", "Public/Core/SimpleMysqlLinkType.h" },
	};
#endif // WITH_METADATA
	static void NewProp_bPrintToScreen_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bPrintToScreen;
	static void NewProp_bPrintToLog_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bPrintToLog;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSimpleMysqlDebugResult>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
void Z_Construct_UScriptStruct_FSimpleMysqlDebugResult_Statics::NewProp_bPrintToScreen_SetBit(void* Obj)
{
	((FSimpleMysqlDebugResult*)Obj)->bPrintToScreen = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FSimpleMysqlDebugResult_Statics::NewProp_bPrintToScreen = { "bPrintToScreen", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FSimpleMysqlDebugResult), &Z_Construct_UScriptStruct_FSimpleMysqlDebugResult_Statics::NewProp_bPrintToScreen_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bPrintToScreen_MetaData), NewProp_bPrintToScreen_MetaData) };
void Z_Construct_UScriptStruct_FSimpleMysqlDebugResult_Statics::NewProp_bPrintToLog_SetBit(void* Obj)
{
	((FSimpleMysqlDebugResult*)Obj)->bPrintToLog = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FSimpleMysqlDebugResult_Statics::NewProp_bPrintToLog = { "bPrintToLog", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FSimpleMysqlDebugResult), &Z_Construct_UScriptStruct_FSimpleMysqlDebugResult_Statics::NewProp_bPrintToLog_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bPrintToLog_MetaData), NewProp_bPrintToLog_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSimpleMysqlDebugResult_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSimpleMysqlDebugResult_Statics::NewProp_bPrintToScreen,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSimpleMysqlDebugResult_Statics::NewProp_bPrintToLog,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSimpleMysqlDebugResult_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSimpleMysqlDebugResult_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_SimpleMySQL,
	nullptr,
	&NewStructOps,
	"SimpleMysqlDebugResult",
	Z_Construct_UScriptStruct_FSimpleMysqlDebugResult_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSimpleMysqlDebugResult_Statics::PropPointers),
	sizeof(FSimpleMysqlDebugResult),
	alignof(FSimpleMysqlDebugResult),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSimpleMysqlDebugResult_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FSimpleMysqlDebugResult_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FSimpleMysqlDebugResult()
{
	if (!Z_Registration_Info_UScriptStruct_SimpleMysqlDebugResult.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_SimpleMysqlDebugResult.InnerSingleton, Z_Construct_UScriptStruct_FSimpleMysqlDebugResult_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_SimpleMysqlDebugResult.InnerSingleton;
}
// End ScriptStruct FSimpleMysqlDebugResult

// Begin ScriptStruct FSimpleMysqlQueryOrderBy
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_SimpleMysqlQueryOrderBy;
class UScriptStruct* FSimpleMysqlQueryOrderBy::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_SimpleMysqlQueryOrderBy.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_SimpleMysqlQueryOrderBy.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSimpleMysqlQueryOrderBy, (UObject*)Z_Construct_UPackage__Script_SimpleMySQL(), TEXT("SimpleMysqlQueryOrderBy"));
	}
	return Z_Registration_Info_UScriptStruct_SimpleMysqlQueryOrderBy.OuterSingleton;
}
template<> SIMPLEMYSQL_API UScriptStruct* StaticStruct<FSimpleMysqlQueryOrderBy>()
{
	return FSimpleMysqlQueryOrderBy::StaticStruct();
}
struct Z_Construct_UScriptStruct_FSimpleMysqlQueryOrderBy_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Core/SimpleMysqlLinkType.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FieldName_MetaData[] = {
		{ "Category", "SimpleMySQL|OrderBy" },
		{ "ModuleRelativePath", "Public/Core/SimpleMysqlLinkType.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bDesc_MetaData[] = {
		{ "Category", "SimpleMySQL|OrderBy" },
		{ "Comment", "//asc  //\xe7\x94\xb1\xe5\xa4\xa7\xe5\x88\xb0\xe5\xb0\x8f\n//desc //\xe7\x94\xb1\xe5\xb0\x8f\xe5\x88\xb0\xe5\xa4\xa7\n" },
		{ "ModuleRelativePath", "Public/Core/SimpleMysqlLinkType.h" },
		{ "ToolTip", "asc  \xe7\x94\xb1\xe5\xa4\xa7\xe5\x88\xb0\xe5\xb0\x8f\ndesc \xe7\x94\xb1\xe5\xb0\x8f\xe5\x88\xb0\xe5\xa4\xa7" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_FieldName;
	static void NewProp_bDesc_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDesc;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSimpleMysqlQueryOrderBy>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FSimpleMysqlQueryOrderBy_Statics::NewProp_FieldName = { "FieldName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSimpleMysqlQueryOrderBy, FieldName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FieldName_MetaData), NewProp_FieldName_MetaData) };
void Z_Construct_UScriptStruct_FSimpleMysqlQueryOrderBy_Statics::NewProp_bDesc_SetBit(void* Obj)
{
	((FSimpleMysqlQueryOrderBy*)Obj)->bDesc = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FSimpleMysqlQueryOrderBy_Statics::NewProp_bDesc = { "bDesc", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FSimpleMysqlQueryOrderBy), &Z_Construct_UScriptStruct_FSimpleMysqlQueryOrderBy_Statics::NewProp_bDesc_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bDesc_MetaData), NewProp_bDesc_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSimpleMysqlQueryOrderBy_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSimpleMysqlQueryOrderBy_Statics::NewProp_FieldName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSimpleMysqlQueryOrderBy_Statics::NewProp_bDesc,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSimpleMysqlQueryOrderBy_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSimpleMysqlQueryOrderBy_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_SimpleMySQL,
	nullptr,
	&NewStructOps,
	"SimpleMysqlQueryOrderBy",
	Z_Construct_UScriptStruct_FSimpleMysqlQueryOrderBy_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSimpleMysqlQueryOrderBy_Statics::PropPointers),
	sizeof(FSimpleMysqlQueryOrderBy),
	alignof(FSimpleMysqlQueryOrderBy),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSimpleMysqlQueryOrderBy_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FSimpleMysqlQueryOrderBy_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FSimpleMysqlQueryOrderBy()
{
	if (!Z_Registration_Info_UScriptStruct_SimpleMysqlQueryOrderBy.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_SimpleMysqlQueryOrderBy.InnerSingleton, Z_Construct_UScriptStruct_FSimpleMysqlQueryOrderBy_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_SimpleMysqlQueryOrderBy.InnerSingleton;
}
// End ScriptStruct FSimpleMysqlQueryOrderBy

// Begin ScriptStruct FSimpleMysqlJoinParameters
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_SimpleMysqlJoinParameters;
class UScriptStruct* FSimpleMysqlJoinParameters::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_SimpleMysqlJoinParameters.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_SimpleMysqlJoinParameters.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSimpleMysqlJoinParameters, (UObject*)Z_Construct_UPackage__Script_SimpleMySQL(), TEXT("SimpleMysqlJoinParameters"));
	}
	return Z_Registration_Info_UScriptStruct_SimpleMysqlJoinParameters.OuterSingleton;
}
template<> SIMPLEMYSQL_API UScriptStruct* StaticStruct<FSimpleMysqlJoinParameters>()
{
	return FSimpleMysqlJoinParameters::StaticStruct();
}
struct Z_Construct_UScriptStruct_FSimpleMysqlJoinParameters_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Core/SimpleMysqlLinkType.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JoinType_MetaData[] = {
		{ "Category", "SimpleMySQL|QueryParameters" },
		{ "ModuleRelativePath", "Public/Core/SimpleMysqlLinkType.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TableName_MetaData[] = {
		{ "Category", "SimpleMySQL|QueryParameters" },
		{ "ModuleRelativePath", "Public/Core/SimpleMysqlLinkType.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Condition_MetaData[] = {
		{ "Category", "SimpleMySQL|QueryParameters" },
		{ "ModuleRelativePath", "Public/Core/SimpleMysqlLinkType.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_JoinType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_JoinType;
	static const UECodeGen_Private::FStrPropertyParams NewProp_TableName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Condition;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSimpleMysqlJoinParameters>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FSimpleMysqlJoinParameters_Statics::NewProp_JoinType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FSimpleMysqlJoinParameters_Statics::NewProp_JoinType = { "JoinType", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSimpleMysqlJoinParameters, JoinType), Z_Construct_UEnum_SimpleMySQL_EMysqlJoinType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JoinType_MetaData), NewProp_JoinType_MetaData) }; // 167747009
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FSimpleMysqlJoinParameters_Statics::NewProp_TableName = { "TableName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSimpleMysqlJoinParameters, TableName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TableName_MetaData), NewProp_TableName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FSimpleMysqlJoinParameters_Statics::NewProp_Condition = { "Condition", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSimpleMysqlJoinParameters, Condition), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Condition_MetaData), NewProp_Condition_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSimpleMysqlJoinParameters_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSimpleMysqlJoinParameters_Statics::NewProp_JoinType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSimpleMysqlJoinParameters_Statics::NewProp_JoinType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSimpleMysqlJoinParameters_Statics::NewProp_TableName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSimpleMysqlJoinParameters_Statics::NewProp_Condition,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSimpleMysqlJoinParameters_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSimpleMysqlJoinParameters_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_SimpleMySQL,
	nullptr,
	&NewStructOps,
	"SimpleMysqlJoinParameters",
	Z_Construct_UScriptStruct_FSimpleMysqlJoinParameters_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSimpleMysqlJoinParameters_Statics::PropPointers),
	sizeof(FSimpleMysqlJoinParameters),
	alignof(FSimpleMysqlJoinParameters),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSimpleMysqlJoinParameters_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FSimpleMysqlJoinParameters_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FSimpleMysqlJoinParameters()
{
	if (!Z_Registration_Info_UScriptStruct_SimpleMysqlJoinParameters.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_SimpleMysqlJoinParameters.InnerSingleton, Z_Construct_UScriptStruct_FSimpleMysqlJoinParameters_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_SimpleMysqlJoinParameters.InnerSingleton;
}
// End ScriptStruct FSimpleMysqlJoinParameters

// Begin ScriptStruct FSimpleMysqlAssignment
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_SimpleMysqlAssignment;
class UScriptStruct* FSimpleMysqlAssignment::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_SimpleMysqlAssignment.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_SimpleMysqlAssignment.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSimpleMysqlAssignment, (UObject*)Z_Construct_UPackage__Script_SimpleMySQL(), TEXT("SimpleMysqlAssignment"));
	}
	return Z_Registration_Info_UScriptStruct_SimpleMysqlAssignment.OuterSingleton;
}
template<> SIMPLEMYSQL_API UScriptStruct* StaticStruct<FSimpleMysqlAssignment>()
{
	return FSimpleMysqlAssignment::StaticStruct();
}
struct Z_Construct_UScriptStruct_FSimpleMysqlAssignment_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Core/SimpleMysqlLinkType.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_A_MetaData[] = {
		{ "Category", "SimpleMySQL|Assignment" },
		{ "ModuleRelativePath", "Public/Core/SimpleMysqlLinkType.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ComparisonOperator_MetaData[] = {
		{ "Category", "SimpleMySQL|Assignment" },
		{ "ModuleRelativePath", "Public/Core/SimpleMysqlLinkType.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_B_MetaData[] = {
		{ "Category", "SimpleMySQL|Assignment" },
		{ "ModuleRelativePath", "Public/Core/SimpleMysqlLinkType.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_A;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ComparisonOperator_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ComparisonOperator;
	static const UECodeGen_Private::FStrPropertyParams NewProp_B;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSimpleMysqlAssignment>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FSimpleMysqlAssignment_Statics::NewProp_A = { "A", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSimpleMysqlAssignment, A), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_A_MetaData), NewProp_A_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FSimpleMysqlAssignment_Statics::NewProp_ComparisonOperator_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FSimpleMysqlAssignment_Statics::NewProp_ComparisonOperator = { "ComparisonOperator", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSimpleMysqlAssignment, ComparisonOperator), Z_Construct_UEnum_SimpleMySQL_EMysqlComparisonOperator, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ComparisonOperator_MetaData), NewProp_ComparisonOperator_MetaData) }; // 607162403
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FSimpleMysqlAssignment_Statics::NewProp_B = { "B", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSimpleMysqlAssignment, B), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_B_MetaData), NewProp_B_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSimpleMysqlAssignment_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSimpleMysqlAssignment_Statics::NewProp_A,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSimpleMysqlAssignment_Statics::NewProp_ComparisonOperator_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSimpleMysqlAssignment_Statics::NewProp_ComparisonOperator,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSimpleMysqlAssignment_Statics::NewProp_B,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSimpleMysqlAssignment_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSimpleMysqlAssignment_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_SimpleMySQL,
	nullptr,
	&NewStructOps,
	"SimpleMysqlAssignment",
	Z_Construct_UScriptStruct_FSimpleMysqlAssignment_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSimpleMysqlAssignment_Statics::PropPointers),
	sizeof(FSimpleMysqlAssignment),
	alignof(FSimpleMysqlAssignment),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSimpleMysqlAssignment_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FSimpleMysqlAssignment_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FSimpleMysqlAssignment()
{
	if (!Z_Registration_Info_UScriptStruct_SimpleMysqlAssignment.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_SimpleMysqlAssignment.InnerSingleton, Z_Construct_UScriptStruct_FSimpleMysqlAssignment_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_SimpleMysqlAssignment.InnerSingleton;
}
// End ScriptStruct FSimpleMysqlAssignment

// Begin ScriptStruct FSimpleMysqlComparisonOperator
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_SimpleMysqlComparisonOperator;
class UScriptStruct* FSimpleMysqlComparisonOperator::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_SimpleMysqlComparisonOperator.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_SimpleMysqlComparisonOperator.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSimpleMysqlComparisonOperator, (UObject*)Z_Construct_UPackage__Script_SimpleMySQL(), TEXT("SimpleMysqlComparisonOperator"));
	}
	return Z_Registration_Info_UScriptStruct_SimpleMysqlComparisonOperator.OuterSingleton;
}
template<> SIMPLEMYSQL_API UScriptStruct* StaticStruct<FSimpleMysqlComparisonOperator>()
{
	return FSimpleMysqlComparisonOperator::StaticStruct();
}
struct Z_Construct_UScriptStruct_FSimpleMysqlComparisonOperator_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Core/SimpleMysqlLinkType.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Assignment_MetaData[] = {
		{ "Category", "SimpleMySQL|ComparisonOperator" },
		{ "ModuleRelativePath", "Public/Core/SimpleMysqlLinkType.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LogicalOperators_MetaData[] = {
		{ "Category", "SimpleMySQL|ComparisonOperator" },
		{ "ModuleRelativePath", "Public/Core/SimpleMysqlLinkType.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Assignment;
	static const UECodeGen_Private::FBytePropertyParams NewProp_LogicalOperators_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_LogicalOperators;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSimpleMysqlComparisonOperator>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSimpleMysqlComparisonOperator_Statics::NewProp_Assignment = { "Assignment", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSimpleMysqlComparisonOperator, Assignment), Z_Construct_UScriptStruct_FSimpleMysqlAssignment, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Assignment_MetaData), NewProp_Assignment_MetaData) }; // 3943474943
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FSimpleMysqlComparisonOperator_Statics::NewProp_LogicalOperators_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FSimpleMysqlComparisonOperator_Statics::NewProp_LogicalOperators = { "LogicalOperators", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSimpleMysqlComparisonOperator, LogicalOperators), Z_Construct_UEnum_SimpleMySQL_EMysqlLogicalOperators, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LogicalOperators_MetaData), NewProp_LogicalOperators_MetaData) }; // 1138254964
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSimpleMysqlComparisonOperator_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSimpleMysqlComparisonOperator_Statics::NewProp_Assignment,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSimpleMysqlComparisonOperator_Statics::NewProp_LogicalOperators_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSimpleMysqlComparisonOperator_Statics::NewProp_LogicalOperators,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSimpleMysqlComparisonOperator_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSimpleMysqlComparisonOperator_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_SimpleMySQL,
	nullptr,
	&NewStructOps,
	"SimpleMysqlComparisonOperator",
	Z_Construct_UScriptStruct_FSimpleMysqlComparisonOperator_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSimpleMysqlComparisonOperator_Statics::PropPointers),
	sizeof(FSimpleMysqlComparisonOperator),
	alignof(FSimpleMysqlComparisonOperator),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSimpleMysqlComparisonOperator_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FSimpleMysqlComparisonOperator_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FSimpleMysqlComparisonOperator()
{
	if (!Z_Registration_Info_UScriptStruct_SimpleMysqlComparisonOperator.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_SimpleMysqlComparisonOperator.InnerSingleton, Z_Construct_UScriptStruct_FSimpleMysqlComparisonOperator_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_SimpleMysqlComparisonOperator.InnerSingleton;
}
// End ScriptStruct FSimpleMysqlComparisonOperator

// Begin ScriptStruct FSimpleMysqlVariableSettings
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_SimpleMysqlVariableSettings;
class UScriptStruct* FSimpleMysqlVariableSettings::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_SimpleMysqlVariableSettings.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_SimpleMysqlVariableSettings.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSimpleMysqlVariableSettings, (UObject*)Z_Construct_UPackage__Script_SimpleMySQL(), TEXT("SimpleMysqlVariableSettings"));
	}
	return Z_Registration_Info_UScriptStruct_SimpleMysqlVariableSettings.OuterSingleton;
}
template<> SIMPLEMYSQL_API UScriptStruct* StaticStruct<FSimpleMysqlVariableSettings>()
{
	return FSimpleMysqlVariableSettings::StaticStruct();
}
struct Z_Construct_UScriptStruct_FSimpleMysqlVariableSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Core/SimpleMysqlLinkType.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VariableName_MetaData[] = {
		{ "Category", "SimpleMySQL|VariableSettings" },
		{ "ModuleRelativePath", "Public/Core/SimpleMysqlLinkType.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AsName_MetaData[] = {
		{ "Category", "SimpleMySQL|VariableSettings" },
		{ "ModuleRelativePath", "Public/Core/SimpleMysqlLinkType.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_VariableName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_AsName;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSimpleMysqlVariableSettings>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FSimpleMysqlVariableSettings_Statics::NewProp_VariableName = { "VariableName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSimpleMysqlVariableSettings, VariableName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VariableName_MetaData), NewProp_VariableName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FSimpleMysqlVariableSettings_Statics::NewProp_AsName = { "AsName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSimpleMysqlVariableSettings, AsName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AsName_MetaData), NewProp_AsName_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSimpleMysqlVariableSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSimpleMysqlVariableSettings_Statics::NewProp_VariableName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSimpleMysqlVariableSettings_Statics::NewProp_AsName,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSimpleMysqlVariableSettings_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSimpleMysqlVariableSettings_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_SimpleMySQL,
	nullptr,
	&NewStructOps,
	"SimpleMysqlVariableSettings",
	Z_Construct_UScriptStruct_FSimpleMysqlVariableSettings_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSimpleMysqlVariableSettings_Statics::PropPointers),
	sizeof(FSimpleMysqlVariableSettings),
	alignof(FSimpleMysqlVariableSettings),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSimpleMysqlVariableSettings_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FSimpleMysqlVariableSettings_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FSimpleMysqlVariableSettings()
{
	if (!Z_Registration_Info_UScriptStruct_SimpleMysqlVariableSettings.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_SimpleMysqlVariableSettings.InnerSingleton, Z_Construct_UScriptStruct_FSimpleMysqlVariableSettings_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_SimpleMysqlVariableSettings.InnerSingleton;
}
// End ScriptStruct FSimpleMysqlVariableSettings

// Begin ScriptStruct FSimpleMysqlQueryParameters
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_SimpleMysqlQueryParameters;
class UScriptStruct* FSimpleMysqlQueryParameters::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_SimpleMysqlQueryParameters.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_SimpleMysqlQueryParameters.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSimpleMysqlQueryParameters, (UObject*)Z_Construct_UPackage__Script_SimpleMySQL(), TEXT("SimpleMysqlQueryParameters"));
	}
	return Z_Registration_Info_UScriptStruct_SimpleMysqlQueryParameters.OuterSingleton;
}
template<> SIMPLEMYSQL_API UScriptStruct* StaticStruct<FSimpleMysqlQueryParameters>()
{
	return FSimpleMysqlQueryParameters::StaticStruct();
}
struct Z_Construct_UScriptStruct_FSimpleMysqlQueryParameters_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Core/SimpleMysqlLinkType.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FuntionSettings_MetaData[] = {
		{ "Category", "SimpleMySQL|QueryParameters" },
		{ "ModuleRelativePath", "Public/Core/SimpleMysqlLinkType.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TableName_MetaData[] = {
		{ "Category", "SimpleMySQL|QueryParameters" },
		{ "ModuleRelativePath", "Public/Core/SimpleMysqlLinkType.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InFields_MetaData[] = {
		{ "Category", "SimpleMySQL|QueryParameters" },
		{ "ModuleRelativePath", "Public/Core/SimpleMysqlLinkType.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bDistinct_MetaData[] = {
		{ "Category", "SimpleMySQL|QueryParameters" },
		{ "ModuleRelativePath", "Public/Core/SimpleMysqlLinkType.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JoinParameters_MetaData[] = {
		{ "Category", "SimpleMySQL|QueryParameters" },
		{ "ModuleRelativePath", "Public/Core/SimpleMysqlLinkType.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Condition_MetaData[] = {
		{ "Category", "SimpleMySQL|QueryParameters" },
		{ "ModuleRelativePath", "Public/Core/SimpleMysqlLinkType.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GroupBy_MetaData[] = {
		{ "Category", "SimpleMySQL|QueryParameters" },
		{ "ModuleRelativePath", "Public/Core/SimpleMysqlLinkType.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OrderBy_MetaData[] = {
		{ "Category", "SimpleMySQL|QueryParameters" },
		{ "ModuleRelativePath", "Public/Core/SimpleMysqlLinkType.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Limit_MetaData[] = {
		{ "Category", "SimpleMySQL|QueryParameters" },
		{ "Comment", "//x = \xe7\xac\xac\xe5\x87\xa0\xe4\xb8\xaa,y = \xe5\x81\x8f\xe7\xa7\xbb\n" },
		{ "ModuleRelativePath", "Public/Core/SimpleMysqlLinkType.h" },
		{ "ToolTip", "x = \xe7\xac\xac\xe5\x87\xa0\xe4\xb8\xaa,y = \xe5\x81\x8f\xe7\xa7\xbb" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bWithRollup_MetaData[] = {
		{ "Category", "SimpleMySQL|QueryParameters" },
		{ "Comment", "//\xe6\x98\xaf\xe5\x90\xa6\xe8\xbf\x9b\xe8\xa1\x8c\xe6\xb1\x87\xe6\x80\xbb\n" },
		{ "ModuleRelativePath", "Public/Core/SimpleMysqlLinkType.h" },
		{ "ToolTip", "\xe6\x98\xaf\xe5\x90\xa6\xe8\xbf\x9b\xe8\xa1\x8c\xe6\xb1\x87\xe6\x80\xbb" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Having_MetaData[] = {
		{ "Category", "SimpleMySQL|QueryParameters" },
		{ "ModuleRelativePath", "Public/Core/SimpleMysqlLinkType.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_FuntionSettings;
	static const UECodeGen_Private::FStrPropertyParams NewProp_TableName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_InFields_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_InFields;
	static void NewProp_bDistinct_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDistinct;
	static const UECodeGen_Private::FStructPropertyParams NewProp_JoinParameters;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Condition_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Condition;
	static const UECodeGen_Private::FStrPropertyParams NewProp_GroupBy_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_GroupBy;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OrderBy_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_OrderBy;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Limit;
	static void NewProp_bWithRollup_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bWithRollup;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Having;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSimpleMysqlQueryParameters>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSimpleMysqlQueryParameters_Statics::NewProp_FuntionSettings = { "FuntionSettings", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSimpleMysqlQueryParameters, FuntionSettings), Z_Construct_UScriptStruct_FSimpleMysqlVariableSettings, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FuntionSettings_MetaData), NewProp_FuntionSettings_MetaData) }; // 3203568013
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FSimpleMysqlQueryParameters_Statics::NewProp_TableName = { "TableName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSimpleMysqlQueryParameters, TableName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TableName_MetaData), NewProp_TableName_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSimpleMysqlQueryParameters_Statics::NewProp_InFields_Inner = { "InFields", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FSimpleMysqlVariableSettings, METADATA_PARAMS(0, nullptr) }; // 3203568013
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FSimpleMysqlQueryParameters_Statics::NewProp_InFields = { "InFields", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSimpleMysqlQueryParameters, InFields), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InFields_MetaData), NewProp_InFields_MetaData) }; // 3203568013
void Z_Construct_UScriptStruct_FSimpleMysqlQueryParameters_Statics::NewProp_bDistinct_SetBit(void* Obj)
{
	((FSimpleMysqlQueryParameters*)Obj)->bDistinct = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FSimpleMysqlQueryParameters_Statics::NewProp_bDistinct = { "bDistinct", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FSimpleMysqlQueryParameters), &Z_Construct_UScriptStruct_FSimpleMysqlQueryParameters_Statics::NewProp_bDistinct_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bDistinct_MetaData), NewProp_bDistinct_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSimpleMysqlQueryParameters_Statics::NewProp_JoinParameters = { "JoinParameters", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSimpleMysqlQueryParameters, JoinParameters), Z_Construct_UScriptStruct_FSimpleMysqlJoinParameters, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JoinParameters_MetaData), NewProp_JoinParameters_MetaData) }; // 1234800105
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSimpleMysqlQueryParameters_Statics::NewProp_Condition_Inner = { "Condition", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FSimpleMysqlComparisonOperator, METADATA_PARAMS(0, nullptr) }; // 3788307969
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FSimpleMysqlQueryParameters_Statics::NewProp_Condition = { "Condition", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSimpleMysqlQueryParameters, Condition), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Condition_MetaData), NewProp_Condition_MetaData) }; // 3788307969
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FSimpleMysqlQueryParameters_Statics::NewProp_GroupBy_Inner = { "GroupBy", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FSimpleMysqlQueryParameters_Statics::NewProp_GroupBy = { "GroupBy", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSimpleMysqlQueryParameters, GroupBy), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GroupBy_MetaData), NewProp_GroupBy_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSimpleMysqlQueryParameters_Statics::NewProp_OrderBy_Inner = { "OrderBy", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FSimpleMysqlQueryOrderBy, METADATA_PARAMS(0, nullptr) }; // 3307790038
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FSimpleMysqlQueryParameters_Statics::NewProp_OrderBy = { "OrderBy", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSimpleMysqlQueryParameters, OrderBy), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OrderBy_MetaData), NewProp_OrderBy_MetaData) }; // 3307790038
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSimpleMysqlQueryParameters_Statics::NewProp_Limit = { "Limit", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSimpleMysqlQueryParameters, Limit), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Limit_MetaData), NewProp_Limit_MetaData) };
void Z_Construct_UScriptStruct_FSimpleMysqlQueryParameters_Statics::NewProp_bWithRollup_SetBit(void* Obj)
{
	((FSimpleMysqlQueryParameters*)Obj)->bWithRollup = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FSimpleMysqlQueryParameters_Statics::NewProp_bWithRollup = { "bWithRollup", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FSimpleMysqlQueryParameters), &Z_Construct_UScriptStruct_FSimpleMysqlQueryParameters_Statics::NewProp_bWithRollup_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bWithRollup_MetaData), NewProp_bWithRollup_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FSimpleMysqlQueryParameters_Statics::NewProp_Having = { "Having", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSimpleMysqlQueryParameters, Having), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Having_MetaData), NewProp_Having_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSimpleMysqlQueryParameters_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSimpleMysqlQueryParameters_Statics::NewProp_FuntionSettings,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSimpleMysqlQueryParameters_Statics::NewProp_TableName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSimpleMysqlQueryParameters_Statics::NewProp_InFields_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSimpleMysqlQueryParameters_Statics::NewProp_InFields,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSimpleMysqlQueryParameters_Statics::NewProp_bDistinct,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSimpleMysqlQueryParameters_Statics::NewProp_JoinParameters,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSimpleMysqlQueryParameters_Statics::NewProp_Condition_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSimpleMysqlQueryParameters_Statics::NewProp_Condition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSimpleMysqlQueryParameters_Statics::NewProp_GroupBy_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSimpleMysqlQueryParameters_Statics::NewProp_GroupBy,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSimpleMysqlQueryParameters_Statics::NewProp_OrderBy_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSimpleMysqlQueryParameters_Statics::NewProp_OrderBy,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSimpleMysqlQueryParameters_Statics::NewProp_Limit,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSimpleMysqlQueryParameters_Statics::NewProp_bWithRollup,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSimpleMysqlQueryParameters_Statics::NewProp_Having,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSimpleMysqlQueryParameters_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSimpleMysqlQueryParameters_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_SimpleMySQL,
	nullptr,
	&NewStructOps,
	"SimpleMysqlQueryParameters",
	Z_Construct_UScriptStruct_FSimpleMysqlQueryParameters_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSimpleMysqlQueryParameters_Statics::PropPointers),
	sizeof(FSimpleMysqlQueryParameters),
	alignof(FSimpleMysqlQueryParameters),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSimpleMysqlQueryParameters_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FSimpleMysqlQueryParameters_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FSimpleMysqlQueryParameters()
{
	if (!Z_Registration_Info_UScriptStruct_SimpleMysqlQueryParameters.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_SimpleMysqlQueryParameters.InnerSingleton, Z_Construct_UScriptStruct_FSimpleMysqlQueryParameters_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_SimpleMysqlQueryParameters.InnerSingleton;
}
// End ScriptStruct FSimpleMysqlQueryParameters

// Begin ScriptStruct FSimpleMysqlReplaceParameters
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_SimpleMysqlReplaceParameters;
class UScriptStruct* FSimpleMysqlReplaceParameters::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_SimpleMysqlReplaceParameters.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_SimpleMysqlReplaceParameters.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSimpleMysqlReplaceParameters, (UObject*)Z_Construct_UPackage__Script_SimpleMySQL(), TEXT("SimpleMysqlReplaceParameters"));
	}
	return Z_Registration_Info_UScriptStruct_SimpleMysqlReplaceParameters.OuterSingleton;
}
template<> SIMPLEMYSQL_API UScriptStruct* StaticStruct<FSimpleMysqlReplaceParameters>()
{
	return FSimpleMysqlReplaceParameters::StaticStruct();
}
struct Z_Construct_UScriptStruct_FSimpleMysqlReplaceParameters_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Core/SimpleMysqlLinkType.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FieldName_MetaData[] = {
		{ "Category", "SimpleMySQL|QueryParameters" },
		{ "ModuleRelativePath", "Public/Core/SimpleMysqlLinkType.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OldDataValue_MetaData[] = {
		{ "Category", "SimpleMySQL|QueryParameters" },
		{ "ModuleRelativePath", "Public/Core/SimpleMysqlLinkType.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NewDataValue_MetaData[] = {
		{ "Category", "SimpleMySQL|QueryParameters" },
		{ "ModuleRelativePath", "Public/Core/SimpleMysqlLinkType.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_FieldName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_OldDataValue;
	static const UECodeGen_Private::FStrPropertyParams NewProp_NewDataValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSimpleMysqlReplaceParameters>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FSimpleMysqlReplaceParameters_Statics::NewProp_FieldName = { "FieldName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSimpleMysqlReplaceParameters, FieldName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FieldName_MetaData), NewProp_FieldName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FSimpleMysqlReplaceParameters_Statics::NewProp_OldDataValue = { "OldDataValue", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSimpleMysqlReplaceParameters, OldDataValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OldDataValue_MetaData), NewProp_OldDataValue_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FSimpleMysqlReplaceParameters_Statics::NewProp_NewDataValue = { "NewDataValue", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSimpleMysqlReplaceParameters, NewDataValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NewDataValue_MetaData), NewProp_NewDataValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSimpleMysqlReplaceParameters_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSimpleMysqlReplaceParameters_Statics::NewProp_FieldName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSimpleMysqlReplaceParameters_Statics::NewProp_OldDataValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSimpleMysqlReplaceParameters_Statics::NewProp_NewDataValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSimpleMysqlReplaceParameters_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSimpleMysqlReplaceParameters_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_SimpleMySQL,
	nullptr,
	&NewStructOps,
	"SimpleMysqlReplaceParameters",
	Z_Construct_UScriptStruct_FSimpleMysqlReplaceParameters_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSimpleMysqlReplaceParameters_Statics::PropPointers),
	sizeof(FSimpleMysqlReplaceParameters),
	alignof(FSimpleMysqlReplaceParameters),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSimpleMysqlReplaceParameters_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FSimpleMysqlReplaceParameters_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FSimpleMysqlReplaceParameters()
{
	if (!Z_Registration_Info_UScriptStruct_SimpleMysqlReplaceParameters.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_SimpleMysqlReplaceParameters.InnerSingleton, Z_Construct_UScriptStruct_FSimpleMysqlReplaceParameters_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_SimpleMysqlReplaceParameters.InnerSingleton;
}
// End ScriptStruct FSimpleMysqlReplaceParameters

// Begin ScriptStruct FSimpleMysqlModifyField
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_SimpleMysqlModifyField;
class UScriptStruct* FSimpleMysqlModifyField::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_SimpleMysqlModifyField.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_SimpleMysqlModifyField.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSimpleMysqlModifyField, (UObject*)Z_Construct_UPackage__Script_SimpleMySQL(), TEXT("SimpleMysqlModifyField"));
	}
	return Z_Registration_Info_UScriptStruct_SimpleMysqlModifyField.OuterSingleton;
}
template<> SIMPLEMYSQL_API UScriptStruct* StaticStruct<FSimpleMysqlModifyField>()
{
	return FSimpleMysqlModifyField::StaticStruct();
}
struct Z_Construct_UScriptStruct_FSimpleMysqlModifyField_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Core/SimpleMysqlLinkType.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FieldOldName_MetaData[] = {
		{ "Category", "SimpleMySQL|QueryParameters" },
		{ "ModuleRelativePath", "Public/Core/SimpleMysqlLinkType.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FieldNewName_MetaData[] = {
		{ "Category", "SimpleMySQL|QueryParameters" },
		{ "ModuleRelativePath", "Public/Core/SimpleMysqlLinkType.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NewFieldType_MetaData[] = {
		{ "Category", "SimpleMySQL|QueryParameters" },
		{ "ModuleRelativePath", "Public/Core/SimpleMysqlLinkType.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_FieldOldName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FieldNewName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_NewFieldType;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSimpleMysqlModifyField>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FSimpleMysqlModifyField_Statics::NewProp_FieldOldName = { "FieldOldName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSimpleMysqlModifyField, FieldOldName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FieldOldName_MetaData), NewProp_FieldOldName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FSimpleMysqlModifyField_Statics::NewProp_FieldNewName = { "FieldNewName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSimpleMysqlModifyField, FieldNewName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FieldNewName_MetaData), NewProp_FieldNewName_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSimpleMysqlModifyField_Statics::NewProp_NewFieldType = { "NewFieldType", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSimpleMysqlModifyField, NewFieldType), Z_Construct_UScriptStruct_FMysqlFieldType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NewFieldType_MetaData), NewProp_NewFieldType_MetaData) }; // 4288358353
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSimpleMysqlModifyField_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSimpleMysqlModifyField_Statics::NewProp_FieldOldName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSimpleMysqlModifyField_Statics::NewProp_FieldNewName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSimpleMysqlModifyField_Statics::NewProp_NewFieldType,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSimpleMysqlModifyField_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSimpleMysqlModifyField_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_SimpleMySQL,
	nullptr,
	&NewStructOps,
	"SimpleMysqlModifyField",
	Z_Construct_UScriptStruct_FSimpleMysqlModifyField_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSimpleMysqlModifyField_Statics::PropPointers),
	sizeof(FSimpleMysqlModifyField),
	alignof(FSimpleMysqlModifyField),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSimpleMysqlModifyField_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FSimpleMysqlModifyField_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FSimpleMysqlModifyField()
{
	if (!Z_Registration_Info_UScriptStruct_SimpleMysqlModifyField.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_SimpleMysqlModifyField.InnerSingleton, Z_Construct_UScriptStruct_FSimpleMysqlModifyField_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_SimpleMysqlModifyField.InnerSingleton;
}
// End ScriptStruct FSimpleMysqlModifyField

// Begin ScriptStruct FSimpleMysqlQueryStmt
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_SimpleMysqlQueryStmt;
class UScriptStruct* FSimpleMysqlQueryStmt::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_SimpleMysqlQueryStmt.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_SimpleMysqlQueryStmt.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSimpleMysqlQueryStmt, (UObject*)Z_Construct_UPackage__Script_SimpleMySQL(), TEXT("SimpleMysqlQueryStmt"));
	}
	return Z_Registration_Info_UScriptStruct_SimpleMysqlQueryStmt.OuterSingleton;
}
template<> SIMPLEMYSQL_API UScriptStruct* StaticStruct<FSimpleMysqlQueryStmt>()
{
	return FSimpleMysqlQueryStmt::StaticStruct();
}
struct Z_Construct_UScriptStruct_FSimpleMysqlQueryStmt_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "//(?,?,?)\n" },
		{ "ModuleRelativePath", "Public/Core/SimpleMysqlLinkType.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[] = {
		{ "Category", "SimpleMySQL|QueryStmt" },
		{ "ModuleRelativePath", "Public/Core/SimpleMysqlLinkType.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VariableType_MetaData[] = {
		{ "Category", "SimpleMySQL|QueryStmt" },
		{ "ModuleRelativePath", "Public/Core/SimpleMysqlLinkType.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_Value;
	static const UECodeGen_Private::FBytePropertyParams NewProp_VariableType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_VariableType;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSimpleMysqlQueryStmt>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FSimpleMysqlQueryStmt_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSimpleMysqlQueryStmt, Value), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Value_MetaData), NewProp_Value_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FSimpleMysqlQueryStmt_Statics::NewProp_VariableType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FSimpleMysqlQueryStmt_Statics::NewProp_VariableType = { "VariableType", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSimpleMysqlQueryStmt, VariableType), Z_Construct_UEnum_SimpleMySQL_EMysqlVariableType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VariableType_MetaData), NewProp_VariableType_MetaData) }; // 1623531787
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSimpleMysqlQueryStmt_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSimpleMysqlQueryStmt_Statics::NewProp_Value,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSimpleMysqlQueryStmt_Statics::NewProp_VariableType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSimpleMysqlQueryStmt_Statics::NewProp_VariableType,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSimpleMysqlQueryStmt_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSimpleMysqlQueryStmt_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_SimpleMySQL,
	nullptr,
	&NewStructOps,
	"SimpleMysqlQueryStmt",
	Z_Construct_UScriptStruct_FSimpleMysqlQueryStmt_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSimpleMysqlQueryStmt_Statics::PropPointers),
	sizeof(FSimpleMysqlQueryStmt),
	alignof(FSimpleMysqlQueryStmt),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSimpleMysqlQueryStmt_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FSimpleMysqlQueryStmt_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FSimpleMysqlQueryStmt()
{
	if (!Z_Registration_Info_UScriptStruct_SimpleMysqlQueryStmt.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_SimpleMysqlQueryStmt.InnerSingleton, Z_Construct_UScriptStruct_FSimpleMysqlQueryStmt_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_SimpleMysqlQueryStmt.InnerSingleton;
}
// End ScriptStruct FSimpleMysqlQueryStmt

// Begin Registration
struct Z_CompiledInDeferFile_FID_Engine_Plugins_RENZHAI_PLUGIN_SimpleMySQL_Source_SimpleMySQL_Public_Core_SimpleMysqlLinkType_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EMysqlVariableType_StaticEnum, TEXT("EMysqlVariableType"), &Z_Registration_Info_UEnum_EMysqlVariableType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1623531787U) },
		{ EMysqlSaveEngine_StaticEnum, TEXT("EMysqlSaveEngine"), &Z_Registration_Info_UEnum_EMysqlSaveEngine, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2142121027U) },
		{ ESimpleClientFlags_StaticEnum, TEXT("ESimpleClientFlags"), &Z_Registration_Info_UEnum_ESimpleClientFlags, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1403481707U) },
		{ EMysqlCharset_StaticEnum, TEXT("EMysqlCharset"), &Z_Registration_Info_UEnum_EMysqlCharset, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 200248681U) },
		{ EMysqlDateType_StaticEnum, TEXT("EMysqlDateType"), &Z_Registration_Info_UEnum_EMysqlDateType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1485813237U) },
		{ EMysqlJoinType_StaticEnum, TEXT("EMysqlJoinType"), &Z_Registration_Info_UEnum_EMysqlJoinType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 167747009U) },
		{ EMysqlQuerySaveType_StaticEnum, TEXT("EMysqlQuerySaveType"), &Z_Registration_Info_UEnum_EMysqlQuerySaveType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3690130953U) },
		{ EMysqlComparisonOperator_StaticEnum, TEXT("EMysqlComparisonOperator"), &Z_Registration_Info_UEnum_EMysqlComparisonOperator, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 607162403U) },
		{ EMysqlLogicalOperators_StaticEnum, TEXT("EMysqlLogicalOperators"), &Z_Registration_Info_UEnum_EMysqlLogicalOperators, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1138254964U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FMysqlFieldType::StaticStruct, Z_Construct_UScriptStruct_FMysqlFieldType_Statics::NewStructOps, TEXT("MysqlFieldType"), &Z_Registration_Info_UScriptStruct_MysqlFieldType, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FMysqlFieldType), 4288358353U) },
		{ FMysqlCreateTableParam::StaticStruct, Z_Construct_UScriptStruct_FMysqlCreateTableParam_Statics::NewStructOps, TEXT("MysqlCreateTableParam"), &Z_Registration_Info_UScriptStruct_MysqlCreateTableParam, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FMysqlCreateTableParam), 966713857U) },
		{ FSimpleMysqlResult::StaticStruct, Z_Construct_UScriptStruct_FSimpleMysqlResult_Statics::NewStructOps, TEXT("SimpleMysqlResult"), &Z_Registration_Info_UScriptStruct_SimpleMysqlResult, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSimpleMysqlResult), 296170381U) },
		{ FSimpleMysqlDebugResult::StaticStruct, Z_Construct_UScriptStruct_FSimpleMysqlDebugResult_Statics::NewStructOps, TEXT("SimpleMysqlDebugResult"), &Z_Registration_Info_UScriptStruct_SimpleMysqlDebugResult, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSimpleMysqlDebugResult), 3187445125U) },
		{ FSimpleMysqlQueryOrderBy::StaticStruct, Z_Construct_UScriptStruct_FSimpleMysqlQueryOrderBy_Statics::NewStructOps, TEXT("SimpleMysqlQueryOrderBy"), &Z_Registration_Info_UScriptStruct_SimpleMysqlQueryOrderBy, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSimpleMysqlQueryOrderBy), 3307790038U) },
		{ FSimpleMysqlJoinParameters::StaticStruct, Z_Construct_UScriptStruct_FSimpleMysqlJoinParameters_Statics::NewStructOps, TEXT("SimpleMysqlJoinParameters"), &Z_Registration_Info_UScriptStruct_SimpleMysqlJoinParameters, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSimpleMysqlJoinParameters), 1234800105U) },
		{ FSimpleMysqlAssignment::StaticStruct, Z_Construct_UScriptStruct_FSimpleMysqlAssignment_Statics::NewStructOps, TEXT("SimpleMysqlAssignment"), &Z_Registration_Info_UScriptStruct_SimpleMysqlAssignment, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSimpleMysqlAssignment), 3943474943U) },
		{ FSimpleMysqlComparisonOperator::StaticStruct, Z_Construct_UScriptStruct_FSimpleMysqlComparisonOperator_Statics::NewStructOps, TEXT("SimpleMysqlComparisonOperator"), &Z_Registration_Info_UScriptStruct_SimpleMysqlComparisonOperator, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSimpleMysqlComparisonOperator), 3788307969U) },
		{ FSimpleMysqlVariableSettings::StaticStruct, Z_Construct_UScriptStruct_FSimpleMysqlVariableSettings_Statics::NewStructOps, TEXT("SimpleMysqlVariableSettings"), &Z_Registration_Info_UScriptStruct_SimpleMysqlVariableSettings, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSimpleMysqlVariableSettings), 3203568013U) },
		{ FSimpleMysqlQueryParameters::StaticStruct, Z_Construct_UScriptStruct_FSimpleMysqlQueryParameters_Statics::NewStructOps, TEXT("SimpleMysqlQueryParameters"), &Z_Registration_Info_UScriptStruct_SimpleMysqlQueryParameters, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSimpleMysqlQueryParameters), 876807722U) },
		{ FSimpleMysqlReplaceParameters::StaticStruct, Z_Construct_UScriptStruct_FSimpleMysqlReplaceParameters_Statics::NewStructOps, TEXT("SimpleMysqlReplaceParameters"), &Z_Registration_Info_UScriptStruct_SimpleMysqlReplaceParameters, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSimpleMysqlReplaceParameters), 1357534489U) },
		{ FSimpleMysqlModifyField::StaticStruct, Z_Construct_UScriptStruct_FSimpleMysqlModifyField_Statics::NewStructOps, TEXT("SimpleMysqlModifyField"), &Z_Registration_Info_UScriptStruct_SimpleMysqlModifyField, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSimpleMysqlModifyField), 2958132979U) },
		{ FSimpleMysqlQueryStmt::StaticStruct, Z_Construct_UScriptStruct_FSimpleMysqlQueryStmt_Statics::NewStructOps, TEXT("SimpleMysqlQueryStmt"), &Z_Registration_Info_UScriptStruct_SimpleMysqlQueryStmt, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSimpleMysqlQueryStmt), 256664098U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Engine_Plugins_RENZHAI_PLUGIN_SimpleMySQL_Source_SimpleMySQL_Public_Core_SimpleMysqlLinkType_h_2369454160(TEXT("/Script/SimpleMySQL"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Engine_Plugins_RENZHAI_PLUGIN_SimpleMySQL_Source_SimpleMySQL_Public_Core_SimpleMysqlLinkType_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Engine_Plugins_RENZHAI_PLUGIN_SimpleMySQL_Source_SimpleMySQL_Public_Core_SimpleMysqlLinkType_h_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_Engine_Plugins_RENZHAI_PLUGIN_SimpleMySQL_Source_SimpleMySQL_Public_Core_SimpleMysqlLinkType_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Engine_Plugins_RENZHAI_PLUGIN_SimpleMySQL_Source_SimpleMySQL_Public_Core_SimpleMysqlLinkType_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
