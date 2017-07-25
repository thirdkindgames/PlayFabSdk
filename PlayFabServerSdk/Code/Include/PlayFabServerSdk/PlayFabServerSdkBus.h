
#pragma once

#include <AzCore/EBus/EBus.h>

namespace PlayFabServerSdk
{
    class PlayFabServerSdkRequests
        : public AZ::EBusTraits
    {

    public:
        static const AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static const AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        // Public functions
    };
    using PlayFabServerSdkRequestBus = AZ::EBus<PlayFabServerSdkRequests>;
} // namespace PlayFabServerSdk
