#include "physicsobject.h"

PhysicsObject::PhysicsObject(raylib::Vector2 initialPos, std::string texturePath,
                             float initialScale, float initialRot, float friction)
        : GameObject(initialPos, texturePath, initialScale, initialRot), friction_(friction) {}

void PhysicsObject::update() {
    const float dt = 1.0f / 60.0f;

    velocity_ = velocity_ + acceleration_ * dt; // Beschleunigung

    velocity_ = velocity_ - velocity_ * friction_; // Reibung

    pos_ += velocity_; // Position aktualisieren

    acceleration_ = raylib::Vector2(0, 0); //Beschleunigung zurücksetzen

    GameObject::update();
}


void PhysicsObject::accelerate(const raylib::Vector2& acceleration) {
    acceleration_ = acceleration;
}



