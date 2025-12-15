#pragma once

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include "physics/PhysicsWorld.h"

class Table {
    public:
    Table(PhysicsWorld& physics);
    void draw(sf::RenderWindow& window);

    private:
    sf::RectangleShape borders[4];
};