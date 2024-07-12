// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/SimpleMysqlLinkType.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SIMPLEMYSQL_SimpleMysqlLinkType_generated_h
#error "SimpleMysqlLinkType.generated.h already included, missing '#pragma once' in SimpleMysqlLinkType.h"
#endif
#define SIMPLEMYSQL_SimpleMysqlLinkType_generated_h

#define FID_Engine_Plugins_RENZHAI_PLUGIN_SimpleMySQL_Source_SimpleMySQL_Public_Core_SimpleMysqlLinkType_h_214_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FMysqlFieldType_Statics; \
	static class UScriptStruct* StaticStruct();


template<> SIMPLEMYSQL_API UScriptStruct* StaticStruct<struct FMysqlFieldType>();

#define FID_Engine_Plugins_RENZHAI_PLUGIN_SimpleMySQL_Source_SimpleMySQL_Public_Core_SimpleMysqlLinkType_h_248_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FMysqlCreateTableParam_Statics; \
	static class UScriptStruct* StaticStruct();


template<> SIMPLEMYSQL_API UScriptStruct* StaticStruct<struct FMysqlCreateTableParam>();

#define FID_Engine_Plugins_RENZHAI_PLUGIN_SimpleMySQL_Source_SimpleMySQL_Public_Core_SimpleMysqlLinkType_h_262_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FSimpleMysqlResult_Statics; \
	static class UScriptStruct* StaticStruct();


template<> SIMPLEMYSQL_API UScriptStruct* StaticStruct<struct FSimpleMysqlResult>();

#define FID_Engine_Plugins_RENZHAI_PLUGIN_SimpleMySQL_Source_SimpleMySQL_Public_Core_SimpleMysqlLinkType_h_271_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FSimpleMysqlDebugResult_Statics; \
	static class UScriptStruct* StaticStruct();


template<> SIMPLEMYSQL_API UScriptStruct* StaticStruct<struct FSimpleMysqlDebugResult>();

#define FID_Engine_Plugins_RENZHAI_PLUGIN_SimpleMySQL_Source_SimpleMySQL_Public_Core_SimpleMysqlLinkType_h_285_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FSimpleMysqlQueryOrderBy_Statics; \
	static class UScriptStruct* StaticStruct();


template<> SIMPLEMYSQL_API UScriptStruct* StaticStruct<struct FSimpleMysqlQueryOrderBy>();

#define FID_Engine_Plugins_RENZHAI_PLUGIN_SimpleMySQL_Source_SimpleMySQL_Public_Core_SimpleMysqlLinkType_h_303_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FSimpleMysqlJoinParameters_Statics; \
	static class UScriptStruct* StaticStruct();


template<> SIMPLEMYSQL_API UScriptStruct* StaticStruct<struct FSimpleMysqlJoinParameters>();

#define FID_Engine_Plugins_RENZHAI_PLUGIN_SimpleMySQL_Source_SimpleMySQL_Public_Core_SimpleMysqlLinkType_h_323_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FSimpleMysqlAssignment_Statics; \
	static class UScriptStruct* StaticStruct();


template<> SIMPLEMYSQL_API UScriptStruct* StaticStruct<struct FSimpleMysqlAssignment>();

#define FID_Engine_Plugins_RENZHAI_PLUGIN_SimpleMySQL_Source_SimpleMySQL_Public_Core_SimpleMysqlLinkType_h_342_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FSimpleMysqlComparisonOperator_Statics; \
	static class UScriptStruct* StaticStruct();


template<> SIMPLEMYSQL_API UScriptStruct* StaticStruct<struct FSimpleMysqlComparisonOperator>();

#define FID_Engine_Plugins_RENZHAI_PLUGIN_SimpleMySQL_Source_SimpleMySQL_Public_Core_SimpleMysqlLinkType_h_358_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FSimpleMysqlVariableSettings_Statics; \
	static class UScriptStruct* StaticStruct();


template<> SIMPLEMYSQL_API UScriptStruct* StaticStruct<struct FSimpleMysqlVariableSettings>();

#define FID_Engine_Plugins_RENZHAI_PLUGIN_SimpleMySQL_Source_SimpleMySQL_Public_Core_SimpleMysqlLinkType_h_374_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FSimpleMysqlQueryParameters_Statics; \
	static class UScriptStruct* StaticStruct();


template<> SIMPLEMYSQL_API UScriptStruct* StaticStruct<struct FSimpleMysqlQueryParameters>();

#define FID_Engine_Plugins_RENZHAI_PLUGIN_SimpleMySQL_Source_SimpleMySQL_Public_Core_SimpleMysqlLinkType_h_423_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FSimpleMysqlReplaceParameters_Statics; \
	static class UScriptStruct* StaticStruct();


template<> SIMPLEMYSQL_API UScriptStruct* StaticStruct<struct FSimpleMysqlReplaceParameters>();

#define FID_Engine_Plugins_RENZHAI_PLUGIN_SimpleMySQL_Source_SimpleMySQL_Public_Core_SimpleMysqlLinkType_h_442_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FSimpleMysqlModifyField_Statics; \
	static class UScriptStruct* StaticStruct();


template<> SIMPLEMYSQL_API UScriptStruct* StaticStruct<struct FSimpleMysqlModifyField>();

#define FID_Engine_Plugins_RENZHAI_PLUGIN_SimpleMySQL_Source_SimpleMySQL_Public_Core_SimpleMysqlLinkType_h_460_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FSimpleMysqlQueryStmt_Statics; \
	static class UScriptStruct* StaticStruct();


template<> SIMPLEMYSQL_API UScriptStruct* StaticStruct<struct FSimpleMysqlQueryStmt>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Engine_Plugins_RENZHAI_PLUGIN_SimpleMySQL_Source_SimpleMySQL_Public_Core_SimpleMysqlLinkType_h


#define FOREACH_ENUM_EMYSQLVARIABLETYPE(op) \
	op(EMysqlVariableType::MYSQL_DECIMAL) \
	op(EMysqlVariableType::MYSQL_TINY) \
	op(EMysqlVariableType::MYSQL_SHORT) \
	op(EMysqlVariableType::MYSQL_LONG) \
	op(EMysqlVariableType::MYSQL_FLOAT) \
	op(EMysqlVariableType::MYSQL_DOUBLE) \
	op(EMysqlVariableType::MYSQL_NULL) \
	op(EMysqlVariableType::MYSQL_TIMESTAMP) \
	op(EMysqlVariableType::MYSQL_LONGLONG) \
	op(EMysqlVariableType::MYSQL_INT24) \
	op(EMysqlVariableType::MYSQL_DATE) \
	op(EMysqlVariableType::MYSQL_TIME) \
	op(EMysqlVariableType::MYSQL_DATETIME) \
	op(EMysqlVariableType::MYSQL_YEAR) \
	op(EMysqlVariableType::MYSQL_NEWDATE) \
	op(EMysqlVariableType::MYSQL_VARCHAR) \
	op(EMysqlVariableType::MYSQL_BIT) \
	op(EMysqlVariableType::MYSQL_TIMESTAMP2) \
	op(EMysqlVariableType::MYSQL_DATETIME2) \
	op(EMysqlVariableType::MYSQL_TIME2) \
	op(EMysqlVariableType::MYSQL_JSON) \
	op(EMysqlVariableType::MYSQL_NEWDECIMAL) \
	op(EMysqlVariableType::MYSQL_ENUM) \
	op(EMysqlVariableType::MYSQL_SET) \
	op(EMysqlVariableType::MYSQL_TINY_BLOB) \
	op(EMysqlVariableType::MYSQL_MEDIUM_BLOB) \
	op(EMysqlVariableType::MYSQL_LONG_BLOB) \
	op(EMysqlVariableType::MYSQL_BLOB) \
	op(EMysqlVariableType::MYSQL_VAR_STRING) \
	op(EMysqlVariableType::MYSQL_STRING) \
	op(EMysqlVariableType::MYSQL_GEOMETRY) 

enum class EMysqlVariableType : uint8;
template<> struct TIsUEnumClass<EMysqlVariableType> { enum { Value = true }; };
template<> SIMPLEMYSQL_API UEnum* StaticEnum<EMysqlVariableType>();

#define FOREACH_ENUM_EMYSQLSAVEENGINE(op) \
	op(EMysqlSaveEngine::InnoDB) \
	op(EMysqlSaveEngine::MyISAM) \
	op(EMysqlSaveEngine::MEMORY) \
	op(EMysqlSaveEngine::ARCHIVE) \
	op(EMysqlSaveEngine::CSV) \
	op(EMysqlSaveEngine::PERFORMANCE_SCHEMA) \
	op(EMysqlSaveEngine::MRG_MYISAM) \
	op(EMysqlSaveEngine::BLACKHOLE) \
	op(EMysqlSaveEngine::FEDERATED) 

enum class EMysqlSaveEngine : uint8;
template<> struct TIsUEnumClass<EMysqlSaveEngine> { enum { Value = true }; };
template<> SIMPLEMYSQL_API UEnum* StaticEnum<EMysqlSaveEngine>();

#define FOREACH_ENUM_ESIMPLECLIENTFLAGS(op) \
	op(ESimpleClientFlags::Client_None) \
	op(ESimpleClientFlags::Client_Long_Password) \
	op(ESimpleClientFlags::Client_Found_Rows) \
	op(ESimpleClientFlags::Client_Long_Flag) \
	op(ESimpleClientFlags::Client_Connect_With_db) \
	op(ESimpleClientFlags::Client_No_Schema) \
	op(ESimpleClientFlags::Client_Compress) \
	op(ESimpleClientFlags::Client_ODBC) \
	op(ESimpleClientFlags::Client_Local_Files) \
	op(ESimpleClientFlags::Client_Ignore_Space) \
	op(ESimpleClientFlags::Client_Protocol_41) \
	op(ESimpleClientFlags::Client_Interactive) \
	op(ESimpleClientFlags::Client_SSL) \
	op(ESimpleClientFlags::Client_Ignore_Sigpipe) \
	op(ESimpleClientFlags::Client_Transactions) \
	op(ESimpleClientFlags::Client_Reserved) \
	op(ESimpleClientFlags::Client_Reserved2) \
	op(ESimpleClientFlags::Client_Multi_Statements) \
	op(ESimpleClientFlags::Client_Multi_Results) \
	op(ESimpleClientFlags::Client_PS_Multi_Results) 

enum class ESimpleClientFlags : uint8;
template<> struct TIsUEnumClass<ESimpleClientFlags> { enum { Value = true }; };
template<> SIMPLEMYSQL_API UEnum* StaticEnum<ESimpleClientFlags>();

#define FOREACH_ENUM_EMYSQLCHARSET(op) \
	op(EMysqlCharset::None) \
	op(EMysqlCharset::armscii8) \
	op(EMysqlCharset::ascii) \
	op(EMysqlCharset::big5) \
	op(EMysqlCharset::binary) \
	op(EMysqlCharset::cp1250) \
	op(EMysqlCharset::cp1251) \
	op(EMysqlCharset::cp1256) \
	op(EMysqlCharset::cp1257) \
	op(EMysqlCharset::cp850) \
	op(EMysqlCharset::cp852) \
	op(EMysqlCharset::cp866) \
	op(EMysqlCharset::cp932) \
	op(EMysqlCharset::dec8) \
	op(EMysqlCharset::eucjpms) \
	op(EMysqlCharset::euckr) \
	op(EMysqlCharset::gb2312) \
	op(EMysqlCharset::gbk) \
	op(EMysqlCharset::geostd8) \
	op(EMysqlCharset::greek) \
	op(EMysqlCharset::bebrew) \
	op(EMysqlCharset::hp8) \
	op(EMysqlCharset::keybcs2) \
	op(EMysqlCharset::koi8r) \
	op(EMysqlCharset::koi8u) \
	op(EMysqlCharset::latin1) \
	op(EMysqlCharset::latin2) \
	op(EMysqlCharset::latin5) \
	op(EMysqlCharset::latin7) \
	op(EMysqlCharset::macce) \
	op(EMysqlCharset::macroman) \
	op(EMysqlCharset::sjis) \
	op(EMysqlCharset::swe7) \
	op(EMysqlCharset::tis620) \
	op(EMysqlCharset::ucs2) \
	op(EMysqlCharset::ujis) \
	op(EMysqlCharset::utf16) \
	op(EMysqlCharset::utf32) \
	op(EMysqlCharset::utf8) \
	op(EMysqlCharset::utf8mb4) 

enum class EMysqlCharset : uint8;
template<> struct TIsUEnumClass<EMysqlCharset> { enum { Value = true }; };
template<> SIMPLEMYSQL_API UEnum* StaticEnum<EMysqlCharset>();

#define FOREACH_ENUM_EMYSQLDATETYPE(op) \
	op(EMysqlDateType::MICROSECOND) \
	op(EMysqlDateType::SECOND) \
	op(EMysqlDateType::MINUTE) \
	op(EMysqlDateType::HOUR) \
	op(EMysqlDateType::DAY) \
	op(EMysqlDateType::WEEK) \
	op(EMysqlDateType::MONTH) \
	op(EMysqlDateType::QUARTER) \
	op(EMysqlDateType::YEAR) \
	op(EMysqlDateType::SECOND_MICROSECOND) \
	op(EMysqlDateType::MINUTE_MICROSECOND) \
	op(EMysqlDateType::MINUTE_SECOND) \
	op(EMysqlDateType::HOUR_MICROSECOND) \
	op(EMysqlDateType::HOUR_SECOND) \
	op(EMysqlDateType::HOUR_MINUTE) \
	op(EMysqlDateType::DAY_MICROSECOND) \
	op(EMysqlDateType::DAY_SECOND) \
	op(EMysqlDateType::DAY_MINUTE) \
	op(EMysqlDateType::DAY_HOUR) \
	op(EMysqlDateType::YEAR_MONTH) 

enum class EMysqlDateType : uint8;
template<> struct TIsUEnumClass<EMysqlDateType> { enum { Value = true }; };
template<> SIMPLEMYSQL_API UEnum* StaticEnum<EMysqlDateType>();

#define FOREACH_ENUM_EMYSQLJOINTYPE(op) \
	op(EMysqlJoinType::NONE) \
	op(EMysqlJoinType::INNER) \
	op(EMysqlJoinType::LEFT) \
	op(EMysqlJoinType::RIGHT) 

enum class EMysqlJoinType : uint8;
template<> struct TIsUEnumClass<EMysqlJoinType> { enum { Value = true }; };
template<> SIMPLEMYSQL_API UEnum* StaticEnum<EMysqlJoinType>();

#define FOREACH_ENUM_EMYSQLQUERYSAVETYPE(op) \
	op(EMysqlQuerySaveType::STORE_RESULT) \
	op(EMysqlQuerySaveType::USE_RESULT) 

enum class EMysqlQuerySaveType : uint8;
template<> struct TIsUEnumClass<EMysqlQuerySaveType> { enum { Value = true }; };
template<> SIMPLEMYSQL_API UEnum* StaticEnum<EMysqlQuerySaveType>();

#define FOREACH_ENUM_EMYSQLCOMPARISONOPERATOR(op) \
	op(EMysqlComparisonOperator::EQUAL) \
	op(EMysqlComparisonOperator::GREATER_THAN) \
	op(EMysqlComparisonOperator::LESS_THAN) \
	op(EMysqlComparisonOperator::GREATER_THAN_OR_EQUAL) \
	op(EMysqlComparisonOperator::LESS_THAN_OR_EQUAL) \
	op(EMysqlComparisonOperator::NOT_EQUAL) \
	op(EMysqlComparisonOperator::BETWEEN) \
	op(EMysqlComparisonOperator::NOT_BETWEEN) \
	op(EMysqlComparisonOperator::SQL_IN) \
	op(EMysqlComparisonOperator::NOT_IN) \
	op(EMysqlComparisonOperator::COMPARE_NULL_VALUES) \
	op(EMysqlComparisonOperator::LIKE) \
	op(EMysqlComparisonOperator::REGEXP_OR_RLIKE) \
	op(EMysqlComparisonOperator::IS_NULL) \
	op(EMysqlComparisonOperator::IS_NOT_NULL) 

enum class EMysqlComparisonOperator : uint8;
template<> struct TIsUEnumClass<EMysqlComparisonOperator> { enum { Value = true }; };
template<> SIMPLEMYSQL_API UEnum* StaticEnum<EMysqlComparisonOperator>();

#define FOREACH_ENUM_EMYSQLLOGICALOPERATORS(op) \
	op(EMysqlLogicalOperators::NONE) \
	op(EMysqlLogicalOperators::NOT) \
	op(EMysqlLogicalOperators::AND) \
	op(EMysqlLogicalOperators::OR) \
	op(EMysqlLogicalOperators::XOR) 

enum class EMysqlLogicalOperators : uint8;
template<> struct TIsUEnumClass<EMysqlLogicalOperators> { enum { Value = true }; };
template<> SIMPLEMYSQL_API UEnum* StaticEnum<EMysqlLogicalOperators>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
