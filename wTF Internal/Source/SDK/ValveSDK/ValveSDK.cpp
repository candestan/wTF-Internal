#include "ValveSDK.hpp"

IVDebugOverlay* ValveSDK::Interfaces::debugOverlay;
IVEngineClient* ValveSDK::Interfaces::engineClient;


HMODULE ValveSDK::Modules::clientModule;
CreateInterfaceFn ValveSDK::Modules::CIClient;
HMODULE ValveSDK::Modules::engineModule;
CreateInterfaceFn ValveSDK::Modules::CIEngine;
HMODULE ValveSDK::Modules::vGuiModule;
CreateInterfaceFn ValveSDK::Modules::CIVGui;
HMODULE ValveSDK::Modules::matSurfaceModule;
CreateInterfaceFn ValveSDK::Modules::CIMatSurface;

INLINE BOOL SetupInterfaces() {
	ValveSDK::Modules::CIClient = reinterpret_cast<CreateInterfaceFn>(GetProcAddress(ValveSDK::Modules::clientModule, _(CREATE_INTERFACE_STR)));
	ValveSDK::Modules::CIEngine = reinterpret_cast<CreateInterfaceFn>(GetProcAddress(ValveSDK::Modules::engineModule, _(CREATE_INTERFACE_STR)));
	ValveSDK::Modules::CIVGui = reinterpret_cast<CreateInterfaceFn>(GetProcAddress(ValveSDK::Modules::vGuiModule, _(CREATE_INTERFACE_STR)));
	ValveSDK::Modules::CIMatSurface = reinterpret_cast<CreateInterfaceFn>(GetProcAddress(ValveSDK::Modules::matSurfaceModule, _(CREATE_INTERFACE_STR)));

	ValveSDK::Interfaces::debugOverlay = reinterpret_cast<IVDebugOverlay*>(ValveSDK::Modules::CIEngine(_(VDEBUG_OVERLAY_INTERFACE_VERSION), NULL));
	ValveSDK::Interfaces::engineClient = reinterpret_cast<IVEngineClient*>(ValveSDK::Modules::CIEngine(_(VENGINE_CLIENT_INTERFACE_VERSION), NULL));
	return TRUE;
}

INLINE BOOL ValveSDK::Initialize() {
	Modules::clientModule = GetModuleHandle(_("client.dll"));
	Modules::engineModule = GetModuleHandle(_("engine.dll"));
	Modules::vGuiModule = GetModuleHandle(_("vgui2.dll"));
	Modules::matSurfaceModule = GetModuleHandle(_("vguimatsurface.dll"));

	SetupInterfaces();
	return TRUE;
}
