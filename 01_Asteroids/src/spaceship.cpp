#include "spaceship.h"

Spaceship::Spaceship(raylib::Vector2 initialPos)
: PhysicsObject(initialPos, texturePath_, 1.0, 0.0, 0.07f)
, health_(maxHealth_)
{
}

void Spaceship::update()
{
    if(IsKeyDown(KEY_W))
    {
        float thrust = 60.0f;
        accelerate(raylib::Vector2{0.f, -thrust}.Rotate(DEG2RAD * rot_));
    }
    if(IsKeyDown(KEY_A))
    {
        rotate(-rotationSpeed_);
    }
    if(IsKeyDown(KEY_D))
    {
        rotate(rotationSpeed_);
    }

    PhysicsObject::update();
}

int Spaceship::getHealth() const
{
    return health_;
}

void Spaceship::handleCollision(std::shared_ptr<GameObject> other) {
    std::shared_ptr<Asteroid> asteroid = std::dynamic_pointer_cast<Asteroid>(other);
    if (asteroid != nullptr) {
        health_--;
    }
}
