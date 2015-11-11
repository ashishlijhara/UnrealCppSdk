// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once
#include "OnlineBlueprintCallProxyBase.h"

#include "Core/PlayFabAdminAPI.h"
#include "Core/PlayFabAdminDataModels.h"
#include "Proxy/PlayFabAdminBPDataModels.h"
#include "PFAdminGetStoreItems.generated.h"

UCLASS()
class PLAYFABPROXY_API UPFAdminGetStoreItems : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FBPAdminGetStoreItemsResultDelegate OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FBPAdminGetStoreItemsResultDelegate OnFailure;
	
	// Retrieves the set of items defined for the specified store, including all prices defined
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "PlayFab|Admin|Title-Wide Data Management")
	static UPFAdminGetStoreItems* GetStoreItems(UObject* WorldContextObject, class APlayerController* PlayerController, const FString& InCatalogVersion, const FString& InStoreId);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;
	// End of UOnlineBlueprintCallProxyBase interface

private:

	PlayFab::AdminModels::FGetStoreItemsRequest Request;

	PlayFab::UPlayFabAdminAPI::FGetStoreItemsDelegate	SuccessDelegate;
	PlayFab::FPlayFabErrorDelegate							ErrorDelegate;

	void OnSuccessCallback(const PlayFab::AdminModels::FGetStoreItemsResult& Result);
	void OnErrorCallback(const PlayFab::FPlayFabError& Error);
};