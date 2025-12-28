#pragma once

#include <SFML/Graphics.hpp>

class Pocket {
public:
    Pocket(sf::Vector2f position, float radius);

    // 判断某个点（球中心）是否进洞
    bool contains(sf::Vector2f ballCenter, float ballRadius) const;


    // 可视化（可选，用于调试）
    void draw(sf::RenderWindow& window) const;

private:
    sf::Vector2f position;
    float radius;

    sf::CircleShape outerRing;
    sf::CircleShape innerRing;
    sf::CircleShape hole;

};