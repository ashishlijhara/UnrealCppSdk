// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PFAdminRemoveServerBuild.h"

UPFAdminRemoveServerBuild::UPFAdminRemoveServerBuild(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabAdminAPI::FRemoveServerBuildDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFAdminRemoveServerBuild* UPFAdminRemoveServerBuild::RemoveServerBuild(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InBuildId)
{
	UPFAdminRemoveServerBuild* Proxy = NewObject<UPFAdminRemoveServerBuild>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.BuildId = InBuildId;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFAdminRemoveServerBuild::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

	bool CallResult = false;

	if(AdminAPI.IsValid())
	{	
		CallResult = AdminAPI->RemoveServerBuild(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		OnFailure.Broadcast();
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFAdminRemoveServerBuild::OnSuccessCallback(const PlayFab::AdminModels::FRemoveServerBuildResult& Result)
{
	OnSuccess.Broadcast();
}

void UPFAdminRemoveServerBuild::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	OnFailure.Broadcast();	
}
