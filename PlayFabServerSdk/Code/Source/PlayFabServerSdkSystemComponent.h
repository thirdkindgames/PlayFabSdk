
#pragma once

#include <AzCore/Component/Component.h>

#include <PlayFabServerSdk/PlayFabServerSdkBus.h>

namespace PlayFabServerSdk
{
    class PlayFabServerSdkSystemComponent
        : public AZ::Component
        , protected PlayFabServerSdkRequestBus::Handler
    {
    public:
        AZ_COMPONENT(PlayFabServerSdkSystemComponent, "{9C3DF7E4-CCFD-42F4-9B75-0B9DF489456E}");

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

    protected:
        ////////////////////////////////////////////////////////////////////////
        // PlayFabServerSdkRequestBus interface implementation

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
