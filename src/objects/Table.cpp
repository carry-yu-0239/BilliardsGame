//
// Created by tb16p666iSwanLily on 2025/12/15.
//
#include "objects/Table.h"

static constexpr float SCALE = 30.f;

Table::Table(PhysicsWorld& physics) {
    b2World& world = physics.getWorld();

    auto makeWall = [&](float x, float y, float w, float h) {
        b2BodyDef def;
        def.position.Set(x / SCALE, y / SCALE);
        b2Body* body = world.CreateBody(&def);

        b2PolygonShape shape;
        shape.SetAsBox(w / SCALE, h / SCALE);
        body->CreateFixture(&shape, 0.f);
    };

    makeWall(500, 10, 500, 10);
    makeWall(500, 590, 500, 10);
    makeWall(10, 300, 10, 300);
    makeWall(990, 300, 10, 300);

    for (auto& b : borders) {
        b.setFillColor(sf::Color(100, 60, 20));
    }
}

void Table::draw(sf::RenderWindow&) {}