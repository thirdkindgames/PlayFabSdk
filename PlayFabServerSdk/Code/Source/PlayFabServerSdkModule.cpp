
#include "StdAfx.h"
#include <platform_impl.h>

#include "PlayFabServerSdkSystemComponent.h"

#include <IGem.h>

namespace PlayFabServerSdk
{
    class PlayFabServerSdkModule
        : public CryHooksModule
    {
    public:
        AZ_RTTI(PlayFabServerSdkModule, "{11D4858D-545E-49DA-9C16-CB783E4541EA}", CryHooksModule);

        PlayFabServerSdkModule()
            : CryHooksModule()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                PlayFabServerSdkSystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<PlayFabServerSdkSystemComponent>(),
            };
        }
    };
}

// DO NOT MODIFY THIS LINE UNLESS YOU RENAME THE GEM
// The first parameter should be GemName_GemIdLower
// The second should be the fully qualified name of the class above
AZ_DECLARE_MODULE_CLASS(PlayFabServerSdk_a7bd94263453450a8cff6c8d047a82ee, PlayFabServerSdk::PlayFabServerSdkModule)
