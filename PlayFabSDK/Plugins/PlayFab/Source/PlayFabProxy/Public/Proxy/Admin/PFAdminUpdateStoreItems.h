// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once
#include "OnlineBlueprintCallProxyBase.h"

#include "Core/PlayFabAdminAPI.h"
#include "Core/PlayFabAdminDataModels.h"
#include "Proxy/PlayFabAdminBPDataModels.h"
#include "PFAdminUpdateStoreItems.generated.h"

UCLASS()
class PLAYFABPROXY_API UPFAdminUpdateStoreItems : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FEmptyOnlineDelegate OnSuccess; 

	UPROPERTY(BlueprintAssignable)
	FEmptyOnlineDelegate OnFailure; 
	
	// Updates an existing virtual item store with new or modified items
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "PlayFab|Admin|Title-Wide Data Management")
	static UPFAdminUpdateStoreItems* UpdateStoreItems(UObject* WorldContextObject, class APlayerController* PlayerController, const FString& InCatalogVersion, const FString& InStoreId, const TArray<FBPAdminStoreItem>& InStore);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;
	// End of UOnlineBlueprintCallProxyBase interface

private:

	PlayFab::AdminModels::FUpdateStoreItemsRequest Request;

	PlayFab::UPlayFabAdminAPI::FUpdateStoreItemsDelegate	SuccessDelegate;
	PlayFab::FPlayFabErrorDelegate							ErrorDelegate;

	void OnSuccessCallback(const PlayFab::AdminModels::FUpdateStoreItemsResult& Result);
	void OnErrorCallback(const PlayFab::FPlayFabError& Error);
};
