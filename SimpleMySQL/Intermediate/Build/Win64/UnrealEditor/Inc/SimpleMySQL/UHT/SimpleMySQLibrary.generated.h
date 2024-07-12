// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "SimpleMySQLibrary.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
 
 struct FMysqlFieldType;
class UObject;
class USimpleMysqlObject;
enum class EMysqlCharset : uint8;
enum class EMysqlDateType : uint8;
enum class EMysqlQuerySaveType : uint8;
enum class EMysqlVariableType : uint8;
enum class ESimpleClientFlags : uint8;
struct FMysqlCreateTableParam;
struct FSimpleMysqlAssignment;
struct FSimpleMysqlComparisonOperator;
struct FSimpleMysqlDebugResult;
struct FSimpleMysqlJoinParameters;
struct FSimpleMysqlModifyField;
struct FSimpleMysqlQueryOrderBy;
struct FSimpleMysqlQueryParameters;
struct FSimpleMysqlQueryStmt;
struct FSimpleMysqlReplaceParameters;
struct FSimpleMysqlResult;
#ifdef SIMPLEMYSQL_SimpleMySQLibrary_generated_h
#error "SimpleMySQLibrary.generated.h already included, missing '#pragma once' in SimpleMySQLibrary.h"
#endif
#define SIMPLEMYSQL_SimpleMySQLibrary_generated_h

#define FID_Engine_Plugins_RENZHAI_PLUGIN_SimpleMySQL_Source_SimpleMySQL_Public_SimpleMySQLibrary_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetModifyFieldNULL); \
	DECLARE_FUNCTION(execGetJoinParametersNULL); \
	DECLARE_FUNCTION(execGetFieldNULL); \
	DECLARE_FUNCTION(execGetNULLQueryParameters); \
	DECLARE_FUNCTION(execGetMapStringNULL); \
	DECLARE_FUNCTION(execGetReplaceParametersNULLArray); \
	DECLARE_FUNCTION(execGetComparisonOperatorNULLArray); \
	DECLARE_FUNCTION(execGetAssignmentNULLArray); \
	DECLARE_FUNCTION(execGetJoinParamNULLArray); \
	DECLARE_FUNCTION(execGetOrderByNULLArray); \
	DECLARE_FUNCTION(execGetStringNULLArray); \
	DECLARE_FUNCTION(execGetSystem_user); \
	DECLARE_FUNCTION(execGetSession_user); \
	DECLARE_FUNCTION(execGetLast_Insert_ID); \
	DECLARE_FUNCTION(execGetCurrent_user); \
	DECLARE_FUNCTION(execGetConnection_ID); \
	DECLARE_FUNCTION(execCharset); \
	DECLARE_FUNCTION(execNULLIf); \
	DECLARE_FUNCTION(execIsNULL); \
	DECLARE_FUNCTION(execBinocularOperation); \
	DECLARE_FUNCTION(execConvert); \
	DECLARE_FUNCTION(execConv); \
	DECLARE_FUNCTION(execCast); \
	DECLARE_FUNCTION(execBinary); \
	DECLARE_FUNCTION(execBin); \
	DECLARE_FUNCTION(execAddTime); \
	DECLARE_FUNCTION(execCurrentTimeStamp); \
	DECLARE_FUNCTION(execCurrentTime); \
	DECLARE_FUNCTION(execCurTime); \
	DECLARE_FUNCTION(execDate); \
	DECLARE_FUNCTION(execDateDiff); \
	DECLARE_FUNCTION(execAddDate); \
	DECLARE_FUNCTION(execDateFormat); \
	DECLARE_FUNCTION(execDateSub); \
	DECLARE_FUNCTION(execDay); \
	DECLARE_FUNCTION(execDayName); \
	DECLARE_FUNCTION(execDayOfMonth); \
	DECLARE_FUNCTION(execDayOfWeek); \
	DECLARE_FUNCTION(execDayOfYear); \
	DECLARE_FUNCTION(execExtract); \
	DECLARE_FUNCTION(execFromDays); \
	DECLARE_FUNCTION(execHour); \
	DECLARE_FUNCTION(execLastDay); \
	DECLARE_FUNCTION(execLocalTime); \
	DECLARE_FUNCTION(execLocalTimeStamp); \
	DECLARE_FUNCTION(execMakeDate); \
	DECLARE_FUNCTION(execMakeTime); \
	DECLARE_FUNCTION(execMicroSecond); \
	DECLARE_FUNCTION(execMinute); \
	DECLARE_FUNCTION(execNow); \
	DECLARE_FUNCTION(execPeriodAdd); \
	DECLARE_FUNCTION(execPeriodDiff); \
	DECLARE_FUNCTION(execQuarter); \
	DECLARE_FUNCTION(execSecond); \
	DECLARE_FUNCTION(execSecToTime); \
	DECLARE_FUNCTION(execStringToDate); \
	DECLARE_FUNCTION(execSubDate); \
	DECLARE_FUNCTION(execSubTime); \
	DECLARE_FUNCTION(execSysDate); \
	DECLARE_FUNCTION(execTime); \
	DECLARE_FUNCTION(execTimeFormat); \
	DECLARE_FUNCTION(execTimeToSec); \
	DECLARE_FUNCTION(execTimeDiff); \
	DECLARE_FUNCTION(execTimeStamp); \
	DECLARE_FUNCTION(execToDays); \
	DECLARE_FUNCTION(execWeek); \
	DECLARE_FUNCTION(execYear); \
	DECLARE_FUNCTION(execWeekDay); \
	DECLARE_FUNCTION(execWeekOfYear); \
	DECLARE_FUNCTION(execYearWeek); \
	DECLARE_FUNCTION(execShowProceduresStatus); \
	DECLARE_FUNCTION(execShowCreateProcedure); \
	DECLARE_FUNCTION(execDropProcedure); \
	DECLARE_FUNCTION(execExecuteProcedure); \
	DECLARE_FUNCTION(execCreateProcedure); \
	DECLARE_FUNCTION(execDefiningVariables); \
	DECLARE_FUNCTION(execShowFunctionsStatus); \
	DECLARE_FUNCTION(execShowCreateFunction); \
	DECLARE_FUNCTION(execDropFunction); \
	DECLARE_FUNCTION(execExecuteFunction); \
	DECLARE_FUNCTION(execCreateFunction); \
	DECLARE_FUNCTION(execReleaseSavePoint); \
	DECLARE_FUNCTION(execRollback); \
	DECLARE_FUNCTION(execSetSavePointName); \
	DECLARE_FUNCTION(execCommit); \
	DECLARE_FUNCTION(execSetAutoCommit); \
	DECLARE_FUNCTION(execStartTransaction); \
	DECLARE_FUNCTION(execReplaceIfExistence); \
	DECLARE_FUNCTION(execSimpleInsertTableData); \
	DECLARE_FUNCTION(execInsertTableData); \
	DECLARE_FUNCTION(execReplaceTableData); \
	DECLARE_FUNCTION(execUpdateTableData); \
	DECLARE_FUNCTION(execPrintResult); \
	DECLARE_FUNCTION(execQueryLink); \
	DECLARE_FUNCTION(execQueryLinkResult); \
	DECLARE_FUNCTION(execGetSelectTableDataSQL); \
	DECLARE_FUNCTION(execGetSelectTableData); \
	DECLARE_FUNCTION(execIsFieldExistInTable); \
	DECLARE_FUNCTION(execGetShowVariables); \
	DECLARE_FUNCTION(execGetShowStatus); \
	DECLARE_FUNCTION(execGetSelectUser); \
	DECLARE_FUNCTION(execGetSelectDatabase); \
	DECLARE_FUNCTION(execGetSelectVersion); \
	DECLARE_FUNCTION(execOptimiseTable); \
	DECLARE_FUNCTION(execDeleteFromTableWhereData); \
	DECLARE_FUNCTION(execDeleteFromTable); \
	DECLARE_FUNCTION(execTruncateTable); \
	DECLARE_FUNCTION(execDropTable); \
	DECLARE_FUNCTION(execDropTemporaryTable); \
	DECLARE_FUNCTION(execCopyTableAToTemporaryBFast); \
	DECLARE_FUNCTION(execCopyTableAToBFast); \
	DECLARE_FUNCTION(execShowTables); \
	DECLARE_FUNCTION(execCopyTableAToTemporaryB); \
	DECLARE_FUNCTION(execCopyTableAToB); \
	DECLARE_FUNCTION(execCreateTemporaryTable); \
	DECLARE_FUNCTION(execCreateTable); \
	DECLARE_FUNCTION(execDropDataBase); \
	DECLARE_FUNCTION(execSelectNewDB); \
	DECLARE_FUNCTION(execCreateAndSelectDataBase); \
	DECLARE_FUNCTION(execCreateDataBase); \
	DECLARE_FUNCTION(execQueryLinkStmt); \
	DECLARE_FUNCTION(execCreateMysqlObject);


#define FID_Engine_Plugins_RENZHAI_PLUGIN_SimpleMySQL_Source_SimpleMySQL_Public_SimpleMySQLibrary_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUSimpleMySQLLibrary(); \
	friend struct Z_Construct_UClass_USimpleMySQLLibrary_Statics; \
public: \
	DECLARE_CLASS(USimpleMySQLLibrary, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/SimpleMySQL"), NO_API) \
	DECLARE_SERIALIZER(USimpleMySQLLibrary)


#define FID_Engine_Plugins_RENZHAI_PLUGIN_SimpleMySQL_Source_SimpleMySQL_Public_SimpleMySQLibrary_h_13_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USimpleMySQLLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	USimpleMySQLLibrary(USimpleMySQLLibrary&&); \
	USimpleMySQLLibrary(const USimpleMySQLLibrary&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USimpleMySQLLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USimpleMySQLLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USimpleMySQLLibrary) \
	NO_API virtual ~USimpleMySQLLibrary();


#define FID_Engine_Plugins_RENZHAI_PLUGIN_SimpleMySQL_Source_SimpleMySQL_Public_SimpleMySQLibrary_h_10_PROLOG
#define FID_Engine_Plugins_RENZHAI_PLUGIN_SimpleMySQL_Source_SimpleMySQL_Public_SimpleMySQLibrary_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Engine_Plugins_RENZHAI_PLUGIN_SimpleMySQL_Source_SimpleMySQL_Public_SimpleMySQLibrary_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Engine_Plugins_RENZHAI_PLUGIN_SimpleMySQL_Source_SimpleMySQL_Public_SimpleMySQLibrary_h_13_INCLASS_NO_PURE_DECLS \
	FID_Engine_Plugins_RENZHAI_PLUGIN_SimpleMySQL_Source_SimpleMySQL_Public_SimpleMySQLibrary_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SIMPLEMYSQL_API UClass* StaticClass<class USimpleMySQLLibrary>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Engine_Plugins_RENZHAI_PLUGIN_SimpleMySQL_Source_SimpleMySQL_Public_SimpleMySQLibrary_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
