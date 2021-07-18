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
#include "interfaces/IVDebugOverlay.h"
#include "interfaces/IVEngineClient.h"

//Classes
	//math
	#include "classes/math/QAngle.h"
	#include "classes/math/Vector.h"
	

namespace ValveSDK {
	namespace Interfaces {
		EXTERN IVDebugOverlay* debugOverlay;
		EXTERN IVEngineClient* engineClient;
	};

	namespace Modules {
		EXTERN HMODULE clientModule;
		EXTERN CreateInterfaceFn CIClient;
		EXTERN HMODULE engineModule;
		EXTERN CreateInterfaceFn CIEngine;
		EXTERN HMODULE vGuiModule;
		EXTERN CreateInterfaceFn CIVGui;
		EXTERN HMODULE matSurfaceModule;
		EXTERN CreateInterfaceFn CIMatSurface;
	};

	EXTERN BOOL Initialize();
}