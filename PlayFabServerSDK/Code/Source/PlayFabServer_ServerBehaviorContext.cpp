// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

#include "StdAfx.h"
#include "PlayFabServer_ServerBehaviorContext.h"
#include <AzCore/RTTI/ReflectContext.h>
#include <AzCore/RTTI/BehaviorContext.h>

#include "PlayFabServerSdk/PlayFabServer_ServerNotificationBus.h"
#include "PlayFabServerSdk/PlayFabServer_ServerBus.h"
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
    class PlayFabServer_ServerBehaviorBusBaseHandler : 
		public AZ::BehaviorEBusHandler
	{ 

    // Note that normally we would list all of the notification handler functions here using the AZ_EBUS_BEHAVIOR_BINDER macro
    // However the AZ_EBUS_BEHAVIOR_BINDER macro supports a maximum of 30 functions, so we generate the calls by hand here instead.
            
    public: 
        AZ_CLASS_ALLOCATOR(T,AZ::SystemAllocator,0)
    protected:

		enum {
			FN_OnError,
			FN_OnAuthenticateSessionTicket,
			FN_OnSetPlayerSecret,
			FN_OnBanUsers,
			FN_OnGetPlayerProfile,
			FN_OnGetPlayFabIDsFromFacebookIDs,
			FN_OnGetPlayFabIDsFromSteamIDs,
			FN_OnGetUserAccountInfo,
			FN_OnGetUserBans,
			FN_OnRevokeAllBansForUser,
			FN_OnRevokeBans,
			FN_OnSendPushNotification,
			FN_OnUpdateAvatarUrl,
			FN_OnUpdateBans,
			FN_OnDeleteUsers,
			FN_OnGetFriendLeaderboard,
			FN_OnGetLeaderboard,
			FN_OnGetLeaderboardAroundUser,
			FN_OnGetPlayerCombinedInfo,
			FN_OnGetPlayerStatistics,
			FN_OnGetPlayerStatisticVersions,
			FN_OnGetUserData,
			FN_OnGetUserInternalData,
			FN_OnGetUserPublisherData,
			FN_OnGetUserPublisherInternalData,
			FN_OnGetUserPublisherReadOnlyData,
			FN_OnGetUserReadOnlyData,
			FN_OnUpdatePlayerStatistics,
			FN_OnUpdateUserData,
			FN_OnUpdateUserInternalData,
			FN_OnUpdateUserPublisherData,
			FN_OnUpdateUserPublisherInternalData,
			FN_OnUpdateUserPublisherReadOnlyData,
			FN_OnUpdateUserReadOnlyData,
			FN_OnGetCatalogItems,
			FN_OnGetPublisherData,
			FN_OnGetTime,
			FN_OnGetTitleData,
			FN_OnGetTitleInternalData,
			FN_OnGetTitleNews,
			FN_OnSetPublisherData,
			FN_OnSetTitleData,
			FN_OnSetTitleInternalData,
			FN_OnAddCharacterVirtualCurrency,
			FN_OnAddUserVirtualCurrency,
			FN_OnConsumeItem,
			FN_OnEvaluateRandomResultTable,
			FN_OnGetCharacterInventory,
			FN_OnGetRandomResultTables,
			FN_OnGetUserInventory,
			FN_OnGrantItemsToCharacter,
			FN_OnGrantItemsToUser,
			FN_OnGrantItemsToUsers,
			FN_OnModifyItemUses,
			FN_OnMoveItemToCharacterFromCharacter,
			FN_OnMoveItemToCharacterFromUser,
			FN_OnMoveItemToUserFromCharacter,
			FN_OnRedeemCoupon,
			FN_OnReportPlayer,
			FN_OnRevokeInventoryItem,
			FN_OnSubtractCharacterVirtualCurrency,
			FN_OnSubtractUserVirtualCurrency,
			FN_OnUnlockContainerInstance,
			FN_OnUnlockContainerItem,
			FN_OnUpdateUserInventoryItemCustomData,
			FN_OnAddFriend,
			FN_OnGetFriendsList,
			FN_OnRemoveFriend,
			FN_OnSetFriendTags,
			FN_OnDeregisterGame,
			FN_OnNotifyMatchmakerPlayerLeft,
			FN_OnRedeemMatchmakerTicket,
			FN_OnRefreshGameServerInstanceHeartbeat,
			FN_OnRegisterGame,
			FN_OnSetGameServerInstanceData,
			FN_OnSetGameServerInstanceState,
			FN_OnSetGameServerInstanceTags,
			FN_OnWriteCharacterEvent,
			FN_OnWritePlayerEvent,
			FN_OnWriteTitleEvent,
			FN_OnAddSharedGroupMembers,
			FN_OnCreateSharedGroup,
			FN_OnDeleteSharedGroup,
			FN_OnGetSharedGroupData,
			FN_OnRemoveSharedGroupMembers,
			FN_OnUpdateSharedGroupData,
			FN_OnExecuteCloudScript,
			FN_OnGetContentDownloadUrl,
			FN_OnDeleteCharacterFromUser,
			FN_OnGetAllUsersCharacters,
			FN_OnGetCharacterLeaderboard,
			FN_OnGetCharacterStatistics,
			FN_OnGetLeaderboardAroundCharacter,
			FN_OnGetLeaderboardForUserCharacters,
			FN_OnGrantCharacterToUser,
			FN_OnUpdateCharacterStatistics,
			FN_OnGetCharacterData,
			FN_OnGetCharacterInternalData,
			FN_OnGetCharacterReadOnlyData,
			FN_OnUpdateCharacterData,
			FN_OnUpdateCharacterInternalData,
			FN_OnUpdateCharacterReadOnlyData,
			FN_OnAddPlayerTag,
			FN_OnGetAllActionGroups,
			FN_OnGetAllSegments,
			FN_OnGetPlayerSegments,
			FN_OnGetPlayersInSegment,
			FN_OnGetPlayerTags,
			FN_OnRemovePlayerTag,
			FN_OnAwardSteamAchievement,
			
        	FN_MAX
    	};

        int GetFunctionIndex(const char* functionName) const override {
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnError)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnAuthenticateSessionTicket)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnSetPlayerSecret)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnBanUsers)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetPlayerProfile)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetPlayFabIDsFromFacebookIDs)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetPlayFabIDsFromSteamIDs)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetUserAccountInfo)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetUserBans)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnRevokeAllBansForUser)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnRevokeBans)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnSendPushNotification)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnUpdateAvatarUrl)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnUpdateBans)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnDeleteUsers)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetFriendLeaderboard)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetLeaderboard)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetLeaderboardAroundUser)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetPlayerCombinedInfo)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetPlayerStatistics)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetPlayerStatisticVersions)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetUserData)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetUserInternalData)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetUserPublisherData)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetUserPublisherInternalData)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetUserPublisherReadOnlyData)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetUserReadOnlyData)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnUpdatePlayerStatistics)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnUpdateUserData)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnUpdateUserInternalData)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnUpdateUserPublisherData)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnUpdateUserPublisherInternalData)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnUpdateUserPublisherReadOnlyData)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnUpdateUserReadOnlyData)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetCatalogItems)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetPublisherData)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetTime)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetTitleData)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetTitleInternalData)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetTitleNews)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnSetPublisherData)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnSetTitleData)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnSetTitleInternalData)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnAddCharacterVirtualCurrency)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnAddUserVirtualCurrency)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnConsumeItem)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnEvaluateRandomResultTable)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetCharacterInventory)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetRandomResultTables)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetUserInventory)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGrantItemsToCharacter)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGrantItemsToUser)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGrantItemsToUsers)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnModifyItemUses)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnMoveItemToCharacterFromCharacter)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnMoveItemToCharacterFromUser)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnMoveItemToUserFromCharacter)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnRedeemCoupon)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnReportPlayer)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnRevokeInventoryItem)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnSubtractCharacterVirtualCurrency)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnSubtractUserVirtualCurrency)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnUnlockContainerInstance)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnUnlockContainerItem)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnUpdateUserInventoryItemCustomData)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnAddFriend)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetFriendsList)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnRemoveFriend)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnSetFriendTags)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnDeregisterGame)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnNotifyMatchmakerPlayerLeft)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnRedeemMatchmakerTicket)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnRefreshGameServerInstanceHeartbeat)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnRegisterGame)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnSetGameServerInstanceData)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnSetGameServerInstanceState)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnSetGameServerInstanceTags)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnWriteCharacterEvent)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnWritePlayerEvent)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnWriteTitleEvent)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnAddSharedGroupMembers)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnCreateSharedGroup)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnDeleteSharedGroup)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetSharedGroupData)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnRemoveSharedGroupMembers)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnUpdateSharedGroupData)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnExecuteCloudScript)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetContentDownloadUrl)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnDeleteCharacterFromUser)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetAllUsersCharacters)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetCharacterLeaderboard)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetCharacterStatistics)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetLeaderboardAroundCharacter)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetLeaderboardForUserCharacters)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGrantCharacterToUser)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnUpdateCharacterStatistics)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetCharacterData)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetCharacterInternalData)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetCharacterReadOnlyData)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnUpdateCharacterData)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnUpdateCharacterInternalData)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnUpdateCharacterReadOnlyData)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnAddPlayerTag)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetAllActionGroups)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetAllSegments)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetPlayerSegments)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetPlayersInSegment)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetPlayerTags)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnRemovePlayerTag)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnAwardSteamAchievement)
			
			return -1;
		}

        bool Connect(AZ::BehaviorValueParameter* id = nullptr) override {
			return AZ::Internal::EBusConnector<T>::Connect(static_cast<T*>(this), id);
		}

        // Constructor
        PlayFabServer_ServerBehaviorBusBaseHandler()
        {
        	m_events.resize(FN_MAX);
			SetEvent(&T::OnError,"OnError");
			SetEvent(&T::OnAuthenticateSessionTicket,"OnAuthenticateSessionTicket");
			SetEvent(&T::OnSetPlayerSecret,"OnSetPlayerSecret");
			SetEvent(&T::OnBanUsers,"OnBanUsers");
			SetEvent(&T::OnGetPlayerProfile,"OnGetPlayerProfile");
			SetEvent(&T::OnGetPlayFabIDsFromFacebookIDs,"OnGetPlayFabIDsFromFacebookIDs");
			SetEvent(&T::OnGetPlayFabIDsFromSteamIDs,"OnGetPlayFabIDsFromSteamIDs");
			SetEvent(&T::OnGetUserAccountInfo,"OnGetUserAccountInfo");
			SetEvent(&T::OnGetUserBans,"OnGetUserBans");
			SetEvent(&T::OnRevokeAllBansForUser,"OnRevokeAllBansForUser");
			SetEvent(&T::OnRevokeBans,"OnRevokeBans");
			SetEvent(&T::OnSendPushNotification,"OnSendPushNotification");
			SetEvent(&T::OnUpdateAvatarUrl,"OnUpdateAvatarUrl");
			SetEvent(&T::OnUpdateBans,"OnUpdateBans");
			SetEvent(&T::OnDeleteUsers,"OnDeleteUsers");
			SetEvent(&T::OnGetFriendLeaderboard,"OnGetFriendLeaderboard");
			SetEvent(&T::OnGetLeaderboard,"OnGetLeaderboard");
			SetEvent(&T::OnGetLeaderboardAroundUser,"OnGetLeaderboardAroundUser");
			SetEvent(&T::OnGetPlayerCombinedInfo,"OnGetPlayerCombinedInfo");
			SetEvent(&T::OnGetPlayerStatistics,"OnGetPlayerStatistics");
			SetEvent(&T::OnGetPlayerStatisticVersions,"OnGetPlayerStatisticVersions");
			SetEvent(&T::OnGetUserData,"OnGetUserData");
			SetEvent(&T::OnGetUserInternalData,"OnGetUserInternalData");
			SetEvent(&T::OnGetUserPublisherData,"OnGetUserPublisherData");
			SetEvent(&T::OnGetUserPublisherInternalData,"OnGetUserPublisherInternalData");
			SetEvent(&T::OnGetUserPublisherReadOnlyData,"OnGetUserPublisherReadOnlyData");
			SetEvent(&T::OnGetUserReadOnlyData,"OnGetUserReadOnlyData");
			SetEvent(&T::OnUpdatePlayerStatistics,"OnUpdatePlayerStatistics");
			SetEvent(&T::OnUpdateUserData,"OnUpdateUserData");
			SetEvent(&T::OnUpdateUserInternalData,"OnUpdateUserInternalData");
			SetEvent(&T::OnUpdateUserPublisherData,"OnUpdateUserPublisherData");
			SetEvent(&T::OnUpdateUserPublisherInternalData,"OnUpdateUserPublisherInternalData");
			SetEvent(&T::OnUpdateUserPublisherReadOnlyData,"OnUpdateUserPublisherReadOnlyData");
			SetEvent(&T::OnUpdateUserReadOnlyData,"OnUpdateUserReadOnlyData");
			SetEvent(&T::OnGetCatalogItems,"OnGetCatalogItems");
			SetEvent(&T::OnGetPublisherData,"OnGetPublisherData");
			SetEvent(&T::OnGetTime,"OnGetTime");
			SetEvent(&T::OnGetTitleData,"OnGetTitleData");
			SetEvent(&T::OnGetTitleInternalData,"OnGetTitleInternalData");
			SetEvent(&T::OnGetTitleNews,"OnGetTitleNews");
			SetEvent(&T::OnSetPublisherData,"OnSetPublisherData");
			SetEvent(&T::OnSetTitleData,"OnSetTitleData");
			SetEvent(&T::OnSetTitleInternalData,"OnSetTitleInternalData");
			SetEvent(&T::OnAddCharacterVirtualCurrency,"OnAddCharacterVirtualCurrency");
			SetEvent(&T::OnAddUserVirtualCurrency,"OnAddUserVirtualCurrency");
			SetEvent(&T::OnConsumeItem,"OnConsumeItem");
			SetEvent(&T::OnEvaluateRandomResultTable,"OnEvaluateRandomResultTable");
			SetEvent(&T::OnGetCharacterInventory,"OnGetCharacterInventory");
			SetEvent(&T::OnGetRandomResultTables,"OnGetRandomResultTables");
			SetEvent(&T::OnGetUserInventory,"OnGetUserInventory");
			SetEvent(&T::OnGrantItemsToCharacter,"OnGrantItemsToCharacter");
			SetEvent(&T::OnGrantItemsToUser,"OnGrantItemsToUser");
			SetEvent(&T::OnGrantItemsToUsers,"OnGrantItemsToUsers");
			SetEvent(&T::OnModifyItemUses,"OnModifyItemUses");
			SetEvent(&T::OnMoveItemToCharacterFromCharacter,"OnMoveItemToCharacterFromCharacter");
			SetEvent(&T::OnMoveItemToCharacterFromUser,"OnMoveItemToCharacterFromUser");
			SetEvent(&T::OnMoveItemToUserFromCharacter,"OnMoveItemToUserFromCharacter");
			SetEvent(&T::OnRedeemCoupon,"OnRedeemCoupon");
			SetEvent(&T::OnReportPlayer,"OnReportPlayer");
			SetEvent(&T::OnRevokeInventoryItem,"OnRevokeInventoryItem");
			SetEvent(&T::OnSubtractCharacterVirtualCurrency,"OnSubtractCharacterVirtualCurrency");
			SetEvent(&T::OnSubtractUserVirtualCurrency,"OnSubtractUserVirtualCurrency");
			SetEvent(&T::OnUnlockContainerInstance,"OnUnlockContainerInstance");
			SetEvent(&T::OnUnlockContainerItem,"OnUnlockContainerItem");
			SetEvent(&T::OnUpdateUserInventoryItemCustomData,"OnUpdateUserInventoryItemCustomData");
			SetEvent(&T::OnAddFriend,"OnAddFriend");
			SetEvent(&T::OnGetFriendsList,"OnGetFriendsList");
			SetEvent(&T::OnRemoveFriend,"OnRemoveFriend");
			SetEvent(&T::OnSetFriendTags,"OnSetFriendTags");
			SetEvent(&T::OnDeregisterGame,"OnDeregisterGame");
			SetEvent(&T::OnNotifyMatchmakerPlayerLeft,"OnNotifyMatchmakerPlayerLeft");
			SetEvent(&T::OnRedeemMatchmakerTicket,"OnRedeemMatchmakerTicket");
			SetEvent(&T::OnRefreshGameServerInstanceHeartbeat,"OnRefreshGameServerInstanceHeartbeat");
			SetEvent(&T::OnRegisterGame,"OnRegisterGame");
			SetEvent(&T::OnSetGameServerInstanceData,"OnSetGameServerInstanceData");
			SetEvent(&T::OnSetGameServerInstanceState,"OnSetGameServerInstanceState");
			SetEvent(&T::OnSetGameServerInstanceTags,"OnSetGameServerInstanceTags");
			SetEvent(&T::OnWriteCharacterEvent,"OnWriteCharacterEvent");
			SetEvent(&T::OnWritePlayerEvent,"OnWritePlayerEvent");
			SetEvent(&T::OnWriteTitleEvent,"OnWriteTitleEvent");
			SetEvent(&T::OnAddSharedGroupMembers,"OnAddSharedGroupMembers");
			SetEvent(&T::OnCreateSharedGroup,"OnCreateSharedGroup");
			SetEvent(&T::OnDeleteSharedGroup,"OnDeleteSharedGroup");
			SetEvent(&T::OnGetSharedGroupData,"OnGetSharedGroupData");
			SetEvent(&T::OnRemoveSharedGroupMembers,"OnRemoveSharedGroupMembers");
			SetEvent(&T::OnUpdateSharedGroupData,"OnUpdateSharedGroupData");
			SetEvent(&T::OnExecuteCloudScript,"OnExecuteCloudScript");
			SetEvent(&T::OnGetContentDownloadUrl,"OnGetContentDownloadUrl");
			SetEvent(&T::OnDeleteCharacterFromUser,"OnDeleteCharacterFromUser");
			SetEvent(&T::OnGetAllUsersCharacters,"OnGetAllUsersCharacters");
			SetEvent(&T::OnGetCharacterLeaderboard,"OnGetCharacterLeaderboard");
			SetEvent(&T::OnGetCharacterStatistics,"OnGetCharacterStatistics");
			SetEvent(&T::OnGetLeaderboardAroundCharacter,"OnGetLeaderboardAroundCharacter");
			SetEvent(&T::OnGetLeaderboardForUserCharacters,"OnGetLeaderboardForUserCharacters");
			SetEvent(&T::OnGrantCharacterToUser,"OnGrantCharacterToUser");
			SetEvent(&T::OnUpdateCharacterStatistics,"OnUpdateCharacterStatistics");
			SetEvent(&T::OnGetCharacterData,"OnGetCharacterData");
			SetEvent(&T::OnGetCharacterInternalData,"OnGetCharacterInternalData");
			SetEvent(&T::OnGetCharacterReadOnlyData,"OnGetCharacterReadOnlyData");
			SetEvent(&T::OnUpdateCharacterData,"OnUpdateCharacterData");
			SetEvent(&T::OnUpdateCharacterInternalData,"OnUpdateCharacterInternalData");
			SetEvent(&T::OnUpdateCharacterReadOnlyData,"OnUpdateCharacterReadOnlyData");
			SetEvent(&T::OnAddPlayerTag,"OnAddPlayerTag");
			SetEvent(&T::OnGetAllActionGroups,"OnGetAllActionGroups");
			SetEvent(&T::OnGetAllSegments,"OnGetAllSegments");
			SetEvent(&T::OnGetPlayerSegments,"OnGetPlayerSegments");
			SetEvent(&T::OnGetPlayersInSegment,"OnGetPlayersInSegment");
			SetEvent(&T::OnGetPlayerTags,"OnGetPlayerTags");
			SetEvent(&T::OnRemovePlayerTag,"OnRemovePlayerTag");
			SetEvent(&T::OnAwardSteamAchievement,"OnAwardSteamAchievement");
			
        }
        
    };

    // Behavior binder for the (request) based notification bus.
	class PlayFabServer_ServerBehaviorBusHandler : 
		public PlayFabServer_ServerNotificationBus::Handler, 
		public PlayFabServer_ServerBehaviorBusBaseHandler<PlayFabServer_ServerBehaviorBusHandler>
	{
   
	public:
        
		AZ_RTTI(PlayFabServer_ServerBehaviorBusHandler,"{57f364a5-ded7-5715-a241-720d676837d5}",AZ::BehaviorEBusHandler)

        void Disconnect() override {
			BusDisconnect();
		}
        
		void OnError(const PlayFabError& error) override
		{
			Call(FN_OnError, error);
		}

		// ------------ Generated APIs to receive from the PlayFab notification bus and forward on to the Lua behavior context.
	
		void OnAuthenticateSessionTicket(const ServerModels::AuthenticateSessionTicketResult& result) { Call(FN_OnAuthenticateSessionTicket, result); };
		void OnSetPlayerSecret(const ServerModels::SetPlayerSecretResult& result) { Call(FN_OnSetPlayerSecret, result); };
		void OnBanUsers(const ServerModels::BanUsersResult& result) { Call(FN_OnBanUsers, result); };
		void OnGetPlayerProfile(const ServerModels::GetPlayerProfileResult& result) { Call(FN_OnGetPlayerProfile, result); };
		void OnGetPlayFabIDsFromFacebookIDs(const ServerModels::GetPlayFabIDsFromFacebookIDsResult& result) { Call(FN_OnGetPlayFabIDsFromFacebookIDs, result); };
		void OnGetPlayFabIDsFromSteamIDs(const ServerModels::GetPlayFabIDsFromSteamIDsResult& result) { Call(FN_OnGetPlayFabIDsFromSteamIDs, result); };
		void OnGetUserAccountInfo(const ServerModels::GetUserAccountInfoResult& result) { Call(FN_OnGetUserAccountInfo, result); };
		void OnGetUserBans(const ServerModels::GetUserBansResult& result) { Call(FN_OnGetUserBans, result); };
		void OnRevokeAllBansForUser(const ServerModels::RevokeAllBansForUserResult& result) { Call(FN_OnRevokeAllBansForUser, result); };
		void OnRevokeBans(const ServerModels::RevokeBansResult& result) { Call(FN_OnRevokeBans, result); };
		void OnSendPushNotification(const ServerModels::SendPushNotificationResult& result) { Call(FN_OnSendPushNotification, result); };
		void OnUpdateAvatarUrl(const ServerModels::EmptyResult& result) { Call(FN_OnUpdateAvatarUrl, result); };
		void OnUpdateBans(const ServerModels::UpdateBansResult& result) { Call(FN_OnUpdateBans, result); };
		void OnDeleteUsers(const ServerModels::DeleteUsersResult& result) { Call(FN_OnDeleteUsers, result); };
		void OnGetFriendLeaderboard(const ServerModels::GetLeaderboardResult& result) { Call(FN_OnGetFriendLeaderboard, result); };
		void OnGetLeaderboard(const ServerModels::GetLeaderboardResult& result) { Call(FN_OnGetLeaderboard, result); };
		void OnGetLeaderboardAroundUser(const ServerModels::GetLeaderboardAroundUserResult& result) { Call(FN_OnGetLeaderboardAroundUser, result); };
		void OnGetPlayerCombinedInfo(const ServerModels::GetPlayerCombinedInfoResult& result) { Call(FN_OnGetPlayerCombinedInfo, result); };
		void OnGetPlayerStatistics(const ServerModels::GetPlayerStatisticsResult& result) { Call(FN_OnGetPlayerStatistics, result); };
		void OnGetPlayerStatisticVersions(const ServerModels::GetPlayerStatisticVersionsResult& result) { Call(FN_OnGetPlayerStatisticVersions, result); };
		void OnGetUserData(const ServerModels::GetUserDataResult& result) { Call(FN_OnGetUserData, result); };
		void OnGetUserInternalData(const ServerModels::GetUserDataResult& result) { Call(FN_OnGetUserInternalData, result); };
		void OnGetUserPublisherData(const ServerModels::GetUserDataResult& result) { Call(FN_OnGetUserPublisherData, result); };
		void OnGetUserPublisherInternalData(const ServerModels::GetUserDataResult& result) { Call(FN_OnGetUserPublisherInternalData, result); };
		void OnGetUserPublisherReadOnlyData(const ServerModels::GetUserDataResult& result) { Call(FN_OnGetUserPublisherReadOnlyData, result); };
		void OnGetUserReadOnlyData(const ServerModels::GetUserDataResult& result) { Call(FN_OnGetUserReadOnlyData, result); };
		void OnUpdatePlayerStatistics(const ServerModels::UpdatePlayerStatisticsResult& result) { Call(FN_OnUpdatePlayerStatistics, result); };
		void OnUpdateUserData(const ServerModels::UpdateUserDataResult& result) { Call(FN_OnUpdateUserData, result); };
		void OnUpdateUserInternalData(const ServerModels::UpdateUserDataResult& result) { Call(FN_OnUpdateUserInternalData, result); };
		void OnUpdateUserPublisherData(const ServerModels::UpdateUserDataResult& result) { Call(FN_OnUpdateUserPublisherData, result); };
		void OnUpdateUserPublisherInternalData(const ServerModels::UpdateUserDataResult& result) { Call(FN_OnUpdateUserPublisherInternalData, result); };
		void OnUpdateUserPublisherReadOnlyData(const ServerModels::UpdateUserDataResult& result) { Call(FN_OnUpdateUserPublisherReadOnlyData, result); };
		void OnUpdateUserReadOnlyData(const ServerModels::UpdateUserDataResult& result) { Call(FN_OnUpdateUserReadOnlyData, result); };
		void OnGetCatalogItems(const ServerModels::GetCatalogItemsResult& result) { Call(FN_OnGetCatalogItems, result); };
		void OnGetPublisherData(const ServerModels::GetPublisherDataResult& result) { Call(FN_OnGetPublisherData, result); };
		void OnGetTime(const ServerModels::GetTimeResult& result) { Call(FN_OnGetTime, result); };
		void OnGetTitleData(const ServerModels::GetTitleDataResult& result) { Call(FN_OnGetTitleData, result); };
		void OnGetTitleInternalData(const ServerModels::GetTitleDataResult& result) { Call(FN_OnGetTitleInternalData, result); };
		void OnGetTitleNews(const ServerModels::GetTitleNewsResult& result) { Call(FN_OnGetTitleNews, result); };
		void OnSetPublisherData(const ServerModels::SetPublisherDataResult& result) { Call(FN_OnSetPublisherData, result); };
		void OnSetTitleData(const ServerModels::SetTitleDataResult& result) { Call(FN_OnSetTitleData, result); };
		void OnSetTitleInternalData(const ServerModels::SetTitleDataResult& result) { Call(FN_OnSetTitleInternalData, result); };
		void OnAddCharacterVirtualCurrency(const ServerModels::ModifyCharacterVirtualCurrencyResult& result) { Call(FN_OnAddCharacterVirtualCurrency, result); };
		void OnAddUserVirtualCurrency(const ServerModels::ModifyUserVirtualCurrencyResult& result) { Call(FN_OnAddUserVirtualCurrency, result); };
		void OnConsumeItem(const ServerModels::ConsumeItemResult& result) { Call(FN_OnConsumeItem, result); };
		void OnEvaluateRandomResultTable(const ServerModels::EvaluateRandomResultTableResult& result) { Call(FN_OnEvaluateRandomResultTable, result); };
		void OnGetCharacterInventory(const ServerModels::GetCharacterInventoryResult& result) { Call(FN_OnGetCharacterInventory, result); };
		void OnGetRandomResultTables(const ServerModels::GetRandomResultTablesResult& result) { Call(FN_OnGetRandomResultTables, result); };
		void OnGetUserInventory(const ServerModels::GetUserInventoryResult& result) { Call(FN_OnGetUserInventory, result); };
		void OnGrantItemsToCharacter(const ServerModels::GrantItemsToCharacterResult& result) { Call(FN_OnGrantItemsToCharacter, result); };
		void OnGrantItemsToUser(const ServerModels::GrantItemsToUserResult& result) { Call(FN_OnGrantItemsToUser, result); };
		void OnGrantItemsToUsers(const ServerModels::GrantItemsToUsersResult& result) { Call(FN_OnGrantItemsToUsers, result); };
		void OnModifyItemUses(const ServerModels::ModifyItemUsesResult& result) { Call(FN_OnModifyItemUses, result); };
		void OnMoveItemToCharacterFromCharacter(const ServerModels::MoveItemToCharacterFromCharacterResult& result) { Call(FN_OnMoveItemToCharacterFromCharacter, result); };
		void OnMoveItemToCharacterFromUser(const ServerModels::MoveItemToCharacterFromUserResult& result) { Call(FN_OnMoveItemToCharacterFromUser, result); };
		void OnMoveItemToUserFromCharacter(const ServerModels::MoveItemToUserFromCharacterResult& result) { Call(FN_OnMoveItemToUserFromCharacter, result); };
		void OnRedeemCoupon(const ServerModels::RedeemCouponResult& result) { Call(FN_OnRedeemCoupon, result); };
		void OnReportPlayer(const ServerModels::ReportPlayerServerResult& result) { Call(FN_OnReportPlayer, result); };
		void OnRevokeInventoryItem(const ServerModels::RevokeInventoryResult& result) { Call(FN_OnRevokeInventoryItem, result); };
		void OnSubtractCharacterVirtualCurrency(const ServerModels::ModifyCharacterVirtualCurrencyResult& result) { Call(FN_OnSubtractCharacterVirtualCurrency, result); };
		void OnSubtractUserVirtualCurrency(const ServerModels::ModifyUserVirtualCurrencyResult& result) { Call(FN_OnSubtractUserVirtualCurrency, result); };
		void OnUnlockContainerInstance(const ServerModels::UnlockContainerItemResult& result) { Call(FN_OnUnlockContainerInstance, result); };
		void OnUnlockContainerItem(const ServerModels::UnlockContainerItemResult& result) { Call(FN_OnUnlockContainerItem, result); };
		void OnUpdateUserInventoryItemCustomData(const ServerModels::EmptyResult& result) { Call(FN_OnUpdateUserInventoryItemCustomData, result); };
		void OnAddFriend(const ServerModels::EmptyResult& result) { Call(FN_OnAddFriend, result); };
		void OnGetFriendsList(const ServerModels::GetFriendsListResult& result) { Call(FN_OnGetFriendsList, result); };
		void OnRemoveFriend(const ServerModels::EmptyResult& result) { Call(FN_OnRemoveFriend, result); };
		void OnSetFriendTags(const ServerModels::EmptyResult& result) { Call(FN_OnSetFriendTags, result); };
		void OnDeregisterGame(const ServerModels::DeregisterGameResponse& result) { Call(FN_OnDeregisterGame, result); };
		void OnNotifyMatchmakerPlayerLeft(const ServerModels::NotifyMatchmakerPlayerLeftResult& result) { Call(FN_OnNotifyMatchmakerPlayerLeft, result); };
		void OnRedeemMatchmakerTicket(const ServerModels::RedeemMatchmakerTicketResult& result) { Call(FN_OnRedeemMatchmakerTicket, result); };
		void OnRefreshGameServerInstanceHeartbeat(const ServerModels::RefreshGameServerInstanceHeartbeatResult& result) { Call(FN_OnRefreshGameServerInstanceHeartbeat, result); };
		void OnRegisterGame(const ServerModels::RegisterGameResponse& result) { Call(FN_OnRegisterGame, result); };
		void OnSetGameServerInstanceData(const ServerModels::SetGameServerInstanceDataResult& result) { Call(FN_OnSetGameServerInstanceData, result); };
		void OnSetGameServerInstanceState(const ServerModels::SetGameServerInstanceStateResult& result) { Call(FN_OnSetGameServerInstanceState, result); };
		void OnSetGameServerInstanceTags(const ServerModels::SetGameServerInstanceTagsResult& result) { Call(FN_OnSetGameServerInstanceTags, result); };
		void OnWriteCharacterEvent(const ServerModels::WriteEventResponse& result) { Call(FN_OnWriteCharacterEvent, result); };
		void OnWritePlayerEvent(const ServerModels::WriteEventResponse& result) { Call(FN_OnWritePlayerEvent, result); };
		void OnWriteTitleEvent(const ServerModels::WriteEventResponse& result) { Call(FN_OnWriteTitleEvent, result); };
		void OnAddSharedGroupMembers(const ServerModels::AddSharedGroupMembersResult& result) { Call(FN_OnAddSharedGroupMembers, result); };
		void OnCreateSharedGroup(const ServerModels::CreateSharedGroupResult& result) { Call(FN_OnCreateSharedGroup, result); };
		void OnDeleteSharedGroup(const ServerModels::EmptyResult& result) { Call(FN_OnDeleteSharedGroup, result); };
		void OnGetSharedGroupData(const ServerModels::GetSharedGroupDataResult& result) { Call(FN_OnGetSharedGroupData, result); };
		void OnRemoveSharedGroupMembers(const ServerModels::RemoveSharedGroupMembersResult& result) { Call(FN_OnRemoveSharedGroupMembers, result); };
		void OnUpdateSharedGroupData(const ServerModels::UpdateSharedGroupDataResult& result) { Call(FN_OnUpdateSharedGroupData, result); };
		void OnExecuteCloudScript(const ServerModels::ExecuteCloudScriptResult& result) { Call(FN_OnExecuteCloudScript, result); };
		void OnGetContentDownloadUrl(const ServerModels::GetContentDownloadUrlResult& result) { Call(FN_OnGetContentDownloadUrl, result); };
		void OnDeleteCharacterFromUser(const ServerModels::DeleteCharacterFromUserResult& result) { Call(FN_OnDeleteCharacterFromUser, result); };
		void OnGetAllUsersCharacters(const ServerModels::ListUsersCharactersResult& result) { Call(FN_OnGetAllUsersCharacters, result); };
		void OnGetCharacterLeaderboard(const ServerModels::GetCharacterLeaderboardResult& result) { Call(FN_OnGetCharacterLeaderboard, result); };
		void OnGetCharacterStatistics(const ServerModels::GetCharacterStatisticsResult& result) { Call(FN_OnGetCharacterStatistics, result); };
		void OnGetLeaderboardAroundCharacter(const ServerModels::GetLeaderboardAroundCharacterResult& result) { Call(FN_OnGetLeaderboardAroundCharacter, result); };
		void OnGetLeaderboardForUserCharacters(const ServerModels::GetLeaderboardForUsersCharactersResult& result) { Call(FN_OnGetLeaderboardForUserCharacters, result); };
		void OnGrantCharacterToUser(const ServerModels::GrantCharacterToUserResult& result) { Call(FN_OnGrantCharacterToUser, result); };
		void OnUpdateCharacterStatistics(const ServerModels::UpdateCharacterStatisticsResult& result) { Call(FN_OnUpdateCharacterStatistics, result); };
		void OnGetCharacterData(const ServerModels::GetCharacterDataResult& result) { Call(FN_OnGetCharacterData, result); };
		void OnGetCharacterInternalData(const ServerModels::GetCharacterDataResult& result) { Call(FN_OnGetCharacterInternalData, result); };
		void OnGetCharacterReadOnlyData(const ServerModels::GetCharacterDataResult& result) { Call(FN_OnGetCharacterReadOnlyData, result); };
		void OnUpdateCharacterData(const ServerModels::UpdateCharacterDataResult& result) { Call(FN_OnUpdateCharacterData, result); };
		void OnUpdateCharacterInternalData(const ServerModels::UpdateCharacterDataResult& result) { Call(FN_OnUpdateCharacterInternalData, result); };
		void OnUpdateCharacterReadOnlyData(const ServerModels::UpdateCharacterDataResult& result) { Call(FN_OnUpdateCharacterReadOnlyData, result); };
		void OnAddPlayerTag(const ServerModels::AddPlayerTagResult& result) { Call(FN_OnAddPlayerTag, result); };
		void OnGetAllActionGroups(const ServerModels::GetAllActionGroupsResult& result) { Call(FN_OnGetAllActionGroups, result); };
		void OnGetAllSegments(const ServerModels::GetAllSegmentsResult& result) { Call(FN_OnGetAllSegments, result); };
		void OnGetPlayerSegments(const ServerModels::GetPlayerSegmentsResult& result) { Call(FN_OnGetPlayerSegments, result); };
		void OnGetPlayersInSegment(const ServerModels::GetPlayersInSegmentResult& result) { Call(FN_OnGetPlayersInSegment, result); };
		void OnGetPlayerTags(const ServerModels::GetPlayerTagsResult& result) { Call(FN_OnGetPlayerTags, result); };
		void OnRemovePlayerTag(const ServerModels::RemovePlayerTagResult& result) { Call(FN_OnRemovePlayerTag, result); };
		void OnAwardSteamAchievement(const ServerModels::AwardSteamAchievementResult& result) { Call(FN_OnAwardSteamAchievement, result); };

	};

    // Behavior binder for the (global) based notification bus.
	class PlayFabServer_ServerGlobalBehaviorBusHandler : 
		public PlayFabServer_ServerGlobalNotificationBus::Handler, 
		public PlayFabServer_ServerBehaviorBusBaseHandler<PlayFabServer_ServerGlobalBehaviorBusHandler>
	{
   
	public:
        
		AZ_RTTI(PlayFabServer_ServerGlobalBehaviorBusHandler,"{93b9adca-98a2-5b27-850c-2de8f5ab335a}",AZ::BehaviorEBusHandler)

        void Disconnect() override {
			BusDisconnect();
		}

		void OnError(const PlayFabError& error, int requestId) override
		{
			Call(FN_OnError, error, requestId);
		}

		// ------------ Generated APIs to receive from the PlayFab notification bus and forward on to the Lua behavior context.
	
		void OnAuthenticateSessionTicket(const ServerModels::AuthenticateSessionTicketResult& result,int requestId) { Call(FN_OnAuthenticateSessionTicket, result,requestId); };
		void OnSetPlayerSecret(const ServerModels::SetPlayerSecretResult& result,int requestId) { Call(FN_OnSetPlayerSecret, result,requestId); };
		void OnBanUsers(const ServerModels::BanUsersResult& result,int requestId) { Call(FN_OnBanUsers, result,requestId); };
		void OnGetPlayerProfile(const ServerModels::GetPlayerProfileResult& result,int requestId) { Call(FN_OnGetPlayerProfile, result,requestId); };
		void OnGetPlayFabIDsFromFacebookIDs(const ServerModels::GetPlayFabIDsFromFacebookIDsResult& result,int requestId) { Call(FN_OnGetPlayFabIDsFromFacebookIDs, result,requestId); };
		void OnGetPlayFabIDsFromSteamIDs(const ServerModels::GetPlayFabIDsFromSteamIDsResult& result,int requestId) { Call(FN_OnGetPlayFabIDsFromSteamIDs, result,requestId); };
		void OnGetUserAccountInfo(const ServerModels::GetUserAccountInfoResult& result,int requestId) { Call(FN_OnGetUserAccountInfo, result,requestId); };
		void OnGetUserBans(const ServerModels::GetUserBansResult& result,int requestId) { Call(FN_OnGetUserBans, result,requestId); };
		void OnRevokeAllBansForUser(const ServerModels::RevokeAllBansForUserResult& result,int requestId) { Call(FN_OnRevokeAllBansForUser, result,requestId); };
		void OnRevokeBans(const ServerModels::RevokeBansResult& result,int requestId) { Call(FN_OnRevokeBans, result,requestId); };
		void OnSendPushNotification(const ServerModels::SendPushNotificationResult& result,int requestId) { Call(FN_OnSendPushNotification, result,requestId); };
		void OnUpdateAvatarUrl(const ServerModels::EmptyResult& result,int requestId) { Call(FN_OnUpdateAvatarUrl, result,requestId); };
		void OnUpdateBans(const ServerModels::UpdateBansResult& result,int requestId) { Call(FN_OnUpdateBans, result,requestId); };
		void OnDeleteUsers(const ServerModels::DeleteUsersResult& result,int requestId) { Call(FN_OnDeleteUsers, result,requestId); };
		void OnGetFriendLeaderboard(const ServerModels::GetLeaderboardResult& result,int requestId) { Call(FN_OnGetFriendLeaderboard, result,requestId); };
		void OnGetLeaderboard(const ServerModels::GetLeaderboardResult& result,int requestId) { Call(FN_OnGetLeaderboard, result,requestId); };
		void OnGetLeaderboardAroundUser(const ServerModels::GetLeaderboardAroundUserResult& result,int requestId) { Call(FN_OnGetLeaderboardAroundUser, result,requestId); };
		void OnGetPlayerCombinedInfo(const ServerModels::GetPlayerCombinedInfoResult& result,int requestId) { Call(FN_OnGetPlayerCombinedInfo, result,requestId); };
		void OnGetPlayerStatistics(const ServerModels::GetPlayerStatisticsResult& result,int requestId) { Call(FN_OnGetPlayerStatistics, result,requestId); };
		void OnGetPlayerStatisticVersions(const ServerModels::GetPlayerStatisticVersionsResult& result,int requestId) { Call(FN_OnGetPlayerStatisticVersions, result,requestId); };
		void OnGetUserData(const ServerModels::GetUserDataResult& result,int requestId) { Call(FN_OnGetUserData, result,requestId); };
		void OnGetUserInternalData(const ServerModels::GetUserDataResult& result,int requestId) { Call(FN_OnGetUserInternalData, result,requestId); };
		void OnGetUserPublisherData(const ServerModels::GetUserDataResult& result,int requestId) { Call(FN_OnGetUserPublisherData, result,requestId); };
		void OnGetUserPublisherInternalData(const ServerModels::GetUserDataResult& result,int requestId) { Call(FN_OnGetUserPublisherInternalData, result,requestId); };
		void OnGetUserPublisherReadOnlyData(const ServerModels::GetUserDataResult& result,int requestId) { Call(FN_OnGetUserPublisherReadOnlyData, result,requestId); };
		void OnGetUserReadOnlyData(const ServerModels::GetUserDataResult& result,int requestId) { Call(FN_OnGetUserReadOnlyData, result,requestId); };
		void OnUpdatePlayerStatistics(const ServerModels::UpdatePlayerStatisticsResult& result,int requestId) { Call(FN_OnUpdatePlayerStatistics, result,requestId); };
		void OnUpdateUserData(const ServerModels::UpdateUserDataResult& result,int requestId) { Call(FN_OnUpdateUserData, result,requestId); };
		void OnUpdateUserInternalData(const ServerModels::UpdateUserDataResult& result,int requestId) { Call(FN_OnUpdateUserInternalData, result,requestId); };
		void OnUpdateUserPublisherData(const ServerModels::UpdateUserDataResult& result,int requestId) { Call(FN_OnUpdateUserPublisherData, result,requestId); };
		void OnUpdateUserPublisherInternalData(const ServerModels::UpdateUserDataResult& result,int requestId) { Call(FN_OnUpdateUserPublisherInternalData, result,requestId); };
		void OnUpdateUserPublisherReadOnlyData(const ServerModels::UpdateUserDataResult& result,int requestId) { Call(FN_OnUpdateUserPublisherReadOnlyData, result,requestId); };
		void OnUpdateUserReadOnlyData(const ServerModels::UpdateUserDataResult& result,int requestId) { Call(FN_OnUpdateUserReadOnlyData, result,requestId); };
		void OnGetCatalogItems(const ServerModels::GetCatalogItemsResult& result,int requestId) { Call(FN_OnGetCatalogItems, result,requestId); };
		void OnGetPublisherData(const ServerModels::GetPublisherDataResult& result,int requestId) { Call(FN_OnGetPublisherData, result,requestId); };
		void OnGetTime(const ServerModels::GetTimeResult& result,int requestId) { Call(FN_OnGetTime, result,requestId); };
		void OnGetTitleData(const ServerModels::GetTitleDataResult& result,int requestId) { Call(FN_OnGetTitleData, result,requestId); };
		void OnGetTitleInternalData(const ServerModels::GetTitleDataResult& result,int requestId) { Call(FN_OnGetTitleInternalData, result,requestId); };
		void OnGetTitleNews(const ServerModels::GetTitleNewsResult& result,int requestId) { Call(FN_OnGetTitleNews, result,requestId); };
		void OnSetPublisherData(const ServerModels::SetPublisherDataResult& result,int requestId) { Call(FN_OnSetPublisherData, result,requestId); };
		void OnSetTitleData(const ServerModels::SetTitleDataResult& result,int requestId) { Call(FN_OnSetTitleData, result,requestId); };
		void OnSetTitleInternalData(const ServerModels::SetTitleDataResult& result,int requestId) { Call(FN_OnSetTitleInternalData, result,requestId); };
		void OnAddCharacterVirtualCurrency(const ServerModels::ModifyCharacterVirtualCurrencyResult& result,int requestId) { Call(FN_OnAddCharacterVirtualCurrency, result,requestId); };
		void OnAddUserVirtualCurrency(const ServerModels::ModifyUserVirtualCurrencyResult& result,int requestId) { Call(FN_OnAddUserVirtualCurrency, result,requestId); };
		void OnConsumeItem(const ServerModels::ConsumeItemResult& result,int requestId) { Call(FN_OnConsumeItem, result,requestId); };
		void OnEvaluateRandomResultTable(const ServerModels::EvaluateRandomResultTableResult& result,int requestId) { Call(FN_OnEvaluateRandomResultTable, result,requestId); };
		void OnGetCharacterInventory(const ServerModels::GetCharacterInventoryResult& result,int requestId) { Call(FN_OnGetCharacterInventory, result,requestId); };
		void OnGetRandomResultTables(const ServerModels::GetRandomResultTablesResult& result,int requestId) { Call(FN_OnGetRandomResultTables, result,requestId); };
		void OnGetUserInventory(const ServerModels::GetUserInventoryResult& result,int requestId) { Call(FN_OnGetUserInventory, result,requestId); };
		void OnGrantItemsToCharacter(const ServerModels::GrantItemsToCharacterResult& result,int requestId) { Call(FN_OnGrantItemsToCharacter, result,requestId); };
		void OnGrantItemsToUser(const ServerModels::GrantItemsToUserResult& result,int requestId) { Call(FN_OnGrantItemsToUser, result,requestId); };
		void OnGrantItemsToUsers(const ServerModels::GrantItemsToUsersResult& result,int requestId) { Call(FN_OnGrantItemsToUsers, result,requestId); };
		void OnModifyItemUses(const ServerModels::ModifyItemUsesResult& result,int requestId) { Call(FN_OnModifyItemUses, result,requestId); };
		void OnMoveItemToCharacterFromCharacter(const ServerModels::MoveItemToCharacterFromCharacterResult& result,int requestId) { Call(FN_OnMoveItemToCharacterFromCharacter, result,requestId); };
		void OnMoveItemToCharacterFromUser(const ServerModels::MoveItemToCharacterFromUserResult& result,int requestId) { Call(FN_OnMoveItemToCharacterFromUser, result,requestId); };
		void OnMoveItemToUserFromCharacter(const ServerModels::MoveItemToUserFromCharacterResult& result,int requestId) { Call(FN_OnMoveItemToUserFromCharacter, result,requestId); };
		void OnRedeemCoupon(const ServerModels::RedeemCouponResult& result,int requestId) { Call(FN_OnRedeemCoupon, result,requestId); };
		void OnReportPlayer(const ServerModels::ReportPlayerServerResult& result,int requestId) { Call(FN_OnReportPlayer, result,requestId); };
		void OnRevokeInventoryItem(const ServerModels::RevokeInventoryResult& result,int requestId) { Call(FN_OnRevokeInventoryItem, result,requestId); };
		void OnSubtractCharacterVirtualCurrency(const ServerModels::ModifyCharacterVirtualCurrencyResult& result,int requestId) { Call(FN_OnSubtractCharacterVirtualCurrency, result,requestId); };
		void OnSubtractUserVirtualCurrency(const ServerModels::ModifyUserVirtualCurrencyResult& result,int requestId) { Call(FN_OnSubtractUserVirtualCurrency, result,requestId); };
		void OnUnlockContainerInstance(const ServerModels::UnlockContainerItemResult& result,int requestId) { Call(FN_OnUnlockContainerInstance, result,requestId); };
		void OnUnlockContainerItem(const ServerModels::UnlockContainerItemResult& result,int requestId) { Call(FN_OnUnlockContainerItem, result,requestId); };
		void OnUpdateUserInventoryItemCustomData(const ServerModels::EmptyResult& result,int requestId) { Call(FN_OnUpdateUserInventoryItemCustomData, result,requestId); };
		void OnAddFriend(const ServerModels::EmptyResult& result,int requestId) { Call(FN_OnAddFriend, result,requestId); };
		void OnGetFriendsList(const ServerModels::GetFriendsListResult& result,int requestId) { Call(FN_OnGetFriendsList, result,requestId); };
		void OnRemoveFriend(const ServerModels::EmptyResult& result,int requestId) { Call(FN_OnRemoveFriend, result,requestId); };
		void OnSetFriendTags(const ServerModels::EmptyResult& result,int requestId) { Call(FN_OnSetFriendTags, result,requestId); };
		void OnDeregisterGame(const ServerModels::DeregisterGameResponse& result,int requestId) { Call(FN_OnDeregisterGame, result,requestId); };
		void OnNotifyMatchmakerPlayerLeft(const ServerModels::NotifyMatchmakerPlayerLeftResult& result,int requestId) { Call(FN_OnNotifyMatchmakerPlayerLeft, result,requestId); };
		void OnRedeemMatchmakerTicket(const ServerModels::RedeemMatchmakerTicketResult& result,int requestId) { Call(FN_OnRedeemMatchmakerTicket, result,requestId); };
		void OnRefreshGameServerInstanceHeartbeat(const ServerModels::RefreshGameServerInstanceHeartbeatResult& result,int requestId) { Call(FN_OnRefreshGameServerInstanceHeartbeat, result,requestId); };
		void OnRegisterGame(const ServerModels::RegisterGameResponse& result,int requestId) { Call(FN_OnRegisterGame, result,requestId); };
		void OnSetGameServerInstanceData(const ServerModels::SetGameServerInstanceDataResult& result,int requestId) { Call(FN_OnSetGameServerInstanceData, result,requestId); };
		void OnSetGameServerInstanceState(const ServerModels::SetGameServerInstanceStateResult& result,int requestId) { Call(FN_OnSetGameServerInstanceState, result,requestId); };
		void OnSetGameServerInstanceTags(const ServerModels::SetGameServerInstanceTagsResult& result,int requestId) { Call(FN_OnSetGameServerInstanceTags, result,requestId); };
		void OnWriteCharacterEvent(const ServerModels::WriteEventResponse& result,int requestId) { Call(FN_OnWriteCharacterEvent, result,requestId); };
		void OnWritePlayerEvent(const ServerModels::WriteEventResponse& result,int requestId) { Call(FN_OnWritePlayerEvent, result,requestId); };
		void OnWriteTitleEvent(const ServerModels::WriteEventResponse& result,int requestId) { Call(FN_OnWriteTitleEvent, result,requestId); };
		void OnAddSharedGroupMembers(const ServerModels::AddSharedGroupMembersResult& result,int requestId) { Call(FN_OnAddSharedGroupMembers, result,requestId); };
		void OnCreateSharedGroup(const ServerModels::CreateSharedGroupResult& result,int requestId) { Call(FN_OnCreateSharedGroup, result,requestId); };
		void OnDeleteSharedGroup(const ServerModels::EmptyResult& result,int requestId) { Call(FN_OnDeleteSharedGroup, result,requestId); };
		void OnGetSharedGroupData(const ServerModels::GetSharedGroupDataResult& result,int requestId) { Call(FN_OnGetSharedGroupData, result,requestId); };
		void OnRemoveSharedGroupMembers(const ServerModels::RemoveSharedGroupMembersResult& result,int requestId) { Call(FN_OnRemoveSharedGroupMembers, result,requestId); };
		void OnUpdateSharedGroupData(const ServerModels::UpdateSharedGroupDataResult& result,int requestId) { Call(FN_OnUpdateSharedGroupData, result,requestId); };
		void OnExecuteCloudScript(const ServerModels::ExecuteCloudScriptResult& result,int requestId) { Call(FN_OnExecuteCloudScript, result,requestId); };
		void OnGetContentDownloadUrl(const ServerModels::GetContentDownloadUrlResult& result,int requestId) { Call(FN_OnGetContentDownloadUrl, result,requestId); };
		void OnDeleteCharacterFromUser(const ServerModels::DeleteCharacterFromUserResult& result,int requestId) { Call(FN_OnDeleteCharacterFromUser, result,requestId); };
		void OnGetAllUsersCharacters(const ServerModels::ListUsersCharactersResult& result,int requestId) { Call(FN_OnGetAllUsersCharacters, result,requestId); };
		void OnGetCharacterLeaderboard(const ServerModels::GetCharacterLeaderboardResult& result,int requestId) { Call(FN_OnGetCharacterLeaderboard, result,requestId); };
		void OnGetCharacterStatistics(const ServerModels::GetCharacterStatisticsResult& result,int requestId) { Call(FN_OnGetCharacterStatistics, result,requestId); };
		void OnGetLeaderboardAroundCharacter(const ServerModels::GetLeaderboardAroundCharacterResult& result,int requestId) { Call(FN_OnGetLeaderboardAroundCharacter, result,requestId); };
		void OnGetLeaderboardForUserCharacters(const ServerModels::GetLeaderboardForUsersCharactersResult& result,int requestId) { Call(FN_OnGetLeaderboardForUserCharacters, result,requestId); };
		void OnGrantCharacterToUser(const ServerModels::GrantCharacterToUserResult& result,int requestId) { Call(FN_OnGrantCharacterToUser, result,requestId); };
		void OnUpdateCharacterStatistics(const ServerModels::UpdateCharacterStatisticsResult& result,int requestId) { Call(FN_OnUpdateCharacterStatistics, result,requestId); };
		void OnGetCharacterData(const ServerModels::GetCharacterDataResult& result,int requestId) { Call(FN_OnGetCharacterData, result,requestId); };
		void OnGetCharacterInternalData(const ServerModels::GetCharacterDataResult& result,int requestId) { Call(FN_OnGetCharacterInternalData, result,requestId); };
		void OnGetCharacterReadOnlyData(const ServerModels::GetCharacterDataResult& result,int requestId) { Call(FN_OnGetCharacterReadOnlyData, result,requestId); };
		void OnUpdateCharacterData(const ServerModels::UpdateCharacterDataResult& result,int requestId) { Call(FN_OnUpdateCharacterData, result,requestId); };
		void OnUpdateCharacterInternalData(const ServerModels::UpdateCharacterDataResult& result,int requestId) { Call(FN_OnUpdateCharacterInternalData, result,requestId); };
		void OnUpdateCharacterReadOnlyData(const ServerModels::UpdateCharacterDataResult& result,int requestId) { Call(FN_OnUpdateCharacterReadOnlyData, result,requestId); };
		void OnAddPlayerTag(const ServerModels::AddPlayerTagResult& result,int requestId) { Call(FN_OnAddPlayerTag, result,requestId); };
		void OnGetAllActionGroups(const ServerModels::GetAllActionGroupsResult& result,int requestId) { Call(FN_OnGetAllActionGroups, result,requestId); };
		void OnGetAllSegments(const ServerModels::GetAllSegmentsResult& result,int requestId) { Call(FN_OnGetAllSegments, result,requestId); };
		void OnGetPlayerSegments(const ServerModels::GetPlayerSegmentsResult& result,int requestId) { Call(FN_OnGetPlayerSegments, result,requestId); };
		void OnGetPlayersInSegment(const ServerModels::GetPlayersInSegmentResult& result,int requestId) { Call(FN_OnGetPlayersInSegment, result,requestId); };
		void OnGetPlayerTags(const ServerModels::GetPlayerTagsResult& result,int requestId) { Call(FN_OnGetPlayerTags, result,requestId); };
		void OnRemovePlayerTag(const ServerModels::RemovePlayerTagResult& result,int requestId) { Call(FN_OnRemovePlayerTag, result,requestId); };
		void OnAwardSteamAchievement(const ServerModels::AwardSteamAchievementResult& result,int requestId) { Call(FN_OnAwardSteamAchievement, result,requestId); };

	};

    //-----------------------------------------------------------------------------------------------------
    // MAIN REFLECTION FUNCTION
    //-----------------------------------------------------------------------------------------------------
	void PlayFabServer_ServerBehaviorContext::Reflect(AZ::ReflectContext* context)
	{
		AZ::BehaviorContext* behaviorContext = azrtti_cast<AZ::BehaviorContext*>(context);
		if (behaviorContext)
		{
			// Reflect the request bus
			behaviorContext->EBus<PlayFabServer_ServerSimpleRequestBus>("PlayFabServerRequestBus")
				->Event("AuthenticateSessionTicket", &PlayFabServer_ServerSimpleRequestBus::Events::AuthenticateSessionTicket)
				->Event("SetPlayerSecret", &PlayFabServer_ServerSimpleRequestBus::Events::SetPlayerSecret)
				->Event("BanUsers", &PlayFabServer_ServerSimpleRequestBus::Events::BanUsers)
				->Event("GetPlayerProfile", &PlayFabServer_ServerSimpleRequestBus::Events::GetPlayerProfile)
				->Event("GetPlayFabIDsFromFacebookIDs", &PlayFabServer_ServerSimpleRequestBus::Events::GetPlayFabIDsFromFacebookIDs)
				->Event("GetPlayFabIDsFromSteamIDs", &PlayFabServer_ServerSimpleRequestBus::Events::GetPlayFabIDsFromSteamIDs)
				->Event("GetUserAccountInfo", &PlayFabServer_ServerSimpleRequestBus::Events::GetUserAccountInfo)
				->Event("GetUserBans", &PlayFabServer_ServerSimpleRequestBus::Events::GetUserBans)
				->Event("RevokeAllBansForUser", &PlayFabServer_ServerSimpleRequestBus::Events::RevokeAllBansForUser)
				->Event("RevokeBans", &PlayFabServer_ServerSimpleRequestBus::Events::RevokeBans)
				->Event("SendPushNotification", &PlayFabServer_ServerSimpleRequestBus::Events::SendPushNotification)
				->Event("UpdateAvatarUrl", &PlayFabServer_ServerSimpleRequestBus::Events::UpdateAvatarUrl)
				->Event("UpdateBans", &PlayFabServer_ServerSimpleRequestBus::Events::UpdateBans)
				->Event("DeleteUsers", &PlayFabServer_ServerSimpleRequestBus::Events::DeleteUsers)
				->Event("GetFriendLeaderboard", &PlayFabServer_ServerSimpleRequestBus::Events::GetFriendLeaderboard)
				->Event("GetLeaderboard", &PlayFabServer_ServerSimpleRequestBus::Events::GetLeaderboard)
				->Event("GetLeaderboardAroundUser", &PlayFabServer_ServerSimpleRequestBus::Events::GetLeaderboardAroundUser)
				->Event("GetPlayerCombinedInfo", &PlayFabServer_ServerSimpleRequestBus::Events::GetPlayerCombinedInfo)
				->Event("GetPlayerStatistics", &PlayFabServer_ServerSimpleRequestBus::Events::GetPlayerStatistics)
				->Event("GetPlayerStatisticVersions", &PlayFabServer_ServerSimpleRequestBus::Events::GetPlayerStatisticVersions)
				->Event("GetUserData", &PlayFabServer_ServerSimpleRequestBus::Events::GetUserData)
				->Event("GetUserInternalData", &PlayFabServer_ServerSimpleRequestBus::Events::GetUserInternalData)
				->Event("GetUserPublisherData", &PlayFabServer_ServerSimpleRequestBus::Events::GetUserPublisherData)
				->Event("GetUserPublisherInternalData", &PlayFabServer_ServerSimpleRequestBus::Events::GetUserPublisherInternalData)
				->Event("GetUserPublisherReadOnlyData", &PlayFabServer_ServerSimpleRequestBus::Events::GetUserPublisherReadOnlyData)
				->Event("GetUserReadOnlyData", &PlayFabServer_ServerSimpleRequestBus::Events::GetUserReadOnlyData)
				->Event("UpdatePlayerStatistics", &PlayFabServer_ServerSimpleRequestBus::Events::UpdatePlayerStatistics)
				->Event("UpdateUserData", &PlayFabServer_ServerSimpleRequestBus::Events::UpdateUserData)
				->Event("UpdateUserInternalData", &PlayFabServer_ServerSimpleRequestBus::Events::UpdateUserInternalData)
				->Event("UpdateUserPublisherData", &PlayFabServer_ServerSimpleRequestBus::Events::UpdateUserPublisherData)
				->Event("UpdateUserPublisherInternalData", &PlayFabServer_ServerSimpleRequestBus::Events::UpdateUserPublisherInternalData)
				->Event("UpdateUserPublisherReadOnlyData", &PlayFabServer_ServerSimpleRequestBus::Events::UpdateUserPublisherReadOnlyData)
				->Event("UpdateUserReadOnlyData", &PlayFabServer_ServerSimpleRequestBus::Events::UpdateUserReadOnlyData)
				->Event("GetCatalogItems", &PlayFabServer_ServerSimpleRequestBus::Events::GetCatalogItems)
				->Event("GetPublisherData", &PlayFabServer_ServerSimpleRequestBus::Events::GetPublisherData)
				->Event("GetTime", &PlayFabServer_ServerSimpleRequestBus::Events::GetTime)
				->Event("GetTitleData", &PlayFabServer_ServerSimpleRequestBus::Events::GetTitleData)
				->Event("GetTitleInternalData", &PlayFabServer_ServerSimpleRequestBus::Events::GetTitleInternalData)
				->Event("GetTitleNews", &PlayFabServer_ServerSimpleRequestBus::Events::GetTitleNews)
				->Event("SetPublisherData", &PlayFabServer_ServerSimpleRequestBus::Events::SetPublisherData)
				->Event("SetTitleData", &PlayFabServer_ServerSimpleRequestBus::Events::SetTitleData)
				->Event("SetTitleInternalData", &PlayFabServer_ServerSimpleRequestBus::Events::SetTitleInternalData)
				->Event("AddCharacterVirtualCurrency", &PlayFabServer_ServerSimpleRequestBus::Events::AddCharacterVirtualCurrency)
				->Event("AddUserVirtualCurrency", &PlayFabServer_ServerSimpleRequestBus::Events::AddUserVirtualCurrency)
				->Event("ConsumeItem", &PlayFabServer_ServerSimpleRequestBus::Events::ConsumeItem)
				->Event("EvaluateRandomResultTable", &PlayFabServer_ServerSimpleRequestBus::Events::EvaluateRandomResultTable)
				->Event("GetCharacterInventory", &PlayFabServer_ServerSimpleRequestBus::Events::GetCharacterInventory)
				->Event("GetRandomResultTables", &PlayFabServer_ServerSimpleRequestBus::Events::GetRandomResultTables)
				->Event("GetUserInventory", &PlayFabServer_ServerSimpleRequestBus::Events::GetUserInventory)
				->Event("GrantItemsToCharacter", &PlayFabServer_ServerSimpleRequestBus::Events::GrantItemsToCharacter)
				->Event("GrantItemsToUser", &PlayFabServer_ServerSimpleRequestBus::Events::GrantItemsToUser)
				->Event("GrantItemsToUsers", &PlayFabServer_ServerSimpleRequestBus::Events::GrantItemsToUsers)
				->Event("ModifyItemUses", &PlayFabServer_ServerSimpleRequestBus::Events::ModifyItemUses)
				->Event("MoveItemToCharacterFromCharacter", &PlayFabServer_ServerSimpleRequestBus::Events::MoveItemToCharacterFromCharacter)
				->Event("MoveItemToCharacterFromUser", &PlayFabServer_ServerSimpleRequestBus::Events::MoveItemToCharacterFromUser)
				->Event("MoveItemToUserFromCharacter", &PlayFabServer_ServerSimpleRequestBus::Events::MoveItemToUserFromCharacter)
				->Event("RedeemCoupon", &PlayFabServer_ServerSimpleRequestBus::Events::RedeemCoupon)
				->Event("ReportPlayer", &PlayFabServer_ServerSimpleRequestBus::Events::ReportPlayer)
				->Event("RevokeInventoryItem", &PlayFabServer_ServerSimpleRequestBus::Events::RevokeInventoryItem)
				->Event("SubtractCharacterVirtualCurrency", &PlayFabServer_ServerSimpleRequestBus::Events::SubtractCharacterVirtualCurrency)
				->Event("SubtractUserVirtualCurrency", &PlayFabServer_ServerSimpleRequestBus::Events::SubtractUserVirtualCurrency)
				->Event("UnlockContainerInstance", &PlayFabServer_ServerSimpleRequestBus::Events::UnlockContainerInstance)
				->Event("UnlockContainerItem", &PlayFabServer_ServerSimpleRequestBus::Events::UnlockContainerItem)
				->Event("UpdateUserInventoryItemCustomData", &PlayFabServer_ServerSimpleRequestBus::Events::UpdateUserInventoryItemCustomData)
				->Event("AddFriend", &PlayFabServer_ServerSimpleRequestBus::Events::AddFriend)
				->Event("GetFriendsList", &PlayFabServer_ServerSimpleRequestBus::Events::GetFriendsList)
				->Event("RemoveFriend", &PlayFabServer_ServerSimpleRequestBus::Events::RemoveFriend)
				->Event("SetFriendTags", &PlayFabServer_ServerSimpleRequestBus::Events::SetFriendTags)
				->Event("DeregisterGame", &PlayFabServer_ServerSimpleRequestBus::Events::DeregisterGame)
				->Event("NotifyMatchmakerPlayerLeft", &PlayFabServer_ServerSimpleRequestBus::Events::NotifyMatchmakerPlayerLeft)
				->Event("RedeemMatchmakerTicket", &PlayFabServer_ServerSimpleRequestBus::Events::RedeemMatchmakerTicket)
				->Event("RefreshGameServerInstanceHeartbeat", &PlayFabServer_ServerSimpleRequestBus::Events::RefreshGameServerInstanceHeartbeat)
				->Event("RegisterGame", &PlayFabServer_ServerSimpleRequestBus::Events::RegisterGame)
				->Event("SetGameServerInstanceData", &PlayFabServer_ServerSimpleRequestBus::Events::SetGameServerInstanceData)
				->Event("SetGameServerInstanceState", &PlayFabServer_ServerSimpleRequestBus::Events::SetGameServerInstanceState)
				->Event("SetGameServerInstanceTags", &PlayFabServer_ServerSimpleRequestBus::Events::SetGameServerInstanceTags)
				->Event("WriteCharacterEvent", &PlayFabServer_ServerSimpleRequestBus::Events::WriteCharacterEvent)
				->Event("WritePlayerEvent", &PlayFabServer_ServerSimpleRequestBus::Events::WritePlayerEvent)
				->Event("WriteTitleEvent", &PlayFabServer_ServerSimpleRequestBus::Events::WriteTitleEvent)
				->Event("AddSharedGroupMembers", &PlayFabServer_ServerSimpleRequestBus::Events::AddSharedGroupMembers)
				->Event("CreateSharedGroup", &PlayFabServer_ServerSimpleRequestBus::Events::CreateSharedGroup)
				->Event("DeleteSharedGroup", &PlayFabServer_ServerSimpleRequestBus::Events::DeleteSharedGroup)
				->Event("GetSharedGroupData", &PlayFabServer_ServerSimpleRequestBus::Events::GetSharedGroupData)
				->Event("RemoveSharedGroupMembers", &PlayFabServer_ServerSimpleRequestBus::Events::RemoveSharedGroupMembers)
				->Event("UpdateSharedGroupData", &PlayFabServer_ServerSimpleRequestBus::Events::UpdateSharedGroupData)
				->Event("ExecuteCloudScript", &PlayFabServer_ServerSimpleRequestBus::Events::ExecuteCloudScript)
				->Event("GetContentDownloadUrl", &PlayFabServer_ServerSimpleRequestBus::Events::GetContentDownloadUrl)
				->Event("DeleteCharacterFromUser", &PlayFabServer_ServerSimpleRequestBus::Events::DeleteCharacterFromUser)
				->Event("GetAllUsersCharacters", &PlayFabServer_ServerSimpleRequestBus::Events::GetAllUsersCharacters)
				->Event("GetCharacterLeaderboard", &PlayFabServer_ServerSimpleRequestBus::Events::GetCharacterLeaderboard)
				->Event("GetCharacterStatistics", &PlayFabServer_ServerSimpleRequestBus::Events::GetCharacterStatistics)
				->Event("GetLeaderboardAroundCharacter", &PlayFabServer_ServerSimpleRequestBus::Events::GetLeaderboardAroundCharacter)
				->Event("GetLeaderboardForUserCharacters", &PlayFabServer_ServerSimpleRequestBus::Events::GetLeaderboardForUserCharacters)
				->Event("GrantCharacterToUser", &PlayFabServer_ServerSimpleRequestBus::Events::GrantCharacterToUser)
				->Event("UpdateCharacterStatistics", &PlayFabServer_ServerSimpleRequestBus::Events::UpdateCharacterStatistics)
				->Event("GetCharacterData", &PlayFabServer_ServerSimpleRequestBus::Events::GetCharacterData)
				->Event("GetCharacterInternalData", &PlayFabServer_ServerSimpleRequestBus::Events::GetCharacterInternalData)
				->Event("GetCharacterReadOnlyData", &PlayFabServer_ServerSimpleRequestBus::Events::GetCharacterReadOnlyData)
				->Event("UpdateCharacterData", &PlayFabServer_ServerSimpleRequestBus::Events::UpdateCharacterData)
				->Event("UpdateCharacterInternalData", &PlayFabServer_ServerSimpleRequestBus::Events::UpdateCharacterInternalData)
				->Event("UpdateCharacterReadOnlyData", &PlayFabServer_ServerSimpleRequestBus::Events::UpdateCharacterReadOnlyData)
				->Event("AddPlayerTag", &PlayFabServer_ServerSimpleRequestBus::Events::AddPlayerTag)
				->Event("GetAllActionGroups", &PlayFabServer_ServerSimpleRequestBus::Events::GetAllActionGroups)
				->Event("GetAllSegments", &PlayFabServer_ServerSimpleRequestBus::Events::GetAllSegments)
				->Event("GetPlayerSegments", &PlayFabServer_ServerSimpleRequestBus::Events::GetPlayerSegments)
				->Event("GetPlayersInSegment", &PlayFabServer_ServerSimpleRequestBus::Events::GetPlayersInSegment)
				->Event("GetPlayerTags", &PlayFabServer_ServerSimpleRequestBus::Events::GetPlayerTags)
				->Event("RemovePlayerTag", &PlayFabServer_ServerSimpleRequestBus::Events::RemovePlayerTag)
				->Event("AwardSteamAchievement", &PlayFabServer_ServerSimpleRequestBus::Events::AwardSteamAchievement);

			// Reflect the ADDRESSED notification bus: (uses the BehaviorBusHandler declared at the beginning of this file)
			behaviorContext->EBus<PlayFabServer_ServerNotificationBus>("PlayFabServerNotificationBus")
				->Handler<PlayFabServer_ServerBehaviorBusHandler>();

			// Reflect the GLOBAL notification bus: (uses the BehaviorBusHandler declared at the beginning of this file)
			behaviorContext->EBus<PlayFabServer_ServerGlobalNotificationBus>("PlayFabServerGlobalNotificationBus")
				->Handler<PlayFabServer_ServerGlobalBehaviorBusHandler>();                
			
            //-----------------------------------------------------------------------------------------------------
			// Reflect enum values
            //-----------------------------------------------------------------------------------------------------
	        behaviorContext 
                ->Enum<ServerModels::TaskInstanceStatus::TaskInstanceStatusSucceeded>( "PlayFabServer_TaskInstanceStatus_Succeeded" )
                ->Enum<ServerModels::TaskInstanceStatus::TaskInstanceStatusStarting>( "PlayFabServer_TaskInstanceStatus_Starting" )
                ->Enum<ServerModels::TaskInstanceStatus::TaskInstanceStatusInProgress>( "PlayFabServer_TaskInstanceStatus_InProgress" )
                ->Enum<ServerModels::TaskInstanceStatus::TaskInstanceStatusFailed>( "PlayFabServer_TaskInstanceStatus_Failed" )
                ->Enum<ServerModels::TaskInstanceStatus::TaskInstanceStatusAborted>( "PlayFabServer_TaskInstanceStatus_Aborted" )
                ->Enum<ServerModels::TaskInstanceStatus::TaskInstanceStatusPending>( "PlayFabServer_TaskInstanceStatus_Pending" )
            ;
            behaviorContext 
                ->Enum<ServerModels::UserOrigination::UserOriginationOrganic>( "PlayFabServer_UserOrigination_Organic" )
                ->Enum<ServerModels::UserOrigination::UserOriginationSteam>( "PlayFabServer_UserOrigination_Steam" )
                ->Enum<ServerModels::UserOrigination::UserOriginationGoogle>( "PlayFabServer_UserOrigination_Google" )
                ->Enum<ServerModels::UserOrigination::UserOriginationAmazon>( "PlayFabServer_UserOrigination_Amazon" )
                ->Enum<ServerModels::UserOrigination::UserOriginationFacebook>( "PlayFabServer_UserOrigination_Facebook" )
                ->Enum<ServerModels::UserOrigination::UserOriginationKongregate>( "PlayFabServer_UserOrigination_Kongregate" )
                ->Enum<ServerModels::UserOrigination::UserOriginationGamersFirst>( "PlayFabServer_UserOrigination_GamersFirst" )
                ->Enum<ServerModels::UserOrigination::UserOriginationUnknown>( "PlayFabServer_UserOrigination_Unknown" )
                ->Enum<ServerModels::UserOrigination::UserOriginationIOS>( "PlayFabServer_UserOrigination_IOS" )
                ->Enum<ServerModels::UserOrigination::UserOriginationLoadTest>( "PlayFabServer_UserOrigination_LoadTest" )
                ->Enum<ServerModels::UserOrigination::UserOriginationAndroid>( "PlayFabServer_UserOrigination_Android" )
                ->Enum<ServerModels::UserOrigination::UserOriginationPSN>( "PlayFabServer_UserOrigination_PSN" )
                ->Enum<ServerModels::UserOrigination::UserOriginationGameCenter>( "PlayFabServer_UserOrigination_GameCenter" )
                ->Enum<ServerModels::UserOrigination::UserOriginationCustomId>( "PlayFabServer_UserOrigination_CustomId" )
                ->Enum<ServerModels::UserOrigination::UserOriginationXboxLive>( "PlayFabServer_UserOrigination_XboxLive" )
                ->Enum<ServerModels::UserOrigination::UserOriginationParse>( "PlayFabServer_UserOrigination_Parse" )
                ->Enum<ServerModels::UserOrigination::UserOriginationTwitch>( "PlayFabServer_UserOrigination_Twitch" )
                ->Enum<ServerModels::UserOrigination::UserOriginationWindowsHello>( "PlayFabServer_UserOrigination_WindowsHello" )
            ;
            behaviorContext 
                ->Enum<ServerModels::Currency::CurrencyAED>( "PlayFabServer_Currency_AED" )
                ->Enum<ServerModels::Currency::CurrencyAFN>( "PlayFabServer_Currency_AFN" )
                ->Enum<ServerModels::Currency::CurrencyALL>( "PlayFabServer_Currency_ALL" )
                ->Enum<ServerModels::Currency::CurrencyAMD>( "PlayFabServer_Currency_AMD" )
                ->Enum<ServerModels::Currency::CurrencyANG>( "PlayFabServer_Currency_ANG" )
                ->Enum<ServerModels::Currency::CurrencyAOA>( "PlayFabServer_Currency_AOA" )
                ->Enum<ServerModels::Currency::CurrencyARS>( "PlayFabServer_Currency_ARS" )
                ->Enum<ServerModels::Currency::CurrencyAUD>( "PlayFabServer_Currency_AUD" )
                ->Enum<ServerModels::Currency::CurrencyAWG>( "PlayFabServer_Currency_AWG" )
                ->Enum<ServerModels::Currency::CurrencyAZN>( "PlayFabServer_Currency_AZN" )
                ->Enum<ServerModels::Currency::CurrencyBAM>( "PlayFabServer_Currency_BAM" )
                ->Enum<ServerModels::Currency::CurrencyBBD>( "PlayFabServer_Currency_BBD" )
                ->Enum<ServerModels::Currency::CurrencyBDT>( "PlayFabServer_Currency_BDT" )
                ->Enum<ServerModels::Currency::CurrencyBGN>( "PlayFabServer_Currency_BGN" )
                ->Enum<ServerModels::Currency::CurrencyBHD>( "PlayFabServer_Currency_BHD" )
                ->Enum<ServerModels::Currency::CurrencyBIF>( "PlayFabServer_Currency_BIF" )
                ->Enum<ServerModels::Currency::CurrencyBMD>( "PlayFabServer_Currency_BMD" )
                ->Enum<ServerModels::Currency::CurrencyBND>( "PlayFabServer_Currency_BND" )
                ->Enum<ServerModels::Currency::CurrencyBOB>( "PlayFabServer_Currency_BOB" )
                ->Enum<ServerModels::Currency::CurrencyBRL>( "PlayFabServer_Currency_BRL" )
                ->Enum<ServerModels::Currency::CurrencyBSD>( "PlayFabServer_Currency_BSD" )
                ->Enum<ServerModels::Currency::CurrencyBTN>( "PlayFabServer_Currency_BTN" )
                ->Enum<ServerModels::Currency::CurrencyBWP>( "PlayFabServer_Currency_BWP" )
                ->Enum<ServerModels::Currency::CurrencyBYR>( "PlayFabServer_Currency_BYR" )
                ->Enum<ServerModels::Currency::CurrencyBZD>( "PlayFabServer_Currency_BZD" )
                ->Enum<ServerModels::Currency::CurrencyCAD>( "PlayFabServer_Currency_CAD" )
                ->Enum<ServerModels::Currency::CurrencyCDF>( "PlayFabServer_Currency_CDF" )
                ->Enum<ServerModels::Currency::CurrencyCHF>( "PlayFabServer_Currency_CHF" )
                ->Enum<ServerModels::Currency::CurrencyCLP>( "PlayFabServer_Currency_CLP" )
                ->Enum<ServerModels::Currency::CurrencyCNY>( "PlayFabServer_Currency_CNY" )
                ->Enum<ServerModels::Currency::CurrencyCOP>( "PlayFabServer_Currency_COP" )
                ->Enum<ServerModels::Currency::CurrencyCRC>( "PlayFabServer_Currency_CRC" )
                ->Enum<ServerModels::Currency::CurrencyCUC>( "PlayFabServer_Currency_CUC" )
                ->Enum<ServerModels::Currency::CurrencyCUP>( "PlayFabServer_Currency_CUP" )
                ->Enum<ServerModels::Currency::CurrencyCVE>( "PlayFabServer_Currency_CVE" )
                ->Enum<ServerModels::Currency::CurrencyCZK>( "PlayFabServer_Currency_CZK" )
                ->Enum<ServerModels::Currency::CurrencyDJF>( "PlayFabServer_Currency_DJF" )
                ->Enum<ServerModels::Currency::CurrencyDKK>( "PlayFabServer_Currency_DKK" )
                ->Enum<ServerModels::Currency::CurrencyDOP>( "PlayFabServer_Currency_DOP" )
                ->Enum<ServerModels::Currency::CurrencyDZD>( "PlayFabServer_Currency_DZD" )
                ->Enum<ServerModels::Currency::CurrencyEGP>( "PlayFabServer_Currency_EGP" )
                ->Enum<ServerModels::Currency::CurrencyERN>( "PlayFabServer_Currency_ERN" )
                ->Enum<ServerModels::Currency::CurrencyETB>( "PlayFabServer_Currency_ETB" )
                ->Enum<ServerModels::Currency::CurrencyEUR>( "PlayFabServer_Currency_EUR" )
                ->Enum<ServerModels::Currency::CurrencyFJD>( "PlayFabServer_Currency_FJD" )
                ->Enum<ServerModels::Currency::CurrencyFKP>( "PlayFabServer_Currency_FKP" )
                ->Enum<ServerModels::Currency::CurrencyGBP>( "PlayFabServer_Currency_GBP" )
                ->Enum<ServerModels::Currency::CurrencyGEL>( "PlayFabServer_Currency_GEL" )
                ->Enum<ServerModels::Currency::CurrencyGGP>( "PlayFabServer_Currency_GGP" )
                ->Enum<ServerModels::Currency::CurrencyGHS>( "PlayFabServer_Currency_GHS" )
                ->Enum<ServerModels::Currency::CurrencyGIP>( "PlayFabServer_Currency_GIP" )
                ->Enum<ServerModels::Currency::CurrencyGMD>( "PlayFabServer_Currency_GMD" )
                ->Enum<ServerModels::Currency::CurrencyGNF>( "PlayFabServer_Currency_GNF" )
                ->Enum<ServerModels::Currency::CurrencyGTQ>( "PlayFabServer_Currency_GTQ" )
                ->Enum<ServerModels::Currency::CurrencyGYD>( "PlayFabServer_Currency_GYD" )
                ->Enum<ServerModels::Currency::CurrencyHKD>( "PlayFabServer_Currency_HKD" )
                ->Enum<ServerModels::Currency::CurrencyHNL>( "PlayFabServer_Currency_HNL" )
                ->Enum<ServerModels::Currency::CurrencyHRK>( "PlayFabServer_Currency_HRK" )
                ->Enum<ServerModels::Currency::CurrencyHTG>( "PlayFabServer_Currency_HTG" )
                ->Enum<ServerModels::Currency::CurrencyHUF>( "PlayFabServer_Currency_HUF" )
                ->Enum<ServerModels::Currency::CurrencyIDR>( "PlayFabServer_Currency_IDR" )
                ->Enum<ServerModels::Currency::CurrencyILS>( "PlayFabServer_Currency_ILS" )
                ->Enum<ServerModels::Currency::CurrencyIMP>( "PlayFabServer_Currency_IMP" )
                ->Enum<ServerModels::Currency::CurrencyINR>( "PlayFabServer_Currency_INR" )
                ->Enum<ServerModels::Currency::CurrencyIQD>( "PlayFabServer_Currency_IQD" )
                ->Enum<ServerModels::Currency::CurrencyIRR>( "PlayFabServer_Currency_IRR" )
                ->Enum<ServerModels::Currency::CurrencyISK>( "PlayFabServer_Currency_ISK" )
                ->Enum<ServerModels::Currency::CurrencyJEP>( "PlayFabServer_Currency_JEP" )
                ->Enum<ServerModels::Currency::CurrencyJMD>( "PlayFabServer_Currency_JMD" )
                ->Enum<ServerModels::Currency::CurrencyJOD>( "PlayFabServer_Currency_JOD" )
                ->Enum<ServerModels::Currency::CurrencyJPY>( "PlayFabServer_Currency_JPY" )
                ->Enum<ServerModels::Currency::CurrencyKES>( "PlayFabServer_Currency_KES" )
                ->Enum<ServerModels::Currency::CurrencyKGS>( "PlayFabServer_Currency_KGS" )
                ->Enum<ServerModels::Currency::CurrencyKHR>( "PlayFabServer_Currency_KHR" )
                ->Enum<ServerModels::Currency::CurrencyKMF>( "PlayFabServer_Currency_KMF" )
                ->Enum<ServerModels::Currency::CurrencyKPW>( "PlayFabServer_Currency_KPW" )
                ->Enum<ServerModels::Currency::CurrencyKRW>( "PlayFabServer_Currency_KRW" )
                ->Enum<ServerModels::Currency::CurrencyKWD>( "PlayFabServer_Currency_KWD" )
                ->Enum<ServerModels::Currency::CurrencyKYD>( "PlayFabServer_Currency_KYD" )
                ->Enum<ServerModels::Currency::CurrencyKZT>( "PlayFabServer_Currency_KZT" )
                ->Enum<ServerModels::Currency::CurrencyLAK>( "PlayFabServer_Currency_LAK" )
                ->Enum<ServerModels::Currency::CurrencyLBP>( "PlayFabServer_Currency_LBP" )
                ->Enum<ServerModels::Currency::CurrencyLKR>( "PlayFabServer_Currency_LKR" )
                ->Enum<ServerModels::Currency::CurrencyLRD>( "PlayFabServer_Currency_LRD" )
                ->Enum<ServerModels::Currency::CurrencyLSL>( "PlayFabServer_Currency_LSL" )
                ->Enum<ServerModels::Currency::CurrencyLYD>( "PlayFabServer_Currency_LYD" )
                ->Enum<ServerModels::Currency::CurrencyMAD>( "PlayFabServer_Currency_MAD" )
                ->Enum<ServerModels::Currency::CurrencyMDL>( "PlayFabServer_Currency_MDL" )
                ->Enum<ServerModels::Currency::CurrencyMGA>( "PlayFabServer_Currency_MGA" )
                ->Enum<ServerModels::Currency::CurrencyMKD>( "PlayFabServer_Currency_MKD" )
                ->Enum<ServerModels::Currency::CurrencyMMK>( "PlayFabServer_Currency_MMK" )
                ->Enum<ServerModels::Currency::CurrencyMNT>( "PlayFabServer_Currency_MNT" )
                ->Enum<ServerModels::Currency::CurrencyMOP>( "PlayFabServer_Currency_MOP" )
                ->Enum<ServerModels::Currency::CurrencyMRO>( "PlayFabServer_Currency_MRO" )
                ->Enum<ServerModels::Currency::CurrencyMUR>( "PlayFabServer_Currency_MUR" )
                ->Enum<ServerModels::Currency::CurrencyMVR>( "PlayFabServer_Currency_MVR" )
                ->Enum<ServerModels::Currency::CurrencyMWK>( "PlayFabServer_Currency_MWK" )
                ->Enum<ServerModels::Currency::CurrencyMXN>( "PlayFabServer_Currency_MXN" )
                ->Enum<ServerModels::Currency::CurrencyMYR>( "PlayFabServer_Currency_MYR" )
                ->Enum<ServerModels::Currency::CurrencyMZN>( "PlayFabServer_Currency_MZN" )
                ->Enum<ServerModels::Currency::CurrencyNAD>( "PlayFabServer_Currency_NAD" )
                ->Enum<ServerModels::Currency::CurrencyNGN>( "PlayFabServer_Currency_NGN" )
                ->Enum<ServerModels::Currency::CurrencyNIO>( "PlayFabServer_Currency_NIO" )
                ->Enum<ServerModels::Currency::CurrencyNOK>( "PlayFabServer_Currency_NOK" )
                ->Enum<ServerModels::Currency::CurrencyNPR>( "PlayFabServer_Currency_NPR" )
                ->Enum<ServerModels::Currency::CurrencyNZD>( "PlayFabServer_Currency_NZD" )
                ->Enum<ServerModels::Currency::CurrencyOMR>( "PlayFabServer_Currency_OMR" )
                ->Enum<ServerModels::Currency::CurrencyPAB>( "PlayFabServer_Currency_PAB" )
                ->Enum<ServerModels::Currency::CurrencyPEN>( "PlayFabServer_Currency_PEN" )
                ->Enum<ServerModels::Currency::CurrencyPGK>( "PlayFabServer_Currency_PGK" )
                ->Enum<ServerModels::Currency::CurrencyPHP>( "PlayFabServer_Currency_PHP" )
                ->Enum<ServerModels::Currency::CurrencyPKR>( "PlayFabServer_Currency_PKR" )
                ->Enum<ServerModels::Currency::CurrencyPLN>( "PlayFabServer_Currency_PLN" )
                ->Enum<ServerModels::Currency::CurrencyPYG>( "PlayFabServer_Currency_PYG" )
                ->Enum<ServerModels::Currency::CurrencyQAR>( "PlayFabServer_Currency_QAR" )
                ->Enum<ServerModels::Currency::CurrencyRON>( "PlayFabServer_Currency_RON" )
                ->Enum<ServerModels::Currency::CurrencyRSD>( "PlayFabServer_Currency_RSD" )
                ->Enum<ServerModels::Currency::CurrencyRUB>( "PlayFabServer_Currency_RUB" )
                ->Enum<ServerModels::Currency::CurrencyRWF>( "PlayFabServer_Currency_RWF" )
                ->Enum<ServerModels::Currency::CurrencySAR>( "PlayFabServer_Currency_SAR" )
                ->Enum<ServerModels::Currency::CurrencySBD>( "PlayFabServer_Currency_SBD" )
                ->Enum<ServerModels::Currency::CurrencySCR>( "PlayFabServer_Currency_SCR" )
                ->Enum<ServerModels::Currency::CurrencySDG>( "PlayFabServer_Currency_SDG" )
                ->Enum<ServerModels::Currency::CurrencySEK>( "PlayFabServer_Currency_SEK" )
                ->Enum<ServerModels::Currency::CurrencySGD>( "PlayFabServer_Currency_SGD" )
                ->Enum<ServerModels::Currency::CurrencySHP>( "PlayFabServer_Currency_SHP" )
                ->Enum<ServerModels::Currency::CurrencySLL>( "PlayFabServer_Currency_SLL" )
                ->Enum<ServerModels::Currency::CurrencySOS>( "PlayFabServer_Currency_SOS" )
                ->Enum<ServerModels::Currency::CurrencySPL>( "PlayFabServer_Currency_SPL" )
                ->Enum<ServerModels::Currency::CurrencySRD>( "PlayFabServer_Currency_SRD" )
                ->Enum<ServerModels::Currency::CurrencySTD>( "PlayFabServer_Currency_STD" )
                ->Enum<ServerModels::Currency::CurrencySVC>( "PlayFabServer_Currency_SVC" )
                ->Enum<ServerModels::Currency::CurrencySYP>( "PlayFabServer_Currency_SYP" )
                ->Enum<ServerModels::Currency::CurrencySZL>( "PlayFabServer_Currency_SZL" )
                ->Enum<ServerModels::Currency::CurrencyTHB>( "PlayFabServer_Currency_THB" )
                ->Enum<ServerModels::Currency::CurrencyTJS>( "PlayFabServer_Currency_TJS" )
                ->Enum<ServerModels::Currency::CurrencyTMT>( "PlayFabServer_Currency_TMT" )
                ->Enum<ServerModels::Currency::CurrencyTND>( "PlayFabServer_Currency_TND" )
                ->Enum<ServerModels::Currency::CurrencyTOP>( "PlayFabServer_Currency_TOP" )
                ->Enum<ServerModels::Currency::CurrencyTRY>( "PlayFabServer_Currency_TRY" )
                ->Enum<ServerModels::Currency::CurrencyTTD>( "PlayFabServer_Currency_TTD" )
                ->Enum<ServerModels::Currency::CurrencyTVD>( "PlayFabServer_Currency_TVD" )
                ->Enum<ServerModels::Currency::CurrencyTWD>( "PlayFabServer_Currency_TWD" )
                ->Enum<ServerModels::Currency::CurrencyTZS>( "PlayFabServer_Currency_TZS" )
                ->Enum<ServerModels::Currency::CurrencyUAH>( "PlayFabServer_Currency_UAH" )
                ->Enum<ServerModels::Currency::CurrencyUGX>( "PlayFabServer_Currency_UGX" )
                ->Enum<ServerModels::Currency::CurrencyUSD>( "PlayFabServer_Currency_USD" )
                ->Enum<ServerModels::Currency::CurrencyUYU>( "PlayFabServer_Currency_UYU" )
                ->Enum<ServerModels::Currency::CurrencyUZS>( "PlayFabServer_Currency_UZS" )
                ->Enum<ServerModels::Currency::CurrencyVEF>( "PlayFabServer_Currency_VEF" )
                ->Enum<ServerModels::Currency::CurrencyVND>( "PlayFabServer_Currency_VND" )
                ->Enum<ServerModels::Currency::CurrencyVUV>( "PlayFabServer_Currency_VUV" )
                ->Enum<ServerModels::Currency::CurrencyWST>( "PlayFabServer_Currency_WST" )
                ->Enum<ServerModels::Currency::CurrencyXAF>( "PlayFabServer_Currency_XAF" )
                ->Enum<ServerModels::Currency::CurrencyXCD>( "PlayFabServer_Currency_XCD" )
                ->Enum<ServerModels::Currency::CurrencyXDR>( "PlayFabServer_Currency_XDR" )
                ->Enum<ServerModels::Currency::CurrencyXOF>( "PlayFabServer_Currency_XOF" )
                ->Enum<ServerModels::Currency::CurrencyXPF>( "PlayFabServer_Currency_XPF" )
                ->Enum<ServerModels::Currency::CurrencyYER>( "PlayFabServer_Currency_YER" )
                ->Enum<ServerModels::Currency::CurrencyZAR>( "PlayFabServer_Currency_ZAR" )
                ->Enum<ServerModels::Currency::CurrencyZMW>( "PlayFabServer_Currency_ZMW" )
                ->Enum<ServerModels::Currency::CurrencyZWD>( "PlayFabServer_Currency_ZWD" )
            ;
            behaviorContext 
                ->Enum<ServerModels::TitleActivationStatus::TitleActivationStatusNone>( "PlayFabServer_TitleActivationStatus_None" )
                ->Enum<ServerModels::TitleActivationStatus::TitleActivationStatusActivatedTitleKey>( "PlayFabServer_TitleActivationStatus_ActivatedTitleKey" )
                ->Enum<ServerModels::TitleActivationStatus::TitleActivationStatusPendingSteam>( "PlayFabServer_TitleActivationStatus_PendingSteam" )
                ->Enum<ServerModels::TitleActivationStatus::TitleActivationStatusActivatedSteam>( "PlayFabServer_TitleActivationStatus_ActivatedSteam" )
                ->Enum<ServerModels::TitleActivationStatus::TitleActivationStatusRevokedSteam>( "PlayFabServer_TitleActivationStatus_RevokedSteam" )
            ;
            behaviorContext 
                ->Enum<ServerModels::CloudScriptRevisionOption::CloudScriptRevisionOptionLive>( "PlayFabServer_CloudScriptRevisionOption_Live" )
                ->Enum<ServerModels::CloudScriptRevisionOption::CloudScriptRevisionOptionLatest>( "PlayFabServer_CloudScriptRevisionOption_Latest" )
                ->Enum<ServerModels::CloudScriptRevisionOption::CloudScriptRevisionOptionSpecific>( "PlayFabServer_CloudScriptRevisionOption_Specific" )
            ;
            behaviorContext 
                ->Enum<ServerModels::EmailVerificationStatus::EmailVerificationStatusUnverified>( "PlayFabServer_EmailVerificationStatus_Unverified" )
                ->Enum<ServerModels::EmailVerificationStatus::EmailVerificationStatusPending>( "PlayFabServer_EmailVerificationStatus_Pending" )
                ->Enum<ServerModels::EmailVerificationStatus::EmailVerificationStatusConfirmed>( "PlayFabServer_EmailVerificationStatus_Confirmed" )
            ;
            behaviorContext 
                ->Enum<ServerModels::ContinentCode::ContinentCodeAF>( "PlayFabServer_ContinentCode_AF" )
                ->Enum<ServerModels::ContinentCode::ContinentCodeAN>( "PlayFabServer_ContinentCode_AN" )
                ->Enum<ServerModels::ContinentCode::ContinentCodeAS>( "PlayFabServer_ContinentCode_AS" )
                ->Enum<ServerModels::ContinentCode::ContinentCodeEU>( "PlayFabServer_ContinentCode_EU" )
                ->Enum<ServerModels::ContinentCode::ContinentCodeNA>( "PlayFabServer_ContinentCode_NA" )
                ->Enum<ServerModels::ContinentCode::ContinentCodeOC>( "PlayFabServer_ContinentCode_OC" )
                ->Enum<ServerModels::ContinentCode::ContinentCodeSA>( "PlayFabServer_ContinentCode_SA" )
            ;
            behaviorContext 
                ->Enum<ServerModels::CountryCode::CountryCodeAF>( "PlayFabServer_CountryCode_AF" )
                ->Enum<ServerModels::CountryCode::CountryCodeAX>( "PlayFabServer_CountryCode_AX" )
                ->Enum<ServerModels::CountryCode::CountryCodeAL>( "PlayFabServer_CountryCode_AL" )
                ->Enum<ServerModels::CountryCode::CountryCodeDZ>( "PlayFabServer_CountryCode_DZ" )
                ->Enum<ServerModels::CountryCode::CountryCodeAS>( "PlayFabServer_CountryCode_AS" )
                ->Enum<ServerModels::CountryCode::CountryCodeAD>( "PlayFabServer_CountryCode_AD" )
                ->Enum<ServerModels::CountryCode::CountryCodeAO>( "PlayFabServer_CountryCode_AO" )
                ->Enum<ServerModels::CountryCode::CountryCodeAI>( "PlayFabServer_CountryCode_AI" )
                ->Enum<ServerModels::CountryCode::CountryCodeAQ>( "PlayFabServer_CountryCode_AQ" )
                ->Enum<ServerModels::CountryCode::CountryCodeAG>( "PlayFabServer_CountryCode_AG" )
                ->Enum<ServerModels::CountryCode::CountryCodeAR>( "PlayFabServer_CountryCode_AR" )
                ->Enum<ServerModels::CountryCode::CountryCodeAM>( "PlayFabServer_CountryCode_AM" )
                ->Enum<ServerModels::CountryCode::CountryCodeAW>( "PlayFabServer_CountryCode_AW" )
                ->Enum<ServerModels::CountryCode::CountryCodeAU>( "PlayFabServer_CountryCode_AU" )
                ->Enum<ServerModels::CountryCode::CountryCodeAT>( "PlayFabServer_CountryCode_AT" )
                ->Enum<ServerModels::CountryCode::CountryCodeAZ>( "PlayFabServer_CountryCode_AZ" )
                ->Enum<ServerModels::CountryCode::CountryCodeBS>( "PlayFabServer_CountryCode_BS" )
                ->Enum<ServerModels::CountryCode::CountryCodeBH>( "PlayFabServer_CountryCode_BH" )
                ->Enum<ServerModels::CountryCode::CountryCodeBD>( "PlayFabServer_CountryCode_BD" )
                ->Enum<ServerModels::CountryCode::CountryCodeBB>( "PlayFabServer_CountryCode_BB" )
                ->Enum<ServerModels::CountryCode::CountryCodeBY>( "PlayFabServer_CountryCode_BY" )
                ->Enum<ServerModels::CountryCode::CountryCodeBE>( "PlayFabServer_CountryCode_BE" )
                ->Enum<ServerModels::CountryCode::CountryCodeBZ>( "PlayFabServer_CountryCode_BZ" )
                ->Enum<ServerModels::CountryCode::CountryCodeBJ>( "PlayFabServer_CountryCode_BJ" )
                ->Enum<ServerModels::CountryCode::CountryCodeBM>( "PlayFabServer_CountryCode_BM" )
                ->Enum<ServerModels::CountryCode::CountryCodeBT>( "PlayFabServer_CountryCode_BT" )
                ->Enum<ServerModels::CountryCode::CountryCodeBO>( "PlayFabServer_CountryCode_BO" )
                ->Enum<ServerModels::CountryCode::CountryCodeBQ>( "PlayFabServer_CountryCode_BQ" )
                ->Enum<ServerModels::CountryCode::CountryCodeBA>( "PlayFabServer_CountryCode_BA" )
                ->Enum<ServerModels::CountryCode::CountryCodeBW>( "PlayFabServer_CountryCode_BW" )
                ->Enum<ServerModels::CountryCode::CountryCodeBV>( "PlayFabServer_CountryCode_BV" )
                ->Enum<ServerModels::CountryCode::CountryCodeBR>( "PlayFabServer_CountryCode_BR" )
                ->Enum<ServerModels::CountryCode::CountryCodeIO>( "PlayFabServer_CountryCode_IO" )
                ->Enum<ServerModels::CountryCode::CountryCodeBN>( "PlayFabServer_CountryCode_BN" )
                ->Enum<ServerModels::CountryCode::CountryCodeBG>( "PlayFabServer_CountryCode_BG" )
                ->Enum<ServerModels::CountryCode::CountryCodeBF>( "PlayFabServer_CountryCode_BF" )
                ->Enum<ServerModels::CountryCode::CountryCodeBI>( "PlayFabServer_CountryCode_BI" )
                ->Enum<ServerModels::CountryCode::CountryCodeKH>( "PlayFabServer_CountryCode_KH" )
                ->Enum<ServerModels::CountryCode::CountryCodeCM>( "PlayFabServer_CountryCode_CM" )
                ->Enum<ServerModels::CountryCode::CountryCodeCA>( "PlayFabServer_CountryCode_CA" )
                ->Enum<ServerModels::CountryCode::CountryCodeCV>( "PlayFabServer_CountryCode_CV" )
                ->Enum<ServerModels::CountryCode::CountryCodeKY>( "PlayFabServer_CountryCode_KY" )
                ->Enum<ServerModels::CountryCode::CountryCodeCF>( "PlayFabServer_CountryCode_CF" )
                ->Enum<ServerModels::CountryCode::CountryCodeTD>( "PlayFabServer_CountryCode_TD" )
                ->Enum<ServerModels::CountryCode::CountryCodeCL>( "PlayFabServer_CountryCode_CL" )
                ->Enum<ServerModels::CountryCode::CountryCodeCN>( "PlayFabServer_CountryCode_CN" )
                ->Enum<ServerModels::CountryCode::CountryCodeCX>( "PlayFabServer_CountryCode_CX" )
                ->Enum<ServerModels::CountryCode::CountryCodeCC>( "PlayFabServer_CountryCode_CC" )
                ->Enum<ServerModels::CountryCode::CountryCodeCO>( "PlayFabServer_CountryCode_CO" )
                ->Enum<ServerModels::CountryCode::CountryCodeKM>( "PlayFabServer_CountryCode_KM" )
                ->Enum<ServerModels::CountryCode::CountryCodeCG>( "PlayFabServer_CountryCode_CG" )
                ->Enum<ServerModels::CountryCode::CountryCodeCD>( "PlayFabServer_CountryCode_CD" )
                ->Enum<ServerModels::CountryCode::CountryCodeCK>( "PlayFabServer_CountryCode_CK" )
                ->Enum<ServerModels::CountryCode::CountryCodeCR>( "PlayFabServer_CountryCode_CR" )
                ->Enum<ServerModels::CountryCode::CountryCodeCI>( "PlayFabServer_CountryCode_CI" )
                ->Enum<ServerModels::CountryCode::CountryCodeHR>( "PlayFabServer_CountryCode_HR" )
                ->Enum<ServerModels::CountryCode::CountryCodeCU>( "PlayFabServer_CountryCode_CU" )
                ->Enum<ServerModels::CountryCode::CountryCodeCW>( "PlayFabServer_CountryCode_CW" )
                ->Enum<ServerModels::CountryCode::CountryCodeCY>( "PlayFabServer_CountryCode_CY" )
                ->Enum<ServerModels::CountryCode::CountryCodeCZ>( "PlayFabServer_CountryCode_CZ" )
                ->Enum<ServerModels::CountryCode::CountryCodeDK>( "PlayFabServer_CountryCode_DK" )
                ->Enum<ServerModels::CountryCode::CountryCodeDJ>( "PlayFabServer_CountryCode_DJ" )
                ->Enum<ServerModels::CountryCode::CountryCodeDM>( "PlayFabServer_CountryCode_DM" )
                ->Enum<ServerModels::CountryCode::CountryCodeDO>( "PlayFabServer_CountryCode_DO" )
                ->Enum<ServerModels::CountryCode::CountryCodeEC>( "PlayFabServer_CountryCode_EC" )
                ->Enum<ServerModels::CountryCode::CountryCodeEG>( "PlayFabServer_CountryCode_EG" )
                ->Enum<ServerModels::CountryCode::CountryCodeSV>( "PlayFabServer_CountryCode_SV" )
                ->Enum<ServerModels::CountryCode::CountryCodeGQ>( "PlayFabServer_CountryCode_GQ" )
                ->Enum<ServerModels::CountryCode::CountryCodeER>( "PlayFabServer_CountryCode_ER" )
                ->Enum<ServerModels::CountryCode::CountryCodeEE>( "PlayFabServer_CountryCode_EE" )
                ->Enum<ServerModels::CountryCode::CountryCodeET>( "PlayFabServer_CountryCode_ET" )
                ->Enum<ServerModels::CountryCode::CountryCodeFK>( "PlayFabServer_CountryCode_FK" )
                ->Enum<ServerModels::CountryCode::CountryCodeFO>( "PlayFabServer_CountryCode_FO" )
                ->Enum<ServerModels::CountryCode::CountryCodeFJ>( "PlayFabServer_CountryCode_FJ" )
                ->Enum<ServerModels::CountryCode::CountryCodeFI>( "PlayFabServer_CountryCode_FI" )
                ->Enum<ServerModels::CountryCode::CountryCodeFR>( "PlayFabServer_CountryCode_FR" )
                ->Enum<ServerModels::CountryCode::CountryCodeGF>( "PlayFabServer_CountryCode_GF" )
                ->Enum<ServerModels::CountryCode::CountryCodePF>( "PlayFabServer_CountryCode_PF" )
                ->Enum<ServerModels::CountryCode::CountryCodeTF>( "PlayFabServer_CountryCode_TF" )
                ->Enum<ServerModels::CountryCode::CountryCodeGA>( "PlayFabServer_CountryCode_GA" )
                ->Enum<ServerModels::CountryCode::CountryCodeGM>( "PlayFabServer_CountryCode_GM" )
                ->Enum<ServerModels::CountryCode::CountryCodeGE>( "PlayFabServer_CountryCode_GE" )
                ->Enum<ServerModels::CountryCode::CountryCodeDE>( "PlayFabServer_CountryCode_DE" )
                ->Enum<ServerModels::CountryCode::CountryCodeGH>( "PlayFabServer_CountryCode_GH" )
                ->Enum<ServerModels::CountryCode::CountryCodeGI>( "PlayFabServer_CountryCode_GI" )
                ->Enum<ServerModels::CountryCode::CountryCodeGR>( "PlayFabServer_CountryCode_GR" )
                ->Enum<ServerModels::CountryCode::CountryCodeGL>( "PlayFabServer_CountryCode_GL" )
                ->Enum<ServerModels::CountryCode::CountryCodeGD>( "PlayFabServer_CountryCode_GD" )
                ->Enum<ServerModels::CountryCode::CountryCodeGP>( "PlayFabServer_CountryCode_GP" )
                ->Enum<ServerModels::CountryCode::CountryCodeGU>( "PlayFabServer_CountryCode_GU" )
                ->Enum<ServerModels::CountryCode::CountryCodeGT>( "PlayFabServer_CountryCode_GT" )
                ->Enum<ServerModels::CountryCode::CountryCodeGG>( "PlayFabServer_CountryCode_GG" )
                ->Enum<ServerModels::CountryCode::CountryCodeGN>( "PlayFabServer_CountryCode_GN" )
                ->Enum<ServerModels::CountryCode::CountryCodeGW>( "PlayFabServer_CountryCode_GW" )
                ->Enum<ServerModels::CountryCode::CountryCodeGY>( "PlayFabServer_CountryCode_GY" )
                ->Enum<ServerModels::CountryCode::CountryCodeHT>( "PlayFabServer_CountryCode_HT" )
                ->Enum<ServerModels::CountryCode::CountryCodeHM>( "PlayFabServer_CountryCode_HM" )
                ->Enum<ServerModels::CountryCode::CountryCodeVA>( "PlayFabServer_CountryCode_VA" )
                ->Enum<ServerModels::CountryCode::CountryCodeHN>( "PlayFabServer_CountryCode_HN" )
                ->Enum<ServerModels::CountryCode::CountryCodeHK>( "PlayFabServer_CountryCode_HK" )
                ->Enum<ServerModels::CountryCode::CountryCodeHU>( "PlayFabServer_CountryCode_HU" )
                ->Enum<ServerModels::CountryCode::CountryCodeIS>( "PlayFabServer_CountryCode_IS" )
                ->Enum<ServerModels::CountryCode::CountryCodeIN>( "PlayFabServer_CountryCode_IN" )
                ->Enum<ServerModels::CountryCode::CountryCodeID>( "PlayFabServer_CountryCode_ID" )
                ->Enum<ServerModels::CountryCode::CountryCodeIR>( "PlayFabServer_CountryCode_IR" )
                ->Enum<ServerModels::CountryCode::CountryCodeIQ>( "PlayFabServer_CountryCode_IQ" )
                ->Enum<ServerModels::CountryCode::CountryCodeIE>( "PlayFabServer_CountryCode_IE" )
                ->Enum<ServerModels::CountryCode::CountryCodeIM>( "PlayFabServer_CountryCode_IM" )
                ->Enum<ServerModels::CountryCode::CountryCodeIL>( "PlayFabServer_CountryCode_IL" )
                ->Enum<ServerModels::CountryCode::CountryCodeIT>( "PlayFabServer_CountryCode_IT" )
                ->Enum<ServerModels::CountryCode::CountryCodeJM>( "PlayFabServer_CountryCode_JM" )
                ->Enum<ServerModels::CountryCode::CountryCodeJP>( "PlayFabServer_CountryCode_JP" )
                ->Enum<ServerModels::CountryCode::CountryCodeJE>( "PlayFabServer_CountryCode_JE" )
                ->Enum<ServerModels::CountryCode::CountryCodeJO>( "PlayFabServer_CountryCode_JO" )
                ->Enum<ServerModels::CountryCode::CountryCodeKZ>( "PlayFabServer_CountryCode_KZ" )
                ->Enum<ServerModels::CountryCode::CountryCodeKE>( "PlayFabServer_CountryCode_KE" )
                ->Enum<ServerModels::CountryCode::CountryCodeKI>( "PlayFabServer_CountryCode_KI" )
                ->Enum<ServerModels::CountryCode::CountryCodeKP>( "PlayFabServer_CountryCode_KP" )
                ->Enum<ServerModels::CountryCode::CountryCodeKR>( "PlayFabServer_CountryCode_KR" )
                ->Enum<ServerModels::CountryCode::CountryCodeKW>( "PlayFabServer_CountryCode_KW" )
                ->Enum<ServerModels::CountryCode::CountryCodeKG>( "PlayFabServer_CountryCode_KG" )
                ->Enum<ServerModels::CountryCode::CountryCodeLA>( "PlayFabServer_CountryCode_LA" )
                ->Enum<ServerModels::CountryCode::CountryCodeLV>( "PlayFabServer_CountryCode_LV" )
                ->Enum<ServerModels::CountryCode::CountryCodeLB>( "PlayFabServer_CountryCode_LB" )
                ->Enum<ServerModels::CountryCode::CountryCodeLS>( "PlayFabServer_CountryCode_LS" )
                ->Enum<ServerModels::CountryCode::CountryCodeLR>( "PlayFabServer_CountryCode_LR" )
                ->Enum<ServerModels::CountryCode::CountryCodeLY>( "PlayFabServer_CountryCode_LY" )
                ->Enum<ServerModels::CountryCode::CountryCodeLI>( "PlayFabServer_CountryCode_LI" )
                ->Enum<ServerModels::CountryCode::CountryCodeLT>( "PlayFabServer_CountryCode_LT" )
                ->Enum<ServerModels::CountryCode::CountryCodeLU>( "PlayFabServer_CountryCode_LU" )
                ->Enum<ServerModels::CountryCode::CountryCodeMO>( "PlayFabServer_CountryCode_MO" )
                ->Enum<ServerModels::CountryCode::CountryCodeMK>( "PlayFabServer_CountryCode_MK" )
                ->Enum<ServerModels::CountryCode::CountryCodeMG>( "PlayFabServer_CountryCode_MG" )
                ->Enum<ServerModels::CountryCode::CountryCodeMW>( "PlayFabServer_CountryCode_MW" )
                ->Enum<ServerModels::CountryCode::CountryCodeMY>( "PlayFabServer_CountryCode_MY" )
                ->Enum<ServerModels::CountryCode::CountryCodeMV>( "PlayFabServer_CountryCode_MV" )
                ->Enum<ServerModels::CountryCode::CountryCodeML>( "PlayFabServer_CountryCode_ML" )
                ->Enum<ServerModels::CountryCode::CountryCodeMT>( "PlayFabServer_CountryCode_MT" )
                ->Enum<ServerModels::CountryCode::CountryCodeMH>( "PlayFabServer_CountryCode_MH" )
                ->Enum<ServerModels::CountryCode::CountryCodeMQ>( "PlayFabServer_CountryCode_MQ" )
                ->Enum<ServerModels::CountryCode::CountryCodeMR>( "PlayFabServer_CountryCode_MR" )
                ->Enum<ServerModels::CountryCode::CountryCodeMU>( "PlayFabServer_CountryCode_MU" )
                ->Enum<ServerModels::CountryCode::CountryCodeYT>( "PlayFabServer_CountryCode_YT" )
                ->Enum<ServerModels::CountryCode::CountryCodeMX>( "PlayFabServer_CountryCode_MX" )
                ->Enum<ServerModels::CountryCode::CountryCodeFM>( "PlayFabServer_CountryCode_FM" )
                ->Enum<ServerModels::CountryCode::CountryCodeMD>( "PlayFabServer_CountryCode_MD" )
                ->Enum<ServerModels::CountryCode::CountryCodeMC>( "PlayFabServer_CountryCode_MC" )
                ->Enum<ServerModels::CountryCode::CountryCodeMN>( "PlayFabServer_CountryCode_MN" )
                ->Enum<ServerModels::CountryCode::CountryCodeME>( "PlayFabServer_CountryCode_ME" )
                ->Enum<ServerModels::CountryCode::CountryCodeMS>( "PlayFabServer_CountryCode_MS" )
                ->Enum<ServerModels::CountryCode::CountryCodeMA>( "PlayFabServer_CountryCode_MA" )
                ->Enum<ServerModels::CountryCode::CountryCodeMZ>( "PlayFabServer_CountryCode_MZ" )
                ->Enum<ServerModels::CountryCode::CountryCodeMM>( "PlayFabServer_CountryCode_MM" )
                ->Enum<ServerModels::CountryCode::CountryCodeNA>( "PlayFabServer_CountryCode_NA" )
                ->Enum<ServerModels::CountryCode::CountryCodeNR>( "PlayFabServer_CountryCode_NR" )
                ->Enum<ServerModels::CountryCode::CountryCodeNP>( "PlayFabServer_CountryCode_NP" )
                ->Enum<ServerModels::CountryCode::CountryCodeNL>( "PlayFabServer_CountryCode_NL" )
                ->Enum<ServerModels::CountryCode::CountryCodeNC>( "PlayFabServer_CountryCode_NC" )
                ->Enum<ServerModels::CountryCode::CountryCodeNZ>( "PlayFabServer_CountryCode_NZ" )
                ->Enum<ServerModels::CountryCode::CountryCodeNI>( "PlayFabServer_CountryCode_NI" )
                ->Enum<ServerModels::CountryCode::CountryCodeNE>( "PlayFabServer_CountryCode_NE" )
                ->Enum<ServerModels::CountryCode::CountryCodeNG>( "PlayFabServer_CountryCode_NG" )
                ->Enum<ServerModels::CountryCode::CountryCodeNU>( "PlayFabServer_CountryCode_NU" )
                ->Enum<ServerModels::CountryCode::CountryCodeNF>( "PlayFabServer_CountryCode_NF" )
                ->Enum<ServerModels::CountryCode::CountryCodeMP>( "PlayFabServer_CountryCode_MP" )
                ->Enum<ServerModels::CountryCode::CountryCodeNO>( "PlayFabServer_CountryCode_NO" )
                ->Enum<ServerModels::CountryCode::CountryCodeOM>( "PlayFabServer_CountryCode_OM" )
                ->Enum<ServerModels::CountryCode::CountryCodePK>( "PlayFabServer_CountryCode_PK" )
                ->Enum<ServerModels::CountryCode::CountryCodePW>( "PlayFabServer_CountryCode_PW" )
                ->Enum<ServerModels::CountryCode::CountryCodePS>( "PlayFabServer_CountryCode_PS" )
                ->Enum<ServerModels::CountryCode::CountryCodePA>( "PlayFabServer_CountryCode_PA" )
                ->Enum<ServerModels::CountryCode::CountryCodePG>( "PlayFabServer_CountryCode_PG" )
                ->Enum<ServerModels::CountryCode::CountryCodePY>( "PlayFabServer_CountryCode_PY" )
                ->Enum<ServerModels::CountryCode::CountryCodePE>( "PlayFabServer_CountryCode_PE" )
                ->Enum<ServerModels::CountryCode::CountryCodePH>( "PlayFabServer_CountryCode_PH" )
                ->Enum<ServerModels::CountryCode::CountryCodePN>( "PlayFabServer_CountryCode_PN" )
                ->Enum<ServerModels::CountryCode::CountryCodePL>( "PlayFabServer_CountryCode_PL" )
                ->Enum<ServerModels::CountryCode::CountryCodePT>( "PlayFabServer_CountryCode_PT" )
                ->Enum<ServerModels::CountryCode::CountryCodePR>( "PlayFabServer_CountryCode_PR" )
                ->Enum<ServerModels::CountryCode::CountryCodeQA>( "PlayFabServer_CountryCode_QA" )
                ->Enum<ServerModels::CountryCode::CountryCodeRE>( "PlayFabServer_CountryCode_RE" )
                ->Enum<ServerModels::CountryCode::CountryCodeRO>( "PlayFabServer_CountryCode_RO" )
                ->Enum<ServerModels::CountryCode::CountryCodeRU>( "PlayFabServer_CountryCode_RU" )
                ->Enum<ServerModels::CountryCode::CountryCodeRW>( "PlayFabServer_CountryCode_RW" )
                ->Enum<ServerModels::CountryCode::CountryCodeBL>( "PlayFabServer_CountryCode_BL" )
                ->Enum<ServerModels::CountryCode::CountryCodeSH>( "PlayFabServer_CountryCode_SH" )
                ->Enum<ServerModels::CountryCode::CountryCodeKN>( "PlayFabServer_CountryCode_KN" )
                ->Enum<ServerModels::CountryCode::CountryCodeLC>( "PlayFabServer_CountryCode_LC" )
                ->Enum<ServerModels::CountryCode::CountryCodeMF>( "PlayFabServer_CountryCode_MF" )
                ->Enum<ServerModels::CountryCode::CountryCodePM>( "PlayFabServer_CountryCode_PM" )
                ->Enum<ServerModels::CountryCode::CountryCodeVC>( "PlayFabServer_CountryCode_VC" )
                ->Enum<ServerModels::CountryCode::CountryCodeWS>( "PlayFabServer_CountryCode_WS" )
                ->Enum<ServerModels::CountryCode::CountryCodeSM>( "PlayFabServer_CountryCode_SM" )
                ->Enum<ServerModels::CountryCode::CountryCodeST>( "PlayFabServer_CountryCode_ST" )
                ->Enum<ServerModels::CountryCode::CountryCodeSA>( "PlayFabServer_CountryCode_SA" )
                ->Enum<ServerModels::CountryCode::CountryCodeSN>( "PlayFabServer_CountryCode_SN" )
                ->Enum<ServerModels::CountryCode::CountryCodeRS>( "PlayFabServer_CountryCode_RS" )
                ->Enum<ServerModels::CountryCode::CountryCodeSC>( "PlayFabServer_CountryCode_SC" )
                ->Enum<ServerModels::CountryCode::CountryCodeSL>( "PlayFabServer_CountryCode_SL" )
                ->Enum<ServerModels::CountryCode::CountryCodeSG>( "PlayFabServer_CountryCode_SG" )
                ->Enum<ServerModels::CountryCode::CountryCodeSX>( "PlayFabServer_CountryCode_SX" )
                ->Enum<ServerModels::CountryCode::CountryCodeSK>( "PlayFabServer_CountryCode_SK" )
                ->Enum<ServerModels::CountryCode::CountryCodeSI>( "PlayFabServer_CountryCode_SI" )
                ->Enum<ServerModels::CountryCode::CountryCodeSB>( "PlayFabServer_CountryCode_SB" )
                ->Enum<ServerModels::CountryCode::CountryCodeSO>( "PlayFabServer_CountryCode_SO" )
                ->Enum<ServerModels::CountryCode::CountryCodeZA>( "PlayFabServer_CountryCode_ZA" )
                ->Enum<ServerModels::CountryCode::CountryCodeGS>( "PlayFabServer_CountryCode_GS" )
                ->Enum<ServerModels::CountryCode::CountryCodeSS>( "PlayFabServer_CountryCode_SS" )
                ->Enum<ServerModels::CountryCode::CountryCodeES>( "PlayFabServer_CountryCode_ES" )
                ->Enum<ServerModels::CountryCode::CountryCodeLK>( "PlayFabServer_CountryCode_LK" )
                ->Enum<ServerModels::CountryCode::CountryCodeSD>( "PlayFabServer_CountryCode_SD" )
                ->Enum<ServerModels::CountryCode::CountryCodeSR>( "PlayFabServer_CountryCode_SR" )
                ->Enum<ServerModels::CountryCode::CountryCodeSJ>( "PlayFabServer_CountryCode_SJ" )
                ->Enum<ServerModels::CountryCode::CountryCodeSZ>( "PlayFabServer_CountryCode_SZ" )
                ->Enum<ServerModels::CountryCode::CountryCodeSE>( "PlayFabServer_CountryCode_SE" )
                ->Enum<ServerModels::CountryCode::CountryCodeCH>( "PlayFabServer_CountryCode_CH" )
                ->Enum<ServerModels::CountryCode::CountryCodeSY>( "PlayFabServer_CountryCode_SY" )
                ->Enum<ServerModels::CountryCode::CountryCodeTW>( "PlayFabServer_CountryCode_TW" )
                ->Enum<ServerModels::CountryCode::CountryCodeTJ>( "PlayFabServer_CountryCode_TJ" )
                ->Enum<ServerModels::CountryCode::CountryCodeTZ>( "PlayFabServer_CountryCode_TZ" )
                ->Enum<ServerModels::CountryCode::CountryCodeTH>( "PlayFabServer_CountryCode_TH" )
                ->Enum<ServerModels::CountryCode::CountryCodeTL>( "PlayFabServer_CountryCode_TL" )
                ->Enum<ServerModels::CountryCode::CountryCodeTG>( "PlayFabServer_CountryCode_TG" )
                ->Enum<ServerModels::CountryCode::CountryCodeTK>( "PlayFabServer_CountryCode_TK" )
                ->Enum<ServerModels::CountryCode::CountryCodeTO>( "PlayFabServer_CountryCode_TO" )
                ->Enum<ServerModels::CountryCode::CountryCodeTT>( "PlayFabServer_CountryCode_TT" )
                ->Enum<ServerModels::CountryCode::CountryCodeTN>( "PlayFabServer_CountryCode_TN" )
                ->Enum<ServerModels::CountryCode::CountryCodeTR>( "PlayFabServer_CountryCode_TR" )
                ->Enum<ServerModels::CountryCode::CountryCodeTM>( "PlayFabServer_CountryCode_TM" )
                ->Enum<ServerModels::CountryCode::CountryCodeTC>( "PlayFabServer_CountryCode_TC" )
                ->Enum<ServerModels::CountryCode::CountryCodeTV>( "PlayFabServer_CountryCode_TV" )
                ->Enum<ServerModels::CountryCode::CountryCodeUG>( "PlayFabServer_CountryCode_UG" )
                ->Enum<ServerModels::CountryCode::CountryCodeUA>( "PlayFabServer_CountryCode_UA" )
                ->Enum<ServerModels::CountryCode::CountryCodeAE>( "PlayFabServer_CountryCode_AE" )
                ->Enum<ServerModels::CountryCode::CountryCodeGB>( "PlayFabServer_CountryCode_GB" )
                ->Enum<ServerModels::CountryCode::CountryCodeUS>( "PlayFabServer_CountryCode_US" )
                ->Enum<ServerModels::CountryCode::CountryCodeUM>( "PlayFabServer_CountryCode_UM" )
                ->Enum<ServerModels::CountryCode::CountryCodeUY>( "PlayFabServer_CountryCode_UY" )
                ->Enum<ServerModels::CountryCode::CountryCodeUZ>( "PlayFabServer_CountryCode_UZ" )
                ->Enum<ServerModels::CountryCode::CountryCodeVU>( "PlayFabServer_CountryCode_VU" )
                ->Enum<ServerModels::CountryCode::CountryCodeVE>( "PlayFabServer_CountryCode_VE" )
                ->Enum<ServerModels::CountryCode::CountryCodeVN>( "PlayFabServer_CountryCode_VN" )
                ->Enum<ServerModels::CountryCode::CountryCodeVG>( "PlayFabServer_CountryCode_VG" )
                ->Enum<ServerModels::CountryCode::CountryCodeVI>( "PlayFabServer_CountryCode_VI" )
                ->Enum<ServerModels::CountryCode::CountryCodeWF>( "PlayFabServer_CountryCode_WF" )
                ->Enum<ServerModels::CountryCode::CountryCodeEH>( "PlayFabServer_CountryCode_EH" )
                ->Enum<ServerModels::CountryCode::CountryCodeYE>( "PlayFabServer_CountryCode_YE" )
                ->Enum<ServerModels::CountryCode::CountryCodeZM>( "PlayFabServer_CountryCode_ZM" )
                ->Enum<ServerModels::CountryCode::CountryCodeZW>( "PlayFabServer_CountryCode_ZW" )
            ;
            behaviorContext 
                ->Enum<ServerModels::LoginIdentityProvider::LoginIdentityProviderUnknown>( "PlayFabServer_LoginIdentityProvider_Unknown" )
                ->Enum<ServerModels::LoginIdentityProvider::LoginIdentityProviderPlayFab>( "PlayFabServer_LoginIdentityProvider_PlayFab" )
                ->Enum<ServerModels::LoginIdentityProvider::LoginIdentityProviderCustom>( "PlayFabServer_LoginIdentityProvider_Custom" )
                ->Enum<ServerModels::LoginIdentityProvider::LoginIdentityProviderGameCenter>( "PlayFabServer_LoginIdentityProvider_GameCenter" )
                ->Enum<ServerModels::LoginIdentityProvider::LoginIdentityProviderGooglePlay>( "PlayFabServer_LoginIdentityProvider_GooglePlay" )
                ->Enum<ServerModels::LoginIdentityProvider::LoginIdentityProviderSteam>( "PlayFabServer_LoginIdentityProvider_Steam" )
                ->Enum<ServerModels::LoginIdentityProvider::LoginIdentityProviderXBoxLive>( "PlayFabServer_LoginIdentityProvider_XBoxLive" )
                ->Enum<ServerModels::LoginIdentityProvider::LoginIdentityProviderPSN>( "PlayFabServer_LoginIdentityProvider_PSN" )
                ->Enum<ServerModels::LoginIdentityProvider::LoginIdentityProviderKongregate>( "PlayFabServer_LoginIdentityProvider_Kongregate" )
                ->Enum<ServerModels::LoginIdentityProvider::LoginIdentityProviderFacebook>( "PlayFabServer_LoginIdentityProvider_Facebook" )
                ->Enum<ServerModels::LoginIdentityProvider::LoginIdentityProviderIOSDevice>( "PlayFabServer_LoginIdentityProvider_IOSDevice" )
                ->Enum<ServerModels::LoginIdentityProvider::LoginIdentityProviderAndroidDevice>( "PlayFabServer_LoginIdentityProvider_AndroidDevice" )
                ->Enum<ServerModels::LoginIdentityProvider::LoginIdentityProviderTwitch>( "PlayFabServer_LoginIdentityProvider_Twitch" )
                ->Enum<ServerModels::LoginIdentityProvider::LoginIdentityProviderWindowsHello>( "PlayFabServer_LoginIdentityProvider_WindowsHello" )
            ;
            behaviorContext 
                ->Enum<ServerModels::PushNotificationPlatform::PushNotificationPlatformApplePushNotificationService>( "PlayFabServer_PushNotificationPlatform_ApplePushNotificationService" )
                ->Enum<ServerModels::PushNotificationPlatform::PushNotificationPlatformGoogleCloudMessaging>( "PlayFabServer_PushNotificationPlatform_GoogleCloudMessaging" )
            ;
            behaviorContext 
                ->Enum<ServerModels::GameInstanceState::GameInstanceStateOpen>( "PlayFabServer_GameInstanceState_Open" )
                ->Enum<ServerModels::GameInstanceState::GameInstanceStateClosed>( "PlayFabServer_GameInstanceState_Closed" )
            ;
            behaviorContext 
                ->Enum<ServerModels::UserDataPermission::UserDataPermissionPrivate>( "PlayFabServer_UserDataPermission_Private" )
                ->Enum<ServerModels::UserDataPermission::UserDataPermissionPublic>( "PlayFabServer_UserDataPermission_Public" )
            ;
            behaviorContext 
                ->Enum<ServerModels::ResultTableNodeType::ResultTableNodeTypeItemId>( "PlayFabServer_ResultTableNodeType_ItemId" )
                ->Enum<ServerModels::ResultTableNodeType::ResultTableNodeTypeTableId>( "PlayFabServer_ResultTableNodeType_TableId" )
            ;
            behaviorContext 
                ->Enum<ServerModels::PlayerConnectionState::PlayerConnectionStateUnassigned>( "PlayFabServer_PlayerConnectionState_Unassigned" )
                ->Enum<ServerModels::PlayerConnectionState::PlayerConnectionStateConnecting>( "PlayFabServer_PlayerConnectionState_Connecting" )
                ->Enum<ServerModels::PlayerConnectionState::PlayerConnectionStateParticipating>( "PlayFabServer_PlayerConnectionState_Participating" )
                ->Enum<ServerModels::PlayerConnectionState::PlayerConnectionStateParticipated>( "PlayFabServer_PlayerConnectionState_Participated" )
            ;
            behaviorContext 
                ->Enum<ServerModels::Region::RegionUSCentral>( "PlayFabServer_Region_USCentral" )
                ->Enum<ServerModels::Region::RegionUSEast>( "PlayFabServer_Region_USEast" )
                ->Enum<ServerModels::Region::RegionEUWest>( "PlayFabServer_Region_EUWest" )
                ->Enum<ServerModels::Region::RegionSingapore>( "PlayFabServer_Region_Singapore" )
                ->Enum<ServerModels::Region::RegionJapan>( "PlayFabServer_Region_Japan" )
                ->Enum<ServerModels::Region::RegionBrazil>( "PlayFabServer_Region_Brazil" )
                ->Enum<ServerModels::Region::RegionAustralia>( "PlayFabServer_Region_Australia" )
            ;
    
            //-----------------------------------------------------------------------------------------------------
			// Reflect data models (structs/classes)
            //-----------------------------------------------------------------------------------------------------

			behaviorContext->Class<ServerModels::NameIdentifier>("PlayFabServer_NameIdentifier")
                ->Constructor() 
			    ->Property("Name", BehaviorValueProperty(&ServerModels::NameIdentifier::Name)) 
			    ->Property("Id", BehaviorValueProperty(&ServerModels::NameIdentifier::Id)) 
			;
		
			behaviorContext->Class<ServerModels::ActionsOnPlayersInSegmentTaskSummary>("PlayFabServer_ActionsOnPlayersInSegmentTaskSummary")
                ->Constructor() 
			    ->Property("TaskInstanceId", BehaviorValueProperty(&ServerModels::ActionsOnPlayersInSegmentTaskSummary::TaskInstanceId)) 
			    ->Property("TaskIdentifier", BehaviorValueProperty(&ServerModels::ActionsOnPlayersInSegmentTaskSummary::TaskIdentifier)) 
			    ->Property("StartedAt", BehaviorValueProperty(&ServerModels::ActionsOnPlayersInSegmentTaskSummary::StartedAt)) 
			    ->Property("CompletedAt", BehaviorValueProperty(&ServerModels::ActionsOnPlayersInSegmentTaskSummary::CompletedAt)) 
			    ->Property("Status", BehaviorValueProperty(&ServerModels::ActionsOnPlayersInSegmentTaskSummary::Status)) 
			    ->Property("PercentComplete", BehaviorValueProperty(&ServerModels::ActionsOnPlayersInSegmentTaskSummary::PercentComplete)) 
			    ->Property("EstimatedSecondsRemaining", BehaviorValueProperty(&ServerModels::ActionsOnPlayersInSegmentTaskSummary::EstimatedSecondsRemaining)) 
			    ->Property("ScheduledByUserId", BehaviorValueProperty(&ServerModels::ActionsOnPlayersInSegmentTaskSummary::ScheduledByUserId)) 
			    ->Property("ErrorMessage", BehaviorValueProperty(&ServerModels::ActionsOnPlayersInSegmentTaskSummary::ErrorMessage)) 
			    ->Property("ErrorWasFatal", BehaviorValueProperty(&ServerModels::ActionsOnPlayersInSegmentTaskSummary::ErrorWasFatal)) 
			    ->Property("TotalPlayersInSegment", BehaviorValueProperty(&ServerModels::ActionsOnPlayersInSegmentTaskSummary::TotalPlayersInSegment)) 
			    ->Property("TotalPlayersProcessed", BehaviorValueProperty(&ServerModels::ActionsOnPlayersInSegmentTaskSummary::TotalPlayersProcessed)) 
			;
		
			behaviorContext->Class<ServerModels::AdCampaignAttribution>("PlayFabServer_AdCampaignAttribution")
                ->Constructor() 
			    ->Property("Platform", BehaviorValueProperty(&ServerModels::AdCampaignAttribution::Platform)) 
			    ->Property("CampaignId", BehaviorValueProperty(&ServerModels::AdCampaignAttribution::CampaignId)) 
			    ->Property("AttributedAt", BehaviorValueProperty(&ServerModels::AdCampaignAttribution::AttributedAt)) 
			;
		
			behaviorContext->Class<ServerModels::AdCampaignAttributionModel>("PlayFabServer_AdCampaignAttributionModel")
                ->Constructor() 
			    ->Property("Platform", BehaviorValueProperty(&ServerModels::AdCampaignAttributionModel::Platform)) 
			    ->Property("CampaignId", BehaviorValueProperty(&ServerModels::AdCampaignAttributionModel::CampaignId)) 
			    ->Property("AttributedAt", BehaviorValueProperty(&ServerModels::AdCampaignAttributionModel::AttributedAt)) 
			;
		
			behaviorContext->Class<ServerModels::AddCharacterVirtualCurrencyRequest>("PlayFabServer_AddCharacterVirtualCurrencyRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ServerModels::AddCharacterVirtualCurrencyRequest::PlayFabId)) 
			    ->Property("CharacterId", BehaviorValueProperty(&ServerModels::AddCharacterVirtualCurrencyRequest::CharacterId)) 
			    ->Property("VirtualCurrency", BehaviorValueProperty(&ServerModels::AddCharacterVirtualCurrencyRequest::VirtualCurrency)) 
			    ->Property("Amount", BehaviorValueProperty(&ServerModels::AddCharacterVirtualCurrencyRequest::Amount)) 
			;
		
			behaviorContext->Class<ServerModels::AddFriendRequest>("PlayFabServer_AddFriendRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ServerModels::AddFriendRequest::PlayFabId)) 
			    ->Property("FriendPlayFabId", BehaviorValueProperty(&ServerModels::AddFriendRequest::FriendPlayFabId)) 
			    ->Property("FriendUsername", BehaviorValueProperty(&ServerModels::AddFriendRequest::FriendUsername)) 
			    ->Property("FriendEmail", BehaviorValueProperty(&ServerModels::AddFriendRequest::FriendEmail)) 
			    ->Property("FriendTitleDisplayName", BehaviorValueProperty(&ServerModels::AddFriendRequest::FriendTitleDisplayName)) 
			;
		
			behaviorContext->Class<ServerModels::AddPlayerTagRequest>("PlayFabServer_AddPlayerTagRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ServerModels::AddPlayerTagRequest::PlayFabId)) 
			    ->Property("TagName", BehaviorValueProperty(&ServerModels::AddPlayerTagRequest::TagName)) 
			;
		
			behaviorContext->Class<ServerModels::AddPlayerTagResult>("PlayFabServer_AddPlayerTagResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<ServerModels::AddSharedGroupMembersRequest>("PlayFabServer_AddSharedGroupMembersRequest")
                ->Constructor() 
			    ->Property("SharedGroupId", BehaviorValueProperty(&ServerModels::AddSharedGroupMembersRequest::SharedGroupId)) 
			    ->Property("PlayFabIds", BehaviorValueProperty(&ServerModels::AddSharedGroupMembersRequest::PlayFabIds)) 
			;
		
			behaviorContext->Class<ServerModels::AddSharedGroupMembersResult>("PlayFabServer_AddSharedGroupMembersResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<ServerModels::AddUserVirtualCurrencyRequest>("PlayFabServer_AddUserVirtualCurrencyRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ServerModels::AddUserVirtualCurrencyRequest::PlayFabId)) 
			    ->Property("VirtualCurrency", BehaviorValueProperty(&ServerModels::AddUserVirtualCurrencyRequest::VirtualCurrency)) 
			    ->Property("Amount", BehaviorValueProperty(&ServerModels::AddUserVirtualCurrencyRequest::Amount)) 
			;
		
			behaviorContext->Class<ServerModels::AuthenticateSessionTicketRequest>("PlayFabServer_AuthenticateSessionTicketRequest")
                ->Constructor() 
			    ->Property("SessionTicket", BehaviorValueProperty(&ServerModels::AuthenticateSessionTicketRequest::SessionTicket)) 
			;
		
			behaviorContext->Class<ServerModels::UserTitleInfo>("PlayFabServer_UserTitleInfo")
                ->Constructor() 
			    ->Property("DisplayName", BehaviorValueProperty(&ServerModels::UserTitleInfo::DisplayName)) 
			    ->Property("Origination", BehaviorValueProperty(&ServerModels::UserTitleInfo::Origination)) 
			    ->Property("Created", BehaviorValueProperty(&ServerModels::UserTitleInfo::Created)) 
			    ->Property("LastLogin", BehaviorValueProperty(&ServerModels::UserTitleInfo::LastLogin)) 
			    ->Property("FirstLogin", BehaviorValueProperty(&ServerModels::UserTitleInfo::FirstLogin)) 
			    ->Property("isBanned", BehaviorValueProperty(&ServerModels::UserTitleInfo::isBanned)) 
			    ->Property("AvatarUrl", BehaviorValueProperty(&ServerModels::UserTitleInfo::AvatarUrl)) 
			;
		
			behaviorContext->Class<ServerModels::UserPrivateAccountInfo>("PlayFabServer_UserPrivateAccountInfo")
                ->Constructor() 
			    ->Property("Email", BehaviorValueProperty(&ServerModels::UserPrivateAccountInfo::Email)) 
			;
		
			behaviorContext->Class<ServerModels::UserFacebookInfo>("PlayFabServer_UserFacebookInfo")
                ->Constructor() 
			    ->Property("FacebookId", BehaviorValueProperty(&ServerModels::UserFacebookInfo::FacebookId)) 
			    ->Property("FullName", BehaviorValueProperty(&ServerModels::UserFacebookInfo::FullName)) 
			;
		
			behaviorContext->Class<ServerModels::UserSteamInfo>("PlayFabServer_UserSteamInfo")
                ->Constructor() 
			    ->Property("SteamId", BehaviorValueProperty(&ServerModels::UserSteamInfo::SteamId)) 
			    ->Property("SteamCountry", BehaviorValueProperty(&ServerModels::UserSteamInfo::SteamCountry)) 
			    ->Property("SteamCurrency", BehaviorValueProperty(&ServerModels::UserSteamInfo::SteamCurrency)) 
			    ->Property("SteamActivationStatus", BehaviorValueProperty(&ServerModels::UserSteamInfo::SteamActivationStatus)) 
			;
		
			behaviorContext->Class<ServerModels::UserGameCenterInfo>("PlayFabServer_UserGameCenterInfo")
                ->Constructor() 
			    ->Property("GameCenterId", BehaviorValueProperty(&ServerModels::UserGameCenterInfo::GameCenterId)) 
			;
		
			behaviorContext->Class<ServerModels::UserIosDeviceInfo>("PlayFabServer_UserIosDeviceInfo")
                ->Constructor() 
			    ->Property("IosDeviceId", BehaviorValueProperty(&ServerModels::UserIosDeviceInfo::IosDeviceId)) 
			;
		
			behaviorContext->Class<ServerModels::UserAndroidDeviceInfo>("PlayFabServer_UserAndroidDeviceInfo")
                ->Constructor() 
			    ->Property("AndroidDeviceId", BehaviorValueProperty(&ServerModels::UserAndroidDeviceInfo::AndroidDeviceId)) 
			;
		
			behaviorContext->Class<ServerModels::UserKongregateInfo>("PlayFabServer_UserKongregateInfo")
                ->Constructor() 
			    ->Property("KongregateId", BehaviorValueProperty(&ServerModels::UserKongregateInfo::KongregateId)) 
			    ->Property("KongregateName", BehaviorValueProperty(&ServerModels::UserKongregateInfo::KongregateName)) 
			;
		
			behaviorContext->Class<ServerModels::UserTwitchInfo>("PlayFabServer_UserTwitchInfo")
                ->Constructor() 
			    ->Property("TwitchId", BehaviorValueProperty(&ServerModels::UserTwitchInfo::TwitchId)) 
			    ->Property("TwitchUserName", BehaviorValueProperty(&ServerModels::UserTwitchInfo::TwitchUserName)) 
			;
		
			behaviorContext->Class<ServerModels::UserPsnInfo>("PlayFabServer_UserPsnInfo")
                ->Constructor() 
			    ->Property("PsnAccountId", BehaviorValueProperty(&ServerModels::UserPsnInfo::PsnAccountId)) 
			    ->Property("PsnOnlineId", BehaviorValueProperty(&ServerModels::UserPsnInfo::PsnOnlineId)) 
			;
		
			behaviorContext->Class<ServerModels::UserGoogleInfo>("PlayFabServer_UserGoogleInfo")
                ->Constructor() 
			    ->Property("GoogleId", BehaviorValueProperty(&ServerModels::UserGoogleInfo::GoogleId)) 
			    ->Property("GoogleEmail", BehaviorValueProperty(&ServerModels::UserGoogleInfo::GoogleEmail)) 
			    ->Property("GoogleLocale", BehaviorValueProperty(&ServerModels::UserGoogleInfo::GoogleLocale)) 
			    ->Property("GoogleGender", BehaviorValueProperty(&ServerModels::UserGoogleInfo::GoogleGender)) 
			;
		
			behaviorContext->Class<ServerModels::UserXboxInfo>("PlayFabServer_UserXboxInfo")
                ->Constructor() 
			    ->Property("XboxUserId", BehaviorValueProperty(&ServerModels::UserXboxInfo::XboxUserId)) 
			;
		
			behaviorContext->Class<ServerModels::UserCustomIdInfo>("PlayFabServer_UserCustomIdInfo")
                ->Constructor() 
			    ->Property("CustomId", BehaviorValueProperty(&ServerModels::UserCustomIdInfo::CustomId)) 
			;
		
			behaviorContext->Class<ServerModels::UserAccountInfo>("PlayFabServer_UserAccountInfo")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ServerModels::UserAccountInfo::PlayFabId)) 
			    ->Property("Created", BehaviorValueProperty(&ServerModels::UserAccountInfo::Created)) 
			    ->Property("Username", BehaviorValueProperty(&ServerModels::UserAccountInfo::Username)) 
			    ->Property("TitleInfo", BehaviorValueProperty(&ServerModels::UserAccountInfo::TitleInfo)) 
			    ->Property("PrivateInfo", BehaviorValueProperty(&ServerModels::UserAccountInfo::PrivateInfo)) 
			    ->Property("FacebookInfo", BehaviorValueProperty(&ServerModels::UserAccountInfo::FacebookInfo)) 
			    ->Property("SteamInfo", BehaviorValueProperty(&ServerModels::UserAccountInfo::SteamInfo)) 
			    ->Property("GameCenterInfo", BehaviorValueProperty(&ServerModels::UserAccountInfo::GameCenterInfo)) 
			    ->Property("IosDeviceInfo", BehaviorValueProperty(&ServerModels::UserAccountInfo::IosDeviceInfo)) 
			    ->Property("AndroidDeviceInfo", BehaviorValueProperty(&ServerModels::UserAccountInfo::AndroidDeviceInfo)) 
			    ->Property("KongregateInfo", BehaviorValueProperty(&ServerModels::UserAccountInfo::KongregateInfo)) 
			    ->Property("TwitchInfo", BehaviorValueProperty(&ServerModels::UserAccountInfo::TwitchInfo)) 
			    ->Property("PsnInfo", BehaviorValueProperty(&ServerModels::UserAccountInfo::PsnInfo)) 
			    ->Property("GoogleInfo", BehaviorValueProperty(&ServerModels::UserAccountInfo::GoogleInfo)) 
			    ->Property("XboxInfo", BehaviorValueProperty(&ServerModels::UserAccountInfo::XboxInfo)) 
			    ->Property("CustomIdInfo", BehaviorValueProperty(&ServerModels::UserAccountInfo::CustomIdInfo)) 
			;
		
			behaviorContext->Class<ServerModels::AuthenticateSessionTicketResult>("PlayFabServer_AuthenticateSessionTicketResult")
                ->Constructor() 
			    ->Property("UserInfo", BehaviorValueProperty(&ServerModels::AuthenticateSessionTicketResult::UserInfo)) 
			;
		
			behaviorContext->Class<ServerModels::AwardSteamAchievementItem>("PlayFabServer_AwardSteamAchievementItem")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ServerModels::AwardSteamAchievementItem::PlayFabId)) 
			    ->Property("AchievementName", BehaviorValueProperty(&ServerModels::AwardSteamAchievementItem::AchievementName)) 
			    ->Property("Result", BehaviorValueProperty(&ServerModels::AwardSteamAchievementItem::Result)) 
			;
		
			behaviorContext->Class<ServerModels::AwardSteamAchievementRequest>("PlayFabServer_AwardSteamAchievementRequest")
                ->Constructor() 
			    ->Property("Achievements", BehaviorValueProperty(&ServerModels::AwardSteamAchievementRequest::Achievements)) 
			;
		
			behaviorContext->Class<ServerModels::AwardSteamAchievementResult>("PlayFabServer_AwardSteamAchievementResult")
                ->Constructor() 
			    ->Property("AchievementResults", BehaviorValueProperty(&ServerModels::AwardSteamAchievementResult::AchievementResults)) 
			;
		
			behaviorContext->Class<ServerModels::BanInfo>("PlayFabServer_BanInfo")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ServerModels::BanInfo::PlayFabId)) 
			    ->Property("BanId", BehaviorValueProperty(&ServerModels::BanInfo::BanId)) 
			    ->Property("IPAddress", BehaviorValueProperty(&ServerModels::BanInfo::IPAddress)) 
			    ->Property("MACAddress", BehaviorValueProperty(&ServerModels::BanInfo::MACAddress)) 
			    ->Property("Created", BehaviorValueProperty(&ServerModels::BanInfo::Created)) 
			    ->Property("Expires", BehaviorValueProperty(&ServerModels::BanInfo::Expires)) 
			    ->Property("Reason", BehaviorValueProperty(&ServerModels::BanInfo::Reason)) 
			    ->Property("Active", BehaviorValueProperty(&ServerModels::BanInfo::Active)) 
			;
		
			behaviorContext->Class<ServerModels::BanRequest>("PlayFabServer_BanRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ServerModels::BanRequest::PlayFabId)) 
			    ->Property("IPAddress", BehaviorValueProperty(&ServerModels::BanRequest::IPAddress)) 
			    ->Property("MACAddress", BehaviorValueProperty(&ServerModels::BanRequest::MACAddress)) 
			    ->Property("Reason", BehaviorValueProperty(&ServerModels::BanRequest::Reason)) 
			    ->Property("DurationInHours", BehaviorValueProperty(&ServerModels::BanRequest::DurationInHours)) 
			;
		
			behaviorContext->Class<ServerModels::BanUsersRequest>("PlayFabServer_BanUsersRequest")
                ->Constructor() 
			    ->Property("Bans", BehaviorValueProperty(&ServerModels::BanUsersRequest::Bans)) 
			;
		
			behaviorContext->Class<ServerModels::BanUsersResult>("PlayFabServer_BanUsersResult")
                ->Constructor() 
			    ->Property("BanData", BehaviorValueProperty(&ServerModels::BanUsersResult::BanData)) 
			;
		
			behaviorContext->Class<ServerModels::CatalogItemConsumableInfo>("PlayFabServer_CatalogItemConsumableInfo")
                ->Constructor() 
			    ->Property("UsageCount", BehaviorValueProperty(&ServerModels::CatalogItemConsumableInfo::UsageCount)) 
			    ->Property("UsagePeriod", BehaviorValueProperty(&ServerModels::CatalogItemConsumableInfo::UsagePeriod)) 
			    ->Property("UsagePeriodGroup", BehaviorValueProperty(&ServerModels::CatalogItemConsumableInfo::UsagePeriodGroup)) 
			;
		
			behaviorContext->Class<ServerModels::CatalogItemContainerInfo>("PlayFabServer_CatalogItemContainerInfo")
                ->Constructor() 
			    ->Property("KeyItemId", BehaviorValueProperty(&ServerModels::CatalogItemContainerInfo::KeyItemId)) 
			    ->Property("ItemContents", BehaviorValueProperty(&ServerModels::CatalogItemContainerInfo::ItemContents)) 
			    ->Property("ResultTableContents", BehaviorValueProperty(&ServerModels::CatalogItemContainerInfo::ResultTableContents)) 
			;
		
			behaviorContext->Class<ServerModels::CatalogItemBundleInfo>("PlayFabServer_CatalogItemBundleInfo")
                ->Constructor() 
			    ->Property("BundledItems", BehaviorValueProperty(&ServerModels::CatalogItemBundleInfo::BundledItems)) 
			    ->Property("BundledResultTables", BehaviorValueProperty(&ServerModels::CatalogItemBundleInfo::BundledResultTables)) 
			;
		
			behaviorContext->Class<ServerModels::CatalogItem>("PlayFabServer_CatalogItem")
                ->Constructor() 
			    ->Property("ItemId", BehaviorValueProperty(&ServerModels::CatalogItem::ItemId)) 
			    ->Property("ItemClass", BehaviorValueProperty(&ServerModels::CatalogItem::ItemClass)) 
			    ->Property("CatalogVersion", BehaviorValueProperty(&ServerModels::CatalogItem::CatalogVersion)) 
			    ->Property("DisplayName", BehaviorValueProperty(&ServerModels::CatalogItem::DisplayName)) 
			    ->Property("Description", BehaviorValueProperty(&ServerModels::CatalogItem::Description)) 
			    ->Property("Tags", BehaviorValueProperty(&ServerModels::CatalogItem::Tags)) 
			    ->Property("CustomData", BehaviorValueProperty(&ServerModels::CatalogItem::CustomData)) 
			    ->Property("Consumable", BehaviorValueProperty(&ServerModels::CatalogItem::Consumable)) 
			    ->Property("Container", BehaviorValueProperty(&ServerModels::CatalogItem::Container)) 
			    ->Property("Bundle", BehaviorValueProperty(&ServerModels::CatalogItem::Bundle)) 
			    ->Property("CanBecomeCharacter", BehaviorValueProperty(&ServerModels::CatalogItem::CanBecomeCharacter)) 
			    ->Property("IsStackable", BehaviorValueProperty(&ServerModels::CatalogItem::IsStackable)) 
			    ->Property("IsTradable", BehaviorValueProperty(&ServerModels::CatalogItem::IsTradable)) 
			    ->Property("ItemImageUrl", BehaviorValueProperty(&ServerModels::CatalogItem::ItemImageUrl)) 
			    ->Property("IsLimitedEdition", BehaviorValueProperty(&ServerModels::CatalogItem::IsLimitedEdition)) 
			    ->Property("InitialLimitedEditionCount", BehaviorValueProperty(&ServerModels::CatalogItem::InitialLimitedEditionCount)) 
			;
		
			behaviorContext->Class<ServerModels::ItemInstance>("PlayFabServer_ItemInstance")
                ->Constructor() 
			    ->Property("ItemId", BehaviorValueProperty(&ServerModels::ItemInstance::ItemId)) 
			    ->Property("ItemInstanceId", BehaviorValueProperty(&ServerModels::ItemInstance::ItemInstanceId)) 
			    ->Property("ItemClass", BehaviorValueProperty(&ServerModels::ItemInstance::ItemClass)) 
			    ->Property("PurchaseDate", BehaviorValueProperty(&ServerModels::ItemInstance::PurchaseDate)) 
			    ->Property("Expiration", BehaviorValueProperty(&ServerModels::ItemInstance::Expiration)) 
			    ->Property("RemainingUses", BehaviorValueProperty(&ServerModels::ItemInstance::RemainingUses)) 
			    ->Property("UsesIncrementedBy", BehaviorValueProperty(&ServerModels::ItemInstance::UsesIncrementedBy)) 
			    ->Property("Annotation", BehaviorValueProperty(&ServerModels::ItemInstance::Annotation)) 
			    ->Property("CatalogVersion", BehaviorValueProperty(&ServerModels::ItemInstance::CatalogVersion)) 
			    ->Property("BundleParent", BehaviorValueProperty(&ServerModels::ItemInstance::BundleParent)) 
			    ->Property("DisplayName", BehaviorValueProperty(&ServerModels::ItemInstance::DisplayName)) 
			    ->Property("UnitCurrency", BehaviorValueProperty(&ServerModels::ItemInstance::UnitCurrency)) 
			    ->Property("UnitPrice", BehaviorValueProperty(&ServerModels::ItemInstance::UnitPrice)) 
			    ->Property("BundleContents", BehaviorValueProperty(&ServerModels::ItemInstance::BundleContents)) 
			;
		
			behaviorContext->Class<ServerModels::CharacterInventory>("PlayFabServer_CharacterInventory")
                ->Constructor() 
			    ->Property("CharacterId", BehaviorValueProperty(&ServerModels::CharacterInventory::CharacterId)) 
			    ->Property("Inventory", BehaviorValueProperty(&ServerModels::CharacterInventory::Inventory)) 
			;
		
			behaviorContext->Class<ServerModels::CharacterLeaderboardEntry>("PlayFabServer_CharacterLeaderboardEntry")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ServerModels::CharacterLeaderboardEntry::PlayFabId)) 
			    ->Property("CharacterId", BehaviorValueProperty(&ServerModels::CharacterLeaderboardEntry::CharacterId)) 
			    ->Property("CharacterName", BehaviorValueProperty(&ServerModels::CharacterLeaderboardEntry::CharacterName)) 
			    ->Property("DisplayName", BehaviorValueProperty(&ServerModels::CharacterLeaderboardEntry::DisplayName)) 
			    ->Property("CharacterType", BehaviorValueProperty(&ServerModels::CharacterLeaderboardEntry::CharacterType)) 
			    ->Property("StatValue", BehaviorValueProperty(&ServerModels::CharacterLeaderboardEntry::StatValue)) 
			    ->Property("Position", BehaviorValueProperty(&ServerModels::CharacterLeaderboardEntry::Position)) 
			;
		
			behaviorContext->Class<ServerModels::CharacterResult>("PlayFabServer_CharacterResult")
                ->Constructor() 
			    ->Property("CharacterId", BehaviorValueProperty(&ServerModels::CharacterResult::CharacterId)) 
			    ->Property("CharacterName", BehaviorValueProperty(&ServerModels::CharacterResult::CharacterName)) 
			    ->Property("CharacterType", BehaviorValueProperty(&ServerModels::CharacterResult::CharacterType)) 
			;
		
			behaviorContext->Class<ServerModels::ConsumeItemRequest>("PlayFabServer_ConsumeItemRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ServerModels::ConsumeItemRequest::PlayFabId)) 
			    ->Property("ItemInstanceId", BehaviorValueProperty(&ServerModels::ConsumeItemRequest::ItemInstanceId)) 
			    ->Property("ConsumeCount", BehaviorValueProperty(&ServerModels::ConsumeItemRequest::ConsumeCount)) 
			    ->Property("CharacterId", BehaviorValueProperty(&ServerModels::ConsumeItemRequest::CharacterId)) 
			;
		
			behaviorContext->Class<ServerModels::ConsumeItemResult>("PlayFabServer_ConsumeItemResult")
                ->Constructor() 
			    ->Property("ItemInstanceId", BehaviorValueProperty(&ServerModels::ConsumeItemResult::ItemInstanceId)) 
			    ->Property("RemainingUses", BehaviorValueProperty(&ServerModels::ConsumeItemResult::RemainingUses)) 
			;
		
			behaviorContext->Class<ServerModels::ContactEmailInfo>("PlayFabServer_ContactEmailInfo")
                ->Constructor() 
			    ->Property("Name", BehaviorValueProperty(&ServerModels::ContactEmailInfo::Name)) 
			    ->Property("EmailAddress", BehaviorValueProperty(&ServerModels::ContactEmailInfo::EmailAddress)) 
			    ->Property("VerificationStatus", BehaviorValueProperty(&ServerModels::ContactEmailInfo::VerificationStatus)) 
			;
		
			behaviorContext->Class<ServerModels::CreateSharedGroupRequest>("PlayFabServer_CreateSharedGroupRequest")
                ->Constructor() 
			    ->Property("SharedGroupId", BehaviorValueProperty(&ServerModels::CreateSharedGroupRequest::SharedGroupId)) 
			;
		
			behaviorContext->Class<ServerModels::CreateSharedGroupResult>("PlayFabServer_CreateSharedGroupResult")
                ->Constructor() 
			    ->Property("SharedGroupId", BehaviorValueProperty(&ServerModels::CreateSharedGroupResult::SharedGroupId)) 
			;
		
			behaviorContext->Class<ServerModels::DeleteCharacterFromUserRequest>("PlayFabServer_DeleteCharacterFromUserRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ServerModels::DeleteCharacterFromUserRequest::PlayFabId)) 
			    ->Property("CharacterId", BehaviorValueProperty(&ServerModels::DeleteCharacterFromUserRequest::CharacterId)) 
			    ->Property("SaveCharacterInventory", BehaviorValueProperty(&ServerModels::DeleteCharacterFromUserRequest::SaveCharacterInventory)) 
			;
		
			behaviorContext->Class<ServerModels::DeleteCharacterFromUserResult>("PlayFabServer_DeleteCharacterFromUserResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<ServerModels::DeleteSharedGroupRequest>("PlayFabServer_DeleteSharedGroupRequest")
                ->Constructor() 
			    ->Property("SharedGroupId", BehaviorValueProperty(&ServerModels::DeleteSharedGroupRequest::SharedGroupId)) 
			;
		
			behaviorContext->Class<ServerModels::DeleteUsersRequest>("PlayFabServer_DeleteUsersRequest")
                ->Constructor() 
			    ->Property("PlayFabIds", BehaviorValueProperty(&ServerModels::DeleteUsersRequest::PlayFabIds)) 
			    ->Property("TitleId", BehaviorValueProperty(&ServerModels::DeleteUsersRequest::TitleId)) 
			;
		
			behaviorContext->Class<ServerModels::DeleteUsersResult>("PlayFabServer_DeleteUsersResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<ServerModels::DeregisterGameRequest>("PlayFabServer_DeregisterGameRequest")
                ->Constructor() 
			    ->Property("LobbyId", BehaviorValueProperty(&ServerModels::DeregisterGameRequest::LobbyId)) 
			;
		
			behaviorContext->Class<ServerModels::DeregisterGameResponse>("PlayFabServer_DeregisterGameResponse")
                ->Constructor() 
			;
		
			behaviorContext->Class<ServerModels::EmptyResult>("PlayFabServer_EmptyResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<ServerModels::EvaluateRandomResultTableRequest>("PlayFabServer_EvaluateRandomResultTableRequest")
                ->Constructor() 
			    ->Property("TableId", BehaviorValueProperty(&ServerModels::EvaluateRandomResultTableRequest::TableId)) 
			    ->Property("CatalogVersion", BehaviorValueProperty(&ServerModels::EvaluateRandomResultTableRequest::CatalogVersion)) 
			;
		
			behaviorContext->Class<ServerModels::EvaluateRandomResultTableResult>("PlayFabServer_EvaluateRandomResultTableResult")
                ->Constructor() 
			    ->Property("ResultItemId", BehaviorValueProperty(&ServerModels::EvaluateRandomResultTableResult::ResultItemId)) 
			;
		
			behaviorContext->Class<ServerModels::LogStatement>("PlayFabServer_LogStatement")
                ->Constructor() 
			    ->Property("Level", BehaviorValueProperty(&ServerModels::LogStatement::Level)) 
			    ->Property("Message", BehaviorValueProperty(&ServerModels::LogStatement::Message)) 
			    ->Property("Data", BehaviorValueProperty(&ServerModels::LogStatement::Data)) 
			;
		
			behaviorContext->Class<ServerModels::ScriptExecutionError>("PlayFabServer_ScriptExecutionError")
                ->Constructor() 
			    ->Property("Error", BehaviorValueProperty(&ServerModels::ScriptExecutionError::Error)) 
			    ->Property("Message", BehaviorValueProperty(&ServerModels::ScriptExecutionError::Message)) 
			    ->Property("StackTrace", BehaviorValueProperty(&ServerModels::ScriptExecutionError::StackTrace)) 
			;
		
			behaviorContext->Class<ServerModels::ExecuteCloudScriptResult>("PlayFabServer_ExecuteCloudScriptResult")
                ->Constructor() 
			    ->Property("FunctionName", BehaviorValueProperty(&ServerModels::ExecuteCloudScriptResult::FunctionName)) 
			    ->Property("Revision", BehaviorValueProperty(&ServerModels::ExecuteCloudScriptResult::Revision)) 
			    ->Property("FunctionResult", BehaviorValueProperty(&ServerModels::ExecuteCloudScriptResult::FunctionResult)) 
			    ->Property("FunctionResultTooLarge", BehaviorValueProperty(&ServerModels::ExecuteCloudScriptResult::FunctionResultTooLarge)) 
			    ->Property("Logs", BehaviorValueProperty(&ServerModels::ExecuteCloudScriptResult::Logs)) 
			    ->Property("LogsTooLarge", BehaviorValueProperty(&ServerModels::ExecuteCloudScriptResult::LogsTooLarge)) 
			    ->Property("ExecutionTimeSeconds", BehaviorValueProperty(&ServerModels::ExecuteCloudScriptResult::ExecutionTimeSeconds)) 
			    ->Property("ProcessorTimeSeconds", BehaviorValueProperty(&ServerModels::ExecuteCloudScriptResult::ProcessorTimeSeconds)) 
			    ->Property("MemoryConsumedBytes", BehaviorValueProperty(&ServerModels::ExecuteCloudScriptResult::MemoryConsumedBytes)) 
			    ->Property("APIRequestsIssued", BehaviorValueProperty(&ServerModels::ExecuteCloudScriptResult::APIRequestsIssued)) 
			    ->Property("HttpRequestsIssued", BehaviorValueProperty(&ServerModels::ExecuteCloudScriptResult::HttpRequestsIssued)) 
			    ->Property("Error", BehaviorValueProperty(&ServerModels::ExecuteCloudScriptResult::Error)) 
			;
		
			behaviorContext->Class<ServerModels::ExecuteCloudScriptServerRequest>("PlayFabServer_ExecuteCloudScriptServerRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ServerModels::ExecuteCloudScriptServerRequest::PlayFabId)) 
			    ->Property("FunctionName", BehaviorValueProperty(&ServerModels::ExecuteCloudScriptServerRequest::FunctionName)) 
			    ->Property("FunctionParameter", BehaviorValueProperty(&ServerModels::ExecuteCloudScriptServerRequest::FunctionParameter)) 
			    ->Property("RevisionSelection", BehaviorValueProperty(&ServerModels::ExecuteCloudScriptServerRequest::RevisionSelection)) 
			    ->Property("SpecificRevision", BehaviorValueProperty(&ServerModels::ExecuteCloudScriptServerRequest::SpecificRevision)) 
			    ->Property("GeneratePlayStreamEvent", BehaviorValueProperty(&ServerModels::ExecuteCloudScriptServerRequest::GeneratePlayStreamEvent)) 
			;
		
			behaviorContext->Class<ServerModels::FacebookPlayFabIdPair>("PlayFabServer_FacebookPlayFabIdPair")
                ->Constructor() 
			    ->Property("FacebookId", BehaviorValueProperty(&ServerModels::FacebookPlayFabIdPair::FacebookId)) 
			    ->Property("PlayFabId", BehaviorValueProperty(&ServerModels::FacebookPlayFabIdPair::PlayFabId)) 
			;
		
			behaviorContext->Class<ServerModels::LocationModel>("PlayFabServer_LocationModel")
                ->Constructor() 
			    ->Property("pfContinentCode", BehaviorValueProperty(&ServerModels::LocationModel::pfContinentCode)) 
			    ->Property("pfCountryCode", BehaviorValueProperty(&ServerModels::LocationModel::pfCountryCode)) 
			    ->Property("City", BehaviorValueProperty(&ServerModels::LocationModel::City)) 
			    ->Property("Latitude", BehaviorValueProperty(&ServerModels::LocationModel::Latitude)) 
			    ->Property("Longitude", BehaviorValueProperty(&ServerModels::LocationModel::Longitude)) 
			;
		
			behaviorContext->Class<ServerModels::TagModel>("PlayFabServer_TagModel")
                ->Constructor() 
			    ->Property("TagValue", BehaviorValueProperty(&ServerModels::TagModel::TagValue)) 
			;
		
			behaviorContext->Class<ServerModels::PushNotificationRegistrationModel>("PlayFabServer_PushNotificationRegistrationModel")
                ->Constructor() 
			    ->Property("Platform", BehaviorValueProperty(&ServerModels::PushNotificationRegistrationModel::Platform)) 
			    ->Property("NotificationEndpointARN", BehaviorValueProperty(&ServerModels::PushNotificationRegistrationModel::NotificationEndpointARN)) 
			;
		
			behaviorContext->Class<ServerModels::LinkedPlatformAccountModel>("PlayFabServer_LinkedPlatformAccountModel")
                ->Constructor() 
			    ->Property("Platform", BehaviorValueProperty(&ServerModels::LinkedPlatformAccountModel::Platform)) 
			    ->Property("PlatformUserId", BehaviorValueProperty(&ServerModels::LinkedPlatformAccountModel::PlatformUserId)) 
			    ->Property("Username", BehaviorValueProperty(&ServerModels::LinkedPlatformAccountModel::Username)) 
			    ->Property("Email", BehaviorValueProperty(&ServerModels::LinkedPlatformAccountModel::Email)) 
			;
		
			behaviorContext->Class<ServerModels::ValueToDateModel>("PlayFabServer_ValueToDateModel")
                ->Constructor() 
			    ->Property("Currency", BehaviorValueProperty(&ServerModels::ValueToDateModel::Currency)) 
			    ->Property("TotalValue", BehaviorValueProperty(&ServerModels::ValueToDateModel::TotalValue)) 
			    ->Property("TotalValueAsDecimal", BehaviorValueProperty(&ServerModels::ValueToDateModel::TotalValueAsDecimal)) 
			;
		
			behaviorContext->Class<ServerModels::VirtualCurrencyBalanceModel>("PlayFabServer_VirtualCurrencyBalanceModel")
                ->Constructor() 
			    ->Property("Currency", BehaviorValueProperty(&ServerModels::VirtualCurrencyBalanceModel::Currency)) 
			    ->Property("TotalValue", BehaviorValueProperty(&ServerModels::VirtualCurrencyBalanceModel::TotalValue)) 
			;
		
			behaviorContext->Class<ServerModels::StatisticModel>("PlayFabServer_StatisticModel")
                ->Constructor() 
			    ->Property("Name", BehaviorValueProperty(&ServerModels::StatisticModel::Name)) 
			    ->Property("Version", BehaviorValueProperty(&ServerModels::StatisticModel::Version)) 
			    ->Property("Value", BehaviorValueProperty(&ServerModels::StatisticModel::Value)) 
			;
		
			behaviorContext->Class<ServerModels::PlayerProfileModel>("PlayFabServer_PlayerProfileModel")
                ->Constructor() 
			    ->Property("PublisherId", BehaviorValueProperty(&ServerModels::PlayerProfileModel::PublisherId)) 
			    ->Property("TitleId", BehaviorValueProperty(&ServerModels::PlayerProfileModel::TitleId)) 
			    ->Property("PlayerId", BehaviorValueProperty(&ServerModels::PlayerProfileModel::PlayerId)) 
			    ->Property("Created", BehaviorValueProperty(&ServerModels::PlayerProfileModel::Created)) 
			    ->Property("Origination", BehaviorValueProperty(&ServerModels::PlayerProfileModel::Origination)) 
			    ->Property("LastLogin", BehaviorValueProperty(&ServerModels::PlayerProfileModel::LastLogin)) 
			    ->Property("BannedUntil", BehaviorValueProperty(&ServerModels::PlayerProfileModel::BannedUntil)) 
			    ->Property("Locations", BehaviorValueProperty(&ServerModels::PlayerProfileModel::Locations)) 
			    ->Property("DisplayName", BehaviorValueProperty(&ServerModels::PlayerProfileModel::DisplayName)) 
			    ->Property("AvatarUrl", BehaviorValueProperty(&ServerModels::PlayerProfileModel::AvatarUrl)) 
			    ->Property("Tags", BehaviorValueProperty(&ServerModels::PlayerProfileModel::Tags)) 
			    ->Property("PushNotificationRegistrations", BehaviorValueProperty(&ServerModels::PlayerProfileModel::PushNotificationRegistrations)) 
			    ->Property("LinkedAccounts", BehaviorValueProperty(&ServerModels::PlayerProfileModel::LinkedAccounts)) 
			    ->Property("AdCampaignAttributions", BehaviorValueProperty(&ServerModels::PlayerProfileModel::AdCampaignAttributions)) 
			    ->Property("TotalValueToDateInUSD", BehaviorValueProperty(&ServerModels::PlayerProfileModel::TotalValueToDateInUSD)) 
			    ->Property("ValuesToDate", BehaviorValueProperty(&ServerModels::PlayerProfileModel::ValuesToDate)) 
			    ->Property("VirtualCurrencyBalances", BehaviorValueProperty(&ServerModels::PlayerProfileModel::VirtualCurrencyBalances)) 
			    ->Property("Statistics", BehaviorValueProperty(&ServerModels::PlayerProfileModel::Statistics)) 
			;
		
			behaviorContext->Class<ServerModels::FriendInfo>("PlayFabServer_FriendInfo")
                ->Constructor() 
			    ->Property("FriendPlayFabId", BehaviorValueProperty(&ServerModels::FriendInfo::FriendPlayFabId)) 
			    ->Property("Username", BehaviorValueProperty(&ServerModels::FriendInfo::Username)) 
			    ->Property("TitleDisplayName", BehaviorValueProperty(&ServerModels::FriendInfo::TitleDisplayName)) 
			    ->Property("Tags", BehaviorValueProperty(&ServerModels::FriendInfo::Tags)) 
			    ->Property("CurrentMatchmakerLobbyId", BehaviorValueProperty(&ServerModels::FriendInfo::CurrentMatchmakerLobbyId)) 
			    ->Property("FacebookInfo", BehaviorValueProperty(&ServerModels::FriendInfo::FacebookInfo)) 
			    ->Property("SteamInfo", BehaviorValueProperty(&ServerModels::FriendInfo::SteamInfo)) 
			    ->Property("GameCenterInfo", BehaviorValueProperty(&ServerModels::FriendInfo::GameCenterInfo)) 
			    ->Property("Profile", BehaviorValueProperty(&ServerModels::FriendInfo::Profile)) 
			;
		
			behaviorContext->Class<ServerModels::GetActionGroupResult>("PlayFabServer_GetActionGroupResult")
                ->Constructor() 
			    ->Property("Name", BehaviorValueProperty(&ServerModels::GetActionGroupResult::Name)) 
			    ->Property("Id", BehaviorValueProperty(&ServerModels::GetActionGroupResult::Id)) 
			;
		
			behaviorContext->Class<ServerModels::GetAllActionGroupsRequest>("PlayFabServer_GetAllActionGroupsRequest")
                ->Constructor() 
			;
		
			behaviorContext->Class<ServerModels::GetAllActionGroupsResult>("PlayFabServer_GetAllActionGroupsResult")
                ->Constructor() 
			    ->Property("ActionGroups", BehaviorValueProperty(&ServerModels::GetAllActionGroupsResult::ActionGroups)) 
			;
		
			behaviorContext->Class<ServerModels::GetAllSegmentsRequest>("PlayFabServer_GetAllSegmentsRequest")
                ->Constructor() 
			;
		
			behaviorContext->Class<ServerModels::GetSegmentResult>("PlayFabServer_GetSegmentResult")
                ->Constructor() 
			    ->Property("Id", BehaviorValueProperty(&ServerModels::GetSegmentResult::Id)) 
			    ->Property("Name", BehaviorValueProperty(&ServerModels::GetSegmentResult::Name)) 
			    ->Property("ABTestParent", BehaviorValueProperty(&ServerModels::GetSegmentResult::ABTestParent)) 
			;
		
			behaviorContext->Class<ServerModels::GetAllSegmentsResult>("PlayFabServer_GetAllSegmentsResult")
                ->Constructor() 
			    ->Property("Segments", BehaviorValueProperty(&ServerModels::GetAllSegmentsResult::Segments)) 
			;
		
			behaviorContext->Class<ServerModels::GetCatalogItemsRequest>("PlayFabServer_GetCatalogItemsRequest")
                ->Constructor() 
			    ->Property("CatalogVersion", BehaviorValueProperty(&ServerModels::GetCatalogItemsRequest::CatalogVersion)) 
			;
		
			behaviorContext->Class<ServerModels::GetCatalogItemsResult>("PlayFabServer_GetCatalogItemsResult")
                ->Constructor() 
			    ->Property("Catalog", BehaviorValueProperty(&ServerModels::GetCatalogItemsResult::Catalog)) 
			;
		
			behaviorContext->Class<ServerModels::GetCharacterDataRequest>("PlayFabServer_GetCharacterDataRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ServerModels::GetCharacterDataRequest::PlayFabId)) 
			    ->Property("CharacterId", BehaviorValueProperty(&ServerModels::GetCharacterDataRequest::CharacterId)) 
			    ->Property("Keys", BehaviorValueProperty(&ServerModels::GetCharacterDataRequest::Keys)) 
			    ->Property("IfChangedFromDataVersion", BehaviorValueProperty(&ServerModels::GetCharacterDataRequest::IfChangedFromDataVersion)) 
			;
		
			behaviorContext->Class<ServerModels::UserDataRecord>("PlayFabServer_UserDataRecord")
                ->Constructor() 
			    ->Property("Value", BehaviorValueProperty(&ServerModels::UserDataRecord::Value)) 
			    ->Property("LastUpdated", BehaviorValueProperty(&ServerModels::UserDataRecord::LastUpdated)) 
			    ->Property("Permission", BehaviorValueProperty(&ServerModels::UserDataRecord::Permission)) 
			;
		
			behaviorContext->Class<ServerModels::GetCharacterDataResult>("PlayFabServer_GetCharacterDataResult")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ServerModels::GetCharacterDataResult::PlayFabId)) 
			    ->Property("DataVersion", BehaviorValueProperty(&ServerModels::GetCharacterDataResult::DataVersion)) 
			    ->Property("CharacterId", BehaviorValueProperty(&ServerModels::GetCharacterDataResult::CharacterId)) 
			;
		
			behaviorContext->Class<ServerModels::GetCharacterInventoryRequest>("PlayFabServer_GetCharacterInventoryRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ServerModels::GetCharacterInventoryRequest::PlayFabId)) 
			    ->Property("CharacterId", BehaviorValueProperty(&ServerModels::GetCharacterInventoryRequest::CharacterId)) 
			    ->Property("CatalogVersion", BehaviorValueProperty(&ServerModels::GetCharacterInventoryRequest::CatalogVersion)) 
			;
		
			behaviorContext->Class<ServerModels::VirtualCurrencyRechargeTime>("PlayFabServer_VirtualCurrencyRechargeTime")
                ->Constructor() 
			    ->Property("SecondsToRecharge", BehaviorValueProperty(&ServerModels::VirtualCurrencyRechargeTime::SecondsToRecharge)) 
			    ->Property("RechargeTime", BehaviorValueProperty(&ServerModels::VirtualCurrencyRechargeTime::RechargeTime)) 
			    ->Property("RechargeMax", BehaviorValueProperty(&ServerModels::VirtualCurrencyRechargeTime::RechargeMax)) 
			;
		
			behaviorContext->Class<ServerModels::GetCharacterInventoryResult>("PlayFabServer_GetCharacterInventoryResult")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ServerModels::GetCharacterInventoryResult::PlayFabId)) 
			    ->Property("CharacterId", BehaviorValueProperty(&ServerModels::GetCharacterInventoryResult::CharacterId)) 
			    ->Property("Inventory", BehaviorValueProperty(&ServerModels::GetCharacterInventoryResult::Inventory)) 
			;
		
			behaviorContext->Class<ServerModels::GetCharacterLeaderboardRequest>("PlayFabServer_GetCharacterLeaderboardRequest")
                ->Constructor() 
			    ->Property("CharacterId", BehaviorValueProperty(&ServerModels::GetCharacterLeaderboardRequest::CharacterId)) 
			    ->Property("CharacterType", BehaviorValueProperty(&ServerModels::GetCharacterLeaderboardRequest::CharacterType)) 
			    ->Property("StatisticName", BehaviorValueProperty(&ServerModels::GetCharacterLeaderboardRequest::StatisticName)) 
			    ->Property("StartPosition", BehaviorValueProperty(&ServerModels::GetCharacterLeaderboardRequest::StartPosition)) 
			    ->Property("MaxResultsCount", BehaviorValueProperty(&ServerModels::GetCharacterLeaderboardRequest::MaxResultsCount)) 
			;
		
			behaviorContext->Class<ServerModels::GetCharacterLeaderboardResult>("PlayFabServer_GetCharacterLeaderboardResult")
                ->Constructor() 
			    ->Property("Leaderboard", BehaviorValueProperty(&ServerModels::GetCharacterLeaderboardResult::Leaderboard)) 
			;
		
			behaviorContext->Class<ServerModels::GetCharacterStatisticsRequest>("PlayFabServer_GetCharacterStatisticsRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ServerModels::GetCharacterStatisticsRequest::PlayFabId)) 
			    ->Property("CharacterId", BehaviorValueProperty(&ServerModels::GetCharacterStatisticsRequest::CharacterId)) 
			;
		
			behaviorContext->Class<ServerModels::GetCharacterStatisticsResult>("PlayFabServer_GetCharacterStatisticsResult")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ServerModels::GetCharacterStatisticsResult::PlayFabId)) 
			    ->Property("CharacterId", BehaviorValueProperty(&ServerModels::GetCharacterStatisticsResult::CharacterId)) 
			;
		
			behaviorContext->Class<ServerModels::GetContentDownloadUrlRequest>("PlayFabServer_GetContentDownloadUrlRequest")
                ->Constructor() 
			    ->Property("Key", BehaviorValueProperty(&ServerModels::GetContentDownloadUrlRequest::Key)) 
			    ->Property("HttpMethod", BehaviorValueProperty(&ServerModels::GetContentDownloadUrlRequest::HttpMethod)) 
			    ->Property("ThruCDN", BehaviorValueProperty(&ServerModels::GetContentDownloadUrlRequest::ThruCDN)) 
			;
		
			behaviorContext->Class<ServerModels::GetContentDownloadUrlResult>("PlayFabServer_GetContentDownloadUrlResult")
                ->Constructor() 
			    ->Property("URL", BehaviorValueProperty(&ServerModels::GetContentDownloadUrlResult::URL)) 
			;
		
			behaviorContext->Class<ServerModels::PlayerProfileViewConstraints>("PlayFabServer_PlayerProfileViewConstraints")
                ->Constructor() 
			    ->Property("ShowDisplayName", BehaviorValueProperty(&ServerModels::PlayerProfileViewConstraints::ShowDisplayName)) 
			    ->Property("ShowCreated", BehaviorValueProperty(&ServerModels::PlayerProfileViewConstraints::ShowCreated)) 
			    ->Property("ShowOrigination", BehaviorValueProperty(&ServerModels::PlayerProfileViewConstraints::ShowOrigination)) 
			    ->Property("ShowLastLogin", BehaviorValueProperty(&ServerModels::PlayerProfileViewConstraints::ShowLastLogin)) 
			    ->Property("ShowBannedUntil", BehaviorValueProperty(&ServerModels::PlayerProfileViewConstraints::ShowBannedUntil)) 
			    ->Property("ShowStatistics", BehaviorValueProperty(&ServerModels::PlayerProfileViewConstraints::ShowStatistics)) 
			    ->Property("ShowCampaignAttributions", BehaviorValueProperty(&ServerModels::PlayerProfileViewConstraints::ShowCampaignAttributions)) 
			    ->Property("ShowPushNotificationRegistrations", BehaviorValueProperty(&ServerModels::PlayerProfileViewConstraints::ShowPushNotificationRegistrations)) 
			    ->Property("ShowLinkedAccounts", BehaviorValueProperty(&ServerModels::PlayerProfileViewConstraints::ShowLinkedAccounts)) 
			    ->Property("ShowTotalValueToDateInUsd", BehaviorValueProperty(&ServerModels::PlayerProfileViewConstraints::ShowTotalValueToDateInUsd)) 
			    ->Property("ShowValuesToDate", BehaviorValueProperty(&ServerModels::PlayerProfileViewConstraints::ShowValuesToDate)) 
			    ->Property("ShowTags", BehaviorValueProperty(&ServerModels::PlayerProfileViewConstraints::ShowTags)) 
			    ->Property("ShowLocations", BehaviorValueProperty(&ServerModels::PlayerProfileViewConstraints::ShowLocations)) 
			    ->Property("ShowAvatarUrl", BehaviorValueProperty(&ServerModels::PlayerProfileViewConstraints::ShowAvatarUrl)) 
			;
		
			behaviorContext->Class<ServerModels::GetFriendLeaderboardRequest>("PlayFabServer_GetFriendLeaderboardRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ServerModels::GetFriendLeaderboardRequest::PlayFabId)) 
			    ->Property("StatisticName", BehaviorValueProperty(&ServerModels::GetFriendLeaderboardRequest::StatisticName)) 
			    ->Property("StartPosition", BehaviorValueProperty(&ServerModels::GetFriendLeaderboardRequest::StartPosition)) 
			    ->Property("MaxResultsCount", BehaviorValueProperty(&ServerModels::GetFriendLeaderboardRequest::MaxResultsCount)) 
			    ->Property("IncludeSteamFriends", BehaviorValueProperty(&ServerModels::GetFriendLeaderboardRequest::IncludeSteamFriends)) 
			    ->Property("IncludeFacebookFriends", BehaviorValueProperty(&ServerModels::GetFriendLeaderboardRequest::IncludeFacebookFriends)) 
			    ->Property("Version", BehaviorValueProperty(&ServerModels::GetFriendLeaderboardRequest::Version)) 
			    ->Property("ProfileConstraints", BehaviorValueProperty(&ServerModels::GetFriendLeaderboardRequest::ProfileConstraints)) 
			;
		
			behaviorContext->Class<ServerModels::GetFriendsListRequest>("PlayFabServer_GetFriendsListRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ServerModels::GetFriendsListRequest::PlayFabId)) 
			    ->Property("IncludeSteamFriends", BehaviorValueProperty(&ServerModels::GetFriendsListRequest::IncludeSteamFriends)) 
			    ->Property("IncludeFacebookFriends", BehaviorValueProperty(&ServerModels::GetFriendsListRequest::IncludeFacebookFriends)) 
			    ->Property("ProfileConstraints", BehaviorValueProperty(&ServerModels::GetFriendsListRequest::ProfileConstraints)) 
			;
		
			behaviorContext->Class<ServerModels::GetFriendsListResult>("PlayFabServer_GetFriendsListResult")
                ->Constructor() 
			    ->Property("Friends", BehaviorValueProperty(&ServerModels::GetFriendsListResult::Friends)) 
			;
		
			behaviorContext->Class<ServerModels::GetLeaderboardAroundCharacterRequest>("PlayFabServer_GetLeaderboardAroundCharacterRequest")
                ->Constructor() 
			    ->Property("StatisticName", BehaviorValueProperty(&ServerModels::GetLeaderboardAroundCharacterRequest::StatisticName)) 
			    ->Property("PlayFabId", BehaviorValueProperty(&ServerModels::GetLeaderboardAroundCharacterRequest::PlayFabId)) 
			    ->Property("CharacterId", BehaviorValueProperty(&ServerModels::GetLeaderboardAroundCharacterRequest::CharacterId)) 
			    ->Property("CharacterType", BehaviorValueProperty(&ServerModels::GetLeaderboardAroundCharacterRequest::CharacterType)) 
			    ->Property("MaxResultsCount", BehaviorValueProperty(&ServerModels::GetLeaderboardAroundCharacterRequest::MaxResultsCount)) 
			;
		
			behaviorContext->Class<ServerModels::GetLeaderboardAroundCharacterResult>("PlayFabServer_GetLeaderboardAroundCharacterResult")
                ->Constructor() 
			    ->Property("Leaderboard", BehaviorValueProperty(&ServerModels::GetLeaderboardAroundCharacterResult::Leaderboard)) 
			;
		
			behaviorContext->Class<ServerModels::GetLeaderboardAroundUserRequest>("PlayFabServer_GetLeaderboardAroundUserRequest")
                ->Constructor() 
			    ->Property("StatisticName", BehaviorValueProperty(&ServerModels::GetLeaderboardAroundUserRequest::StatisticName)) 
			    ->Property("PlayFabId", BehaviorValueProperty(&ServerModels::GetLeaderboardAroundUserRequest::PlayFabId)) 
			    ->Property("MaxResultsCount", BehaviorValueProperty(&ServerModels::GetLeaderboardAroundUserRequest::MaxResultsCount)) 
			    ->Property("ProfileConstraints", BehaviorValueProperty(&ServerModels::GetLeaderboardAroundUserRequest::ProfileConstraints)) 
			    ->Property("Version", BehaviorValueProperty(&ServerModels::GetLeaderboardAroundUserRequest::Version)) 
			;
		
			behaviorContext->Class<ServerModels::PlayerLeaderboardEntry>("PlayFabServer_PlayerLeaderboardEntry")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ServerModels::PlayerLeaderboardEntry::PlayFabId)) 
			    ->Property("DisplayName", BehaviorValueProperty(&ServerModels::PlayerLeaderboardEntry::DisplayName)) 
			    ->Property("StatValue", BehaviorValueProperty(&ServerModels::PlayerLeaderboardEntry::StatValue)) 
			    ->Property("Position", BehaviorValueProperty(&ServerModels::PlayerLeaderboardEntry::Position)) 
			    ->Property("Profile", BehaviorValueProperty(&ServerModels::PlayerLeaderboardEntry::Profile)) 
			;
		
			behaviorContext->Class<ServerModels::GetLeaderboardAroundUserResult>("PlayFabServer_GetLeaderboardAroundUserResult")
                ->Constructor() 
			    ->Property("Leaderboard", BehaviorValueProperty(&ServerModels::GetLeaderboardAroundUserResult::Leaderboard)) 
			    ->Property("Version", BehaviorValueProperty(&ServerModels::GetLeaderboardAroundUserResult::Version)) 
			    ->Property("NextReset", BehaviorValueProperty(&ServerModels::GetLeaderboardAroundUserResult::NextReset)) 
			;
		
			behaviorContext->Class<ServerModels::GetLeaderboardForUsersCharactersRequest>("PlayFabServer_GetLeaderboardForUsersCharactersRequest")
                ->Constructor() 
			    ->Property("StatisticName", BehaviorValueProperty(&ServerModels::GetLeaderboardForUsersCharactersRequest::StatisticName)) 
			    ->Property("PlayFabId", BehaviorValueProperty(&ServerModels::GetLeaderboardForUsersCharactersRequest::PlayFabId)) 
			    ->Property("MaxResultsCount", BehaviorValueProperty(&ServerModels::GetLeaderboardForUsersCharactersRequest::MaxResultsCount)) 
			;
		
			behaviorContext->Class<ServerModels::GetLeaderboardForUsersCharactersResult>("PlayFabServer_GetLeaderboardForUsersCharactersResult")
                ->Constructor() 
			    ->Property("Leaderboard", BehaviorValueProperty(&ServerModels::GetLeaderboardForUsersCharactersResult::Leaderboard)) 
			;
		
			behaviorContext->Class<ServerModels::GetLeaderboardRequest>("PlayFabServer_GetLeaderboardRequest")
                ->Constructor() 
			    ->Property("StatisticName", BehaviorValueProperty(&ServerModels::GetLeaderboardRequest::StatisticName)) 
			    ->Property("StartPosition", BehaviorValueProperty(&ServerModels::GetLeaderboardRequest::StartPosition)) 
			    ->Property("MaxResultsCount", BehaviorValueProperty(&ServerModels::GetLeaderboardRequest::MaxResultsCount)) 
			    ->Property("ProfileConstraints", BehaviorValueProperty(&ServerModels::GetLeaderboardRequest::ProfileConstraints)) 
			    ->Property("Version", BehaviorValueProperty(&ServerModels::GetLeaderboardRequest::Version)) 
			;
		
			behaviorContext->Class<ServerModels::GetLeaderboardResult>("PlayFabServer_GetLeaderboardResult")
                ->Constructor() 
			    ->Property("Leaderboard", BehaviorValueProperty(&ServerModels::GetLeaderboardResult::Leaderboard)) 
			    ->Property("Version", BehaviorValueProperty(&ServerModels::GetLeaderboardResult::Version)) 
			    ->Property("NextReset", BehaviorValueProperty(&ServerModels::GetLeaderboardResult::NextReset)) 
			;
		
			behaviorContext->Class<ServerModels::GetPlayerCombinedInfoRequestParams>("PlayFabServer_GetPlayerCombinedInfoRequestParams")
                ->Constructor() 
			    ->Property("GetUserAccountInfo", BehaviorValueProperty(&ServerModels::GetPlayerCombinedInfoRequestParams::GetUserAccountInfo)) 
			    ->Property("GetUserInventory", BehaviorValueProperty(&ServerModels::GetPlayerCombinedInfoRequestParams::GetUserInventory)) 
			    ->Property("GetUserVirtualCurrency", BehaviorValueProperty(&ServerModels::GetPlayerCombinedInfoRequestParams::GetUserVirtualCurrency)) 
			    ->Property("GetUserData", BehaviorValueProperty(&ServerModels::GetPlayerCombinedInfoRequestParams::GetUserData)) 
			    ->Property("UserDataKeys", BehaviorValueProperty(&ServerModels::GetPlayerCombinedInfoRequestParams::UserDataKeys)) 
			    ->Property("GetUserReadOnlyData", BehaviorValueProperty(&ServerModels::GetPlayerCombinedInfoRequestParams::GetUserReadOnlyData)) 
			    ->Property("UserReadOnlyDataKeys", BehaviorValueProperty(&ServerModels::GetPlayerCombinedInfoRequestParams::UserReadOnlyDataKeys)) 
			    ->Property("GetCharacterInventories", BehaviorValueProperty(&ServerModels::GetPlayerCombinedInfoRequestParams::GetCharacterInventories)) 
			    ->Property("GetCharacterList", BehaviorValueProperty(&ServerModels::GetPlayerCombinedInfoRequestParams::GetCharacterList)) 
			    ->Property("GetTitleData", BehaviorValueProperty(&ServerModels::GetPlayerCombinedInfoRequestParams::GetTitleData)) 
			    ->Property("TitleDataKeys", BehaviorValueProperty(&ServerModels::GetPlayerCombinedInfoRequestParams::TitleDataKeys)) 
			    ->Property("GetPlayerStatistics", BehaviorValueProperty(&ServerModels::GetPlayerCombinedInfoRequestParams::GetPlayerStatistics)) 
			    ->Property("PlayerStatisticNames", BehaviorValueProperty(&ServerModels::GetPlayerCombinedInfoRequestParams::PlayerStatisticNames)) 
			    ->Property("GetPlayerProfile", BehaviorValueProperty(&ServerModels::GetPlayerCombinedInfoRequestParams::GetPlayerProfile)) 
			    ->Property("ProfileConstraints", BehaviorValueProperty(&ServerModels::GetPlayerCombinedInfoRequestParams::ProfileConstraints)) 
			;
		
			behaviorContext->Class<ServerModels::GetPlayerCombinedInfoRequest>("PlayFabServer_GetPlayerCombinedInfoRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ServerModels::GetPlayerCombinedInfoRequest::PlayFabId)) 
			    ->Property("InfoRequestParameters", BehaviorValueProperty(&ServerModels::GetPlayerCombinedInfoRequest::InfoRequestParameters)) 
			;
		
			behaviorContext->Class<ServerModels::StatisticValue>("PlayFabServer_StatisticValue")
                ->Constructor() 
			    ->Property("StatisticName", BehaviorValueProperty(&ServerModels::StatisticValue::StatisticName)) 
			    ->Property("Value", BehaviorValueProperty(&ServerModels::StatisticValue::Value)) 
			    ->Property("Version", BehaviorValueProperty(&ServerModels::StatisticValue::Version)) 
			;
		
			behaviorContext->Class<ServerModels::GetPlayerCombinedInfoResultPayload>("PlayFabServer_GetPlayerCombinedInfoResultPayload")
                ->Constructor() 
			    ->Property("AccountInfo", BehaviorValueProperty(&ServerModels::GetPlayerCombinedInfoResultPayload::AccountInfo)) 
			    ->Property("UserInventory", BehaviorValueProperty(&ServerModels::GetPlayerCombinedInfoResultPayload::UserInventory)) 
			    ->Property("UserDataVersion", BehaviorValueProperty(&ServerModels::GetPlayerCombinedInfoResultPayload::UserDataVersion)) 
			    ->Property("UserReadOnlyDataVersion", BehaviorValueProperty(&ServerModels::GetPlayerCombinedInfoResultPayload::UserReadOnlyDataVersion)) 
			    ->Property("CharacterList", BehaviorValueProperty(&ServerModels::GetPlayerCombinedInfoResultPayload::CharacterList)) 
			    ->Property("CharacterInventories", BehaviorValueProperty(&ServerModels::GetPlayerCombinedInfoResultPayload::CharacterInventories)) 
			    ->Property("PlayerStatistics", BehaviorValueProperty(&ServerModels::GetPlayerCombinedInfoResultPayload::PlayerStatistics)) 
			    ->Property("PlayerProfile", BehaviorValueProperty(&ServerModels::GetPlayerCombinedInfoResultPayload::PlayerProfile)) 
			;
		
			behaviorContext->Class<ServerModels::GetPlayerCombinedInfoResult>("PlayFabServer_GetPlayerCombinedInfoResult")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ServerModels::GetPlayerCombinedInfoResult::PlayFabId)) 
			    ->Property("InfoResultPayload", BehaviorValueProperty(&ServerModels::GetPlayerCombinedInfoResult::InfoResultPayload)) 
			;
		
			behaviorContext->Class<ServerModels::GetPlayerProfileRequest>("PlayFabServer_GetPlayerProfileRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ServerModels::GetPlayerProfileRequest::PlayFabId)) 
			    ->Property("ProfileConstraints", BehaviorValueProperty(&ServerModels::GetPlayerProfileRequest::ProfileConstraints)) 
			;
		
			behaviorContext->Class<ServerModels::GetPlayerProfileResult>("PlayFabServer_GetPlayerProfileResult")
                ->Constructor() 
			    ->Property("PlayerProfile", BehaviorValueProperty(&ServerModels::GetPlayerProfileResult::PlayerProfile)) 
			;
		
			behaviorContext->Class<ServerModels::GetPlayerSegmentsResult>("PlayFabServer_GetPlayerSegmentsResult")
                ->Constructor() 
			    ->Property("Segments", BehaviorValueProperty(&ServerModels::GetPlayerSegmentsResult::Segments)) 
			;
		
			behaviorContext->Class<ServerModels::GetPlayersInSegmentRequest>("PlayFabServer_GetPlayersInSegmentRequest")
                ->Constructor() 
			    ->Property("SegmentId", BehaviorValueProperty(&ServerModels::GetPlayersInSegmentRequest::SegmentId)) 
			    ->Property("SecondsToLive", BehaviorValueProperty(&ServerModels::GetPlayersInSegmentRequest::SecondsToLive)) 
			    ->Property("MaxBatchSize", BehaviorValueProperty(&ServerModels::GetPlayersInSegmentRequest::MaxBatchSize)) 
			    ->Property("ContinuationToken", BehaviorValueProperty(&ServerModels::GetPlayersInSegmentRequest::ContinuationToken)) 
			;
		
			behaviorContext->Class<ServerModels::PlayerLocation>("PlayFabServer_PlayerLocation")
                ->Constructor() 
			    ->Property("pfContinentCode",
				    [](ServerModels::PlayerLocation* p) { return p->pfContinentCode; },
				    [](ServerModels::PlayerLocation* p, ServerModels::ContinentCode v) { p->pfContinentCode = v; })
			    ->Property("pfCountryCode",
				    [](ServerModels::PlayerLocation* p) { return p->pfCountryCode; },
				    [](ServerModels::PlayerLocation* p, ServerModels::CountryCode v) { p->pfCountryCode = v; })
			    ->Property("City", BehaviorValueProperty(&ServerModels::PlayerLocation::City)) 
			    ->Property("Latitude", BehaviorValueProperty(&ServerModels::PlayerLocation::Latitude)) 
			    ->Property("Longitude", BehaviorValueProperty(&ServerModels::PlayerLocation::Longitude)) 
			;
		
			behaviorContext->Class<ServerModels::PushNotificationRegistration>("PlayFabServer_PushNotificationRegistration")
                ->Constructor() 
			    ->Property("Platform", BehaviorValueProperty(&ServerModels::PushNotificationRegistration::Platform)) 
			    ->Property("NotificationEndpointARN", BehaviorValueProperty(&ServerModels::PushNotificationRegistration::NotificationEndpointARN)) 
			;
		
			behaviorContext->Class<ServerModels::PlayerLinkedAccount>("PlayFabServer_PlayerLinkedAccount")
                ->Constructor() 
			    ->Property("Platform", BehaviorValueProperty(&ServerModels::PlayerLinkedAccount::Platform)) 
			    ->Property("PlatformUserId", BehaviorValueProperty(&ServerModels::PlayerLinkedAccount::PlatformUserId)) 
			    ->Property("Username", BehaviorValueProperty(&ServerModels::PlayerLinkedAccount::Username)) 
			    ->Property("Email", BehaviorValueProperty(&ServerModels::PlayerLinkedAccount::Email)) 
			;
		
			behaviorContext->Class<ServerModels::PlayerStatistic>("PlayFabServer_PlayerStatistic")
                ->Constructor() 
			    ->Property("Id", BehaviorValueProperty(&ServerModels::PlayerStatistic::Id)) 
			    ->Property("StatisticVersion", BehaviorValueProperty(&ServerModels::PlayerStatistic::StatisticVersion)) 
			    ->Property("StatisticValue", BehaviorValueProperty(&ServerModels::PlayerStatistic::StatisticValue)) 
			    ->Property("Name", BehaviorValueProperty(&ServerModels::PlayerStatistic::Name)) 
			;
		
			behaviorContext->Class<ServerModels::PlayerProfile>("PlayFabServer_PlayerProfile")
                ->Constructor() 
			    ->Property("PlayerId", BehaviorValueProperty(&ServerModels::PlayerProfile::PlayerId)) 
			    ->Property("TitleId", BehaviorValueProperty(&ServerModels::PlayerProfile::TitleId)) 
			    ->Property("DisplayName", BehaviorValueProperty(&ServerModels::PlayerProfile::DisplayName)) 
			    ->Property("PublisherId", BehaviorValueProperty(&ServerModels::PlayerProfile::PublisherId)) 
			    ->Property("Origination", BehaviorValueProperty(&ServerModels::PlayerProfile::Origination)) 
			    ->Property("Created", BehaviorValueProperty(&ServerModels::PlayerProfile::Created)) 
			    ->Property("LastLogin", BehaviorValueProperty(&ServerModels::PlayerProfile::LastLogin)) 
			    ->Property("BannedUntil", BehaviorValueProperty(&ServerModels::PlayerProfile::BannedUntil)) 
			    ->Property("AvatarUrl", BehaviorValueProperty(&ServerModels::PlayerProfile::AvatarUrl)) 
			    ->Property("TotalValueToDateInUSD", BehaviorValueProperty(&ServerModels::PlayerProfile::TotalValueToDateInUSD)) 
			    ->Property("Tags", BehaviorValueProperty(&ServerModels::PlayerProfile::Tags)) 
			    ->Property("AdCampaignAttributions", BehaviorValueProperty(&ServerModels::PlayerProfile::AdCampaignAttributions)) 
			    ->Property("PushNotificationRegistrations", BehaviorValueProperty(&ServerModels::PlayerProfile::PushNotificationRegistrations)) 
			    ->Property("LinkedAccounts", BehaviorValueProperty(&ServerModels::PlayerProfile::LinkedAccounts)) 
			    ->Property("PlayerStatistics", BehaviorValueProperty(&ServerModels::PlayerProfile::PlayerStatistics)) 
			    ->Property("ContactEmailAddresses", BehaviorValueProperty(&ServerModels::PlayerProfile::ContactEmailAddresses)) 
			;
		
			behaviorContext->Class<ServerModels::GetPlayersInSegmentResult>("PlayFabServer_GetPlayersInSegmentResult")
                ->Constructor() 
			    ->Property("ProfilesInSegment", BehaviorValueProperty(&ServerModels::GetPlayersInSegmentResult::ProfilesInSegment)) 
			    ->Property("ContinuationToken", BehaviorValueProperty(&ServerModels::GetPlayersInSegmentResult::ContinuationToken)) 
			    ->Property("PlayerProfiles", BehaviorValueProperty(&ServerModels::GetPlayersInSegmentResult::PlayerProfiles)) 
			;
		
			behaviorContext->Class<ServerModels::GetPlayersSegmentsRequest>("PlayFabServer_GetPlayersSegmentsRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ServerModels::GetPlayersSegmentsRequest::PlayFabId)) 
			;
		
			behaviorContext->Class<ServerModels::StatisticNameVersion>("PlayFabServer_StatisticNameVersion")
                ->Constructor() 
			    ->Property("StatisticName", BehaviorValueProperty(&ServerModels::StatisticNameVersion::StatisticName)) 
			    ->Property("Version", BehaviorValueProperty(&ServerModels::StatisticNameVersion::Version)) 
			;
		
			behaviorContext->Class<ServerModels::GetPlayerStatisticsRequest>("PlayFabServer_GetPlayerStatisticsRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ServerModels::GetPlayerStatisticsRequest::PlayFabId)) 
			    ->Property("StatisticNames", BehaviorValueProperty(&ServerModels::GetPlayerStatisticsRequest::StatisticNames)) 
			    ->Property("StatisticNameVersions", BehaviorValueProperty(&ServerModels::GetPlayerStatisticsRequest::StatisticNameVersions)) 
			;
		
			behaviorContext->Class<ServerModels::GetPlayerStatisticsResult>("PlayFabServer_GetPlayerStatisticsResult")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ServerModels::GetPlayerStatisticsResult::PlayFabId)) 
			    ->Property("Statistics", BehaviorValueProperty(&ServerModels::GetPlayerStatisticsResult::Statistics)) 
			;
		
			behaviorContext->Class<ServerModels::GetPlayerStatisticVersionsRequest>("PlayFabServer_GetPlayerStatisticVersionsRequest")
                ->Constructor() 
			    ->Property("StatisticName", BehaviorValueProperty(&ServerModels::GetPlayerStatisticVersionsRequest::StatisticName)) 
			;
		
			behaviorContext->Class<ServerModels::PlayerStatisticVersion>("PlayFabServer_PlayerStatisticVersion")
                ->Constructor() 
			    ->Property("StatisticName", BehaviorValueProperty(&ServerModels::PlayerStatisticVersion::StatisticName)) 
			    ->Property("Version", BehaviorValueProperty(&ServerModels::PlayerStatisticVersion::Version)) 
			    ->Property("ScheduledActivationTime", BehaviorValueProperty(&ServerModels::PlayerStatisticVersion::ScheduledActivationTime)) 
			    ->Property("ActivationTime", BehaviorValueProperty(&ServerModels::PlayerStatisticVersion::ActivationTime)) 
			    ->Property("ScheduledDeactivationTime", BehaviorValueProperty(&ServerModels::PlayerStatisticVersion::ScheduledDeactivationTime)) 
			    ->Property("DeactivationTime", BehaviorValueProperty(&ServerModels::PlayerStatisticVersion::DeactivationTime)) 
			;
		
			behaviorContext->Class<ServerModels::GetPlayerStatisticVersionsResult>("PlayFabServer_GetPlayerStatisticVersionsResult")
                ->Constructor() 
			    ->Property("StatisticVersions", BehaviorValueProperty(&ServerModels::GetPlayerStatisticVersionsResult::StatisticVersions)) 
			;
		
			behaviorContext->Class<ServerModels::GetPlayerTagsRequest>("PlayFabServer_GetPlayerTagsRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ServerModels::GetPlayerTagsRequest::PlayFabId)) 
			    ->Property("Namespace", BehaviorValueProperty(&ServerModels::GetPlayerTagsRequest::Namespace)) 
			;
		
			behaviorContext->Class<ServerModels::GetPlayerTagsResult>("PlayFabServer_GetPlayerTagsResult")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ServerModels::GetPlayerTagsResult::PlayFabId)) 
			    ->Property("Tags", BehaviorValueProperty(&ServerModels::GetPlayerTagsResult::Tags)) 
			;
		
			behaviorContext->Class<ServerModels::GetPlayFabIDsFromFacebookIDsRequest>("PlayFabServer_GetPlayFabIDsFromFacebookIDsRequest")
                ->Constructor() 
			    ->Property("FacebookIDs", BehaviorValueProperty(&ServerModels::GetPlayFabIDsFromFacebookIDsRequest::FacebookIDs)) 
			;
		
			behaviorContext->Class<ServerModels::GetPlayFabIDsFromFacebookIDsResult>("PlayFabServer_GetPlayFabIDsFromFacebookIDsResult")
                ->Constructor() 
			    ->Property("Data", BehaviorValueProperty(&ServerModels::GetPlayFabIDsFromFacebookIDsResult::Data)) 
			;
		
			behaviorContext->Class<ServerModels::GetPlayFabIDsFromSteamIDsRequest>("PlayFabServer_GetPlayFabIDsFromSteamIDsRequest")
                ->Constructor() 
			    ->Property("SteamStringIDs", BehaviorValueProperty(&ServerModels::GetPlayFabIDsFromSteamIDsRequest::SteamStringIDs)) 
			;
		
			behaviorContext->Class<ServerModels::SteamPlayFabIdPair>("PlayFabServer_SteamPlayFabIdPair")
                ->Constructor() 
			    ->Property("SteamStringId", BehaviorValueProperty(&ServerModels::SteamPlayFabIdPair::SteamStringId)) 
			    ->Property("PlayFabId", BehaviorValueProperty(&ServerModels::SteamPlayFabIdPair::PlayFabId)) 
			;
		
			behaviorContext->Class<ServerModels::GetPlayFabIDsFromSteamIDsResult>("PlayFabServer_GetPlayFabIDsFromSteamIDsResult")
                ->Constructor() 
			    ->Property("Data", BehaviorValueProperty(&ServerModels::GetPlayFabIDsFromSteamIDsResult::Data)) 
			;
		
			behaviorContext->Class<ServerModels::GetPublisherDataRequest>("PlayFabServer_GetPublisherDataRequest")
                ->Constructor() 
			    ->Property("Keys", BehaviorValueProperty(&ServerModels::GetPublisherDataRequest::Keys)) 
			;
		
			behaviorContext->Class<ServerModels::GetPublisherDataResult>("PlayFabServer_GetPublisherDataResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<ServerModels::GetRandomResultTablesRequest>("PlayFabServer_GetRandomResultTablesRequest")
                ->Constructor() 
			    ->Property("CatalogVersion", BehaviorValueProperty(&ServerModels::GetRandomResultTablesRequest::CatalogVersion)) 
			    ->Property("TableIDs", BehaviorValueProperty(&ServerModels::GetRandomResultTablesRequest::TableIDs)) 
			;
		
			behaviorContext->Class<ServerModels::ResultTableNode>("PlayFabServer_ResultTableNode")
                ->Constructor() 
			    ->Property("ResultItemType",
				    [](ServerModels::ResultTableNode* p) { return p->ResultItemType; },
				    [](ServerModels::ResultTableNode* p, ServerModels::ResultTableNodeType v) { p->ResultItemType = v; })
			    ->Property("ResultItem", BehaviorValueProperty(&ServerModels::ResultTableNode::ResultItem)) 
			    ->Property("Weight", BehaviorValueProperty(&ServerModels::ResultTableNode::Weight)) 
			;
		
			behaviorContext->Class<ServerModels::RandomResultTableListing>("PlayFabServer_RandomResultTableListing")
                ->Constructor() 
			    ->Property("CatalogVersion", BehaviorValueProperty(&ServerModels::RandomResultTableListing::CatalogVersion)) 
			    ->Property("TableId", BehaviorValueProperty(&ServerModels::RandomResultTableListing::TableId)) 
			    ->Property("Nodes", BehaviorValueProperty(&ServerModels::RandomResultTableListing::Nodes)) 
			;
		
			behaviorContext->Class<ServerModels::GetRandomResultTablesResult>("PlayFabServer_GetRandomResultTablesResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<ServerModels::GetSharedGroupDataRequest>("PlayFabServer_GetSharedGroupDataRequest")
                ->Constructor() 
			    ->Property("SharedGroupId", BehaviorValueProperty(&ServerModels::GetSharedGroupDataRequest::SharedGroupId)) 
			    ->Property("Keys", BehaviorValueProperty(&ServerModels::GetSharedGroupDataRequest::Keys)) 
			    ->Property("GetMembers", BehaviorValueProperty(&ServerModels::GetSharedGroupDataRequest::GetMembers)) 
			;
		
			behaviorContext->Class<ServerModels::SharedGroupDataRecord>("PlayFabServer_SharedGroupDataRecord")
                ->Constructor() 
			    ->Property("Value", BehaviorValueProperty(&ServerModels::SharedGroupDataRecord::Value)) 
			    ->Property("LastUpdatedBy", BehaviorValueProperty(&ServerModels::SharedGroupDataRecord::LastUpdatedBy)) 
			    ->Property("LastUpdated", BehaviorValueProperty(&ServerModels::SharedGroupDataRecord::LastUpdated)) 
			    ->Property("Permission", BehaviorValueProperty(&ServerModels::SharedGroupDataRecord::Permission)) 
			;
		
			behaviorContext->Class<ServerModels::GetSharedGroupDataResult>("PlayFabServer_GetSharedGroupDataResult")
                ->Constructor() 
			    ->Property("Members", BehaviorValueProperty(&ServerModels::GetSharedGroupDataResult::Members)) 
			;
		
			behaviorContext->Class<ServerModels::GetTimeRequest>("PlayFabServer_GetTimeRequest")
                ->Constructor() 
			;
		
			behaviorContext->Class<ServerModels::GetTimeResult>("PlayFabServer_GetTimeResult")
                ->Constructor() 
			    ->Property("Time", BehaviorValueProperty(&ServerModels::GetTimeResult::Time)) 
			;
		
			behaviorContext->Class<ServerModels::GetTitleDataRequest>("PlayFabServer_GetTitleDataRequest")
                ->Constructor() 
			    ->Property("Keys", BehaviorValueProperty(&ServerModels::GetTitleDataRequest::Keys)) 
			;
		
			behaviorContext->Class<ServerModels::GetTitleDataResult>("PlayFabServer_GetTitleDataResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<ServerModels::GetTitleNewsRequest>("PlayFabServer_GetTitleNewsRequest")
                ->Constructor() 
			    ->Property("Count", BehaviorValueProperty(&ServerModels::GetTitleNewsRequest::Count)) 
			;
		
			behaviorContext->Class<ServerModels::TitleNewsItem>("PlayFabServer_TitleNewsItem")
                ->Constructor() 
			    ->Property("Timestamp", BehaviorValueProperty(&ServerModels::TitleNewsItem::Timestamp)) 
			    ->Property("NewsId", BehaviorValueProperty(&ServerModels::TitleNewsItem::NewsId)) 
			    ->Property("Title", BehaviorValueProperty(&ServerModels::TitleNewsItem::Title)) 
			    ->Property("Body", BehaviorValueProperty(&ServerModels::TitleNewsItem::Body)) 
			;
		
			behaviorContext->Class<ServerModels::GetTitleNewsResult>("PlayFabServer_GetTitleNewsResult")
                ->Constructor() 
			    ->Property("News", BehaviorValueProperty(&ServerModels::GetTitleNewsResult::News)) 
			;
		
			behaviorContext->Class<ServerModels::GetUserAccountInfoRequest>("PlayFabServer_GetUserAccountInfoRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ServerModels::GetUserAccountInfoRequest::PlayFabId)) 
			;
		
			behaviorContext->Class<ServerModels::GetUserAccountInfoResult>("PlayFabServer_GetUserAccountInfoResult")
                ->Constructor() 
			    ->Property("UserInfo", BehaviorValueProperty(&ServerModels::GetUserAccountInfoResult::UserInfo)) 
			;
		
			behaviorContext->Class<ServerModels::GetUserBansRequest>("PlayFabServer_GetUserBansRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ServerModels::GetUserBansRequest::PlayFabId)) 
			;
		
			behaviorContext->Class<ServerModels::GetUserBansResult>("PlayFabServer_GetUserBansResult")
                ->Constructor() 
			    ->Property("BanData", BehaviorValueProperty(&ServerModels::GetUserBansResult::BanData)) 
			;
		
			behaviorContext->Class<ServerModels::GetUserDataRequest>("PlayFabServer_GetUserDataRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ServerModels::GetUserDataRequest::PlayFabId)) 
			    ->Property("Keys", BehaviorValueProperty(&ServerModels::GetUserDataRequest::Keys)) 
			    ->Property("IfChangedFromDataVersion", BehaviorValueProperty(&ServerModels::GetUserDataRequest::IfChangedFromDataVersion)) 
			;
		
			behaviorContext->Class<ServerModels::GetUserDataResult>("PlayFabServer_GetUserDataResult")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ServerModels::GetUserDataResult::PlayFabId)) 
			    ->Property("DataVersion", BehaviorValueProperty(&ServerModels::GetUserDataResult::DataVersion)) 
			;
		
			behaviorContext->Class<ServerModels::GetUserInventoryRequest>("PlayFabServer_GetUserInventoryRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ServerModels::GetUserInventoryRequest::PlayFabId)) 
			;
		
			behaviorContext->Class<ServerModels::GetUserInventoryResult>("PlayFabServer_GetUserInventoryResult")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ServerModels::GetUserInventoryResult::PlayFabId)) 
			    ->Property("Inventory", BehaviorValueProperty(&ServerModels::GetUserInventoryResult::Inventory)) 
			;
		
			behaviorContext->Class<ServerModels::GrantCharacterToUserRequest>("PlayFabServer_GrantCharacterToUserRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ServerModels::GrantCharacterToUserRequest::PlayFabId)) 
			    ->Property("CharacterName", BehaviorValueProperty(&ServerModels::GrantCharacterToUserRequest::CharacterName)) 
			    ->Property("CharacterType", BehaviorValueProperty(&ServerModels::GrantCharacterToUserRequest::CharacterType)) 
			;
		
			behaviorContext->Class<ServerModels::GrantCharacterToUserResult>("PlayFabServer_GrantCharacterToUserResult")
                ->Constructor() 
			    ->Property("CharacterId", BehaviorValueProperty(&ServerModels::GrantCharacterToUserResult::CharacterId)) 
			;
		
			behaviorContext->Class<ServerModels::GrantedItemInstance>("PlayFabServer_GrantedItemInstance")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ServerModels::GrantedItemInstance::PlayFabId)) 
			    ->Property("CharacterId", BehaviorValueProperty(&ServerModels::GrantedItemInstance::CharacterId)) 
			    ->Property("Result", BehaviorValueProperty(&ServerModels::GrantedItemInstance::Result)) 
			    ->Property("ItemId", BehaviorValueProperty(&ServerModels::GrantedItemInstance::ItemId)) 
			    ->Property("ItemInstanceId", BehaviorValueProperty(&ServerModels::GrantedItemInstance::ItemInstanceId)) 
			    ->Property("ItemClass", BehaviorValueProperty(&ServerModels::GrantedItemInstance::ItemClass)) 
			    ->Property("PurchaseDate", BehaviorValueProperty(&ServerModels::GrantedItemInstance::PurchaseDate)) 
			    ->Property("Expiration", BehaviorValueProperty(&ServerModels::GrantedItemInstance::Expiration)) 
			    ->Property("RemainingUses", BehaviorValueProperty(&ServerModels::GrantedItemInstance::RemainingUses)) 
			    ->Property("UsesIncrementedBy", BehaviorValueProperty(&ServerModels::GrantedItemInstance::UsesIncrementedBy)) 
			    ->Property("Annotation", BehaviorValueProperty(&ServerModels::GrantedItemInstance::Annotation)) 
			    ->Property("CatalogVersion", BehaviorValueProperty(&ServerModels::GrantedItemInstance::CatalogVersion)) 
			    ->Property("BundleParent", BehaviorValueProperty(&ServerModels::GrantedItemInstance::BundleParent)) 
			    ->Property("DisplayName", BehaviorValueProperty(&ServerModels::GrantedItemInstance::DisplayName)) 
			    ->Property("UnitCurrency", BehaviorValueProperty(&ServerModels::GrantedItemInstance::UnitCurrency)) 
			    ->Property("UnitPrice", BehaviorValueProperty(&ServerModels::GrantedItemInstance::UnitPrice)) 
			    ->Property("BundleContents", BehaviorValueProperty(&ServerModels::GrantedItemInstance::BundleContents)) 
			;
		
			behaviorContext->Class<ServerModels::GrantItemsToCharacterRequest>("PlayFabServer_GrantItemsToCharacterRequest")
                ->Constructor() 
			    ->Property("CatalogVersion", BehaviorValueProperty(&ServerModels::GrantItemsToCharacterRequest::CatalogVersion)) 
			    ->Property("CharacterId", BehaviorValueProperty(&ServerModels::GrantItemsToCharacterRequest::CharacterId)) 
			    ->Property("PlayFabId", BehaviorValueProperty(&ServerModels::GrantItemsToCharacterRequest::PlayFabId)) 
			    ->Property("Annotation", BehaviorValueProperty(&ServerModels::GrantItemsToCharacterRequest::Annotation)) 
			    ->Property("ItemIds", BehaviorValueProperty(&ServerModels::GrantItemsToCharacterRequest::ItemIds)) 
			;
		
			behaviorContext->Class<ServerModels::GrantItemsToCharacterResult>("PlayFabServer_GrantItemsToCharacterResult")
                ->Constructor() 
			    ->Property("ItemGrantResults", BehaviorValueProperty(&ServerModels::GrantItemsToCharacterResult::ItemGrantResults)) 
			;
		
			behaviorContext->Class<ServerModels::GrantItemsToUserRequest>("PlayFabServer_GrantItemsToUserRequest")
                ->Constructor() 
			    ->Property("CatalogVersion", BehaviorValueProperty(&ServerModels::GrantItemsToUserRequest::CatalogVersion)) 
			    ->Property("PlayFabId", BehaviorValueProperty(&ServerModels::GrantItemsToUserRequest::PlayFabId)) 
			    ->Property("Annotation", BehaviorValueProperty(&ServerModels::GrantItemsToUserRequest::Annotation)) 
			    ->Property("ItemIds", BehaviorValueProperty(&ServerModels::GrantItemsToUserRequest::ItemIds)) 
			;
		
			behaviorContext->Class<ServerModels::GrantItemsToUserResult>("PlayFabServer_GrantItemsToUserResult")
                ->Constructor() 
			    ->Property("ItemGrantResults", BehaviorValueProperty(&ServerModels::GrantItemsToUserResult::ItemGrantResults)) 
			;
		
			behaviorContext->Class<ServerModels::ItemGrant>("PlayFabServer_ItemGrant")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ServerModels::ItemGrant::PlayFabId)) 
			    ->Property("ItemId", BehaviorValueProperty(&ServerModels::ItemGrant::ItemId)) 
			    ->Property("Annotation", BehaviorValueProperty(&ServerModels::ItemGrant::Annotation)) 
			    ->Property("CharacterId", BehaviorValueProperty(&ServerModels::ItemGrant::CharacterId)) 
			    ->Property("KeysToRemove", BehaviorValueProperty(&ServerModels::ItemGrant::KeysToRemove)) 
			;
		
			behaviorContext->Class<ServerModels::GrantItemsToUsersRequest>("PlayFabServer_GrantItemsToUsersRequest")
                ->Constructor() 
			    ->Property("CatalogVersion", BehaviorValueProperty(&ServerModels::GrantItemsToUsersRequest::CatalogVersion)) 
			    ->Property("ItemGrants", BehaviorValueProperty(&ServerModels::GrantItemsToUsersRequest::ItemGrants)) 
			;
		
			behaviorContext->Class<ServerModels::GrantItemsToUsersResult>("PlayFabServer_GrantItemsToUsersResult")
                ->Constructor() 
			    ->Property("ItemGrantResults", BehaviorValueProperty(&ServerModels::GrantItemsToUsersResult::ItemGrantResults)) 
			;
		
			behaviorContext->Class<ServerModels::ListUsersCharactersRequest>("PlayFabServer_ListUsersCharactersRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ServerModels::ListUsersCharactersRequest::PlayFabId)) 
			;
		
			behaviorContext->Class<ServerModels::ListUsersCharactersResult>("PlayFabServer_ListUsersCharactersResult")
                ->Constructor() 
			    ->Property("Characters", BehaviorValueProperty(&ServerModels::ListUsersCharactersResult::Characters)) 
			;
		
			behaviorContext->Class<ServerModels::ModifyCharacterVirtualCurrencyResult>("PlayFabServer_ModifyCharacterVirtualCurrencyResult")
                ->Constructor() 
			    ->Property("VirtualCurrency", BehaviorValueProperty(&ServerModels::ModifyCharacterVirtualCurrencyResult::VirtualCurrency)) 
			    ->Property("Balance", BehaviorValueProperty(&ServerModels::ModifyCharacterVirtualCurrencyResult::Balance)) 
			;
		
			behaviorContext->Class<ServerModels::ModifyItemUsesRequest>("PlayFabServer_ModifyItemUsesRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ServerModels::ModifyItemUsesRequest::PlayFabId)) 
			    ->Property("ItemInstanceId", BehaviorValueProperty(&ServerModels::ModifyItemUsesRequest::ItemInstanceId)) 
			    ->Property("UsesToAdd", BehaviorValueProperty(&ServerModels::ModifyItemUsesRequest::UsesToAdd)) 
			;
		
			behaviorContext->Class<ServerModels::ModifyItemUsesResult>("PlayFabServer_ModifyItemUsesResult")
                ->Constructor() 
			    ->Property("ItemInstanceId", BehaviorValueProperty(&ServerModels::ModifyItemUsesResult::ItemInstanceId)) 
			    ->Property("RemainingUses", BehaviorValueProperty(&ServerModels::ModifyItemUsesResult::RemainingUses)) 
			;
		
			behaviorContext->Class<ServerModels::ModifyUserVirtualCurrencyResult>("PlayFabServer_ModifyUserVirtualCurrencyResult")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ServerModels::ModifyUserVirtualCurrencyResult::PlayFabId)) 
			    ->Property("VirtualCurrency", BehaviorValueProperty(&ServerModels::ModifyUserVirtualCurrencyResult::VirtualCurrency)) 
			    ->Property("BalanceChange", BehaviorValueProperty(&ServerModels::ModifyUserVirtualCurrencyResult::BalanceChange)) 
			    ->Property("Balance", BehaviorValueProperty(&ServerModels::ModifyUserVirtualCurrencyResult::Balance)) 
			;
		
			behaviorContext->Class<ServerModels::MoveItemToCharacterFromCharacterRequest>("PlayFabServer_MoveItemToCharacterFromCharacterRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ServerModels::MoveItemToCharacterFromCharacterRequest::PlayFabId)) 
			    ->Property("GivingCharacterId", BehaviorValueProperty(&ServerModels::MoveItemToCharacterFromCharacterRequest::GivingCharacterId)) 
			    ->Property("ReceivingCharacterId", BehaviorValueProperty(&ServerModels::MoveItemToCharacterFromCharacterRequest::ReceivingCharacterId)) 
			    ->Property("ItemInstanceId", BehaviorValueProperty(&ServerModels::MoveItemToCharacterFromCharacterRequest::ItemInstanceId)) 
			;
		
			behaviorContext->Class<ServerModels::MoveItemToCharacterFromCharacterResult>("PlayFabServer_MoveItemToCharacterFromCharacterResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<ServerModels::MoveItemToCharacterFromUserRequest>("PlayFabServer_MoveItemToCharacterFromUserRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ServerModels::MoveItemToCharacterFromUserRequest::PlayFabId)) 
			    ->Property("CharacterId", BehaviorValueProperty(&ServerModels::MoveItemToCharacterFromUserRequest::CharacterId)) 
			    ->Property("ItemInstanceId", BehaviorValueProperty(&ServerModels::MoveItemToCharacterFromUserRequest::ItemInstanceId)) 
			;
		
			behaviorContext->Class<ServerModels::MoveItemToCharacterFromUserResult>("PlayFabServer_MoveItemToCharacterFromUserResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<ServerModels::MoveItemToUserFromCharacterRequest>("PlayFabServer_MoveItemToUserFromCharacterRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ServerModels::MoveItemToUserFromCharacterRequest::PlayFabId)) 
			    ->Property("CharacterId", BehaviorValueProperty(&ServerModels::MoveItemToUserFromCharacterRequest::CharacterId)) 
			    ->Property("ItemInstanceId", BehaviorValueProperty(&ServerModels::MoveItemToUserFromCharacterRequest::ItemInstanceId)) 
			;
		
			behaviorContext->Class<ServerModels::MoveItemToUserFromCharacterResult>("PlayFabServer_MoveItemToUserFromCharacterResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<ServerModels::NotifyMatchmakerPlayerLeftRequest>("PlayFabServer_NotifyMatchmakerPlayerLeftRequest")
                ->Constructor() 
			    ->Property("LobbyId", BehaviorValueProperty(&ServerModels::NotifyMatchmakerPlayerLeftRequest::LobbyId)) 
			    ->Property("PlayFabId", BehaviorValueProperty(&ServerModels::NotifyMatchmakerPlayerLeftRequest::PlayFabId)) 
			;
		
			behaviorContext->Class<ServerModels::NotifyMatchmakerPlayerLeftResult>("PlayFabServer_NotifyMatchmakerPlayerLeftResult")
                ->Constructor() 
			    ->Property("PlayerState", BehaviorValueProperty(&ServerModels::NotifyMatchmakerPlayerLeftResult::PlayerState)) 
			;
		
			behaviorContext->Class<ServerModels::PushNotificationPackage>("PlayFabServer_PushNotificationPackage")
                ->Constructor() 
			    ->Property("ScheduleDate", BehaviorValueProperty(&ServerModels::PushNotificationPackage::ScheduleDate)) 
			    ->Property("Title", BehaviorValueProperty(&ServerModels::PushNotificationPackage::Title)) 
			    ->Property("Message", BehaviorValueProperty(&ServerModels::PushNotificationPackage::Message)) 
			    ->Property("Icon", BehaviorValueProperty(&ServerModels::PushNotificationPackage::Icon)) 
			    ->Property("Sound", BehaviorValueProperty(&ServerModels::PushNotificationPackage::Sound)) 
			    ->Property("CustomData", BehaviorValueProperty(&ServerModels::PushNotificationPackage::CustomData)) 
			;
		
			behaviorContext->Class<ServerModels::RedeemCouponRequest>("PlayFabServer_RedeemCouponRequest")
                ->Constructor() 
			    ->Property("CouponCode", BehaviorValueProperty(&ServerModels::RedeemCouponRequest::CouponCode)) 
			    ->Property("PlayFabId", BehaviorValueProperty(&ServerModels::RedeemCouponRequest::PlayFabId)) 
			    ->Property("CatalogVersion", BehaviorValueProperty(&ServerModels::RedeemCouponRequest::CatalogVersion)) 
			    ->Property("CharacterId", BehaviorValueProperty(&ServerModels::RedeemCouponRequest::CharacterId)) 
			;
		
			behaviorContext->Class<ServerModels::RedeemCouponResult>("PlayFabServer_RedeemCouponResult")
                ->Constructor() 
			    ->Property("GrantedItems", BehaviorValueProperty(&ServerModels::RedeemCouponResult::GrantedItems)) 
			;
		
			behaviorContext->Class<ServerModels::RedeemMatchmakerTicketRequest>("PlayFabServer_RedeemMatchmakerTicketRequest")
                ->Constructor() 
			    ->Property("Ticket", BehaviorValueProperty(&ServerModels::RedeemMatchmakerTicketRequest::Ticket)) 
			    ->Property("LobbyId", BehaviorValueProperty(&ServerModels::RedeemMatchmakerTicketRequest::LobbyId)) 
			;
		
			behaviorContext->Class<ServerModels::RedeemMatchmakerTicketResult>("PlayFabServer_RedeemMatchmakerTicketResult")
                ->Constructor() 
			    ->Property("TicketIsValid", BehaviorValueProperty(&ServerModels::RedeemMatchmakerTicketResult::TicketIsValid)) 
			    ->Property("Error", BehaviorValueProperty(&ServerModels::RedeemMatchmakerTicketResult::Error)) 
			    ->Property("UserInfo", BehaviorValueProperty(&ServerModels::RedeemMatchmakerTicketResult::UserInfo)) 
			;
		
			behaviorContext->Class<ServerModels::RefreshGameServerInstanceHeartbeatRequest>("PlayFabServer_RefreshGameServerInstanceHeartbeatRequest")
                ->Constructor() 
			    ->Property("LobbyId", BehaviorValueProperty(&ServerModels::RefreshGameServerInstanceHeartbeatRequest::LobbyId)) 
			;
		
			behaviorContext->Class<ServerModels::RefreshGameServerInstanceHeartbeatResult>("PlayFabServer_RefreshGameServerInstanceHeartbeatResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<ServerModels::RegisterGameRequest>("PlayFabServer_RegisterGameRequest")
                ->Constructor() 
			    ->Property("LobbyId", BehaviorValueProperty(&ServerModels::RegisterGameRequest::LobbyId)) 
			    ->Property("ServerHost", BehaviorValueProperty(&ServerModels::RegisterGameRequest::ServerHost)) 
			    ->Property("ServerPort", BehaviorValueProperty(&ServerModels::RegisterGameRequest::ServerPort)) 
			    ->Property("Build", BehaviorValueProperty(&ServerModels::RegisterGameRequest::Build)) 
			    ->Property("pfRegion",
				    [](ServerModels::RegisterGameRequest* p) { return p->pfRegion; },
				    [](ServerModels::RegisterGameRequest* p, ServerModels::Region v) { p->pfRegion = v; })
			    ->Property("GameMode", BehaviorValueProperty(&ServerModels::RegisterGameRequest::GameMode)) 
			;
		
			behaviorContext->Class<ServerModels::RegisterGameResponse>("PlayFabServer_RegisterGameResponse")
                ->Constructor() 
			    ->Property("LobbyId", BehaviorValueProperty(&ServerModels::RegisterGameResponse::LobbyId)) 
			;
		
			behaviorContext->Class<ServerModels::RemoveFriendRequest>("PlayFabServer_RemoveFriendRequest")
                ->Constructor() 
			    ->Property("FriendPlayFabId", BehaviorValueProperty(&ServerModels::RemoveFriendRequest::FriendPlayFabId)) 
			    ->Property("PlayFabId", BehaviorValueProperty(&ServerModels::RemoveFriendRequest::PlayFabId)) 
			;
		
			behaviorContext->Class<ServerModels::RemovePlayerTagRequest>("PlayFabServer_RemovePlayerTagRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ServerModels::RemovePlayerTagRequest::PlayFabId)) 
			    ->Property("TagName", BehaviorValueProperty(&ServerModels::RemovePlayerTagRequest::TagName)) 
			;
		
			behaviorContext->Class<ServerModels::RemovePlayerTagResult>("PlayFabServer_RemovePlayerTagResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<ServerModels::RemoveSharedGroupMembersRequest>("PlayFabServer_RemoveSharedGroupMembersRequest")
                ->Constructor() 
			    ->Property("SharedGroupId", BehaviorValueProperty(&ServerModels::RemoveSharedGroupMembersRequest::SharedGroupId)) 
			    ->Property("PlayFabIds", BehaviorValueProperty(&ServerModels::RemoveSharedGroupMembersRequest::PlayFabIds)) 
			;
		
			behaviorContext->Class<ServerModels::RemoveSharedGroupMembersResult>("PlayFabServer_RemoveSharedGroupMembersResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<ServerModels::ReportPlayerServerRequest>("PlayFabServer_ReportPlayerServerRequest")
                ->Constructor() 
			    ->Property("ReporterId", BehaviorValueProperty(&ServerModels::ReportPlayerServerRequest::ReporterId)) 
			    ->Property("ReporteeId", BehaviorValueProperty(&ServerModels::ReportPlayerServerRequest::ReporteeId)) 
			    ->Property("Comment", BehaviorValueProperty(&ServerModels::ReportPlayerServerRequest::Comment)) 
			;
		
			behaviorContext->Class<ServerModels::ReportPlayerServerResult>("PlayFabServer_ReportPlayerServerResult")
                ->Constructor() 
			    ->Property("Updated", BehaviorValueProperty(&ServerModels::ReportPlayerServerResult::Updated)) 
			    ->Property("SubmissionsRemaining", BehaviorValueProperty(&ServerModels::ReportPlayerServerResult::SubmissionsRemaining)) 
			;
		
			behaviorContext->Class<ServerModels::RevokeAllBansForUserRequest>("PlayFabServer_RevokeAllBansForUserRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ServerModels::RevokeAllBansForUserRequest::PlayFabId)) 
			;
		
			behaviorContext->Class<ServerModels::RevokeAllBansForUserResult>("PlayFabServer_RevokeAllBansForUserResult")
                ->Constructor() 
			    ->Property("BanData", BehaviorValueProperty(&ServerModels::RevokeAllBansForUserResult::BanData)) 
			;
		
			behaviorContext->Class<ServerModels::RevokeBansRequest>("PlayFabServer_RevokeBansRequest")
                ->Constructor() 
			    ->Property("BanIds", BehaviorValueProperty(&ServerModels::RevokeBansRequest::BanIds)) 
			;
		
			behaviorContext->Class<ServerModels::RevokeBansResult>("PlayFabServer_RevokeBansResult")
                ->Constructor() 
			    ->Property("BanData", BehaviorValueProperty(&ServerModels::RevokeBansResult::BanData)) 
			;
		
			behaviorContext->Class<ServerModels::RevokeInventoryItemRequest>("PlayFabServer_RevokeInventoryItemRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ServerModels::RevokeInventoryItemRequest::PlayFabId)) 
			    ->Property("CharacterId", BehaviorValueProperty(&ServerModels::RevokeInventoryItemRequest::CharacterId)) 
			    ->Property("ItemInstanceId", BehaviorValueProperty(&ServerModels::RevokeInventoryItemRequest::ItemInstanceId)) 
			;
		
			behaviorContext->Class<ServerModels::RevokeInventoryResult>("PlayFabServer_RevokeInventoryResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<ServerModels::SendPushNotificationRequest>("PlayFabServer_SendPushNotificationRequest")
                ->Constructor() 
			    ->Property("Recipient", BehaviorValueProperty(&ServerModels::SendPushNotificationRequest::Recipient)) 
			    ->Property("Message", BehaviorValueProperty(&ServerModels::SendPushNotificationRequest::Message)) 
			    ->Property("Package", BehaviorValueProperty(&ServerModels::SendPushNotificationRequest::Package)) 
			    ->Property("Subject", BehaviorValueProperty(&ServerModels::SendPushNotificationRequest::Subject)) 
			;
		
			behaviorContext->Class<ServerModels::SendPushNotificationResult>("PlayFabServer_SendPushNotificationResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<ServerModels::SetFriendTagsRequest>("PlayFabServer_SetFriendTagsRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ServerModels::SetFriendTagsRequest::PlayFabId)) 
			    ->Property("FriendPlayFabId", BehaviorValueProperty(&ServerModels::SetFriendTagsRequest::FriendPlayFabId)) 
			    ->Property("Tags", BehaviorValueProperty(&ServerModels::SetFriendTagsRequest::Tags)) 
			;
		
			behaviorContext->Class<ServerModels::SetGameServerInstanceDataRequest>("PlayFabServer_SetGameServerInstanceDataRequest")
                ->Constructor() 
			    ->Property("LobbyId", BehaviorValueProperty(&ServerModels::SetGameServerInstanceDataRequest::LobbyId)) 
			    ->Property("GameServerData", BehaviorValueProperty(&ServerModels::SetGameServerInstanceDataRequest::GameServerData)) 
			;
		
			behaviorContext->Class<ServerModels::SetGameServerInstanceDataResult>("PlayFabServer_SetGameServerInstanceDataResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<ServerModels::SetGameServerInstanceStateRequest>("PlayFabServer_SetGameServerInstanceStateRequest")
                ->Constructor() 
			    ->Property("LobbyId", BehaviorValueProperty(&ServerModels::SetGameServerInstanceStateRequest::LobbyId)) 
			    ->Property("State",
				    [](ServerModels::SetGameServerInstanceStateRequest* p) { return p->State; },
				    [](ServerModels::SetGameServerInstanceStateRequest* p, ServerModels::GameInstanceState v) { p->State = v; })
			;
		
			behaviorContext->Class<ServerModels::SetGameServerInstanceStateResult>("PlayFabServer_SetGameServerInstanceStateResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<ServerModels::SetGameServerInstanceTagsRequest>("PlayFabServer_SetGameServerInstanceTagsRequest")
                ->Constructor() 
			    ->Property("LobbyId", BehaviorValueProperty(&ServerModels::SetGameServerInstanceTagsRequest::LobbyId)) 
			;
		
			behaviorContext->Class<ServerModels::SetGameServerInstanceTagsResult>("PlayFabServer_SetGameServerInstanceTagsResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<ServerModels::SetPlayerSecretRequest>("PlayFabServer_SetPlayerSecretRequest")
                ->Constructor() 
			    ->Property("PlayerSecret", BehaviorValueProperty(&ServerModels::SetPlayerSecretRequest::PlayerSecret)) 
			    ->Property("PlayFabId", BehaviorValueProperty(&ServerModels::SetPlayerSecretRequest::PlayFabId)) 
			;
		
			behaviorContext->Class<ServerModels::SetPlayerSecretResult>("PlayFabServer_SetPlayerSecretResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<ServerModels::SetPublisherDataRequest>("PlayFabServer_SetPublisherDataRequest")
                ->Constructor() 
			    ->Property("Key", BehaviorValueProperty(&ServerModels::SetPublisherDataRequest::Key)) 
			    ->Property("Value", BehaviorValueProperty(&ServerModels::SetPublisherDataRequest::Value)) 
			;
		
			behaviorContext->Class<ServerModels::SetPublisherDataResult>("PlayFabServer_SetPublisherDataResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<ServerModels::SetTitleDataRequest>("PlayFabServer_SetTitleDataRequest")
                ->Constructor() 
			    ->Property("Key", BehaviorValueProperty(&ServerModels::SetTitleDataRequest::Key)) 
			    ->Property("Value", BehaviorValueProperty(&ServerModels::SetTitleDataRequest::Value)) 
			;
		
			behaviorContext->Class<ServerModels::SetTitleDataResult>("PlayFabServer_SetTitleDataResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<ServerModels::StatisticUpdate>("PlayFabServer_StatisticUpdate")
                ->Constructor() 
			    ->Property("StatisticName", BehaviorValueProperty(&ServerModels::StatisticUpdate::StatisticName)) 
			    ->Property("Version", BehaviorValueProperty(&ServerModels::StatisticUpdate::Version)) 
			    ->Property("Value", BehaviorValueProperty(&ServerModels::StatisticUpdate::Value)) 
			;
		
			behaviorContext->Class<ServerModels::SubtractCharacterVirtualCurrencyRequest>("PlayFabServer_SubtractCharacterVirtualCurrencyRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ServerModels::SubtractCharacterVirtualCurrencyRequest::PlayFabId)) 
			    ->Property("CharacterId", BehaviorValueProperty(&ServerModels::SubtractCharacterVirtualCurrencyRequest::CharacterId)) 
			    ->Property("VirtualCurrency", BehaviorValueProperty(&ServerModels::SubtractCharacterVirtualCurrencyRequest::VirtualCurrency)) 
			    ->Property("Amount", BehaviorValueProperty(&ServerModels::SubtractCharacterVirtualCurrencyRequest::Amount)) 
			;
		
			behaviorContext->Class<ServerModels::SubtractUserVirtualCurrencyRequest>("PlayFabServer_SubtractUserVirtualCurrencyRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ServerModels::SubtractUserVirtualCurrencyRequest::PlayFabId)) 
			    ->Property("VirtualCurrency", BehaviorValueProperty(&ServerModels::SubtractUserVirtualCurrencyRequest::VirtualCurrency)) 
			    ->Property("Amount", BehaviorValueProperty(&ServerModels::SubtractUserVirtualCurrencyRequest::Amount)) 
			;
		
			behaviorContext->Class<ServerModels::UnlockContainerInstanceRequest>("PlayFabServer_UnlockContainerInstanceRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ServerModels::UnlockContainerInstanceRequest::PlayFabId)) 
			    ->Property("CharacterId", BehaviorValueProperty(&ServerModels::UnlockContainerInstanceRequest::CharacterId)) 
			    ->Property("ContainerItemInstanceId", BehaviorValueProperty(&ServerModels::UnlockContainerInstanceRequest::ContainerItemInstanceId)) 
			    ->Property("KeyItemInstanceId", BehaviorValueProperty(&ServerModels::UnlockContainerInstanceRequest::KeyItemInstanceId)) 
			    ->Property("CatalogVersion", BehaviorValueProperty(&ServerModels::UnlockContainerInstanceRequest::CatalogVersion)) 
			;
		
			behaviorContext->Class<ServerModels::UnlockContainerItemRequest>("PlayFabServer_UnlockContainerItemRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ServerModels::UnlockContainerItemRequest::PlayFabId)) 
			    ->Property("CharacterId", BehaviorValueProperty(&ServerModels::UnlockContainerItemRequest::CharacterId)) 
			    ->Property("ContainerItemId", BehaviorValueProperty(&ServerModels::UnlockContainerItemRequest::ContainerItemId)) 
			    ->Property("CatalogVersion", BehaviorValueProperty(&ServerModels::UnlockContainerItemRequest::CatalogVersion)) 
			;
		
			behaviorContext->Class<ServerModels::UnlockContainerItemResult>("PlayFabServer_UnlockContainerItemResult")
                ->Constructor() 
			    ->Property("UnlockedItemInstanceId", BehaviorValueProperty(&ServerModels::UnlockContainerItemResult::UnlockedItemInstanceId)) 
			    ->Property("UnlockedWithItemInstanceId", BehaviorValueProperty(&ServerModels::UnlockContainerItemResult::UnlockedWithItemInstanceId)) 
			    ->Property("GrantedItems", BehaviorValueProperty(&ServerModels::UnlockContainerItemResult::GrantedItems)) 
			;
		
			behaviorContext->Class<ServerModels::UpdateAvatarUrlRequest>("PlayFabServer_UpdateAvatarUrlRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ServerModels::UpdateAvatarUrlRequest::PlayFabId)) 
			    ->Property("ImageUrl", BehaviorValueProperty(&ServerModels::UpdateAvatarUrlRequest::ImageUrl)) 
			;
		
			behaviorContext->Class<ServerModels::UpdateBanRequest>("PlayFabServer_UpdateBanRequest")
                ->Constructor() 
			    ->Property("BanId", BehaviorValueProperty(&ServerModels::UpdateBanRequest::BanId)) 
			    ->Property("Reason", BehaviorValueProperty(&ServerModels::UpdateBanRequest::Reason)) 
			    ->Property("Expires", BehaviorValueProperty(&ServerModels::UpdateBanRequest::Expires)) 
			    ->Property("IPAddress", BehaviorValueProperty(&ServerModels::UpdateBanRequest::IPAddress)) 
			    ->Property("MACAddress", BehaviorValueProperty(&ServerModels::UpdateBanRequest::MACAddress)) 
			    ->Property("Permanent", BehaviorValueProperty(&ServerModels::UpdateBanRequest::Permanent)) 
			    ->Property("Active", BehaviorValueProperty(&ServerModels::UpdateBanRequest::Active)) 
			;
		
			behaviorContext->Class<ServerModels::UpdateBansRequest>("PlayFabServer_UpdateBansRequest")
                ->Constructor() 
			    ->Property("Bans", BehaviorValueProperty(&ServerModels::UpdateBansRequest::Bans)) 
			;
		
			behaviorContext->Class<ServerModels::UpdateBansResult>("PlayFabServer_UpdateBansResult")
                ->Constructor() 
			    ->Property("BanData", BehaviorValueProperty(&ServerModels::UpdateBansResult::BanData)) 
			;
		
			behaviorContext->Class<ServerModels::UpdateCharacterDataRequest>("PlayFabServer_UpdateCharacterDataRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ServerModels::UpdateCharacterDataRequest::PlayFabId)) 
			    ->Property("CharacterId", BehaviorValueProperty(&ServerModels::UpdateCharacterDataRequest::CharacterId)) 
			    ->Property("KeysToRemove", BehaviorValueProperty(&ServerModels::UpdateCharacterDataRequest::KeysToRemove)) 
			    ->Property("Permission", BehaviorValueProperty(&ServerModels::UpdateCharacterDataRequest::Permission)) 
			;
		
			behaviorContext->Class<ServerModels::UpdateCharacterDataResult>("PlayFabServer_UpdateCharacterDataResult")
                ->Constructor() 
			    ->Property("DataVersion", BehaviorValueProperty(&ServerModels::UpdateCharacterDataResult::DataVersion)) 
			;
		
			behaviorContext->Class<ServerModels::UpdateCharacterStatisticsRequest>("PlayFabServer_UpdateCharacterStatisticsRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ServerModels::UpdateCharacterStatisticsRequest::PlayFabId)) 
			    ->Property("CharacterId", BehaviorValueProperty(&ServerModels::UpdateCharacterStatisticsRequest::CharacterId)) 
			;
		
			behaviorContext->Class<ServerModels::UpdateCharacterStatisticsResult>("PlayFabServer_UpdateCharacterStatisticsResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<ServerModels::UpdatePlayerStatisticsRequest>("PlayFabServer_UpdatePlayerStatisticsRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ServerModels::UpdatePlayerStatisticsRequest::PlayFabId)) 
			    ->Property("Statistics", BehaviorValueProperty(&ServerModels::UpdatePlayerStatisticsRequest::Statistics)) 
			    ->Property("ForceUpdate", BehaviorValueProperty(&ServerModels::UpdatePlayerStatisticsRequest::ForceUpdate)) 
			;
		
			behaviorContext->Class<ServerModels::UpdatePlayerStatisticsResult>("PlayFabServer_UpdatePlayerStatisticsResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<ServerModels::UpdateSharedGroupDataRequest>("PlayFabServer_UpdateSharedGroupDataRequest")
                ->Constructor() 
			    ->Property("SharedGroupId", BehaviorValueProperty(&ServerModels::UpdateSharedGroupDataRequest::SharedGroupId)) 
			    ->Property("KeysToRemove", BehaviorValueProperty(&ServerModels::UpdateSharedGroupDataRequest::KeysToRemove)) 
			    ->Property("Permission", BehaviorValueProperty(&ServerModels::UpdateSharedGroupDataRequest::Permission)) 
			;
		
			behaviorContext->Class<ServerModels::UpdateSharedGroupDataResult>("PlayFabServer_UpdateSharedGroupDataResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<ServerModels::UpdateUserDataRequest>("PlayFabServer_UpdateUserDataRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ServerModels::UpdateUserDataRequest::PlayFabId)) 
			    ->Property("KeysToRemove", BehaviorValueProperty(&ServerModels::UpdateUserDataRequest::KeysToRemove)) 
			    ->Property("Permission", BehaviorValueProperty(&ServerModels::UpdateUserDataRequest::Permission)) 
			;
		
			behaviorContext->Class<ServerModels::UpdateUserDataResult>("PlayFabServer_UpdateUserDataResult")
                ->Constructor() 
			    ->Property("DataVersion", BehaviorValueProperty(&ServerModels::UpdateUserDataResult::DataVersion)) 
			;
		
			behaviorContext->Class<ServerModels::UpdateUserInternalDataRequest>("PlayFabServer_UpdateUserInternalDataRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ServerModels::UpdateUserInternalDataRequest::PlayFabId)) 
			    ->Property("KeysToRemove", BehaviorValueProperty(&ServerModels::UpdateUserInternalDataRequest::KeysToRemove)) 
			;
		
			behaviorContext->Class<ServerModels::UpdateUserInventoryItemDataRequest>("PlayFabServer_UpdateUserInventoryItemDataRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ServerModels::UpdateUserInventoryItemDataRequest::PlayFabId)) 
			    ->Property("CharacterId", BehaviorValueProperty(&ServerModels::UpdateUserInventoryItemDataRequest::CharacterId)) 
			    ->Property("ItemInstanceId", BehaviorValueProperty(&ServerModels::UpdateUserInventoryItemDataRequest::ItemInstanceId)) 
			    ->Property("KeysToRemove", BehaviorValueProperty(&ServerModels::UpdateUserInventoryItemDataRequest::KeysToRemove)) 
			;
		
			behaviorContext->Class<ServerModels::WriteEventResponse>("PlayFabServer_WriteEventResponse")
                ->Constructor() 
			    ->Property("EventId", BehaviorValueProperty(&ServerModels::WriteEventResponse::EventId)) 
			;
		
			behaviorContext->Class<ServerModels::WriteServerCharacterEventRequest>("PlayFabServer_WriteServerCharacterEventRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ServerModels::WriteServerCharacterEventRequest::PlayFabId)) 
			    ->Property("CharacterId", BehaviorValueProperty(&ServerModels::WriteServerCharacterEventRequest::CharacterId)) 
			    ->Property("EventName", BehaviorValueProperty(&ServerModels::WriteServerCharacterEventRequest::EventName)) 
			    ->Property("Timestamp", BehaviorValueProperty(&ServerModels::WriteServerCharacterEventRequest::Timestamp)) 
			;
		
			behaviorContext->Class<ServerModels::WriteServerPlayerEventRequest>("PlayFabServer_WriteServerPlayerEventRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ServerModels::WriteServerPlayerEventRequest::PlayFabId)) 
			    ->Property("EventName", BehaviorValueProperty(&ServerModels::WriteServerPlayerEventRequest::EventName)) 
			    ->Property("Timestamp", BehaviorValueProperty(&ServerModels::WriteServerPlayerEventRequest::Timestamp)) 
			;
		
			behaviorContext->Class<ServerModels::WriteTitleEventRequest>("PlayFabServer_WriteTitleEventRequest")
                ->Constructor() 
			    ->Property("EventName", BehaviorValueProperty(&ServerModels::WriteTitleEventRequest::EventName)) 
			    ->Property("Timestamp", BehaviorValueProperty(&ServerModels::WriteTitleEventRequest::Timestamp)) 
			;
		 
				
		} // if (behaviorContext) {...
	} // End of BehaviorContext::Reflect()

}