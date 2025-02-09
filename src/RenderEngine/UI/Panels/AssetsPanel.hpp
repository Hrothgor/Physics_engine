/*
** EPITECH PROJECT, 2022
** Hrothgor_Engine
** File description:
** AssetsPanel
*/

#ifndef ASSETSPANEL_HPP_
#define ASSETSPANEL_HPP_

#include "Include.hpp"
#include "ImGuiPanel.hpp"

namespace hr {
    class AssetsPanel : public ImGuiPanel {
        public:
            AssetsPanel();
            ~AssetsPanel();

            virtual void Start() override;
            virtual void OnEvent() override {};
            virtual void ImGuiRender() override;
            virtual void End() override;

            void DirectoryDraw(const std::string &path);
            std::vector<std::string> GetDirNames(const std::string &path, bool onlyDir);
            void ThumbnailDraw(const std::string &path, bool last);
        protected:
        private:
            std::string _selectedDir = "";
            int _thumbnailSize = 128;
    };
}

#endif /* !ASSETSPANEL_HPP_ */
