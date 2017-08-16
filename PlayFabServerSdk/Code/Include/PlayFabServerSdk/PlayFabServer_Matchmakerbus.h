
#pragma once

#include <PlayFabServerSdk/PlayFabError.h>
#include <PlayFabServerSdk/PlayFabMatchmakerDataModels.h>
#include <AzCore/EBus/EBus.h>

namespace PlayFabServerSdk
{
    class PlayFabServer_MatchmakerRequests
        : public AZ::EBusTraits
    {

    public:
        static const AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static const AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;

        virtual int GetPendingCalls() = 0;

        // ------------ Generated API call wrappers
        virtual int AuthUser(MatchmakerModels::AuthUserRequest& request, ProcessApiCallback<MatchmakerModels::AuthUserResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual int PlayerJoined(MatchmakerModels::PlayerJoinedRequest& request, ProcessApiCallback<MatchmakerModels::PlayerJoinedResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual int PlayerLeft(MatchmakerModels::PlayerLeftRequest& request, ProcessApiCallback<MatchmakerModels::PlayerLeftResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual int StartGame(MatchmakerModels::StartGameRequest& request, ProcessApiCallback<MatchmakerModels::StartGameResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual int UserInfo(MatchmakerModels::UserInfoRequest& request, ProcessApiCallback<MatchmakerModels::UserInfoResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
    };

    using PlayFabServer_MatchmakerRequestBus = AZ::EBus<PlayFabServer_MatchmakerRequests>;

    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    // Simple request bus API - this version is exposed to Behavior context (Lua) and does not allow callbacks to be set.
    // This is because behavior context has no way to set the callbacks (it uses a notification bus instead), additionally
    // it does not support optional arguments in the bus interface so without this we would need to supply "nil" values
    // for each callback function in Lua.
    class PlayFabServer_MatchmakerSimpleRequests
        : public AZ::EBusTraits
    {

    public:
        static const AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static const AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;

        virtual int GetPendingCalls() = 0;

        // ------------ Generated API call wrappers
        virtual int AuthUser(MatchmakerModels::AuthUserRequest& request) = 0;
        virtual int PlayerJoined(MatchmakerModels::PlayerJoinedRequest& request) = 0;
        virtual int PlayerLeft(MatchmakerModels::PlayerLeftRequest& request) = 0;
        virtual int StartGame(MatchmakerModels::StartGameRequest& request) = 0;
        virtual int UserInfo(MatchmakerModels::UserInfoRequest& request) = 0;
    };

    using PlayFabServer_MatchmakerSimpleRequestBus = AZ::EBus<PlayFabServer_MatchmakerSimpleRequests>;
    // #THIRD_KIND_END

} // namespace PlayFabServerSdk
