// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

#pragma once
#include <AzCore/Component/Component.h>

namespace PlayFabComboSdk
{
		// This component provides behavior context reflection for the PlayFab SDK, this allows it to be used by Lua and other Lumberyard systems.
		class PlayFabCombo_ClientBehaviorContext : public AZ::Component
		{
		public:
			AZ_COMPONENT(PlayFabCombo_ClientBehaviorContext, "{68948715-efe9-5d00-af29-f208dd87ada7}");

			static void Reflect(AZ::ReflectContext* context);

			void Activate() override { }
			void Deactivate() override { }

		};

}
