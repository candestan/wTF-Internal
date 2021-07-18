//
//  Functions.hpp
//  wTF Internal
//
//  Created by Can on 18.07.2021.
//  Copyright © 2021 Lyceion. All rights reserved.
//


#pragma once
#include "../../framework.hpp"

namespace DirectXFunctions {

#pragma region Defines
	extern IDirect3DVertexDeclaration9* vertDec;
	extern IDirect3DVertexShader9* vertShader;
	extern DWORD dwOld_D3DRS_COLORWRITEENABLE;
#pragma endregion

	VOID SaveState(IDirect3DDevice9* pD3dDevice);
	VOID RestoreState(IDirect3DDevice9* pD3dDevice);

	VOID RenderTest(IDirect3DDevice9* pD3dDevice);
}