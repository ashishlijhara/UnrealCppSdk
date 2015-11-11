// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once
#include "OnlineBlueprintCallProxyBase.h"

#include "Core/PlayFabServerAPI.h"
#include "Core/PlayFabServerDataModels.h"
#include "Proxy/PlayFabServerBPDataModels.h"
#include "PFServerAuthenticateSessionTicket.generated.h"

UCLASS()
class PLAYFABPROXY_API UPFServerAuthenticateSessionTicket : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FBPServerAuthenticateSessionTicketResultDelegate OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FBPServerAuthenticateSessionTicketResultDelegate OnFailure;
	
	// Validated a client's session ticket, and if successful, returns details for that user
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "PlayFab|Server|Authentication")
	static UPFServerAuthenticateSessionTicket* AuthenticateSessionTicket(UObject* WorldContextObject, class APlayerController* PlayerController, const FString& InSessionTicket);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;
	// End of UOnlineBlueprintCallProxyBase interface

private:

	PlayFab::ServerModels::FAuthenticateSessionTicketRequest Request;

	PlayFab::UPlayFabServerAPI::FAuthenticateSessionTicketDelegate	SuccessDelegate;
	PlayFab::FPlayFabErrorDelegate							ErrorDelegate;

	void OnSuccessCallback(const PlayFab::ServerModels::FAuthenticateSessionTicketResult& Result);
	void OnErrorCallback(const PlayFab::FPlayFabError& Error);
};