//
//  ValveSDK.hpp
//  wTF Internal
//
//  Created by Can on 18.07.2021.
//  Copyright © 2021 Lyceion. All rights reserved.
//


#pragma once

#include "../../../framework.hpp"

//Interfaces
#include "interfaces/IAppSystem.h"
#include "interfaces/IClientEntityList.h"
#include "interfaces/IVDebugOverlay.h"
#include "interfaces/IVEngineClient.h"
#include "interfaces/IInputSystem.h"

//Classes
	//math
	#include "classes/math/math.h"
#include "classes/IClientEntity.h"
	

namespace ValveSDK {
	namespace Interfaces {
		EXTERN IClientEntityList* clientEntityList;
		EXTERN IVDebugOverlay* debugOverlay;
		EXTERN IVEngineClient* engineClient;
		EXTERN IInputSystem* inputSystem;
	};

	namespace Modules {
		EXTERN HMODULE clientModule;
		EXTERN HMODULE engineModule;
		EXTERN HMODULE vGuiModule;
		EXTERN HMODULE matSurfaceModule;
		EXTERN HMODULE inputSystemModule;
	};

	VOID Initialize();
	VOID Uninitialize();
}