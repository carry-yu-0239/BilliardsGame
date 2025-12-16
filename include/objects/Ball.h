#pragma once

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include "physics/PhysicsWorld.h"

// Ball 类：台球（图形 + 物理）
class Ball {
    public:

    // 构造函数：在指定位置创建球
    Ball(PhysicsWorld& physics, sf::Vector2f position);

    // 从物理世界同步位置
    void update();

    // 绘制球
    void draw(sf::RenderWindow& window);

    // 对球施加冲量（击球）
    void applyImpulse(const sf::Vector2f& impulse);

    private:

    // SFML 圆形，用于渲染
    sf::CircleShape shape;

    // Box2D 刚体指针
    b2Body* body;
};