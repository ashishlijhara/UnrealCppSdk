// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PFServerMoveItemToUserFromCharacter.h"

UPFServerMoveItemToUserFromCharacter::UPFServerMoveItemToUserFromCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabServerAPI::FMoveItemToUserFromCharacterDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFServerMoveItemToUserFromCharacter* UPFServerMoveItemToUserFromCharacter::MoveItemToUserFromCharacter(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InPlayFabId, const FString& InCharacterId, const FString& InItemInstanceId)
{
	UPFServerMoveItemToUserFromCharacter* Proxy = NewObject<UPFServerMoveItemToUserFromCharacter>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.PlayFabId = InPlayFabId;
	Proxy->Request.CharacterId = InCharacterId;
	Proxy->Request.ItemInstanceId = InItemInstanceId;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFServerMoveItemToUserFromCharacter::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabServerPtr ServerAPI = IPlayFabModuleInterface::Get().GetServerAPI();

	bool CallResult = false;

	if(ServerAPI.IsValid())
	{	
		CallResult = ServerAPI->MoveItemToUserFromCharacter(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		OnFailure.Broadcast();
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFServerMoveItemToUserFromCharacter::OnSuccessCallback(const PlayFab::ServerModels::FMoveItemToUserFromCharacterResult& Result)
{
	OnSuccess.Broadcast();
}

void UPFServerMoveItemToUserFromCharacter::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	OnFailure.Broadcast();	
}
