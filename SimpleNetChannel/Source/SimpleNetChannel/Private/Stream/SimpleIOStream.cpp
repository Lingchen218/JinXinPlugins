// Copyright (C) RenZhai.2021.All Rights Reserved.

#include "Stream/SimpleIOStream.h"
#include "Log/SimpleNetChannelLog.h"
#include <string>

#if PLATFORM_WINDOWS
#pragma optimize("",off) 
#endif

FSimpleIOStream::FSimpleIOStream(TArray<uint8>& InBuffer)
:Buffer(InBuffer)
, Ptr(InBuffer.GetData())
{}

void FSimpleIOStream::Wirte(void* InData, int64 InLength)
{
	int32 StartPos = Buffer.AddUninitialized(InLength);
	FMemory::Memcpy(&Buffer[StartPos], InData, InLength);
}

void FSimpleIOStream::Seek(int32 InPos)
{
	if (!Ptr)
	{
		Ptr = Buffer.GetData();
	}

	Ptr += InPos;
}

FSimpleIOStream& FSimpleIOStream::operator<<(FString& InValue)
{
	//字节砍半 有bug 强行将字节压缩到 125的范围 导致大于这个范围的字符出现 ??? 乱码
	/*std::string StrBuffer = TCHAR_TO_UTF8(*InValue);

	FSimpleIOStream& Stream = *this;
	int32 Num = InValue.GetCharArray().Num();
	Stream << Num;

	if (Num > 0)
	{
		Wirte((void*)StrBuffer.c_str(), sizeof(char) * Num);
	}*/

	*this << InValue.GetCharArray();

	return *this;
}

FSimpleIOStream& FSimpleIOStream::operator>>(FString& InValue)
{
	*this >> InValue.GetCharArray();

	//FSimpleIOStream& Stream = *this;
	//int32 Num = 0;
	//Stream >> Num;

	/*if (Num > 0)
	{
		int32 InLength = sizeof(char) * Num;
		if (InLength > 0)
		{
			std::string StrBuffer;
			StrBuffer.reserve(InLength);
			StrBuffer = Ptr;
			FMemory::Memcpy((void*)StrBuffer.c_str(), Ptr, strlen(Ptr));

			InValue = UTF8_TO_TCHAR(StrBuffer.c_str());

			Seek(InLength);
		}
	}*/

	return *this;
}

uint8* FSimpleIOStream::Begin()
{
	Ptr = Buffer.GetData();
	return Ptr;
}

uint8* FSimpleIOStream::End()
{
	Begin();
	Ptr += Buffer.Num();
	return Ptr;
}

uint8* FSimpleIOStream::Tall()
{
	return Ptr;
}

void FSimpleIOStream::PrintMsg(const FString& InString)
{
	UE_LOG(LogSimpleNetChannel, Error, TEXT("%s"),*InString);
}

#if PLATFORM_WINDOWS
#pragma optimize("",on) 
#endif