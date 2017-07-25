
#include "StdAfx.h"

#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>

#include "PlayFabComboTestSystemComponent.h"

namespace PlayFabComboTest
{
    void PlayFabComboTestSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<PlayFabComboTestSystemComponent, AZ::Component>()
                ->Version(0)
                ->SerializerForEmptyClass();

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<PlayFabComboTestSystemComponent>("PlayFabComboTest", "[Description of functionality provided by this System Component]")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                        // ->Attribute(AZ::Edit::Attributes::Category, "") Set a category
                        ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System"))
                        ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void PlayFabComboTestSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("PlayFabComboTestService"));
    }

    void PlayFabComboTestSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("PlayFabComboTestService"));
    }

    void PlayFabComboTestSystemComponent::GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required)
    {
        (void)required;
    }

    void PlayFabComboTestSystemComponent::GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
        (void)dependent;
    }

    void PlayFabComboTestSystemComponent::Init()
    {
    }

    void PlayFabComboTestSystemComponent::Activate()
    {
        PlayFabComboTestRequestBus::Handler::BusConnect();
    }

    void PlayFabComboTestSystemComponent::Deactivate()
    {
        PlayFabComboTestRequestBus::Handler::BusDisconnect();
    }
}
