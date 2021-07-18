//
//  Functions.cpp
//  wTF Internal
//
//  Created by Can on 18.07.2021.
//  Copyright © 2021 Lyceion. All rights reserved.
//


#include "Functions.hpp"

#pragma region DirectXFunctions

#pragma region Defines
IDirect3DVertexDeclaration9* DirectXFunctions::vertDec;
IDirect3DVertexShader9* DirectXFunctions::vertShader;
DWORD DirectXFunctions::dwOld_D3DRS_COLORWRITEENABLE;
#pragma endregion


VOID DirectXFunctions::SaveState(IDirect3DDevice9* pD3dDevice) {
	pD3dDevice->GetRenderState(D3DRS_COLORWRITEENABLE, &dwOld_D3DRS_COLORWRITEENABLE);
	pD3dDevice->GetVertexDeclaration(&vertDec);
	pD3dDevice->GetVertexShader(&vertShader);
	pD3dDevice->SetRenderState(D3DRS_COLORWRITEENABLE, 0xffffffff);
	pD3dDevice->SetRenderState(D3DRS_SRGBWRITEENABLE, false);
	pD3dDevice->SetSamplerState(NULL, D3DSAMP_ADDRESSU, D3DTADDRESS_WRAP);
	pD3dDevice->SetSamplerState(NULL, D3DSAMP_ADDRESSV, D3DTADDRESS_WRAP);
	pD3dDevice->SetSamplerState(NULL, D3DSAMP_ADDRESSW, D3DTADDRESS_WRAP);
	pD3dDevice->SetSamplerState(NULL, D3DSAMP_SRGBTEXTURE, NULL);
}

VOID DirectXFunctions::RestoreState(IDirect3DDevice9* pD3dDevice) {
	pD3dDevice->SetRenderState(D3DRS_COLORWRITEENABLE, dwOld_D3DRS_COLORWRITEENABLE);
	pD3dDevice->SetRenderState(D3DRS_SRGBWRITEENABLE, true);
	pD3dDevice->SetVertexDeclaration(vertDec);
	pD3dDevice->SetVertexShader(vertShader);
}

VOID DirectXFunctions::RenderTest(IDirect3DDevice9* pD3dDevice) { //Credits to AIXEE
	D3DCOLOR color = D3DCOLOR_XRGB(255, 0, 0);
	D3DRECT position = { 100, 100, 200, 200 };
	pD3dDevice->Clear(1, &position, D3DCLEAR_TARGET | D3DCLEAR_TARGET, color, 0, 0);
}

#pragma endregion