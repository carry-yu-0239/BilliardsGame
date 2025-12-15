cmake_minimum_required(VERSION 3.20)
project(BilliardsGame LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ===== SFML 3.0 =====
set(SFML_DIR "C:/SFML-3.0.2-windows-vc17-64-bit/SFML-3.0.2/lib/cmake/SFML")

find_package(SFML CONFIG REQUIRED COMPONENTS System Window Graphics)

# ===== Box2D =====
add_subdirectory(third_party/box2d)

# ===== Executable =====
add_executable(BilliardsGame
        main.cpp
        include/core/Game.h
        include/physics/PhysicsWorld.h
        include/objects/Ball.h
        include/objects/Table.h
        src/core/Game.cpp
        src/physics/PhysicsWorld.cpp
        src/objects/Ball.cpp
        src/objects/Table.cpp
)

target_include_directories(BilliardsGame
PRIVATE
    include
)

# ===== Link libraries =====
target_link_libraries(BilliardsGame
        PRIVATE
        SFML::System
        SFML::Window
        SFML::Graphics
        box2d
)