#include "MMORPGType.h"
#include "Json.h"

namespace NetDataAnalysis
{
	void UserDataToString(const FMMORPGUserData& InUserData, FString& OutString)
	{
		TSharedRef<TJsonWriter<TCHAR, TCondensedJsonPrintPolicy<TCHAR>>> Writer = TJsonWriterFactory<TCHAR, TCondensedJsonPrintPolicy<TCHAR>>::Create(&OutString);

		Writer->WriteObjectStart();
		{
			Writer->WriteValue(TEXT("ID"), *FString::FromInt(InUserData.ID));
			Writer->WriteValue(TEXT("Account"), *InUserData.Account);
			Writer->WriteValue(TEXT("Email"), *InUserData.Email);
			Writer->WriteValue(TEXT("Name"), *InUserData.Name);
			Writer->WriteValue(TEXT("HeadPortraitURL"), *InUserData.HeadPortraitURL);
		}
		Writer->WriteObjectEnd();
		Writer->Close();
	}

	void StringToUserData(const FString& InString, FMMORPGUserData& OutUserData)
	{
		TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(InString);
		TSharedPtr<FJsonValue> ReadRoot;

		if (FJsonSerializer::Deserialize(Reader, ReadRoot))
		{
			if (TSharedPtr<FJsonObject> InJsonObject = ReadRoot->AsObject())//转换成对象
			{
				OutUserData.ID = FCString::Atoi(*InJsonObject->GetStringField(TEXT("ID")));
				OutUserData.Account = InJsonObject->GetStringField(TEXT("Account"));
				OutUserData.Email = InJsonObject->GetStringField(TEXT("Email"));
				OutUserData.Name = InJsonObject->GetStringField(TEXT("Name"));
				OutUserData.HeadPortraitURL = InJsonObject->GetStringField(TEXT("HeadPortraitURL"));
			}
		}
	}
}