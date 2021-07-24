#include "Features.hpp"

VOID Visuals::Snapline(ImDrawList* drawArea) {
	if (!Settings::Visuals::Snapline) return;
	for (int i = 0; i <= Interfaces::engineClient->GetMaxClients(); i++) {
		IClientEntity* entity = Interfaces::clientEntityList->GetClientEntity(i);
		if (!entity) return;
		Vector output;
		if (Interfaces::debugOverlay->ScreenPosition(entity->, output))
			drawArea->AddLine(ImVec2(0, 0), ImVec2(output.x, output.y), IM_COL32_WHITE);
	}
}