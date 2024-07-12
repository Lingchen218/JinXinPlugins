// Copyright (C) RenZhai.2020.All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"
#include "HTTP/Core/SimpleHttpActionRequest.h"
#include "SimpleHTTPType.h"
#include "Request/RequestInterface.h"

/**
 * 
 */
class SIMPLEHTTP_API FSimpleHttpActionRequest :public TSharedFromThis<FSimpleHttpActionRequest>
{
public:
	typedef FSimpleHttpActionRequest Super;

	//BP
	FSimpleHttpSingleRequestCompleteDelegate			SimpleHttpRequestCompleteDelegate;
	FSimpleHttpSingleRequestProgressDelegate			SimpleHttpRequestProgressDelegate;
	FSimpleHttpSingleRequestHeaderReceivedDelegate		SimpleHttpRequestHeaderReceivedDelegate;
	FAllRequestCompleteDelegate							AllRequestCompleteDelegate;

	//C++
	FSimpleSingleCompleteDelegate						SimpleCompleteDelegate;
	FSimpleSingleRequestProgressDelegate				SimpleSingleRequestProgressDelegate;
	FSimpleSingleRequestHeaderReceivedDelegate			SimpleSingleRequestHeaderReceivedDelegate;
	FSimpleDelegate										AllTasksCompletedDelegate;

public:
	FSimpleHttpActionRequest();
	virtual ~FSimpleHttpActionRequest();

	virtual bool Suspend();
	virtual bool Cancel();

	virtual bool SendRequest(ESimpleHTTPVerbType InType, const FString& URL, const TMap<FString, FString>& InMeta, const FString& InConentData);
	virtual bool SendRequest(ESimpleHTTPVerbType InType, const FString& URL, const TMap<FString, FString>& InMeta, const TArray<uint8>& InData);

	//Compatibility blueprint
	virtual void GetObjects(const TArray<FString> &URL, const FString &SavePaths);
	virtual void GetObjects(const TArray<FString> &URL);
	virtual void DeleteObjects(const TArray<FString> &URL);

	virtual bool GetObject(const FString &URL);
	virtual bool GetObject(const FString &URL, const FString &SavePaths);
	virtual bool PutObject(const FString &URL, const TArray<uint8> &Data);
	virtual bool PutObject(const FString &URL, const FString &LocalPaths);
	virtual bool PutObjectByString(const FString& URL, const FString& InBuff);
	virtual bool PutObject(const FString &URL, TSharedRef<FArchive, ESPMode::ThreadSafe> Stream);
	virtual bool DeleteObject(const FString &URL);
	virtual bool PostObject(const FString &URL);
	virtual bool PostObject(const FString& URL, const FString& LocalPaths);
	virtual bool PostObject(const FString& URL, const TArray<uint8>& Data);

	FORCEINLINE FString GetPaths() { return TmpSavePaths; }
	FORCEINLINE void SetPaths(const FString &NewPaths) { TmpSavePaths = NewPaths; }
	FORCEINLINE bool IsRequestComplete() { return bRequestComplete; }

	FORCEINLINE void SetAsynchronousState(bool bNewAsy) { bAsynchronous = bNewAsy; }

protected:
	virtual void HttpRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully);
	virtual void HttpRequestProgress(FHttpRequestPtr Request, int32 BytesSent, int32 BytesReceived);
	virtual void HttpRequestProgress64(FHttpRequestPtr Request, uint64 BytesSent, uint64 BytesReceived);
	virtual void HttpRequestHeaderReceived(FHttpRequestPtr Request, const FString& HeaderName, const FString& NewHeaderValue);

	void Print(const FString &Msg, float Time = 10.f, FColor Color = FColor::Red);

protected:
	void RequestPtrToSimpleRequest(FHttpRequestPtr Request, FSimpleHttpRequest& SimpleHttpRequest);
	void ResponsePtrToSimpleResponse(FHttpResponsePtr Response, FSimpleHttpResponse& SimpleHttpResponse);

protected:
	virtual void ExecutionCompleteDelegate(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully);

protected:
	FString						TmpSavePaths;
	bool						bRequestComplete;
	bool						bSaveDisk;
	bool						bAsynchronous;
};
