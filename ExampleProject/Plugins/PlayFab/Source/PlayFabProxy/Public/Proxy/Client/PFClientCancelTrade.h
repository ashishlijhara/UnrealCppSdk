// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once
#include "OnlineBlueprintCallProxyBase.h"

#include "Core/PlayFabClientAPI.h"
#include "Core/PlayFabClientDataModels.h"
#include "Proxy/PlayFabClientBPDataModels.h"
#include "PFClientCancelTrade.generated.h"

UCLASS()
class PLAYFABPROXY_API UPFClientCancelTrade : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FBPClientCancelTradeResponseDelegate OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FBPClientCancelTradeResponseDelegate OnFailure;
	
	// Cancels an open trade.
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "PlayFab|Client|Trading")
	static UPFClientCancelTrade* CancelTrade(UObject* WorldContextObject, class APlayerController* PlayerController, const FString& InTradeId);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;
	// End of UOnlineBlueprintCallProxyBase interface

private:

	PlayFab::ClientModels::FCancelTradeRequest Request;

	PlayFab::UPlayFabClientAPI::FCancelTradeDelegate	SuccessDelegate;
	PlayFab::FPlayFabErrorDelegate							ErrorDelegate;

	void OnSuccessCallback(const PlayFab::ClientModels::FCancelTradeResponse& Result);
	void OnErrorCallback(const PlayFab::FPlayFabError& Error);
};
