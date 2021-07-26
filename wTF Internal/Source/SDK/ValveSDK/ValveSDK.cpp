//
//  ValveSDK.cpp
//  wTF Internal
//
//  Created by Can on 18.07.2021.
//  Copyright © 2021 Lyceion. All rights reserved.
//


#include "ValveSDK.hpp"

namespace ValveSDK {

	IClientEntityList* Interfaces::clientEntityList;
	IVDebugOverlay* Interfaces::debugOverlay;
	IVEngineClient* Interfaces::engineClient;
	IInputSystem* Interfaces::inputSystem;


	HMODULE Modules::clientModule;
	HMODULE Modules::engineModule;
	HMODULE Modules::vGuiModule;
	HMODULE Modules::matSurfaceModule;
	HMODULE Modules::inputSystemModule;

	VOID Initialize() {
		Modules::clientModule = GetModuleHandle(_("client.dll"));
		Modules::engineModule = GetModuleHandle(_("engine.dll"));
		Modules::vGuiModule = GetModuleHandle(_("vgui2.dll"));
		Modules::matSurfaceModule = GetModuleHandle(_("vguimatsurface.dll"));
		Modules::inputSystemModule = GetModuleHandle(_("inputsystem.dll"));

		CreateInterfaceFn CIClient = reinterpret_cast<CreateInterfaceFn>(GetProcAddress(Modules::clientModule, _(CREATE_INTERFACE_STR)));
		CreateInterfaceFn CIEngine = reinterpret_cast<CreateInterfaceFn>(GetProcAddress(Modules::engineModule, _(CREATE_INTERFACE_STR)));
		CreateInterfaceFn CIVGui = reinterpret_cast<CreateInterfaceFn>(GetProcAddress(Modules::vGuiModule, _(CREATE_INTERFACE_STR)));
		CreateInterfaceFn CIMatSurface = reinterpret_cast<CreateInterfaceFn>(GetProcAddress(Modules::matSurfaceModule, _(CREATE_INTERFACE_STR)));
		CreateInterfaceFn CIInputSystem = reinterpret_cast<CreateInterfaceFn>(GetProcAddress(Modules::inputSystemModule, _(CREATE_INTERFACE_STR)));

		Interfaces::clientEntityList = reinterpret_cast<IClientEntityList*>(CIClient(_(VCLIENTENTITYLIST_INTERFACE_VERSION), NULL)); //"VClientEntityList003"
		Interfaces::debugOverlay = reinterpret_cast<IVDebugOverlay*>(CIEngine(_(VDEBUG_OVERLAY_INTERFACE_VERSION), NULL)); //"VDebugOverlay003"
		Interfaces::engineClient = reinterpret_cast<IVEngineClient*>(CIEngine(_(VENGINE_CLIENT_INTERFACE_VERSION), NULL)); //"VEngineClient013"
		Interfaces::inputSystem = reinterpret_cast<IInputSystem*>(CIInputSystem(_(INPUTSYSTEM_INTERFACE_VERSION), NULL)); //"InputSystemVersion001"
	}

	VOID Uninitialize() {
		free(Interfaces::clientEntityList);
		free(Interfaces::debugOverlay);
		free(Interfaces::engineClient);
		free(Interfaces::inputSystem);
		free(Modules::clientModule);
		free(Modules::engineModule);
		free(Modules::matSurfaceModule);
		free(Modules::vGuiModule);
		free(Modules::inputSystemModule);
	}
}
