// Copyright (C) RenZhai.2020.All Rights Reserved.
#include "SimpleMySQLibrary.h"
#include "MySQL/mysql.h"
#include "Core/SimpleMysqlLink.h"
#include "Blueprint/SimpleMysqlObject.h"

USimpleMysqlObject * USimpleMySQLLibrary::CreateMysqlObject(UObject* WorldContextObject, const FString &InUser, const FString &InHost, const FString &InPawd, const FString &InDB, const int32 InPort, const TArray<ESimpleClientFlags> &ClientFlag, const FString &Unix_Socket /*= TEXT("\0")*//*= 0*/)
{
	USimpleMysqlObject * MysqlObject = NULL;

	auto CallMainThreadWork = [&]()->USimpleMysqlObject*
	{
#ifdef  PLATFORM_PROJECT
		if (UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
		{
			if (USimpleMysqlObject *Object = NewObject<USimpleMysqlObject>(World))
			{
				Object->InitMysql(InUser, InHost, InPawd, InDB, InPort, Unix_Socket, ClientFlag);	
			
				return Object;
			}
		}
		return nullptr;
#else
		USimpleMysqlObject* Object = NewObject<USimpleMysqlObject>();
		if (Object)
		{
			Object->InitMysql(InUser, InHost, InPawd, InDB, InPort, Unix_Socket, ClientFlag);
			Object->AddToRoot();
		}

		return Object;
#endif // PLATFORM_PROJECT
	};

	if (FPlatformTLS::GetCurrentThreadId() == GGameThreadId)
	{
		MysqlObject = CallMainThreadWork();
	}
	else
	{
		//呼叫主线程
		FGraphEventRef EventRef = FFunctionGraphTask::CreateAndDispatchWhenReady([&]()
		{
			MysqlObject = CallMainThreadWork();
		},
		TStatId(),
		NULL,
		ENamedThreads::GameThread);

		//异步线程 阻塞
		FTaskGraphInterface::Get().WaitUntilTaskCompletes(EventRef);
	}

	return MysqlObject;
}

bool USimpleMySQLLibrary::QueryLinkStmt(USimpleMysqlObject *Object, const FString& SQL, const TArray<FSimpleMysqlQueryStmt>& InQueryStmtParam, FSimpleMysqlQueryStmtResult& OutResult, FString& ErrMesg)
{
	if (Object)
	{
		return Object->GetLink()->QueryLinkStmt(SQL,InQueryStmtParam, OutResult,ErrMesg);
	}

	return false;
}

bool USimpleMySQLLibrary::QueryLink(USimpleMysqlObject *Object, const FString &SQL, FString &ErrMesg)
{
	if (Object)
	{
		return Object->GetLink()->QueryLink(SQL, ErrMesg);
	}

	return false;
}

bool USimpleMySQLLibrary::SelectNewDB(USimpleMysqlObject *Object, const FString &NewDB, FString &ErrMesg)
{
	if (Object)
	{
		return Object->GetLink()->SelectNewDB(NewDB, ErrMesg);
	}

	return false;
}

bool USimpleMySQLLibrary::CreateDataBase(USimpleMysqlObject *Object, const FString &DataBaseName, EMysqlCharset Charset, FString &ErrorMsg)
{
	if (Object)
	{
		return Object->GetLink()->CreateDataBase(DataBaseName, Charset, ErrorMsg);
	}

	return false;
}

bool USimpleMySQLLibrary::CreateAndSelectDataBase(USimpleMysqlObject *Object, const FString &DataBaseName, EMysqlCharset Charset, FString &ErrorMsg)
{
	if (Object)
	{
		return Object->GetLink()->CreateAndSelectDataBase(DataBaseName, Charset, ErrorMsg);
	}

	return false;
}

bool USimpleMySQLLibrary::DropDataBase(USimpleMysqlObject *Object, const FString &DataBaseName, FString &ErrorMsg)
{
	if (Object)
	{
		return Object->GetLink()->DropDataBase(DataBaseName, ErrorMsg);
	}

	return false;
}

bool USimpleMySQLLibrary::CreateTable(USimpleMysqlObject *Object, const FString &TableName, const TMap<FString, FMysqlFieldType> &InFields, const TArray<FString> &InPrimaryKeys, const FMysqlCreateTableParam &Param, FString &ErrorMsg)
{
	if (Object)
	{
		return Object->GetLink()->CreateTable(TableName, InFields, InPrimaryKeys, Param, ErrorMsg);
	}

	return false;
}

bool USimpleMySQLLibrary::CreateTemporaryTable(USimpleMysqlObject *Object, const FString &TableName, const TMap<FString, FMysqlFieldType> &InFields, const FSimpleMysqlQueryParameters &QueryParam, FString &ErrorMsg)
{
	if (Object)
	{
		return Object->GetLink()->CreateTemporaryTable(TableName, InFields, QueryParam, ErrorMsg);
	}

	return false;
}

bool USimpleMySQLLibrary::CopyTableAToB(USimpleMysqlObject *Object, const FString &A, const FString &B, const TArray<FString> &Fields, FString &ErrorMsg)
{
	if (Object)
	{
		return Object->GetLink()->CopyTableAToB(A, B, Fields, ErrorMsg);
	}

	return false;
}

bool USimpleMySQLLibrary::CopyTableAToTemporaryB(USimpleMysqlObject *Object, const FString &TableA, const FString &TemporaryTableB, const TArray<FString> &Fields, FString &ErrorMsg)
{
	if (Object)
	{
		return Object->GetLink()->CopyTableAToTemporaryB(TableA, TemporaryTableB, Fields, ErrorMsg);
	}

	return false;
}

bool USimpleMySQLLibrary::ShowTables(USimpleMysqlObject *Object, const FString &TableName, EMysqlQuerySaveType SaveType, TArray<FSimpleMysqlResult> &Results, FString &ErrMesg, const FSimpleMysqlDebugResult &Debug)
{
	if (Object)
	{
		return Object->GetLink()->ShowTables(TableName, SaveType, Results, ErrMesg, Debug);
	}

	return false;
}

bool USimpleMySQLLibrary::CopyTableAToBFast(USimpleMysqlObject *Object, const FString &CopySourceTable, const TMap<FString, FMysqlFieldType> &InsertFields, const FSimpleMysqlQueryParameters &QueryParam, FString &ErrorMsg)
{
	if (Object)
	{
		return Object->GetLink()->CopyTableAToBFast(CopySourceTable, InsertFields, QueryParam, ErrorMsg);
	}

	return false;
}

bool USimpleMySQLLibrary::CopyTableAToTemporaryBFast(USimpleMysqlObject *Object, const FString &CopySourceTable, const TMap<FString, FMysqlFieldType> &InsertFields, const FSimpleMysqlQueryParameters &QueryParam, FString &ErrorMsg)
{
	if (Object)
	{
		return Object->GetLink()->CopyTableAToTemporaryBFast(CopySourceTable, InsertFields, QueryParam, ErrorMsg);
	}

	return false;
}

bool USimpleMySQLLibrary::DropTemporaryTable(USimpleMysqlObject *Object, const FString &TemporaryTableName, FString &ErrorMsg)
{
	if (Object)
	{
		return Object->GetLink()->DropTemporaryTable(TemporaryTableName, ErrorMsg);
	}

	return false;
}

bool USimpleMySQLLibrary::DropTable(USimpleMysqlObject *Object, const FString &TableName, FString &ErrorMsg)
{
	if (Object)
	{
		return Object->GetLink()->DropTable(TableName, ErrorMsg);
	}

	return false;
}

bool USimpleMySQLLibrary::TruncateTable(USimpleMysqlObject *Object, const FString &TableName, FString &ErrorMsg)
{
	if (Object)
	{
		return Object->GetLink()->TruncateTable(TableName, ErrorMsg);
	}

	return false;
}

bool USimpleMySQLLibrary::DeleteFromTable(USimpleMysqlObject *Object, const FString &TableName, FString &ErrorMsg)
{
	if (Object)
	{
		return Object->GetLink()->DeleteFromTable(TableName, ErrorMsg);
	}

	return false;
}

bool USimpleMySQLLibrary::DeleteFromTableWhereData(USimpleMysqlObject *Object, const FString &TableName, const TArray<FSimpleMysqlComparisonOperator> &Condition, FString &ErrorMsg)
{
	if (Object)
	{
		return Object->GetLink()->DeleteFromTableWhereData(TableName, Condition, ErrorMsg);
	}

	return false;
}

bool USimpleMySQLLibrary::OptimiseTable(USimpleMysqlObject *Object, const FString &TableName, FString &ErrorMsg)
{
	if (Object)
	{
		return Object->GetLink()->OptimiseTable(TableName, ErrorMsg);
	}

	return false;
}

bool USimpleMySQLLibrary::GetSelectVersion(USimpleMysqlObject *Object, TArray<FSimpleMysqlResult> &Results, FString &ErrMesg, const FSimpleMysqlDebugResult &Debug, EMysqlQuerySaveType SaveType /*= EMysqlQuerySaveType::STORE_RESULT*/)
{
	if (Object)
	{
		return Object->GetLink()->GetSelectVersion(Results, ErrMesg, SaveType, Debug);
	}

	return false;
}

bool USimpleMySQLLibrary::GetSelectDatabase(USimpleMysqlObject *Object, TArray<FSimpleMysqlResult> &Results, FString &ErrMesg, const FSimpleMysqlDebugResult &Debug, EMysqlQuerySaveType SaveType /*= EMysqlQuerySaveType::STORE_RESULT*/)
{
	if (Object)
	{
		return Object->GetLink()->GetSelectDatabase(Results, ErrMesg, SaveType, Debug);
	}

	return false;
}

bool USimpleMySQLLibrary::GetSelectUser(USimpleMysqlObject *Object, TArray<FSimpleMysqlResult> &Results, FString &ErrMesg, const FSimpleMysqlDebugResult &Debug, EMysqlQuerySaveType SaveType /*= EMysqlQuerySaveType::STORE_RESULT*/)
{
	if (Object)
	{
		return Object->GetLink()->GetSelectUser(Results, ErrMesg, SaveType, Debug);
	}

	return false;
}

bool USimpleMySQLLibrary::GetShowStatus(USimpleMysqlObject *Object, TArray<FSimpleMysqlResult> &Results, FString &ErrMesg, const FSimpleMysqlDebugResult &Debug, EMysqlQuerySaveType SaveType /*= EMysqlQuerySaveType::STORE_RESULT*/)
{
	if (Object)
	{
		return Object->GetLink()->GetShowStatus(Results, ErrMesg, SaveType, Debug);
	}

	return false;
}

bool USimpleMySQLLibrary::GetShowVariables(USimpleMysqlObject *Object, TArray<FSimpleMysqlResult> &Results, FString &ErrMesg, const FSimpleMysqlDebugResult &Debug, EMysqlQuerySaveType SaveType /*= EMysqlQuerySaveType::STORE_RESULT*/)
{
	if (Object)
	{
		return Object->GetLink()->GetShowVariables(Results, ErrMesg, SaveType, Debug);
	}

	return false;
}

bool USimpleMySQLLibrary::GetSelectTableData(USimpleMysqlObject* Object, const FSimpleMysqlQueryParameters& QueryParam, TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, EMysqlQuerySaveType SaveType, const FSimpleMysqlDebugResult& Debug)
{
	if (Object)
	{
		return Object->GetLink()->GetSelectTableData(QueryParam, Results, ErrMesg, SaveType, Debug);
	}

	return false;
}

bool USimpleMySQLLibrary::PrintResult(USimpleMysqlObject *Object, const TArray<FSimpleMysqlResult> &Results, bool bPrintToScreen /*= true*/, bool bPrintToLog /*= true*/)
{
	if (Object)
	{
		return Object->GetLink()->PrintResult(Results, bPrintToLog, bPrintToScreen);
	}

	return false;
}

bool USimpleMySQLLibrary::UpdateTableData(USimpleMysqlObject *Object, const FString &TableName, const TArray<FSimpleMysqlAssignment> &InFields, const TArray<FSimpleMysqlComparisonOperator> &Condition, FString &ErrorMsg)
{
	if (Object)
	{
		return Object->GetLink()->UpdateTableData(TableName, InFields, Condition, ErrorMsg);
	}

	return false;
}

bool USimpleMySQLLibrary::ReplaceTableData(USimpleMysqlObject *Object, const FString &TableName, const TArray<FSimpleMysqlReplaceParameters> &InReplaces, const TArray<FSimpleMysqlComparisonOperator> &Condition, FString &ErrorMsg)
{
	if (Object)
	{
		return Object->GetLink()->ReplaceTableData(TableName, InReplaces, Condition, ErrorMsg);
	}

	return false;
}

bool USimpleMySQLLibrary::InsertTableData(USimpleMysqlObject *Object, const FString& TableName, const TMap<FString, FString> &InsetKeyValueDatas, const FSimpleMysqlQueryParameters &QueryParam, FString& ErrorMsg, bool bIgnore)
{
	if (Object)
	{
		return Object->GetLink()->InsertTableData(TableName, InsetKeyValueDatas, QueryParam, ErrorMsg, bIgnore);
	}

	return false;
}

bool USimpleMySQLLibrary::SimpleInsertTableData(USimpleMysqlObject *Object, const FString& TableName, const TArray<FString> &InsetValueDatas, const FSimpleMysqlQueryParameters &QueryParam, FString& ErrorMsg, bool bIgnore)
{
	if (Object)
	{
		return Object->GetLink()->SimpleInsertTableData(TableName, InsetValueDatas, QueryParam, ErrorMsg, bIgnore);
	}

	return false;
}

bool USimpleMySQLLibrary::ReplaceIfExistence(USimpleMysqlObject *Object, const FString& TableName, const TMap<FString, FString> &InsetKeyValueDatas, FString& ErrorMsg)
{
	if (Object)
	{
		return Object->GetLink()->ReplaceIfExistence(TableName, InsetKeyValueDatas, ErrorMsg);
	}

	return false;
}

bool USimpleMySQLLibrary::StartTransaction(USimpleMysqlObject *Object, FString &ErrorMsg)
{
	if (Object)
	{
		return Object->GetLink()->StartTransaction(ErrorMsg);
	}

	return false;
}

bool USimpleMySQLLibrary::SetAutoCommit(USimpleMysqlObject *Object, bool bAuto, FString &ErrorMsg)
{
	if (Object)
	{
		return Object->GetLink()->SetAutoCommit(bAuto, ErrorMsg);
	}

	return false;
}

bool USimpleMySQLLibrary::Commit(USimpleMysqlObject *Object, FString &ErrorMsg)
{
	if (Object)
	{
		return Object->GetLink()->Commit(ErrorMsg);
	}

	return false;
}

bool USimpleMySQLLibrary::SetSavePointName(USimpleMysqlObject *Object, const FString &SaveName, FString &ErrorMsg)
{
	if (Object)
	{
		return Object->GetLink()->SetSavePointName(SaveName, ErrorMsg);
	}

	return false;
}

bool USimpleMySQLLibrary::Rollback(USimpleMysqlObject *Object, const FString &SaveName, FString &ErrorMsg)
{
	if (Object)
	{
		return Object->GetLink()->Rollback(SaveName, ErrorMsg);
	}

	return false;
}

bool USimpleMySQLLibrary::ReleaseSavePoint(USimpleMysqlObject *Object, const FString &SaveName, FString &ErrorMsg)
{
	if (Object)
	{
		return Object->GetLink()->ReleaseSavePoint(SaveName, ErrorMsg);
	}

	return false;
}

bool USimpleMySQLLibrary::CreateFunction(USimpleMysqlObject *Object, const FString &InFunctionName, const TMap<FString, FMysqlFieldType> &InParameter, const FString &InFunctionBody, FString& ErrMesg, EMysqlVariableType InReturnsType /*= EMysqlVariableType::INT*/, const FString &InComment /*= TEXT("")*/)
{
	if (Object)
	{
		return Object->GetLink()->CreateFunction(InFunctionName, InParameter, InFunctionBody, ErrMesg, InReturnsType, InComment);
	}

	return false;
}

bool USimpleMySQLLibrary::ExecuteFunction(USimpleMysqlObject *Object, const FString &InFunctionName, const TArray<FString> &InParameter, TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, EMysqlQuerySaveType SaveType, const FSimpleMysqlDebugResult& Debug)
{
	if (Object)
	{
		return Object->GetLink()->ExecuteFunction(InFunctionName, InParameter, Results, ErrMesg, SaveType, Debug);
	}

	return false;
}

bool USimpleMySQLLibrary::DropFunction(USimpleMysqlObject *Object, const FString &InFunctionName, FString& ErrMesg)
{
	if (Object)
	{
		return Object->GetLink()->DropFunction(InFunctionName, ErrMesg);
	}

	return false;
}

bool USimpleMySQLLibrary::ShowCreateFunction(USimpleMysqlObject *Object, const FString &InFunctionName, TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, EMysqlQuerySaveType SaveType, const FSimpleMysqlDebugResult& Debug)
{
	if (Object)
	{
		return Object->GetLink()->ShowCreateFunction(InFunctionName, Results, ErrMesg, SaveType, Debug);
	}

	return false;
}

bool USimpleMySQLLibrary::ShowFunctionsStatus(USimpleMysqlObject *Object, TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, EMysqlQuerySaveType SaveType, const FSimpleMysqlDebugResult& Debug)
{
	if (Object)
	{
		return Object->GetLink()->ShowFunctionsStatus(Results, ErrMesg, SaveType, Debug);
	}

	return false;
}

bool USimpleMySQLLibrary::DefiningVariables(USimpleMysqlObject *Object, const FString &InVariablesName, const FString &InValue, FString &ErrMesg)
{
	if (Object)
	{
		return Object->GetLink()->DefiningVariables(InVariablesName, InValue, ErrMesg);
	}

	return false;
}

bool USimpleMySQLLibrary::CreateProcedure(USimpleMysqlObject *Object, const FString &InProcedureName, const TMap<FString, FMysqlFieldType> &InParameter, const FString &InProcedureBody, FString& ErrMesg, const FString &InComment /*= TEXT("")*/)
{
	if (Object)
	{
		return Object->GetLink()->CreateProcedure(InProcedureName, InParameter, InProcedureBody, ErrMesg, InComment);
	}

	return false;
}

bool USimpleMySQLLibrary::ExecuteProcedure(USimpleMysqlObject *Object, const FString &InProcedureName, const TArray<FString> &InParameter, TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, EMysqlQuerySaveType SaveType, const FSimpleMysqlDebugResult& Debug)
{
	if (Object)
	{
		return Object->GetLink()->ExecuteProcedure(InProcedureName, InParameter, Results, ErrMesg, SaveType, Debug);
	}

	return false;
}

bool USimpleMySQLLibrary::DropProcedure(USimpleMysqlObject *Object, const FString &InProcedureName, FString& ErrMesg)
{
	if (Object)
	{
		return Object->GetLink()->DropProcedure(InProcedureName, ErrMesg);
	}

	return false;
}

bool USimpleMySQLLibrary::ShowCreateProcedure(USimpleMysqlObject *Object, const FString &InProcedureName, TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, EMysqlQuerySaveType SaveType, const FSimpleMysqlDebugResult& Debug)
{
	if (Object)
	{
		return Object->GetLink()->ShowCreateProcedure(InProcedureName, Results, ErrMesg, SaveType, Debug);
	}

	return false;
}

bool USimpleMySQLLibrary::ShowProceduresStatus(USimpleMysqlObject *Object, TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, EMysqlQuerySaveType SaveType, const FSimpleMysqlDebugResult& Debug)
{
	if (Object)
	{
		return Object->GetLink()->ShowProceduresStatus(Results, ErrMesg, SaveType, Debug);
	}

	return false;
}

bool USimpleMySQLLibrary::YearWeek(USimpleMysqlObject *Object, const FString &InDate, TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, EMysqlQuerySaveType SaveType, const FSimpleMysqlDebugResult& Debug)
{
	if (Object)
	{
		return Object->GetLink()->YearWeek(InDate, Results, ErrMesg, SaveType, Debug);
	}

	return false;
}

bool USimpleMySQLLibrary::WeekOfYear(USimpleMysqlObject *Object, const FString& InDate, TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, EMysqlQuerySaveType SaveType, const FSimpleMysqlDebugResult& Debug)
{
	if (Object)
	{
		return Object->GetLink()->WeekOfYear(InDate, Results, ErrMesg, SaveType, Debug);
	}

	return false;
}

bool USimpleMySQLLibrary::WeekDay(USimpleMysqlObject *Object, const FString& InDate, TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, EMysqlQuerySaveType SaveType, const FSimpleMysqlDebugResult& Debug)
{
	if (Object)
	{
		return Object->GetLink()->WeekDay(InDate, Results, ErrMesg, SaveType, Debug);
	}

	return false;
}

bool USimpleMySQLLibrary::Year(USimpleMysqlObject *Object, const FString& InDate, TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, EMysqlQuerySaveType SaveType, const FSimpleMysqlDebugResult& Debug)
{
	if (Object)
	{
		return Object->GetLink()->Year(InDate, Results, ErrMesg, SaveType, Debug);
	}

	return false;
}

bool USimpleMySQLLibrary::Week(USimpleMysqlObject *Object, const FString& InDate, TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, EMysqlQuerySaveType SaveType, const FSimpleMysqlDebugResult& Debug)
{
	if (Object)
	{
		return Object->GetLink()->Week(InDate, Results, ErrMesg, SaveType, Debug);
	}

	return false;
}

bool USimpleMySQLLibrary::ToDays(USimpleMysqlObject *Object, const FString& InDate, TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, EMysqlQuerySaveType SaveType, const FSimpleMysqlDebugResult& Debug)
{
	if (Object)
	{
		return Object->GetLink()->ToDays(InDate, Results, ErrMesg, SaveType, Debug);
	}

	return false;
}

bool USimpleMySQLLibrary::TimeStamp(USimpleMysqlObject *Object, const FString& InExpression, const FString& InInterval, TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, EMysqlQuerySaveType SaveType, const FSimpleMysqlDebugResult& Debug)
{
	if (Object)
	{
		return Object->GetLink()->TimeStamp(InExpression, InInterval, Results, ErrMesg, SaveType, Debug);
	}

	return false;
}

bool USimpleMySQLLibrary::TimeDiff(USimpleMysqlObject *Object, const FString& InTime1, const FString& InTime2, TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, EMysqlQuerySaveType SaveType, const FSimpleMysqlDebugResult& Debug)
{
	if (Object)
	{
		return Object->GetLink()->TimeDiff(InTime1, InTime2, Results, ErrMesg, SaveType, Debug);
	}

	return false;
}

bool USimpleMySQLLibrary::TimeToSec(USimpleMysqlObject *Object, const FString& InTime, TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, EMysqlQuerySaveType SaveType, const FSimpleMysqlDebugResult& Debug)
{
	if (Object)
	{
		return Object->GetLink()->TimeToSec(InTime, Results, ErrMesg, SaveType, Debug);
	}

	return false;
}

bool USimpleMySQLLibrary::IsFieldExistInTable(USimpleMysqlObject *Object, const FString &InTableName, const FString &InFieldName, FString &ErrMesg)
{
	if (Object)
	{
		return Object->GetLink()->IsFieldExistInTable(InTableName, InFieldName, ErrMesg);
	}

	return false;
}

bool USimpleMySQLLibrary::TimeFormat(USimpleMysqlObject *Object, const FString& InTime, const FString& InFormat, TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, EMysqlQuerySaveType SaveType, const FSimpleMysqlDebugResult& Debug)
{
	if (Object)
	{
		return Object->GetLink()->TimeFormat(InTime, InFormat, Results, ErrMesg, SaveType, Debug);
	}

	return false;
}

bool USimpleMySQLLibrary::Time(USimpleMysqlObject *Object, const FString& InExpression, TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, EMysqlQuerySaveType SaveType, const FSimpleMysqlDebugResult& Debug)
{
	if (Object)
	{
		return Object->GetLink()->Time(InExpression, Results, ErrMesg, SaveType, Debug);
	}

	return false;
}

bool USimpleMySQLLibrary::SysDate(USimpleMysqlObject *Object, TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, EMysqlQuerySaveType SaveType, const FSimpleMysqlDebugResult& Debug)
{
	if (Object)
	{
		return Object->GetLink()->SysDate(Results, ErrMesg, SaveType, Debug);
	}

	return false;
}

bool USimpleMySQLLibrary::SubTime(USimpleMysqlObject *Object, const FString& InTime, int64 InSecond, TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, EMysqlQuerySaveType SaveType, const FSimpleMysqlDebugResult& Debug)
{
	if (Object)
	{
		return Object->GetLink()->SubTime(InTime, InSecond, Results, ErrMesg, SaveType, Debug);
	}

	return false;
}

bool USimpleMySQLLibrary::SubDate(USimpleMysqlObject *Object, const FString& InDate, int64 InDay, TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, EMysqlQuerySaveType SaveType, const FSimpleMysqlDebugResult& Debug)
{
	if (Object)
	{
		return Object->GetLink()->SubDate(InDate, InDay, Results, ErrMesg, SaveType, Debug);
	}

	return false;
}

bool USimpleMySQLLibrary::StringToDate(USimpleMysqlObject *Object, const FString& InString, const FString& InFormatMask, TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, EMysqlQuerySaveType SaveType, const FSimpleMysqlDebugResult& Debug)
{
	if (Object)
	{
		return Object->GetLink()->StringToDate(InString, InFormatMask, Results, ErrMesg, SaveType, Debug);
	}

	return false;
}

bool USimpleMySQLLibrary::SecToTime(USimpleMysqlObject *Object, const int64 InSecond, TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, EMysqlQuerySaveType SaveType, const FSimpleMysqlDebugResult& Debug)
{
	if (Object)
	{
		return Object->GetLink()->SecToTime(InSecond, Results, ErrMesg, SaveType, Debug);
	}

	return false;
}

bool USimpleMySQLLibrary::Second(USimpleMysqlObject *Object, const FString &InTime, TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, EMysqlQuerySaveType SaveType, const FSimpleMysqlDebugResult& Debug)
{
	if (Object)
	{
		return Object->GetLink()->Second(InTime, Results, ErrMesg, SaveType, Debug);
	}

	return false;
}

bool USimpleMySQLLibrary::Quarter(USimpleMysqlObject *Object, const FString &InDate, TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, EMysqlQuerySaveType SaveType, const FSimpleMysqlDebugResult& Debug)
{
	if (Object)
	{
		return Object->GetLink()->Quarter(InDate, Results, ErrMesg, SaveType, Debug);
	}

	return false;
}

bool USimpleMySQLLibrary::PeriodDiff(USimpleMysqlObject *Object, const int64 Period1, const int64 Period2, TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, EMysqlQuerySaveType SaveType, const FSimpleMysqlDebugResult& Debug)
{
	if (Object)
	{
		return Object->GetLink()->PeriodDiff(Period1, Period2, Results, ErrMesg, SaveType, Debug);
	}

	return false;
}

bool USimpleMySQLLibrary::PeriodAdd(USimpleMysqlObject *Object, const int64 InPeriod, const int64 InMonths, TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, EMysqlQuerySaveType SaveType, const FSimpleMysqlDebugResult& Debug)
{
	if (Object)
	{
		return Object->GetLink()->PeriodAdd(InPeriod, InMonths, Results, ErrMesg, SaveType, Debug);
	}

	return false;
}

bool USimpleMySQLLibrary::Now(USimpleMysqlObject *Object, TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, EMysqlQuerySaveType SaveType, const FSimpleMysqlDebugResult& Debug)
{
	if (Object)
	{
		return Object->GetLink()->Now(Results, ErrMesg, SaveType, Debug);
	}

	return false;
}

bool USimpleMySQLLibrary::Minute(USimpleMysqlObject *Object, const FString &InTime, TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, EMysqlQuerySaveType SaveType, const FSimpleMysqlDebugResult& Debug)
{
	if (Object)
	{
		return Object->GetLink()->Minute(InTime, Results, ErrMesg, SaveType, Debug);
	}

	return false;
}

bool USimpleMySQLLibrary::MicroSecond(USimpleMysqlObject *Object, const FString &InDate, TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, EMysqlQuerySaveType SaveType, const FSimpleMysqlDebugResult& Debug)
{
	if (Object)
	{
		return Object->GetLink()->MicroSecond(InDate, Results, ErrMesg, SaveType, Debug);
	}

	return false;
}

bool USimpleMySQLLibrary::MakeTime(USimpleMysqlObject *Object, const FString &InDate, TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, EMysqlQuerySaveType SaveType, const FSimpleMysqlDebugResult& Debug)
{
	if (Object)
	{
		return Object->GetLink()->MakeTime(InDate, Results, ErrMesg, SaveType, Debug);
	}

	return false;
}

bool USimpleMySQLLibrary::MakeDate(USimpleMysqlObject *Object, const int32 InYear, const int64 DayOfYear, TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, EMysqlQuerySaveType SaveType, const FSimpleMysqlDebugResult& Debug)
{
	if (Object)
	{
		return Object->GetLink()->MakeDate(InYear, DayOfYear, Results, ErrMesg, SaveType, Debug);
	}

	return false;
}

bool USimpleMySQLLibrary::LocalTimeStamp(USimpleMysqlObject *Object, TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, EMysqlQuerySaveType SaveType, const FSimpleMysqlDebugResult& Debug)
{
	if (Object)
	{
		return Object->GetLink()->LocalTimeStamp(Results, ErrMesg, SaveType, Debug);
	}

	return false;
}

bool USimpleMySQLLibrary::LocalTime(USimpleMysqlObject *Object, TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, EMysqlQuerySaveType SaveType, const FSimpleMysqlDebugResult& Debug)
{
	if (Object)
	{
		return Object->GetLink()->LocalTime(Results, ErrMesg, SaveType, Debug);
	}

	return false;
}

bool USimpleMySQLLibrary::LastDay(USimpleMysqlObject *Object, const FString &InDate, TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, EMysqlQuerySaveType SaveType, const FSimpleMysqlDebugResult& Debug)
{
	if (Object)
	{
		return Object->GetLink()->LastDay(InDate, Results, ErrMesg, SaveType, Debug);
	}

	return false;
}

bool USimpleMySQLLibrary::Hour(USimpleMysqlObject *Object, const FString &InTime, TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, EMysqlQuerySaveType SaveType, const FSimpleMysqlDebugResult& Debug)
{
	if (Object)
	{
		return Object->GetLink()->Hour(InTime, Results, ErrMesg, SaveType, Debug);
	}

	return false;
}

bool USimpleMySQLLibrary::FromDays(USimpleMysqlObject *Object, const int64 InDay, TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, EMysqlQuerySaveType SaveType, const FSimpleMysqlDebugResult& Debug)
{
	if (Object)
	{
		return Object->GetLink()->FromDays(InDay, Results, ErrMesg, SaveType, Debug);
	}

	return false;
}

bool USimpleMySQLLibrary::Extract(USimpleMysqlObject *Object, const FString &InDate, const EMysqlDateType DateType, TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, EMysqlQuerySaveType SaveType, const FSimpleMysqlDebugResult& Debug)
{
	if (Object)
	{
		return Object->GetLink()->Extract(InDate, DateType, Results, ErrMesg, SaveType, Debug);
	}

	return false;
}

bool USimpleMySQLLibrary::DayOfYear(USimpleMysqlObject *Object, const FString &InDate, TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, EMysqlQuerySaveType SaveType, const FSimpleMysqlDebugResult& Debug)
{
	if (Object)
	{
		return Object->GetLink()->DayOfYear(InDate, Results, ErrMesg, SaveType, Debug);
	}

	return false;
}

bool USimpleMySQLLibrary::DayOfWeek(USimpleMysqlObject *Object, const FString &InDate, TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, EMysqlQuerySaveType SaveType, const FSimpleMysqlDebugResult& Debug)
{
	if (Object)
	{
		return Object->GetLink()->DayOfWeek(InDate, Results, ErrMesg, SaveType, Debug);
	}

	return false;
}

bool USimpleMySQLLibrary::DayOfMonth(USimpleMysqlObject *Object, const FString &InDate, TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, EMysqlQuerySaveType SaveType, const FSimpleMysqlDebugResult& Debug)
{
	if (Object)
	{
		return Object->GetLink()->DayOfMonth(InDate, Results, ErrMesg, SaveType, Debug);
	}

	return false;
}

bool USimpleMySQLLibrary::DayName(USimpleMysqlObject *Object, const FString& InDate, TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, EMysqlQuerySaveType SaveType, const FSimpleMysqlDebugResult& Debug)
{
	if (Object)
	{
		return Object->GetLink()->DayName(InDate, Results, ErrMesg, SaveType, Debug);
	}

	return false;
}

bool USimpleMySQLLibrary::Day(USimpleMysqlObject *Object, const FString& InDate, TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, EMysqlQuerySaveType SaveType, const FSimpleMysqlDebugResult& Debug)
{
	if (Object)
	{
		return Object->GetLink()->Day(InDate, Results, ErrMesg, SaveType, Debug);
	}

	return false;
}

bool USimpleMySQLLibrary::DateSub(USimpleMysqlObject *Object, const FString& InDate, const int64 InInterval, TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, EMysqlQuerySaveType SaveType, const FSimpleMysqlDebugResult& Debug)
{
	if (Object)
	{
		return Object->GetLink()->DateSub(InDate, InInterval, Results, ErrMesg, SaveType, Debug);
	}

	return false;
}

bool USimpleMySQLLibrary::DateFormat(USimpleMysqlObject *Object, const FString& InDate, const FString& InFormat, TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, EMysqlQuerySaveType SaveType, const FSimpleMysqlDebugResult& Debug)
{
	if (Object)
	{
		return Object->GetLink()->DateFormat(InDate, InFormat, Results, ErrMesg, SaveType, Debug);
	}

	return false;
}

bool USimpleMySQLLibrary::AddDate(USimpleMysqlObject *Object, const FString& InDate, const int64 InInterval, TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, EMysqlQuerySaveType SaveType, const FSimpleMysqlDebugResult& Debug)
{
	if (Object)
	{
		return Object->GetLink()->AddDate(InDate, InInterval, Results, ErrMesg, SaveType, Debug);
	}

	return false;
}

bool USimpleMySQLLibrary::DateDiff(USimpleMysqlObject *Object, const FString& InD1, const FString& InD2, TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, EMysqlQuerySaveType SaveType, const FSimpleMysqlDebugResult& Debug)
{
	if (Object)
	{
		return Object->GetLink()->DateDiff(InD1, InD2, Results, ErrMesg, SaveType, Debug);
	}

	return false;
}

bool USimpleMySQLLibrary::Date(USimpleMysqlObject *Object, const FString& InExpression, TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, EMysqlQuerySaveType SaveType, const FSimpleMysqlDebugResult& Debug)
{
	if (Object)
	{
		return Object->GetLink()->Date(InExpression, Results, ErrMesg, SaveType, Debug);
	}

	return false;
}

bool USimpleMySQLLibrary::CurTime(USimpleMysqlObject *Object, TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, EMysqlQuerySaveType SaveType, const FSimpleMysqlDebugResult& Debug)
{
	if (Object)
	{
		return Object->GetLink()->CurTime(Results, ErrMesg, SaveType, Debug);
	}

	return false;
}

bool USimpleMySQLLibrary::CurrentTime(USimpleMysqlObject *Object, TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, EMysqlQuerySaveType SaveType, const FSimpleMysqlDebugResult& Debug)
{
	if (Object)
	{
		return Object->GetLink()->CurrentTime(Results, ErrMesg, SaveType, Debug);
	}

	return false;
}

bool USimpleMySQLLibrary::CurrentTimeStamp(USimpleMysqlObject *Object, TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, EMysqlQuerySaveType SaveType, const FSimpleMysqlDebugResult& Debug)
{
	if (Object)
	{
		return Object->GetLink()->CurrentTimeStamp(Results, ErrMesg, SaveType, Debug);
	}

	return false;
}

bool USimpleMySQLLibrary::AddTime(USimpleMysqlObject *Object, const FString& InDate, const int64 InSecond, TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, EMysqlQuerySaveType SaveType, const FSimpleMysqlDebugResult& Debug)
{
	if (Object)
	{
		return Object->GetLink()->AddTime(InDate, InSecond, Results, ErrMesg, SaveType, Debug);
	}

	return false;
}

bool USimpleMySQLLibrary::Bin(USimpleMysqlObject* Object, const int64 Value, TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, EMysqlQuerySaveType SaveType, const FSimpleMysqlDebugResult& Debug)
{
	if (Object)
	{
		return Object->GetLink()->Bin(Value, Results, ErrMesg, SaveType, Debug);
	}

	return false;
}

bool USimpleMySQLLibrary::Binary(USimpleMysqlObject* Object, const FString& Value, TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, EMysqlQuerySaveType SaveType, const FSimpleMysqlDebugResult& Debug)
{
	if (Object)
	{
		return Object->GetLink()->Binary(Value, Results, ErrMesg, SaveType, Debug);
	}

	return false;
}

bool USimpleMySQLLibrary::Cast(USimpleMysqlObject* Object, const FString& Value, EMysqlVariableType VariableType, TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, EMysqlQuerySaveType SaveType, const FSimpleMysqlDebugResult& Debug)
{
	if (Object)
	{
		return Object->GetLink()->Cast(Value, VariableType, Results, ErrMesg, SaveType, Debug);
	}

	return false;
}

bool USimpleMySQLLibrary::Conv(USimpleMysqlObject* Object, const FString& Value, int64 F1, int64 F2, TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, EMysqlQuerySaveType SaveType, const FSimpleMysqlDebugResult& Debug)
{
	if (Object)
	{
		return Object->GetLink()->Conv(Value, F1, F2, Results, ErrMesg, SaveType, Debug);
	}

	return false;
}

bool USimpleMySQLLibrary::Convert(USimpleMysqlObject* Object, const FString& InString, EMysqlCharset Charset, TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, EMysqlQuerySaveType SaveType, const FSimpleMysqlDebugResult& Debug)
{
	if (Object)
	{
		return Object->GetLink()->Convert(InString, Charset, Results, ErrMesg, SaveType, Debug);
	}

	return false;
}

bool USimpleMySQLLibrary::BinocularOperation(USimpleMysqlObject* Object, const FString& Expression, const FString& ValueA, const FString& ValueB, TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, EMysqlQuerySaveType SaveType, const FSimpleMysqlDebugResult& Debug)
{
	if (Object)
	{
		return Object->GetLink()->BinocularOperation(Expression, ValueA, ValueB, Results, ErrMesg, SaveType, Debug);
	}

	return false;
}

bool USimpleMySQLLibrary::IsNULL(USimpleMysqlObject* Object, const FString& Expression, TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, EMysqlQuerySaveType SaveType, const FSimpleMysqlDebugResult& Debug)
{
	if (Object)
	{
		return Object->GetLink()->IsNULL(Expression, Results, ErrMesg, SaveType, Debug);
	}

	return false;
}

bool USimpleMySQLLibrary::NULLIf(USimpleMysqlObject* Object, const FString& ValueA, const FString& ValueB, TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, EMysqlQuerySaveType SaveType, const FSimpleMysqlDebugResult& Debug)
{
	if (Object)
	{
		return Object->GetLink()->NULLIf(ValueA, ValueB, Results, ErrMesg, SaveType, Debug);
	}

	return false;
}

bool USimpleMySQLLibrary::Charset(USimpleMysqlObject* Object, const FString& Value, TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, EMysqlQuerySaveType SaveType, const FSimpleMysqlDebugResult& Debug)
{
	if (Object)
	{
		return Object->GetLink()->Charset(Value, Results, ErrMesg, SaveType, Debug);
	}

	return false;
}

bool USimpleMySQLLibrary::GetConnection_ID(USimpleMysqlObject* Object, TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, EMysqlQuerySaveType SaveType, const FSimpleMysqlDebugResult& Debug)
{
	if (Object)
	{
		return Object->GetLink()->GetConnection_ID(Results, ErrMesg, SaveType, Debug);
	}

	return false;
}

bool USimpleMySQLLibrary::GetCurrent_user(USimpleMysqlObject* Object, TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, EMysqlQuerySaveType SaveType, const FSimpleMysqlDebugResult& Debug)
{
	if (Object)
	{
		return Object->GetLink()->GetCurrent_user(Results, ErrMesg, SaveType, Debug);
	}

	return false;
}

bool USimpleMySQLLibrary::GetLast_Insert_ID(USimpleMysqlObject* Object, TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, EMysqlQuerySaveType SaveType, const FSimpleMysqlDebugResult& Debug)
{
	if (Object)
	{
		return Object->GetLink()->GetLast_Insert_ID(Results, ErrMesg, SaveType, Debug);
	}

	return false;
}

bool USimpleMySQLLibrary::GetSession_user(USimpleMysqlObject* Object, TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, EMysqlQuerySaveType SaveType, const FSimpleMysqlDebugResult& Debug)
{
	if (Object)
	{
		return Object->GetLink()->GetSession_user(Results, ErrMesg, SaveType, Debug);
	}

	return false;
}

bool USimpleMySQLLibrary::GetSystem_user(USimpleMysqlObject* Object, TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, EMysqlQuerySaveType SaveType, const FSimpleMysqlDebugResult& Debug)
{
	if (Object)
	{
		return Object->GetLink()->GetSystem_user(Results, ErrMesg, SaveType, Debug);
	}

	return false;
}

bool USimpleMySQLLibrary::GetSelectTableDataSQL(USimpleMysqlObject *Object, FString &SQL, const FSimpleMysqlQueryParameters &QueryParam)
{
	if (Object)
	{
		return Object->GetLink()->GetSelectTableDataSQL(SQL, QueryParam);
	}

	return false;
}

bool USimpleMySQLLibrary::QueryLinkResult(USimpleMysqlObject *Object, const FString &SQL, TArray<FSimpleMysqlResult>& Results, FString& ErrMesg, EMysqlQuerySaveType SaveType, const FSimpleMysqlDebugResult& Debug)
{
	if (Object)
	{
		return Object->GetLink()->QueryLinkResult(SQL, Results, ErrMesg, SaveType, Debug);
	}

	return false;
}

TArray<FString> USimpleMySQLLibrary::GetStringNULLArray()
{
	return TArray<FString>();
}

TArray<FSimpleMysqlAssignment> USimpleMySQLLibrary::GetAssignmentNULLArray()
{
	return TArray<FSimpleMysqlAssignment>();
}

TArray<FSimpleMysqlComparisonOperator> USimpleMySQLLibrary::GetComparisonOperatorNULLArray()
{
	return TArray<FSimpleMysqlComparisonOperator>();
}

TArray<FSimpleMysqlReplaceParameters> USimpleMySQLLibrary::GetReplaceParametersNULLArray()
{
	return TArray<FSimpleMysqlReplaceParameters>();
}

TMap<FString, FString> USimpleMySQLLibrary::GetMapStringNULL()
{
	return TMap<FString, FString>();
}

FSimpleMysqlQueryParameters USimpleMySQLLibrary::GetNULLQueryParameters()
{
	return FSimpleMysqlQueryParameters();
}

TMap<FString, FMysqlFieldType> USimpleMySQLLibrary::GetFieldNULL()
{
	return TMap<FString, FMysqlFieldType>();
}

FSimpleMysqlJoinParameters USimpleMySQLLibrary::GetJoinParametersNULL()
{
	return FSimpleMysqlJoinParameters();
}

FSimpleMysqlModifyField USimpleMySQLLibrary::GetModifyFieldNULL()
{
	return FSimpleMysqlModifyField();
}

TArray<FSimpleMysqlQueryOrderBy> USimpleMySQLLibrary::GetOrderByNULLArray()
{
	return TArray<FSimpleMysqlQueryOrderBy>();
}

TArray<FSimpleMysqlJoinParameters> USimpleMySQLLibrary::GetJoinParamNULLArray()
{
	return TArray<FSimpleMysqlJoinParameters>();
}
