// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

#include "StdAfx.h"
#include "PlayFabCombo_ClientBehaviorContext.h"
#include <AzCore/RTTI/ReflectContext.h>
#include <AzCore/RTTI/BehaviorContext.h>

#include "PlayFabComboSdk/PlayFabCombo_ClientNotificationBus.h"
#include "PlayFabComboSdk/PlayFabCombo_ClientBus.h"
#include "PlayFabComboSdk/PlayFabComboDataModels.h"

#include "PlayFabCombo_OnDemandReflection.inl"

namespace PlayFabComboSdk
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
    class PlayFabCombo_ClientBehaviorBusBaseHandler : 
		public AZ::BehaviorEBusHandler
	{ 

    // Note that normally we would list all of the notification handler functions here using the AZ_EBUS_BEHAVIOR_BINDER macro
    // However the AZ_EBUS_BEHAVIOR_BINDER macro supports a maximum of 30 functions, so we generate the calls by hand here instead.
            
    public: 
        AZ_CLASS_ALLOCATOR(T,AZ::SystemAllocator,0)
    protected:

		enum {
			FN_OnError,
			FN_OnGetPhotonAuthenticationToken,
			FN_OnGetTitlePublicKey,
			FN_OnGetWindowsHelloChallenge,
			FN_OnLoginWithAndroidDeviceID,
			FN_OnLoginWithCustomID,
			FN_OnLoginWithEmailAddress,
			FN_OnLoginWithFacebook,
			FN_OnLoginWithGameCenter,
			FN_OnLoginWithGoogleAccount,
			FN_OnLoginWithIOSDeviceID,
			FN_OnLoginWithKongregate,
			FN_OnLoginWithPlayFab,
			FN_OnLoginWithSteam,
			FN_OnLoginWithTwitch,
			FN_OnLoginWithWindowsHello,
			FN_OnRegisterPlayFabUser,
			FN_OnRegisterWithWindowsHello,
			FN_OnSetPlayerSecret,
			FN_OnAddGenericID,
			FN_OnAddUsernamePassword,
			FN_OnGetAccountInfo,
			FN_OnGetPlayerCombinedInfo,
			FN_OnGetPlayerProfile,
			FN_OnGetPlayFabIDsFromFacebookIDs,
			FN_OnGetPlayFabIDsFromGameCenterIDs,
			FN_OnGetPlayFabIDsFromGenericIDs,
			FN_OnGetPlayFabIDsFromGoogleIDs,
			FN_OnGetPlayFabIDsFromKongregateIDs,
			FN_OnGetPlayFabIDsFromSteamIDs,
			FN_OnGetPlayFabIDsFromTwitchIDs,
			FN_OnLinkAndroidDeviceID,
			FN_OnLinkCustomID,
			FN_OnLinkFacebookAccount,
			FN_OnLinkGameCenterAccount,
			FN_OnLinkGoogleAccount,
			FN_OnLinkIOSDeviceID,
			FN_OnLinkKongregate,
			FN_OnLinkSteamAccount,
			FN_OnLinkTwitch,
			FN_OnLinkWindowsHello,
			FN_OnRemoveGenericID,
			FN_OnReportPlayer,
			FN_OnSendAccountRecoveryEmail,
			FN_OnUnlinkAndroidDeviceID,
			FN_OnUnlinkCustomID,
			FN_OnUnlinkFacebookAccount,
			FN_OnUnlinkGameCenterAccount,
			FN_OnUnlinkGoogleAccount,
			FN_OnUnlinkIOSDeviceID,
			FN_OnUnlinkKongregate,
			FN_OnUnlinkSteamAccount,
			FN_OnUnlinkTwitch,
			FN_OnUnlinkWindowsHello,
			FN_OnUpdateAvatarUrl,
			FN_OnUpdateUserTitleDisplayName,
			FN_OnGetFriendLeaderboard,
			FN_OnGetFriendLeaderboardAroundPlayer,
			FN_OnGetLeaderboard,
			FN_OnGetLeaderboardAroundPlayer,
			FN_OnGetPlayerStatistics,
			FN_OnGetPlayerStatisticVersions,
			FN_OnGetUserData,
			FN_OnGetUserPublisherData,
			FN_OnGetUserPublisherReadOnlyData,
			FN_OnGetUserReadOnlyData,
			FN_OnUpdatePlayerStatistics,
			FN_OnUpdateUserData,
			FN_OnUpdateUserPublisherData,
			FN_OnGetCatalogItems,
			FN_OnGetPublisherData,
			FN_OnGetStoreItems,
			FN_OnGetTime,
			FN_OnGetTitleData,
			FN_OnGetTitleNews,
			FN_OnAddUserVirtualCurrency,
			FN_OnConfirmPurchase,
			FN_OnConsumeItem,
			FN_OnGetCharacterInventory,
			FN_OnGetPurchase,
			FN_OnGetUserInventory,
			FN_OnPayForPurchase,
			FN_OnPurchaseItem,
			FN_OnRedeemCoupon,
			FN_OnStartPurchase,
			FN_OnSubtractUserVirtualCurrency,
			FN_OnUnlockContainerInstance,
			FN_OnUnlockContainerItem,
			FN_OnAddFriend,
			FN_OnGetFriendsList,
			FN_OnRemoveFriend,
			FN_OnSetFriendTags,
			FN_OnGetCurrentGames,
			FN_OnGetGameServerRegions,
			FN_OnMatchmake,
			FN_OnStartGame,
			FN_OnWriteCharacterEvent,
			FN_OnWritePlayerEvent,
			FN_OnWriteTitleEvent,
			FN_OnAddSharedGroupMembers,
			FN_OnCreateSharedGroup,
			FN_OnGetSharedGroupData,
			FN_OnRemoveSharedGroupMembers,
			FN_OnUpdateSharedGroupData,
			FN_OnExecuteCloudScript,
			FN_OnGetContentDownloadUrl,
			FN_OnGetAllUsersCharacters,
			FN_OnGetCharacterLeaderboard,
			FN_OnGetCharacterStatistics,
			FN_OnGetLeaderboardAroundCharacter,
			FN_OnGetLeaderboardForUserCharacters,
			FN_OnGrantCharacterToUser,
			FN_OnUpdateCharacterStatistics,
			FN_OnGetCharacterData,
			FN_OnGetCharacterReadOnlyData,
			FN_OnUpdateCharacterData,
			FN_OnAcceptTrade,
			FN_OnCancelTrade,
			FN_OnGetPlayerTrades,
			FN_OnGetTradeStatus,
			FN_OnOpenTrade,
			FN_OnAttributeInstall,
			FN_OnGetPlayerSegments,
			FN_OnGetPlayerTags,
			FN_OnAndroidDevicePushNotificationRegistration,
			FN_OnRegisterForIOSPushNotification,
			FN_OnRestoreIOSPurchases,
			FN_OnValidateAmazonIAPReceipt,
			FN_OnValidateGooglePlayPurchase,
			FN_OnValidateIOSReceipt,
			FN_OnValidateWindowsStoreReceipt,
			
        	FN_MAX
    	};

        int GetFunctionIndex(const char* functionName) const override {
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnError)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetPhotonAuthenticationToken)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetTitlePublicKey)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetWindowsHelloChallenge)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnLoginWithAndroidDeviceID)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnLoginWithCustomID)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnLoginWithEmailAddress)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnLoginWithFacebook)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnLoginWithGameCenter)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnLoginWithGoogleAccount)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnLoginWithIOSDeviceID)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnLoginWithKongregate)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnLoginWithPlayFab)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnLoginWithSteam)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnLoginWithTwitch)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnLoginWithWindowsHello)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnRegisterPlayFabUser)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnRegisterWithWindowsHello)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnSetPlayerSecret)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnAddGenericID)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnAddUsernamePassword)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetAccountInfo)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetPlayerCombinedInfo)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetPlayerProfile)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetPlayFabIDsFromFacebookIDs)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetPlayFabIDsFromGameCenterIDs)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetPlayFabIDsFromGenericIDs)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetPlayFabIDsFromGoogleIDs)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetPlayFabIDsFromKongregateIDs)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetPlayFabIDsFromSteamIDs)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetPlayFabIDsFromTwitchIDs)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnLinkAndroidDeviceID)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnLinkCustomID)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnLinkFacebookAccount)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnLinkGameCenterAccount)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnLinkGoogleAccount)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnLinkIOSDeviceID)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnLinkKongregate)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnLinkSteamAccount)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnLinkTwitch)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnLinkWindowsHello)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnRemoveGenericID)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnReportPlayer)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnSendAccountRecoveryEmail)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnUnlinkAndroidDeviceID)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnUnlinkCustomID)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnUnlinkFacebookAccount)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnUnlinkGameCenterAccount)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnUnlinkGoogleAccount)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnUnlinkIOSDeviceID)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnUnlinkKongregate)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnUnlinkSteamAccount)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnUnlinkTwitch)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnUnlinkWindowsHello)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnUpdateAvatarUrl)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnUpdateUserTitleDisplayName)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetFriendLeaderboard)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetFriendLeaderboardAroundPlayer)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetLeaderboard)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetLeaderboardAroundPlayer)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetPlayerStatistics)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetPlayerStatisticVersions)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetUserData)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetUserPublisherData)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetUserPublisherReadOnlyData)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetUserReadOnlyData)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnUpdatePlayerStatistics)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnUpdateUserData)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnUpdateUserPublisherData)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetCatalogItems)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetPublisherData)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetStoreItems)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetTime)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetTitleData)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetTitleNews)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnAddUserVirtualCurrency)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnConfirmPurchase)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnConsumeItem)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetCharacterInventory)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetPurchase)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetUserInventory)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnPayForPurchase)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnPurchaseItem)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnRedeemCoupon)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnStartPurchase)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnSubtractUserVirtualCurrency)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnUnlockContainerInstance)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnUnlockContainerItem)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnAddFriend)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetFriendsList)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnRemoveFriend)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnSetFriendTags)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetCurrentGames)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetGameServerRegions)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnMatchmake)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnStartGame)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnWriteCharacterEvent)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnWritePlayerEvent)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnWriteTitleEvent)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnAddSharedGroupMembers)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnCreateSharedGroup)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetSharedGroupData)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnRemoveSharedGroupMembers)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnUpdateSharedGroupData)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnExecuteCloudScript)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetContentDownloadUrl)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetAllUsersCharacters)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetCharacterLeaderboard)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetCharacterStatistics)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetLeaderboardAroundCharacter)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetLeaderboardForUserCharacters)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGrantCharacterToUser)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnUpdateCharacterStatistics)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetCharacterData)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetCharacterReadOnlyData)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnUpdateCharacterData)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnAcceptTrade)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnCancelTrade)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetPlayerTrades)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetTradeStatus)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnOpenTrade)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnAttributeInstall)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetPlayerSegments)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnGetPlayerTags)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnAndroidDevicePushNotificationRegistration)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnRegisterForIOSPushNotification)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnRestoreIOSPurchases)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnValidateAmazonIAPReceipt)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnValidateGooglePlayPurchase)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnValidateIOSReceipt)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnValidateWindowsStoreReceipt)
			
			return -1;
		}

        bool Connect(AZ::BehaviorValueParameter* id = nullptr) override {
			return AZ::Internal::EBusConnector<T>::Connect(static_cast<T*>(this), id);
		}

        // Constructor
        PlayFabCombo_ClientBehaviorBusBaseHandler()
        {
        	m_events.resize(FN_MAX);
			SetEvent(&T::OnError,"OnError");
			SetEvent(&T::OnGetPhotonAuthenticationToken,"OnGetPhotonAuthenticationToken");
			SetEvent(&T::OnGetTitlePublicKey,"OnGetTitlePublicKey");
			SetEvent(&T::OnGetWindowsHelloChallenge,"OnGetWindowsHelloChallenge");
			SetEvent(&T::OnLoginWithAndroidDeviceID,"OnLoginWithAndroidDeviceID");
			SetEvent(&T::OnLoginWithCustomID,"OnLoginWithCustomID");
			SetEvent(&T::OnLoginWithEmailAddress,"OnLoginWithEmailAddress");
			SetEvent(&T::OnLoginWithFacebook,"OnLoginWithFacebook");
			SetEvent(&T::OnLoginWithGameCenter,"OnLoginWithGameCenter");
			SetEvent(&T::OnLoginWithGoogleAccount,"OnLoginWithGoogleAccount");
			SetEvent(&T::OnLoginWithIOSDeviceID,"OnLoginWithIOSDeviceID");
			SetEvent(&T::OnLoginWithKongregate,"OnLoginWithKongregate");
			SetEvent(&T::OnLoginWithPlayFab,"OnLoginWithPlayFab");
			SetEvent(&T::OnLoginWithSteam,"OnLoginWithSteam");
			SetEvent(&T::OnLoginWithTwitch,"OnLoginWithTwitch");
			SetEvent(&T::OnLoginWithWindowsHello,"OnLoginWithWindowsHello");
			SetEvent(&T::OnRegisterPlayFabUser,"OnRegisterPlayFabUser");
			SetEvent(&T::OnRegisterWithWindowsHello,"OnRegisterWithWindowsHello");
			SetEvent(&T::OnSetPlayerSecret,"OnSetPlayerSecret");
			SetEvent(&T::OnAddGenericID,"OnAddGenericID");
			SetEvent(&T::OnAddUsernamePassword,"OnAddUsernamePassword");
			SetEvent(&T::OnGetAccountInfo,"OnGetAccountInfo");
			SetEvent(&T::OnGetPlayerCombinedInfo,"OnGetPlayerCombinedInfo");
			SetEvent(&T::OnGetPlayerProfile,"OnGetPlayerProfile");
			SetEvent(&T::OnGetPlayFabIDsFromFacebookIDs,"OnGetPlayFabIDsFromFacebookIDs");
			SetEvent(&T::OnGetPlayFabIDsFromGameCenterIDs,"OnGetPlayFabIDsFromGameCenterIDs");
			SetEvent(&T::OnGetPlayFabIDsFromGenericIDs,"OnGetPlayFabIDsFromGenericIDs");
			SetEvent(&T::OnGetPlayFabIDsFromGoogleIDs,"OnGetPlayFabIDsFromGoogleIDs");
			SetEvent(&T::OnGetPlayFabIDsFromKongregateIDs,"OnGetPlayFabIDsFromKongregateIDs");
			SetEvent(&T::OnGetPlayFabIDsFromSteamIDs,"OnGetPlayFabIDsFromSteamIDs");
			SetEvent(&T::OnGetPlayFabIDsFromTwitchIDs,"OnGetPlayFabIDsFromTwitchIDs");
			SetEvent(&T::OnLinkAndroidDeviceID,"OnLinkAndroidDeviceID");
			SetEvent(&T::OnLinkCustomID,"OnLinkCustomID");
			SetEvent(&T::OnLinkFacebookAccount,"OnLinkFacebookAccount");
			SetEvent(&T::OnLinkGameCenterAccount,"OnLinkGameCenterAccount");
			SetEvent(&T::OnLinkGoogleAccount,"OnLinkGoogleAccount");
			SetEvent(&T::OnLinkIOSDeviceID,"OnLinkIOSDeviceID");
			SetEvent(&T::OnLinkKongregate,"OnLinkKongregate");
			SetEvent(&T::OnLinkSteamAccount,"OnLinkSteamAccount");
			SetEvent(&T::OnLinkTwitch,"OnLinkTwitch");
			SetEvent(&T::OnLinkWindowsHello,"OnLinkWindowsHello");
			SetEvent(&T::OnRemoveGenericID,"OnRemoveGenericID");
			SetEvent(&T::OnReportPlayer,"OnReportPlayer");
			SetEvent(&T::OnSendAccountRecoveryEmail,"OnSendAccountRecoveryEmail");
			SetEvent(&T::OnUnlinkAndroidDeviceID,"OnUnlinkAndroidDeviceID");
			SetEvent(&T::OnUnlinkCustomID,"OnUnlinkCustomID");
			SetEvent(&T::OnUnlinkFacebookAccount,"OnUnlinkFacebookAccount");
			SetEvent(&T::OnUnlinkGameCenterAccount,"OnUnlinkGameCenterAccount");
			SetEvent(&T::OnUnlinkGoogleAccount,"OnUnlinkGoogleAccount");
			SetEvent(&T::OnUnlinkIOSDeviceID,"OnUnlinkIOSDeviceID");
			SetEvent(&T::OnUnlinkKongregate,"OnUnlinkKongregate");
			SetEvent(&T::OnUnlinkSteamAccount,"OnUnlinkSteamAccount");
			SetEvent(&T::OnUnlinkTwitch,"OnUnlinkTwitch");
			SetEvent(&T::OnUnlinkWindowsHello,"OnUnlinkWindowsHello");
			SetEvent(&T::OnUpdateAvatarUrl,"OnUpdateAvatarUrl");
			SetEvent(&T::OnUpdateUserTitleDisplayName,"OnUpdateUserTitleDisplayName");
			SetEvent(&T::OnGetFriendLeaderboard,"OnGetFriendLeaderboard");
			SetEvent(&T::OnGetFriendLeaderboardAroundPlayer,"OnGetFriendLeaderboardAroundPlayer");
			SetEvent(&T::OnGetLeaderboard,"OnGetLeaderboard");
			SetEvent(&T::OnGetLeaderboardAroundPlayer,"OnGetLeaderboardAroundPlayer");
			SetEvent(&T::OnGetPlayerStatistics,"OnGetPlayerStatistics");
			SetEvent(&T::OnGetPlayerStatisticVersions,"OnGetPlayerStatisticVersions");
			SetEvent(&T::OnGetUserData,"OnGetUserData");
			SetEvent(&T::OnGetUserPublisherData,"OnGetUserPublisherData");
			SetEvent(&T::OnGetUserPublisherReadOnlyData,"OnGetUserPublisherReadOnlyData");
			SetEvent(&T::OnGetUserReadOnlyData,"OnGetUserReadOnlyData");
			SetEvent(&T::OnUpdatePlayerStatistics,"OnUpdatePlayerStatistics");
			SetEvent(&T::OnUpdateUserData,"OnUpdateUserData");
			SetEvent(&T::OnUpdateUserPublisherData,"OnUpdateUserPublisherData");
			SetEvent(&T::OnGetCatalogItems,"OnGetCatalogItems");
			SetEvent(&T::OnGetPublisherData,"OnGetPublisherData");
			SetEvent(&T::OnGetStoreItems,"OnGetStoreItems");
			SetEvent(&T::OnGetTime,"OnGetTime");
			SetEvent(&T::OnGetTitleData,"OnGetTitleData");
			SetEvent(&T::OnGetTitleNews,"OnGetTitleNews");
			SetEvent(&T::OnAddUserVirtualCurrency,"OnAddUserVirtualCurrency");
			SetEvent(&T::OnConfirmPurchase,"OnConfirmPurchase");
			SetEvent(&T::OnConsumeItem,"OnConsumeItem");
			SetEvent(&T::OnGetCharacterInventory,"OnGetCharacterInventory");
			SetEvent(&T::OnGetPurchase,"OnGetPurchase");
			SetEvent(&T::OnGetUserInventory,"OnGetUserInventory");
			SetEvent(&T::OnPayForPurchase,"OnPayForPurchase");
			SetEvent(&T::OnPurchaseItem,"OnPurchaseItem");
			SetEvent(&T::OnRedeemCoupon,"OnRedeemCoupon");
			SetEvent(&T::OnStartPurchase,"OnStartPurchase");
			SetEvent(&T::OnSubtractUserVirtualCurrency,"OnSubtractUserVirtualCurrency");
			SetEvent(&T::OnUnlockContainerInstance,"OnUnlockContainerInstance");
			SetEvent(&T::OnUnlockContainerItem,"OnUnlockContainerItem");
			SetEvent(&T::OnAddFriend,"OnAddFriend");
			SetEvent(&T::OnGetFriendsList,"OnGetFriendsList");
			SetEvent(&T::OnRemoveFriend,"OnRemoveFriend");
			SetEvent(&T::OnSetFriendTags,"OnSetFriendTags");
			SetEvent(&T::OnGetCurrentGames,"OnGetCurrentGames");
			SetEvent(&T::OnGetGameServerRegions,"OnGetGameServerRegions");
			SetEvent(&T::OnMatchmake,"OnMatchmake");
			SetEvent(&T::OnStartGame,"OnStartGame");
			SetEvent(&T::OnWriteCharacterEvent,"OnWriteCharacterEvent");
			SetEvent(&T::OnWritePlayerEvent,"OnWritePlayerEvent");
			SetEvent(&T::OnWriteTitleEvent,"OnWriteTitleEvent");
			SetEvent(&T::OnAddSharedGroupMembers,"OnAddSharedGroupMembers");
			SetEvent(&T::OnCreateSharedGroup,"OnCreateSharedGroup");
			SetEvent(&T::OnGetSharedGroupData,"OnGetSharedGroupData");
			SetEvent(&T::OnRemoveSharedGroupMembers,"OnRemoveSharedGroupMembers");
			SetEvent(&T::OnUpdateSharedGroupData,"OnUpdateSharedGroupData");
			SetEvent(&T::OnExecuteCloudScript,"OnExecuteCloudScript");
			SetEvent(&T::OnGetContentDownloadUrl,"OnGetContentDownloadUrl");
			SetEvent(&T::OnGetAllUsersCharacters,"OnGetAllUsersCharacters");
			SetEvent(&T::OnGetCharacterLeaderboard,"OnGetCharacterLeaderboard");
			SetEvent(&T::OnGetCharacterStatistics,"OnGetCharacterStatistics");
			SetEvent(&T::OnGetLeaderboardAroundCharacter,"OnGetLeaderboardAroundCharacter");
			SetEvent(&T::OnGetLeaderboardForUserCharacters,"OnGetLeaderboardForUserCharacters");
			SetEvent(&T::OnGrantCharacterToUser,"OnGrantCharacterToUser");
			SetEvent(&T::OnUpdateCharacterStatistics,"OnUpdateCharacterStatistics");
			SetEvent(&T::OnGetCharacterData,"OnGetCharacterData");
			SetEvent(&T::OnGetCharacterReadOnlyData,"OnGetCharacterReadOnlyData");
			SetEvent(&T::OnUpdateCharacterData,"OnUpdateCharacterData");
			SetEvent(&T::OnAcceptTrade,"OnAcceptTrade");
			SetEvent(&T::OnCancelTrade,"OnCancelTrade");
			SetEvent(&T::OnGetPlayerTrades,"OnGetPlayerTrades");
			SetEvent(&T::OnGetTradeStatus,"OnGetTradeStatus");
			SetEvent(&T::OnOpenTrade,"OnOpenTrade");
			SetEvent(&T::OnAttributeInstall,"OnAttributeInstall");
			SetEvent(&T::OnGetPlayerSegments,"OnGetPlayerSegments");
			SetEvent(&T::OnGetPlayerTags,"OnGetPlayerTags");
			SetEvent(&T::OnAndroidDevicePushNotificationRegistration,"OnAndroidDevicePushNotificationRegistration");
			SetEvent(&T::OnRegisterForIOSPushNotification,"OnRegisterForIOSPushNotification");
			SetEvent(&T::OnRestoreIOSPurchases,"OnRestoreIOSPurchases");
			SetEvent(&T::OnValidateAmazonIAPReceipt,"OnValidateAmazonIAPReceipt");
			SetEvent(&T::OnValidateGooglePlayPurchase,"OnValidateGooglePlayPurchase");
			SetEvent(&T::OnValidateIOSReceipt,"OnValidateIOSReceipt");
			SetEvent(&T::OnValidateWindowsStoreReceipt,"OnValidateWindowsStoreReceipt");
			
        }
        
    };

    // Behavior binder for the (request) based notification bus.
	class PlayFabCombo_ClientBehaviorBusHandler : 
		public PlayFabCombo_ClientNotificationBus::Handler, 
		public PlayFabCombo_ClientBehaviorBusBaseHandler<PlayFabCombo_ClientBehaviorBusHandler>
	{
   
	public:
        
		AZ_RTTI(PlayFabCombo_ClientBehaviorBusHandler,"{2c530f9a-1967-50da-a04b-bb1744908e16}",AZ::BehaviorEBusHandler)

        void Disconnect() override {
			BusDisconnect();
		}
        
		void OnError(const PlayFabError& error) override
		{
			Call(FN_OnError, error);
		}

		// ------------ Generated APIs to receive from the PlayFab notification bus and forward on to the Lua behavior context.
	
		void OnGetPhotonAuthenticationToken(const ClientModels::GetPhotonAuthenticationTokenResult& result) { Call(FN_OnGetPhotonAuthenticationToken, result); };
		void OnGetTitlePublicKey(const ClientModels::GetTitlePublicKeyResult& result) { Call(FN_OnGetTitlePublicKey, result); };
		void OnGetWindowsHelloChallenge(const ClientModels::GetWindowsHelloChallengeResponse& result) { Call(FN_OnGetWindowsHelloChallenge, result); };
		void OnLoginWithAndroidDeviceID(const ClientModels::LoginResult& result) { Call(FN_OnLoginWithAndroidDeviceID, result); };
		void OnLoginWithCustomID(const ClientModels::LoginResult& result) { Call(FN_OnLoginWithCustomID, result); };
		void OnLoginWithEmailAddress(const ClientModels::LoginResult& result) { Call(FN_OnLoginWithEmailAddress, result); };
		void OnLoginWithFacebook(const ClientModels::LoginResult& result) { Call(FN_OnLoginWithFacebook, result); };
		void OnLoginWithGameCenter(const ClientModels::LoginResult& result) { Call(FN_OnLoginWithGameCenter, result); };
		void OnLoginWithGoogleAccount(const ClientModels::LoginResult& result) { Call(FN_OnLoginWithGoogleAccount, result); };
		void OnLoginWithIOSDeviceID(const ClientModels::LoginResult& result) { Call(FN_OnLoginWithIOSDeviceID, result); };
		void OnLoginWithKongregate(const ClientModels::LoginResult& result) { Call(FN_OnLoginWithKongregate, result); };
		void OnLoginWithPlayFab(const ClientModels::LoginResult& result) { Call(FN_OnLoginWithPlayFab, result); };
		void OnLoginWithSteam(const ClientModels::LoginResult& result) { Call(FN_OnLoginWithSteam, result); };
		void OnLoginWithTwitch(const ClientModels::LoginResult& result) { Call(FN_OnLoginWithTwitch, result); };
		void OnLoginWithWindowsHello(const ClientModels::LoginResult& result) { Call(FN_OnLoginWithWindowsHello, result); };
		void OnRegisterPlayFabUser(const ClientModels::RegisterPlayFabUserResult& result) { Call(FN_OnRegisterPlayFabUser, result); };
		void OnRegisterWithWindowsHello(const ClientModels::LoginResult& result) { Call(FN_OnRegisterWithWindowsHello, result); };
		void OnSetPlayerSecret(const ClientModels::SetPlayerSecretResult& result) { Call(FN_OnSetPlayerSecret, result); };
		void OnAddGenericID(const ClientModels::AddGenericIDResult& result) { Call(FN_OnAddGenericID, result); };
		void OnAddUsernamePassword(const ClientModels::AddUsernamePasswordResult& result) { Call(FN_OnAddUsernamePassword, result); };
		void OnGetAccountInfo(const ClientModels::GetAccountInfoResult& result) { Call(FN_OnGetAccountInfo, result); };
		void OnGetPlayerCombinedInfo(const ClientModels::GetPlayerCombinedInfoResult& result) { Call(FN_OnGetPlayerCombinedInfo, result); };
		void OnGetPlayerProfile(const ClientModels::GetPlayerProfileResult& result) { Call(FN_OnGetPlayerProfile, result); };
		void OnGetPlayFabIDsFromFacebookIDs(const ClientModels::GetPlayFabIDsFromFacebookIDsResult& result) { Call(FN_OnGetPlayFabIDsFromFacebookIDs, result); };
		void OnGetPlayFabIDsFromGameCenterIDs(const ClientModels::GetPlayFabIDsFromGameCenterIDsResult& result) { Call(FN_OnGetPlayFabIDsFromGameCenterIDs, result); };
		void OnGetPlayFabIDsFromGenericIDs(const ClientModels::GetPlayFabIDsFromGenericIDsResult& result) { Call(FN_OnGetPlayFabIDsFromGenericIDs, result); };
		void OnGetPlayFabIDsFromGoogleIDs(const ClientModels::GetPlayFabIDsFromGoogleIDsResult& result) { Call(FN_OnGetPlayFabIDsFromGoogleIDs, result); };
		void OnGetPlayFabIDsFromKongregateIDs(const ClientModels::GetPlayFabIDsFromKongregateIDsResult& result) { Call(FN_OnGetPlayFabIDsFromKongregateIDs, result); };
		void OnGetPlayFabIDsFromSteamIDs(const ClientModels::GetPlayFabIDsFromSteamIDsResult& result) { Call(FN_OnGetPlayFabIDsFromSteamIDs, result); };
		void OnGetPlayFabIDsFromTwitchIDs(const ClientModels::GetPlayFabIDsFromTwitchIDsResult& result) { Call(FN_OnGetPlayFabIDsFromTwitchIDs, result); };
		void OnLinkAndroidDeviceID(const ClientModels::LinkAndroidDeviceIDResult& result) { Call(FN_OnLinkAndroidDeviceID, result); };
		void OnLinkCustomID(const ClientModels::LinkCustomIDResult& result) { Call(FN_OnLinkCustomID, result); };
		void OnLinkFacebookAccount(const ClientModels::LinkFacebookAccountResult& result) { Call(FN_OnLinkFacebookAccount, result); };
		void OnLinkGameCenterAccount(const ClientModels::LinkGameCenterAccountResult& result) { Call(FN_OnLinkGameCenterAccount, result); };
		void OnLinkGoogleAccount(const ClientModels::LinkGoogleAccountResult& result) { Call(FN_OnLinkGoogleAccount, result); };
		void OnLinkIOSDeviceID(const ClientModels::LinkIOSDeviceIDResult& result) { Call(FN_OnLinkIOSDeviceID, result); };
		void OnLinkKongregate(const ClientModels::LinkKongregateAccountResult& result) { Call(FN_OnLinkKongregate, result); };
		void OnLinkSteamAccount(const ClientModels::LinkSteamAccountResult& result) { Call(FN_OnLinkSteamAccount, result); };
		void OnLinkTwitch(const ClientModels::LinkTwitchAccountResult& result) { Call(FN_OnLinkTwitch, result); };
		void OnLinkWindowsHello(const ClientModels::LinkWindowsHelloAccountResponse& result) { Call(FN_OnLinkWindowsHello, result); };
		void OnRemoveGenericID(const ClientModels::RemoveGenericIDResult& result) { Call(FN_OnRemoveGenericID, result); };
		void OnReportPlayer(const ClientModels::ReportPlayerClientResult& result) { Call(FN_OnReportPlayer, result); };
		void OnSendAccountRecoveryEmail(const ClientModels::SendAccountRecoveryEmailResult& result) { Call(FN_OnSendAccountRecoveryEmail, result); };
		void OnUnlinkAndroidDeviceID(const ClientModels::UnlinkAndroidDeviceIDResult& result) { Call(FN_OnUnlinkAndroidDeviceID, result); };
		void OnUnlinkCustomID(const ClientModels::UnlinkCustomIDResult& result) { Call(FN_OnUnlinkCustomID, result); };
		void OnUnlinkFacebookAccount(const ClientModels::UnlinkFacebookAccountResult& result) { Call(FN_OnUnlinkFacebookAccount, result); };
		void OnUnlinkGameCenterAccount(const ClientModels::UnlinkGameCenterAccountResult& result) { Call(FN_OnUnlinkGameCenterAccount, result); };
		void OnUnlinkGoogleAccount(const ClientModels::UnlinkGoogleAccountResult& result) { Call(FN_OnUnlinkGoogleAccount, result); };
		void OnUnlinkIOSDeviceID(const ClientModels::UnlinkIOSDeviceIDResult& result) { Call(FN_OnUnlinkIOSDeviceID, result); };
		void OnUnlinkKongregate(const ClientModels::UnlinkKongregateAccountResult& result) { Call(FN_OnUnlinkKongregate, result); };
		void OnUnlinkSteamAccount(const ClientModels::UnlinkSteamAccountResult& result) { Call(FN_OnUnlinkSteamAccount, result); };
		void OnUnlinkTwitch(const ClientModels::UnlinkTwitchAccountResult& result) { Call(FN_OnUnlinkTwitch, result); };
		void OnUnlinkWindowsHello(const ClientModels::UnlinkWindowsHelloAccountResponse& result) { Call(FN_OnUnlinkWindowsHello, result); };
		void OnUpdateAvatarUrl(const ClientModels::EmptyResult& result) { Call(FN_OnUpdateAvatarUrl, result); };
		void OnUpdateUserTitleDisplayName(const ClientModels::UpdateUserTitleDisplayNameResult& result) { Call(FN_OnUpdateUserTitleDisplayName, result); };
		void OnGetFriendLeaderboard(const ClientModels::GetLeaderboardResult& result) { Call(FN_OnGetFriendLeaderboard, result); };
		void OnGetFriendLeaderboardAroundPlayer(const ClientModels::GetFriendLeaderboardAroundPlayerResult& result) { Call(FN_OnGetFriendLeaderboardAroundPlayer, result); };
		void OnGetLeaderboard(const ClientModels::GetLeaderboardResult& result) { Call(FN_OnGetLeaderboard, result); };
		void OnGetLeaderboardAroundPlayer(const ClientModels::GetLeaderboardAroundPlayerResult& result) { Call(FN_OnGetLeaderboardAroundPlayer, result); };
		void OnGetPlayerStatistics(const ClientModels::GetPlayerStatisticsResult& result) { Call(FN_OnGetPlayerStatistics, result); };
		void OnGetPlayerStatisticVersions(const ClientModels::GetPlayerStatisticVersionsResult& result) { Call(FN_OnGetPlayerStatisticVersions, result); };
		void OnGetUserData(const ClientModels::GetUserDataResult& result) { Call(FN_OnGetUserData, result); };
		void OnGetUserPublisherData(const ClientModels::GetUserDataResult& result) { Call(FN_OnGetUserPublisherData, result); };
		void OnGetUserPublisherReadOnlyData(const ClientModels::GetUserDataResult& result) { Call(FN_OnGetUserPublisherReadOnlyData, result); };
		void OnGetUserReadOnlyData(const ClientModels::GetUserDataResult& result) { Call(FN_OnGetUserReadOnlyData, result); };
		void OnUpdatePlayerStatistics(const ClientModels::UpdatePlayerStatisticsResult& result) { Call(FN_OnUpdatePlayerStatistics, result); };
		void OnUpdateUserData(const ClientModels::UpdateUserDataResult& result) { Call(FN_OnUpdateUserData, result); };
		void OnUpdateUserPublisherData(const ClientModels::UpdateUserDataResult& result) { Call(FN_OnUpdateUserPublisherData, result); };
		void OnGetCatalogItems(const ClientModels::GetCatalogItemsResult& result) { Call(FN_OnGetCatalogItems, result); };
		void OnGetPublisherData(const ClientModels::GetPublisherDataResult& result) { Call(FN_OnGetPublisherData, result); };
		void OnGetStoreItems(const ClientModels::GetStoreItemsResult& result) { Call(FN_OnGetStoreItems, result); };
		void OnGetTime(const ClientModels::GetTimeResult& result) { Call(FN_OnGetTime, result); };
		void OnGetTitleData(const ClientModels::GetTitleDataResult& result) { Call(FN_OnGetTitleData, result); };
		void OnGetTitleNews(const ClientModels::GetTitleNewsResult& result) { Call(FN_OnGetTitleNews, result); };
		void OnAddUserVirtualCurrency(const ClientModels::ModifyUserVirtualCurrencyResult& result) { Call(FN_OnAddUserVirtualCurrency, result); };
		void OnConfirmPurchase(const ClientModels::ConfirmPurchaseResult& result) { Call(FN_OnConfirmPurchase, result); };
		void OnConsumeItem(const ClientModels::ConsumeItemResult& result) { Call(FN_OnConsumeItem, result); };
		void OnGetCharacterInventory(const ClientModels::GetCharacterInventoryResult& result) { Call(FN_OnGetCharacterInventory, result); };
		void OnGetPurchase(const ClientModels::GetPurchaseResult& result) { Call(FN_OnGetPurchase, result); };
		void OnGetUserInventory(const ClientModels::GetUserInventoryResult& result) { Call(FN_OnGetUserInventory, result); };
		void OnPayForPurchase(const ClientModels::PayForPurchaseResult& result) { Call(FN_OnPayForPurchase, result); };
		void OnPurchaseItem(const ClientModels::PurchaseItemResult& result) { Call(FN_OnPurchaseItem, result); };
		void OnRedeemCoupon(const ClientModels::RedeemCouponResult& result) { Call(FN_OnRedeemCoupon, result); };
		void OnStartPurchase(const ClientModels::StartPurchaseResult& result) { Call(FN_OnStartPurchase, result); };
		void OnSubtractUserVirtualCurrency(const ClientModels::ModifyUserVirtualCurrencyResult& result) { Call(FN_OnSubtractUserVirtualCurrency, result); };
		void OnUnlockContainerInstance(const ClientModels::UnlockContainerItemResult& result) { Call(FN_OnUnlockContainerInstance, result); };
		void OnUnlockContainerItem(const ClientModels::UnlockContainerItemResult& result) { Call(FN_OnUnlockContainerItem, result); };
		void OnAddFriend(const ClientModels::AddFriendResult& result) { Call(FN_OnAddFriend, result); };
		void OnGetFriendsList(const ClientModels::GetFriendsListResult& result) { Call(FN_OnGetFriendsList, result); };
		void OnRemoveFriend(const ClientModels::RemoveFriendResult& result) { Call(FN_OnRemoveFriend, result); };
		void OnSetFriendTags(const ClientModels::SetFriendTagsResult& result) { Call(FN_OnSetFriendTags, result); };
		void OnGetCurrentGames(const ClientModels::CurrentGamesResult& result) { Call(FN_OnGetCurrentGames, result); };
		void OnGetGameServerRegions(const ClientModels::GameServerRegionsResult& result) { Call(FN_OnGetGameServerRegions, result); };
		void OnMatchmake(const ClientModels::MatchmakeResult& result) { Call(FN_OnMatchmake, result); };
		void OnStartGame(const ClientModels::StartGameResult& result) { Call(FN_OnStartGame, result); };
		void OnWriteCharacterEvent(const ClientModels::WriteEventResponse& result) { Call(FN_OnWriteCharacterEvent, result); };
		void OnWritePlayerEvent(const ClientModels::WriteEventResponse& result) { Call(FN_OnWritePlayerEvent, result); };
		void OnWriteTitleEvent(const ClientModels::WriteEventResponse& result) { Call(FN_OnWriteTitleEvent, result); };
		void OnAddSharedGroupMembers(const ClientModels::AddSharedGroupMembersResult& result) { Call(FN_OnAddSharedGroupMembers, result); };
		void OnCreateSharedGroup(const ClientModels::CreateSharedGroupResult& result) { Call(FN_OnCreateSharedGroup, result); };
		void OnGetSharedGroupData(const ClientModels::GetSharedGroupDataResult& result) { Call(FN_OnGetSharedGroupData, result); };
		void OnRemoveSharedGroupMembers(const ClientModels::RemoveSharedGroupMembersResult& result) { Call(FN_OnRemoveSharedGroupMembers, result); };
		void OnUpdateSharedGroupData(const ClientModels::UpdateSharedGroupDataResult& result) { Call(FN_OnUpdateSharedGroupData, result); };
		void OnExecuteCloudScript(const ClientModels::ExecuteCloudScriptResult& result) { Call(FN_OnExecuteCloudScript, result); };
		void OnGetContentDownloadUrl(const ClientModels::GetContentDownloadUrlResult& result) { Call(FN_OnGetContentDownloadUrl, result); };
		void OnGetAllUsersCharacters(const ClientModels::ListUsersCharactersResult& result) { Call(FN_OnGetAllUsersCharacters, result); };
		void OnGetCharacterLeaderboard(const ClientModels::GetCharacterLeaderboardResult& result) { Call(FN_OnGetCharacterLeaderboard, result); };
		void OnGetCharacterStatistics(const ClientModels::GetCharacterStatisticsResult& result) { Call(FN_OnGetCharacterStatistics, result); };
		void OnGetLeaderboardAroundCharacter(const ClientModels::GetLeaderboardAroundCharacterResult& result) { Call(FN_OnGetLeaderboardAroundCharacter, result); };
		void OnGetLeaderboardForUserCharacters(const ClientModels::GetLeaderboardForUsersCharactersResult& result) { Call(FN_OnGetLeaderboardForUserCharacters, result); };
		void OnGrantCharacterToUser(const ClientModels::GrantCharacterToUserResult& result) { Call(FN_OnGrantCharacterToUser, result); };
		void OnUpdateCharacterStatistics(const ClientModels::UpdateCharacterStatisticsResult& result) { Call(FN_OnUpdateCharacterStatistics, result); };
		void OnGetCharacterData(const ClientModels::GetCharacterDataResult& result) { Call(FN_OnGetCharacterData, result); };
		void OnGetCharacterReadOnlyData(const ClientModels::GetCharacterDataResult& result) { Call(FN_OnGetCharacterReadOnlyData, result); };
		void OnUpdateCharacterData(const ClientModels::UpdateCharacterDataResult& result) { Call(FN_OnUpdateCharacterData, result); };
		void OnAcceptTrade(const ClientModels::AcceptTradeResponse& result) { Call(FN_OnAcceptTrade, result); };
		void OnCancelTrade(const ClientModels::CancelTradeResponse& result) { Call(FN_OnCancelTrade, result); };
		void OnGetPlayerTrades(const ClientModels::GetPlayerTradesResponse& result) { Call(FN_OnGetPlayerTrades, result); };
		void OnGetTradeStatus(const ClientModels::GetTradeStatusResponse& result) { Call(FN_OnGetTradeStatus, result); };
		void OnOpenTrade(const ClientModels::OpenTradeResponse& result) { Call(FN_OnOpenTrade, result); };
		void OnAttributeInstall(const ClientModels::AttributeInstallResult& result) { Call(FN_OnAttributeInstall, result); };
		void OnGetPlayerSegments(const ClientModels::GetPlayerSegmentsResult& result) { Call(FN_OnGetPlayerSegments, result); };
		void OnGetPlayerTags(const ClientModels::GetPlayerTagsResult& result) { Call(FN_OnGetPlayerTags, result); };
		void OnAndroidDevicePushNotificationRegistration(const ClientModels::AndroidDevicePushNotificationRegistrationResult& result) { Call(FN_OnAndroidDevicePushNotificationRegistration, result); };
		void OnRegisterForIOSPushNotification(const ClientModels::RegisterForIOSPushNotificationResult& result) { Call(FN_OnRegisterForIOSPushNotification, result); };
		void OnRestoreIOSPurchases(const ClientModels::RestoreIOSPurchasesResult& result) { Call(FN_OnRestoreIOSPurchases, result); };
		void OnValidateAmazonIAPReceipt(const ClientModels::ValidateAmazonReceiptResult& result) { Call(FN_OnValidateAmazonIAPReceipt, result); };
		void OnValidateGooglePlayPurchase(const ClientModels::ValidateGooglePlayPurchaseResult& result) { Call(FN_OnValidateGooglePlayPurchase, result); };
		void OnValidateIOSReceipt(const ClientModels::ValidateIOSReceiptResult& result) { Call(FN_OnValidateIOSReceipt, result); };
		void OnValidateWindowsStoreReceipt(const ClientModels::ValidateWindowsReceiptResult& result) { Call(FN_OnValidateWindowsStoreReceipt, result); };

	};

    // Behavior binder for the (global) based notification bus.
	class PlayFabCombo_ClientGlobalBehaviorBusHandler : 
		public PlayFabCombo_ClientGlobalNotificationBus::Handler, 
		public PlayFabCombo_ClientBehaviorBusBaseHandler<PlayFabCombo_ClientGlobalBehaviorBusHandler>
	{
   
	public:
        
		AZ_RTTI(PlayFabCombo_ClientGlobalBehaviorBusHandler,"{546b606b-0bf3-5df7-b256-cc6c1164d0c8}",AZ::BehaviorEBusHandler)

        void Disconnect() override {
			BusDisconnect();
		}

		void OnError(const PlayFabError& error, int requestId) override
		{
			Call(FN_OnError, error, requestId);
		}

		// ------------ Generated APIs to receive from the PlayFab notification bus and forward on to the Lua behavior context.
	
		void OnGetPhotonAuthenticationToken(const ClientModels::GetPhotonAuthenticationTokenResult& result,int requestId) { Call(FN_OnGetPhotonAuthenticationToken, result,requestId); };
		void OnGetTitlePublicKey(const ClientModels::GetTitlePublicKeyResult& result,int requestId) { Call(FN_OnGetTitlePublicKey, result,requestId); };
		void OnGetWindowsHelloChallenge(const ClientModels::GetWindowsHelloChallengeResponse& result,int requestId) { Call(FN_OnGetWindowsHelloChallenge, result,requestId); };
		void OnLoginWithAndroidDeviceID(const ClientModels::LoginResult& result,int requestId) { Call(FN_OnLoginWithAndroidDeviceID, result,requestId); };
		void OnLoginWithCustomID(const ClientModels::LoginResult& result,int requestId) { Call(FN_OnLoginWithCustomID, result,requestId); };
		void OnLoginWithEmailAddress(const ClientModels::LoginResult& result,int requestId) { Call(FN_OnLoginWithEmailAddress, result,requestId); };
		void OnLoginWithFacebook(const ClientModels::LoginResult& result,int requestId) { Call(FN_OnLoginWithFacebook, result,requestId); };
		void OnLoginWithGameCenter(const ClientModels::LoginResult& result,int requestId) { Call(FN_OnLoginWithGameCenter, result,requestId); };
		void OnLoginWithGoogleAccount(const ClientModels::LoginResult& result,int requestId) { Call(FN_OnLoginWithGoogleAccount, result,requestId); };
		void OnLoginWithIOSDeviceID(const ClientModels::LoginResult& result,int requestId) { Call(FN_OnLoginWithIOSDeviceID, result,requestId); };
		void OnLoginWithKongregate(const ClientModels::LoginResult& result,int requestId) { Call(FN_OnLoginWithKongregate, result,requestId); };
		void OnLoginWithPlayFab(const ClientModels::LoginResult& result,int requestId) { Call(FN_OnLoginWithPlayFab, result,requestId); };
		void OnLoginWithSteam(const ClientModels::LoginResult& result,int requestId) { Call(FN_OnLoginWithSteam, result,requestId); };
		void OnLoginWithTwitch(const ClientModels::LoginResult& result,int requestId) { Call(FN_OnLoginWithTwitch, result,requestId); };
		void OnLoginWithWindowsHello(const ClientModels::LoginResult& result,int requestId) { Call(FN_OnLoginWithWindowsHello, result,requestId); };
		void OnRegisterPlayFabUser(const ClientModels::RegisterPlayFabUserResult& result,int requestId) { Call(FN_OnRegisterPlayFabUser, result,requestId); };
		void OnRegisterWithWindowsHello(const ClientModels::LoginResult& result,int requestId) { Call(FN_OnRegisterWithWindowsHello, result,requestId); };
		void OnSetPlayerSecret(const ClientModels::SetPlayerSecretResult& result,int requestId) { Call(FN_OnSetPlayerSecret, result,requestId); };
		void OnAddGenericID(const ClientModels::AddGenericIDResult& result,int requestId) { Call(FN_OnAddGenericID, result,requestId); };
		void OnAddUsernamePassword(const ClientModels::AddUsernamePasswordResult& result,int requestId) { Call(FN_OnAddUsernamePassword, result,requestId); };
		void OnGetAccountInfo(const ClientModels::GetAccountInfoResult& result,int requestId) { Call(FN_OnGetAccountInfo, result,requestId); };
		void OnGetPlayerCombinedInfo(const ClientModels::GetPlayerCombinedInfoResult& result,int requestId) { Call(FN_OnGetPlayerCombinedInfo, result,requestId); };
		void OnGetPlayerProfile(const ClientModels::GetPlayerProfileResult& result,int requestId) { Call(FN_OnGetPlayerProfile, result,requestId); };
		void OnGetPlayFabIDsFromFacebookIDs(const ClientModels::GetPlayFabIDsFromFacebookIDsResult& result,int requestId) { Call(FN_OnGetPlayFabIDsFromFacebookIDs, result,requestId); };
		void OnGetPlayFabIDsFromGameCenterIDs(const ClientModels::GetPlayFabIDsFromGameCenterIDsResult& result,int requestId) { Call(FN_OnGetPlayFabIDsFromGameCenterIDs, result,requestId); };
		void OnGetPlayFabIDsFromGenericIDs(const ClientModels::GetPlayFabIDsFromGenericIDsResult& result,int requestId) { Call(FN_OnGetPlayFabIDsFromGenericIDs, result,requestId); };
		void OnGetPlayFabIDsFromGoogleIDs(const ClientModels::GetPlayFabIDsFromGoogleIDsResult& result,int requestId) { Call(FN_OnGetPlayFabIDsFromGoogleIDs, result,requestId); };
		void OnGetPlayFabIDsFromKongregateIDs(const ClientModels::GetPlayFabIDsFromKongregateIDsResult& result,int requestId) { Call(FN_OnGetPlayFabIDsFromKongregateIDs, result,requestId); };
		void OnGetPlayFabIDsFromSteamIDs(const ClientModels::GetPlayFabIDsFromSteamIDsResult& result,int requestId) { Call(FN_OnGetPlayFabIDsFromSteamIDs, result,requestId); };
		void OnGetPlayFabIDsFromTwitchIDs(const ClientModels::GetPlayFabIDsFromTwitchIDsResult& result,int requestId) { Call(FN_OnGetPlayFabIDsFromTwitchIDs, result,requestId); };
		void OnLinkAndroidDeviceID(const ClientModels::LinkAndroidDeviceIDResult& result,int requestId) { Call(FN_OnLinkAndroidDeviceID, result,requestId); };
		void OnLinkCustomID(const ClientModels::LinkCustomIDResult& result,int requestId) { Call(FN_OnLinkCustomID, result,requestId); };
		void OnLinkFacebookAccount(const ClientModels::LinkFacebookAccountResult& result,int requestId) { Call(FN_OnLinkFacebookAccount, result,requestId); };
		void OnLinkGameCenterAccount(const ClientModels::LinkGameCenterAccountResult& result,int requestId) { Call(FN_OnLinkGameCenterAccount, result,requestId); };
		void OnLinkGoogleAccount(const ClientModels::LinkGoogleAccountResult& result,int requestId) { Call(FN_OnLinkGoogleAccount, result,requestId); };
		void OnLinkIOSDeviceID(const ClientModels::LinkIOSDeviceIDResult& result,int requestId) { Call(FN_OnLinkIOSDeviceID, result,requestId); };
		void OnLinkKongregate(const ClientModels::LinkKongregateAccountResult& result,int requestId) { Call(FN_OnLinkKongregate, result,requestId); };
		void OnLinkSteamAccount(const ClientModels::LinkSteamAccountResult& result,int requestId) { Call(FN_OnLinkSteamAccount, result,requestId); };
		void OnLinkTwitch(const ClientModels::LinkTwitchAccountResult& result,int requestId) { Call(FN_OnLinkTwitch, result,requestId); };
		void OnLinkWindowsHello(const ClientModels::LinkWindowsHelloAccountResponse& result,int requestId) { Call(FN_OnLinkWindowsHello, result,requestId); };
		void OnRemoveGenericID(const ClientModels::RemoveGenericIDResult& result,int requestId) { Call(FN_OnRemoveGenericID, result,requestId); };
		void OnReportPlayer(const ClientModels::ReportPlayerClientResult& result,int requestId) { Call(FN_OnReportPlayer, result,requestId); };
		void OnSendAccountRecoveryEmail(const ClientModels::SendAccountRecoveryEmailResult& result,int requestId) { Call(FN_OnSendAccountRecoveryEmail, result,requestId); };
		void OnUnlinkAndroidDeviceID(const ClientModels::UnlinkAndroidDeviceIDResult& result,int requestId) { Call(FN_OnUnlinkAndroidDeviceID, result,requestId); };
		void OnUnlinkCustomID(const ClientModels::UnlinkCustomIDResult& result,int requestId) { Call(FN_OnUnlinkCustomID, result,requestId); };
		void OnUnlinkFacebookAccount(const ClientModels::UnlinkFacebookAccountResult& result,int requestId) { Call(FN_OnUnlinkFacebookAccount, result,requestId); };
		void OnUnlinkGameCenterAccount(const ClientModels::UnlinkGameCenterAccountResult& result,int requestId) { Call(FN_OnUnlinkGameCenterAccount, result,requestId); };
		void OnUnlinkGoogleAccount(const ClientModels::UnlinkGoogleAccountResult& result,int requestId) { Call(FN_OnUnlinkGoogleAccount, result,requestId); };
		void OnUnlinkIOSDeviceID(const ClientModels::UnlinkIOSDeviceIDResult& result,int requestId) { Call(FN_OnUnlinkIOSDeviceID, result,requestId); };
		void OnUnlinkKongregate(const ClientModels::UnlinkKongregateAccountResult& result,int requestId) { Call(FN_OnUnlinkKongregate, result,requestId); };
		void OnUnlinkSteamAccount(const ClientModels::UnlinkSteamAccountResult& result,int requestId) { Call(FN_OnUnlinkSteamAccount, result,requestId); };
		void OnUnlinkTwitch(const ClientModels::UnlinkTwitchAccountResult& result,int requestId) { Call(FN_OnUnlinkTwitch, result,requestId); };
		void OnUnlinkWindowsHello(const ClientModels::UnlinkWindowsHelloAccountResponse& result,int requestId) { Call(FN_OnUnlinkWindowsHello, result,requestId); };
		void OnUpdateAvatarUrl(const ClientModels::EmptyResult& result,int requestId) { Call(FN_OnUpdateAvatarUrl, result,requestId); };
		void OnUpdateUserTitleDisplayName(const ClientModels::UpdateUserTitleDisplayNameResult& result,int requestId) { Call(FN_OnUpdateUserTitleDisplayName, result,requestId); };
		void OnGetFriendLeaderboard(const ClientModels::GetLeaderboardResult& result,int requestId) { Call(FN_OnGetFriendLeaderboard, result,requestId); };
		void OnGetFriendLeaderboardAroundPlayer(const ClientModels::GetFriendLeaderboardAroundPlayerResult& result,int requestId) { Call(FN_OnGetFriendLeaderboardAroundPlayer, result,requestId); };
		void OnGetLeaderboard(const ClientModels::GetLeaderboardResult& result,int requestId) { Call(FN_OnGetLeaderboard, result,requestId); };
		void OnGetLeaderboardAroundPlayer(const ClientModels::GetLeaderboardAroundPlayerResult& result,int requestId) { Call(FN_OnGetLeaderboardAroundPlayer, result,requestId); };
		void OnGetPlayerStatistics(const ClientModels::GetPlayerStatisticsResult& result,int requestId) { Call(FN_OnGetPlayerStatistics, result,requestId); };
		void OnGetPlayerStatisticVersions(const ClientModels::GetPlayerStatisticVersionsResult& result,int requestId) { Call(FN_OnGetPlayerStatisticVersions, result,requestId); };
		void OnGetUserData(const ClientModels::GetUserDataResult& result,int requestId) { Call(FN_OnGetUserData, result,requestId); };
		void OnGetUserPublisherData(const ClientModels::GetUserDataResult& result,int requestId) { Call(FN_OnGetUserPublisherData, result,requestId); };
		void OnGetUserPublisherReadOnlyData(const ClientModels::GetUserDataResult& result,int requestId) { Call(FN_OnGetUserPublisherReadOnlyData, result,requestId); };
		void OnGetUserReadOnlyData(const ClientModels::GetUserDataResult& result,int requestId) { Call(FN_OnGetUserReadOnlyData, result,requestId); };
		void OnUpdatePlayerStatistics(const ClientModels::UpdatePlayerStatisticsResult& result,int requestId) { Call(FN_OnUpdatePlayerStatistics, result,requestId); };
		void OnUpdateUserData(const ClientModels::UpdateUserDataResult& result,int requestId) { Call(FN_OnUpdateUserData, result,requestId); };
		void OnUpdateUserPublisherData(const ClientModels::UpdateUserDataResult& result,int requestId) { Call(FN_OnUpdateUserPublisherData, result,requestId); };
		void OnGetCatalogItems(const ClientModels::GetCatalogItemsResult& result,int requestId) { Call(FN_OnGetCatalogItems, result,requestId); };
		void OnGetPublisherData(const ClientModels::GetPublisherDataResult& result,int requestId) { Call(FN_OnGetPublisherData, result,requestId); };
		void OnGetStoreItems(const ClientModels::GetStoreItemsResult& result,int requestId) { Call(FN_OnGetStoreItems, result,requestId); };
		void OnGetTime(const ClientModels::GetTimeResult& result,int requestId) { Call(FN_OnGetTime, result,requestId); };
		void OnGetTitleData(const ClientModels::GetTitleDataResult& result,int requestId) { Call(FN_OnGetTitleData, result,requestId); };
		void OnGetTitleNews(const ClientModels::GetTitleNewsResult& result,int requestId) { Call(FN_OnGetTitleNews, result,requestId); };
		void OnAddUserVirtualCurrency(const ClientModels::ModifyUserVirtualCurrencyResult& result,int requestId) { Call(FN_OnAddUserVirtualCurrency, result,requestId); };
		void OnConfirmPurchase(const ClientModels::ConfirmPurchaseResult& result,int requestId) { Call(FN_OnConfirmPurchase, result,requestId); };
		void OnConsumeItem(const ClientModels::ConsumeItemResult& result,int requestId) { Call(FN_OnConsumeItem, result,requestId); };
		void OnGetCharacterInventory(const ClientModels::GetCharacterInventoryResult& result,int requestId) { Call(FN_OnGetCharacterInventory, result,requestId); };
		void OnGetPurchase(const ClientModels::GetPurchaseResult& result,int requestId) { Call(FN_OnGetPurchase, result,requestId); };
		void OnGetUserInventory(const ClientModels::GetUserInventoryResult& result,int requestId) { Call(FN_OnGetUserInventory, result,requestId); };
		void OnPayForPurchase(const ClientModels::PayForPurchaseResult& result,int requestId) { Call(FN_OnPayForPurchase, result,requestId); };
		void OnPurchaseItem(const ClientModels::PurchaseItemResult& result,int requestId) { Call(FN_OnPurchaseItem, result,requestId); };
		void OnRedeemCoupon(const ClientModels::RedeemCouponResult& result,int requestId) { Call(FN_OnRedeemCoupon, result,requestId); };
		void OnStartPurchase(const ClientModels::StartPurchaseResult& result,int requestId) { Call(FN_OnStartPurchase, result,requestId); };
		void OnSubtractUserVirtualCurrency(const ClientModels::ModifyUserVirtualCurrencyResult& result,int requestId) { Call(FN_OnSubtractUserVirtualCurrency, result,requestId); };
		void OnUnlockContainerInstance(const ClientModels::UnlockContainerItemResult& result,int requestId) { Call(FN_OnUnlockContainerInstance, result,requestId); };
		void OnUnlockContainerItem(const ClientModels::UnlockContainerItemResult& result,int requestId) { Call(FN_OnUnlockContainerItem, result,requestId); };
		void OnAddFriend(const ClientModels::AddFriendResult& result,int requestId) { Call(FN_OnAddFriend, result,requestId); };
		void OnGetFriendsList(const ClientModels::GetFriendsListResult& result,int requestId) { Call(FN_OnGetFriendsList, result,requestId); };
		void OnRemoveFriend(const ClientModels::RemoveFriendResult& result,int requestId) { Call(FN_OnRemoveFriend, result,requestId); };
		void OnSetFriendTags(const ClientModels::SetFriendTagsResult& result,int requestId) { Call(FN_OnSetFriendTags, result,requestId); };
		void OnGetCurrentGames(const ClientModels::CurrentGamesResult& result,int requestId) { Call(FN_OnGetCurrentGames, result,requestId); };
		void OnGetGameServerRegions(const ClientModels::GameServerRegionsResult& result,int requestId) { Call(FN_OnGetGameServerRegions, result,requestId); };
		void OnMatchmake(const ClientModels::MatchmakeResult& result,int requestId) { Call(FN_OnMatchmake, result,requestId); };
		void OnStartGame(const ClientModels::StartGameResult& result,int requestId) { Call(FN_OnStartGame, result,requestId); };
		void OnWriteCharacterEvent(const ClientModels::WriteEventResponse& result,int requestId) { Call(FN_OnWriteCharacterEvent, result,requestId); };
		void OnWritePlayerEvent(const ClientModels::WriteEventResponse& result,int requestId) { Call(FN_OnWritePlayerEvent, result,requestId); };
		void OnWriteTitleEvent(const ClientModels::WriteEventResponse& result,int requestId) { Call(FN_OnWriteTitleEvent, result,requestId); };
		void OnAddSharedGroupMembers(const ClientModels::AddSharedGroupMembersResult& result,int requestId) { Call(FN_OnAddSharedGroupMembers, result,requestId); };
		void OnCreateSharedGroup(const ClientModels::CreateSharedGroupResult& result,int requestId) { Call(FN_OnCreateSharedGroup, result,requestId); };
		void OnGetSharedGroupData(const ClientModels::GetSharedGroupDataResult& result,int requestId) { Call(FN_OnGetSharedGroupData, result,requestId); };
		void OnRemoveSharedGroupMembers(const ClientModels::RemoveSharedGroupMembersResult& result,int requestId) { Call(FN_OnRemoveSharedGroupMembers, result,requestId); };
		void OnUpdateSharedGroupData(const ClientModels::UpdateSharedGroupDataResult& result,int requestId) { Call(FN_OnUpdateSharedGroupData, result,requestId); };
		void OnExecuteCloudScript(const ClientModels::ExecuteCloudScriptResult& result,int requestId) { Call(FN_OnExecuteCloudScript, result,requestId); };
		void OnGetContentDownloadUrl(const ClientModels::GetContentDownloadUrlResult& result,int requestId) { Call(FN_OnGetContentDownloadUrl, result,requestId); };
		void OnGetAllUsersCharacters(const ClientModels::ListUsersCharactersResult& result,int requestId) { Call(FN_OnGetAllUsersCharacters, result,requestId); };
		void OnGetCharacterLeaderboard(const ClientModels::GetCharacterLeaderboardResult& result,int requestId) { Call(FN_OnGetCharacterLeaderboard, result,requestId); };
		void OnGetCharacterStatistics(const ClientModels::GetCharacterStatisticsResult& result,int requestId) { Call(FN_OnGetCharacterStatistics, result,requestId); };
		void OnGetLeaderboardAroundCharacter(const ClientModels::GetLeaderboardAroundCharacterResult& result,int requestId) { Call(FN_OnGetLeaderboardAroundCharacter, result,requestId); };
		void OnGetLeaderboardForUserCharacters(const ClientModels::GetLeaderboardForUsersCharactersResult& result,int requestId) { Call(FN_OnGetLeaderboardForUserCharacters, result,requestId); };
		void OnGrantCharacterToUser(const ClientModels::GrantCharacterToUserResult& result,int requestId) { Call(FN_OnGrantCharacterToUser, result,requestId); };
		void OnUpdateCharacterStatistics(const ClientModels::UpdateCharacterStatisticsResult& result,int requestId) { Call(FN_OnUpdateCharacterStatistics, result,requestId); };
		void OnGetCharacterData(const ClientModels::GetCharacterDataResult& result,int requestId) { Call(FN_OnGetCharacterData, result,requestId); };
		void OnGetCharacterReadOnlyData(const ClientModels::GetCharacterDataResult& result,int requestId) { Call(FN_OnGetCharacterReadOnlyData, result,requestId); };
		void OnUpdateCharacterData(const ClientModels::UpdateCharacterDataResult& result,int requestId) { Call(FN_OnUpdateCharacterData, result,requestId); };
		void OnAcceptTrade(const ClientModels::AcceptTradeResponse& result,int requestId) { Call(FN_OnAcceptTrade, result,requestId); };
		void OnCancelTrade(const ClientModels::CancelTradeResponse& result,int requestId) { Call(FN_OnCancelTrade, result,requestId); };
		void OnGetPlayerTrades(const ClientModels::GetPlayerTradesResponse& result,int requestId) { Call(FN_OnGetPlayerTrades, result,requestId); };
		void OnGetTradeStatus(const ClientModels::GetTradeStatusResponse& result,int requestId) { Call(FN_OnGetTradeStatus, result,requestId); };
		void OnOpenTrade(const ClientModels::OpenTradeResponse& result,int requestId) { Call(FN_OnOpenTrade, result,requestId); };
		void OnAttributeInstall(const ClientModels::AttributeInstallResult& result,int requestId) { Call(FN_OnAttributeInstall, result,requestId); };
		void OnGetPlayerSegments(const ClientModels::GetPlayerSegmentsResult& result,int requestId) { Call(FN_OnGetPlayerSegments, result,requestId); };
		void OnGetPlayerTags(const ClientModels::GetPlayerTagsResult& result,int requestId) { Call(FN_OnGetPlayerTags, result,requestId); };
		void OnAndroidDevicePushNotificationRegistration(const ClientModels::AndroidDevicePushNotificationRegistrationResult& result,int requestId) { Call(FN_OnAndroidDevicePushNotificationRegistration, result,requestId); };
		void OnRegisterForIOSPushNotification(const ClientModels::RegisterForIOSPushNotificationResult& result,int requestId) { Call(FN_OnRegisterForIOSPushNotification, result,requestId); };
		void OnRestoreIOSPurchases(const ClientModels::RestoreIOSPurchasesResult& result,int requestId) { Call(FN_OnRestoreIOSPurchases, result,requestId); };
		void OnValidateAmazonIAPReceipt(const ClientModels::ValidateAmazonReceiptResult& result,int requestId) { Call(FN_OnValidateAmazonIAPReceipt, result,requestId); };
		void OnValidateGooglePlayPurchase(const ClientModels::ValidateGooglePlayPurchaseResult& result,int requestId) { Call(FN_OnValidateGooglePlayPurchase, result,requestId); };
		void OnValidateIOSReceipt(const ClientModels::ValidateIOSReceiptResult& result,int requestId) { Call(FN_OnValidateIOSReceipt, result,requestId); };
		void OnValidateWindowsStoreReceipt(const ClientModels::ValidateWindowsReceiptResult& result,int requestId) { Call(FN_OnValidateWindowsStoreReceipt, result,requestId); };

	};

    //-----------------------------------------------------------------------------------------------------
    // MAIN REFLECTION FUNCTION
    //-----------------------------------------------------------------------------------------------------
	void PlayFabCombo_ClientBehaviorContext::Reflect(AZ::ReflectContext* context)
	{
		AZ::BehaviorContext* behaviorContext = azrtti_cast<AZ::BehaviorContext*>(context);
		if (behaviorContext)
		{
			// Reflect the request bus
			behaviorContext->EBus<PlayFabCombo_ClientSimpleRequestBus>("PlayFabClientRequestBus")
				->Event("GetPhotonAuthenticationToken", &PlayFabCombo_ClientSimpleRequestBus::Events::GetPhotonAuthenticationToken)
				->Event("GetTitlePublicKey", &PlayFabCombo_ClientSimpleRequestBus::Events::GetTitlePublicKey)
				->Event("GetWindowsHelloChallenge", &PlayFabCombo_ClientSimpleRequestBus::Events::GetWindowsHelloChallenge)
				->Event("LoginWithAndroidDeviceID", &PlayFabCombo_ClientSimpleRequestBus::Events::LoginWithAndroidDeviceID)
				->Event("LoginWithCustomID", &PlayFabCombo_ClientSimpleRequestBus::Events::LoginWithCustomID)
				->Event("LoginWithEmailAddress", &PlayFabCombo_ClientSimpleRequestBus::Events::LoginWithEmailAddress)
				->Event("LoginWithFacebook", &PlayFabCombo_ClientSimpleRequestBus::Events::LoginWithFacebook)
				->Event("LoginWithGameCenter", &PlayFabCombo_ClientSimpleRequestBus::Events::LoginWithGameCenter)
				->Event("LoginWithGoogleAccount", &PlayFabCombo_ClientSimpleRequestBus::Events::LoginWithGoogleAccount)
				->Event("LoginWithIOSDeviceID", &PlayFabCombo_ClientSimpleRequestBus::Events::LoginWithIOSDeviceID)
				->Event("LoginWithKongregate", &PlayFabCombo_ClientSimpleRequestBus::Events::LoginWithKongregate)
				->Event("LoginWithPlayFab", &PlayFabCombo_ClientSimpleRequestBus::Events::LoginWithPlayFab)
				->Event("LoginWithSteam", &PlayFabCombo_ClientSimpleRequestBus::Events::LoginWithSteam)
				->Event("LoginWithTwitch", &PlayFabCombo_ClientSimpleRequestBus::Events::LoginWithTwitch)
				->Event("LoginWithWindowsHello", &PlayFabCombo_ClientSimpleRequestBus::Events::LoginWithWindowsHello)
				->Event("RegisterPlayFabUser", &PlayFabCombo_ClientSimpleRequestBus::Events::RegisterPlayFabUser)
				->Event("RegisterWithWindowsHello", &PlayFabCombo_ClientSimpleRequestBus::Events::RegisterWithWindowsHello)
				->Event("SetPlayerSecret", &PlayFabCombo_ClientSimpleRequestBus::Events::SetPlayerSecret)
				->Event("AddGenericID", &PlayFabCombo_ClientSimpleRequestBus::Events::AddGenericID)
				->Event("AddUsernamePassword", &PlayFabCombo_ClientSimpleRequestBus::Events::AddUsernamePassword)
				->Event("GetAccountInfo", &PlayFabCombo_ClientSimpleRequestBus::Events::GetAccountInfo)
				->Event("GetPlayerCombinedInfo", &PlayFabCombo_ClientSimpleRequestBus::Events::GetPlayerCombinedInfo)
				->Event("GetPlayerProfile", &PlayFabCombo_ClientSimpleRequestBus::Events::GetPlayerProfile)
				->Event("GetPlayFabIDsFromFacebookIDs", &PlayFabCombo_ClientSimpleRequestBus::Events::GetPlayFabIDsFromFacebookIDs)
				->Event("GetPlayFabIDsFromGameCenterIDs", &PlayFabCombo_ClientSimpleRequestBus::Events::GetPlayFabIDsFromGameCenterIDs)
				->Event("GetPlayFabIDsFromGenericIDs", &PlayFabCombo_ClientSimpleRequestBus::Events::GetPlayFabIDsFromGenericIDs)
				->Event("GetPlayFabIDsFromGoogleIDs", &PlayFabCombo_ClientSimpleRequestBus::Events::GetPlayFabIDsFromGoogleIDs)
				->Event("GetPlayFabIDsFromKongregateIDs", &PlayFabCombo_ClientSimpleRequestBus::Events::GetPlayFabIDsFromKongregateIDs)
				->Event("GetPlayFabIDsFromSteamIDs", &PlayFabCombo_ClientSimpleRequestBus::Events::GetPlayFabIDsFromSteamIDs)
				->Event("GetPlayFabIDsFromTwitchIDs", &PlayFabCombo_ClientSimpleRequestBus::Events::GetPlayFabIDsFromTwitchIDs)
				->Event("LinkAndroidDeviceID", &PlayFabCombo_ClientSimpleRequestBus::Events::LinkAndroidDeviceID)
				->Event("LinkCustomID", &PlayFabCombo_ClientSimpleRequestBus::Events::LinkCustomID)
				->Event("LinkFacebookAccount", &PlayFabCombo_ClientSimpleRequestBus::Events::LinkFacebookAccount)
				->Event("LinkGameCenterAccount", &PlayFabCombo_ClientSimpleRequestBus::Events::LinkGameCenterAccount)
				->Event("LinkGoogleAccount", &PlayFabCombo_ClientSimpleRequestBus::Events::LinkGoogleAccount)
				->Event("LinkIOSDeviceID", &PlayFabCombo_ClientSimpleRequestBus::Events::LinkIOSDeviceID)
				->Event("LinkKongregate", &PlayFabCombo_ClientSimpleRequestBus::Events::LinkKongregate)
				->Event("LinkSteamAccount", &PlayFabCombo_ClientSimpleRequestBus::Events::LinkSteamAccount)
				->Event("LinkTwitch", &PlayFabCombo_ClientSimpleRequestBus::Events::LinkTwitch)
				->Event("LinkWindowsHello", &PlayFabCombo_ClientSimpleRequestBus::Events::LinkWindowsHello)
				->Event("RemoveGenericID", &PlayFabCombo_ClientSimpleRequestBus::Events::RemoveGenericID)
				->Event("ReportPlayer", &PlayFabCombo_ClientSimpleRequestBus::Events::ReportPlayer)
				->Event("SendAccountRecoveryEmail", &PlayFabCombo_ClientSimpleRequestBus::Events::SendAccountRecoveryEmail)
				->Event("UnlinkAndroidDeviceID", &PlayFabCombo_ClientSimpleRequestBus::Events::UnlinkAndroidDeviceID)
				->Event("UnlinkCustomID", &PlayFabCombo_ClientSimpleRequestBus::Events::UnlinkCustomID)
				->Event("UnlinkFacebookAccount", &PlayFabCombo_ClientSimpleRequestBus::Events::UnlinkFacebookAccount)
				->Event("UnlinkGameCenterAccount", &PlayFabCombo_ClientSimpleRequestBus::Events::UnlinkGameCenterAccount)
				->Event("UnlinkGoogleAccount", &PlayFabCombo_ClientSimpleRequestBus::Events::UnlinkGoogleAccount)
				->Event("UnlinkIOSDeviceID", &PlayFabCombo_ClientSimpleRequestBus::Events::UnlinkIOSDeviceID)
				->Event("UnlinkKongregate", &PlayFabCombo_ClientSimpleRequestBus::Events::UnlinkKongregate)
				->Event("UnlinkSteamAccount", &PlayFabCombo_ClientSimpleRequestBus::Events::UnlinkSteamAccount)
				->Event("UnlinkTwitch", &PlayFabCombo_ClientSimpleRequestBus::Events::UnlinkTwitch)
				->Event("UnlinkWindowsHello", &PlayFabCombo_ClientSimpleRequestBus::Events::UnlinkWindowsHello)
				->Event("UpdateAvatarUrl", &PlayFabCombo_ClientSimpleRequestBus::Events::UpdateAvatarUrl)
				->Event("UpdateUserTitleDisplayName", &PlayFabCombo_ClientSimpleRequestBus::Events::UpdateUserTitleDisplayName)
				->Event("GetFriendLeaderboard", &PlayFabCombo_ClientSimpleRequestBus::Events::GetFriendLeaderboard)
				->Event("GetFriendLeaderboardAroundPlayer", &PlayFabCombo_ClientSimpleRequestBus::Events::GetFriendLeaderboardAroundPlayer)
				->Event("GetLeaderboard", &PlayFabCombo_ClientSimpleRequestBus::Events::GetLeaderboard)
				->Event("GetLeaderboardAroundPlayer", &PlayFabCombo_ClientSimpleRequestBus::Events::GetLeaderboardAroundPlayer)
				->Event("GetPlayerStatistics", &PlayFabCombo_ClientSimpleRequestBus::Events::GetPlayerStatistics)
				->Event("GetPlayerStatisticVersions", &PlayFabCombo_ClientSimpleRequestBus::Events::GetPlayerStatisticVersions)
				->Event("GetUserData", &PlayFabCombo_ClientSimpleRequestBus::Events::GetUserData)
				->Event("GetUserPublisherData", &PlayFabCombo_ClientSimpleRequestBus::Events::GetUserPublisherData)
				->Event("GetUserPublisherReadOnlyData", &PlayFabCombo_ClientSimpleRequestBus::Events::GetUserPublisherReadOnlyData)
				->Event("GetUserReadOnlyData", &PlayFabCombo_ClientSimpleRequestBus::Events::GetUserReadOnlyData)
				->Event("UpdatePlayerStatistics", &PlayFabCombo_ClientSimpleRequestBus::Events::UpdatePlayerStatistics)
				->Event("UpdateUserData", &PlayFabCombo_ClientSimpleRequestBus::Events::UpdateUserData)
				->Event("UpdateUserPublisherData", &PlayFabCombo_ClientSimpleRequestBus::Events::UpdateUserPublisherData)
				->Event("GetCatalogItems", &PlayFabCombo_ClientSimpleRequestBus::Events::GetCatalogItems)
				->Event("GetPublisherData", &PlayFabCombo_ClientSimpleRequestBus::Events::GetPublisherData)
				->Event("GetStoreItems", &PlayFabCombo_ClientSimpleRequestBus::Events::GetStoreItems)
				->Event("GetTime", &PlayFabCombo_ClientSimpleRequestBus::Events::GetTime)
				->Event("GetTitleData", &PlayFabCombo_ClientSimpleRequestBus::Events::GetTitleData)
				->Event("GetTitleNews", &PlayFabCombo_ClientSimpleRequestBus::Events::GetTitleNews)
				->Event("AddUserVirtualCurrency", &PlayFabCombo_ClientSimpleRequestBus::Events::AddUserVirtualCurrency)
				->Event("ConfirmPurchase", &PlayFabCombo_ClientSimpleRequestBus::Events::ConfirmPurchase)
				->Event("ConsumeItem", &PlayFabCombo_ClientSimpleRequestBus::Events::ConsumeItem)
				->Event("GetCharacterInventory", &PlayFabCombo_ClientSimpleRequestBus::Events::GetCharacterInventory)
				->Event("GetPurchase", &PlayFabCombo_ClientSimpleRequestBus::Events::GetPurchase)
				->Event("GetUserInventory", &PlayFabCombo_ClientSimpleRequestBus::Events::GetUserInventory)
				->Event("PayForPurchase", &PlayFabCombo_ClientSimpleRequestBus::Events::PayForPurchase)
				->Event("PurchaseItem", &PlayFabCombo_ClientSimpleRequestBus::Events::PurchaseItem)
				->Event("RedeemCoupon", &PlayFabCombo_ClientSimpleRequestBus::Events::RedeemCoupon)
				->Event("StartPurchase", &PlayFabCombo_ClientSimpleRequestBus::Events::StartPurchase)
				->Event("SubtractUserVirtualCurrency", &PlayFabCombo_ClientSimpleRequestBus::Events::SubtractUserVirtualCurrency)
				->Event("UnlockContainerInstance", &PlayFabCombo_ClientSimpleRequestBus::Events::UnlockContainerInstance)
				->Event("UnlockContainerItem", &PlayFabCombo_ClientSimpleRequestBus::Events::UnlockContainerItem)
				->Event("AddFriend", &PlayFabCombo_ClientSimpleRequestBus::Events::AddFriend)
				->Event("GetFriendsList", &PlayFabCombo_ClientSimpleRequestBus::Events::GetFriendsList)
				->Event("RemoveFriend", &PlayFabCombo_ClientSimpleRequestBus::Events::RemoveFriend)
				->Event("SetFriendTags", &PlayFabCombo_ClientSimpleRequestBus::Events::SetFriendTags)
				->Event("GetCurrentGames", &PlayFabCombo_ClientSimpleRequestBus::Events::GetCurrentGames)
				->Event("GetGameServerRegions", &PlayFabCombo_ClientSimpleRequestBus::Events::GetGameServerRegions)
				->Event("Matchmake", &PlayFabCombo_ClientSimpleRequestBus::Events::Matchmake)
				->Event("StartGame", &PlayFabCombo_ClientSimpleRequestBus::Events::StartGame)
				->Event("WriteCharacterEvent", &PlayFabCombo_ClientSimpleRequestBus::Events::WriteCharacterEvent)
				->Event("WritePlayerEvent", &PlayFabCombo_ClientSimpleRequestBus::Events::WritePlayerEvent)
				->Event("WriteTitleEvent", &PlayFabCombo_ClientSimpleRequestBus::Events::WriteTitleEvent)
				->Event("AddSharedGroupMembers", &PlayFabCombo_ClientSimpleRequestBus::Events::AddSharedGroupMembers)
				->Event("CreateSharedGroup", &PlayFabCombo_ClientSimpleRequestBus::Events::CreateSharedGroup)
				->Event("GetSharedGroupData", &PlayFabCombo_ClientSimpleRequestBus::Events::GetSharedGroupData)
				->Event("RemoveSharedGroupMembers", &PlayFabCombo_ClientSimpleRequestBus::Events::RemoveSharedGroupMembers)
				->Event("UpdateSharedGroupData", &PlayFabCombo_ClientSimpleRequestBus::Events::UpdateSharedGroupData)
				->Event("ExecuteCloudScript", &PlayFabCombo_ClientSimpleRequestBus::Events::ExecuteCloudScript)
				->Event("GetContentDownloadUrl", &PlayFabCombo_ClientSimpleRequestBus::Events::GetContentDownloadUrl)
				->Event("GetAllUsersCharacters", &PlayFabCombo_ClientSimpleRequestBus::Events::GetAllUsersCharacters)
				->Event("GetCharacterLeaderboard", &PlayFabCombo_ClientSimpleRequestBus::Events::GetCharacterLeaderboard)
				->Event("GetCharacterStatistics", &PlayFabCombo_ClientSimpleRequestBus::Events::GetCharacterStatistics)
				->Event("GetLeaderboardAroundCharacter", &PlayFabCombo_ClientSimpleRequestBus::Events::GetLeaderboardAroundCharacter)
				->Event("GetLeaderboardForUserCharacters", &PlayFabCombo_ClientSimpleRequestBus::Events::GetLeaderboardForUserCharacters)
				->Event("GrantCharacterToUser", &PlayFabCombo_ClientSimpleRequestBus::Events::GrantCharacterToUser)
				->Event("UpdateCharacterStatistics", &PlayFabCombo_ClientSimpleRequestBus::Events::UpdateCharacterStatistics)
				->Event("GetCharacterData", &PlayFabCombo_ClientSimpleRequestBus::Events::GetCharacterData)
				->Event("GetCharacterReadOnlyData", &PlayFabCombo_ClientSimpleRequestBus::Events::GetCharacterReadOnlyData)
				->Event("UpdateCharacterData", &PlayFabCombo_ClientSimpleRequestBus::Events::UpdateCharacterData)
				->Event("AcceptTrade", &PlayFabCombo_ClientSimpleRequestBus::Events::AcceptTrade)
				->Event("CancelTrade", &PlayFabCombo_ClientSimpleRequestBus::Events::CancelTrade)
				->Event("GetPlayerTrades", &PlayFabCombo_ClientSimpleRequestBus::Events::GetPlayerTrades)
				->Event("GetTradeStatus", &PlayFabCombo_ClientSimpleRequestBus::Events::GetTradeStatus)
				->Event("OpenTrade", &PlayFabCombo_ClientSimpleRequestBus::Events::OpenTrade)
				->Event("AttributeInstall", &PlayFabCombo_ClientSimpleRequestBus::Events::AttributeInstall)
				->Event("GetPlayerSegments", &PlayFabCombo_ClientSimpleRequestBus::Events::GetPlayerSegments)
				->Event("GetPlayerTags", &PlayFabCombo_ClientSimpleRequestBus::Events::GetPlayerTags)
				->Event("AndroidDevicePushNotificationRegistration", &PlayFabCombo_ClientSimpleRequestBus::Events::AndroidDevicePushNotificationRegistration)
				->Event("RegisterForIOSPushNotification", &PlayFabCombo_ClientSimpleRequestBus::Events::RegisterForIOSPushNotification)
				->Event("RestoreIOSPurchases", &PlayFabCombo_ClientSimpleRequestBus::Events::RestoreIOSPurchases)
				->Event("ValidateAmazonIAPReceipt", &PlayFabCombo_ClientSimpleRequestBus::Events::ValidateAmazonIAPReceipt)
				->Event("ValidateGooglePlayPurchase", &PlayFabCombo_ClientSimpleRequestBus::Events::ValidateGooglePlayPurchase)
				->Event("ValidateIOSReceipt", &PlayFabCombo_ClientSimpleRequestBus::Events::ValidateIOSReceipt)
				->Event("ValidateWindowsStoreReceipt", &PlayFabCombo_ClientSimpleRequestBus::Events::ValidateWindowsStoreReceipt);

			// Reflect the ADDRESSED notification bus: (uses the BehaviorBusHandler declared at the beginning of this file)
			behaviorContext->EBus<PlayFabCombo_ClientNotificationBus>("PlayFabClientNotificationBus")
				->Handler<PlayFabCombo_ClientBehaviorBusHandler>();

			// Reflect the GLOBAL notification bus: (uses the BehaviorBusHandler declared at the beginning of this file)
			behaviorContext->EBus<PlayFabCombo_ClientGlobalNotificationBus>("PlayFabClientGlobalNotificationBus")
				->Handler<PlayFabCombo_ClientGlobalBehaviorBusHandler>();                
			
            //-----------------------------------------------------------------------------------------------------
			// Reflect enum values
            //-----------------------------------------------------------------------------------------------------
	        behaviorContext 
                ->Enum<ClientModels::TradeStatus::TradeStatusInvalid>( "PlayFabClient_TradeStatus_Invalid" )
                ->Enum<ClientModels::TradeStatus::TradeStatusOpening>( "PlayFabClient_TradeStatus_Opening" )
                ->Enum<ClientModels::TradeStatus::TradeStatusOpen>( "PlayFabClient_TradeStatus_Open" )
                ->Enum<ClientModels::TradeStatus::TradeStatusAccepting>( "PlayFabClient_TradeStatus_Accepting" )
                ->Enum<ClientModels::TradeStatus::TradeStatusAccepted>( "PlayFabClient_TradeStatus_Accepted" )
                ->Enum<ClientModels::TradeStatus::TradeStatusFilled>( "PlayFabClient_TradeStatus_Filled" )
                ->Enum<ClientModels::TradeStatus::TradeStatusCancelled>( "PlayFabClient_TradeStatus_Cancelled" )
            ;
            behaviorContext 
                ->Enum<ClientModels::CloudScriptRevisionOption::CloudScriptRevisionOptionLive>( "PlayFabClient_CloudScriptRevisionOption_Live" )
                ->Enum<ClientModels::CloudScriptRevisionOption::CloudScriptRevisionOptionLatest>( "PlayFabClient_CloudScriptRevisionOption_Latest" )
                ->Enum<ClientModels::CloudScriptRevisionOption::CloudScriptRevisionOptionSpecific>( "PlayFabClient_CloudScriptRevisionOption_Specific" )
            ;
            behaviorContext 
                ->Enum<ClientModels::ContinentCode::ContinentCodeAF>( "PlayFabClient_ContinentCode_AF" )
                ->Enum<ClientModels::ContinentCode::ContinentCodeAN>( "PlayFabClient_ContinentCode_AN" )
                ->Enum<ClientModels::ContinentCode::ContinentCodeAS>( "PlayFabClient_ContinentCode_AS" )
                ->Enum<ClientModels::ContinentCode::ContinentCodeEU>( "PlayFabClient_ContinentCode_EU" )
                ->Enum<ClientModels::ContinentCode::ContinentCodeNA>( "PlayFabClient_ContinentCode_NA" )
                ->Enum<ClientModels::ContinentCode::ContinentCodeOC>( "PlayFabClient_ContinentCode_OC" )
                ->Enum<ClientModels::ContinentCode::ContinentCodeSA>( "PlayFabClient_ContinentCode_SA" )
            ;
            behaviorContext 
                ->Enum<ClientModels::CountryCode::CountryCodeAF>( "PlayFabClient_CountryCode_AF" )
                ->Enum<ClientModels::CountryCode::CountryCodeAX>( "PlayFabClient_CountryCode_AX" )
                ->Enum<ClientModels::CountryCode::CountryCodeAL>( "PlayFabClient_CountryCode_AL" )
                ->Enum<ClientModels::CountryCode::CountryCodeDZ>( "PlayFabClient_CountryCode_DZ" )
                ->Enum<ClientModels::CountryCode::CountryCodeAS>( "PlayFabClient_CountryCode_AS" )
                ->Enum<ClientModels::CountryCode::CountryCodeAD>( "PlayFabClient_CountryCode_AD" )
                ->Enum<ClientModels::CountryCode::CountryCodeAO>( "PlayFabClient_CountryCode_AO" )
                ->Enum<ClientModels::CountryCode::CountryCodeAI>( "PlayFabClient_CountryCode_AI" )
                ->Enum<ClientModels::CountryCode::CountryCodeAQ>( "PlayFabClient_CountryCode_AQ" )
                ->Enum<ClientModels::CountryCode::CountryCodeAG>( "PlayFabClient_CountryCode_AG" )
                ->Enum<ClientModels::CountryCode::CountryCodeAR>( "PlayFabClient_CountryCode_AR" )
                ->Enum<ClientModels::CountryCode::CountryCodeAM>( "PlayFabClient_CountryCode_AM" )
                ->Enum<ClientModels::CountryCode::CountryCodeAW>( "PlayFabClient_CountryCode_AW" )
                ->Enum<ClientModels::CountryCode::CountryCodeAU>( "PlayFabClient_CountryCode_AU" )
                ->Enum<ClientModels::CountryCode::CountryCodeAT>( "PlayFabClient_CountryCode_AT" )
                ->Enum<ClientModels::CountryCode::CountryCodeAZ>( "PlayFabClient_CountryCode_AZ" )
                ->Enum<ClientModels::CountryCode::CountryCodeBS>( "PlayFabClient_CountryCode_BS" )
                ->Enum<ClientModels::CountryCode::CountryCodeBH>( "PlayFabClient_CountryCode_BH" )
                ->Enum<ClientModels::CountryCode::CountryCodeBD>( "PlayFabClient_CountryCode_BD" )
                ->Enum<ClientModels::CountryCode::CountryCodeBB>( "PlayFabClient_CountryCode_BB" )
                ->Enum<ClientModels::CountryCode::CountryCodeBY>( "PlayFabClient_CountryCode_BY" )
                ->Enum<ClientModels::CountryCode::CountryCodeBE>( "PlayFabClient_CountryCode_BE" )
                ->Enum<ClientModels::CountryCode::CountryCodeBZ>( "PlayFabClient_CountryCode_BZ" )
                ->Enum<ClientModels::CountryCode::CountryCodeBJ>( "PlayFabClient_CountryCode_BJ" )
                ->Enum<ClientModels::CountryCode::CountryCodeBM>( "PlayFabClient_CountryCode_BM" )
                ->Enum<ClientModels::CountryCode::CountryCodeBT>( "PlayFabClient_CountryCode_BT" )
                ->Enum<ClientModels::CountryCode::CountryCodeBO>( "PlayFabClient_CountryCode_BO" )
                ->Enum<ClientModels::CountryCode::CountryCodeBQ>( "PlayFabClient_CountryCode_BQ" )
                ->Enum<ClientModels::CountryCode::CountryCodeBA>( "PlayFabClient_CountryCode_BA" )
                ->Enum<ClientModels::CountryCode::CountryCodeBW>( "PlayFabClient_CountryCode_BW" )
                ->Enum<ClientModels::CountryCode::CountryCodeBV>( "PlayFabClient_CountryCode_BV" )
                ->Enum<ClientModels::CountryCode::CountryCodeBR>( "PlayFabClient_CountryCode_BR" )
                ->Enum<ClientModels::CountryCode::CountryCodeIO>( "PlayFabClient_CountryCode_IO" )
                ->Enum<ClientModels::CountryCode::CountryCodeBN>( "PlayFabClient_CountryCode_BN" )
                ->Enum<ClientModels::CountryCode::CountryCodeBG>( "PlayFabClient_CountryCode_BG" )
                ->Enum<ClientModels::CountryCode::CountryCodeBF>( "PlayFabClient_CountryCode_BF" )
                ->Enum<ClientModels::CountryCode::CountryCodeBI>( "PlayFabClient_CountryCode_BI" )
                ->Enum<ClientModels::CountryCode::CountryCodeKH>( "PlayFabClient_CountryCode_KH" )
                ->Enum<ClientModels::CountryCode::CountryCodeCM>( "PlayFabClient_CountryCode_CM" )
                ->Enum<ClientModels::CountryCode::CountryCodeCA>( "PlayFabClient_CountryCode_CA" )
                ->Enum<ClientModels::CountryCode::CountryCodeCV>( "PlayFabClient_CountryCode_CV" )
                ->Enum<ClientModels::CountryCode::CountryCodeKY>( "PlayFabClient_CountryCode_KY" )
                ->Enum<ClientModels::CountryCode::CountryCodeCF>( "PlayFabClient_CountryCode_CF" )
                ->Enum<ClientModels::CountryCode::CountryCodeTD>( "PlayFabClient_CountryCode_TD" )
                ->Enum<ClientModels::CountryCode::CountryCodeCL>( "PlayFabClient_CountryCode_CL" )
                ->Enum<ClientModels::CountryCode::CountryCodeCN>( "PlayFabClient_CountryCode_CN" )
                ->Enum<ClientModels::CountryCode::CountryCodeCX>( "PlayFabClient_CountryCode_CX" )
                ->Enum<ClientModels::CountryCode::CountryCodeCC>( "PlayFabClient_CountryCode_CC" )
                ->Enum<ClientModels::CountryCode::CountryCodeCO>( "PlayFabClient_CountryCode_CO" )
                ->Enum<ClientModels::CountryCode::CountryCodeKM>( "PlayFabClient_CountryCode_KM" )
                ->Enum<ClientModels::CountryCode::CountryCodeCG>( "PlayFabClient_CountryCode_CG" )
                ->Enum<ClientModels::CountryCode::CountryCodeCD>( "PlayFabClient_CountryCode_CD" )
                ->Enum<ClientModels::CountryCode::CountryCodeCK>( "PlayFabClient_CountryCode_CK" )
                ->Enum<ClientModels::CountryCode::CountryCodeCR>( "PlayFabClient_CountryCode_CR" )
                ->Enum<ClientModels::CountryCode::CountryCodeCI>( "PlayFabClient_CountryCode_CI" )
                ->Enum<ClientModels::CountryCode::CountryCodeHR>( "PlayFabClient_CountryCode_HR" )
                ->Enum<ClientModels::CountryCode::CountryCodeCU>( "PlayFabClient_CountryCode_CU" )
                ->Enum<ClientModels::CountryCode::CountryCodeCW>( "PlayFabClient_CountryCode_CW" )
                ->Enum<ClientModels::CountryCode::CountryCodeCY>( "PlayFabClient_CountryCode_CY" )
                ->Enum<ClientModels::CountryCode::CountryCodeCZ>( "PlayFabClient_CountryCode_CZ" )
                ->Enum<ClientModels::CountryCode::CountryCodeDK>( "PlayFabClient_CountryCode_DK" )
                ->Enum<ClientModels::CountryCode::CountryCodeDJ>( "PlayFabClient_CountryCode_DJ" )
                ->Enum<ClientModels::CountryCode::CountryCodeDM>( "PlayFabClient_CountryCode_DM" )
                ->Enum<ClientModels::CountryCode::CountryCodeDO>( "PlayFabClient_CountryCode_DO" )
                ->Enum<ClientModels::CountryCode::CountryCodeEC>( "PlayFabClient_CountryCode_EC" )
                ->Enum<ClientModels::CountryCode::CountryCodeEG>( "PlayFabClient_CountryCode_EG" )
                ->Enum<ClientModels::CountryCode::CountryCodeSV>( "PlayFabClient_CountryCode_SV" )
                ->Enum<ClientModels::CountryCode::CountryCodeGQ>( "PlayFabClient_CountryCode_GQ" )
                ->Enum<ClientModels::CountryCode::CountryCodeER>( "PlayFabClient_CountryCode_ER" )
                ->Enum<ClientModels::CountryCode::CountryCodeEE>( "PlayFabClient_CountryCode_EE" )
                ->Enum<ClientModels::CountryCode::CountryCodeET>( "PlayFabClient_CountryCode_ET" )
                ->Enum<ClientModels::CountryCode::CountryCodeFK>( "PlayFabClient_CountryCode_FK" )
                ->Enum<ClientModels::CountryCode::CountryCodeFO>( "PlayFabClient_CountryCode_FO" )
                ->Enum<ClientModels::CountryCode::CountryCodeFJ>( "PlayFabClient_CountryCode_FJ" )
                ->Enum<ClientModels::CountryCode::CountryCodeFI>( "PlayFabClient_CountryCode_FI" )
                ->Enum<ClientModels::CountryCode::CountryCodeFR>( "PlayFabClient_CountryCode_FR" )
                ->Enum<ClientModels::CountryCode::CountryCodeGF>( "PlayFabClient_CountryCode_GF" )
                ->Enum<ClientModels::CountryCode::CountryCodePF>( "PlayFabClient_CountryCode_PF" )
                ->Enum<ClientModels::CountryCode::CountryCodeTF>( "PlayFabClient_CountryCode_TF" )
                ->Enum<ClientModels::CountryCode::CountryCodeGA>( "PlayFabClient_CountryCode_GA" )
                ->Enum<ClientModels::CountryCode::CountryCodeGM>( "PlayFabClient_CountryCode_GM" )
                ->Enum<ClientModels::CountryCode::CountryCodeGE>( "PlayFabClient_CountryCode_GE" )
                ->Enum<ClientModels::CountryCode::CountryCodeDE>( "PlayFabClient_CountryCode_DE" )
                ->Enum<ClientModels::CountryCode::CountryCodeGH>( "PlayFabClient_CountryCode_GH" )
                ->Enum<ClientModels::CountryCode::CountryCodeGI>( "PlayFabClient_CountryCode_GI" )
                ->Enum<ClientModels::CountryCode::CountryCodeGR>( "PlayFabClient_CountryCode_GR" )
                ->Enum<ClientModels::CountryCode::CountryCodeGL>( "PlayFabClient_CountryCode_GL" )
                ->Enum<ClientModels::CountryCode::CountryCodeGD>( "PlayFabClient_CountryCode_GD" )
                ->Enum<ClientModels::CountryCode::CountryCodeGP>( "PlayFabClient_CountryCode_GP" )
                ->Enum<ClientModels::CountryCode::CountryCodeGU>( "PlayFabClient_CountryCode_GU" )
                ->Enum<ClientModels::CountryCode::CountryCodeGT>( "PlayFabClient_CountryCode_GT" )
                ->Enum<ClientModels::CountryCode::CountryCodeGG>( "PlayFabClient_CountryCode_GG" )
                ->Enum<ClientModels::CountryCode::CountryCodeGN>( "PlayFabClient_CountryCode_GN" )
                ->Enum<ClientModels::CountryCode::CountryCodeGW>( "PlayFabClient_CountryCode_GW" )
                ->Enum<ClientModels::CountryCode::CountryCodeGY>( "PlayFabClient_CountryCode_GY" )
                ->Enum<ClientModels::CountryCode::CountryCodeHT>( "PlayFabClient_CountryCode_HT" )
                ->Enum<ClientModels::CountryCode::CountryCodeHM>( "PlayFabClient_CountryCode_HM" )
                ->Enum<ClientModels::CountryCode::CountryCodeVA>( "PlayFabClient_CountryCode_VA" )
                ->Enum<ClientModels::CountryCode::CountryCodeHN>( "PlayFabClient_CountryCode_HN" )
                ->Enum<ClientModels::CountryCode::CountryCodeHK>( "PlayFabClient_CountryCode_HK" )
                ->Enum<ClientModels::CountryCode::CountryCodeHU>( "PlayFabClient_CountryCode_HU" )
                ->Enum<ClientModels::CountryCode::CountryCodeIS>( "PlayFabClient_CountryCode_IS" )
                ->Enum<ClientModels::CountryCode::CountryCodeIN>( "PlayFabClient_CountryCode_IN" )
                ->Enum<ClientModels::CountryCode::CountryCodeID>( "PlayFabClient_CountryCode_ID" )
                ->Enum<ClientModels::CountryCode::CountryCodeIR>( "PlayFabClient_CountryCode_IR" )
                ->Enum<ClientModels::CountryCode::CountryCodeIQ>( "PlayFabClient_CountryCode_IQ" )
                ->Enum<ClientModels::CountryCode::CountryCodeIE>( "PlayFabClient_CountryCode_IE" )
                ->Enum<ClientModels::CountryCode::CountryCodeIM>( "PlayFabClient_CountryCode_IM" )
                ->Enum<ClientModels::CountryCode::CountryCodeIL>( "PlayFabClient_CountryCode_IL" )
                ->Enum<ClientModels::CountryCode::CountryCodeIT>( "PlayFabClient_CountryCode_IT" )
                ->Enum<ClientModels::CountryCode::CountryCodeJM>( "PlayFabClient_CountryCode_JM" )
                ->Enum<ClientModels::CountryCode::CountryCodeJP>( "PlayFabClient_CountryCode_JP" )
                ->Enum<ClientModels::CountryCode::CountryCodeJE>( "PlayFabClient_CountryCode_JE" )
                ->Enum<ClientModels::CountryCode::CountryCodeJO>( "PlayFabClient_CountryCode_JO" )
                ->Enum<ClientModels::CountryCode::CountryCodeKZ>( "PlayFabClient_CountryCode_KZ" )
                ->Enum<ClientModels::CountryCode::CountryCodeKE>( "PlayFabClient_CountryCode_KE" )
                ->Enum<ClientModels::CountryCode::CountryCodeKI>( "PlayFabClient_CountryCode_KI" )
                ->Enum<ClientModels::CountryCode::CountryCodeKP>( "PlayFabClient_CountryCode_KP" )
                ->Enum<ClientModels::CountryCode::CountryCodeKR>( "PlayFabClient_CountryCode_KR" )
                ->Enum<ClientModels::CountryCode::CountryCodeKW>( "PlayFabClient_CountryCode_KW" )
                ->Enum<ClientModels::CountryCode::CountryCodeKG>( "PlayFabClient_CountryCode_KG" )
                ->Enum<ClientModels::CountryCode::CountryCodeLA>( "PlayFabClient_CountryCode_LA" )
                ->Enum<ClientModels::CountryCode::CountryCodeLV>( "PlayFabClient_CountryCode_LV" )
                ->Enum<ClientModels::CountryCode::CountryCodeLB>( "PlayFabClient_CountryCode_LB" )
                ->Enum<ClientModels::CountryCode::CountryCodeLS>( "PlayFabClient_CountryCode_LS" )
                ->Enum<ClientModels::CountryCode::CountryCodeLR>( "PlayFabClient_CountryCode_LR" )
                ->Enum<ClientModels::CountryCode::CountryCodeLY>( "PlayFabClient_CountryCode_LY" )
                ->Enum<ClientModels::CountryCode::CountryCodeLI>( "PlayFabClient_CountryCode_LI" )
                ->Enum<ClientModels::CountryCode::CountryCodeLT>( "PlayFabClient_CountryCode_LT" )
                ->Enum<ClientModels::CountryCode::CountryCodeLU>( "PlayFabClient_CountryCode_LU" )
                ->Enum<ClientModels::CountryCode::CountryCodeMO>( "PlayFabClient_CountryCode_MO" )
                ->Enum<ClientModels::CountryCode::CountryCodeMK>( "PlayFabClient_CountryCode_MK" )
                ->Enum<ClientModels::CountryCode::CountryCodeMG>( "PlayFabClient_CountryCode_MG" )
                ->Enum<ClientModels::CountryCode::CountryCodeMW>( "PlayFabClient_CountryCode_MW" )
                ->Enum<ClientModels::CountryCode::CountryCodeMY>( "PlayFabClient_CountryCode_MY" )
                ->Enum<ClientModels::CountryCode::CountryCodeMV>( "PlayFabClient_CountryCode_MV" )
                ->Enum<ClientModels::CountryCode::CountryCodeML>( "PlayFabClient_CountryCode_ML" )
                ->Enum<ClientModels::CountryCode::CountryCodeMT>( "PlayFabClient_CountryCode_MT" )
                ->Enum<ClientModels::CountryCode::CountryCodeMH>( "PlayFabClient_CountryCode_MH" )
                ->Enum<ClientModels::CountryCode::CountryCodeMQ>( "PlayFabClient_CountryCode_MQ" )
                ->Enum<ClientModels::CountryCode::CountryCodeMR>( "PlayFabClient_CountryCode_MR" )
                ->Enum<ClientModels::CountryCode::CountryCodeMU>( "PlayFabClient_CountryCode_MU" )
                ->Enum<ClientModels::CountryCode::CountryCodeYT>( "PlayFabClient_CountryCode_YT" )
                ->Enum<ClientModels::CountryCode::CountryCodeMX>( "PlayFabClient_CountryCode_MX" )
                ->Enum<ClientModels::CountryCode::CountryCodeFM>( "PlayFabClient_CountryCode_FM" )
                ->Enum<ClientModels::CountryCode::CountryCodeMD>( "PlayFabClient_CountryCode_MD" )
                ->Enum<ClientModels::CountryCode::CountryCodeMC>( "PlayFabClient_CountryCode_MC" )
                ->Enum<ClientModels::CountryCode::CountryCodeMN>( "PlayFabClient_CountryCode_MN" )
                ->Enum<ClientModels::CountryCode::CountryCodeME>( "PlayFabClient_CountryCode_ME" )
                ->Enum<ClientModels::CountryCode::CountryCodeMS>( "PlayFabClient_CountryCode_MS" )
                ->Enum<ClientModels::CountryCode::CountryCodeMA>( "PlayFabClient_CountryCode_MA" )
                ->Enum<ClientModels::CountryCode::CountryCodeMZ>( "PlayFabClient_CountryCode_MZ" )
                ->Enum<ClientModels::CountryCode::CountryCodeMM>( "PlayFabClient_CountryCode_MM" )
                ->Enum<ClientModels::CountryCode::CountryCodeNA>( "PlayFabClient_CountryCode_NA" )
                ->Enum<ClientModels::CountryCode::CountryCodeNR>( "PlayFabClient_CountryCode_NR" )
                ->Enum<ClientModels::CountryCode::CountryCodeNP>( "PlayFabClient_CountryCode_NP" )
                ->Enum<ClientModels::CountryCode::CountryCodeNL>( "PlayFabClient_CountryCode_NL" )
                ->Enum<ClientModels::CountryCode::CountryCodeNC>( "PlayFabClient_CountryCode_NC" )
                ->Enum<ClientModels::CountryCode::CountryCodeNZ>( "PlayFabClient_CountryCode_NZ" )
                ->Enum<ClientModels::CountryCode::CountryCodeNI>( "PlayFabClient_CountryCode_NI" )
                ->Enum<ClientModels::CountryCode::CountryCodeNE>( "PlayFabClient_CountryCode_NE" )
                ->Enum<ClientModels::CountryCode::CountryCodeNG>( "PlayFabClient_CountryCode_NG" )
                ->Enum<ClientModels::CountryCode::CountryCodeNU>( "PlayFabClient_CountryCode_NU" )
                ->Enum<ClientModels::CountryCode::CountryCodeNF>( "PlayFabClient_CountryCode_NF" )
                ->Enum<ClientModels::CountryCode::CountryCodeMP>( "PlayFabClient_CountryCode_MP" )
                ->Enum<ClientModels::CountryCode::CountryCodeNO>( "PlayFabClient_CountryCode_NO" )
                ->Enum<ClientModels::CountryCode::CountryCodeOM>( "PlayFabClient_CountryCode_OM" )
                ->Enum<ClientModels::CountryCode::CountryCodePK>( "PlayFabClient_CountryCode_PK" )
                ->Enum<ClientModels::CountryCode::CountryCodePW>( "PlayFabClient_CountryCode_PW" )
                ->Enum<ClientModels::CountryCode::CountryCodePS>( "PlayFabClient_CountryCode_PS" )
                ->Enum<ClientModels::CountryCode::CountryCodePA>( "PlayFabClient_CountryCode_PA" )
                ->Enum<ClientModels::CountryCode::CountryCodePG>( "PlayFabClient_CountryCode_PG" )
                ->Enum<ClientModels::CountryCode::CountryCodePY>( "PlayFabClient_CountryCode_PY" )
                ->Enum<ClientModels::CountryCode::CountryCodePE>( "PlayFabClient_CountryCode_PE" )
                ->Enum<ClientModels::CountryCode::CountryCodePH>( "PlayFabClient_CountryCode_PH" )
                ->Enum<ClientModels::CountryCode::CountryCodePN>( "PlayFabClient_CountryCode_PN" )
                ->Enum<ClientModels::CountryCode::CountryCodePL>( "PlayFabClient_CountryCode_PL" )
                ->Enum<ClientModels::CountryCode::CountryCodePT>( "PlayFabClient_CountryCode_PT" )
                ->Enum<ClientModels::CountryCode::CountryCodePR>( "PlayFabClient_CountryCode_PR" )
                ->Enum<ClientModels::CountryCode::CountryCodeQA>( "PlayFabClient_CountryCode_QA" )
                ->Enum<ClientModels::CountryCode::CountryCodeRE>( "PlayFabClient_CountryCode_RE" )
                ->Enum<ClientModels::CountryCode::CountryCodeRO>( "PlayFabClient_CountryCode_RO" )
                ->Enum<ClientModels::CountryCode::CountryCodeRU>( "PlayFabClient_CountryCode_RU" )
                ->Enum<ClientModels::CountryCode::CountryCodeRW>( "PlayFabClient_CountryCode_RW" )
                ->Enum<ClientModels::CountryCode::CountryCodeBL>( "PlayFabClient_CountryCode_BL" )
                ->Enum<ClientModels::CountryCode::CountryCodeSH>( "PlayFabClient_CountryCode_SH" )
                ->Enum<ClientModels::CountryCode::CountryCodeKN>( "PlayFabClient_CountryCode_KN" )
                ->Enum<ClientModels::CountryCode::CountryCodeLC>( "PlayFabClient_CountryCode_LC" )
                ->Enum<ClientModels::CountryCode::CountryCodeMF>( "PlayFabClient_CountryCode_MF" )
                ->Enum<ClientModels::CountryCode::CountryCodePM>( "PlayFabClient_CountryCode_PM" )
                ->Enum<ClientModels::CountryCode::CountryCodeVC>( "PlayFabClient_CountryCode_VC" )
                ->Enum<ClientModels::CountryCode::CountryCodeWS>( "PlayFabClient_CountryCode_WS" )
                ->Enum<ClientModels::CountryCode::CountryCodeSM>( "PlayFabClient_CountryCode_SM" )
                ->Enum<ClientModels::CountryCode::CountryCodeST>( "PlayFabClient_CountryCode_ST" )
                ->Enum<ClientModels::CountryCode::CountryCodeSA>( "PlayFabClient_CountryCode_SA" )
                ->Enum<ClientModels::CountryCode::CountryCodeSN>( "PlayFabClient_CountryCode_SN" )
                ->Enum<ClientModels::CountryCode::CountryCodeRS>( "PlayFabClient_CountryCode_RS" )
                ->Enum<ClientModels::CountryCode::CountryCodeSC>( "PlayFabClient_CountryCode_SC" )
                ->Enum<ClientModels::CountryCode::CountryCodeSL>( "PlayFabClient_CountryCode_SL" )
                ->Enum<ClientModels::CountryCode::CountryCodeSG>( "PlayFabClient_CountryCode_SG" )
                ->Enum<ClientModels::CountryCode::CountryCodeSX>( "PlayFabClient_CountryCode_SX" )
                ->Enum<ClientModels::CountryCode::CountryCodeSK>( "PlayFabClient_CountryCode_SK" )
                ->Enum<ClientModels::CountryCode::CountryCodeSI>( "PlayFabClient_CountryCode_SI" )
                ->Enum<ClientModels::CountryCode::CountryCodeSB>( "PlayFabClient_CountryCode_SB" )
                ->Enum<ClientModels::CountryCode::CountryCodeSO>( "PlayFabClient_CountryCode_SO" )
                ->Enum<ClientModels::CountryCode::CountryCodeZA>( "PlayFabClient_CountryCode_ZA" )
                ->Enum<ClientModels::CountryCode::CountryCodeGS>( "PlayFabClient_CountryCode_GS" )
                ->Enum<ClientModels::CountryCode::CountryCodeSS>( "PlayFabClient_CountryCode_SS" )
                ->Enum<ClientModels::CountryCode::CountryCodeES>( "PlayFabClient_CountryCode_ES" )
                ->Enum<ClientModels::CountryCode::CountryCodeLK>( "PlayFabClient_CountryCode_LK" )
                ->Enum<ClientModels::CountryCode::CountryCodeSD>( "PlayFabClient_CountryCode_SD" )
                ->Enum<ClientModels::CountryCode::CountryCodeSR>( "PlayFabClient_CountryCode_SR" )
                ->Enum<ClientModels::CountryCode::CountryCodeSJ>( "PlayFabClient_CountryCode_SJ" )
                ->Enum<ClientModels::CountryCode::CountryCodeSZ>( "PlayFabClient_CountryCode_SZ" )
                ->Enum<ClientModels::CountryCode::CountryCodeSE>( "PlayFabClient_CountryCode_SE" )
                ->Enum<ClientModels::CountryCode::CountryCodeCH>( "PlayFabClient_CountryCode_CH" )
                ->Enum<ClientModels::CountryCode::CountryCodeSY>( "PlayFabClient_CountryCode_SY" )
                ->Enum<ClientModels::CountryCode::CountryCodeTW>( "PlayFabClient_CountryCode_TW" )
                ->Enum<ClientModels::CountryCode::CountryCodeTJ>( "PlayFabClient_CountryCode_TJ" )
                ->Enum<ClientModels::CountryCode::CountryCodeTZ>( "PlayFabClient_CountryCode_TZ" )
                ->Enum<ClientModels::CountryCode::CountryCodeTH>( "PlayFabClient_CountryCode_TH" )
                ->Enum<ClientModels::CountryCode::CountryCodeTL>( "PlayFabClient_CountryCode_TL" )
                ->Enum<ClientModels::CountryCode::CountryCodeTG>( "PlayFabClient_CountryCode_TG" )
                ->Enum<ClientModels::CountryCode::CountryCodeTK>( "PlayFabClient_CountryCode_TK" )
                ->Enum<ClientModels::CountryCode::CountryCodeTO>( "PlayFabClient_CountryCode_TO" )
                ->Enum<ClientModels::CountryCode::CountryCodeTT>( "PlayFabClient_CountryCode_TT" )
                ->Enum<ClientModels::CountryCode::CountryCodeTN>( "PlayFabClient_CountryCode_TN" )
                ->Enum<ClientModels::CountryCode::CountryCodeTR>( "PlayFabClient_CountryCode_TR" )
                ->Enum<ClientModels::CountryCode::CountryCodeTM>( "PlayFabClient_CountryCode_TM" )
                ->Enum<ClientModels::CountryCode::CountryCodeTC>( "PlayFabClient_CountryCode_TC" )
                ->Enum<ClientModels::CountryCode::CountryCodeTV>( "PlayFabClient_CountryCode_TV" )
                ->Enum<ClientModels::CountryCode::CountryCodeUG>( "PlayFabClient_CountryCode_UG" )
                ->Enum<ClientModels::CountryCode::CountryCodeUA>( "PlayFabClient_CountryCode_UA" )
                ->Enum<ClientModels::CountryCode::CountryCodeAE>( "PlayFabClient_CountryCode_AE" )
                ->Enum<ClientModels::CountryCode::CountryCodeGB>( "PlayFabClient_CountryCode_GB" )
                ->Enum<ClientModels::CountryCode::CountryCodeUS>( "PlayFabClient_CountryCode_US" )
                ->Enum<ClientModels::CountryCode::CountryCodeUM>( "PlayFabClient_CountryCode_UM" )
                ->Enum<ClientModels::CountryCode::CountryCodeUY>( "PlayFabClient_CountryCode_UY" )
                ->Enum<ClientModels::CountryCode::CountryCodeUZ>( "PlayFabClient_CountryCode_UZ" )
                ->Enum<ClientModels::CountryCode::CountryCodeVU>( "PlayFabClient_CountryCode_VU" )
                ->Enum<ClientModels::CountryCode::CountryCodeVE>( "PlayFabClient_CountryCode_VE" )
                ->Enum<ClientModels::CountryCode::CountryCodeVN>( "PlayFabClient_CountryCode_VN" )
                ->Enum<ClientModels::CountryCode::CountryCodeVG>( "PlayFabClient_CountryCode_VG" )
                ->Enum<ClientModels::CountryCode::CountryCodeVI>( "PlayFabClient_CountryCode_VI" )
                ->Enum<ClientModels::CountryCode::CountryCodeWF>( "PlayFabClient_CountryCode_WF" )
                ->Enum<ClientModels::CountryCode::CountryCodeEH>( "PlayFabClient_CountryCode_EH" )
                ->Enum<ClientModels::CountryCode::CountryCodeYE>( "PlayFabClient_CountryCode_YE" )
                ->Enum<ClientModels::CountryCode::CountryCodeZM>( "PlayFabClient_CountryCode_ZM" )
                ->Enum<ClientModels::CountryCode::CountryCodeZW>( "PlayFabClient_CountryCode_ZW" )
            ;
            behaviorContext 
                ->Enum<ClientModels::Currency::CurrencyAED>( "PlayFabClient_Currency_AED" )
                ->Enum<ClientModels::Currency::CurrencyAFN>( "PlayFabClient_Currency_AFN" )
                ->Enum<ClientModels::Currency::CurrencyALL>( "PlayFabClient_Currency_ALL" )
                ->Enum<ClientModels::Currency::CurrencyAMD>( "PlayFabClient_Currency_AMD" )
                ->Enum<ClientModels::Currency::CurrencyANG>( "PlayFabClient_Currency_ANG" )
                ->Enum<ClientModels::Currency::CurrencyAOA>( "PlayFabClient_Currency_AOA" )
                ->Enum<ClientModels::Currency::CurrencyARS>( "PlayFabClient_Currency_ARS" )
                ->Enum<ClientModels::Currency::CurrencyAUD>( "PlayFabClient_Currency_AUD" )
                ->Enum<ClientModels::Currency::CurrencyAWG>( "PlayFabClient_Currency_AWG" )
                ->Enum<ClientModels::Currency::CurrencyAZN>( "PlayFabClient_Currency_AZN" )
                ->Enum<ClientModels::Currency::CurrencyBAM>( "PlayFabClient_Currency_BAM" )
                ->Enum<ClientModels::Currency::CurrencyBBD>( "PlayFabClient_Currency_BBD" )
                ->Enum<ClientModels::Currency::CurrencyBDT>( "PlayFabClient_Currency_BDT" )
                ->Enum<ClientModels::Currency::CurrencyBGN>( "PlayFabClient_Currency_BGN" )
                ->Enum<ClientModels::Currency::CurrencyBHD>( "PlayFabClient_Currency_BHD" )
                ->Enum<ClientModels::Currency::CurrencyBIF>( "PlayFabClient_Currency_BIF" )
                ->Enum<ClientModels::Currency::CurrencyBMD>( "PlayFabClient_Currency_BMD" )
                ->Enum<ClientModels::Currency::CurrencyBND>( "PlayFabClient_Currency_BND" )
                ->Enum<ClientModels::Currency::CurrencyBOB>( "PlayFabClient_Currency_BOB" )
                ->Enum<ClientModels::Currency::CurrencyBRL>( "PlayFabClient_Currency_BRL" )
                ->Enum<ClientModels::Currency::CurrencyBSD>( "PlayFabClient_Currency_BSD" )
                ->Enum<ClientModels::Currency::CurrencyBTN>( "PlayFabClient_Currency_BTN" )
                ->Enum<ClientModels::Currency::CurrencyBWP>( "PlayFabClient_Currency_BWP" )
                ->Enum<ClientModels::Currency::CurrencyBYR>( "PlayFabClient_Currency_BYR" )
                ->Enum<ClientModels::Currency::CurrencyBZD>( "PlayFabClient_Currency_BZD" )
                ->Enum<ClientModels::Currency::CurrencyCAD>( "PlayFabClient_Currency_CAD" )
                ->Enum<ClientModels::Currency::CurrencyCDF>( "PlayFabClient_Currency_CDF" )
                ->Enum<ClientModels::Currency::CurrencyCHF>( "PlayFabClient_Currency_CHF" )
                ->Enum<ClientModels::Currency::CurrencyCLP>( "PlayFabClient_Currency_CLP" )
                ->Enum<ClientModels::Currency::CurrencyCNY>( "PlayFabClient_Currency_CNY" )
                ->Enum<ClientModels::Currency::CurrencyCOP>( "PlayFabClient_Currency_COP" )
                ->Enum<ClientModels::Currency::CurrencyCRC>( "PlayFabClient_Currency_CRC" )
                ->Enum<ClientModels::Currency::CurrencyCUC>( "PlayFabClient_Currency_CUC" )
                ->Enum<ClientModels::Currency::CurrencyCUP>( "PlayFabClient_Currency_CUP" )
                ->Enum<ClientModels::Currency::CurrencyCVE>( "PlayFabClient_Currency_CVE" )
                ->Enum<ClientModels::Currency::CurrencyCZK>( "PlayFabClient_Currency_CZK" )
                ->Enum<ClientModels::Currency::CurrencyDJF>( "PlayFabClient_Currency_DJF" )
                ->Enum<ClientModels::Currency::CurrencyDKK>( "PlayFabClient_Currency_DKK" )
                ->Enum<ClientModels::Currency::CurrencyDOP>( "PlayFabClient_Currency_DOP" )
                ->Enum<ClientModels::Currency::CurrencyDZD>( "PlayFabClient_Currency_DZD" )
                ->Enum<ClientModels::Currency::CurrencyEGP>( "PlayFabClient_Currency_EGP" )
                ->Enum<ClientModels::Currency::CurrencyERN>( "PlayFabClient_Currency_ERN" )
                ->Enum<ClientModels::Currency::CurrencyETB>( "PlayFabClient_Currency_ETB" )
                ->Enum<ClientModels::Currency::CurrencyEUR>( "PlayFabClient_Currency_EUR" )
                ->Enum<ClientModels::Currency::CurrencyFJD>( "PlayFabClient_Currency_FJD" )
                ->Enum<ClientModels::Currency::CurrencyFKP>( "PlayFabClient_Currency_FKP" )
                ->Enum<ClientModels::Currency::CurrencyGBP>( "PlayFabClient_Currency_GBP" )
                ->Enum<ClientModels::Currency::CurrencyGEL>( "PlayFabClient_Currency_GEL" )
                ->Enum<ClientModels::Currency::CurrencyGGP>( "PlayFabClient_Currency_GGP" )
                ->Enum<ClientModels::Currency::CurrencyGHS>( "PlayFabClient_Currency_GHS" )
                ->Enum<ClientModels::Currency::CurrencyGIP>( "PlayFabClient_Currency_GIP" )
                ->Enum<ClientModels::Currency::CurrencyGMD>( "PlayFabClient_Currency_GMD" )
                ->Enum<ClientModels::Currency::CurrencyGNF>( "PlayFabClient_Currency_GNF" )
                ->Enum<ClientModels::Currency::CurrencyGTQ>( "PlayFabClient_Currency_GTQ" )
                ->Enum<ClientModels::Currency::CurrencyGYD>( "PlayFabClient_Currency_GYD" )
                ->Enum<ClientModels::Currency::CurrencyHKD>( "PlayFabClient_Currency_HKD" )
                ->Enum<ClientModels::Currency::CurrencyHNL>( "PlayFabClient_Currency_HNL" )
                ->Enum<ClientModels::Currency::CurrencyHRK>( "PlayFabClient_Currency_HRK" )
                ->Enum<ClientModels::Currency::CurrencyHTG>( "PlayFabClient_Currency_HTG" )
                ->Enum<ClientModels::Currency::CurrencyHUF>( "PlayFabClient_Currency_HUF" )
                ->Enum<ClientModels::Currency::CurrencyIDR>( "PlayFabClient_Currency_IDR" )
                ->Enum<ClientModels::Currency::CurrencyILS>( "PlayFabClient_Currency_ILS" )
                ->Enum<ClientModels::Currency::CurrencyIMP>( "PlayFabClient_Currency_IMP" )
                ->Enum<ClientModels::Currency::CurrencyINR>( "PlayFabClient_Currency_INR" )
                ->Enum<ClientModels::Currency::CurrencyIQD>( "PlayFabClient_Currency_IQD" )
                ->Enum<ClientModels::Currency::CurrencyIRR>( "PlayFabClient_Currency_IRR" )
                ->Enum<ClientModels::Currency::CurrencyISK>( "PlayFabClient_Currency_ISK" )
                ->Enum<ClientModels::Currency::CurrencyJEP>( "PlayFabClient_Currency_JEP" )
                ->Enum<ClientModels::Currency::CurrencyJMD>( "PlayFabClient_Currency_JMD" )
                ->Enum<ClientModels::Currency::CurrencyJOD>( "PlayFabClient_Currency_JOD" )
                ->Enum<ClientModels::Currency::CurrencyJPY>( "PlayFabClient_Currency_JPY" )
                ->Enum<ClientModels::Currency::CurrencyKES>( "PlayFabClient_Currency_KES" )
                ->Enum<ClientModels::Currency::CurrencyKGS>( "PlayFabClient_Currency_KGS" )
                ->Enum<ClientModels::Currency::CurrencyKHR>( "PlayFabClient_Currency_KHR" )
                ->Enum<ClientModels::Currency::CurrencyKMF>( "PlayFabClient_Currency_KMF" )
                ->Enum<ClientModels::Currency::CurrencyKPW>( "PlayFabClient_Currency_KPW" )
                ->Enum<ClientModels::Currency::CurrencyKRW>( "PlayFabClient_Currency_KRW" )
                ->Enum<ClientModels::Currency::CurrencyKWD>( "PlayFabClient_Currency_KWD" )
                ->Enum<ClientModels::Currency::CurrencyKYD>( "PlayFabClient_Currency_KYD" )
                ->Enum<ClientModels::Currency::CurrencyKZT>( "PlayFabClient_Currency_KZT" )
                ->Enum<ClientModels::Currency::CurrencyLAK>( "PlayFabClient_Currency_LAK" )
                ->Enum<ClientModels::Currency::CurrencyLBP>( "PlayFabClient_Currency_LBP" )
                ->Enum<ClientModels::Currency::CurrencyLKR>( "PlayFabClient_Currency_LKR" )
                ->Enum<ClientModels::Currency::CurrencyLRD>( "PlayFabClient_Currency_LRD" )
                ->Enum<ClientModels::Currency::CurrencyLSL>( "PlayFabClient_Currency_LSL" )
                ->Enum<ClientModels::Currency::CurrencyLYD>( "PlayFabClient_Currency_LYD" )
                ->Enum<ClientModels::Currency::CurrencyMAD>( "PlayFabClient_Currency_MAD" )
                ->Enum<ClientModels::Currency::CurrencyMDL>( "PlayFabClient_Currency_MDL" )
                ->Enum<ClientModels::Currency::CurrencyMGA>( "PlayFabClient_Currency_MGA" )
                ->Enum<ClientModels::Currency::CurrencyMKD>( "PlayFabClient_Currency_MKD" )
                ->Enum<ClientModels::Currency::CurrencyMMK>( "PlayFabClient_Currency_MMK" )
                ->Enum<ClientModels::Currency::CurrencyMNT>( "PlayFabClient_Currency_MNT" )
                ->Enum<ClientModels::Currency::CurrencyMOP>( "PlayFabClient_Currency_MOP" )
                ->Enum<ClientModels::Currency::CurrencyMRO>( "PlayFabClient_Currency_MRO" )
                ->Enum<ClientModels::Currency::CurrencyMUR>( "PlayFabClient_Currency_MUR" )
                ->Enum<ClientModels::Currency::CurrencyMVR>( "PlayFabClient_Currency_MVR" )
                ->Enum<ClientModels::Currency::CurrencyMWK>( "PlayFabClient_Currency_MWK" )
                ->Enum<ClientModels::Currency::CurrencyMXN>( "PlayFabClient_Currency_MXN" )
                ->Enum<ClientModels::Currency::CurrencyMYR>( "PlayFabClient_Currency_MYR" )
                ->Enum<ClientModels::Currency::CurrencyMZN>( "PlayFabClient_Currency_MZN" )
                ->Enum<ClientModels::Currency::CurrencyNAD>( "PlayFabClient_Currency_NAD" )
                ->Enum<ClientModels::Currency::CurrencyNGN>( "PlayFabClient_Currency_NGN" )
                ->Enum<ClientModels::Currency::CurrencyNIO>( "PlayFabClient_Currency_NIO" )
                ->Enum<ClientModels::Currency::CurrencyNOK>( "PlayFabClient_Currency_NOK" )
                ->Enum<ClientModels::Currency::CurrencyNPR>( "PlayFabClient_Currency_NPR" )
                ->Enum<ClientModels::Currency::CurrencyNZD>( "PlayFabClient_Currency_NZD" )
                ->Enum<ClientModels::Currency::CurrencyOMR>( "PlayFabClient_Currency_OMR" )
                ->Enum<ClientModels::Currency::CurrencyPAB>( "PlayFabClient_Currency_PAB" )
                ->Enum<ClientModels::Currency::CurrencyPEN>( "PlayFabClient_Currency_PEN" )
                ->Enum<ClientModels::Currency::CurrencyPGK>( "PlayFabClient_Currency_PGK" )
                ->Enum<ClientModels::Currency::CurrencyPHP>( "PlayFabClient_Currency_PHP" )
                ->Enum<ClientModels::Currency::CurrencyPKR>( "PlayFabClient_Currency_PKR" )
                ->Enum<ClientModels::Currency::CurrencyPLN>( "PlayFabClient_Currency_PLN" )
                ->Enum<ClientModels::Currency::CurrencyPYG>( "PlayFabClient_Currency_PYG" )
                ->Enum<ClientModels::Currency::CurrencyQAR>( "PlayFabClient_Currency_QAR" )
                ->Enum<ClientModels::Currency::CurrencyRON>( "PlayFabClient_Currency_RON" )
                ->Enum<ClientModels::Currency::CurrencyRSD>( "PlayFabClient_Currency_RSD" )
                ->Enum<ClientModels::Currency::CurrencyRUB>( "PlayFabClient_Currency_RUB" )
                ->Enum<ClientModels::Currency::CurrencyRWF>( "PlayFabClient_Currency_RWF" )
                ->Enum<ClientModels::Currency::CurrencySAR>( "PlayFabClient_Currency_SAR" )
                ->Enum<ClientModels::Currency::CurrencySBD>( "PlayFabClient_Currency_SBD" )
                ->Enum<ClientModels::Currency::CurrencySCR>( "PlayFabClient_Currency_SCR" )
                ->Enum<ClientModels::Currency::CurrencySDG>( "PlayFabClient_Currency_SDG" )
                ->Enum<ClientModels::Currency::CurrencySEK>( "PlayFabClient_Currency_SEK" )
                ->Enum<ClientModels::Currency::CurrencySGD>( "PlayFabClient_Currency_SGD" )
                ->Enum<ClientModels::Currency::CurrencySHP>( "PlayFabClient_Currency_SHP" )
                ->Enum<ClientModels::Currency::CurrencySLL>( "PlayFabClient_Currency_SLL" )
                ->Enum<ClientModels::Currency::CurrencySOS>( "PlayFabClient_Currency_SOS" )
                ->Enum<ClientModels::Currency::CurrencySPL>( "PlayFabClient_Currency_SPL" )
                ->Enum<ClientModels::Currency::CurrencySRD>( "PlayFabClient_Currency_SRD" )
                ->Enum<ClientModels::Currency::CurrencySTD>( "PlayFabClient_Currency_STD" )
                ->Enum<ClientModels::Currency::CurrencySVC>( "PlayFabClient_Currency_SVC" )
                ->Enum<ClientModels::Currency::CurrencySYP>( "PlayFabClient_Currency_SYP" )
                ->Enum<ClientModels::Currency::CurrencySZL>( "PlayFabClient_Currency_SZL" )
                ->Enum<ClientModels::Currency::CurrencyTHB>( "PlayFabClient_Currency_THB" )
                ->Enum<ClientModels::Currency::CurrencyTJS>( "PlayFabClient_Currency_TJS" )
                ->Enum<ClientModels::Currency::CurrencyTMT>( "PlayFabClient_Currency_TMT" )
                ->Enum<ClientModels::Currency::CurrencyTND>( "PlayFabClient_Currency_TND" )
                ->Enum<ClientModels::Currency::CurrencyTOP>( "PlayFabClient_Currency_TOP" )
                ->Enum<ClientModels::Currency::CurrencyTRY>( "PlayFabClient_Currency_TRY" )
                ->Enum<ClientModels::Currency::CurrencyTTD>( "PlayFabClient_Currency_TTD" )
                ->Enum<ClientModels::Currency::CurrencyTVD>( "PlayFabClient_Currency_TVD" )
                ->Enum<ClientModels::Currency::CurrencyTWD>( "PlayFabClient_Currency_TWD" )
                ->Enum<ClientModels::Currency::CurrencyTZS>( "PlayFabClient_Currency_TZS" )
                ->Enum<ClientModels::Currency::CurrencyUAH>( "PlayFabClient_Currency_UAH" )
                ->Enum<ClientModels::Currency::CurrencyUGX>( "PlayFabClient_Currency_UGX" )
                ->Enum<ClientModels::Currency::CurrencyUSD>( "PlayFabClient_Currency_USD" )
                ->Enum<ClientModels::Currency::CurrencyUYU>( "PlayFabClient_Currency_UYU" )
                ->Enum<ClientModels::Currency::CurrencyUZS>( "PlayFabClient_Currency_UZS" )
                ->Enum<ClientModels::Currency::CurrencyVEF>( "PlayFabClient_Currency_VEF" )
                ->Enum<ClientModels::Currency::CurrencyVND>( "PlayFabClient_Currency_VND" )
                ->Enum<ClientModels::Currency::CurrencyVUV>( "PlayFabClient_Currency_VUV" )
                ->Enum<ClientModels::Currency::CurrencyWST>( "PlayFabClient_Currency_WST" )
                ->Enum<ClientModels::Currency::CurrencyXAF>( "PlayFabClient_Currency_XAF" )
                ->Enum<ClientModels::Currency::CurrencyXCD>( "PlayFabClient_Currency_XCD" )
                ->Enum<ClientModels::Currency::CurrencyXDR>( "PlayFabClient_Currency_XDR" )
                ->Enum<ClientModels::Currency::CurrencyXOF>( "PlayFabClient_Currency_XOF" )
                ->Enum<ClientModels::Currency::CurrencyXPF>( "PlayFabClient_Currency_XPF" )
                ->Enum<ClientModels::Currency::CurrencyYER>( "PlayFabClient_Currency_YER" )
                ->Enum<ClientModels::Currency::CurrencyZAR>( "PlayFabClient_Currency_ZAR" )
                ->Enum<ClientModels::Currency::CurrencyZMW>( "PlayFabClient_Currency_ZMW" )
                ->Enum<ClientModels::Currency::CurrencyZWD>( "PlayFabClient_Currency_ZWD" )
            ;
            behaviorContext 
                ->Enum<ClientModels::Region::RegionUSCentral>( "PlayFabClient_Region_USCentral" )
                ->Enum<ClientModels::Region::RegionUSEast>( "PlayFabClient_Region_USEast" )
                ->Enum<ClientModels::Region::RegionEUWest>( "PlayFabClient_Region_EUWest" )
                ->Enum<ClientModels::Region::RegionSingapore>( "PlayFabClient_Region_Singapore" )
                ->Enum<ClientModels::Region::RegionJapan>( "PlayFabClient_Region_Japan" )
                ->Enum<ClientModels::Region::RegionBrazil>( "PlayFabClient_Region_Brazil" )
                ->Enum<ClientModels::Region::RegionAustralia>( "PlayFabClient_Region_Australia" )
            ;
            behaviorContext 
                ->Enum<ClientModels::GameInstanceState::GameInstanceStateOpen>( "PlayFabClient_GameInstanceState_Open" )
                ->Enum<ClientModels::GameInstanceState::GameInstanceStateClosed>( "PlayFabClient_GameInstanceState_Closed" )
            ;
            behaviorContext 
                ->Enum<ClientModels::TitleActivationStatus::TitleActivationStatusNone>( "PlayFabClient_TitleActivationStatus_None" )
                ->Enum<ClientModels::TitleActivationStatus::TitleActivationStatusActivatedTitleKey>( "PlayFabClient_TitleActivationStatus_ActivatedTitleKey" )
                ->Enum<ClientModels::TitleActivationStatus::TitleActivationStatusPendingSteam>( "PlayFabClient_TitleActivationStatus_PendingSteam" )
                ->Enum<ClientModels::TitleActivationStatus::TitleActivationStatusActivatedSteam>( "PlayFabClient_TitleActivationStatus_ActivatedSteam" )
                ->Enum<ClientModels::TitleActivationStatus::TitleActivationStatusRevokedSteam>( "PlayFabClient_TitleActivationStatus_RevokedSteam" )
            ;
            behaviorContext 
                ->Enum<ClientModels::LoginIdentityProvider::LoginIdentityProviderUnknown>( "PlayFabClient_LoginIdentityProvider_Unknown" )
                ->Enum<ClientModels::LoginIdentityProvider::LoginIdentityProviderPlayFab>( "PlayFabClient_LoginIdentityProvider_PlayFab" )
                ->Enum<ClientModels::LoginIdentityProvider::LoginIdentityProviderCustom>( "PlayFabClient_LoginIdentityProvider_Custom" )
                ->Enum<ClientModels::LoginIdentityProvider::LoginIdentityProviderGameCenter>( "PlayFabClient_LoginIdentityProvider_GameCenter" )
                ->Enum<ClientModels::LoginIdentityProvider::LoginIdentityProviderGooglePlay>( "PlayFabClient_LoginIdentityProvider_GooglePlay" )
                ->Enum<ClientModels::LoginIdentityProvider::LoginIdentityProviderSteam>( "PlayFabClient_LoginIdentityProvider_Steam" )
                ->Enum<ClientModels::LoginIdentityProvider::LoginIdentityProviderXBoxLive>( "PlayFabClient_LoginIdentityProvider_XBoxLive" )
                ->Enum<ClientModels::LoginIdentityProvider::LoginIdentityProviderPSN>( "PlayFabClient_LoginIdentityProvider_PSN" )
                ->Enum<ClientModels::LoginIdentityProvider::LoginIdentityProviderKongregate>( "PlayFabClient_LoginIdentityProvider_Kongregate" )
                ->Enum<ClientModels::LoginIdentityProvider::LoginIdentityProviderFacebook>( "PlayFabClient_LoginIdentityProvider_Facebook" )
                ->Enum<ClientModels::LoginIdentityProvider::LoginIdentityProviderIOSDevice>( "PlayFabClient_LoginIdentityProvider_IOSDevice" )
                ->Enum<ClientModels::LoginIdentityProvider::LoginIdentityProviderAndroidDevice>( "PlayFabClient_LoginIdentityProvider_AndroidDevice" )
                ->Enum<ClientModels::LoginIdentityProvider::LoginIdentityProviderTwitch>( "PlayFabClient_LoginIdentityProvider_Twitch" )
                ->Enum<ClientModels::LoginIdentityProvider::LoginIdentityProviderWindowsHello>( "PlayFabClient_LoginIdentityProvider_WindowsHello" )
            ;
            behaviorContext 
                ->Enum<ClientModels::PushNotificationPlatform::PushNotificationPlatformApplePushNotificationService>( "PlayFabClient_PushNotificationPlatform_ApplePushNotificationService" )
                ->Enum<ClientModels::PushNotificationPlatform::PushNotificationPlatformGoogleCloudMessaging>( "PlayFabClient_PushNotificationPlatform_GoogleCloudMessaging" )
            ;
            behaviorContext 
                ->Enum<ClientModels::UserOrigination::UserOriginationOrganic>( "PlayFabClient_UserOrigination_Organic" )
                ->Enum<ClientModels::UserOrigination::UserOriginationSteam>( "PlayFabClient_UserOrigination_Steam" )
                ->Enum<ClientModels::UserOrigination::UserOriginationGoogle>( "PlayFabClient_UserOrigination_Google" )
                ->Enum<ClientModels::UserOrigination::UserOriginationAmazon>( "PlayFabClient_UserOrigination_Amazon" )
                ->Enum<ClientModels::UserOrigination::UserOriginationFacebook>( "PlayFabClient_UserOrigination_Facebook" )
                ->Enum<ClientModels::UserOrigination::UserOriginationKongregate>( "PlayFabClient_UserOrigination_Kongregate" )
                ->Enum<ClientModels::UserOrigination::UserOriginationGamersFirst>( "PlayFabClient_UserOrigination_GamersFirst" )
                ->Enum<ClientModels::UserOrigination::UserOriginationUnknown>( "PlayFabClient_UserOrigination_Unknown" )
                ->Enum<ClientModels::UserOrigination::UserOriginationIOS>( "PlayFabClient_UserOrigination_IOS" )
                ->Enum<ClientModels::UserOrigination::UserOriginationLoadTest>( "PlayFabClient_UserOrigination_LoadTest" )
                ->Enum<ClientModels::UserOrigination::UserOriginationAndroid>( "PlayFabClient_UserOrigination_Android" )
                ->Enum<ClientModels::UserOrigination::UserOriginationPSN>( "PlayFabClient_UserOrigination_PSN" )
                ->Enum<ClientModels::UserOrigination::UserOriginationGameCenter>( "PlayFabClient_UserOrigination_GameCenter" )
                ->Enum<ClientModels::UserOrigination::UserOriginationCustomId>( "PlayFabClient_UserOrigination_CustomId" )
                ->Enum<ClientModels::UserOrigination::UserOriginationXboxLive>( "PlayFabClient_UserOrigination_XboxLive" )
                ->Enum<ClientModels::UserOrigination::UserOriginationParse>( "PlayFabClient_UserOrigination_Parse" )
                ->Enum<ClientModels::UserOrigination::UserOriginationTwitch>( "PlayFabClient_UserOrigination_Twitch" )
                ->Enum<ClientModels::UserOrigination::UserOriginationWindowsHello>( "PlayFabClient_UserOrigination_WindowsHello" )
            ;
            behaviorContext 
                ->Enum<ClientModels::UserDataPermission::UserDataPermissionPrivate>( "PlayFabClient_UserDataPermission_Private" )
                ->Enum<ClientModels::UserDataPermission::UserDataPermissionPublic>( "PlayFabClient_UserDataPermission_Public" )
            ;
            behaviorContext 
                ->Enum<ClientModels::SourceType::SourceTypeAdmin>( "PlayFabClient_SourceType_Admin" )
                ->Enum<ClientModels::SourceType::SourceTypeBackEnd>( "PlayFabClient_SourceType_BackEnd" )
                ->Enum<ClientModels::SourceType::SourceTypeGameClient>( "PlayFabClient_SourceType_GameClient" )
                ->Enum<ClientModels::SourceType::SourceTypeGameServer>( "PlayFabClient_SourceType_GameServer" )
                ->Enum<ClientModels::SourceType::SourceTypePartner>( "PlayFabClient_SourceType_Partner" )
            ;
            behaviorContext 
                ->Enum<ClientModels::MatchmakeStatus::MatchmakeStatusComplete>( "PlayFabClient_MatchmakeStatus_Complete" )
                ->Enum<ClientModels::MatchmakeStatus::MatchmakeStatusWaiting>( "PlayFabClient_MatchmakeStatus_Waiting" )
                ->Enum<ClientModels::MatchmakeStatus::MatchmakeStatusGameNotFound>( "PlayFabClient_MatchmakeStatus_GameNotFound" )
                ->Enum<ClientModels::MatchmakeStatus::MatchmakeStatusNoAvailableSlots>( "PlayFabClient_MatchmakeStatus_NoAvailableSlots" )
                ->Enum<ClientModels::MatchmakeStatus::MatchmakeStatusSessionClosed>( "PlayFabClient_MatchmakeStatus_SessionClosed" )
            ;
            behaviorContext 
                ->Enum<ClientModels::TransactionStatus::TransactionStatusCreateCart>( "PlayFabClient_TransactionStatus_CreateCart" )
                ->Enum<ClientModels::TransactionStatus::TransactionStatusInit>( "PlayFabClient_TransactionStatus_Init" )
                ->Enum<ClientModels::TransactionStatus::TransactionStatusApproved>( "PlayFabClient_TransactionStatus_Approved" )
                ->Enum<ClientModels::TransactionStatus::TransactionStatusSucceeded>( "PlayFabClient_TransactionStatus_Succeeded" )
                ->Enum<ClientModels::TransactionStatus::TransactionStatusFailedByProvider>( "PlayFabClient_TransactionStatus_FailedByProvider" )
                ->Enum<ClientModels::TransactionStatus::TransactionStatusDisputePending>( "PlayFabClient_TransactionStatus_DisputePending" )
                ->Enum<ClientModels::TransactionStatus::TransactionStatusRefundPending>( "PlayFabClient_TransactionStatus_RefundPending" )
                ->Enum<ClientModels::TransactionStatus::TransactionStatusRefunded>( "PlayFabClient_TransactionStatus_Refunded" )
                ->Enum<ClientModels::TransactionStatus::TransactionStatusRefundFailed>( "PlayFabClient_TransactionStatus_RefundFailed" )
                ->Enum<ClientModels::TransactionStatus::TransactionStatusChargedBack>( "PlayFabClient_TransactionStatus_ChargedBack" )
                ->Enum<ClientModels::TransactionStatus::TransactionStatusFailedByUber>( "PlayFabClient_TransactionStatus_FailedByUber" )
                ->Enum<ClientModels::TransactionStatus::TransactionStatusFailedByPlayFab>( "PlayFabClient_TransactionStatus_FailedByPlayFab" )
                ->Enum<ClientModels::TransactionStatus::TransactionStatusRevoked>( "PlayFabClient_TransactionStatus_Revoked" )
                ->Enum<ClientModels::TransactionStatus::TransactionStatusTradePending>( "PlayFabClient_TransactionStatus_TradePending" )
                ->Enum<ClientModels::TransactionStatus::TransactionStatusTraded>( "PlayFabClient_TransactionStatus_Traded" )
                ->Enum<ClientModels::TransactionStatus::TransactionStatusUpgraded>( "PlayFabClient_TransactionStatus_Upgraded" )
                ->Enum<ClientModels::TransactionStatus::TransactionStatusStackPending>( "PlayFabClient_TransactionStatus_StackPending" )
                ->Enum<ClientModels::TransactionStatus::TransactionStatusStacked>( "PlayFabClient_TransactionStatus_Stacked" )
                ->Enum<ClientModels::TransactionStatus::TransactionStatusOther>( "PlayFabClient_TransactionStatus_Other" )
                ->Enum<ClientModels::TransactionStatus::TransactionStatusFailed>( "PlayFabClient_TransactionStatus_Failed" )
            ;
    
            //-----------------------------------------------------------------------------------------------------
			// Reflect data models (structs/classes)
            //-----------------------------------------------------------------------------------------------------

			behaviorContext->Class<ClientModels::AcceptTradeRequest>("PlayFabClient_AcceptTradeRequest")
                ->Constructor() 
			    ->Property("OfferingPlayerId", BehaviorValueProperty(&ClientModels::AcceptTradeRequest::OfferingPlayerId)) 
			    ->Property("TradeId", BehaviorValueProperty(&ClientModels::AcceptTradeRequest::TradeId)) 
			    ->Property("AcceptedInventoryInstanceIds", BehaviorValueProperty(&ClientModels::AcceptTradeRequest::AcceptedInventoryInstanceIds)) 
			;
		
			behaviorContext->Class<ClientModels::TradeInfo>("PlayFabClient_TradeInfo")
                ->Constructor() 
			    ->Property("Status", BehaviorValueProperty(&ClientModels::TradeInfo::Status)) 
			    ->Property("TradeId", BehaviorValueProperty(&ClientModels::TradeInfo::TradeId)) 
			    ->Property("OfferingPlayerId", BehaviorValueProperty(&ClientModels::TradeInfo::OfferingPlayerId)) 
			    ->Property("OfferedInventoryInstanceIds", BehaviorValueProperty(&ClientModels::TradeInfo::OfferedInventoryInstanceIds)) 
			    ->Property("OfferedCatalogItemIds", BehaviorValueProperty(&ClientModels::TradeInfo::OfferedCatalogItemIds)) 
			    ->Property("RequestedCatalogItemIds", BehaviorValueProperty(&ClientModels::TradeInfo::RequestedCatalogItemIds)) 
			    ->Property("AllowedPlayerIds", BehaviorValueProperty(&ClientModels::TradeInfo::AllowedPlayerIds)) 
			    ->Property("AcceptedPlayerId", BehaviorValueProperty(&ClientModels::TradeInfo::AcceptedPlayerId)) 
			    ->Property("AcceptedInventoryInstanceIds", BehaviorValueProperty(&ClientModels::TradeInfo::AcceptedInventoryInstanceIds)) 
			    ->Property("OpenedAt", BehaviorValueProperty(&ClientModels::TradeInfo::OpenedAt)) 
			    ->Property("FilledAt", BehaviorValueProperty(&ClientModels::TradeInfo::FilledAt)) 
			    ->Property("CancelledAt", BehaviorValueProperty(&ClientModels::TradeInfo::CancelledAt)) 
			    ->Property("InvalidatedAt", BehaviorValueProperty(&ClientModels::TradeInfo::InvalidatedAt)) 
			;
		
			behaviorContext->Class<ClientModels::AcceptTradeResponse>("PlayFabClient_AcceptTradeResponse")
                ->Constructor() 
			    ->Property("Trade", BehaviorValueProperty(&ClientModels::AcceptTradeResponse::Trade)) 
			;
		
			behaviorContext->Class<ClientModels::AdCampaignAttributionModel>("PlayFabClient_AdCampaignAttributionModel")
                ->Constructor() 
			    ->Property("Platform", BehaviorValueProperty(&ClientModels::AdCampaignAttributionModel::Platform)) 
			    ->Property("CampaignId", BehaviorValueProperty(&ClientModels::AdCampaignAttributionModel::CampaignId)) 
			    ->Property("AttributedAt", BehaviorValueProperty(&ClientModels::AdCampaignAttributionModel::AttributedAt)) 
			;
		
			behaviorContext->Class<ClientModels::AddFriendRequest>("PlayFabClient_AddFriendRequest")
                ->Constructor() 
			    ->Property("FriendPlayFabId", BehaviorValueProperty(&ClientModels::AddFriendRequest::FriendPlayFabId)) 
			    ->Property("FriendUsername", BehaviorValueProperty(&ClientModels::AddFriendRequest::FriendUsername)) 
			    ->Property("FriendEmail", BehaviorValueProperty(&ClientModels::AddFriendRequest::FriendEmail)) 
			    ->Property("FriendTitleDisplayName", BehaviorValueProperty(&ClientModels::AddFriendRequest::FriendTitleDisplayName)) 
			;
		
			behaviorContext->Class<ClientModels::AddFriendResult>("PlayFabClient_AddFriendResult")
                ->Constructor() 
			    ->Property("Created", BehaviorValueProperty(&ClientModels::AddFriendResult::Created)) 
			;
		
			behaviorContext->Class<ClientModels::GenericServiceId>("PlayFabClient_GenericServiceId")
                ->Constructor() 
			    ->Property("ServiceName", BehaviorValueProperty(&ClientModels::GenericServiceId::ServiceName)) 
			    ->Property("UserId", BehaviorValueProperty(&ClientModels::GenericServiceId::UserId)) 
			;
		
			behaviorContext->Class<ClientModels::AddGenericIDRequest>("PlayFabClient_AddGenericIDRequest")
                ->Constructor() 
			    ->Property("GenericId", BehaviorValueProperty(&ClientModels::AddGenericIDRequest::GenericId)) 
			;
		
			behaviorContext->Class<ClientModels::AddGenericIDResult>("PlayFabClient_AddGenericIDResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<ClientModels::AddSharedGroupMembersRequest>("PlayFabClient_AddSharedGroupMembersRequest")
                ->Constructor() 
			    ->Property("SharedGroupId", BehaviorValueProperty(&ClientModels::AddSharedGroupMembersRequest::SharedGroupId)) 
			    ->Property("PlayFabIds", BehaviorValueProperty(&ClientModels::AddSharedGroupMembersRequest::PlayFabIds)) 
			;
		
			behaviorContext->Class<ClientModels::AddSharedGroupMembersResult>("PlayFabClient_AddSharedGroupMembersResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<ClientModels::AddUsernamePasswordRequest>("PlayFabClient_AddUsernamePasswordRequest")
                ->Constructor() 
			    ->Property("Username", BehaviorValueProperty(&ClientModels::AddUsernamePasswordRequest::Username)) 
			    ->Property("Email", BehaviorValueProperty(&ClientModels::AddUsernamePasswordRequest::Email)) 
			    ->Property("Password", BehaviorValueProperty(&ClientModels::AddUsernamePasswordRequest::Password)) 
			;
		
			behaviorContext->Class<ClientModels::AddUsernamePasswordResult>("PlayFabClient_AddUsernamePasswordResult")
                ->Constructor() 
			    ->Property("Username", BehaviorValueProperty(&ClientModels::AddUsernamePasswordResult::Username)) 
			;
		
			behaviorContext->Class<ClientModels::AddUserVirtualCurrencyRequest>("PlayFabClient_AddUserVirtualCurrencyRequest")
                ->Constructor() 
			    ->Property("VirtualCurrency", BehaviorValueProperty(&ClientModels::AddUserVirtualCurrencyRequest::VirtualCurrency)) 
			    ->Property("Amount", BehaviorValueProperty(&ClientModels::AddUserVirtualCurrencyRequest::Amount)) 
			;
		
			behaviorContext->Class<ClientModels::AndroidDevicePushNotificationRegistrationRequest>("PlayFabClient_AndroidDevicePushNotificationRegistrationRequest")
                ->Constructor() 
			    ->Property("DeviceToken", BehaviorValueProperty(&ClientModels::AndroidDevicePushNotificationRegistrationRequest::DeviceToken)) 
			    ->Property("SendPushNotificationConfirmation", BehaviorValueProperty(&ClientModels::AndroidDevicePushNotificationRegistrationRequest::SendPushNotificationConfirmation)) 
			    ->Property("ConfirmationMessage", BehaviorValueProperty(&ClientModels::AndroidDevicePushNotificationRegistrationRequest::ConfirmationMessage)) 
			;
		
			behaviorContext->Class<ClientModels::AndroidDevicePushNotificationRegistrationResult>("PlayFabClient_AndroidDevicePushNotificationRegistrationResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<ClientModels::AttributeInstallRequest>("PlayFabClient_AttributeInstallRequest")
                ->Constructor() 
			    ->Property("Idfa", BehaviorValueProperty(&ClientModels::AttributeInstallRequest::Idfa)) 
			    ->Property("Adid", BehaviorValueProperty(&ClientModels::AttributeInstallRequest::Adid)) 
			;
		
			behaviorContext->Class<ClientModels::AttributeInstallResult>("PlayFabClient_AttributeInstallResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<ClientModels::CancelTradeRequest>("PlayFabClient_CancelTradeRequest")
                ->Constructor() 
			    ->Property("TradeId", BehaviorValueProperty(&ClientModels::CancelTradeRequest::TradeId)) 
			;
		
			behaviorContext->Class<ClientModels::CancelTradeResponse>("PlayFabClient_CancelTradeResponse")
                ->Constructor() 
			    ->Property("Trade", BehaviorValueProperty(&ClientModels::CancelTradeResponse::Trade)) 
			;
		
			behaviorContext->Class<ClientModels::CartItem>("PlayFabClient_CartItem")
                ->Constructor() 
			    ->Property("ItemId", BehaviorValueProperty(&ClientModels::CartItem::ItemId)) 
			    ->Property("ItemClass", BehaviorValueProperty(&ClientModels::CartItem::ItemClass)) 
			    ->Property("ItemInstanceId", BehaviorValueProperty(&ClientModels::CartItem::ItemInstanceId)) 
			    ->Property("DisplayName", BehaviorValueProperty(&ClientModels::CartItem::DisplayName)) 
			    ->Property("Description", BehaviorValueProperty(&ClientModels::CartItem::Description)) 
			;
		
			behaviorContext->Class<ClientModels::CatalogItemConsumableInfo>("PlayFabClient_CatalogItemConsumableInfo")
                ->Constructor() 
			    ->Property("UsageCount", BehaviorValueProperty(&ClientModels::CatalogItemConsumableInfo::UsageCount)) 
			    ->Property("UsagePeriod", BehaviorValueProperty(&ClientModels::CatalogItemConsumableInfo::UsagePeriod)) 
			    ->Property("UsagePeriodGroup", BehaviorValueProperty(&ClientModels::CatalogItemConsumableInfo::UsagePeriodGroup)) 
			;
		
			behaviorContext->Class<ClientModels::CatalogItemContainerInfo>("PlayFabClient_CatalogItemContainerInfo")
                ->Constructor() 
			    ->Property("KeyItemId", BehaviorValueProperty(&ClientModels::CatalogItemContainerInfo::KeyItemId)) 
			    ->Property("ItemContents", BehaviorValueProperty(&ClientModels::CatalogItemContainerInfo::ItemContents)) 
			    ->Property("ResultTableContents", BehaviorValueProperty(&ClientModels::CatalogItemContainerInfo::ResultTableContents)) 
			;
		
			behaviorContext->Class<ClientModels::CatalogItemBundleInfo>("PlayFabClient_CatalogItemBundleInfo")
                ->Constructor() 
			    ->Property("BundledItems", BehaviorValueProperty(&ClientModels::CatalogItemBundleInfo::BundledItems)) 
			    ->Property("BundledResultTables", BehaviorValueProperty(&ClientModels::CatalogItemBundleInfo::BundledResultTables)) 
			;
		
			behaviorContext->Class<ClientModels::CatalogItem>("PlayFabClient_CatalogItem")
                ->Constructor() 
			    ->Property("ItemId", BehaviorValueProperty(&ClientModels::CatalogItem::ItemId)) 
			    ->Property("ItemClass", BehaviorValueProperty(&ClientModels::CatalogItem::ItemClass)) 
			    ->Property("CatalogVersion", BehaviorValueProperty(&ClientModels::CatalogItem::CatalogVersion)) 
			    ->Property("DisplayName", BehaviorValueProperty(&ClientModels::CatalogItem::DisplayName)) 
			    ->Property("Description", BehaviorValueProperty(&ClientModels::CatalogItem::Description)) 
			    ->Property("Tags", BehaviorValueProperty(&ClientModels::CatalogItem::Tags)) 
			    ->Property("CustomData", BehaviorValueProperty(&ClientModels::CatalogItem::CustomData)) 
			    ->Property("Consumable", BehaviorValueProperty(&ClientModels::CatalogItem::Consumable)) 
			    ->Property("Container", BehaviorValueProperty(&ClientModels::CatalogItem::Container)) 
			    ->Property("Bundle", BehaviorValueProperty(&ClientModels::CatalogItem::Bundle)) 
			    ->Property("CanBecomeCharacter", BehaviorValueProperty(&ClientModels::CatalogItem::CanBecomeCharacter)) 
			    ->Property("IsStackable", BehaviorValueProperty(&ClientModels::CatalogItem::IsStackable)) 
			    ->Property("IsTradable", BehaviorValueProperty(&ClientModels::CatalogItem::IsTradable)) 
			    ->Property("ItemImageUrl", BehaviorValueProperty(&ClientModels::CatalogItem::ItemImageUrl)) 
			    ->Property("IsLimitedEdition", BehaviorValueProperty(&ClientModels::CatalogItem::IsLimitedEdition)) 
			    ->Property("InitialLimitedEditionCount", BehaviorValueProperty(&ClientModels::CatalogItem::InitialLimitedEditionCount)) 
			;
		
			behaviorContext->Class<ClientModels::ItemInstance>("PlayFabClient_ItemInstance")
                ->Constructor() 
			    ->Property("ItemId", BehaviorValueProperty(&ClientModels::ItemInstance::ItemId)) 
			    ->Property("ItemInstanceId", BehaviorValueProperty(&ClientModels::ItemInstance::ItemInstanceId)) 
			    ->Property("ItemClass", BehaviorValueProperty(&ClientModels::ItemInstance::ItemClass)) 
			    ->Property("PurchaseDate", BehaviorValueProperty(&ClientModels::ItemInstance::PurchaseDate)) 
			    ->Property("Expiration", BehaviorValueProperty(&ClientModels::ItemInstance::Expiration)) 
			    ->Property("RemainingUses", BehaviorValueProperty(&ClientModels::ItemInstance::RemainingUses)) 
			    ->Property("UsesIncrementedBy", BehaviorValueProperty(&ClientModels::ItemInstance::UsesIncrementedBy)) 
			    ->Property("Annotation", BehaviorValueProperty(&ClientModels::ItemInstance::Annotation)) 
			    ->Property("CatalogVersion", BehaviorValueProperty(&ClientModels::ItemInstance::CatalogVersion)) 
			    ->Property("BundleParent", BehaviorValueProperty(&ClientModels::ItemInstance::BundleParent)) 
			    ->Property("DisplayName", BehaviorValueProperty(&ClientModels::ItemInstance::DisplayName)) 
			    ->Property("UnitCurrency", BehaviorValueProperty(&ClientModels::ItemInstance::UnitCurrency)) 
			    ->Property("UnitPrice", BehaviorValueProperty(&ClientModels::ItemInstance::UnitPrice)) 
			    ->Property("BundleContents", BehaviorValueProperty(&ClientModels::ItemInstance::BundleContents)) 
			;
		
			behaviorContext->Class<ClientModels::CharacterInventory>("PlayFabClient_CharacterInventory")
                ->Constructor() 
			    ->Property("CharacterId", BehaviorValueProperty(&ClientModels::CharacterInventory::CharacterId)) 
			    ->Property("Inventory", BehaviorValueProperty(&ClientModels::CharacterInventory::Inventory)) 
			;
		
			behaviorContext->Class<ClientModels::CharacterLeaderboardEntry>("PlayFabClient_CharacterLeaderboardEntry")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ClientModels::CharacterLeaderboardEntry::PlayFabId)) 
			    ->Property("CharacterId", BehaviorValueProperty(&ClientModels::CharacterLeaderboardEntry::CharacterId)) 
			    ->Property("CharacterName", BehaviorValueProperty(&ClientModels::CharacterLeaderboardEntry::CharacterName)) 
			    ->Property("DisplayName", BehaviorValueProperty(&ClientModels::CharacterLeaderboardEntry::DisplayName)) 
			    ->Property("CharacterType", BehaviorValueProperty(&ClientModels::CharacterLeaderboardEntry::CharacterType)) 
			    ->Property("StatValue", BehaviorValueProperty(&ClientModels::CharacterLeaderboardEntry::StatValue)) 
			    ->Property("Position", BehaviorValueProperty(&ClientModels::CharacterLeaderboardEntry::Position)) 
			;
		
			behaviorContext->Class<ClientModels::CharacterResult>("PlayFabClient_CharacterResult")
                ->Constructor() 
			    ->Property("CharacterId", BehaviorValueProperty(&ClientModels::CharacterResult::CharacterId)) 
			    ->Property("CharacterName", BehaviorValueProperty(&ClientModels::CharacterResult::CharacterName)) 
			    ->Property("CharacterType", BehaviorValueProperty(&ClientModels::CharacterResult::CharacterType)) 
			;
		
			behaviorContext->Class<ClientModels::Container_Dictionary_String_String>("PlayFabClient_Container_Dictionary_String_String")
                ->Constructor() 
			;
		
			behaviorContext->Class<ClientModels::CollectionFilter>("PlayFabClient_CollectionFilter")
                ->Constructor() 
			    ->Property("Includes", BehaviorValueProperty(&ClientModels::CollectionFilter::Includes)) 
			    ->Property("Excludes", BehaviorValueProperty(&ClientModels::CollectionFilter::Excludes)) 
			;
		
			behaviorContext->Class<ClientModels::ConfirmPurchaseRequest>("PlayFabClient_ConfirmPurchaseRequest")
                ->Constructor() 
			    ->Property("OrderId", BehaviorValueProperty(&ClientModels::ConfirmPurchaseRequest::OrderId)) 
			;
		
			behaviorContext->Class<ClientModels::ConfirmPurchaseResult>("PlayFabClient_ConfirmPurchaseResult")
                ->Constructor() 
			    ->Property("OrderId", BehaviorValueProperty(&ClientModels::ConfirmPurchaseResult::OrderId)) 
			    ->Property("PurchaseDate", BehaviorValueProperty(&ClientModels::ConfirmPurchaseResult::PurchaseDate)) 
			    ->Property("Items", BehaviorValueProperty(&ClientModels::ConfirmPurchaseResult::Items)) 
			;
		
			behaviorContext->Class<ClientModels::ConsumeItemRequest>("PlayFabClient_ConsumeItemRequest")
                ->Constructor() 
			    ->Property("ItemInstanceId", BehaviorValueProperty(&ClientModels::ConsumeItemRequest::ItemInstanceId)) 
			    ->Property("ConsumeCount", BehaviorValueProperty(&ClientModels::ConsumeItemRequest::ConsumeCount)) 
			    ->Property("CharacterId", BehaviorValueProperty(&ClientModels::ConsumeItemRequest::CharacterId)) 
			;
		
			behaviorContext->Class<ClientModels::ConsumeItemResult>("PlayFabClient_ConsumeItemResult")
                ->Constructor() 
			    ->Property("ItemInstanceId", BehaviorValueProperty(&ClientModels::ConsumeItemResult::ItemInstanceId)) 
			    ->Property("RemainingUses", BehaviorValueProperty(&ClientModels::ConsumeItemResult::RemainingUses)) 
			;
		
			behaviorContext->Class<ClientModels::CreateSharedGroupRequest>("PlayFabClient_CreateSharedGroupRequest")
                ->Constructor() 
			    ->Property("SharedGroupId", BehaviorValueProperty(&ClientModels::CreateSharedGroupRequest::SharedGroupId)) 
			;
		
			behaviorContext->Class<ClientModels::CreateSharedGroupResult>("PlayFabClient_CreateSharedGroupResult")
                ->Constructor() 
			    ->Property("SharedGroupId", BehaviorValueProperty(&ClientModels::CreateSharedGroupResult::SharedGroupId)) 
			;
		
			behaviorContext->Class<ClientModels::CurrentGamesRequest>("PlayFabClient_CurrentGamesRequest")
                ->Constructor() 
			    ->Property("pfRegion", BehaviorValueProperty(&ClientModels::CurrentGamesRequest::pfRegion)) 
			    ->Property("BuildVersion", BehaviorValueProperty(&ClientModels::CurrentGamesRequest::BuildVersion)) 
			    ->Property("GameMode", BehaviorValueProperty(&ClientModels::CurrentGamesRequest::GameMode)) 
			    ->Property("StatisticName", BehaviorValueProperty(&ClientModels::CurrentGamesRequest::StatisticName)) 
			    ->Property("TagFilter", BehaviorValueProperty(&ClientModels::CurrentGamesRequest::TagFilter)) 
			;
		
			behaviorContext->Class<ClientModels::GameInfo>("PlayFabClient_GameInfo")
                ->Constructor() 
			    ->Property("pfRegion", BehaviorValueProperty(&ClientModels::GameInfo::pfRegion)) 
			    ->Property("LobbyID", BehaviorValueProperty(&ClientModels::GameInfo::LobbyID)) 
			    ->Property("BuildVersion", BehaviorValueProperty(&ClientModels::GameInfo::BuildVersion)) 
			    ->Property("GameMode", BehaviorValueProperty(&ClientModels::GameInfo::GameMode)) 
			    ->Property("StatisticName", BehaviorValueProperty(&ClientModels::GameInfo::StatisticName)) 
			    ->Property("MaxPlayers", BehaviorValueProperty(&ClientModels::GameInfo::MaxPlayers)) 
			    ->Property("PlayerUserIds", BehaviorValueProperty(&ClientModels::GameInfo::PlayerUserIds)) 
			    ->Property("RunTime", BehaviorValueProperty(&ClientModels::GameInfo::RunTime)) 
			    ->Property("GameServerState", BehaviorValueProperty(&ClientModels::GameInfo::GameServerState)) 
			    ->Property("GameServerData", BehaviorValueProperty(&ClientModels::GameInfo::GameServerData)) 
			    ->Property("LastHeartbeat", BehaviorValueProperty(&ClientModels::GameInfo::LastHeartbeat)) 
			    ->Property("ServerHostname", BehaviorValueProperty(&ClientModels::GameInfo::ServerHostname)) 
			    ->Property("ServerPort", BehaviorValueProperty(&ClientModels::GameInfo::ServerPort)) 
			;
		
			behaviorContext->Class<ClientModels::CurrentGamesResult>("PlayFabClient_CurrentGamesResult")
                ->Constructor() 
			    ->Property("Games", BehaviorValueProperty(&ClientModels::CurrentGamesResult::Games)) 
			    ->Property("PlayerCount", BehaviorValueProperty(&ClientModels::CurrentGamesResult::PlayerCount)) 
			    ->Property("GameCount", BehaviorValueProperty(&ClientModels::CurrentGamesResult::GameCount)) 
			;
		
			behaviorContext->Class<ClientModels::EmptyResult>("PlayFabClient_EmptyResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<ClientModels::ExecuteCloudScriptRequest>("PlayFabClient_ExecuteCloudScriptRequest")
                ->Constructor() 
			    ->Property("FunctionName", BehaviorValueProperty(&ClientModels::ExecuteCloudScriptRequest::FunctionName)) 
			    ->Property("FunctionParameter", BehaviorValueProperty(&ClientModels::ExecuteCloudScriptRequest::FunctionParameter)) 
			    ->Property("RevisionSelection", BehaviorValueProperty(&ClientModels::ExecuteCloudScriptRequest::RevisionSelection)) 
			    ->Property("SpecificRevision", BehaviorValueProperty(&ClientModels::ExecuteCloudScriptRequest::SpecificRevision)) 
			    ->Property("GeneratePlayStreamEvent", BehaviorValueProperty(&ClientModels::ExecuteCloudScriptRequest::GeneratePlayStreamEvent)) 
			;
		
			behaviorContext->Class<ClientModels::LogStatement>("PlayFabClient_LogStatement")
                ->Constructor() 
			    ->Property("Level", BehaviorValueProperty(&ClientModels::LogStatement::Level)) 
			    ->Property("Message", BehaviorValueProperty(&ClientModels::LogStatement::Message)) 
			    ->Property("Data", BehaviorValueProperty(&ClientModels::LogStatement::Data)) 
			;
		
			behaviorContext->Class<ClientModels::ScriptExecutionError>("PlayFabClient_ScriptExecutionError")
                ->Constructor() 
			    ->Property("Error", BehaviorValueProperty(&ClientModels::ScriptExecutionError::Error)) 
			    ->Property("Message", BehaviorValueProperty(&ClientModels::ScriptExecutionError::Message)) 
			    ->Property("StackTrace", BehaviorValueProperty(&ClientModels::ScriptExecutionError::StackTrace)) 
			;
		
			behaviorContext->Class<ClientModels::ExecuteCloudScriptResult>("PlayFabClient_ExecuteCloudScriptResult")
                ->Constructor() 
			    ->Property("FunctionName", BehaviorValueProperty(&ClientModels::ExecuteCloudScriptResult::FunctionName)) 
			    ->Property("Revision", BehaviorValueProperty(&ClientModels::ExecuteCloudScriptResult::Revision)) 
			    ->Property("FunctionResult", BehaviorValueProperty(&ClientModels::ExecuteCloudScriptResult::FunctionResult)) 
			    ->Property("FunctionResultTooLarge", BehaviorValueProperty(&ClientModels::ExecuteCloudScriptResult::FunctionResultTooLarge)) 
			    ->Property("Logs", BehaviorValueProperty(&ClientModels::ExecuteCloudScriptResult::Logs)) 
			    ->Property("LogsTooLarge", BehaviorValueProperty(&ClientModels::ExecuteCloudScriptResult::LogsTooLarge)) 
			    ->Property("ExecutionTimeSeconds", BehaviorValueProperty(&ClientModels::ExecuteCloudScriptResult::ExecutionTimeSeconds)) 
			    ->Property("ProcessorTimeSeconds", BehaviorValueProperty(&ClientModels::ExecuteCloudScriptResult::ProcessorTimeSeconds)) 
			    ->Property("MemoryConsumedBytes", BehaviorValueProperty(&ClientModels::ExecuteCloudScriptResult::MemoryConsumedBytes)) 
			    ->Property("APIRequestsIssued", BehaviorValueProperty(&ClientModels::ExecuteCloudScriptResult::APIRequestsIssued)) 
			    ->Property("HttpRequestsIssued", BehaviorValueProperty(&ClientModels::ExecuteCloudScriptResult::HttpRequestsIssued)) 
			    ->Property("Error", BehaviorValueProperty(&ClientModels::ExecuteCloudScriptResult::Error)) 
			;
		
			behaviorContext->Class<ClientModels::FacebookPlayFabIdPair>("PlayFabClient_FacebookPlayFabIdPair")
                ->Constructor() 
			    ->Property("FacebookId", BehaviorValueProperty(&ClientModels::FacebookPlayFabIdPair::FacebookId)) 
			    ->Property("PlayFabId", BehaviorValueProperty(&ClientModels::FacebookPlayFabIdPair::PlayFabId)) 
			;
		
			behaviorContext->Class<ClientModels::UserFacebookInfo>("PlayFabClient_UserFacebookInfo")
                ->Constructor() 
			    ->Property("FacebookId", BehaviorValueProperty(&ClientModels::UserFacebookInfo::FacebookId)) 
			    ->Property("FullName", BehaviorValueProperty(&ClientModels::UserFacebookInfo::FullName)) 
			;
		
			behaviorContext->Class<ClientModels::UserSteamInfo>("PlayFabClient_UserSteamInfo")
                ->Constructor() 
			    ->Property("SteamId", BehaviorValueProperty(&ClientModels::UserSteamInfo::SteamId)) 
			    ->Property("SteamCountry", BehaviorValueProperty(&ClientModels::UserSteamInfo::SteamCountry)) 
			    ->Property("SteamCurrency", BehaviorValueProperty(&ClientModels::UserSteamInfo::SteamCurrency)) 
			    ->Property("SteamActivationStatus", BehaviorValueProperty(&ClientModels::UserSteamInfo::SteamActivationStatus)) 
			;
		
			behaviorContext->Class<ClientModels::UserGameCenterInfo>("PlayFabClient_UserGameCenterInfo")
                ->Constructor() 
			    ->Property("GameCenterId", BehaviorValueProperty(&ClientModels::UserGameCenterInfo::GameCenterId)) 
			;
		
			behaviorContext->Class<ClientModels::LocationModel>("PlayFabClient_LocationModel")
                ->Constructor() 
			    ->Property("pfContinentCode", BehaviorValueProperty(&ClientModels::LocationModel::pfContinentCode)) 
			    ->Property("pfCountryCode", BehaviorValueProperty(&ClientModels::LocationModel::pfCountryCode)) 
			    ->Property("City", BehaviorValueProperty(&ClientModels::LocationModel::City)) 
			    ->Property("Latitude", BehaviorValueProperty(&ClientModels::LocationModel::Latitude)) 
			    ->Property("Longitude", BehaviorValueProperty(&ClientModels::LocationModel::Longitude)) 
			;
		
			behaviorContext->Class<ClientModels::TagModel>("PlayFabClient_TagModel")
                ->Constructor() 
			    ->Property("TagValue", BehaviorValueProperty(&ClientModels::TagModel::TagValue)) 
			;
		
			behaviorContext->Class<ClientModels::PushNotificationRegistrationModel>("PlayFabClient_PushNotificationRegistrationModel")
                ->Constructor() 
			    ->Property("Platform", BehaviorValueProperty(&ClientModels::PushNotificationRegistrationModel::Platform)) 
			    ->Property("NotificationEndpointARN", BehaviorValueProperty(&ClientModels::PushNotificationRegistrationModel::NotificationEndpointARN)) 
			;
		
			behaviorContext->Class<ClientModels::LinkedPlatformAccountModel>("PlayFabClient_LinkedPlatformAccountModel")
                ->Constructor() 
			    ->Property("Platform", BehaviorValueProperty(&ClientModels::LinkedPlatformAccountModel::Platform)) 
			    ->Property("PlatformUserId", BehaviorValueProperty(&ClientModels::LinkedPlatformAccountModel::PlatformUserId)) 
			    ->Property("Username", BehaviorValueProperty(&ClientModels::LinkedPlatformAccountModel::Username)) 
			    ->Property("Email", BehaviorValueProperty(&ClientModels::LinkedPlatformAccountModel::Email)) 
			;
		
			behaviorContext->Class<ClientModels::ValueToDateModel>("PlayFabClient_ValueToDateModel")
                ->Constructor() 
			    ->Property("Currency", BehaviorValueProperty(&ClientModels::ValueToDateModel::Currency)) 
			    ->Property("TotalValue", BehaviorValueProperty(&ClientModels::ValueToDateModel::TotalValue)) 
			    ->Property("TotalValueAsDecimal", BehaviorValueProperty(&ClientModels::ValueToDateModel::TotalValueAsDecimal)) 
			;
		
			behaviorContext->Class<ClientModels::VirtualCurrencyBalanceModel>("PlayFabClient_VirtualCurrencyBalanceModel")
                ->Constructor() 
			    ->Property("Currency", BehaviorValueProperty(&ClientModels::VirtualCurrencyBalanceModel::Currency)) 
			    ->Property("TotalValue", BehaviorValueProperty(&ClientModels::VirtualCurrencyBalanceModel::TotalValue)) 
			;
		
			behaviorContext->Class<ClientModels::StatisticModel>("PlayFabClient_StatisticModel")
                ->Constructor() 
			    ->Property("Name", BehaviorValueProperty(&ClientModels::StatisticModel::Name)) 
			    ->Property("Version", BehaviorValueProperty(&ClientModels::StatisticModel::Version)) 
			    ->Property("Value", BehaviorValueProperty(&ClientModels::StatisticModel::Value)) 
			;
		
			behaviorContext->Class<ClientModels::PlayerProfileModel>("PlayFabClient_PlayerProfileModel")
                ->Constructor() 
			    ->Property("PublisherId", BehaviorValueProperty(&ClientModels::PlayerProfileModel::PublisherId)) 
			    ->Property("TitleId", BehaviorValueProperty(&ClientModels::PlayerProfileModel::TitleId)) 
			    ->Property("PlayerId", BehaviorValueProperty(&ClientModels::PlayerProfileModel::PlayerId)) 
			    ->Property("Created", BehaviorValueProperty(&ClientModels::PlayerProfileModel::Created)) 
			    ->Property("Origination", BehaviorValueProperty(&ClientModels::PlayerProfileModel::Origination)) 
			    ->Property("LastLogin", BehaviorValueProperty(&ClientModels::PlayerProfileModel::LastLogin)) 
			    ->Property("BannedUntil", BehaviorValueProperty(&ClientModels::PlayerProfileModel::BannedUntil)) 
			    ->Property("Locations", BehaviorValueProperty(&ClientModels::PlayerProfileModel::Locations)) 
			    ->Property("DisplayName", BehaviorValueProperty(&ClientModels::PlayerProfileModel::DisplayName)) 
			    ->Property("AvatarUrl", BehaviorValueProperty(&ClientModels::PlayerProfileModel::AvatarUrl)) 
			    ->Property("Tags", BehaviorValueProperty(&ClientModels::PlayerProfileModel::Tags)) 
			    ->Property("PushNotificationRegistrations", BehaviorValueProperty(&ClientModels::PlayerProfileModel::PushNotificationRegistrations)) 
			    ->Property("LinkedAccounts", BehaviorValueProperty(&ClientModels::PlayerProfileModel::LinkedAccounts)) 
			    ->Property("AdCampaignAttributions", BehaviorValueProperty(&ClientModels::PlayerProfileModel::AdCampaignAttributions)) 
			    ->Property("TotalValueToDateInUSD", BehaviorValueProperty(&ClientModels::PlayerProfileModel::TotalValueToDateInUSD)) 
			    ->Property("ValuesToDate", BehaviorValueProperty(&ClientModels::PlayerProfileModel::ValuesToDate)) 
			    ->Property("VirtualCurrencyBalances", BehaviorValueProperty(&ClientModels::PlayerProfileModel::VirtualCurrencyBalances)) 
			    ->Property("Statistics", BehaviorValueProperty(&ClientModels::PlayerProfileModel::Statistics)) 
			;
		
			behaviorContext->Class<ClientModels::FriendInfo>("PlayFabClient_FriendInfo")
                ->Constructor() 
			    ->Property("FriendPlayFabId", BehaviorValueProperty(&ClientModels::FriendInfo::FriendPlayFabId)) 
			    ->Property("Username", BehaviorValueProperty(&ClientModels::FriendInfo::Username)) 
			    ->Property("TitleDisplayName", BehaviorValueProperty(&ClientModels::FriendInfo::TitleDisplayName)) 
			    ->Property("Tags", BehaviorValueProperty(&ClientModels::FriendInfo::Tags)) 
			    ->Property("CurrentMatchmakerLobbyId", BehaviorValueProperty(&ClientModels::FriendInfo::CurrentMatchmakerLobbyId)) 
			    ->Property("FacebookInfo", BehaviorValueProperty(&ClientModels::FriendInfo::FacebookInfo)) 
			    ->Property("SteamInfo", BehaviorValueProperty(&ClientModels::FriendInfo::SteamInfo)) 
			    ->Property("GameCenterInfo", BehaviorValueProperty(&ClientModels::FriendInfo::GameCenterInfo)) 
			    ->Property("Profile", BehaviorValueProperty(&ClientModels::FriendInfo::Profile)) 
			;
		
			behaviorContext->Class<ClientModels::GameCenterPlayFabIdPair>("PlayFabClient_GameCenterPlayFabIdPair")
                ->Constructor() 
			    ->Property("GameCenterId", BehaviorValueProperty(&ClientModels::GameCenterPlayFabIdPair::GameCenterId)) 
			    ->Property("PlayFabId", BehaviorValueProperty(&ClientModels::GameCenterPlayFabIdPair::PlayFabId)) 
			;
		
			behaviorContext->Class<ClientModels::GameServerRegionsRequest>("PlayFabClient_GameServerRegionsRequest")
                ->Constructor() 
			    ->Property("BuildVersion", BehaviorValueProperty(&ClientModels::GameServerRegionsRequest::BuildVersion)) 
			    ->Property("TitleId", BehaviorValueProperty(&ClientModels::GameServerRegionsRequest::TitleId)) 
			;
		
			behaviorContext->Class<ClientModels::RegionInfo>("PlayFabClient_RegionInfo")
                ->Constructor() 
			    ->Property("pfRegion", BehaviorValueProperty(&ClientModels::RegionInfo::pfRegion)) 
			    ->Property("Name", BehaviorValueProperty(&ClientModels::RegionInfo::Name)) 
			    ->Property("Available", BehaviorValueProperty(&ClientModels::RegionInfo::Available)) 
			    ->Property("PingUrl", BehaviorValueProperty(&ClientModels::RegionInfo::PingUrl)) 
			;
		
			behaviorContext->Class<ClientModels::GameServerRegionsResult>("PlayFabClient_GameServerRegionsResult")
                ->Constructor() 
			    ->Property("Regions", BehaviorValueProperty(&ClientModels::GameServerRegionsResult::Regions)) 
			;
		
			behaviorContext->Class<ClientModels::GenericPlayFabIdPair>("PlayFabClient_GenericPlayFabIdPair")
                ->Constructor() 
			    ->Property("GenericId", BehaviorValueProperty(&ClientModels::GenericPlayFabIdPair::GenericId)) 
			    ->Property("PlayFabId", BehaviorValueProperty(&ClientModels::GenericPlayFabIdPair::PlayFabId)) 
			;
		
			behaviorContext->Class<ClientModels::GetAccountInfoRequest>("PlayFabClient_GetAccountInfoRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ClientModels::GetAccountInfoRequest::PlayFabId)) 
			    ->Property("Username", BehaviorValueProperty(&ClientModels::GetAccountInfoRequest::Username)) 
			    ->Property("Email", BehaviorValueProperty(&ClientModels::GetAccountInfoRequest::Email)) 
			    ->Property("TitleDisplayName", BehaviorValueProperty(&ClientModels::GetAccountInfoRequest::TitleDisplayName)) 
			;
		
			behaviorContext->Class<ClientModels::UserTitleInfo>("PlayFabClient_UserTitleInfo")
                ->Constructor() 
			    ->Property("DisplayName", BehaviorValueProperty(&ClientModels::UserTitleInfo::DisplayName)) 
			    ->Property("Origination", BehaviorValueProperty(&ClientModels::UserTitleInfo::Origination)) 
			    ->Property("Created", BehaviorValueProperty(&ClientModels::UserTitleInfo::Created)) 
			    ->Property("LastLogin", BehaviorValueProperty(&ClientModels::UserTitleInfo::LastLogin)) 
			    ->Property("FirstLogin", BehaviorValueProperty(&ClientModels::UserTitleInfo::FirstLogin)) 
			    ->Property("isBanned", BehaviorValueProperty(&ClientModels::UserTitleInfo::isBanned)) 
			    ->Property("AvatarUrl", BehaviorValueProperty(&ClientModels::UserTitleInfo::AvatarUrl)) 
			;
		
			behaviorContext->Class<ClientModels::UserPrivateAccountInfo>("PlayFabClient_UserPrivateAccountInfo")
                ->Constructor() 
			    ->Property("Email", BehaviorValueProperty(&ClientModels::UserPrivateAccountInfo::Email)) 
			;
		
			behaviorContext->Class<ClientModels::UserIosDeviceInfo>("PlayFabClient_UserIosDeviceInfo")
                ->Constructor() 
			    ->Property("IosDeviceId", BehaviorValueProperty(&ClientModels::UserIosDeviceInfo::IosDeviceId)) 
			;
		
			behaviorContext->Class<ClientModels::UserAndroidDeviceInfo>("PlayFabClient_UserAndroidDeviceInfo")
                ->Constructor() 
			    ->Property("AndroidDeviceId", BehaviorValueProperty(&ClientModels::UserAndroidDeviceInfo::AndroidDeviceId)) 
			;
		
			behaviorContext->Class<ClientModels::UserKongregateInfo>("PlayFabClient_UserKongregateInfo")
                ->Constructor() 
			    ->Property("KongregateId", BehaviorValueProperty(&ClientModels::UserKongregateInfo::KongregateId)) 
			    ->Property("KongregateName", BehaviorValueProperty(&ClientModels::UserKongregateInfo::KongregateName)) 
			;
		
			behaviorContext->Class<ClientModels::UserTwitchInfo>("PlayFabClient_UserTwitchInfo")
                ->Constructor() 
			    ->Property("TwitchId", BehaviorValueProperty(&ClientModels::UserTwitchInfo::TwitchId)) 
			    ->Property("TwitchUserName", BehaviorValueProperty(&ClientModels::UserTwitchInfo::TwitchUserName)) 
			;
		
			behaviorContext->Class<ClientModels::UserPsnInfo>("PlayFabClient_UserPsnInfo")
                ->Constructor() 
			    ->Property("PsnAccountId", BehaviorValueProperty(&ClientModels::UserPsnInfo::PsnAccountId)) 
			    ->Property("PsnOnlineId", BehaviorValueProperty(&ClientModels::UserPsnInfo::PsnOnlineId)) 
			;
		
			behaviorContext->Class<ClientModels::UserGoogleInfo>("PlayFabClient_UserGoogleInfo")
                ->Constructor() 
			    ->Property("GoogleId", BehaviorValueProperty(&ClientModels::UserGoogleInfo::GoogleId)) 
			    ->Property("GoogleEmail", BehaviorValueProperty(&ClientModels::UserGoogleInfo::GoogleEmail)) 
			    ->Property("GoogleLocale", BehaviorValueProperty(&ClientModels::UserGoogleInfo::GoogleLocale)) 
			    ->Property("GoogleGender", BehaviorValueProperty(&ClientModels::UserGoogleInfo::GoogleGender)) 
			;
		
			behaviorContext->Class<ClientModels::UserXboxInfo>("PlayFabClient_UserXboxInfo")
                ->Constructor() 
			    ->Property("XboxUserId", BehaviorValueProperty(&ClientModels::UserXboxInfo::XboxUserId)) 
			;
		
			behaviorContext->Class<ClientModels::UserCustomIdInfo>("PlayFabClient_UserCustomIdInfo")
                ->Constructor() 
			    ->Property("CustomId", BehaviorValueProperty(&ClientModels::UserCustomIdInfo::CustomId)) 
			;
		
			behaviorContext->Class<ClientModels::UserAccountInfo>("PlayFabClient_UserAccountInfo")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ClientModels::UserAccountInfo::PlayFabId)) 
			    ->Property("Created", BehaviorValueProperty(&ClientModels::UserAccountInfo::Created)) 
			    ->Property("Username", BehaviorValueProperty(&ClientModels::UserAccountInfo::Username)) 
			    ->Property("TitleInfo", BehaviorValueProperty(&ClientModels::UserAccountInfo::TitleInfo)) 
			    ->Property("PrivateInfo", BehaviorValueProperty(&ClientModels::UserAccountInfo::PrivateInfo)) 
			    ->Property("FacebookInfo", BehaviorValueProperty(&ClientModels::UserAccountInfo::FacebookInfo)) 
			    ->Property("SteamInfo", BehaviorValueProperty(&ClientModels::UserAccountInfo::SteamInfo)) 
			    ->Property("GameCenterInfo", BehaviorValueProperty(&ClientModels::UserAccountInfo::GameCenterInfo)) 
			    ->Property("IosDeviceInfo", BehaviorValueProperty(&ClientModels::UserAccountInfo::IosDeviceInfo)) 
			    ->Property("AndroidDeviceInfo", BehaviorValueProperty(&ClientModels::UserAccountInfo::AndroidDeviceInfo)) 
			    ->Property("KongregateInfo", BehaviorValueProperty(&ClientModels::UserAccountInfo::KongregateInfo)) 
			    ->Property("TwitchInfo", BehaviorValueProperty(&ClientModels::UserAccountInfo::TwitchInfo)) 
			    ->Property("PsnInfo", BehaviorValueProperty(&ClientModels::UserAccountInfo::PsnInfo)) 
			    ->Property("GoogleInfo", BehaviorValueProperty(&ClientModels::UserAccountInfo::GoogleInfo)) 
			    ->Property("XboxInfo", BehaviorValueProperty(&ClientModels::UserAccountInfo::XboxInfo)) 
			    ->Property("CustomIdInfo", BehaviorValueProperty(&ClientModels::UserAccountInfo::CustomIdInfo)) 
			;
		
			behaviorContext->Class<ClientModels::GetAccountInfoResult>("PlayFabClient_GetAccountInfoResult")
                ->Constructor() 
			    ->Property("AccountInfo", BehaviorValueProperty(&ClientModels::GetAccountInfoResult::AccountInfo)) 
			;
		
			behaviorContext->Class<ClientModels::GetCatalogItemsRequest>("PlayFabClient_GetCatalogItemsRequest")
                ->Constructor() 
			    ->Property("CatalogVersion", BehaviorValueProperty(&ClientModels::GetCatalogItemsRequest::CatalogVersion)) 
			;
		
			behaviorContext->Class<ClientModels::GetCatalogItemsResult>("PlayFabClient_GetCatalogItemsResult")
                ->Constructor() 
			    ->Property("Catalog", BehaviorValueProperty(&ClientModels::GetCatalogItemsResult::Catalog)) 
			;
		
			behaviorContext->Class<ClientModels::GetCharacterDataRequest>("PlayFabClient_GetCharacterDataRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ClientModels::GetCharacterDataRequest::PlayFabId)) 
			    ->Property("CharacterId", BehaviorValueProperty(&ClientModels::GetCharacterDataRequest::CharacterId)) 
			    ->Property("Keys", BehaviorValueProperty(&ClientModels::GetCharacterDataRequest::Keys)) 
			    ->Property("IfChangedFromDataVersion", BehaviorValueProperty(&ClientModels::GetCharacterDataRequest::IfChangedFromDataVersion)) 
			;
		
			behaviorContext->Class<ClientModels::UserDataRecord>("PlayFabClient_UserDataRecord")
                ->Constructor() 
			    ->Property("Value", BehaviorValueProperty(&ClientModels::UserDataRecord::Value)) 
			    ->Property("LastUpdated", BehaviorValueProperty(&ClientModels::UserDataRecord::LastUpdated)) 
			    ->Property("Permission", BehaviorValueProperty(&ClientModels::UserDataRecord::Permission)) 
			;
		
			behaviorContext->Class<ClientModels::GetCharacterDataResult>("PlayFabClient_GetCharacterDataResult")
                ->Constructor() 
			    ->Property("CharacterId", BehaviorValueProperty(&ClientModels::GetCharacterDataResult::CharacterId)) 
			    ->Property("DataVersion", BehaviorValueProperty(&ClientModels::GetCharacterDataResult::DataVersion)) 
			;
		
			behaviorContext->Class<ClientModels::GetCharacterInventoryRequest>("PlayFabClient_GetCharacterInventoryRequest")
                ->Constructor() 
			    ->Property("CharacterId", BehaviorValueProperty(&ClientModels::GetCharacterInventoryRequest::CharacterId)) 
			    ->Property("CatalogVersion", BehaviorValueProperty(&ClientModels::GetCharacterInventoryRequest::CatalogVersion)) 
			;
		
			behaviorContext->Class<ClientModels::VirtualCurrencyRechargeTime>("PlayFabClient_VirtualCurrencyRechargeTime")
                ->Constructor() 
			    ->Property("SecondsToRecharge", BehaviorValueProperty(&ClientModels::VirtualCurrencyRechargeTime::SecondsToRecharge)) 
			    ->Property("RechargeTime", BehaviorValueProperty(&ClientModels::VirtualCurrencyRechargeTime::RechargeTime)) 
			    ->Property("RechargeMax", BehaviorValueProperty(&ClientModels::VirtualCurrencyRechargeTime::RechargeMax)) 
			;
		
			behaviorContext->Class<ClientModels::GetCharacterInventoryResult>("PlayFabClient_GetCharacterInventoryResult")
                ->Constructor() 
			    ->Property("CharacterId", BehaviorValueProperty(&ClientModels::GetCharacterInventoryResult::CharacterId)) 
			    ->Property("Inventory", BehaviorValueProperty(&ClientModels::GetCharacterInventoryResult::Inventory)) 
			;
		
			behaviorContext->Class<ClientModels::GetCharacterLeaderboardRequest>("PlayFabClient_GetCharacterLeaderboardRequest")
                ->Constructor() 
			    ->Property("CharacterType", BehaviorValueProperty(&ClientModels::GetCharacterLeaderboardRequest::CharacterType)) 
			    ->Property("StatisticName", BehaviorValueProperty(&ClientModels::GetCharacterLeaderboardRequest::StatisticName)) 
			    ->Property("StartPosition", BehaviorValueProperty(&ClientModels::GetCharacterLeaderboardRequest::StartPosition)) 
			    ->Property("MaxResultsCount", BehaviorValueProperty(&ClientModels::GetCharacterLeaderboardRequest::MaxResultsCount)) 
			;
		
			behaviorContext->Class<ClientModels::GetCharacterLeaderboardResult>("PlayFabClient_GetCharacterLeaderboardResult")
                ->Constructor() 
			    ->Property("Leaderboard", BehaviorValueProperty(&ClientModels::GetCharacterLeaderboardResult::Leaderboard)) 
			;
		
			behaviorContext->Class<ClientModels::GetCharacterStatisticsRequest>("PlayFabClient_GetCharacterStatisticsRequest")
                ->Constructor() 
			    ->Property("CharacterId", BehaviorValueProperty(&ClientModels::GetCharacterStatisticsRequest::CharacterId)) 
			;
		
			behaviorContext->Class<ClientModels::GetCharacterStatisticsResult>("PlayFabClient_GetCharacterStatisticsResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<ClientModels::GetContentDownloadUrlRequest>("PlayFabClient_GetContentDownloadUrlRequest")
                ->Constructor() 
			    ->Property("Key", BehaviorValueProperty(&ClientModels::GetContentDownloadUrlRequest::Key)) 
			    ->Property("HttpMethod", BehaviorValueProperty(&ClientModels::GetContentDownloadUrlRequest::HttpMethod)) 
			    ->Property("ThruCDN", BehaviorValueProperty(&ClientModels::GetContentDownloadUrlRequest::ThruCDN)) 
			;
		
			behaviorContext->Class<ClientModels::GetContentDownloadUrlResult>("PlayFabClient_GetContentDownloadUrlResult")
                ->Constructor() 
			    ->Property("URL", BehaviorValueProperty(&ClientModels::GetContentDownloadUrlResult::URL)) 
			;
		
			behaviorContext->Class<ClientModels::PlayerProfileViewConstraints>("PlayFabClient_PlayerProfileViewConstraints")
                ->Constructor() 
			    ->Property("ShowDisplayName", BehaviorValueProperty(&ClientModels::PlayerProfileViewConstraints::ShowDisplayName)) 
			    ->Property("ShowCreated", BehaviorValueProperty(&ClientModels::PlayerProfileViewConstraints::ShowCreated)) 
			    ->Property("ShowOrigination", BehaviorValueProperty(&ClientModels::PlayerProfileViewConstraints::ShowOrigination)) 
			    ->Property("ShowLastLogin", BehaviorValueProperty(&ClientModels::PlayerProfileViewConstraints::ShowLastLogin)) 
			    ->Property("ShowBannedUntil", BehaviorValueProperty(&ClientModels::PlayerProfileViewConstraints::ShowBannedUntil)) 
			    ->Property("ShowStatistics", BehaviorValueProperty(&ClientModels::PlayerProfileViewConstraints::ShowStatistics)) 
			    ->Property("ShowCampaignAttributions", BehaviorValueProperty(&ClientModels::PlayerProfileViewConstraints::ShowCampaignAttributions)) 
			    ->Property("ShowPushNotificationRegistrations", BehaviorValueProperty(&ClientModels::PlayerProfileViewConstraints::ShowPushNotificationRegistrations)) 
			    ->Property("ShowLinkedAccounts", BehaviorValueProperty(&ClientModels::PlayerProfileViewConstraints::ShowLinkedAccounts)) 
			    ->Property("ShowTotalValueToDateInUsd", BehaviorValueProperty(&ClientModels::PlayerProfileViewConstraints::ShowTotalValueToDateInUsd)) 
			    ->Property("ShowValuesToDate", BehaviorValueProperty(&ClientModels::PlayerProfileViewConstraints::ShowValuesToDate)) 
			    ->Property("ShowTags", BehaviorValueProperty(&ClientModels::PlayerProfileViewConstraints::ShowTags)) 
			    ->Property("ShowLocations", BehaviorValueProperty(&ClientModels::PlayerProfileViewConstraints::ShowLocations)) 
			    ->Property("ShowAvatarUrl", BehaviorValueProperty(&ClientModels::PlayerProfileViewConstraints::ShowAvatarUrl)) 
			;
		
			behaviorContext->Class<ClientModels::GetFriendLeaderboardAroundPlayerRequest>("PlayFabClient_GetFriendLeaderboardAroundPlayerRequest")
                ->Constructor() 
			    ->Property("StatisticName", BehaviorValueProperty(&ClientModels::GetFriendLeaderboardAroundPlayerRequest::StatisticName)) 
			    ->Property("MaxResultsCount", BehaviorValueProperty(&ClientModels::GetFriendLeaderboardAroundPlayerRequest::MaxResultsCount)) 
			    ->Property("PlayFabId", BehaviorValueProperty(&ClientModels::GetFriendLeaderboardAroundPlayerRequest::PlayFabId)) 
			    ->Property("IncludeSteamFriends", BehaviorValueProperty(&ClientModels::GetFriendLeaderboardAroundPlayerRequest::IncludeSteamFriends)) 
			    ->Property("IncludeFacebookFriends", BehaviorValueProperty(&ClientModels::GetFriendLeaderboardAroundPlayerRequest::IncludeFacebookFriends)) 
			    ->Property("Version", BehaviorValueProperty(&ClientModels::GetFriendLeaderboardAroundPlayerRequest::Version)) 
			    ->Property("ProfileConstraints", BehaviorValueProperty(&ClientModels::GetFriendLeaderboardAroundPlayerRequest::ProfileConstraints)) 
			;
		
			behaviorContext->Class<ClientModels::PlayerLeaderboardEntry>("PlayFabClient_PlayerLeaderboardEntry")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ClientModels::PlayerLeaderboardEntry::PlayFabId)) 
			    ->Property("DisplayName", BehaviorValueProperty(&ClientModels::PlayerLeaderboardEntry::DisplayName)) 
			    ->Property("StatValue", BehaviorValueProperty(&ClientModels::PlayerLeaderboardEntry::StatValue)) 
			    ->Property("Position", BehaviorValueProperty(&ClientModels::PlayerLeaderboardEntry::Position)) 
			    ->Property("Profile", BehaviorValueProperty(&ClientModels::PlayerLeaderboardEntry::Profile)) 
			;
		
			behaviorContext->Class<ClientModels::GetFriendLeaderboardAroundPlayerResult>("PlayFabClient_GetFriendLeaderboardAroundPlayerResult")
                ->Constructor() 
			    ->Property("Leaderboard", BehaviorValueProperty(&ClientModels::GetFriendLeaderboardAroundPlayerResult::Leaderboard)) 
			    ->Property("Version", BehaviorValueProperty(&ClientModels::GetFriendLeaderboardAroundPlayerResult::Version)) 
			    ->Property("NextReset", BehaviorValueProperty(&ClientModels::GetFriendLeaderboardAroundPlayerResult::NextReset)) 
			;
		
			behaviorContext->Class<ClientModels::GetFriendLeaderboardRequest>("PlayFabClient_GetFriendLeaderboardRequest")
                ->Constructor() 
			    ->Property("StatisticName", BehaviorValueProperty(&ClientModels::GetFriendLeaderboardRequest::StatisticName)) 
			    ->Property("StartPosition", BehaviorValueProperty(&ClientModels::GetFriendLeaderboardRequest::StartPosition)) 
			    ->Property("MaxResultsCount", BehaviorValueProperty(&ClientModels::GetFriendLeaderboardRequest::MaxResultsCount)) 
			    ->Property("IncludeSteamFriends", BehaviorValueProperty(&ClientModels::GetFriendLeaderboardRequest::IncludeSteamFriends)) 
			    ->Property("IncludeFacebookFriends", BehaviorValueProperty(&ClientModels::GetFriendLeaderboardRequest::IncludeFacebookFriends)) 
			    ->Property("Version", BehaviorValueProperty(&ClientModels::GetFriendLeaderboardRequest::Version)) 
			    ->Property("ProfileConstraints", BehaviorValueProperty(&ClientModels::GetFriendLeaderboardRequest::ProfileConstraints)) 
			;
		
			behaviorContext->Class<ClientModels::GetFriendsListRequest>("PlayFabClient_GetFriendsListRequest")
                ->Constructor() 
			    ->Property("IncludeSteamFriends", BehaviorValueProperty(&ClientModels::GetFriendsListRequest::IncludeSteamFriends)) 
			    ->Property("IncludeFacebookFriends", BehaviorValueProperty(&ClientModels::GetFriendsListRequest::IncludeFacebookFriends)) 
			    ->Property("ProfileConstraints", BehaviorValueProperty(&ClientModels::GetFriendsListRequest::ProfileConstraints)) 
			;
		
			behaviorContext->Class<ClientModels::GetFriendsListResult>("PlayFabClient_GetFriendsListResult")
                ->Constructor() 
			    ->Property("Friends", BehaviorValueProperty(&ClientModels::GetFriendsListResult::Friends)) 
			;
		
			behaviorContext->Class<ClientModels::GetLeaderboardAroundCharacterRequest>("PlayFabClient_GetLeaderboardAroundCharacterRequest")
                ->Constructor() 
			    ->Property("StatisticName", BehaviorValueProperty(&ClientModels::GetLeaderboardAroundCharacterRequest::StatisticName)) 
			    ->Property("CharacterId", BehaviorValueProperty(&ClientModels::GetLeaderboardAroundCharacterRequest::CharacterId)) 
			    ->Property("CharacterType", BehaviorValueProperty(&ClientModels::GetLeaderboardAroundCharacterRequest::CharacterType)) 
			    ->Property("MaxResultsCount", BehaviorValueProperty(&ClientModels::GetLeaderboardAroundCharacterRequest::MaxResultsCount)) 
			;
		
			behaviorContext->Class<ClientModels::GetLeaderboardAroundCharacterResult>("PlayFabClient_GetLeaderboardAroundCharacterResult")
                ->Constructor() 
			    ->Property("Leaderboard", BehaviorValueProperty(&ClientModels::GetLeaderboardAroundCharacterResult::Leaderboard)) 
			;
		
			behaviorContext->Class<ClientModels::GetLeaderboardAroundPlayerRequest>("PlayFabClient_GetLeaderboardAroundPlayerRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ClientModels::GetLeaderboardAroundPlayerRequest::PlayFabId)) 
			    ->Property("StatisticName", BehaviorValueProperty(&ClientModels::GetLeaderboardAroundPlayerRequest::StatisticName)) 
			    ->Property("MaxResultsCount", BehaviorValueProperty(&ClientModels::GetLeaderboardAroundPlayerRequest::MaxResultsCount)) 
			    ->Property("Version", BehaviorValueProperty(&ClientModels::GetLeaderboardAroundPlayerRequest::Version)) 
			    ->Property("ProfileConstraints", BehaviorValueProperty(&ClientModels::GetLeaderboardAroundPlayerRequest::ProfileConstraints)) 
			;
		
			behaviorContext->Class<ClientModels::GetLeaderboardAroundPlayerResult>("PlayFabClient_GetLeaderboardAroundPlayerResult")
                ->Constructor() 
			    ->Property("Leaderboard", BehaviorValueProperty(&ClientModels::GetLeaderboardAroundPlayerResult::Leaderboard)) 
			    ->Property("Version", BehaviorValueProperty(&ClientModels::GetLeaderboardAroundPlayerResult::Version)) 
			    ->Property("NextReset", BehaviorValueProperty(&ClientModels::GetLeaderboardAroundPlayerResult::NextReset)) 
			;
		
			behaviorContext->Class<ClientModels::GetLeaderboardForUsersCharactersRequest>("PlayFabClient_GetLeaderboardForUsersCharactersRequest")
                ->Constructor() 
			    ->Property("StatisticName", BehaviorValueProperty(&ClientModels::GetLeaderboardForUsersCharactersRequest::StatisticName)) 
			    ->Property("MaxResultsCount", BehaviorValueProperty(&ClientModels::GetLeaderboardForUsersCharactersRequest::MaxResultsCount)) 
			;
		
			behaviorContext->Class<ClientModels::GetLeaderboardForUsersCharactersResult>("PlayFabClient_GetLeaderboardForUsersCharactersResult")
                ->Constructor() 
			    ->Property("Leaderboard", BehaviorValueProperty(&ClientModels::GetLeaderboardForUsersCharactersResult::Leaderboard)) 
			;
		
			behaviorContext->Class<ClientModels::GetLeaderboardRequest>("PlayFabClient_GetLeaderboardRequest")
                ->Constructor() 
			    ->Property("StatisticName", BehaviorValueProperty(&ClientModels::GetLeaderboardRequest::StatisticName)) 
			    ->Property("StartPosition", BehaviorValueProperty(&ClientModels::GetLeaderboardRequest::StartPosition)) 
			    ->Property("MaxResultsCount", BehaviorValueProperty(&ClientModels::GetLeaderboardRequest::MaxResultsCount)) 
			    ->Property("Version", BehaviorValueProperty(&ClientModels::GetLeaderboardRequest::Version)) 
			    ->Property("ProfileConstraints", BehaviorValueProperty(&ClientModels::GetLeaderboardRequest::ProfileConstraints)) 
			;
		
			behaviorContext->Class<ClientModels::GetLeaderboardResult>("PlayFabClient_GetLeaderboardResult")
                ->Constructor() 
			    ->Property("Leaderboard", BehaviorValueProperty(&ClientModels::GetLeaderboardResult::Leaderboard)) 
			    ->Property("Version", BehaviorValueProperty(&ClientModels::GetLeaderboardResult::Version)) 
			    ->Property("NextReset", BehaviorValueProperty(&ClientModels::GetLeaderboardResult::NextReset)) 
			;
		
			behaviorContext->Class<ClientModels::GetPhotonAuthenticationTokenRequest>("PlayFabClient_GetPhotonAuthenticationTokenRequest")
                ->Constructor() 
			    ->Property("PhotonApplicationId", BehaviorValueProperty(&ClientModels::GetPhotonAuthenticationTokenRequest::PhotonApplicationId)) 
			;
		
			behaviorContext->Class<ClientModels::GetPhotonAuthenticationTokenResult>("PlayFabClient_GetPhotonAuthenticationTokenResult")
                ->Constructor() 
			    ->Property("PhotonCustomAuthenticationToken", BehaviorValueProperty(&ClientModels::GetPhotonAuthenticationTokenResult::PhotonCustomAuthenticationToken)) 
			;
		
			behaviorContext->Class<ClientModels::GetPlayerCombinedInfoRequestParams>("PlayFabClient_GetPlayerCombinedInfoRequestParams")
                ->Constructor() 
			    ->Property("GetUserAccountInfo", BehaviorValueProperty(&ClientModels::GetPlayerCombinedInfoRequestParams::GetUserAccountInfo)) 
			    ->Property("GetUserInventory", BehaviorValueProperty(&ClientModels::GetPlayerCombinedInfoRequestParams::GetUserInventory)) 
			    ->Property("GetUserVirtualCurrency", BehaviorValueProperty(&ClientModels::GetPlayerCombinedInfoRequestParams::GetUserVirtualCurrency)) 
			    ->Property("GetUserData", BehaviorValueProperty(&ClientModels::GetPlayerCombinedInfoRequestParams::GetUserData)) 
			    ->Property("UserDataKeys", BehaviorValueProperty(&ClientModels::GetPlayerCombinedInfoRequestParams::UserDataKeys)) 
			    ->Property("GetUserReadOnlyData", BehaviorValueProperty(&ClientModels::GetPlayerCombinedInfoRequestParams::GetUserReadOnlyData)) 
			    ->Property("UserReadOnlyDataKeys", BehaviorValueProperty(&ClientModels::GetPlayerCombinedInfoRequestParams::UserReadOnlyDataKeys)) 
			    ->Property("GetCharacterInventories", BehaviorValueProperty(&ClientModels::GetPlayerCombinedInfoRequestParams::GetCharacterInventories)) 
			    ->Property("GetCharacterList", BehaviorValueProperty(&ClientModels::GetPlayerCombinedInfoRequestParams::GetCharacterList)) 
			    ->Property("GetTitleData", BehaviorValueProperty(&ClientModels::GetPlayerCombinedInfoRequestParams::GetTitleData)) 
			    ->Property("TitleDataKeys", BehaviorValueProperty(&ClientModels::GetPlayerCombinedInfoRequestParams::TitleDataKeys)) 
			    ->Property("GetPlayerStatistics", BehaviorValueProperty(&ClientModels::GetPlayerCombinedInfoRequestParams::GetPlayerStatistics)) 
			    ->Property("PlayerStatisticNames", BehaviorValueProperty(&ClientModels::GetPlayerCombinedInfoRequestParams::PlayerStatisticNames)) 
			    ->Property("GetPlayerProfile", BehaviorValueProperty(&ClientModels::GetPlayerCombinedInfoRequestParams::GetPlayerProfile)) 
			    ->Property("ProfileConstraints", BehaviorValueProperty(&ClientModels::GetPlayerCombinedInfoRequestParams::ProfileConstraints)) 
			;
		
			behaviorContext->Class<ClientModels::GetPlayerCombinedInfoRequest>("PlayFabClient_GetPlayerCombinedInfoRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ClientModels::GetPlayerCombinedInfoRequest::PlayFabId)) 
			    ->Property("InfoRequestParameters", BehaviorValueProperty(&ClientModels::GetPlayerCombinedInfoRequest::InfoRequestParameters)) 
			;
		
			behaviorContext->Class<ClientModels::StatisticValue>("PlayFabClient_StatisticValue")
                ->Constructor() 
			    ->Property("StatisticName", BehaviorValueProperty(&ClientModels::StatisticValue::StatisticName)) 
			    ->Property("Value", BehaviorValueProperty(&ClientModels::StatisticValue::Value)) 
			    ->Property("Version", BehaviorValueProperty(&ClientModels::StatisticValue::Version)) 
			;
		
			behaviorContext->Class<ClientModels::GetPlayerCombinedInfoResultPayload>("PlayFabClient_GetPlayerCombinedInfoResultPayload")
                ->Constructor() 
			    ->Property("AccountInfo", BehaviorValueProperty(&ClientModels::GetPlayerCombinedInfoResultPayload::AccountInfo)) 
			    ->Property("UserInventory", BehaviorValueProperty(&ClientModels::GetPlayerCombinedInfoResultPayload::UserInventory)) 
			    ->Property("UserDataVersion", BehaviorValueProperty(&ClientModels::GetPlayerCombinedInfoResultPayload::UserDataVersion)) 
			    ->Property("UserReadOnlyDataVersion", BehaviorValueProperty(&ClientModels::GetPlayerCombinedInfoResultPayload::UserReadOnlyDataVersion)) 
			    ->Property("CharacterList", BehaviorValueProperty(&ClientModels::GetPlayerCombinedInfoResultPayload::CharacterList)) 
			    ->Property("CharacterInventories", BehaviorValueProperty(&ClientModels::GetPlayerCombinedInfoResultPayload::CharacterInventories)) 
			    ->Property("PlayerStatistics", BehaviorValueProperty(&ClientModels::GetPlayerCombinedInfoResultPayload::PlayerStatistics)) 
			    ->Property("PlayerProfile", BehaviorValueProperty(&ClientModels::GetPlayerCombinedInfoResultPayload::PlayerProfile)) 
			;
		
			behaviorContext->Class<ClientModels::GetPlayerCombinedInfoResult>("PlayFabClient_GetPlayerCombinedInfoResult")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ClientModels::GetPlayerCombinedInfoResult::PlayFabId)) 
			    ->Property("InfoResultPayload", BehaviorValueProperty(&ClientModels::GetPlayerCombinedInfoResult::InfoResultPayload)) 
			;
		
			behaviorContext->Class<ClientModels::GetPlayerProfileRequest>("PlayFabClient_GetPlayerProfileRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ClientModels::GetPlayerProfileRequest::PlayFabId)) 
			    ->Property("ProfileConstraints", BehaviorValueProperty(&ClientModels::GetPlayerProfileRequest::ProfileConstraints)) 
			;
		
			behaviorContext->Class<ClientModels::GetPlayerProfileResult>("PlayFabClient_GetPlayerProfileResult")
                ->Constructor() 
			    ->Property("PlayerProfile", BehaviorValueProperty(&ClientModels::GetPlayerProfileResult::PlayerProfile)) 
			;
		
			behaviorContext->Class<ClientModels::GetPlayerSegmentsRequest>("PlayFabClient_GetPlayerSegmentsRequest")
                ->Constructor() 
			;
		
			behaviorContext->Class<ClientModels::GetSegmentResult>("PlayFabClient_GetSegmentResult")
                ->Constructor() 
			    ->Property("Id", BehaviorValueProperty(&ClientModels::GetSegmentResult::Id)) 
			    ->Property("Name", BehaviorValueProperty(&ClientModels::GetSegmentResult::Name)) 
			    ->Property("ABTestParent", BehaviorValueProperty(&ClientModels::GetSegmentResult::ABTestParent)) 
			;
		
			behaviorContext->Class<ClientModels::GetPlayerSegmentsResult>("PlayFabClient_GetPlayerSegmentsResult")
                ->Constructor() 
			    ->Property("Segments", BehaviorValueProperty(&ClientModels::GetPlayerSegmentsResult::Segments)) 
			;
		
			behaviorContext->Class<ClientModels::StatisticNameVersion>("PlayFabClient_StatisticNameVersion")
                ->Constructor() 
			    ->Property("StatisticName", BehaviorValueProperty(&ClientModels::StatisticNameVersion::StatisticName)) 
			    ->Property("Version", BehaviorValueProperty(&ClientModels::StatisticNameVersion::Version)) 
			;
		
			behaviorContext->Class<ClientModels::GetPlayerStatisticsRequest>("PlayFabClient_GetPlayerStatisticsRequest")
                ->Constructor() 
			    ->Property("StatisticNames", BehaviorValueProperty(&ClientModels::GetPlayerStatisticsRequest::StatisticNames)) 
			    ->Property("StatisticNameVersions", BehaviorValueProperty(&ClientModels::GetPlayerStatisticsRequest::StatisticNameVersions)) 
			;
		
			behaviorContext->Class<ClientModels::GetPlayerStatisticsResult>("PlayFabClient_GetPlayerStatisticsResult")
                ->Constructor() 
			    ->Property("Statistics", BehaviorValueProperty(&ClientModels::GetPlayerStatisticsResult::Statistics)) 
			;
		
			behaviorContext->Class<ClientModels::GetPlayerStatisticVersionsRequest>("PlayFabClient_GetPlayerStatisticVersionsRequest")
                ->Constructor() 
			    ->Property("StatisticName", BehaviorValueProperty(&ClientModels::GetPlayerStatisticVersionsRequest::StatisticName)) 
			;
		
			behaviorContext->Class<ClientModels::PlayerStatisticVersion>("PlayFabClient_PlayerStatisticVersion")
                ->Constructor() 
			    ->Property("StatisticName", BehaviorValueProperty(&ClientModels::PlayerStatisticVersion::StatisticName)) 
			    ->Property("Version", BehaviorValueProperty(&ClientModels::PlayerStatisticVersion::Version)) 
			    ->Property("ScheduledActivationTime", BehaviorValueProperty(&ClientModels::PlayerStatisticVersion::ScheduledActivationTime)) 
			    ->Property("ActivationTime", BehaviorValueProperty(&ClientModels::PlayerStatisticVersion::ActivationTime)) 
			    ->Property("ScheduledDeactivationTime", BehaviorValueProperty(&ClientModels::PlayerStatisticVersion::ScheduledDeactivationTime)) 
			    ->Property("DeactivationTime", BehaviorValueProperty(&ClientModels::PlayerStatisticVersion::DeactivationTime)) 
			;
		
			behaviorContext->Class<ClientModels::GetPlayerStatisticVersionsResult>("PlayFabClient_GetPlayerStatisticVersionsResult")
                ->Constructor() 
			    ->Property("StatisticVersions", BehaviorValueProperty(&ClientModels::GetPlayerStatisticVersionsResult::StatisticVersions)) 
			;
		
			behaviorContext->Class<ClientModels::GetPlayerTagsRequest>("PlayFabClient_GetPlayerTagsRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ClientModels::GetPlayerTagsRequest::PlayFabId)) 
			    ->Property("Namespace", BehaviorValueProperty(&ClientModels::GetPlayerTagsRequest::Namespace)) 
			;
		
			behaviorContext->Class<ClientModels::GetPlayerTagsResult>("PlayFabClient_GetPlayerTagsResult")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ClientModels::GetPlayerTagsResult::PlayFabId)) 
			    ->Property("Tags", BehaviorValueProperty(&ClientModels::GetPlayerTagsResult::Tags)) 
			;
		
			behaviorContext->Class<ClientModels::GetPlayerTradesRequest>("PlayFabClient_GetPlayerTradesRequest")
                ->Constructor() 
			    ->Property("StatusFilter", BehaviorValueProperty(&ClientModels::GetPlayerTradesRequest::StatusFilter)) 
			;
		
			behaviorContext->Class<ClientModels::GetPlayerTradesResponse>("PlayFabClient_GetPlayerTradesResponse")
                ->Constructor() 
			    ->Property("OpenedTrades", BehaviorValueProperty(&ClientModels::GetPlayerTradesResponse::OpenedTrades)) 
			    ->Property("AcceptedTrades", BehaviorValueProperty(&ClientModels::GetPlayerTradesResponse::AcceptedTrades)) 
			;
		
			behaviorContext->Class<ClientModels::GetPlayFabIDsFromFacebookIDsRequest>("PlayFabClient_GetPlayFabIDsFromFacebookIDsRequest")
                ->Constructor() 
			    ->Property("FacebookIDs", BehaviorValueProperty(&ClientModels::GetPlayFabIDsFromFacebookIDsRequest::FacebookIDs)) 
			;
		
			behaviorContext->Class<ClientModels::GetPlayFabIDsFromFacebookIDsResult>("PlayFabClient_GetPlayFabIDsFromFacebookIDsResult")
                ->Constructor() 
			    ->Property("Data", BehaviorValueProperty(&ClientModels::GetPlayFabIDsFromFacebookIDsResult::Data)) 
			;
		
			behaviorContext->Class<ClientModels::GetPlayFabIDsFromGameCenterIDsRequest>("PlayFabClient_GetPlayFabIDsFromGameCenterIDsRequest")
                ->Constructor() 
			    ->Property("GameCenterIDs", BehaviorValueProperty(&ClientModels::GetPlayFabIDsFromGameCenterIDsRequest::GameCenterIDs)) 
			;
		
			behaviorContext->Class<ClientModels::GetPlayFabIDsFromGameCenterIDsResult>("PlayFabClient_GetPlayFabIDsFromGameCenterIDsResult")
                ->Constructor() 
			    ->Property("Data", BehaviorValueProperty(&ClientModels::GetPlayFabIDsFromGameCenterIDsResult::Data)) 
			;
		
			behaviorContext->Class<ClientModels::GetPlayFabIDsFromGenericIDsRequest>("PlayFabClient_GetPlayFabIDsFromGenericIDsRequest")
                ->Constructor() 
			    ->Property("GenericIDs", BehaviorValueProperty(&ClientModels::GetPlayFabIDsFromGenericIDsRequest::GenericIDs)) 
			;
		
			behaviorContext->Class<ClientModels::GetPlayFabIDsFromGenericIDsResult>("PlayFabClient_GetPlayFabIDsFromGenericIDsResult")
                ->Constructor() 
			    ->Property("Data", BehaviorValueProperty(&ClientModels::GetPlayFabIDsFromGenericIDsResult::Data)) 
			;
		
			behaviorContext->Class<ClientModels::GetPlayFabIDsFromGoogleIDsRequest>("PlayFabClient_GetPlayFabIDsFromGoogleIDsRequest")
                ->Constructor() 
			    ->Property("GoogleIDs", BehaviorValueProperty(&ClientModels::GetPlayFabIDsFromGoogleIDsRequest::GoogleIDs)) 
			;
		
			behaviorContext->Class<ClientModels::GooglePlayFabIdPair>("PlayFabClient_GooglePlayFabIdPair")
                ->Constructor() 
			    ->Property("GoogleId", BehaviorValueProperty(&ClientModels::GooglePlayFabIdPair::GoogleId)) 
			    ->Property("PlayFabId", BehaviorValueProperty(&ClientModels::GooglePlayFabIdPair::PlayFabId)) 
			;
		
			behaviorContext->Class<ClientModels::GetPlayFabIDsFromGoogleIDsResult>("PlayFabClient_GetPlayFabIDsFromGoogleIDsResult")
                ->Constructor() 
			    ->Property("Data", BehaviorValueProperty(&ClientModels::GetPlayFabIDsFromGoogleIDsResult::Data)) 
			;
		
			behaviorContext->Class<ClientModels::GetPlayFabIDsFromKongregateIDsRequest>("PlayFabClient_GetPlayFabIDsFromKongregateIDsRequest")
                ->Constructor() 
			    ->Property("KongregateIDs", BehaviorValueProperty(&ClientModels::GetPlayFabIDsFromKongregateIDsRequest::KongregateIDs)) 
			;
		
			behaviorContext->Class<ClientModels::KongregatePlayFabIdPair>("PlayFabClient_KongregatePlayFabIdPair")
                ->Constructor() 
			    ->Property("KongregateId", BehaviorValueProperty(&ClientModels::KongregatePlayFabIdPair::KongregateId)) 
			    ->Property("PlayFabId", BehaviorValueProperty(&ClientModels::KongregatePlayFabIdPair::PlayFabId)) 
			;
		
			behaviorContext->Class<ClientModels::GetPlayFabIDsFromKongregateIDsResult>("PlayFabClient_GetPlayFabIDsFromKongregateIDsResult")
                ->Constructor() 
			    ->Property("Data", BehaviorValueProperty(&ClientModels::GetPlayFabIDsFromKongregateIDsResult::Data)) 
			;
		
			behaviorContext->Class<ClientModels::GetPlayFabIDsFromSteamIDsRequest>("PlayFabClient_GetPlayFabIDsFromSteamIDsRequest")
                ->Constructor() 
			    ->Property("SteamStringIDs", BehaviorValueProperty(&ClientModels::GetPlayFabIDsFromSteamIDsRequest::SteamStringIDs)) 
			;
		
			behaviorContext->Class<ClientModels::SteamPlayFabIdPair>("PlayFabClient_SteamPlayFabIdPair")
                ->Constructor() 
			    ->Property("SteamStringId", BehaviorValueProperty(&ClientModels::SteamPlayFabIdPair::SteamStringId)) 
			    ->Property("PlayFabId", BehaviorValueProperty(&ClientModels::SteamPlayFabIdPair::PlayFabId)) 
			;
		
			behaviorContext->Class<ClientModels::GetPlayFabIDsFromSteamIDsResult>("PlayFabClient_GetPlayFabIDsFromSteamIDsResult")
                ->Constructor() 
			    ->Property("Data", BehaviorValueProperty(&ClientModels::GetPlayFabIDsFromSteamIDsResult::Data)) 
			;
		
			behaviorContext->Class<ClientModels::GetPlayFabIDsFromTwitchIDsRequest>("PlayFabClient_GetPlayFabIDsFromTwitchIDsRequest")
                ->Constructor() 
			    ->Property("TwitchIds", BehaviorValueProperty(&ClientModels::GetPlayFabIDsFromTwitchIDsRequest::TwitchIds)) 
			;
		
			behaviorContext->Class<ClientModels::TwitchPlayFabIdPair>("PlayFabClient_TwitchPlayFabIdPair")
                ->Constructor() 
			    ->Property("TwitchId", BehaviorValueProperty(&ClientModels::TwitchPlayFabIdPair::TwitchId)) 
			    ->Property("PlayFabId", BehaviorValueProperty(&ClientModels::TwitchPlayFabIdPair::PlayFabId)) 
			;
		
			behaviorContext->Class<ClientModels::GetPlayFabIDsFromTwitchIDsResult>("PlayFabClient_GetPlayFabIDsFromTwitchIDsResult")
                ->Constructor() 
			    ->Property("Data", BehaviorValueProperty(&ClientModels::GetPlayFabIDsFromTwitchIDsResult::Data)) 
			;
		
			behaviorContext->Class<ClientModels::GetPublisherDataRequest>("PlayFabClient_GetPublisherDataRequest")
                ->Constructor() 
			    ->Property("Keys", BehaviorValueProperty(&ClientModels::GetPublisherDataRequest::Keys)) 
			;
		
			behaviorContext->Class<ClientModels::GetPublisherDataResult>("PlayFabClient_GetPublisherDataResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<ClientModels::GetPurchaseRequest>("PlayFabClient_GetPurchaseRequest")
                ->Constructor() 
			    ->Property("OrderId", BehaviorValueProperty(&ClientModels::GetPurchaseRequest::OrderId)) 
			;
		
			behaviorContext->Class<ClientModels::GetPurchaseResult>("PlayFabClient_GetPurchaseResult")
                ->Constructor() 
			    ->Property("OrderId", BehaviorValueProperty(&ClientModels::GetPurchaseResult::OrderId)) 
			    ->Property("PaymentProvider", BehaviorValueProperty(&ClientModels::GetPurchaseResult::PaymentProvider)) 
			    ->Property("TransactionId", BehaviorValueProperty(&ClientModels::GetPurchaseResult::TransactionId)) 
			    ->Property("TransactionStatus", BehaviorValueProperty(&ClientModels::GetPurchaseResult::TransactionStatus)) 
			    ->Property("PurchaseDate", BehaviorValueProperty(&ClientModels::GetPurchaseResult::PurchaseDate)) 
			;
		
			behaviorContext->Class<ClientModels::GetSharedGroupDataRequest>("PlayFabClient_GetSharedGroupDataRequest")
                ->Constructor() 
			    ->Property("SharedGroupId", BehaviorValueProperty(&ClientModels::GetSharedGroupDataRequest::SharedGroupId)) 
			    ->Property("Keys", BehaviorValueProperty(&ClientModels::GetSharedGroupDataRequest::Keys)) 
			    ->Property("GetMembers", BehaviorValueProperty(&ClientModels::GetSharedGroupDataRequest::GetMembers)) 
			;
		
			behaviorContext->Class<ClientModels::SharedGroupDataRecord>("PlayFabClient_SharedGroupDataRecord")
                ->Constructor() 
			    ->Property("Value", BehaviorValueProperty(&ClientModels::SharedGroupDataRecord::Value)) 
			    ->Property("LastUpdatedBy", BehaviorValueProperty(&ClientModels::SharedGroupDataRecord::LastUpdatedBy)) 
			    ->Property("LastUpdated", BehaviorValueProperty(&ClientModels::SharedGroupDataRecord::LastUpdated)) 
			    ->Property("Permission", BehaviorValueProperty(&ClientModels::SharedGroupDataRecord::Permission)) 
			;
		
			behaviorContext->Class<ClientModels::GetSharedGroupDataResult>("PlayFabClient_GetSharedGroupDataResult")
                ->Constructor() 
			    ->Property("Members", BehaviorValueProperty(&ClientModels::GetSharedGroupDataResult::Members)) 
			;
		
			behaviorContext->Class<ClientModels::GetStoreItemsRequest>("PlayFabClient_GetStoreItemsRequest")
                ->Constructor() 
			    ->Property("CatalogVersion", BehaviorValueProperty(&ClientModels::GetStoreItemsRequest::CatalogVersion)) 
			    ->Property("StoreId", BehaviorValueProperty(&ClientModels::GetStoreItemsRequest::StoreId)) 
			;
		
			behaviorContext->Class<ClientModels::StoreItem>("PlayFabClient_StoreItem")
                ->Constructor() 
			    ->Property("ItemId", BehaviorValueProperty(&ClientModels::StoreItem::ItemId)) 
			    ->Property("CustomData", BehaviorValueProperty(&ClientModels::StoreItem::CustomData)) 
			    ->Property("DisplayPosition", BehaviorValueProperty(&ClientModels::StoreItem::DisplayPosition)) 
			;
		
			behaviorContext->Class<ClientModels::StoreMarketingModel>("PlayFabClient_StoreMarketingModel")
                ->Constructor() 
			    ->Property("DisplayName", BehaviorValueProperty(&ClientModels::StoreMarketingModel::DisplayName)) 
			    ->Property("Description", BehaviorValueProperty(&ClientModels::StoreMarketingModel::Description)) 
			    ->Property("Metadata", BehaviorValueProperty(&ClientModels::StoreMarketingModel::Metadata)) 
			;
		
			behaviorContext->Class<ClientModels::GetStoreItemsResult>("PlayFabClient_GetStoreItemsResult")
                ->Constructor() 
			    ->Property("Store", BehaviorValueProperty(&ClientModels::GetStoreItemsResult::Store)) 
			    ->Property("Source", BehaviorValueProperty(&ClientModels::GetStoreItemsResult::Source)) 
			    ->Property("CatalogVersion", BehaviorValueProperty(&ClientModels::GetStoreItemsResult::CatalogVersion)) 
			    ->Property("StoreId", BehaviorValueProperty(&ClientModels::GetStoreItemsResult::StoreId)) 
			    ->Property("MarketingData", BehaviorValueProperty(&ClientModels::GetStoreItemsResult::MarketingData)) 
			;
		
			behaviorContext->Class<ClientModels::GetTimeRequest>("PlayFabClient_GetTimeRequest")
                ->Constructor() 
			;
		
			behaviorContext->Class<ClientModels::GetTimeResult>("PlayFabClient_GetTimeResult")
                ->Constructor() 
			    ->Property("Time", BehaviorValueProperty(&ClientModels::GetTimeResult::Time)) 
			;
		
			behaviorContext->Class<ClientModels::GetTitleDataRequest>("PlayFabClient_GetTitleDataRequest")
                ->Constructor() 
			    ->Property("Keys", BehaviorValueProperty(&ClientModels::GetTitleDataRequest::Keys)) 
			;
		
			behaviorContext->Class<ClientModels::GetTitleDataResult>("PlayFabClient_GetTitleDataResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<ClientModels::GetTitleNewsRequest>("PlayFabClient_GetTitleNewsRequest")
                ->Constructor() 
			    ->Property("Count", BehaviorValueProperty(&ClientModels::GetTitleNewsRequest::Count)) 
			;
		
			behaviorContext->Class<ClientModels::TitleNewsItem>("PlayFabClient_TitleNewsItem")
                ->Constructor() 
			    ->Property("Timestamp", BehaviorValueProperty(&ClientModels::TitleNewsItem::Timestamp)) 
			    ->Property("NewsId", BehaviorValueProperty(&ClientModels::TitleNewsItem::NewsId)) 
			    ->Property("Title", BehaviorValueProperty(&ClientModels::TitleNewsItem::Title)) 
			    ->Property("Body", BehaviorValueProperty(&ClientModels::TitleNewsItem::Body)) 
			;
		
			behaviorContext->Class<ClientModels::GetTitleNewsResult>("PlayFabClient_GetTitleNewsResult")
                ->Constructor() 
			    ->Property("News", BehaviorValueProperty(&ClientModels::GetTitleNewsResult::News)) 
			;
		
			behaviorContext->Class<ClientModels::GetTitlePublicKeyRequest>("PlayFabClient_GetTitlePublicKeyRequest")
                ->Constructor() 
			    ->Property("TitleId", BehaviorValueProperty(&ClientModels::GetTitlePublicKeyRequest::TitleId)) 
			    ->Property("TitleSharedSecret", BehaviorValueProperty(&ClientModels::GetTitlePublicKeyRequest::TitleSharedSecret)) 
			;
		
			behaviorContext->Class<ClientModels::GetTitlePublicKeyResult>("PlayFabClient_GetTitlePublicKeyResult")
                ->Constructor() 
			    ->Property("RSAPublicKey", BehaviorValueProperty(&ClientModels::GetTitlePublicKeyResult::RSAPublicKey)) 
			;
		
			behaviorContext->Class<ClientModels::GetTradeStatusRequest>("PlayFabClient_GetTradeStatusRequest")
                ->Constructor() 
			    ->Property("OfferingPlayerId", BehaviorValueProperty(&ClientModels::GetTradeStatusRequest::OfferingPlayerId)) 
			    ->Property("TradeId", BehaviorValueProperty(&ClientModels::GetTradeStatusRequest::TradeId)) 
			;
		
			behaviorContext->Class<ClientModels::GetTradeStatusResponse>("PlayFabClient_GetTradeStatusResponse")
                ->Constructor() 
			    ->Property("Trade", BehaviorValueProperty(&ClientModels::GetTradeStatusResponse::Trade)) 
			;
		
			behaviorContext->Class<ClientModels::GetUserDataRequest>("PlayFabClient_GetUserDataRequest")
                ->Constructor() 
			    ->Property("Keys", BehaviorValueProperty(&ClientModels::GetUserDataRequest::Keys)) 
			    ->Property("PlayFabId", BehaviorValueProperty(&ClientModels::GetUserDataRequest::PlayFabId)) 
			    ->Property("IfChangedFromDataVersion", BehaviorValueProperty(&ClientModels::GetUserDataRequest::IfChangedFromDataVersion)) 
			;
		
			behaviorContext->Class<ClientModels::GetUserDataResult>("PlayFabClient_GetUserDataResult")
                ->Constructor() 
			    ->Property("DataVersion", BehaviorValueProperty(&ClientModels::GetUserDataResult::DataVersion)) 
			;
		
			behaviorContext->Class<ClientModels::GetUserInventoryRequest>("PlayFabClient_GetUserInventoryRequest")
                ->Constructor() 
			;
		
			behaviorContext->Class<ClientModels::GetUserInventoryResult>("PlayFabClient_GetUserInventoryResult")
                ->Constructor() 
			    ->Property("Inventory", BehaviorValueProperty(&ClientModels::GetUserInventoryResult::Inventory)) 
			;
		
			behaviorContext->Class<ClientModels::GetWindowsHelloChallengeRequest>("PlayFabClient_GetWindowsHelloChallengeRequest")
                ->Constructor() 
			    ->Property("TitleId", BehaviorValueProperty(&ClientModels::GetWindowsHelloChallengeRequest::TitleId)) 
			    ->Property("PublicKeyHint", BehaviorValueProperty(&ClientModels::GetWindowsHelloChallengeRequest::PublicKeyHint)) 
			;
		
			behaviorContext->Class<ClientModels::GetWindowsHelloChallengeResponse>("PlayFabClient_GetWindowsHelloChallengeResponse")
                ->Constructor() 
			    ->Property("Challenge", BehaviorValueProperty(&ClientModels::GetWindowsHelloChallengeResponse::Challenge)) 
			;
		
			behaviorContext->Class<ClientModels::GrantCharacterToUserRequest>("PlayFabClient_GrantCharacterToUserRequest")
                ->Constructor() 
			    ->Property("CatalogVersion", BehaviorValueProperty(&ClientModels::GrantCharacterToUserRequest::CatalogVersion)) 
			    ->Property("ItemId", BehaviorValueProperty(&ClientModels::GrantCharacterToUserRequest::ItemId)) 
			    ->Property("CharacterName", BehaviorValueProperty(&ClientModels::GrantCharacterToUserRequest::CharacterName)) 
			;
		
			behaviorContext->Class<ClientModels::GrantCharacterToUserResult>("PlayFabClient_GrantCharacterToUserResult")
                ->Constructor() 
			    ->Property("CharacterId", BehaviorValueProperty(&ClientModels::GrantCharacterToUserResult::CharacterId)) 
			    ->Property("CharacterType", BehaviorValueProperty(&ClientModels::GrantCharacterToUserResult::CharacterType)) 
			    ->Property("Result", BehaviorValueProperty(&ClientModels::GrantCharacterToUserResult::Result)) 
			;
		
			behaviorContext->Class<ClientModels::ItemPurchaseRequest>("PlayFabClient_ItemPurchaseRequest")
                ->Constructor() 
			    ->Property("ItemId", BehaviorValueProperty(&ClientModels::ItemPurchaseRequest::ItemId)) 
			    ->Property("Quantity", BehaviorValueProperty(&ClientModels::ItemPurchaseRequest::Quantity)) 
			    ->Property("Annotation", BehaviorValueProperty(&ClientModels::ItemPurchaseRequest::Annotation)) 
			    ->Property("UpgradeFromItems", BehaviorValueProperty(&ClientModels::ItemPurchaseRequest::UpgradeFromItems)) 
			;
		
			behaviorContext->Class<ClientModels::LinkAndroidDeviceIDRequest>("PlayFabClient_LinkAndroidDeviceIDRequest")
                ->Constructor() 
			    ->Property("AndroidDeviceId", BehaviorValueProperty(&ClientModels::LinkAndroidDeviceIDRequest::AndroidDeviceId)) 
			    ->Property("OS", BehaviorValueProperty(&ClientModels::LinkAndroidDeviceIDRequest::OS)) 
			    ->Property("AndroidDevice", BehaviorValueProperty(&ClientModels::LinkAndroidDeviceIDRequest::AndroidDevice)) 
			    ->Property("ForceLink", BehaviorValueProperty(&ClientModels::LinkAndroidDeviceIDRequest::ForceLink)) 
			;
		
			behaviorContext->Class<ClientModels::LinkAndroidDeviceIDResult>("PlayFabClient_LinkAndroidDeviceIDResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<ClientModels::LinkCustomIDRequest>("PlayFabClient_LinkCustomIDRequest")
                ->Constructor() 
			    ->Property("CustomId", BehaviorValueProperty(&ClientModels::LinkCustomIDRequest::CustomId)) 
			    ->Property("ForceLink", BehaviorValueProperty(&ClientModels::LinkCustomIDRequest::ForceLink)) 
			;
		
			behaviorContext->Class<ClientModels::LinkCustomIDResult>("PlayFabClient_LinkCustomIDResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<ClientModels::LinkFacebookAccountRequest>("PlayFabClient_LinkFacebookAccountRequest")
                ->Constructor() 
			    ->Property("AccessToken", BehaviorValueProperty(&ClientModels::LinkFacebookAccountRequest::AccessToken)) 
			    ->Property("ForceLink", BehaviorValueProperty(&ClientModels::LinkFacebookAccountRequest::ForceLink)) 
			;
		
			behaviorContext->Class<ClientModels::LinkFacebookAccountResult>("PlayFabClient_LinkFacebookAccountResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<ClientModels::LinkGameCenterAccountRequest>("PlayFabClient_LinkGameCenterAccountRequest")
                ->Constructor() 
			    ->Property("GameCenterId", BehaviorValueProperty(&ClientModels::LinkGameCenterAccountRequest::GameCenterId)) 
			    ->Property("ForceLink", BehaviorValueProperty(&ClientModels::LinkGameCenterAccountRequest::ForceLink)) 
			;
		
			behaviorContext->Class<ClientModels::LinkGameCenterAccountResult>("PlayFabClient_LinkGameCenterAccountResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<ClientModels::LinkGoogleAccountRequest>("PlayFabClient_LinkGoogleAccountRequest")
                ->Constructor() 
			    ->Property("ServerAuthCode", BehaviorValueProperty(&ClientModels::LinkGoogleAccountRequest::ServerAuthCode)) 
			    ->Property("ForceLink", BehaviorValueProperty(&ClientModels::LinkGoogleAccountRequest::ForceLink)) 
			;
		
			behaviorContext->Class<ClientModels::LinkGoogleAccountResult>("PlayFabClient_LinkGoogleAccountResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<ClientModels::LinkIOSDeviceIDRequest>("PlayFabClient_LinkIOSDeviceIDRequest")
                ->Constructor() 
			    ->Property("DeviceId", BehaviorValueProperty(&ClientModels::LinkIOSDeviceIDRequest::DeviceId)) 
			    ->Property("OS", BehaviorValueProperty(&ClientModels::LinkIOSDeviceIDRequest::OS)) 
			    ->Property("DeviceModel", BehaviorValueProperty(&ClientModels::LinkIOSDeviceIDRequest::DeviceModel)) 
			    ->Property("ForceLink", BehaviorValueProperty(&ClientModels::LinkIOSDeviceIDRequest::ForceLink)) 
			;
		
			behaviorContext->Class<ClientModels::LinkIOSDeviceIDResult>("PlayFabClient_LinkIOSDeviceIDResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<ClientModels::LinkKongregateAccountRequest>("PlayFabClient_LinkKongregateAccountRequest")
                ->Constructor() 
			    ->Property("KongregateId", BehaviorValueProperty(&ClientModels::LinkKongregateAccountRequest::KongregateId)) 
			    ->Property("AuthTicket", BehaviorValueProperty(&ClientModels::LinkKongregateAccountRequest::AuthTicket)) 
			    ->Property("ForceLink", BehaviorValueProperty(&ClientModels::LinkKongregateAccountRequest::ForceLink)) 
			;
		
			behaviorContext->Class<ClientModels::LinkKongregateAccountResult>("PlayFabClient_LinkKongregateAccountResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<ClientModels::LinkSteamAccountRequest>("PlayFabClient_LinkSteamAccountRequest")
                ->Constructor() 
			    ->Property("SteamTicket", BehaviorValueProperty(&ClientModels::LinkSteamAccountRequest::SteamTicket)) 
			    ->Property("ForceLink", BehaviorValueProperty(&ClientModels::LinkSteamAccountRequest::ForceLink)) 
			;
		
			behaviorContext->Class<ClientModels::LinkSteamAccountResult>("PlayFabClient_LinkSteamAccountResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<ClientModels::LinkTwitchAccountRequest>("PlayFabClient_LinkTwitchAccountRequest")
                ->Constructor() 
			    ->Property("AccessToken", BehaviorValueProperty(&ClientModels::LinkTwitchAccountRequest::AccessToken)) 
			    ->Property("ForceLink", BehaviorValueProperty(&ClientModels::LinkTwitchAccountRequest::ForceLink)) 
			;
		
			behaviorContext->Class<ClientModels::LinkTwitchAccountResult>("PlayFabClient_LinkTwitchAccountResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<ClientModels::LinkWindowsHelloAccountRequest>("PlayFabClient_LinkWindowsHelloAccountRequest")
                ->Constructor() 
			    ->Property("UserName", BehaviorValueProperty(&ClientModels::LinkWindowsHelloAccountRequest::UserName)) 
			    ->Property("PublicKey", BehaviorValueProperty(&ClientModels::LinkWindowsHelloAccountRequest::PublicKey)) 
			    ->Property("DeviceName", BehaviorValueProperty(&ClientModels::LinkWindowsHelloAccountRequest::DeviceName)) 
			    ->Property("ForceLink", BehaviorValueProperty(&ClientModels::LinkWindowsHelloAccountRequest::ForceLink)) 
			;
		
			behaviorContext->Class<ClientModels::LinkWindowsHelloAccountResponse>("PlayFabClient_LinkWindowsHelloAccountResponse")
                ->Constructor() 
			;
		
			behaviorContext->Class<ClientModels::ListUsersCharactersRequest>("PlayFabClient_ListUsersCharactersRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ClientModels::ListUsersCharactersRequest::PlayFabId)) 
			;
		
			behaviorContext->Class<ClientModels::ListUsersCharactersResult>("PlayFabClient_ListUsersCharactersResult")
                ->Constructor() 
			    ->Property("Characters", BehaviorValueProperty(&ClientModels::ListUsersCharactersResult::Characters)) 
			;
		
			behaviorContext->Class<ClientModels::UserSettings>("PlayFabClient_UserSettings")
                ->Constructor() 
			    ->Property("NeedsAttribution", BehaviorValueProperty(&ClientModels::UserSettings::NeedsAttribution)) 
			;
		
			behaviorContext->Class<ClientModels::LoginResult>("PlayFabClient_LoginResult")
                ->Constructor() 
			    ->Property("SessionTicket", BehaviorValueProperty(&ClientModels::LoginResult::SessionTicket)) 
			    ->Property("PlayFabId", BehaviorValueProperty(&ClientModels::LoginResult::PlayFabId)) 
			    ->Property("NewlyCreated", BehaviorValueProperty(&ClientModels::LoginResult::NewlyCreated)) 
			    ->Property("SettingsForUser", BehaviorValueProperty(&ClientModels::LoginResult::SettingsForUser)) 
			    ->Property("LastLoginTime", BehaviorValueProperty(&ClientModels::LoginResult::LastLoginTime)) 
			    ->Property("InfoResultPayload", BehaviorValueProperty(&ClientModels::LoginResult::InfoResultPayload)) 
			;
		
			behaviorContext->Class<ClientModels::LoginWithAndroidDeviceIDRequest>("PlayFabClient_LoginWithAndroidDeviceIDRequest")
                ->Constructor() 
			    ->Property("AndroidDeviceId", BehaviorValueProperty(&ClientModels::LoginWithAndroidDeviceIDRequest::AndroidDeviceId)) 
			    ->Property("OS", BehaviorValueProperty(&ClientModels::LoginWithAndroidDeviceIDRequest::OS)) 
			    ->Property("AndroidDevice", BehaviorValueProperty(&ClientModels::LoginWithAndroidDeviceIDRequest::AndroidDevice)) 
			    ->Property("CreateAccount", BehaviorValueProperty(&ClientModels::LoginWithAndroidDeviceIDRequest::CreateAccount)) 
			    ->Property("TitleId", BehaviorValueProperty(&ClientModels::LoginWithAndroidDeviceIDRequest::TitleId)) 
			    ->Property("EncryptedRequest", BehaviorValueProperty(&ClientModels::LoginWithAndroidDeviceIDRequest::EncryptedRequest)) 
			    ->Property("PlayerSecret", BehaviorValueProperty(&ClientModels::LoginWithAndroidDeviceIDRequest::PlayerSecret)) 
			    ->Property("InfoRequestParameters", BehaviorValueProperty(&ClientModels::LoginWithAndroidDeviceIDRequest::InfoRequestParameters)) 
			;
		
			behaviorContext->Class<ClientModels::LoginWithCustomIDRequest>("PlayFabClient_LoginWithCustomIDRequest")
                ->Constructor() 
			    ->Property("CustomId", BehaviorValueProperty(&ClientModels::LoginWithCustomIDRequest::CustomId)) 
			    ->Property("CreateAccount", BehaviorValueProperty(&ClientModels::LoginWithCustomIDRequest::CreateAccount)) 
			    ->Property("TitleId", BehaviorValueProperty(&ClientModels::LoginWithCustomIDRequest::TitleId)) 
			    ->Property("EncryptedRequest", BehaviorValueProperty(&ClientModels::LoginWithCustomIDRequest::EncryptedRequest)) 
			    ->Property("PlayerSecret", BehaviorValueProperty(&ClientModels::LoginWithCustomIDRequest::PlayerSecret)) 
			    ->Property("InfoRequestParameters", BehaviorValueProperty(&ClientModels::LoginWithCustomIDRequest::InfoRequestParameters)) 
			;
		
			behaviorContext->Class<ClientModels::LoginWithEmailAddressRequest>("PlayFabClient_LoginWithEmailAddressRequest")
                ->Constructor() 
			    ->Property("TitleId", BehaviorValueProperty(&ClientModels::LoginWithEmailAddressRequest::TitleId)) 
			    ->Property("Email", BehaviorValueProperty(&ClientModels::LoginWithEmailAddressRequest::Email)) 
			    ->Property("Password", BehaviorValueProperty(&ClientModels::LoginWithEmailAddressRequest::Password)) 
			    ->Property("InfoRequestParameters", BehaviorValueProperty(&ClientModels::LoginWithEmailAddressRequest::InfoRequestParameters)) 
			;
		
			behaviorContext->Class<ClientModels::LoginWithFacebookRequest>("PlayFabClient_LoginWithFacebookRequest")
                ->Constructor() 
			    ->Property("AccessToken", BehaviorValueProperty(&ClientModels::LoginWithFacebookRequest::AccessToken)) 
			    ->Property("CreateAccount", BehaviorValueProperty(&ClientModels::LoginWithFacebookRequest::CreateAccount)) 
			    ->Property("TitleId", BehaviorValueProperty(&ClientModels::LoginWithFacebookRequest::TitleId)) 
			    ->Property("EncryptedRequest", BehaviorValueProperty(&ClientModels::LoginWithFacebookRequest::EncryptedRequest)) 
			    ->Property("PlayerSecret", BehaviorValueProperty(&ClientModels::LoginWithFacebookRequest::PlayerSecret)) 
			    ->Property("InfoRequestParameters", BehaviorValueProperty(&ClientModels::LoginWithFacebookRequest::InfoRequestParameters)) 
			;
		
			behaviorContext->Class<ClientModels::LoginWithGameCenterRequest>("PlayFabClient_LoginWithGameCenterRequest")
                ->Constructor() 
			    ->Property("PlayerId", BehaviorValueProperty(&ClientModels::LoginWithGameCenterRequest::PlayerId)) 
			    ->Property("CreateAccount", BehaviorValueProperty(&ClientModels::LoginWithGameCenterRequest::CreateAccount)) 
			    ->Property("TitleId", BehaviorValueProperty(&ClientModels::LoginWithGameCenterRequest::TitleId)) 
			    ->Property("EncryptedRequest", BehaviorValueProperty(&ClientModels::LoginWithGameCenterRequest::EncryptedRequest)) 
			    ->Property("PlayerSecret", BehaviorValueProperty(&ClientModels::LoginWithGameCenterRequest::PlayerSecret)) 
			    ->Property("InfoRequestParameters", BehaviorValueProperty(&ClientModels::LoginWithGameCenterRequest::InfoRequestParameters)) 
			;
		
			behaviorContext->Class<ClientModels::LoginWithGoogleAccountRequest>("PlayFabClient_LoginWithGoogleAccountRequest")
                ->Constructor() 
			    ->Property("ServerAuthCode", BehaviorValueProperty(&ClientModels::LoginWithGoogleAccountRequest::ServerAuthCode)) 
			    ->Property("CreateAccount", BehaviorValueProperty(&ClientModels::LoginWithGoogleAccountRequest::CreateAccount)) 
			    ->Property("TitleId", BehaviorValueProperty(&ClientModels::LoginWithGoogleAccountRequest::TitleId)) 
			    ->Property("EncryptedRequest", BehaviorValueProperty(&ClientModels::LoginWithGoogleAccountRequest::EncryptedRequest)) 
			    ->Property("PlayerSecret", BehaviorValueProperty(&ClientModels::LoginWithGoogleAccountRequest::PlayerSecret)) 
			    ->Property("InfoRequestParameters", BehaviorValueProperty(&ClientModels::LoginWithGoogleAccountRequest::InfoRequestParameters)) 
			;
		
			behaviorContext->Class<ClientModels::LoginWithIOSDeviceIDRequest>("PlayFabClient_LoginWithIOSDeviceIDRequest")
                ->Constructor() 
			    ->Property("DeviceId", BehaviorValueProperty(&ClientModels::LoginWithIOSDeviceIDRequest::DeviceId)) 
			    ->Property("OS", BehaviorValueProperty(&ClientModels::LoginWithIOSDeviceIDRequest::OS)) 
			    ->Property("DeviceModel", BehaviorValueProperty(&ClientModels::LoginWithIOSDeviceIDRequest::DeviceModel)) 
			    ->Property("CreateAccount", BehaviorValueProperty(&ClientModels::LoginWithIOSDeviceIDRequest::CreateAccount)) 
			    ->Property("TitleId", BehaviorValueProperty(&ClientModels::LoginWithIOSDeviceIDRequest::TitleId)) 
			    ->Property("EncryptedRequest", BehaviorValueProperty(&ClientModels::LoginWithIOSDeviceIDRequest::EncryptedRequest)) 
			    ->Property("PlayerSecret", BehaviorValueProperty(&ClientModels::LoginWithIOSDeviceIDRequest::PlayerSecret)) 
			    ->Property("InfoRequestParameters", BehaviorValueProperty(&ClientModels::LoginWithIOSDeviceIDRequest::InfoRequestParameters)) 
			;
		
			behaviorContext->Class<ClientModels::LoginWithKongregateRequest>("PlayFabClient_LoginWithKongregateRequest")
                ->Constructor() 
			    ->Property("KongregateId", BehaviorValueProperty(&ClientModels::LoginWithKongregateRequest::KongregateId)) 
			    ->Property("AuthTicket", BehaviorValueProperty(&ClientModels::LoginWithKongregateRequest::AuthTicket)) 
			    ->Property("CreateAccount", BehaviorValueProperty(&ClientModels::LoginWithKongregateRequest::CreateAccount)) 
			    ->Property("InfoRequestParameters", BehaviorValueProperty(&ClientModels::LoginWithKongregateRequest::InfoRequestParameters)) 
			    ->Property("TitleId", BehaviorValueProperty(&ClientModels::LoginWithKongregateRequest::TitleId)) 
			    ->Property("EncryptedRequest", BehaviorValueProperty(&ClientModels::LoginWithKongregateRequest::EncryptedRequest)) 
			    ->Property("PlayerSecret", BehaviorValueProperty(&ClientModels::LoginWithKongregateRequest::PlayerSecret)) 
			;
		
			behaviorContext->Class<ClientModels::LoginWithPlayFabRequest>("PlayFabClient_LoginWithPlayFabRequest")
                ->Constructor() 
			    ->Property("TitleId", BehaviorValueProperty(&ClientModels::LoginWithPlayFabRequest::TitleId)) 
			    ->Property("Username", BehaviorValueProperty(&ClientModels::LoginWithPlayFabRequest::Username)) 
			    ->Property("Password", BehaviorValueProperty(&ClientModels::LoginWithPlayFabRequest::Password)) 
			    ->Property("InfoRequestParameters", BehaviorValueProperty(&ClientModels::LoginWithPlayFabRequest::InfoRequestParameters)) 
			;
		
			behaviorContext->Class<ClientModels::LoginWithSteamRequest>("PlayFabClient_LoginWithSteamRequest")
                ->Constructor() 
			    ->Property("SteamTicket", BehaviorValueProperty(&ClientModels::LoginWithSteamRequest::SteamTicket)) 
			    ->Property("CreateAccount", BehaviorValueProperty(&ClientModels::LoginWithSteamRequest::CreateAccount)) 
			    ->Property("TitleId", BehaviorValueProperty(&ClientModels::LoginWithSteamRequest::TitleId)) 
			    ->Property("EncryptedRequest", BehaviorValueProperty(&ClientModels::LoginWithSteamRequest::EncryptedRequest)) 
			    ->Property("PlayerSecret", BehaviorValueProperty(&ClientModels::LoginWithSteamRequest::PlayerSecret)) 
			    ->Property("InfoRequestParameters", BehaviorValueProperty(&ClientModels::LoginWithSteamRequest::InfoRequestParameters)) 
			;
		
			behaviorContext->Class<ClientModels::LoginWithTwitchRequest>("PlayFabClient_LoginWithTwitchRequest")
                ->Constructor() 
			    ->Property("AccessToken", BehaviorValueProperty(&ClientModels::LoginWithTwitchRequest::AccessToken)) 
			    ->Property("CreateAccount", BehaviorValueProperty(&ClientModels::LoginWithTwitchRequest::CreateAccount)) 
			    ->Property("TitleId", BehaviorValueProperty(&ClientModels::LoginWithTwitchRequest::TitleId)) 
			    ->Property("EncryptedRequest", BehaviorValueProperty(&ClientModels::LoginWithTwitchRequest::EncryptedRequest)) 
			    ->Property("PlayerSecret", BehaviorValueProperty(&ClientModels::LoginWithTwitchRequest::PlayerSecret)) 
			    ->Property("InfoRequestParameters", BehaviorValueProperty(&ClientModels::LoginWithTwitchRequest::InfoRequestParameters)) 
			;
		
			behaviorContext->Class<ClientModels::LoginWithWindowsHelloRequest>("PlayFabClient_LoginWithWindowsHelloRequest")
                ->Constructor() 
			    ->Property("TitleId", BehaviorValueProperty(&ClientModels::LoginWithWindowsHelloRequest::TitleId)) 
			    ->Property("ChallengeSignature", BehaviorValueProperty(&ClientModels::LoginWithWindowsHelloRequest::ChallengeSignature)) 
			    ->Property("PublicKeyHint", BehaviorValueProperty(&ClientModels::LoginWithWindowsHelloRequest::PublicKeyHint)) 
			    ->Property("InfoRequestParameters", BehaviorValueProperty(&ClientModels::LoginWithWindowsHelloRequest::InfoRequestParameters)) 
			;
		
			behaviorContext->Class<ClientModels::MatchmakeRequest>("PlayFabClient_MatchmakeRequest")
                ->Constructor() 
			    ->Property("BuildVersion", BehaviorValueProperty(&ClientModels::MatchmakeRequest::BuildVersion)) 
			    ->Property("pfRegion", BehaviorValueProperty(&ClientModels::MatchmakeRequest::pfRegion)) 
			    ->Property("GameMode", BehaviorValueProperty(&ClientModels::MatchmakeRequest::GameMode)) 
			    ->Property("LobbyId", BehaviorValueProperty(&ClientModels::MatchmakeRequest::LobbyId)) 
			    ->Property("StatisticName", BehaviorValueProperty(&ClientModels::MatchmakeRequest::StatisticName)) 
			    ->Property("CharacterId", BehaviorValueProperty(&ClientModels::MatchmakeRequest::CharacterId)) 
			    ->Property("StartNewIfNoneFound", BehaviorValueProperty(&ClientModels::MatchmakeRequest::StartNewIfNoneFound)) 
			    ->Property("TagFilter", BehaviorValueProperty(&ClientModels::MatchmakeRequest::TagFilter)) 
			;
		
			behaviorContext->Class<ClientModels::MatchmakeResult>("PlayFabClient_MatchmakeResult")
                ->Constructor() 
			    ->Property("LobbyID", BehaviorValueProperty(&ClientModels::MatchmakeResult::LobbyID)) 
			    ->Property("ServerHostname", BehaviorValueProperty(&ClientModels::MatchmakeResult::ServerHostname)) 
			    ->Property("ServerPort", BehaviorValueProperty(&ClientModels::MatchmakeResult::ServerPort)) 
			    ->Property("Ticket", BehaviorValueProperty(&ClientModels::MatchmakeResult::Ticket)) 
			    ->Property("Expires", BehaviorValueProperty(&ClientModels::MatchmakeResult::Expires)) 
			    ->Property("PollWaitTimeMS", BehaviorValueProperty(&ClientModels::MatchmakeResult::PollWaitTimeMS)) 
			    ->Property("Status", BehaviorValueProperty(&ClientModels::MatchmakeResult::Status)) 
			;
		
			behaviorContext->Class<ClientModels::ModifyUserVirtualCurrencyResult>("PlayFabClient_ModifyUserVirtualCurrencyResult")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ClientModels::ModifyUserVirtualCurrencyResult::PlayFabId)) 
			    ->Property("VirtualCurrency", BehaviorValueProperty(&ClientModels::ModifyUserVirtualCurrencyResult::VirtualCurrency)) 
			    ->Property("BalanceChange", BehaviorValueProperty(&ClientModels::ModifyUserVirtualCurrencyResult::BalanceChange)) 
			    ->Property("Balance", BehaviorValueProperty(&ClientModels::ModifyUserVirtualCurrencyResult::Balance)) 
			;
		
			behaviorContext->Class<ClientModels::NameIdentifier>("PlayFabClient_NameIdentifier")
                ->Constructor() 
			    ->Property("Name", BehaviorValueProperty(&ClientModels::NameIdentifier::Name)) 
			    ->Property("Id", BehaviorValueProperty(&ClientModels::NameIdentifier::Id)) 
			;
		
			behaviorContext->Class<ClientModels::OpenTradeRequest>("PlayFabClient_OpenTradeRequest")
                ->Constructor() 
			    ->Property("OfferedInventoryInstanceIds", BehaviorValueProperty(&ClientModels::OpenTradeRequest::OfferedInventoryInstanceIds)) 
			    ->Property("RequestedCatalogItemIds", BehaviorValueProperty(&ClientModels::OpenTradeRequest::RequestedCatalogItemIds)) 
			    ->Property("AllowedPlayerIds", BehaviorValueProperty(&ClientModels::OpenTradeRequest::AllowedPlayerIds)) 
			;
		
			behaviorContext->Class<ClientModels::OpenTradeResponse>("PlayFabClient_OpenTradeResponse")
                ->Constructor() 
			    ->Property("Trade", BehaviorValueProperty(&ClientModels::OpenTradeResponse::Trade)) 
			;
		
			behaviorContext->Class<ClientModels::PayForPurchaseRequest>("PlayFabClient_PayForPurchaseRequest")
                ->Constructor() 
			    ->Property("OrderId", BehaviorValueProperty(&ClientModels::PayForPurchaseRequest::OrderId)) 
			    ->Property("ProviderName", BehaviorValueProperty(&ClientModels::PayForPurchaseRequest::ProviderName)) 
			    ->Property("Currency", BehaviorValueProperty(&ClientModels::PayForPurchaseRequest::Currency)) 
			    ->Property("ProviderTransactionId", BehaviorValueProperty(&ClientModels::PayForPurchaseRequest::ProviderTransactionId)) 
			;
		
			behaviorContext->Class<ClientModels::PayForPurchaseResult>("PlayFabClient_PayForPurchaseResult")
                ->Constructor() 
			    ->Property("OrderId", BehaviorValueProperty(&ClientModels::PayForPurchaseResult::OrderId)) 
			    ->Property("Status", BehaviorValueProperty(&ClientModels::PayForPurchaseResult::Status)) 
			    ->Property("PurchaseCurrency", BehaviorValueProperty(&ClientModels::PayForPurchaseResult::PurchaseCurrency)) 
			    ->Property("PurchasePrice", BehaviorValueProperty(&ClientModels::PayForPurchaseResult::PurchasePrice)) 
			    ->Property("CreditApplied", BehaviorValueProperty(&ClientModels::PayForPurchaseResult::CreditApplied)) 
			    ->Property("ProviderData", BehaviorValueProperty(&ClientModels::PayForPurchaseResult::ProviderData)) 
			    ->Property("PurchaseConfirmationPageURL", BehaviorValueProperty(&ClientModels::PayForPurchaseResult::PurchaseConfirmationPageURL)) 
			    ->Property("ProviderToken", BehaviorValueProperty(&ClientModels::PayForPurchaseResult::ProviderToken)) 
			;
		
			behaviorContext->Class<ClientModels::PaymentOption>("PlayFabClient_PaymentOption")
                ->Constructor() 
			    ->Property("Currency", BehaviorValueProperty(&ClientModels::PaymentOption::Currency)) 
			    ->Property("ProviderName", BehaviorValueProperty(&ClientModels::PaymentOption::ProviderName)) 
			    ->Property("Price", BehaviorValueProperty(&ClientModels::PaymentOption::Price)) 
			    ->Property("StoreCredit", BehaviorValueProperty(&ClientModels::PaymentOption::StoreCredit)) 
			;
		
			behaviorContext->Class<ClientModels::PurchaseItemRequest>("PlayFabClient_PurchaseItemRequest")
                ->Constructor() 
			    ->Property("ItemId", BehaviorValueProperty(&ClientModels::PurchaseItemRequest::ItemId)) 
			    ->Property("VirtualCurrency", BehaviorValueProperty(&ClientModels::PurchaseItemRequest::VirtualCurrency)) 
			    ->Property("Price", BehaviorValueProperty(&ClientModels::PurchaseItemRequest::Price)) 
			    ->Property("CatalogVersion", BehaviorValueProperty(&ClientModels::PurchaseItemRequest::CatalogVersion)) 
			    ->Property("StoreId", BehaviorValueProperty(&ClientModels::PurchaseItemRequest::StoreId)) 
			    ->Property("CharacterId", BehaviorValueProperty(&ClientModels::PurchaseItemRequest::CharacterId)) 
			;
		
			behaviorContext->Class<ClientModels::PurchaseItemResult>("PlayFabClient_PurchaseItemResult")
                ->Constructor() 
			    ->Property("Items", BehaviorValueProperty(&ClientModels::PurchaseItemResult::Items)) 
			;
		
			behaviorContext->Class<ClientModels::RedeemCouponRequest>("PlayFabClient_RedeemCouponRequest")
                ->Constructor() 
			    ->Property("CouponCode", BehaviorValueProperty(&ClientModels::RedeemCouponRequest::CouponCode)) 
			    ->Property("CatalogVersion", BehaviorValueProperty(&ClientModels::RedeemCouponRequest::CatalogVersion)) 
			    ->Property("CharacterId", BehaviorValueProperty(&ClientModels::RedeemCouponRequest::CharacterId)) 
			;
		
			behaviorContext->Class<ClientModels::RedeemCouponResult>("PlayFabClient_RedeemCouponResult")
                ->Constructor() 
			    ->Property("GrantedItems", BehaviorValueProperty(&ClientModels::RedeemCouponResult::GrantedItems)) 
			;
		
			behaviorContext->Class<ClientModels::RegisterForIOSPushNotificationRequest>("PlayFabClient_RegisterForIOSPushNotificationRequest")
                ->Constructor() 
			    ->Property("DeviceToken", BehaviorValueProperty(&ClientModels::RegisterForIOSPushNotificationRequest::DeviceToken)) 
			    ->Property("SendPushNotificationConfirmation", BehaviorValueProperty(&ClientModels::RegisterForIOSPushNotificationRequest::SendPushNotificationConfirmation)) 
			    ->Property("ConfirmationMessage", BehaviorValueProperty(&ClientModels::RegisterForIOSPushNotificationRequest::ConfirmationMessage)) 
			;
		
			behaviorContext->Class<ClientModels::RegisterForIOSPushNotificationResult>("PlayFabClient_RegisterForIOSPushNotificationResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<ClientModels::RegisterPlayFabUserRequest>("PlayFabClient_RegisterPlayFabUserRequest")
                ->Constructor() 
			    ->Property("Username", BehaviorValueProperty(&ClientModels::RegisterPlayFabUserRequest::Username)) 
			    ->Property("Email", BehaviorValueProperty(&ClientModels::RegisterPlayFabUserRequest::Email)) 
			    ->Property("Password", BehaviorValueProperty(&ClientModels::RegisterPlayFabUserRequest::Password)) 
			    ->Property("RequireBothUsernameAndEmail", BehaviorValueProperty(&ClientModels::RegisterPlayFabUserRequest::RequireBothUsernameAndEmail)) 
			    ->Property("DisplayName", BehaviorValueProperty(&ClientModels::RegisterPlayFabUserRequest::DisplayName)) 
			    ->Property("TitleId", BehaviorValueProperty(&ClientModels::RegisterPlayFabUserRequest::TitleId)) 
			    ->Property("EncryptedRequest", BehaviorValueProperty(&ClientModels::RegisterPlayFabUserRequest::EncryptedRequest)) 
			    ->Property("PlayerSecret", BehaviorValueProperty(&ClientModels::RegisterPlayFabUserRequest::PlayerSecret)) 
			    ->Property("InfoRequestParameters", BehaviorValueProperty(&ClientModels::RegisterPlayFabUserRequest::InfoRequestParameters)) 
			;
		
			behaviorContext->Class<ClientModels::RegisterPlayFabUserResult>("PlayFabClient_RegisterPlayFabUserResult")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&ClientModels::RegisterPlayFabUserResult::PlayFabId)) 
			    ->Property("SessionTicket", BehaviorValueProperty(&ClientModels::RegisterPlayFabUserResult::SessionTicket)) 
			    ->Property("Username", BehaviorValueProperty(&ClientModels::RegisterPlayFabUserResult::Username)) 
			    ->Property("SettingsForUser", BehaviorValueProperty(&ClientModels::RegisterPlayFabUserResult::SettingsForUser)) 
			;
		
			behaviorContext->Class<ClientModels::RegisterWithWindowsHelloRequest>("PlayFabClient_RegisterWithWindowsHelloRequest")
                ->Constructor() 
			    ->Property("UserName", BehaviorValueProperty(&ClientModels::RegisterWithWindowsHelloRequest::UserName)) 
			    ->Property("PublicKey", BehaviorValueProperty(&ClientModels::RegisterWithWindowsHelloRequest::PublicKey)) 
			    ->Property("DeviceName", BehaviorValueProperty(&ClientModels::RegisterWithWindowsHelloRequest::DeviceName)) 
			    ->Property("TitleId", BehaviorValueProperty(&ClientModels::RegisterWithWindowsHelloRequest::TitleId)) 
			    ->Property("EncryptedRequest", BehaviorValueProperty(&ClientModels::RegisterWithWindowsHelloRequest::EncryptedRequest)) 
			    ->Property("PlayerSecret", BehaviorValueProperty(&ClientModels::RegisterWithWindowsHelloRequest::PlayerSecret)) 
			    ->Property("InfoRequestParameters", BehaviorValueProperty(&ClientModels::RegisterWithWindowsHelloRequest::InfoRequestParameters)) 
			;
		
			behaviorContext->Class<ClientModels::RemoveFriendRequest>("PlayFabClient_RemoveFriendRequest")
                ->Constructor() 
			    ->Property("FriendPlayFabId", BehaviorValueProperty(&ClientModels::RemoveFriendRequest::FriendPlayFabId)) 
			;
		
			behaviorContext->Class<ClientModels::RemoveFriendResult>("PlayFabClient_RemoveFriendResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<ClientModels::RemoveGenericIDRequest>("PlayFabClient_RemoveGenericIDRequest")
                ->Constructor() 
			    ->Property("GenericId", BehaviorValueProperty(&ClientModels::RemoveGenericIDRequest::GenericId)) 
			;
		
			behaviorContext->Class<ClientModels::RemoveGenericIDResult>("PlayFabClient_RemoveGenericIDResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<ClientModels::RemoveSharedGroupMembersRequest>("PlayFabClient_RemoveSharedGroupMembersRequest")
                ->Constructor() 
			    ->Property("SharedGroupId", BehaviorValueProperty(&ClientModels::RemoveSharedGroupMembersRequest::SharedGroupId)) 
			    ->Property("PlayFabIds", BehaviorValueProperty(&ClientModels::RemoveSharedGroupMembersRequest::PlayFabIds)) 
			;
		
			behaviorContext->Class<ClientModels::RemoveSharedGroupMembersResult>("PlayFabClient_RemoveSharedGroupMembersResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<ClientModels::ReportPlayerClientRequest>("PlayFabClient_ReportPlayerClientRequest")
                ->Constructor() 
			    ->Property("ReporteeId", BehaviorValueProperty(&ClientModels::ReportPlayerClientRequest::ReporteeId)) 
			    ->Property("Comment", BehaviorValueProperty(&ClientModels::ReportPlayerClientRequest::Comment)) 
			;
		
			behaviorContext->Class<ClientModels::ReportPlayerClientResult>("PlayFabClient_ReportPlayerClientResult")
                ->Constructor() 
			    ->Property("Updated", BehaviorValueProperty(&ClientModels::ReportPlayerClientResult::Updated)) 
			    ->Property("SubmissionsRemaining", BehaviorValueProperty(&ClientModels::ReportPlayerClientResult::SubmissionsRemaining)) 
			;
		
			behaviorContext->Class<ClientModels::RestoreIOSPurchasesRequest>("PlayFabClient_RestoreIOSPurchasesRequest")
                ->Constructor() 
			    ->Property("ReceiptData", BehaviorValueProperty(&ClientModels::RestoreIOSPurchasesRequest::ReceiptData)) 
			;
		
			behaviorContext->Class<ClientModels::RestoreIOSPurchasesResult>("PlayFabClient_RestoreIOSPurchasesResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<ClientModels::SendAccountRecoveryEmailRequest>("PlayFabClient_SendAccountRecoveryEmailRequest")
                ->Constructor() 
			    ->Property("Email", BehaviorValueProperty(&ClientModels::SendAccountRecoveryEmailRequest::Email)) 
			    ->Property("TitleId", BehaviorValueProperty(&ClientModels::SendAccountRecoveryEmailRequest::TitleId)) 
			;
		
			behaviorContext->Class<ClientModels::SendAccountRecoveryEmailResult>("PlayFabClient_SendAccountRecoveryEmailResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<ClientModels::SetFriendTagsRequest>("PlayFabClient_SetFriendTagsRequest")
                ->Constructor() 
			    ->Property("FriendPlayFabId", BehaviorValueProperty(&ClientModels::SetFriendTagsRequest::FriendPlayFabId)) 
			    ->Property("Tags", BehaviorValueProperty(&ClientModels::SetFriendTagsRequest::Tags)) 
			;
		
			behaviorContext->Class<ClientModels::SetFriendTagsResult>("PlayFabClient_SetFriendTagsResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<ClientModels::SetPlayerSecretRequest>("PlayFabClient_SetPlayerSecretRequest")
                ->Constructor() 
			    ->Property("PlayerSecret", BehaviorValueProperty(&ClientModels::SetPlayerSecretRequest::PlayerSecret)) 
			    ->Property("EncryptedRequest", BehaviorValueProperty(&ClientModels::SetPlayerSecretRequest::EncryptedRequest)) 
			;
		
			behaviorContext->Class<ClientModels::SetPlayerSecretResult>("PlayFabClient_SetPlayerSecretResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<ClientModels::StartGameRequest>("PlayFabClient_StartGameRequest")
                ->Constructor() 
			    ->Property("BuildVersion", BehaviorValueProperty(&ClientModels::StartGameRequest::BuildVersion)) 
			    ->Property("pfRegion",
				    [](ClientModels::StartGameRequest* p) { return p->pfRegion; },
				    [](ClientModels::StartGameRequest* p, ClientModels::Region v) { p->pfRegion = v; })
			    ->Property("GameMode", BehaviorValueProperty(&ClientModels::StartGameRequest::GameMode)) 
			    ->Property("StatisticName", BehaviorValueProperty(&ClientModels::StartGameRequest::StatisticName)) 
			    ->Property("CharacterId", BehaviorValueProperty(&ClientModels::StartGameRequest::CharacterId)) 
			    ->Property("CustomCommandLineData", BehaviorValueProperty(&ClientModels::StartGameRequest::CustomCommandLineData)) 
			;
		
			behaviorContext->Class<ClientModels::StartGameResult>("PlayFabClient_StartGameResult")
                ->Constructor() 
			    ->Property("LobbyID", BehaviorValueProperty(&ClientModels::StartGameResult::LobbyID)) 
			    ->Property("ServerHostname", BehaviorValueProperty(&ClientModels::StartGameResult::ServerHostname)) 
			    ->Property("ServerPort", BehaviorValueProperty(&ClientModels::StartGameResult::ServerPort)) 
			    ->Property("Ticket", BehaviorValueProperty(&ClientModels::StartGameResult::Ticket)) 
			    ->Property("Expires", BehaviorValueProperty(&ClientModels::StartGameResult::Expires)) 
			    ->Property("Password", BehaviorValueProperty(&ClientModels::StartGameResult::Password)) 
			;
		
			behaviorContext->Class<ClientModels::StartPurchaseRequest>("PlayFabClient_StartPurchaseRequest")
                ->Constructor() 
			    ->Property("CatalogVersion", BehaviorValueProperty(&ClientModels::StartPurchaseRequest::CatalogVersion)) 
			    ->Property("StoreId", BehaviorValueProperty(&ClientModels::StartPurchaseRequest::StoreId)) 
			    ->Property("Items", BehaviorValueProperty(&ClientModels::StartPurchaseRequest::Items)) 
			;
		
			behaviorContext->Class<ClientModels::StartPurchaseResult>("PlayFabClient_StartPurchaseResult")
                ->Constructor() 
			    ->Property("OrderId", BehaviorValueProperty(&ClientModels::StartPurchaseResult::OrderId)) 
			    ->Property("Contents", BehaviorValueProperty(&ClientModels::StartPurchaseResult::Contents)) 
			    ->Property("PaymentOptions", BehaviorValueProperty(&ClientModels::StartPurchaseResult::PaymentOptions)) 
			;
		
			behaviorContext->Class<ClientModels::StatisticUpdate>("PlayFabClient_StatisticUpdate")
                ->Constructor() 
			    ->Property("StatisticName", BehaviorValueProperty(&ClientModels::StatisticUpdate::StatisticName)) 
			    ->Property("Version", BehaviorValueProperty(&ClientModels::StatisticUpdate::Version)) 
			    ->Property("Value", BehaviorValueProperty(&ClientModels::StatisticUpdate::Value)) 
			;
		
			behaviorContext->Class<ClientModels::SubtractUserVirtualCurrencyRequest>("PlayFabClient_SubtractUserVirtualCurrencyRequest")
                ->Constructor() 
			    ->Property("VirtualCurrency", BehaviorValueProperty(&ClientModels::SubtractUserVirtualCurrencyRequest::VirtualCurrency)) 
			    ->Property("Amount", BehaviorValueProperty(&ClientModels::SubtractUserVirtualCurrencyRequest::Amount)) 
			;
		
			behaviorContext->Class<ClientModels::UnlinkAndroidDeviceIDRequest>("PlayFabClient_UnlinkAndroidDeviceIDRequest")
                ->Constructor() 
			    ->Property("AndroidDeviceId", BehaviorValueProperty(&ClientModels::UnlinkAndroidDeviceIDRequest::AndroidDeviceId)) 
			;
		
			behaviorContext->Class<ClientModels::UnlinkAndroidDeviceIDResult>("PlayFabClient_UnlinkAndroidDeviceIDResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<ClientModels::UnlinkCustomIDRequest>("PlayFabClient_UnlinkCustomIDRequest")
                ->Constructor() 
			    ->Property("CustomId", BehaviorValueProperty(&ClientModels::UnlinkCustomIDRequest::CustomId)) 
			;
		
			behaviorContext->Class<ClientModels::UnlinkCustomIDResult>("PlayFabClient_UnlinkCustomIDResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<ClientModels::UnlinkFacebookAccountRequest>("PlayFabClient_UnlinkFacebookAccountRequest")
                ->Constructor() 
			;
		
			behaviorContext->Class<ClientModels::UnlinkFacebookAccountResult>("PlayFabClient_UnlinkFacebookAccountResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<ClientModels::UnlinkGameCenterAccountRequest>("PlayFabClient_UnlinkGameCenterAccountRequest")
                ->Constructor() 
			;
		
			behaviorContext->Class<ClientModels::UnlinkGameCenterAccountResult>("PlayFabClient_UnlinkGameCenterAccountResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<ClientModels::UnlinkGoogleAccountRequest>("PlayFabClient_UnlinkGoogleAccountRequest")
                ->Constructor() 
			;
		
			behaviorContext->Class<ClientModels::UnlinkGoogleAccountResult>("PlayFabClient_UnlinkGoogleAccountResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<ClientModels::UnlinkIOSDeviceIDRequest>("PlayFabClient_UnlinkIOSDeviceIDRequest")
                ->Constructor() 
			    ->Property("DeviceId", BehaviorValueProperty(&ClientModels::UnlinkIOSDeviceIDRequest::DeviceId)) 
			;
		
			behaviorContext->Class<ClientModels::UnlinkIOSDeviceIDResult>("PlayFabClient_UnlinkIOSDeviceIDResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<ClientModels::UnlinkKongregateAccountRequest>("PlayFabClient_UnlinkKongregateAccountRequest")
                ->Constructor() 
			;
		
			behaviorContext->Class<ClientModels::UnlinkKongregateAccountResult>("PlayFabClient_UnlinkKongregateAccountResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<ClientModels::UnlinkSteamAccountRequest>("PlayFabClient_UnlinkSteamAccountRequest")
                ->Constructor() 
			;
		
			behaviorContext->Class<ClientModels::UnlinkSteamAccountResult>("PlayFabClient_UnlinkSteamAccountResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<ClientModels::UnlinkTwitchAccountRequest>("PlayFabClient_UnlinkTwitchAccountRequest")
                ->Constructor() 
			;
		
			behaviorContext->Class<ClientModels::UnlinkTwitchAccountResult>("PlayFabClient_UnlinkTwitchAccountResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<ClientModels::UnlinkWindowsHelloAccountRequest>("PlayFabClient_UnlinkWindowsHelloAccountRequest")
                ->Constructor() 
			    ->Property("PublicKeyHint", BehaviorValueProperty(&ClientModels::UnlinkWindowsHelloAccountRequest::PublicKeyHint)) 
			;
		
			behaviorContext->Class<ClientModels::UnlinkWindowsHelloAccountResponse>("PlayFabClient_UnlinkWindowsHelloAccountResponse")
                ->Constructor() 
			;
		
			behaviorContext->Class<ClientModels::UnlockContainerInstanceRequest>("PlayFabClient_UnlockContainerInstanceRequest")
                ->Constructor() 
			    ->Property("CharacterId", BehaviorValueProperty(&ClientModels::UnlockContainerInstanceRequest::CharacterId)) 
			    ->Property("ContainerItemInstanceId", BehaviorValueProperty(&ClientModels::UnlockContainerInstanceRequest::ContainerItemInstanceId)) 
			    ->Property("KeyItemInstanceId", BehaviorValueProperty(&ClientModels::UnlockContainerInstanceRequest::KeyItemInstanceId)) 
			    ->Property("CatalogVersion", BehaviorValueProperty(&ClientModels::UnlockContainerInstanceRequest::CatalogVersion)) 
			;
		
			behaviorContext->Class<ClientModels::UnlockContainerItemRequest>("PlayFabClient_UnlockContainerItemRequest")
                ->Constructor() 
			    ->Property("ContainerItemId", BehaviorValueProperty(&ClientModels::UnlockContainerItemRequest::ContainerItemId)) 
			    ->Property("CatalogVersion", BehaviorValueProperty(&ClientModels::UnlockContainerItemRequest::CatalogVersion)) 
			    ->Property("CharacterId", BehaviorValueProperty(&ClientModels::UnlockContainerItemRequest::CharacterId)) 
			;
		
			behaviorContext->Class<ClientModels::UnlockContainerItemResult>("PlayFabClient_UnlockContainerItemResult")
                ->Constructor() 
			    ->Property("UnlockedItemInstanceId", BehaviorValueProperty(&ClientModels::UnlockContainerItemResult::UnlockedItemInstanceId)) 
			    ->Property("UnlockedWithItemInstanceId", BehaviorValueProperty(&ClientModels::UnlockContainerItemResult::UnlockedWithItemInstanceId)) 
			    ->Property("GrantedItems", BehaviorValueProperty(&ClientModels::UnlockContainerItemResult::GrantedItems)) 
			;
		
			behaviorContext->Class<ClientModels::UpdateAvatarUrlRequest>("PlayFabClient_UpdateAvatarUrlRequest")
                ->Constructor() 
			    ->Property("ImageUrl", BehaviorValueProperty(&ClientModels::UpdateAvatarUrlRequest::ImageUrl)) 
			;
		
			behaviorContext->Class<ClientModels::UpdateCharacterDataRequest>("PlayFabClient_UpdateCharacterDataRequest")
                ->Constructor() 
			    ->Property("CharacterId", BehaviorValueProperty(&ClientModels::UpdateCharacterDataRequest::CharacterId)) 
			    ->Property("KeysToRemove", BehaviorValueProperty(&ClientModels::UpdateCharacterDataRequest::KeysToRemove)) 
			    ->Property("Permission", BehaviorValueProperty(&ClientModels::UpdateCharacterDataRequest::Permission)) 
			;
		
			behaviorContext->Class<ClientModels::UpdateCharacterDataResult>("PlayFabClient_UpdateCharacterDataResult")
                ->Constructor() 
			    ->Property("DataVersion", BehaviorValueProperty(&ClientModels::UpdateCharacterDataResult::DataVersion)) 
			;
		
			behaviorContext->Class<ClientModels::UpdateCharacterStatisticsRequest>("PlayFabClient_UpdateCharacterStatisticsRequest")
                ->Constructor() 
			    ->Property("CharacterId", BehaviorValueProperty(&ClientModels::UpdateCharacterStatisticsRequest::CharacterId)) 
			;
		
			behaviorContext->Class<ClientModels::UpdateCharacterStatisticsResult>("PlayFabClient_UpdateCharacterStatisticsResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<ClientModels::UpdatePlayerStatisticsRequest>("PlayFabClient_UpdatePlayerStatisticsRequest")
                ->Constructor() 
			    ->Property("Statistics", BehaviorValueProperty(&ClientModels::UpdatePlayerStatisticsRequest::Statistics)) 
			;
		
			behaviorContext->Class<ClientModels::UpdatePlayerStatisticsResult>("PlayFabClient_UpdatePlayerStatisticsResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<ClientModels::UpdateSharedGroupDataRequest>("PlayFabClient_UpdateSharedGroupDataRequest")
                ->Constructor() 
			    ->Property("SharedGroupId", BehaviorValueProperty(&ClientModels::UpdateSharedGroupDataRequest::SharedGroupId)) 
			    ->Property("KeysToRemove", BehaviorValueProperty(&ClientModels::UpdateSharedGroupDataRequest::KeysToRemove)) 
			    ->Property("Permission", BehaviorValueProperty(&ClientModels::UpdateSharedGroupDataRequest::Permission)) 
			;
		
			behaviorContext->Class<ClientModels::UpdateSharedGroupDataResult>("PlayFabClient_UpdateSharedGroupDataResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<ClientModels::UpdateUserDataRequest>("PlayFabClient_UpdateUserDataRequest")
                ->Constructor() 
			    ->Property("KeysToRemove", BehaviorValueProperty(&ClientModels::UpdateUserDataRequest::KeysToRemove)) 
			    ->Property("Permission", BehaviorValueProperty(&ClientModels::UpdateUserDataRequest::Permission)) 
			;
		
			behaviorContext->Class<ClientModels::UpdateUserDataResult>("PlayFabClient_UpdateUserDataResult")
                ->Constructor() 
			    ->Property("DataVersion", BehaviorValueProperty(&ClientModels::UpdateUserDataResult::DataVersion)) 
			;
		
			behaviorContext->Class<ClientModels::UpdateUserTitleDisplayNameRequest>("PlayFabClient_UpdateUserTitleDisplayNameRequest")
                ->Constructor() 
			    ->Property("DisplayName", BehaviorValueProperty(&ClientModels::UpdateUserTitleDisplayNameRequest::DisplayName)) 
			;
		
			behaviorContext->Class<ClientModels::UpdateUserTitleDisplayNameResult>("PlayFabClient_UpdateUserTitleDisplayNameResult")
                ->Constructor() 
			    ->Property("DisplayName", BehaviorValueProperty(&ClientModels::UpdateUserTitleDisplayNameResult::DisplayName)) 
			;
		
			behaviorContext->Class<ClientModels::ValidateAmazonReceiptRequest>("PlayFabClient_ValidateAmazonReceiptRequest")
                ->Constructor() 
			    ->Property("ReceiptId", BehaviorValueProperty(&ClientModels::ValidateAmazonReceiptRequest::ReceiptId)) 
			    ->Property("UserId", BehaviorValueProperty(&ClientModels::ValidateAmazonReceiptRequest::UserId)) 
			    ->Property("CatalogVersion", BehaviorValueProperty(&ClientModels::ValidateAmazonReceiptRequest::CatalogVersion)) 
			    ->Property("CurrencyCode", BehaviorValueProperty(&ClientModels::ValidateAmazonReceiptRequest::CurrencyCode)) 
			    ->Property("PurchasePrice", BehaviorValueProperty(&ClientModels::ValidateAmazonReceiptRequest::PurchasePrice)) 
			;
		
			behaviorContext->Class<ClientModels::ValidateAmazonReceiptResult>("PlayFabClient_ValidateAmazonReceiptResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<ClientModels::ValidateGooglePlayPurchaseRequest>("PlayFabClient_ValidateGooglePlayPurchaseRequest")
                ->Constructor() 
			    ->Property("ReceiptJson", BehaviorValueProperty(&ClientModels::ValidateGooglePlayPurchaseRequest::ReceiptJson)) 
			    ->Property("Signature", BehaviorValueProperty(&ClientModels::ValidateGooglePlayPurchaseRequest::Signature)) 
			    ->Property("CurrencyCode", BehaviorValueProperty(&ClientModels::ValidateGooglePlayPurchaseRequest::CurrencyCode)) 
			    ->Property("PurchasePrice", BehaviorValueProperty(&ClientModels::ValidateGooglePlayPurchaseRequest::PurchasePrice)) 
			;
		
			behaviorContext->Class<ClientModels::ValidateGooglePlayPurchaseResult>("PlayFabClient_ValidateGooglePlayPurchaseResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<ClientModels::ValidateIOSReceiptRequest>("PlayFabClient_ValidateIOSReceiptRequest")
                ->Constructor() 
			    ->Property("ReceiptData", BehaviorValueProperty(&ClientModels::ValidateIOSReceiptRequest::ReceiptData)) 
			    ->Property("CurrencyCode", BehaviorValueProperty(&ClientModels::ValidateIOSReceiptRequest::CurrencyCode)) 
			    ->Property("PurchasePrice", BehaviorValueProperty(&ClientModels::ValidateIOSReceiptRequest::PurchasePrice)) 
			;
		
			behaviorContext->Class<ClientModels::ValidateIOSReceiptResult>("PlayFabClient_ValidateIOSReceiptResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<ClientModels::ValidateWindowsReceiptRequest>("PlayFabClient_ValidateWindowsReceiptRequest")
                ->Constructor() 
			    ->Property("Receipt", BehaviorValueProperty(&ClientModels::ValidateWindowsReceiptRequest::Receipt)) 
			    ->Property("CatalogVersion", BehaviorValueProperty(&ClientModels::ValidateWindowsReceiptRequest::CatalogVersion)) 
			    ->Property("CurrencyCode", BehaviorValueProperty(&ClientModels::ValidateWindowsReceiptRequest::CurrencyCode)) 
			    ->Property("PurchasePrice", BehaviorValueProperty(&ClientModels::ValidateWindowsReceiptRequest::PurchasePrice)) 
			;
		
			behaviorContext->Class<ClientModels::ValidateWindowsReceiptResult>("PlayFabClient_ValidateWindowsReceiptResult")
                ->Constructor() 
			;
		
			behaviorContext->Class<ClientModels::WriteClientCharacterEventRequest>("PlayFabClient_WriteClientCharacterEventRequest")
                ->Constructor() 
			    ->Property("CharacterId", BehaviorValueProperty(&ClientModels::WriteClientCharacterEventRequest::CharacterId)) 
			    ->Property("EventName", BehaviorValueProperty(&ClientModels::WriteClientCharacterEventRequest::EventName)) 
			    ->Property("Timestamp", BehaviorValueProperty(&ClientModels::WriteClientCharacterEventRequest::Timestamp)) 
			;
		
			behaviorContext->Class<ClientModels::WriteClientPlayerEventRequest>("PlayFabClient_WriteClientPlayerEventRequest")
                ->Constructor() 
			    ->Property("EventName", BehaviorValueProperty(&ClientModels::WriteClientPlayerEventRequest::EventName)) 
			    ->Property("Timestamp", BehaviorValueProperty(&ClientModels::WriteClientPlayerEventRequest::Timestamp)) 
			;
		
			behaviorContext->Class<ClientModels::WriteEventResponse>("PlayFabClient_WriteEventResponse")
                ->Constructor() 
			    ->Property("EventId", BehaviorValueProperty(&ClientModels::WriteEventResponse::EventId)) 
			;
		
			behaviorContext->Class<ClientModels::WriteTitleEventRequest>("PlayFabClient_WriteTitleEventRequest")
                ->Constructor() 
			    ->Property("EventName", BehaviorValueProperty(&ClientModels::WriteTitleEventRequest::EventName)) 
			    ->Property("Timestamp", BehaviorValueProperty(&ClientModels::WriteTitleEventRequest::Timestamp)) 
			;
		 
				
		} // if (behaviorContext) {...
	} // End of BehaviorContext::Reflect()

}