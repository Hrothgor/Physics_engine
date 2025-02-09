/*
** EPITECH PROJECT, 2022
** Hrothgor_Engine
** File description:
** ShadowMapPanel
*/

#include "ShadowMapPanel.hpp"
#include "RenderEngine/ShadowMapping/ShadowMapMasterRenderer.hpp"

namespace hr {
    ShadowMapPanel::ShadowMapPanel()
    {
    }

    ShadowMapPanel::~ShadowMapPanel()
    {
    }

    void ShadowMapPanel::ImGuiRender()
    {
        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2 {0, 0});
        ImGui::Begin("Shadow Map view", &_isOpen, ImGuiWindowFlags_NoScrollbar);

        ImVec2 size = ImGui::GetContentRegionAvail();
        ImGui::Image((ImTextureID)ShadowMapMasterRenderer::Get()->FrameBuffer.GetShadowMap(), size, ImVec2 {0, 1}, ImVec2 {1, 0});

        ImGui::End();
        ImGui::PopStyleVar();
    }
}

