#include "core/Game.h"

Game::Game()
    //  初始化窗口（1000*600、标题）
    : window(sf::VideoMode({1000, 600}), "Billiards Game")
    //  创建物理世界（假定重力为0）
    , physics()
    //  创建桌子
    , table(physics)
{
    //  设置帧率上限为60Hz，避免CPU占用
    window.setFramerateLimit(60);

    //  创建母球
    balls.emplace_back(physics, sf::Vector2f(300.f, 300.f));

    //  创建目标球（简单三角形排列）
    balls.emplace_back(physics, sf::Vector2f(600.f, 280.f));
    balls.emplace_back(physics, sf::Vector2f(620.f, 300.f));
    balls.emplace_back(physics, sf::Vector2f(600.f, 320.f));
}

//  ======== 游戏主循环 ========

void Game::run() {
    sf::Clock clock;    //计算帧间隔时间
    while (window.isOpen()) {

        //计算delta time(s)
        float dt = clock.restart().asSeconds();

        //处理输入
        processEvents();

        //更新物理、对象
        update(dt);

        //渲染画面
        render();
    }
}

//  ======== 处理窗口和鼠标事件 ========

void Game::processEvents() {
    while (auto event = window.pollEvent()) {

        //  关闭窗口事件
        if (event->is<sf::Event::Closed>())
            window.close();

        //  按下鼠标，开始拖拽
        if (auto* mouse = event->getIf<sf::Event::MouseButtonPressed>()) {
            if (mouse->button == sf::Mouse::Button::Left) {
                dragging = true;
                dragStart = window.mapPixelToCoords({mouse->position.x, mouse->position.y});
            }
        }

        //  释放鼠标：施加冲量（模拟球杆击球）
        if (auto* mouse = event->getIf<sf::Event::MouseButtonReleased>()) {
            if (mouse->button == sf::Mouse::Button::Left && dragging) {

                dragging = false;
                sf::Vector2f dragEnd = window.mapPixelToCoords({mouse->position.x, mouse->position.y});

                //  方向=起点-终点（反向）
                sf::Vector2f impulse = dragStart - dragEnd;

                //对母球施加冲量
                balls[0].applyImpulse(impulse * 0.05f);
            }
        }
    }
}

//  ========  更新游戏状态  ========
void Game::update(float dt) {
    //  推进Box2D物理模拟
    physics.step(dt);
    //  同步每个球的物理状态到图形
    for (auto& b : balls) b.update();
}

//  ========  渲染函数  ========
void Game::render() {

    //  清屏（绿色桌布）
    window.clear(sf::Color(30, 120, 30));

    //  绘制桌子
    table.draw(window);

    //  绘制所有球
    for (auto& b : balls) b.draw(window);

    //显示到屏幕
    window.display();
}