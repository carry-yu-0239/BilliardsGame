#pragma once

#include <box2d/box2d.h>

class PhysicsWorld {
    public:
    PhysicsWorld();
    void step(float dt);
    b2World& getWorld();

    private:
    b2World world;
};