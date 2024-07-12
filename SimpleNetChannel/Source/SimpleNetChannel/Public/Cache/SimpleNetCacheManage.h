// Copyright (C) RenZhai.2021.All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

//主要针对缓存，比如服务器客户端发过来的一段段散包，当数量达到要求，会合成一个整包，这个函数是散包缓存
class SIMPLENETCHANNEL_API FSimpleNetCacheManage
{
public:
	FSimpleNetCacheManage();

public:
	struct FCache
	{
		FCache();

		uint32 TotalSize;
		TArray<uint8> Cache;

		void Reset();
	};

public:
	FSimpleNetCacheManage::FCache& operator[](const FGuid &InGuid)
	{
		return Caches[InGuid];
	}

public:
	void Add(const FGuid &InGuid,const FSimpleNetCacheManage::FCache &InCache);
	FSimpleNetCacheManage::FCache* Find(const FGuid& InGuid);
	void Remove(const FGuid& InGuid);
	void Reset();

protected:
	TMap<FGuid, FCache> Caches;
	FCriticalSection CachesReadWrite;//针对缓存锁 
};