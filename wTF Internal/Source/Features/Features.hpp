//
//  Features.hpp
//  wTF Internal
//
//  Created by Can on 25.07.2021.
//  Copyright © 2021 Lyceion. All rights reserved.
//


#pragma once

#include "../Settings.hpp"
#include "../SDK/ValveSDK/ValveSDK.hpp"
using namespace ValveSDK;

namespace Visuals {
	VOID Snapline(ImDrawList* drawArea);
	VOID NameESP(ImDrawList* drawArea);
}