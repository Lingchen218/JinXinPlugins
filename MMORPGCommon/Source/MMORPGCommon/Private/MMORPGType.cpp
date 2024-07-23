#include "MMORPGType.h"
#include "Json.h"

namespace NetDataAnalysis
{
	void UserDataToString(const FMMORPGUserData& InUserData, FString& OutString)
	{
		OutString.Empty();

		TSharedRef<TJsonWriter<TCHAR, TCondensedJsonPrintPolicy<TCHAR>>> Writer = TJsonWriterFactory<TCHAR, TCondensedJsonPrintPolicy<TCHAR>>::Create(&OutString);

		Writer->WriteObjectStart();
		{
			Writer->WriteValue(TEXT("ID"), InUserData.ID);
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
				OutUserData.ID = InJsonObject->GetIntegerField(TEXT("ID"));
				OutUserData.Account = InJsonObject->GetStringField(TEXT("Account"));
				OutUserData.Email = InJsonObject->GetStringField(TEXT("Email"));
				OutUserData.Name = InJsonObject->GetStringField(TEXT("Name"));
				OutUserData.HeadPortraitURL = InJsonObject->GetStringField(TEXT("HeadPortraitURL"));
			}
		}
	}

	void CharacterAppearacnceToString(const FCharacterAppearacnce& InCA, FString& OutString)
	{
		OutString.Empty();

		TSharedRef<TJsonWriter<TCHAR, TCondensedJsonPrintPolicy<TCHAR>>> Writer = TJsonWriterFactory<TCHAR, TCondensedJsonPrintPolicy<TCHAR>>::Create(&OutString);

		Writer->WriteArrayStart();
		for (auto& Temp : InCA)
		{
			Writer->WriteObjectStart();
			Writer->WriteValue(TEXT("Name"), Temp.Name);
			Writer->WriteValue(TEXT("Date"), Temp.Date);
			Writer->WriteValue(TEXT("Lv"), Temp.Lv);
			Writer->WriteValue(TEXT("SlotPosition"), Temp.SlotPosition);
			Writer->WriteValue(TEXT("LegSize"), Temp.LegSize);
			Writer->WriteValue(TEXT("WaistSize"), Temp.WaistSize);
			Writer->WriteValue(TEXT("ArmSize"), Temp.ArmSize);
			Writer->WriteValue(TEXT("HeadSize"), Temp.HeadSize);
			Writer->WriteValue(TEXT("ChestSize"), Temp.ChestSize);
			Writer->WriteObjectEnd();
		}
		Writer->WriteArrayEnd();
		Writer->Close();
	}

	void StringToFCharacterAppearacnce(const FString& InString, FCharacterAppearacnce& OutCA)
	{
		TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(InString);
		TArray<TSharedPtr<FJsonValue>> ReadRoot;

		if (FJsonSerializer::Deserialize(Reader, ReadRoot))
		{
			for (auto& Temp : ReadRoot)
			{
				OutCA.Add(FMMORPGCharacterAppearance());
				FMMORPGCharacterAppearance& InCA = OutCA.Last();
				if (TSharedPtr<FJsonObject> InJsonObject = Temp->AsObject())
				{
					InCA.Name = InJsonObject->GetStringField(TEXT("Name"));
					InCA.Date = InJsonObject->GetStringField(TEXT("Date"));
					InCA.Lv = InJsonObject->GetIntegerField(TEXT("Lv"));
					InCA.SlotPosition = InJsonObject->GetIntegerField(TEXT("SlotPosition"));
					InCA.LegSize = InJsonObject->GetNumberField(TEXT("LegSize"));
					InCA.WaistSize = InJsonObject->GetNumberField(TEXT("WaistSize"));
					InCA.ArmSize = InJsonObject->GetNumberField(TEXT("ArmSize"));
					InCA.HeadSize = InJsonObject->GetNumberField(TEXT("HeadSize"));
					InCA.ChestSize = InJsonObject->GetNumberField(TEXT("ChestSize"));
				}
			}
		}
	}

	void CharacterAppearacnceToString(const FMMORPGCharacterAppearance& InCA, FString& OutString)
	{
		OutString.Empty();

		TSharedRef<TJsonWriter<TCHAR, TCondensedJsonPrintPolicy<TCHAR>>> Writer = TJsonWriterFactory<TCHAR, TCondensedJsonPrintPolicy<TCHAR>>::Create(&OutString);

		Writer->WriteObjectStart();
		Writer->WriteValue(TEXT("Name"), InCA.Name);
		Writer->WriteValue(TEXT("Date"), InCA.Date);
		Writer->WriteValue(TEXT("Lv"), InCA.Lv);
		Writer->WriteValue(TEXT("SlotPosition"), InCA.SlotPosition);
		Writer->WriteValue(TEXT("LegSize"), InCA.LegSize);
		Writer->WriteValue(TEXT("WaistSize"), InCA.WaistSize);
		Writer->WriteValue(TEXT("ArmSize"), InCA.ArmSize);
		Writer->WriteValue(TEXT("HeadSize"), InCA.HeadSize);
		Writer->WriteValue(TEXT("ChestSize"), InCA.ChestSize);

		Writer->WriteObjectEnd();
		Writer->Close();
	}

	void StringToFCharacterAppearacnce(const FString& InString, FMMORPGCharacterAppearance& OutCA)
	{
		TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(InString);
		TSharedPtr<FJsonValue> ReadRoot;

		if (FJsonSerializer::Deserialize(Reader, ReadRoot))
		{
			if (TSharedPtr<FJsonObject> InJsonObject = ReadRoot->AsObject())//转换成对象
			{
				OutCA.Name = InJsonObject->GetStringField(TEXT("Name"));
				OutCA.Date = InJsonObject->GetStringField(TEXT("Date"));
				OutCA.Lv = InJsonObject->GetIntegerField(TEXT("Lv"));
				OutCA.SlotPosition = InJsonObject->GetIntegerField(TEXT("SlotPosition"));
				OutCA.LegSize = InJsonObject->GetNumberField(TEXT("LegSize"));
				OutCA.WaistSize = InJsonObject->GetNumberField(TEXT("WaistSize"));
				OutCA.ArmSize = InJsonObject->GetNumberField(TEXT("ArmSize"));
				OutCA.ArmSize = InJsonObject->GetNumberField(TEXT("HeadSize"));
				OutCA.ArmSize = InJsonObject->GetNumberField(TEXT("ChestSize"));
			}
		}
	}

}

void FMMORPGCharacterAppearance::Reset()
{
	Name.Empty();
	Date.Empty();
	Lv = INDEX_NONE;
	SlotPosition = INDEX_NONE;
	LegSize = 0.f;
	WaistSize = 0.f;
	ArmSize = 0.f;
	HeadSize = 0.f;
	ChestSize = 0.f;
}
