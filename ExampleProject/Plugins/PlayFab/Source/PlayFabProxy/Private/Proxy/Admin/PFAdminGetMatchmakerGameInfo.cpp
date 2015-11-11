// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PFAdminGetMatchmakerGameInfo.h"

UPFAdminGetMatchmakerGameInfo::UPFAdminGetMatchmakerGameInfo(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabAdminAPI::FGetMatchmakerGameInfoDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFAdminGetMatchmakerGameInfo* UPFAdminGetMatchmakerGameInfo::GetMatchmakerGameInfo(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InLobbyId)
{
	UPFAdminGetMatchmakerGameInfo* Proxy = NewObject<UPFAdminGetMatchmakerGameInfo>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.LobbyId = InLobbyId;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFAdminGetMatchmakerGameInfo::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

	bool CallResult = false;

	if(AdminAPI.IsValid())
	{	
		CallResult = AdminAPI->GetMatchmakerGameInfo(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPAdminGetMatchmakerGameInfoResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFAdminGetMatchmakerGameInfo::OnSuccessCallback(const PlayFab::AdminModels::FGetMatchmakerGameInfoResult& Result)
{
	FBPAdminGetMatchmakerGameInfoResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFAdminGetMatchmakerGameInfo::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPAdminGetMatchmakerGameInfoResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}