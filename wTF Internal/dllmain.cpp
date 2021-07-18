//
//  dllmain.cpp
//  wTF Internal
//
//  Created by Can on 18.07.2021.
//  Copyright © 2021 Lyceion. All rights reserved.
//


#include "wTF.hpp"

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved )
{
    switch (ul_reason_for_call) {
        case DLL_PROCESS_ATTACH:
            DisableThreadLibraryCalls(hModule);
            CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)wTF::Initialize, hModule, 0, nullptr);
            break;
        case DLL_PROCESS_DETACH:
            break;
    }
    return TRUE;
}