// Copyright (C) RenZhai.2020.All Rights Reserved.
#include "Request/HTTPClientRequest.h"
#include "Core/SimpleHttpMacro.h"
#include "SimpleHTTPLog.h"
#include "Core/SimpleHTTPMethod.h"

SimpleHTTP::HTTP::FPutObjectRequest::FPutObjectRequest(const FString &URL, const FString& ContentString)
{
	DEFINITION_HTTP_TYPE(PUT,"multipart/form-data;charset=utf-8")
	HttpReuest->SetContentAsString(ContentString);

	UE_LOG(LogSimpleHTTP, Log, TEXT("PUT Action as string"));
}

SimpleHTTP::HTTP::FPutObjectRequest::FPutObjectRequest(const FString &URL, TSharedRef<FArchive, ESPMode::ThreadSafe> Stream)
{
	DEFINITION_HTTP_TYPE(PUT, "multipart/form-data;charset=utf-8")
	HttpReuest->SetContentFromStream(Stream);

	UE_LOG(LogSimpleHTTP, Log, TEXT("PUT Action by stream."));
}

SimpleHTTP::HTTP::FPutObjectRequest::FPutObjectRequest(const FString &URL,const TArray<uint8>& ContentPayload)
{
	DEFINITION_HTTP_TYPE(PUT, "multipart/form-data;charset=utf-8")
	HttpReuest->SetContent(ContentPayload);

	UE_LOG(LogSimpleHTTP, Log, TEXT("PUT Action by content."));
}

//Get: get resources from the server
//Post: create a new resource on the server.
//Put: update resources on the server and provide the changed complete resources on the client
//Patch: update resources on the server and provide changed properties on the client
//Delete: delete a resource from the server.
//Head: get the metadata of the resource.
//Options: get information about which attributes of the resource can be changed by the client.

SimpleHTTP::HTTP::FGetObjectRequest::FGetObjectRequest(const FString &URL)
{
	DEFINITION_HTTP_TYPE(GET, "application/x-www-form-urlencoded;charset=utf-8")

	UE_LOG(LogSimpleHTTP, Log, TEXT("GET Action."));
}

SimpleHTTP::HTTP::FDeleteObjectsRequest::FDeleteObjectsRequest(const FString &URL)
{
	DEFINITION_HTTP_TYPE(DELETE, "application/x-www-form-urlencoded;charset=utf-8")

	UE_LOG(LogSimpleHTTP, Log, TEXT("DELETE Action."));
}

SimpleHTTP::HTTP::FPostObjectsRequest::FPostObjectsRequest(const FString &URL)
{
	DEFINITION_HTTP_TYPE(POST, "application/x-www-form-urlencoded;charset=utf-8")

	UE_LOG(LogSimpleHTTP, Log, TEXT("POST Action."));
}

SimpleHTTP::HTTP::FPostObjectsRequest::FPostObjectsRequest(const FString& URL, const FString& ContentString)
{
	DEFINITION_HTTP_TYPE(POST,"multipart/form-data;charset=utf-8")
	HttpReuest->SetContentAsString(ContentString);

	UE_LOG(LogSimpleHTTP, Log, TEXT("Post Action as string"));
}

SimpleHTTP::HTTP::FPostObjectsRequest::FPostObjectsRequest(const FString& URL, const TArray<uint8>& ContentPayload)
{
	DEFINITION_HTTP_TYPE(POST,"multipart/form-data;charset=utf-8")
	HttpReuest->SetContent(ContentPayload);

	UE_LOG(LogSimpleHTTP, Log, TEXT("Post Action as Byte"));
}

SimpleHTTP::HTTP::FObjectsRequest::FObjectsRequest(ESimpleHTTPVerbType InType, const FString& URL, const TMap<FString, FString>& InMeta, const FString& InConentData)
{
	FString InNewURLEncoded = SimpleHTTP::SimpleURLEncode(*URL);

	HttpReuest->SetURL(URL);
	HttpReuest->SetVerb(HTTPVerbToString(InType));

	for (auto &Tmp : InMeta)
	{
		HttpReuest->SetHeader(Tmp.Key, Tmp.Value);
	}

	HttpReuest->SetContentAsString(InConentData);	
}

SimpleHTTP::HTTP::FObjectsRequest::FObjectsRequest(ESimpleHTTPVerbType InType, const FString& URL, const TMap<FString, FString>& InMeta, const TArray<uint8>& InData)
{
	FString InNewURLEncoded = SimpleHTTP::SimpleURLEncode(*URL);

	HttpReuest->SetURL(InNewURLEncoded);
	HttpReuest->SetVerb(HTTPVerbToString(InType));

	for (auto& Tmp : InMeta)
	{
		HttpReuest->SetHeader(Tmp.Key, Tmp.Value);
	}

	HttpReuest->SetContent(InData);
}

FString SimpleHTTP::HTTP::HTTPVerbToString(ESimpleHTTPVerbType InVerbType)
{
	switch (InVerbType)
	{
	case ESimpleHTTPVerbType::SIMPLE_POST:
		return TEXT("POST");
	case ESimpleHTTPVerbType::SIMPLE_PUT:
		return TEXT("PUT");
	case ESimpleHTTPVerbType::SIMPLE_GET:
		return TEXT("GET");
	case ESimpleHTTPVerbType::SIMPLE_DELETE:
		return TEXT("DELETE");
	}

	return TEXT("POST");
}
