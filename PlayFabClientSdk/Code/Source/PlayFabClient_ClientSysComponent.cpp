
#include "StdAfx.h"

#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>

#include "PlayFabClient_ClientSysComponent.h"

#include "PlayFabSettings.h"
#include "PlayFabClientApi.h"

namespace PlayFabClientSdk
{
    using namespace ClientModels;

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
        // Start the http request manager thread
        PlayFabRequestManager::playFabHttp = new PlayFabRequestManager();

        PlayFabClient_ClientRequestBus::Handler::BusConnect();
    }

    void PlayFabClient_ClientSysComponent::Deactivate()
    {
        PlayFabClient_ClientRequestBus::Handler::BusDisconnect();

        // Shut down the http handler thread
        if (PlayFabRequestManager::playFabHttp)
        {
            delete PlayFabRequestManager::playFabHttp;
            PlayFabRequestManager::playFabHttp = nullptr;
        }
    }

    // Client-Specific
    bool PlayFabClient_ClientSysComponent::IsClientLoggedIn()
    {
        return PlayFabClientApi::IsClientLoggedIn();
    }

    int PlayFabClient_ClientSysComponent::GetPendingCalls()
    {
        return PlayFabClientApi::GetPendingCalls();
    }

    // ------------ Generated API call wrappers
    void PlayFabClient_ClientSysComponent::GetPhotonAuthenticationToken(GetPhotonAuthenticationTokenRequest& request, ProcessApiCallback<GetPhotonAuthenticationTokenResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetPhotonAuthenticationToken(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::GetTitlePublicKey(GetTitlePublicKeyRequest& request, ProcessApiCallback<GetTitlePublicKeyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetTitlePublicKey(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::GetWindowsHelloChallenge(GetWindowsHelloChallengeRequest& request, ProcessApiCallback<GetWindowsHelloChallengeResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetWindowsHelloChallenge(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::LoginWithAndroidDeviceID(LoginWithAndroidDeviceIDRequest& request, ProcessApiCallback<LoginResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::LoginWithAndroidDeviceID(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::LoginWithCustomID(LoginWithCustomIDRequest& request, ProcessApiCallback<LoginResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::LoginWithCustomID(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::LoginWithEmailAddress(LoginWithEmailAddressRequest& request, ProcessApiCallback<LoginResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::LoginWithEmailAddress(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::LoginWithFacebook(LoginWithFacebookRequest& request, ProcessApiCallback<LoginResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::LoginWithFacebook(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::LoginWithGameCenter(LoginWithGameCenterRequest& request, ProcessApiCallback<LoginResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::LoginWithGameCenter(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::LoginWithGoogleAccount(LoginWithGoogleAccountRequest& request, ProcessApiCallback<LoginResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::LoginWithGoogleAccount(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::LoginWithIOSDeviceID(LoginWithIOSDeviceIDRequest& request, ProcessApiCallback<LoginResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::LoginWithIOSDeviceID(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::LoginWithKongregate(LoginWithKongregateRequest& request, ProcessApiCallback<LoginResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::LoginWithKongregate(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::LoginWithPlayFab(LoginWithPlayFabRequest& request, ProcessApiCallback<LoginResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::LoginWithPlayFab(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::LoginWithSteam(LoginWithSteamRequest& request, ProcessApiCallback<LoginResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::LoginWithSteam(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::LoginWithTwitch(LoginWithTwitchRequest& request, ProcessApiCallback<LoginResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::LoginWithTwitch(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::LoginWithWindowsHello(LoginWithWindowsHelloRequest& request, ProcessApiCallback<LoginResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::LoginWithWindowsHello(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::RegisterPlayFabUser(RegisterPlayFabUserRequest& request, ProcessApiCallback<RegisterPlayFabUserResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::RegisterPlayFabUser(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::RegisterWithWindowsHello(RegisterWithWindowsHelloRequest& request, ProcessApiCallback<LoginResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::RegisterWithWindowsHello(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::SetPlayerSecret(SetPlayerSecretRequest& request, ProcessApiCallback<SetPlayerSecretResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::SetPlayerSecret(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::AddGenericID(AddGenericIDRequest& request, ProcessApiCallback<AddGenericIDResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::AddGenericID(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::AddUsernamePassword(AddUsernamePasswordRequest& request, ProcessApiCallback<AddUsernamePasswordResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::AddUsernamePassword(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::GetAccountInfo(GetAccountInfoRequest& request, ProcessApiCallback<GetAccountInfoResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetAccountInfo(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::GetPlayerCombinedInfo(GetPlayerCombinedInfoRequest& request, ProcessApiCallback<GetPlayerCombinedInfoResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetPlayerCombinedInfo(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::GetPlayerProfile(GetPlayerProfileRequest& request, ProcessApiCallback<GetPlayerProfileResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetPlayerProfile(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::GetPlayFabIDsFromFacebookIDs(GetPlayFabIDsFromFacebookIDsRequest& request, ProcessApiCallback<GetPlayFabIDsFromFacebookIDsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetPlayFabIDsFromFacebookIDs(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::GetPlayFabIDsFromGameCenterIDs(GetPlayFabIDsFromGameCenterIDsRequest& request, ProcessApiCallback<GetPlayFabIDsFromGameCenterIDsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetPlayFabIDsFromGameCenterIDs(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::GetPlayFabIDsFromGenericIDs(GetPlayFabIDsFromGenericIDsRequest& request, ProcessApiCallback<GetPlayFabIDsFromGenericIDsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetPlayFabIDsFromGenericIDs(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::GetPlayFabIDsFromGoogleIDs(GetPlayFabIDsFromGoogleIDsRequest& request, ProcessApiCallback<GetPlayFabIDsFromGoogleIDsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetPlayFabIDsFromGoogleIDs(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::GetPlayFabIDsFromKongregateIDs(GetPlayFabIDsFromKongregateIDsRequest& request, ProcessApiCallback<GetPlayFabIDsFromKongregateIDsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetPlayFabIDsFromKongregateIDs(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::GetPlayFabIDsFromSteamIDs(GetPlayFabIDsFromSteamIDsRequest& request, ProcessApiCallback<GetPlayFabIDsFromSteamIDsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetPlayFabIDsFromSteamIDs(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::GetPlayFabIDsFromTwitchIDs(GetPlayFabIDsFromTwitchIDsRequest& request, ProcessApiCallback<GetPlayFabIDsFromTwitchIDsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetPlayFabIDsFromTwitchIDs(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::LinkAndroidDeviceID(LinkAndroidDeviceIDRequest& request, ProcessApiCallback<LinkAndroidDeviceIDResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::LinkAndroidDeviceID(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::LinkCustomID(LinkCustomIDRequest& request, ProcessApiCallback<LinkCustomIDResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::LinkCustomID(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::LinkFacebookAccount(LinkFacebookAccountRequest& request, ProcessApiCallback<LinkFacebookAccountResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::LinkFacebookAccount(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::LinkGameCenterAccount(LinkGameCenterAccountRequest& request, ProcessApiCallback<LinkGameCenterAccountResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::LinkGameCenterAccount(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::LinkGoogleAccount(LinkGoogleAccountRequest& request, ProcessApiCallback<LinkGoogleAccountResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::LinkGoogleAccount(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::LinkIOSDeviceID(LinkIOSDeviceIDRequest& request, ProcessApiCallback<LinkIOSDeviceIDResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::LinkIOSDeviceID(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::LinkKongregate(LinkKongregateAccountRequest& request, ProcessApiCallback<LinkKongregateAccountResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::LinkKongregate(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::LinkSteamAccount(LinkSteamAccountRequest& request, ProcessApiCallback<LinkSteamAccountResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::LinkSteamAccount(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::LinkTwitch(LinkTwitchAccountRequest& request, ProcessApiCallback<LinkTwitchAccountResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::LinkTwitch(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::LinkWindowsHello(LinkWindowsHelloAccountRequest& request, ProcessApiCallback<LinkWindowsHelloAccountResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::LinkWindowsHello(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::RemoveGenericID(RemoveGenericIDRequest& request, ProcessApiCallback<RemoveGenericIDResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::RemoveGenericID(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::ReportPlayer(ReportPlayerClientRequest& request, ProcessApiCallback<ReportPlayerClientResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::ReportPlayer(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::SendAccountRecoveryEmail(SendAccountRecoveryEmailRequest& request, ProcessApiCallback<SendAccountRecoveryEmailResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::SendAccountRecoveryEmail(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::UnlinkAndroidDeviceID(UnlinkAndroidDeviceIDRequest& request, ProcessApiCallback<UnlinkAndroidDeviceIDResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::UnlinkAndroidDeviceID(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::UnlinkCustomID(UnlinkCustomIDRequest& request, ProcessApiCallback<UnlinkCustomIDResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::UnlinkCustomID(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::UnlinkFacebookAccount(ProcessApiCallback<UnlinkFacebookAccountResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::UnlinkFacebookAccount(callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::UnlinkGameCenterAccount(ProcessApiCallback<UnlinkGameCenterAccountResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::UnlinkGameCenterAccount(callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::UnlinkGoogleAccount(ProcessApiCallback<UnlinkGoogleAccountResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::UnlinkGoogleAccount(callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::UnlinkIOSDeviceID(UnlinkIOSDeviceIDRequest& request, ProcessApiCallback<UnlinkIOSDeviceIDResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::UnlinkIOSDeviceID(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::UnlinkKongregate(ProcessApiCallback<UnlinkKongregateAccountResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::UnlinkKongregate(callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::UnlinkSteamAccount(ProcessApiCallback<UnlinkSteamAccountResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::UnlinkSteamAccount(callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::UnlinkTwitch(ProcessApiCallback<UnlinkTwitchAccountResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::UnlinkTwitch(callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::UnlinkWindowsHello(UnlinkWindowsHelloAccountRequest& request, ProcessApiCallback<UnlinkWindowsHelloAccountResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::UnlinkWindowsHello(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::UpdateAvatarUrl(UpdateAvatarUrlRequest& request, ProcessApiCallback<EmptyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::UpdateAvatarUrl(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::UpdateUserTitleDisplayName(UpdateUserTitleDisplayNameRequest& request, ProcessApiCallback<UpdateUserTitleDisplayNameResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::UpdateUserTitleDisplayName(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::GetFriendLeaderboard(GetFriendLeaderboardRequest& request, ProcessApiCallback<GetLeaderboardResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetFriendLeaderboard(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::GetFriendLeaderboardAroundPlayer(GetFriendLeaderboardAroundPlayerRequest& request, ProcessApiCallback<GetFriendLeaderboardAroundPlayerResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetFriendLeaderboardAroundPlayer(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::GetLeaderboard(GetLeaderboardRequest& request, ProcessApiCallback<GetLeaderboardResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetLeaderboard(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::GetLeaderboardAroundPlayer(GetLeaderboardAroundPlayerRequest& request, ProcessApiCallback<GetLeaderboardAroundPlayerResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetLeaderboardAroundPlayer(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::GetPlayerStatistics(GetPlayerStatisticsRequest& request, ProcessApiCallback<GetPlayerStatisticsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetPlayerStatistics(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::GetPlayerStatisticVersions(GetPlayerStatisticVersionsRequest& request, ProcessApiCallback<GetPlayerStatisticVersionsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetPlayerStatisticVersions(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::GetUserData(GetUserDataRequest& request, ProcessApiCallback<GetUserDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetUserData(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::GetUserPublisherData(GetUserDataRequest& request, ProcessApiCallback<GetUserDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetUserPublisherData(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::GetUserPublisherReadOnlyData(GetUserDataRequest& request, ProcessApiCallback<GetUserDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetUserPublisherReadOnlyData(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::GetUserReadOnlyData(GetUserDataRequest& request, ProcessApiCallback<GetUserDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetUserReadOnlyData(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::UpdatePlayerStatistics(UpdatePlayerStatisticsRequest& request, ProcessApiCallback<UpdatePlayerStatisticsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::UpdatePlayerStatistics(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::UpdateUserData(UpdateUserDataRequest& request, ProcessApiCallback<UpdateUserDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::UpdateUserData(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::UpdateUserPublisherData(UpdateUserDataRequest& request, ProcessApiCallback<UpdateUserDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::UpdateUserPublisherData(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::GetCatalogItems(GetCatalogItemsRequest& request, ProcessApiCallback<GetCatalogItemsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetCatalogItems(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::GetPublisherData(GetPublisherDataRequest& request, ProcessApiCallback<GetPublisherDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetPublisherData(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::GetStoreItems(GetStoreItemsRequest& request, ProcessApiCallback<GetStoreItemsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetStoreItems(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::GetTime(ProcessApiCallback<GetTimeResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetTime(callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::GetTitleData(GetTitleDataRequest& request, ProcessApiCallback<GetTitleDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetTitleData(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::GetTitleNews(GetTitleNewsRequest& request, ProcessApiCallback<GetTitleNewsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetTitleNews(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::AddUserVirtualCurrency(AddUserVirtualCurrencyRequest& request, ProcessApiCallback<ModifyUserVirtualCurrencyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::AddUserVirtualCurrency(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::ConfirmPurchase(ConfirmPurchaseRequest& request, ProcessApiCallback<ConfirmPurchaseResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::ConfirmPurchase(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::ConsumeItem(ConsumeItemRequest& request, ProcessApiCallback<ConsumeItemResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::ConsumeItem(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::GetCharacterInventory(GetCharacterInventoryRequest& request, ProcessApiCallback<GetCharacterInventoryResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetCharacterInventory(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::GetPurchase(GetPurchaseRequest& request, ProcessApiCallback<GetPurchaseResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetPurchase(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::GetUserInventory(ProcessApiCallback<GetUserInventoryResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetUserInventory(callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::PayForPurchase(PayForPurchaseRequest& request, ProcessApiCallback<PayForPurchaseResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::PayForPurchase(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::PurchaseItem(PurchaseItemRequest& request, ProcessApiCallback<PurchaseItemResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::PurchaseItem(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::RedeemCoupon(RedeemCouponRequest& request, ProcessApiCallback<RedeemCouponResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::RedeemCoupon(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::StartPurchase(StartPurchaseRequest& request, ProcessApiCallback<StartPurchaseResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::StartPurchase(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::SubtractUserVirtualCurrency(SubtractUserVirtualCurrencyRequest& request, ProcessApiCallback<ModifyUserVirtualCurrencyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::SubtractUserVirtualCurrency(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::UnlockContainerInstance(UnlockContainerInstanceRequest& request, ProcessApiCallback<UnlockContainerItemResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::UnlockContainerInstance(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::UnlockContainerItem(UnlockContainerItemRequest& request, ProcessApiCallback<UnlockContainerItemResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::UnlockContainerItem(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::AddFriend(AddFriendRequest& request, ProcessApiCallback<AddFriendResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::AddFriend(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::GetFriendsList(GetFriendsListRequest& request, ProcessApiCallback<GetFriendsListResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetFriendsList(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::RemoveFriend(RemoveFriendRequest& request, ProcessApiCallback<RemoveFriendResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::RemoveFriend(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::SetFriendTags(SetFriendTagsRequest& request, ProcessApiCallback<SetFriendTagsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::SetFriendTags(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::GetCurrentGames(CurrentGamesRequest& request, ProcessApiCallback<CurrentGamesResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetCurrentGames(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::GetGameServerRegions(GameServerRegionsRequest& request, ProcessApiCallback<GameServerRegionsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetGameServerRegions(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::Matchmake(MatchmakeRequest& request, ProcessApiCallback<MatchmakeResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::Matchmake(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::StartGame(StartGameRequest& request, ProcessApiCallback<StartGameResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::StartGame(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::WriteCharacterEvent(WriteClientCharacterEventRequest& request, ProcessApiCallback<WriteEventResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::WriteCharacterEvent(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::WritePlayerEvent(WriteClientPlayerEventRequest& request, ProcessApiCallback<WriteEventResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::WritePlayerEvent(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::WriteTitleEvent(WriteTitleEventRequest& request, ProcessApiCallback<WriteEventResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::WriteTitleEvent(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::AddSharedGroupMembers(AddSharedGroupMembersRequest& request, ProcessApiCallback<AddSharedGroupMembersResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::AddSharedGroupMembers(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::CreateSharedGroup(CreateSharedGroupRequest& request, ProcessApiCallback<CreateSharedGroupResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::CreateSharedGroup(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::GetSharedGroupData(GetSharedGroupDataRequest& request, ProcessApiCallback<GetSharedGroupDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetSharedGroupData(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::RemoveSharedGroupMembers(RemoveSharedGroupMembersRequest& request, ProcessApiCallback<RemoveSharedGroupMembersResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::RemoveSharedGroupMembers(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::UpdateSharedGroupData(UpdateSharedGroupDataRequest& request, ProcessApiCallback<UpdateSharedGroupDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::UpdateSharedGroupData(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::ExecuteCloudScript(ExecuteCloudScriptRequest& request, ProcessApiCallback<ExecuteCloudScriptResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::ExecuteCloudScript(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::GetContentDownloadUrl(GetContentDownloadUrlRequest& request, ProcessApiCallback<GetContentDownloadUrlResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetContentDownloadUrl(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::GetAllUsersCharacters(ListUsersCharactersRequest& request, ProcessApiCallback<ListUsersCharactersResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetAllUsersCharacters(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::GetCharacterLeaderboard(GetCharacterLeaderboardRequest& request, ProcessApiCallback<GetCharacterLeaderboardResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetCharacterLeaderboard(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::GetCharacterStatistics(GetCharacterStatisticsRequest& request, ProcessApiCallback<GetCharacterStatisticsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetCharacterStatistics(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::GetLeaderboardAroundCharacter(GetLeaderboardAroundCharacterRequest& request, ProcessApiCallback<GetLeaderboardAroundCharacterResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetLeaderboardAroundCharacter(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::GetLeaderboardForUserCharacters(GetLeaderboardForUsersCharactersRequest& request, ProcessApiCallback<GetLeaderboardForUsersCharactersResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetLeaderboardForUserCharacters(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::GrantCharacterToUser(GrantCharacterToUserRequest& request, ProcessApiCallback<GrantCharacterToUserResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GrantCharacterToUser(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::UpdateCharacterStatistics(UpdateCharacterStatisticsRequest& request, ProcessApiCallback<UpdateCharacterStatisticsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::UpdateCharacterStatistics(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::GetCharacterData(GetCharacterDataRequest& request, ProcessApiCallback<GetCharacterDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetCharacterData(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::GetCharacterReadOnlyData(GetCharacterDataRequest& request, ProcessApiCallback<GetCharacterDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetCharacterReadOnlyData(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::UpdateCharacterData(UpdateCharacterDataRequest& request, ProcessApiCallback<UpdateCharacterDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::UpdateCharacterData(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::AcceptTrade(AcceptTradeRequest& request, ProcessApiCallback<AcceptTradeResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::AcceptTrade(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::CancelTrade(CancelTradeRequest& request, ProcessApiCallback<CancelTradeResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::CancelTrade(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::GetPlayerTrades(GetPlayerTradesRequest& request, ProcessApiCallback<GetPlayerTradesResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetPlayerTrades(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::GetTradeStatus(GetTradeStatusRequest& request, ProcessApiCallback<GetTradeStatusResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetTradeStatus(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::OpenTrade(OpenTradeRequest& request, ProcessApiCallback<OpenTradeResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::OpenTrade(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::AttributeInstall(AttributeInstallRequest& request, ProcessApiCallback<AttributeInstallResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::AttributeInstall(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::GetPlayerSegments(ProcessApiCallback<GetPlayerSegmentsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetPlayerSegments(callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::GetPlayerTags(GetPlayerTagsRequest& request, ProcessApiCallback<GetPlayerTagsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::GetPlayerTags(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::AndroidDevicePushNotificationRegistration(AndroidDevicePushNotificationRegistrationRequest& request, ProcessApiCallback<AndroidDevicePushNotificationRegistrationResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::AndroidDevicePushNotificationRegistration(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::RegisterForIOSPushNotification(RegisterForIOSPushNotificationRequest& request, ProcessApiCallback<RegisterForIOSPushNotificationResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::RegisterForIOSPushNotification(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::RestoreIOSPurchases(RestoreIOSPurchasesRequest& request, ProcessApiCallback<RestoreIOSPurchasesResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::RestoreIOSPurchases(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::ValidateAmazonIAPReceipt(ValidateAmazonReceiptRequest& request, ProcessApiCallback<ValidateAmazonReceiptResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::ValidateAmazonIAPReceipt(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::ValidateGooglePlayPurchase(ValidateGooglePlayPurchaseRequest& request, ProcessApiCallback<ValidateGooglePlayPurchaseResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::ValidateGooglePlayPurchase(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::ValidateIOSReceipt(ValidateIOSReceiptRequest& request, ProcessApiCallback<ValidateIOSReceiptResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::ValidateIOSReceipt(request, callback, errorCallback, customData);
    }
    void PlayFabClient_ClientSysComponent::ValidateWindowsStoreReceipt(ValidateWindowsReceiptRequest& request, ProcessApiCallback<ValidateWindowsReceiptResult> callback, ErrorCallback errorCallback, void* customData)
    {
        PlayFabClientApi::ValidateWindowsStoreReceipt(request, callback, errorCallback, customData);
    }
}
