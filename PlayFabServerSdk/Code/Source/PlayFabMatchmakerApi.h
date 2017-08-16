#pragma once

#include <PlayFabServerSdk/PlayFabError.h>
#include <PlayFabServerSdk/PlayFabMatchmakerDataModels.h>
#include <PlayFabServerSdk/PlayFabHttp.h>

namespace PlayFabServerSdk
{
    class PlayFabMatchmakerApi
    {
    public:


        // ------------ Error callback
        static void OnError(const PlayFabRequest& request, const PlayFabError& error);

        // ------------ Generated Api calls
        static int AuthUser(MatchmakerModels::AuthUserRequest& request, ProcessApiCallback<MatchmakerModels::AuthUserResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int PlayerJoined(MatchmakerModels::PlayerJoinedRequest& request, ProcessApiCallback<MatchmakerModels::PlayerJoinedResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int PlayerLeft(MatchmakerModels::PlayerLeftRequest& request, ProcessApiCallback<MatchmakerModels::PlayerLeftResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int StartGame(MatchmakerModels::StartGameRequest& request, ProcessApiCallback<MatchmakerModels::StartGameResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);
        static int UserInfo(MatchmakerModels::UserInfoRequest& request, ProcessApiCallback<MatchmakerModels::UserInfoResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr);

    private:
        // ------------ Private constructor, to enforce all-static class
        PlayFabMatchmakerApi();

        // ------------ Generated result handlers
        static void OnAuthUserResult(PlayFabRequest* request);
        static void OnPlayerJoinedResult(PlayFabRequest* request);
        static void OnPlayerLeftResult(PlayFabRequest* request);
        static void OnStartGameResult(PlayFabRequest* request);
        static void OnUserInfoResult(PlayFabRequest* request);
    };
};
