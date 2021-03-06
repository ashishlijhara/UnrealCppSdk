// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once
#include "OnlineBlueprintCallProxyBase.h"

#include "Core/PlayFabAdminAPI.h"
#include "Core/PlayFabAdminDataModels.h"
#include "Proxy/PlayFabAdminBPDataModels.h"
#include "PFAdminGetPublisherData.generated.h"

UCLASS()
class PLAYFABPROXY_API UPFAdminGetPublisherData : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FBPAdminGetPublisherDataResultDelegate OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FBPAdminGetPublisherDataResultDelegate OnFailure;
	
	// Retrieves the key-value store of custom publisher settings
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "PlayFab|Admin|Shared Group Data")
	static UPFAdminGetPublisherData* GetPublisherData(UObject* WorldContextObject, class APlayerController* PlayerController, const TArray<FString>& InKeys);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;
	// End of UOnlineBlueprintCallProxyBase interface

private:

	PlayFab::AdminModels::FGetPublisherDataRequest Request;

	PlayFab::UPlayFabAdminAPI::FGetPublisherDataDelegate	SuccessDelegate;
	PlayFab::FPlayFabErrorDelegate							ErrorDelegate;

	void OnSuccessCallback(const PlayFab::AdminModels::FGetPublisherDataResult& Result);
	void OnErrorCallback(const PlayFab::FPlayFabError& Error);
};
