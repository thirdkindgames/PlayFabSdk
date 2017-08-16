// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

// This file contains the reflection logic for any types which are global to the gem 
// E.g. any types which are ot tied to a specific API such as 'client', 'admin', 'matchmaking' etc.

#pragma once
#include <AzCore/Component/Component.h>
#include <AzCore/RTTI/ReflectContext.h>
#include <AzCore/RTTI/BehaviorContext.h>
#include <PlayFabComboSdk/PlayFabBaseModel.h>

namespace PlayFabComboSdk
{
		// This component provides behavior context reflection for the PlayFab SDK, this allows it to be used by Lua and other Lumberyard systems.
		class PlayFabCombo_BehaviorContextShared : public AZ::Component
		{
		public:
			AZ_COMPONENT(PlayFabCombo_BehaviorContextShared, "{f5ec4192-4f9a-5516-ba69-2a39b00ede9b}");

			static void Reflect(AZ::ReflectContext* context)
            {
                // Reflect only classes and enums which are global to the gem here (e.g. shared between APIs)
                // All other reflection is in PlayFab<Gem>_<Api>BehaviorContext.cpp
                AZ::BehaviorContext* behaviorContext = azrtti_cast<AZ::BehaviorContext*>(context);
                if (behaviorContext)
                {
                    behaviorContext->Class<PlayFabComboSdk::MultitypeVar>("PlayFabCombo_MultitypeVar");
                    
                    behaviorContext->Class<PlayFabComboSdk::PlayFabError>("PlayFabCombo_PlayFabError")
						->Property("HttpCode", BehaviorValueProperty(&PlayFabComboSdk::PlayFabError::HttpCode))
						->Property("HttpStatus", BehaviorValueProperty(&PlayFabComboSdk::PlayFabError::HttpStatus))
						->Property("ErrorCode", 
							[](PlayFabComboSdk::PlayFabError* p) { return p->ErrorCode; },
							[](PlayFabComboSdk::PlayFabError* p, PlayFabComboSdk::PlayFabErrorCode v) { p->ErrorCode = v; }
						)
						->Property("ErrorName", BehaviorValueProperty(&PlayFabComboSdk::PlayFabError::ErrorName))
						->Property("ErrorMessage", BehaviorValueProperty(&PlayFabComboSdk::PlayFabError::ErrorMessage))
						->Property("ErrorDetails", BehaviorValueProperty(&PlayFabComboSdk::PlayFabError::ErrorDetails))
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
        
        
