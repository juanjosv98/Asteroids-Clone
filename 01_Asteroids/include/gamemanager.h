#pragma once

#include <list>
#include <memory>

#include "gameobject.h"
#include "spaceship.h"
#include "asteroid.h"
#include "projectile.h"

class GameManager
{
    using GameObjectContainer = std::list<std::shared_ptr<GameObject>>;

private:
    int score_;

    GameObjectContainer objects_;
    std::shared_ptr<Spaceship> player_;

    raylib::Vector2 generateRandomPos();

    void launchProjectile();

public:
    GameManager();

    void spawnAsteroid();

    void spawnSpaceship();

    void update();

    void drawObjects() const;

    void drawHud() const;

    void checkCollisions();

    bool isColliding(const std::shared_ptr<GameObject>& obj1, const std::shared_ptr<GameObject>& obj2);

};