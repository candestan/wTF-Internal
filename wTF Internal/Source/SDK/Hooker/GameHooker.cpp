//
//  GameHooker.cpp
//  wTF Internal
//
//  Created by Can on 18.07.2021.
//  Copyright © 2021 Lyceion. All rights reserved.
//


#include "Hooker.hpp"

VOID GameHooker::Install() {
	ValveSDK::Initialize();
}

VOID GameHooker::Uninstall() {
	ValveSDK::Uninitialize();
}