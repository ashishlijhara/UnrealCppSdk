// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once
#include "OnlineBlueprintCallProxyBase.h"

#include "Core/PlayFabAdminAPI.h"
#include "Core/PlayFabAdminDataModels.h"
#include "Proxy/PlayFabAdminBPDataModels.h"
#include "PFAdminSetTitleData.generated.h"

UCLASS()
class PLAYFABPROXY_API UPFAdminSetTitleData : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FEmptyOnlineDelegate OnSuccess; 

	UPROPERTY(BlueprintAssignable)
	FEmptyOnlineDelegate OnFailure; 
	
	// Creates and updates the key-value store of custom title settings
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "PlayFab|Admin|Title-Wide Data Management")
	static UPFAdminSetTitleData* SetTitleData(UObject* WorldContextObject, class APlayerController* PlayerController, const FString& InKey, const FString& InValue);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;
	// End of UOnlineBlueprintCallProxyBase interface

private:

	PlayFab::AdminModels::FSetTitleDataRequest Request;

	PlayFab::UPlayFabAdminAPI::FSetTitleDataDelegate	SuccessDelegate;
	PlayFab::FPlayFabErrorDelegate							ErrorDelegate;

	void OnSuccessCallback(const PlayFab::AdminModels::FSetTitleDataResult& Result);
	void OnErrorCallback(const PlayFab::FPlayFabError& Error);
};