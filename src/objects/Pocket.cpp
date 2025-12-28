#include "objects/Pocket.h"
#include <cmath>

Pocket::Pocket(sf::Vector2f pos, float r)
    : position(pos), radius(r) {

    // ===== 外圈（洞口）=====
    outerRing.setRadius(radius + 6.f);
    outerRing.setOrigin(
        sf::Vector2f{ outerRing.getRadius(), outerRing.getRadius() }
    );
    outerRing.setPosition(position);
    outerRing.setFillColor(sf::Color(90, 60, 30));

    // ===== 内圈（洞沿）=====
    innerRing.setRadius(radius + 2.f);
    innerRing.setOrigin(
        sf::Vector2f{ innerRing.getRadius(), innerRing.getRadius() }
    );
    innerRing.setPosition(position);
    innerRing.setFillColor(sf::Color(50, 50, 50));

    // ===== 真正的洞 =====
    hole.setRadius(radius);
    hole.setOrigin(
        sf::Vector2f{ radius, radius }
    );
    hole.setPosition(position);
    hole.setFillColor(sf::Color::Black);
}



bool Pocket::contains(sf::Vector2f ballCenter, float ballRadius) const {
    float dx = ballCenter.x - position.x;
    float dy = ballCenter.y - position.y;
    float d = std::sqrt(dx * dx + dy * dy);

    // 核心判定：d <= R - r
    return d <= (radius - ballRadius);
}


void Pocket::draw(sf::RenderWindow& window) const {
    window.draw(outerRing);
    window.draw(innerRing);
    window.draw(hole);
}