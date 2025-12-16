#include "objects/Table.h"

static constexpr float SCALE = 30.f;

// 构造函数：创建四面静态墙体
Table::Table(PhysicsWorld& physics) {
    b2World& world = physics.getWorld();

    // Lambda：创建墙体
    auto makeWall = [&](float x, float y, float w, float h) {
        b2BodyDef bodyDef;
        bodyDef.position.Set(x / SCALE, y / SCALE);

        b2Body* body = world.CreateBody(&bodyDef);

        b2PolygonShape shape;
        shape.SetAsBox(w / SCALE, h / SCALE);

        body->CreateFixture(&shape, 0.f);
    };

    // 上下左右四面墙
    makeWall(500, 10, 500, 10);
    makeWall(500, 590, 500, 10);
    makeWall(10, 300, 10, 300);
    makeWall(990, 300, 10, 300);
}

// 桌子绘制（当前背景已在 Game::render 中完成）
void Table::draw(sf::RenderWindow&) {}