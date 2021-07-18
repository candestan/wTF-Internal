//
//  Menu.hpp
//  wTF Internal
//
//  Created by Can on 18.07.2021.
//  Copyright © 2021 Lyceion. All rights reserved.
//


#pragma once
#include "../../Settings.hpp"

namespace MenuRenderer {
	EXTERN BOOL _VISIBLE;
	VOID RenderMenu();
	BOOL Initialize();
	BOOL DeInitialize();
}