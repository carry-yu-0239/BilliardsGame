//
// Created by tb16p666iSwanLily on 2025/12/15.
//
#include "physics/PhysicsWorld.h"

// 构造函数：创建无重力世界（台球在水平桌面）
PhysicsWorld::PhysicsWorld()
    : world(b2Vec2(0.f, 0.f)) {}

// 每一帧推进物理
void PhysicsWorld::step(float dt) {
    // velocityIterations 和 positionIterations
    world.Step(dt, 8, 3);
}

// 返回世界引用
b2World& PhysicsWorld::getWorld() {
    return world;
}