// #THIRD_KIND_PLAYFAB_NOTIFICATION_BUS: dbowen (2017/08/11)
#pragma once
#include <AzCore/EBus/EBus.h>
#include <PlayFabComboSdk/PlayFabMatchmakerDataModels.h>

namespace PlayFabComboSdk
{
    // Request based notification bus, use this bus when you want to listen for a callback from a specific instance of an API request.
    class PlayFabCombo_MatchmakerNotifications
        : public AZ::EBusTraits
    {

    public:
		// The EBus has multiple addresses. Addresses are not ordered. The address corresponds to the ID of the request.
		static const AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::ById;
		typedef int BusIdType;

        // ------------ General notifications (not related to a specific API call)
        virtual void OnError(const PlayFabError& error) {};

        // ------------ Generated API call wrappers
        virtual void OnAuthUser(const MatchmakerModels::AuthUserResponse& result) {};
        virtual void OnPlayerJoined(const MatchmakerModels::PlayerJoinedResponse& result) {};
        virtual void OnPlayerLeft(const MatchmakerModels::PlayerLeftResponse& result) {};
        virtual void OnStartGame(const MatchmakerModels::StartGameResponse& result) {};
        virtual void OnUserInfo(const MatchmakerModels::UserInfoResponse& result) {};
    
   };

    using PlayFabCombo_MatchmakerNotificationBus = AZ::EBus<PlayFabCombo_MatchmakerNotifications>;

    // Global notification bus - use this bus when you want to listen for all responses to a particular type of request. 
    class PlayFabCombo_MatchmakerGlobalNotifications
        : public AZ::EBusTraits
    {

    public:
		// The EBus has a single address, all notifications go to this address.
		static const AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;

        // ------------ General notifications (not related to a specific API call)
        virtual void OnError(const PlayFabError& error, int requestId) {};

        // ------------ Generated API call wrappers
        virtual void OnAuthUser(const MatchmakerModels::AuthUserResponse& result, int requestId) {};
        virtual void OnPlayerJoined(const MatchmakerModels::PlayerJoinedResponse& result, int requestId) {};
        virtual void OnPlayerLeft(const MatchmakerModels::PlayerLeftResponse& result, int requestId) {};
        virtual void OnStartGame(const MatchmakerModels::StartGameResponse& result, int requestId) {};
        virtual void OnUserInfo(const MatchmakerModels::UserInfoResponse& result, int requestId) {};
    
   };

    using PlayFabCombo_MatchmakerGlobalNotificationBus = AZ::EBus<PlayFabCombo_MatchmakerGlobalNotifications>;

} // namespace PlayFabComboSdk
