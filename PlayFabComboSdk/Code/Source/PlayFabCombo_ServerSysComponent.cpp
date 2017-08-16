
#include "StdAfx.h"

#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>

#include "PlayFabCombo_ServerSysComponent.h"

#include "PlayFabSettings.h"
#include "PlayFabServerApi.h"

namespace PlayFabComboSdk
{
    void PlayFabCombo_ServerSysComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<PlayFabCombo_ServerSysComponent, AZ::Component>()
                ->Version(0)
                ->SerializerForEmptyClass();

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<PlayFabCombo_ServerSysComponent>("PlayFabCombo_Server", "Provides access to the Server API within the PlayFab Combo SDK")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                    // ->Attribute(AZ::Edit::Attributes::Category, "") Set a category
                    ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System"))
                    ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void PlayFabCombo_ServerSysComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("PlayFabCombo_ServerService"));
    }

    void PlayFabCombo_ServerSysComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("PlayFabCombo_ServerService"));
    }

    void PlayFabCombo_ServerSysComponent::GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required)
    {
        (void)required;
    }

    void PlayFabCombo_ServerSysComponent::GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
        (void)dependent;
    }

    void PlayFabCombo_ServerSysComponent::Init()
    {
    }

    void PlayFabCombo_ServerSysComponent::Activate()
    {
        PlayFabCombo_ServerRequestBus::Handler::BusConnect();
        PlayFabCombo_ServerSimpleRequestBus::Handler::BusConnect(); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    }

    void PlayFabCombo_ServerSysComponent::Deactivate()
    {
        PlayFabCombo_ServerRequestBus::Handler::BusDisconnect();
        PlayFabCombo_ServerSimpleRequestBus::Handler::BusDisconnect(); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    }

    int PlayFabCombo_ServerSysComponent::GetPendingCalls()
    {
        return PlayFabRequestManager::playFabHttp->GetPendingCalls();
    }

    // ------------ Generated API call wrappers
    int PlayFabCombo_ServerSysComponent::AuthenticateSessionTicket(ServerModels::AuthenticateSessionTicketRequest& request, ProcessApiCallback<ServerModels::AuthenticateSessionTicketResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::AuthenticateSessionTicket(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::AuthenticateSessionTicket(ServerModels::AuthenticateSessionTicketRequest& request)
    {
        return AuthenticateSessionTicket(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::SetPlayerSecret(ServerModels::SetPlayerSecretRequest& request, ProcessApiCallback<ServerModels::SetPlayerSecretResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::SetPlayerSecret(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::SetPlayerSecret(ServerModels::SetPlayerSecretRequest& request)
    {
        return SetPlayerSecret(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::BanUsers(ServerModels::BanUsersRequest& request, ProcessApiCallback<ServerModels::BanUsersResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::BanUsers(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::BanUsers(ServerModels::BanUsersRequest& request)
    {
        return BanUsers(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::GetPlayerProfile(ServerModels::GetPlayerProfileRequest& request, ProcessApiCallback<ServerModels::GetPlayerProfileResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::GetPlayerProfile(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::GetPlayerProfile(ServerModels::GetPlayerProfileRequest& request)
    {
        return GetPlayerProfile(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::GetPlayFabIDsFromFacebookIDs(ServerModels::GetPlayFabIDsFromFacebookIDsRequest& request, ProcessApiCallback<ServerModels::GetPlayFabIDsFromFacebookIDsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::GetPlayFabIDsFromFacebookIDs(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::GetPlayFabIDsFromFacebookIDs(ServerModels::GetPlayFabIDsFromFacebookIDsRequest& request)
    {
        return GetPlayFabIDsFromFacebookIDs(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::GetPlayFabIDsFromSteamIDs(ServerModels::GetPlayFabIDsFromSteamIDsRequest& request, ProcessApiCallback<ServerModels::GetPlayFabIDsFromSteamIDsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::GetPlayFabIDsFromSteamIDs(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::GetPlayFabIDsFromSteamIDs(ServerModels::GetPlayFabIDsFromSteamIDsRequest& request)
    {
        return GetPlayFabIDsFromSteamIDs(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::GetUserAccountInfo(ServerModels::GetUserAccountInfoRequest& request, ProcessApiCallback<ServerModels::GetUserAccountInfoResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::GetUserAccountInfo(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::GetUserAccountInfo(ServerModels::GetUserAccountInfoRequest& request)
    {
        return GetUserAccountInfo(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::GetUserBans(ServerModels::GetUserBansRequest& request, ProcessApiCallback<ServerModels::GetUserBansResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::GetUserBans(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::GetUserBans(ServerModels::GetUserBansRequest& request)
    {
        return GetUserBans(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::RevokeAllBansForUser(ServerModels::RevokeAllBansForUserRequest& request, ProcessApiCallback<ServerModels::RevokeAllBansForUserResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::RevokeAllBansForUser(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::RevokeAllBansForUser(ServerModels::RevokeAllBansForUserRequest& request)
    {
        return RevokeAllBansForUser(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::RevokeBans(ServerModels::RevokeBansRequest& request, ProcessApiCallback<ServerModels::RevokeBansResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::RevokeBans(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::RevokeBans(ServerModels::RevokeBansRequest& request)
    {
        return RevokeBans(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::SendPushNotification(ServerModels::SendPushNotificationRequest& request, ProcessApiCallback<ServerModels::SendPushNotificationResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::SendPushNotification(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::SendPushNotification(ServerModels::SendPushNotificationRequest& request)
    {
        return SendPushNotification(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::UpdateAvatarUrl(ServerModels::UpdateAvatarUrlRequest& request, ProcessApiCallback<ServerModels::EmptyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::UpdateAvatarUrl(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::UpdateAvatarUrl(ServerModels::UpdateAvatarUrlRequest& request)
    {
        return UpdateAvatarUrl(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::UpdateBans(ServerModels::UpdateBansRequest& request, ProcessApiCallback<ServerModels::UpdateBansResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::UpdateBans(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::UpdateBans(ServerModels::UpdateBansRequest& request)
    {
        return UpdateBans(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::DeleteUsers(ServerModels::DeleteUsersRequest& request, ProcessApiCallback<ServerModels::DeleteUsersResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::DeleteUsers(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::DeleteUsers(ServerModels::DeleteUsersRequest& request)
    {
        return DeleteUsers(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::GetFriendLeaderboard(ServerModels::GetFriendLeaderboardRequest& request, ProcessApiCallback<ServerModels::GetLeaderboardResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::GetFriendLeaderboard(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::GetFriendLeaderboard(ServerModels::GetFriendLeaderboardRequest& request)
    {
        return GetFriendLeaderboard(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::GetLeaderboard(ServerModels::GetLeaderboardRequest& request, ProcessApiCallback<ServerModels::GetLeaderboardResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::GetLeaderboard(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::GetLeaderboard(ServerModels::GetLeaderboardRequest& request)
    {
        return GetLeaderboard(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::GetLeaderboardAroundUser(ServerModels::GetLeaderboardAroundUserRequest& request, ProcessApiCallback<ServerModels::GetLeaderboardAroundUserResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::GetLeaderboardAroundUser(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::GetLeaderboardAroundUser(ServerModels::GetLeaderboardAroundUserRequest& request)
    {
        return GetLeaderboardAroundUser(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::GetPlayerCombinedInfo(ServerModels::GetPlayerCombinedInfoRequest& request, ProcessApiCallback<ServerModels::GetPlayerCombinedInfoResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::GetPlayerCombinedInfo(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::GetPlayerCombinedInfo(ServerModels::GetPlayerCombinedInfoRequest& request)
    {
        return GetPlayerCombinedInfo(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::GetPlayerStatistics(ServerModels::GetPlayerStatisticsRequest& request, ProcessApiCallback<ServerModels::GetPlayerStatisticsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::GetPlayerStatistics(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::GetPlayerStatistics(ServerModels::GetPlayerStatisticsRequest& request)
    {
        return GetPlayerStatistics(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::GetPlayerStatisticVersions(ServerModels::GetPlayerStatisticVersionsRequest& request, ProcessApiCallback<ServerModels::GetPlayerStatisticVersionsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::GetPlayerStatisticVersions(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::GetPlayerStatisticVersions(ServerModels::GetPlayerStatisticVersionsRequest& request)
    {
        return GetPlayerStatisticVersions(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::GetUserData(ServerModels::GetUserDataRequest& request, ProcessApiCallback<ServerModels::GetUserDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::GetUserData(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::GetUserData(ServerModels::GetUserDataRequest& request)
    {
        return GetUserData(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::GetUserInternalData(ServerModels::GetUserDataRequest& request, ProcessApiCallback<ServerModels::GetUserDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::GetUserInternalData(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::GetUserInternalData(ServerModels::GetUserDataRequest& request)
    {
        return GetUserInternalData(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::GetUserPublisherData(ServerModels::GetUserDataRequest& request, ProcessApiCallback<ServerModels::GetUserDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::GetUserPublisherData(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::GetUserPublisherData(ServerModels::GetUserDataRequest& request)
    {
        return GetUserPublisherData(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::GetUserPublisherInternalData(ServerModels::GetUserDataRequest& request, ProcessApiCallback<ServerModels::GetUserDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::GetUserPublisherInternalData(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::GetUserPublisherInternalData(ServerModels::GetUserDataRequest& request)
    {
        return GetUserPublisherInternalData(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::GetUserPublisherReadOnlyData(ServerModels::GetUserDataRequest& request, ProcessApiCallback<ServerModels::GetUserDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::GetUserPublisherReadOnlyData(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::GetUserPublisherReadOnlyData(ServerModels::GetUserDataRequest& request)
    {
        return GetUserPublisherReadOnlyData(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::GetUserReadOnlyData(ServerModels::GetUserDataRequest& request, ProcessApiCallback<ServerModels::GetUserDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::GetUserReadOnlyData(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::GetUserReadOnlyData(ServerModels::GetUserDataRequest& request)
    {
        return GetUserReadOnlyData(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::UpdatePlayerStatistics(ServerModels::UpdatePlayerStatisticsRequest& request, ProcessApiCallback<ServerModels::UpdatePlayerStatisticsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::UpdatePlayerStatistics(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::UpdatePlayerStatistics(ServerModels::UpdatePlayerStatisticsRequest& request)
    {
        return UpdatePlayerStatistics(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::UpdateUserData(ServerModels::UpdateUserDataRequest& request, ProcessApiCallback<ServerModels::UpdateUserDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::UpdateUserData(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::UpdateUserData(ServerModels::UpdateUserDataRequest& request)
    {
        return UpdateUserData(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::UpdateUserInternalData(ServerModels::UpdateUserInternalDataRequest& request, ProcessApiCallback<ServerModels::UpdateUserDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::UpdateUserInternalData(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::UpdateUserInternalData(ServerModels::UpdateUserInternalDataRequest& request)
    {
        return UpdateUserInternalData(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::UpdateUserPublisherData(ServerModels::UpdateUserDataRequest& request, ProcessApiCallback<ServerModels::UpdateUserDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::UpdateUserPublisherData(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::UpdateUserPublisherData(ServerModels::UpdateUserDataRequest& request)
    {
        return UpdateUserPublisherData(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::UpdateUserPublisherInternalData(ServerModels::UpdateUserInternalDataRequest& request, ProcessApiCallback<ServerModels::UpdateUserDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::UpdateUserPublisherInternalData(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::UpdateUserPublisherInternalData(ServerModels::UpdateUserInternalDataRequest& request)
    {
        return UpdateUserPublisherInternalData(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::UpdateUserPublisherReadOnlyData(ServerModels::UpdateUserDataRequest& request, ProcessApiCallback<ServerModels::UpdateUserDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::UpdateUserPublisherReadOnlyData(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::UpdateUserPublisherReadOnlyData(ServerModels::UpdateUserDataRequest& request)
    {
        return UpdateUserPublisherReadOnlyData(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::UpdateUserReadOnlyData(ServerModels::UpdateUserDataRequest& request, ProcessApiCallback<ServerModels::UpdateUserDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::UpdateUserReadOnlyData(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::UpdateUserReadOnlyData(ServerModels::UpdateUserDataRequest& request)
    {
        return UpdateUserReadOnlyData(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::GetCatalogItems(ServerModels::GetCatalogItemsRequest& request, ProcessApiCallback<ServerModels::GetCatalogItemsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::GetCatalogItems(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::GetCatalogItems(ServerModels::GetCatalogItemsRequest& request)
    {
        return GetCatalogItems(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::GetPublisherData(ServerModels::GetPublisherDataRequest& request, ProcessApiCallback<ServerModels::GetPublisherDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::GetPublisherData(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::GetPublisherData(ServerModels::GetPublisherDataRequest& request)
    {
        return GetPublisherData(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::GetTime(ProcessApiCallback<ServerModels::GetTimeResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::GetTime(callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::GetTime()
    {
        return GetTime(nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::GetTitleData(ServerModels::GetTitleDataRequest& request, ProcessApiCallback<ServerModels::GetTitleDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::GetTitleData(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::GetTitleData(ServerModels::GetTitleDataRequest& request)
    {
        return GetTitleData(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::GetTitleInternalData(ServerModels::GetTitleDataRequest& request, ProcessApiCallback<ServerModels::GetTitleDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::GetTitleInternalData(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::GetTitleInternalData(ServerModels::GetTitleDataRequest& request)
    {
        return GetTitleInternalData(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::GetTitleNews(ServerModels::GetTitleNewsRequest& request, ProcessApiCallback<ServerModels::GetTitleNewsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::GetTitleNews(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::GetTitleNews(ServerModels::GetTitleNewsRequest& request)
    {
        return GetTitleNews(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::SetPublisherData(ServerModels::SetPublisherDataRequest& request, ProcessApiCallback<ServerModels::SetPublisherDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::SetPublisherData(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::SetPublisherData(ServerModels::SetPublisherDataRequest& request)
    {
        return SetPublisherData(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::SetTitleData(ServerModels::SetTitleDataRequest& request, ProcessApiCallback<ServerModels::SetTitleDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::SetTitleData(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::SetTitleData(ServerModels::SetTitleDataRequest& request)
    {
        return SetTitleData(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::SetTitleInternalData(ServerModels::SetTitleDataRequest& request, ProcessApiCallback<ServerModels::SetTitleDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::SetTitleInternalData(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::SetTitleInternalData(ServerModels::SetTitleDataRequest& request)
    {
        return SetTitleInternalData(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::AddCharacterVirtualCurrency(ServerModels::AddCharacterVirtualCurrencyRequest& request, ProcessApiCallback<ServerModels::ModifyCharacterVirtualCurrencyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::AddCharacterVirtualCurrency(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::AddCharacterVirtualCurrency(ServerModels::AddCharacterVirtualCurrencyRequest& request)
    {
        return AddCharacterVirtualCurrency(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::AddUserVirtualCurrency(ServerModels::AddUserVirtualCurrencyRequest& request, ProcessApiCallback<ServerModels::ModifyUserVirtualCurrencyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::AddUserVirtualCurrency(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::AddUserVirtualCurrency(ServerModels::AddUserVirtualCurrencyRequest& request)
    {
        return AddUserVirtualCurrency(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::ConsumeItem(ServerModels::ConsumeItemRequest& request, ProcessApiCallback<ServerModels::ConsumeItemResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::ConsumeItem(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::ConsumeItem(ServerModels::ConsumeItemRequest& request)
    {
        return ConsumeItem(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::EvaluateRandomResultTable(ServerModels::EvaluateRandomResultTableRequest& request, ProcessApiCallback<ServerModels::EvaluateRandomResultTableResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::EvaluateRandomResultTable(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::EvaluateRandomResultTable(ServerModels::EvaluateRandomResultTableRequest& request)
    {
        return EvaluateRandomResultTable(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::GetCharacterInventory(ServerModels::GetCharacterInventoryRequest& request, ProcessApiCallback<ServerModels::GetCharacterInventoryResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::GetCharacterInventory(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::GetCharacterInventory(ServerModels::GetCharacterInventoryRequest& request)
    {
        return GetCharacterInventory(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::GetRandomResultTables(ServerModels::GetRandomResultTablesRequest& request, ProcessApiCallback<ServerModels::GetRandomResultTablesResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::GetRandomResultTables(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::GetRandomResultTables(ServerModels::GetRandomResultTablesRequest& request)
    {
        return GetRandomResultTables(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::GetUserInventory(ServerModels::GetUserInventoryRequest& request, ProcessApiCallback<ServerModels::GetUserInventoryResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::GetUserInventory(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::GetUserInventory(ServerModels::GetUserInventoryRequest& request)
    {
        return GetUserInventory(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::GrantItemsToCharacter(ServerModels::GrantItemsToCharacterRequest& request, ProcessApiCallback<ServerModels::GrantItemsToCharacterResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::GrantItemsToCharacter(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::GrantItemsToCharacter(ServerModels::GrantItemsToCharacterRequest& request)
    {
        return GrantItemsToCharacter(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::GrantItemsToUser(ServerModels::GrantItemsToUserRequest& request, ProcessApiCallback<ServerModels::GrantItemsToUserResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::GrantItemsToUser(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::GrantItemsToUser(ServerModels::GrantItemsToUserRequest& request)
    {
        return GrantItemsToUser(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::GrantItemsToUsers(ServerModels::GrantItemsToUsersRequest& request, ProcessApiCallback<ServerModels::GrantItemsToUsersResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::GrantItemsToUsers(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::GrantItemsToUsers(ServerModels::GrantItemsToUsersRequest& request)
    {
        return GrantItemsToUsers(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::ModifyItemUses(ServerModels::ModifyItemUsesRequest& request, ProcessApiCallback<ServerModels::ModifyItemUsesResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::ModifyItemUses(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::ModifyItemUses(ServerModels::ModifyItemUsesRequest& request)
    {
        return ModifyItemUses(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::MoveItemToCharacterFromCharacter(ServerModels::MoveItemToCharacterFromCharacterRequest& request, ProcessApiCallback<ServerModels::MoveItemToCharacterFromCharacterResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::MoveItemToCharacterFromCharacter(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::MoveItemToCharacterFromCharacter(ServerModels::MoveItemToCharacterFromCharacterRequest& request)
    {
        return MoveItemToCharacterFromCharacter(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::MoveItemToCharacterFromUser(ServerModels::MoveItemToCharacterFromUserRequest& request, ProcessApiCallback<ServerModels::MoveItemToCharacterFromUserResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::MoveItemToCharacterFromUser(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::MoveItemToCharacterFromUser(ServerModels::MoveItemToCharacterFromUserRequest& request)
    {
        return MoveItemToCharacterFromUser(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::MoveItemToUserFromCharacter(ServerModels::MoveItemToUserFromCharacterRequest& request, ProcessApiCallback<ServerModels::MoveItemToUserFromCharacterResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::MoveItemToUserFromCharacter(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::MoveItemToUserFromCharacter(ServerModels::MoveItemToUserFromCharacterRequest& request)
    {
        return MoveItemToUserFromCharacter(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::RedeemCoupon(ServerModels::RedeemCouponRequest& request, ProcessApiCallback<ServerModels::RedeemCouponResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::RedeemCoupon(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::RedeemCoupon(ServerModels::RedeemCouponRequest& request)
    {
        return RedeemCoupon(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::ReportPlayer(ServerModels::ReportPlayerServerRequest& request, ProcessApiCallback<ServerModels::ReportPlayerServerResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::ReportPlayer(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::ReportPlayer(ServerModels::ReportPlayerServerRequest& request)
    {
        return ReportPlayer(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::RevokeInventoryItem(ServerModels::RevokeInventoryItemRequest& request, ProcessApiCallback<ServerModels::RevokeInventoryResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::RevokeInventoryItem(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::RevokeInventoryItem(ServerModels::RevokeInventoryItemRequest& request)
    {
        return RevokeInventoryItem(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::SubtractCharacterVirtualCurrency(ServerModels::SubtractCharacterVirtualCurrencyRequest& request, ProcessApiCallback<ServerModels::ModifyCharacterVirtualCurrencyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::SubtractCharacterVirtualCurrency(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::SubtractCharacterVirtualCurrency(ServerModels::SubtractCharacterVirtualCurrencyRequest& request)
    {
        return SubtractCharacterVirtualCurrency(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::SubtractUserVirtualCurrency(ServerModels::SubtractUserVirtualCurrencyRequest& request, ProcessApiCallback<ServerModels::ModifyUserVirtualCurrencyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::SubtractUserVirtualCurrency(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::SubtractUserVirtualCurrency(ServerModels::SubtractUserVirtualCurrencyRequest& request)
    {
        return SubtractUserVirtualCurrency(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::UnlockContainerInstance(ServerModels::UnlockContainerInstanceRequest& request, ProcessApiCallback<ServerModels::UnlockContainerItemResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::UnlockContainerInstance(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::UnlockContainerInstance(ServerModels::UnlockContainerInstanceRequest& request)
    {
        return UnlockContainerInstance(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::UnlockContainerItem(ServerModels::UnlockContainerItemRequest& request, ProcessApiCallback<ServerModels::UnlockContainerItemResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::UnlockContainerItem(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::UnlockContainerItem(ServerModels::UnlockContainerItemRequest& request)
    {
        return UnlockContainerItem(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::UpdateUserInventoryItemCustomData(ServerModels::UpdateUserInventoryItemDataRequest& request, ProcessApiCallback<ServerModels::EmptyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::UpdateUserInventoryItemCustomData(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::UpdateUserInventoryItemCustomData(ServerModels::UpdateUserInventoryItemDataRequest& request)
    {
        return UpdateUserInventoryItemCustomData(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::AddFriend(ServerModels::AddFriendRequest& request, ProcessApiCallback<ServerModels::EmptyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::AddFriend(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::AddFriend(ServerModels::AddFriendRequest& request)
    {
        return AddFriend(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::GetFriendsList(ServerModels::GetFriendsListRequest& request, ProcessApiCallback<ServerModels::GetFriendsListResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::GetFriendsList(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::GetFriendsList(ServerModels::GetFriendsListRequest& request)
    {
        return GetFriendsList(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::RemoveFriend(ServerModels::RemoveFriendRequest& request, ProcessApiCallback<ServerModels::EmptyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::RemoveFriend(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::RemoveFriend(ServerModels::RemoveFriendRequest& request)
    {
        return RemoveFriend(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::SetFriendTags(ServerModels::SetFriendTagsRequest& request, ProcessApiCallback<ServerModels::EmptyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::SetFriendTags(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::SetFriendTags(ServerModels::SetFriendTagsRequest& request)
    {
        return SetFriendTags(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::DeregisterGame(ServerModels::DeregisterGameRequest& request, ProcessApiCallback<ServerModels::DeregisterGameResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::DeregisterGame(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::DeregisterGame(ServerModels::DeregisterGameRequest& request)
    {
        return DeregisterGame(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::NotifyMatchmakerPlayerLeft(ServerModels::NotifyMatchmakerPlayerLeftRequest& request, ProcessApiCallback<ServerModels::NotifyMatchmakerPlayerLeftResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::NotifyMatchmakerPlayerLeft(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::NotifyMatchmakerPlayerLeft(ServerModels::NotifyMatchmakerPlayerLeftRequest& request)
    {
        return NotifyMatchmakerPlayerLeft(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::RedeemMatchmakerTicket(ServerModels::RedeemMatchmakerTicketRequest& request, ProcessApiCallback<ServerModels::RedeemMatchmakerTicketResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::RedeemMatchmakerTicket(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::RedeemMatchmakerTicket(ServerModels::RedeemMatchmakerTicketRequest& request)
    {
        return RedeemMatchmakerTicket(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::RefreshGameServerInstanceHeartbeat(ServerModels::RefreshGameServerInstanceHeartbeatRequest& request, ProcessApiCallback<ServerModels::RefreshGameServerInstanceHeartbeatResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::RefreshGameServerInstanceHeartbeat(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::RefreshGameServerInstanceHeartbeat(ServerModels::RefreshGameServerInstanceHeartbeatRequest& request)
    {
        return RefreshGameServerInstanceHeartbeat(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::RegisterGame(ServerModels::RegisterGameRequest& request, ProcessApiCallback<ServerModels::RegisterGameResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::RegisterGame(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::RegisterGame(ServerModels::RegisterGameRequest& request)
    {
        return RegisterGame(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::SetGameServerInstanceData(ServerModels::SetGameServerInstanceDataRequest& request, ProcessApiCallback<ServerModels::SetGameServerInstanceDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::SetGameServerInstanceData(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::SetGameServerInstanceData(ServerModels::SetGameServerInstanceDataRequest& request)
    {
        return SetGameServerInstanceData(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::SetGameServerInstanceState(ServerModels::SetGameServerInstanceStateRequest& request, ProcessApiCallback<ServerModels::SetGameServerInstanceStateResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::SetGameServerInstanceState(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::SetGameServerInstanceState(ServerModels::SetGameServerInstanceStateRequest& request)
    {
        return SetGameServerInstanceState(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::SetGameServerInstanceTags(ServerModels::SetGameServerInstanceTagsRequest& request, ProcessApiCallback<ServerModels::SetGameServerInstanceTagsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::SetGameServerInstanceTags(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::SetGameServerInstanceTags(ServerModels::SetGameServerInstanceTagsRequest& request)
    {
        return SetGameServerInstanceTags(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::WriteCharacterEvent(ServerModels::WriteServerCharacterEventRequest& request, ProcessApiCallback<ServerModels::WriteEventResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::WriteCharacterEvent(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::WriteCharacterEvent(ServerModels::WriteServerCharacterEventRequest& request)
    {
        return WriteCharacterEvent(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::WritePlayerEvent(ServerModels::WriteServerPlayerEventRequest& request, ProcessApiCallback<ServerModels::WriteEventResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::WritePlayerEvent(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::WritePlayerEvent(ServerModels::WriteServerPlayerEventRequest& request)
    {
        return WritePlayerEvent(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::WriteTitleEvent(ServerModels::WriteTitleEventRequest& request, ProcessApiCallback<ServerModels::WriteEventResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::WriteTitleEvent(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::WriteTitleEvent(ServerModels::WriteTitleEventRequest& request)
    {
        return WriteTitleEvent(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::AddSharedGroupMembers(ServerModels::AddSharedGroupMembersRequest& request, ProcessApiCallback<ServerModels::AddSharedGroupMembersResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::AddSharedGroupMembers(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::AddSharedGroupMembers(ServerModels::AddSharedGroupMembersRequest& request)
    {
        return AddSharedGroupMembers(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::CreateSharedGroup(ServerModels::CreateSharedGroupRequest& request, ProcessApiCallback<ServerModels::CreateSharedGroupResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::CreateSharedGroup(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::CreateSharedGroup(ServerModels::CreateSharedGroupRequest& request)
    {
        return CreateSharedGroup(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::DeleteSharedGroup(ServerModels::DeleteSharedGroupRequest& request, ProcessApiCallback<ServerModels::EmptyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::DeleteSharedGroup(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::DeleteSharedGroup(ServerModels::DeleteSharedGroupRequest& request)
    {
        return DeleteSharedGroup(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::GetSharedGroupData(ServerModels::GetSharedGroupDataRequest& request, ProcessApiCallback<ServerModels::GetSharedGroupDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::GetSharedGroupData(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::GetSharedGroupData(ServerModels::GetSharedGroupDataRequest& request)
    {
        return GetSharedGroupData(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::RemoveSharedGroupMembers(ServerModels::RemoveSharedGroupMembersRequest& request, ProcessApiCallback<ServerModels::RemoveSharedGroupMembersResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::RemoveSharedGroupMembers(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::RemoveSharedGroupMembers(ServerModels::RemoveSharedGroupMembersRequest& request)
    {
        return RemoveSharedGroupMembers(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::UpdateSharedGroupData(ServerModels::UpdateSharedGroupDataRequest& request, ProcessApiCallback<ServerModels::UpdateSharedGroupDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::UpdateSharedGroupData(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::UpdateSharedGroupData(ServerModels::UpdateSharedGroupDataRequest& request)
    {
        return UpdateSharedGroupData(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::ExecuteCloudScript(ServerModels::ExecuteCloudScriptServerRequest& request, ProcessApiCallback<ServerModels::ExecuteCloudScriptResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::ExecuteCloudScript(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::ExecuteCloudScript(ServerModels::ExecuteCloudScriptServerRequest& request)
    {
        return ExecuteCloudScript(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::GetContentDownloadUrl(ServerModels::GetContentDownloadUrlRequest& request, ProcessApiCallback<ServerModels::GetContentDownloadUrlResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::GetContentDownloadUrl(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::GetContentDownloadUrl(ServerModels::GetContentDownloadUrlRequest& request)
    {
        return GetContentDownloadUrl(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::DeleteCharacterFromUser(ServerModels::DeleteCharacterFromUserRequest& request, ProcessApiCallback<ServerModels::DeleteCharacterFromUserResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::DeleteCharacterFromUser(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::DeleteCharacterFromUser(ServerModels::DeleteCharacterFromUserRequest& request)
    {
        return DeleteCharacterFromUser(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::GetAllUsersCharacters(ServerModels::ListUsersCharactersRequest& request, ProcessApiCallback<ServerModels::ListUsersCharactersResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::GetAllUsersCharacters(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::GetAllUsersCharacters(ServerModels::ListUsersCharactersRequest& request)
    {
        return GetAllUsersCharacters(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::GetCharacterLeaderboard(ServerModels::GetCharacterLeaderboardRequest& request, ProcessApiCallback<ServerModels::GetCharacterLeaderboardResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::GetCharacterLeaderboard(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::GetCharacterLeaderboard(ServerModels::GetCharacterLeaderboardRequest& request)
    {
        return GetCharacterLeaderboard(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::GetCharacterStatistics(ServerModels::GetCharacterStatisticsRequest& request, ProcessApiCallback<ServerModels::GetCharacterStatisticsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::GetCharacterStatistics(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::GetCharacterStatistics(ServerModels::GetCharacterStatisticsRequest& request)
    {
        return GetCharacterStatistics(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::GetLeaderboardAroundCharacter(ServerModels::GetLeaderboardAroundCharacterRequest& request, ProcessApiCallback<ServerModels::GetLeaderboardAroundCharacterResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::GetLeaderboardAroundCharacter(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::GetLeaderboardAroundCharacter(ServerModels::GetLeaderboardAroundCharacterRequest& request)
    {
        return GetLeaderboardAroundCharacter(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::GetLeaderboardForUserCharacters(ServerModels::GetLeaderboardForUsersCharactersRequest& request, ProcessApiCallback<ServerModels::GetLeaderboardForUsersCharactersResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::GetLeaderboardForUserCharacters(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::GetLeaderboardForUserCharacters(ServerModels::GetLeaderboardForUsersCharactersRequest& request)
    {
        return GetLeaderboardForUserCharacters(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::GrantCharacterToUser(ServerModels::GrantCharacterToUserRequest& request, ProcessApiCallback<ServerModels::GrantCharacterToUserResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::GrantCharacterToUser(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::GrantCharacterToUser(ServerModels::GrantCharacterToUserRequest& request)
    {
        return GrantCharacterToUser(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::UpdateCharacterStatistics(ServerModels::UpdateCharacterStatisticsRequest& request, ProcessApiCallback<ServerModels::UpdateCharacterStatisticsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::UpdateCharacterStatistics(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::UpdateCharacterStatistics(ServerModels::UpdateCharacterStatisticsRequest& request)
    {
        return UpdateCharacterStatistics(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::GetCharacterData(ServerModels::GetCharacterDataRequest& request, ProcessApiCallback<ServerModels::GetCharacterDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::GetCharacterData(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::GetCharacterData(ServerModels::GetCharacterDataRequest& request)
    {
        return GetCharacterData(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::GetCharacterInternalData(ServerModels::GetCharacterDataRequest& request, ProcessApiCallback<ServerModels::GetCharacterDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::GetCharacterInternalData(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::GetCharacterInternalData(ServerModels::GetCharacterDataRequest& request)
    {
        return GetCharacterInternalData(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::GetCharacterReadOnlyData(ServerModels::GetCharacterDataRequest& request, ProcessApiCallback<ServerModels::GetCharacterDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::GetCharacterReadOnlyData(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::GetCharacterReadOnlyData(ServerModels::GetCharacterDataRequest& request)
    {
        return GetCharacterReadOnlyData(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::UpdateCharacterData(ServerModels::UpdateCharacterDataRequest& request, ProcessApiCallback<ServerModels::UpdateCharacterDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::UpdateCharacterData(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::UpdateCharacterData(ServerModels::UpdateCharacterDataRequest& request)
    {
        return UpdateCharacterData(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::UpdateCharacterInternalData(ServerModels::UpdateCharacterDataRequest& request, ProcessApiCallback<ServerModels::UpdateCharacterDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::UpdateCharacterInternalData(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::UpdateCharacterInternalData(ServerModels::UpdateCharacterDataRequest& request)
    {
        return UpdateCharacterInternalData(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::UpdateCharacterReadOnlyData(ServerModels::UpdateCharacterDataRequest& request, ProcessApiCallback<ServerModels::UpdateCharacterDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::UpdateCharacterReadOnlyData(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::UpdateCharacterReadOnlyData(ServerModels::UpdateCharacterDataRequest& request)
    {
        return UpdateCharacterReadOnlyData(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::AddPlayerTag(ServerModels::AddPlayerTagRequest& request, ProcessApiCallback<ServerModels::AddPlayerTagResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::AddPlayerTag(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::AddPlayerTag(ServerModels::AddPlayerTagRequest& request)
    {
        return AddPlayerTag(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::GetAllActionGroups(ProcessApiCallback<ServerModels::GetAllActionGroupsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::GetAllActionGroups(callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::GetAllActionGroups()
    {
        return GetAllActionGroups(nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::GetAllSegments(ProcessApiCallback<ServerModels::GetAllSegmentsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::GetAllSegments(callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::GetAllSegments()
    {
        return GetAllSegments(nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::GetPlayerSegments(ServerModels::GetPlayersSegmentsRequest& request, ProcessApiCallback<ServerModels::GetPlayerSegmentsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::GetPlayerSegments(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::GetPlayerSegments(ServerModels::GetPlayersSegmentsRequest& request)
    {
        return GetPlayerSegments(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::GetPlayersInSegment(ServerModels::GetPlayersInSegmentRequest& request, ProcessApiCallback<ServerModels::GetPlayersInSegmentResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::GetPlayersInSegment(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::GetPlayersInSegment(ServerModels::GetPlayersInSegmentRequest& request)
    {
        return GetPlayersInSegment(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::GetPlayerTags(ServerModels::GetPlayerTagsRequest& request, ProcessApiCallback<ServerModels::GetPlayerTagsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::GetPlayerTags(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::GetPlayerTags(ServerModels::GetPlayerTagsRequest& request)
    {
        return GetPlayerTags(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::RemovePlayerTag(ServerModels::RemovePlayerTagRequest& request, ProcessApiCallback<ServerModels::RemovePlayerTagResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::RemovePlayerTag(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::RemovePlayerTag(ServerModels::RemovePlayerTagRequest& request)
    {
        return RemovePlayerTag(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabCombo_ServerSysComponent::AwardSteamAchievement(ServerModels::AwardSteamAchievementRequest& request, ProcessApiCallback<ServerModels::AwardSteamAchievementResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabServerApi::AwardSteamAchievement(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabCombo_ServerSysComponent::AwardSteamAchievement(ServerModels::AwardSteamAchievementRequest& request)
    {
        return AwardSteamAchievement(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
}
