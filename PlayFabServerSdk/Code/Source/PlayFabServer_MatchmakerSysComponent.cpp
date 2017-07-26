
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
        // Start the http request manager thread
        PlayFabRequestManager::playFabHttp = new PlayFabRequestManager();

        PlayFabServer_MatchmakerRequestBus::Handler::BusConnect();
    }

    void PlayFabServer_MatchmakerSysComponent::Deactivate()
    {
        PlayFabServer_MatchmakerRequestBus::Handler::BusDisconnect();

        // Shut down the http handler thread
        if (PlayFabRequestManager::playFabHttp)
        {
            delete PlayFabRequestManager::playFabHttp;
            PlayFabRequestManager::playFabHttp = nullptr;
        }
    }

    // ------------ Generated API call wrappers
    void PlayFabServer_MatchmakerSysComponent::AuthUser(MatchmakerModels::AuthUserRequest& request, ProcessApiCallback<MatchmakerModels::AuthUserResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabMatchmakerApi::AuthUser(request, callback, errorCallback, customData);
    }
    void PlayFabServer_MatchmakerSysComponent::PlayerJoined(MatchmakerModels::PlayerJoinedRequest& request, ProcessApiCallback<MatchmakerModels::PlayerJoinedResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabMatchmakerApi::PlayerJoined(request, callback, errorCallback, customData);
    }
    void PlayFabServer_MatchmakerSysComponent::PlayerLeft(MatchmakerModels::PlayerLeftRequest& request, ProcessApiCallback<MatchmakerModels::PlayerLeftResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabMatchmakerApi::PlayerLeft(request, callback, errorCallback, customData);
    }
    void PlayFabServer_MatchmakerSysComponent::StartGame(MatchmakerModels::StartGameRequest& request, ProcessApiCallback<MatchmakerModels::StartGameResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabMatchmakerApi::StartGame(request, callback, errorCallback, customData);
    }
    void PlayFabServer_MatchmakerSysComponent::UserInfo(MatchmakerModels::UserInfoRequest& request, ProcessApiCallback<MatchmakerModels::UserInfoResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabMatchmakerApi::UserInfo(request, callback, errorCallback, customData);
    }
}
