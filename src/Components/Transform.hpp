/*
** EPITECH PROJECT, 2022
** Hrothgor_Engine
** File description:
** Transform
*/

#ifndef TRANSFORM_HPP_
#define TRANSFORM_HPP_

#include "Include.hpp"
#include "Ecs/Component.hpp"
#include "Json.hpp"

namespace hr {
    struct AxisAngle {
        Vector3 axis;
        float angle;
    };

    class Transform : public Component {
        public:
            Transform(GameObject *gameObject);
            ~Transform();

            virtual void Update() override;

            void Translate(Vector3 vec);
            void Rotate(Vector3 vec);
            void Rotate(float x, float y, float z);

            Matrix GetTransformMatrix() const;

            Vector3 GetPosition() const;
            Vector3 GetPositionWorld() const;
            void SetPosition(Vector3 pos);
            void SetPosition(float x, float y, float z);
            void SetPositionFromWorld(float x, float y, float z);

            Vector3 GetRotation() const;
            Vector3 GetRotationRadian() const;
            Quaternion GetRotationQuaternion() const;
            AxisAngle GetRotationAxisAngle() const;
            Matrix GetRotationMatrix() const;
            void SetRotation(Vector3 rotation);
            void SetRotation(float x, float y, float z);

            Vector3 GetScale() const;
            Vector3 GetScaleWorld() const;
            void SetScale(Vector3 scale);
            void SetScale(float x, float y, float z);
            void SetScaleFromWorld(float x, float y, float z);
            
            Vector3 GetFront() const;
            std::vector<Vector3> GetLocalAxis() const;

            static Quaternion EulerToQuaternion(Vector3 euler);

            virtual void ImGuiRender() override;

            virtual nlohmann::json ToJson() const override;
            virtual void FromJson(const nlohmann::json &json) override;

            virtual Component *Clone(GameObject *gameObject) override;
        protected:
        private:
            Vector3 _position;
            Vector3 _rotation;
            Vector3 _scale;
            Vector3 _front;
    };
}

#endif /* !TRANSFORM_HPP_ */
