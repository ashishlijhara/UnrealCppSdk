// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once
#include "OnlineBlueprintCallProxyBase.h"

#include "Core/PlayFabServerAPI.h"
#include "Core/PlayFabServerDataModels.h"
#include "Proxy/PlayFabServerBPDataModels.h"
#include "PFServerSubtractUserVirtualCurrency.generated.h"

UCLASS()
class PLAYFABPROXY_API UPFServerSubtractUserVirtualCurrency : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FBPServerModifyUserVirtualCurrencyResultDelegate OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FBPServerModifyUserVirtualCurrencyResultDelegate OnFailure;
	
	// Decrements the user's balance of the specified virtual currency by the stated amount
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "PlayFab|Server|Player Item Management")
	static UPFServerSubtractUserVirtualCurrency* SubtractUserVirtualCurrency(UObject* WorldContextObject, class APlayerController* PlayerController, const FString& InPlayFabId, const FString& InVirtualCurrency, const int32& InAmount);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;
	// End of UOnlineBlueprintCallProxyBase interface

private:

	PlayFab::ServerModels::FSubtractUserVirtualCurrencyRequest Request;

	PlayFab::UPlayFabServerAPI::FSubtractUserVirtualCurrencyDelegate	SuccessDelegate;
	PlayFab::FPlayFabErrorDelegate							ErrorDelegate;

	void OnSuccessCallback(const PlayFab::ServerModels::FModifyUserVirtualCurrencyResult& Result);
	void OnErrorCallback(const PlayFab::FPlayFabError& Error);
};
