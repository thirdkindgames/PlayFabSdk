
#pragma once

#include <AzCore/EBus/EBus.h>

namespace PlayFabServerSdk
{
    class PlayFabServer_SettingsRequests
        : public AZ::EBusTraits
    {

    public:
        static const AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static const AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;

        // Read-Only Section
        virtual AZStd::string GetBuildIdentifier() = 0;

        // Read/Write Section
        virtual void SetTitleId(AZStd::string newTitleId) = 0;
        virtual AZStd::string GetTitleId() = 0;

        virtual void SetDevSecretKey(AZStd::string newSecretKey) = 0;
        virtual AZStd::string GetDevSecretKey() = 0;

    };

    using PlayFabServer_SettingsRequestBus = AZ::EBus<PlayFabServer_SettingsRequests>;
} // namespace PlayFabServerSdk
