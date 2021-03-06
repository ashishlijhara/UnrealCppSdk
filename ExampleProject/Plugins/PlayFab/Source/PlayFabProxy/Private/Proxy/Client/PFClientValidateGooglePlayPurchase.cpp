// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PFClientValidateGooglePlayPurchase.h"

UPFClientValidateGooglePlayPurchase::UPFClientValidateGooglePlayPurchase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabClientAPI::FValidateGooglePlayPurchaseDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFClientValidateGooglePlayPurchase* UPFClientValidateGooglePlayPurchase::ValidateGooglePlayPurchase(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InReceiptJson, const FString& InSignature, const FString& InCurrencyCode, const int32& InPurchasePrice)
{
	UPFClientValidateGooglePlayPurchase* Proxy = NewObject<UPFClientValidateGooglePlayPurchase>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.ReceiptJson = InReceiptJson;
	Proxy->Request.Signature = InSignature;
	Proxy->Request.CurrencyCode = InCurrencyCode;
	Proxy->Request.PurchasePrice = InPurchasePrice;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFClientValidateGooglePlayPurchase::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

	bool CallResult = false;

	if(ClientAPI.IsValid())
	{	
		CallResult = ClientAPI->ValidateGooglePlayPurchase(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		OnFailure.Broadcast();
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFClientValidateGooglePlayPurchase::OnSuccessCallback(const PlayFab::ClientModels::FValidateGooglePlayPurchaseResult& Result)
{
	OnSuccess.Broadcast();
}

void UPFClientValidateGooglePlayPurchase::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	OnFailure.Broadcast();	
}
