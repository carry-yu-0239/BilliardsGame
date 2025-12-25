#include "objects/Ball.h"

// 像素到米的缩放比例（Box2D 使用米）
static constexpr float SCALE = 30.f;

// 构造函数
Ball::Ball(PhysicsWorld& physics, sf::Vector2f position) {
    // ---------- 图形部分 ----------
    shape.setRadius(10.f);
    shape.setOrigin({10.f, 10.f});
    shape.setFillColor(sf::Color::White);

    // ---------- 物理部分 ----------
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;              // 动态刚体
    bodyDef.position.Set(position.x / SCALE, position.y / SCALE);

    // 在世界中创建刚体
    body = physics.getWorld().CreateBody(&bodyDef);

    // 创建圆形碰撞体
    b2CircleShape circle;
    circle.m_radius = 10.f / SCALE;

    // 夹具定义
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &circle;
    fixtureDef.density = 1.f;       // 密度
    fixtureDef.restitution = 0.9f;  // 弹性系数
    fixtureDef.friction = 0.1f;     // 摩擦系数

    body->CreateFixture(&fixtureDef);

    // 线性阻尼：模拟台面摩擦
    body->SetLinearDamping(0.08f);
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

sf::Vector2f Ball::getPosition() const {
    b2Vec2 pos = body->GetPosition();

    return {pos.x * SCALE, pos.y * SCALE};
}

// 施加冲量（击球）
void Ball::applyImpulse(const sf::Vector2f& impulse) {
    body->ApplyLinearImpulseToCenter(
        {impulse.x / SCALE, impulse.y / SCALE},
        true
    );
}