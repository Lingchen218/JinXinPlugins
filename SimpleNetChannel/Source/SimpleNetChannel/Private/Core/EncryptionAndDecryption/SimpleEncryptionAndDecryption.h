// Copyright (C) RenZhai.2021.All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Global/SimpleNetGlobalInfo.h"

namespace SimpleEncryptionAndDecryption
{
	void Encryption(TArray<uint8>& InData);
	void Decryption(uint8* InData, int32 InLen);
	void Decryption(TArray<uint8>& InData);
}
