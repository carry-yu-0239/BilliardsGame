//
// Created by tb16p666iSwanLily on 2025/12/15.
//
#include "objects/Ball.h"

static constexpr float SCALE = 30.f;

Ball::Ball(PhysicsWorld& physics, sf::Vector2f position) {
    shape.setRadius(10.f);
    shape.setOrigin({10.f, 10.f});
    shape.setFillColor(sf::Color::White);

    b2BodyDef def;
    def.type = b2_dynamicBody;
    def.position.Set(position.x / SCALE, position.y / SCALE);
    body = physics.getWorld().CreateBody(&def);

    b2CircleShape circle;
    circle.m_radius = 10.f / SCALE;

    b2FixtureDef fix;
    fix.shape = &circle;
    fix.density = 1.f;
    fix.restitution = 0.9f;
    fix.friction = 0.1f;
    body->CreateFixture(&fix);

    body->SetLinearDamping(0.4f);
}

void Ball::update() {
    b2Vec2 pos = body->GetPosition();
    shape.setPosition({pos.x * SCALE, pos.y * SCALE});
}

void Ball::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

void Ball::applyImpulse(const sf::Vector2f& impulse) {
    body->ApplyLinearImpulseToCenter({impulse.x / SCALE, impulse.y / SCALE}, true);
}