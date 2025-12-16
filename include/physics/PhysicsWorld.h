#pragma once

#include <box2d/box2d.h>

// PhysicsWorld：对 Box2D 世界的简单封装
// 统一管理 Step 和访问
class PhysicsWorld {
    public:

    PhysicsWorld();

    // 推进物理模拟
    void step(float dt);

    // 获取底层 Box2D 世界（供 Ball / Table 使用）
    b2World& getWorld();

    private:

    // Box2D 世界对象
    b2World world;
};