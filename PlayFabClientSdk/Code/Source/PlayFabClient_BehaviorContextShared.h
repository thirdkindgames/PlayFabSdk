// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

// This file contains the reflection logic for any types which are global to the gem 
// E.g. any types which are ot tied to a specific API such as 'client', 'admin', 'matchmaking' etc.

#pragma once
#include <AzCore/Component/Component.h>
#include <AzCore/RTTI/ReflectContext.h>
#include <AzCore/RTTI/BehaviorContext.h>
#include <PlayFabClientSdk/PlayFabBaseModel.h>

namespace PlayFabClientSdk
{
		// This component provides behavior context reflection for the PlayFab SDK, this allows it to be used by Lua and other Lumberyard systems.
		class PlayFabClient_BehaviorContextShared : public AZ::Component
		{
		public:
			AZ_COMPONENT(PlayFabClient_BehaviorContextShared, "{0674978f-a73c-5e35-878d-444861d7041a}");

			static void Reflect(AZ::ReflectContext* context)
            {
                // Reflect only classes and enums which are global to the gem here (e.g. shared between APIs)
                // All other reflection is in PlayFab<Gem>_<Api>BehaviorContext.cpp
                AZ::BehaviorContext* behaviorContext = azrtti_cast<AZ::BehaviorContext*>(context);
                if (behaviorContext)
                {
                    behaviorContext->Class<PlayFabClientSdk::MultitypeVar>("PlayFabClient_MultitypeVar");
                    
                    behaviorContext->Class<PlayFabClientSdk::PlayFabError>("PlayFabClient_PlayFabError")
						->Property("HttpCode", BehaviorValueProperty(&PlayFabClientSdk::PlayFabError::HttpCode))
						->Property("HttpStatus", BehaviorValueProperty(&PlayFabClientSdk::PlayFabError::HttpStatus))
						->Property("ErrorCode", 
							[](PlayFabClientSdk::PlayFabError* p) { return p->ErrorCode; },
							[](PlayFabClientSdk::PlayFabError* p, PlayFabClientSdk::PlayFabErrorCode v) { p->ErrorCode = v; }
						)
						->Property("ErrorName", BehaviorValueProperty(&PlayFabClientSdk::PlayFabError::ErrorName))
						->Property("ErrorMessage", BehaviorValueProperty(&PlayFabClientSdk::PlayFabError::ErrorMessage))
						->Property("ErrorDetails", BehaviorValueProperty(&PlayFabClientSdk::PlayFabError::ErrorDetails))
                        ->Method("__tostring", [](const PlayFabError* error) 
						{ 
							auto errorMessage = AZStd::string::format("PlayFab Error:\n---------------------------\n");
								
							errorMessage.append(AZStd::string::format("HttpCode: %i\nHttpStatus: %s\nError Code: %i\nError: %s\n",
								error->HttpCode,
								error->HttpStatus.c_str(),
								error->ErrorCode,
								error->ErrorName.c_str()
							)); 

							errorMessage.append("Additional details:\n");
							for (auto& details : error->ErrorDetails)
							{
								errorMessage.append(AZStd::string::format("%s: %s", details.first.c_str(), details.second.c_str()));
							}

							errorMessage.append(AZStd::string::format("\n---------------------------\n"));

							return errorMessage;
						})
					;
                }
            }

			void Activate() override { }
			void Deactivate() override { }

		};

}
        
        
