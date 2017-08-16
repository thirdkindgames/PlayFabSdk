
#include "StdAfx.h"

#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>

#include "PlayFabClient_ClientSysComponent.h"

#include "PlayFabSettings.h"
#include "PlayFabClientApi.h"

namespace PlayFabClientSdk
{
    void PlayFabClient_ClientSysComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<PlayFabClient_ClientSysComponent, AZ::Component>()
                ->Version(0)
                ->SerializerForEmptyClass();

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<PlayFabClient_ClientSysComponent>("PlayFabClient_Client", "Provides access to the Client API within the PlayFab Client SDK")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                    // ->Attribute(AZ::Edit::Attributes::Category, "") Set a category
                    ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System"))
                    ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void PlayFabClient_ClientSysComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("PlayFabClient_ClientService"));
    }

    void PlayFabClient_ClientSysComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("PlayFabClient_ClientService"));
    }

    void PlayFabClient_ClientSysComponent::GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required)
    {
        (void)required;
    }

    void PlayFabClient_ClientSysComponent::GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
        (void)dependent;
    }

    void PlayFabClient_ClientSysComponent::Init()
    {
    }

    void PlayFabClient_ClientSysComponent::Activate()
    {
        PlayFabClient_ClientRequestBus::Handler::BusConnect();
        PlayFabClient_ClientSimpleRequestBus::Handler::BusConnect(); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    }

    void PlayFabClient_ClientSysComponent::Deactivate()
    {
        PlayFabClient_ClientRequestBus::Handler::BusDisconnect();
        PlayFabClient_ClientSimpleRequestBus::Handler::BusDisconnect(); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    }

    int PlayFabClient_ClientSysComponent::GetPendingCalls()
    {
        return PlayFabRequestManager::playFabHttp->GetPendingCalls();
    }

    // Client-Specific
    bool PlayFabClient_ClientSysComponent::IsClientLoggedIn()
    {
        return PlayFabClientApi::IsClientLoggedIn();
    }

    // ------------ Generated API call wrappers
    int PlayFabClient_ClientSysComponent::GetPhotonAuthenticationToken(ClientModels::GetPhotonAuthenticationTokenRequest& request, ProcessApiCallback<ClientModels::GetPhotonAuthenticationTokenResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::GetPhotonAuthenticationToken(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::GetPhotonAuthenticationToken(ClientModels::GetPhotonAuthenticationTokenRequest& request)
    {
        return GetPhotonAuthenticationToken(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::GetTitlePublicKey(ClientModels::GetTitlePublicKeyRequest& request, ProcessApiCallback<ClientModels::GetTitlePublicKeyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::GetTitlePublicKey(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::GetTitlePublicKey(ClientModels::GetTitlePublicKeyRequest& request)
    {
        return GetTitlePublicKey(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::GetWindowsHelloChallenge(ClientModels::GetWindowsHelloChallengeRequest& request, ProcessApiCallback<ClientModels::GetWindowsHelloChallengeResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::GetWindowsHelloChallenge(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::GetWindowsHelloChallenge(ClientModels::GetWindowsHelloChallengeRequest& request)
    {
        return GetWindowsHelloChallenge(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::LoginWithAndroidDeviceID(ClientModels::LoginWithAndroidDeviceIDRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::LoginWithAndroidDeviceID(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::LoginWithAndroidDeviceID(ClientModels::LoginWithAndroidDeviceIDRequest& request)
    {
        return LoginWithAndroidDeviceID(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::LoginWithCustomID(ClientModels::LoginWithCustomIDRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::LoginWithCustomID(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::LoginWithCustomID(ClientModels::LoginWithCustomIDRequest& request)
    {
        return LoginWithCustomID(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::LoginWithEmailAddress(ClientModels::LoginWithEmailAddressRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::LoginWithEmailAddress(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::LoginWithEmailAddress(ClientModels::LoginWithEmailAddressRequest& request)
    {
        return LoginWithEmailAddress(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::LoginWithFacebook(ClientModels::LoginWithFacebookRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::LoginWithFacebook(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::LoginWithFacebook(ClientModels::LoginWithFacebookRequest& request)
    {
        return LoginWithFacebook(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::LoginWithGameCenter(ClientModels::LoginWithGameCenterRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::LoginWithGameCenter(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::LoginWithGameCenter(ClientModels::LoginWithGameCenterRequest& request)
    {
        return LoginWithGameCenter(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::LoginWithGoogleAccount(ClientModels::LoginWithGoogleAccountRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::LoginWithGoogleAccount(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::LoginWithGoogleAccount(ClientModels::LoginWithGoogleAccountRequest& request)
    {
        return LoginWithGoogleAccount(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::LoginWithIOSDeviceID(ClientModels::LoginWithIOSDeviceIDRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::LoginWithIOSDeviceID(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::LoginWithIOSDeviceID(ClientModels::LoginWithIOSDeviceIDRequest& request)
    {
        return LoginWithIOSDeviceID(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::LoginWithKongregate(ClientModels::LoginWithKongregateRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::LoginWithKongregate(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::LoginWithKongregate(ClientModels::LoginWithKongregateRequest& request)
    {
        return LoginWithKongregate(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::LoginWithPlayFab(ClientModels::LoginWithPlayFabRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::LoginWithPlayFab(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::LoginWithPlayFab(ClientModels::LoginWithPlayFabRequest& request)
    {
        return LoginWithPlayFab(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::LoginWithSteam(ClientModels::LoginWithSteamRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::LoginWithSteam(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::LoginWithSteam(ClientModels::LoginWithSteamRequest& request)
    {
        return LoginWithSteam(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::LoginWithTwitch(ClientModels::LoginWithTwitchRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::LoginWithTwitch(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::LoginWithTwitch(ClientModels::LoginWithTwitchRequest& request)
    {
        return LoginWithTwitch(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::LoginWithWindowsHello(ClientModels::LoginWithWindowsHelloRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::LoginWithWindowsHello(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::LoginWithWindowsHello(ClientModels::LoginWithWindowsHelloRequest& request)
    {
        return LoginWithWindowsHello(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::RegisterPlayFabUser(ClientModels::RegisterPlayFabUserRequest& request, ProcessApiCallback<ClientModels::RegisterPlayFabUserResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::RegisterPlayFabUser(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::RegisterPlayFabUser(ClientModels::RegisterPlayFabUserRequest& request)
    {
        return RegisterPlayFabUser(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::RegisterWithWindowsHello(ClientModels::RegisterWithWindowsHelloRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::RegisterWithWindowsHello(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::RegisterWithWindowsHello(ClientModels::RegisterWithWindowsHelloRequest& request)
    {
        return RegisterWithWindowsHello(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::SetPlayerSecret(ClientModels::SetPlayerSecretRequest& request, ProcessApiCallback<ClientModels::SetPlayerSecretResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::SetPlayerSecret(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::SetPlayerSecret(ClientModels::SetPlayerSecretRequest& request)
    {
        return SetPlayerSecret(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::AddGenericID(ClientModels::AddGenericIDRequest& request, ProcessApiCallback<ClientModels::AddGenericIDResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::AddGenericID(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::AddGenericID(ClientModels::AddGenericIDRequest& request)
    {
        return AddGenericID(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::AddUsernamePassword(ClientModels::AddUsernamePasswordRequest& request, ProcessApiCallback<ClientModels::AddUsernamePasswordResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::AddUsernamePassword(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::AddUsernamePassword(ClientModels::AddUsernamePasswordRequest& request)
    {
        return AddUsernamePassword(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::GetAccountInfo(ClientModels::GetAccountInfoRequest& request, ProcessApiCallback<ClientModels::GetAccountInfoResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::GetAccountInfo(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::GetAccountInfo(ClientModels::GetAccountInfoRequest& request)
    {
        return GetAccountInfo(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::GetPlayerCombinedInfo(ClientModels::GetPlayerCombinedInfoRequest& request, ProcessApiCallback<ClientModels::GetPlayerCombinedInfoResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::GetPlayerCombinedInfo(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::GetPlayerCombinedInfo(ClientModels::GetPlayerCombinedInfoRequest& request)
    {
        return GetPlayerCombinedInfo(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::GetPlayerProfile(ClientModels::GetPlayerProfileRequest& request, ProcessApiCallback<ClientModels::GetPlayerProfileResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::GetPlayerProfile(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::GetPlayerProfile(ClientModels::GetPlayerProfileRequest& request)
    {
        return GetPlayerProfile(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::GetPlayFabIDsFromFacebookIDs(ClientModels::GetPlayFabIDsFromFacebookIDsRequest& request, ProcessApiCallback<ClientModels::GetPlayFabIDsFromFacebookIDsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::GetPlayFabIDsFromFacebookIDs(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::GetPlayFabIDsFromFacebookIDs(ClientModels::GetPlayFabIDsFromFacebookIDsRequest& request)
    {
        return GetPlayFabIDsFromFacebookIDs(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::GetPlayFabIDsFromGameCenterIDs(ClientModels::GetPlayFabIDsFromGameCenterIDsRequest& request, ProcessApiCallback<ClientModels::GetPlayFabIDsFromGameCenterIDsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::GetPlayFabIDsFromGameCenterIDs(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::GetPlayFabIDsFromGameCenterIDs(ClientModels::GetPlayFabIDsFromGameCenterIDsRequest& request)
    {
        return GetPlayFabIDsFromGameCenterIDs(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::GetPlayFabIDsFromGenericIDs(ClientModels::GetPlayFabIDsFromGenericIDsRequest& request, ProcessApiCallback<ClientModels::GetPlayFabIDsFromGenericIDsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::GetPlayFabIDsFromGenericIDs(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::GetPlayFabIDsFromGenericIDs(ClientModels::GetPlayFabIDsFromGenericIDsRequest& request)
    {
        return GetPlayFabIDsFromGenericIDs(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::GetPlayFabIDsFromGoogleIDs(ClientModels::GetPlayFabIDsFromGoogleIDsRequest& request, ProcessApiCallback<ClientModels::GetPlayFabIDsFromGoogleIDsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::GetPlayFabIDsFromGoogleIDs(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::GetPlayFabIDsFromGoogleIDs(ClientModels::GetPlayFabIDsFromGoogleIDsRequest& request)
    {
        return GetPlayFabIDsFromGoogleIDs(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::GetPlayFabIDsFromKongregateIDs(ClientModels::GetPlayFabIDsFromKongregateIDsRequest& request, ProcessApiCallback<ClientModels::GetPlayFabIDsFromKongregateIDsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::GetPlayFabIDsFromKongregateIDs(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::GetPlayFabIDsFromKongregateIDs(ClientModels::GetPlayFabIDsFromKongregateIDsRequest& request)
    {
        return GetPlayFabIDsFromKongregateIDs(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::GetPlayFabIDsFromSteamIDs(ClientModels::GetPlayFabIDsFromSteamIDsRequest& request, ProcessApiCallback<ClientModels::GetPlayFabIDsFromSteamIDsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::GetPlayFabIDsFromSteamIDs(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::GetPlayFabIDsFromSteamIDs(ClientModels::GetPlayFabIDsFromSteamIDsRequest& request)
    {
        return GetPlayFabIDsFromSteamIDs(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::GetPlayFabIDsFromTwitchIDs(ClientModels::GetPlayFabIDsFromTwitchIDsRequest& request, ProcessApiCallback<ClientModels::GetPlayFabIDsFromTwitchIDsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::GetPlayFabIDsFromTwitchIDs(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::GetPlayFabIDsFromTwitchIDs(ClientModels::GetPlayFabIDsFromTwitchIDsRequest& request)
    {
        return GetPlayFabIDsFromTwitchIDs(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::LinkAndroidDeviceID(ClientModels::LinkAndroidDeviceIDRequest& request, ProcessApiCallback<ClientModels::LinkAndroidDeviceIDResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::LinkAndroidDeviceID(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::LinkAndroidDeviceID(ClientModels::LinkAndroidDeviceIDRequest& request)
    {
        return LinkAndroidDeviceID(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::LinkCustomID(ClientModels::LinkCustomIDRequest& request, ProcessApiCallback<ClientModels::LinkCustomIDResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::LinkCustomID(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::LinkCustomID(ClientModels::LinkCustomIDRequest& request)
    {
        return LinkCustomID(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::LinkFacebookAccount(ClientModels::LinkFacebookAccountRequest& request, ProcessApiCallback<ClientModels::LinkFacebookAccountResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::LinkFacebookAccount(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::LinkFacebookAccount(ClientModels::LinkFacebookAccountRequest& request)
    {
        return LinkFacebookAccount(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::LinkGameCenterAccount(ClientModels::LinkGameCenterAccountRequest& request, ProcessApiCallback<ClientModels::LinkGameCenterAccountResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::LinkGameCenterAccount(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::LinkGameCenterAccount(ClientModels::LinkGameCenterAccountRequest& request)
    {
        return LinkGameCenterAccount(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::LinkGoogleAccount(ClientModels::LinkGoogleAccountRequest& request, ProcessApiCallback<ClientModels::LinkGoogleAccountResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::LinkGoogleAccount(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::LinkGoogleAccount(ClientModels::LinkGoogleAccountRequest& request)
    {
        return LinkGoogleAccount(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::LinkIOSDeviceID(ClientModels::LinkIOSDeviceIDRequest& request, ProcessApiCallback<ClientModels::LinkIOSDeviceIDResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::LinkIOSDeviceID(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::LinkIOSDeviceID(ClientModels::LinkIOSDeviceIDRequest& request)
    {
        return LinkIOSDeviceID(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::LinkKongregate(ClientModels::LinkKongregateAccountRequest& request, ProcessApiCallback<ClientModels::LinkKongregateAccountResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::LinkKongregate(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::LinkKongregate(ClientModels::LinkKongregateAccountRequest& request)
    {
        return LinkKongregate(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::LinkSteamAccount(ClientModels::LinkSteamAccountRequest& request, ProcessApiCallback<ClientModels::LinkSteamAccountResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::LinkSteamAccount(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::LinkSteamAccount(ClientModels::LinkSteamAccountRequest& request)
    {
        return LinkSteamAccount(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::LinkTwitch(ClientModels::LinkTwitchAccountRequest& request, ProcessApiCallback<ClientModels::LinkTwitchAccountResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::LinkTwitch(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::LinkTwitch(ClientModels::LinkTwitchAccountRequest& request)
    {
        return LinkTwitch(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::LinkWindowsHello(ClientModels::LinkWindowsHelloAccountRequest& request, ProcessApiCallback<ClientModels::LinkWindowsHelloAccountResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::LinkWindowsHello(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::LinkWindowsHello(ClientModels::LinkWindowsHelloAccountRequest& request)
    {
        return LinkWindowsHello(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::RemoveGenericID(ClientModels::RemoveGenericIDRequest& request, ProcessApiCallback<ClientModels::RemoveGenericIDResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::RemoveGenericID(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::RemoveGenericID(ClientModels::RemoveGenericIDRequest& request)
    {
        return RemoveGenericID(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::ReportPlayer(ClientModels::ReportPlayerClientRequest& request, ProcessApiCallback<ClientModels::ReportPlayerClientResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::ReportPlayer(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::ReportPlayer(ClientModels::ReportPlayerClientRequest& request)
    {
        return ReportPlayer(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::SendAccountRecoveryEmail(ClientModels::SendAccountRecoveryEmailRequest& request, ProcessApiCallback<ClientModels::SendAccountRecoveryEmailResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::SendAccountRecoveryEmail(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::SendAccountRecoveryEmail(ClientModels::SendAccountRecoveryEmailRequest& request)
    {
        return SendAccountRecoveryEmail(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::UnlinkAndroidDeviceID(ClientModels::UnlinkAndroidDeviceIDRequest& request, ProcessApiCallback<ClientModels::UnlinkAndroidDeviceIDResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::UnlinkAndroidDeviceID(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::UnlinkAndroidDeviceID(ClientModels::UnlinkAndroidDeviceIDRequest& request)
    {
        return UnlinkAndroidDeviceID(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::UnlinkCustomID(ClientModels::UnlinkCustomIDRequest& request, ProcessApiCallback<ClientModels::UnlinkCustomIDResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::UnlinkCustomID(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::UnlinkCustomID(ClientModels::UnlinkCustomIDRequest& request)
    {
        return UnlinkCustomID(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::UnlinkFacebookAccount(ProcessApiCallback<ClientModels::UnlinkFacebookAccountResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::UnlinkFacebookAccount(callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::UnlinkFacebookAccount()
    {
        return UnlinkFacebookAccount(nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::UnlinkGameCenterAccount(ProcessApiCallback<ClientModels::UnlinkGameCenterAccountResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::UnlinkGameCenterAccount(callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::UnlinkGameCenterAccount()
    {
        return UnlinkGameCenterAccount(nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::UnlinkGoogleAccount(ProcessApiCallback<ClientModels::UnlinkGoogleAccountResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::UnlinkGoogleAccount(callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::UnlinkGoogleAccount()
    {
        return UnlinkGoogleAccount(nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::UnlinkIOSDeviceID(ClientModels::UnlinkIOSDeviceIDRequest& request, ProcessApiCallback<ClientModels::UnlinkIOSDeviceIDResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::UnlinkIOSDeviceID(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::UnlinkIOSDeviceID(ClientModels::UnlinkIOSDeviceIDRequest& request)
    {
        return UnlinkIOSDeviceID(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::UnlinkKongregate(ProcessApiCallback<ClientModels::UnlinkKongregateAccountResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::UnlinkKongregate(callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::UnlinkKongregate()
    {
        return UnlinkKongregate(nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::UnlinkSteamAccount(ProcessApiCallback<ClientModels::UnlinkSteamAccountResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::UnlinkSteamAccount(callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::UnlinkSteamAccount()
    {
        return UnlinkSteamAccount(nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::UnlinkTwitch(ProcessApiCallback<ClientModels::UnlinkTwitchAccountResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::UnlinkTwitch(callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::UnlinkTwitch()
    {
        return UnlinkTwitch(nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::UnlinkWindowsHello(ClientModels::UnlinkWindowsHelloAccountRequest& request, ProcessApiCallback<ClientModels::UnlinkWindowsHelloAccountResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::UnlinkWindowsHello(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::UnlinkWindowsHello(ClientModels::UnlinkWindowsHelloAccountRequest& request)
    {
        return UnlinkWindowsHello(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::UpdateAvatarUrl(ClientModels::UpdateAvatarUrlRequest& request, ProcessApiCallback<ClientModels::EmptyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::UpdateAvatarUrl(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::UpdateAvatarUrl(ClientModels::UpdateAvatarUrlRequest& request)
    {
        return UpdateAvatarUrl(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::UpdateUserTitleDisplayName(ClientModels::UpdateUserTitleDisplayNameRequest& request, ProcessApiCallback<ClientModels::UpdateUserTitleDisplayNameResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::UpdateUserTitleDisplayName(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::UpdateUserTitleDisplayName(ClientModels::UpdateUserTitleDisplayNameRequest& request)
    {
        return UpdateUserTitleDisplayName(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::GetFriendLeaderboard(ClientModels::GetFriendLeaderboardRequest& request, ProcessApiCallback<ClientModels::GetLeaderboardResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::GetFriendLeaderboard(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::GetFriendLeaderboard(ClientModels::GetFriendLeaderboardRequest& request)
    {
        return GetFriendLeaderboard(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::GetFriendLeaderboardAroundPlayer(ClientModels::GetFriendLeaderboardAroundPlayerRequest& request, ProcessApiCallback<ClientModels::GetFriendLeaderboardAroundPlayerResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::GetFriendLeaderboardAroundPlayer(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::GetFriendLeaderboardAroundPlayer(ClientModels::GetFriendLeaderboardAroundPlayerRequest& request)
    {
        return GetFriendLeaderboardAroundPlayer(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::GetLeaderboard(ClientModels::GetLeaderboardRequest& request, ProcessApiCallback<ClientModels::GetLeaderboardResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::GetLeaderboard(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::GetLeaderboard(ClientModels::GetLeaderboardRequest& request)
    {
        return GetLeaderboard(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::GetLeaderboardAroundPlayer(ClientModels::GetLeaderboardAroundPlayerRequest& request, ProcessApiCallback<ClientModels::GetLeaderboardAroundPlayerResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::GetLeaderboardAroundPlayer(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::GetLeaderboardAroundPlayer(ClientModels::GetLeaderboardAroundPlayerRequest& request)
    {
        return GetLeaderboardAroundPlayer(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::GetPlayerStatistics(ClientModels::GetPlayerStatisticsRequest& request, ProcessApiCallback<ClientModels::GetPlayerStatisticsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::GetPlayerStatistics(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::GetPlayerStatistics(ClientModels::GetPlayerStatisticsRequest& request)
    {
        return GetPlayerStatistics(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::GetPlayerStatisticVersions(ClientModels::GetPlayerStatisticVersionsRequest& request, ProcessApiCallback<ClientModels::GetPlayerStatisticVersionsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::GetPlayerStatisticVersions(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::GetPlayerStatisticVersions(ClientModels::GetPlayerStatisticVersionsRequest& request)
    {
        return GetPlayerStatisticVersions(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::GetUserData(ClientModels::GetUserDataRequest& request, ProcessApiCallback<ClientModels::GetUserDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::GetUserData(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::GetUserData(ClientModels::GetUserDataRequest& request)
    {
        return GetUserData(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::GetUserPublisherData(ClientModels::GetUserDataRequest& request, ProcessApiCallback<ClientModels::GetUserDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::GetUserPublisherData(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::GetUserPublisherData(ClientModels::GetUserDataRequest& request)
    {
        return GetUserPublisherData(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::GetUserPublisherReadOnlyData(ClientModels::GetUserDataRequest& request, ProcessApiCallback<ClientModels::GetUserDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::GetUserPublisherReadOnlyData(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::GetUserPublisherReadOnlyData(ClientModels::GetUserDataRequest& request)
    {
        return GetUserPublisherReadOnlyData(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::GetUserReadOnlyData(ClientModels::GetUserDataRequest& request, ProcessApiCallback<ClientModels::GetUserDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::GetUserReadOnlyData(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::GetUserReadOnlyData(ClientModels::GetUserDataRequest& request)
    {
        return GetUserReadOnlyData(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::UpdatePlayerStatistics(ClientModels::UpdatePlayerStatisticsRequest& request, ProcessApiCallback<ClientModels::UpdatePlayerStatisticsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::UpdatePlayerStatistics(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::UpdatePlayerStatistics(ClientModels::UpdatePlayerStatisticsRequest& request)
    {
        return UpdatePlayerStatistics(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::UpdateUserData(ClientModels::UpdateUserDataRequest& request, ProcessApiCallback<ClientModels::UpdateUserDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::UpdateUserData(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::UpdateUserData(ClientModels::UpdateUserDataRequest& request)
    {
        return UpdateUserData(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::UpdateUserPublisherData(ClientModels::UpdateUserDataRequest& request, ProcessApiCallback<ClientModels::UpdateUserDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::UpdateUserPublisherData(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::UpdateUserPublisherData(ClientModels::UpdateUserDataRequest& request)
    {
        return UpdateUserPublisherData(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::GetCatalogItems(ClientModels::GetCatalogItemsRequest& request, ProcessApiCallback<ClientModels::GetCatalogItemsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::GetCatalogItems(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::GetCatalogItems(ClientModels::GetCatalogItemsRequest& request)
    {
        return GetCatalogItems(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::GetPublisherData(ClientModels::GetPublisherDataRequest& request, ProcessApiCallback<ClientModels::GetPublisherDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::GetPublisherData(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::GetPublisherData(ClientModels::GetPublisherDataRequest& request)
    {
        return GetPublisherData(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::GetStoreItems(ClientModels::GetStoreItemsRequest& request, ProcessApiCallback<ClientModels::GetStoreItemsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::GetStoreItems(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::GetStoreItems(ClientModels::GetStoreItemsRequest& request)
    {
        return GetStoreItems(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::GetTime(ProcessApiCallback<ClientModels::GetTimeResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::GetTime(callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::GetTime()
    {
        return GetTime(nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::GetTitleData(ClientModels::GetTitleDataRequest& request, ProcessApiCallback<ClientModels::GetTitleDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::GetTitleData(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::GetTitleData(ClientModels::GetTitleDataRequest& request)
    {
        return GetTitleData(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::GetTitleNews(ClientModels::GetTitleNewsRequest& request, ProcessApiCallback<ClientModels::GetTitleNewsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::GetTitleNews(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::GetTitleNews(ClientModels::GetTitleNewsRequest& request)
    {
        return GetTitleNews(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::AddUserVirtualCurrency(ClientModels::AddUserVirtualCurrencyRequest& request, ProcessApiCallback<ClientModels::ModifyUserVirtualCurrencyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::AddUserVirtualCurrency(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::AddUserVirtualCurrency(ClientModels::AddUserVirtualCurrencyRequest& request)
    {
        return AddUserVirtualCurrency(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::ConfirmPurchase(ClientModels::ConfirmPurchaseRequest& request, ProcessApiCallback<ClientModels::ConfirmPurchaseResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::ConfirmPurchase(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::ConfirmPurchase(ClientModels::ConfirmPurchaseRequest& request)
    {
        return ConfirmPurchase(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::ConsumeItem(ClientModels::ConsumeItemRequest& request, ProcessApiCallback<ClientModels::ConsumeItemResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::ConsumeItem(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::ConsumeItem(ClientModels::ConsumeItemRequest& request)
    {
        return ConsumeItem(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::GetCharacterInventory(ClientModels::GetCharacterInventoryRequest& request, ProcessApiCallback<ClientModels::GetCharacterInventoryResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::GetCharacterInventory(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::GetCharacterInventory(ClientModels::GetCharacterInventoryRequest& request)
    {
        return GetCharacterInventory(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::GetPurchase(ClientModels::GetPurchaseRequest& request, ProcessApiCallback<ClientModels::GetPurchaseResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::GetPurchase(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::GetPurchase(ClientModels::GetPurchaseRequest& request)
    {
        return GetPurchase(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::GetUserInventory(ProcessApiCallback<ClientModels::GetUserInventoryResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::GetUserInventory(callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::GetUserInventory()
    {
        return GetUserInventory(nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::PayForPurchase(ClientModels::PayForPurchaseRequest& request, ProcessApiCallback<ClientModels::PayForPurchaseResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::PayForPurchase(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::PayForPurchase(ClientModels::PayForPurchaseRequest& request)
    {
        return PayForPurchase(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::PurchaseItem(ClientModels::PurchaseItemRequest& request, ProcessApiCallback<ClientModels::PurchaseItemResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::PurchaseItem(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::PurchaseItem(ClientModels::PurchaseItemRequest& request)
    {
        return PurchaseItem(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::RedeemCoupon(ClientModels::RedeemCouponRequest& request, ProcessApiCallback<ClientModels::RedeemCouponResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::RedeemCoupon(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::RedeemCoupon(ClientModels::RedeemCouponRequest& request)
    {
        return RedeemCoupon(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::StartPurchase(ClientModels::StartPurchaseRequest& request, ProcessApiCallback<ClientModels::StartPurchaseResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::StartPurchase(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::StartPurchase(ClientModels::StartPurchaseRequest& request)
    {
        return StartPurchase(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::SubtractUserVirtualCurrency(ClientModels::SubtractUserVirtualCurrencyRequest& request, ProcessApiCallback<ClientModels::ModifyUserVirtualCurrencyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::SubtractUserVirtualCurrency(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::SubtractUserVirtualCurrency(ClientModels::SubtractUserVirtualCurrencyRequest& request)
    {
        return SubtractUserVirtualCurrency(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::UnlockContainerInstance(ClientModels::UnlockContainerInstanceRequest& request, ProcessApiCallback<ClientModels::UnlockContainerItemResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::UnlockContainerInstance(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::UnlockContainerInstance(ClientModels::UnlockContainerInstanceRequest& request)
    {
        return UnlockContainerInstance(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::UnlockContainerItem(ClientModels::UnlockContainerItemRequest& request, ProcessApiCallback<ClientModels::UnlockContainerItemResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::UnlockContainerItem(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::UnlockContainerItem(ClientModels::UnlockContainerItemRequest& request)
    {
        return UnlockContainerItem(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::AddFriend(ClientModels::AddFriendRequest& request, ProcessApiCallback<ClientModels::AddFriendResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::AddFriend(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::AddFriend(ClientModels::AddFriendRequest& request)
    {
        return AddFriend(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::GetFriendsList(ClientModels::GetFriendsListRequest& request, ProcessApiCallback<ClientModels::GetFriendsListResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::GetFriendsList(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::GetFriendsList(ClientModels::GetFriendsListRequest& request)
    {
        return GetFriendsList(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::RemoveFriend(ClientModels::RemoveFriendRequest& request, ProcessApiCallback<ClientModels::RemoveFriendResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::RemoveFriend(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::RemoveFriend(ClientModels::RemoveFriendRequest& request)
    {
        return RemoveFriend(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::SetFriendTags(ClientModels::SetFriendTagsRequest& request, ProcessApiCallback<ClientModels::SetFriendTagsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::SetFriendTags(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::SetFriendTags(ClientModels::SetFriendTagsRequest& request)
    {
        return SetFriendTags(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::GetCurrentGames(ClientModels::CurrentGamesRequest& request, ProcessApiCallback<ClientModels::CurrentGamesResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::GetCurrentGames(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::GetCurrentGames(ClientModels::CurrentGamesRequest& request)
    {
        return GetCurrentGames(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::GetGameServerRegions(ClientModels::GameServerRegionsRequest& request, ProcessApiCallback<ClientModels::GameServerRegionsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::GetGameServerRegions(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::GetGameServerRegions(ClientModels::GameServerRegionsRequest& request)
    {
        return GetGameServerRegions(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::Matchmake(ClientModels::MatchmakeRequest& request, ProcessApiCallback<ClientModels::MatchmakeResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::Matchmake(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::Matchmake(ClientModels::MatchmakeRequest& request)
    {
        return Matchmake(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::StartGame(ClientModels::StartGameRequest& request, ProcessApiCallback<ClientModels::StartGameResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::StartGame(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::StartGame(ClientModels::StartGameRequest& request)
    {
        return StartGame(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::WriteCharacterEvent(ClientModels::WriteClientCharacterEventRequest& request, ProcessApiCallback<ClientModels::WriteEventResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::WriteCharacterEvent(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::WriteCharacterEvent(ClientModels::WriteClientCharacterEventRequest& request)
    {
        return WriteCharacterEvent(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::WritePlayerEvent(ClientModels::WriteClientPlayerEventRequest& request, ProcessApiCallback<ClientModels::WriteEventResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::WritePlayerEvent(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::WritePlayerEvent(ClientModels::WriteClientPlayerEventRequest& request)
    {
        return WritePlayerEvent(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::WriteTitleEvent(ClientModels::WriteTitleEventRequest& request, ProcessApiCallback<ClientModels::WriteEventResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::WriteTitleEvent(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::WriteTitleEvent(ClientModels::WriteTitleEventRequest& request)
    {
        return WriteTitleEvent(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::AddSharedGroupMembers(ClientModels::AddSharedGroupMembersRequest& request, ProcessApiCallback<ClientModels::AddSharedGroupMembersResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::AddSharedGroupMembers(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::AddSharedGroupMembers(ClientModels::AddSharedGroupMembersRequest& request)
    {
        return AddSharedGroupMembers(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::CreateSharedGroup(ClientModels::CreateSharedGroupRequest& request, ProcessApiCallback<ClientModels::CreateSharedGroupResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::CreateSharedGroup(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::CreateSharedGroup(ClientModels::CreateSharedGroupRequest& request)
    {
        return CreateSharedGroup(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::GetSharedGroupData(ClientModels::GetSharedGroupDataRequest& request, ProcessApiCallback<ClientModels::GetSharedGroupDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::GetSharedGroupData(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::GetSharedGroupData(ClientModels::GetSharedGroupDataRequest& request)
    {
        return GetSharedGroupData(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::RemoveSharedGroupMembers(ClientModels::RemoveSharedGroupMembersRequest& request, ProcessApiCallback<ClientModels::RemoveSharedGroupMembersResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::RemoveSharedGroupMembers(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::RemoveSharedGroupMembers(ClientModels::RemoveSharedGroupMembersRequest& request)
    {
        return RemoveSharedGroupMembers(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::UpdateSharedGroupData(ClientModels::UpdateSharedGroupDataRequest& request, ProcessApiCallback<ClientModels::UpdateSharedGroupDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::UpdateSharedGroupData(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::UpdateSharedGroupData(ClientModels::UpdateSharedGroupDataRequest& request)
    {
        return UpdateSharedGroupData(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::ExecuteCloudScript(ClientModels::ExecuteCloudScriptRequest& request, ProcessApiCallback<ClientModels::ExecuteCloudScriptResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::ExecuteCloudScript(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::ExecuteCloudScript(ClientModels::ExecuteCloudScriptRequest& request)
    {
        return ExecuteCloudScript(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::GetContentDownloadUrl(ClientModels::GetContentDownloadUrlRequest& request, ProcessApiCallback<ClientModels::GetContentDownloadUrlResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::GetContentDownloadUrl(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::GetContentDownloadUrl(ClientModels::GetContentDownloadUrlRequest& request)
    {
        return GetContentDownloadUrl(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::GetAllUsersCharacters(ClientModels::ListUsersCharactersRequest& request, ProcessApiCallback<ClientModels::ListUsersCharactersResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::GetAllUsersCharacters(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::GetAllUsersCharacters(ClientModels::ListUsersCharactersRequest& request)
    {
        return GetAllUsersCharacters(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::GetCharacterLeaderboard(ClientModels::GetCharacterLeaderboardRequest& request, ProcessApiCallback<ClientModels::GetCharacterLeaderboardResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::GetCharacterLeaderboard(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::GetCharacterLeaderboard(ClientModels::GetCharacterLeaderboardRequest& request)
    {
        return GetCharacterLeaderboard(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::GetCharacterStatistics(ClientModels::GetCharacterStatisticsRequest& request, ProcessApiCallback<ClientModels::GetCharacterStatisticsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::GetCharacterStatistics(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::GetCharacterStatistics(ClientModels::GetCharacterStatisticsRequest& request)
    {
        return GetCharacterStatistics(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::GetLeaderboardAroundCharacter(ClientModels::GetLeaderboardAroundCharacterRequest& request, ProcessApiCallback<ClientModels::GetLeaderboardAroundCharacterResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::GetLeaderboardAroundCharacter(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::GetLeaderboardAroundCharacter(ClientModels::GetLeaderboardAroundCharacterRequest& request)
    {
        return GetLeaderboardAroundCharacter(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::GetLeaderboardForUserCharacters(ClientModels::GetLeaderboardForUsersCharactersRequest& request, ProcessApiCallback<ClientModels::GetLeaderboardForUsersCharactersResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::GetLeaderboardForUserCharacters(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::GetLeaderboardForUserCharacters(ClientModels::GetLeaderboardForUsersCharactersRequest& request)
    {
        return GetLeaderboardForUserCharacters(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::GrantCharacterToUser(ClientModels::GrantCharacterToUserRequest& request, ProcessApiCallback<ClientModels::GrantCharacterToUserResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::GrantCharacterToUser(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::GrantCharacterToUser(ClientModels::GrantCharacterToUserRequest& request)
    {
        return GrantCharacterToUser(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::UpdateCharacterStatistics(ClientModels::UpdateCharacterStatisticsRequest& request, ProcessApiCallback<ClientModels::UpdateCharacterStatisticsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::UpdateCharacterStatistics(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::UpdateCharacterStatistics(ClientModels::UpdateCharacterStatisticsRequest& request)
    {
        return UpdateCharacterStatistics(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::GetCharacterData(ClientModels::GetCharacterDataRequest& request, ProcessApiCallback<ClientModels::GetCharacterDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::GetCharacterData(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::GetCharacterData(ClientModels::GetCharacterDataRequest& request)
    {
        return GetCharacterData(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::GetCharacterReadOnlyData(ClientModels::GetCharacterDataRequest& request, ProcessApiCallback<ClientModels::GetCharacterDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::GetCharacterReadOnlyData(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::GetCharacterReadOnlyData(ClientModels::GetCharacterDataRequest& request)
    {
        return GetCharacterReadOnlyData(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::UpdateCharacterData(ClientModels::UpdateCharacterDataRequest& request, ProcessApiCallback<ClientModels::UpdateCharacterDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::UpdateCharacterData(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::UpdateCharacterData(ClientModels::UpdateCharacterDataRequest& request)
    {
        return UpdateCharacterData(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::AcceptTrade(ClientModels::AcceptTradeRequest& request, ProcessApiCallback<ClientModels::AcceptTradeResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::AcceptTrade(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::AcceptTrade(ClientModels::AcceptTradeRequest& request)
    {
        return AcceptTrade(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::CancelTrade(ClientModels::CancelTradeRequest& request, ProcessApiCallback<ClientModels::CancelTradeResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::CancelTrade(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::CancelTrade(ClientModels::CancelTradeRequest& request)
    {
        return CancelTrade(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::GetPlayerTrades(ClientModels::GetPlayerTradesRequest& request, ProcessApiCallback<ClientModels::GetPlayerTradesResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::GetPlayerTrades(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::GetPlayerTrades(ClientModels::GetPlayerTradesRequest& request)
    {
        return GetPlayerTrades(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::GetTradeStatus(ClientModels::GetTradeStatusRequest& request, ProcessApiCallback<ClientModels::GetTradeStatusResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::GetTradeStatus(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::GetTradeStatus(ClientModels::GetTradeStatusRequest& request)
    {
        return GetTradeStatus(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::OpenTrade(ClientModels::OpenTradeRequest& request, ProcessApiCallback<ClientModels::OpenTradeResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::OpenTrade(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::OpenTrade(ClientModels::OpenTradeRequest& request)
    {
        return OpenTrade(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::AttributeInstall(ClientModels::AttributeInstallRequest& request, ProcessApiCallback<ClientModels::AttributeInstallResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::AttributeInstall(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::AttributeInstall(ClientModels::AttributeInstallRequest& request)
    {
        return AttributeInstall(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::GetPlayerSegments(ProcessApiCallback<ClientModels::GetPlayerSegmentsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::GetPlayerSegments(callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::GetPlayerSegments()
    {
        return GetPlayerSegments(nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::GetPlayerTags(ClientModels::GetPlayerTagsRequest& request, ProcessApiCallback<ClientModels::GetPlayerTagsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::GetPlayerTags(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::GetPlayerTags(ClientModels::GetPlayerTagsRequest& request)
    {
        return GetPlayerTags(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::AndroidDevicePushNotificationRegistration(ClientModels::AndroidDevicePushNotificationRegistrationRequest& request, ProcessApiCallback<ClientModels::AndroidDevicePushNotificationRegistrationResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::AndroidDevicePushNotificationRegistration(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::AndroidDevicePushNotificationRegistration(ClientModels::AndroidDevicePushNotificationRegistrationRequest& request)
    {
        return AndroidDevicePushNotificationRegistration(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::RegisterForIOSPushNotification(ClientModels::RegisterForIOSPushNotificationRequest& request, ProcessApiCallback<ClientModels::RegisterForIOSPushNotificationResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::RegisterForIOSPushNotification(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::RegisterForIOSPushNotification(ClientModels::RegisterForIOSPushNotificationRequest& request)
    {
        return RegisterForIOSPushNotification(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::RestoreIOSPurchases(ClientModels::RestoreIOSPurchasesRequest& request, ProcessApiCallback<ClientModels::RestoreIOSPurchasesResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::RestoreIOSPurchases(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::RestoreIOSPurchases(ClientModels::RestoreIOSPurchasesRequest& request)
    {
        return RestoreIOSPurchases(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::ValidateAmazonIAPReceipt(ClientModels::ValidateAmazonReceiptRequest& request, ProcessApiCallback<ClientModels::ValidateAmazonReceiptResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::ValidateAmazonIAPReceipt(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::ValidateAmazonIAPReceipt(ClientModels::ValidateAmazonReceiptRequest& request)
    {
        return ValidateAmazonIAPReceipt(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::ValidateGooglePlayPurchase(ClientModels::ValidateGooglePlayPurchaseRequest& request, ProcessApiCallback<ClientModels::ValidateGooglePlayPurchaseResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::ValidateGooglePlayPurchase(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::ValidateGooglePlayPurchase(ClientModels::ValidateGooglePlayPurchaseRequest& request)
    {
        return ValidateGooglePlayPurchase(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::ValidateIOSReceipt(ClientModels::ValidateIOSReceiptRequest& request, ProcessApiCallback<ClientModels::ValidateIOSReceiptResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::ValidateIOSReceipt(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::ValidateIOSReceipt(ClientModels::ValidateIOSReceiptRequest& request)
    {
        return ValidateIOSReceipt(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabClient_ClientSysComponent::ValidateWindowsStoreReceipt(ClientModels::ValidateWindowsReceiptRequest& request, ProcessApiCallback<ClientModels::ValidateWindowsReceiptResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabClientApi::ValidateWindowsStoreReceipt(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabClient_ClientSysComponent::ValidateWindowsStoreReceipt(ClientModels::ValidateWindowsReceiptRequest& request)
    {
        return ValidateWindowsStoreReceipt(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
}
