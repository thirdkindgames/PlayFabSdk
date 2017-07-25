
#include "StdAfx.h"
#include <platform_impl.h>

#include "PlayFabComboSdkSystemComponent.h"

#include <IGem.h>

namespace PlayFabComboSdk
{
    class PlayFabComboSdkModule
        : public CryHooksModule
    {
    public:
        AZ_RTTI(PlayFabComboSdkModule, "{C035EAD2-AD5D-458E-9D11-93B2E318CD09}", CryHooksModule);

        PlayFabComboSdkModule()
            : CryHooksModule()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                PlayFabComboSdkSystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<PlayFabComboSdkSystemComponent>(),
            };
        }
    };
}

// DO NOT MODIFY THIS LINE UNLESS YOU RENAME THE GEM
// The first parameter should be GemName_GemIdLower
// The second should be the fully qualified name of the class above
AZ_DECLARE_MODULE_CLASS(PlayFabComboSdk_abf1282cbb534d908e39e0684e34cb20, PlayFabComboSdk::PlayFabComboSdkModule)
