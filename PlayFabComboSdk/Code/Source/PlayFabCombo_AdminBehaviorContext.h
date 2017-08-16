// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

#pragma once
#include <AzCore/Component/Component.h>

namespace PlayFabComboSdk
{
		// This component provides behavior context reflection for the PlayFab SDK, this allows it to be used by Lua and other Lumberyard systems.
		class PlayFabCombo_AdminBehaviorContext : public AZ::Component
		{
		public:
			AZ_COMPONENT(PlayFabCombo_AdminBehaviorContext, "{d704c53d-a6e4-55d0-ada8-0c318f4f9066}");

			static void Reflect(AZ::ReflectContext* context);

			void Activate() override { }
			void Deactivate() override { }

		};

}
