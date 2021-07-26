//
//  GameHooker.cpp
//  wTF Internal
//
//  Created by Can on 18.07.2021.
//  Copyright © 2021 Lyceion. All rights reserved.
//


#include "Hooker.hpp"
#include "../../../Thirdparty/minhook/include/MinHook.h"


VOID GameHooker::Install() {
	while (!GetModuleHandle(_("serverbrowser.dll")))
		Sleep(10);
	ValveSDK::Initialize();
}

VOID GameHooker::Uninstall() {
	ValveSDK::Uninitialize();
}