// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once
#include "OnlineBlueprintCallProxyBase.h"

#include "Core/PlayFabServerAPI.h"
#include "Core/PlayFabServerDataModels.h"
#include "Proxy/PlayFabServerBPDataModels.h"
#include "PFServerGrantItemsToUsers.generated.h"

UCLASS()
class PLAYFABPROXY_API UPFServerGrantItemsToUsers : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FBPServerGrantItemsToUsersResultDelegate OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FBPServerGrantItemsToUsersResultDelegate OnFailure;
	
	// Adds the specified items to the specified user inventories
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "PlayFab|Server|Player Item Management")
	static UPFServerGrantItemsToUsers* GrantItemsToUsers(UObject* WorldContextObject, class APlayerController* PlayerController, const FString& InCatalogVersion, const TArray<FBPServerItemGrant>& InItemGrants);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;
	// End of UOnlineBlueprintCallProxyBase interface

private:

	PlayFab::ServerModels::FGrantItemsToUsersRequest Request;

	PlayFab::UPlayFabServerAPI::FGrantItemsToUsersDelegate	SuccessDelegate;
	PlayFab::FPlayFabErrorDelegate							ErrorDelegate;

	void OnSuccessCallback(const PlayFab::ServerModels::FGrantItemsToUsersResult& Result);
	void OnErrorCallback(const PlayFab::FPlayFabError& Error);
};