// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

#pragma once
#include <AzCore/Component/Component.h>

namespace PlayFabServerSdk
{
		// This component provides behavior context reflection for the PlayFab SDK, this allows it to be used by Lua and other Lumberyard systems.
		class PlayFabServer_ServerBehaviorContext : public AZ::Component
		{
		public:
			AZ_COMPONENT(PlayFabServer_ServerBehaviorContext, "{6c533100-2112-5601-bff0-9099453e5dcd}");

			static void Reflect(AZ::ReflectContext* context);

			void Activate() override { }
			void Deactivate() override { }

		};

}
