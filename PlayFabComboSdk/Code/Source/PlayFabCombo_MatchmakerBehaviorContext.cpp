// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

#include "StdAfx.h"
#include "PlayFabCombo_MatchmakerBehaviorContext.h"
#include <AzCore/RTTI/ReflectContext.h>
#include <AzCore/RTTI/BehaviorContext.h>

#include "PlayFabComboSdk/PlayFabCombo_MatchmakerNotificationBus.h"
#include "PlayFabComboSdk/PlayFabCombo_MatchmakerBus.h"
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
    class PlayFabCombo_MatchmakerBehaviorBusBaseHandler : 
		public AZ::BehaviorEBusHandler
	{ 

    // Note that normally we would list all of the notification handler functions here using the AZ_EBUS_BEHAVIOR_BINDER macro
    // However the AZ_EBUS_BEHAVIOR_BINDER macro supports a maximum of 30 functions, so we generate the calls by hand here instead.
            
    public: 
        AZ_CLASS_ALLOCATOR(T,AZ::SystemAllocator,0)
    protected:

		enum {
			FN_OnError,
			FN_OnAuthUser,
			FN_OnPlayerJoined,
			FN_OnPlayerLeft,
			FN_OnStartGame,
			FN_OnUserInfo,
			
        	FN_MAX
    	};

        int GetFunctionIndex(const char* functionName) const override {
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnError)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnAuthUser)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnPlayerJoined)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnPlayerLeft)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnStartGame)
			AZ_BEHAVIOR_EBUS_FUNC_INDEX(OnUserInfo)
			
			return -1;
		}

        bool Connect(AZ::BehaviorValueParameter* id = nullptr) override {
			return AZ::Internal::EBusConnector<T>::Connect(static_cast<T*>(this), id);
		}

        // Constructor
        PlayFabCombo_MatchmakerBehaviorBusBaseHandler()
        {
        	m_events.resize(FN_MAX);
			SetEvent(&T::OnError,"OnError");
			SetEvent(&T::OnAuthUser,"OnAuthUser");
			SetEvent(&T::OnPlayerJoined,"OnPlayerJoined");
			SetEvent(&T::OnPlayerLeft,"OnPlayerLeft");
			SetEvent(&T::OnStartGame,"OnStartGame");
			SetEvent(&T::OnUserInfo,"OnUserInfo");
			
        }
        
    };

    // Behavior binder for the (request) based notification bus.
	class PlayFabCombo_MatchmakerBehaviorBusHandler : 
		public PlayFabCombo_MatchmakerNotificationBus::Handler, 
		public PlayFabCombo_MatchmakerBehaviorBusBaseHandler<PlayFabCombo_MatchmakerBehaviorBusHandler>
	{
   
	public:
        
		AZ_RTTI(PlayFabCombo_MatchmakerBehaviorBusHandler,"{e5d09cd9-8a23-5234-aabf-881cab746f01}",AZ::BehaviorEBusHandler)

        void Disconnect() override {
			BusDisconnect();
		}
        
		void OnError(const PlayFabError& error) override
		{
			Call(FN_OnError, error);
		}

		// ------------ Generated APIs to receive from the PlayFab notification bus and forward on to the Lua behavior context.
	
		void OnAuthUser(const MatchmakerModels::AuthUserResponse& result) { Call(FN_OnAuthUser, result); };
		void OnPlayerJoined(const MatchmakerModels::PlayerJoinedResponse& result) { Call(FN_OnPlayerJoined, result); };
		void OnPlayerLeft(const MatchmakerModels::PlayerLeftResponse& result) { Call(FN_OnPlayerLeft, result); };
		void OnStartGame(const MatchmakerModels::StartGameResponse& result) { Call(FN_OnStartGame, result); };
		void OnUserInfo(const MatchmakerModels::UserInfoResponse& result) { Call(FN_OnUserInfo, result); };

	};

    // Behavior binder for the (global) based notification bus.
	class PlayFabCombo_MatchmakerGlobalBehaviorBusHandler : 
		public PlayFabCombo_MatchmakerGlobalNotificationBus::Handler, 
		public PlayFabCombo_MatchmakerBehaviorBusBaseHandler<PlayFabCombo_MatchmakerGlobalBehaviorBusHandler>
	{
   
	public:
        
		AZ_RTTI(PlayFabCombo_MatchmakerGlobalBehaviorBusHandler,"{683b04b1-7a66-50d8-bd94-e34cce3ae565}",AZ::BehaviorEBusHandler)

        void Disconnect() override {
			BusDisconnect();
		}

		void OnError(const PlayFabError& error, int requestId) override
		{
			Call(FN_OnError, error, requestId);
		}

		// ------------ Generated APIs to receive from the PlayFab notification bus and forward on to the Lua behavior context.
	
		void OnAuthUser(const MatchmakerModels::AuthUserResponse& result,int requestId) { Call(FN_OnAuthUser, result,requestId); };
		void OnPlayerJoined(const MatchmakerModels::PlayerJoinedResponse& result,int requestId) { Call(FN_OnPlayerJoined, result,requestId); };
		void OnPlayerLeft(const MatchmakerModels::PlayerLeftResponse& result,int requestId) { Call(FN_OnPlayerLeft, result,requestId); };
		void OnStartGame(const MatchmakerModels::StartGameResponse& result,int requestId) { Call(FN_OnStartGame, result,requestId); };
		void OnUserInfo(const MatchmakerModels::UserInfoResponse& result,int requestId) { Call(FN_OnUserInfo, result,requestId); };

	};

    //-----------------------------------------------------------------------------------------------------
    // MAIN REFLECTION FUNCTION
    //-----------------------------------------------------------------------------------------------------
	void PlayFabCombo_MatchmakerBehaviorContext::Reflect(AZ::ReflectContext* context)
	{
		AZ::BehaviorContext* behaviorContext = azrtti_cast<AZ::BehaviorContext*>(context);
		if (behaviorContext)
		{
			// Reflect the request bus
			behaviorContext->EBus<PlayFabCombo_MatchmakerSimpleRequestBus>("PlayFabMatchmakerRequestBus")
				->Event("AuthUser", &PlayFabCombo_MatchmakerSimpleRequestBus::Events::AuthUser)
				->Event("PlayerJoined", &PlayFabCombo_MatchmakerSimpleRequestBus::Events::PlayerJoined)
				->Event("PlayerLeft", &PlayFabCombo_MatchmakerSimpleRequestBus::Events::PlayerLeft)
				->Event("StartGame", &PlayFabCombo_MatchmakerSimpleRequestBus::Events::StartGame)
				->Event("UserInfo", &PlayFabCombo_MatchmakerSimpleRequestBus::Events::UserInfo);

			// Reflect the ADDRESSED notification bus: (uses the BehaviorBusHandler declared at the beginning of this file)
			behaviorContext->EBus<PlayFabCombo_MatchmakerNotificationBus>("PlayFabMatchmakerNotificationBus")
				->Handler<PlayFabCombo_MatchmakerBehaviorBusHandler>();

			// Reflect the GLOBAL notification bus: (uses the BehaviorBusHandler declared at the beginning of this file)
			behaviorContext->EBus<PlayFabCombo_MatchmakerGlobalNotificationBus>("PlayFabMatchmakerGlobalNotificationBus")
				->Handler<PlayFabCombo_MatchmakerGlobalBehaviorBusHandler>();                
			
            //-----------------------------------------------------------------------------------------------------
			// Reflect enum values
            //-----------------------------------------------------------------------------------------------------
	        behaviorContext 
                ->Enum<MatchmakerModels::Region::RegionUSCentral>( "PlayFabMatchmaker_Region_USCentral" )
                ->Enum<MatchmakerModels::Region::RegionUSEast>( "PlayFabMatchmaker_Region_USEast" )
                ->Enum<MatchmakerModels::Region::RegionEUWest>( "PlayFabMatchmaker_Region_EUWest" )
                ->Enum<MatchmakerModels::Region::RegionSingapore>( "PlayFabMatchmaker_Region_Singapore" )
                ->Enum<MatchmakerModels::Region::RegionJapan>( "PlayFabMatchmaker_Region_Japan" )
                ->Enum<MatchmakerModels::Region::RegionBrazil>( "PlayFabMatchmaker_Region_Brazil" )
                ->Enum<MatchmakerModels::Region::RegionAustralia>( "PlayFabMatchmaker_Region_Australia" )
            ;
    
            //-----------------------------------------------------------------------------------------------------
			// Reflect data models (structs/classes)
            //-----------------------------------------------------------------------------------------------------

			behaviorContext->Class<MatchmakerModels::AuthUserRequest>("PlayFabMatchmaker_AuthUserRequest")
                ->Constructor() 
			    ->Property("AuthorizationTicket", BehaviorValueProperty(&MatchmakerModels::AuthUserRequest::AuthorizationTicket)) 
			;
		
			behaviorContext->Class<MatchmakerModels::AuthUserResponse>("PlayFabMatchmaker_AuthUserResponse")
                ->Constructor() 
			    ->Property("Authorized", BehaviorValueProperty(&MatchmakerModels::AuthUserResponse::Authorized)) 
			    ->Property("PlayFabId", BehaviorValueProperty(&MatchmakerModels::AuthUserResponse::PlayFabId)) 
			;
		
			behaviorContext->Class<MatchmakerModels::DeregisterGameRequest>("PlayFabMatchmaker_DeregisterGameRequest")
                ->Constructor() 
			    ->Property("LobbyId", BehaviorValueProperty(&MatchmakerModels::DeregisterGameRequest::LobbyId)) 
			;
		
			behaviorContext->Class<MatchmakerModels::DeregisterGameResponse>("PlayFabMatchmaker_DeregisterGameResponse")
                ->Constructor() 
			;
		
			behaviorContext->Class<MatchmakerModels::ItemInstance>("PlayFabMatchmaker_ItemInstance")
                ->Constructor() 
			    ->Property("ItemId", BehaviorValueProperty(&MatchmakerModels::ItemInstance::ItemId)) 
			    ->Property("ItemInstanceId", BehaviorValueProperty(&MatchmakerModels::ItemInstance::ItemInstanceId)) 
			    ->Property("ItemClass", BehaviorValueProperty(&MatchmakerModels::ItemInstance::ItemClass)) 
			    ->Property("PurchaseDate", BehaviorValueProperty(&MatchmakerModels::ItemInstance::PurchaseDate)) 
			    ->Property("Expiration", BehaviorValueProperty(&MatchmakerModels::ItemInstance::Expiration)) 
			    ->Property("RemainingUses", BehaviorValueProperty(&MatchmakerModels::ItemInstance::RemainingUses)) 
			    ->Property("UsesIncrementedBy", BehaviorValueProperty(&MatchmakerModels::ItemInstance::UsesIncrementedBy)) 
			    ->Property("Annotation", BehaviorValueProperty(&MatchmakerModels::ItemInstance::Annotation)) 
			    ->Property("CatalogVersion", BehaviorValueProperty(&MatchmakerModels::ItemInstance::CatalogVersion)) 
			    ->Property("BundleParent", BehaviorValueProperty(&MatchmakerModels::ItemInstance::BundleParent)) 
			    ->Property("DisplayName", BehaviorValueProperty(&MatchmakerModels::ItemInstance::DisplayName)) 
			    ->Property("UnitCurrency", BehaviorValueProperty(&MatchmakerModels::ItemInstance::UnitCurrency)) 
			    ->Property("UnitPrice", BehaviorValueProperty(&MatchmakerModels::ItemInstance::UnitPrice)) 
			    ->Property("BundleContents", BehaviorValueProperty(&MatchmakerModels::ItemInstance::BundleContents)) 
			;
		
			behaviorContext->Class<MatchmakerModels::PlayerJoinedRequest>("PlayFabMatchmaker_PlayerJoinedRequest")
                ->Constructor() 
			    ->Property("LobbyId", BehaviorValueProperty(&MatchmakerModels::PlayerJoinedRequest::LobbyId)) 
			    ->Property("PlayFabId", BehaviorValueProperty(&MatchmakerModels::PlayerJoinedRequest::PlayFabId)) 
			;
		
			behaviorContext->Class<MatchmakerModels::PlayerJoinedResponse>("PlayFabMatchmaker_PlayerJoinedResponse")
                ->Constructor() 
			;
		
			behaviorContext->Class<MatchmakerModels::PlayerLeftRequest>("PlayFabMatchmaker_PlayerLeftRequest")
                ->Constructor() 
			    ->Property("LobbyId", BehaviorValueProperty(&MatchmakerModels::PlayerLeftRequest::LobbyId)) 
			    ->Property("PlayFabId", BehaviorValueProperty(&MatchmakerModels::PlayerLeftRequest::PlayFabId)) 
			;
		
			behaviorContext->Class<MatchmakerModels::PlayerLeftResponse>("PlayFabMatchmaker_PlayerLeftResponse")
                ->Constructor() 
			;
		
			behaviorContext->Class<MatchmakerModels::RegisterGameRequest>("PlayFabMatchmaker_RegisterGameRequest")
                ->Constructor() 
			    ->Property("LobbyId", BehaviorValueProperty(&MatchmakerModels::RegisterGameRequest::LobbyId)) 
			    ->Property("ServerHost", BehaviorValueProperty(&MatchmakerModels::RegisterGameRequest::ServerHost)) 
			    ->Property("ServerPort", BehaviorValueProperty(&MatchmakerModels::RegisterGameRequest::ServerPort)) 
			    ->Property("Build", BehaviorValueProperty(&MatchmakerModels::RegisterGameRequest::Build)) 
			    ->Property("pfRegion",
				    [](MatchmakerModels::RegisterGameRequest* p) { return p->pfRegion; },
				    [](MatchmakerModels::RegisterGameRequest* p, MatchmakerModels::Region v) { p->pfRegion = v; })
			    ->Property("GameMode", BehaviorValueProperty(&MatchmakerModels::RegisterGameRequest::GameMode)) 
			;
		
			behaviorContext->Class<MatchmakerModels::RegisterGameResponse>("PlayFabMatchmaker_RegisterGameResponse")
                ->Constructor() 
			    ->Property("LobbyId", BehaviorValueProperty(&MatchmakerModels::RegisterGameResponse::LobbyId)) 
			;
		
			behaviorContext->Class<MatchmakerModels::StartGameRequest>("PlayFabMatchmaker_StartGameRequest")
                ->Constructor() 
			    ->Property("Build", BehaviorValueProperty(&MatchmakerModels::StartGameRequest::Build)) 
			    ->Property("pfRegion",
				    [](MatchmakerModels::StartGameRequest* p) { return p->pfRegion; },
				    [](MatchmakerModels::StartGameRequest* p, MatchmakerModels::Region v) { p->pfRegion = v; })
			    ->Property("GameMode", BehaviorValueProperty(&MatchmakerModels::StartGameRequest::GameMode)) 
			    ->Property("CustomCommandLineData", BehaviorValueProperty(&MatchmakerModels::StartGameRequest::CustomCommandLineData)) 
			    ->Property("ExternalMatchmakerEventEndpoint", BehaviorValueProperty(&MatchmakerModels::StartGameRequest::ExternalMatchmakerEventEndpoint)) 
			;
		
			behaviorContext->Class<MatchmakerModels::StartGameResponse>("PlayFabMatchmaker_StartGameResponse")
                ->Constructor() 
			    ->Property("GameID", BehaviorValueProperty(&MatchmakerModels::StartGameResponse::GameID)) 
			    ->Property("ServerHostname", BehaviorValueProperty(&MatchmakerModels::StartGameResponse::ServerHostname)) 
			    ->Property("ServerPort", BehaviorValueProperty(&MatchmakerModels::StartGameResponse::ServerPort)) 
			;
		
			behaviorContext->Class<MatchmakerModels::UserInfoRequest>("PlayFabMatchmaker_UserInfoRequest")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&MatchmakerModels::UserInfoRequest::PlayFabId)) 
			    ->Property("MinCatalogVersion", BehaviorValueProperty(&MatchmakerModels::UserInfoRequest::MinCatalogVersion)) 
			;
		
			behaviorContext->Class<MatchmakerModels::VirtualCurrencyRechargeTime>("PlayFabMatchmaker_VirtualCurrencyRechargeTime")
                ->Constructor() 
			    ->Property("SecondsToRecharge", BehaviorValueProperty(&MatchmakerModels::VirtualCurrencyRechargeTime::SecondsToRecharge)) 
			    ->Property("RechargeTime", BehaviorValueProperty(&MatchmakerModels::VirtualCurrencyRechargeTime::RechargeTime)) 
			    ->Property("RechargeMax", BehaviorValueProperty(&MatchmakerModels::VirtualCurrencyRechargeTime::RechargeMax)) 
			;
		
			behaviorContext->Class<MatchmakerModels::UserInfoResponse>("PlayFabMatchmaker_UserInfoResponse")
                ->Constructor() 
			    ->Property("PlayFabId", BehaviorValueProperty(&MatchmakerModels::UserInfoResponse::PlayFabId)) 
			    ->Property("Username", BehaviorValueProperty(&MatchmakerModels::UserInfoResponse::Username)) 
			    ->Property("TitleDisplayName", BehaviorValueProperty(&MatchmakerModels::UserInfoResponse::TitleDisplayName)) 
			    ->Property("Inventory", BehaviorValueProperty(&MatchmakerModels::UserInfoResponse::Inventory)) 
			    ->Property("IsDeveloper", BehaviorValueProperty(&MatchmakerModels::UserInfoResponse::IsDeveloper)) 
			    ->Property("SteamId", BehaviorValueProperty(&MatchmakerModels::UserInfoResponse::SteamId)) 
			;
		 
				
		} // if (behaviorContext) {...
	} // End of BehaviorContext::Reflect()

}