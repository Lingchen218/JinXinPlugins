#include "Cache/SimpleNetCacheManage.h"
#include "Misc/ScopeLock.h"

FSimpleNetCacheManage::FSimpleNetCacheManage()
{

}

void FSimpleNetCacheManage::Add(const FGuid& InGuid, const FSimpleNetCacheManage::FCache& InCache)
{
	FScopeLock ScopeLock(&CachesReadWrite);

	Caches.Add(InGuid, InCache);
}

FSimpleNetCacheManage::FCache* FSimpleNetCacheManage::Find(const FGuid& InGuid)
{
	FScopeLock ScopeLock(&CachesReadWrite);
	FSimpleNetCacheManage::FCache* InCaches = nullptr;

	InCaches = Caches.Find(InGuid);

	return InCaches;
}

void FSimpleNetCacheManage::Remove(const FGuid& InGuid)
{
	FScopeLock ScopeLock(&CachesReadWrite);

	Caches.Remove(InGuid);
}

void FSimpleNetCacheManage::Reset()
{
	FScopeLock ScopeLock(&CachesReadWrite);

	Caches.Empty();
}

FSimpleNetCacheManage::FCache::FCache()
{
	Reset();
}

void FSimpleNetCacheManage::FCache::Reset()
{
	TotalSize = 0;
	Cache.Empty();
}