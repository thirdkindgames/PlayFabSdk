#pragma once

#include "PlayFab/PlayFabError.h"

namespace PlayFab
{
    class PlayFabSettings
    {
    public:
        static PlayFabSettings playFabSettings; // Global settings for all Apis

        const Aws::String playFabSDKVersion;
        const Aws::String playFabVersionString;

        bool useDevelopmentEnvironment;
        Aws::String developmentEnvironmentURL;
        Aws::String productionEnvironmentURL;
        Aws::String titleId; // You must set this value for PlayFab to work properly (Found in the Game Manager for your title, at the PlayFab Website)
        ErrorCallback globalErrorHandler;
        Aws::String advertisingIdType; // Set this to the appropriate AD_TYPE_X constant below
        Aws::String advertisingIdValue; // Set this to corresponding device value

        // DisableAdvertising is provided for completeness, but changing it is not suggested
        // Disabling this may prevent your advertising-related PlayFab marketplace partners from working correctly
        bool disableAdvertising;
        const Aws::String AD_TYPE_IDFA;
        const Aws::String AD_TYPE_ANDROID_ID;

        PlayFabSettings();

        Aws::String getURL(const Aws::String& callPath)
        {
            if (serverURL.length() == 0)
                serverURL = "https://"+titleId+(useDevelopmentEnvironment ? developmentEnvironmentURL : productionEnvironmentURL);
            return serverURL + callPath;
        }

    private:
        Aws::String serverURL; // A cache of the constructed url string
    };
}
