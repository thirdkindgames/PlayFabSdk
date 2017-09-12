#pragma once

// #THIRD_KIND_PLAYFAB_DATA_GATHERER: gwatson (2017/09/12) - Added PlayFab data gatherer to send system information events to PlayFab on login

#include <AzCore/std/containers/unordered_map.h>

#include "PlayFabClientSdk/PlayFabBaseModel.h"

namespace PlayFab
{
    class PlayFabDataGatherer
    {
    public:
        using DataMap = AZStd::unordered_map<AZStd::string, PlayFabClientSdk::MultitypeVar>;

        PlayFabDataGatherer() = default;
        ~PlayFabDataGatherer() = default;

        AZStd::string GenerateReport();
        const DataMap& GetData();

    protected:
        void GatherData();

    private:
        DataMap m_dataMap;
        bool m_dataGathered = false;
    };
}
