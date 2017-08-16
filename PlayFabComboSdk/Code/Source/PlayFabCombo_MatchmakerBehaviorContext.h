// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

#pragma once
#include <AzCore/Component/Component.h>

namespace PlayFabComboSdk
{
		// This component provides behavior context reflection for the PlayFab SDK, this allows it to be used by Lua and other Lumberyard systems.
		class PlayFabCombo_MatchmakerBehaviorContext : public AZ::Component
		{
		public:
			AZ_COMPONENT(PlayFabCombo_MatchmakerBehaviorContext, "{5efb548d-a677-59d9-a1e3-1af7ce84afc4}");

			static void Reflect(AZ::ReflectContext* context);

			void Activate() override { }
			void Deactivate() override { }

		};

}
