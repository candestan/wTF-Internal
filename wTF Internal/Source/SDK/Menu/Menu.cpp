//
//  Menu.cpp
//  wTF Internal
//
//  Created by Can on 18.07.2021.
//  Copyright © 2021 Lyceion. All rights reserved.
//


#include "Menu.hpp"
bool Settings::Visuals::Snapline = false;
bool Settings::Visuals::NameESP = false;
VOID Menu() {
    ImGui::SetNextWindowSize(ImVec2(500, 300));
    ImGui::SetNextWindowBgAlpha(1.0f);
    ImGui::Begin(PROJECT_NAME, NULL, ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse); {
        ImGui::Text(_("This is means we sucsessfully hooked!"));
        static bool test = true;
        ImGui::Checkbox(_("TEST"), &test);
        if (test) ImGui::Text(_("Test is passed!!"));
        ImGui::Checkbox(_("Snaplines"), &Settings::Visuals::Snapline);
        ImGui::Checkbox(_("Name ESP"), &Settings::Visuals::NameESP);
    }
    ImGui::End();
}

BOOL CreateFontAtlas() {
    return TRUE;
}

BOOL MenuRenderer::_VISIBLE = false;
VOID MenuRenderer::RenderMenu() {
    // Start the handling Open&Close input
    if (ImGui::GetIO().KeysDownDuration[VK_INSERT] == 0.0f)  MenuRenderer::_VISIBLE = !MenuRenderer::_VISIBLE;
    // Render the Menu as an Intellectual
    if (_VISIBLE) Menu();
}

BOOL MenuRenderer::Initialize() {
    // Setup Dear ImGui context
    if (!IMGUI_CHECKVERSION()) return FALSE;

    ImGui::CreateContext();

    ImGuiIO& io = ImGui::GetIO(); (void)io;
    if (!&io) return FALSE;

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    return TRUE;
}

BOOL MenuRenderer::DeInitialize() {
    ImGui_ImplDX9_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();
    return TRUE;
}
