// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

#pragma once
#include <AzCore/Component/Component.h>

namespace PlayFabComboSdk
{
		// This component provides behavior context reflection for the PlayFab SDK, this allows it to be used by Lua and other Lumberyard systems.
		class PlayFabCombo_ServerBehaviorContext : public AZ::Component
		{
		public:
			AZ_COMPONENT(PlayFabCombo_ServerBehaviorContext, "{817e4bf4-bfec-5f4b-8422-554f852280cb}");

			static void Reflect(AZ::ReflectContext* context);

			void Activate() override { }
			void Deactivate() override { }

		};

}
