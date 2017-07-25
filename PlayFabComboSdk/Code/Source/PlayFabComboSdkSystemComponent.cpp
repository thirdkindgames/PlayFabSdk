
#include "StdAfx.h"

#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>

#include "PlayFabComboSdkSystemComponent.h"

namespace PlayFabComboSdk
{
    void PlayFabComboSdkSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<PlayFabComboSdkSystemComponent, AZ::Component>()
                ->Version(0)
                ->SerializerForEmptyClass();

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<PlayFabComboSdkSystemComponent>("PlayFabComboSdk", "[Description of functionality provided by this System Component]")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                        // ->Attribute(AZ::Edit::Attributes::Category, "") Set a category
                        ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System"))
                        ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void PlayFabComboSdkSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("PlayFabComboSdkService"));
    }

    void PlayFabComboSdkSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("PlayFabComboSdkService"));
    }

    void PlayFabComboSdkSystemComponent::GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required)
    {
        (void)required;
    }

    void PlayFabComboSdkSystemComponent::GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
        (void)dependent;
    }

    void PlayFabComboSdkSystemComponent::Init()
    {
    }

    void PlayFabComboSdkSystemComponent::Activate()
    {
        PlayFabComboSdkRequestBus::Handler::BusConnect();
    }

    void PlayFabComboSdkSystemComponent::Deactivate()
    {
        PlayFabComboSdkRequestBus::Handler::BusDisconnect();
    }
}
