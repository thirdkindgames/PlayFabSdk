
#pragma once

#include <AzCore/Component/Component.h>

#include <PlayFabComboSdk/PlayFabCombo_Matchmakerbus.h>

namespace PlayFabComboSdk
{
    class PlayFabCombo_MatchmakerSysComponent
        : public AZ::Component
        , protected PlayFabCombo_MatchmakerRequestBus::Handler
        , protected PlayFabCombo_MatchmakerSimpleRequestBus::Handler
    {
    public:
        AZ_COMPONENT(PlayFabCombo_MatchmakerSysComponent, "{525A86F9-CFF4-4868-A55F-24F5E76823CC}");

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        int GetPendingCalls() override;

    protected:
        ////////////////////////////////////////////////////////////////////////
        // PlayFabCombo_MatchmakerRequestBus interface implementation

        // ------------ Generated Api calls
        int AuthUser(MatchmakerModels::AuthUserRequest& request, ProcessApiCallback<MatchmakerModels::AuthUserResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int AuthUser(MatchmakerModels::AuthUserRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int PlayerJoined(MatchmakerModels::PlayerJoinedRequest& request, ProcessApiCallback<MatchmakerModels::PlayerJoinedResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int PlayerJoined(MatchmakerModels::PlayerJoinedRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int PlayerLeft(MatchmakerModels::PlayerLeftRequest& request, ProcessApiCallback<MatchmakerModels::PlayerLeftResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int PlayerLeft(MatchmakerModels::PlayerLeftRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int StartGame(MatchmakerModels::StartGameRequest& request, ProcessApiCallback<MatchmakerModels::StartGameResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int StartGame(MatchmakerModels::StartGameRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int UserInfo(MatchmakerModels::UserInfoRequest& request, ProcessApiCallback<MatchmakerModels::UserInfoResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int UserInfo(MatchmakerModels::UserInfoRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
