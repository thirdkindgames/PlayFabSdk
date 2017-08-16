// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

#pragma once
#include <AzCore/Component/Component.h>

namespace PlayFabServerSdk
{
		// This component provides behavior context reflection for the PlayFab SDK, this allows it to be used by Lua and other Lumberyard systems.
		class PlayFabServer_MatchmakerBehaviorContext : public AZ::Component
		{
		public:
			AZ_COMPONENT(PlayFabServer_MatchmakerBehaviorContext, "{93f5db22-cb41-5b32-9563-3727e0066df1}");

			static void Reflect(AZ::ReflectContext* context);

			void Activate() override { }
			void Deactivate() override { }

		};

}
