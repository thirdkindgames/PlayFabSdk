
#pragma once

#include <PlayFabClientSdk/PlayFabError.h>
#include <PlayFabClientSdk/PlayFabClientDataModels.h>
#include <AzCore/EBus/EBus.h>

namespace PlayFabClientSdk
{
    using namespace ClientModels;

    class PlayFabClient_ClientBus
        : public AZ::EBusTraits
    {

    public:
        static const AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static const AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;

        virtual bool IsClientLoggedIn() = 0;
        virtual int GetPendingCalls() = 0;

        // ------------ Generated API call wrappers
        virtual void GetPhotonAuthenticationToken(GetPhotonAuthenticationTokenRequest& request, ProcessApiCallback<GetPhotonAuthenticationTokenResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void GetTitlePublicKey(GetTitlePublicKeyRequest& request, ProcessApiCallback<GetTitlePublicKeyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void GetWindowsHelloChallenge(GetWindowsHelloChallengeRequest& request, ProcessApiCallback<GetWindowsHelloChallengeResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void LoginWithAndroidDeviceID(LoginWithAndroidDeviceIDRequest& request, ProcessApiCallback<LoginResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void LoginWithCustomID(LoginWithCustomIDRequest& request, ProcessApiCallback<LoginResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void LoginWithEmailAddress(LoginWithEmailAddressRequest& request, ProcessApiCallback<LoginResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void LoginWithFacebook(LoginWithFacebookRequest& request, ProcessApiCallback<LoginResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void LoginWithGameCenter(LoginWithGameCenterRequest& request, ProcessApiCallback<LoginResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void LoginWithGoogleAccount(LoginWithGoogleAccountRequest& request, ProcessApiCallback<LoginResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void LoginWithIOSDeviceID(LoginWithIOSDeviceIDRequest& request, ProcessApiCallback<LoginResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void LoginWithKongregate(LoginWithKongregateRequest& request, ProcessApiCallback<LoginResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void LoginWithPlayFab(LoginWithPlayFabRequest& request, ProcessApiCallback<LoginResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void LoginWithSteam(LoginWithSteamRequest& request, ProcessApiCallback<LoginResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void LoginWithTwitch(LoginWithTwitchRequest& request, ProcessApiCallback<LoginResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void LoginWithWindowsHello(LoginWithWindowsHelloRequest& request, ProcessApiCallback<LoginResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void RegisterPlayFabUser(RegisterPlayFabUserRequest& request, ProcessApiCallback<RegisterPlayFabUserResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void RegisterWithWindowsHello(RegisterWithWindowsHelloRequest& request, ProcessApiCallback<LoginResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void SetPlayerSecret(SetPlayerSecretRequest& request, ProcessApiCallback<SetPlayerSecretResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void AddGenericID(AddGenericIDRequest& request, ProcessApiCallback<AddGenericIDResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void AddUsernamePassword(AddUsernamePasswordRequest& request, ProcessApiCallback<AddUsernamePasswordResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void GetAccountInfo(GetAccountInfoRequest& request, ProcessApiCallback<GetAccountInfoResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void GetPlayerCombinedInfo(GetPlayerCombinedInfoRequest& request, ProcessApiCallback<GetPlayerCombinedInfoResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void GetPlayerProfile(GetPlayerProfileRequest& request, ProcessApiCallback<GetPlayerProfileResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void GetPlayFabIDsFromFacebookIDs(GetPlayFabIDsFromFacebookIDsRequest& request, ProcessApiCallback<GetPlayFabIDsFromFacebookIDsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void GetPlayFabIDsFromGameCenterIDs(GetPlayFabIDsFromGameCenterIDsRequest& request, ProcessApiCallback<GetPlayFabIDsFromGameCenterIDsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void GetPlayFabIDsFromGenericIDs(GetPlayFabIDsFromGenericIDsRequest& request, ProcessApiCallback<GetPlayFabIDsFromGenericIDsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void GetPlayFabIDsFromGoogleIDs(GetPlayFabIDsFromGoogleIDsRequest& request, ProcessApiCallback<GetPlayFabIDsFromGoogleIDsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void GetPlayFabIDsFromKongregateIDs(GetPlayFabIDsFromKongregateIDsRequest& request, ProcessApiCallback<GetPlayFabIDsFromKongregateIDsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void GetPlayFabIDsFromSteamIDs(GetPlayFabIDsFromSteamIDsRequest& request, ProcessApiCallback<GetPlayFabIDsFromSteamIDsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void GetPlayFabIDsFromTwitchIDs(GetPlayFabIDsFromTwitchIDsRequest& request, ProcessApiCallback<GetPlayFabIDsFromTwitchIDsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void LinkAndroidDeviceID(LinkAndroidDeviceIDRequest& request, ProcessApiCallback<LinkAndroidDeviceIDResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void LinkCustomID(LinkCustomIDRequest& request, ProcessApiCallback<LinkCustomIDResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void LinkFacebookAccount(LinkFacebookAccountRequest& request, ProcessApiCallback<LinkFacebookAccountResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void LinkGameCenterAccount(LinkGameCenterAccountRequest& request, ProcessApiCallback<LinkGameCenterAccountResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void LinkGoogleAccount(LinkGoogleAccountRequest& request, ProcessApiCallback<LinkGoogleAccountResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void LinkIOSDeviceID(LinkIOSDeviceIDRequest& request, ProcessApiCallback<LinkIOSDeviceIDResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void LinkKongregate(LinkKongregateAccountRequest& request, ProcessApiCallback<LinkKongregateAccountResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void LinkSteamAccount(LinkSteamAccountRequest& request, ProcessApiCallback<LinkSteamAccountResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void LinkTwitch(LinkTwitchAccountRequest& request, ProcessApiCallback<LinkTwitchAccountResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void LinkWindowsHello(LinkWindowsHelloAccountRequest& request, ProcessApiCallback<LinkWindowsHelloAccountResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void RemoveGenericID(RemoveGenericIDRequest& request, ProcessApiCallback<RemoveGenericIDResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void ReportPlayer(ReportPlayerClientRequest& request, ProcessApiCallback<ReportPlayerClientResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void SendAccountRecoveryEmail(SendAccountRecoveryEmailRequest& request, ProcessApiCallback<SendAccountRecoveryEmailResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void UnlinkAndroidDeviceID(UnlinkAndroidDeviceIDRequest& request, ProcessApiCallback<UnlinkAndroidDeviceIDResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void UnlinkCustomID(UnlinkCustomIDRequest& request, ProcessApiCallback<UnlinkCustomIDResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void UnlinkFacebookAccount(ProcessApiCallback<UnlinkFacebookAccountResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void UnlinkGameCenterAccount(ProcessApiCallback<UnlinkGameCenterAccountResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void UnlinkGoogleAccount(ProcessApiCallback<UnlinkGoogleAccountResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void UnlinkIOSDeviceID(UnlinkIOSDeviceIDRequest& request, ProcessApiCallback<UnlinkIOSDeviceIDResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void UnlinkKongregate(ProcessApiCallback<UnlinkKongregateAccountResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void UnlinkSteamAccount(ProcessApiCallback<UnlinkSteamAccountResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void UnlinkTwitch(ProcessApiCallback<UnlinkTwitchAccountResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void UnlinkWindowsHello(UnlinkWindowsHelloAccountRequest& request, ProcessApiCallback<UnlinkWindowsHelloAccountResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void UpdateAvatarUrl(UpdateAvatarUrlRequest& request, ProcessApiCallback<EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void UpdateUserTitleDisplayName(UpdateUserTitleDisplayNameRequest& request, ProcessApiCallback<UpdateUserTitleDisplayNameResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void GetFriendLeaderboard(GetFriendLeaderboardRequest& request, ProcessApiCallback<GetLeaderboardResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void GetFriendLeaderboardAroundPlayer(GetFriendLeaderboardAroundPlayerRequest& request, ProcessApiCallback<GetFriendLeaderboardAroundPlayerResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void GetLeaderboard(GetLeaderboardRequest& request, ProcessApiCallback<GetLeaderboardResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void GetLeaderboardAroundPlayer(GetLeaderboardAroundPlayerRequest& request, ProcessApiCallback<GetLeaderboardAroundPlayerResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void GetPlayerStatistics(GetPlayerStatisticsRequest& request, ProcessApiCallback<GetPlayerStatisticsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void GetPlayerStatisticVersions(GetPlayerStatisticVersionsRequest& request, ProcessApiCallback<GetPlayerStatisticVersionsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void GetUserData(GetUserDataRequest& request, ProcessApiCallback<GetUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void GetUserPublisherData(GetUserDataRequest& request, ProcessApiCallback<GetUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void GetUserPublisherReadOnlyData(GetUserDataRequest& request, ProcessApiCallback<GetUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void GetUserReadOnlyData(GetUserDataRequest& request, ProcessApiCallback<GetUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void UpdatePlayerStatistics(UpdatePlayerStatisticsRequest& request, ProcessApiCallback<UpdatePlayerStatisticsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void UpdateUserData(UpdateUserDataRequest& request, ProcessApiCallback<UpdateUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void UpdateUserPublisherData(UpdateUserDataRequest& request, ProcessApiCallback<UpdateUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void GetCatalogItems(GetCatalogItemsRequest& request, ProcessApiCallback<GetCatalogItemsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void GetPublisherData(GetPublisherDataRequest& request, ProcessApiCallback<GetPublisherDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void GetStoreItems(GetStoreItemsRequest& request, ProcessApiCallback<GetStoreItemsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void GetTime(ProcessApiCallback<GetTimeResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void GetTitleData(GetTitleDataRequest& request, ProcessApiCallback<GetTitleDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void GetTitleNews(GetTitleNewsRequest& request, ProcessApiCallback<GetTitleNewsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void AddUserVirtualCurrency(AddUserVirtualCurrencyRequest& request, ProcessApiCallback<ModifyUserVirtualCurrencyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void ConfirmPurchase(ConfirmPurchaseRequest& request, ProcessApiCallback<ConfirmPurchaseResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void ConsumeItem(ConsumeItemRequest& request, ProcessApiCallback<ConsumeItemResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void GetCharacterInventory(GetCharacterInventoryRequest& request, ProcessApiCallback<GetCharacterInventoryResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void GetPurchase(GetPurchaseRequest& request, ProcessApiCallback<GetPurchaseResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void GetUserInventory(ProcessApiCallback<GetUserInventoryResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void PayForPurchase(PayForPurchaseRequest& request, ProcessApiCallback<PayForPurchaseResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void PurchaseItem(PurchaseItemRequest& request, ProcessApiCallback<PurchaseItemResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void RedeemCoupon(RedeemCouponRequest& request, ProcessApiCallback<RedeemCouponResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void StartPurchase(StartPurchaseRequest& request, ProcessApiCallback<StartPurchaseResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void SubtractUserVirtualCurrency(SubtractUserVirtualCurrencyRequest& request, ProcessApiCallback<ModifyUserVirtualCurrencyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void UnlockContainerInstance(UnlockContainerInstanceRequest& request, ProcessApiCallback<UnlockContainerItemResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void UnlockContainerItem(UnlockContainerItemRequest& request, ProcessApiCallback<UnlockContainerItemResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void AddFriend(AddFriendRequest& request, ProcessApiCallback<AddFriendResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void GetFriendsList(GetFriendsListRequest& request, ProcessApiCallback<GetFriendsListResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void RemoveFriend(RemoveFriendRequest& request, ProcessApiCallback<RemoveFriendResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void SetFriendTags(SetFriendTagsRequest& request, ProcessApiCallback<SetFriendTagsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void GetCurrentGames(CurrentGamesRequest& request, ProcessApiCallback<CurrentGamesResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void GetGameServerRegions(GameServerRegionsRequest& request, ProcessApiCallback<GameServerRegionsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void Matchmake(MatchmakeRequest& request, ProcessApiCallback<MatchmakeResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void StartGame(StartGameRequest& request, ProcessApiCallback<StartGameResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void WriteCharacterEvent(WriteClientCharacterEventRequest& request, ProcessApiCallback<WriteEventResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void WritePlayerEvent(WriteClientPlayerEventRequest& request, ProcessApiCallback<WriteEventResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void WriteTitleEvent(WriteTitleEventRequest& request, ProcessApiCallback<WriteEventResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void AddSharedGroupMembers(AddSharedGroupMembersRequest& request, ProcessApiCallback<AddSharedGroupMembersResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void CreateSharedGroup(CreateSharedGroupRequest& request, ProcessApiCallback<CreateSharedGroupResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void GetSharedGroupData(GetSharedGroupDataRequest& request, ProcessApiCallback<GetSharedGroupDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void RemoveSharedGroupMembers(RemoveSharedGroupMembersRequest& request, ProcessApiCallback<RemoveSharedGroupMembersResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void UpdateSharedGroupData(UpdateSharedGroupDataRequest& request, ProcessApiCallback<UpdateSharedGroupDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void ExecuteCloudScript(ExecuteCloudScriptRequest& request, ProcessApiCallback<ExecuteCloudScriptResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void GetContentDownloadUrl(GetContentDownloadUrlRequest& request, ProcessApiCallback<GetContentDownloadUrlResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void GetAllUsersCharacters(ListUsersCharactersRequest& request, ProcessApiCallback<ListUsersCharactersResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void GetCharacterLeaderboard(GetCharacterLeaderboardRequest& request, ProcessApiCallback<GetCharacterLeaderboardResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void GetCharacterStatistics(GetCharacterStatisticsRequest& request, ProcessApiCallback<GetCharacterStatisticsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void GetLeaderboardAroundCharacter(GetLeaderboardAroundCharacterRequest& request, ProcessApiCallback<GetLeaderboardAroundCharacterResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void GetLeaderboardForUserCharacters(GetLeaderboardForUsersCharactersRequest& request, ProcessApiCallback<GetLeaderboardForUsersCharactersResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void GrantCharacterToUser(GrantCharacterToUserRequest& request, ProcessApiCallback<GrantCharacterToUserResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void UpdateCharacterStatistics(UpdateCharacterStatisticsRequest& request, ProcessApiCallback<UpdateCharacterStatisticsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void GetCharacterData(GetCharacterDataRequest& request, ProcessApiCallback<GetCharacterDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void GetCharacterReadOnlyData(GetCharacterDataRequest& request, ProcessApiCallback<GetCharacterDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void UpdateCharacterData(UpdateCharacterDataRequest& request, ProcessApiCallback<UpdateCharacterDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void AcceptTrade(AcceptTradeRequest& request, ProcessApiCallback<AcceptTradeResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void CancelTrade(CancelTradeRequest& request, ProcessApiCallback<CancelTradeResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void GetPlayerTrades(GetPlayerTradesRequest& request, ProcessApiCallback<GetPlayerTradesResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void GetTradeStatus(GetTradeStatusRequest& request, ProcessApiCallback<GetTradeStatusResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void OpenTrade(OpenTradeRequest& request, ProcessApiCallback<OpenTradeResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void AttributeInstall(AttributeInstallRequest& request, ProcessApiCallback<AttributeInstallResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void GetPlayerSegments(ProcessApiCallback<GetPlayerSegmentsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void GetPlayerTags(GetPlayerTagsRequest& request, ProcessApiCallback<GetPlayerTagsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void AndroidDevicePushNotificationRegistration(AndroidDevicePushNotificationRegistrationRequest& request, ProcessApiCallback<AndroidDevicePushNotificationRegistrationResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void RegisterForIOSPushNotification(RegisterForIOSPushNotificationRequest& request, ProcessApiCallback<RegisterForIOSPushNotificationResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void RestoreIOSPurchases(RestoreIOSPurchasesRequest& request, ProcessApiCallback<RestoreIOSPurchasesResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void ValidateAmazonIAPReceipt(ValidateAmazonReceiptRequest& request, ProcessApiCallback<ValidateAmazonReceiptResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void ValidateGooglePlayPurchase(ValidateGooglePlayPurchaseRequest& request, ProcessApiCallback<ValidateGooglePlayPurchaseResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void ValidateIOSReceipt(ValidateIOSReceiptRequest& request, ProcessApiCallback<ValidateIOSReceiptResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
        virtual void ValidateWindowsStoreReceipt(ValidateWindowsReceiptRequest& request, ProcessApiCallback<ValidateWindowsReceiptResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) = 0;
    };

    using PlayFabClient_ClientRequestBus = AZ::EBus<PlayFabClient_ClientBus>;
} // namespace PlayFabClientSdk
