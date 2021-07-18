//
//  framework.hpp
//  wTF Internal
//
//  Created by Can on 18.07.2021.
//  Copyright © 2021 Lyceion. All rights reserved.
//


#pragma once

#define WIN32_LEAN_AND_MEAN //Came default by WIN
// Windows Headers
#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <Psapi.h>
#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <limits>
#include <string_view>
#include <utility>


//String Encryption
#include "Thirdparty/xorstr/include/xorstr.hpp"
#define _(str) xorstr_(str)


//DirectX Headers
#include <d3d9types.h>
#include <d3d9.h>


//ImGUI Headers
#define IMGUI_DEFINE_MATH_OPERATORS
#define IMGUI_IMPL_WIN32_DISABLE_GAMEPAD
#include "../../Thirdparty/imgui/imgui.h"
#include "../../Thirdparty/imgui/backends/imgui_impl_dx9.h"
#include "../../Thirdparty/imgui/imgui_internal.h"
#include "../../Thirdparty/imgui/backends/imgui_impl_win32.h"


//DEFINES
#define PROJECT_NAME _("wTF Internal")
#define EXTERN extern //Bc looks cooler imo
#define INLINE inline //Bc looks cooler imo
