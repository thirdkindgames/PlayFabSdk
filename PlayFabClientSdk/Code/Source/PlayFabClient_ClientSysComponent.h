
#pragma once

#include <AzCore/Component/Component.h>

#include <PlayFabClientSdk/PlayFabClient_Clientbus.h>

namespace PlayFabClientSdk
{
    class PlayFabClient_ClientSysComponent
        : public AZ::Component
        , protected PlayFabClient_ClientRequestBus::Handler
        , protected PlayFabClient_ClientSimpleRequestBus::Handler
    {
    public:
        AZ_COMPONENT(PlayFabClient_ClientSysComponent, "{FDEEA325-EC4C-4D4B-9FBD-E64A8D523CE6}");

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        int GetPendingCalls() override;

    protected:
        ////////////////////////////////////////////////////////////////////////
        // PlayFabClient_ClientRequestBus interface implementation

        // Public, Client-Specific
        bool IsClientLoggedIn() override;

        // ------------ Generated Api calls
        int GetPhotonAuthenticationToken(ClientModels::GetPhotonAuthenticationTokenRequest& request, ProcessApiCallback<ClientModels::GetPhotonAuthenticationTokenResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int GetPhotonAuthenticationToken(ClientModels::GetPhotonAuthenticationTokenRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int GetTitlePublicKey(ClientModels::GetTitlePublicKeyRequest& request, ProcessApiCallback<ClientModels::GetTitlePublicKeyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int GetTitlePublicKey(ClientModels::GetTitlePublicKeyRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int GetWindowsHelloChallenge(ClientModels::GetWindowsHelloChallengeRequest& request, ProcessApiCallback<ClientModels::GetWindowsHelloChallengeResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int GetWindowsHelloChallenge(ClientModels::GetWindowsHelloChallengeRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int LoginWithAndroidDeviceID(ClientModels::LoginWithAndroidDeviceIDRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int LoginWithAndroidDeviceID(ClientModels::LoginWithAndroidDeviceIDRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int LoginWithCustomID(ClientModels::LoginWithCustomIDRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int LoginWithCustomID(ClientModels::LoginWithCustomIDRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int LoginWithEmailAddress(ClientModels::LoginWithEmailAddressRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int LoginWithEmailAddress(ClientModels::LoginWithEmailAddressRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int LoginWithFacebook(ClientModels::LoginWithFacebookRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int LoginWithFacebook(ClientModels::LoginWithFacebookRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int LoginWithGameCenter(ClientModels::LoginWithGameCenterRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int LoginWithGameCenter(ClientModels::LoginWithGameCenterRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int LoginWithGoogleAccount(ClientModels::LoginWithGoogleAccountRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int LoginWithGoogleAccount(ClientModels::LoginWithGoogleAccountRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int LoginWithIOSDeviceID(ClientModels::LoginWithIOSDeviceIDRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int LoginWithIOSDeviceID(ClientModels::LoginWithIOSDeviceIDRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int LoginWithKongregate(ClientModels::LoginWithKongregateRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int LoginWithKongregate(ClientModels::LoginWithKongregateRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int LoginWithPlayFab(ClientModels::LoginWithPlayFabRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int LoginWithPlayFab(ClientModels::LoginWithPlayFabRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int LoginWithSteam(ClientModels::LoginWithSteamRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int LoginWithSteam(ClientModels::LoginWithSteamRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int LoginWithTwitch(ClientModels::LoginWithTwitchRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int LoginWithTwitch(ClientModels::LoginWithTwitchRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int LoginWithWindowsHello(ClientModels::LoginWithWindowsHelloRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int LoginWithWindowsHello(ClientModels::LoginWithWindowsHelloRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int RegisterPlayFabUser(ClientModels::RegisterPlayFabUserRequest& request, ProcessApiCallback<ClientModels::RegisterPlayFabUserResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int RegisterPlayFabUser(ClientModels::RegisterPlayFabUserRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int RegisterWithWindowsHello(ClientModels::RegisterWithWindowsHelloRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int RegisterWithWindowsHello(ClientModels::RegisterWithWindowsHelloRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int SetPlayerSecret(ClientModels::SetPlayerSecretRequest& request, ProcessApiCallback<ClientModels::SetPlayerSecretResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int SetPlayerSecret(ClientModels::SetPlayerSecretRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int AddGenericID(ClientModels::AddGenericIDRequest& request, ProcessApiCallback<ClientModels::AddGenericIDResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int AddGenericID(ClientModels::AddGenericIDRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int AddUsernamePassword(ClientModels::AddUsernamePasswordRequest& request, ProcessApiCallback<ClientModels::AddUsernamePasswordResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int AddUsernamePassword(ClientModels::AddUsernamePasswordRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int GetAccountInfo(ClientModels::GetAccountInfoRequest& request, ProcessApiCallback<ClientModels::GetAccountInfoResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int GetAccountInfo(ClientModels::GetAccountInfoRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int GetPlayerCombinedInfo(ClientModels::GetPlayerCombinedInfoRequest& request, ProcessApiCallback<ClientModels::GetPlayerCombinedInfoResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int GetPlayerCombinedInfo(ClientModels::GetPlayerCombinedInfoRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int GetPlayerProfile(ClientModels::GetPlayerProfileRequest& request, ProcessApiCallback<ClientModels::GetPlayerProfileResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int GetPlayerProfile(ClientModels::GetPlayerProfileRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int GetPlayFabIDsFromFacebookIDs(ClientModels::GetPlayFabIDsFromFacebookIDsRequest& request, ProcessApiCallback<ClientModels::GetPlayFabIDsFromFacebookIDsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int GetPlayFabIDsFromFacebookIDs(ClientModels::GetPlayFabIDsFromFacebookIDsRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int GetPlayFabIDsFromGameCenterIDs(ClientModels::GetPlayFabIDsFromGameCenterIDsRequest& request, ProcessApiCallback<ClientModels::GetPlayFabIDsFromGameCenterIDsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int GetPlayFabIDsFromGameCenterIDs(ClientModels::GetPlayFabIDsFromGameCenterIDsRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int GetPlayFabIDsFromGenericIDs(ClientModels::GetPlayFabIDsFromGenericIDsRequest& request, ProcessApiCallback<ClientModels::GetPlayFabIDsFromGenericIDsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int GetPlayFabIDsFromGenericIDs(ClientModels::GetPlayFabIDsFromGenericIDsRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int GetPlayFabIDsFromGoogleIDs(ClientModels::GetPlayFabIDsFromGoogleIDsRequest& request, ProcessApiCallback<ClientModels::GetPlayFabIDsFromGoogleIDsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int GetPlayFabIDsFromGoogleIDs(ClientModels::GetPlayFabIDsFromGoogleIDsRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int GetPlayFabIDsFromKongregateIDs(ClientModels::GetPlayFabIDsFromKongregateIDsRequest& request, ProcessApiCallback<ClientModels::GetPlayFabIDsFromKongregateIDsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int GetPlayFabIDsFromKongregateIDs(ClientModels::GetPlayFabIDsFromKongregateIDsRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int GetPlayFabIDsFromSteamIDs(ClientModels::GetPlayFabIDsFromSteamIDsRequest& request, ProcessApiCallback<ClientModels::GetPlayFabIDsFromSteamIDsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int GetPlayFabIDsFromSteamIDs(ClientModels::GetPlayFabIDsFromSteamIDsRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int GetPlayFabIDsFromTwitchIDs(ClientModels::GetPlayFabIDsFromTwitchIDsRequest& request, ProcessApiCallback<ClientModels::GetPlayFabIDsFromTwitchIDsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int GetPlayFabIDsFromTwitchIDs(ClientModels::GetPlayFabIDsFromTwitchIDsRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int LinkAndroidDeviceID(ClientModels::LinkAndroidDeviceIDRequest& request, ProcessApiCallback<ClientModels::LinkAndroidDeviceIDResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int LinkAndroidDeviceID(ClientModels::LinkAndroidDeviceIDRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int LinkCustomID(ClientModels::LinkCustomIDRequest& request, ProcessApiCallback<ClientModels::LinkCustomIDResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int LinkCustomID(ClientModels::LinkCustomIDRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int LinkFacebookAccount(ClientModels::LinkFacebookAccountRequest& request, ProcessApiCallback<ClientModels::LinkFacebookAccountResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int LinkFacebookAccount(ClientModels::LinkFacebookAccountRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int LinkGameCenterAccount(ClientModels::LinkGameCenterAccountRequest& request, ProcessApiCallback<ClientModels::LinkGameCenterAccountResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int LinkGameCenterAccount(ClientModels::LinkGameCenterAccountRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int LinkGoogleAccount(ClientModels::LinkGoogleAccountRequest& request, ProcessApiCallback<ClientModels::LinkGoogleAccountResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int LinkGoogleAccount(ClientModels::LinkGoogleAccountRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int LinkIOSDeviceID(ClientModels::LinkIOSDeviceIDRequest& request, ProcessApiCallback<ClientModels::LinkIOSDeviceIDResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int LinkIOSDeviceID(ClientModels::LinkIOSDeviceIDRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int LinkKongregate(ClientModels::LinkKongregateAccountRequest& request, ProcessApiCallback<ClientModels::LinkKongregateAccountResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int LinkKongregate(ClientModels::LinkKongregateAccountRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int LinkSteamAccount(ClientModels::LinkSteamAccountRequest& request, ProcessApiCallback<ClientModels::LinkSteamAccountResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int LinkSteamAccount(ClientModels::LinkSteamAccountRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int LinkTwitch(ClientModels::LinkTwitchAccountRequest& request, ProcessApiCallback<ClientModels::LinkTwitchAccountResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int LinkTwitch(ClientModels::LinkTwitchAccountRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int LinkWindowsHello(ClientModels::LinkWindowsHelloAccountRequest& request, ProcessApiCallback<ClientModels::LinkWindowsHelloAccountResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int LinkWindowsHello(ClientModels::LinkWindowsHelloAccountRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int RemoveGenericID(ClientModels::RemoveGenericIDRequest& request, ProcessApiCallback<ClientModels::RemoveGenericIDResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int RemoveGenericID(ClientModels::RemoveGenericIDRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int ReportPlayer(ClientModels::ReportPlayerClientRequest& request, ProcessApiCallback<ClientModels::ReportPlayerClientResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int ReportPlayer(ClientModels::ReportPlayerClientRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int SendAccountRecoveryEmail(ClientModels::SendAccountRecoveryEmailRequest& request, ProcessApiCallback<ClientModels::SendAccountRecoveryEmailResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int SendAccountRecoveryEmail(ClientModels::SendAccountRecoveryEmailRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int UnlinkAndroidDeviceID(ClientModels::UnlinkAndroidDeviceIDRequest& request, ProcessApiCallback<ClientModels::UnlinkAndroidDeviceIDResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int UnlinkAndroidDeviceID(ClientModels::UnlinkAndroidDeviceIDRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int UnlinkCustomID(ClientModels::UnlinkCustomIDRequest& request, ProcessApiCallback<ClientModels::UnlinkCustomIDResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int UnlinkCustomID(ClientModels::UnlinkCustomIDRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int UnlinkFacebookAccount(ProcessApiCallback<ClientModels::UnlinkFacebookAccountResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int UnlinkFacebookAccount() override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int UnlinkGameCenterAccount(ProcessApiCallback<ClientModels::UnlinkGameCenterAccountResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int UnlinkGameCenterAccount() override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int UnlinkGoogleAccount(ProcessApiCallback<ClientModels::UnlinkGoogleAccountResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int UnlinkGoogleAccount() override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int UnlinkIOSDeviceID(ClientModels::UnlinkIOSDeviceIDRequest& request, ProcessApiCallback<ClientModels::UnlinkIOSDeviceIDResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int UnlinkIOSDeviceID(ClientModels::UnlinkIOSDeviceIDRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int UnlinkKongregate(ProcessApiCallback<ClientModels::UnlinkKongregateAccountResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int UnlinkKongregate() override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int UnlinkSteamAccount(ProcessApiCallback<ClientModels::UnlinkSteamAccountResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int UnlinkSteamAccount() override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int UnlinkTwitch(ProcessApiCallback<ClientModels::UnlinkTwitchAccountResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int UnlinkTwitch() override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int UnlinkWindowsHello(ClientModels::UnlinkWindowsHelloAccountRequest& request, ProcessApiCallback<ClientModels::UnlinkWindowsHelloAccountResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int UnlinkWindowsHello(ClientModels::UnlinkWindowsHelloAccountRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int UpdateAvatarUrl(ClientModels::UpdateAvatarUrlRequest& request, ProcessApiCallback<ClientModels::EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int UpdateAvatarUrl(ClientModels::UpdateAvatarUrlRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int UpdateUserTitleDisplayName(ClientModels::UpdateUserTitleDisplayNameRequest& request, ProcessApiCallback<ClientModels::UpdateUserTitleDisplayNameResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int UpdateUserTitleDisplayName(ClientModels::UpdateUserTitleDisplayNameRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int GetFriendLeaderboard(ClientModels::GetFriendLeaderboardRequest& request, ProcessApiCallback<ClientModels::GetLeaderboardResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int GetFriendLeaderboard(ClientModels::GetFriendLeaderboardRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int GetFriendLeaderboardAroundPlayer(ClientModels::GetFriendLeaderboardAroundPlayerRequest& request, ProcessApiCallback<ClientModels::GetFriendLeaderboardAroundPlayerResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int GetFriendLeaderboardAroundPlayer(ClientModels::GetFriendLeaderboardAroundPlayerRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int GetLeaderboard(ClientModels::GetLeaderboardRequest& request, ProcessApiCallback<ClientModels::GetLeaderboardResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int GetLeaderboard(ClientModels::GetLeaderboardRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int GetLeaderboardAroundPlayer(ClientModels::GetLeaderboardAroundPlayerRequest& request, ProcessApiCallback<ClientModels::GetLeaderboardAroundPlayerResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int GetLeaderboardAroundPlayer(ClientModels::GetLeaderboardAroundPlayerRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int GetPlayerStatistics(ClientModels::GetPlayerStatisticsRequest& request, ProcessApiCallback<ClientModels::GetPlayerStatisticsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int GetPlayerStatistics(ClientModels::GetPlayerStatisticsRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int GetPlayerStatisticVersions(ClientModels::GetPlayerStatisticVersionsRequest& request, ProcessApiCallback<ClientModels::GetPlayerStatisticVersionsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int GetPlayerStatisticVersions(ClientModels::GetPlayerStatisticVersionsRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int GetUserData(ClientModels::GetUserDataRequest& request, ProcessApiCallback<ClientModels::GetUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int GetUserData(ClientModels::GetUserDataRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int GetUserPublisherData(ClientModels::GetUserDataRequest& request, ProcessApiCallback<ClientModels::GetUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int GetUserPublisherData(ClientModels::GetUserDataRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int GetUserPublisherReadOnlyData(ClientModels::GetUserDataRequest& request, ProcessApiCallback<ClientModels::GetUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int GetUserPublisherReadOnlyData(ClientModels::GetUserDataRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int GetUserReadOnlyData(ClientModels::GetUserDataRequest& request, ProcessApiCallback<ClientModels::GetUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int GetUserReadOnlyData(ClientModels::GetUserDataRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int UpdatePlayerStatistics(ClientModels::UpdatePlayerStatisticsRequest& request, ProcessApiCallback<ClientModels::UpdatePlayerStatisticsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int UpdatePlayerStatistics(ClientModels::UpdatePlayerStatisticsRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int UpdateUserData(ClientModels::UpdateUserDataRequest& request, ProcessApiCallback<ClientModels::UpdateUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int UpdateUserData(ClientModels::UpdateUserDataRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int UpdateUserPublisherData(ClientModels::UpdateUserDataRequest& request, ProcessApiCallback<ClientModels::UpdateUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int UpdateUserPublisherData(ClientModels::UpdateUserDataRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int GetCatalogItems(ClientModels::GetCatalogItemsRequest& request, ProcessApiCallback<ClientModels::GetCatalogItemsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int GetCatalogItems(ClientModels::GetCatalogItemsRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int GetPublisherData(ClientModels::GetPublisherDataRequest& request, ProcessApiCallback<ClientModels::GetPublisherDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int GetPublisherData(ClientModels::GetPublisherDataRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int GetStoreItems(ClientModels::GetStoreItemsRequest& request, ProcessApiCallback<ClientModels::GetStoreItemsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int GetStoreItems(ClientModels::GetStoreItemsRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int GetTime(ProcessApiCallback<ClientModels::GetTimeResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int GetTime() override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int GetTitleData(ClientModels::GetTitleDataRequest& request, ProcessApiCallback<ClientModels::GetTitleDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int GetTitleData(ClientModels::GetTitleDataRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int GetTitleNews(ClientModels::GetTitleNewsRequest& request, ProcessApiCallback<ClientModels::GetTitleNewsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int GetTitleNews(ClientModels::GetTitleNewsRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int AddUserVirtualCurrency(ClientModels::AddUserVirtualCurrencyRequest& request, ProcessApiCallback<ClientModels::ModifyUserVirtualCurrencyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int AddUserVirtualCurrency(ClientModels::AddUserVirtualCurrencyRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int ConfirmPurchase(ClientModels::ConfirmPurchaseRequest& request, ProcessApiCallback<ClientModels::ConfirmPurchaseResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int ConfirmPurchase(ClientModels::ConfirmPurchaseRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int ConsumeItem(ClientModels::ConsumeItemRequest& request, ProcessApiCallback<ClientModels::ConsumeItemResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int ConsumeItem(ClientModels::ConsumeItemRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int GetCharacterInventory(ClientModels::GetCharacterInventoryRequest& request, ProcessApiCallback<ClientModels::GetCharacterInventoryResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int GetCharacterInventory(ClientModels::GetCharacterInventoryRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int GetPurchase(ClientModels::GetPurchaseRequest& request, ProcessApiCallback<ClientModels::GetPurchaseResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int GetPurchase(ClientModels::GetPurchaseRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int GetUserInventory(ProcessApiCallback<ClientModels::GetUserInventoryResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int GetUserInventory() override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int PayForPurchase(ClientModels::PayForPurchaseRequest& request, ProcessApiCallback<ClientModels::PayForPurchaseResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int PayForPurchase(ClientModels::PayForPurchaseRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int PurchaseItem(ClientModels::PurchaseItemRequest& request, ProcessApiCallback<ClientModels::PurchaseItemResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int PurchaseItem(ClientModels::PurchaseItemRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int RedeemCoupon(ClientModels::RedeemCouponRequest& request, ProcessApiCallback<ClientModels::RedeemCouponResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int RedeemCoupon(ClientModels::RedeemCouponRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int StartPurchase(ClientModels::StartPurchaseRequest& request, ProcessApiCallback<ClientModels::StartPurchaseResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int StartPurchase(ClientModels::StartPurchaseRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int SubtractUserVirtualCurrency(ClientModels::SubtractUserVirtualCurrencyRequest& request, ProcessApiCallback<ClientModels::ModifyUserVirtualCurrencyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int SubtractUserVirtualCurrency(ClientModels::SubtractUserVirtualCurrencyRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int UnlockContainerInstance(ClientModels::UnlockContainerInstanceRequest& request, ProcessApiCallback<ClientModels::UnlockContainerItemResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int UnlockContainerInstance(ClientModels::UnlockContainerInstanceRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int UnlockContainerItem(ClientModels::UnlockContainerItemRequest& request, ProcessApiCallback<ClientModels::UnlockContainerItemResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int UnlockContainerItem(ClientModels::UnlockContainerItemRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int AddFriend(ClientModels::AddFriendRequest& request, ProcessApiCallback<ClientModels::AddFriendResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int AddFriend(ClientModels::AddFriendRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int GetFriendsList(ClientModels::GetFriendsListRequest& request, ProcessApiCallback<ClientModels::GetFriendsListResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int GetFriendsList(ClientModels::GetFriendsListRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int RemoveFriend(ClientModels::RemoveFriendRequest& request, ProcessApiCallback<ClientModels::RemoveFriendResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int RemoveFriend(ClientModels::RemoveFriendRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int SetFriendTags(ClientModels::SetFriendTagsRequest& request, ProcessApiCallback<ClientModels::SetFriendTagsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int SetFriendTags(ClientModels::SetFriendTagsRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int GetCurrentGames(ClientModels::CurrentGamesRequest& request, ProcessApiCallback<ClientModels::CurrentGamesResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int GetCurrentGames(ClientModels::CurrentGamesRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int GetGameServerRegions(ClientModels::GameServerRegionsRequest& request, ProcessApiCallback<ClientModels::GameServerRegionsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int GetGameServerRegions(ClientModels::GameServerRegionsRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int Matchmake(ClientModels::MatchmakeRequest& request, ProcessApiCallback<ClientModels::MatchmakeResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int Matchmake(ClientModels::MatchmakeRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int StartGame(ClientModels::StartGameRequest& request, ProcessApiCallback<ClientModels::StartGameResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int StartGame(ClientModels::StartGameRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int WriteCharacterEvent(ClientModels::WriteClientCharacterEventRequest& request, ProcessApiCallback<ClientModels::WriteEventResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int WriteCharacterEvent(ClientModels::WriteClientCharacterEventRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int WritePlayerEvent(ClientModels::WriteClientPlayerEventRequest& request, ProcessApiCallback<ClientModels::WriteEventResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int WritePlayerEvent(ClientModels::WriteClientPlayerEventRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int WriteTitleEvent(ClientModels::WriteTitleEventRequest& request, ProcessApiCallback<ClientModels::WriteEventResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int WriteTitleEvent(ClientModels::WriteTitleEventRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int AddSharedGroupMembers(ClientModels::AddSharedGroupMembersRequest& request, ProcessApiCallback<ClientModels::AddSharedGroupMembersResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int AddSharedGroupMembers(ClientModels::AddSharedGroupMembersRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int CreateSharedGroup(ClientModels::CreateSharedGroupRequest& request, ProcessApiCallback<ClientModels::CreateSharedGroupResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int CreateSharedGroup(ClientModels::CreateSharedGroupRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int GetSharedGroupData(ClientModels::GetSharedGroupDataRequest& request, ProcessApiCallback<ClientModels::GetSharedGroupDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int GetSharedGroupData(ClientModels::GetSharedGroupDataRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int RemoveSharedGroupMembers(ClientModels::RemoveSharedGroupMembersRequest& request, ProcessApiCallback<ClientModels::RemoveSharedGroupMembersResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int RemoveSharedGroupMembers(ClientModels::RemoveSharedGroupMembersRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int UpdateSharedGroupData(ClientModels::UpdateSharedGroupDataRequest& request, ProcessApiCallback<ClientModels::UpdateSharedGroupDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int UpdateSharedGroupData(ClientModels::UpdateSharedGroupDataRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int ExecuteCloudScript(ClientModels::ExecuteCloudScriptRequest& request, ProcessApiCallback<ClientModels::ExecuteCloudScriptResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int ExecuteCloudScript(ClientModels::ExecuteCloudScriptRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int GetContentDownloadUrl(ClientModels::GetContentDownloadUrlRequest& request, ProcessApiCallback<ClientModels::GetContentDownloadUrlResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int GetContentDownloadUrl(ClientModels::GetContentDownloadUrlRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int GetAllUsersCharacters(ClientModels::ListUsersCharactersRequest& request, ProcessApiCallback<ClientModels::ListUsersCharactersResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int GetAllUsersCharacters(ClientModels::ListUsersCharactersRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int GetCharacterLeaderboard(ClientModels::GetCharacterLeaderboardRequest& request, ProcessApiCallback<ClientModels::GetCharacterLeaderboardResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int GetCharacterLeaderboard(ClientModels::GetCharacterLeaderboardRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int GetCharacterStatistics(ClientModels::GetCharacterStatisticsRequest& request, ProcessApiCallback<ClientModels::GetCharacterStatisticsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int GetCharacterStatistics(ClientModels::GetCharacterStatisticsRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int GetLeaderboardAroundCharacter(ClientModels::GetLeaderboardAroundCharacterRequest& request, ProcessApiCallback<ClientModels::GetLeaderboardAroundCharacterResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int GetLeaderboardAroundCharacter(ClientModels::GetLeaderboardAroundCharacterRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int GetLeaderboardForUserCharacters(ClientModels::GetLeaderboardForUsersCharactersRequest& request, ProcessApiCallback<ClientModels::GetLeaderboardForUsersCharactersResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int GetLeaderboardForUserCharacters(ClientModels::GetLeaderboardForUsersCharactersRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int GrantCharacterToUser(ClientModels::GrantCharacterToUserRequest& request, ProcessApiCallback<ClientModels::GrantCharacterToUserResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int GrantCharacterToUser(ClientModels::GrantCharacterToUserRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int UpdateCharacterStatistics(ClientModels::UpdateCharacterStatisticsRequest& request, ProcessApiCallback<ClientModels::UpdateCharacterStatisticsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int UpdateCharacterStatistics(ClientModels::UpdateCharacterStatisticsRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int GetCharacterData(ClientModels::GetCharacterDataRequest& request, ProcessApiCallback<ClientModels::GetCharacterDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int GetCharacterData(ClientModels::GetCharacterDataRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int GetCharacterReadOnlyData(ClientModels::GetCharacterDataRequest& request, ProcessApiCallback<ClientModels::GetCharacterDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int GetCharacterReadOnlyData(ClientModels::GetCharacterDataRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int UpdateCharacterData(ClientModels::UpdateCharacterDataRequest& request, ProcessApiCallback<ClientModels::UpdateCharacterDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int UpdateCharacterData(ClientModels::UpdateCharacterDataRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int AcceptTrade(ClientModels::AcceptTradeRequest& request, ProcessApiCallback<ClientModels::AcceptTradeResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int AcceptTrade(ClientModels::AcceptTradeRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int CancelTrade(ClientModels::CancelTradeRequest& request, ProcessApiCallback<ClientModels::CancelTradeResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int CancelTrade(ClientModels::CancelTradeRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int GetPlayerTrades(ClientModels::GetPlayerTradesRequest& request, ProcessApiCallback<ClientModels::GetPlayerTradesResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int GetPlayerTrades(ClientModels::GetPlayerTradesRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int GetTradeStatus(ClientModels::GetTradeStatusRequest& request, ProcessApiCallback<ClientModels::GetTradeStatusResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int GetTradeStatus(ClientModels::GetTradeStatusRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int OpenTrade(ClientModels::OpenTradeRequest& request, ProcessApiCallback<ClientModels::OpenTradeResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int OpenTrade(ClientModels::OpenTradeRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int AttributeInstall(ClientModels::AttributeInstallRequest& request, ProcessApiCallback<ClientModels::AttributeInstallResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int AttributeInstall(ClientModels::AttributeInstallRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int GetPlayerSegments(ProcessApiCallback<ClientModels::GetPlayerSegmentsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int GetPlayerSegments() override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int GetPlayerTags(ClientModels::GetPlayerTagsRequest& request, ProcessApiCallback<ClientModels::GetPlayerTagsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int GetPlayerTags(ClientModels::GetPlayerTagsRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int AndroidDevicePushNotificationRegistration(ClientModels::AndroidDevicePushNotificationRegistrationRequest& request, ProcessApiCallback<ClientModels::AndroidDevicePushNotificationRegistrationResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int AndroidDevicePushNotificationRegistration(ClientModels::AndroidDevicePushNotificationRegistrationRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int RegisterForIOSPushNotification(ClientModels::RegisterForIOSPushNotificationRequest& request, ProcessApiCallback<ClientModels::RegisterForIOSPushNotificationResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int RegisterForIOSPushNotification(ClientModels::RegisterForIOSPushNotificationRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int RestoreIOSPurchases(ClientModels::RestoreIOSPurchasesRequest& request, ProcessApiCallback<ClientModels::RestoreIOSPurchasesResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int RestoreIOSPurchases(ClientModels::RestoreIOSPurchasesRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int ValidateAmazonIAPReceipt(ClientModels::ValidateAmazonReceiptRequest& request, ProcessApiCallback<ClientModels::ValidateAmazonReceiptResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int ValidateAmazonIAPReceipt(ClientModels::ValidateAmazonReceiptRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int ValidateGooglePlayPurchase(ClientModels::ValidateGooglePlayPurchaseRequest& request, ProcessApiCallback<ClientModels::ValidateGooglePlayPurchaseResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int ValidateGooglePlayPurchase(ClientModels::ValidateGooglePlayPurchaseRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int ValidateIOSReceipt(ClientModels::ValidateIOSReceiptRequest& request, ProcessApiCallback<ClientModels::ValidateIOSReceiptResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int ValidateIOSReceipt(ClientModels::ValidateIOSReceiptRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
        int ValidateWindowsStoreReceipt(ClientModels::ValidateWindowsReceiptRequest& request, ProcessApiCallback<ClientModels::ValidateWindowsReceiptResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        int ValidateWindowsStoreReceipt(ClientModels::ValidateWindowsReceiptRequest& request) override; // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
