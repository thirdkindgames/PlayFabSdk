#include "StdAfx.h"
#include "PlayFabAdminApi.h"
#include "PlayFabSettings.h"

#include <AzCore/EBus/EBus.h>
#include "PlayFabServerSdk/PlayFabServer_AdminNotificationBus.h" // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS: dbowen (2017/08/11)

using namespace PlayFabServerSdk;


// #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
void PlayFabAdminApi::OnError(const PlayFabRequest& request, const PlayFabError& error)
{
    EBUS_EVENT_ID(request.mRequestId,PlayFabServer_AdminNotificationBus, OnError, error);     
    EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnError, error, request.mRequestId);
}
// THIRD_KIND_END

// PlayFabAdmin Api
PlayFabAdminApi::PlayFabAdminApi() {}

int PlayFabAdminApi::CreatePlayerSharedSecret(
    AdminModels::CreatePlayerSharedSecretRequest& request,
    ProcessApiCallback<AdminModels::CreatePlayerSharedSecretResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/CreatePlayerSharedSecret"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnCreatePlayerSharedSecretResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnCreatePlayerSharedSecretResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::CreatePlayerSharedSecretResult* outResult = new AdminModels::CreatePlayerSharedSecretResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::CreatePlayerSharedSecretResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::CreatePlayerSharedSecretResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnCreatePlayerSharedSecret, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnCreatePlayerSharedSecret, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::DeletePlayerSharedSecret(
    AdminModels::DeletePlayerSharedSecretRequest& request,
    ProcessApiCallback<AdminModels::DeletePlayerSharedSecretResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/DeletePlayerSharedSecret"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnDeletePlayerSharedSecretResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnDeletePlayerSharedSecretResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::DeletePlayerSharedSecretResult* outResult = new AdminModels::DeletePlayerSharedSecretResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::DeletePlayerSharedSecretResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::DeletePlayerSharedSecretResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnDeletePlayerSharedSecret, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnDeletePlayerSharedSecret, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::GetPlayerSharedSecrets(

    ProcessApiCallback<AdminModels::GetPlayerSharedSecretsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetPlayerSharedSecrets"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, "", customData, callback, errorCallback, OnGetPlayerSharedSecretsResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetPlayerSharedSecretsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GetPlayerSharedSecretsResult* outResult = new AdminModels::GetPlayerSharedSecretsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GetPlayerSharedSecretsResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GetPlayerSharedSecretsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnGetPlayerSharedSecrets, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnGetPlayerSharedSecrets, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::GetPolicy(
    AdminModels::GetPolicyRequest& request,
    ProcessApiCallback<AdminModels::GetPolicyResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetPolicy"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetPolicyResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetPolicyResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GetPolicyResponse* outResult = new AdminModels::GetPolicyResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GetPolicyResponse> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GetPolicyResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnGetPolicy, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnGetPolicy, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::SetPlayerSecret(
    AdminModels::SetPlayerSecretRequest& request,
    ProcessApiCallback<AdminModels::SetPlayerSecretResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/SetPlayerSecret"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnSetPlayerSecretResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnSetPlayerSecretResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::SetPlayerSecretResult* outResult = new AdminModels::SetPlayerSecretResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::SetPlayerSecretResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::SetPlayerSecretResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnSetPlayerSecret, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnSetPlayerSecret, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::UpdatePlayerSharedSecret(
    AdminModels::UpdatePlayerSharedSecretRequest& request,
    ProcessApiCallback<AdminModels::UpdatePlayerSharedSecretResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/UpdatePlayerSharedSecret"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdatePlayerSharedSecretResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnUpdatePlayerSharedSecretResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::UpdatePlayerSharedSecretResult* outResult = new AdminModels::UpdatePlayerSharedSecretResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::UpdatePlayerSharedSecretResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::UpdatePlayerSharedSecretResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnUpdatePlayerSharedSecret, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnUpdatePlayerSharedSecret, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::UpdatePolicy(
    AdminModels::UpdatePolicyRequest& request,
    ProcessApiCallback<AdminModels::UpdatePolicyResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/UpdatePolicy"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdatePolicyResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnUpdatePolicyResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::UpdatePolicyResponse* outResult = new AdminModels::UpdatePolicyResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::UpdatePolicyResponse> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::UpdatePolicyResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnUpdatePolicy, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnUpdatePolicy, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::BanUsers(
    AdminModels::BanUsersRequest& request,
    ProcessApiCallback<AdminModels::BanUsersResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/BanUsers"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnBanUsersResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnBanUsersResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::BanUsersResult* outResult = new AdminModels::BanUsersResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::BanUsersResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::BanUsersResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnBanUsers, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnBanUsers, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::DeletePlayer(
    AdminModels::DeletePlayerRequest& request,
    ProcessApiCallback<AdminModels::DeletePlayerResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/DeletePlayer"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnDeletePlayerResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnDeletePlayerResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::DeletePlayerResult* outResult = new AdminModels::DeletePlayerResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::DeletePlayerResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::DeletePlayerResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnDeletePlayer, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnDeletePlayer, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::GetUserAccountInfo(
    AdminModels::LookupUserAccountInfoRequest& request,
    ProcessApiCallback<AdminModels::LookupUserAccountInfoResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetUserAccountInfo"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetUserAccountInfoResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetUserAccountInfoResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::LookupUserAccountInfoResult* outResult = new AdminModels::LookupUserAccountInfoResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::LookupUserAccountInfoResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::LookupUserAccountInfoResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnGetUserAccountInfo, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnGetUserAccountInfo, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::GetUserBans(
    AdminModels::GetUserBansRequest& request,
    ProcessApiCallback<AdminModels::GetUserBansResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetUserBans"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetUserBansResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetUserBansResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GetUserBansResult* outResult = new AdminModels::GetUserBansResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GetUserBansResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GetUserBansResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnGetUserBans, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnGetUserBans, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::ResetUsers(
    AdminModels::ResetUsersRequest& request,
    ProcessApiCallback<AdminModels::BlankResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/ResetUsers"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnResetUsersResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnResetUsersResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::BlankResult* outResult = new AdminModels::BlankResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::BlankResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::BlankResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnResetUsers, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnResetUsers, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::RevokeAllBansForUser(
    AdminModels::RevokeAllBansForUserRequest& request,
    ProcessApiCallback<AdminModels::RevokeAllBansForUserResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/RevokeAllBansForUser"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnRevokeAllBansForUserResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnRevokeAllBansForUserResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::RevokeAllBansForUserResult* outResult = new AdminModels::RevokeAllBansForUserResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::RevokeAllBansForUserResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::RevokeAllBansForUserResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnRevokeAllBansForUser, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnRevokeAllBansForUser, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::RevokeBans(
    AdminModels::RevokeBansRequest& request,
    ProcessApiCallback<AdminModels::RevokeBansResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/RevokeBans"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnRevokeBansResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnRevokeBansResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::RevokeBansResult* outResult = new AdminModels::RevokeBansResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::RevokeBansResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::RevokeBansResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnRevokeBans, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnRevokeBans, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::SendAccountRecoveryEmail(
    AdminModels::SendAccountRecoveryEmailRequest& request,
    ProcessApiCallback<AdminModels::SendAccountRecoveryEmailResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/SendAccountRecoveryEmail"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnSendAccountRecoveryEmailResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnSendAccountRecoveryEmailResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::SendAccountRecoveryEmailResult* outResult = new AdminModels::SendAccountRecoveryEmailResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::SendAccountRecoveryEmailResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::SendAccountRecoveryEmailResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnSendAccountRecoveryEmail, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnSendAccountRecoveryEmail, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::UpdateBans(
    AdminModels::UpdateBansRequest& request,
    ProcessApiCallback<AdminModels::UpdateBansResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/UpdateBans"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdateBansResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnUpdateBansResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::UpdateBansResult* outResult = new AdminModels::UpdateBansResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::UpdateBansResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::UpdateBansResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnUpdateBans, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnUpdateBans, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::UpdateUserTitleDisplayName(
    AdminModels::UpdateUserTitleDisplayNameRequest& request,
    ProcessApiCallback<AdminModels::UpdateUserTitleDisplayNameResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/UpdateUserTitleDisplayName"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdateUserTitleDisplayNameResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnUpdateUserTitleDisplayNameResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::UpdateUserTitleDisplayNameResult* outResult = new AdminModels::UpdateUserTitleDisplayNameResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::UpdateUserTitleDisplayNameResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::UpdateUserTitleDisplayNameResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnUpdateUserTitleDisplayName, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnUpdateUserTitleDisplayName, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::CreatePlayerStatisticDefinition(
    AdminModels::CreatePlayerStatisticDefinitionRequest& request,
    ProcessApiCallback<AdminModels::CreatePlayerStatisticDefinitionResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/CreatePlayerStatisticDefinition"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnCreatePlayerStatisticDefinitionResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnCreatePlayerStatisticDefinitionResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::CreatePlayerStatisticDefinitionResult* outResult = new AdminModels::CreatePlayerStatisticDefinitionResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::CreatePlayerStatisticDefinitionResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::CreatePlayerStatisticDefinitionResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnCreatePlayerStatisticDefinition, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnCreatePlayerStatisticDefinition, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::DeleteUsers(
    AdminModels::DeleteUsersRequest& request,
    ProcessApiCallback<AdminModels::DeleteUsersResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/DeleteUsers"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnDeleteUsersResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnDeleteUsersResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::DeleteUsersResult* outResult = new AdminModels::DeleteUsersResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::DeleteUsersResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::DeleteUsersResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnDeleteUsers, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnDeleteUsers, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::GetDataReport(
    AdminModels::GetDataReportRequest& request,
    ProcessApiCallback<AdminModels::GetDataReportResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetDataReport"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetDataReportResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetDataReportResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GetDataReportResult* outResult = new AdminModels::GetDataReportResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GetDataReportResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GetDataReportResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnGetDataReport, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnGetDataReport, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::GetPlayerStatisticDefinitions(

    ProcessApiCallback<AdminModels::GetPlayerStatisticDefinitionsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetPlayerStatisticDefinitions"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, "", customData, callback, errorCallback, OnGetPlayerStatisticDefinitionsResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetPlayerStatisticDefinitionsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GetPlayerStatisticDefinitionsResult* outResult = new AdminModels::GetPlayerStatisticDefinitionsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GetPlayerStatisticDefinitionsResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GetPlayerStatisticDefinitionsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnGetPlayerStatisticDefinitions, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnGetPlayerStatisticDefinitions, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::GetPlayerStatisticVersions(
    AdminModels::GetPlayerStatisticVersionsRequest& request,
    ProcessApiCallback<AdminModels::GetPlayerStatisticVersionsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetPlayerStatisticVersions"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetPlayerStatisticVersionsResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetPlayerStatisticVersionsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GetPlayerStatisticVersionsResult* outResult = new AdminModels::GetPlayerStatisticVersionsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GetPlayerStatisticVersionsResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GetPlayerStatisticVersionsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnGetPlayerStatisticVersions, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnGetPlayerStatisticVersions, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::GetUserData(
    AdminModels::GetUserDataRequest& request,
    ProcessApiCallback<AdminModels::GetUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetUserData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetUserDataResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetUserDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GetUserDataResult* outResult = new AdminModels::GetUserDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GetUserDataResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GetUserDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnGetUserData, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnGetUserData, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::GetUserInternalData(
    AdminModels::GetUserDataRequest& request,
    ProcessApiCallback<AdminModels::GetUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetUserInternalData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetUserInternalDataResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetUserInternalDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GetUserDataResult* outResult = new AdminModels::GetUserDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GetUserDataResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GetUserDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnGetUserInternalData, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnGetUserInternalData, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::GetUserPublisherData(
    AdminModels::GetUserDataRequest& request,
    ProcessApiCallback<AdminModels::GetUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetUserPublisherData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetUserPublisherDataResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetUserPublisherDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GetUserDataResult* outResult = new AdminModels::GetUserDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GetUserDataResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GetUserDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnGetUserPublisherData, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnGetUserPublisherData, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::GetUserPublisherInternalData(
    AdminModels::GetUserDataRequest& request,
    ProcessApiCallback<AdminModels::GetUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetUserPublisherInternalData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetUserPublisherInternalDataResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetUserPublisherInternalDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GetUserDataResult* outResult = new AdminModels::GetUserDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GetUserDataResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GetUserDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnGetUserPublisherInternalData, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnGetUserPublisherInternalData, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::GetUserPublisherReadOnlyData(
    AdminModels::GetUserDataRequest& request,
    ProcessApiCallback<AdminModels::GetUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetUserPublisherReadOnlyData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetUserPublisherReadOnlyDataResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetUserPublisherReadOnlyDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GetUserDataResult* outResult = new AdminModels::GetUserDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GetUserDataResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GetUserDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnGetUserPublisherReadOnlyData, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnGetUserPublisherReadOnlyData, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::GetUserReadOnlyData(
    AdminModels::GetUserDataRequest& request,
    ProcessApiCallback<AdminModels::GetUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetUserReadOnlyData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetUserReadOnlyDataResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetUserReadOnlyDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GetUserDataResult* outResult = new AdminModels::GetUserDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GetUserDataResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GetUserDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnGetUserReadOnlyData, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnGetUserReadOnlyData, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::IncrementPlayerStatisticVersion(
    AdminModels::IncrementPlayerStatisticVersionRequest& request,
    ProcessApiCallback<AdminModels::IncrementPlayerStatisticVersionResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/IncrementPlayerStatisticVersion"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnIncrementPlayerStatisticVersionResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnIncrementPlayerStatisticVersionResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::IncrementPlayerStatisticVersionResult* outResult = new AdminModels::IncrementPlayerStatisticVersionResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::IncrementPlayerStatisticVersionResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::IncrementPlayerStatisticVersionResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnIncrementPlayerStatisticVersion, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnIncrementPlayerStatisticVersion, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::RefundPurchase(
    AdminModels::RefundPurchaseRequest& request,
    ProcessApiCallback<AdminModels::RefundPurchaseResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/RefundPurchase"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnRefundPurchaseResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnRefundPurchaseResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::RefundPurchaseResponse* outResult = new AdminModels::RefundPurchaseResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::RefundPurchaseResponse> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::RefundPurchaseResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnRefundPurchase, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnRefundPurchase, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::ResetUserStatistics(
    AdminModels::ResetUserStatisticsRequest& request,
    ProcessApiCallback<AdminModels::ResetUserStatisticsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/ResetUserStatistics"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnResetUserStatisticsResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnResetUserStatisticsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::ResetUserStatisticsResult* outResult = new AdminModels::ResetUserStatisticsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::ResetUserStatisticsResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::ResetUserStatisticsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnResetUserStatistics, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnResetUserStatistics, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::ResolvePurchaseDispute(
    AdminModels::ResolvePurchaseDisputeRequest& request,
    ProcessApiCallback<AdminModels::ResolvePurchaseDisputeResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/ResolvePurchaseDispute"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnResolvePurchaseDisputeResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnResolvePurchaseDisputeResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::ResolvePurchaseDisputeResponse* outResult = new AdminModels::ResolvePurchaseDisputeResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::ResolvePurchaseDisputeResponse> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::ResolvePurchaseDisputeResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnResolvePurchaseDispute, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnResolvePurchaseDispute, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::UpdatePlayerStatisticDefinition(
    AdminModels::UpdatePlayerStatisticDefinitionRequest& request,
    ProcessApiCallback<AdminModels::UpdatePlayerStatisticDefinitionResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/UpdatePlayerStatisticDefinition"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdatePlayerStatisticDefinitionResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnUpdatePlayerStatisticDefinitionResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::UpdatePlayerStatisticDefinitionResult* outResult = new AdminModels::UpdatePlayerStatisticDefinitionResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::UpdatePlayerStatisticDefinitionResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::UpdatePlayerStatisticDefinitionResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnUpdatePlayerStatisticDefinition, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnUpdatePlayerStatisticDefinition, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::UpdateUserData(
    AdminModels::UpdateUserDataRequest& request,
    ProcessApiCallback<AdminModels::UpdateUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/UpdateUserData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdateUserDataResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnUpdateUserDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::UpdateUserDataResult* outResult = new AdminModels::UpdateUserDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::UpdateUserDataResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::UpdateUserDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnUpdateUserData, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnUpdateUserData, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::UpdateUserInternalData(
    AdminModels::UpdateUserInternalDataRequest& request,
    ProcessApiCallback<AdminModels::UpdateUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/UpdateUserInternalData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdateUserInternalDataResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnUpdateUserInternalDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::UpdateUserDataResult* outResult = new AdminModels::UpdateUserDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::UpdateUserDataResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::UpdateUserDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnUpdateUserInternalData, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnUpdateUserInternalData, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::UpdateUserPublisherData(
    AdminModels::UpdateUserDataRequest& request,
    ProcessApiCallback<AdminModels::UpdateUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/UpdateUserPublisherData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdateUserPublisherDataResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnUpdateUserPublisherDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::UpdateUserDataResult* outResult = new AdminModels::UpdateUserDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::UpdateUserDataResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::UpdateUserDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnUpdateUserPublisherData, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnUpdateUserPublisherData, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::UpdateUserPublisherInternalData(
    AdminModels::UpdateUserInternalDataRequest& request,
    ProcessApiCallback<AdminModels::UpdateUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/UpdateUserPublisherInternalData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdateUserPublisherInternalDataResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnUpdateUserPublisherInternalDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::UpdateUserDataResult* outResult = new AdminModels::UpdateUserDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::UpdateUserDataResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::UpdateUserDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnUpdateUserPublisherInternalData, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnUpdateUserPublisherInternalData, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::UpdateUserPublisherReadOnlyData(
    AdminModels::UpdateUserDataRequest& request,
    ProcessApiCallback<AdminModels::UpdateUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/UpdateUserPublisherReadOnlyData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdateUserPublisherReadOnlyDataResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnUpdateUserPublisherReadOnlyDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::UpdateUserDataResult* outResult = new AdminModels::UpdateUserDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::UpdateUserDataResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::UpdateUserDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnUpdateUserPublisherReadOnlyData, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnUpdateUserPublisherReadOnlyData, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::UpdateUserReadOnlyData(
    AdminModels::UpdateUserDataRequest& request,
    ProcessApiCallback<AdminModels::UpdateUserDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/UpdateUserReadOnlyData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdateUserReadOnlyDataResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnUpdateUserReadOnlyDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::UpdateUserDataResult* outResult = new AdminModels::UpdateUserDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::UpdateUserDataResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::UpdateUserDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnUpdateUserReadOnlyData, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnUpdateUserReadOnlyData, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::AddNews(
    AdminModels::AddNewsRequest& request,
    ProcessApiCallback<AdminModels::AddNewsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/AddNews"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnAddNewsResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnAddNewsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::AddNewsResult* outResult = new AdminModels::AddNewsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::AddNewsResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::AddNewsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnAddNews, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnAddNews, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::AddVirtualCurrencyTypes(
    AdminModels::AddVirtualCurrencyTypesRequest& request,
    ProcessApiCallback<AdminModels::BlankResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/AddVirtualCurrencyTypes"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnAddVirtualCurrencyTypesResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnAddVirtualCurrencyTypesResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::BlankResult* outResult = new AdminModels::BlankResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::BlankResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::BlankResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnAddVirtualCurrencyTypes, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnAddVirtualCurrencyTypes, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::DeleteStore(
    AdminModels::DeleteStoreRequest& request,
    ProcessApiCallback<AdminModels::DeleteStoreResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/DeleteStore"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnDeleteStoreResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnDeleteStoreResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::DeleteStoreResult* outResult = new AdminModels::DeleteStoreResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::DeleteStoreResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::DeleteStoreResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnDeleteStore, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnDeleteStore, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::GetCatalogItems(
    AdminModels::GetCatalogItemsRequest& request,
    ProcessApiCallback<AdminModels::GetCatalogItemsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetCatalogItems"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetCatalogItemsResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetCatalogItemsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GetCatalogItemsResult* outResult = new AdminModels::GetCatalogItemsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GetCatalogItemsResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GetCatalogItemsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnGetCatalogItems, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnGetCatalogItems, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::GetPublisherData(
    AdminModels::GetPublisherDataRequest& request,
    ProcessApiCallback<AdminModels::GetPublisherDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetPublisherData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetPublisherDataResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetPublisherDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GetPublisherDataResult* outResult = new AdminModels::GetPublisherDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GetPublisherDataResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GetPublisherDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnGetPublisherData, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnGetPublisherData, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::GetRandomResultTables(
    AdminModels::GetRandomResultTablesRequest& request,
    ProcessApiCallback<AdminModels::GetRandomResultTablesResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetRandomResultTables"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetRandomResultTablesResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetRandomResultTablesResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GetRandomResultTablesResult* outResult = new AdminModels::GetRandomResultTablesResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GetRandomResultTablesResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GetRandomResultTablesResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnGetRandomResultTables, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnGetRandomResultTables, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::GetStoreItems(
    AdminModels::GetStoreItemsRequest& request,
    ProcessApiCallback<AdminModels::GetStoreItemsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetStoreItems"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetStoreItemsResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetStoreItemsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GetStoreItemsResult* outResult = new AdminModels::GetStoreItemsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GetStoreItemsResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GetStoreItemsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnGetStoreItems, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnGetStoreItems, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::GetTitleData(
    AdminModels::GetTitleDataRequest& request,
    ProcessApiCallback<AdminModels::GetTitleDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetTitleData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetTitleDataResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetTitleDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GetTitleDataResult* outResult = new AdminModels::GetTitleDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GetTitleDataResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GetTitleDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnGetTitleData, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnGetTitleData, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::GetTitleInternalData(
    AdminModels::GetTitleDataRequest& request,
    ProcessApiCallback<AdminModels::GetTitleDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetTitleInternalData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetTitleInternalDataResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetTitleInternalDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GetTitleDataResult* outResult = new AdminModels::GetTitleDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GetTitleDataResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GetTitleDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnGetTitleInternalData, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnGetTitleInternalData, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::ListVirtualCurrencyTypes(

    ProcessApiCallback<AdminModels::ListVirtualCurrencyTypesResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/ListVirtualCurrencyTypes"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, "", customData, callback, errorCallback, OnListVirtualCurrencyTypesResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnListVirtualCurrencyTypesResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::ListVirtualCurrencyTypesResult* outResult = new AdminModels::ListVirtualCurrencyTypesResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::ListVirtualCurrencyTypesResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::ListVirtualCurrencyTypesResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnListVirtualCurrencyTypes, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnListVirtualCurrencyTypes, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::RemoveVirtualCurrencyTypes(
    AdminModels::RemoveVirtualCurrencyTypesRequest& request,
    ProcessApiCallback<AdminModels::BlankResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/RemoveVirtualCurrencyTypes"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnRemoveVirtualCurrencyTypesResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnRemoveVirtualCurrencyTypesResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::BlankResult* outResult = new AdminModels::BlankResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::BlankResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::BlankResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnRemoveVirtualCurrencyTypes, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnRemoveVirtualCurrencyTypes, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::SetCatalogItems(
    AdminModels::UpdateCatalogItemsRequest& request,
    ProcessApiCallback<AdminModels::UpdateCatalogItemsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/SetCatalogItems"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnSetCatalogItemsResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnSetCatalogItemsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::UpdateCatalogItemsResult* outResult = new AdminModels::UpdateCatalogItemsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::UpdateCatalogItemsResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::UpdateCatalogItemsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnSetCatalogItems, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnSetCatalogItems, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::SetStoreItems(
    AdminModels::UpdateStoreItemsRequest& request,
    ProcessApiCallback<AdminModels::UpdateStoreItemsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/SetStoreItems"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnSetStoreItemsResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnSetStoreItemsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::UpdateStoreItemsResult* outResult = new AdminModels::UpdateStoreItemsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::UpdateStoreItemsResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::UpdateStoreItemsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnSetStoreItems, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnSetStoreItems, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::SetTitleData(
    AdminModels::SetTitleDataRequest& request,
    ProcessApiCallback<AdminModels::SetTitleDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/SetTitleData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnSetTitleDataResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnSetTitleDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::SetTitleDataResult* outResult = new AdminModels::SetTitleDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::SetTitleDataResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::SetTitleDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnSetTitleData, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnSetTitleData, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::SetTitleInternalData(
    AdminModels::SetTitleDataRequest& request,
    ProcessApiCallback<AdminModels::SetTitleDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/SetTitleInternalData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnSetTitleInternalDataResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnSetTitleInternalDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::SetTitleDataResult* outResult = new AdminModels::SetTitleDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::SetTitleDataResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::SetTitleDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnSetTitleInternalData, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnSetTitleInternalData, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::SetupPushNotification(
    AdminModels::SetupPushNotificationRequest& request,
    ProcessApiCallback<AdminModels::SetupPushNotificationResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/SetupPushNotification"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnSetupPushNotificationResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnSetupPushNotificationResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::SetupPushNotificationResult* outResult = new AdminModels::SetupPushNotificationResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::SetupPushNotificationResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::SetupPushNotificationResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnSetupPushNotification, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnSetupPushNotification, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::UpdateCatalogItems(
    AdminModels::UpdateCatalogItemsRequest& request,
    ProcessApiCallback<AdminModels::UpdateCatalogItemsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/UpdateCatalogItems"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdateCatalogItemsResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnUpdateCatalogItemsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::UpdateCatalogItemsResult* outResult = new AdminModels::UpdateCatalogItemsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::UpdateCatalogItemsResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::UpdateCatalogItemsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnUpdateCatalogItems, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnUpdateCatalogItems, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::UpdateRandomResultTables(
    AdminModels::UpdateRandomResultTablesRequest& request,
    ProcessApiCallback<AdminModels::UpdateRandomResultTablesResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/UpdateRandomResultTables"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdateRandomResultTablesResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnUpdateRandomResultTablesResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::UpdateRandomResultTablesResult* outResult = new AdminModels::UpdateRandomResultTablesResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::UpdateRandomResultTablesResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::UpdateRandomResultTablesResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnUpdateRandomResultTables, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnUpdateRandomResultTables, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::UpdateStoreItems(
    AdminModels::UpdateStoreItemsRequest& request,
    ProcessApiCallback<AdminModels::UpdateStoreItemsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/UpdateStoreItems"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdateStoreItemsResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnUpdateStoreItemsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::UpdateStoreItemsResult* outResult = new AdminModels::UpdateStoreItemsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::UpdateStoreItemsResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::UpdateStoreItemsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnUpdateStoreItems, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnUpdateStoreItems, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::AddUserVirtualCurrency(
    AdminModels::AddUserVirtualCurrencyRequest& request,
    ProcessApiCallback<AdminModels::ModifyUserVirtualCurrencyResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/AddUserVirtualCurrency"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnAddUserVirtualCurrencyResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnAddUserVirtualCurrencyResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::ModifyUserVirtualCurrencyResult* outResult = new AdminModels::ModifyUserVirtualCurrencyResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::ModifyUserVirtualCurrencyResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::ModifyUserVirtualCurrencyResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnAddUserVirtualCurrency, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnAddUserVirtualCurrency, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::GetUserInventory(
    AdminModels::GetUserInventoryRequest& request,
    ProcessApiCallback<AdminModels::GetUserInventoryResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetUserInventory"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetUserInventoryResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetUserInventoryResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GetUserInventoryResult* outResult = new AdminModels::GetUserInventoryResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GetUserInventoryResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GetUserInventoryResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnGetUserInventory, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnGetUserInventory, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::GrantItemsToUsers(
    AdminModels::GrantItemsToUsersRequest& request,
    ProcessApiCallback<AdminModels::GrantItemsToUsersResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GrantItemsToUsers"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGrantItemsToUsersResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGrantItemsToUsersResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GrantItemsToUsersResult* outResult = new AdminModels::GrantItemsToUsersResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GrantItemsToUsersResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GrantItemsToUsersResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnGrantItemsToUsers, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnGrantItemsToUsers, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::RevokeInventoryItem(
    AdminModels::RevokeInventoryItemRequest& request,
    ProcessApiCallback<AdminModels::RevokeInventoryResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/RevokeInventoryItem"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnRevokeInventoryItemResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnRevokeInventoryItemResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::RevokeInventoryResult* outResult = new AdminModels::RevokeInventoryResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::RevokeInventoryResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::RevokeInventoryResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnRevokeInventoryItem, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnRevokeInventoryItem, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::SubtractUserVirtualCurrency(
    AdminModels::SubtractUserVirtualCurrencyRequest& request,
    ProcessApiCallback<AdminModels::ModifyUserVirtualCurrencyResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/SubtractUserVirtualCurrency"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnSubtractUserVirtualCurrencyResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnSubtractUserVirtualCurrencyResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::ModifyUserVirtualCurrencyResult* outResult = new AdminModels::ModifyUserVirtualCurrencyResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::ModifyUserVirtualCurrencyResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::ModifyUserVirtualCurrencyResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnSubtractUserVirtualCurrency, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnSubtractUserVirtualCurrency, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::GetMatchmakerGameInfo(
    AdminModels::GetMatchmakerGameInfoRequest& request,
    ProcessApiCallback<AdminModels::GetMatchmakerGameInfoResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetMatchmakerGameInfo"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetMatchmakerGameInfoResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetMatchmakerGameInfoResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GetMatchmakerGameInfoResult* outResult = new AdminModels::GetMatchmakerGameInfoResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GetMatchmakerGameInfoResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GetMatchmakerGameInfoResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnGetMatchmakerGameInfo, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnGetMatchmakerGameInfo, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::GetMatchmakerGameModes(
    AdminModels::GetMatchmakerGameModesRequest& request,
    ProcessApiCallback<AdminModels::GetMatchmakerGameModesResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetMatchmakerGameModes"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetMatchmakerGameModesResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetMatchmakerGameModesResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GetMatchmakerGameModesResult* outResult = new AdminModels::GetMatchmakerGameModesResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GetMatchmakerGameModesResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GetMatchmakerGameModesResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnGetMatchmakerGameModes, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnGetMatchmakerGameModes, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::ModifyMatchmakerGameModes(
    AdminModels::ModifyMatchmakerGameModesRequest& request,
    ProcessApiCallback<AdminModels::ModifyMatchmakerGameModesResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/ModifyMatchmakerGameModes"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnModifyMatchmakerGameModesResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnModifyMatchmakerGameModesResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::ModifyMatchmakerGameModesResult* outResult = new AdminModels::ModifyMatchmakerGameModesResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::ModifyMatchmakerGameModesResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::ModifyMatchmakerGameModesResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnModifyMatchmakerGameModes, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnModifyMatchmakerGameModes, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::AddServerBuild(
    AdminModels::AddServerBuildRequest& request,
    ProcessApiCallback<AdminModels::AddServerBuildResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/AddServerBuild"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnAddServerBuildResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnAddServerBuildResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::AddServerBuildResult* outResult = new AdminModels::AddServerBuildResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::AddServerBuildResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::AddServerBuildResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnAddServerBuild, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnAddServerBuild, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::GetServerBuildInfo(
    AdminModels::GetServerBuildInfoRequest& request,
    ProcessApiCallback<AdminModels::GetServerBuildInfoResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetServerBuildInfo"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetServerBuildInfoResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetServerBuildInfoResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GetServerBuildInfoResult* outResult = new AdminModels::GetServerBuildInfoResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GetServerBuildInfoResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GetServerBuildInfoResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnGetServerBuildInfo, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnGetServerBuildInfo, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::GetServerBuildUploadUrl(
    AdminModels::GetServerBuildUploadURLRequest& request,
    ProcessApiCallback<AdminModels::GetServerBuildUploadURLResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetServerBuildUploadUrl"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetServerBuildUploadUrlResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetServerBuildUploadUrlResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GetServerBuildUploadURLResult* outResult = new AdminModels::GetServerBuildUploadURLResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GetServerBuildUploadURLResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GetServerBuildUploadURLResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnGetServerBuildUploadUrl, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnGetServerBuildUploadUrl, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::ListServerBuilds(

    ProcessApiCallback<AdminModels::ListBuildsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/ListServerBuilds"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, "", customData, callback, errorCallback, OnListServerBuildsResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnListServerBuildsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::ListBuildsResult* outResult = new AdminModels::ListBuildsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::ListBuildsResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::ListBuildsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnListServerBuilds, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnListServerBuilds, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::ModifyServerBuild(
    AdminModels::ModifyServerBuildRequest& request,
    ProcessApiCallback<AdminModels::ModifyServerBuildResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/ModifyServerBuild"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnModifyServerBuildResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnModifyServerBuildResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::ModifyServerBuildResult* outResult = new AdminModels::ModifyServerBuildResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::ModifyServerBuildResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::ModifyServerBuildResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnModifyServerBuild, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnModifyServerBuild, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::RemoveServerBuild(
    AdminModels::RemoveServerBuildRequest& request,
    ProcessApiCallback<AdminModels::RemoveServerBuildResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/RemoveServerBuild"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnRemoveServerBuildResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnRemoveServerBuildResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::RemoveServerBuildResult* outResult = new AdminModels::RemoveServerBuildResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::RemoveServerBuildResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::RemoveServerBuildResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnRemoveServerBuild, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnRemoveServerBuild, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::SetPublisherData(
    AdminModels::SetPublisherDataRequest& request,
    ProcessApiCallback<AdminModels::SetPublisherDataResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/SetPublisherData"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnSetPublisherDataResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnSetPublisherDataResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::SetPublisherDataResult* outResult = new AdminModels::SetPublisherDataResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::SetPublisherDataResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::SetPublisherDataResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnSetPublisherData, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnSetPublisherData, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::GetCloudScriptRevision(
    AdminModels::GetCloudScriptRevisionRequest& request,
    ProcessApiCallback<AdminModels::GetCloudScriptRevisionResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetCloudScriptRevision"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetCloudScriptRevisionResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetCloudScriptRevisionResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GetCloudScriptRevisionResult* outResult = new AdminModels::GetCloudScriptRevisionResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GetCloudScriptRevisionResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GetCloudScriptRevisionResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnGetCloudScriptRevision, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnGetCloudScriptRevision, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::GetCloudScriptVersions(

    ProcessApiCallback<AdminModels::GetCloudScriptVersionsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetCloudScriptVersions"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, "", customData, callback, errorCallback, OnGetCloudScriptVersionsResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetCloudScriptVersionsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GetCloudScriptVersionsResult* outResult = new AdminModels::GetCloudScriptVersionsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GetCloudScriptVersionsResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GetCloudScriptVersionsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnGetCloudScriptVersions, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnGetCloudScriptVersions, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::SetPublishedRevision(
    AdminModels::SetPublishedRevisionRequest& request,
    ProcessApiCallback<AdminModels::SetPublishedRevisionResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/SetPublishedRevision"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnSetPublishedRevisionResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnSetPublishedRevisionResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::SetPublishedRevisionResult* outResult = new AdminModels::SetPublishedRevisionResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::SetPublishedRevisionResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::SetPublishedRevisionResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnSetPublishedRevision, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnSetPublishedRevision, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::UpdateCloudScript(
    AdminModels::UpdateCloudScriptRequest& request,
    ProcessApiCallback<AdminModels::UpdateCloudScriptResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/UpdateCloudScript"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdateCloudScriptResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnUpdateCloudScriptResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::UpdateCloudScriptResult* outResult = new AdminModels::UpdateCloudScriptResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::UpdateCloudScriptResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::UpdateCloudScriptResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnUpdateCloudScript, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnUpdateCloudScript, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::DeleteContent(
    AdminModels::DeleteContentRequest& request,
    ProcessApiCallback<AdminModels::BlankResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/DeleteContent"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnDeleteContentResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnDeleteContentResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::BlankResult* outResult = new AdminModels::BlankResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::BlankResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::BlankResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnDeleteContent, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnDeleteContent, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::GetContentList(
    AdminModels::GetContentListRequest& request,
    ProcessApiCallback<AdminModels::GetContentListResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetContentList"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetContentListResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetContentListResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GetContentListResult* outResult = new AdminModels::GetContentListResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GetContentListResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GetContentListResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnGetContentList, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnGetContentList, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::GetContentUploadUrl(
    AdminModels::GetContentUploadUrlRequest& request,
    ProcessApiCallback<AdminModels::GetContentUploadUrlResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetContentUploadUrl"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetContentUploadUrlResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetContentUploadUrlResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GetContentUploadUrlResult* outResult = new AdminModels::GetContentUploadUrlResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GetContentUploadUrlResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GetContentUploadUrlResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnGetContentUploadUrl, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnGetContentUploadUrl, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::ResetCharacterStatistics(
    AdminModels::ResetCharacterStatisticsRequest& request,
    ProcessApiCallback<AdminModels::ResetCharacterStatisticsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/ResetCharacterStatistics"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnResetCharacterStatisticsResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnResetCharacterStatisticsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::ResetCharacterStatisticsResult* outResult = new AdminModels::ResetCharacterStatisticsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::ResetCharacterStatisticsResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::ResetCharacterStatisticsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnResetCharacterStatistics, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnResetCharacterStatistics, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::AddPlayerTag(
    AdminModels::AddPlayerTagRequest& request,
    ProcessApiCallback<AdminModels::AddPlayerTagResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/AddPlayerTag"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnAddPlayerTagResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnAddPlayerTagResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::AddPlayerTagResult* outResult = new AdminModels::AddPlayerTagResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::AddPlayerTagResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::AddPlayerTagResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnAddPlayerTag, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnAddPlayerTag, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::GetAllActionGroups(

    ProcessApiCallback<AdminModels::GetAllActionGroupsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetAllActionGroups"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, "", customData, callback, errorCallback, OnGetAllActionGroupsResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetAllActionGroupsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GetAllActionGroupsResult* outResult = new AdminModels::GetAllActionGroupsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GetAllActionGroupsResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GetAllActionGroupsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnGetAllActionGroups, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnGetAllActionGroups, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::GetAllSegments(

    ProcessApiCallback<AdminModels::GetAllSegmentsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetAllSegments"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, "", customData, callback, errorCallback, OnGetAllSegmentsResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetAllSegmentsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GetAllSegmentsResult* outResult = new AdminModels::GetAllSegmentsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GetAllSegmentsResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GetAllSegmentsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnGetAllSegments, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnGetAllSegments, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::GetPlayerSegments(
    AdminModels::GetPlayersSegmentsRequest& request,
    ProcessApiCallback<AdminModels::GetPlayerSegmentsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetPlayerSegments"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetPlayerSegmentsResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetPlayerSegmentsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GetPlayerSegmentsResult* outResult = new AdminModels::GetPlayerSegmentsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GetPlayerSegmentsResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GetPlayerSegmentsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnGetPlayerSegments, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnGetPlayerSegments, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::GetPlayersInSegment(
    AdminModels::GetPlayersInSegmentRequest& request,
    ProcessApiCallback<AdminModels::GetPlayersInSegmentResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetPlayersInSegment"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetPlayersInSegmentResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetPlayersInSegmentResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GetPlayersInSegmentResult* outResult = new AdminModels::GetPlayersInSegmentResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GetPlayersInSegmentResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GetPlayersInSegmentResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnGetPlayersInSegment, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnGetPlayersInSegment, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::GetPlayerTags(
    AdminModels::GetPlayerTagsRequest& request,
    ProcessApiCallback<AdminModels::GetPlayerTagsResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetPlayerTags"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetPlayerTagsResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetPlayerTagsResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GetPlayerTagsResult* outResult = new AdminModels::GetPlayerTagsResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GetPlayerTagsResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GetPlayerTagsResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnGetPlayerTags, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnGetPlayerTags, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::RemovePlayerTag(
    AdminModels::RemovePlayerTagRequest& request,
    ProcessApiCallback<AdminModels::RemovePlayerTagResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/RemovePlayerTag"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnRemovePlayerTagResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnRemovePlayerTagResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::RemovePlayerTagResult* outResult = new AdminModels::RemovePlayerTagResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::RemovePlayerTagResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::RemovePlayerTagResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnRemovePlayerTag, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnRemovePlayerTag, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::AbortTaskInstance(
    AdminModels::AbortTaskInstanceRequest& request,
    ProcessApiCallback<AdminModels::EmptyResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/AbortTaskInstance"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnAbortTaskInstanceResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnAbortTaskInstanceResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::EmptyResult* outResult = new AdminModels::EmptyResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::EmptyResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::EmptyResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnAbortTaskInstance, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnAbortTaskInstance, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::CreateActionsOnPlayersInSegmentTask(
    AdminModels::CreateActionsOnPlayerSegmentTaskRequest& request,
    ProcessApiCallback<AdminModels::CreateTaskResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/CreateActionsOnPlayersInSegmentTask"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnCreateActionsOnPlayersInSegmentTaskResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnCreateActionsOnPlayersInSegmentTaskResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::CreateTaskResult* outResult = new AdminModels::CreateTaskResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::CreateTaskResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::CreateTaskResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnCreateActionsOnPlayersInSegmentTask, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnCreateActionsOnPlayersInSegmentTask, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::CreateCloudScriptTask(
    AdminModels::CreateCloudScriptTaskRequest& request,
    ProcessApiCallback<AdminModels::CreateTaskResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/CreateCloudScriptTask"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnCreateCloudScriptTaskResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnCreateCloudScriptTaskResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::CreateTaskResult* outResult = new AdminModels::CreateTaskResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::CreateTaskResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::CreateTaskResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnCreateCloudScriptTask, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnCreateCloudScriptTask, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::DeleteTask(
    AdminModels::DeleteTaskRequest& request,
    ProcessApiCallback<AdminModels::EmptyResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/DeleteTask"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnDeleteTaskResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnDeleteTaskResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::EmptyResult* outResult = new AdminModels::EmptyResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::EmptyResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::EmptyResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnDeleteTask, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnDeleteTask, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::GetActionsOnPlayersInSegmentTaskInstance(
    AdminModels::GetTaskInstanceRequest& request,
    ProcessApiCallback<AdminModels::GetActionsOnPlayersInSegmentTaskInstanceResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetActionsOnPlayersInSegmentTaskInstance"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetActionsOnPlayersInSegmentTaskInstanceResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetActionsOnPlayersInSegmentTaskInstanceResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GetActionsOnPlayersInSegmentTaskInstanceResult* outResult = new AdminModels::GetActionsOnPlayersInSegmentTaskInstanceResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GetActionsOnPlayersInSegmentTaskInstanceResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GetActionsOnPlayersInSegmentTaskInstanceResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnGetActionsOnPlayersInSegmentTaskInstance, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnGetActionsOnPlayersInSegmentTaskInstance, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::GetCloudScriptTaskInstance(
    AdminModels::GetTaskInstanceRequest& request,
    ProcessApiCallback<AdminModels::GetCloudScriptTaskInstanceResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetCloudScriptTaskInstance"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetCloudScriptTaskInstanceResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetCloudScriptTaskInstanceResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GetCloudScriptTaskInstanceResult* outResult = new AdminModels::GetCloudScriptTaskInstanceResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GetCloudScriptTaskInstanceResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GetCloudScriptTaskInstanceResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnGetCloudScriptTaskInstance, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnGetCloudScriptTaskInstance, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::GetTaskInstances(
    AdminModels::GetTaskInstancesRequest& request,
    ProcessApiCallback<AdminModels::GetTaskInstancesResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetTaskInstances"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetTaskInstancesResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetTaskInstancesResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GetTaskInstancesResult* outResult = new AdminModels::GetTaskInstancesResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GetTaskInstancesResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GetTaskInstancesResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnGetTaskInstances, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnGetTaskInstances, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::GetTasks(
    AdminModels::GetTasksRequest& request,
    ProcessApiCallback<AdminModels::GetTasksResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/GetTasks"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnGetTasksResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnGetTasksResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::GetTasksResult* outResult = new AdminModels::GetTasksResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::GetTasksResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::GetTasksResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnGetTasks, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnGetTasks, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::RunTask(
    AdminModels::RunTaskRequest& request,
    ProcessApiCallback<AdminModels::RunTaskResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/RunTask"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnRunTaskResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnRunTaskResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::RunTaskResult* outResult = new AdminModels::RunTaskResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::RunTaskResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::RunTaskResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnRunTask, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnRunTask, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabAdminApi::UpdateTask(
    AdminModels::UpdateTaskRequest& request,
    ProcessApiCallback<AdminModels::EmptyResult> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Admin/UpdateTask"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUpdateTaskResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabAdminApi::OnUpdateTaskResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        AdminModels::EmptyResult* outResult = new AdminModels::EmptyResult;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<AdminModels::EmptyResult> successCallback = reinterpret_cast<ProcessApiCallback<AdminModels::EmptyResult>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_AdminNotificationBus, OnUpdateTask, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_AdminGlobalNotificationBus, OnUpdateTask, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

