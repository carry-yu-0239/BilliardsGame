//
// Created by tb16p666iSwanLily on 2025/12/15.
//
#pragma once    // 防止头文件重复包含

#include <SFML/Graphics.hpp>
#include <vector>

//引入物理世界与游戏对象
#include "physics/PhysicsWorld.h"
#include "objects/Ball.h"
#include "objects/Table.h"

//Game类：整个游戏的总控中心，
//负责窗口、事件、更新、渲染
class Game {
    public:
    Game(); //构造函数负责初始化窗口和场景
    void run(); //游戏主循环

    private:

    //处理输入（键盘/鼠标）
    void processEvents();

    //更新游戏状态
    //（包括物理状态、对象状态）
    void update(float dt);

    //绘制所有内容到窗口
    void render();

    //  ====  成员变量  ====

    //SFML渲染窗口
    sf::RenderWindow window;

    //Box2D物理世界封装
    PhysicsWorld physics;

    //台球桌
    Table table;

    //所有台球（索引为0的球即为母球）
    std::vector<Ball> balls;

    //  ====  输入状态  ====

    //是否正在用鼠标拖拽击球
    bool dragging=false;

    //鼠标按下时的位置
    sf::Vector2f dragStart;
};