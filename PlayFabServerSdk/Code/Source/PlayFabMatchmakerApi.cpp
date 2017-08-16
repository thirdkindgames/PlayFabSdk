#include "StdAfx.h"
#include "PlayFabMatchmakerApi.h"
#include "PlayFabSettings.h"

#include <AzCore/EBus/EBus.h>
#include "PlayFabServerSdk/PlayFabServer_MatchmakerNotificationBus.h" // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS: dbowen (2017/08/11)

using namespace PlayFabServerSdk;


// #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
void PlayFabMatchmakerApi::OnError(const PlayFabRequest& request, const PlayFabError& error)
{
    EBUS_EVENT_ID(request.mRequestId,PlayFabServer_MatchmakerNotificationBus, OnError, error);     
    EBUS_EVENT(PlayFabServer_MatchmakerGlobalNotificationBus, OnError, error, request.mRequestId);
}
// THIRD_KIND_END

// PlayFabMatchmaker Api
PlayFabMatchmakerApi::PlayFabMatchmakerApi() {}

int PlayFabMatchmakerApi::AuthUser(
    MatchmakerModels::AuthUserRequest& request,
    ProcessApiCallback<MatchmakerModels::AuthUserResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Matchmaker/AuthUser"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnAuthUserResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabMatchmakerApi::OnAuthUserResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        MatchmakerModels::AuthUserResponse* outResult = new MatchmakerModels::AuthUserResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<MatchmakerModels::AuthUserResponse> successCallback = reinterpret_cast<ProcessApiCallback<MatchmakerModels::AuthUserResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_MatchmakerNotificationBus, OnAuthUser, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_MatchmakerGlobalNotificationBus, OnAuthUser, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabMatchmakerApi::PlayerJoined(
    MatchmakerModels::PlayerJoinedRequest& request,
    ProcessApiCallback<MatchmakerModels::PlayerJoinedResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Matchmaker/PlayerJoined"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnPlayerJoinedResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabMatchmakerApi::OnPlayerJoinedResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        MatchmakerModels::PlayerJoinedResponse* outResult = new MatchmakerModels::PlayerJoinedResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<MatchmakerModels::PlayerJoinedResponse> successCallback = reinterpret_cast<ProcessApiCallback<MatchmakerModels::PlayerJoinedResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_MatchmakerNotificationBus, OnPlayerJoined, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_MatchmakerGlobalNotificationBus, OnPlayerJoined, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabMatchmakerApi::PlayerLeft(
    MatchmakerModels::PlayerLeftRequest& request,
    ProcessApiCallback<MatchmakerModels::PlayerLeftResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Matchmaker/PlayerLeft"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnPlayerLeftResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabMatchmakerApi::OnPlayerLeftResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        MatchmakerModels::PlayerLeftResponse* outResult = new MatchmakerModels::PlayerLeftResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<MatchmakerModels::PlayerLeftResponse> successCallback = reinterpret_cast<ProcessApiCallback<MatchmakerModels::PlayerLeftResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_MatchmakerNotificationBus, OnPlayerLeft, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_MatchmakerGlobalNotificationBus, OnPlayerLeft, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabMatchmakerApi::StartGame(
    MatchmakerModels::StartGameRequest& request,
    ProcessApiCallback<MatchmakerModels::StartGameResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Matchmaker/StartGame"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnStartGameResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabMatchmakerApi::OnStartGameResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        MatchmakerModels::StartGameResponse* outResult = new MatchmakerModels::StartGameResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<MatchmakerModels::StartGameResponse> successCallback = reinterpret_cast<ProcessApiCallback<MatchmakerModels::StartGameResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_MatchmakerNotificationBus, OnStartGame, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_MatchmakerGlobalNotificationBus, OnStartGame, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

int PlayFabMatchmakerApi::UserInfo(
    MatchmakerModels::UserInfoRequest& request,
    ProcessApiCallback<MatchmakerModels::UserInfoResponse> callback,
    ErrorCallback errorCallback,
    void* customData
)
{

    PlayFabRequest* newRequest = new PlayFabRequest(PlayFabSettings::playFabSettings->getURL("/Matchmaker/UserInfo"), Aws::Http::HttpMethod::HTTP_POST, "X-SecretKey", PlayFabSettings::playFabSettings->developerSecretKey, request.toJSONString(), customData, callback, errorCallback, OnUserInfoResult, OnError);
    return PlayFabRequestManager::playFabHttp->AddRequest(newRequest);
}

void PlayFabMatchmakerApi::OnUserInfoResult(PlayFabRequest* request)
{
    if (PlayFabBaseModel::DecodeRequest(request))
    {
        MatchmakerModels::UserInfoResponse* outResult = new MatchmakerModels::UserInfoResponse;
        outResult->readFromValue(request->mResponseJson->FindMember("data")->value);


        if (request->mResultCallback != nullptr)
        {
            ProcessApiCallback<MatchmakerModels::UserInfoResponse> successCallback = reinterpret_cast<ProcessApiCallback<MatchmakerModels::UserInfoResponse>>(request->mResultCallback);
            successCallback(*outResult, request->mCustomData);
        }

		EBUS_EVENT_ID(request->mRequestId,PlayFabServer_MatchmakerNotificationBus, OnUserInfo, *outResult); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)
        EBUS_EVENT(PlayFabServer_MatchmakerGlobalNotificationBus, OnUserInfo, *outResult, request->mRequestId); // #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS_: dbowen (2017/08/11)

        delete outResult;
        delete request;
    }
}

