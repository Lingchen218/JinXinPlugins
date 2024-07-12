// Copyright (C) RenZhai.2021.All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#if PLATFORM_WINDOWS
#pragma optimize("",off) 
#endif

class SIMPLENETCHANNEL_API FSimpleIOStream
{
public:
	TArray<uint8>& Buffer;

public:
	FSimpleIOStream(TArray<uint8>& InBuffer);

public:

	template<class T>
	FSimpleIOStream& operator<<(T &InValue)
	{
		Wirte((void*)&InValue, sizeof(T));
		return *this;
	}

	template<class T>
	FSimpleIOStream& operator<<(TArray<T>& InValue)
	{
		FSimpleIOStream& Stream = *this;
		int32 Num = InValue.Num();
		Stream << Num;

		if (Num > 0)
		{
			Wirte(InValue.GetData(), sizeof(T) * Num);
		}

		return *this;
	}

	template<class Key,class Value>
	FSimpleIOStream& operator<<(TMap<Key,Value>& InValue)
	{
		FSimpleIOStream& Stream = *this;
		int32 Num = InValue.Num();
		Stream << Num;

		for (auto &Tmp: InValue)
		{
			Stream << Tmp.Key;
			Stream << Tmp.Value;
		}

		return *this;
	}

	template<class T>
	FSimpleIOStream& operator<<(TArray<TArray<T>>& InValue)
	{
		FSimpleIOStream& Stream = *this;
		int32 Num = InValue.Num();
		Stream << Num;

		if (Num > 0)
		{
			for (auto &Tmp : InValue)
			{
				Stream << Tmp;
			}
		}

		return *this;
	}

	FSimpleIOStream& operator<<(TArray<FString>& InValue)
	{
		FSimpleIOStream& Stream = *this;
		int32 Num = InValue.Num();
		Stream << Num;

		for (int32 i = 0; i < Num; i++)
		{
			Stream << InValue[i];
		}

		return *this;
	}

	FSimpleIOStream& operator<<(FString& InValue);

public:

	template<class T>
	FSimpleIOStream& operator>>(T& InValue)
	{
		Read<T>(InValue);
		return *this;
	}

	template<class T>
	FSimpleIOStream& operator>>(TArray<T>& InValue)
	{
		FSimpleIOStream& Stream = *this;
		int32 Num = 0;
		Stream >> Num; 

		if (Num >= 1753880896)
		{
			PrintMsg(TEXT("Value = 1753880896"));
		}
		else if (Num > 0)
		{
			int32 InLength = sizeof(T) * Num;
			if (InLength > 0)
			{
				InValue.AddUninitialized(Num);

				FMemory::Memcpy(InValue.GetData(), Ptr, InLength);

				Seek(InLength);
			}
		}

		return *this;
	}

	template<class T>
	FSimpleIOStream& operator>>(TArray<TArray<T>>& InValue)
	{
		FSimpleIOStream& Stream = *this;
		int32 Num = 0;
		Stream >> Num; 

		if (Num >= 1753880896)
		{
			PrintMsg(TEXT("Value = 1753880896"));
		}
		else if (Num > 0)
		{
			for (int32 i = 0 ;i < Num ;i++)
			{
				TArray<T> &InValueArray = InValue.AddDefaulted_GetRef();
				Stream >> InValueArray;
			}
		}

		return *this;
	}

	template<class Key, class Value>
	FSimpleIOStream& operator>>(TMap<Key,Value>& InValue)
	{
		FSimpleIOStream& Stream = *this;
		int32 Num = 0;
		Stream >> Num;

		if (Num > 0)
		{
			for (int32 i = 0; i < Num; i++)
			{
				Key InKey;
				Stream >> InKey;

				Value& InOtherValue = InValue.Add(InKey);

				Stream >> InOtherValue;
			}
		}
	
		return *this;
	}

	FSimpleIOStream& operator>>(TArray<FString>& InValue)
	{
		FSimpleIOStream& Stream = *this;
		int32 Num = 0;
		Stream >> Num;

		if (Num >= 1753880896)
		{
			PrintMsg(TEXT("Value = 1753880896"));
		}
		else if (Num > 0)
		{
			for (int32 i = 0; i < Num; i++)
			{
				InValue.Add(FString());
				FString& MyString = InValue.Last();

				Stream >> MyString;
			}
		}

		return *this;
	}

	FSimpleIOStream& operator>>(FString& InValue);

private:
	void Wirte(void* InData, int64 InLength);

	template<class T>
	void Read(T &InValue)
	{
		Seek(0);//

		InValue = *(T*)Ptr;
		Seek(sizeof(T));
	}

public:
	void Seek(int32 InPos = 1);

	uint8* Begin();
	uint8* End();
	uint8* Tall();

private:
	void PrintMsg(const FString& InString);

private:
	uint8* Ptr;
};

#if PLATFORM_WINDOWS
#pragma optimize("",on) 
#endif