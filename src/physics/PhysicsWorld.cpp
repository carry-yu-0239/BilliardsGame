//
// Created by tb16p666iSwanLily on 2025/12/15.
//
#include "physics/PhysicsWorld.h"

PhysicsWorld::PhysicsWorld()
: world(b2Vec2(0.f, 0.f)) {}

void PhysicsWorld::step(float dt) {
    world.Step(dt, 6, 2);
}

b2World& PhysicsWorld::getWorld() {
    return world;
}