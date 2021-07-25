//
//  Visuals.cpp
//  wTF Internal
//
//  Created by Can on 25.07.2021.
//  Copyright © 2021 Lyceion. All rights reserved.
//


#include "Features.hpp"

//credits to: @danielkrupinski/Osiris -> "https://github.com/danielkrupinski/Osiris/blob/master/Osiris/Hacks/Visuals.cpp#L643"
static bool worldToScreen(const Vector& in, ImVec2& out)
{
    const auto& matrix = Interfaces::engineClient->WorldToScreenMatrix();
    const auto w = matrix[3][0] * in.x + matrix[3][1] * in.y + matrix[3][2] * in.z + matrix[3][3];
    if (w < 0.001f) return false;
    out = ImGui::GetIO().DisplaySize / 2.0f;
    out.x *= 1.0f + (matrix[0][0] * in.x + matrix[0][1] * in.y + matrix[0][2] * in.z + matrix[0][3]) / w;
    out.y *= 1.0f - (matrix[1][0] * in.x + matrix[1][1] * in.y + matrix[1][2] * in.z + matrix[1][3]) / w;
    return true;
}

VOID Visuals::Snapline(ImDrawList* drawArea) {
	if (!Settings::Visuals::Snapline) return;
	for (int i = 1; i <= Interfaces::clientEntityList->GetHighestEntityIndex(); i++) {
		IClientEntity* entity = Interfaces::clientEntityList->GetClientEntity(i);
		if (!entity) return;
		ImVec2 output;
		if (worldToScreen(entity->GetAbsOrigin(), output))
            drawArea->AddLine(ImVec2(0, 0), output, IM_COL32_WHITE);
	}
}

VOID Visuals::NameESP(ImDrawList* drawArea) {
    if (!Settings::Visuals::NameESP) return;
    for (int i = 1; i <= Interfaces::clientEntityList->GetHighestEntityIndex(); i++) {
        IClientEntity* entity = Interfaces::clientEntityList->GetClientEntity(i);
        if (!entity) return;
        ImVec2 screen;
        player_info_t info;
        if (!Interfaces::engineClient->GetPlayerInfo(i, &info)) return;
        if (worldToScreen(entity->GetAbsOrigin(), screen))
            drawArea->AddText(screen, IM_COL32_WHITE, info.name);
    }
}