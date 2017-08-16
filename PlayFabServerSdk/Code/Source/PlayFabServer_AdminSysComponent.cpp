
#include "StdAfx.h"

#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>

#include "PlayFabServer_AdminSysComponent.h"

#include "PlayFabSettings.h"
#include "PlayFabAdminApi.h"

namespace PlayFabServerSdk
{
    void PlayFabServer_AdminSysComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<PlayFabServer_AdminSysComponent, AZ::Component>()
                ->Version(0)
                ->SerializerForEmptyClass();

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<PlayFabServer_AdminSysComponent>("PlayFabServer_Admin", "Provides access to the Admin API within the PlayFab Server SDK")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                    // ->Attribute(AZ::Edit::Attributes::Category, "") Set a category
                    ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System"))
                    ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void PlayFabServer_AdminSysComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("PlayFabServer_AdminService"));
    }

    void PlayFabServer_AdminSysComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("PlayFabServer_AdminService"));
    }

    void PlayFabServer_AdminSysComponent::GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required)
    {
        (void)required;
    }

    void PlayFabServer_AdminSysComponent::GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
        (void)dependent;
    }

    void PlayFabServer_AdminSysComponent::Init()
    {
    }

    void PlayFabServer_AdminSysComponent::Activate()
    {
        PlayFabServer_AdminRequestBus::Handler::BusConnect();
        PlayFabServer_AdminSimpleRequestBus::Handler::BusConnect(); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    }

    void PlayFabServer_AdminSysComponent::Deactivate()
    {
        PlayFabServer_AdminRequestBus::Handler::BusDisconnect();
        PlayFabServer_AdminSimpleRequestBus::Handler::BusDisconnect(); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    }

    int PlayFabServer_AdminSysComponent::GetPendingCalls()
    {
        return PlayFabRequestManager::playFabHttp->GetPendingCalls();
    }

    // ------------ Generated API call wrappers
    int PlayFabServer_AdminSysComponent::CreatePlayerSharedSecret(AdminModels::CreatePlayerSharedSecretRequest& request, ProcessApiCallback<AdminModels::CreatePlayerSharedSecretResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::CreatePlayerSharedSecret(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::CreatePlayerSharedSecret(AdminModels::CreatePlayerSharedSecretRequest& request)
    {
        return CreatePlayerSharedSecret(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::DeletePlayerSharedSecret(AdminModels::DeletePlayerSharedSecretRequest& request, ProcessApiCallback<AdminModels::DeletePlayerSharedSecretResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::DeletePlayerSharedSecret(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::DeletePlayerSharedSecret(AdminModels::DeletePlayerSharedSecretRequest& request)
    {
        return DeletePlayerSharedSecret(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::GetPlayerSharedSecrets(ProcessApiCallback<AdminModels::GetPlayerSharedSecretsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::GetPlayerSharedSecrets(callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::GetPlayerSharedSecrets()
    {
        return GetPlayerSharedSecrets(nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::GetPolicy(AdminModels::GetPolicyRequest& request, ProcessApiCallback<AdminModels::GetPolicyResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::GetPolicy(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::GetPolicy(AdminModels::GetPolicyRequest& request)
    {
        return GetPolicy(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::SetPlayerSecret(AdminModels::SetPlayerSecretRequest& request, ProcessApiCallback<AdminModels::SetPlayerSecretResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::SetPlayerSecret(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::SetPlayerSecret(AdminModels::SetPlayerSecretRequest& request)
    {
        return SetPlayerSecret(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::UpdatePlayerSharedSecret(AdminModels::UpdatePlayerSharedSecretRequest& request, ProcessApiCallback<AdminModels::UpdatePlayerSharedSecretResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::UpdatePlayerSharedSecret(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::UpdatePlayerSharedSecret(AdminModels::UpdatePlayerSharedSecretRequest& request)
    {
        return UpdatePlayerSharedSecret(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::UpdatePolicy(AdminModels::UpdatePolicyRequest& request, ProcessApiCallback<AdminModels::UpdatePolicyResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::UpdatePolicy(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::UpdatePolicy(AdminModels::UpdatePolicyRequest& request)
    {
        return UpdatePolicy(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::BanUsers(AdminModels::BanUsersRequest& request, ProcessApiCallback<AdminModels::BanUsersResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::BanUsers(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::BanUsers(AdminModels::BanUsersRequest& request)
    {
        return BanUsers(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::DeletePlayer(AdminModels::DeletePlayerRequest& request, ProcessApiCallback<AdminModels::DeletePlayerResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::DeletePlayer(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::DeletePlayer(AdminModels::DeletePlayerRequest& request)
    {
        return DeletePlayer(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::GetUserAccountInfo(AdminModels::LookupUserAccountInfoRequest& request, ProcessApiCallback<AdminModels::LookupUserAccountInfoResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::GetUserAccountInfo(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::GetUserAccountInfo(AdminModels::LookupUserAccountInfoRequest& request)
    {
        return GetUserAccountInfo(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::GetUserBans(AdminModels::GetUserBansRequest& request, ProcessApiCallback<AdminModels::GetUserBansResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::GetUserBans(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::GetUserBans(AdminModels::GetUserBansRequest& request)
    {
        return GetUserBans(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::ResetUsers(AdminModels::ResetUsersRequest& request, ProcessApiCallback<AdminModels::BlankResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::ResetUsers(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::ResetUsers(AdminModels::ResetUsersRequest& request)
    {
        return ResetUsers(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::RevokeAllBansForUser(AdminModels::RevokeAllBansForUserRequest& request, ProcessApiCallback<AdminModels::RevokeAllBansForUserResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::RevokeAllBansForUser(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::RevokeAllBansForUser(AdminModels::RevokeAllBansForUserRequest& request)
    {
        return RevokeAllBansForUser(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::RevokeBans(AdminModels::RevokeBansRequest& request, ProcessApiCallback<AdminModels::RevokeBansResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::RevokeBans(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::RevokeBans(AdminModels::RevokeBansRequest& request)
    {
        return RevokeBans(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::SendAccountRecoveryEmail(AdminModels::SendAccountRecoveryEmailRequest& request, ProcessApiCallback<AdminModels::SendAccountRecoveryEmailResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::SendAccountRecoveryEmail(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::SendAccountRecoveryEmail(AdminModels::SendAccountRecoveryEmailRequest& request)
    {
        return SendAccountRecoveryEmail(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::UpdateBans(AdminModels::UpdateBansRequest& request, ProcessApiCallback<AdminModels::UpdateBansResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::UpdateBans(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::UpdateBans(AdminModels::UpdateBansRequest& request)
    {
        return UpdateBans(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::UpdateUserTitleDisplayName(AdminModels::UpdateUserTitleDisplayNameRequest& request, ProcessApiCallback<AdminModels::UpdateUserTitleDisplayNameResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::UpdateUserTitleDisplayName(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::UpdateUserTitleDisplayName(AdminModels::UpdateUserTitleDisplayNameRequest& request)
    {
        return UpdateUserTitleDisplayName(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::CreatePlayerStatisticDefinition(AdminModels::CreatePlayerStatisticDefinitionRequest& request, ProcessApiCallback<AdminModels::CreatePlayerStatisticDefinitionResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::CreatePlayerStatisticDefinition(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::CreatePlayerStatisticDefinition(AdminModels::CreatePlayerStatisticDefinitionRequest& request)
    {
        return CreatePlayerStatisticDefinition(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::DeleteUsers(AdminModels::DeleteUsersRequest& request, ProcessApiCallback<AdminModels::DeleteUsersResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::DeleteUsers(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::DeleteUsers(AdminModels::DeleteUsersRequest& request)
    {
        return DeleteUsers(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::GetDataReport(AdminModels::GetDataReportRequest& request, ProcessApiCallback<AdminModels::GetDataReportResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::GetDataReport(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::GetDataReport(AdminModels::GetDataReportRequest& request)
    {
        return GetDataReport(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::GetPlayerStatisticDefinitions(ProcessApiCallback<AdminModels::GetPlayerStatisticDefinitionsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::GetPlayerStatisticDefinitions(callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::GetPlayerStatisticDefinitions()
    {
        return GetPlayerStatisticDefinitions(nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::GetPlayerStatisticVersions(AdminModels::GetPlayerStatisticVersionsRequest& request, ProcessApiCallback<AdminModels::GetPlayerStatisticVersionsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::GetPlayerStatisticVersions(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::GetPlayerStatisticVersions(AdminModels::GetPlayerStatisticVersionsRequest& request)
    {
        return GetPlayerStatisticVersions(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::GetUserData(AdminModels::GetUserDataRequest& request, ProcessApiCallback<AdminModels::GetUserDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::GetUserData(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::GetUserData(AdminModels::GetUserDataRequest& request)
    {
        return GetUserData(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::GetUserInternalData(AdminModels::GetUserDataRequest& request, ProcessApiCallback<AdminModels::GetUserDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::GetUserInternalData(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::GetUserInternalData(AdminModels::GetUserDataRequest& request)
    {
        return GetUserInternalData(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::GetUserPublisherData(AdminModels::GetUserDataRequest& request, ProcessApiCallback<AdminModels::GetUserDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::GetUserPublisherData(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::GetUserPublisherData(AdminModels::GetUserDataRequest& request)
    {
        return GetUserPublisherData(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::GetUserPublisherInternalData(AdminModels::GetUserDataRequest& request, ProcessApiCallback<AdminModels::GetUserDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::GetUserPublisherInternalData(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::GetUserPublisherInternalData(AdminModels::GetUserDataRequest& request)
    {
        return GetUserPublisherInternalData(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::GetUserPublisherReadOnlyData(AdminModels::GetUserDataRequest& request, ProcessApiCallback<AdminModels::GetUserDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::GetUserPublisherReadOnlyData(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::GetUserPublisherReadOnlyData(AdminModels::GetUserDataRequest& request)
    {
        return GetUserPublisherReadOnlyData(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::GetUserReadOnlyData(AdminModels::GetUserDataRequest& request, ProcessApiCallback<AdminModels::GetUserDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::GetUserReadOnlyData(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::GetUserReadOnlyData(AdminModels::GetUserDataRequest& request)
    {
        return GetUserReadOnlyData(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::IncrementPlayerStatisticVersion(AdminModels::IncrementPlayerStatisticVersionRequest& request, ProcessApiCallback<AdminModels::IncrementPlayerStatisticVersionResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::IncrementPlayerStatisticVersion(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::IncrementPlayerStatisticVersion(AdminModels::IncrementPlayerStatisticVersionRequest& request)
    {
        return IncrementPlayerStatisticVersion(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::RefundPurchase(AdminModels::RefundPurchaseRequest& request, ProcessApiCallback<AdminModels::RefundPurchaseResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::RefundPurchase(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::RefundPurchase(AdminModels::RefundPurchaseRequest& request)
    {
        return RefundPurchase(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::ResetUserStatistics(AdminModels::ResetUserStatisticsRequest& request, ProcessApiCallback<AdminModels::ResetUserStatisticsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::ResetUserStatistics(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::ResetUserStatistics(AdminModels::ResetUserStatisticsRequest& request)
    {
        return ResetUserStatistics(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::ResolvePurchaseDispute(AdminModels::ResolvePurchaseDisputeRequest& request, ProcessApiCallback<AdminModels::ResolvePurchaseDisputeResponse> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::ResolvePurchaseDispute(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::ResolvePurchaseDispute(AdminModels::ResolvePurchaseDisputeRequest& request)
    {
        return ResolvePurchaseDispute(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::UpdatePlayerStatisticDefinition(AdminModels::UpdatePlayerStatisticDefinitionRequest& request, ProcessApiCallback<AdminModels::UpdatePlayerStatisticDefinitionResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::UpdatePlayerStatisticDefinition(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::UpdatePlayerStatisticDefinition(AdminModels::UpdatePlayerStatisticDefinitionRequest& request)
    {
        return UpdatePlayerStatisticDefinition(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::UpdateUserData(AdminModels::UpdateUserDataRequest& request, ProcessApiCallback<AdminModels::UpdateUserDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::UpdateUserData(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::UpdateUserData(AdminModels::UpdateUserDataRequest& request)
    {
        return UpdateUserData(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::UpdateUserInternalData(AdminModels::UpdateUserInternalDataRequest& request, ProcessApiCallback<AdminModels::UpdateUserDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::UpdateUserInternalData(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::UpdateUserInternalData(AdminModels::UpdateUserInternalDataRequest& request)
    {
        return UpdateUserInternalData(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::UpdateUserPublisherData(AdminModels::UpdateUserDataRequest& request, ProcessApiCallback<AdminModels::UpdateUserDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::UpdateUserPublisherData(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::UpdateUserPublisherData(AdminModels::UpdateUserDataRequest& request)
    {
        return UpdateUserPublisherData(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::UpdateUserPublisherInternalData(AdminModels::UpdateUserInternalDataRequest& request, ProcessApiCallback<AdminModels::UpdateUserDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::UpdateUserPublisherInternalData(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::UpdateUserPublisherInternalData(AdminModels::UpdateUserInternalDataRequest& request)
    {
        return UpdateUserPublisherInternalData(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::UpdateUserPublisherReadOnlyData(AdminModels::UpdateUserDataRequest& request, ProcessApiCallback<AdminModels::UpdateUserDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::UpdateUserPublisherReadOnlyData(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::UpdateUserPublisherReadOnlyData(AdminModels::UpdateUserDataRequest& request)
    {
        return UpdateUserPublisherReadOnlyData(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::UpdateUserReadOnlyData(AdminModels::UpdateUserDataRequest& request, ProcessApiCallback<AdminModels::UpdateUserDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::UpdateUserReadOnlyData(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::UpdateUserReadOnlyData(AdminModels::UpdateUserDataRequest& request)
    {
        return UpdateUserReadOnlyData(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::AddNews(AdminModels::AddNewsRequest& request, ProcessApiCallback<AdminModels::AddNewsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::AddNews(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::AddNews(AdminModels::AddNewsRequest& request)
    {
        return AddNews(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::AddVirtualCurrencyTypes(AdminModels::AddVirtualCurrencyTypesRequest& request, ProcessApiCallback<AdminModels::BlankResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::AddVirtualCurrencyTypes(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::AddVirtualCurrencyTypes(AdminModels::AddVirtualCurrencyTypesRequest& request)
    {
        return AddVirtualCurrencyTypes(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::DeleteStore(AdminModels::DeleteStoreRequest& request, ProcessApiCallback<AdminModels::DeleteStoreResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::DeleteStore(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::DeleteStore(AdminModels::DeleteStoreRequest& request)
    {
        return DeleteStore(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::GetCatalogItems(AdminModels::GetCatalogItemsRequest& request, ProcessApiCallback<AdminModels::GetCatalogItemsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::GetCatalogItems(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::GetCatalogItems(AdminModels::GetCatalogItemsRequest& request)
    {
        return GetCatalogItems(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::GetPublisherData(AdminModels::GetPublisherDataRequest& request, ProcessApiCallback<AdminModels::GetPublisherDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::GetPublisherData(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::GetPublisherData(AdminModels::GetPublisherDataRequest& request)
    {
        return GetPublisherData(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::GetRandomResultTables(AdminModels::GetRandomResultTablesRequest& request, ProcessApiCallback<AdminModels::GetRandomResultTablesResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::GetRandomResultTables(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::GetRandomResultTables(AdminModels::GetRandomResultTablesRequest& request)
    {
        return GetRandomResultTables(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::GetStoreItems(AdminModels::GetStoreItemsRequest& request, ProcessApiCallback<AdminModels::GetStoreItemsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::GetStoreItems(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::GetStoreItems(AdminModels::GetStoreItemsRequest& request)
    {
        return GetStoreItems(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::GetTitleData(AdminModels::GetTitleDataRequest& request, ProcessApiCallback<AdminModels::GetTitleDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::GetTitleData(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::GetTitleData(AdminModels::GetTitleDataRequest& request)
    {
        return GetTitleData(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::GetTitleInternalData(AdminModels::GetTitleDataRequest& request, ProcessApiCallback<AdminModels::GetTitleDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::GetTitleInternalData(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::GetTitleInternalData(AdminModels::GetTitleDataRequest& request)
    {
        return GetTitleInternalData(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::ListVirtualCurrencyTypes(ProcessApiCallback<AdminModels::ListVirtualCurrencyTypesResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::ListVirtualCurrencyTypes(callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::ListVirtualCurrencyTypes()
    {
        return ListVirtualCurrencyTypes(nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::RemoveVirtualCurrencyTypes(AdminModels::RemoveVirtualCurrencyTypesRequest& request, ProcessApiCallback<AdminModels::BlankResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::RemoveVirtualCurrencyTypes(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::RemoveVirtualCurrencyTypes(AdminModels::RemoveVirtualCurrencyTypesRequest& request)
    {
        return RemoveVirtualCurrencyTypes(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::SetCatalogItems(AdminModels::UpdateCatalogItemsRequest& request, ProcessApiCallback<AdminModels::UpdateCatalogItemsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::SetCatalogItems(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::SetCatalogItems(AdminModels::UpdateCatalogItemsRequest& request)
    {
        return SetCatalogItems(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::SetStoreItems(AdminModels::UpdateStoreItemsRequest& request, ProcessApiCallback<AdminModels::UpdateStoreItemsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::SetStoreItems(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::SetStoreItems(AdminModels::UpdateStoreItemsRequest& request)
    {
        return SetStoreItems(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::SetTitleData(AdminModels::SetTitleDataRequest& request, ProcessApiCallback<AdminModels::SetTitleDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::SetTitleData(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::SetTitleData(AdminModels::SetTitleDataRequest& request)
    {
        return SetTitleData(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::SetTitleInternalData(AdminModels::SetTitleDataRequest& request, ProcessApiCallback<AdminModels::SetTitleDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::SetTitleInternalData(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::SetTitleInternalData(AdminModels::SetTitleDataRequest& request)
    {
        return SetTitleInternalData(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::SetupPushNotification(AdminModels::SetupPushNotificationRequest& request, ProcessApiCallback<AdminModels::SetupPushNotificationResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::SetupPushNotification(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::SetupPushNotification(AdminModels::SetupPushNotificationRequest& request)
    {
        return SetupPushNotification(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::UpdateCatalogItems(AdminModels::UpdateCatalogItemsRequest& request, ProcessApiCallback<AdminModels::UpdateCatalogItemsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::UpdateCatalogItems(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::UpdateCatalogItems(AdminModels::UpdateCatalogItemsRequest& request)
    {
        return UpdateCatalogItems(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::UpdateRandomResultTables(AdminModels::UpdateRandomResultTablesRequest& request, ProcessApiCallback<AdminModels::UpdateRandomResultTablesResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::UpdateRandomResultTables(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::UpdateRandomResultTables(AdminModels::UpdateRandomResultTablesRequest& request)
    {
        return UpdateRandomResultTables(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::UpdateStoreItems(AdminModels::UpdateStoreItemsRequest& request, ProcessApiCallback<AdminModels::UpdateStoreItemsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::UpdateStoreItems(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::UpdateStoreItems(AdminModels::UpdateStoreItemsRequest& request)
    {
        return UpdateStoreItems(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::AddUserVirtualCurrency(AdminModels::AddUserVirtualCurrencyRequest& request, ProcessApiCallback<AdminModels::ModifyUserVirtualCurrencyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::AddUserVirtualCurrency(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::AddUserVirtualCurrency(AdminModels::AddUserVirtualCurrencyRequest& request)
    {
        return AddUserVirtualCurrency(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::GetUserInventory(AdminModels::GetUserInventoryRequest& request, ProcessApiCallback<AdminModels::GetUserInventoryResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::GetUserInventory(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::GetUserInventory(AdminModels::GetUserInventoryRequest& request)
    {
        return GetUserInventory(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::GrantItemsToUsers(AdminModels::GrantItemsToUsersRequest& request, ProcessApiCallback<AdminModels::GrantItemsToUsersResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::GrantItemsToUsers(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::GrantItemsToUsers(AdminModels::GrantItemsToUsersRequest& request)
    {
        return GrantItemsToUsers(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::RevokeInventoryItem(AdminModels::RevokeInventoryItemRequest& request, ProcessApiCallback<AdminModels::RevokeInventoryResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::RevokeInventoryItem(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::RevokeInventoryItem(AdminModels::RevokeInventoryItemRequest& request)
    {
        return RevokeInventoryItem(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::SubtractUserVirtualCurrency(AdminModels::SubtractUserVirtualCurrencyRequest& request, ProcessApiCallback<AdminModels::ModifyUserVirtualCurrencyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::SubtractUserVirtualCurrency(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::SubtractUserVirtualCurrency(AdminModels::SubtractUserVirtualCurrencyRequest& request)
    {
        return SubtractUserVirtualCurrency(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::GetMatchmakerGameInfo(AdminModels::GetMatchmakerGameInfoRequest& request, ProcessApiCallback<AdminModels::GetMatchmakerGameInfoResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::GetMatchmakerGameInfo(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::GetMatchmakerGameInfo(AdminModels::GetMatchmakerGameInfoRequest& request)
    {
        return GetMatchmakerGameInfo(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::GetMatchmakerGameModes(AdminModels::GetMatchmakerGameModesRequest& request, ProcessApiCallback<AdminModels::GetMatchmakerGameModesResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::GetMatchmakerGameModes(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::GetMatchmakerGameModes(AdminModels::GetMatchmakerGameModesRequest& request)
    {
        return GetMatchmakerGameModes(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::ModifyMatchmakerGameModes(AdminModels::ModifyMatchmakerGameModesRequest& request, ProcessApiCallback<AdminModels::ModifyMatchmakerGameModesResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::ModifyMatchmakerGameModes(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::ModifyMatchmakerGameModes(AdminModels::ModifyMatchmakerGameModesRequest& request)
    {
        return ModifyMatchmakerGameModes(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::AddServerBuild(AdminModels::AddServerBuildRequest& request, ProcessApiCallback<AdminModels::AddServerBuildResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::AddServerBuild(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::AddServerBuild(AdminModels::AddServerBuildRequest& request)
    {
        return AddServerBuild(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::GetServerBuildInfo(AdminModels::GetServerBuildInfoRequest& request, ProcessApiCallback<AdminModels::GetServerBuildInfoResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::GetServerBuildInfo(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::GetServerBuildInfo(AdminModels::GetServerBuildInfoRequest& request)
    {
        return GetServerBuildInfo(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::GetServerBuildUploadUrl(AdminModels::GetServerBuildUploadURLRequest& request, ProcessApiCallback<AdminModels::GetServerBuildUploadURLResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::GetServerBuildUploadUrl(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::GetServerBuildUploadUrl(AdminModels::GetServerBuildUploadURLRequest& request)
    {
        return GetServerBuildUploadUrl(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::ListServerBuilds(ProcessApiCallback<AdminModels::ListBuildsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::ListServerBuilds(callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::ListServerBuilds()
    {
        return ListServerBuilds(nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::ModifyServerBuild(AdminModels::ModifyServerBuildRequest& request, ProcessApiCallback<AdminModels::ModifyServerBuildResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::ModifyServerBuild(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::ModifyServerBuild(AdminModels::ModifyServerBuildRequest& request)
    {
        return ModifyServerBuild(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::RemoveServerBuild(AdminModels::RemoveServerBuildRequest& request, ProcessApiCallback<AdminModels::RemoveServerBuildResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::RemoveServerBuild(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::RemoveServerBuild(AdminModels::RemoveServerBuildRequest& request)
    {
        return RemoveServerBuild(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::SetPublisherData(AdminModels::SetPublisherDataRequest& request, ProcessApiCallback<AdminModels::SetPublisherDataResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::SetPublisherData(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::SetPublisherData(AdminModels::SetPublisherDataRequest& request)
    {
        return SetPublisherData(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::GetCloudScriptRevision(AdminModels::GetCloudScriptRevisionRequest& request, ProcessApiCallback<AdminModels::GetCloudScriptRevisionResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::GetCloudScriptRevision(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::GetCloudScriptRevision(AdminModels::GetCloudScriptRevisionRequest& request)
    {
        return GetCloudScriptRevision(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::GetCloudScriptVersions(ProcessApiCallback<AdminModels::GetCloudScriptVersionsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::GetCloudScriptVersions(callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::GetCloudScriptVersions()
    {
        return GetCloudScriptVersions(nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::SetPublishedRevision(AdminModels::SetPublishedRevisionRequest& request, ProcessApiCallback<AdminModels::SetPublishedRevisionResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::SetPublishedRevision(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::SetPublishedRevision(AdminModels::SetPublishedRevisionRequest& request)
    {
        return SetPublishedRevision(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::UpdateCloudScript(AdminModels::UpdateCloudScriptRequest& request, ProcessApiCallback<AdminModels::UpdateCloudScriptResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::UpdateCloudScript(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::UpdateCloudScript(AdminModels::UpdateCloudScriptRequest& request)
    {
        return UpdateCloudScript(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::DeleteContent(AdminModels::DeleteContentRequest& request, ProcessApiCallback<AdminModels::BlankResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::DeleteContent(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::DeleteContent(AdminModels::DeleteContentRequest& request)
    {
        return DeleteContent(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::GetContentList(AdminModels::GetContentListRequest& request, ProcessApiCallback<AdminModels::GetContentListResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::GetContentList(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::GetContentList(AdminModels::GetContentListRequest& request)
    {
        return GetContentList(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::GetContentUploadUrl(AdminModels::GetContentUploadUrlRequest& request, ProcessApiCallback<AdminModels::GetContentUploadUrlResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::GetContentUploadUrl(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::GetContentUploadUrl(AdminModels::GetContentUploadUrlRequest& request)
    {
        return GetContentUploadUrl(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::ResetCharacterStatistics(AdminModels::ResetCharacterStatisticsRequest& request, ProcessApiCallback<AdminModels::ResetCharacterStatisticsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::ResetCharacterStatistics(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::ResetCharacterStatistics(AdminModels::ResetCharacterStatisticsRequest& request)
    {
        return ResetCharacterStatistics(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::AddPlayerTag(AdminModels::AddPlayerTagRequest& request, ProcessApiCallback<AdminModels::AddPlayerTagResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::AddPlayerTag(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::AddPlayerTag(AdminModels::AddPlayerTagRequest& request)
    {
        return AddPlayerTag(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::GetAllActionGroups(ProcessApiCallback<AdminModels::GetAllActionGroupsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::GetAllActionGroups(callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::GetAllActionGroups()
    {
        return GetAllActionGroups(nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::GetAllSegments(ProcessApiCallback<AdminModels::GetAllSegmentsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::GetAllSegments(callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::GetAllSegments()
    {
        return GetAllSegments(nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::GetPlayerSegments(AdminModels::GetPlayersSegmentsRequest& request, ProcessApiCallback<AdminModels::GetPlayerSegmentsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::GetPlayerSegments(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::GetPlayerSegments(AdminModels::GetPlayersSegmentsRequest& request)
    {
        return GetPlayerSegments(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::GetPlayersInSegment(AdminModels::GetPlayersInSegmentRequest& request, ProcessApiCallback<AdminModels::GetPlayersInSegmentResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::GetPlayersInSegment(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::GetPlayersInSegment(AdminModels::GetPlayersInSegmentRequest& request)
    {
        return GetPlayersInSegment(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::GetPlayerTags(AdminModels::GetPlayerTagsRequest& request, ProcessApiCallback<AdminModels::GetPlayerTagsResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::GetPlayerTags(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::GetPlayerTags(AdminModels::GetPlayerTagsRequest& request)
    {
        return GetPlayerTags(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::RemovePlayerTag(AdminModels::RemovePlayerTagRequest& request, ProcessApiCallback<AdminModels::RemovePlayerTagResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::RemovePlayerTag(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::RemovePlayerTag(AdminModels::RemovePlayerTagRequest& request)
    {
        return RemovePlayerTag(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::AbortTaskInstance(AdminModels::AbortTaskInstanceRequest& request, ProcessApiCallback<AdminModels::EmptyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::AbortTaskInstance(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::AbortTaskInstance(AdminModels::AbortTaskInstanceRequest& request)
    {
        return AbortTaskInstance(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::CreateActionsOnPlayersInSegmentTask(AdminModels::CreateActionsOnPlayerSegmentTaskRequest& request, ProcessApiCallback<AdminModels::CreateTaskResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::CreateActionsOnPlayersInSegmentTask(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::CreateActionsOnPlayersInSegmentTask(AdminModels::CreateActionsOnPlayerSegmentTaskRequest& request)
    {
        return CreateActionsOnPlayersInSegmentTask(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::CreateCloudScriptTask(AdminModels::CreateCloudScriptTaskRequest& request, ProcessApiCallback<AdminModels::CreateTaskResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::CreateCloudScriptTask(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::CreateCloudScriptTask(AdminModels::CreateCloudScriptTaskRequest& request)
    {
        return CreateCloudScriptTask(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::DeleteTask(AdminModels::DeleteTaskRequest& request, ProcessApiCallback<AdminModels::EmptyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::DeleteTask(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::DeleteTask(AdminModels::DeleteTaskRequest& request)
    {
        return DeleteTask(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::GetActionsOnPlayersInSegmentTaskInstance(AdminModels::GetTaskInstanceRequest& request, ProcessApiCallback<AdminModels::GetActionsOnPlayersInSegmentTaskInstanceResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::GetActionsOnPlayersInSegmentTaskInstance(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::GetActionsOnPlayersInSegmentTaskInstance(AdminModels::GetTaskInstanceRequest& request)
    {
        return GetActionsOnPlayersInSegmentTaskInstance(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::GetCloudScriptTaskInstance(AdminModels::GetTaskInstanceRequest& request, ProcessApiCallback<AdminModels::GetCloudScriptTaskInstanceResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::GetCloudScriptTaskInstance(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::GetCloudScriptTaskInstance(AdminModels::GetTaskInstanceRequest& request)
    {
        return GetCloudScriptTaskInstance(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::GetTaskInstances(AdminModels::GetTaskInstancesRequest& request, ProcessApiCallback<AdminModels::GetTaskInstancesResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::GetTaskInstances(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::GetTaskInstances(AdminModels::GetTaskInstancesRequest& request)
    {
        return GetTaskInstances(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::GetTasks(AdminModels::GetTasksRequest& request, ProcessApiCallback<AdminModels::GetTasksResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::GetTasks(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::GetTasks(AdminModels::GetTasksRequest& request)
    {
        return GetTasks(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::RunTask(AdminModels::RunTaskRequest& request, ProcessApiCallback<AdminModels::RunTaskResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::RunTask(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::RunTask(AdminModels::RunTaskRequest& request)
    {
        return RunTask(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
    int PlayFabServer_AdminSysComponent::UpdateTask(AdminModels::UpdateTaskRequest& request, ProcessApiCallback<AdminModels::EmptyResult> callback, ErrorCallback errorCallback, void* customData)
    {
        return PlayFabAdminApi::UpdateTask(request, callback, errorCallback, customData);
    }
    // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
    int PlayFabServer_AdminSysComponent::UpdateTask(AdminModels::UpdateTaskRequest& request)
    {
        return UpdateTask(request, nullptr, nullptr, nullptr);
    }
    // THIRD_KIND_END
}
