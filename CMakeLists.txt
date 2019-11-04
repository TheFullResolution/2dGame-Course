cmake_minimum_required(VERSION 3.7)
project(2dgameengine)

add_definitions(-std=c++14)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")

find_package(SDL2 REQUIRED)
find_package(SDL2_IMAGE REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

add_compile_options(-Wall -Wextra -Wpedantic)


include_directories(lib/glm)
include_directories(lib/lua)

add_executable(2dgameengine main.cpp src/AssetManager.cpp src/Entity.cpp src/EntityManager.cpp src/Game.cpp src/TextureManager.cpp src/Animation.cpp src/Animation.h src/Map.cpp src/Map.h)
target_link_libraries(2dgameengine ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})