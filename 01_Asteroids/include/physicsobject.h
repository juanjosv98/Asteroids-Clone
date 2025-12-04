#pragma once

#include "gameobject.h"
#include <raylib-cpp.hpp>

class PhysicsObject : public GameObject {
private:
    raylib::Vector2 velocity_;
    raylib::Vector2 acceleration_;
    const float friction_;

public:
    PhysicsObject(raylib::Vector2 initialPos, std::string texturePath,
                  float initialScale, float initialRot, float friction);

    void accelerate(const raylib::Vector2& acceleration);
    void update() override;

};