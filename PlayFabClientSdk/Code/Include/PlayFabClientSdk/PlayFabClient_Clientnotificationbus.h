// #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS: dbowen (2017/08/11)
#pragma once
#include <AzCore/EBus/EBus.h>
#include <PlayFabClientSdk/PlayFabClientDataModels.h>

namespace PlayFabClientSdk
{
    // Request based notification bus, use this bus when you want to listen for a callback from a specific instance of an API request.
    class PlayFabClient_ClientNotifications
        : public AZ::EBusTraits
    {

    public:
		// The EBus has multiple addresses. Addresses are not ordered. The address corresponds to the ID of the request.
		static const AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::ById;
		typedef int BusIdType;

        // ------------ General notifications (not related to a specific API call)
        virtual void OnError(const PlayFabError& error) {};

        // ------------ Generated API call wrappers
        virtual void OnGetPhotonAuthenticationToken(const ClientModels::GetPhotonAuthenticationTokenResult& result) {};
        virtual void OnGetTitlePublicKey(const ClientModels::GetTitlePublicKeyResult& result) {};
        virtual void OnGetWindowsHelloChallenge(const ClientModels::GetWindowsHelloChallengeResponse& result) {};
        virtual void OnLoginWithAndroidDeviceID(const ClientModels::LoginResult& result) {};
        virtual void OnLoginWithCustomID(const ClientModels::LoginResult& result) {};
        virtual void OnLoginWithEmailAddress(const ClientModels::LoginResult& result) {};
        virtual void OnLoginWithFacebook(const ClientModels::LoginResult& result) {};
        virtual void OnLoginWithGameCenter(const ClientModels::LoginResult& result) {};
        virtual void OnLoginWithGoogleAccount(const ClientModels::LoginResult& result) {};
        virtual void OnLoginWithIOSDeviceID(const ClientModels::LoginResult& result) {};
        virtual void OnLoginWithKongregate(const ClientModels::LoginResult& result) {};
        virtual void OnLoginWithPlayFab(const ClientModels::LoginResult& result) {};
        virtual void OnLoginWithSteam(const ClientModels::LoginResult& result) {};
        virtual void OnLoginWithTwitch(const ClientModels::LoginResult& result) {};
        virtual void OnLoginWithWindowsHello(const ClientModels::LoginResult& result) {};
        virtual void OnRegisterPlayFabUser(const ClientModels::RegisterPlayFabUserResult& result) {};
        virtual void OnRegisterWithWindowsHello(const ClientModels::LoginResult& result) {};
        virtual void OnSetPlayerSecret(const ClientModels::SetPlayerSecretResult& result) {};
        virtual void OnAddGenericID(const ClientModels::AddGenericIDResult& result) {};
        virtual void OnAddUsernamePassword(const ClientModels::AddUsernamePasswordResult& result) {};
        virtual void OnGetAccountInfo(const ClientModels::GetAccountInfoResult& result) {};
        virtual void OnGetPlayerCombinedInfo(const ClientModels::GetPlayerCombinedInfoResult& result) {};
        virtual void OnGetPlayerProfile(const ClientModels::GetPlayerProfileResult& result) {};
        virtual void OnGetPlayFabIDsFromFacebookIDs(const ClientModels::GetPlayFabIDsFromFacebookIDsResult& result) {};
        virtual void OnGetPlayFabIDsFromGameCenterIDs(const ClientModels::GetPlayFabIDsFromGameCenterIDsResult& result) {};
        virtual void OnGetPlayFabIDsFromGenericIDs(const ClientModels::GetPlayFabIDsFromGenericIDsResult& result) {};
        virtual void OnGetPlayFabIDsFromGoogleIDs(const ClientModels::GetPlayFabIDsFromGoogleIDsResult& result) {};
        virtual void OnGetPlayFabIDsFromKongregateIDs(const ClientModels::GetPlayFabIDsFromKongregateIDsResult& result) {};
        virtual void OnGetPlayFabIDsFromSteamIDs(const ClientModels::GetPlayFabIDsFromSteamIDsResult& result) {};
        virtual void OnGetPlayFabIDsFromTwitchIDs(const ClientModels::GetPlayFabIDsFromTwitchIDsResult& result) {};
        virtual void OnLinkAndroidDeviceID(const ClientModels::LinkAndroidDeviceIDResult& result) {};
        virtual void OnLinkCustomID(const ClientModels::LinkCustomIDResult& result) {};
        virtual void OnLinkFacebookAccount(const ClientModels::LinkFacebookAccountResult& result) {};
        virtual void OnLinkGameCenterAccount(const ClientModels::LinkGameCenterAccountResult& result) {};
        virtual void OnLinkGoogleAccount(const ClientModels::LinkGoogleAccountResult& result) {};
        virtual void OnLinkIOSDeviceID(const ClientModels::LinkIOSDeviceIDResult& result) {};
        virtual void OnLinkKongregate(const ClientModels::LinkKongregateAccountResult& result) {};
        virtual void OnLinkSteamAccount(const ClientModels::LinkSteamAccountResult& result) {};
        virtual void OnLinkTwitch(const ClientModels::LinkTwitchAccountResult& result) {};
        virtual void OnLinkWindowsHello(const ClientModels::LinkWindowsHelloAccountResponse& result) {};
        virtual void OnRemoveGenericID(const ClientModels::RemoveGenericIDResult& result) {};
        virtual void OnReportPlayer(const ClientModels::ReportPlayerClientResult& result) {};
        virtual void OnSendAccountRecoveryEmail(const ClientModels::SendAccountRecoveryEmailResult& result) {};
        virtual void OnUnlinkAndroidDeviceID(const ClientModels::UnlinkAndroidDeviceIDResult& result) {};
        virtual void OnUnlinkCustomID(const ClientModels::UnlinkCustomIDResult& result) {};
        virtual void OnUnlinkFacebookAccount(const ClientModels::UnlinkFacebookAccountResult& result) {};
        virtual void OnUnlinkGameCenterAccount(const ClientModels::UnlinkGameCenterAccountResult& result) {};
        virtual void OnUnlinkGoogleAccount(const ClientModels::UnlinkGoogleAccountResult& result) {};
        virtual void OnUnlinkIOSDeviceID(const ClientModels::UnlinkIOSDeviceIDResult& result) {};
        virtual void OnUnlinkKongregate(const ClientModels::UnlinkKongregateAccountResult& result) {};
        virtual void OnUnlinkSteamAccount(const ClientModels::UnlinkSteamAccountResult& result) {};
        virtual void OnUnlinkTwitch(const ClientModels::UnlinkTwitchAccountResult& result) {};
        virtual void OnUnlinkWindowsHello(const ClientModels::UnlinkWindowsHelloAccountResponse& result) {};
        virtual void OnUpdateAvatarUrl(const ClientModels::EmptyResult& result) {};
        virtual void OnUpdateUserTitleDisplayName(const ClientModels::UpdateUserTitleDisplayNameResult& result) {};
        virtual void OnGetFriendLeaderboard(const ClientModels::GetLeaderboardResult& result) {};
        virtual void OnGetFriendLeaderboardAroundPlayer(const ClientModels::GetFriendLeaderboardAroundPlayerResult& result) {};
        virtual void OnGetLeaderboard(const ClientModels::GetLeaderboardResult& result) {};
        virtual void OnGetLeaderboardAroundPlayer(const ClientModels::GetLeaderboardAroundPlayerResult& result) {};
        virtual void OnGetPlayerStatistics(const ClientModels::GetPlayerStatisticsResult& result) {};
        virtual void OnGetPlayerStatisticVersions(const ClientModels::GetPlayerStatisticVersionsResult& result) {};
        virtual void OnGetUserData(const ClientModels::GetUserDataResult& result) {};
        virtual void OnGetUserPublisherData(const ClientModels::GetUserDataResult& result) {};
        virtual void OnGetUserPublisherReadOnlyData(const ClientModels::GetUserDataResult& result) {};
        virtual void OnGetUserReadOnlyData(const ClientModels::GetUserDataResult& result) {};
        virtual void OnUpdatePlayerStatistics(const ClientModels::UpdatePlayerStatisticsResult& result) {};
        virtual void OnUpdateUserData(const ClientModels::UpdateUserDataResult& result) {};
        virtual void OnUpdateUserPublisherData(const ClientModels::UpdateUserDataResult& result) {};
        virtual void OnGetCatalogItems(const ClientModels::GetCatalogItemsResult& result) {};
        virtual void OnGetPublisherData(const ClientModels::GetPublisherDataResult& result) {};
        virtual void OnGetStoreItems(const ClientModels::GetStoreItemsResult& result) {};
        virtual void OnGetTime(const ClientModels::GetTimeResult& result) {};
        virtual void OnGetTitleData(const ClientModels::GetTitleDataResult& result) {};
        virtual void OnGetTitleNews(const ClientModels::GetTitleNewsResult& result) {};
        virtual void OnAddUserVirtualCurrency(const ClientModels::ModifyUserVirtualCurrencyResult& result) {};
        virtual void OnConfirmPurchase(const ClientModels::ConfirmPurchaseResult& result) {};
        virtual void OnConsumeItem(const ClientModels::ConsumeItemResult& result) {};
        virtual void OnGetCharacterInventory(const ClientModels::GetCharacterInventoryResult& result) {};
        virtual void OnGetPurchase(const ClientModels::GetPurchaseResult& result) {};
        virtual void OnGetUserInventory(const ClientModels::GetUserInventoryResult& result) {};
        virtual void OnPayForPurchase(const ClientModels::PayForPurchaseResult& result) {};
        virtual void OnPurchaseItem(const ClientModels::PurchaseItemResult& result) {};
        virtual void OnRedeemCoupon(const ClientModels::RedeemCouponResult& result) {};
        virtual void OnStartPurchase(const ClientModels::StartPurchaseResult& result) {};
        virtual void OnSubtractUserVirtualCurrency(const ClientModels::ModifyUserVirtualCurrencyResult& result) {};
        virtual void OnUnlockContainerInstance(const ClientModels::UnlockContainerItemResult& result) {};
        virtual void OnUnlockContainerItem(const ClientModels::UnlockContainerItemResult& result) {};
        virtual void OnAddFriend(const ClientModels::AddFriendResult& result) {};
        virtual void OnGetFriendsList(const ClientModels::GetFriendsListResult& result) {};
        virtual void OnRemoveFriend(const ClientModels::RemoveFriendResult& result) {};
        virtual void OnSetFriendTags(const ClientModels::SetFriendTagsResult& result) {};
        virtual void OnGetCurrentGames(const ClientModels::CurrentGamesResult& result) {};
        virtual void OnGetGameServerRegions(const ClientModels::GameServerRegionsResult& result) {};
        virtual void OnMatchmake(const ClientModels::MatchmakeResult& result) {};
        virtual void OnStartGame(const ClientModels::StartGameResult& result) {};
        virtual void OnWriteCharacterEvent(const ClientModels::WriteEventResponse& result) {};
        virtual void OnWritePlayerEvent(const ClientModels::WriteEventResponse& result) {};
        virtual void OnWriteTitleEvent(const ClientModels::WriteEventResponse& result) {};
        virtual void OnAddSharedGroupMembers(const ClientModels::AddSharedGroupMembersResult& result) {};
        virtual void OnCreateSharedGroup(const ClientModels::CreateSharedGroupResult& result) {};
        virtual void OnGetSharedGroupData(const ClientModels::GetSharedGroupDataResult& result) {};
        virtual void OnRemoveSharedGroupMembers(const ClientModels::RemoveSharedGroupMembersResult& result) {};
        virtual void OnUpdateSharedGroupData(const ClientModels::UpdateSharedGroupDataResult& result) {};
        virtual void OnExecuteCloudScript(const ClientModels::ExecuteCloudScriptResult& result) {};
        virtual void OnGetContentDownloadUrl(const ClientModels::GetContentDownloadUrlResult& result) {};
        virtual void OnGetAllUsersCharacters(const ClientModels::ListUsersCharactersResult& result) {};
        virtual void OnGetCharacterLeaderboard(const ClientModels::GetCharacterLeaderboardResult& result) {};
        virtual void OnGetCharacterStatistics(const ClientModels::GetCharacterStatisticsResult& result) {};
        virtual void OnGetLeaderboardAroundCharacter(const ClientModels::GetLeaderboardAroundCharacterResult& result) {};
        virtual void OnGetLeaderboardForUserCharacters(const ClientModels::GetLeaderboardForUsersCharactersResult& result) {};
        virtual void OnGrantCharacterToUser(const ClientModels::GrantCharacterToUserResult& result) {};
        virtual void OnUpdateCharacterStatistics(const ClientModels::UpdateCharacterStatisticsResult& result) {};
        virtual void OnGetCharacterData(const ClientModels::GetCharacterDataResult& result) {};
        virtual void OnGetCharacterReadOnlyData(const ClientModels::GetCharacterDataResult& result) {};
        virtual void OnUpdateCharacterData(const ClientModels::UpdateCharacterDataResult& result) {};
        virtual void OnAcceptTrade(const ClientModels::AcceptTradeResponse& result) {};
        virtual void OnCancelTrade(const ClientModels::CancelTradeResponse& result) {};
        virtual void OnGetPlayerTrades(const ClientModels::GetPlayerTradesResponse& result) {};
        virtual void OnGetTradeStatus(const ClientModels::GetTradeStatusResponse& result) {};
        virtual void OnOpenTrade(const ClientModels::OpenTradeResponse& result) {};
        virtual void OnAttributeInstall(const ClientModels::AttributeInstallResult& result) {};
        virtual void OnGetPlayerSegments(const ClientModels::GetPlayerSegmentsResult& result) {};
        virtual void OnGetPlayerTags(const ClientModels::GetPlayerTagsResult& result) {};
        virtual void OnAndroidDevicePushNotificationRegistration(const ClientModels::AndroidDevicePushNotificationRegistrationResult& result) {};
        virtual void OnRegisterForIOSPushNotification(const ClientModels::RegisterForIOSPushNotificationResult& result) {};
        virtual void OnRestoreIOSPurchases(const ClientModels::RestoreIOSPurchasesResult& result) {};
        virtual void OnValidateAmazonIAPReceipt(const ClientModels::ValidateAmazonReceiptResult& result) {};
        virtual void OnValidateGooglePlayPurchase(const ClientModels::ValidateGooglePlayPurchaseResult& result) {};
        virtual void OnValidateIOSReceipt(const ClientModels::ValidateIOSReceiptResult& result) {};
        virtual void OnValidateWindowsStoreReceipt(const ClientModels::ValidateWindowsReceiptResult& result) {};
    
   };

    using PlayFabClient_ClientNotificationBus = AZ::EBus<PlayFabClient_ClientNotifications>;

    // Global notification bus - use this bus when you want to listen for all responses to a particular type of request. 
    class PlayFabClient_ClientGlobalNotifications
        : public AZ::EBusTraits
    {

    public:
		// The EBus has a single address, all notifications go to this address.
		static const AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;

        // ------------ General notifications (not related to a specific API call)
        virtual void OnError(const PlayFabError& error, int requestId) {};

        // ------------ Generated API call wrappers
        virtual void OnGetPhotonAuthenticationToken(const ClientModels::GetPhotonAuthenticationTokenResult& result, int requestId) {};
        virtual void OnGetTitlePublicKey(const ClientModels::GetTitlePublicKeyResult& result, int requestId) {};
        virtual void OnGetWindowsHelloChallenge(const ClientModels::GetWindowsHelloChallengeResponse& result, int requestId) {};
        virtual void OnLoginWithAndroidDeviceID(const ClientModels::LoginResult& result, int requestId) {};
        virtual void OnLoginWithCustomID(const ClientModels::LoginResult& result, int requestId) {};
        virtual void OnLoginWithEmailAddress(const ClientModels::LoginResult& result, int requestId) {};
        virtual void OnLoginWithFacebook(const ClientModels::LoginResult& result, int requestId) {};
        virtual void OnLoginWithGameCenter(const ClientModels::LoginResult& result, int requestId) {};
        virtual void OnLoginWithGoogleAccount(const ClientModels::LoginResult& result, int requestId) {};
        virtual void OnLoginWithIOSDeviceID(const ClientModels::LoginResult& result, int requestId) {};
        virtual void OnLoginWithKongregate(const ClientModels::LoginResult& result, int requestId) {};
        virtual void OnLoginWithPlayFab(const ClientModels::LoginResult& result, int requestId) {};
        virtual void OnLoginWithSteam(const ClientModels::LoginResult& result, int requestId) {};
        virtual void OnLoginWithTwitch(const ClientModels::LoginResult& result, int requestId) {};
        virtual void OnLoginWithWindowsHello(const ClientModels::LoginResult& result, int requestId) {};
        virtual void OnRegisterPlayFabUser(const ClientModels::RegisterPlayFabUserResult& result, int requestId) {};
        virtual void OnRegisterWithWindowsHello(const ClientModels::LoginResult& result, int requestId) {};
        virtual void OnSetPlayerSecret(const ClientModels::SetPlayerSecretResult& result, int requestId) {};
        virtual void OnAddGenericID(const ClientModels::AddGenericIDResult& result, int requestId) {};
        virtual void OnAddUsernamePassword(const ClientModels::AddUsernamePasswordResult& result, int requestId) {};
        virtual void OnGetAccountInfo(const ClientModels::GetAccountInfoResult& result, int requestId) {};
        virtual void OnGetPlayerCombinedInfo(const ClientModels::GetPlayerCombinedInfoResult& result, int requestId) {};
        virtual void OnGetPlayerProfile(const ClientModels::GetPlayerProfileResult& result, int requestId) {};
        virtual void OnGetPlayFabIDsFromFacebookIDs(const ClientModels::GetPlayFabIDsFromFacebookIDsResult& result, int requestId) {};
        virtual void OnGetPlayFabIDsFromGameCenterIDs(const ClientModels::GetPlayFabIDsFromGameCenterIDsResult& result, int requestId) {};
        virtual void OnGetPlayFabIDsFromGenericIDs(const ClientModels::GetPlayFabIDsFromGenericIDsResult& result, int requestId) {};
        virtual void OnGetPlayFabIDsFromGoogleIDs(const ClientModels::GetPlayFabIDsFromGoogleIDsResult& result, int requestId) {};
        virtual void OnGetPlayFabIDsFromKongregateIDs(const ClientModels::GetPlayFabIDsFromKongregateIDsResult& result, int requestId) {};
        virtual void OnGetPlayFabIDsFromSteamIDs(const ClientModels::GetPlayFabIDsFromSteamIDsResult& result, int requestId) {};
        virtual void OnGetPlayFabIDsFromTwitchIDs(const ClientModels::GetPlayFabIDsFromTwitchIDsResult& result, int requestId) {};
        virtual void OnLinkAndroidDeviceID(const ClientModels::LinkAndroidDeviceIDResult& result, int requestId) {};
        virtual void OnLinkCustomID(const ClientModels::LinkCustomIDResult& result, int requestId) {};
        virtual void OnLinkFacebookAccount(const ClientModels::LinkFacebookAccountResult& result, int requestId) {};
        virtual void OnLinkGameCenterAccount(const ClientModels::LinkGameCenterAccountResult& result, int requestId) {};
        virtual void OnLinkGoogleAccount(const ClientModels::LinkGoogleAccountResult& result, int requestId) {};
        virtual void OnLinkIOSDeviceID(const ClientModels::LinkIOSDeviceIDResult& result, int requestId) {};
        virtual void OnLinkKongregate(const ClientModels::LinkKongregateAccountResult& result, int requestId) {};
        virtual void OnLinkSteamAccount(const ClientModels::LinkSteamAccountResult& result, int requestId) {};
        virtual void OnLinkTwitch(const ClientModels::LinkTwitchAccountResult& result, int requestId) {};
        virtual void OnLinkWindowsHello(const ClientModels::LinkWindowsHelloAccountResponse& result, int requestId) {};
        virtual void OnRemoveGenericID(const ClientModels::RemoveGenericIDResult& result, int requestId) {};
        virtual void OnReportPlayer(const ClientModels::ReportPlayerClientResult& result, int requestId) {};
        virtual void OnSendAccountRecoveryEmail(const ClientModels::SendAccountRecoveryEmailResult& result, int requestId) {};
        virtual void OnUnlinkAndroidDeviceID(const ClientModels::UnlinkAndroidDeviceIDResult& result, int requestId) {};
        virtual void OnUnlinkCustomID(const ClientModels::UnlinkCustomIDResult& result, int requestId) {};
        virtual void OnUnlinkFacebookAccount(const ClientModels::UnlinkFacebookAccountResult& result, int requestId) {};
        virtual void OnUnlinkGameCenterAccount(const ClientModels::UnlinkGameCenterAccountResult& result, int requestId) {};
        virtual void OnUnlinkGoogleAccount(const ClientModels::UnlinkGoogleAccountResult& result, int requestId) {};
        virtual void OnUnlinkIOSDeviceID(const ClientModels::UnlinkIOSDeviceIDResult& result, int requestId) {};
        virtual void OnUnlinkKongregate(const ClientModels::UnlinkKongregateAccountResult& result, int requestId) {};
        virtual void OnUnlinkSteamAccount(const ClientModels::UnlinkSteamAccountResult& result, int requestId) {};
        virtual void OnUnlinkTwitch(const ClientModels::UnlinkTwitchAccountResult& result, int requestId) {};
        virtual void OnUnlinkWindowsHello(const ClientModels::UnlinkWindowsHelloAccountResponse& result, int requestId) {};
        virtual void OnUpdateAvatarUrl(const ClientModels::EmptyResult& result, int requestId) {};
        virtual void OnUpdateUserTitleDisplayName(const ClientModels::UpdateUserTitleDisplayNameResult& result, int requestId) {};
        virtual void OnGetFriendLeaderboard(const ClientModels::GetLeaderboardResult& result, int requestId) {};
        virtual void OnGetFriendLeaderboardAroundPlayer(const ClientModels::GetFriendLeaderboardAroundPlayerResult& result, int requestId) {};
        virtual void OnGetLeaderboard(const ClientModels::GetLeaderboardResult& result, int requestId) {};
        virtual void OnGetLeaderboardAroundPlayer(const ClientModels::GetLeaderboardAroundPlayerResult& result, int requestId) {};
        virtual void OnGetPlayerStatistics(const ClientModels::GetPlayerStatisticsResult& result, int requestId) {};
        virtual void OnGetPlayerStatisticVersions(const ClientModels::GetPlayerStatisticVersionsResult& result, int requestId) {};
        virtual void OnGetUserData(const ClientModels::GetUserDataResult& result, int requestId) {};
        virtual void OnGetUserPublisherData(const ClientModels::GetUserDataResult& result, int requestId) {};
        virtual void OnGetUserPublisherReadOnlyData(const ClientModels::GetUserDataResult& result, int requestId) {};
        virtual void OnGetUserReadOnlyData(const ClientModels::GetUserDataResult& result, int requestId) {};
        virtual void OnUpdatePlayerStatistics(const ClientModels::UpdatePlayerStatisticsResult& result, int requestId) {};
        virtual void OnUpdateUserData(const ClientModels::UpdateUserDataResult& result, int requestId) {};
        virtual void OnUpdateUserPublisherData(const ClientModels::UpdateUserDataResult& result, int requestId) {};
        virtual void OnGetCatalogItems(const ClientModels::GetCatalogItemsResult& result, int requestId) {};
        virtual void OnGetPublisherData(const ClientModels::GetPublisherDataResult& result, int requestId) {};
        virtual void OnGetStoreItems(const ClientModels::GetStoreItemsResult& result, int requestId) {};
        virtual void OnGetTime(const ClientModels::GetTimeResult& result, int requestId) {};
        virtual void OnGetTitleData(const ClientModels::GetTitleDataResult& result, int requestId) {};
        virtual void OnGetTitleNews(const ClientModels::GetTitleNewsResult& result, int requestId) {};
        virtual void OnAddUserVirtualCurrency(const ClientModels::ModifyUserVirtualCurrencyResult& result, int requestId) {};
        virtual void OnConfirmPurchase(const ClientModels::ConfirmPurchaseResult& result, int requestId) {};
        virtual void OnConsumeItem(const ClientModels::ConsumeItemResult& result, int requestId) {};
        virtual void OnGetCharacterInventory(const ClientModels::GetCharacterInventoryResult& result, int requestId) {};
        virtual void OnGetPurchase(const ClientModels::GetPurchaseResult& result, int requestId) {};
        virtual void OnGetUserInventory(const ClientModels::GetUserInventoryResult& result, int requestId) {};
        virtual void OnPayForPurchase(const ClientModels::PayForPurchaseResult& result, int requestId) {};
        virtual void OnPurchaseItem(const ClientModels::PurchaseItemResult& result, int requestId) {};
        virtual void OnRedeemCoupon(const ClientModels::RedeemCouponResult& result, int requestId) {};
        virtual void OnStartPurchase(const ClientModels::StartPurchaseResult& result, int requestId) {};
        virtual void OnSubtractUserVirtualCurrency(const ClientModels::ModifyUserVirtualCurrencyResult& result, int requestId) {};
        virtual void OnUnlockContainerInstance(const ClientModels::UnlockContainerItemResult& result, int requestId) {};
        virtual void OnUnlockContainerItem(const ClientModels::UnlockContainerItemResult& result, int requestId) {};
        virtual void OnAddFriend(const ClientModels::AddFriendResult& result, int requestId) {};
        virtual void OnGetFriendsList(const ClientModels::GetFriendsListResult& result, int requestId) {};
        virtual void OnRemoveFriend(const ClientModels::RemoveFriendResult& result, int requestId) {};
        virtual void OnSetFriendTags(const ClientModels::SetFriendTagsResult& result, int requestId) {};
        virtual void OnGetCurrentGames(const ClientModels::CurrentGamesResult& result, int requestId) {};
        virtual void OnGetGameServerRegions(const ClientModels::GameServerRegionsResult& result, int requestId) {};
        virtual void OnMatchmake(const ClientModels::MatchmakeResult& result, int requestId) {};
        virtual void OnStartGame(const ClientModels::StartGameResult& result, int requestId) {};
        virtual void OnWriteCharacterEvent(const ClientModels::WriteEventResponse& result, int requestId) {};
        virtual void OnWritePlayerEvent(const ClientModels::WriteEventResponse& result, int requestId) {};
        virtual void OnWriteTitleEvent(const ClientModels::WriteEventResponse& result, int requestId) {};
        virtual void OnAddSharedGroupMembers(const ClientModels::AddSharedGroupMembersResult& result, int requestId) {};
        virtual void OnCreateSharedGroup(const ClientModels::CreateSharedGroupResult& result, int requestId) {};
        virtual void OnGetSharedGroupData(const ClientModels::GetSharedGroupDataResult& result, int requestId) {};
        virtual void OnRemoveSharedGroupMembers(const ClientModels::RemoveSharedGroupMembersResult& result, int requestId) {};
        virtual void OnUpdateSharedGroupData(const ClientModels::UpdateSharedGroupDataResult& result, int requestId) {};
        virtual void OnExecuteCloudScript(const ClientModels::ExecuteCloudScriptResult& result, int requestId) {};
        virtual void OnGetContentDownloadUrl(const ClientModels::GetContentDownloadUrlResult& result, int requestId) {};
        virtual void OnGetAllUsersCharacters(const ClientModels::ListUsersCharactersResult& result, int requestId) {};
        virtual void OnGetCharacterLeaderboard(const ClientModels::GetCharacterLeaderboardResult& result, int requestId) {};
        virtual void OnGetCharacterStatistics(const ClientModels::GetCharacterStatisticsResult& result, int requestId) {};
        virtual void OnGetLeaderboardAroundCharacter(const ClientModels::GetLeaderboardAroundCharacterResult& result, int requestId) {};
        virtual void OnGetLeaderboardForUserCharacters(const ClientModels::GetLeaderboardForUsersCharactersResult& result, int requestId) {};
        virtual void OnGrantCharacterToUser(const ClientModels::GrantCharacterToUserResult& result, int requestId) {};
        virtual void OnUpdateCharacterStatistics(const ClientModels::UpdateCharacterStatisticsResult& result, int requestId) {};
        virtual void OnGetCharacterData(const ClientModels::GetCharacterDataResult& result, int requestId) {};
        virtual void OnGetCharacterReadOnlyData(const ClientModels::GetCharacterDataResult& result, int requestId) {};
        virtual void OnUpdateCharacterData(const ClientModels::UpdateCharacterDataResult& result, int requestId) {};
        virtual void OnAcceptTrade(const ClientModels::AcceptTradeResponse& result, int requestId) {};
        virtual void OnCancelTrade(const ClientModels::CancelTradeResponse& result, int requestId) {};
        virtual void OnGetPlayerTrades(const ClientModels::GetPlayerTradesResponse& result, int requestId) {};
        virtual void OnGetTradeStatus(const ClientModels::GetTradeStatusResponse& result, int requestId) {};
        virtual void OnOpenTrade(const ClientModels::OpenTradeResponse& result, int requestId) {};
        virtual void OnAttributeInstall(const ClientModels::AttributeInstallResult& result, int requestId) {};
        virtual void OnGetPlayerSegments(const ClientModels::GetPlayerSegmentsResult& result, int requestId) {};
        virtual void OnGetPlayerTags(const ClientModels::GetPlayerTagsResult& result, int requestId) {};
        virtual void OnAndroidDevicePushNotificationRegistration(const ClientModels::AndroidDevicePushNotificationRegistrationResult& result, int requestId) {};
        virtual void OnRegisterForIOSPushNotification(const ClientModels::RegisterForIOSPushNotificationResult& result, int requestId) {};
        virtual void OnRestoreIOSPurchases(const ClientModels::RestoreIOSPurchasesResult& result, int requestId) {};
        virtual void OnValidateAmazonIAPReceipt(const ClientModels::ValidateAmazonReceiptResult& result, int requestId) {};
        virtual void OnValidateGooglePlayPurchase(const ClientModels::ValidateGooglePlayPurchaseResult& result, int requestId) {};
        virtual void OnValidateIOSReceipt(const ClientModels::ValidateIOSReceiptResult& result, int requestId) {};
        virtual void OnValidateWindowsStoreReceipt(const ClientModels::ValidateWindowsReceiptResult& result, int requestId) {};
    
   };

    using PlayFabClient_ClientGlobalNotificationBus = AZ::EBus<PlayFabClient_ClientGlobalNotifications>;

} // namespace PlayFabClientSdk
