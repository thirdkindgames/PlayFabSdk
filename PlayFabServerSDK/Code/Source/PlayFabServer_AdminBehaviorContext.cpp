// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

#include "StdAfx.h"
#include "PlayFabServer_AdminBehaviorContext.h"
#include <AzCore/RTTI/ReflectContext.h>
#include <AzCore/RTTI/BehaviorContext.h>

#include "PlayFabServerSdk/PlayFabServer_AdminNotificationBus.h"
#include "PlayFabServerSdk/PlayFabServer_AdminBus.h"
#include "PlayFabServerSdk/PlayFabServerDataModels.h"

#include "PlayFabServer_OnDemandReflection.inl"

namespace PlayFabServerSdk
{
    //-----------------------------------------------------------------------------------------------------
    // Behavior binder for the notification bus.
    //-----------------------------------------------------------------------------------------------------
    // These binders monitor the specified PlayFab NotificationBus and forward messages to the behavior context
	// This is a Lumberyard requirement for reflection because the behavior context can not guarantee that there
    // is a handler for each message. If a message expects a result, you must provide a default result in case
    // the message is not handled by the behavior context user.

    // This base class provides the shared binding logic for the 2 buses (the request based notification bus and the global notification buses)
    template<typename T>
    class PlayFabServer_AdminBehaviorBusBaseHandler : 
		public AZ::BehaviorEBusHandler
	{ 

    // Note that normally we would list all of the notification handler functions here using the AZ_EBUS_BEHAVIOR_BINDER macro
    // However the AZ_EBUS_BEHAVIOR_BINDER macro supports a maximum of 30 functions, so we generate the calls by hand here instead.
            
    public: 
        AZ_CLASS_ALLOCATOR(T,AZ::SystemAllocator,0)
    protected:

		enum {
			FN_OnError,
			FN_OnCreatePlayerSharedSecret,
			FN_OnDeletePlayerSharedSecret,
			FN_OnGetPlayerSharedSecrets,
			FN_OnGetPolicy,
			FN_OnSetPlayerSecret,
			FN_OnUpdatePlayerSharedSecret,
			FN_OnUpdatePolicy,
			FN_OnBanUsers,
			FN_OnDeletePlayer,
			FN_OnGetUserAccountInfo,
			FN_OnGetUserBans,
			FN_OnResetUsers,
			FN_OnRevokeAllBansForUser,
			FN_OnRevokeBans,
			FN_OnSendAccountRecoveryEmail,
			FN_OnUpdateBans,
			FN_OnUpdateUserTitleDisplayName,
			FN_OnCreatePlayerStatisticDefinition,
			FN_OnDeleteUsers,
			FN_OnGetDataReport,
			FN_OnGetPlayerStatisticDefinitions,
			FN_OnGetPlayerStatisticVersions,
			FN_OnGetUserData,
			FN_OnGetUserInternalData,
			FN_OnGetUserPublisherData,
			FN_OnGetUserPublisherInternalData,
			FN_OnGetUserPublisherReadOnlyData,
			FN_OnGetUserReadOnlyData,
			FN_OnIncrementPlayerStatisticVersion,
			FN_OnRefundPurchase,
			FN_OnResetUserStatistics,
			FN_OnResolvePurchaseDispute,
			FN_OnUpdatePlayerStatisticDefinition,
			FN_OnUpdateUserData,
			FN_OnUpdateUserInternalData,
			FN_OnUpdateUserPublisherData,
			FN_OnUpdateUserPublisherInternalData,
			FN_OnUpdateUserPublisherReadOnlyData,
			FN_OnUpdateUserReadOnlyData,
			FN_OnAddNews,
			FN_OnAddVirtualCurrencyTypes,
			FN_OnDeleteStore,
			FN_OnGetCatalogItems,
			FN_OnGetPublisherData,
			FN_OnGetRandomResultTables,
			FN_OnGetStoreItems,
			FN_OnGetTitleData,
			FN_OnGetTitleInternalData,
			FN_OnListVirtualCurrencyTypes,
			FN_OnRemoveVirtualCurrencyTypes,
			FN_OnSetCatalogItems,
			FN_OnSetStoreItems,
			FN_OnSetTitleData,
			FN_OnSetTitleInternalData,
			FN_OnSetupPushNotification,
			FN_OnUpdateCatalogItems,
			FN_OnUpdateRandomResultTables,
			FN_OnUpdateStoreItems,
			FN_OnAddUserVirtualCurrency,
			FN_OnGetUserInventory,
			FN_OnGrantItemsToUsers,
			FN_OnRevokeInventoryItem,
			FN_OnSubtractUserVirtualCurrency,
			FN_OnGetMatchmakerGameInfo,
			FN_OnGetMatchmakerGameModes,
			FN_OnModifyMatchmakerGameModes,
			FN_OnAddServerBuild,
			FN_OnGetServerBuildInfo,
			FN_OnGetServerBuildUploadUrl,
			FN_OnListServerBuilds,
			FN_OnModifyServerBuild,
			FN_OnRemoveServerBuild,
			FN_OnSetPublisherData,
			FN_OnGetCloudScriptRevision,
			FN_OnGetCloudScriptVersions,
			FN_OnSetPublishedRevision,
			FN_OnUpdateCloudScript,
			FN_OnDeleteContent,
			FN_OnGetContentList,
			FN_OnGetContentUploadUrl,
			FN_OnResetCharacterStatistics,
			FN_OnAddPlayerTag,
			FN_OnGetAllActionGroups,
			FN_OnGetAllSegments,
			FN_OnGetPlayerSegments,
			FN_OnGetPlayersInSegment,
			FN_OnGetPlayerTags,
			FN_OnRemovePlayerTag,
			FN_OnAbortTaskInstance,
			FN_OnCreateActionsOnPlayersInSegmentTask,
			FN_OnCreateCloudScriptTask,
			FN_OnDeleteTask,
			FN_OnGetActionsOnPlayersInSegmentTaskInstance,
			FN_OnGetCloudScriptTaskInstance,
			FN_OnGetTaskInstances,
			FN_OnGetTasks,
			FN_OnRunTask,
			FN_OnUpdateTask,
			
        	FN_MAX
    	};

        int GetFunctionIndex(const char* functionName) const override {
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnError)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnCreatePlayerSharedSecret)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnDeletePlayerSharedSecret)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetPlayerSharedSecrets)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetPolicy)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnSetPlayerSecret)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnUpdatePlayerSharedSecret)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnUpdatePolicy)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnBanUsers)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnDeletePlayer)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetUserAccountInfo)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetUserBans)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnResetUsers)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnRevokeAllBansForUser)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnRevokeBans)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnSendAccountRecoveryEmail)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnUpdateBans)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnUpdateUserTitleDisplayName)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnCreatePlayerStatisticDefinition)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnDeleteUsers)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetDataReport)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetPlayerStatisticDefinitions)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetPlayerStatisticVersions)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetUserData)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetUserInternalData)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetUserPublisherData)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetUserPublisherInternalData)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetUserPublisherReadOnlyData)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetUserReadOnlyData)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnIncrementPlayerStatisticVersion)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnRefundPurchase)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnResetUserStatistics)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnResolvePurchaseDispute)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnUpdatePlayerStatisticDefinition)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnUpdateUserData)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnUpdateUserInternalData)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnUpdateUserPublisherData)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnUpdateUserPublisherInternalData)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnUpdateUserPublisherReadOnlyData)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnUpdateUserReadOnlyData)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnAddNews)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnAddVirtualCurrencyTypes)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnDeleteStore)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetCatalogItems)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetPublisherData)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetRandomResultTables)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetStoreItems)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetTitleData)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetTitleInternalData)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnListVirtualCurrencyTypes)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnRemoveVirtualCurrencyTypes)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnSetCatalogItems)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnSetStoreItems)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnSetTitleData)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnSetTitleInternalData)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnSetupPushNotification)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnUpdateCatalogItems)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnUpdateRandomResultTables)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnUpdateStoreItems)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnAddUserVirtualCurrency)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetUserInventory)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGrantItemsToUsers)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnRevokeInventoryItem)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnSubtractUserVirtualCurrency)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetMatchmakerGameInfo)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetMatchmakerGameModes)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnModifyMatchmakerGameModes)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnAddServerBuild)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetServerBuildInfo)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetServerBuildUploadUrl)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnListServerBuilds)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnModifyServerBuild)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnRemoveServerBuild)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnSetPublisherData)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetCloudScriptRevision)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetCloudScriptVersions)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnSetPublishedRevision)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnUpdateCloudScript)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnDeleteContent)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetContentList)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetContentUploadUrl)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnResetCharacterStatistics)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnAddPlayerTag)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetAllActionGroups)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetAllSegments)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetPlayerSegments)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetPlayersInSegment)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetPlayerTags)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnRemovePlayerTag)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnAbortTaskInstance)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnCreateActionsOnPlayersInSegmentTask)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnCreateCloudScriptTask)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnDeleteTask)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetActionsOnPlayersInSegmentTaskInstance)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetCloudScriptTaskInstance)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetTaskInstances)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetTasks)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnRunTask)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnUpdateTask)
			
			return -1;
		}

        bool Connect(AZ::BehaviorValueParameter* id = nullptr) override {
			return AZ::Internal::EBusConnector<T>::Connect(static_cast<T*>(this), id);
		}

        // Constructor
        PlayFabServer_AdminBehaviorBusBaseHandler()
        {
        	m_events.resize(FN_MAX);
			SetEvent(&T::OnError,"OnError");
			SetEvent(&T::OnCreatePlayerSharedSecret,"OnCreatePlayerSharedSecret");
			SetEvent(&T::OnDeletePlayerSharedSecret,"OnDeletePlayerSharedSecret");
			SetEvent(&T::OnGetPlayerSharedSecrets,"OnGetPlayerSharedSecrets");
			SetEvent(&T::OnGetPolicy,"OnGetPolicy");
			SetEvent(&T::OnSetPlayerSecret,"OnSetPlayerSecret");
			SetEvent(&T::OnUpdatePlayerSharedSecret,"OnUpdatePlayerSharedSecret");
			SetEvent(&T::OnUpdatePolicy,"OnUpdatePolicy");
			SetEvent(&T::OnBanUsers,"OnBanUsers");
			SetEvent(&T::OnDeletePlayer,"OnDeletePlayer");
			SetEvent(&T::OnGetUserAccountInfo,"OnGetUserAccountInfo");
			SetEvent(&T::OnGetUserBans,"OnGetUserBans");
			SetEvent(&T::OnResetUsers,"OnResetUsers");
			SetEvent(&T::OnRevokeAllBansForUser,"OnRevokeAllBansForUser");
			SetEvent(&T::OnRevokeBans,"OnRevokeBans");
			SetEvent(&T::OnSendAccountRecoveryEmail,"OnSendAccountRecoveryEmail");
			SetEvent(&T::OnUpdateBans,"OnUpdateBans");
			SetEvent(&T::OnUpdateUserTitleDisplayName,"OnUpdateUserTitleDisplayName");
			SetEvent(&T::OnCreatePlayerStatisticDefinition,"OnCreatePlayerStatisticDefinition");
			SetEvent(&T::OnDeleteUsers,"OnDeleteUsers");
			SetEvent(&T::OnGetDataReport,"OnGetDataReport");
			SetEvent(&T::OnGetPlayerStatisticDefinitions,"OnGetPlayerStatisticDefinitions");
			SetEvent(&T::OnGetPlayerStatisticVersions,"OnGetPlayerStatisticVersions");
			SetEvent(&T::OnGetUserData,"OnGetUserData");
			SetEvent(&T::OnGetUserInternalData,"OnGetUserInternalData");
			SetEvent(&T::OnGetUserPublisherData,"OnGetUserPublisherData");
			SetEvent(&T::OnGetUserPublisherInternalData,"OnGetUserPublisherInternalData");
			SetEvent(&T::OnGetUserPublisherReadOnlyData,"OnGetUserPublisherReadOnlyData");
			SetEvent(&T::OnGetUserReadOnlyData,"OnGetUserReadOnlyData");
			SetEvent(&T::OnIncrementPlayerStatisticVersion,"OnIncrementPlayerStatisticVersion");
			SetEvent(&T::OnRefundPurchase,"OnRefundPurchase");
			SetEvent(&T::OnResetUserStatistics,"OnResetUserStatistics");
			SetEvent(&T::OnResolvePurchaseDispute,"OnResolvePurchaseDispute");
			SetEvent(&T::OnUpdatePlayerStatisticDefinition,"OnUpdatePlayerStatisticDefinition");
			SetEvent(&T::OnUpdateUserData,"OnUpdateUserData");
			SetEvent(&T::OnUpdateUserInternalData,"OnUpdateUserInternalData");
			SetEvent(&T::OnUpdateUserPublisherData,"OnUpdateUserPublisherData");
			SetEvent(&T::OnUpdateUserPublisherInternalData,"OnUpdateUserPublisherInternalData");
			SetEvent(&T::OnUpdateUserPublisherReadOnlyData,"OnUpdateUserPublisherReadOnlyData");
			SetEvent(&T::OnUpdateUserReadOnlyData,"OnUpdateUserReadOnlyData");
			SetEvent(&T::OnAddNews,"OnAddNews");
			SetEvent(&T::OnAddVirtualCurrencyTypes,"OnAddVirtualCurrencyTypes");
			SetEvent(&T::OnDeleteStore,"OnDeleteStore");
			SetEvent(&T::OnGetCatalogItems,"OnGetCatalogItems");
			SetEvent(&T::OnGetPublisherData,"OnGetPublisherData");
			SetEvent(&T::OnGetRandomResultTables,"OnGetRandomResultTables");
			SetEvent(&T::OnGetStoreItems,"OnGetStoreItems");
			SetEvent(&T::OnGetTitleData,"OnGetTitleData");
			SetEvent(&T::OnGetTitleInternalData,"OnGetTitleInternalData");
			SetEvent(&T::OnListVirtualCurrencyTypes,"OnListVirtualCurrencyTypes");
			SetEvent(&T::OnRemoveVirtualCurrencyTypes,"OnRemoveVirtualCurrencyTypes");
			SetEvent(&T::OnSetCatalogItems,"OnSetCatalogItems");
			SetEvent(&T::OnSetStoreItems,"OnSetStoreItems");
			SetEvent(&T::OnSetTitleData,"OnSetTitleData");
			SetEvent(&T::OnSetTitleInternalData,"OnSetTitleInternalData");
			SetEvent(&T::OnSetupPushNotification,"OnSetupPushNotification");
			SetEvent(&T::OnUpdateCatalogItems,"OnUpdateCatalogItems");
			SetEvent(&T::OnUpdateRandomResultTables,"OnUpdateRandomResultTables");
			SetEvent(&T::OnUpdateStoreItems,"OnUpdateStoreItems");
			SetEvent(&T::OnAddUserVirtualCurrency,"OnAddUserVirtualCurrency");
			SetEvent(&T::OnGetUserInventory,"OnGetUserInventory");
			SetEvent(&T::OnGrantItemsToUsers,"OnGrantItemsToUsers");
			SetEvent(&T::OnRevokeInventoryItem,"OnRevokeInventoryItem");
			SetEvent(&T::OnSubtractUserVirtualCurrency,"OnSubtractUserVirtualCurrency");
			SetEvent(&T::OnGetMatchmakerGameInfo,"OnGetMatchmakerGameInfo");
			SetEvent(&T::OnGetMatchmakerGameModes,"OnGetMatchmakerGameModes");
			SetEvent(&T::OnModifyMatchmakerGameModes,"OnModifyMatchmakerGameModes");
			SetEvent(&T::OnAddServerBuild,"OnAddServerBuild");
			SetEvent(&T::OnGetServerBuildInfo,"OnGetServerBuildInfo");
			SetEvent(&T::OnGetServerBuildUploadUrl,"OnGetServerBuildUploadUrl");
			SetEvent(&T::OnListServerBuilds,"OnListServerBuilds");
			SetEvent(&T::OnModifyServerBuild,"OnModifyServerBuild");
			SetEvent(&T::OnRemoveServerBuild,"OnRemoveServerBuild");
			SetEvent(&T::OnSetPublisherData,"OnSetPublisherData");
			SetEvent(&T::OnGetCloudScriptRevision,"OnGetCloudScriptRevision");
			SetEvent(&T::OnGetCloudScriptVersions,"OnGetCloudScriptVersions");
			SetEvent(&T::OnSetPublishedRevision,"OnSetPublishedRevision");
			SetEvent(&T::OnUpdateCloudScript,"OnUpdateCloudScript");
			SetEvent(&T::OnDeleteContent,"OnDeleteContent");
			SetEvent(&T::OnGetContentList,"OnGetContentList");
			SetEvent(&T::OnGetContentUploadUrl,"OnGetContentUploadUrl");
			SetEvent(&T::OnResetCharacterStatistics,"OnResetCharacterStatistics");
			SetEvent(&T::OnAddPlayerTag,"OnAddPlayerTag");
			SetEvent(&T::OnGetAllActionGroups,"OnGetAllActionGroups");
			SetEvent(&T::OnGetAllSegments,"OnGetAllSegments");
			SetEvent(&T::OnGetPlayerSegments,"OnGetPlayerSegments");
			SetEvent(&T::OnGetPlayersInSegment,"OnGetPlayersInSegment");
			SetEvent(&T::OnGetPlayerTags,"OnGetPlayerTags");
			SetEvent(&T::OnRemovePlayerTag,"OnRemovePlayerTag");
			SetEvent(&T::OnAbortTaskInstance,"OnAbortTaskInstance");
			SetEvent(&T::OnCreateActionsOnPlayersInSegmentTask,"OnCreateActionsOnPlayersInSegmentTask");
			SetEvent(&T::OnCreateCloudScriptTask,"OnCreateCloudScriptTask");
			SetEvent(&T::OnDeleteTask,"OnDeleteTask");
			SetEvent(&T::OnGetActionsOnPlayersInSegmentTaskInstance,"OnGetActionsOnPlayersInSegmentTaskInstance");
			SetEvent(&T::OnGetCloudScriptTaskInstance,"OnGetCloudScriptTaskInstance");
			SetEvent(&T::OnGetTaskInstances,"OnGetTaskInstances");
			SetEvent(&T::OnGetTasks,"OnGetTasks");
			SetEvent(&T::OnRunTask,"OnRunTask");
			SetEvent(&T::OnUpdateTask,"OnUpdateTask");
			
        }
        
    };

    // Behavior binder for the (request) based notification bus.
	class PlayFabServer_AdminBehaviorBusHandler : 
		public PlayFabServer_AdminNotificationBus::Handler, 
		public PlayFabServer_AdminBehaviorBusBaseHandler<PlayFabServer_AdminBehaviorBusHandler>
	{
   
	public:
        
		AZ_RTTI(PlayFabServer_AdminBehaviorBusHandler,"{5e89d69d-3fa2-53b4-8da7-ffa6c7167a6a}",AZ::BehaviorEBusHandler)

        void Disconnect() override {
			BusDisconnect();
		}
        
		void OnError(const PlayFabError& error) override
		{
			Call(FN_OnError, error);
		}

		// ------------ Generated APIs to receive from the PlayFab notification bus and forward on to the Lua behavior context.
	
		void OnCreatePlayerSharedSecret(const AdminModels::CreatePlayerSharedSecretResult& result) { Call(FN_OnCreatePlayerSharedSecret, result); };
		void OnDeletePlayerSharedSecret(const AdminModels::DeletePlayerSharedSecretResult& result) { Call(FN_OnDeletePlayerSharedSecret, result); };
		void OnGetPlayerSharedSecrets(const AdminModels::GetPlayerSharedSecretsResult& result) { Call(FN_OnGetPlayerSharedSecrets, result); };
		void OnGetPolicy(const AdminModels::GetPolicyResponse& result) { Call(FN_OnGetPolicy, result); };
		void OnSetPlayerSecret(const AdminModels::SetPlayerSecretResult& result) { Call(FN_OnSetPlayerSecret, result); };
		void OnUpdatePlayerSharedSecret(const AdminModels::UpdatePlayerSharedSecretResult& result) { Call(FN_OnUpdatePlayerSharedSecret, result); };
		void OnUpdatePolicy(const AdminModels::UpdatePolicyResponse& result) { Call(FN_OnUpdatePolicy, result); };
		void OnBanUsers(const AdminModels::BanUsersResult& result) { Call(FN_OnBanUsers, result); };
		void OnDeletePlayer(const AdminModels::DeletePlayerResult& result) { Call(FN_OnDeletePlayer, result); };
		void OnGetUserAccountInfo(const AdminModels::LookupUserAccountInfoResult& result) { Call(FN_OnGetUserAccountInfo, result); };
		void OnGetUserBans(const AdminModels::GetUserBansResult& result) { Call(FN_OnGetUserBans, result); };
		void OnResetUsers(const AdminModels::BlankResult& result) { Call(FN_OnResetUsers, result); };
		void OnRevokeAllBansForUser(const AdminModels::RevokeAllBansForUserResult& result) { Call(FN_OnRevokeAllBansForUser, result); };
		void OnRevokeBans(const AdminModels::RevokeBansResult& result) { Call(FN_OnRevokeBans, result); };
		void OnSendAccountRecoveryEmail(const AdminModels::SendAccountRecoveryEmailResult& result) { Call(FN_OnSendAccountRecoveryEmail, result); };
		void OnUpdateBans(const AdminModels::UpdateBansResult& result) { Call(FN_OnUpdateBans, result); };
		void OnUpdateUserTitleDisplayName(const AdminModels::UpdateUserTitleDisplayNameResult& result) { Call(FN_OnUpdateUserTitleDisplayName, result); };
		void OnCreatePlayerStatisticDefinition(const AdminModels::CreatePlayerStatisticDefinitionResult& result) { Call(FN_OnCreatePlayerStatisticDefinition, result); };
		void OnDeleteUsers(const AdminModels::DeleteUsersResult& result) { Call(FN_OnDeleteUsers, result); };
		void OnGetDataReport(const AdminModels::GetDataReportResult& result) { Call(FN_OnGetDataReport, result); };
		void OnGetPlayerStatisticDefinitions(const AdminModels::GetPlayerStatisticDefinitionsResult& result) { Call(FN_OnGetPlayerStatisticDefinitions, result); };
		void OnGetPlayerStatisticVersions(const AdminModels::GetPlayerStatisticVersionsResult& result) { Call(FN_OnGetPlayerStatisticVersions, result); };
		void OnGetUserData(const AdminModels::GetUserDataResult& result) { Call(FN_OnGetUserData, result); };
		void OnGetUserInternalData(const AdminModels::GetUserDataResult& result) { Call(FN_OnGetUserInternalData, result); };
		void OnGetUserPublisherData(const AdminModels::GetUserDataResult& result) { Call(FN_OnGetUserPublisherData, result); };
		void OnGetUserPublisherInternalData(const AdminModels::GetUserDataResult& result) { Call(FN_OnGetUserPublisherInternalData, result); };
		void OnGetUserPublisherReadOnlyData(const AdminModels::GetUserDataResult& result) { Call(FN_OnGetUserPublisherReadOnlyData, result); };
		void OnGetUserReadOnlyData(const AdminModels::GetUserDataResult& result) { Call(FN_OnGetUserReadOnlyData, result); };
		void OnIncrementPlayerStatisticVersion(const AdminModels::IncrementPlayerStatisticVersionResult& result) { Call(FN_OnIncrementPlayerStatisticVersion, result); };
		void OnRefundPurchase(const AdminModels::RefundPurchaseResponse& result) { Call(FN_OnRefundPurchase, result); };
		void OnResetUserStatistics(const AdminModels::ResetUserStatisticsResult& result) { Call(FN_OnResetUserStatistics, result); };
		void OnResolvePurchaseDispute(const AdminModels::ResolvePurchaseDisputeResponse& result) { Call(FN_OnResolvePurchaseDispute, result); };
		void OnUpdatePlayerStatisticDefinition(const AdminModels::UpdatePlayerStatisticDefinitionResult& result) { Call(FN_OnUpdatePlayerStatisticDefinition, result); };
		void OnUpdateUserData(const AdminModels::UpdateUserDataResult& result) { Call(FN_OnUpdateUserData, result); };
		void OnUpdateUserInternalData(const AdminModels::UpdateUserDataResult& result) { Call(FN_OnUpdateUserInternalData, result); };
		void OnUpdateUserPublisherData(const AdminModels::UpdateUserDataResult& result) { Call(FN_OnUpdateUserPublisherData, result); };
		void OnUpdateUserPublisherInternalData(const AdminModels::UpdateUserDataResult& result) { Call(FN_OnUpdateUserPublisherInternalData, result); };
		void OnUpdateUserPublisherReadOnlyData(const AdminModels::UpdateUserDataResult& result) { Call(FN_OnUpdateUserPublisherReadOnlyData, result); };
		void OnUpdateUserReadOnlyData(const AdminModels::UpdateUserDataResult& result) { Call(FN_OnUpdateUserReadOnlyData, result); };
		void OnAddNews(const AdminModels::AddNewsResult& result) { Call(FN_OnAddNews, result); };
		void OnAddVirtualCurrencyTypes(const AdminModels::BlankResult& result) { Call(FN_OnAddVirtualCurrencyTypes, result); };
		void OnDeleteStore(const AdminModels::DeleteStoreResult& result) { Call(FN_OnDeleteStore, result); };
		void OnGetCatalogItems(const AdminModels::GetCatalogItemsResult& result) { Call(FN_OnGetCatalogItems, result); };
		void OnGetPublisherData(const AdminModels::GetPublisherDataResult& result) { Call(FN_OnGetPublisherData, result); };
		void OnGetRandomResultTables(const AdminModels::GetRandomResultTablesResult& result) { Call(FN_OnGetRandomResultTables, result); };
		void OnGetStoreItems(const AdminModels::GetStoreItemsResult& result) { Call(FN_OnGetStoreItems, result); };
		void OnGetTitleData(const AdminModels::GetTitleDataResult& result) { Call(FN_OnGetTitleData, result); };
		void OnGetTitleInternalData(const AdminModels::GetTitleDataResult& result) { Call(FN_OnGetTitleInternalData, result); };
		void OnListVirtualCurrencyTypes(const AdminModels::ListVirtualCurrencyTypesResult& result) { Call(FN_OnListVirtualCurrencyTypes, result); };
		void OnRemoveVirtualCurrencyTypes(const AdminModels::BlankResult& result) { Call(FN_OnRemoveVirtualCurrencyTypes, result); };
		void OnSetCatalogItems(const AdminModels::UpdateCatalogItemsResult& result) { Call(FN_OnSetCatalogItems, result); };
		void OnSetStoreItems(const AdminModels::UpdateStoreItemsResult& result) { Call(FN_OnSetStoreItems, result); };
		void OnSetTitleData(const AdminModels::SetTitleDataResult& result) { Call(FN_OnSetTitleData, result); };
		void OnSetTitleInternalData(const AdminModels::SetTitleDataResult& result) { Call(FN_OnSetTitleInternalData, result); };
		void OnSetupPushNotification(const AdminModels::SetupPushNotificationResult& result) { Call(FN_OnSetupPushNotification, result); };
		void OnUpdateCatalogItems(const AdminModels::UpdateCatalogItemsResult& result) { Call(FN_OnUpdateCatalogItems, result); };
		void OnUpdateRandomResultTables(const AdminModels::UpdateRandomResultTablesResult& result) { Call(FN_OnUpdateRandomResultTables, result); };
		void OnUpdateStoreItems(const AdminModels::UpdateStoreItemsResult& result) { Call(FN_OnUpdateStoreItems, result); };
		void OnAddUserVirtualCurrency(const AdminModels::ModifyUserVirtualCurrencyResult& result) { Call(FN_OnAddUserVirtualCurrency, result); };
		void OnGetUserInventory(const AdminModels::GetUserInventoryResult& result) { Call(FN_OnGetUserInventory, result); };
		void OnGrantItemsToUsers(const AdminModels::GrantItemsToUsersResult& result) { Call(FN_OnGrantItemsToUsers, result); };
		void OnRevokeInventoryItem(const AdminModels::RevokeInventoryResult& result) { Call(FN_OnRevokeInventoryItem, result); };
		void OnSubtractUserVirtualCurrency(const AdminModels::ModifyUserVirtualCurrencyResult& result) { Call(FN_OnSubtractUserVirtualCurrency, result); };
		void OnGetMatchmakerGameInfo(const AdminModels::GetMatchmakerGameInfoResult& result) { Call(FN_OnGetMatchmakerGameInfo, result); };
		void OnGetMatchmakerGameModes(const AdminModels::GetMatchmakerGameModesResult& result) { Call(FN_OnGetMatchmakerGameModes, result); };
		void OnModifyMatchmakerGameModes(const AdminModels::ModifyMatchmakerGameModesResult& result) { Call(FN_OnModifyMatchmakerGameModes, result); };
		void OnAddServerBuild(const AdminModels::AddServerBuildResult& result) { Call(FN_OnAddServerBuild, result); };
		void OnGetServerBuildInfo(const AdminModels::GetServerBuildInfoResult& result) { Call(FN_OnGetServerBuildInfo, result); };
		void OnGetServerBuildUploadUrl(const AdminModels::GetServerBuildUploadURLResult& result) { Call(FN_OnGetServerBuildUploadUrl, result); };
		void OnListServerBuilds(const AdminModels::ListBuildsResult& result) { Call(FN_OnListServerBuilds, result); };
		void OnModifyServerBuild(const AdminModels::ModifyServerBuildResult& result) { Call(FN_OnModifyServerBuild, result); };
		void OnRemoveServerBuild(const AdminModels::RemoveServerBuildResult& result) { Call(FN_OnRemoveServerBuild, result); };
		void OnSetPublisherData(const AdminModels::SetPublisherDataResult& result) { Call(FN_OnSetPublisherData, result); };
		void OnGetCloudScriptRevision(const AdminModels::GetCloudScriptRevisionResult& result) { Call(FN_OnGetCloudScriptRevision, result); };
		void OnGetCloudScriptVersions(const AdminModels::GetCloudScriptVersionsResult& result) { Call(FN_OnGetCloudScriptVersions, result); };
		void OnSetPublishedRevision(const AdminModels::SetPublishedRevisionResult& result) { Call(FN_OnSetPublishedRevision, result); };
		void OnUpdateCloudScript(const AdminModels::UpdateCloudScriptResult& result) { Call(FN_OnUpdateCloudScript, result); };
		void OnDeleteContent(const AdminModels::BlankResult& result) { Call(FN_OnDeleteContent, result); };
		void OnGetContentList(const AdminModels::GetContentListResult& result) { Call(FN_OnGetContentList, result); };
		void OnGetContentUploadUrl(const AdminModels::GetContentUploadUrlResult& result) { Call(FN_OnGetContentUploadUrl, result); };
		void OnResetCharacterStatistics(const AdminModels::ResetCharacterStatisticsResult& result) { Call(FN_OnResetCharacterStatistics, result); };
		void OnAddPlayerTag(const AdminModels::AddPlayerTagResult& result) { Call(FN_OnAddPlayerTag, result); };
		void OnGetAllActionGroups(const AdminModels::GetAllActionGroupsResult& result) { Call(FN_OnGetAllActionGroups, result); };
		void OnGetAllSegments(const AdminModels::GetAllSegmentsResult& result) { Call(FN_OnGetAllSegments, result); };
		void OnGetPlayerSegments(const AdminModels::GetPlayerSegmentsResult& result) { Call(FN_OnGetPlayerSegments, result); };
		void OnGetPlayersInSegment(const AdminModels::GetPlayersInSegmentResult& result) { Call(FN_OnGetPlayersInSegment, result); };
		void OnGetPlayerTags(const AdminModels::GetPlayerTagsResult& result) { Call(FN_OnGetPlayerTags, result); };
		void OnRemovePlayerTag(const AdminModels::RemovePlayerTagResult& result) { Call(FN_OnRemovePlayerTag, result); };
		void OnAbortTaskInstance(const AdminModels::EmptyResult& result) { Call(FN_OnAbortTaskInstance, result); };
		void OnCreateActionsOnPlayersInSegmentTask(const AdminModels::CreateTaskResult& result) { Call(FN_OnCreateActionsOnPlayersInSegmentTask, result); };
		void OnCreateCloudScriptTask(const AdminModels::CreateTaskResult& result) { Call(FN_OnCreateCloudScriptTask, result); };
		void OnDeleteTask(const AdminModels::EmptyResult& result) { Call(FN_OnDeleteTask, result); };
		void OnGetActionsOnPlayersInSegmentTaskInstance(const AdminModels::GetActionsOnPlayersInSegmentTaskInstanceResult& result) { Call(FN_OnGetActionsOnPlayersInSegmentTaskInstance, result); };
		void OnGetCloudScriptTaskInstance(const AdminModels::GetCloudScriptTaskInstanceResult& result) { Call(FN_OnGetCloudScriptTaskInstance, result); };
		void OnGetTaskInstances(const AdminModels::GetTaskInstancesResult& result) { Call(FN_OnGetTaskInstances, result); };
		void OnGetTasks(const AdminModels::GetTasksResult& result) { Call(FN_OnGetTasks, result); };
		void OnRunTask(const AdminModels::RunTaskResult& result) { Call(FN_OnRunTask, result); };
		void OnUpdateTask(const AdminModels::EmptyResult& result) { Call(FN_OnUpdateTask, result); };

	};

    // Behavior binder for the (global) based notification bus.
	class PlayFabServer_AdminGlobalBehaviorBusHandler : 
		public PlayFabServer_AdminGlobalNotificationBus::Handler, 
		public PlayFabServer_AdminBehaviorBusBaseHandler<PlayFabServer_AdminGlobalBehaviorBusHandler>
	{
   
	public:
        
		AZ_RTTI(PlayFabServer_AdminGlobalBehaviorBusHandler,"{d9e59256-f1fa-5fcb-98cc-9158e7153710}",AZ::BehaviorEBusHandler)

        void Disconnect() override {
			BusDisconnect();
		}

		void OnError(const PlayFabError& error, int requestId) override
		{
			Call(FN_OnError, error, requestId);
		}

		// ------------ Generated APIs to receive from the PlayFab notification bus and forward on to the Lua behavior context.
	
		void OnCreatePlayerSharedSecret(const AdminModels::CreatePlayerSharedSecretResult& result,int requestId) { Call(FN_OnCreatePlayerSharedSecret, result,requestId); };
		void OnDeletePlayerSharedSecret(const AdminModels::DeletePlayerSharedSecretResult& result,int requestId) { Call(FN_OnDeletePlayerSharedSecret, result,requestId); };
		void OnGetPlayerSharedSecrets(const AdminModels::GetPlayerSharedSecretsResult& result,int requestId) { Call(FN_OnGetPlayerSharedSecrets, result,requestId); };
		void OnGetPolicy(const AdminModels::GetPolicyResponse& result,int requestId) { Call(FN_OnGetPolicy, result,requestId); };
		void OnSetPlayerSecret(const AdminModels::SetPlayerSecretResult& result,int requestId) { Call(FN_OnSetPlayerSecret, result,requestId); };
		void OnUpdatePlayerSharedSecret(const AdminModels::UpdatePlayerSharedSecretResult& result,int requestId) { Call(FN_OnUpdatePlayerSharedSecret, result,requestId); };
		void OnUpdatePolicy(const AdminModels::UpdatePolicyResponse& result,int requestId) { Call(FN_OnUpdatePolicy, result,requestId); };
		void OnBanUsers(const AdminModels::BanUsersResult& result,int requestId) { Call(FN_OnBanUsers, result,requestId); };
		void OnDeletePlayer(const AdminModels::DeletePlayerResult& result,int requestId) { Call(FN_OnDeletePlayer, result,requestId); };
		void OnGetUserAccountInfo(const AdminModels::LookupUserAccountInfoResult& result,int requestId) { Call(FN_OnGetUserAccountInfo, result,requestId); };
		void OnGetUserBans(const AdminModels::GetUserBansResult& result,int requestId) { Call(FN_OnGetUserBans, result,requestId); };
		void OnResetUsers(const AdminModels::BlankResult& result,int requestId) { Call(FN_OnResetUsers, result,requestId); };
		void OnRevokeAllBansForUser(const AdminModels::RevokeAllBansForUserResult& result,int requestId) { Call(FN_OnRevokeAllBansForUser, result,requestId); };
		void OnRevokeBans(const AdminModels::RevokeBansResult& result,int requestId) { Call(FN_OnRevokeBans, result,requestId); };
		void OnSendAccountRecoveryEmail(const AdminModels::SendAccountRecoveryEmailResult& result,int requestId) { Call(FN_OnSendAccountRecoveryEmail, result,requestId); };
		void OnUpdateBans(const AdminModels::UpdateBansResult& result,int requestId) { Call(FN_OnUpdateBans, result,requestId); };
		void OnUpdateUserTitleDisplayName(const AdminModels::UpdateUserTitleDisplayNameResult& result,int requestId) { Call(FN_OnUpdateUserTitleDisplayName, result,requestId); };
		void OnCreatePlayerStatisticDefinition(const AdminModels::CreatePlayerStatisticDefinitionResult& result,int requestId) { Call(FN_OnCreatePlayerStatisticDefinition, result,requestId); };
		void OnDeleteUsers(const AdminModels::DeleteUsersResult& result,int requestId) { Call(FN_OnDeleteUsers, result,requestId); };
		void OnGetDataReport(const AdminModels::GetDataReportResult& result,int requestId) { Call(FN_OnGetDataReport, result,requestId); };
		void OnGetPlayerStatisticDefinitions(const AdminModels::GetPlayerStatisticDefinitionsResult& result,int requestId) { Call(FN_OnGetPlayerStatisticDefinitions, result,requestId); };
		void OnGetPlayerStatisticVersions(const AdminModels::GetPlayerStatisticVersionsResult& result,int requestId) { Call(FN_OnGetPlayerStatisticVersions, result,requestId); };
		void OnGetUserData(const AdminModels::GetUserDataResult& result,int requestId) { Call(FN_OnGetUserData, result,requestId); };
		void OnGetUserInternalData(const AdminModels::GetUserDataResult& result,int requestId) { Call(FN_OnGetUserInternalData, result,requestId); };
		void OnGetUserPublisherData(const AdminModels::GetUserDataResult& result,int requestId) { Call(FN_OnGetUserPublisherData, result,requestId); };
		void OnGetUserPublisherInternalData(const AdminModels::GetUserDataResult& result,int requestId) { Call(FN_OnGetUserPublisherInternalData, result,requestId); };
		void OnGetUserPublisherReadOnlyData(const AdminModels::GetUserDataResult& result,int requestId) { Call(FN_OnGetUserPublisherReadOnlyData, result,requestId); };
		void OnGetUserReadOnlyData(const AdminModels::GetUserDataResult& result,int requestId) { Call(FN_OnGetUserReadOnlyData, result,requestId); };
		void OnIncrementPlayerStatisticVersion(const AdminModels::IncrementPlayerStatisticVersionResult& result,int requestId) { Call(FN_OnIncrementPlayerStatisticVersion, result,requestId); };
		void OnRefundPurchase(const AdminModels::RefundPurchaseResponse& result,int requestId) { Call(FN_OnRefundPurchase, result,requestId); };
		void OnResetUserStatistics(const AdminModels::ResetUserStatisticsResult& result,int requestId) { Call(FN_OnResetUserStatistics, result,requestId); };
		void OnResolvePurchaseDispute(const AdminModels::ResolvePurchaseDisputeResponse& result,int requestId) { Call(FN_OnResolvePurchaseDispute, result,requestId); };
		void OnUpdatePlayerStatisticDefinition(const AdminModels::UpdatePlayerStatisticDefinitionResult& result,int requestId) { Call(FN_OnUpdatePlayerStatisticDefinition, result,requestId); };
		void OnUpdateUserData(const AdminModels::UpdateUserDataResult& result,int requestId) { Call(FN_OnUpdateUserData, result,requestId); };
		void OnUpdateUserInternalData(const AdminModels::UpdateUserDataResult& result,int requestId) { Call(FN_OnUpdateUserInternalData, result,requestId); };
		void OnUpdateUserPublisherData(const AdminModels::UpdateUserDataResult& result,int requestId) { Call(FN_OnUpdateUserPublisherData, result,requestId); };
		void OnUpdateUserPublisherInternalData(const AdminModels::UpdateUserDataResult& result,int requestId) { Call(FN_OnUpdateUserPublisherInternalData, result,requestId); };
		void OnUpdateUserPublisherReadOnlyData(const AdminModels::UpdateUserDataResult& result,int requestId) { Call(FN_OnUpdateUserPublisherReadOnlyData, result,requestId); };
		void OnUpdateUserReadOnlyData(const AdminModels::UpdateUserDataResult& result,int requestId) { Call(FN_OnUpdateUserReadOnlyData, result,requestId); };
		void OnAddNews(const AdminModels::AddNewsResult& result,int requestId) { Call(FN_OnAddNews, result,requestId); };
		void OnAddVirtualCurrencyTypes(const AdminModels::BlankResult& result,int requestId) { Call(FN_OnAddVirtualCurrencyTypes, result,requestId); };
		void OnDeleteStore(const AdminModels::DeleteStoreResult& result,int requestId) { Call(FN_OnDeleteStore, result,requestId); };
		void OnGetCatalogItems(const AdminModels::GetCatalogItemsResult& result,int requestId) { Call(FN_OnGetCatalogItems, result,requestId); };
		void OnGetPublisherData(const AdminModels::GetPublisherDataResult& result,int requestId) { Call(FN_OnGetPublisherData, result,requestId); };
		void OnGetRandomResultTables(const AdminModels::GetRandomResultTablesResult& result,int requestId) { Call(FN_OnGetRandomResultTables, result,requestId); };
		void OnGetStoreItems(const AdminModels::GetStoreItemsResult& result,int requestId) { Call(FN_OnGetStoreItems, result,requestId); };
		void OnGetTitleData(const AdminModels::GetTitleDataResult& result,int requestId) { Call(FN_OnGetTitleData, result,requestId); };
		void OnGetTitleInternalData(const AdminModels::GetTitleDataResult& result,int requestId) { Call(FN_OnGetTitleInternalData, result,requestId); };
		void OnListVirtualCurrencyTypes(const AdminModels::ListVirtualCurrencyTypesResult& result,int requestId) { Call(FN_OnListVirtualCurrencyTypes, result,requestId); };
		void OnRemoveVirtualCurrencyTypes(const AdminModels::BlankResult& result,int requestId) { Call(FN_OnRemoveVirtualCurrencyTypes, result,requestId); };
		void OnSetCatalogItems(const AdminModels::UpdateCatalogItemsResult& result,int requestId) { Call(FN_OnSetCatalogItems, result,requestId); };
		void OnSetStoreItems(const AdminModels::UpdateStoreItemsResult& result,int requestId) { Call(FN_OnSetStoreItems, result,requestId); };
		void OnSetTitleData(const AdminModels::SetTitleDataResult& result,int requestId) { Call(FN_OnSetTitleData, result,requestId); };
		void OnSetTitleInternalData(const AdminModels::SetTitleDataResult& result,int requestId) { Call(FN_OnSetTitleInternalData, result,requestId); };
		void OnSetupPushNotification(const AdminModels::SetupPushNotificationResult& result,int requestId) { Call(FN_OnSetupPushNotification, result,requestId); };
		void OnUpdateCatalogItems(const AdminModels::UpdateCatalogItemsResult& result,int requestId) { Call(FN_OnUpdateCatalogItems, result,requestId); };
		void OnUpdateRandomResultTables(const AdminModels::UpdateRandomResultTablesResult& result,int requestId) { Call(FN_OnUpdateRandomResultTables, result,requestId); };
		void OnUpdateStoreItems(const AdminModels::UpdateStoreItemsResult& result,int requestId) { Call(FN_OnUpdateStoreItems, result,requestId); };
		void OnAddUserVirtualCurrency(const AdminModels::ModifyUserVirtualCurrencyResult& result,int requestId) { Call(FN_OnAddUserVirtualCurrency, result,requestId); };
		void OnGetUserInventory(const AdminModels::GetUserInventoryResult& result,int requestId) { Call(FN_OnGetUserInventory, result,requestId); };
		void OnGrantItemsToUsers(const AdminModels::GrantItemsToUsersResult& result,int requestId) { Call(FN_OnGrantItemsToUsers, result,requestId); };
		void OnRevokeInventoryItem(const AdminModels::RevokeInventoryResult& result,int requestId) { Call(FN_OnRevokeInventoryItem, result,requestId); };
		void OnSubtractUserVirtualCurrency(const AdminModels::ModifyUserVirtualCurrencyResult& result,int requestId) { Call(FN_OnSubtractUserVirtualCurrency, result,requestId); };
		void OnGetMatchmakerGameInfo(const AdminModels::GetMatchmakerGameInfoResult& result,int requestId) { Call(FN_OnGetMatchmakerGameInfo, result,requestId); };
		void OnGetMatchmakerGameModes(const AdminModels::GetMatchmakerGameModesResult& result,int requestId) { Call(FN_OnGetMatchmakerGameModes, result,requestId); };
		void OnModifyMatchmakerGameModes(const AdminModels::ModifyMatchmakerGameModesResult& result,int requestId) { Call(FN_OnModifyMatchmakerGameModes, result,requestId); };
		void OnAddServerBuild(const AdminModels::AddServerBuildResult& result,int requestId) { Call(FN_OnAddServerBuild, result,requestId); };
		void OnGetServerBuildInfo(const AdminModels::GetServerBuildInfoResult& result,int requestId) { Call(FN_OnGetServerBuildInfo, result,requestId); };
		void OnGetServerBuildUploadUrl(const AdminModels::GetServerBuildUploadURLResult& result,int requestId) { Call(FN_OnGetServerBuildUploadUrl, result,requestId); };
		void OnListServerBuilds(const AdminModels::ListBuildsResult& result,int requestId) { Call(FN_OnListServerBuilds, result,requestId); };
		void OnModifyServerBuild(const AdminModels::ModifyServerBuildResult& result,int requestId) { Call(FN_OnModifyServerBuild, result,requestId); };
		void OnRemoveServerBuild(const AdminModels::RemoveServerBuildResult& result,int requestId) { Call(FN_OnRemoveServerBuild, result,requestId); };
		void OnSetPublisherData(const AdminModels::SetPublisherDataResult& result,int requestId) { Call(FN_OnSetPublisherData, result,requestId); };
		void OnGetCloudScriptRevision(const AdminModels::GetCloudScriptRevisionResult& result,int requestId) { Call(FN_OnGetCloudScriptRevision, result,requestId); };
		void OnGetCloudScriptVersions(const AdminModels::GetCloudScriptVersionsResult& result,int requestId) { Call(FN_OnGetCloudScriptVersions, result,requestId); };
		void OnSetPublishedRevision(const AdminModels::SetPublishedRevisionResult& result,int requestId) { Call(FN_OnSetPublishedRevision, result,requestId); };
		void OnUpdateCloudScript(const AdminModels::UpdateCloudScriptResult& result,int requestId) { Call(FN_OnUpdateCloudScript, result,requestId); };
		void OnDeleteContent(const AdminModels::BlankResult& result,int requestId) { Call(FN_OnDeleteContent, result,requestId); };
		void OnGetContentList(const AdminModels::GetContentListResult& result,int requestId) { Call(FN_OnGetContentList, result,requestId); };
		void OnGetContentUploadUrl(const AdminModels::GetContentUploadUrlResult& result,int requestId) { Call(FN_OnGetContentUploadUrl, result,requestId); };
		void OnResetCharacterStatistics(const AdminModels::ResetCharacterStatisticsResult& result,int requestId) { Call(FN_OnResetCharacterStatistics, result,requestId); };
		void OnAddPlayerTag(const AdminModels::AddPlayerTagResult& result,int requestId) { Call(FN_OnAddPlayerTag, result,requestId); };
		void OnGetAllActionGroups(const AdminModels::GetAllActionGroupsResult& result,int requestId) { Call(FN_OnGetAllActionGroups, result,requestId); };
		void OnGetAllSegments(const AdminModels::GetAllSegmentsResult& result,int requestId) { Call(FN_OnGetAllSegments, result,requestId); };
		void OnGetPlayerSegments(const AdminModels::GetPlayerSegmentsResult& result,int requestId) { Call(FN_OnGetPlayerSegments, result,requestId); };
		void OnGetPlayersInSegment(const AdminModels::GetPlayersInSegmentResult& result,int requestId) { Call(FN_OnGetPlayersInSegment, result,requestId); };
		void OnGetPlayerTags(const AdminModels::GetPlayerTagsResult& result,int requestId) { Call(FN_OnGetPlayerTags, result,requestId); };
		void OnRemovePlayerTag(const AdminModels::RemovePlayerTagResult& result,int requestId) { Call(FN_OnRemovePlayerTag, result,requestId); };
		void OnAbortTaskInstance(const AdminModels::EmptyResult& result,int requestId) { Call(FN_OnAbortTaskInstance, result,requestId); };
		void OnCreateActionsOnPlayersInSegmentTask(const AdminModels::CreateTaskResult& result,int requestId) { Call(FN_OnCreateActionsOnPlayersInSegmentTask, result,requestId); };
		void OnCreateCloudScriptTask(const AdminModels::CreateTaskResult& result,int requestId) { Call(FN_OnCreateCloudScriptTask, result,requestId); };
		void OnDeleteTask(const AdminModels::EmptyResult& result,int requestId) { Call(FN_OnDeleteTask, result,requestId); };
		void OnGetActionsOnPlayersInSegmentTaskInstance(const AdminModels::GetActionsOnPlayersInSegmentTaskInstanceResult& result,int requestId) { Call(FN_OnGetActionsOnPlayersInSegmentTaskInstance, result,requestId); };
		void OnGetCloudScriptTaskInstance(const AdminModels::GetCloudScriptTaskInstanceResult& result,int requestId) { Call(FN_OnGetCloudScriptTaskInstance, result,requestId); };
		void OnGetTaskInstances(const AdminModels::GetTaskInstancesResult& result,int requestId) { Call(FN_OnGetTaskInstances, result,requestId); };
		void OnGetTasks(const AdminModels::GetTasksResult& result,int requestId) { Call(FN_OnGetTasks, result,requestId); };
		void OnRunTask(const AdminModels::RunTaskResult& result,int requestId) { Call(FN_OnRunTask, result,requestId); };
		void OnUpdateTask(const AdminModels::EmptyResult& result,int requestId) { Call(FN_OnUpdateTask, result,requestId); };

	};

    //-----------------------------------------------------------------------------------------------------
    // MAIN REFLECTION FUNCTION
    //-----------------------------------------------------------------------------------------------------
	void PlayFabServer_AdminBehaviorContext::Reflect(AZ::ReflectContext* context)
	{
		AZ::BehaviorContext* behaviorContext = azrtti_cast<AZ::BehaviorContext*>(context);
		if (behaviorContext)
		{
			// Reflect the request bus
			behaviorContext->EBus<PlayFabServer_AdminSimpleRequestBus>("PlayFabAdminRequestBus")
				->Event("CreatePlayerSharedSecret", &PlayFabServer_AdminSimpleRequestBus::Events::CreatePlayerSharedSecret)
				->Event("DeletePlayerSharedSecret", &PlayFabServer_AdminSimpleRequestBus::Events::DeletePlayerSharedSecret)
				->Event("GetPlayerSharedSecrets", &PlayFabServer_AdminSimpleRequestBus::Events::GetPlayerSharedSecrets)
				->Event("GetPolicy", &PlayFabServer_AdminSimpleRequestBus::Events::GetPolicy)
				->Event("SetPlayerSecret", &PlayFabServer_AdminSimpleRequestBus::Events::SetPlayerSecret)
				->Event("UpdatePlayerSharedSecret", &PlayFabServer_AdminSimpleRequestBus::Events::UpdatePlayerSharedSecret)
				->Event("UpdatePolicy", &PlayFabServer_AdminSimpleRequestBus::Events::UpdatePolicy)
				->Event("BanUsers", &PlayFabServer_AdminSimpleRequestBus::Events::BanUsers)
				->Event("DeletePlayer", &PlayFabServer_AdminSimpleRequestBus::Events::DeletePlayer)
				->Event("GetUserAccountInfo", &PlayFabServer_AdminSimpleRequestBus::Events::GetUserAccountInfo)
				->Event("GetUserBans", &PlayFabServer_AdminSimpleRequestBus::Events::GetUserBans)
				->Event("ResetUsers", &PlayFabServer_AdminSimpleRequestBus::Events::ResetUsers)
				->Event("RevokeAllBansForUser", &PlayFabServer_AdminSimpleRequestBus::Events::RevokeAllBansForUser)
				->Event("RevokeBans", &PlayFabServer_AdminSimpleRequestBus::Events::RevokeBans)
				->Event("SendAccountRecoveryEmail", &PlayFabServer_AdminSimpleRequestBus::Events::SendAccountRecoveryEmail)
				->Event("UpdateBans", &PlayFabServer_AdminSimpleRequestBus::Events::UpdateBans)
				->Event("UpdateUserTitleDisplayName", &PlayFabServer_AdminSimpleRequestBus::Events::UpdateUserTitleDisplayName)
				->Event("CreatePlayerStatisticDefinition", &PlayFabServer_AdminSimpleRequestBus::Events::CreatePlayerStatisticDefinition)
				->Event("DeleteUsers", &PlayFabServer_AdminSimpleRequestBus::Events::DeleteUsers)
				->Event("GetDataReport", &PlayFabServer_AdminSimpleRequestBus::Events::GetDataReport)
				->Event("GetPlayerStatisticDefinitions", &PlayFabServer_AdminSimpleRequestBus::Events::GetPlayerStatisticDefinitions)
				->Event("GetPlayerStatisticVersions", &PlayFabServer_AdminSimpleRequestBus::Events::GetPlayerStatisticVersions)
				->Event("GetUserData", &PlayFabServer_AdminSimpleRequestBus::Events::GetUserData)
				->Event("GetUserInternalData", &PlayFabServer_AdminSimpleRequestBus::Events::GetUserInternalData)
				->Event("GetUserPublisherData", &PlayFabServer_AdminSimpleRequestBus::Events::GetUserPublisherData)
				->Event("GetUserPublisherInternalData", &PlayFabServer_AdminSimpleRequestBus::Events::GetUserPublisherInternalData)
				->Event("GetUserPublisherReadOnlyData", &PlayFabServer_AdminSimpleRequestBus::Events::GetUserPublisherReadOnlyData)
				->Event("GetUserReadOnlyData", &PlayFabServer_AdminSimpleRequestBus::Events::GetUserReadOnlyData)
				->Event("IncrementPlayerStatisticVersion", &PlayFabServer_AdminSimpleRequestBus::Events::IncrementPlayerStatisticVersion)
				->Event("RefundPurchase", &PlayFabServer_AdminSimpleRequestBus::Events::RefundPurchase)
				->Event("ResetUserStatistics", &PlayFabServer_AdminSimpleRequestBus::Events::ResetUserStatistics)
				->Event("ResolvePurchaseDispute", &PlayFabServer_AdminSimpleRequestBus::Events::ResolvePurchaseDispute)
				->Event("UpdatePlayerStatisticDefinition", &PlayFabServer_AdminSimpleRequestBus::Events::UpdatePlayerStatisticDefinition)
				->Event("UpdateUserData", &PlayFabServer_AdminSimpleRequestBus::Events::UpdateUserData)
				->Event("UpdateUserInternalData", &PlayFabServer_AdminSimpleRequestBus::Events::UpdateUserInternalData)
				->Event("UpdateUserPublisherData", &PlayFabServer_AdminSimpleRequestBus::Events::UpdateUserPublisherData)
				->Event("UpdateUserPublisherInternalData", &PlayFabServer_AdminSimpleRequestBus::Events::UpdateUserPublisherInternalData)
				->Event("UpdateUserPublisherReadOnlyData", &PlayFabServer_AdminSimpleRequestBus::Events::UpdateUserPublisherReadOnlyData)
				->Event("UpdateUserReadOnlyData", &PlayFabServer_AdminSimpleRequestBus::Events::UpdateUserReadOnlyData)
				->Event("AddNews", &PlayFabServer_AdminSimpleRequestBus::Events::AddNews)
				->Event("AddVirtualCurrencyTypes", &PlayFabServer_AdminSimpleRequestBus::Events::AddVirtualCurrencyTypes)
				->Event("DeleteStore", &PlayFabServer_AdminSimpleRequestBus::Events::DeleteStore)
				->Event("GetCatalogItems", &PlayFabServer_AdminSimpleRequestBus::Events::GetCatalogItems)
				->Event("GetPublisherData", &PlayFabServer_AdminSimpleRequestBus::Events::GetPublisherData)
				->Event("GetRandomResultTables", &PlayFabServer_AdminSimpleRequestBus::Events::GetRandomResultTables)
				->Event("GetStoreItems", &PlayFabServer_AdminSimpleRequestBus::Events::GetStoreItems)
				->Event("GetTitleData", &PlayFabServer_AdminSimpleRequestBus::Events::GetTitleData)
				->Event("GetTitleInternalData", &PlayFabServer_AdminSimpleRequestBus::Events::GetTitleInternalData)
				->Event("ListVirtualCurrencyTypes", &PlayFabServer_AdminSimpleRequestBus::Events::ListVirtualCurrencyTypes)
				->Event("RemoveVirtualCurrencyTypes", &PlayFabServer_AdminSimpleRequestBus::Events::RemoveVirtualCurrencyTypes)
				->Event("SetCatalogItems", &PlayFabServer_AdminSimpleRequestBus::Events::SetCatalogItems)
				->Event("SetStoreItems", &PlayFabServer_AdminSimpleRequestBus::Events::SetStoreItems)
				->Event("SetTitleData", &PlayFabServer_AdminSimpleRequestBus::Events::SetTitleData)
				->Event("SetTitleInternalData", &PlayFabServer_AdminSimpleRequestBus::Events::SetTitleInternalData)
				->Event("SetupPushNotification", &PlayFabServer_AdminSimpleRequestBus::Events::SetupPushNotification)
				->Event("UpdateCatalogItems", &PlayFabServer_AdminSimpleRequestBus::Events::UpdateCatalogItems)
				->Event("UpdateRandomResultTables", &PlayFabServer_AdminSimpleRequestBus::Events::UpdateRandomResultTables)
				->Event("UpdateStoreItems", &PlayFabServer_AdminSimpleRequestBus::Events::UpdateStoreItems)
				->Event("AddUserVirtualCurrency", &PlayFabServer_AdminSimpleRequestBus::Events::AddUserVirtualCurrency)
				->Event("GetUserInventory", &PlayFabServer_AdminSimpleRequestBus::Events::GetUserInventory)
				->Event("GrantItemsToUsers", &PlayFabServer_AdminSimpleRequestBus::Events::GrantItemsToUsers)
				->Event("RevokeInventoryItem", &PlayFabServer_AdminSimpleRequestBus::Events::RevokeInventoryItem)
				->Event("SubtractUserVirtualCurrency", &PlayFabServer_AdminSimpleRequestBus::Events::SubtractUserVirtualCurrency)
				->Event("GetMatchmakerGameInfo", &PlayFabServer_AdminSimpleRequestBus::Events::GetMatchmakerGameInfo)
				->Event("GetMatchmakerGameModes", &PlayFabServer_AdminSimpleRequestBus::Events::GetMatchmakerGameModes)
				->Event("ModifyMatchmakerGameModes", &PlayFabServer_AdminSimpleRequestBus::Events::ModifyMatchmakerGameModes)
				->Event("AddServerBuild", &PlayFabServer_AdminSimpleRequestBus::Events::AddServerBuild)
				->Event("GetServerBuildInfo", &PlayFabServer_AdminSimpleRequestBus::Events::GetServerBuildInfo)
				->Event("GetServerBuildUploadUrl", &PlayFabServer_AdminSimpleRequestBus::Events::GetServerBuildUploadUrl)
				->Event("ListServerBuilds", &PlayFabServer_AdminSimpleRequestBus::Events::ListServerBuilds)
				->Event("ModifyServerBuild", &PlayFabServer_AdminSimpleRequestBus::Events::ModifyServerBuild)
				->Event("RemoveServerBuild", &PlayFabServer_AdminSimpleRequestBus::Events::RemoveServerBuild)
				->Event("SetPublisherData", &PlayFabServer_AdminSimpleRequestBus::Events::SetPublisherData)
				->Event("GetCloudScriptRevision", &PlayFabServer_AdminSimpleRequestBus::Events::GetCloudScriptRevision)
				->Event("GetCloudScriptVersions", &PlayFabServer_AdminSimpleRequestBus::Events::GetCloudScriptVersions)
				->Event("SetPublishedRevision", &PlayFabServer_AdminSimpleRequestBus::Events::SetPublishedRevision)
				->Event("UpdateCloudScript", &PlayFabServer_AdminSimpleRequestBus::Events::UpdateCloudScript)
				->Event("DeleteContent", &PlayFabServer_AdminSimpleRequestBus::Events::DeleteContent)
				->Event("GetContentList", &PlayFabServer_AdminSimpleRequestBus::Events::GetContentList)
				->Event("GetContentUploadUrl", &PlayFabServer_AdminSimpleRequestBus::Events::GetContentUploadUrl)
				->Event("ResetCharacterStatistics", &PlayFabServer_AdminSimpleRequestBus::Events::ResetCharacterStatistics)
				->Event("AddPlayerTag", &PlayFabServer_AdminSimpleRequestBus::Events::AddPlayerTag)
				->Event("GetAllActionGroups", &PlayFabServer_AdminSimpleRequestBus::Events::GetAllActionGroups)
				->Event("GetAllSegments", &PlayFabServer_AdminSimpleRequestBus::Events::GetAllSegments)
				->Event("GetPlayerSegments", &PlayFabServer_AdminSimpleRequestBus::Events::GetPlayerSegments)
				->Event("GetPlayersInSegment", &PlayFabServer_AdminSimpleRequestBus::Events::GetPlayersInSegment)
				->Event("GetPlayerTags", &PlayFabServer_AdminSimpleRequestBus::Events::GetPlayerTags)
				->Event("RemovePlayerTag", &PlayFabServer_AdminSimpleRequestBus::Events::RemovePlayerTag)
				->Event("AbortTaskInstance", &PlayFabServer_AdminSimpleRequestBus::Events::AbortTaskInstance)
				->Event("CreateActionsOnPlayersInSegmentTask", &PlayFabServer_AdminSimpleRequestBus::Events::CreateActionsOnPlayersInSegmentTask)
				->Event("CreateCloudScriptTask", &PlayFabServer_AdminSimpleRequestBus::Events::CreateCloudScriptTask)
				->Event("DeleteTask", &PlayFabServer_AdminSimpleRequestBus::Events::DeleteTask)
				->Event("GetActionsOnPlayersInSegmentTaskInstance", &PlayFabServer_AdminSimpleRequestBus::Events::GetActionsOnPlayersInSegmentTaskInstance)
				->Event("GetCloudScriptTaskInstance", &PlayFabServer_AdminSimpleRequestBus::Events::GetCloudScriptTaskInstance)
				->Event("GetTaskInstances", &PlayFabServer_AdminSimpleRequestBus::Events::GetTaskInstances)
				->Event("GetTasks", &PlayFabServer_AdminSimpleRequestBus::Events::GetTasks)
				->Event("RunTask", &PlayFabServer_AdminSimpleRequestBus::Events::RunTask)
				->Event("UpdateTask", &PlayFabServer_AdminSimpleRequestBus::Events::UpdateTask);

			// Reflect the ADDRESSED notification bus: (uses the BehaviorBusHandler declared at the beginning of this file)
			behaviorContext->EBus<PlayFabServer_AdminNotificationBus>("PlayFabAdminNotificationBus")
				->Handler<PlayFabServer_AdminBehaviorBusHandler>();

			// Reflect the GLOBAL notification bus: (uses the BehaviorBusHandler declared at the beginning of this file)
			behaviorContext->EBus<PlayFabServer_AdminGlobalNotificationBus>("PlayFabAdminGlobalNotificationBus")
				->Handler<PlayFabServer_AdminGlobalBehaviorBusHandler>();                
			
            //-----------------------------------------------------------------------------------------------------
			// Reflect enum values
            //-----------------------------------------------------------------------------------------------------
	        behaviorContext 
                ->Enum<AdminModels::TaskInstanceStatus::TaskInstanceStatusSucceeded>( "PlayFabAdmin_TaskInstanceStatus_Succeeded" )
                ->Enum<AdminModels::TaskInstanceStatus::TaskInstanceStatusStarting>( "PlayFabAdmin_TaskInstanceStatus_Starting" )
                ->Enum<AdminModels::TaskInstanceStatus::TaskInstanceStatusInProgress>( "PlayFabAdmin_TaskInstanceStatus_InProgress" )
                ->Enum<AdminModels::TaskInstanceStatus::TaskInstanceStatusFailed>( "PlayFabAdmin_TaskInstanceStatus_Failed" )
                ->Enum<AdminModels::TaskInstanceStatus::TaskInstanceStatusAborted>( "PlayFabAdmin_TaskInstanceStatus_Aborted" )
                ->Enum<AdminModels::TaskInstanceStatus::TaskInstanceStatusPending>( "PlayFabAdmin_TaskInstanceStatus_Pending" )
            ;
            behaviorContext 
                ->Enum<AdminModels::Region::RegionUSCentral>( "PlayFabAdmin_Region_USCentral" )
                ->Enum<AdminModels::Region::RegionUSEast>( "PlayFabAdmin_Region_USEast" )
                ->Enum<AdminModels::Region::RegionEUWest>( "PlayFabAdmin_Region_EUWest" )
                ->Enum<AdminModels::Region::RegionSingapore>( "PlayFabAdmin_Region_Singapore" )
                ->Enum<AdminModels::Region::RegionJapan>( "PlayFabAdmin_Region_Japan" )
                ->Enum<AdminModels::Region::RegionBrazil>( "PlayFabAdmin_Region_Brazil" )
                ->Enum<AdminModels::Region::RegionAustralia>( "PlayFabAdmin_Region_Australia" )
            ;
            behaviorContext 
                ->Enum<AdminModels::GameBuildStatus::GameBuildStatusAvailable>( "PlayFabAdmin_GameBuildStatus_Available" )
                ->Enum<AdminModels::GameBuildStatus::GameBuildStatusValidating>( "PlayFabAdmin_GameBuildStatus_Validating" )
                ->Enum<AdminModels::GameBuildStatus::GameBuildStatusInvalidBuildPackage>( "PlayFabAdmin_GameBuildStatus_InvalidBuildPackage" )
                ->Enum<AdminModels::GameBuildStatus::GameBuildStatusProcessing>( "PlayFabAdmin_GameBuildStatus_Processing" )
                ->Enum<AdminModels::GameBuildStatus::GameBuildStatusFailedToProcess>( "PlayFabAdmin_GameBuildStatus_FailedToProcess" )
            ;
            behaviorContext 
                ->Enum<AdminModels::Conditionals::ConditionalsAny>( "PlayFabAdmin_Conditionals_Any" )
                ->Enum<AdminModels::Conditionals::ConditionalsTrue>( "PlayFabAdmin_Conditionals_True" )
                ->Enum<AdminModels::Conditionals::ConditionalsFalse>( "PlayFabAdmin_Conditionals_False" )
            ;
            behaviorContext 
                ->Enum<AdminModels::EmailVerificationStatus::EmailVerificationStatusUnverified>( "PlayFabAdmin_EmailVerificationStatus_Unverified" )
                ->Enum<AdminModels::EmailVerificationStatus::EmailVerificationStatusPending>( "PlayFabAdmin_EmailVerificationStatus_Pending" )
                ->Enum<AdminModels::EmailVerificationStatus::EmailVerificationStatusConfirmed>( "PlayFabAdmin_EmailVerificationStatus_Confirmed" )
            ;
            behaviorContext 
                ->Enum<AdminModels::ContinentCode::ContinentCodeAF>( "PlayFabAdmin_ContinentCode_AF" )
                ->Enum<AdminModels::ContinentCode::ContinentCodeAN>( "PlayFabAdmin_ContinentCode_AN" )
                ->Enum<AdminModels::ContinentCode::ContinentCodeAS>( "PlayFabAdmin_ContinentCode_AS" )
                ->Enum<AdminModels::ContinentCode::ContinentCodeEU>( "PlayFabAdmin_ContinentCode_EU" )
                ->Enum<AdminModels::ContinentCode::ContinentCodeNA>( "PlayFabAdmin_ContinentCode_NA" )
                ->Enum<AdminModels::ContinentCode::ContinentCodeOC>( "PlayFabAdmin_ContinentCode_OC" )
                ->Enum<AdminModels::ContinentCode::ContinentCodeSA>( "PlayFabAdmin_ContinentCode_SA" )
            ;
            behaviorContext 
                ->Enum<AdminModels::CountryCode::CountryCodeAF>( "PlayFabAdmin_CountryCode_AF" )
                ->Enum<AdminModels::CountryCode::CountryCodeAX>( "PlayFabAdmin_CountryCode_AX" )
                ->Enum<AdminModels::CountryCode::CountryCodeAL>( "PlayFabAdmin_CountryCode_AL" )
                ->Enum<AdminModels::CountryCode::CountryCodeDZ>( "PlayFabAdmin_CountryCode_DZ" )
                ->Enum<AdminModels::CountryCode::CountryCodeAS>( "PlayFabAdmin_CountryCode_AS" )
                ->Enum<AdminModels::CountryCode::CountryCodeAD>( "PlayFabAdmin_CountryCode_AD" )
                ->Enum<AdminModels::CountryCode::CountryCodeAO>( "PlayFabAdmin_CountryCode_AO" )
                ->Enum<AdminModels::CountryCode::CountryCodeAI>( "PlayFabAdmin_CountryCode_AI" )
                ->Enum<AdminModels::CountryCode::CountryCodeAQ>( "PlayFabAdmin_CountryCode_AQ" )
                ->Enum<AdminModels::CountryCode::CountryCodeAG>( "PlayFabAdmin_CountryCode_AG" )
                ->Enum<AdminModels::CountryCode::CountryCodeAR>( "PlayFabAdmin_CountryCode_AR" )
                ->Enum<AdminModels::CountryCode::CountryCodeAM>( "PlayFabAdmin_CountryCode_AM" )
                ->Enum<AdminModels::CountryCode::CountryCodeAW>( "PlayFabAdmin_CountryCode_AW" )
                ->Enum<AdminModels::CountryCode::CountryCodeAU>( "PlayFabAdmin_CountryCode_AU" )
                ->Enum<AdminModels::CountryCode::CountryCodeAT>( "PlayFabAdmin_CountryCode_AT" )
                ->Enum<AdminModels::CountryCode::CountryCodeAZ>( "PlayFabAdmin_CountryCode_AZ" )
                ->Enum<AdminModels::CountryCode::CountryCodeBS>( "PlayFabAdmin_CountryCode_BS" )
                ->Enum<AdminModels::CountryCode::CountryCodeBH>( "PlayFabAdmin_CountryCode_BH" )
                ->Enum<AdminModels::CountryCode::CountryCodeBD>( "PlayFabAdmin_CountryCode_BD" )
                ->Enum<AdminModels::CountryCode::CountryCodeBB>( "PlayFabAdmin_CountryCode_BB" )
                ->Enum<AdminModels::CountryCode::CountryCodeBY>( "PlayFabAdmin_CountryCode_BY" )
                ->Enum<AdminModels::CountryCode::CountryCodeBE>( "PlayFabAdmin_CountryCode_BE" )
                ->Enum<AdminModels::CountryCode::CountryCodeBZ>( "PlayFabAdmin_CountryCode_BZ" )
                ->Enum<AdminModels::CountryCode::CountryCodeBJ>( "PlayFabAdmin_CountryCode_BJ" )
                ->Enum<AdminModels::CountryCode::CountryCodeBM>( "PlayFabAdmin_CountryCode_BM" )
                ->Enum<AdminModels::CountryCode::CountryCodeBT>( "PlayFabAdmin_CountryCode_BT" )
                ->Enum<AdminModels::CountryCode::CountryCodeBO>( "PlayFabAdmin_CountryCode_BO" )
                ->Enum<AdminModels::CountryCode::CountryCodeBQ>( "PlayFabAdmin_CountryCode_BQ" )
                ->Enum<AdminModels::CountryCode::CountryCodeBA>( "PlayFabAdmin_CountryCode_BA" )
                ->Enum<AdminModels::CountryCode::CountryCodeBW>( "PlayFabAdmin_CountryCode_BW" )
                ->Enum<AdminModels::CountryCode::CountryCodeBV>( "PlayFabAdmin_CountryCode_BV" )
                ->Enum<AdminModels::CountryCode::CountryCodeBR>( "PlayFabAdmin_CountryCode_BR" )
                ->Enum<AdminModels::CountryCode::CountryCodeIO>( "PlayFabAdmin_CountryCode_IO" )
                ->Enum<AdminModels::CountryCode::CountryCodeBN>( "PlayFabAdmin_CountryCode_BN" )
                ->Enum<AdminModels::CountryCode::CountryCodeBG>( "PlayFabAdmin_CountryCode_BG" )
                ->Enum<AdminModels::CountryCode::CountryCodeBF>( "PlayFabAdmin_CountryCode_BF" )
                ->Enum<AdminModels::CountryCode::CountryCodeBI>( "PlayFabAdmin_CountryCode_BI" )
                ->Enum<AdminModels::CountryCode::CountryCodeKH>( "PlayFabAdmin_CountryCode_KH" )
                ->Enum<AdminModels::CountryCode::CountryCodeCM>( "PlayFabAdmin_CountryCode_CM" )
                ->Enum<AdminModels::CountryCode::CountryCodeCA>( "PlayFabAdmin_CountryCode_CA" )
                ->Enum<AdminModels::CountryCode::CountryCodeCV>( "PlayFabAdmin_CountryCode_CV" )
                ->Enum<AdminModels::CountryCode::CountryCodeKY>( "PlayFabAdmin_CountryCode_KY" )
                ->Enum<AdminModels::CountryCode::CountryCodeCF>( "PlayFabAdmin_CountryCode_CF" )
                ->Enum<AdminModels::CountryCode::CountryCodeTD>( "PlayFabAdmin_CountryCode_TD" )
                ->Enum<AdminModels::CountryCode::CountryCodeCL>( "PlayFabAdmin_CountryCode_CL" )
                ->Enum<AdminModels::CountryCode::CountryCodeCN>( "PlayFabAdmin_CountryCode_CN" )
                ->Enum<AdminModels::CountryCode::CountryCodeCX>( "PlayFabAdmin_CountryCode_CX" )
                ->Enum<AdminModels::CountryCode::CountryCodeCC>( "PlayFabAdmin_CountryCode_CC" )
                ->Enum<AdminModels::CountryCode::CountryCodeCO>( "PlayFabAdmin_CountryCode_CO" )
                ->Enum<AdminModels::CountryCode::CountryCodeKM>( "PlayFabAdmin_CountryCode_KM" )
                ->Enum<AdminModels::CountryCode::CountryCodeCG>( "PlayFabAdmin_CountryCode_CG" )
                ->Enum<AdminModels::CountryCode::CountryCodeCD>( "PlayFabAdmin_CountryCode_CD" )
                ->Enum<AdminModels::CountryCode::CountryCodeCK>( "PlayFabAdmin_CountryCode_CK" )
                ->Enum<AdminModels::CountryCode::CountryCodeCR>( "PlayFabAdmin_CountryCode_CR" )
                ->Enum<AdminModels::CountryCode::CountryCodeCI>( "PlayFabAdmin_CountryCode_CI" )
                ->Enum<AdminModels::CountryCode::CountryCodeHR>( "PlayFabAdmin_CountryCode_HR" )
                ->Enum<AdminModels::CountryCode::CountryCodeCU>( "PlayFabAdmin_CountryCode_CU" )
                ->Enum<AdminModels::CountryCode::CountryCodeCW>( "PlayFabAdmin_CountryCode_CW" )
                ->Enum<AdminModels::CountryCode::CountryCodeCY>( "PlayFabAdmin_CountryCode_CY" )
                ->Enum<AdminModels::CountryCode::CountryCodeCZ>( "PlayFabAdmin_CountryCode_CZ" )
                ->Enum<AdminModels::CountryCode::CountryCodeDK>( "PlayFabAdmin_CountryCode_DK" )
                ->Enum<AdminModels::CountryCode::CountryCodeDJ>( "PlayFabAdmin_CountryCode_DJ" )
                ->Enum<AdminModels::CountryCode::CountryCodeDM>( "PlayFabAdmin_CountryCode_DM" )
                ->Enum<AdminModels::CountryCode::CountryCodeDO>( "PlayFabAdmin_CountryCode_DO" )
                ->Enum<AdminModels::CountryCode::CountryCodeEC>( "PlayFabAdmin_CountryCode_EC" )
                ->Enum<AdminModels::CountryCode::CountryCodeEG>( "PlayFabAdmin_CountryCode_EG" )
                ->Enum<AdminModels::CountryCode::CountryCodeSV>( "PlayFabAdmin_CountryCode_SV" )
                ->Enum<AdminModels::CountryCode::CountryCodeGQ>( "PlayFabAdmin_CountryCode_GQ" )
                ->Enum<AdminModels::CountryCode::CountryCodeER>( "PlayFabAdmin_CountryCode_ER" )
                ->Enum<AdminModels::CountryCode::CountryCodeEE>( "PlayFabAdmin_CountryCode_EE" )
                ->Enum<AdminModels::CountryCode::CountryCodeET>( "PlayFabAdmin_CountryCode_ET" )
                ->Enum<AdminModels::CountryCode::CountryCodeFK>( "PlayFabAdmin_CountryCode_FK" )
                ->Enum<AdminModels::CountryCode::CountryCodeFO>( "PlayFabAdmin_CountryCode_FO" )
                ->Enum<AdminModels::CountryCode::CountryCodeFJ>( "PlayFabAdmin_CountryCode_FJ" )
                ->Enum<AdminModels::CountryCode::CountryCodeFI>( "PlayFabAdmin_CountryCode_FI" )
                ->Enum<AdminModels::CountryCode::CountryCodeFR>( "PlayFabAdmin_CountryCode_FR" )
                ->Enum<AdminModels::CountryCode::CountryCodeGF>( "PlayFabAdmin_CountryCode_GF" )
                ->Enum<AdminModels::CountryCode::CountryCodePF>( "PlayFabAdmin_CountryCode_PF" )
                ->Enum<AdminModels::CountryCode::CountryCodeTF>( "PlayFabAdmin_CountryCode_TF" )
                ->Enum<AdminModels::CountryCode::CountryCodeGA>( "PlayFabAdmin_CountryCode_GA" )
                ->Enum<AdminModels::CountryCode::CountryCodeGM>( "PlayFabAdmin_CountryCode_GM" )
                ->Enum<AdminModels::CountryCode::CountryCodeGE>( "PlayFabAdmin_CountryCode_GE" )
                ->Enum<AdminModels::CountryCode::CountryCodeDE>( "PlayFabAdmin_CountryCode_DE" )
                ->Enum<AdminModels::CountryCode::CountryCodeGH>( "PlayFabAdmin_CountryCode_GH" )
                ->Enum<AdminModels::CountryCode::CountryCodeGI>( "PlayFabAdmin_CountryCode_GI" )
                ->Enum<AdminModels::CountryCode::CountryCodeGR>( "PlayFabAdmin_CountryCode_GR" )
                ->Enum<AdminModels::CountryCode::CountryCodeGL>( "PlayFabAdmin_CountryCode_GL" )
                ->Enum<AdminModels::CountryCode::CountryCodeGD>( "PlayFabAdmin_CountryCode_GD" )
                ->Enum<AdminModels::CountryCode::CountryCodeGP>( "PlayFabAdmin_CountryCode_GP" )
                ->Enum<AdminModels::CountryCode::CountryCodeGU>( "PlayFabAdmin_CountryCode_GU" )
                ->Enum<AdminModels::CountryCode::CountryCodeGT>( "PlayFabAdmin_CountryCode_GT" )
                ->Enum<AdminModels::CountryCode::CountryCodeGG>( "PlayFabAdmin_CountryCode_GG" )
                ->Enum<AdminModels::CountryCode::CountryCodeGN>( "PlayFabAdmin_CountryCode_GN" )
                ->Enum<AdminModels::CountryCode::CountryCodeGW>( "PlayFabAdmin_CountryCode_GW" )
                ->Enum<AdminModels::CountryCode::CountryCodeGY>( "PlayFabAdmin_CountryCode_GY" )
                ->Enum<AdminModels::CountryCode::CountryCodeHT>( "PlayFabAdmin_CountryCode_HT" )
                ->Enum<AdminModels::CountryCode::CountryCodeHM>( "PlayFabAdmin_CountryCode_HM" )
                ->Enum<AdminModels::CountryCode::CountryCodeVA>( "PlayFabAdmin_CountryCode_VA" )
                ->Enum<AdminModels::CountryCode::CountryCodeHN>( "PlayFabAdmin_CountryCode_HN" )
                ->Enum<AdminModels::CountryCode::CountryCodeHK>( "PlayFabAdmin_CountryCode_HK" )
                ->Enum<AdminModels::CountryCode::CountryCodeHU>( "PlayFabAdmin_CountryCode_HU" )
                ->Enum<AdminModels::CountryCode::CountryCodeIS>( "PlayFabAdmin_CountryCode_IS" )
                ->Enum<AdminModels::CountryCode::CountryCodeIN>( "PlayFabAdmin_CountryCode_IN" )
                ->Enum<AdminModels::CountryCode::CountryCodeID>( "PlayFabAdmin_CountryCode_ID" )
                ->Enum<AdminModels::CountryCode::CountryCodeIR>( "PlayFabAdmin_CountryCode_IR" )
                ->Enum<AdminModels::CountryCode::CountryCodeIQ>( "PlayFabAdmin_CountryCode_IQ" )
                ->Enum<AdminModels::CountryCode::CountryCodeIE>( "PlayFabAdmin_CountryCode_IE" )
                ->Enum<AdminModels::CountryCode::CountryCodeIM>( "PlayFabAdmin_CountryCode_IM" )
                ->Enum<AdminModels::CountryCode::CountryCodeIL>( "PlayFabAdmin_CountryCode_IL" )
                ->Enum<AdminModels::CountryCode::CountryCodeIT>( "PlayFabAdmin_CountryCode_IT" )
                ->Enum<AdminModels::CountryCode::CountryCodeJM>( "PlayFabAdmin_CountryCode_JM" )
                ->Enum<AdminModels::CountryCode::CountryCodeJP>( "PlayFabAdmin_CountryCode_JP" )
                ->Enum<AdminModels::CountryCode::CountryCodeJE>( "PlayFabAdmin_CountryCode_JE" )
                ->Enum<AdminModels::CountryCode::CountryCodeJO>( "PlayFabAdmin_CountryCode_JO" )
                ->Enum<AdminModels::CountryCode::CountryCodeKZ>( "PlayFabAdmin_CountryCode_KZ" )
                ->Enum<AdminModels::CountryCode::CountryCodeKE>( "PlayFabAdmin_CountryCode_KE" )
                ->Enum<AdminModels::CountryCode::CountryCodeKI>( "PlayFabAdmin_CountryCode_KI" )
                ->Enum<AdminModels::CountryCode::CountryCodeKP>( "PlayFabAdmin_CountryCode_KP" )
                ->Enum<AdminModels::CountryCode::CountryCodeKR>( "PlayFabAdmin_CountryCode_KR" )
                ->Enum<AdminModels::CountryCode::CountryCodeKW>( "PlayFabAdmin_CountryCode_KW" )
                ->Enum<AdminModels::CountryCode::CountryCodeKG>( "PlayFabAdmin_CountryCode_KG" )
                ->Enum<AdminModels::CountryCode::CountryCodeLA>( "PlayFabAdmin_CountryCode_LA" )
                ->Enum<AdminModels::CountryCode::CountryCodeLV>( "PlayFabAdmin_CountryCode_LV" )
                ->Enum<AdminModels::CountryCode::CountryCodeLB>( "PlayFabAdmin_CountryCode_LB" )
                ->Enum<AdminModels::CountryCode::CountryCodeLS>( "PlayFabAdmin_CountryCode_LS" )
                ->Enum<AdminModels::CountryCode::CountryCodeLR>( "PlayFabAdmin_CountryCode_LR" )
                ->Enum<AdminModels::CountryCode::CountryCodeLY>( "PlayFabAdmin_CountryCode_LY" )
                ->Enum<AdminModels::CountryCode::CountryCodeLI>( "PlayFabAdmin_CountryCode_LI" )
                ->Enum<AdminModels::CountryCode::CountryCodeLT>( "PlayFabAdmin_CountryCode_LT" )
                ->Enum<AdminModels::CountryCode::CountryCodeLU>( "PlayFabAdmin_CountryCode_LU" )
                ->Enum<AdminModels::CountryCode::CountryCodeMO>( "PlayFabAdmin_CountryCode_MO" )
                ->Enum<AdminModels::CountryCode::CountryCodeMK>( "PlayFabAdmin_CountryCode_MK" )
                ->Enum<AdminModels::CountryCode::CountryCodeMG>( "PlayFabAdmin_CountryCode_MG" )
                ->Enum<AdminModels::CountryCode::CountryCodeMW>( "PlayFabAdmin_CountryCode_MW" )
                ->Enum<AdminModels::CountryCode::CountryCodeMY>( "PlayFabAdmin_CountryCode_MY" )
                ->Enum<AdminModels::CountryCode::CountryCodeMV>( "PlayFabAdmin_CountryCode_MV" )
                ->Enum<AdminModels::CountryCode::CountryCodeML>( "PlayFabAdmin_CountryCode_ML" )
                ->Enum<AdminModels::CountryCode::CountryCodeMT>( "PlayFabAdmin_CountryCode_MT" )
                ->Enum<AdminModels::CountryCode::CountryCodeMH>( "PlayFabAdmin_CountryCode_MH" )
                ->Enum<AdminModels::CountryCode::CountryCodeMQ>( "PlayFabAdmin_CountryCode_MQ" )
                ->Enum<AdminModels::CountryCode::CountryCodeMR>( "PlayFabAdmin_CountryCode_MR" )
                ->Enum<AdminModels::CountryCode::CountryCodeMU>( "PlayFabAdmin_CountryCode_MU" )
                ->Enum<AdminModels::CountryCode::CountryCodeYT>( "PlayFabAdmin_CountryCode_YT" )
                ->Enum<AdminModels::CountryCode::CountryCodeMX>( "PlayFabAdmin_CountryCode_MX" )
                ->Enum<AdminModels::CountryCode::CountryCodeFM>( "PlayFabAdmin_CountryCode_FM" )
                ->Enum<AdminModels::CountryCode::CountryCodeMD>( "PlayFabAdmin_CountryCode_MD" )
                ->Enum<AdminModels::CountryCode::CountryCodeMC>( "PlayFabAdmin_CountryCode_MC" )
                ->Enum<AdminModels::CountryCode::CountryCodeMN>( "PlayFabAdmin_CountryCode_MN" )
                ->Enum<AdminModels::CountryCode::CountryCodeME>( "PlayFabAdmin_CountryCode_ME" )
                ->Enum<AdminModels::CountryCode::CountryCodeMS>( "PlayFabAdmin_CountryCode_MS" )
                ->Enum<AdminModels::CountryCode::CountryCodeMA>( "PlayFabAdmin_CountryCode_MA" )
                ->Enum<AdminModels::CountryCode::CountryCodeMZ>( "PlayFabAdmin_CountryCode_MZ" )
                ->Enum<AdminModels::CountryCode::CountryCodeMM>( "PlayFabAdmin_CountryCode_MM" )
                ->Enum<AdminModels::CountryCode::CountryCodeNA>( "PlayFabAdmin_CountryCode_NA" )
                ->Enum<AdminModels::CountryCode::CountryCodeNR>( "PlayFabAdmin_CountryCode_NR" )
                ->Enum<AdminModels::CountryCode::CountryCodeNP>( "PlayFabAdmin_CountryCode_NP" )
                ->Enum<AdminModels::CountryCode::CountryCodeNL>( "PlayFabAdmin_CountryCode_NL" )
                ->Enum<AdminModels::CountryCode::CountryCodeNC>( "PlayFabAdmin_CountryCode_NC" )
                ->Enum<AdminModels::CountryCode::CountryCodeNZ>( "PlayFabAdmin_CountryCode_NZ" )
                ->Enum<AdminModels::CountryCode::CountryCodeNI>( "PlayFabAdmin_CountryCode_NI" )
                ->Enum<AdminModels::CountryCode::CountryCodeNE>( "PlayFabAdmin_CountryCode_NE" )
                ->Enum<AdminModels::CountryCode::CountryCodeNG>( "PlayFabAdmin_CountryCode_NG" )
                ->Enum<AdminModels::CountryCode::CountryCodeNU>( "PlayFabAdmin_CountryCode_NU" )
                ->Enum<AdminModels::CountryCode::CountryCodeNF>( "PlayFabAdmin_CountryCode_NF" )
                ->Enum<AdminModels::CountryCode::CountryCodeMP>( "PlayFabAdmin_CountryCode_MP" )
                ->Enum<AdminModels::CountryCode::CountryCodeNO>( "PlayFabAdmin_CountryCode_NO" )
                ->Enum<AdminModels::CountryCode::CountryCodeOM>( "PlayFabAdmin_CountryCode_OM" )
                ->Enum<AdminModels::CountryCode::CountryCodePK>( "PlayFabAdmin_CountryCode_PK" )
                ->Enum<AdminModels::CountryCode::CountryCodePW>( "PlayFabAdmin_CountryCode_PW" )
                ->Enum<AdminModels::CountryCode::CountryCodePS>( "PlayFabAdmin_CountryCode_PS" )
                ->Enum<AdminModels::CountryCode::CountryCodePA>( "PlayFabAdmin_CountryCode_PA" )
                ->Enum<AdminModels::CountryCode::CountryCodePG>( "PlayFabAdmin_CountryCode_PG" )
                ->Enum<AdminModels::CountryCode::CountryCodePY>( "PlayFabAdmin_CountryCode_PY" )
                ->Enum<AdminModels::CountryCode::CountryCodePE>( "PlayFabAdmin_CountryCode_PE" )
                ->Enum<AdminModels::CountryCode::CountryCodePH>( "PlayFabAdmin_CountryCode_PH" )
                ->Enum<AdminModels::CountryCode::CountryCodePN>( "PlayFabAdmin_CountryCode_PN" )
                ->Enum<AdminModels::CountryCode::CountryCodePL>( "PlayFabAdmin_CountryCode_PL" )
                ->Enum<AdminModels::CountryCode::CountryCodePT>( "PlayFabAdmin_CountryCode_PT" )
                ->Enum<AdminModels::CountryCode::CountryCodePR>( "PlayFabAdmin_CountryCode_PR" )
                ->Enum<AdminModels::CountryCode::CountryCodeQA>( "PlayFabAdmin_CountryCode_QA" )
                ->Enum<AdminModels::CountryCode::CountryCodeRE>( "PlayFabAdmin_CountryCode_RE" )
                ->Enum<AdminModels::CountryCode::CountryCodeRO>( "PlayFabAdmin_CountryCode_RO" )
                ->Enum<AdminModels::CountryCode::CountryCodeRU>( "PlayFabAdmin_CountryCode_RU" )
                ->Enum<AdminModels::CountryCode::CountryCodeRW>( "PlayFabAdmin_CountryCode_RW" )
                ->Enum<AdminModels::CountryCode::CountryCodeBL>( "PlayFabAdmin_CountryCode_BL" )
                ->Enum<AdminModels::CountryCode::CountryCodeSH>( "PlayFabAdmin_CountryCode_SH" )
                ->Enum<AdminModels::CountryCode::CountryCodeKN>( "PlayFabAdmin_CountryCode_KN" )
                ->Enum<AdminModels::CountryCode::CountryCodeLC>( "PlayFabAdmin_CountryCode_LC" )
                ->Enum<AdminModels::CountryCode::CountryCodeMF>( "PlayFabAdmin_CountryCode_MF" )
                ->Enum<AdminModels::CountryCode::CountryCodePM>( "PlayFabAdmin_CountryCode_PM" )
                ->Enum<AdminModels::CountryCode::CountryCodeVC>( "PlayFabAdmin_CountryCode_VC" )
                ->Enum<AdminModels::CountryCode::CountryCodeWS>( "PlayFabAdmin_CountryCode_WS" )
                ->Enum<AdminModels::CountryCode::CountryCodeSM>( "PlayFabAdmin_CountryCode_SM" )
                ->Enum<AdminModels::CountryCode::CountryCodeST>( "PlayFabAdmin_CountryCode_ST" )
                ->Enum<AdminModels::CountryCode::CountryCodeSA>( "PlayFabAdmin_CountryCode_SA" )
                ->Enum<AdminModels::CountryCode::CountryCodeSN>( "PlayFabAdmin_CountryCode_SN" )
                ->Enum<AdminModels::CountryCode::CountryCodeRS>( "PlayFabAdmin_CountryCode_RS" )
                ->Enum<AdminModels::CountryCode::CountryCodeSC>( "PlayFabAdmin_CountryCode_SC" )
                ->Enum<AdminModels::CountryCode::CountryCodeSL>( "PlayFabAdmin_CountryCode_SL" )
                ->Enum<AdminModels::CountryCode::CountryCodeSG>( "PlayFabAdmin_CountryCode_SG" )
                ->Enum<AdminModels::CountryCode::CountryCodeSX>( "PlayFabAdmin_CountryCode_SX" )
                ->Enum<AdminModels::CountryCode::CountryCodeSK>( "PlayFabAdmin_CountryCode_SK" )
                ->Enum<AdminModels::CountryCode::CountryCodeSI>( "PlayFabAdmin_CountryCode_SI" )
                ->Enum<AdminModels::CountryCode::CountryCodeSB>( "PlayFabAdmin_CountryCode_SB" )
                ->Enum<AdminModels::CountryCode::CountryCodeSO>( "PlayFabAdmin_CountryCode_SO" )
                ->Enum<AdminModels::CountryCode::CountryCodeZA>( "PlayFabAdmin_CountryCode_ZA" )
                ->Enum<AdminModels::CountryCode::CountryCodeGS>( "PlayFabAdmin_CountryCode_GS" )
                ->Enum<AdminModels::CountryCode::CountryCodeSS>( "PlayFabAdmin_CountryCode_SS" )
                ->Enum<AdminModels::CountryCode::CountryCodeES>( "PlayFabAdmin_CountryCode_ES" )
                ->Enum<AdminModels::CountryCode::CountryCodeLK>( "PlayFabAdmin_CountryCode_LK" )
                ->Enum<AdminModels::CountryCode::CountryCodeSD>( "PlayFabAdmin_CountryCode_SD" )
                ->Enum<AdminModels::CountryCode::CountryCodeSR>( "PlayFabAdmin_CountryCode_SR" )
                ->Enum<AdminModels::CountryCode::CountryCodeSJ>( "PlayFabAdmin_CountryCode_SJ" )
                ->Enum<AdminModels::CountryCode::CountryCodeSZ>( "PlayFabAdmin_CountryCode_SZ" )
                ->Enum<AdminModels::CountryCode::CountryCodeSE>( "PlayFabAdmin_CountryCode_SE" )
                ->Enum<AdminModels::CountryCode::CountryCodeCH>( "PlayFabAdmin_CountryCode_CH" )
                ->Enum<AdminModels::CountryCode::CountryCodeSY>( "PlayFabAdmin_CountryCode_SY" )
                ->Enum<AdminModels::CountryCode::CountryCodeTW>( "PlayFabAdmin_CountryCode_TW" )
                ->Enum<AdminModels::CountryCode::CountryCodeTJ>( "PlayFabAdmin_CountryCode_TJ" )
                ->Enum<AdminModels::CountryCode::CountryCodeTZ>( "PlayFabAdmin_CountryCode_TZ" )
                ->Enum<AdminModels::CountryCode::CountryCodeTH>( "PlayFabAdmin_CountryCode_TH" )
                ->Enum<AdminModels::CountryCode::CountryCodeTL>( "PlayFabAdmin_CountryCode_TL" )
                ->Enum<AdminModels::CountryCode::CountryCodeTG>( "PlayFabAdmin_CountryCode_TG" )
                ->Enum<AdminModels::CountryCode::CountryCodeTK>( "PlayFabAdmin_CountryCode_TK" )
                ->Enum<AdminModels::CountryCode::CountryCodeTO>( "PlayFabAdmin_CountryCode_TO" )
                ->Enum<AdminModels::CountryCode::CountryCodeTT>( "PlayFabAdmin_CountryCode_TT" )
                ->Enum<AdminModels::CountryCode::CountryCodeTN>( "PlayFabAdmin_CountryCode_TN" )
                ->Enum<AdminModels::CountryCode::CountryCodeTR>( "PlayFabAdmin_CountryCode_TR" )
                ->Enum<AdminModels::CountryCode::CountryCodeTM>( "PlayFabAdmin_CountryCode_TM" )
                ->Enum<AdminModels::CountryCode::CountryCodeTC>( "PlayFabAdmin_CountryCode_TC" )
                ->Enum<AdminModels::CountryCode::CountryCodeTV>( "PlayFabAdmin_CountryCode_TV" )
                ->Enum<AdminModels::CountryCode::CountryCodeUG>( "PlayFabAdmin_CountryCode_UG" )
                ->Enum<AdminModels::CountryCode::CountryCodeUA>( "PlayFabAdmin_CountryCode_UA" )
                ->Enum<AdminModels::CountryCode::CountryCodeAE>( "PlayFabAdmin_CountryCode_AE" )
                ->Enum<AdminModels::CountryCode::CountryCodeGB>( "PlayFabAdmin_CountryCode_GB" )
                ->Enum<AdminModels::CountryCode::CountryCodeUS>( "PlayFabAdmin_CountryCode_US" )
                ->Enum<AdminModels::CountryCode::CountryCodeUM>( "PlayFabAdmin_CountryCode_UM" )
                ->Enum<AdminModels::CountryCode::CountryCodeUY>( "PlayFabAdmin_CountryCode_UY" )
                ->Enum<AdminModels::CountryCode::CountryCodeUZ>( "PlayFabAdmin_CountryCode_UZ" )
                ->Enum<AdminModels::CountryCode::CountryCodeVU>( "PlayFabAdmin_CountryCode_VU" )
                ->Enum<AdminModels::CountryCode::CountryCodeVE>( "PlayFabAdmin_CountryCode_VE" )
                ->Enum<AdminModels::CountryCode::CountryCodeVN>( "PlayFabAdmin_CountryCode_VN" )
                ->Enum<AdminModels::CountryCode::CountryCodeVG>( "PlayFabAdmin_CountryCode_VG" )
                ->Enum<AdminModels::CountryCode::CountryCodeVI>( "PlayFabAdmin_CountryCode_VI" )
                ->Enum<AdminModels::CountryCode::CountryCodeWF>( "PlayFabAdmin_CountryCode_WF" )
                ->Enum<AdminModels::CountryCode::CountryCodeEH>( "PlayFabAdmin_CountryCode_EH" )
                ->Enum<AdminModels::CountryCode::CountryCodeYE>( "PlayFabAdmin_CountryCode_YE" )
                ->Enum<AdminModels::CountryCode::CountryCodeZM>( "PlayFabAdmin_CountryCode_ZM" )
                ->Enum<AdminModels::CountryCode::CountryCodeZW>( "PlayFabAdmin_CountryCode_ZW" )
            ;
            behaviorContext 
                ->Enum<AdminModels::StatisticResetIntervalOption::StatisticResetIntervalOptionNever>( "PlayFabAdmin_StatisticResetIntervalOption_Never" )
                ->Enum<AdminModels::StatisticResetIntervalOption::StatisticResetIntervalOptionHour>( "PlayFabAdmin_StatisticResetIntervalOption_Hour" )
                ->Enum<AdminModels::StatisticResetIntervalOption::StatisticResetIntervalOptionDay>( "PlayFabAdmin_StatisticResetIntervalOption_Day" )
                ->Enum<AdminModels::StatisticResetIntervalOption::StatisticResetIntervalOptionWeek>( "PlayFabAdmin_StatisticResetIntervalOption_Week" )
                ->Enum<AdminModels::StatisticResetIntervalOption::StatisticResetIntervalOptionMonth>( "PlayFabAdmin_StatisticResetIntervalOption_Month" )
            ;
            behaviorContext 
                ->Enum<AdminModels::StatisticAggregationMethod::StatisticAggregationMethodLast>( "PlayFabAdmin_StatisticAggregationMethod_Last" )
                ->Enum<AdminModels::StatisticAggregationMethod::StatisticAggregationMethodMin>( "PlayFabAdmin_StatisticAggregationMethod_Min" )
                ->Enum<AdminModels::StatisticAggregationMethod::StatisticAggregationMethodMax>( "PlayFabAdmin_StatisticAggregationMethod_Max" )
                ->Enum<AdminModels::StatisticAggregationMethod::StatisticAggregationMethodSum>( "PlayFabAdmin_StatisticAggregationMethod_Sum" )
            ;
            behaviorContext 
                ->Enum<AdminModels::Currency::CurrencyAED>( "PlayFabAdmin_Currency_AED" )
                ->Enum<AdminModels::Currency::CurrencyAFN>( "PlayFabAdmin_Currency_AFN" )
                ->Enum<AdminModels::Currency::CurrencyALL>( "PlayFabAdmin_Currency_ALL" )
                ->Enum<AdminModels::Currency::CurrencyAMD>( "PlayFabAdmin_Currency_AMD" )
                ->Enum<AdminModels::Currency::CurrencyANG>( "PlayFabAdmin_Currency_ANG" )
                ->Enum<AdminModels::Currency::CurrencyAOA>( "PlayFabAdmin_Currency_AOA" )
                ->Enum<AdminModels::Currency::CurrencyARS>( "PlayFabAdmin_Currency_ARS" )
                ->Enum<AdminModels::Currency::CurrencyAUD>( "PlayFabAdmin_Currency_AUD" )
                ->Enum<AdminModels::Currency::CurrencyAWG>( "PlayFabAdmin_Currency_AWG" )
                ->Enum<AdminModels::Currency::CurrencyAZN>( "PlayFabAdmin_Currency_AZN" )
                ->Enum<AdminModels::Currency::CurrencyBAM>( "PlayFabAdmin_Currency_BAM" )
                ->Enum<AdminModels::Currency::CurrencyBBD>( "PlayFabAdmin_Currency_BBD" )
                ->Enum<AdminModels::Currency::CurrencyBDT>( "PlayFabAdmin_Currency_BDT" )
                ->Enum<AdminModels::Currency::CurrencyBGN>( "PlayFabAdmin_Currency_BGN" )
                ->Enum<AdminModels::Currency::CurrencyBHD>( "PlayFabAdmin_Currency_BHD" )
                ->Enum<AdminModels::Currency::CurrencyBIF>( "PlayFabAdmin_Currency_BIF" )
                ->Enum<AdminModels::Currency::CurrencyBMD>( "PlayFabAdmin_Currency_BMD" )
                ->Enum<AdminModels::Currency::CurrencyBND>( "PlayFabAdmin_Currency_BND" )
                ->Enum<AdminModels::Currency::CurrencyBOB>( "PlayFabAdmin_Currency_BOB" )
                ->Enum<AdminModels::Currency::CurrencyBRL>( "PlayFabAdmin_Currency_BRL" )
                ->Enum<AdminModels::Currency::CurrencyBSD>( "PlayFabAdmin_Currency_BSD" )
                ->Enum<AdminModels::Currency::CurrencyBTN>( "PlayFabAdmin_Currency_BTN" )
                ->Enum<AdminModels::Currency::CurrencyBWP>( "PlayFabAdmin_Currency_BWP" )
                ->Enum<AdminModels::Currency::CurrencyBYR>( "PlayFabAdmin_Currency_BYR" )
                ->Enum<AdminModels::Currency::CurrencyBZD>( "PlayFabAdmin_Currency_BZD" )
                ->Enum<AdminModels::Currency::CurrencyCAD>( "PlayFabAdmin_Currency_CAD" )
                ->Enum<AdminModels::Currency::CurrencyCDF>( "PlayFabAdmin_Currency_CDF" )
                ->Enum<AdminModels::Currency::CurrencyCHF>( "PlayFabAdmin_Currency_CHF" )
                ->Enum<AdminModels::Currency::CurrencyCLP>( "PlayFabAdmin_Currency_CLP" )
                ->Enum<AdminModels::Currency::CurrencyCNY>( "PlayFabAdmin_Currency_CNY" )
                ->Enum<AdminModels::Currency::CurrencyCOP>( "PlayFabAdmin_Currency_COP" )
                ->Enum<AdminModels::Currency::CurrencyCRC>( "PlayFabAdmin_Currency_CRC" )
                ->Enum<AdminModels::Currency::CurrencyCUC>( "PlayFabAdmin_Currency_CUC" )
                ->Enum<AdminModels::Currency::CurrencyCUP>( "PlayFabAdmin_Currency_CUP" )
                ->Enum<AdminModels::Currency::CurrencyCVE>( "PlayFabAdmin_Currency_CVE" )
                ->Enum<AdminModels::Currency::CurrencyCZK>( "PlayFabAdmin_Currency_CZK" )
                ->Enum<AdminModels::Currency::CurrencyDJF>( "PlayFabAdmin_Currency_DJF" )
                ->Enum<AdminModels::Currency::CurrencyDKK>( "PlayFabAdmin_Currency_DKK" )
                ->Enum<AdminModels::Currency::CurrencyDOP>( "PlayFabAdmin_Currency_DOP" )
                ->Enum<AdminModels::Currency::CurrencyDZD>( "PlayFabAdmin_Currency_DZD" )
                ->Enum<AdminModels::Currency::CurrencyEGP>( "PlayFabAdmin_Currency_EGP" )
                ->Enum<AdminModels::Currency::CurrencyERN>( "PlayFabAdmin_Currency_ERN" )
                ->Enum<AdminModels::Currency::CurrencyETB>( "PlayFabAdmin_Currency_ETB" )
                ->Enum<AdminModels::Currency::CurrencyEUR>( "PlayFabAdmin_Currency_EUR" )
                ->Enum<AdminModels::Currency::CurrencyFJD>( "PlayFabAdmin_Currency_FJD" )
                ->Enum<AdminModels::Currency::CurrencyFKP>( "PlayFabAdmin_Currency_FKP" )
                ->Enum<AdminModels::Currency::CurrencyGBP>( "PlayFabAdmin_Currency_GBP" )
                ->Enum<AdminModels::Currency::CurrencyGEL>( "PlayFabAdmin_Currency_GEL" )
                ->Enum<AdminModels::Currency::CurrencyGGP>( "PlayFabAdmin_Currency_GGP" )
                ->Enum<AdminModels::Currency::CurrencyGHS>( "PlayFabAdmin_Currency_GHS" )
                ->Enum<AdminModels::Currency::CurrencyGIP>( "PlayFabAdmin_Currency_GIP" )
                ->Enum<AdminModels::Currency::CurrencyGMD>( "PlayFabAdmin_Currency_GMD" )
                ->Enum<AdminModels::Currency::CurrencyGNF>( "PlayFabAdmin_Currency_GNF" )
                ->Enum<AdminModels::Currency::CurrencyGTQ>( "PlayFabAdmin_Currency_GTQ" )
                ->Enum<AdminModels::Currency::CurrencyGYD>( "PlayFabAdmin_Currency_GYD" )
                ->Enum<AdminModels::Currency::CurrencyHKD>( "PlayFabAdmin_Currency_HKD" )
                ->Enum<AdminModels::Currency::CurrencyHNL>( "PlayFabAdmin_Currency_HNL" )
                ->Enum<AdminModels::Currency::CurrencyHRK>( "PlayFabAdmin_Currency_HRK" )
                ->Enum<AdminModels::Currency::CurrencyHTG>( "PlayFabAdmin_Currency_HTG" )
                ->Enum<AdminModels::Currency::CurrencyHUF>( "PlayFabAdmin_Currency_HUF" )
                ->Enum<AdminModels::Currency::CurrencyIDR>( "PlayFabAdmin_Currency_IDR" )
                ->Enum<AdminModels::Currency::CurrencyILS>( "PlayFabAdmin_Currency_ILS" )
                ->Enum<AdminModels::Currency::CurrencyIMP>( "PlayFabAdmin_Currency_IMP" )
                ->Enum<AdminModels::Currency::CurrencyINR>( "PlayFabAdmin_Currency_INR" )
                ->Enum<AdminModels::Currency::CurrencyIQD>( "PlayFabAdmin_Currency_IQD" )
                ->Enum<AdminModels::Currency::CurrencyIRR>( "PlayFabAdmin_Currency_IRR" )
                ->Enum<AdminModels::Currency::CurrencyISK>( "PlayFabAdmin_Currency_ISK" )
                ->Enum<AdminModels::Currency::CurrencyJEP>( "PlayFabAdmin_Currency_JEP" )
                ->Enum<AdminModels::Currency::CurrencyJMD>( "PlayFabAdmin_Currency_JMD" )
                ->Enum<AdminModels::Currency::CurrencyJOD>( "PlayFabAdmin_Currency_JOD" )
                ->Enum<AdminModels::Currency::CurrencyJPY>( "PlayFabAdmin_Currency_JPY" )
                ->Enum<AdminModels::Currency::CurrencyKES>( "PlayFabAdmin_Currency_KES" )
                ->Enum<AdminModels::Currency::CurrencyKGS>( "PlayFabAdmin_Currency_KGS" )
                ->Enum<AdminModels::Currency::CurrencyKHR>( "PlayFabAdmin_Currency_KHR" )
                ->Enum<AdminModels::Currency::CurrencyKMF>( "PlayFabAdmin_Currency_KMF" )
                ->Enum<AdminModels::Currency::CurrencyKPW>( "PlayFabAdmin_Currency_KPW" )
                ->Enum<AdminModels::Currency::CurrencyKRW>( "PlayFabAdmin_Currency_KRW" )
                ->Enum<AdminModels::Currency::CurrencyKWD>( "PlayFabAdmin_Currency_KWD" )
                ->Enum<AdminModels::Currency::CurrencyKYD>( "PlayFabAdmin_Currency_KYD" )
                ->Enum<AdminModels::Currency::CurrencyKZT>( "PlayFabAdmin_Currency_KZT" )
                ->Enum<AdminModels::Currency::CurrencyLAK>( "PlayFabAdmin_Currency_LAK" )
                ->Enum<AdminModels::Currency::CurrencyLBP>( "PlayFabAdmin_Currency_LBP" )
                ->Enum<AdminModels::Currency::CurrencyLKR>( "PlayFabAdmin_Currency_LKR" )
                ->Enum<AdminModels::Currency::CurrencyLRD>( "PlayFabAdmin_Currency_LRD" )
                ->Enum<AdminModels::Currency::CurrencyLSL>( "PlayFabAdmin_Currency_LSL" )
                ->Enum<AdminModels::Currency::CurrencyLYD>( "PlayFabAdmin_Currency_LYD" )
                ->Enum<AdminModels::Currency::CurrencyMAD>( "PlayFabAdmin_Currency_MAD" )
                ->Enum<AdminModels::Currency::CurrencyMDL>( "PlayFabAdmin_Currency_MDL" )
                ->Enum<AdminModels::Currency::CurrencyMGA>( "PlayFabAdmin_Currency_MGA" )
                ->Enum<AdminModels::Currency::CurrencyMKD>( "PlayFabAdmin_Currency_MKD" )
                ->Enum<AdminModels::Currency::CurrencyMMK>( "PlayFabAdmin_Currency_MMK" )
                ->Enum<AdminModels::Currency::CurrencyMNT>( "PlayFabAdmin_Currency_MNT" )
                ->Enum<AdminModels::Currency::CurrencyMOP>( "PlayFabAdmin_Currency_MOP" )
                ->Enum<AdminModels::Currency::CurrencyMRO>( "PlayFabAdmin_Currency_MRO" )
                ->Enum<AdminModels::Currency::CurrencyMUR>( "PlayFabAdmin_Currency_MUR" )
                ->Enum<AdminModels::Currency::CurrencyMVR>( "PlayFabAdmin_Currency_MVR" )
                ->Enum<AdminModels::Currency::CurrencyMWK>( "PlayFabAdmin_Currency_MWK" )
                ->Enum<AdminModels::Currency::CurrencyMXN>( "PlayFabAdmin_Currency_MXN" )
                ->Enum<AdminModels::Currency::CurrencyMYR>( "PlayFabAdmin_Currency_MYR" )
                ->Enum<AdminModels::Currency::CurrencyMZN>( "PlayFabAdmin_Currency_MZN" )
                ->Enum<AdminModels::Currency::CurrencyNAD>( "PlayFabAdmin_Currency_NAD" )
                ->Enum<AdminModels::Currency::CurrencyNGN>( "PlayFabAdmin_Currency_NGN" )
                ->Enum<AdminModels::Currency::CurrencyNIO>( "PlayFabAdmin_Currency_NIO" )
                ->Enum<AdminModels::Currency::CurrencyNOK>( "PlayFabAdmin_Currency_NOK" )
                ->Enum<AdminModels::Currency::CurrencyNPR>( "PlayFabAdmin_Currency_NPR" )
                ->Enum<AdminModels::Currency::CurrencyNZD>( "PlayFabAdmin_Currency_NZD" )
                ->Enum<AdminModels::Currency::CurrencyOMR>( "PlayFabAdmin_Currency_OMR" )
                ->Enum<AdminModels::Currency::CurrencyPAB>( "PlayFabAdmin_Currency_PAB" )
                ->Enum<AdminModels::Currency::CurrencyPEN>( "PlayFabAdmin_Currency_PEN" )
                ->Enum<AdminModels::Currency::CurrencyPGK>( "PlayFabAdmin_Currency_PGK" )
                ->Enum<AdminModels::Currency::CurrencyPHP>( "PlayFabAdmin_Currency_PHP" )
                ->Enum<AdminModels::Currency::CurrencyPKR>( "PlayFabAdmin_Currency_PKR" )
                ->Enum<AdminModels::Currency::CurrencyPLN>( "PlayFabAdmin_Currency_PLN" )
                ->Enum<AdminModels::Currency::CurrencyPYG>( "PlayFabAdmin_Currency_PYG" )
                ->Enum<AdminModels::Currency::CurrencyQAR>( "PlayFabAdmin_Currency_QAR" )
                ->Enum<AdminModels::Currency::CurrencyRON>( "PlayFabAdmin_Currency_RON" )
                ->Enum<AdminModels::Currency::CurrencyRSD>( "PlayFabAdmin_Currency_RSD" )
                ->Enum<AdminModels::Currency::CurrencyRUB>( "PlayFabAdmin_Currency_RUB" )
                ->Enum<AdminModels::Currency::CurrencyRWF>( "PlayFabAdmin_Currency_RWF" )
                ->Enum<AdminModels::Currency::CurrencySAR>( "PlayFabAdmin_Currency_SAR" )
                ->Enum<AdminModels::Currency::CurrencySBD>( "PlayFabAdmin_Currency_SBD" )
                ->Enum<AdminModels::Currency::CurrencySCR>( "PlayFabAdmin_Currency_SCR" )
                ->Enum<AdminModels::Currency::CurrencySDG>( "PlayFabAdmin_Currency_SDG" )
                ->Enum<AdminModels::Currency::CurrencySEK>( "PlayFabAdmin_Currency_SEK" )
                ->Enum<AdminModels::Currency::CurrencySGD>( "PlayFabAdmin_Currency_SGD" )
                ->Enum<AdminModels::Currency::CurrencySHP>( "PlayFabAdmin_Currency_SHP" )
                ->Enum<AdminModels::Currency::CurrencySLL>( "PlayFabAdmin_Currency_SLL" )
                ->Enum<AdminModels::Currency::CurrencySOS>( "PlayFabAdmin_Currency_SOS" )
                ->Enum<AdminModels::Currency::CurrencySPL>( "PlayFabAdmin_Currency_SPL" )
                ->Enum<AdminModels::Currency::CurrencySRD>( "PlayFabAdmin_Currency_SRD" )
                ->Enum<AdminModels::Currency::CurrencySTD>( "PlayFabAdmin_Currency_STD" )
                ->Enum<AdminModels::Currency::CurrencySVC>( "PlayFabAdmin_Currency_SVC" )
                ->Enum<AdminModels::Currency::CurrencySYP>( "PlayFabAdmin_Currency_SYP" )
                ->Enum<AdminModels::Currency::CurrencySZL>( "PlayFabAdmin_Currency_SZL" )
                ->Enum<AdminModels::Currency::CurrencyTHB>( "PlayFabAdmin_Currency_THB" )
                ->Enum<AdminModels::Currency::CurrencyTJS>( "PlayFabAdmin_Currency_TJS" )
                ->Enum<AdminModels::Currency::CurrencyTMT>( "PlayFabAdmin_Currency_TMT" )
                ->Enum<AdminModels::Currency::CurrencyTND>( "PlayFabAdmin_Currency_TND" )
                ->Enum<AdminModels::Currency::CurrencyTOP>( "PlayFabAdmin_Currency_TOP" )
                ->Enum<AdminModels::Currency::CurrencyTRY>( "PlayFabAdmin_Currency_TRY" )
                ->Enum<AdminModels::Currency::CurrencyTTD>( "PlayFabAdmin_Currency_TTD" )
                ->Enum<AdminModels::Currency::CurrencyTVD>( "PlayFabAdmin_Currency_TVD" )
                ->Enum<AdminModels::Currency::CurrencyTWD>( "PlayFabAdmin_Currency_TWD" )
                ->Enum<AdminModels::Currency::CurrencyTZS>( "PlayFabAdmin_Currency_TZS" )
                ->Enum<AdminModels::Currency::CurrencyUAH>( "PlayFabAdmin_Currency_UAH" )
                ->Enum<AdminModels::Currency::CurrencyUGX>( "PlayFabAdmin_Currency_UGX" )
                ->Enum<AdminModels::Currency::CurrencyUSD>( "PlayFabAdmin_Currency_USD" )
                ->Enum<AdminModels::Currency::CurrencyUYU>( "PlayFabAdmin_Currency_UYU" )
                ->Enum<AdminModels::Currency::CurrencyUZS>( "PlayFabAdmin_Currency_UZS" )
                ->Enum<AdminModels::Currency::CurrencyVEF>( "PlayFabAdmin_Currency_VEF" )
                ->Enum<AdminModels::Currency::CurrencyVND>( "PlayFabAdmin_Currency_VND" )
                ->Enum<AdminModels::Currency::CurrencyVUV>( "PlayFabAdmin_Currency_VUV" )
                ->Enum<AdminModels::Currency::CurrencyWST>( "PlayFabAdmin_Currency_WST" )
                ->Enum<AdminModels::Currency::CurrencyXAF>( "PlayFabAdmin_Currency_XAF" )
                ->Enum<AdminModels::Currency::CurrencyXCD>( "PlayFabAdmin_Currency_XCD" )
                ->Enum<AdminModels::Currency::CurrencyXDR>( "PlayFabAdmin_Currency_XDR" )
                ->Enum<AdminModels::Currency::CurrencyXOF>( "PlayFabAdmin_Currency_XOF" )
                ->Enum<AdminModels::Currency::CurrencyXPF>( "PlayFabAdmin_Currency_XPF" )
                ->Enum<AdminModels::Currency::CurrencyYER>( "PlayFabAdmin_Currency_YER" )
                ->Enum<AdminModels::Currency::CurrencyZAR>( "PlayFabAdmin_Currency_ZAR" )
                ->Enum<AdminModels::Currency::CurrencyZMW>( "PlayFabAdmin_Currency_ZMW" )
                ->Enum<AdminModels::Currency::CurrencyZWD>( "PlayFabAdmin_Currency_ZWD" )
            ;
            behaviorContext 
                ->Enum<AdminModels::EffectType::EffectTypeAllow>( "PlayFabAdmin_EffectType_Allow" )
                ->Enum<AdminModels::EffectType::EffectTypeDeny>( "PlayFabAdmin_EffectType_Deny" )
            ;
            behaviorContext 
                ->Enum<AdminModels::LoginIdentityProvider::LoginIdentityProviderUnknown>( "PlayFabAdmin_LoginIdentityProvider_Unknown" )
                ->Enum<AdminModels::LoginIdentityProvider::LoginIdentityProviderPlayFab>( "PlayFabAdmin_LoginIdentityProvider_PlayFab" )
                ->Enum<AdminModels::LoginIdentityProvider::LoginIdentityProviderCustom>( "PlayFabAdmin_LoginIdentityProvider_Custom" )
                ->Enum<AdminModels::LoginIdentityProvider::LoginIdentityProviderGameCenter>( "PlayFabAdmin_LoginIdentityProvider_GameCenter" )
                ->Enum<AdminModels::LoginIdentityProvider::LoginIdentityProviderGooglePlay>( "PlayFabAdmin_LoginIdentityProvider_GooglePlay" )
                ->Enum<AdminModels::LoginIdentityProvider::LoginIdentityProviderSteam>( "PlayFabAdmin_LoginIdentityProvider_Steam" )
                ->Enum<AdminModels::LoginIdentityProvider::LoginIdentityProviderXBoxLive>( "PlayFabAdmin_LoginIdentityProvider_XBoxLive" )
                ->Enum<AdminModels::LoginIdentityProvider::LoginIdentityProviderPSN>( "PlayFabAdmin_LoginIdentityProvider_PSN" )
                ->Enum<AdminModels::LoginIdentityProvider::LoginIdentityProviderKongregate>( "PlayFabAdmin_LoginIdentityProvider_Kongregate" )
                ->Enum<AdminModels::LoginIdentityProvider::LoginIdentityProviderFacebook>( "PlayFabAdmin_LoginIdentityProvider_Facebook" )
                ->Enum<AdminModels::LoginIdentityProvider::LoginIdentityProviderIOSDevice>( "PlayFabAdmin_LoginIdentityProvider_IOSDevice" )
                ->Enum<AdminModels::LoginIdentityProvider::LoginIdentityProviderAndroidDevice>( "PlayFabAdmin_LoginIdentityProvider_AndroidDevice" )
                ->Enum<AdminModels::LoginIdentityProvider::LoginIdentityProviderTwitch>( "PlayFabAdmin_LoginIdentityProvider_Twitch" )
                ->Enum<AdminModels::LoginIdentityProvider::LoginIdentityProviderWindowsHello>( "PlayFabAdmin_LoginIdentityProvider_WindowsHello" )
            ;
            behaviorContext 
                ->Enum<AdminModels::PushNotificationPlatform::PushNotificationPlatformApplePushNotificationService>( "PlayFabAdmin_PushNotificationPlatform_ApplePushNotificationService" )
                ->Enum<AdminModels::PushNotificationPlatform::PushNotificationPlatformGoogleCloudMessaging>( "PlayFabAdmin_PushNotificationPlatform_GoogleCloudMessaging" )
            ;
            behaviorContext 
                ->Enum<AdminModels::StatisticVersionStatus::StatisticVersionStatusActive>( "PlayFabAdmin_StatisticVersionStatus_Active" )
                ->Enum<AdminModels::StatisticVersionStatus::StatisticVersionStatusSnapshotPending>( "PlayFabAdmin_StatisticVersionStatus_SnapshotPending" )
                ->Enum<AdminModels::StatisticVersionStatus::StatisticVersionStatusSnapshot>( "PlayFabAdmin_StatisticVersionStatus_Snapshot" )
                ->Enum<AdminModels::StatisticVersionStatus::StatisticVersionStatusArchivalPending>( "PlayFabAdmin_StatisticVersionStatus_ArchivalPending" )
                ->Enum<AdminModels::StatisticVersionStatus::StatisticVersionStatusArchived>( "PlayFabAdmin_StatisticVersionStatus_Archived" )
            ;
            behaviorContext 
                ->Enum<AdminModels::ResultTableNodeType::ResultTableNodeTypeItemId>( "PlayFabAdmin_ResultTableNodeType_ItemId" )
                ->Enum<AdminModels::ResultTableNodeType::ResultTableNodeTypeTableId>( "PlayFabAdmin_ResultTableNodeType_TableId" )
            ;
            behaviorContext 
                ->Enum<AdminModels::SourceType::SourceTypeAdmin>( "PlayFabAdmin_SourceType_Admin" )
                ->Enum<AdminModels::SourceType::SourceTypeBackEnd>( "PlayFabAdmin_SourceType_BackEnd" )
                ->Enum<AdminModels::SourceType::SourceTypeGameClient>( "PlayFabAdmin_SourceType_GameClient" )
                ->Enum<AdminModels::SourceType::SourceTypeGameServer>( "PlayFabAdmin_SourceType_GameServer" )
                ->Enum<AdminModels::SourceType::SourceTypePartner>( "PlayFabAdmin_SourceType_Partner" )
            ;
            behaviorContext 
                ->Enum<AdminModels::ScheduledTaskType::ScheduledTaskTypeCloudScript>( "PlayFabAdmin_ScheduledTaskType_CloudScript" )
                ->Enum<AdminModels::ScheduledTaskType::ScheduledTaskTypeActionsOnPlayerSegment>( "PlayFabAdmin_ScheduledTaskType_ActionsOnPlayerSegment" )
            ;
            behaviorContext 
                ->Enum<AdminModels::UserDataPermission::UserDataPermissionPrivate>( "PlayFabAdmin_UserDataPermission_Private" )
                ->Enum<AdminModels::UserDataPermission::UserDataPermissionPublic>( "PlayFabAdmin_UserDataPermission_Public" )
            ;
            behaviorContext 
                ->Enum<AdminModels::UserOrigination::UserOriginationOrganic>( "PlayFabAdmin_UserOrigination_Organic" )
                ->Enum<AdminModels::UserOrigination::UserOriginationSteam>( "PlayFabAdmin_UserOrigination_Steam" )
                ->Enum<AdminModels::UserOrigination::UserOriginationGoogle>( "PlayFabAdmin_UserOrigination_Google" )
                ->Enum<AdminModels::UserOrigination::UserOriginationAmazon>( "PlayFabAdmin_UserOrigination_Amazon" )
                ->Enum<AdminModels::UserOrigination::UserOriginationFacebook>( "PlayFabAdmin_UserOrigination_Facebook" )
                ->Enum<AdminModels::UserOrigination::UserOriginationKongregate>( "PlayFabAdmin_UserOrigination_Kongregate" )
                ->Enum<AdminModels::UserOrigination::UserOriginationGamersFirst>( "PlayFabAdmin_UserOrigination_GamersFirst" )
                ->Enum<AdminModels::UserOrigination::UserOriginationUnknown>( "PlayFabAdmin_UserOrigination_Unknown" )
                ->Enum<AdminModels::UserOrigination::UserOriginationIOS>( "PlayFabAdmin_UserOrigination_IOS" )
                ->Enum<AdminModels::UserOrigination::UserOriginationLoadTest>( "PlayFabAdmin_UserOrigination_LoadTest" )
                ->Enum<AdminModels::UserOrigination::UserOriginationAndroid>( "PlayFabAdmin_UserOrigination_Android" )
                ->Enum<AdminModels::UserOrigination::UserOriginationPSN>( "PlayFabAdmin_UserOrigination_PSN" )
                ->Enum<AdminModels::UserOrigination::UserOriginationGameCenter>( "PlayFabAdmin_UserOrigination_GameCenter" )
                ->Enum<AdminModels::UserOrigination::UserOriginationCustomId>( "PlayFabAdmin_UserOrigination_CustomId" )
                ->Enum<AdminModels::UserOrigination::UserOriginationXboxLive>( "PlayFabAdmin_UserOrigination_XboxLive" )
                ->Enum<AdminModels::UserOrigination::UserOriginationParse>( "PlayFabAdmin_UserOrigination_Parse" )
                ->Enum<AdminModels::UserOrigination::UserOriginationTwitch>( "PlayFabAdmin_UserOrigination_Twitch" )
                ->Enum<AdminModels::UserOrigination::UserOriginationWindowsHello>( "PlayFabAdmin_UserOrigination_WindowsHello" )
            ;
            behaviorContext 
                ->Enum<AdminModels::TitleActivationStatus::TitleActivationStatusNone>( "PlayFabAdmin_TitleActivationStatus_None" )
                ->Enum<AdminModels::TitleActivationStatus::TitleActivationStatusActivatedTitleKey>( "PlayFabAdmin_TitleActivationStatus_ActivatedTitleKey" )
                ->Enum<AdminModels::TitleActivationStatus::TitleActivationStatusPendingSteam>( "PlayFabAdmin_TitleActivationStatus_PendingSteam" )
                ->Enum<AdminModels::TitleActivationStatus::TitleActivationStatusActivatedSteam>( "PlayFabAdmin_TitleActivationStatus_ActivatedSteam" )
                ->Enum<AdminModels::TitleActivationStatus::TitleActivationStatusRevokedSteam>( "PlayFabAdmin_TitleActivationStatus_RevokedSteam" )
            ;
            behaviorContext 
                ->Enum<AdminModels::PushSetupPlatform::PushSetupPlatformGCM>( "PlayFabAdmin_PushSetupPlatform_GCM" )
                ->Enum<AdminModels::PushSetupPlatform::PushSetupPlatformAPNS>( "PlayFabAdmin_PushSetupPlatform_APNS" )
                ->Enum<AdminModels::PushSetupPlatform::PushSetupPlatformAPNS_SANDBOX>( "PlayFabAdmin_PushSetupPlatform_APNS_SANDBOX" )
            ;
            behaviorContext 
                ->Enum<AdminModels::ResolutionOutcome::ResolutionOutcomeRevoke>( "PlayFabAdmin_ResolutionOutcome_Revoke" )
                ->Enum<AdminModels::ResolutionOutcome::ResolutionOutcomeReinstate>( "PlayFabAdmin_ResolutionOutcome_Reinstate" )
                ->Enum<AdminModels::ResolutionOutcome::ResolutionOutcomeManual>( "PlayFabAdmin_ResolutionOutcome_Manual" )
            ;
            behaviorContext 
                ->Enum<AdminModels::StatisticVersionArchivalStatus::StatisticVersionArchivalStatusNotScheduled>( "PlayFabAdmin_StatisticVersionArchivalStatus_NotScheduled" )
                ->Enum<AdminModels::StatisticVersionArchivalStatus::StatisticVersionArchivalStatusScheduled>( "PlayFabAdmin_StatisticVersionArchivalStatus_Scheduled" )
                ->Enum<AdminModels::StatisticVersionArchivalStatus::StatisticVersionArchivalStatusQueued>( "PlayFabAdmin_StatisticVersionArchivalStatus_Queued" )
                ->Enum<AdminModels::StatisticVersionArchivalStatus::StatisticVersionArchivalStatusInProgress>( "PlayFabAdmin_StatisticVersionArchivalStatus_InProgress" )
                ->Enum<AdminModels::StatisticVersionArchivalStatus::StatisticVersionArchivalStatusComplete>( "PlayFabAdmin_StatisticVersionArchivalStatus_Complete" )
            ;
    
            //-----------------------------------------------------------------------------------------------------
			// Reflect data models (structs/classes)
            //-----------------------------------------------------------------------------------------------------

			behaviorContext->Class<AdminModels::AbortTaskInstanceRequest>("PlayFabAdmin_AbortTaskInstanceRequest")
                ->Constructor() 
			    ->Property("TaskInstanceId", BehaviorValueProperty(&AdminModels::AbortTaskInstanceRequest::TaskInstanceId)) 
			;
		
			behaviorContext->Class<AdminModels::ActionsOnPlayersInSegmentTaskParameter>("PlayFabAdmin_ActionsOnPlayersInSegmentTaskParameter")
                ->Constructor() 
			    ->Property("SegmentId", BehaviorValueProperty(&AdminModels::ActionsOnPlayersInSegmentTaskParameter::SegmentId)) 
			    ->Property("ActionId", BehaviorValueProperty(&AdminModels::ActionsOnPlayersInSegmentTaskParameter::ActionId)) 
			;
		
			behaviorContext->Class<AdminModels::NameIdentifier>("PlayFabAdmin_NameIdentifier")
                ->Constructor() 
			    ->Property("Name", BehaviorValueProperty(&AdminModels::NameIdentifier::Name)) 
			    ->Property("Id", BehaviorValueProperty(&AdminModels::NameIdentifier::Id)) 
			;
		
			behaviorContext->Class<AdminModels::ActionsOnPlayersInSegmentTaskSummary>("PlayFabAdmin_ActionsOnPlayersInSegmentTaskSummary")
                ->Constructor() 
			    ->Property("TaskInstanceId", BehaviorValueProperty(&AdminModels::ActionsOnPlayersInSegmentTaskSummary::TaskInstanceId)) 
			    ->Property("TaskIdentifier", BehaviorValueProperty(&AdminModels::ActionsOnPlayersInSegmentTaskSummary::TaskIdentifier)) 
			    ->Property("StartedAt", BehaviorValueProperty(&AdminModels::ActionsOnPlayersInSegmentTaskSummary::StartedAt)) 
			    ->Property("CompletedAt", BehaviorValueProperty(&AdminModels::ActionsOnPlayersInSegmentTaskSummary::CompletedAt)) 
			    ->Property("Status", BehaviorValueProperty(&AdminModels::ActionsOnPlayersInSegmentTaskSummary::Status)) 
			    ->Property("PercentComplete", BehaviorValueProperty(&AdminModels::ActionsOnPlayersInSegmentTaskSummary::PercentComplete)) 
			    ->Property("EstimatedSecondsRemaining", BehaviorValueProperty(&AdminModels::ActionsOnPlayersInSegmentTaskSummary::EstimatedSecondsRemaining)) 
			    ->Property("ScheduledByUserId", BehaviorValueProperty(&AdminModels::ActionsOnPlayersInSegmentTaskSummary::ScheduledByUserId)) 
			    ->Property("ErrorMessage", BehaviorValueProperty(&AdminModels::ActionsOnPlayersInSegmentTaskSummary::ErrorMessage)) 
			    ->Property("ErrorWasFatal", BehaviorValueProperty(&AdminModels::ActionsOnPlayersInSegmentTaskSummary::ErrorWasFatal)) 
			    ->Property("TotalPlayersInSegment", BehaviorValueProperty(&AdminModels::ActionsOnPlayersInSegmentTaskSummary::TotalPlayersInSegment)) 
			    ->Property("TotalPlayersProcessed", BehaviorValueProperty(&AdminModels::ActionsOnPlayersInSegmentTaskSummary::TotalPlayersProcessed)) 
			;
		
			behaviorContext->Class<AdminModels::AdCampaignAttribution>("PlayFabAdmin_AdCampaignAttribution")
                ->Constructor() 
			    ->Property("Platform", BehaviorValueProperty(&AdminModels::AdCampaignAttribution::Platform)) 
			    ->Property("CampaignId", BehaviorValueProperty(&AdminModels::AdCampaignAttribution::CampaignId)) 
			    ->Property("AttributedAt", BehaviorValueProperty(&AdminModels::AdCampaignAttribution::AttributedAt)) 
			;
		
			behaviorContext->Class<AdminModels::AddNewsRequest>("PlayFabAdmin_AddNewsRequest")
                ->Constructor() 
			    ->Property("Timestamp", BehaviorValueProperty(&AdminModels::AddNewsRequest::Timestamp)) 
			    ->Property("Title", BehaviorValueProperty(&AdminModels::AddNewsRequest::Title)) 
			    ->Property("Body", BehaviorValueProperty(&AdminModels::AddNewsRequest::Body)) 
			;
		
			behaviorContext->Class<AdminModels::AddNewsResult>("PlayFabAdmin_AddNewsResult")
                ->Constructor() 
			    ->Property("NewsId", BehaviorValueProperty(&AdminModels::AddNewsResult::NewsId)) 
			;
		
			behaviorContext->Class<AdminModels::AddPlayerTagRequest>("PlayFabAdmin_AddPlayerTagRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&AdminModels::AddPlayerTagRequest::PlayFabId)) 
			    ->Property("TagName", BehaviorValueProperty(&AdminModels::AddPlayerTagRequest::TagName)) 
			;
		
			behaviorContext->Class<AdminModels::AddPlayerTagResult>("PlayFabAdmin_AddPlayerTagResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<AdminModels::AddServerBuildRequest>("PlayFabAdmin_AddServerBuildRequest")
                ->Constructor() 
			    ->Property("BuildId", BehaviorValueProperty(&AdminModels::AddServerBuildRequest::BuildId)) 
			    ->Property("CommandLineTemplate", BehaviorValueProperty(&AdminModels::AddServerBuildRequest::CommandLineTemplate)) 
			    ->Property("ExecutablePath", BehaviorValueProperty(&AdminModels::AddServerBuildRequest::ExecutablePath)) 
			    ->Property("Comment", BehaviorValueProperty(&AdminModels::AddServerBuildRequest::Comment)) 
			    ->Property("MaxGamesPerHost", BehaviorValueProperty(&AdminModels::AddServerBuildRequest::MaxGamesPerHost)) 
			    ->Property("MinFreeGameSlots", BehaviorValueProperty(&AdminModels::AddServerBuildRequest::MinFreeGameSlots)) 
			;
		
			behaviorContext->Class<AdminModels::AddServerBuildResult>("PlayFabAdmin_AddServerBuildResult")
                ->Constructor() 
			    ->Property("BuildId", BehaviorValueProperty(&AdminModels::AddServerBuildResult::BuildId)) 
			    ->Property("MaxGamesPerHost", BehaviorValueProperty(&AdminModels::AddServerBuildResult::MaxGamesPerHost)) 
			    ->Property("MinFreeGameSlots", BehaviorValueProperty(&AdminModels::AddServerBuildResult::MinFreeGameSlots)) 
			    ->Property("CommandLineTemplate", BehaviorValueProperty(&AdminModels::AddServerBuildResult::CommandLineTemplate)) 
			    ->Property("ExecutablePath", BehaviorValueProperty(&AdminModels::AddServerBuildResult::ExecutablePath)) 
			    ->Property("Comment", BehaviorValueProperty(&AdminModels::AddServerBuildResult::Comment)) 
			    ->Property("Timestamp", BehaviorValueProperty(&AdminModels::AddServerBuildResult::Timestamp)) 
			    ->Property("TitleId", BehaviorValueProperty(&AdminModels::AddServerBuildResult::TitleId)) 
			    ->Property("Status", BehaviorValueProperty(&AdminModels::AddServerBuildResult::Status)) 
			;
		
			behaviorContext->Class<AdminModels::AddUserVirtualCurrencyRequest>("PlayFabAdmin_AddUserVirtualCurrencyRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&AdminModels::AddUserVirtualCurrencyRequest::PlayFabId)) 
			    ->Property("VirtualCurrency", BehaviorValueProperty(&AdminModels::AddUserVirtualCurrencyRequest::VirtualCurrency)) 
			    ->Property("Amount", BehaviorValueProperty(&AdminModels::AddUserVirtualCurrencyRequest::Amount)) 
			;
		
			behaviorContext->Class<AdminModels::VirtualCurrencyData>("PlayFabAdmin_VirtualCurrencyData")
                ->Constructor() 
			    ->Property("CurrencyCode", BehaviorValueProperty(&AdminModels::VirtualCurrencyData::CurrencyCode)) 
			    ->Property("DisplayName", BehaviorValueProperty(&AdminModels::VirtualCurrencyData::DisplayName)) 
			    ->Property("InitialDeposit", BehaviorValueProperty(&AdminModels::VirtualCurrencyData::InitialDeposit)) 
			    ->Property("RechargeRate", BehaviorValueProperty(&AdminModels::VirtualCurrencyData::RechargeRate)) 
			    ->Property("RechargeMax", BehaviorValueProperty(&AdminModels::VirtualCurrencyData::RechargeMax)) 
			;
		
			behaviorContext->Class<AdminModels::AddVirtualCurrencyTypesRequest>("PlayFabAdmin_AddVirtualCurrencyTypesRequest")
                ->Constructor() 
			    ->Property("VirtualCurrencies", BehaviorValueProperty(&AdminModels::AddVirtualCurrencyTypesRequest::VirtualCurrencies)) 
			;
		
			behaviorContext->Class<AdminModels::ApiCondition>("PlayFabAdmin_ApiCondition")
                ->Constructor() 
			    ->Property("HasSignatureOrEncryption", BehaviorValueProperty(&AdminModels::ApiCondition::HasSignatureOrEncryption)) 
			;
		
			behaviorContext->Class<AdminModels::BanInfo>("PlayFabAdmin_BanInfo")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&AdminModels::BanInfo::PlayFabId)) 
			    ->Property("BanId", BehaviorValueProperty(&AdminModels::BanInfo::BanId)) 
			    ->Property("IPAddress", BehaviorValueProperty(&AdminModels::BanInfo::IPAddress)) 
			    ->Property("MACAddress", BehaviorValueProperty(&AdminModels::BanInfo::MACAddress)) 
			    ->Property("Created", BehaviorValueProperty(&AdminModels::BanInfo::Created)) 
			    ->Property("Expires", BehaviorValueProperty(&AdminModels::BanInfo::Expires)) 
			    ->Property("Reason", BehaviorValueProperty(&AdminModels::BanInfo::Reason)) 
			    ->Property("Active", BehaviorValueProperty(&AdminModels::BanInfo::Active)) 
			;
		
			behaviorContext->Class<AdminModels::BanRequest>("PlayFabAdmin_BanRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&AdminModels::BanRequest::PlayFabId)) 
			    ->Property("IPAddress", BehaviorValueProperty(&AdminModels::BanRequest::IPAddress)) 
			    ->Property("MACAddress", BehaviorValueProperty(&AdminModels::BanRequest::MACAddress)) 
			    ->Property("Reason", BehaviorValueProperty(&AdminModels::BanRequest::Reason)) 
			    ->Property("DurationInHours", BehaviorValueProperty(&AdminModels::BanRequest::DurationInHours)) 
			;
		
			behaviorContext->Class<AdminModels::BanUsersRequest>("PlayFabAdmin_BanUsersRequest")
                ->Constructor() 
			    ->Property("Bans", BehaviorValueProperty(&AdminModels::BanUsersRequest::Bans)) 
			;
		
			behaviorContext->Class<AdminModels::BanUsersResult>("PlayFabAdmin_BanUsersResult")
                ->Constructor() 
			    ->Property("BanData", BehaviorValueProperty(&AdminModels::BanUsersResult::BanData)) 
			;
		
			behaviorContext->Class<AdminModels::BlankResult>("PlayFabAdmin_BlankResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<AdminModels::CatalogItemConsumableInfo>("PlayFabAdmin_CatalogItemConsumableInfo")
                ->Constructor() 
			    ->Property("UsageCount", BehaviorValueProperty(&AdminModels::CatalogItemConsumableInfo::UsageCount)) 
			    ->Property("UsagePeriod", BehaviorValueProperty(&AdminModels::CatalogItemConsumableInfo::UsagePeriod)) 
			    ->Property("UsagePeriodGroup", BehaviorValueProperty(&AdminModels::CatalogItemConsumableInfo::UsagePeriodGroup)) 
			;
		
			behaviorContext->Class<AdminModels::CatalogItemContainerInfo>("PlayFabAdmin_CatalogItemContainerInfo")
                ->Constructor() 
			    ->Property("KeyItemId", BehaviorValueProperty(&AdminModels::CatalogItemContainerInfo::KeyItemId)) 
			    ->Property("ItemContents", BehaviorValueProperty(&AdminModels::CatalogItemContainerInfo::ItemContents)) 
			    ->Property("ResultTableContents", BehaviorValueProperty(&AdminModels::CatalogItemContainerInfo::ResultTableContents)) 
			;
		
			behaviorContext->Class<AdminModels::CatalogItemBundleInfo>("PlayFabAdmin_CatalogItemBundleInfo")
                ->Constructor() 
			    ->Property("BundledItems", BehaviorValueProperty(&AdminModels::CatalogItemBundleInfo::BundledItems)) 
			    ->Property("BundledResultTables", BehaviorValueProperty(&AdminModels::CatalogItemBundleInfo::BundledResultTables)) 
			;
		
			behaviorContext->Class<AdminModels::CatalogItem>("PlayFabAdmin_CatalogItem")
                ->Constructor() 
			    ->Property("ItemId", BehaviorValueProperty(&AdminModels::CatalogItem::ItemId)) 
			    ->Property("ItemClass", BehaviorValueProperty(&AdminModels::CatalogItem::ItemClass)) 
			    ->Property("CatalogVersion", BehaviorValueProperty(&AdminModels::CatalogItem::CatalogVersion)) 
			    ->Property("DisplayName", BehaviorValueProperty(&AdminModels::CatalogItem::DisplayName)) 
			    ->Property("Description", BehaviorValueProperty(&AdminModels::CatalogItem::Description)) 
			    ->Property("Tags", BehaviorValueProperty(&AdminModels::CatalogItem::Tags)) 
			    ->Property("CustomData", BehaviorValueProperty(&AdminModels::CatalogItem::CustomData)) 
			    ->Property("Consumable", BehaviorValueProperty(&AdminModels::CatalogItem::Consumable)) 
			    ->Property("Container", BehaviorValueProperty(&AdminModels::CatalogItem::Container)) 
			    ->Property("Bundle", BehaviorValueProperty(&AdminModels::CatalogItem::Bundle)) 
			    ->Property("CanBecomeCharacter", BehaviorValueProperty(&AdminModels::CatalogItem::CanBecomeCharacter)) 
			    ->Property("IsStackable", BehaviorValueProperty(&AdminModels::CatalogItem::IsStackable)) 
			    ->Property("IsTradable", BehaviorValueProperty(&AdminModels::CatalogItem::IsTradable)) 
			    ->Property("ItemImageUrl", BehaviorValueProperty(&AdminModels::CatalogItem::ItemImageUrl)) 
			    ->Property("IsLimitedEdition", BehaviorValueProperty(&AdminModels::CatalogItem::IsLimitedEdition)) 
			    ->Property("InitialLimitedEditionCount", BehaviorValueProperty(&AdminModels::CatalogItem::InitialLimitedEditionCount)) 
			;
		
			behaviorContext->Class<AdminModels::CloudScriptFile>("PlayFabAdmin_CloudScriptFile")
                ->Constructor() 
			    ->Property("Filename", BehaviorValueProperty(&AdminModels::CloudScriptFile::Filename)) 
			    ->Property("FileContents", BehaviorValueProperty(&AdminModels::CloudScriptFile::FileContents)) 
			;
		
			behaviorContext->Class<AdminModels::CloudScriptTaskParameter>("PlayFabAdmin_CloudScriptTaskParameter")
                ->Constructor() 
			    ->Property("FunctionName", BehaviorValueProperty(&AdminModels::CloudScriptTaskParameter::FunctionName)) 
			    ->Property("Argument", BehaviorValueProperty(&AdminModels::CloudScriptTaskParameter::Argument)) 
			;
		
			behaviorContext->Class<AdminModels::LogStatement>("PlayFabAdmin_LogStatement")
                ->Constructor() 
			    ->Property("Level", BehaviorValueProperty(&AdminModels::LogStatement::Level)) 
			    ->Property("Message", BehaviorValueProperty(&AdminModels::LogStatement::Message)) 
			    ->Property("Data", BehaviorValueProperty(&AdminModels::LogStatement::Data)) 
			;
		
			behaviorContext->Class<AdminModels::ScriptExecutionError>("PlayFabAdmin_ScriptExecutionError")
                ->Constructor() 
			    ->Property("Error", BehaviorValueProperty(&AdminModels::ScriptExecutionError::Error)) 
			    ->Property("Message", BehaviorValueProperty(&AdminModels::ScriptExecutionError::Message)) 
			    ->Property("StackTrace", BehaviorValueProperty(&AdminModels::ScriptExecutionError::StackTrace)) 
			;
		
			behaviorContext->Class<AdminModels::ExecuteCloudScriptResult>("PlayFabAdmin_ExecuteCloudScriptResult")
                ->Constructor() 
			    ->Property("FunctionName", BehaviorValueProperty(&AdminModels::ExecuteCloudScriptResult::FunctionName)) 
			    ->Property("Revision", BehaviorValueProperty(&AdminModels::ExecuteCloudScriptResult::Revision)) 
			    ->Property("FunctionResult", BehaviorValueProperty(&AdminModels::ExecuteCloudScriptResult::FunctionResult)) 
			    ->Property("FunctionResultTooLarge", BehaviorValueProperty(&AdminModels::ExecuteCloudScriptResult::FunctionResultTooLarge)) 
			    ->Property("Logs", BehaviorValueProperty(&AdminModels::ExecuteCloudScriptResult::Logs)) 
			    ->Property("LogsTooLarge", BehaviorValueProperty(&AdminModels::ExecuteCloudScriptResult::LogsTooLarge)) 
			    ->Property("ExecutionTimeSeconds", BehaviorValueProperty(&AdminModels::ExecuteCloudScriptResult::ExecutionTimeSeconds)) 
			    ->Property("ProcessorTimeSeconds", BehaviorValueProperty(&AdminModels::ExecuteCloudScriptResult::ProcessorTimeSeconds)) 
			    ->Property("MemoryConsumedBytes", BehaviorValueProperty(&AdminModels::ExecuteCloudScriptResult::MemoryConsumedBytes)) 
			    ->Property("APIRequestsIssued", BehaviorValueProperty(&AdminModels::ExecuteCloudScriptResult::APIRequestsIssued)) 
			    ->Property("HttpRequestsIssued", BehaviorValueProperty(&AdminModels::ExecuteCloudScriptResult::HttpRequestsIssued)) 
			    ->Property("Error", BehaviorValueProperty(&AdminModels::ExecuteCloudScriptResult::Error)) 
			;
		
			behaviorContext->Class<AdminModels::CloudScriptTaskSummary>("PlayFabAdmin_CloudScriptTaskSummary")
                ->Constructor() 
			    ->Property("TaskInstanceId", BehaviorValueProperty(&AdminModels::CloudScriptTaskSummary::TaskInstanceId)) 
			    ->Property("TaskIdentifier", BehaviorValueProperty(&AdminModels::CloudScriptTaskSummary::TaskIdentifier)) 
			    ->Property("StartedAt", BehaviorValueProperty(&AdminModels::CloudScriptTaskSummary::StartedAt)) 
			    ->Property("CompletedAt", BehaviorValueProperty(&AdminModels::CloudScriptTaskSummary::CompletedAt)) 
			    ->Property("Status", BehaviorValueProperty(&AdminModels::CloudScriptTaskSummary::Status)) 
			    ->Property("PercentComplete", BehaviorValueProperty(&AdminModels::CloudScriptTaskSummary::PercentComplete)) 
			    ->Property("EstimatedSecondsRemaining", BehaviorValueProperty(&AdminModels::CloudScriptTaskSummary::EstimatedSecondsRemaining)) 
			    ->Property("ScheduledByUserId", BehaviorValueProperty(&AdminModels::CloudScriptTaskSummary::ScheduledByUserId)) 
			    ->Property("Result", BehaviorValueProperty(&AdminModels::CloudScriptTaskSummary::Result)) 
			;
		
			behaviorContext->Class<AdminModels::CloudScriptVersionStatus>("PlayFabAdmin_CloudScriptVersionStatus")
                ->Constructor() 
			    ->Property("Version", BehaviorValueProperty(&AdminModels::CloudScriptVersionStatus::Version)) 
			    ->Property("PublishedRevision", BehaviorValueProperty(&AdminModels::CloudScriptVersionStatus::PublishedRevision)) 
			    ->Property("LatestRevision", BehaviorValueProperty(&AdminModels::CloudScriptVersionStatus::LatestRevision)) 
			;
		
			behaviorContext->Class<AdminModels::ContactEmailInfo>("PlayFabAdmin_ContactEmailInfo")
                ->Constructor() 
			    ->Property("Name", BehaviorValueProperty(&AdminModels::ContactEmailInfo::Name)) 
			    ->Property("EmailAddress", BehaviorValueProperty(&AdminModels::ContactEmailInfo::EmailAddress)) 
			    ->Property("VerificationStatus", BehaviorValueProperty(&AdminModels::ContactEmailInfo::VerificationStatus)) 
			;
		
			behaviorContext->Class<AdminModels::ContentInfo>("PlayFabAdmin_ContentInfo")
                ->Constructor() 
			    ->Property("Key", BehaviorValueProperty(&AdminModels::ContentInfo::Key)) 
			    ->Property("Size", BehaviorValueProperty(&AdminModels::ContentInfo::Size)) 
			    ->Property("LastModified", BehaviorValueProperty(&AdminModels::ContentInfo::LastModified)) 
			;
		
			behaviorContext->Class<AdminModels::CreateActionsOnPlayerSegmentTaskRequest>("PlayFabAdmin_CreateActionsOnPlayerSegmentTaskRequest")
                ->Constructor() 
			    ->Property("Name", BehaviorValueProperty(&AdminModels::CreateActionsOnPlayerSegmentTaskRequest::Name)) 
			    ->Property("Description", BehaviorValueProperty(&AdminModels::CreateActionsOnPlayerSegmentTaskRequest::Description)) 
			    ->Property("Schedule", BehaviorValueProperty(&AdminModels::CreateActionsOnPlayerSegmentTaskRequest::Schedule)) 
			    ->Property("IsActive", BehaviorValueProperty(&AdminModels::CreateActionsOnPlayerSegmentTaskRequest::IsActive)) 
			    ->Property("Parameter", BehaviorValueProperty(&AdminModels::CreateActionsOnPlayerSegmentTaskRequest::Parameter)) 
			;
		
			behaviorContext->Class<AdminModels::CreateCloudScriptTaskRequest>("PlayFabAdmin_CreateCloudScriptTaskRequest")
                ->Constructor() 
			    ->Property("Name", BehaviorValueProperty(&AdminModels::CreateCloudScriptTaskRequest::Name)) 
			    ->Property("Description", BehaviorValueProperty(&AdminModels::CreateCloudScriptTaskRequest::Description)) 
			    ->Property("Schedule", BehaviorValueProperty(&AdminModels::CreateCloudScriptTaskRequest::Schedule)) 
			    ->Property("IsActive", BehaviorValueProperty(&AdminModels::CreateCloudScriptTaskRequest::IsActive)) 
			    ->Property("Parameter", BehaviorValueProperty(&AdminModels::CreateCloudScriptTaskRequest::Parameter)) 
			;
		
			behaviorContext->Class<AdminModels::CreatePlayerSharedSecretRequest>("PlayFabAdmin_CreatePlayerSharedSecretRequest")
                ->Constructor() 
			    ->Property("FriendlyName", BehaviorValueProperty(&AdminModels::CreatePlayerSharedSecretRequest::FriendlyName)) 
			;
		
			behaviorContext->Class<AdminModels::CreatePlayerSharedSecretResult>("PlayFabAdmin_CreatePlayerSharedSecretResult")
                ->Constructor() 
			    ->Property("SecretKey", BehaviorValueProperty(&AdminModels::CreatePlayerSharedSecretResult::SecretKey)) 
			;
		
			behaviorContext->Class<AdminModels::CreatePlayerStatisticDefinitionRequest>("PlayFabAdmin_CreatePlayerStatisticDefinitionRequest")
                ->Constructor() 
			    ->Property("StatisticName", BehaviorValueProperty(&AdminModels::CreatePlayerStatisticDefinitionRequest::StatisticName)) 
			    ->Property("VersionChangeInterval", BehaviorValueProperty(&AdminModels::CreatePlayerStatisticDefinitionRequest::VersionChangeInterval)) 
			    ->Property("AggregationMethod", BehaviorValueProperty(&AdminModels::CreatePlayerStatisticDefinitionRequest::AggregationMethod)) 
			;
		
			behaviorContext->Class<AdminModels::PlayerStatisticDefinition>("PlayFabAdmin_PlayerStatisticDefinition")
                ->Constructor() 
			    ->Property("StatisticName", BehaviorValueProperty(&AdminModels::PlayerStatisticDefinition::StatisticName)) 
			    ->Property("CurrentVersion", BehaviorValueProperty(&AdminModels::PlayerStatisticDefinition::CurrentVersion)) 
			    ->Property("VersionChangeInterval", BehaviorValueProperty(&AdminModels::PlayerStatisticDefinition::VersionChangeInterval)) 
			    ->Property("AggregationMethod", BehaviorValueProperty(&AdminModels::PlayerStatisticDefinition::AggregationMethod)) 
			;
		
			behaviorContext->Class<AdminModels::CreatePlayerStatisticDefinitionResult>("PlayFabAdmin_CreatePlayerStatisticDefinitionResult")
                ->Constructor() 
			    ->Property("Statistic", BehaviorValueProperty(&AdminModels::CreatePlayerStatisticDefinitionResult::Statistic)) 
			;
		
			behaviorContext->Class<AdminModels::CreateTaskResult>("PlayFabAdmin_CreateTaskResult")
                ->Constructor() 
			    ->Property("TaskId", BehaviorValueProperty(&AdminModels::CreateTaskResult::TaskId)) 
			;
		
			behaviorContext->Class<AdminModels::DeleteContentRequest>("PlayFabAdmin_DeleteContentRequest")
                ->Constructor() 
			    ->Property("Key", BehaviorValueProperty(&AdminModels::DeleteContentRequest::Key)) 
			;
		
			behaviorContext->Class<AdminModels::DeletePlayerRequest>("PlayFabAdmin_DeletePlayerRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&AdminModels::DeletePlayerRequest::PlayFabId)) 
			;
		
			behaviorContext->Class<AdminModels::DeletePlayerResult>("PlayFabAdmin_DeletePlayerResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<AdminModels::DeletePlayerSharedSecretRequest>("PlayFabAdmin_DeletePlayerSharedSecretRequest")
                ->Constructor() 
			    ->Property("SecretKey", BehaviorValueProperty(&AdminModels::DeletePlayerSharedSecretRequest::SecretKey)) 
			;
		
			behaviorContext->Class<AdminModels::DeletePlayerSharedSecretResult>("PlayFabAdmin_DeletePlayerSharedSecretResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<AdminModels::DeleteStoreRequest>("PlayFabAdmin_DeleteStoreRequest")
                ->Constructor() 
			    ->Property("CatalogVersion", BehaviorValueProperty(&AdminModels::DeleteStoreRequest::CatalogVersion)) 
			    ->Property("StoreId", BehaviorValueProperty(&AdminModels::DeleteStoreRequest::StoreId)) 
			;
		
			behaviorContext->Class<AdminModels::DeleteStoreResult>("PlayFabAdmin_DeleteStoreResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<AdminModels::DeleteTaskRequest>("PlayFabAdmin_DeleteTaskRequest")
                ->Constructor() 
			    ->Property("Identifier", BehaviorValueProperty(&AdminModels::DeleteTaskRequest::Identifier)) 
			;
		
			behaviorContext->Class<AdminModels::DeleteUsersRequest>("PlayFabAdmin_DeleteUsersRequest")
                ->Constructor() 
			    ->Property("PlayFabIds", BehaviorValueProperty(&AdminModels::DeleteUsersRequest::PlayFabIds)) 
			    ->Property("TitleId", BehaviorValueProperty(&AdminModels::DeleteUsersRequest::TitleId)) 
			;
		
			behaviorContext->Class<AdminModels::DeleteUsersResult>("PlayFabAdmin_DeleteUsersResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<AdminModels::EmptyResult>("PlayFabAdmin_EmptyResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<AdminModels::GameModeInfo>("PlayFabAdmin_GameModeInfo")
                ->Constructor() 
			    ->Property("Gamemode", BehaviorValueProperty(&AdminModels::GameModeInfo::Gamemode)) 
			    ->Property("MinPlayerCount", BehaviorValueProperty(&AdminModels::GameModeInfo::MinPlayerCount)) 
			    ->Property("MaxPlayerCount", BehaviorValueProperty(&AdminModels::GameModeInfo::MaxPlayerCount)) 
			    ->Property("StartOpen", BehaviorValueProperty(&AdminModels::GameModeInfo::StartOpen)) 
			;
		
			behaviorContext->Class<AdminModels::GetActionGroupResult>("PlayFabAdmin_GetActionGroupResult")
                ->Constructor() 
			    ->Property("Name", BehaviorValueProperty(&AdminModels::GetActionGroupResult::Name)) 
			    ->Property("Id", BehaviorValueProperty(&AdminModels::GetActionGroupResult::Id)) 
			;
		
			behaviorContext->Class<AdminModels::GetActionsOnPlayersInSegmentTaskInstanceResult>("PlayFabAdmin_GetActionsOnPlayersInSegmentTaskInstanceResult")
                ->Constructor() 
			    ->Property("Summary", BehaviorValueProperty(&AdminModels::GetActionsOnPlayersInSegmentTaskInstanceResult::Summary)) 
			    ->Property("Parameter", BehaviorValueProperty(&AdminModels::GetActionsOnPlayersInSegmentTaskInstanceResult::Parameter)) 
			;
		
			behaviorContext->Class<AdminModels::GetAllActionGroupsRequest>("PlayFabAdmin_GetAllActionGroupsRequest")
                ->Constructor() 
			;
		
			behaviorContext->Class<AdminModels::GetAllActionGroupsResult>("PlayFabAdmin_GetAllActionGroupsResult")
                ->Constructor() 
			    ->Property("ActionGroups", BehaviorValueProperty(&AdminModels::GetAllActionGroupsResult::ActionGroups)) 
			;
		
			behaviorContext->Class<AdminModels::GetAllSegmentsRequest>("PlayFabAdmin_GetAllSegmentsRequest")
                ->Constructor() 
			;
		
			behaviorContext->Class<AdminModels::GetSegmentResult>("PlayFabAdmin_GetSegmentResult")
                ->Constructor() 
			    ->Property("Id", BehaviorValueProperty(&AdminModels::GetSegmentResult::Id)) 
			    ->Property("Name", BehaviorValueProperty(&AdminModels::GetSegmentResult::Name)) 
			    ->Property("ABTestParent", BehaviorValueProperty(&AdminModels::GetSegmentResult::ABTestParent)) 
			;
		
			behaviorContext->Class<AdminModels::GetAllSegmentsResult>("PlayFabAdmin_GetAllSegmentsResult")
                ->Constructor() 
			    ->Property("Segments", BehaviorValueProperty(&AdminModels::GetAllSegmentsResult::Segments)) 
			;
		
			behaviorContext->Class<AdminModels::GetCatalogItemsRequest>("PlayFabAdmin_GetCatalogItemsRequest")
                ->Constructor() 
			    ->Property("CatalogVersion", BehaviorValueProperty(&AdminModels::GetCatalogItemsRequest::CatalogVersion)) 
			;
		
			behaviorContext->Class<AdminModels::GetCatalogItemsResult>("PlayFabAdmin_GetCatalogItemsResult")
                ->Constructor() 
			    ->Property("Catalog", BehaviorValueProperty(&AdminModels::GetCatalogItemsResult::Catalog)) 
			;
		
			behaviorContext->Class<AdminModels::GetCloudScriptRevisionRequest>("PlayFabAdmin_GetCloudScriptRevisionRequest")
                ->Constructor() 
			    ->Property("Version", BehaviorValueProperty(&AdminModels::GetCloudScriptRevisionRequest::Version)) 
			    ->Property("Revision", BehaviorValueProperty(&AdminModels::GetCloudScriptRevisionRequest::Revision)) 
			;
		
			behaviorContext->Class<AdminModels::GetCloudScriptRevisionResult>("PlayFabAdmin_GetCloudScriptRevisionResult")
                ->Constructor() 
			    ->Property("Version", BehaviorValueProperty(&AdminModels::GetCloudScriptRevisionResult::Version)) 
			    ->Property("Revision", BehaviorValueProperty(&AdminModels::GetCloudScriptRevisionResult::Revision)) 
			    ->Property("CreatedAt", BehaviorValueProperty(&AdminModels::GetCloudScriptRevisionResult::CreatedAt)) 
			    ->Property("Files", BehaviorValueProperty(&AdminModels::GetCloudScriptRevisionResult::Files)) 
			    ->Property("IsPublished", BehaviorValueProperty(&AdminModels::GetCloudScriptRevisionResult::IsPublished)) 
			;
		
			behaviorContext->Class<AdminModels::GetCloudScriptTaskInstanceResult>("PlayFabAdmin_GetCloudScriptTaskInstanceResult")
                ->Constructor() 
			    ->Property("Summary", BehaviorValueProperty(&AdminModels::GetCloudScriptTaskInstanceResult::Summary)) 
			    ->Property("Parameter", BehaviorValueProperty(&AdminModels::GetCloudScriptTaskInstanceResult::Parameter)) 
			;
		
			behaviorContext->Class<AdminModels::GetCloudScriptVersionsRequest>("PlayFabAdmin_GetCloudScriptVersionsRequest")
                ->Constructor() 
			;
		
			behaviorContext->Class<AdminModels::GetCloudScriptVersionsResult>("PlayFabAdmin_GetCloudScriptVersionsResult")
                ->Constructor() 
			    ->Property("Versions", BehaviorValueProperty(&AdminModels::GetCloudScriptVersionsResult::Versions)) 
			;
		
			behaviorContext->Class<AdminModels::GetContentListRequest>("PlayFabAdmin_GetContentListRequest")
                ->Constructor() 
			    ->Property("Prefix", BehaviorValueProperty(&AdminModels::GetContentListRequest::Prefix)) 
			;
		
			behaviorContext->Class<AdminModels::GetContentListResult>("PlayFabAdmin_GetContentListResult")
                ->Constructor() 
			    ->Property("ItemCount", BehaviorValueProperty(&AdminModels::GetContentListResult::ItemCount)) 
			    ->Property("TotalSize", BehaviorValueProperty(&AdminModels::GetContentListResult::TotalSize)) 
			    ->Property("Contents", BehaviorValueProperty(&AdminModels::GetContentListResult::Contents)) 
			;
		
			behaviorContext->Class<AdminModels::GetContentUploadUrlRequest>("PlayFabAdmin_GetContentUploadUrlRequest")
                ->Constructor() 
			    ->Property("Key", BehaviorValueProperty(&AdminModels::GetContentUploadUrlRequest::Key)) 
			    ->Property("ContentType", BehaviorValueProperty(&AdminModels::GetContentUploadUrlRequest::ContentType)) 
			;
		
			behaviorContext->Class<AdminModels::GetContentUploadUrlResult>("PlayFabAdmin_GetContentUploadUrlResult")
                ->Constructor() 
			    ->Property("URL", BehaviorValueProperty(&AdminModels::GetContentUploadUrlResult::URL)) 
			;
		
			behaviorContext->Class<AdminModels::GetDataReportRequest>("PlayFabAdmin_GetDataReportRequest")
                ->Constructor() 
			    ->Property("ReportName", BehaviorValueProperty(&AdminModels::GetDataReportRequest::ReportName)) 
			    ->Property("Year", BehaviorValueProperty(&AdminModels::GetDataReportRequest::Year)) 
			    ->Property("Month", BehaviorValueProperty(&AdminModels::GetDataReportRequest::Month)) 
			    ->Property("Day", BehaviorValueProperty(&AdminModels::GetDataReportRequest::Day)) 
			;
		
			behaviorContext->Class<AdminModels::GetDataReportResult>("PlayFabAdmin_GetDataReportResult")
                ->Constructor() 
			    ->Property("DownloadUrl", BehaviorValueProperty(&AdminModels::GetDataReportResult::DownloadUrl)) 
			;
		
			behaviorContext->Class<AdminModels::GetMatchmakerGameInfoRequest>("PlayFabAdmin_GetMatchmakerGameInfoRequest")
                ->Constructor() 
			    ->Property("LobbyId", BehaviorValueProperty(&AdminModels::GetMatchmakerGameInfoRequest::LobbyId)) 
			;
		
			behaviorContext->Class<AdminModels::GetMatchmakerGameInfoResult>("PlayFabAdmin_GetMatchmakerGameInfoResult")
                ->Constructor() 
			    ->Property("LobbyId", BehaviorValueProperty(&AdminModels::GetMatchmakerGameInfoResult::LobbyId)) 
			    ->Property("TitleId", BehaviorValueProperty(&AdminModels::GetMatchmakerGameInfoResult::TitleId)) 
			    ->Property("StartTime", BehaviorValueProperty(&AdminModels::GetMatchmakerGameInfoResult::StartTime)) 
			    ->Property("EndTime", BehaviorValueProperty(&AdminModels::GetMatchmakerGameInfoResult::EndTime)) 
			    ->Property("Mode", BehaviorValueProperty(&AdminModels::GetMatchmakerGameInfoResult::Mode)) 
			    ->Property("BuildVersion", BehaviorValueProperty(&AdminModels::GetMatchmakerGameInfoResult::BuildVersion)) 
			    ->Property("pfRegion", BehaviorValueProperty(&AdminModels::GetMatchmakerGameInfoResult::pfRegion)) 
			    ->Property("Players", BehaviorValueProperty(&AdminModels::GetMatchmakerGameInfoResult::Players)) 
			    ->Property("ServerAddress", BehaviorValueProperty(&AdminModels::GetMatchmakerGameInfoResult::ServerAddress)) 
			    ->Property("ServerPort", BehaviorValueProperty(&AdminModels::GetMatchmakerGameInfoResult::ServerPort)) 
			;
		
			behaviorContext->Class<AdminModels::GetMatchmakerGameModesRequest>("PlayFabAdmin_GetMatchmakerGameModesRequest")
                ->Constructor() 
			    ->Property("BuildVersion", BehaviorValueProperty(&AdminModels::GetMatchmakerGameModesRequest::BuildVersion)) 
			;
		
			behaviorContext->Class<AdminModels::GetMatchmakerGameModesResult>("PlayFabAdmin_GetMatchmakerGameModesResult")
                ->Constructor() 
			    ->Property("GameModes", BehaviorValueProperty(&AdminModels::GetMatchmakerGameModesResult::GameModes)) 
			;
		
			behaviorContext->Class<AdminModels::GetPlayerSegmentsResult>("PlayFabAdmin_GetPlayerSegmentsResult")
                ->Constructor() 
			    ->Property("Segments", BehaviorValueProperty(&AdminModels::GetPlayerSegmentsResult::Segments)) 
			;
		
			behaviorContext->Class<AdminModels::GetPlayerSharedSecretsRequest>("PlayFabAdmin_GetPlayerSharedSecretsRequest")
                ->Constructor() 
			;
		
			behaviorContext->Class<AdminModels::SharedSecret>("PlayFabAdmin_SharedSecret")
                ->Constructor() 
			    ->Property("SecretKey", BehaviorValueProperty(&AdminModels::SharedSecret::SecretKey)) 
			    ->Property("FriendlyName", BehaviorValueProperty(&AdminModels::SharedSecret::FriendlyName)) 
			    ->Property("Disabled", BehaviorValueProperty(&AdminModels::SharedSecret::Disabled)) 
			;
		
			behaviorContext->Class<AdminModels::GetPlayerSharedSecretsResult>("PlayFabAdmin_GetPlayerSharedSecretsResult")
                ->Constructor() 
			    ->Property("SharedSecrets", BehaviorValueProperty(&AdminModels::GetPlayerSharedSecretsResult::SharedSecrets)) 
			;
		
			behaviorContext->Class<AdminModels::GetPlayersInSegmentRequest>("PlayFabAdmin_GetPlayersInSegmentRequest")
                ->Constructor() 
			    ->Property("SegmentId", BehaviorValueProperty(&AdminModels::GetPlayersInSegmentRequest::SegmentId)) 
			    ->Property("SecondsToLive", BehaviorValueProperty(&AdminModels::GetPlayersInSegmentRequest::SecondsToLive)) 
			    ->Property("MaxBatchSize", BehaviorValueProperty(&AdminModels::GetPlayersInSegmentRequest::MaxBatchSize)) 
			    ->Property("ContinuationToken", BehaviorValueProperty(&AdminModels::GetPlayersInSegmentRequest::ContinuationToken)) 
			;
		
			behaviorContext->Class<AdminModels::PlayerLocation>("PlayFabAdmin_PlayerLocation")
                ->Constructor() 
			    ->Property("pfContinentCode",
				    [](AdminModels::PlayerLocation* p) { return p->pfContinentCode; },
				    [](AdminModels::PlayerLocation* p, AdminModels::ContinentCode v) { p->pfContinentCode = v; })
			    ->Property("pfCountryCode",
				    [](AdminModels::PlayerLocation* p) { return p->pfCountryCode; },
				    [](AdminModels::PlayerLocation* p, AdminModels::CountryCode v) { p->pfCountryCode = v; })
			    ->Property("City", BehaviorValueProperty(&AdminModels::PlayerLocation::City)) 
			    ->Property("Latitude", BehaviorValueProperty(&AdminModels::PlayerLocation::Latitude)) 
			    ->Property("Longitude", BehaviorValueProperty(&AdminModels::PlayerLocation::Longitude)) 
			;
		
			behaviorContext->Class<AdminModels::PushNotificationRegistration>("PlayFabAdmin_PushNotificationRegistration")
                ->Constructor() 
			    ->Property("Platform", BehaviorValueProperty(&AdminModels::PushNotificationRegistration::Platform)) 
			    ->Property("NotificationEndpointARN", BehaviorValueProperty(&AdminModels::PushNotificationRegistration::NotificationEndpointARN)) 
			;
		
			behaviorContext->Class<AdminModels::PlayerLinkedAccount>("PlayFabAdmin_PlayerLinkedAccount")
                ->Constructor() 
			    ->Property("Platform", BehaviorValueProperty(&AdminModels::PlayerLinkedAccount::Platform)) 
			    ->Property("PlatformUserId", BehaviorValueProperty(&AdminModels::PlayerLinkedAccount::PlatformUserId)) 
			    ->Property("Username", BehaviorValueProperty(&AdminModels::PlayerLinkedAccount::Username)) 
			    ->Property("Email", BehaviorValueProperty(&AdminModels::PlayerLinkedAccount::Email)) 
			;
		
			behaviorContext->Class<AdminModels::PlayerStatistic>("PlayFabAdmin_PlayerStatistic")
                ->Constructor() 
			    ->Property("Id", BehaviorValueProperty(&AdminModels::PlayerStatistic::Id)) 
			    ->Property("StatisticVersion", BehaviorValueProperty(&AdminModels::PlayerStatistic::StatisticVersion)) 
			    ->Property("StatisticValue", BehaviorValueProperty(&AdminModels::PlayerStatistic::StatisticValue)) 
			    ->Property("Name", BehaviorValueProperty(&AdminModels::PlayerStatistic::Name)) 
			;
		
			behaviorContext->Class<AdminModels::PlayerProfile>("PlayFabAdmin_PlayerProfile")
                ->Constructor() 
			    ->Property("PlayerId", BehaviorValueProperty(&AdminModels::PlayerProfile::PlayerId)) 
			    ->Property("TitleId", BehaviorValueProperty(&AdminModels::PlayerProfile::TitleId)) 
			    ->Property("DisplayName", BehaviorValueProperty(&AdminModels::PlayerProfile::DisplayName)) 
			    ->Property("PublisherId", BehaviorValueProperty(&AdminModels::PlayerProfile::PublisherId)) 
			    ->Property("Origination", BehaviorValueProperty(&AdminModels::PlayerProfile::Origination)) 
			    ->Property("Created", BehaviorValueProperty(&AdminModels::PlayerProfile::Created)) 
			    ->Property("LastLogin", BehaviorValueProperty(&AdminModels::PlayerProfile::LastLogin)) 
			    ->Property("BannedUntil", BehaviorValueProperty(&AdminModels::PlayerProfile::BannedUntil)) 
			    ->Property("AvatarUrl", BehaviorValueProperty(&AdminModels::PlayerProfile::AvatarUrl)) 
			    ->Property("TotalValueToDateInUSD", BehaviorValueProperty(&AdminModels::PlayerProfile::TotalValueToDateInUSD)) 
			    ->Property("Tags", BehaviorValueProperty(&AdminModels::PlayerProfile::Tags)) 
			    ->Property("AdCampaignAttributions", BehaviorValueProperty(&AdminModels::PlayerProfile::AdCampaignAttributions)) 
			    ->Property("PushNotificationRegistrations", BehaviorValueProperty(&AdminModels::PlayerProfile::PushNotificationRegistrations)) 
			    ->Property("LinkedAccounts", BehaviorValueProperty(&AdminModels::PlayerProfile::LinkedAccounts)) 
			    ->Property("PlayerStatistics", BehaviorValueProperty(&AdminModels::PlayerProfile::PlayerStatistics)) 
			    ->Property("ContactEmailAddresses", BehaviorValueProperty(&AdminModels::PlayerProfile::ContactEmailAddresses)) 
			;
		
			behaviorContext->Class<AdminModels::GetPlayersInSegmentResult>("PlayFabAdmin_GetPlayersInSegmentResult")
                ->Constructor() 
			    ->Property("ProfilesInSegment", BehaviorValueProperty(&AdminModels::GetPlayersInSegmentResult::ProfilesInSegment)) 
			    ->Property("ContinuationToken", BehaviorValueProperty(&AdminModels::GetPlayersInSegmentResult::ContinuationToken)) 
			    ->Property("PlayerProfiles", BehaviorValueProperty(&AdminModels::GetPlayersInSegmentResult::PlayerProfiles)) 
			;
		
			behaviorContext->Class<AdminModels::GetPlayersSegmentsRequest>("PlayFabAdmin_GetPlayersSegmentsRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&AdminModels::GetPlayersSegmentsRequest::PlayFabId)) 
			;
		
			behaviorContext->Class<AdminModels::GetPlayerStatisticDefinitionsRequest>("PlayFabAdmin_GetPlayerStatisticDefinitionsRequest")
                ->Constructor() 
			;
		
			behaviorContext->Class<AdminModels::GetPlayerStatisticDefinitionsResult>("PlayFabAdmin_GetPlayerStatisticDefinitionsResult")
                ->Constructor() 
			    ->Property("Statistics", BehaviorValueProperty(&AdminModels::GetPlayerStatisticDefinitionsResult::Statistics)) 
			;
		
			behaviorContext->Class<AdminModels::GetPlayerStatisticVersionsRequest>("PlayFabAdmin_GetPlayerStatisticVersionsRequest")
                ->Constructor() 
			    ->Property("StatisticName", BehaviorValueProperty(&AdminModels::GetPlayerStatisticVersionsRequest::StatisticName)) 
			;
		
			behaviorContext->Class<AdminModels::PlayerStatisticVersion>("PlayFabAdmin_PlayerStatisticVersion")
                ->Constructor() 
			    ->Property("StatisticName", BehaviorValueProperty(&AdminModels::PlayerStatisticVersion::StatisticName)) 
			    ->Property("Version", BehaviorValueProperty(&AdminModels::PlayerStatisticVersion::Version)) 
			    ->Property("ScheduledActivationTime", BehaviorValueProperty(&AdminModels::PlayerStatisticVersion::ScheduledActivationTime)) 
			    ->Property("ActivationTime", BehaviorValueProperty(&AdminModels::PlayerStatisticVersion::ActivationTime)) 
			    ->Property("ScheduledDeactivationTime", BehaviorValueProperty(&AdminModels::PlayerStatisticVersion::ScheduledDeactivationTime)) 
			    ->Property("DeactivationTime", BehaviorValueProperty(&AdminModels::PlayerStatisticVersion::DeactivationTime)) 
			    ->Property("Status", BehaviorValueProperty(&AdminModels::PlayerStatisticVersion::Status)) 
			    ->Property("ArchiveDownloadUrl", BehaviorValueProperty(&AdminModels::PlayerStatisticVersion::ArchiveDownloadUrl)) 
			;
		
			behaviorContext->Class<AdminModels::GetPlayerStatisticVersionsResult>("PlayFabAdmin_GetPlayerStatisticVersionsResult")
                ->Constructor() 
			    ->Property("StatisticVersions", BehaviorValueProperty(&AdminModels::GetPlayerStatisticVersionsResult::StatisticVersions)) 
			;
		
			behaviorContext->Class<AdminModels::GetPlayerTagsRequest>("PlayFabAdmin_GetPlayerTagsRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&AdminModels::GetPlayerTagsRequest::PlayFabId)) 
			    ->Property("Namespace", BehaviorValueProperty(&AdminModels::GetPlayerTagsRequest::Namespace)) 
			;
		
			behaviorContext->Class<AdminModels::GetPlayerTagsResult>("PlayFabAdmin_GetPlayerTagsResult")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&AdminModels::GetPlayerTagsResult::PlayFabId)) 
			    ->Property("Tags", BehaviorValueProperty(&AdminModels::GetPlayerTagsResult::Tags)) 
			;
		
			behaviorContext->Class<AdminModels::GetPolicyRequest>("PlayFabAdmin_GetPolicyRequest")
                ->Constructor() 
			    ->Property("PolicyName", BehaviorValueProperty(&AdminModels::GetPolicyRequest::PolicyName)) 
			;
		
			behaviorContext->Class<AdminModels::PermissionStatement>("PlayFabAdmin_PermissionStatement")
                ->Constructor() 
			    ->Property("Resource", BehaviorValueProperty(&AdminModels::PermissionStatement::Resource)) 
			    ->Property("Action", BehaviorValueProperty(&AdminModels::PermissionStatement::Action)) 
			    ->Property("Effect",
				    [](AdminModels::PermissionStatement* p) { return p->Effect; },
				    [](AdminModels::PermissionStatement* p, AdminModels::EffectType v) { p->Effect = v; })
			    ->Property("Principal", BehaviorValueProperty(&AdminModels::PermissionStatement::Principal)) 
			    ->Property("Comment", BehaviorValueProperty(&AdminModels::PermissionStatement::Comment)) 
			    ->Property("ApiConditions", BehaviorValueProperty(&AdminModels::PermissionStatement::ApiConditions)) 
			;
		
			behaviorContext->Class<AdminModels::GetPolicyResponse>("PlayFabAdmin_GetPolicyResponse")
                ->Constructor() 
			    ->Property("PolicyName", BehaviorValueProperty(&AdminModels::GetPolicyResponse::PolicyName)) 
			    ->Property("Statements", BehaviorValueProperty(&AdminModels::GetPolicyResponse::Statements)) 
			;
		
			behaviorContext->Class<AdminModels::GetPublisherDataRequest>("PlayFabAdmin_GetPublisherDataRequest")
                ->Constructor() 
			    ->Property("Keys", BehaviorValueProperty(&AdminModels::GetPublisherDataRequest::Keys)) 
			;
		
			behaviorContext->Class<AdminModels::GetPublisherDataResult>("PlayFabAdmin_GetPublisherDataResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<AdminModels::GetRandomResultTablesRequest>("PlayFabAdmin_GetRandomResultTablesRequest")
                ->Constructor() 
			    ->Property("CatalogVersion", BehaviorValueProperty(&AdminModels::GetRandomResultTablesRequest::CatalogVersion)) 
			;
		
			behaviorContext->Class<AdminModels::ResultTableNode>("PlayFabAdmin_ResultTableNode")
                ->Constructor() 
			    ->Property("ResultItemType",
				    [](AdminModels::ResultTableNode* p) { return p->ResultItemType; },
				    [](AdminModels::ResultTableNode* p, AdminModels::ResultTableNodeType v) { p->ResultItemType = v; })
			    ->Property("ResultItem", BehaviorValueProperty(&AdminModels::ResultTableNode::ResultItem)) 
			    ->Property("Weight", BehaviorValueProperty(&AdminModels::ResultTableNode::Weight)) 
			;
		
			behaviorContext->Class<AdminModels::RandomResultTableListing>("PlayFabAdmin_RandomResultTableListing")
                ->Constructor() 
			    ->Property("CatalogVersion", BehaviorValueProperty(&AdminModels::RandomResultTableListing::CatalogVersion)) 
			    ->Property("TableId", BehaviorValueProperty(&AdminModels::RandomResultTableListing::TableId)) 
			    ->Property("Nodes", BehaviorValueProperty(&AdminModels::RandomResultTableListing::Nodes)) 
			;
		
			behaviorContext->Class<AdminModels::GetRandomResultTablesResult>("PlayFabAdmin_GetRandomResultTablesResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<AdminModels::GetServerBuildInfoRequest>("PlayFabAdmin_GetServerBuildInfoRequest")
                ->Constructor() 
			    ->Property("BuildId", BehaviorValueProperty(&AdminModels::GetServerBuildInfoRequest::BuildId)) 
			;
		
			behaviorContext->Class<AdminModels::GetServerBuildInfoResult>("PlayFabAdmin_GetServerBuildInfoResult")
                ->Constructor() 
			    ->Property("BuildId", BehaviorValueProperty(&AdminModels::GetServerBuildInfoResult::BuildId)) 
			    ->Property("MaxGamesPerHost", BehaviorValueProperty(&AdminModels::GetServerBuildInfoResult::MaxGamesPerHost)) 
			    ->Property("MinFreeGameSlots", BehaviorValueProperty(&AdminModels::GetServerBuildInfoResult::MinFreeGameSlots)) 
			    ->Property("Comment", BehaviorValueProperty(&AdminModels::GetServerBuildInfoResult::Comment)) 
			    ->Property("Timestamp", BehaviorValueProperty(&AdminModels::GetServerBuildInfoResult::Timestamp)) 
			    ->Property("TitleId", BehaviorValueProperty(&AdminModels::GetServerBuildInfoResult::TitleId)) 
			    ->Property("Status", BehaviorValueProperty(&AdminModels::GetServerBuildInfoResult::Status)) 
			    ->Property("ErrorMessage", BehaviorValueProperty(&AdminModels::GetServerBuildInfoResult::ErrorMessage)) 
			;
		
			behaviorContext->Class<AdminModels::GetServerBuildUploadURLRequest>("PlayFabAdmin_GetServerBuildUploadURLRequest")
                ->Constructor() 
			    ->Property("BuildId", BehaviorValueProperty(&AdminModels::GetServerBuildUploadURLRequest::BuildId)) 
			;
		
			behaviorContext->Class<AdminModels::GetServerBuildUploadURLResult>("PlayFabAdmin_GetServerBuildUploadURLResult")
                ->Constructor() 
			    ->Property("URL", BehaviorValueProperty(&AdminModels::GetServerBuildUploadURLResult::URL)) 
			;
		
			behaviorContext->Class<AdminModels::GetStoreItemsRequest>("PlayFabAdmin_GetStoreItemsRequest")
                ->Constructor() 
			    ->Property("CatalogVersion", BehaviorValueProperty(&AdminModels::GetStoreItemsRequest::CatalogVersion)) 
			    ->Property("StoreId", BehaviorValueProperty(&AdminModels::GetStoreItemsRequest::StoreId)) 
			;
		
			behaviorContext->Class<AdminModels::StoreItem>("PlayFabAdmin_StoreItem")
                ->Constructor() 
			    ->Property("ItemId", BehaviorValueProperty(&AdminModels::StoreItem::ItemId)) 
			    ->Property("CustomData", BehaviorValueProperty(&AdminModels::StoreItem::CustomData)) 
			    ->Property("DisplayPosition", BehaviorValueProperty(&AdminModels::StoreItem::DisplayPosition)) 
			;
		
			behaviorContext->Class<AdminModels::StoreMarketingModel>("PlayFabAdmin_StoreMarketingModel")
                ->Constructor() 
			    ->Property("DisplayName", BehaviorValueProperty(&AdminModels::StoreMarketingModel::DisplayName)) 
			    ->Property("Description", BehaviorValueProperty(&AdminModels::StoreMarketingModel::Description)) 
			    ->Property("Metadata", BehaviorValueProperty(&AdminModels::StoreMarketingModel::Metadata)) 
			;
		
			behaviorContext->Class<AdminModels::GetStoreItemsResult>("PlayFabAdmin_GetStoreItemsResult")
                ->Constructor() 
			    ->Property("Store", BehaviorValueProperty(&AdminModels::GetStoreItemsResult::Store)) 
			    ->Property("Source", BehaviorValueProperty(&AdminModels::GetStoreItemsResult::Source)) 
			    ->Property("CatalogVersion", BehaviorValueProperty(&AdminModels::GetStoreItemsResult::CatalogVersion)) 
			    ->Property("StoreId", BehaviorValueProperty(&AdminModels::GetStoreItemsResult::StoreId)) 
			    ->Property("MarketingData", BehaviorValueProperty(&AdminModels::GetStoreItemsResult::MarketingData)) 
			;
		
			behaviorContext->Class<AdminModels::GetTaskInstanceRequest>("PlayFabAdmin_GetTaskInstanceRequest")
                ->Constructor() 
			    ->Property("TaskInstanceId", BehaviorValueProperty(&AdminModels::GetTaskInstanceRequest::TaskInstanceId)) 
			;
		
			behaviorContext->Class<AdminModels::GetTaskInstancesRequest>("PlayFabAdmin_GetTaskInstancesRequest")
                ->Constructor() 
			    ->Property("TaskIdentifier", BehaviorValueProperty(&AdminModels::GetTaskInstancesRequest::TaskIdentifier)) 
			    ->Property("StatusFilter", BehaviorValueProperty(&AdminModels::GetTaskInstancesRequest::StatusFilter)) 
			    ->Property("StartedAtRangeFrom", BehaviorValueProperty(&AdminModels::GetTaskInstancesRequest::StartedAtRangeFrom)) 
			    ->Property("StartedAtRangeTo", BehaviorValueProperty(&AdminModels::GetTaskInstancesRequest::StartedAtRangeTo)) 
			;
		
			behaviorContext->Class<AdminModels::TaskInstanceBasicSummary>("PlayFabAdmin_TaskInstanceBasicSummary")
                ->Constructor() 
			    ->Property("TaskInstanceId", BehaviorValueProperty(&AdminModels::TaskInstanceBasicSummary::TaskInstanceId)) 
			    ->Property("TaskIdentifier", BehaviorValueProperty(&AdminModels::TaskInstanceBasicSummary::TaskIdentifier)) 
			    ->Property("StartedAt", BehaviorValueProperty(&AdminModels::TaskInstanceBasicSummary::StartedAt)) 
			    ->Property("CompletedAt", BehaviorValueProperty(&AdminModels::TaskInstanceBasicSummary::CompletedAt)) 
			    ->Property("Status", BehaviorValueProperty(&AdminModels::TaskInstanceBasicSummary::Status)) 
			    ->Property("PercentComplete", BehaviorValueProperty(&AdminModels::TaskInstanceBasicSummary::PercentComplete)) 
			    ->Property("EstimatedSecondsRemaining", BehaviorValueProperty(&AdminModels::TaskInstanceBasicSummary::EstimatedSecondsRemaining)) 
			    ->Property("ScheduledByUserId", BehaviorValueProperty(&AdminModels::TaskInstanceBasicSummary::ScheduledByUserId)) 
			    ->Property("Type", BehaviorValueProperty(&AdminModels::TaskInstanceBasicSummary::Type)) 
			;
		
			behaviorContext->Class<AdminModels::GetTaskInstancesResult>("PlayFabAdmin_GetTaskInstancesResult")
                ->Constructor() 
			    ->Property("Summaries", BehaviorValueProperty(&AdminModels::GetTaskInstancesResult::Summaries)) 
			;
		
			behaviorContext->Class<AdminModels::GetTasksRequest>("PlayFabAdmin_GetTasksRequest")
                ->Constructor() 
			    ->Property("Identifier", BehaviorValueProperty(&AdminModels::GetTasksRequest::Identifier)) 
			;
		
			behaviorContext->Class<AdminModels::ScheduledTask>("PlayFabAdmin_ScheduledTask")
                ->Constructor() 
			    ->Property("TaskId", BehaviorValueProperty(&AdminModels::ScheduledTask::TaskId)) 
			    ->Property("Name", BehaviorValueProperty(&AdminModels::ScheduledTask::Name)) 
			    ->Property("Description", BehaviorValueProperty(&AdminModels::ScheduledTask::Description)) 
			    ->Property("Schedule", BehaviorValueProperty(&AdminModels::ScheduledTask::Schedule)) 
			    ->Property("IsActive", BehaviorValueProperty(&AdminModels::ScheduledTask::IsActive)) 
			    ->Property("Type", BehaviorValueProperty(&AdminModels::ScheduledTask::Type)) 
			    ->Property("Parameter", BehaviorValueProperty(&AdminModels::ScheduledTask::Parameter)) 
			    ->Property("LastRunTime", BehaviorValueProperty(&AdminModels::ScheduledTask::LastRunTime)) 
			    ->Property("NextRunTime", BehaviorValueProperty(&AdminModels::ScheduledTask::NextRunTime)) 
			;
		
			behaviorContext->Class<AdminModels::GetTasksResult>("PlayFabAdmin_GetTasksResult")
                ->Constructor() 
			    ->Property("Tasks", BehaviorValueProperty(&AdminModels::GetTasksResult::Tasks)) 
			;
		
			behaviorContext->Class<AdminModels::GetTitleDataRequest>("PlayFabAdmin_GetTitleDataRequest")
                ->Constructor() 
			    ->Property("Keys", BehaviorValueProperty(&AdminModels::GetTitleDataRequest::Keys)) 
			;
		
			behaviorContext->Class<AdminModels::GetTitleDataResult>("PlayFabAdmin_GetTitleDataResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<AdminModels::GetUserBansRequest>("PlayFabAdmin_GetUserBansRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&AdminModels::GetUserBansRequest::PlayFabId)) 
			;
		
			behaviorContext->Class<AdminModels::GetUserBansResult>("PlayFabAdmin_GetUserBansResult")
                ->Constructor() 
			    ->Property("BanData", BehaviorValueProperty(&AdminModels::GetUserBansResult::BanData)) 
			;
		
			behaviorContext->Class<AdminModels::GetUserDataRequest>("PlayFabAdmin_GetUserDataRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&AdminModels::GetUserDataRequest::PlayFabId)) 
			    ->Property("Keys", BehaviorValueProperty(&AdminModels::GetUserDataRequest::Keys)) 
			    ->Property("IfChangedFromDataVersion", BehaviorValueProperty(&AdminModels::GetUserDataRequest::IfChangedFromDataVersion)) 
			;
		
			behaviorContext->Class<AdminModels::UserDataRecord>("PlayFabAdmin_UserDataRecord")
                ->Constructor() 
			    ->Property("Value", BehaviorValueProperty(&AdminModels::UserDataRecord::Value)) 
			    ->Property("LastUpdated", BehaviorValueProperty(&AdminModels::UserDataRecord::LastUpdated)) 
			    ->Property("Permission", BehaviorValueProperty(&AdminModels::UserDataRecord::Permission)) 
			;
		
			behaviorContext->Class<AdminModels::GetUserDataResult>("PlayFabAdmin_GetUserDataResult")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&AdminModels::GetUserDataResult::PlayFabId)) 
			    ->Property("DataVersion", BehaviorValueProperty(&AdminModels::GetUserDataResult::DataVersion)) 
			;
		
			behaviorContext->Class<AdminModels::GetUserInventoryRequest>("PlayFabAdmin_GetUserInventoryRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&AdminModels::GetUserInventoryRequest::PlayFabId)) 
			;
		
			behaviorContext->Class<AdminModels::ItemInstance>("PlayFabAdmin_ItemInstance")
                ->Constructor() 
			    ->Property("ItemId", BehaviorValueProperty(&AdminModels::ItemInstance::ItemId)) 
			    ->Property("ItemInstanceId", BehaviorValueProperty(&AdminModels::ItemInstance::ItemInstanceId)) 
			    ->Property("ItemClass", BehaviorValueProperty(&AdminModels::ItemInstance::ItemClass)) 
			    ->Property("PurchaseDate", BehaviorValueProperty(&AdminModels::ItemInstance::PurchaseDate)) 
			    ->Property("Expiration", BehaviorValueProperty(&AdminModels::ItemInstance::Expiration)) 
			    ->Property("RemainingUses", BehaviorValueProperty(&AdminModels::ItemInstance::RemainingUses)) 
			    ->Property("UsesIncrementedBy", BehaviorValueProperty(&AdminModels::ItemInstance::UsesIncrementedBy)) 
			    ->Property("Annotation", BehaviorValueProperty(&AdminModels::ItemInstance::Annotation)) 
			    ->Property("CatalogVersion", BehaviorValueProperty(&AdminModels::ItemInstance::CatalogVersion)) 
			    ->Property("BundleParent", BehaviorValueProperty(&AdminModels::ItemInstance::BundleParent)) 
			    ->Property("DisplayName", BehaviorValueProperty(&AdminModels::ItemInstance::DisplayName)) 
			    ->Property("UnitCurrency", BehaviorValueProperty(&AdminModels::ItemInstance::UnitCurrency)) 
			    ->Property("UnitPrice", BehaviorValueProperty(&AdminModels::ItemInstance::UnitPrice)) 
			    ->Property("BundleContents", BehaviorValueProperty(&AdminModels::ItemInstance::BundleContents)) 
			;
		
			behaviorContext->Class<AdminModels::VirtualCurrencyRechargeTime>("PlayFabAdmin_VirtualCurrencyRechargeTime")
                ->Constructor() 
			    ->Property("SecondsToRecharge", BehaviorValueProperty(&AdminModels::VirtualCurrencyRechargeTime::SecondsToRecharge)) 
			    ->Property("RechargeTime", BehaviorValueProperty(&AdminModels::VirtualCurrencyRechargeTime::RechargeTime)) 
			    ->Property("RechargeMax", BehaviorValueProperty(&AdminModels::VirtualCurrencyRechargeTime::RechargeMax)) 
			;
		
			behaviorContext->Class<AdminModels::GetUserInventoryResult>("PlayFabAdmin_GetUserInventoryResult")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&AdminModels::GetUserInventoryResult::PlayFabId)) 
			    ->Property("Inventory", BehaviorValueProperty(&AdminModels::GetUserInventoryResult::Inventory)) 
			;
		
			behaviorContext->Class<AdminModels::GrantedItemInstance>("PlayFabAdmin_GrantedItemInstance")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&AdminModels::GrantedItemInstance::PlayFabId)) 
			    ->Property("CharacterId", BehaviorValueProperty(&AdminModels::GrantedItemInstance::CharacterId)) 
			    ->Property("Result", BehaviorValueProperty(&AdminModels::GrantedItemInstance::Result)) 
			    ->Property("ItemId", BehaviorValueProperty(&AdminModels::GrantedItemInstance::ItemId)) 
			    ->Property("ItemInstanceId", BehaviorValueProperty(&AdminModels::GrantedItemInstance::ItemInstanceId)) 
			    ->Property("ItemClass", BehaviorValueProperty(&AdminModels::GrantedItemInstance::ItemClass)) 
			    ->Property("PurchaseDate", BehaviorValueProperty(&AdminModels::GrantedItemInstance::PurchaseDate)) 
			    ->Property("Expiration", BehaviorValueProperty(&AdminModels::GrantedItemInstance::Expiration)) 
			    ->Property("RemainingUses", BehaviorValueProperty(&AdminModels::GrantedItemInstance::RemainingUses)) 
			    ->Property("UsesIncrementedBy", BehaviorValueProperty(&AdminModels::GrantedItemInstance::UsesIncrementedBy)) 
			    ->Property("Annotation", BehaviorValueProperty(&AdminModels::GrantedItemInstance::Annotation)) 
			    ->Property("CatalogVersion", BehaviorValueProperty(&AdminModels::GrantedItemInstance::CatalogVersion)) 
			    ->Property("BundleParent", BehaviorValueProperty(&AdminModels::GrantedItemInstance::BundleParent)) 
			    ->Property("DisplayName", BehaviorValueProperty(&AdminModels::GrantedItemInstance::DisplayName)) 
			    ->Property("UnitCurrency", BehaviorValueProperty(&AdminModels::GrantedItemInstance::UnitCurrency)) 
			    ->Property("UnitPrice", BehaviorValueProperty(&AdminModels::GrantedItemInstance::UnitPrice)) 
			    ->Property("BundleContents", BehaviorValueProperty(&AdminModels::GrantedItemInstance::BundleContents)) 
			;
		
			behaviorContext->Class<AdminModels::ItemGrant>("PlayFabAdmin_ItemGrant")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&AdminModels::ItemGrant::PlayFabId)) 
			    ->Property("ItemId", BehaviorValueProperty(&AdminModels::ItemGrant::ItemId)) 
			    ->Property("Annotation", BehaviorValueProperty(&AdminModels::ItemGrant::Annotation)) 
			    ->Property("CharacterId", BehaviorValueProperty(&AdminModels::ItemGrant::CharacterId)) 
			    ->Property("KeysToRemove", BehaviorValueProperty(&AdminModels::ItemGrant::KeysToRemove)) 
			;
		
			behaviorContext->Class<AdminModels::GrantItemsToUsersRequest>("PlayFabAdmin_GrantItemsToUsersRequest")
                ->Constructor() 
			    ->Property("CatalogVersion", BehaviorValueProperty(&AdminModels::GrantItemsToUsersRequest::CatalogVersion)) 
			    ->Property("ItemGrants", BehaviorValueProperty(&AdminModels::GrantItemsToUsersRequest::ItemGrants)) 
			;
		
			behaviorContext->Class<AdminModels::GrantItemsToUsersResult>("PlayFabAdmin_GrantItemsToUsersResult")
                ->Constructor() 
			    ->Property("ItemGrantResults", BehaviorValueProperty(&AdminModels::GrantItemsToUsersResult::ItemGrantResults)) 
			;
		
			behaviorContext->Class<AdminModels::IncrementPlayerStatisticVersionRequest>("PlayFabAdmin_IncrementPlayerStatisticVersionRequest")
                ->Constructor() 
			    ->Property("StatisticName", BehaviorValueProperty(&AdminModels::IncrementPlayerStatisticVersionRequest::StatisticName)) 
			;
		
			behaviorContext->Class<AdminModels::IncrementPlayerStatisticVersionResult>("PlayFabAdmin_IncrementPlayerStatisticVersionResult")
                ->Constructor() 
			    ->Property("StatisticVersion", BehaviorValueProperty(&AdminModels::IncrementPlayerStatisticVersionResult::StatisticVersion)) 
			;
		
			behaviorContext->Class<AdminModels::ListBuildsRequest>("PlayFabAdmin_ListBuildsRequest")
                ->Constructor() 
			;
		
			behaviorContext->Class<AdminModels::ListBuildsResult>("PlayFabAdmin_ListBuildsResult")
                ->Constructor() 
			    ->Property("Builds", BehaviorValueProperty(&AdminModels::ListBuildsResult::Builds)) 
			;
		
			behaviorContext->Class<AdminModels::ListVirtualCurrencyTypesRequest>("PlayFabAdmin_ListVirtualCurrencyTypesRequest")
                ->Constructor() 
			;
		
			behaviorContext->Class<AdminModels::ListVirtualCurrencyTypesResult>("PlayFabAdmin_ListVirtualCurrencyTypesResult")
                ->Constructor() 
			    ->Property("VirtualCurrencies", BehaviorValueProperty(&AdminModels::ListVirtualCurrencyTypesResult::VirtualCurrencies)) 
			;
		
			behaviorContext->Class<AdminModels::LookupUserAccountInfoRequest>("PlayFabAdmin_LookupUserAccountInfoRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&AdminModels::LookupUserAccountInfoRequest::PlayFabId)) 
			    ->Property("Email", BehaviorValueProperty(&AdminModels::LookupUserAccountInfoRequest::Email)) 
			    ->Property("Username", BehaviorValueProperty(&AdminModels::LookupUserAccountInfoRequest::Username)) 
			    ->Property("TitleDisplayName", BehaviorValueProperty(&AdminModels::LookupUserAccountInfoRequest::TitleDisplayName)) 
			;
		
			behaviorContext->Class<AdminModels::UserTitleInfo>("PlayFabAdmin_UserTitleInfo")
                ->Constructor() 
			    ->Property("DisplayName", BehaviorValueProperty(&AdminModels::UserTitleInfo::DisplayName)) 
			    ->Property("Origination", BehaviorValueProperty(&AdminModels::UserTitleInfo::Origination)) 
			    ->Property("Created", BehaviorValueProperty(&AdminModels::UserTitleInfo::Created)) 
			    ->Property("LastLogin", BehaviorValueProperty(&AdminModels::UserTitleInfo::LastLogin)) 
			    ->Property("FirstLogin", BehaviorValueProperty(&AdminModels::UserTitleInfo::FirstLogin)) 
			    ->Property("isBanned", BehaviorValueProperty(&AdminModels::UserTitleInfo::isBanned)) 
			    ->Property("AvatarUrl", BehaviorValueProperty(&AdminModels::UserTitleInfo::AvatarUrl)) 
			;
		
			behaviorContext->Class<AdminModels::UserPrivateAccountInfo>("PlayFabAdmin_UserPrivateAccountInfo")
                ->Constructor() 
			    ->Property("Email", BehaviorValueProperty(&AdminModels::UserPrivateAccountInfo::Email)) 
			;
		
			behaviorContext->Class<AdminModels::UserFacebookInfo>("PlayFabAdmin_UserFacebookInfo")
                ->Constructor() 
			    ->Property("FacebookId", BehaviorValueProperty(&AdminModels::UserFacebookInfo::FacebookId)) 
			    ->Property("FullName", BehaviorValueProperty(&AdminModels::UserFacebookInfo::FullName)) 
			;
		
			behaviorContext->Class<AdminModels::UserSteamInfo>("PlayFabAdmin_UserSteamInfo")
                ->Constructor() 
			    ->Property("SteamId", BehaviorValueProperty(&AdminModels::UserSteamInfo::SteamId)) 
			    ->Property("SteamCountry", BehaviorValueProperty(&AdminModels::UserSteamInfo::SteamCountry)) 
			    ->Property("SteamCurrency", BehaviorValueProperty(&AdminModels::UserSteamInfo::SteamCurrency)) 
			    ->Property("SteamActivationStatus", BehaviorValueProperty(&AdminModels::UserSteamInfo::SteamActivationStatus)) 
			;
		
			behaviorContext->Class<AdminModels::UserGameCenterInfo>("PlayFabAdmin_UserGameCenterInfo")
                ->Constructor() 
			    ->Property("GameCenterId", BehaviorValueProperty(&AdminModels::UserGameCenterInfo::GameCenterId)) 
			;
		
			behaviorContext->Class<AdminModels::UserIosDeviceInfo>("PlayFabAdmin_UserIosDeviceInfo")
                ->Constructor() 
			    ->Property("IosDeviceId", BehaviorValueProperty(&AdminModels::UserIosDeviceInfo::IosDeviceId)) 
			;
		
			behaviorContext->Class<AdminModels::UserAndroidDeviceInfo>("PlayFabAdmin_UserAndroidDeviceInfo")
                ->Constructor() 
			    ->Property("AndroidDeviceId", BehaviorValueProperty(&AdminModels::UserAndroidDeviceInfo::AndroidDeviceId)) 
			;
		
			behaviorContext->Class<AdminModels::UserKongregateInfo>("PlayFabAdmin_UserKongregateInfo")
                ->Constructor() 
			    ->Property("KongregateId", BehaviorValueProperty(&AdminModels::UserKongregateInfo::KongregateId)) 
			    ->Property("KongregateName", BehaviorValueProperty(&AdminModels::UserKongregateInfo::KongregateName)) 
			;
		
			behaviorContext->Class<AdminModels::UserTwitchInfo>("PlayFabAdmin_UserTwitchInfo")
                ->Constructor() 
			    ->Property("TwitchId", BehaviorValueProperty(&AdminModels::UserTwitchInfo::TwitchId)) 
			    ->Property("TwitchUserName", BehaviorValueProperty(&AdminModels::UserTwitchInfo::TwitchUserName)) 
			;
		
			behaviorContext->Class<AdminModels::UserPsnInfo>("PlayFabAdmin_UserPsnInfo")
                ->Constructor() 
			    ->Property("PsnAccountId", BehaviorValueProperty(&AdminModels::UserPsnInfo::PsnAccountId)) 
			    ->Property("PsnOnlineId", BehaviorValueProperty(&AdminModels::UserPsnInfo::PsnOnlineId)) 
			;
		
			behaviorContext->Class<AdminModels::UserGoogleInfo>("PlayFabAdmin_UserGoogleInfo")
                ->Constructor() 
			    ->Property("GoogleId", BehaviorValueProperty(&AdminModels::UserGoogleInfo::GoogleId)) 
			    ->Property("GoogleEmail", BehaviorValueProperty(&AdminModels::UserGoogleInfo::GoogleEmail)) 
			    ->Property("GoogleLocale", BehaviorValueProperty(&AdminModels::UserGoogleInfo::GoogleLocale)) 
			    ->Property("GoogleGender", BehaviorValueProperty(&AdminModels::UserGoogleInfo::GoogleGender)) 
			;
		
			behaviorContext->Class<AdminModels::UserXboxInfo>("PlayFabAdmin_UserXboxInfo")
                ->Constructor() 
			    ->Property("XboxUserId", BehaviorValueProperty(&AdminModels::UserXboxInfo::XboxUserId)) 
			;
		
			behaviorContext->Class<AdminModels::UserCustomIdInfo>("PlayFabAdmin_UserCustomIdInfo")
                ->Constructor() 
			    ->Property("CustomId", BehaviorValueProperty(&AdminModels::UserCustomIdInfo::CustomId)) 
			;
		
			behaviorContext->Class<AdminModels::UserAccountInfo>("PlayFabAdmin_UserAccountInfo")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&AdminModels::UserAccountInfo::PlayFabId)) 
			    ->Property("Created", BehaviorValueProperty(&AdminModels::UserAccountInfo::Created)) 
			    ->Property("Username", BehaviorValueProperty(&AdminModels::UserAccountInfo::Username)) 
			    ->Property("TitleInfo", BehaviorValueProperty(&AdminModels::UserAccountInfo::TitleInfo)) 
			    ->Property("PrivateInfo", BehaviorValueProperty(&AdminModels::UserAccountInfo::PrivateInfo)) 
			    ->Property("FacebookInfo", BehaviorValueProperty(&AdminModels::UserAccountInfo::FacebookInfo)) 
			    ->Property("SteamInfo", BehaviorValueProperty(&AdminModels::UserAccountInfo::SteamInfo)) 
			    ->Property("GameCenterInfo", BehaviorValueProperty(&AdminModels::UserAccountInfo::GameCenterInfo)) 
			    ->Property("IosDeviceInfo", BehaviorValueProperty(&AdminModels::UserAccountInfo::IosDeviceInfo)) 
			    ->Property("AndroidDeviceInfo", BehaviorValueProperty(&AdminModels::UserAccountInfo::AndroidDeviceInfo)) 
			    ->Property("KongregateInfo", BehaviorValueProperty(&AdminModels::UserAccountInfo::KongregateInfo)) 
			    ->Property("TwitchInfo", BehaviorValueProperty(&AdminModels::UserAccountInfo::TwitchInfo)) 
			    ->Property("PsnInfo", BehaviorValueProperty(&AdminModels::UserAccountInfo::PsnInfo)) 
			    ->Property("GoogleInfo", BehaviorValueProperty(&AdminModels::UserAccountInfo::GoogleInfo)) 
			    ->Property("XboxInfo", BehaviorValueProperty(&AdminModels::UserAccountInfo::XboxInfo)) 
			    ->Property("CustomIdInfo", BehaviorValueProperty(&AdminModels::UserAccountInfo::CustomIdInfo)) 
			;
		
			behaviorContext->Class<AdminModels::LookupUserAccountInfoResult>("PlayFabAdmin_LookupUserAccountInfoResult")
                ->Constructor() 
			    ->Property("UserInfo", BehaviorValueProperty(&AdminModels::LookupUserAccountInfoResult::UserInfo)) 
			;
		
			behaviorContext->Class<AdminModels::ModifyMatchmakerGameModesRequest>("PlayFabAdmin_ModifyMatchmakerGameModesRequest")
                ->Constructor() 
			    ->Property("BuildVersion", BehaviorValueProperty(&AdminModels::ModifyMatchmakerGameModesRequest::BuildVersion)) 
			    ->Property("GameModes", BehaviorValueProperty(&AdminModels::ModifyMatchmakerGameModesRequest::GameModes)) 
			;
		
			behaviorContext->Class<AdminModels::ModifyMatchmakerGameModesResult>("PlayFabAdmin_ModifyMatchmakerGameModesResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<AdminModels::ModifyServerBuildRequest>("PlayFabAdmin_ModifyServerBuildRequest")
                ->Constructor() 
			    ->Property("BuildId", BehaviorValueProperty(&AdminModels::ModifyServerBuildRequest::BuildId)) 
			    ->Property("Timestamp", BehaviorValueProperty(&AdminModels::ModifyServerBuildRequest::Timestamp)) 
			    ->Property("MaxGamesPerHost", BehaviorValueProperty(&AdminModels::ModifyServerBuildRequest::MaxGamesPerHost)) 
			    ->Property("MinFreeGameSlots", BehaviorValueProperty(&AdminModels::ModifyServerBuildRequest::MinFreeGameSlots)) 
			    ->Property("CommandLineTemplate", BehaviorValueProperty(&AdminModels::ModifyServerBuildRequest::CommandLineTemplate)) 
			    ->Property("ExecutablePath", BehaviorValueProperty(&AdminModels::ModifyServerBuildRequest::ExecutablePath)) 
			    ->Property("Comment", BehaviorValueProperty(&AdminModels::ModifyServerBuildRequest::Comment)) 
			;
		
			behaviorContext->Class<AdminModels::ModifyServerBuildResult>("PlayFabAdmin_ModifyServerBuildResult")
                ->Constructor() 
			    ->Property("BuildId", BehaviorValueProperty(&AdminModels::ModifyServerBuildResult::BuildId)) 
			    ->Property("MaxGamesPerHost", BehaviorValueProperty(&AdminModels::ModifyServerBuildResult::MaxGamesPerHost)) 
			    ->Property("MinFreeGameSlots", BehaviorValueProperty(&AdminModels::ModifyServerBuildResult::MinFreeGameSlots)) 
			    ->Property("CommandLineTemplate", BehaviorValueProperty(&AdminModels::ModifyServerBuildResult::CommandLineTemplate)) 
			    ->Property("ExecutablePath", BehaviorValueProperty(&AdminModels::ModifyServerBuildResult::ExecutablePath)) 
			    ->Property("Comment", BehaviorValueProperty(&AdminModels::ModifyServerBuildResult::Comment)) 
			    ->Property("Timestamp", BehaviorValueProperty(&AdminModels::ModifyServerBuildResult::Timestamp)) 
			    ->Property("TitleId", BehaviorValueProperty(&AdminModels::ModifyServerBuildResult::TitleId)) 
			    ->Property("Status", BehaviorValueProperty(&AdminModels::ModifyServerBuildResult::Status)) 
			;
		
			behaviorContext->Class<AdminModels::ModifyUserVirtualCurrencyResult>("PlayFabAdmin_ModifyUserVirtualCurrencyResult")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&AdminModels::ModifyUserVirtualCurrencyResult::PlayFabId)) 
			    ->Property("VirtualCurrency", BehaviorValueProperty(&AdminModels::ModifyUserVirtualCurrencyResult::VirtualCurrency)) 
			    ->Property("BalanceChange", BehaviorValueProperty(&AdminModels::ModifyUserVirtualCurrencyResult::BalanceChange)) 
			    ->Property("Balance", BehaviorValueProperty(&AdminModels::ModifyUserVirtualCurrencyResult::Balance)) 
			;
		
			behaviorContext->Class<AdminModels::RandomResultTable>("PlayFabAdmin_RandomResultTable")
                ->Constructor() 
			    ->Property("TableId", BehaviorValueProperty(&AdminModels::RandomResultTable::TableId)) 
			    ->Property("Nodes", BehaviorValueProperty(&AdminModels::RandomResultTable::Nodes)) 
			;
		
			behaviorContext->Class<AdminModels::RefundPurchaseRequest>("PlayFabAdmin_RefundPurchaseRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&AdminModels::RefundPurchaseRequest::PlayFabId)) 
			    ->Property("OrderId", BehaviorValueProperty(&AdminModels::RefundPurchaseRequest::OrderId)) 
			    ->Property("Reason", BehaviorValueProperty(&AdminModels::RefundPurchaseRequest::Reason)) 
			;
		
			behaviorContext->Class<AdminModels::RefundPurchaseResponse>("PlayFabAdmin_RefundPurchaseResponse")
                ->Constructor() 
			    ->Property("PurchaseStatus", BehaviorValueProperty(&AdminModels::RefundPurchaseResponse::PurchaseStatus)) 
			;
		
			behaviorContext->Class<AdminModels::RemovePlayerTagRequest>("PlayFabAdmin_RemovePlayerTagRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&AdminModels::RemovePlayerTagRequest::PlayFabId)) 
			    ->Property("TagName", BehaviorValueProperty(&AdminModels::RemovePlayerTagRequest::TagName)) 
			;
		
			behaviorContext->Class<AdminModels::RemovePlayerTagResult>("PlayFabAdmin_RemovePlayerTagResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<AdminModels::RemoveServerBuildRequest>("PlayFabAdmin_RemoveServerBuildRequest")
                ->Constructor() 
			    ->Property("BuildId", BehaviorValueProperty(&AdminModels::RemoveServerBuildRequest::BuildId)) 
			;
		
			behaviorContext->Class<AdminModels::RemoveServerBuildResult>("PlayFabAdmin_RemoveServerBuildResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<AdminModels::RemoveVirtualCurrencyTypesRequest>("PlayFabAdmin_RemoveVirtualCurrencyTypesRequest")
                ->Constructor() 
			    ->Property("VirtualCurrencies", BehaviorValueProperty(&AdminModels::RemoveVirtualCurrencyTypesRequest::VirtualCurrencies)) 
			;
		
			behaviorContext->Class<AdminModels::ResetCharacterStatisticsRequest>("PlayFabAdmin_ResetCharacterStatisticsRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&AdminModels::ResetCharacterStatisticsRequest::PlayFabId)) 
			    ->Property("CharacterId", BehaviorValueProperty(&AdminModels::ResetCharacterStatisticsRequest::CharacterId)) 
			;
		
			behaviorContext->Class<AdminModels::ResetCharacterStatisticsResult>("PlayFabAdmin_ResetCharacterStatisticsResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<AdminModels::UserCredentials>("PlayFabAdmin_UserCredentials")
                ->Constructor() 
			    ->Property("Username", BehaviorValueProperty(&AdminModels::UserCredentials::Username)) 
			;
		
			behaviorContext->Class<AdminModels::ResetUsersRequest>("PlayFabAdmin_ResetUsersRequest")
                ->Constructor() 
			    ->Property("Users", BehaviorValueProperty(&AdminModels::ResetUsersRequest::Users)) 
			;
		
			behaviorContext->Class<AdminModels::ResetUserStatisticsRequest>("PlayFabAdmin_ResetUserStatisticsRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&AdminModels::ResetUserStatisticsRequest::PlayFabId)) 
			;
		
			behaviorContext->Class<AdminModels::ResetUserStatisticsResult>("PlayFabAdmin_ResetUserStatisticsResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<AdminModels::ResolvePurchaseDisputeRequest>("PlayFabAdmin_ResolvePurchaseDisputeRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&AdminModels::ResolvePurchaseDisputeRequest::PlayFabId)) 
			    ->Property("OrderId", BehaviorValueProperty(&AdminModels::ResolvePurchaseDisputeRequest::OrderId)) 
			    ->Property("Reason", BehaviorValueProperty(&AdminModels::ResolvePurchaseDisputeRequest::Reason)) 
			    ->Property("Outcome",
				    [](AdminModels::ResolvePurchaseDisputeRequest* p) { return p->Outcome; },
				    [](AdminModels::ResolvePurchaseDisputeRequest* p, AdminModels::ResolutionOutcome v) { p->Outcome = v; })
			;
		
			behaviorContext->Class<AdminModels::ResolvePurchaseDisputeResponse>("PlayFabAdmin_ResolvePurchaseDisputeResponse")
                ->Constructor() 
			    ->Property("PurchaseStatus", BehaviorValueProperty(&AdminModels::ResolvePurchaseDisputeResponse::PurchaseStatus)) 
			;
		
			behaviorContext->Class<AdminModels::RevokeAllBansForUserRequest>("PlayFabAdmin_RevokeAllBansForUserRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&AdminModels::RevokeAllBansForUserRequest::PlayFabId)) 
			;
		
			behaviorContext->Class<AdminModels::RevokeAllBansForUserResult>("PlayFabAdmin_RevokeAllBansForUserResult")
                ->Constructor() 
			    ->Property("BanData", BehaviorValueProperty(&AdminModels::RevokeAllBansForUserResult::BanData)) 
			;
		
			behaviorContext->Class<AdminModels::RevokeBansRequest>("PlayFabAdmin_RevokeBansRequest")
                ->Constructor() 
			    ->Property("BanIds", BehaviorValueProperty(&AdminModels::RevokeBansRequest::BanIds)) 
			;
		
			behaviorContext->Class<AdminModels::RevokeBansResult>("PlayFabAdmin_RevokeBansResult")
                ->Constructor() 
			    ->Property("BanData", BehaviorValueProperty(&AdminModels::RevokeBansResult::BanData)) 
			;
		
			behaviorContext->Class<AdminModels::RevokeInventoryItemRequest>("PlayFabAdmin_RevokeInventoryItemRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&AdminModels::RevokeInventoryItemRequest::PlayFabId)) 
			    ->Property("CharacterId", BehaviorValueProperty(&AdminModels::RevokeInventoryItemRequest::CharacterId)) 
			    ->Property("ItemInstanceId", BehaviorValueProperty(&AdminModels::RevokeInventoryItemRequest::ItemInstanceId)) 
			;
		
			behaviorContext->Class<AdminModels::RevokeInventoryResult>("PlayFabAdmin_RevokeInventoryResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<AdminModels::RunTaskRequest>("PlayFabAdmin_RunTaskRequest")
                ->Constructor() 
			    ->Property("Identifier", BehaviorValueProperty(&AdminModels::RunTaskRequest::Identifier)) 
			;
		
			behaviorContext->Class<AdminModels::RunTaskResult>("PlayFabAdmin_RunTaskResult")
                ->Constructor() 
			    ->Property("TaskInstanceId", BehaviorValueProperty(&AdminModels::RunTaskResult::TaskInstanceId)) 
			;
		
			behaviorContext->Class<AdminModels::SendAccountRecoveryEmailRequest>("PlayFabAdmin_SendAccountRecoveryEmailRequest")
                ->Constructor() 
			    ->Property("Email", BehaviorValueProperty(&AdminModels::SendAccountRecoveryEmailRequest::Email)) 
			;
		
			behaviorContext->Class<AdminModels::SendAccountRecoveryEmailResult>("PlayFabAdmin_SendAccountRecoveryEmailResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<AdminModels::SetPlayerSecretRequest>("PlayFabAdmin_SetPlayerSecretRequest")
                ->Constructor() 
			    ->Property("PlayerSecret", BehaviorValueProperty(&AdminModels::SetPlayerSecretRequest::PlayerSecret)) 
			    ->Property("PlayFabId", BehaviorValueProperty(&AdminModels::SetPlayerSecretRequest::PlayFabId)) 
			;
		
			behaviorContext->Class<AdminModels::SetPlayerSecretResult>("PlayFabAdmin_SetPlayerSecretResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<AdminModels::SetPublishedRevisionRequest>("PlayFabAdmin_SetPublishedRevisionRequest")
                ->Constructor() 
			    ->Property("Version", BehaviorValueProperty(&AdminModels::SetPublishedRevisionRequest::Version)) 
			    ->Property("Revision", BehaviorValueProperty(&AdminModels::SetPublishedRevisionRequest::Revision)) 
			;
		
			behaviorContext->Class<AdminModels::SetPublishedRevisionResult>("PlayFabAdmin_SetPublishedRevisionResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<AdminModels::SetPublisherDataRequest>("PlayFabAdmin_SetPublisherDataRequest")
                ->Constructor() 
			    ->Property("Key", BehaviorValueProperty(&AdminModels::SetPublisherDataRequest::Key)) 
			    ->Property("Value", BehaviorValueProperty(&AdminModels::SetPublisherDataRequest::Value)) 
			;
		
			behaviorContext->Class<AdminModels::SetPublisherDataResult>("PlayFabAdmin_SetPublisherDataResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<AdminModels::SetTitleDataRequest>("PlayFabAdmin_SetTitleDataRequest")
                ->Constructor() 
			    ->Property("Key", BehaviorValueProperty(&AdminModels::SetTitleDataRequest::Key)) 
			    ->Property("Value", BehaviorValueProperty(&AdminModels::SetTitleDataRequest::Value)) 
			;
		
			behaviorContext->Class<AdminModels::SetTitleDataResult>("PlayFabAdmin_SetTitleDataResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<AdminModels::SetupPushNotificationRequest>("PlayFabAdmin_SetupPushNotificationRequest")
                ->Constructor() 
			    ->Property("Name", BehaviorValueProperty(&AdminModels::SetupPushNotificationRequest::Name)) 
			    ->Property("Platform",
				    [](AdminModels::SetupPushNotificationRequest* p) { return p->Platform; },
				    [](AdminModels::SetupPushNotificationRequest* p, AdminModels::PushSetupPlatform v) { p->Platform = v; })
			    ->Property("Key", BehaviorValueProperty(&AdminModels::SetupPushNotificationRequest::Key)) 
			    ->Property("Credential", BehaviorValueProperty(&AdminModels::SetupPushNotificationRequest::Credential)) 
			    ->Property("OverwriteOldARN", BehaviorValueProperty(&AdminModels::SetupPushNotificationRequest::OverwriteOldARN)) 
			;
		
			behaviorContext->Class<AdminModels::SetupPushNotificationResult>("PlayFabAdmin_SetupPushNotificationResult")
                ->Constructor() 
			    ->Property("ARN", BehaviorValueProperty(&AdminModels::SetupPushNotificationResult::ARN)) 
			;
		
			behaviorContext->Class<AdminModels::SubtractUserVirtualCurrencyRequest>("PlayFabAdmin_SubtractUserVirtualCurrencyRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&AdminModels::SubtractUserVirtualCurrencyRequest::PlayFabId)) 
			    ->Property("VirtualCurrency", BehaviorValueProperty(&AdminModels::SubtractUserVirtualCurrencyRequest::VirtualCurrency)) 
			    ->Property("Amount", BehaviorValueProperty(&AdminModels::SubtractUserVirtualCurrencyRequest::Amount)) 
			;
		
			behaviorContext->Class<AdminModels::UpdateBanRequest>("PlayFabAdmin_UpdateBanRequest")
                ->Constructor() 
			    ->Property("BanId", BehaviorValueProperty(&AdminModels::UpdateBanRequest::BanId)) 
			    ->Property("Reason", BehaviorValueProperty(&AdminModels::UpdateBanRequest::Reason)) 
			    ->Property("Expires", BehaviorValueProperty(&AdminModels::UpdateBanRequest::Expires)) 
			    ->Property("IPAddress", BehaviorValueProperty(&AdminModels::UpdateBanRequest::IPAddress)) 
			    ->Property("MACAddress", BehaviorValueProperty(&AdminModels::UpdateBanRequest::MACAddress)) 
			    ->Property("Permanent", BehaviorValueProperty(&AdminModels::UpdateBanRequest::Permanent)) 
			    ->Property("Active", BehaviorValueProperty(&AdminModels::UpdateBanRequest::Active)) 
			;
		
			behaviorContext->Class<AdminModels::UpdateBansRequest>("PlayFabAdmin_UpdateBansRequest")
                ->Constructor() 
			    ->Property("Bans", BehaviorValueProperty(&AdminModels::UpdateBansRequest::Bans)) 
			;
		
			behaviorContext->Class<AdminModels::UpdateBansResult>("PlayFabAdmin_UpdateBansResult")
                ->Constructor() 
			    ->Property("BanData", BehaviorValueProperty(&AdminModels::UpdateBansResult::BanData)) 
			;
		
			behaviorContext->Class<AdminModels::UpdateCatalogItemsRequest>("PlayFabAdmin_UpdateCatalogItemsRequest")
                ->Constructor() 
			    ->Property("CatalogVersion", BehaviorValueProperty(&AdminModels::UpdateCatalogItemsRequest::CatalogVersion)) 
			    ->Property("SetAsDefaultCatalog", BehaviorValueProperty(&AdminModels::UpdateCatalogItemsRequest::SetAsDefaultCatalog)) 
			    ->Property("Catalog", BehaviorValueProperty(&AdminModels::UpdateCatalogItemsRequest::Catalog)) 
			;
		
			behaviorContext->Class<AdminModels::UpdateCatalogItemsResult>("PlayFabAdmin_UpdateCatalogItemsResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<AdminModels::UpdateCloudScriptRequest>("PlayFabAdmin_UpdateCloudScriptRequest")
                ->Constructor() 
			    ->Property("Files", BehaviorValueProperty(&AdminModels::UpdateCloudScriptRequest::Files)) 
			    ->Property("Publish", BehaviorValueProperty(&AdminModels::UpdateCloudScriptRequest::Publish)) 
			    ->Property("DeveloperPlayFabId", BehaviorValueProperty(&AdminModels::UpdateCloudScriptRequest::DeveloperPlayFabId)) 
			;
		
			behaviorContext->Class<AdminModels::UpdateCloudScriptResult>("PlayFabAdmin_UpdateCloudScriptResult")
                ->Constructor() 
			    ->Property("Version", BehaviorValueProperty(&AdminModels::UpdateCloudScriptResult::Version)) 
			    ->Property("Revision", BehaviorValueProperty(&AdminModels::UpdateCloudScriptResult::Revision)) 
			;
		
			behaviorContext->Class<AdminModels::UpdatePlayerSharedSecretRequest>("PlayFabAdmin_UpdatePlayerSharedSecretRequest")
                ->Constructor() 
			    ->Property("SecretKey", BehaviorValueProperty(&AdminModels::UpdatePlayerSharedSecretRequest::SecretKey)) 
			    ->Property("FriendlyName", BehaviorValueProperty(&AdminModels::UpdatePlayerSharedSecretRequest::FriendlyName)) 
			    ->Property("Disabled", BehaviorValueProperty(&AdminModels::UpdatePlayerSharedSecretRequest::Disabled)) 
			;
		
			behaviorContext->Class<AdminModels::UpdatePlayerSharedSecretResult>("PlayFabAdmin_UpdatePlayerSharedSecretResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<AdminModels::UpdatePlayerStatisticDefinitionRequest>("PlayFabAdmin_UpdatePlayerStatisticDefinitionRequest")
                ->Constructor() 
			    ->Property("StatisticName", BehaviorValueProperty(&AdminModels::UpdatePlayerStatisticDefinitionRequest::StatisticName)) 
			    ->Property("VersionChangeInterval", BehaviorValueProperty(&AdminModels::UpdatePlayerStatisticDefinitionRequest::VersionChangeInterval)) 
			    ->Property("AggregationMethod", BehaviorValueProperty(&AdminModels::UpdatePlayerStatisticDefinitionRequest::AggregationMethod)) 
			;
		
			behaviorContext->Class<AdminModels::UpdatePlayerStatisticDefinitionResult>("PlayFabAdmin_UpdatePlayerStatisticDefinitionResult")
                ->Constructor() 
			    ->Property("Statistic", BehaviorValueProperty(&AdminModels::UpdatePlayerStatisticDefinitionResult::Statistic)) 
			;
		
			behaviorContext->Class<AdminModels::UpdatePolicyRequest>("PlayFabAdmin_UpdatePolicyRequest")
                ->Constructor() 
			    ->Property("PolicyName", BehaviorValueProperty(&AdminModels::UpdatePolicyRequest::PolicyName)) 
			    ->Property("Statements", BehaviorValueProperty(&AdminModels::UpdatePolicyRequest::Statements)) 
			    ->Property("OverwritePolicy", BehaviorValueProperty(&AdminModels::UpdatePolicyRequest::OverwritePolicy)) 
			;
		
			behaviorContext->Class<AdminModels::UpdatePolicyResponse>("PlayFabAdmin_UpdatePolicyResponse")
                ->Constructor() 
			    ->Property("PolicyName", BehaviorValueProperty(&AdminModels::UpdatePolicyResponse::PolicyName)) 
			    ->Property("Statements", BehaviorValueProperty(&AdminModels::UpdatePolicyResponse::Statements)) 
			;
		
			behaviorContext->Class<AdminModels::UpdateRandomResultTablesRequest>("PlayFabAdmin_UpdateRandomResultTablesRequest")
                ->Constructor() 
			    ->Property("CatalogVersion", BehaviorValueProperty(&AdminModels::UpdateRandomResultTablesRequest::CatalogVersion)) 
			    ->Property("Tables", BehaviorValueProperty(&AdminModels::UpdateRandomResultTablesRequest::Tables)) 
			;
		
			behaviorContext->Class<AdminModels::UpdateRandomResultTablesResult>("PlayFabAdmin_UpdateRandomResultTablesResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<AdminModels::UpdateStoreItemsRequest>("PlayFabAdmin_UpdateStoreItemsRequest")
                ->Constructor() 
			    ->Property("CatalogVersion", BehaviorValueProperty(&AdminModels::UpdateStoreItemsRequest::CatalogVersion)) 
			    ->Property("StoreId", BehaviorValueProperty(&AdminModels::UpdateStoreItemsRequest::StoreId)) 
			    ->Property("MarketingData", BehaviorValueProperty(&AdminModels::UpdateStoreItemsRequest::MarketingData)) 
			    ->Property("Store", BehaviorValueProperty(&AdminModels::UpdateStoreItemsRequest::Store)) 
			;
		
			behaviorContext->Class<AdminModels::UpdateStoreItemsResult>("PlayFabAdmin_UpdateStoreItemsResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<AdminModels::UpdateTaskRequest>("PlayFabAdmin_UpdateTaskRequest")
                ->Constructor() 
			    ->Property("Identifier", BehaviorValueProperty(&AdminModels::UpdateTaskRequest::Identifier)) 
			    ->Property("Name", BehaviorValueProperty(&AdminModels::UpdateTaskRequest::Name)) 
			    ->Property("Description", BehaviorValueProperty(&AdminModels::UpdateTaskRequest::Description)) 
			    ->Property("Schedule", BehaviorValueProperty(&AdminModels::UpdateTaskRequest::Schedule)) 
			    ->Property("IsActive", BehaviorValueProperty(&AdminModels::UpdateTaskRequest::IsActive)) 
			    ->Property("Type",
				    [](AdminModels::UpdateTaskRequest* p) { return p->Type; },
				    [](AdminModels::UpdateTaskRequest* p, AdminModels::ScheduledTaskType v) { p->Type = v; })
			    ->Property("Parameter", BehaviorValueProperty(&AdminModels::UpdateTaskRequest::Parameter)) 
			;
		
			behaviorContext->Class<AdminModels::UpdateUserDataRequest>("PlayFabAdmin_UpdateUserDataRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&AdminModels::UpdateUserDataRequest::PlayFabId)) 
			    ->Property("KeysToRemove", BehaviorValueProperty(&AdminModels::UpdateUserDataRequest::KeysToRemove)) 
			    ->Property("Permission", BehaviorValueProperty(&AdminModels::UpdateUserDataRequest::Permission)) 
			;
		
			behaviorContext->Class<AdminModels::UpdateUserDataResult>("PlayFabAdmin_UpdateUserDataResult")
                ->Constructor() 
			    ->Property("DataVersion", BehaviorValueProperty(&AdminModels::UpdateUserDataResult::DataVersion)) 
			;
		
			behaviorContext->Class<AdminModels::UpdateUserInternalDataRequest>("PlayFabAdmin_UpdateUserInternalDataRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&AdminModels::UpdateUserInternalDataRequest::PlayFabId)) 
			    ->Property("KeysToRemove", BehaviorValueProperty(&AdminModels::UpdateUserInternalDataRequest::KeysToRemove)) 
			;
		
			behaviorContext->Class<AdminModels::UpdateUserTitleDisplayNameRequest>("PlayFabAdmin_UpdateUserTitleDisplayNameRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&AdminModels::UpdateUserTitleDisplayNameRequest::PlayFabId)) 
			    ->Property("DisplayName", BehaviorValueProperty(&AdminModels::UpdateUserTitleDisplayNameRequest::DisplayName)) 
			;
		
			behaviorContext->Class<AdminModels::UpdateUserTitleDisplayNameResult>("PlayFabAdmin_UpdateUserTitleDisplayNameResult")
                ->Constructor() 
			    ->Property("DisplayName", BehaviorValueProperty(&AdminModels::UpdateUserTitleDisplayNameResult::DisplayName)) 
			;
		 
				
		} // if (behaviorContext) {...
	} // End of BehaviorContext::Reflect()

}