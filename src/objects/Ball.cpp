#include "objects/Ball.h"

// 像素到米的缩放比例（Box2D 使用米）
static constexpr float SCALE = 30.f;

// 构造函数
// ===== 原构造函数：默认白球 =====
Ball::Ball(PhysicsWorld& physics, sf::Vector2f position)
    : Ball(physics, position, sf::Color::White) {
}

// ===== 新构造函数：可指定颜色 =====
Ball::Ball(PhysicsWorld& physics,
           sf::Vector2f position,
           sf::Color color) {

    // ---------- 图形部分 ----------
    shape.setRadius(10.f);
    shape.setOrigin({10.f, 10.f});
    shape.setFillColor(color);

    // ---------- 物理部分 ----------
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(position.x / SCALE, position.y / SCALE);

    body = physics.getWorld().CreateBody(&bodyDef);

    b2CircleShape circle;
    circle.m_radius = 10.f / SCALE;

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &circle;
    fixtureDef.density = 1.f;
    fixtureDef.restitution = 0.9f;
    fixtureDef.friction = 0.1f;

    body->CreateFixture(&fixtureDef);

    body->SetLinearDamping(0.01f);
}

// 更新图形位置
void Ball::update() {
    b2Vec2 pos = body->GetPosition();
    shape.setPosition({pos.x * SCALE, pos.y * SCALE});
}

// 绘制
void Ball::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

//  获取球的半径
float Ball::getRadius() const {
    return shape.getRadius();
}

sf::Vector2f Ball::getPosition() const {
    b2Vec2 pos = body->GetPosition();

    return {pos.x * SCALE, pos.y * SCALE};
}

//  reset球
void Ball::reset(sf::Vector2f position) {
    body->SetTransform(
        b2Vec2(position.x / SCALE, position.y / SCALE),
        0.f
    );
    body->SetLinearVelocity(b2Vec2_zero);
    body->SetAngularVelocity(0.f);
}


// 施加冲量（击球）
void Ball::applyImpulse(const sf::Vector2f& impulse) {
    body->ApplyLinearImpulseToCenter(
        {impulse.x / SCALE, impulse.y / SCALE},
        true
    );
}