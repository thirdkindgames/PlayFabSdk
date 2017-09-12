#include "StdAfx.h"
#include "PlayFabClientApi.h"
#include "PlayFabSettings.h"

#include <AzCore/EBus/EBus.h>
#include "PlayFabClientSdk/PlayFabClient_ClientNotificationBus.h" // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS: dbowen (2017/08/11)

#include "PlayFabDataGatherer.h"        // #THIRD_KIND_PLAYFAB_DATA_GATHERER: gwatson (2017/09/12) - Added PlayFab data gatherer to send system information events to PlayFab on login

using namespace PlayFabClientSdk;

// Client-Specific
AZStd::string PlayFabClientApi::mUserSessionTicket;

bool PlayFabClientApi::IsClientLoggedIn()
{
    return mUserSessionTicket.length() != 0;
}

// #THIRD_KIND_PLAYFAB_SHUTDOWN_FIXES: - Added a logout function so that the statics can be destroyed before the system allocator.
void PlayFabClientApi::ForgetClientCredentials()
{
    // #THIRD_KIND_PLAYFAB_CRASH_WHEN_PC_IS_OFFLINE: szaluga (2017/08/05)
    // We're taking advantage of the SSO optimization implemented by AZStd::string (and virtually all popular compilers) -
    // small strings are using an internal buffer instead of the allocator.
    // Note: This was not possible with Aws::String, as it deliberately disabled SSO to fix some Android/gcc issuses,
    // but now that PlayFab uses AZStd::string, it should be safe to rely on this behaviour.
    mUserSessionTicket.set_capacity(0);
}

void PlayFabClientApi::MultiStepClientLogin(bool needsAttribution)
{
    // #THIRD_KIND_PLAYFAB_DATA_GATHERER: gwatson (2017/09/12) - Added PlayFab data gatherer to send system information events to PlayFab on login
    // Output the system information event
    PlayFab::PlayFabDataGatherer dataGatherer;
    AZ_TracePrintf("PlayFab", dataGatherer.GenerateReport().c_str());

    ClientModels::WriteClientPlayerEventRequest request;
    request.EventName = "system_information";
    request.Body = dataGatherer.GetData();;
    WritePlayerEvent(request, nullptr, nullptr, nullptr);
    // #THIRD_KIND_PLAYFAB_DATA_GATHERER: gwatson (2017/09/12) - Added PlayFab data gatherer to send system information events to PlayFab on login

    if (needsAttribution && !PlayFabSettings::playFabSettings->disableAdvertising && PlayFabSettings::playFabSettings->advertisingIdType.length() > 0 && PlayFabSettings::playFabSettings->advertisingIdValue.length() > 0)
    {
        ClientModels::AttributeInstallRequest request;
        if (PlayFabSettings::playFabSettings->advertisingIdType == PlayFabSettings::playFabSettings->AD_TYPE_IDFA)
            request.Idfa = PlayFabSettings::playFabSettings->advertisingIdValue;
        else if (PlayFabSettings::playFabSettings->advertisingIdType == PlayFabSettings::playFabSettings->AD_TYPE_ANDROID_ID)
            request.Adid = PlayFabSettings::playFabSettings->advertisingIdValue;
        else
            return;
        AttributeInstall(request, nullptr, nullptr);
    }
}


// #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
void PlayFabClientApi::OnError(const PlayFabRequest& request, const PlayFabError& error)
{
    EBUS_EVENT_ID(request.mRequestId,PlayFabClient_ClientNotificationBus, OnError, error);     
    EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnError, error, request.mRequestId);
}
// THIRD_KIND_END

// PlayFabClient Api
PlayFabClientApi::PlayFabClientApi() {}

int PlayFabClientApi::GetPhotonAuthenticationToken(
    ClientModels::GetPhotonAuthenticationTokenRequest& request,
    ProcessApiCallback<ClientModels::GetPhotonAuthenticationTokenResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetPhotonAuthenticationToken"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetPhotonAuthenticationTokenResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetPhotonAuthenticationTokenResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetPhotonAuthenticationTokenResult* outResult = new ClientModels::GetPhotonAuthenticationTokenResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetPhotonAuthenticationTokenResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetPhotonAuthenticationTokenResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnGetPhotonAuthenticationToken, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnGetPhotonAuthenticationToken, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::GetTitlePublicKey(
    ClientModels::GetTitlePublicKeyRequest& request,
    ProcessApiCallback<ClientModels::GetTitlePublicKeyResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetTitlePublicKey"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnGetTitlePublicKeyResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetTitlePublicKeyResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetTitlePublicKeyResult* outResult = new ClientModels::GetTitlePublicKeyResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetTitlePublicKeyResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetTitlePublicKeyResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnGetTitlePublicKey, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnGetTitlePublicKey, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::GetWindowsHelloChallenge(
    ClientModels::GetWindowsHelloChallengeRequest& request,
    ProcessApiCallback<ClientModels::GetWindowsHelloChallengeResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetWindowsHelloChallenge"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnGetWindowsHelloChallengeResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetWindowsHelloChallengeResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetWindowsHelloChallengeResponse* outResult = new ClientModels::GetWindowsHelloChallengeResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetWindowsHelloChallengeResponse> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetWindowsHelloChallengeResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnGetWindowsHelloChallenge, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnGetWindowsHelloChallenge, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::LoginWithAndroidDeviceID(
    ClientModels::LoginWithAndroidDeviceIDRequest& request,
    ProcessApiCallback<ClientModels::LoginResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{
    if (PlayFabSettings::playFabSettings->titleId.length() > 0)
        request.TitleId = PlayFabSettings::playFabSettings->titleId;

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/LoginWithAndroidDeviceID"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnLoginWithAndroidDeviceIDResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnLoginWithAndroidDeviceIDResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::LoginResult* outResult = new ClientModels::LoginResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);

        if (outResult->SessionTicket.length() > 0)
        {
            PlayFabClientApi::mUserSessionTicket = outResult->SessionTicket;
        }
        MultiStepClientLogin(outResult->SettingsForUser->NeedsAttribution);

        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::LoginResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::LoginResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnLoginWithAndroidDeviceID, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnLoginWithAndroidDeviceID, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::LoginWithCustomID(
    ClientModels::LoginWithCustomIDRequest& request,
    ProcessApiCallback<ClientModels::LoginResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{
    if (PlayFabSettings::playFabSettings->titleId.length() > 0)
        request.TitleId = PlayFabSettings::playFabSettings->titleId;

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/LoginWithCustomID"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnLoginWithCustomIDResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnLoginWithCustomIDResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::LoginResult* outResult = new ClientModels::LoginResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);

        if (outResult->SessionTicket.length() > 0)
        {
            PlayFabClientApi::mUserSessionTicket = outResult->SessionTicket;
        }
        MultiStepClientLogin(outResult->SettingsForUser->NeedsAttribution);

        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::LoginResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::LoginResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnLoginWithCustomID, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnLoginWithCustomID, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::LoginWithEmailAddress(
    ClientModels::LoginWithEmailAddressRequest& request,
    ProcessApiCallback<ClientModels::LoginResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{
    if (PlayFabSettings::playFabSettings->titleId.length() > 0)
        request.TitleId = PlayFabSettings::playFabSettings->titleId;

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/LoginWithEmailAddress"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnLoginWithEmailAddressResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnLoginWithEmailAddressResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::LoginResult* outResult = new ClientModels::LoginResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);

        if (outResult->SessionTicket.length() > 0)
        {
            PlayFabClientApi::mUserSessionTicket = outResult->SessionTicket;
        }
        MultiStepClientLogin(outResult->SettingsForUser->NeedsAttribution);

        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::LoginResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::LoginResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnLoginWithEmailAddress, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnLoginWithEmailAddress, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::LoginWithFacebook(
    ClientModels::LoginWithFacebookRequest& request,
    ProcessApiCallback<ClientModels::LoginResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{
    if (PlayFabSettings::playFabSettings->titleId.length() > 0)
        request.TitleId = PlayFabSettings::playFabSettings->titleId;

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/LoginWithFacebook"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnLoginWithFacebookResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnLoginWithFacebookResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::LoginResult* outResult = new ClientModels::LoginResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);

        if (outResult->SessionTicket.length() > 0)
        {
            PlayFabClientApi::mUserSessionTicket = outResult->SessionTicket;
        }
        MultiStepClientLogin(outResult->SettingsForUser->NeedsAttribution);

        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::LoginResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::LoginResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnLoginWithFacebook, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnLoginWithFacebook, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::LoginWithGameCenter(
    ClientModels::LoginWithGameCenterRequest& request,
    ProcessApiCallback<ClientModels::LoginResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{
    if (PlayFabSettings::playFabSettings->titleId.length() > 0)
        request.TitleId = PlayFabSettings::playFabSettings->titleId;

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/LoginWithGameCenter"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnLoginWithGameCenterResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnLoginWithGameCenterResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::LoginResult* outResult = new ClientModels::LoginResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);

        if (outResult->SessionTicket.length() > 0)
        {
            PlayFabClientApi::mUserSessionTicket = outResult->SessionTicket;
        }
        MultiStepClientLogin(outResult->SettingsForUser->NeedsAttribution);

        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::LoginResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::LoginResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnLoginWithGameCenter, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnLoginWithGameCenter, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::LoginWithGoogleAccount(
    ClientModels::LoginWithGoogleAccountRequest& request,
    ProcessApiCallback<ClientModels::LoginResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{
    if (PlayFabSettings::playFabSettings->titleId.length() > 0)
        request.TitleId = PlayFabSettings::playFabSettings->titleId;

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/LoginWithGoogleAccount"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnLoginWithGoogleAccountResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnLoginWithGoogleAccountResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::LoginResult* outResult = new ClientModels::LoginResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);

        if (outResult->SessionTicket.length() > 0)
        {
            PlayFabClientApi::mUserSessionTicket = outResult->SessionTicket;
        }
        MultiStepClientLogin(outResult->SettingsForUser->NeedsAttribution);

        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::LoginResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::LoginResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnLoginWithGoogleAccount, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnLoginWithGoogleAccount, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::LoginWithIOSDeviceID(
    ClientModels::LoginWithIOSDeviceIDRequest& request,
    ProcessApiCallback<ClientModels::LoginResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{
    if (PlayFabSettings::playFabSettings->titleId.length() > 0)
        request.TitleId = PlayFabSettings::playFabSettings->titleId;

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/LoginWithIOSDeviceID"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnLoginWithIOSDeviceIDResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnLoginWithIOSDeviceIDResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::LoginResult* outResult = new ClientModels::LoginResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);

        if (outResult->SessionTicket.length() > 0)
        {
            PlayFabClientApi::mUserSessionTicket = outResult->SessionTicket;
        }
        MultiStepClientLogin(outResult->SettingsForUser->NeedsAttribution);

        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::LoginResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::LoginResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnLoginWithIOSDeviceID, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnLoginWithIOSDeviceID, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::LoginWithKongregate(
    ClientModels::LoginWithKongregateRequest& request,
    ProcessApiCallback<ClientModels::LoginResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{
    if (PlayFabSettings::playFabSettings->titleId.length() > 0)
        request.TitleId = PlayFabSettings::playFabSettings->titleId;

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/LoginWithKongregate"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnLoginWithKongregateResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnLoginWithKongregateResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::LoginResult* outResult = new ClientModels::LoginResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);

        if (outResult->SessionTicket.length() > 0)
        {
            PlayFabClientApi::mUserSessionTicket = outResult->SessionTicket;
        }
        MultiStepClientLogin(outResult->SettingsForUser->NeedsAttribution);

        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::LoginResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::LoginResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnLoginWithKongregate, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnLoginWithKongregate, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::LoginWithPlayFab(
    ClientModels::LoginWithPlayFabRequest& request,
    ProcessApiCallback<ClientModels::LoginResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{
    if (PlayFabSettings::playFabSettings->titleId.length() > 0)
        request.TitleId = PlayFabSettings::playFabSettings->titleId;

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/LoginWithPlayFab"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnLoginWithPlayFabResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnLoginWithPlayFabResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::LoginResult* outResult = new ClientModels::LoginResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);

        if (outResult->SessionTicket.length() > 0)
        {
            PlayFabClientApi::mUserSessionTicket = outResult->SessionTicket;
        }
        MultiStepClientLogin(outResult->SettingsForUser->NeedsAttribution);

        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::LoginResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::LoginResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnLoginWithPlayFab, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnLoginWithPlayFab, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::LoginWithSteam(
    ClientModels::LoginWithSteamRequest& request,
    ProcessApiCallback<ClientModels::LoginResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{
    if (PlayFabSettings::playFabSettings->titleId.length() > 0)
        request.TitleId = PlayFabSettings::playFabSettings->titleId;

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/LoginWithSteam"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnLoginWithSteamResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnLoginWithSteamResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::LoginResult* outResult = new ClientModels::LoginResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);

        if (outResult->SessionTicket.length() > 0)
        {
            PlayFabClientApi::mUserSessionTicket = outResult->SessionTicket;
        }
        MultiStepClientLogin(outResult->SettingsForUser->NeedsAttribution);

        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::LoginResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::LoginResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnLoginWithSteam, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnLoginWithSteam, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::LoginWithTwitch(
    ClientModels::LoginWithTwitchRequest& request,
    ProcessApiCallback<ClientModels::LoginResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{
    if (PlayFabSettings::playFabSettings->titleId.length() > 0)
        request.TitleId = PlayFabSettings::playFabSettings->titleId;

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/LoginWithTwitch"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnLoginWithTwitchResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnLoginWithTwitchResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::LoginResult* outResult = new ClientModels::LoginResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);

        if (outResult->SessionTicket.length() > 0)
        {
            PlayFabClientApi::mUserSessionTicket = outResult->SessionTicket;
        }
        MultiStepClientLogin(outResult->SettingsForUser->NeedsAttribution);

        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::LoginResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::LoginResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnLoginWithTwitch, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnLoginWithTwitch, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::LoginWithWindowsHello(
    ClientModels::LoginWithWindowsHelloRequest& request,
    ProcessApiCallback<ClientModels::LoginResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{
    if (PlayFabSettings::playFabSettings->titleId.length() > 0)
        request.TitleId = PlayFabSettings::playFabSettings->titleId;

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/LoginWithWindowsHello"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnLoginWithWindowsHelloResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnLoginWithWindowsHelloResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::LoginResult* outResult = new ClientModels::LoginResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);

        if (outResult->SessionTicket.length() > 0)
        {
            PlayFabClientApi::mUserSessionTicket = outResult->SessionTicket;
        }
        MultiStepClientLogin(outResult->SettingsForUser->NeedsAttribution);

        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::LoginResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::LoginResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnLoginWithWindowsHello, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnLoginWithWindowsHello, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::RegisterPlayFabUser(
    ClientModels::RegisterPlayFabUserRequest& request,
    ProcessApiCallback<ClientModels::RegisterPlayFabUserResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{
    if (PlayFabSettings::playFabSettings->titleId.length() > 0)
        request.TitleId = PlayFabSettings::playFabSettings->titleId;

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/RegisterPlayFabUser"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnRegisterPlayFabUserResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnRegisterPlayFabUserResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::RegisterPlayFabUserResult* outResult = new ClientModels::RegisterPlayFabUserResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);

        if (outResult->SessionTicket.length() > 0)
        {
            PlayFabClientApi::mUserSessionTicket = outResult->SessionTicket;
        }
        MultiStepClientLogin(outResult->SettingsForUser->NeedsAttribution);

        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::RegisterPlayFabUserResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::RegisterPlayFabUserResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnRegisterPlayFabUser, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnRegisterPlayFabUser, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::RegisterWithWindowsHello(
    ClientModels::RegisterWithWindowsHelloRequest& request,
    ProcessApiCallback<ClientModels::LoginResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{
    if (PlayFabSettings::playFabSettings->titleId.length() > 0)
        request.TitleId = PlayFabSettings::playFabSettings->titleId;

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/RegisterWithWindowsHello"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnRegisterWithWindowsHelloResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnRegisterWithWindowsHelloResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::LoginResult* outResult = new ClientModels::LoginResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);

        if (outResult->SessionTicket.length() > 0)
        {
            PlayFabClientApi::mUserSessionTicket = outResult->SessionTicket;
        }
        MultiStepClientLogin(outResult->SettingsForUser->NeedsAttribution);

        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::LoginResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::LoginResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnRegisterWithWindowsHello, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnRegisterWithWindowsHello, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::SetPlayerSecret(
    ClientModels::SetPlayerSecretRequest& request,
    ProcessApiCallback<ClientModels::SetPlayerSecretResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/SetPlayerSecret"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnSetPlayerSecretResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnSetPlayerSecretResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::SetPlayerSecretResult* outResult = new ClientModels::SetPlayerSecretResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::SetPlayerSecretResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::SetPlayerSecretResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnSetPlayerSecret, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnSetPlayerSecret, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::AddGenericID(
    ClientModels::AddGenericIDRequest& request,
    ProcessApiCallback<ClientModels::AddGenericIDResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/AddGenericID"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnAddGenericIDResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnAddGenericIDResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::AddGenericIDResult* outResult = new ClientModels::AddGenericIDResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::AddGenericIDResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::AddGenericIDResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnAddGenericID, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnAddGenericID, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::AddUsernamePassword(
    ClientModels::AddUsernamePasswordRequest& request,
    ProcessApiCallback<ClientModels::AddUsernamePasswordResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/AddUsernamePassword"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnAddUsernamePasswordResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnAddUsernamePasswordResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::AddUsernamePasswordResult* outResult = new ClientModels::AddUsernamePasswordResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::AddUsernamePasswordResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::AddUsernamePasswordResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnAddUsernamePassword, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnAddUsernamePassword, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::GetAccountInfo(
    ClientModels::GetAccountInfoRequest& request,
    ProcessApiCallback<ClientModels::GetAccountInfoResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetAccountInfo"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetAccountInfoResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetAccountInfoResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetAccountInfoResult* outResult = new ClientModels::GetAccountInfoResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetAccountInfoResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetAccountInfoResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnGetAccountInfo, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnGetAccountInfo, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::GetPlayerCombinedInfo(
    ClientModels::GetPlayerCombinedInfoRequest& request,
    ProcessApiCallback<ClientModels::GetPlayerCombinedInfoResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetPlayerCombinedInfo"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetPlayerCombinedInfoResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetPlayerCombinedInfoResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetPlayerCombinedInfoResult* outResult = new ClientModels::GetPlayerCombinedInfoResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetPlayerCombinedInfoResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetPlayerCombinedInfoResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnGetPlayerCombinedInfo, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnGetPlayerCombinedInfo, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::GetPlayerProfile(
    ClientModels::GetPlayerProfileRequest& request,
    ProcessApiCallback<ClientModels::GetPlayerProfileResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetPlayerProfile"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetPlayerProfileResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetPlayerProfileResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetPlayerProfileResult* outResult = new ClientModels::GetPlayerProfileResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetPlayerProfileResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetPlayerProfileResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnGetPlayerProfile, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnGetPlayerProfile, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::GetPlayFabIDsFromFacebookIDs(
    ClientModels::GetPlayFabIDsFromFacebookIDsRequest& request,
    ProcessApiCallback<ClientModels::GetPlayFabIDsFromFacebookIDsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetPlayFabIDsFromFacebookIDs"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetPlayFabIDsFromFacebookIDsResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetPlayFabIDsFromFacebookIDsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetPlayFabIDsFromFacebookIDsResult* outResult = new ClientModels::GetPlayFabIDsFromFacebookIDsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetPlayFabIDsFromFacebookIDsResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetPlayFabIDsFromFacebookIDsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnGetPlayFabIDsFromFacebookIDs, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnGetPlayFabIDsFromFacebookIDs, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::GetPlayFabIDsFromGameCenterIDs(
    ClientModels::GetPlayFabIDsFromGameCenterIDsRequest& request,
    ProcessApiCallback<ClientModels::GetPlayFabIDsFromGameCenterIDsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetPlayFabIDsFromGameCenterIDs"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetPlayFabIDsFromGameCenterIDsResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetPlayFabIDsFromGameCenterIDsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetPlayFabIDsFromGameCenterIDsResult* outResult = new ClientModels::GetPlayFabIDsFromGameCenterIDsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetPlayFabIDsFromGameCenterIDsResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetPlayFabIDsFromGameCenterIDsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnGetPlayFabIDsFromGameCenterIDs, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnGetPlayFabIDsFromGameCenterIDs, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::GetPlayFabIDsFromGenericIDs(
    ClientModels::GetPlayFabIDsFromGenericIDsRequest& request,
    ProcessApiCallback<ClientModels::GetPlayFabIDsFromGenericIDsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetPlayFabIDsFromGenericIDs"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetPlayFabIDsFromGenericIDsResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetPlayFabIDsFromGenericIDsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetPlayFabIDsFromGenericIDsResult* outResult = new ClientModels::GetPlayFabIDsFromGenericIDsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetPlayFabIDsFromGenericIDsResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetPlayFabIDsFromGenericIDsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnGetPlayFabIDsFromGenericIDs, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnGetPlayFabIDsFromGenericIDs, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::GetPlayFabIDsFromGoogleIDs(
    ClientModels::GetPlayFabIDsFromGoogleIDsRequest& request,
    ProcessApiCallback<ClientModels::GetPlayFabIDsFromGoogleIDsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetPlayFabIDsFromGoogleIDs"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetPlayFabIDsFromGoogleIDsResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetPlayFabIDsFromGoogleIDsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetPlayFabIDsFromGoogleIDsResult* outResult = new ClientModels::GetPlayFabIDsFromGoogleIDsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetPlayFabIDsFromGoogleIDsResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetPlayFabIDsFromGoogleIDsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnGetPlayFabIDsFromGoogleIDs, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnGetPlayFabIDsFromGoogleIDs, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::GetPlayFabIDsFromKongregateIDs(
    ClientModels::GetPlayFabIDsFromKongregateIDsRequest& request,
    ProcessApiCallback<ClientModels::GetPlayFabIDsFromKongregateIDsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetPlayFabIDsFromKongregateIDs"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetPlayFabIDsFromKongregateIDsResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetPlayFabIDsFromKongregateIDsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetPlayFabIDsFromKongregateIDsResult* outResult = new ClientModels::GetPlayFabIDsFromKongregateIDsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetPlayFabIDsFromKongregateIDsResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetPlayFabIDsFromKongregateIDsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnGetPlayFabIDsFromKongregateIDs, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnGetPlayFabIDsFromKongregateIDs, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::GetPlayFabIDsFromSteamIDs(
    ClientModels::GetPlayFabIDsFromSteamIDsRequest& request,
    ProcessApiCallback<ClientModels::GetPlayFabIDsFromSteamIDsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetPlayFabIDsFromSteamIDs"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetPlayFabIDsFromSteamIDsResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetPlayFabIDsFromSteamIDsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetPlayFabIDsFromSteamIDsResult* outResult = new ClientModels::GetPlayFabIDsFromSteamIDsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetPlayFabIDsFromSteamIDsResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetPlayFabIDsFromSteamIDsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnGetPlayFabIDsFromSteamIDs, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnGetPlayFabIDsFromSteamIDs, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::GetPlayFabIDsFromTwitchIDs(
    ClientModels::GetPlayFabIDsFromTwitchIDsRequest& request,
    ProcessApiCallback<ClientModels::GetPlayFabIDsFromTwitchIDsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetPlayFabIDsFromTwitchIDs"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetPlayFabIDsFromTwitchIDsResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetPlayFabIDsFromTwitchIDsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetPlayFabIDsFromTwitchIDsResult* outResult = new ClientModels::GetPlayFabIDsFromTwitchIDsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetPlayFabIDsFromTwitchIDsResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetPlayFabIDsFromTwitchIDsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnGetPlayFabIDsFromTwitchIDs, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnGetPlayFabIDsFromTwitchIDs, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::LinkAndroidDeviceID(
    ClientModels::LinkAndroidDeviceIDRequest& request,
    ProcessApiCallback<ClientModels::LinkAndroidDeviceIDResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/LinkAndroidDeviceID"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnLinkAndroidDeviceIDResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnLinkAndroidDeviceIDResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::LinkAndroidDeviceIDResult* outResult = new ClientModels::LinkAndroidDeviceIDResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::LinkAndroidDeviceIDResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::LinkAndroidDeviceIDResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnLinkAndroidDeviceID, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnLinkAndroidDeviceID, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::LinkCustomID(
    ClientModels::LinkCustomIDRequest& request,
    ProcessApiCallback<ClientModels::LinkCustomIDResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/LinkCustomID"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnLinkCustomIDResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnLinkCustomIDResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::LinkCustomIDResult* outResult = new ClientModels::LinkCustomIDResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::LinkCustomIDResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::LinkCustomIDResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnLinkCustomID, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnLinkCustomID, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::LinkFacebookAccount(
    ClientModels::LinkFacebookAccountRequest& request,
    ProcessApiCallback<ClientModels::LinkFacebookAccountResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/LinkFacebookAccount"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnLinkFacebookAccountResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnLinkFacebookAccountResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::LinkFacebookAccountResult* outResult = new ClientModels::LinkFacebookAccountResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::LinkFacebookAccountResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::LinkFacebookAccountResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnLinkFacebookAccount, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnLinkFacebookAccount, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::LinkGameCenterAccount(
    ClientModels::LinkGameCenterAccountRequest& request,
    ProcessApiCallback<ClientModels::LinkGameCenterAccountResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/LinkGameCenterAccount"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnLinkGameCenterAccountResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnLinkGameCenterAccountResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::LinkGameCenterAccountResult* outResult = new ClientModels::LinkGameCenterAccountResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::LinkGameCenterAccountResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::LinkGameCenterAccountResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnLinkGameCenterAccount, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnLinkGameCenterAccount, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::LinkGoogleAccount(
    ClientModels::LinkGoogleAccountRequest& request,
    ProcessApiCallback<ClientModels::LinkGoogleAccountResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/LinkGoogleAccount"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnLinkGoogleAccountResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnLinkGoogleAccountResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::LinkGoogleAccountResult* outResult = new ClientModels::LinkGoogleAccountResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::LinkGoogleAccountResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::LinkGoogleAccountResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnLinkGoogleAccount, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnLinkGoogleAccount, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::LinkIOSDeviceID(
    ClientModels::LinkIOSDeviceIDRequest& request,
    ProcessApiCallback<ClientModels::LinkIOSDeviceIDResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/LinkIOSDeviceID"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnLinkIOSDeviceIDResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnLinkIOSDeviceIDResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::LinkIOSDeviceIDResult* outResult = new ClientModels::LinkIOSDeviceIDResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::LinkIOSDeviceIDResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::LinkIOSDeviceIDResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnLinkIOSDeviceID, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnLinkIOSDeviceID, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::LinkKongregate(
    ClientModels::LinkKongregateAccountRequest& request,
    ProcessApiCallback<ClientModels::LinkKongregateAccountResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/LinkKongregate"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnLinkKongregateResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnLinkKongregateResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::LinkKongregateAccountResult* outResult = new ClientModels::LinkKongregateAccountResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::LinkKongregateAccountResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::LinkKongregateAccountResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnLinkKongregate, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnLinkKongregate, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::LinkSteamAccount(
    ClientModels::LinkSteamAccountRequest& request,
    ProcessApiCallback<ClientModels::LinkSteamAccountResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/LinkSteamAccount"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnLinkSteamAccountResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnLinkSteamAccountResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::LinkSteamAccountResult* outResult = new ClientModels::LinkSteamAccountResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::LinkSteamAccountResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::LinkSteamAccountResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnLinkSteamAccount, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnLinkSteamAccount, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::LinkTwitch(
    ClientModels::LinkTwitchAccountRequest& request,
    ProcessApiCallback<ClientModels::LinkTwitchAccountResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/LinkTwitch"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnLinkTwitchResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnLinkTwitchResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::LinkTwitchAccountResult* outResult = new ClientModels::LinkTwitchAccountResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::LinkTwitchAccountResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::LinkTwitchAccountResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnLinkTwitch, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnLinkTwitch, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::LinkWindowsHello(
    ClientModels::LinkWindowsHelloAccountRequest& request,
    ProcessApiCallback<ClientModels::LinkWindowsHelloAccountResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/LinkWindowsHello"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnLinkWindowsHelloResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnLinkWindowsHelloResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::LinkWindowsHelloAccountResponse* outResult = new ClientModels::LinkWindowsHelloAccountResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::LinkWindowsHelloAccountResponse> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::LinkWindowsHelloAccountResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnLinkWindowsHello, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnLinkWindowsHello, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::RemoveGenericID(
    ClientModels::RemoveGenericIDRequest& request,
    ProcessApiCallback<ClientModels::RemoveGenericIDResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/RemoveGenericID"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnRemoveGenericIDResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnRemoveGenericIDResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::RemoveGenericIDResult* outResult = new ClientModels::RemoveGenericIDResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::RemoveGenericIDResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::RemoveGenericIDResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnRemoveGenericID, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnRemoveGenericID, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::ReportPlayer(
    ClientModels::ReportPlayerClientRequest& request,
    ProcessApiCallback<ClientModels::ReportPlayerClientResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/ReportPlayer"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnReportPlayerResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnReportPlayerResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::ReportPlayerClientResult* outResult = new ClientModels::ReportPlayerClientResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::ReportPlayerClientResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::ReportPlayerClientResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnReportPlayer, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnReportPlayer, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::SendAccountRecoveryEmail(
    ClientModels::SendAccountRecoveryEmailRequest& request,
    ProcessApiCallback<ClientModels::SendAccountRecoveryEmailResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/SendAccountRecoveryEmail"), Aws::Http::HttpMethod::HTTP_POST, "", "", request.toJSONString(), customData, callback, errorCallback, OnSendAccountRecoveryEmailResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnSendAccountRecoveryEmailResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::SendAccountRecoveryEmailResult* outResult = new ClientModels::SendAccountRecoveryEmailResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::SendAccountRecoveryEmailResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::SendAccountRecoveryEmailResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnSendAccountRecoveryEmail, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnSendAccountRecoveryEmail, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::UnlinkAndroidDeviceID(
    ClientModels::UnlinkAndroidDeviceIDRequest& request,
    ProcessApiCallback<ClientModels::UnlinkAndroidDeviceIDResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/UnlinkAndroidDeviceID"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnUnlinkAndroidDeviceIDResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnUnlinkAndroidDeviceIDResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::UnlinkAndroidDeviceIDResult* outResult = new ClientModels::UnlinkAndroidDeviceIDResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::UnlinkAndroidDeviceIDResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::UnlinkAndroidDeviceIDResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnUnlinkAndroidDeviceID, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnUnlinkAndroidDeviceID, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::UnlinkCustomID(
    ClientModels::UnlinkCustomIDRequest& request,
    ProcessApiCallback<ClientModels::UnlinkCustomIDResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/UnlinkCustomID"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnUnlinkCustomIDResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnUnlinkCustomIDResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::UnlinkCustomIDResult* outResult = new ClientModels::UnlinkCustomIDResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::UnlinkCustomIDResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::UnlinkCustomIDResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnUnlinkCustomID, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnUnlinkCustomID, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::UnlinkFacebookAccount(

    ProcessApiCallback<ClientModels::UnlinkFacebookAccountResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/UnlinkFacebookAccount"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, "", customData, callback, errorCallback, OnUnlinkFacebookAccountResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnUnlinkFacebookAccountResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::UnlinkFacebookAccountResult* outResult = new ClientModels::UnlinkFacebookAccountResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::UnlinkFacebookAccountResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::UnlinkFacebookAccountResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnUnlinkFacebookAccount, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnUnlinkFacebookAccount, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::UnlinkGameCenterAccount(

    ProcessApiCallback<ClientModels::UnlinkGameCenterAccountResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/UnlinkGameCenterAccount"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, "", customData, callback, errorCallback, OnUnlinkGameCenterAccountResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnUnlinkGameCenterAccountResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::UnlinkGameCenterAccountResult* outResult = new ClientModels::UnlinkGameCenterAccountResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::UnlinkGameCenterAccountResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::UnlinkGameCenterAccountResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnUnlinkGameCenterAccount, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnUnlinkGameCenterAccount, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::UnlinkGoogleAccount(

    ProcessApiCallback<ClientModels::UnlinkGoogleAccountResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/UnlinkGoogleAccount"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, "", customData, callback, errorCallback, OnUnlinkGoogleAccountResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnUnlinkGoogleAccountResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::UnlinkGoogleAccountResult* outResult = new ClientModels::UnlinkGoogleAccountResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::UnlinkGoogleAccountResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::UnlinkGoogleAccountResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnUnlinkGoogleAccount, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnUnlinkGoogleAccount, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::UnlinkIOSDeviceID(
    ClientModels::UnlinkIOSDeviceIDRequest& request,
    ProcessApiCallback<ClientModels::UnlinkIOSDeviceIDResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/UnlinkIOSDeviceID"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnUnlinkIOSDeviceIDResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnUnlinkIOSDeviceIDResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::UnlinkIOSDeviceIDResult* outResult = new ClientModels::UnlinkIOSDeviceIDResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::UnlinkIOSDeviceIDResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::UnlinkIOSDeviceIDResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnUnlinkIOSDeviceID, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnUnlinkIOSDeviceID, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::UnlinkKongregate(

    ProcessApiCallback<ClientModels::UnlinkKongregateAccountResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/UnlinkKongregate"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, "", customData, callback, errorCallback, OnUnlinkKongregateResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnUnlinkKongregateResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::UnlinkKongregateAccountResult* outResult = new ClientModels::UnlinkKongregateAccountResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::UnlinkKongregateAccountResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::UnlinkKongregateAccountResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnUnlinkKongregate, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnUnlinkKongregate, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::UnlinkSteamAccount(

    ProcessApiCallback<ClientModels::UnlinkSteamAccountResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/UnlinkSteamAccount"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, "", customData, callback, errorCallback, OnUnlinkSteamAccountResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnUnlinkSteamAccountResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::UnlinkSteamAccountResult* outResult = new ClientModels::UnlinkSteamAccountResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::UnlinkSteamAccountResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::UnlinkSteamAccountResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnUnlinkSteamAccount, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnUnlinkSteamAccount, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::UnlinkTwitch(

    ProcessApiCallback<ClientModels::UnlinkTwitchAccountResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/UnlinkTwitch"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, "", customData, callback, errorCallback, OnUnlinkTwitchResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnUnlinkTwitchResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::UnlinkTwitchAccountResult* outResult = new ClientModels::UnlinkTwitchAccountResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::UnlinkTwitchAccountResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::UnlinkTwitchAccountResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnUnlinkTwitch, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnUnlinkTwitch, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::UnlinkWindowsHello(
    ClientModels::UnlinkWindowsHelloAccountRequest& request,
    ProcessApiCallback<ClientModels::UnlinkWindowsHelloAccountResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/UnlinkWindowsHello"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnUnlinkWindowsHelloResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnUnlinkWindowsHelloResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::UnlinkWindowsHelloAccountResponse* outResult = new ClientModels::UnlinkWindowsHelloAccountResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::UnlinkWindowsHelloAccountResponse> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::UnlinkWindowsHelloAccountResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnUnlinkWindowsHello, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnUnlinkWindowsHello, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::UpdateAvatarUrl(
    ClientModels::UpdateAvatarUrlRequest& request,
    ProcessApiCallback<ClientModels::EmptyResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/UpdateAvatarUrl"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnUpdateAvatarUrlResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnUpdateAvatarUrlResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::EmptyResult* outResult = new ClientModels::EmptyResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::EmptyResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::EmptyResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnUpdateAvatarUrl, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnUpdateAvatarUrl, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::UpdateUserTitleDisplayName(
    ClientModels::UpdateUserTitleDisplayNameRequest& request,
    ProcessApiCallback<ClientModels::UpdateUserTitleDisplayNameResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/UpdateUserTitleDisplayName"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnUpdateUserTitleDisplayNameResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnUpdateUserTitleDisplayNameResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::UpdateUserTitleDisplayNameResult* outResult = new ClientModels::UpdateUserTitleDisplayNameResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::UpdateUserTitleDisplayNameResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::UpdateUserTitleDisplayNameResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnUpdateUserTitleDisplayName, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnUpdateUserTitleDisplayName, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::GetFriendLeaderboard(
    ClientModels::GetFriendLeaderboardRequest& request,
    ProcessApiCallback<ClientModels::GetLeaderboardResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetFriendLeaderboard"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetFriendLeaderboardResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetFriendLeaderboardResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetLeaderboardResult* outResult = new ClientModels::GetLeaderboardResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetLeaderboardResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetLeaderboardResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnGetFriendLeaderboard, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnGetFriendLeaderboard, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::GetFriendLeaderboardAroundPlayer(
    ClientModels::GetFriendLeaderboardAroundPlayerRequest& request,
    ProcessApiCallback<ClientModels::GetFriendLeaderboardAroundPlayerResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetFriendLeaderboardAroundPlayer"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetFriendLeaderboardAroundPlayerResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetFriendLeaderboardAroundPlayerResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetFriendLeaderboardAroundPlayerResult* outResult = new ClientModels::GetFriendLeaderboardAroundPlayerResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetFriendLeaderboardAroundPlayerResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetFriendLeaderboardAroundPlayerResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnGetFriendLeaderboardAroundPlayer, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnGetFriendLeaderboardAroundPlayer, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::GetLeaderboard(
    ClientModels::GetLeaderboardRequest& request,
    ProcessApiCallback<ClientModels::GetLeaderboardResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetLeaderboard"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetLeaderboardResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetLeaderboardResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetLeaderboardResult* outResult = new ClientModels::GetLeaderboardResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetLeaderboardResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetLeaderboardResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnGetLeaderboard, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnGetLeaderboard, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::GetLeaderboardAroundPlayer(
    ClientModels::GetLeaderboardAroundPlayerRequest& request,
    ProcessApiCallback<ClientModels::GetLeaderboardAroundPlayerResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetLeaderboardAroundPlayer"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetLeaderboardAroundPlayerResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetLeaderboardAroundPlayerResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetLeaderboardAroundPlayerResult* outResult = new ClientModels::GetLeaderboardAroundPlayerResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetLeaderboardAroundPlayerResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetLeaderboardAroundPlayerResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnGetLeaderboardAroundPlayer, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnGetLeaderboardAroundPlayer, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::GetPlayerStatistics(
    ClientModels::GetPlayerStatisticsRequest& request,
    ProcessApiCallback<ClientModels::GetPlayerStatisticsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetPlayerStatistics"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetPlayerStatisticsResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetPlayerStatisticsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetPlayerStatisticsResult* outResult = new ClientModels::GetPlayerStatisticsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetPlayerStatisticsResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetPlayerStatisticsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnGetPlayerStatistics, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnGetPlayerStatistics, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::GetPlayerStatisticVersions(
    ClientModels::GetPlayerStatisticVersionsRequest& request,
    ProcessApiCallback<ClientModels::GetPlayerStatisticVersionsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetPlayerStatisticVersions"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetPlayerStatisticVersionsResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetPlayerStatisticVersionsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetPlayerStatisticVersionsResult* outResult = new ClientModels::GetPlayerStatisticVersionsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetPlayerStatisticVersionsResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetPlayerStatisticVersionsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnGetPlayerStatisticVersions, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnGetPlayerStatisticVersions, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::GetUserData(
    ClientModels::GetUserDataRequest& request,
    ProcessApiCallback<ClientModels::GetUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetUserData"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetUserDataResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetUserDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetUserDataResult* outResult = new ClientModels::GetUserDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetUserDataResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetUserDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnGetUserData, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnGetUserData, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::GetUserPublisherData(
    ClientModels::GetUserDataRequest& request,
    ProcessApiCallback<ClientModels::GetUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetUserPublisherData"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetUserPublisherDataResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetUserPublisherDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetUserDataResult* outResult = new ClientModels::GetUserDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetUserDataResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetUserDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnGetUserPublisherData, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnGetUserPublisherData, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::GetUserPublisherReadOnlyData(
    ClientModels::GetUserDataRequest& request,
    ProcessApiCallback<ClientModels::GetUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetUserPublisherReadOnlyData"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetUserPublisherReadOnlyDataResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetUserPublisherReadOnlyDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetUserDataResult* outResult = new ClientModels::GetUserDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetUserDataResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetUserDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnGetUserPublisherReadOnlyData, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnGetUserPublisherReadOnlyData, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::GetUserReadOnlyData(
    ClientModels::GetUserDataRequest& request,
    ProcessApiCallback<ClientModels::GetUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetUserReadOnlyData"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetUserReadOnlyDataResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetUserReadOnlyDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetUserDataResult* outResult = new ClientModels::GetUserDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetUserDataResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetUserDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnGetUserReadOnlyData, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnGetUserReadOnlyData, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::UpdatePlayerStatistics(
    ClientModels::UpdatePlayerStatisticsRequest& request,
    ProcessApiCallback<ClientModels::UpdatePlayerStatisticsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/UpdatePlayerStatistics"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnUpdatePlayerStatisticsResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnUpdatePlayerStatisticsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::UpdatePlayerStatisticsResult* outResult = new ClientModels::UpdatePlayerStatisticsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::UpdatePlayerStatisticsResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::UpdatePlayerStatisticsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnUpdatePlayerStatistics, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnUpdatePlayerStatistics, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::UpdateUserData(
    ClientModels::UpdateUserDataRequest& request,
    ProcessApiCallback<ClientModels::UpdateUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/UpdateUserData"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnUpdateUserDataResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnUpdateUserDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::UpdateUserDataResult* outResult = new ClientModels::UpdateUserDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::UpdateUserDataResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::UpdateUserDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnUpdateUserData, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnUpdateUserData, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::UpdateUserPublisherData(
    ClientModels::UpdateUserDataRequest& request,
    ProcessApiCallback<ClientModels::UpdateUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/UpdateUserPublisherData"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnUpdateUserPublisherDataResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnUpdateUserPublisherDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::UpdateUserDataResult* outResult = new ClientModels::UpdateUserDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::UpdateUserDataResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::UpdateUserDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnUpdateUserPublisherData, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnUpdateUserPublisherData, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::GetCatalogItems(
    ClientModels::GetCatalogItemsRequest& request,
    ProcessApiCallback<ClientModels::GetCatalogItemsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetCatalogItems"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetCatalogItemsResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetCatalogItemsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetCatalogItemsResult* outResult = new ClientModels::GetCatalogItemsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetCatalogItemsResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetCatalogItemsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnGetCatalogItems, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnGetCatalogItems, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::GetPublisherData(
    ClientModels::GetPublisherDataRequest& request,
    ProcessApiCallback<ClientModels::GetPublisherDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetPublisherData"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetPublisherDataResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetPublisherDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetPublisherDataResult* outResult = new ClientModels::GetPublisherDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetPublisherDataResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetPublisherDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnGetPublisherData, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnGetPublisherData, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::GetStoreItems(
    ClientModels::GetStoreItemsRequest& request,
    ProcessApiCallback<ClientModels::GetStoreItemsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetStoreItems"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetStoreItemsResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetStoreItemsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetStoreItemsResult* outResult = new ClientModels::GetStoreItemsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetStoreItemsResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetStoreItemsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnGetStoreItems, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnGetStoreItems, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::GetTime(

    ProcessApiCallback<ClientModels::GetTimeResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetTime"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, "", customData, callback, errorCallback, OnGetTimeResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetTimeResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetTimeResult* outResult = new ClientModels::GetTimeResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetTimeResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetTimeResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnGetTime, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnGetTime, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::GetTitleData(
    ClientModels::GetTitleDataRequest& request,
    ProcessApiCallback<ClientModels::GetTitleDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetTitleData"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetTitleDataResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetTitleDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetTitleDataResult* outResult = new ClientModels::GetTitleDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetTitleDataResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetTitleDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnGetTitleData, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnGetTitleData, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::GetTitleNews(
    ClientModels::GetTitleNewsRequest& request,
    ProcessApiCallback<ClientModels::GetTitleNewsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetTitleNews"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetTitleNewsResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetTitleNewsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetTitleNewsResult* outResult = new ClientModels::GetTitleNewsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetTitleNewsResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetTitleNewsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnGetTitleNews, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnGetTitleNews, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::AddUserVirtualCurrency(
    ClientModels::AddUserVirtualCurrencyRequest& request,
    ProcessApiCallback<ClientModels::ModifyUserVirtualCurrencyResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/AddUserVirtualCurrency"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnAddUserVirtualCurrencyResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnAddUserVirtualCurrencyResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::ModifyUserVirtualCurrencyResult* outResult = new ClientModels::ModifyUserVirtualCurrencyResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::ModifyUserVirtualCurrencyResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::ModifyUserVirtualCurrencyResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnAddUserVirtualCurrency, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnAddUserVirtualCurrency, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::ConfirmPurchase(
    ClientModels::ConfirmPurchaseRequest& request,
    ProcessApiCallback<ClientModels::ConfirmPurchaseResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/ConfirmPurchase"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnConfirmPurchaseResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnConfirmPurchaseResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::ConfirmPurchaseResult* outResult = new ClientModels::ConfirmPurchaseResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::ConfirmPurchaseResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::ConfirmPurchaseResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnConfirmPurchase, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnConfirmPurchase, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::ConsumeItem(
    ClientModels::ConsumeItemRequest& request,
    ProcessApiCallback<ClientModels::ConsumeItemResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/ConsumeItem"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnConsumeItemResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnConsumeItemResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::ConsumeItemResult* outResult = new ClientModels::ConsumeItemResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::ConsumeItemResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::ConsumeItemResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnConsumeItem, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnConsumeItem, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::GetCharacterInventory(
    ClientModels::GetCharacterInventoryRequest& request,
    ProcessApiCallback<ClientModels::GetCharacterInventoryResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetCharacterInventory"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetCharacterInventoryResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetCharacterInventoryResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetCharacterInventoryResult* outResult = new ClientModels::GetCharacterInventoryResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetCharacterInventoryResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetCharacterInventoryResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnGetCharacterInventory, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnGetCharacterInventory, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::GetPurchase(
    ClientModels::GetPurchaseRequest& request,
    ProcessApiCallback<ClientModels::GetPurchaseResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetPurchase"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetPurchaseResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetPurchaseResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetPurchaseResult* outResult = new ClientModels::GetPurchaseResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetPurchaseResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetPurchaseResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnGetPurchase, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnGetPurchase, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::GetUserInventory(

    ProcessApiCallback<ClientModels::GetUserInventoryResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetUserInventory"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, "", customData, callback, errorCallback, OnGetUserInventoryResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetUserInventoryResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetUserInventoryResult* outResult = new ClientModels::GetUserInventoryResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetUserInventoryResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetUserInventoryResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnGetUserInventory, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnGetUserInventory, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::PayForPurchase(
    ClientModels::PayForPurchaseRequest& request,
    ProcessApiCallback<ClientModels::PayForPurchaseResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/PayForPurchase"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnPayForPurchaseResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnPayForPurchaseResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::PayForPurchaseResult* outResult = new ClientModels::PayForPurchaseResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::PayForPurchaseResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::PayForPurchaseResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnPayForPurchase, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnPayForPurchase, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::PurchaseItem(
    ClientModels::PurchaseItemRequest& request,
    ProcessApiCallback<ClientModels::PurchaseItemResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/PurchaseItem"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnPurchaseItemResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnPurchaseItemResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::PurchaseItemResult* outResult = new ClientModels::PurchaseItemResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::PurchaseItemResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::PurchaseItemResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnPurchaseItem, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnPurchaseItem, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::RedeemCoupon(
    ClientModels::RedeemCouponRequest& request,
    ProcessApiCallback<ClientModels::RedeemCouponResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/RedeemCoupon"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnRedeemCouponResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnRedeemCouponResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::RedeemCouponResult* outResult = new ClientModels::RedeemCouponResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::RedeemCouponResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::RedeemCouponResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnRedeemCoupon, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnRedeemCoupon, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::StartPurchase(
    ClientModels::StartPurchaseRequest& request,
    ProcessApiCallback<ClientModels::StartPurchaseResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/StartPurchase"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnStartPurchaseResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnStartPurchaseResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::StartPurchaseResult* outResult = new ClientModels::StartPurchaseResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::StartPurchaseResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::StartPurchaseResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnStartPurchase, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnStartPurchase, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::SubtractUserVirtualCurrency(
    ClientModels::SubtractUserVirtualCurrencyRequest& request,
    ProcessApiCallback<ClientModels::ModifyUserVirtualCurrencyResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/SubtractUserVirtualCurrency"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnSubtractUserVirtualCurrencyResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnSubtractUserVirtualCurrencyResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::ModifyUserVirtualCurrencyResult* outResult = new ClientModels::ModifyUserVirtualCurrencyResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::ModifyUserVirtualCurrencyResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::ModifyUserVirtualCurrencyResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnSubtractUserVirtualCurrency, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnSubtractUserVirtualCurrency, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::UnlockContainerInstance(
    ClientModels::UnlockContainerInstanceRequest& request,
    ProcessApiCallback<ClientModels::UnlockContainerItemResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/UnlockContainerInstance"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnUnlockContainerInstanceResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnUnlockContainerInstanceResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::UnlockContainerItemResult* outResult = new ClientModels::UnlockContainerItemResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::UnlockContainerItemResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::UnlockContainerItemResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnUnlockContainerInstance, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnUnlockContainerInstance, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::UnlockContainerItem(
    ClientModels::UnlockContainerItemRequest& request,
    ProcessApiCallback<ClientModels::UnlockContainerItemResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/UnlockContainerItem"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnUnlockContainerItemResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnUnlockContainerItemResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::UnlockContainerItemResult* outResult = new ClientModels::UnlockContainerItemResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::UnlockContainerItemResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::UnlockContainerItemResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnUnlockContainerItem, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnUnlockContainerItem, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::AddFriend(
    ClientModels::AddFriendRequest& request,
    ProcessApiCallback<ClientModels::AddFriendResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/AddFriend"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnAddFriendResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnAddFriendResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::AddFriendResult* outResult = new ClientModels::AddFriendResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::AddFriendResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::AddFriendResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnAddFriend, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnAddFriend, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::GetFriendsList(
    ClientModels::GetFriendsListRequest& request,
    ProcessApiCallback<ClientModels::GetFriendsListResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetFriendsList"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetFriendsListResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetFriendsListResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetFriendsListResult* outResult = new ClientModels::GetFriendsListResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetFriendsListResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetFriendsListResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnGetFriendsList, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnGetFriendsList, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::RemoveFriend(
    ClientModels::RemoveFriendRequest& request,
    ProcessApiCallback<ClientModels::RemoveFriendResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/RemoveFriend"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnRemoveFriendResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnRemoveFriendResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::RemoveFriendResult* outResult = new ClientModels::RemoveFriendResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::RemoveFriendResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::RemoveFriendResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnRemoveFriend, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnRemoveFriend, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::SetFriendTags(
    ClientModels::SetFriendTagsRequest& request,
    ProcessApiCallback<ClientModels::SetFriendTagsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/SetFriendTags"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnSetFriendTagsResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnSetFriendTagsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::SetFriendTagsResult* outResult = new ClientModels::SetFriendTagsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::SetFriendTagsResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::SetFriendTagsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnSetFriendTags, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnSetFriendTags, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::GetCurrentGames(
    ClientModels::CurrentGamesRequest& request,
    ProcessApiCallback<ClientModels::CurrentGamesResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetCurrentGames"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetCurrentGamesResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetCurrentGamesResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::CurrentGamesResult* outResult = new ClientModels::CurrentGamesResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::CurrentGamesResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::CurrentGamesResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnGetCurrentGames, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnGetCurrentGames, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::GetGameServerRegions(
    ClientModels::GameServerRegionsRequest& request,
    ProcessApiCallback<ClientModels::GameServerRegionsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetGameServerRegions"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetGameServerRegionsResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetGameServerRegionsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GameServerRegionsResult* outResult = new ClientModels::GameServerRegionsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GameServerRegionsResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GameServerRegionsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnGetGameServerRegions, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnGetGameServerRegions, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::Matchmake(
    ClientModels::MatchmakeRequest& request,
    ProcessApiCallback<ClientModels::MatchmakeResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/Matchmake"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnMatchmakeResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnMatchmakeResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::MatchmakeResult* outResult = new ClientModels::MatchmakeResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::MatchmakeResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::MatchmakeResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnMatchmake, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnMatchmake, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::StartGame(
    ClientModels::StartGameRequest& request,
    ProcessApiCallback<ClientModels::StartGameResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/StartGame"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnStartGameResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnStartGameResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::StartGameResult* outResult = new ClientModels::StartGameResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::StartGameResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::StartGameResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnStartGame, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnStartGame, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::WriteCharacterEvent(
    ClientModels::WriteClientCharacterEventRequest& request,
    ProcessApiCallback<ClientModels::WriteEventResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/WriteCharacterEvent"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnWriteCharacterEventResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnWriteCharacterEventResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::WriteEventResponse* outResult = new ClientModels::WriteEventResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::WriteEventResponse> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::WriteEventResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnWriteCharacterEvent, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnWriteCharacterEvent, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::WritePlayerEvent(
    ClientModels::WriteClientPlayerEventRequest& request,
    ProcessApiCallback<ClientModels::WriteEventResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/WritePlayerEvent"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnWritePlayerEventResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnWritePlayerEventResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::WriteEventResponse* outResult = new ClientModels::WriteEventResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::WriteEventResponse> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::WriteEventResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnWritePlayerEvent, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnWritePlayerEvent, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::WriteTitleEvent(
    ClientModels::WriteTitleEventRequest& request,
    ProcessApiCallback<ClientModels::WriteEventResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/WriteTitleEvent"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnWriteTitleEventResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnWriteTitleEventResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::WriteEventResponse* outResult = new ClientModels::WriteEventResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::WriteEventResponse> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::WriteEventResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnWriteTitleEvent, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnWriteTitleEvent, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::AddSharedGroupMembers(
    ClientModels::AddSharedGroupMembersRequest& request,
    ProcessApiCallback<ClientModels::AddSharedGroupMembersResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/AddSharedGroupMembers"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnAddSharedGroupMembersResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnAddSharedGroupMembersResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::AddSharedGroupMembersResult* outResult = new ClientModels::AddSharedGroupMembersResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::AddSharedGroupMembersResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::AddSharedGroupMembersResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnAddSharedGroupMembers, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnAddSharedGroupMembers, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::CreateSharedGroup(
    ClientModels::CreateSharedGroupRequest& request,
    ProcessApiCallback<ClientModels::CreateSharedGroupResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/CreateSharedGroup"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnCreateSharedGroupResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnCreateSharedGroupResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::CreateSharedGroupResult* outResult = new ClientModels::CreateSharedGroupResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::CreateSharedGroupResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::CreateSharedGroupResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnCreateSharedGroup, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnCreateSharedGroup, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::GetSharedGroupData(
    ClientModels::GetSharedGroupDataRequest& request,
    ProcessApiCallback<ClientModels::GetSharedGroupDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetSharedGroupData"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetSharedGroupDataResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetSharedGroupDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetSharedGroupDataResult* outResult = new ClientModels::GetSharedGroupDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetSharedGroupDataResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetSharedGroupDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnGetSharedGroupData, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnGetSharedGroupData, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::RemoveSharedGroupMembers(
    ClientModels::RemoveSharedGroupMembersRequest& request,
    ProcessApiCallback<ClientModels::RemoveSharedGroupMembersResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/RemoveSharedGroupMembers"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnRemoveSharedGroupMembersResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnRemoveSharedGroupMembersResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::RemoveSharedGroupMembersResult* outResult = new ClientModels::RemoveSharedGroupMembersResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::RemoveSharedGroupMembersResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::RemoveSharedGroupMembersResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnRemoveSharedGroupMembers, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnRemoveSharedGroupMembers, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::UpdateSharedGroupData(
    ClientModels::UpdateSharedGroupDataRequest& request,
    ProcessApiCallback<ClientModels::UpdateSharedGroupDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/UpdateSharedGroupData"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnUpdateSharedGroupDataResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnUpdateSharedGroupDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::UpdateSharedGroupDataResult* outResult = new ClientModels::UpdateSharedGroupDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::UpdateSharedGroupDataResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::UpdateSharedGroupDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnUpdateSharedGroupData, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnUpdateSharedGroupData, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::ExecuteCloudScript(
    ClientModels::ExecuteCloudScriptRequest& request,
    ProcessApiCallback<ClientModels::ExecuteCloudScriptResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/ExecuteCloudScript"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnExecuteCloudScriptResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnExecuteCloudScriptResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::ExecuteCloudScriptResult* outResult = new ClientModels::ExecuteCloudScriptResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::ExecuteCloudScriptResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::ExecuteCloudScriptResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnExecuteCloudScript, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnExecuteCloudScript, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::GetContentDownloadUrl(
    ClientModels::GetContentDownloadUrlRequest& request,
    ProcessApiCallback<ClientModels::GetContentDownloadUrlResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetContentDownloadUrl"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetContentDownloadUrlResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetContentDownloadUrlResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetContentDownloadUrlResult* outResult = new ClientModels::GetContentDownloadUrlResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetContentDownloadUrlResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetContentDownloadUrlResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnGetContentDownloadUrl, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnGetContentDownloadUrl, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::GetAllUsersCharacters(
    ClientModels::ListUsersCharactersRequest& request,
    ProcessApiCallback<ClientModels::ListUsersCharactersResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetAllUsersCharacters"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetAllUsersCharactersResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetAllUsersCharactersResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::ListUsersCharactersResult* outResult = new ClientModels::ListUsersCharactersResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::ListUsersCharactersResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::ListUsersCharactersResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnGetAllUsersCharacters, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnGetAllUsersCharacters, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::GetCharacterLeaderboard(
    ClientModels::GetCharacterLeaderboardRequest& request,
    ProcessApiCallback<ClientModels::GetCharacterLeaderboardResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetCharacterLeaderboard"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetCharacterLeaderboardResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetCharacterLeaderboardResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetCharacterLeaderboardResult* outResult = new ClientModels::GetCharacterLeaderboardResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetCharacterLeaderboardResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetCharacterLeaderboardResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnGetCharacterLeaderboard, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnGetCharacterLeaderboard, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::GetCharacterStatistics(
    ClientModels::GetCharacterStatisticsRequest& request,
    ProcessApiCallback<ClientModels::GetCharacterStatisticsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetCharacterStatistics"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetCharacterStatisticsResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetCharacterStatisticsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetCharacterStatisticsResult* outResult = new ClientModels::GetCharacterStatisticsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetCharacterStatisticsResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetCharacterStatisticsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnGetCharacterStatistics, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnGetCharacterStatistics, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::GetLeaderboardAroundCharacter(
    ClientModels::GetLeaderboardAroundCharacterRequest& request,
    ProcessApiCallback<ClientModels::GetLeaderboardAroundCharacterResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetLeaderboardAroundCharacter"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetLeaderboardAroundCharacterResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetLeaderboardAroundCharacterResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetLeaderboardAroundCharacterResult* outResult = new ClientModels::GetLeaderboardAroundCharacterResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetLeaderboardAroundCharacterResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetLeaderboardAroundCharacterResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnGetLeaderboardAroundCharacter, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnGetLeaderboardAroundCharacter, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::GetLeaderboardForUserCharacters(
    ClientModels::GetLeaderboardForUsersCharactersRequest& request,
    ProcessApiCallback<ClientModels::GetLeaderboardForUsersCharactersResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetLeaderboardForUserCharacters"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetLeaderboardForUserCharactersResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetLeaderboardForUserCharactersResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetLeaderboardForUsersCharactersResult* outResult = new ClientModels::GetLeaderboardForUsersCharactersResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetLeaderboardForUsersCharactersResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetLeaderboardForUsersCharactersResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnGetLeaderboardForUserCharacters, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnGetLeaderboardForUserCharacters, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::GrantCharacterToUser(
    ClientModels::GrantCharacterToUserRequest& request,
    ProcessApiCallback<ClientModels::GrantCharacterToUserResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GrantCharacterToUser"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGrantCharacterToUserResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGrantCharacterToUserResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GrantCharacterToUserResult* outResult = new ClientModels::GrantCharacterToUserResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GrantCharacterToUserResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GrantCharacterToUserResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnGrantCharacterToUser, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnGrantCharacterToUser, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::UpdateCharacterStatistics(
    ClientModels::UpdateCharacterStatisticsRequest& request,
    ProcessApiCallback<ClientModels::UpdateCharacterStatisticsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/UpdateCharacterStatistics"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnUpdateCharacterStatisticsResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnUpdateCharacterStatisticsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::UpdateCharacterStatisticsResult* outResult = new ClientModels::UpdateCharacterStatisticsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::UpdateCharacterStatisticsResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::UpdateCharacterStatisticsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnUpdateCharacterStatistics, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnUpdateCharacterStatistics, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::GetCharacterData(
    ClientModels::GetCharacterDataRequest& request,
    ProcessApiCallback<ClientModels::GetCharacterDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetCharacterData"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetCharacterDataResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetCharacterDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetCharacterDataResult* outResult = new ClientModels::GetCharacterDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetCharacterDataResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetCharacterDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnGetCharacterData, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnGetCharacterData, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::GetCharacterReadOnlyData(
    ClientModels::GetCharacterDataRequest& request,
    ProcessApiCallback<ClientModels::GetCharacterDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetCharacterReadOnlyData"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetCharacterReadOnlyDataResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetCharacterReadOnlyDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetCharacterDataResult* outResult = new ClientModels::GetCharacterDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetCharacterDataResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetCharacterDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnGetCharacterReadOnlyData, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnGetCharacterReadOnlyData, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::UpdateCharacterData(
    ClientModels::UpdateCharacterDataRequest& request,
    ProcessApiCallback<ClientModels::UpdateCharacterDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/UpdateCharacterData"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnUpdateCharacterDataResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnUpdateCharacterDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::UpdateCharacterDataResult* outResult = new ClientModels::UpdateCharacterDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::UpdateCharacterDataResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::UpdateCharacterDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnUpdateCharacterData, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnUpdateCharacterData, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::AcceptTrade(
    ClientModels::AcceptTradeRequest& request,
    ProcessApiCallback<ClientModels::AcceptTradeResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/AcceptTrade"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnAcceptTradeResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnAcceptTradeResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::AcceptTradeResponse* outResult = new ClientModels::AcceptTradeResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::AcceptTradeResponse> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::AcceptTradeResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnAcceptTrade, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnAcceptTrade, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::CancelTrade(
    ClientModels::CancelTradeRequest& request,
    ProcessApiCallback<ClientModels::CancelTradeResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/CancelTrade"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnCancelTradeResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnCancelTradeResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::CancelTradeResponse* outResult = new ClientModels::CancelTradeResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::CancelTradeResponse> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::CancelTradeResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnCancelTrade, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnCancelTrade, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::GetPlayerTrades(
    ClientModels::GetPlayerTradesRequest& request,
    ProcessApiCallback<ClientModels::GetPlayerTradesResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetPlayerTrades"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetPlayerTradesResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetPlayerTradesResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetPlayerTradesResponse* outResult = new ClientModels::GetPlayerTradesResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetPlayerTradesResponse> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetPlayerTradesResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnGetPlayerTrades, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnGetPlayerTrades, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::GetTradeStatus(
    ClientModels::GetTradeStatusRequest& request,
    ProcessApiCallback<ClientModels::GetTradeStatusResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetTradeStatus"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetTradeStatusResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetTradeStatusResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetTradeStatusResponse* outResult = new ClientModels::GetTradeStatusResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetTradeStatusResponse> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetTradeStatusResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnGetTradeStatus, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnGetTradeStatus, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::OpenTrade(
    ClientModels::OpenTradeRequest& request,
    ProcessApiCallback<ClientModels::OpenTradeResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/OpenTrade"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnOpenTradeResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnOpenTradeResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::OpenTradeResponse* outResult = new ClientModels::OpenTradeResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::OpenTradeResponse> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::OpenTradeResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnOpenTrade, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnOpenTrade, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::AttributeInstall(
    ClientModels::AttributeInstallRequest& request,
    ProcessApiCallback<ClientModels::AttributeInstallResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/AttributeInstall"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnAttributeInstallResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnAttributeInstallResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::AttributeInstallResult* outResult = new ClientModels::AttributeInstallResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);

        // Modify advertisingIdType:  Prevents us from sending the id multiple times, and allows automated tests to determine id was sent successfully
        PlayFabSettings::playFabSettings->advertisingIdType += "_Successful";

        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::AttributeInstallResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::AttributeInstallResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnAttributeInstall, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnAttributeInstall, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::GetPlayerSegments(

    ProcessApiCallback<ClientModels::GetPlayerSegmentsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetPlayerSegments"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, "", customData, callback, errorCallback, OnGetPlayerSegmentsResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetPlayerSegmentsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetPlayerSegmentsResult* outResult = new ClientModels::GetPlayerSegmentsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetPlayerSegmentsResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetPlayerSegmentsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnGetPlayerSegments, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnGetPlayerSegments, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::GetPlayerTags(
    ClientModels::GetPlayerTagsRequest& request,
    ProcessApiCallback<ClientModels::GetPlayerTagsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/GetPlayerTags"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnGetPlayerTagsResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnGetPlayerTagsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::GetPlayerTagsResult* outResult = new ClientModels::GetPlayerTagsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::GetPlayerTagsResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::GetPlayerTagsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnGetPlayerTags, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnGetPlayerTags, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::AndroidDevicePushNotificationRegistration(
    ClientModels::AndroidDevicePushNotificationRegistrationRequest& request,
    ProcessApiCallback<ClientModels::AndroidDevicePushNotificationRegistrationResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/AndroidDevicePushNotificationRegistration"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnAndroidDevicePushNotificationRegistrationResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnAndroidDevicePushNotificationRegistrationResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::AndroidDevicePushNotificationRegistrationResult* outResult = new ClientModels::AndroidDevicePushNotificationRegistrationResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::AndroidDevicePushNotificationRegistrationResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::AndroidDevicePushNotificationRegistrationResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnAndroidDevicePushNotificationRegistration, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnAndroidDevicePushNotificationRegistration, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::RegisterForIOSPushNotification(
    ClientModels::RegisterForIOSPushNotificationRequest& request,
    ProcessApiCallback<ClientModels::RegisterForIOSPushNotificationResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/RegisterForIOSPushNotification"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnRegisterForIOSPushNotificationResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnRegisterForIOSPushNotificationResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::RegisterForIOSPushNotificationResult* outResult = new ClientModels::RegisterForIOSPushNotificationResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::RegisterForIOSPushNotificationResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::RegisterForIOSPushNotificationResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnRegisterForIOSPushNotification, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnRegisterForIOSPushNotification, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::RestoreIOSPurchases(
    ClientModels::RestoreIOSPurchasesRequest& request,
    ProcessApiCallback<ClientModels::RestoreIOSPurchasesResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/RestoreIOSPurchases"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnRestoreIOSPurchasesResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnRestoreIOSPurchasesResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::RestoreIOSPurchasesResult* outResult = new ClientModels::RestoreIOSPurchasesResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::RestoreIOSPurchasesResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::RestoreIOSPurchasesResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnRestoreIOSPurchases, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnRestoreIOSPurchases, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::ValidateAmazonIAPReceipt(
    ClientModels::ValidateAmazonReceiptRequest& request,
    ProcessApiCallback<ClientModels::ValidateAmazonReceiptResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/ValidateAmazonIAPReceipt"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnValidateAmazonIAPReceiptResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnValidateAmazonIAPReceiptResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::ValidateAmazonReceiptResult* outResult = new ClientModels::ValidateAmazonReceiptResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::ValidateAmazonReceiptResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::ValidateAmazonReceiptResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnValidateAmazonIAPReceipt, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnValidateAmazonIAPReceipt, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::ValidateGooglePlayPurchase(
    ClientModels::ValidateGooglePlayPurchaseRequest& request,
    ProcessApiCallback<ClientModels::ValidateGooglePlayPurchaseResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/ValidateGooglePlayPurchase"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnValidateGooglePlayPurchaseResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnValidateGooglePlayPurchaseResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::ValidateGooglePlayPurchaseResult* outResult = new ClientModels::ValidateGooglePlayPurchaseResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::ValidateGooglePlayPurchaseResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::ValidateGooglePlayPurchaseResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnValidateGooglePlayPurchase, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnValidateGooglePlayPurchase, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::ValidateIOSReceipt(
    ClientModels::ValidateIOSReceiptRequest& request,
    ProcessApiCallback<ClientModels::ValidateIOSReceiptResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/ValidateIOSReceipt"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnValidateIOSReceiptResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnValidateIOSReceiptResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::ValidateIOSReceiptResult* outResult = new ClientModels::ValidateIOSReceiptResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::ValidateIOSReceiptResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::ValidateIOSReceiptResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnValidateIOSReceipt, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnValidateIOSReceipt, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabClientApi::ValidateWindowsStoreReceipt(
    ClientModels::ValidateWindowsReceiptRequest& request,
    ProcessApiCallback<ClientModels::ValidateWindowsReceiptResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Client/ValidateWindowsStoreReceipt"), Aws::Http::HttpMethod::HTTP_POST, "X-Authorization", mUserSessionTicket, request.toJSONString(), customData, callback, errorCallback, OnValidateWindowsStoreReceiptResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabClientApi::OnValidateWindowsStoreReceiptResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        ClientModels::ValidateWindowsReceiptResult* outResult = new ClientModels::ValidateWindowsReceiptResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<ClientModels::ValidateWindowsReceiptResult> successCallback = reinterpret_cast<ProcessApiCallback<ClientModels::ValidateWindowsReceiptResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabClient_ClientNotificationBus, OnValidateWindowsStoreReceipt, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabClient_ClientGlobalNotificationBus, OnValidateWindowsStoreReceipt, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

