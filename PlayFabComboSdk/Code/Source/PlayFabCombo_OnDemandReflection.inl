// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

// This file contains on demand reflection functions which are used to reflect templated types without needing to enumerate
// all possible versions of the class by hand.

#include "StdAfx.h"

#include <AzCore/RTTI/ReflectContext.h>
#include <AzCore/RTTI/BehaviorContext.h>
#include <AzCore/RTTI/OnDemandReflection.h>

namespace AZ
{
    // Fully reflect Boxed<T> types. This allows Lua to be able to check if a value exists. E.g. in some responses
	// values may not be provided (depending on the request options and backend state) in this case.
	template<typename T>
	struct OnDemandReflection< PlayFabComboSdk::Boxed<T> >
	{
		using ContainerType = PlayFabComboSdk::Boxed<T>;

		static void Reflect(ReflectContext* context)
		{
			BehaviorContext* behaviorContext = azrtti_cast<BehaviorContext*>(context);
			if (behaviorContext)
			{
				behaviorContext->Class<ContainerType>()
					->Constructor()
					->Method("isNull", &ContainerType::isNull)
					->Method("notNull", &ContainerType::notNull)
					->Method("setNull", &ContainerType::setNull)
					->Property("value",
						// Getter
						[](ContainerType* box) { return (T)box->mValue; },
						// Setter
						[](ContainerType* box, T value) { box->mValue = value; }
					)
					;
			}
		}
	};
}