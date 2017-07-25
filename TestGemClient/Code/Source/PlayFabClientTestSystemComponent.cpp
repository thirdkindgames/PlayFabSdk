
#include "StdAfx.h"

#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>

#include "PlayFabClientTestSystemComponent.h"

namespace PlayFabClientTest
{
    void PlayFabClientTestSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<PlayFabClientTestSystemComponent, AZ::Component>()
                ->Version(0)
                ->SerializerForEmptyClass();

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<PlayFabClientTestSystemComponent>("PlayFabClientTest", "[Description of functionality provided by this System Component]")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                    // ->Attribute(AZ::Edit::Attributes::Category, "") Set a category
                    ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System"))
                    ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void PlayFabClientTestSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("PlayFabClientTestService"));
    }

    void PlayFabClientTestSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("PlayFabClientTestService"));
    }

    void PlayFabClientTestSystemComponent::GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required)
    {
        (void)required;
    }

    void PlayFabClientTestSystemComponent::GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
        (void)dependent;
    }

    void PlayFabClientTestSystemComponent::Init()
    {
    }

    void PlayFabClientTestSystemComponent::Activate()
    {
        PlayFabClientTestRequestBus::Handler::BusConnect();
    }

    void PlayFabClientTestSystemComponent::Deactivate()
    {
        PlayFabClientTestRequestBus::Handler::BusDisconnect();
    }
}
