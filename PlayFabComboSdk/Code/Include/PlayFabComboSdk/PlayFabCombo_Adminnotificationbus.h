// #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS: dbowen (2017/08/11)
#pragma once
#include <AzCore/EBus/EBus.h>
#include <PlayFabComboSdk/PlayFabAdminDataModels.h>

namespace PlayFabComboSdk
{
    // Request based notification bus, use this bus when you want to listen for a callback from a specific instance of an API request.
    class PlayFabCombo_AdminNotifications
        : public AZ::EBusTraits
    {

    public:
		// The EBus has multiple addresses. Addresses are not ordered. The address corresponds to the ID of the request.
		static const AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::ById;
		typedef int BusIdType;

        // ------------ General notifications (not related to a specific API call)
        virtual void OnError(const PlayFabError& error) {};

        // ------------ Generated API call wrappers
        virtual void OnCreatePlayerSharedSecret(const AdminModels::CreatePlayerSharedSecretResult& result) {};
        virtual void OnDeletePlayerSharedSecret(const AdminModels::DeletePlayerSharedSecretResult& result) {};
        virtual void OnGetPlayerSharedSecrets(const AdminModels::GetPlayerSharedSecretsResult& result) {};
        virtual void OnGetPolicy(const AdminModels::GetPolicyResponse& result) {};
        virtual void OnSetPlayerSecret(const AdminModels::SetPlayerSecretResult& result) {};
        virtual void OnUpdatePlayerSharedSecret(const AdminModels::UpdatePlayerSharedSecretResult& result) {};
        virtual void OnUpdatePolicy(const AdminModels::UpdatePolicyResponse& result) {};
        virtual void OnBanUsers(const AdminModels::BanUsersResult& result) {};
        virtual void OnDeletePlayer(const AdminModels::DeletePlayerResult& result) {};
        virtual void OnGetUserAccountInfo(const AdminModels::LookupUserAccountInfoResult& result) {};
        virtual void OnGetUserBans(const AdminModels::GetUserBansResult& result) {};
        virtual void OnResetUsers(const AdminModels::BlankResult& result) {};
        virtual void OnRevokeAllBansForUser(const AdminModels::RevokeAllBansForUserResult& result) {};
        virtual void OnRevokeBans(const AdminModels::RevokeBansResult& result) {};
        virtual void OnSendAccountRecoveryEmail(const AdminModels::SendAccountRecoveryEmailResult& result) {};
        virtual void OnUpdateBans(const AdminModels::UpdateBansResult& result) {};
        virtual void OnUpdateUserTitleDisplayName(const AdminModels::UpdateUserTitleDisplayNameResult& result) {};
        virtual void OnCreatePlayerStatisticDefinition(const AdminModels::CreatePlayerStatisticDefinitionResult& result) {};
        virtual void OnDeleteUsers(const AdminModels::DeleteUsersResult& result) {};
        virtual void OnGetDataReport(const AdminModels::GetDataReportResult& result) {};
        virtual void OnGetPlayerStatisticDefinitions(const AdminModels::GetPlayerStatisticDefinitionsResult& result) {};
        virtual void OnGetPlayerStatisticVersions(const AdminModels::GetPlayerStatisticVersionsResult& result) {};
        virtual void OnGetUserData(const AdminModels::GetUserDataResult& result) {};
        virtual void OnGetUserInternalData(const AdminModels::GetUserDataResult& result) {};
        virtual void OnGetUserPublisherData(const AdminModels::GetUserDataResult& result) {};
        virtual void OnGetUserPublisherInternalData(const AdminModels::GetUserDataResult& result) {};
        virtual void OnGetUserPublisherReadOnlyData(const AdminModels::GetUserDataResult& result) {};
        virtual void OnGetUserReadOnlyData(const AdminModels::GetUserDataResult& result) {};
        virtual void OnIncrementPlayerStatisticVersion(const AdminModels::IncrementPlayerStatisticVersionResult& result) {};
        virtual void OnRefundPurchase(const AdminModels::RefundPurchaseResponse& result) {};
        virtual void OnResetUserStatistics(const AdminModels::ResetUserStatisticsResult& result) {};
        virtual void OnResolvePurchaseDispute(const AdminModels::ResolvePurchaseDisputeResponse& result) {};
        virtual void OnUpdatePlayerStatisticDefinition(const AdminModels::UpdatePlayerStatisticDefinitionResult& result) {};
        virtual void OnUpdateUserData(const AdminModels::UpdateUserDataResult& result) {};
        virtual void OnUpdateUserInternalData(const AdminModels::UpdateUserDataResult& result) {};
        virtual void OnUpdateUserPublisherData(const AdminModels::UpdateUserDataResult& result) {};
        virtual void OnUpdateUserPublisherInternalData(const AdminModels::UpdateUserDataResult& result) {};
        virtual void OnUpdateUserPublisherReadOnlyData(const AdminModels::UpdateUserDataResult& result) {};
        virtual void OnUpdateUserReadOnlyData(const AdminModels::UpdateUserDataResult& result) {};
        virtual void OnAddNews(const AdminModels::AddNewsResult& result) {};
        virtual void OnAddVirtualCurrencyTypes(const AdminModels::BlankResult& result) {};
        virtual void OnDeleteStore(const AdminModels::DeleteStoreResult& result) {};
        virtual void OnGetCatalogItems(const AdminModels::GetCatalogItemsResult& result) {};
        virtual void OnGetPublisherData(const AdminModels::GetPublisherDataResult& result) {};
        virtual void OnGetRandomResultTables(const AdminModels::GetRandomResultTablesResult& result) {};
        virtual void OnGetStoreItems(const AdminModels::GetStoreItemsResult& result) {};
        virtual void OnGetTitleData(const AdminModels::GetTitleDataResult& result) {};
        virtual void OnGetTitleInternalData(const AdminModels::GetTitleDataResult& result) {};
        virtual void OnListVirtualCurrencyTypes(const AdminModels::ListVirtualCurrencyTypesResult& result) {};
        virtual void OnRemoveVirtualCurrencyTypes(const AdminModels::BlankResult& result) {};
        virtual void OnSetCatalogItems(const AdminModels::UpdateCatalogItemsResult& result) {};
        virtual void OnSetStoreItems(const AdminModels::UpdateStoreItemsResult& result) {};
        virtual void OnSetTitleData(const AdminModels::SetTitleDataResult& result) {};
        virtual void OnSetTitleInternalData(const AdminModels::SetTitleDataResult& result) {};
        virtual void OnSetupPushNotification(const AdminModels::SetupPushNotificationResult& result) {};
        virtual void OnUpdateCatalogItems(const AdminModels::UpdateCatalogItemsResult& result) {};
        virtual void OnUpdateRandomResultTables(const AdminModels::UpdateRandomResultTablesResult& result) {};
        virtual void OnUpdateStoreItems(const AdminModels::UpdateStoreItemsResult& result) {};
        virtual void OnAddUserVirtualCurrency(const AdminModels::ModifyUserVirtualCurrencyResult& result) {};
        virtual void OnGetUserInventory(const AdminModels::GetUserInventoryResult& result) {};
        virtual void OnGrantItemsToUsers(const AdminModels::GrantItemsToUsersResult& result) {};
        virtual void OnRevokeInventoryItem(const AdminModels::RevokeInventoryResult& result) {};
        virtual void OnSubtractUserVirtualCurrency(const AdminModels::ModifyUserVirtualCurrencyResult& result) {};
        virtual void OnGetMatchmakerGameInfo(const AdminModels::GetMatchmakerGameInfoResult& result) {};
        virtual void OnGetMatchmakerGameModes(const AdminModels::GetMatchmakerGameModesResult& result) {};
        virtual void OnModifyMatchmakerGameModes(const AdminModels::ModifyMatchmakerGameModesResult& result) {};
        virtual void OnAddServerBuild(const AdminModels::AddServerBuildResult& result) {};
        virtual void OnGetServerBuildInfo(const AdminModels::GetServerBuildInfoResult& result) {};
        virtual void OnGetServerBuildUploadUrl(const AdminModels::GetServerBuildUploadURLResult& result) {};
        virtual void OnListServerBuilds(const AdminModels::ListBuildsResult& result) {};
        virtual void OnModifyServerBuild(const AdminModels::ModifyServerBuildResult& result) {};
        virtual void OnRemoveServerBuild(const AdminModels::RemoveServerBuildResult& result) {};
        virtual void OnSetPublisherData(const AdminModels::SetPublisherDataResult& result) {};
        virtual void OnGetCloudScriptRevision(const AdminModels::GetCloudScriptRevisionResult& result) {};
        virtual void OnGetCloudScriptVersions(const AdminModels::GetCloudScriptVersionsResult& result) {};
        virtual void OnSetPublishedRevision(const AdminModels::SetPublishedRevisionResult& result) {};
        virtual void OnUpdateCloudScript(const AdminModels::UpdateCloudScriptResult& result) {};
        virtual void OnDeleteContent(const AdminModels::BlankResult& result) {};
        virtual void OnGetContentList(const AdminModels::GetContentListResult& result) {};
        virtual void OnGetContentUploadUrl(const AdminModels::GetContentUploadUrlResult& result) {};
        virtual void OnResetCharacterStatistics(const AdminModels::ResetCharacterStatisticsResult& result) {};
        virtual void OnAddPlayerTag(const AdminModels::AddPlayerTagResult& result) {};
        virtual void OnGetAllActionGroups(const AdminModels::GetAllActionGroupsResult& result) {};
        virtual void OnGetAllSegments(const AdminModels::GetAllSegmentsResult& result) {};
        virtual void OnGetPlayerSegments(const AdminModels::GetPlayerSegmentsResult& result) {};
        virtual void OnGetPlayersInSegment(const AdminModels::GetPlayersInSegmentResult& result) {};
        virtual void OnGetPlayerTags(const AdminModels::GetPlayerTagsResult& result) {};
        virtual void OnRemovePlayerTag(const AdminModels::RemovePlayerTagResult& result) {};
        virtual void OnAbortTaskInstance(const AdminModels::EmptyResult& result) {};
        virtual void OnCreateActionsOnPlayersInSegmentTask(const AdminModels::CreateTaskResult& result) {};
        virtual void OnCreateCloudScriptTask(const AdminModels::CreateTaskResult& result) {};
        virtual void OnDeleteTask(const AdminModels::EmptyResult& result) {};
        virtual void OnGetActionsOnPlayersInSegmentTaskInstance(const AdminModels::GetActionsOnPlayersInSegmentTaskInstanceResult& result) {};
        virtual void OnGetCloudScriptTaskInstance(const AdminModels::GetCloudScriptTaskInstanceResult& result) {};
        virtual void OnGetTaskInstances(const AdminModels::GetTaskInstancesResult& result) {};
        virtual void OnGetTasks(const AdminModels::GetTasksResult& result) {};
        virtual void OnRunTask(const AdminModels::RunTaskResult& result) {};
        virtual void OnUpdateTask(const AdminModels::EmptyResult& result) {};
    
   };

    using PlayFabCombo_AdminNotificationBus = AZ::EBus<PlayFabCombo_AdminNotifications>;

    // Global notification bus - use this bus when you want to listen for all responses to a particular type of request. 
    class PlayFabCombo_AdminGlobalNotifications
        : public AZ::EBusTraits
    {

    public:
		// The EBus has a single address, all notifications go to this address.
		static const AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;

        // ------------ General notifications (not related to a specific API call)
        virtual void OnError(const PlayFabError& error, int requestId) {};

        // ------------ Generated API call wrappers
        virtual void OnCreatePlayerSharedSecret(const AdminModels::CreatePlayerSharedSecretResult& result, int requestId) {};
        virtual void OnDeletePlayerSharedSecret(const AdminModels::DeletePlayerSharedSecretResult& result, int requestId) {};
        virtual void OnGetPlayerSharedSecrets(const AdminModels::GetPlayerSharedSecretsResult& result, int requestId) {};
        virtual void OnGetPolicy(const AdminModels::GetPolicyResponse& result, int requestId) {};
        virtual void OnSetPlayerSecret(const AdminModels::SetPlayerSecretResult& result, int requestId) {};
        virtual void OnUpdatePlayerSharedSecret(const AdminModels::UpdatePlayerSharedSecretResult& result, int requestId) {};
        virtual void OnUpdatePolicy(const AdminModels::UpdatePolicyResponse& result, int requestId) {};
        virtual void OnBanUsers(const AdminModels::BanUsersResult& result, int requestId) {};
        virtual void OnDeletePlayer(const AdminModels::DeletePlayerResult& result, int requestId) {};
        virtual void OnGetUserAccountInfo(const AdminModels::LookupUserAccountInfoResult& result, int requestId) {};
        virtual void OnGetUserBans(const AdminModels::GetUserBansResult& result, int requestId) {};
        virtual void OnResetUsers(const AdminModels::BlankResult& result, int requestId) {};
        virtual void OnRevokeAllBansForUser(const AdminModels::RevokeAllBansForUserResult& result, int requestId) {};
        virtual void OnRevokeBans(const AdminModels::RevokeBansResult& result, int requestId) {};
        virtual void OnSendAccountRecoveryEmail(const AdminModels::SendAccountRecoveryEmailResult& result, int requestId) {};
        virtual void OnUpdateBans(const AdminModels::UpdateBansResult& result, int requestId) {};
        virtual void OnUpdateUserTitleDisplayName(const AdminModels::UpdateUserTitleDisplayNameResult& result, int requestId) {};
        virtual void OnCreatePlayerStatisticDefinition(const AdminModels::CreatePlayerStatisticDefinitionResult& result, int requestId) {};
        virtual void OnDeleteUsers(const AdminModels::DeleteUsersResult& result, int requestId) {};
        virtual void OnGetDataReport(const AdminModels::GetDataReportResult& result, int requestId) {};
        virtual void OnGetPlayerStatisticDefinitions(const AdminModels::GetPlayerStatisticDefinitionsResult& result, int requestId) {};
        virtual void OnGetPlayerStatisticVersions(const AdminModels::GetPlayerStatisticVersionsResult& result, int requestId) {};
        virtual void OnGetUserData(const AdminModels::GetUserDataResult& result, int requestId) {};
        virtual void OnGetUserInternalData(const AdminModels::GetUserDataResult& result, int requestId) {};
        virtual void OnGetUserPublisherData(const AdminModels::GetUserDataResult& result, int requestId) {};
        virtual void OnGetUserPublisherInternalData(const AdminModels::GetUserDataResult& result, int requestId) {};
        virtual void OnGetUserPublisherReadOnlyData(const AdminModels::GetUserDataResult& result, int requestId) {};
        virtual void OnGetUserReadOnlyData(const AdminModels::GetUserDataResult& result, int requestId) {};
        virtual void OnIncrementPlayerStatisticVersion(const AdminModels::IncrementPlayerStatisticVersionResult& result, int requestId) {};
        virtual void OnRefundPurchase(const AdminModels::RefundPurchaseResponse& result, int requestId) {};
        virtual void OnResetUserStatistics(const AdminModels::ResetUserStatisticsResult& result, int requestId) {};
        virtual void OnResolvePurchaseDispute(const AdminModels::ResolvePurchaseDisputeResponse& result, int requestId) {};
        virtual void OnUpdatePlayerStatisticDefinition(const AdminModels::UpdatePlayerStatisticDefinitionResult& result, int requestId) {};
        virtual void OnUpdateUserData(const AdminModels::UpdateUserDataResult& result, int requestId) {};
        virtual void OnUpdateUserInternalData(const AdminModels::UpdateUserDataResult& result, int requestId) {};
        virtual void OnUpdateUserPublisherData(const AdminModels::UpdateUserDataResult& result, int requestId) {};
        virtual void OnUpdateUserPublisherInternalData(const AdminModels::UpdateUserDataResult& result, int requestId) {};
        virtual void OnUpdateUserPublisherReadOnlyData(const AdminModels::UpdateUserDataResult& result, int requestId) {};
        virtual void OnUpdateUserReadOnlyData(const AdminModels::UpdateUserDataResult& result, int requestId) {};
        virtual void OnAddNews(const AdminModels::AddNewsResult& result, int requestId) {};
        virtual void OnAddVirtualCurrencyTypes(const AdminModels::BlankResult& result, int requestId) {};
        virtual void OnDeleteStore(const AdminModels::DeleteStoreResult& result, int requestId) {};
        virtual void OnGetCatalogItems(const AdminModels::GetCatalogItemsResult& result, int requestId) {};
        virtual void OnGetPublisherData(const AdminModels::GetPublisherDataResult& result, int requestId) {};
        virtual void OnGetRandomResultTables(const AdminModels::GetRandomResultTablesResult& result, int requestId) {};
        virtual void OnGetStoreItems(const AdminModels::GetStoreItemsResult& result, int requestId) {};
        virtual void OnGetTitleData(const AdminModels::GetTitleDataResult& result, int requestId) {};
        virtual void OnGetTitleInternalData(const AdminModels::GetTitleDataResult& result, int requestId) {};
        virtual void OnListVirtualCurrencyTypes(const AdminModels::ListVirtualCurrencyTypesResult& result, int requestId) {};
        virtual void OnRemoveVirtualCurrencyTypes(const AdminModels::BlankResult& result, int requestId) {};
        virtual void OnSetCatalogItems(const AdminModels::UpdateCatalogItemsResult& result, int requestId) {};
        virtual void OnSetStoreItems(const AdminModels::UpdateStoreItemsResult& result, int requestId) {};
        virtual void OnSetTitleData(const AdminModels::SetTitleDataResult& result, int requestId) {};
        virtual void OnSetTitleInternalData(const AdminModels::SetTitleDataResult& result, int requestId) {};
        virtual void OnSetupPushNotification(const AdminModels::SetupPushNotificationResult& result, int requestId) {};
        virtual void OnUpdateCatalogItems(const AdminModels::UpdateCatalogItemsResult& result, int requestId) {};
        virtual void OnUpdateRandomResultTables(const AdminModels::UpdateRandomResultTablesResult& result, int requestId) {};
        virtual void OnUpdateStoreItems(const AdminModels::UpdateStoreItemsResult& result, int requestId) {};
        virtual void OnAddUserVirtualCurrency(const AdminModels::ModifyUserVirtualCurrencyResult& result, int requestId) {};
        virtual void OnGetUserInventory(const AdminModels::GetUserInventoryResult& result, int requestId) {};
        virtual void OnGrantItemsToUsers(const AdminModels::GrantItemsToUsersResult& result, int requestId) {};
        virtual void OnRevokeInventoryItem(const AdminModels::RevokeInventoryResult& result, int requestId) {};
        virtual void OnSubtractUserVirtualCurrency(const AdminModels::ModifyUserVirtualCurrencyResult& result, int requestId) {};
        virtual void OnGetMatchmakerGameInfo(const AdminModels::GetMatchmakerGameInfoResult& result, int requestId) {};
        virtual void OnGetMatchmakerGameModes(const AdminModels::GetMatchmakerGameModesResult& result, int requestId) {};
        virtual void OnModifyMatchmakerGameModes(const AdminModels::ModifyMatchmakerGameModesResult& result, int requestId) {};
        virtual void OnAddServerBuild(const AdminModels::AddServerBuildResult& result, int requestId) {};
        virtual void OnGetServerBuildInfo(const AdminModels::GetServerBuildInfoResult& result, int requestId) {};
        virtual void OnGetServerBuildUploadUrl(const AdminModels::GetServerBuildUploadURLResult& result, int requestId) {};
        virtual void OnListServerBuilds(const AdminModels::ListBuildsResult& result, int requestId) {};
        virtual void OnModifyServerBuild(const AdminModels::ModifyServerBuildResult& result, int requestId) {};
        virtual void OnRemoveServerBuild(const AdminModels::RemoveServerBuildResult& result, int requestId) {};
        virtual void OnSetPublisherData(const AdminModels::SetPublisherDataResult& result, int requestId) {};
        virtual void OnGetCloudScriptRevision(const AdminModels::GetCloudScriptRevisionResult& result, int requestId) {};
        virtual void OnGetCloudScriptVersions(const AdminModels::GetCloudScriptVersionsResult& result, int requestId) {};
        virtual void OnSetPublishedRevision(const AdminModels::SetPublishedRevisionResult& result, int requestId) {};
        virtual void OnUpdateCloudScript(const AdminModels::UpdateCloudScriptResult& result, int requestId) {};
        virtual void OnDeleteContent(const AdminModels::BlankResult& result, int requestId) {};
        virtual void OnGetContentList(const AdminModels::GetContentListResult& result, int requestId) {};
        virtual void OnGetContentUploadUrl(const AdminModels::GetContentUploadUrlResult& result, int requestId) {};
        virtual void OnResetCharacterStatistics(const AdminModels::ResetCharacterStatisticsResult& result, int requestId) {};
        virtual void OnAddPlayerTag(const AdminModels::AddPlayerTagResult& result, int requestId) {};
        virtual void OnGetAllActionGroups(const AdminModels::GetAllActionGroupsResult& result, int requestId) {};
        virtual void OnGetAllSegments(const AdminModels::GetAllSegmentsResult& result, int requestId) {};
        virtual void OnGetPlayerSegments(const AdminModels::GetPlayerSegmentsResult& result, int requestId) {};
        virtual void OnGetPlayersInSegment(const AdminModels::GetPlayersInSegmentResult& result, int requestId) {};
        virtual void OnGetPlayerTags(const AdminModels::GetPlayerTagsResult& result, int requestId) {};
        virtual void OnRemovePlayerTag(const AdminModels::RemovePlayerTagResult& result, int requestId) {};
        virtual void OnAbortTaskInstance(const AdminModels::EmptyResult& result, int requestId) {};
        virtual void OnCreateActionsOnPlayersInSegmentTask(const AdminModels::CreateTaskResult& result, int requestId) {};
        virtual void OnCreateCloudScriptTask(const AdminModels::CreateTaskResult& result, int requestId) {};
        virtual void OnDeleteTask(const AdminModels::EmptyResult& result, int requestId) {};
        virtual void OnGetActionsOnPlayersInSegmentTaskInstance(const AdminModels::GetActionsOnPlayersInSegmentTaskInstanceResult& result, int requestId) {};
        virtual void OnGetCloudScriptTaskInstance(const AdminModels::GetCloudScriptTaskInstanceResult& result, int requestId) {};
        virtual void OnGetTaskInstances(const AdminModels::GetTaskInstancesResult& result, int requestId) {};
        virtual void OnGetTasks(const AdminModels::GetTasksResult& result, int requestId) {};
        virtual void OnRunTask(const AdminModels::RunTaskResult& result, int requestId) {};
        virtual void OnUpdateTask(const AdminModels::EmptyResult& result, int requestId) {};
    
   };

    using PlayFabCombo_AdminGlobalNotificationBus = AZ::EBus<PlayFabCombo_AdminGlobalNotifications>;

} // namespace PlayFabComboSdk
