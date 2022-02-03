/*
** EPITECH PROJECT, 2022
** Physics_engine
** File description:
** Master3DRenderer
*/

#ifndef MASTER3DRENDERER_HPP_
#define MASTER3DRENDERER_HPP_

#include "../include.hpp"
#include "EntityRenderer.hpp"
#include "GizmosRenderer.hpp"

namespace hr {
    class MainCamera3D;
    class GameObject;

    class Master3DRenderer {
        public:
            Master3DRenderer();
            ~Master3DRenderer();

            void Start();
            void Draw();
            void End();

            void RegisterGizmos(GameObject *model);
            void RegisterObject(GameObject *model);
            void RegisterLight(GameObject *light);
            // void Register(Particle *particles);

        protected:
        private:
            MainCamera3D *_camera;
            EntityRenderer _entityRenderer;
            GizmosRenderer _gizmosRenderer;

        protected:
            static Master3DRenderer *instance;
        public:
            Master3DRenderer(Master3DRenderer &other) = delete;
            void operator=(const Master3DRenderer &) = delete;
            static Master3DRenderer *Get() {
                if (instance == nullptr)
                    instance = new Master3DRenderer();
                return instance;
            };
    };
}


#endif /* !MASTER3DRENDERER_HPP_ */
