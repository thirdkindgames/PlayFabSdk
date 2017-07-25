
#pragma once

#include <AzCore/Component/Component.h>

#include <PlayFabClientSdk/PlayFabClient_ClientBus.h>

namespace PlayFabClientSdk
{
    using namespace ClientModels;

    class PlayFabClient_ClientSysComponent
        : public AZ::Component
        , protected PlayFabClient_ClientRequestBus::Handler
    {
    public:
        AZ_COMPONENT(PlayFabClient_ClientSysComponent, "{FDEEA325-EC4C-4D4B-9FBD-E64A8D523CE6}");

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

    protected:
        ////////////////////////////////////////////////////////////////////////
        // PlayFabClient_ClientRequestBus interface implementation

        // Public, Client-Specific
        bool IsClientLoggedIn() override;
        int GetPendingCalls() override;

        // ------------ Generated Api calls
        void GetPhotonAuthenticationToken(GetPhotonAuthenticationTokenRequest& request, ProcessApiCallback<GetPhotonAuthenticationTokenResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetTitlePublicKey(GetTitlePublicKeyRequest& request, ProcessApiCallback<GetTitlePublicKeyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetWindowsHelloChallenge(GetWindowsHelloChallengeRequest& request, ProcessApiCallback<GetWindowsHelloChallengeResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void LoginWithAndroidDeviceID(LoginWithAndroidDeviceIDRequest& request, ProcessApiCallback<LoginResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void LoginWithCustomID(LoginWithCustomIDRequest& request, ProcessApiCallback<LoginResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void LoginWithEmailAddress(LoginWithEmailAddressRequest& request, ProcessApiCallback<LoginResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void LoginWithFacebook(LoginWithFacebookRequest& request, ProcessApiCallback<LoginResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void LoginWithGameCenter(LoginWithGameCenterRequest& request, ProcessApiCallback<LoginResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void LoginWithGoogleAccount(LoginWithGoogleAccountRequest& request, ProcessApiCallback<LoginResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void LoginWithIOSDeviceID(LoginWithIOSDeviceIDRequest& request, ProcessApiCallback<LoginResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void LoginWithKongregate(LoginWithKongregateRequest& request, ProcessApiCallback<LoginResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void LoginWithPlayFab(LoginWithPlayFabRequest& request, ProcessApiCallback<LoginResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void LoginWithSteam(LoginWithSteamRequest& request, ProcessApiCallback<LoginResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void LoginWithTwitch(LoginWithTwitchRequest& request, ProcessApiCallback<LoginResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void LoginWithWindowsHello(LoginWithWindowsHelloRequest& request, ProcessApiCallback<LoginResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void RegisterPlayFabUser(RegisterPlayFabUserRequest& request, ProcessApiCallback<RegisterPlayFabUserResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void RegisterWithWindowsHello(RegisterWithWindowsHelloRequest& request, ProcessApiCallback<LoginResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void SetPlayerSecret(SetPlayerSecretRequest& request, ProcessApiCallback<SetPlayerSecretResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void AddGenericID(AddGenericIDRequest& request, ProcessApiCallback<AddGenericIDResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void AddUsernamePassword(AddUsernamePasswordRequest& request, ProcessApiCallback<AddUsernamePasswordResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetAccountInfo(GetAccountInfoRequest& request, ProcessApiCallback<GetAccountInfoResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetPlayerCombinedInfo(GetPlayerCombinedInfoRequest& request, ProcessApiCallback<GetPlayerCombinedInfoResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetPlayerProfile(GetPlayerProfileRequest& request, ProcessApiCallback<GetPlayerProfileResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetPlayFabIDsFromFacebookIDs(GetPlayFabIDsFromFacebookIDsRequest& request, ProcessApiCallback<GetPlayFabIDsFromFacebookIDsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetPlayFabIDsFromGameCenterIDs(GetPlayFabIDsFromGameCenterIDsRequest& request, ProcessApiCallback<GetPlayFabIDsFromGameCenterIDsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetPlayFabIDsFromGenericIDs(GetPlayFabIDsFromGenericIDsRequest& request, ProcessApiCallback<GetPlayFabIDsFromGenericIDsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetPlayFabIDsFromGoogleIDs(GetPlayFabIDsFromGoogleIDsRequest& request, ProcessApiCallback<GetPlayFabIDsFromGoogleIDsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetPlayFabIDsFromKongregateIDs(GetPlayFabIDsFromKongregateIDsRequest& request, ProcessApiCallback<GetPlayFabIDsFromKongregateIDsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetPlayFabIDsFromSteamIDs(GetPlayFabIDsFromSteamIDsRequest& request, ProcessApiCallback<GetPlayFabIDsFromSteamIDsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetPlayFabIDsFromTwitchIDs(GetPlayFabIDsFromTwitchIDsRequest& request, ProcessApiCallback<GetPlayFabIDsFromTwitchIDsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void LinkAndroidDeviceID(LinkAndroidDeviceIDRequest& request, ProcessApiCallback<LinkAndroidDeviceIDResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void LinkCustomID(LinkCustomIDRequest& request, ProcessApiCallback<LinkCustomIDResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void LinkFacebookAccount(LinkFacebookAccountRequest& request, ProcessApiCallback<LinkFacebookAccountResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void LinkGameCenterAccount(LinkGameCenterAccountRequest& request, ProcessApiCallback<LinkGameCenterAccountResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void LinkGoogleAccount(LinkGoogleAccountRequest& request, ProcessApiCallback<LinkGoogleAccountResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void LinkIOSDeviceID(LinkIOSDeviceIDRequest& request, ProcessApiCallback<LinkIOSDeviceIDResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void LinkKongregate(LinkKongregateAccountRequest& request, ProcessApiCallback<LinkKongregateAccountResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void LinkSteamAccount(LinkSteamAccountRequest& request, ProcessApiCallback<LinkSteamAccountResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void LinkTwitch(LinkTwitchAccountRequest& request, ProcessApiCallback<LinkTwitchAccountResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void LinkWindowsHello(LinkWindowsHelloAccountRequest& request, ProcessApiCallback<LinkWindowsHelloAccountResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void RemoveGenericID(RemoveGenericIDRequest& request, ProcessApiCallback<RemoveGenericIDResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void ReportPlayer(ReportPlayerClientRequest& request, ProcessApiCallback<ReportPlayerClientResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void SendAccountRecoveryEmail(SendAccountRecoveryEmailRequest& request, ProcessApiCallback<SendAccountRecoveryEmailResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UnlinkAndroidDeviceID(UnlinkAndroidDeviceIDRequest& request, ProcessApiCallback<UnlinkAndroidDeviceIDResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UnlinkCustomID(UnlinkCustomIDRequest& request, ProcessApiCallback<UnlinkCustomIDResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UnlinkFacebookAccount(ProcessApiCallback<UnlinkFacebookAccountResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UnlinkGameCenterAccount(ProcessApiCallback<UnlinkGameCenterAccountResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UnlinkGoogleAccount(ProcessApiCallback<UnlinkGoogleAccountResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UnlinkIOSDeviceID(UnlinkIOSDeviceIDRequest& request, ProcessApiCallback<UnlinkIOSDeviceIDResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UnlinkKongregate(ProcessApiCallback<UnlinkKongregateAccountResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UnlinkSteamAccount(ProcessApiCallback<UnlinkSteamAccountResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UnlinkTwitch(ProcessApiCallback<UnlinkTwitchAccountResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UnlinkWindowsHello(UnlinkWindowsHelloAccountRequest& request, ProcessApiCallback<UnlinkWindowsHelloAccountResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UpdateAvatarUrl(UpdateAvatarUrlRequest& request, ProcessApiCallback<EmptyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UpdateUserTitleDisplayName(UpdateUserTitleDisplayNameRequest& request, ProcessApiCallback<UpdateUserTitleDisplayNameResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetFriendLeaderboard(GetFriendLeaderboardRequest& request, ProcessApiCallback<GetLeaderboardResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetFriendLeaderboardAroundPlayer(GetFriendLeaderboardAroundPlayerRequest& request, ProcessApiCallback<GetFriendLeaderboardAroundPlayerResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetLeaderboard(GetLeaderboardRequest& request, ProcessApiCallback<GetLeaderboardResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetLeaderboardAroundPlayer(GetLeaderboardAroundPlayerRequest& request, ProcessApiCallback<GetLeaderboardAroundPlayerResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetPlayerStatistics(GetPlayerStatisticsRequest& request, ProcessApiCallback<GetPlayerStatisticsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetPlayerStatisticVersions(GetPlayerStatisticVersionsRequest& request, ProcessApiCallback<GetPlayerStatisticVersionsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetUserData(GetUserDataRequest& request, ProcessApiCallback<GetUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetUserPublisherData(GetUserDataRequest& request, ProcessApiCallback<GetUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetUserPublisherReadOnlyData(GetUserDataRequest& request, ProcessApiCallback<GetUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetUserReadOnlyData(GetUserDataRequest& request, ProcessApiCallback<GetUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UpdatePlayerStatistics(UpdatePlayerStatisticsRequest& request, ProcessApiCallback<UpdatePlayerStatisticsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UpdateUserData(UpdateUserDataRequest& request, ProcessApiCallback<UpdateUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UpdateUserPublisherData(UpdateUserDataRequest& request, ProcessApiCallback<UpdateUserDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetCatalogItems(GetCatalogItemsRequest& request, ProcessApiCallback<GetCatalogItemsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetPublisherData(GetPublisherDataRequest& request, ProcessApiCallback<GetPublisherDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetStoreItems(GetStoreItemsRequest& request, ProcessApiCallback<GetStoreItemsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetTime(ProcessApiCallback<GetTimeResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetTitleData(GetTitleDataRequest& request, ProcessApiCallback<GetTitleDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetTitleNews(GetTitleNewsRequest& request, ProcessApiCallback<GetTitleNewsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void AddUserVirtualCurrency(AddUserVirtualCurrencyRequest& request, ProcessApiCallback<ModifyUserVirtualCurrencyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void ConfirmPurchase(ConfirmPurchaseRequest& request, ProcessApiCallback<ConfirmPurchaseResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void ConsumeItem(ConsumeItemRequest& request, ProcessApiCallback<ConsumeItemResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetCharacterInventory(GetCharacterInventoryRequest& request, ProcessApiCallback<GetCharacterInventoryResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetPurchase(GetPurchaseRequest& request, ProcessApiCallback<GetPurchaseResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetUserInventory(ProcessApiCallback<GetUserInventoryResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void PayForPurchase(PayForPurchaseRequest& request, ProcessApiCallback<PayForPurchaseResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void PurchaseItem(PurchaseItemRequest& request, ProcessApiCallback<PurchaseItemResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void RedeemCoupon(RedeemCouponRequest& request, ProcessApiCallback<RedeemCouponResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void StartPurchase(StartPurchaseRequest& request, ProcessApiCallback<StartPurchaseResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void SubtractUserVirtualCurrency(SubtractUserVirtualCurrencyRequest& request, ProcessApiCallback<ModifyUserVirtualCurrencyResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UnlockContainerInstance(UnlockContainerInstanceRequest& request, ProcessApiCallback<UnlockContainerItemResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UnlockContainerItem(UnlockContainerItemRequest& request, ProcessApiCallback<UnlockContainerItemResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void AddFriend(AddFriendRequest& request, ProcessApiCallback<AddFriendResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetFriendsList(GetFriendsListRequest& request, ProcessApiCallback<GetFriendsListResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void RemoveFriend(RemoveFriendRequest& request, ProcessApiCallback<RemoveFriendResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void SetFriendTags(SetFriendTagsRequest& request, ProcessApiCallback<SetFriendTagsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetCurrentGames(CurrentGamesRequest& request, ProcessApiCallback<CurrentGamesResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetGameServerRegions(GameServerRegionsRequest& request, ProcessApiCallback<GameServerRegionsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void Matchmake(MatchmakeRequest& request, ProcessApiCallback<MatchmakeResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void StartGame(StartGameRequest& request, ProcessApiCallback<StartGameResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void WriteCharacterEvent(WriteClientCharacterEventRequest& request, ProcessApiCallback<WriteEventResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void WritePlayerEvent(WriteClientPlayerEventRequest& request, ProcessApiCallback<WriteEventResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void WriteTitleEvent(WriteTitleEventRequest& request, ProcessApiCallback<WriteEventResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void AddSharedGroupMembers(AddSharedGroupMembersRequest& request, ProcessApiCallback<AddSharedGroupMembersResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void CreateSharedGroup(CreateSharedGroupRequest& request, ProcessApiCallback<CreateSharedGroupResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetSharedGroupData(GetSharedGroupDataRequest& request, ProcessApiCallback<GetSharedGroupDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void RemoveSharedGroupMembers(RemoveSharedGroupMembersRequest& request, ProcessApiCallback<RemoveSharedGroupMembersResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UpdateSharedGroupData(UpdateSharedGroupDataRequest& request, ProcessApiCallback<UpdateSharedGroupDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void ExecuteCloudScript(ExecuteCloudScriptRequest& request, ProcessApiCallback<ExecuteCloudScriptResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetContentDownloadUrl(GetContentDownloadUrlRequest& request, ProcessApiCallback<GetContentDownloadUrlResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetAllUsersCharacters(ListUsersCharactersRequest& request, ProcessApiCallback<ListUsersCharactersResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetCharacterLeaderboard(GetCharacterLeaderboardRequest& request, ProcessApiCallback<GetCharacterLeaderboardResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetCharacterStatistics(GetCharacterStatisticsRequest& request, ProcessApiCallback<GetCharacterStatisticsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetLeaderboardAroundCharacter(GetLeaderboardAroundCharacterRequest& request, ProcessApiCallback<GetLeaderboardAroundCharacterResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetLeaderboardForUserCharacters(GetLeaderboardForUsersCharactersRequest& request, ProcessApiCallback<GetLeaderboardForUsersCharactersResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GrantCharacterToUser(GrantCharacterToUserRequest& request, ProcessApiCallback<GrantCharacterToUserResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UpdateCharacterStatistics(UpdateCharacterStatisticsRequest& request, ProcessApiCallback<UpdateCharacterStatisticsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetCharacterData(GetCharacterDataRequest& request, ProcessApiCallback<GetCharacterDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetCharacterReadOnlyData(GetCharacterDataRequest& request, ProcessApiCallback<GetCharacterDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void UpdateCharacterData(UpdateCharacterDataRequest& request, ProcessApiCallback<UpdateCharacterDataResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void AcceptTrade(AcceptTradeRequest& request, ProcessApiCallback<AcceptTradeResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void CancelTrade(CancelTradeRequest& request, ProcessApiCallback<CancelTradeResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetPlayerTrades(GetPlayerTradesRequest& request, ProcessApiCallback<GetPlayerTradesResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetTradeStatus(GetTradeStatusRequest& request, ProcessApiCallback<GetTradeStatusResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void OpenTrade(OpenTradeRequest& request, ProcessApiCallback<OpenTradeResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void AttributeInstall(AttributeInstallRequest& request, ProcessApiCallback<AttributeInstallResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetPlayerSegments(ProcessApiCallback<GetPlayerSegmentsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetPlayerTags(GetPlayerTagsRequest& request, ProcessApiCallback<GetPlayerTagsResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void AndroidDevicePushNotificationRegistration(AndroidDevicePushNotificationRegistrationRequest& request, ProcessApiCallback<AndroidDevicePushNotificationRegistrationResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void RegisterForIOSPushNotification(RegisterForIOSPushNotificationRequest& request, ProcessApiCallback<RegisterForIOSPushNotificationResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void RestoreIOSPurchases(RestoreIOSPurchasesRequest& request, ProcessApiCallback<RestoreIOSPurchasesResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void ValidateAmazonIAPReceipt(ValidateAmazonReceiptRequest& request, ProcessApiCallback<ValidateAmazonReceiptResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void ValidateGooglePlayPurchase(ValidateGooglePlayPurchaseRequest& request, ProcessApiCallback<ValidateGooglePlayPurchaseResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void ValidateIOSReceipt(ValidateIOSReceiptRequest& request, ProcessApiCallback<ValidateIOSReceiptResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void ValidateWindowsStoreReceipt(ValidateWindowsReceiptRequest& request, ProcessApiCallback<ValidateWindowsReceiptResult> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
