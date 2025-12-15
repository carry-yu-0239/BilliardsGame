#pragma once

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include "physics/PhysicsWorld.h"

class Ball {
    public:
    Ball(PhysicsWorld& physics,
        sf::Vector2f position);
    void update();
    void draw(sf::RenderWindow& window);
    void applyImpulse(const sf::Vector2f& impulse);

    private:
    sf::CircleShape shape;
    b2Body* body;
};