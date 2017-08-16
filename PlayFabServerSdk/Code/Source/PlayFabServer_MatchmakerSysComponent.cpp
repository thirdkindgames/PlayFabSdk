
#include "StdAfx.h"

#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>

#include "PlayFabServer_MatchmakerSysComponent.h"

#include "PlayFabSettings.h"
#include "PlayFabMatchmakerApi.h"

namespace PlayFabServerSdk
{
    void PlayFabServer_MatchmakerSysComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<PlayFabServer_MatchmakerSysComponent, AZ::Component>()
                ->Version(0)
                ->SerializerForEmptyClass();

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<PlayFabServer_MatchmakerSysComponent>("PlayFabServer_Matchmaker", "Provides access to the Matchmaker API within the PlayFab Server SDK")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                    // ->Attribute(AZ::Edit::Attributes::Category, "") Set a category
                    ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System"))
                    ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void PlayFabServer_MatchmakerSysComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("PlayFabServer_MatchmakerService"));
    }

    void PlayFabServer_MatchmakerSysComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("PlayFabServer_MatchmakerService"));
    }

    void PlayFabServer_MatchmakerSysComponent::GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required)
    {
        (void)required;
    }

    void PlayFabServer_MatchmakerSysComponent::GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
        (void)dependent;
    }

    void PlayFabServer_MatchmakerSysComponent::Init()
    {
    }

    void PlayFabServer_MatchmakerSysComponent::Activate()
    {
        PlayFabServer_MatchmakerRequestBus::Handler::BusConnect();
        PlayFabServer_MatchmakerSimpleRequestBus::Handler::BusConnect(); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    }

    void PlayFabServer_MatchmakerSysComponent::Deactivate()
    {
        PlayFabServer_MatchmakerRequestBus::Handler::BusDisconnect();
        PlayFabServer_MatchmakerSimpleRequestBus::Handler::BusDisconnect(); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    }

    int PlayFabServer_MatchmakerSysComponent::GetPendingCalls()
    {
        return PlayFabRequestManager::playFabHttp->GetPendingCalls();
    }

    // ------------ Generated API call wrappers
    int PlayFabServer_MatchmakerSysComponent::AuthUser(MatchmakerModels::AuthUserRequest& request, ProcessApiCallback<MatchmakerModels::AuthUserResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabMatchmakerApi::AuthUser(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_MatchmakerSysComponent::AuthUser(MatchmakerModels::AuthUserRequest& request)
    {
        return AuthUser(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_MatchmakerSysComponent::PlayerJoined(MatchmakerModels::PlayerJoinedRequest& request, ProcessApiCallback<MatchmakerModels::PlayerJoinedResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabMatchmakerApi::PlayerJoined(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_MatchmakerSysComponent::PlayerJoined(MatchmakerModels::PlayerJoinedRequest& request)
    {
        return PlayerJoined(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_MatchmakerSysComponent::PlayerLeft(MatchmakerModels::PlayerLeftRequest& request, ProcessApiCallback<MatchmakerModels::PlayerLeftResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabMatchmakerApi::PlayerLeft(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_MatchmakerSysComponent::PlayerLeft(MatchmakerModels::PlayerLeftRequest& request)
    {
        return PlayerLeft(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_MatchmakerSysComponent::StartGame(MatchmakerModels::StartGameRequest& request, ProcessApiCallback<MatchmakerModels::StartGameResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabMatchmakerApi::StartGame(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_MatchmakerSysComponent::StartGame(MatchmakerModels::StartGameRequest& request)
    {
        return StartGame(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_MatchmakerSysComponent::UserInfo(MatchmakerModels::UserInfoRequest& request, ProcessApiCallback<MatchmakerModels::UserInfoResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabMatchmakerApi::UserInfo(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_MatchmakerSysComponent::UserInfo(MatchmakerModels::UserInfoRequest& request)
    {
        return UserInfo(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
}
