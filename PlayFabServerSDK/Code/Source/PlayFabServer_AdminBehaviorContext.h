// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

#pragma once
#include <AzCore/Component/Component.h>

namespace PlayFabServerSdk
{
		// This component provides behavior context reflection for the PlayFab SDK, this allows it to be used by Lua and other Lumberyard systems.
		class PlayFabServer_AdminBehaviorContext : public AZ::Component
		{
		public:
			AZ_COMPONENT(PlayFabServer_AdminBehaviorContext, "{ea48519e-a065-5324-af53-4cc4ec71dfcd}");

			static void Reflect(AZ::ReflectContext* context);

			void Activate() override { }
			void Deactivate() override { }

		};

}
