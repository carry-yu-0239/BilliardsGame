//
// Created by tb16p666iSwanLily on 2025/12/15.
//
#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "physics/PhysicsWorld.h"
#include "objects/Ball.h"
#include "objects/Table.h"

class Game {
    public:
    Game();
    void run();

    private:
    void processEvents();
    void update(float dt);
    void render();

    sf::RenderWindow window;
    PhysicsWorld physics;
    Table table;
    std::vector<Ball> balls;

    //cue input
    bool dragging=false;
    sf::Vector2f dragStart;
};