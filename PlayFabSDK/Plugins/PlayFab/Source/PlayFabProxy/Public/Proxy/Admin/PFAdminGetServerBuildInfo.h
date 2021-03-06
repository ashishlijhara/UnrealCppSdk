// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once
#include "OnlineBlueprintCallProxyBase.h"

#include "Core/PlayFabAdminAPI.h"
#include "Core/PlayFabAdminDataModels.h"
#include "Proxy/PlayFabAdminBPDataModels.h"
#include "PFAdminGetServerBuildInfo.generated.h"

UCLASS()
class PLAYFABPROXY_API UPFAdminGetServerBuildInfo : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FBPAdminGetServerBuildInfoResultDelegate OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FBPAdminGetServerBuildInfoResultDelegate OnFailure;
	
	// Retrieves the build details for the specified game server executable
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "PlayFab|Admin|Custom Server Management")
	static UPFAdminGetServerBuildInfo* GetServerBuildInfo(UObject* WorldContextObject, class APlayerController* PlayerController, const FString& InBuildId);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;
	// End of UOnlineBlueprintCallProxyBase interface

private:

	PlayFab::AdminModels::FGetServerBuildInfoRequest Request;

	PlayFab::UPlayFabAdminAPI::FGetServerBuildInfoDelegate	SuccessDelegate;
	PlayFab::FPlayFabErrorDelegate							ErrorDelegate;

	void OnSuccessCallback(const PlayFab::AdminModels::FGetServerBuildInfoResult& Result);
	void OnErrorCallback(const PlayFab::FPlayFabError& Error);
};
