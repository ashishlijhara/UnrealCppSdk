// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PFClientUnlinkSteamAccount.h"

UPFClientUnlinkSteamAccount::UPFClientUnlinkSteamAccount(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabClientAPI::FUnlinkSteamAccountDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFClientUnlinkSteamAccount* UPFClientUnlinkSteamAccount::UnlinkSteamAccount(UObject* WorldContextObject, class APlayerController* PlayerController )
{
	UPFClientUnlinkSteamAccount* Proxy = NewObject<UPFClientUnlinkSteamAccount>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFClientUnlinkSteamAccount::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

	bool CallResult = false;

	if(ClientAPI.IsValid())
	{	
		CallResult = ClientAPI->UnlinkSteamAccount(SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		OnFailure.Broadcast();
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFClientUnlinkSteamAccount::OnSuccessCallback(const PlayFab::ClientModels::FUnlinkSteamAccountResult& Result)
{
	OnSuccess.Broadcast();
}

void UPFClientUnlinkSteamAccount::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	OnFailure.Broadcast();	
}