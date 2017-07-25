
#pragma once

#include <AzCore/EBus/EBus.h>

namespace PlayFabComboSdk
{
    class PlayFabComboSdkRequests
        : public AZ::EBusTraits
    {

    public:
        static const AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static const AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        // Public functions
    };
    using PlayFabComboSdkRequestBus = AZ::EBus<PlayFabComboSdkRequests>;
} // namespace PlayFabComboSdk
