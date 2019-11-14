cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 14)

project(2dGameEngine)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(Lua REQUIRED)
include_directories(
        ${SDL2_INCLUDE_DIR}
        ${SDL2_IMAGE_INCLUDE_DIR}
        ${SDL2_TTF_INCLUDE_DIR}
        ${LUA_INCLUDE_DIR}
)

add_compile_options(-Wall -Wextra -Wpedantic)

add_executable(2dGameEngine main.cpp src/AssetManager.cpp src/Game.h src/Constants.h src/Entity.cpp src/EntityManager.cpp src/Game.cpp src/TextureManager.cpp src/Animation.cpp src/Animation.h src/Map.cpp src/Map.h src/Collision.cpp src/Collision.h src/Components/ColliderComponent.h src/FontManager.cpp src/FontManager.h src/Components/TextLabelComponent.h src/Components/ProjectileEmitterComponent.h)
target_link_libraries(
        2dGameEngine
        ${SDL2_LIBRARY}
        ${SDL2_IMAGE_LIBRARIES}
        ${SDL2_TTF_LIBRARIES}
        ${LUA_INCLUDE_DIR}
)