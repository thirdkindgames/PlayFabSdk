
#include "StdAfx.h"

#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>

#include "PlayFabServerSdkSystemComponent.h"

namespace PlayFabServerSdk
{
    void PlayFabServerSdkSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<PlayFabServerSdkSystemComponent, AZ::Component>()
                ->Version(0)
                ->SerializerForEmptyClass();

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<PlayFabServerSdkSystemComponent>("PlayFabServerSdk", "[Description of functionality provided by this System Component]")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                        // ->Attribute(AZ::Edit::Attributes::Category, "") Set a category
                        ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System"))
                        ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void PlayFabServerSdkSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("PlayFabServerSdkService"));
    }

    void PlayFabServerSdkSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("PlayFabServerSdkService"));
    }

    void PlayFabServerSdkSystemComponent::GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required)
    {
        (void)required;
    }

    void PlayFabServerSdkSystemComponent::GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
        (void)dependent;
    }

    void PlayFabServerSdkSystemComponent::Init()
    {
    }

    void PlayFabServerSdkSystemComponent::Activate()
    {
        PlayFabServerSdkRequestBus::Handler::BusConnect();
    }

    void PlayFabServerSdkSystemComponent::Deactivate()
    {
        PlayFabServerSdkRequestBus::Handler::BusDisconnect();
    }
}
