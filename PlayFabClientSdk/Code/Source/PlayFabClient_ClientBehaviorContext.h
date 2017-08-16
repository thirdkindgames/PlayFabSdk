// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

#pragma once
#include <AzCore/Component/Component.h>

namespace PlayFabClientSdk
{
		// This component provides behavior context reflection for the PlayFab SDK, this allows it to be used by Lua and other Lumberyard systems.
		class PlayFabClient_ClientBehaviorContext : public AZ::Component
		{
		public:
			AZ_COMPONENT(PlayFabClient_ClientBehaviorContext, "{ed3ee3c8-0f0b-5070-a8a2-587712cacbf3}");

			static void Reflect(AZ::ReflectContext* context);

			void Activate() override { }
			void Deactivate() override { }

		};

}
