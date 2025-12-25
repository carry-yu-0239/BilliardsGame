#pragma once

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include "physics/PhysicsWorld.h"

// Table 类：台球桌（边界）
class Table {
    public:
    // 构造函数：创建四周墙体
    Table(PhysicsWorld& physics);

    // 绘制桌子（目前仅背景）
    void draw(sf::RenderWindow& window);

};