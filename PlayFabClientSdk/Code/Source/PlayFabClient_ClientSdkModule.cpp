
#include "StdAfx.h"

#include <platform_impl.h> // Resharper says this is unused, but it's still required in some less direct way

#include "PlayFabClient_ClientSysComponent.h"

#include "PlayFabSettings.h"
#include <PlayFabClientSdk/PlayFabError.h>

#include <IGem.h>

namespace PlayFabClientSdk
{
    static void ExampleGlobalErrorHandler(const PlayFabError& error, void* customData)
    {
        AZ_TracePrintf("PlayFab", "==================================================================\n");
        AZ_TracePrintf("PlayFab", "PlayFab Error\n");
        AZ_TracePrintf("PlayFab", " HTTP Status: %s\n", error.HttpStatus.c_str());
        AZ_TracePrintf("PlayFab", " Error: %s\n", error.ErrorName.c_str());
        AZ_TracePrintf("PlayFab", " Description: %s\n", error.ErrorMessage.c_str());

        if (!error.ErrorDetails.empty())
        {
            AZ_TracePrintf("PlayFab", " Additional Info:\n")
                for (auto& details : error.ErrorDetails)
                {
                    AZ_TracePrintf("PlayFab", "  %s: %s\n", details.first.c_str(), details.second.c_str());
                }
        }
        AZ_TracePrintf("PlayFab", "==================================================================\n");
    }

    class PlayFabClient_ClientSdkModule
        : public CryHooksModule
    {
    public:
        AZ_RTTI(PlayFabClient_ClientSdkModule, "{FDEEA325-EC4C-4D4B-9FBD-E64A8D523CE0}", CryHooksModule);

        PlayFabClient_ClientSdkModule()
            : CryHooksModule()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                PlayFabClient_ClientSysComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<PlayFabClient_ClientSysComponent>(),
            };
        }

        void OnSystemEvent(ESystemEvent event, UINT_PTR wparam, UINT_PTR lparam) override
        {
            switch (event)
            {
            case ESYSTEM_EVENT_GAME_POST_INIT:
            {
                // Set the game title id
                auto titleIdCvar = gEnv->pConsole->GetCVar("playfab_titleid");
                if (titleIdCvar)
                {
                    PlayFabSettings::playFabSettings.titleId = titleIdCvar->GetString();
                }

                PlayFabSettings::playFabSettings.globalErrorHandler = &ExampleGlobalErrorHandler;
            }

            break;

            case ESYSTEM_EVENT_FULL_SHUTDOWN:
            case ESYSTEM_EVENT_FAST_SHUTDOWN:
                // Put your shutdown code here
                // Other Gems may have been shutdown already, but none will have destructed
                break;
            }
        }

    };
}

// DO NOT MODIFY THIS LINE UNLESS YOU RENAME THE GEM
// The first parameter should be GemName_GemIdLower
// The second should be the fully qualified name of the class above
AZ_DECLARE_MODULE_CLASS(PlayFabClientSdk_59aceeb4fcdc4556859a00fdef51702b, PlayFabClientSdk::PlayFabClient_ClientSdkModule)
