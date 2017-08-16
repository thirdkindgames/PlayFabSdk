// #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS: dbowen (2017/08/11)
#pragma once
#include <AzCore/EBus/EBus.h>
#include <PlayFabServerSdk/PlayFabServerDataModels.h>

namespace PlayFabServerSdk
{
    // Request based notification bus, use this bus when you want to listen for a callback from a specific instance of an API request.
    class PlayFabServer_ServerNotifications
        : public AZ::EBusTraits
    {

    public:
		// The EBus has multiple addresses. Addresses are not ordered. The address corresponds to the ID of the request.
		static const AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::ById;
		typedef int BusIdType;

        // ------------ General notifications (not related to a specific API call)
        virtual void OnError(const PlayFabError& error) {};

        // ------------ Generated API call wrappers
        virtual void OnAuthenticateSessionTicket(const ServerModels::AuthenticateSessionTicketResult& result) {};
        virtual void OnSetPlayerSecret(const ServerModels::SetPlayerSecretResult& result) {};
        virtual void OnBanUsers(const ServerModels::BanUsersResult& result) {};
        virtual void OnGetPlayerProfile(const ServerModels::GetPlayerProfileResult& result) {};
        virtual void OnGetPlayFabIDsFromFacebookIDs(const ServerModels::GetPlayFabIDsFromFacebookIDsResult& result) {};
        virtual void OnGetPlayFabIDsFromSteamIDs(const ServerModels::GetPlayFabIDsFromSteamIDsResult& result) {};
        virtual void OnGetUserAccountInfo(const ServerModels::GetUserAccountInfoResult& result) {};
        virtual void OnGetUserBans(const ServerModels::GetUserBansResult& result) {};
        virtual void OnRevokeAllBansForUser(const ServerModels::RevokeAllBansForUserResult& result) {};
        virtual void OnRevokeBans(const ServerModels::RevokeBansResult& result) {};
        virtual void OnSendPushNotification(const ServerModels::SendPushNotificationResult& result) {};
        virtual void OnUpdateAvatarUrl(const ServerModels::EmptyResult& result) {};
        virtual void OnUpdateBans(const ServerModels::UpdateBansResult& result) {};
        virtual void OnDeleteUsers(const ServerModels::DeleteUsersResult& result) {};
        virtual void OnGetFriendLeaderboard(const ServerModels::GetLeaderboardResult& result) {};
        virtual void OnGetLeaderboard(const ServerModels::GetLeaderboardResult& result) {};
        virtual void OnGetLeaderboardAroundUser(const ServerModels::GetLeaderboardAroundUserResult& result) {};
        virtual void OnGetPlayerCombinedInfo(const ServerModels::GetPlayerCombinedInfoResult& result) {};
        virtual void OnGetPlayerStatistics(const ServerModels::GetPlayerStatisticsResult& result) {};
        virtual void OnGetPlayerStatisticVersions(const ServerModels::GetPlayerStatisticVersionsResult& result) {};
        virtual void OnGetUserData(const ServerModels::GetUserDataResult& result) {};
        virtual void OnGetUserInternalData(const ServerModels::GetUserDataResult& result) {};
        virtual void OnGetUserPublisherData(const ServerModels::GetUserDataResult& result) {};
        virtual void OnGetUserPublisherInternalData(const ServerModels::GetUserDataResult& result) {};
        virtual void OnGetUserPublisherReadOnlyData(const ServerModels::GetUserDataResult& result) {};
        virtual void OnGetUserReadOnlyData(const ServerModels::GetUserDataResult& result) {};
        virtual void OnUpdatePlayerStatistics(const ServerModels::UpdatePlayerStatisticsResult& result) {};
        virtual void OnUpdateUserData(const ServerModels::UpdateUserDataResult& result) {};
        virtual void OnUpdateUserInternalData(const ServerModels::UpdateUserDataResult& result) {};
        virtual void OnUpdateUserPublisherData(const ServerModels::UpdateUserDataResult& result) {};
        virtual void OnUpdateUserPublisherInternalData(const ServerModels::UpdateUserDataResult& result) {};
        virtual void OnUpdateUserPublisherReadOnlyData(const ServerModels::UpdateUserDataResult& result) {};
        virtual void OnUpdateUserReadOnlyData(const ServerModels::UpdateUserDataResult& result) {};
        virtual void OnGetCatalogItems(const ServerModels::GetCatalogItemsResult& result) {};
        virtual void OnGetPublisherData(const ServerModels::GetPublisherDataResult& result) {};
        virtual void OnGetTime(const ServerModels::GetTimeResult& result) {};
        virtual void OnGetTitleData(const ServerModels::GetTitleDataResult& result) {};
        virtual void OnGetTitleInternalData(const ServerModels::GetTitleDataResult& result) {};
        virtual void OnGetTitleNews(const ServerModels::GetTitleNewsResult& result) {};
        virtual void OnSetPublisherData(const ServerModels::SetPublisherDataResult& result) {};
        virtual void OnSetTitleData(const ServerModels::SetTitleDataResult& result) {};
        virtual void OnSetTitleInternalData(const ServerModels::SetTitleDataResult& result) {};
        virtual void OnAddCharacterVirtualCurrency(const ServerModels::ModifyCharacterVirtualCurrencyResult& result) {};
        virtual void OnAddUserVirtualCurrency(const ServerModels::ModifyUserVirtualCurrencyResult& result) {};
        virtual void OnConsumeItem(const ServerModels::ConsumeItemResult& result) {};
        virtual void OnEvaluateRandomResultTable(const ServerModels::EvaluateRandomResultTableResult& result) {};
        virtual void OnGetCharacterInventory(const ServerModels::GetCharacterInventoryResult& result) {};
        virtual void OnGetRandomResultTables(const ServerModels::GetRandomResultTablesResult& result) {};
        virtual void OnGetUserInventory(const ServerModels::GetUserInventoryResult& result) {};
        virtual void OnGrantItemsToCharacter(const ServerModels::GrantItemsToCharacterResult& result) {};
        virtual void OnGrantItemsToUser(const ServerModels::GrantItemsToUserResult& result) {};
        virtual void OnGrantItemsToUsers(const ServerModels::GrantItemsToUsersResult& result) {};
        virtual void OnModifyItemUses(const ServerModels::ModifyItemUsesResult& result) {};
        virtual void OnMoveItemToCharacterFromCharacter(const ServerModels::MoveItemToCharacterFromCharacterResult& result) {};
        virtual void OnMoveItemToCharacterFromUser(const ServerModels::MoveItemToCharacterFromUserResult& result) {};
        virtual void OnMoveItemToUserFromCharacter(const ServerModels::MoveItemToUserFromCharacterResult& result) {};
        virtual void OnRedeemCoupon(const ServerModels::RedeemCouponResult& result) {};
        virtual void OnReportPlayer(const ServerModels::ReportPlayerServerResult& result) {};
        virtual void OnRevokeInventoryItem(const ServerModels::RevokeInventoryResult& result) {};
        virtual void OnSubtractCharacterVirtualCurrency(const ServerModels::ModifyCharacterVirtualCurrencyResult& result) {};
        virtual void OnSubtractUserVirtualCurrency(const ServerModels::ModifyUserVirtualCurrencyResult& result) {};
        virtual void OnUnlockContainerInstance(const ServerModels::UnlockContainerItemResult& result) {};
        virtual void OnUnlockContainerItem(const ServerModels::UnlockContainerItemResult& result) {};
        virtual void OnUpdateUserInventoryItemCustomData(const ServerModels::EmptyResult& result) {};
        virtual void OnAddFriend(const ServerModels::EmptyResult& result) {};
        virtual void OnGetFriendsList(const ServerModels::GetFriendsListResult& result) {};
        virtual void OnRemoveFriend(const ServerModels::EmptyResult& result) {};
        virtual void OnSetFriendTags(const ServerModels::EmptyResult& result) {};
        virtual void OnDeregisterGame(const ServerModels::DeregisterGameResponse& result) {};
        virtual void OnNotifyMatchmakerPlayerLeft(const ServerModels::NotifyMatchmakerPlayerLeftResult& result) {};
        virtual void OnRedeemMatchmakerTicket(const ServerModels::RedeemMatchmakerTicketResult& result) {};
        virtual void OnRefreshGameServerInstanceHeartbeat(const ServerModels::RefreshGameServerInstanceHeartbeatResult& result) {};
        virtual void OnRegisterGame(const ServerModels::RegisterGameResponse& result) {};
        virtual void OnSetGameServerInstanceData(const ServerModels::SetGameServerInstanceDataResult& result) {};
        virtual void OnSetGameServerInstanceState(const ServerModels::SetGameServerInstanceStateResult& result) {};
        virtual void OnSetGameServerInstanceTags(const ServerModels::SetGameServerInstanceTagsResult& result) {};
        virtual void OnWriteCharacterEvent(const ServerModels::WriteEventResponse& result) {};
        virtual void OnWritePlayerEvent(const ServerModels::WriteEventResponse& result) {};
        virtual void OnWriteTitleEvent(const ServerModels::WriteEventResponse& result) {};
        virtual void OnAddSharedGroupMembers(const ServerModels::AddSharedGroupMembersResult& result) {};
        virtual void OnCreateSharedGroup(const ServerModels::CreateSharedGroupResult& result) {};
        virtual void OnDeleteSharedGroup(const ServerModels::EmptyResult& result) {};
        virtual void OnGetSharedGroupData(const ServerModels::GetSharedGroupDataResult& result) {};
        virtual void OnRemoveSharedGroupMembers(const ServerModels::RemoveSharedGroupMembersResult& result) {};
        virtual void OnUpdateSharedGroupData(const ServerModels::UpdateSharedGroupDataResult& result) {};
        virtual void OnExecuteCloudScript(const ServerModels::ExecuteCloudScriptResult& result) {};
        virtual void OnGetContentDownloadUrl(const ServerModels::GetContentDownloadUrlResult& result) {};
        virtual void OnDeleteCharacterFromUser(const ServerModels::DeleteCharacterFromUserResult& result) {};
        virtual void OnGetAllUsersCharacters(const ServerModels::ListUsersCharactersResult& result) {};
        virtual void OnGetCharacterLeaderboard(const ServerModels::GetCharacterLeaderboardResult& result) {};
        virtual void OnGetCharacterStatistics(const ServerModels::GetCharacterStatisticsResult& result) {};
        virtual void OnGetLeaderboardAroundCharacter(const ServerModels::GetLeaderboardAroundCharacterResult& result) {};
        virtual void OnGetLeaderboardForUserCharacters(const ServerModels::GetLeaderboardForUsersCharactersResult& result) {};
        virtual void OnGrantCharacterToUser(const ServerModels::GrantCharacterToUserResult& result) {};
        virtual void OnUpdateCharacterStatistics(const ServerModels::UpdateCharacterStatisticsResult& result) {};
        virtual void OnGetCharacterData(const ServerModels::GetCharacterDataResult& result) {};
        virtual void OnGetCharacterInternalData(const ServerModels::GetCharacterDataResult& result) {};
        virtual void OnGetCharacterReadOnlyData(const ServerModels::GetCharacterDataResult& result) {};
        virtual void OnUpdateCharacterData(const ServerModels::UpdateCharacterDataResult& result) {};
        virtual void OnUpdateCharacterInternalData(const ServerModels::UpdateCharacterDataResult& result) {};
        virtual void OnUpdateCharacterReadOnlyData(const ServerModels::UpdateCharacterDataResult& result) {};
        virtual void OnAddPlayerTag(const ServerModels::AddPlayerTagResult& result) {};
        virtual void OnGetAllActionGroups(const ServerModels::GetAllActionGroupsResult& result) {};
        virtual void OnGetAllSegments(const ServerModels::GetAllSegmentsResult& result) {};
        virtual void OnGetPlayerSegments(const ServerModels::GetPlayerSegmentsResult& result) {};
        virtual void OnGetPlayersInSegment(const ServerModels::GetPlayersInSegmentResult& result) {};
        virtual void OnGetPlayerTags(const ServerModels::GetPlayerTagsResult& result) {};
        virtual void OnRemovePlayerTag(const ServerModels::RemovePlayerTagResult& result) {};
        virtual void OnAwardSteamAchievement(const ServerModels::AwardSteamAchievementResult& result) {};
    
   };

    using PlayFabServer_ServerNotificationBus = AZ::EBus<PlayFabServer_ServerNotifications>;

    // Global notification bus - use this bus when you want to listen for all responses to a particular type of request. 
    class PlayFabServer_ServerGlobalNotifications
        : public AZ::EBusTraits
    {

    public:
		// The EBus has a single address, all notifications go to this address.
		static const AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;

        // ------------ General notifications (not related to a specific API call)
        virtual void OnError(const PlayFabError& error, int requestId) {};

        // ------------ Generated API call wrappers
        virtual void OnAuthenticateSessionTicket(const ServerModels::AuthenticateSessionTicketResult& result, int requestId) {};
        virtual void OnSetPlayerSecret(const ServerModels::SetPlayerSecretResult& result, int requestId) {};
        virtual void OnBanUsers(const ServerModels::BanUsersResult& result, int requestId) {};
        virtual void OnGetPlayerProfile(const ServerModels::GetPlayerProfileResult& result, int requestId) {};
        virtual void OnGetPlayFabIDsFromFacebookIDs(const ServerModels::GetPlayFabIDsFromFacebookIDsResult& result, int requestId) {};
        virtual void OnGetPlayFabIDsFromSteamIDs(const ServerModels::GetPlayFabIDsFromSteamIDsResult& result, int requestId) {};
        virtual void OnGetUserAccountInfo(const ServerModels::GetUserAccountInfoResult& result, int requestId) {};
        virtual void OnGetUserBans(const ServerModels::GetUserBansResult& result, int requestId) {};
        virtual void OnRevokeAllBansForUser(const ServerModels::RevokeAllBansForUserResult& result, int requestId) {};
        virtual void OnRevokeBans(const ServerModels::RevokeBansResult& result, int requestId) {};
        virtual void OnSendPushNotification(const ServerModels::SendPushNotificationResult& result, int requestId) {};
        virtual void OnUpdateAvatarUrl(const ServerModels::EmptyResult& result, int requestId) {};
        virtual void OnUpdateBans(const ServerModels::UpdateBansResult& result, int requestId) {};
        virtual void OnDeleteUsers(const ServerModels::DeleteUsersResult& result, int requestId) {};
        virtual void OnGetFriendLeaderboard(const ServerModels::GetLeaderboardResult& result, int requestId) {};
        virtual void OnGetLeaderboard(const ServerModels::GetLeaderboardResult& result, int requestId) {};
        virtual void OnGetLeaderboardAroundUser(const ServerModels::GetLeaderboardAroundUserResult& result, int requestId) {};
        virtual void OnGetPlayerCombinedInfo(const ServerModels::GetPlayerCombinedInfoResult& result, int requestId) {};
        virtual void OnGetPlayerStatistics(const ServerModels::GetPlayerStatisticsResult& result, int requestId) {};
        virtual void OnGetPlayerStatisticVersions(const ServerModels::GetPlayerStatisticVersionsResult& result, int requestId) {};
        virtual void OnGetUserData(const ServerModels::GetUserDataResult& result, int requestId) {};
        virtual void OnGetUserInternalData(const ServerModels::GetUserDataResult& result, int requestId) {};
        virtual void OnGetUserPublisherData(const ServerModels::GetUserDataResult& result, int requestId) {};
        virtual void OnGetUserPublisherInternalData(const ServerModels::GetUserDataResult& result, int requestId) {};
        virtual void OnGetUserPublisherReadOnlyData(const ServerModels::GetUserDataResult& result, int requestId) {};
        virtual void OnGetUserReadOnlyData(const ServerModels::GetUserDataResult& result, int requestId) {};
        virtual void OnUpdatePlayerStatistics(const ServerModels::UpdatePlayerStatisticsResult& result, int requestId) {};
        virtual void OnUpdateUserData(const ServerModels::UpdateUserDataResult& result, int requestId) {};
        virtual void OnUpdateUserInternalData(const ServerModels::UpdateUserDataResult& result, int requestId) {};
        virtual void OnUpdateUserPublisherData(const ServerModels::UpdateUserDataResult& result, int requestId) {};
        virtual void OnUpdateUserPublisherInternalData(const ServerModels::UpdateUserDataResult& result, int requestId) {};
        virtual void OnUpdateUserPublisherReadOnlyData(const ServerModels::UpdateUserDataResult& result, int requestId) {};
        virtual void OnUpdateUserReadOnlyData(const ServerModels::UpdateUserDataResult& result, int requestId) {};
        virtual void OnGetCatalogItems(const ServerModels::GetCatalogItemsResult& result, int requestId) {};
        virtual void OnGetPublisherData(const ServerModels::GetPublisherDataResult& result, int requestId) {};
        virtual void OnGetTime(const ServerModels::GetTimeResult& result, int requestId) {};
        virtual void OnGetTitleData(const ServerModels::GetTitleDataResult& result, int requestId) {};
        virtual void OnGetTitleInternalData(const ServerModels::GetTitleDataResult& result, int requestId) {};
        virtual void OnGetTitleNews(const ServerModels::GetTitleNewsResult& result, int requestId) {};
        virtual void OnSetPublisherData(const ServerModels::SetPublisherDataResult& result, int requestId) {};
        virtual void OnSetTitleData(const ServerModels::SetTitleDataResult& result, int requestId) {};
        virtual void OnSetTitleInternalData(const ServerModels::SetTitleDataResult& result, int requestId) {};
        virtual void OnAddCharacterVirtualCurrency(const ServerModels::ModifyCharacterVirtualCurrencyResult& result, int requestId) {};
        virtual void OnAddUserVirtualCurrency(const ServerModels::ModifyUserVirtualCurrencyResult& result, int requestId) {};
        virtual void OnConsumeItem(const ServerModels::ConsumeItemResult& result, int requestId) {};
        virtual void OnEvaluateRandomResultTable(const ServerModels::EvaluateRandomResultTableResult& result, int requestId) {};
        virtual void OnGetCharacterInventory(const ServerModels::GetCharacterInventoryResult& result, int requestId) {};
        virtual void OnGetRandomResultTables(const ServerModels::GetRandomResultTablesResult& result, int requestId) {};
        virtual void OnGetUserInventory(const ServerModels::GetUserInventoryResult& result, int requestId) {};
        virtual void OnGrantItemsToCharacter(const ServerModels::GrantItemsToCharacterResult& result, int requestId) {};
        virtual void OnGrantItemsToUser(const ServerModels::GrantItemsToUserResult& result, int requestId) {};
        virtual void OnGrantItemsToUsers(const ServerModels::GrantItemsToUsersResult& result, int requestId) {};
        virtual void OnModifyItemUses(const ServerModels::ModifyItemUsesResult& result, int requestId) {};
        virtual void OnMoveItemToCharacterFromCharacter(const ServerModels::MoveItemToCharacterFromCharacterResult& result, int requestId) {};
        virtual void OnMoveItemToCharacterFromUser(const ServerModels::MoveItemToCharacterFromUserResult& result, int requestId) {};
        virtual void OnMoveItemToUserFromCharacter(const ServerModels::MoveItemToUserFromCharacterResult& result, int requestId) {};
        virtual void OnRedeemCoupon(const ServerModels::RedeemCouponResult& result, int requestId) {};
        virtual void OnReportPlayer(const ServerModels::ReportPlayerServerResult& result, int requestId) {};
        virtual void OnRevokeInventoryItem(const ServerModels::RevokeInventoryResult& result, int requestId) {};
        virtual void OnSubtractCharacterVirtualCurrency(const ServerModels::ModifyCharacterVirtualCurrencyResult& result, int requestId) {};
        virtual void OnSubtractUserVirtualCurrency(const ServerModels::ModifyUserVirtualCurrencyResult& result, int requestId) {};
        virtual void OnUnlockContainerInstance(const ServerModels::UnlockContainerItemResult& result, int requestId) {};
        virtual void OnUnlockContainerItem(const ServerModels::UnlockContainerItemResult& result, int requestId) {};
        virtual void OnUpdateUserInventoryItemCustomData(const ServerModels::EmptyResult& result, int requestId) {};
        virtual void OnAddFriend(const ServerModels::EmptyResult& result, int requestId) {};
        virtual void OnGetFriendsList(const ServerModels::GetFriendsListResult& result, int requestId) {};
        virtual void OnRemoveFriend(const ServerModels::EmptyResult& result, int requestId) {};
        virtual void OnSetFriendTags(const ServerModels::EmptyResult& result, int requestId) {};
        virtual void OnDeregisterGame(const ServerModels::DeregisterGameResponse& result, int requestId) {};
        virtual void OnNotifyMatchmakerPlayerLeft(const ServerModels::NotifyMatchmakerPlayerLeftResult& result, int requestId) {};
        virtual void OnRedeemMatchmakerTicket(const ServerModels::RedeemMatchmakerTicketResult& result, int requestId) {};
        virtual void OnRefreshGameServerInstanceHeartbeat(const ServerModels::RefreshGameServerInstanceHeartbeatResult& result, int requestId) {};
        virtual void OnRegisterGame(const ServerModels::RegisterGameResponse& result, int requestId) {};
        virtual void OnSetGameServerInstanceData(const ServerModels::SetGameServerInstanceDataResult& result, int requestId) {};
        virtual void OnSetGameServerInstanceState(const ServerModels::SetGameServerInstanceStateResult& result, int requestId) {};
        virtual void OnSetGameServerInstanceTags(const ServerModels::SetGameServerInstanceTagsResult& result, int requestId) {};
        virtual void OnWriteCharacterEvent(const ServerModels::WriteEventResponse& result, int requestId) {};
        virtual void OnWritePlayerEvent(const ServerModels::WriteEventResponse& result, int requestId) {};
        virtual void OnWriteTitleEvent(const ServerModels::WriteEventResponse& result, int requestId) {};
        virtual void OnAddSharedGroupMembers(const ServerModels::AddSharedGroupMembersResult& result, int requestId) {};
        virtual void OnCreateSharedGroup(const ServerModels::CreateSharedGroupResult& result, int requestId) {};
        virtual void OnDeleteSharedGroup(const ServerModels::EmptyResult& result, int requestId) {};
        virtual void OnGetSharedGroupData(const ServerModels::GetSharedGroupDataResult& result, int requestId) {};
        virtual void OnRemoveSharedGroupMembers(const ServerModels::RemoveSharedGroupMembersResult& result, int requestId) {};
        virtual void OnUpdateSharedGroupData(const ServerModels::UpdateSharedGroupDataResult& result, int requestId) {};
        virtual void OnExecuteCloudScript(const ServerModels::ExecuteCloudScriptResult& result, int requestId) {};
        virtual void OnGetContentDownloadUrl(const ServerModels::GetContentDownloadUrlResult& result, int requestId) {};
        virtual void OnDeleteCharacterFromUser(const ServerModels::DeleteCharacterFromUserResult& result, int requestId) {};
        virtual void OnGetAllUsersCharacters(const ServerModels::ListUsersCharactersResult& result, int requestId) {};
        virtual void OnGetCharacterLeaderboard(const ServerModels::GetCharacterLeaderboardResult& result, int requestId) {};
        virtual void OnGetCharacterStatistics(const ServerModels::GetCharacterStatisticsResult& result, int requestId) {};
        virtual void OnGetLeaderboardAroundCharacter(const ServerModels::GetLeaderboardAroundCharacterResult& result, int requestId) {};
        virtual void OnGetLeaderboardForUserCharacters(const ServerModels::GetLeaderboardForUsersCharactersResult& result, int requestId) {};
        virtual void OnGrantCharacterToUser(const ServerModels::GrantCharacterToUserResult& result, int requestId) {};
        virtual void OnUpdateCharacterStatistics(const ServerModels::UpdateCharacterStatisticsResult& result, int requestId) {};
        virtual void OnGetCharacterData(const ServerModels::GetCharacterDataResult& result, int requestId) {};
        virtual void OnGetCharacterInternalData(const ServerModels::GetCharacterDataResult& result, int requestId) {};
        virtual void OnGetCharacterReadOnlyData(const ServerModels::GetCharacterDataResult& result, int requestId) {};
        virtual void OnUpdateCharacterData(const ServerModels::UpdateCharacterDataResult& result, int requestId) {};
        virtual void OnUpdateCharacterInternalData(const ServerModels::UpdateCharacterDataResult& result, int requestId) {};
        virtual void OnUpdateCharacterReadOnlyData(const ServerModels::UpdateCharacterDataResult& result, int requestId) {};
        virtual void OnAddPlayerTag(const ServerModels::AddPlayerTagResult& result, int requestId) {};
        virtual void OnGetAllActionGroups(const ServerModels::GetAllActionGroupsResult& result, int requestId) {};
        virtual void OnGetAllSegments(const ServerModels::GetAllSegmentsResult& result, int requestId) {};
        virtual void OnGetPlayerSegments(const ServerModels::GetPlayerSegmentsResult& result, int requestId) {};
        virtual void OnGetPlayersInSegment(const ServerModels::GetPlayersInSegmentResult& result, int requestId) {};
        virtual void OnGetPlayerTags(const ServerModels::GetPlayerTagsResult& result, int requestId) {};
        virtual void OnRemovePlayerTag(const ServerModels::RemovePlayerTagResult& result, int requestId) {};
        virtual void OnAwardSteamAchievement(const ServerModels::AwardSteamAchievementResult& result, int requestId) {};
    
   };

    using PlayFabServer_ServerGlobalNotificationBus = AZ::EBus<PlayFabServer_ServerGlobalNotifications>;

} // namespace PlayFabServerSdk
