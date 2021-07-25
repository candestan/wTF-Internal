//
//  DirectXHooker.cpp
//  wTF Internal
//
//  Created by Can on 18.07.2021.
//  Copyright © 2021 Lyceion. All rights reserved.
//


#include "Hooker.hpp"
#include "../../../Thirdparty/kiero/kiero.h"

#pragma region Defines
static HWND hWnd;
#pragma endregion

#pragma region WIN_WindowProc_Hook
LRESULT ImGui_ImplWin32_WndProcHandler(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
static LRESULT CALLBACK hkWINWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	ImGui_ImplWin32_WndProcHandler(hwnd, uMsg, wParam, lParam);

	return CallWindowProcA(DirectXHooker::Originals::oWindowProc, hwnd, uMsg, wParam, lParam);
}
#pragma endregion

#pragma region DX9_Present_Hook
static HRESULT STDMETHODCALLTYPE  hkDXPresent(IDirect3DDevice9* pD3dDevice, const RECT* pSourceRect, const RECT* pDestRect, HWND hDestWindowOverride, const RGNDATA* pDirtyRegion) {
	DirectXFunctions::SaveState(pD3dDevice);

	static BOOL InitImGuiImplWin32 = ImGui_ImplWin32_Init(hWnd);
	static BOOL InitImGuiDX9 = ImGui_ImplDX9_Init(pD3dDevice);

	ImGui_ImplDX9_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	MenuRenderer::RenderMenu(); //Calling Menu Renderer.

	ImDrawList* drawList = ImGui::GetBackgroundDrawList();
	Visuals::Snapline(drawList);
	Visuals::NameESP(drawList);

	ImGui::EndFrame();
	ImGui::Render();

	if (pD3dDevice->BeginScene() == D3D_OK) {
		ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
		pD3dDevice->EndScene();
	}

	DirectXFunctions::RestoreState(pD3dDevice);

	return DirectXHooker::Originals::DXPresent(pD3dDevice, pSourceRect, pDestRect, hDestWindowOverride, pDirtyRegion);
}
#pragma endregion

#pragma region DX9_Reset_Hook
static HRESULT STDMETHODCALLTYPE  hkDXReset(IDirect3DDevice9* pD3dDevice, D3DPRESENT_PARAMETERS* D3DPRESENT_PARAMETERS) {
	ImGui_ImplDX9_InvalidateDeviceObjects();
	return DirectXHooker::Originals::DXReset(pD3dDevice, D3DPRESENT_PARAMETERS);
}
#pragma endregion

namespace DirectXHooker {
	static WNDPROC Originals::oWindowProc;

	std::add_pointer_t<HRESULT STDMETHODCALLTYPE(IDirect3DDevice9*, const RECT*, const RECT*, HWND, const RGNDATA*)> Originals::DXPresent;
	std::add_pointer_t<HRESULT STDMETHODCALLTYPE(IDirect3DDevice9*, D3DPRESENT_PARAMETERS*)> Originals::DXReset;

	BOOL Install() {
		bool attached = false;
		do
		{
			if (kiero::init(kiero::RenderType::D3D9) == kiero::Status::Success)
			{
				MenuRenderer::Initialize();

				hWnd = FindWindow(_("Valve001"), NULL);
				if (!hWnd) return FALSE;
				else Originals::oWindowProc = WNDPROC(SetWindowLongPtrW(hWnd, GWLP_WNDPROC, LONG_PTR(hkWINWindowProc)));

				kiero::bind(DirectXTable::Reset, (void**)&Originals::DXReset, hkDXReset);
				kiero::bind(DirectXTable::Present, (void**)&Originals::DXPresent, hkDXPresent);

				attached = true;
			}
		} while (!attached);
		return TRUE;
	}

	VOID Uninstall() {
		Originals::oWindowProc = WNDPROC(SetWindowLongPtrW(hWnd, GWLP_WNDPROC, LONG_PTR(Originals::oWindowProc)));
		free(hWnd);
		kiero::unbind(DirectXTable::Reset);
		kiero::unbind(DirectXTable::Present);
	}
}