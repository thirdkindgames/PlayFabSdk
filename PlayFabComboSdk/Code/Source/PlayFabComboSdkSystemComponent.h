
#pragma once

#include <AzCore/Component/Component.h>

#include <PlayFabComboSdk/PlayFabComboSdkBus.h>

namespace PlayFabComboSdk
{
    class PlayFabComboSdkSystemComponent
        : public AZ::Component
        , protected PlayFabComboSdkRequestBus::Handler
    {
    public:
        AZ_COMPONENT(PlayFabComboSdkSystemComponent, "{525A86F9-CFF4-4868-A55F-24F5E76823CB}");

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

    protected:
        ////////////////////////////////////////////////////////////////////////
        // PlayFabComboSdkRequestBus interface implementation

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
