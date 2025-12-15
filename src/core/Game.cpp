//
// Created by tb16p666iSwanLily on 2025/12/15.
//
#include "core/Game.h"

Game::Game()
: window(sf::VideoMode({1000, 600}), "Billiards Game")
, physics()
, table(physics)
{
    window.setFramerateLimit(60);

    // cue ball
    balls.emplace_back(physics, sf::Vector2f(300.f, 300.f));

    // target balls
    balls.emplace_back(physics, sf::Vector2f(600.f, 280.f));
    balls.emplace_back(physics, sf::Vector2f(620.f, 300.f));
    balls.emplace_back(physics, sf::Vector2f(600.f, 320.f));
}

void Game::run() {
    sf::Clock clock;
    while (window.isOpen()) {
        float dt = clock.restart().asSeconds();
        processEvents();
        update(dt);
        render();
    }
}

void Game::processEvents() {
    while (auto event = window.pollEvent()) {
        if (event->is<sf::Event::Closed>())
            window.close();

        if (auto* mouse = event->getIf<sf::Event::MouseButtonPressed>()) {
            if (mouse->button == sf::Mouse::Button::Left) {
                dragging = true;
                dragStart = window.mapPixelToCoords({mouse->position.x, mouse->position.y});
            }
        }

        if (auto* mouse = event->getIf<sf::Event::MouseButtonReleased>()) {
            if (mouse->button == sf::Mouse::Button::Left && dragging) {
                dragging = false;
                sf::Vector2f dragEnd = window.mapPixelToCoords({mouse->position.x, mouse->position.y});
                sf::Vector2f impulse = dragStart - dragEnd;
                balls[0].applyImpulse(impulse * 0.05f);
            }
        }
    }
}

void Game::update(float dt) {
    physics.step(dt);
    for (auto& b : balls) b.update();
}

void Game::render() {
    window.clear(sf::Color(30, 120, 30));
    table.draw(window);
    for (auto& b : balls) b.draw(window);
    window.display();
}