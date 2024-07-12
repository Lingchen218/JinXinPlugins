#include "Json/SimpleMySQLJson.h"

#if !IS_PROGRAM
#include "Runtime/Launch/Resources/Version.h"
#endif

#if IS_PROGRAM

#ifndef ENGINE_MAJOR_VERSION
#define ENGINE_MAJOR_VERSION 5
#endif // !ENGINE_MAJOR_VERSION

#ifndef ENGINE_MINOR_VERSION
#define ENGINE_MINOR_VERSION 3
#endif // !ENGINE_MAJOR_VERSION

#endif

#if ENGINE_MAJOR_VERSION == 5 && ENGINE_MINOR_VERSION >= 3
#include "Json.h"
#endif

namespace SimpleMySQLJson
{
	bool StringToArrayMysqlArrayResult(const FString& InJsonString, TArray<FSimpleMysqlResult>& OutMysqlResult)
	{
#if ENGINE_MAJOR_VERSION == 5 && ENGINE_MINOR_VERSION >= 3
		TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(InJsonString);
		TArray<TSharedPtr<FJsonValue>> ValueRoots;

		if (FJsonSerializer::Deserialize(JsonReader, ValueRoots))
		{
			for (auto &Tmp : ValueRoots)
			{
				if (const TSharedPtr<FJsonObject>& InJsonObject = Tmp->AsObject())
				{
					FSimpleMysqlResult &InResult = OutMysqlResult.AddDefaulted_GetRef();

					const TArray<TSharedPtr<FJsonValue>>& InArrayObject = InJsonObject->GetArrayField(TEXT("Rows"));
					for (auto &SubTmp : InArrayObject)
					{
						if (const TSharedPtr<FJsonObject>& InSubJsonObject = SubTmp->AsObject())
						{
							FString Key = InSubJsonObject->GetStringField(TEXT("Key"));
							FString Value = InSubJsonObject->GetStringField(TEXT("Value"));

							InResult.Rows.Add(Key,Value);
						}
					}
				}
			}

			return true;
		}
#endif
		return false;
	}

	bool ArrayMysqlArrayResultToString(const TArray<FSimpleMysqlResult>& InMysqlResult,FString& OutJsonString)
	{
#if ENGINE_MAJOR_VERSION == 5 && ENGINE_MINOR_VERSION >= 3
		TSharedPtr<TJsonWriter<TCHAR, TCondensedJsonPrintPolicy<TCHAR>>> JsonWriter =
			TJsonWriterFactory<TCHAR, TCondensedJsonPrintPolicy<TCHAR>>::Create(&OutJsonString);

		JsonWriter->WriteArrayStart();
		for(auto &Tmp : InMysqlResult)
		{
			JsonWriter->WriteArrayStart();
			for (auto &TmpRow : Tmp.Rows)
			{
				JsonWriter->WriteObjectStart();
				{
					JsonWriter->WriteValue(TEXT("Key"), TmpRow.Key);
					JsonWriter->WriteValue(TEXT("Value"), TmpRow.Value);
				}
				JsonWriter->WriteObjectEnd();
			}
			JsonWriter->WriteArrayEnd();
		}
		JsonWriter->WriteArrayEnd();
		JsonWriter->Close();
#endif
		return !OutJsonString.IsEmpty();
	}
}