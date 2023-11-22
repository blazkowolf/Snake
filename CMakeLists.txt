cmake_minimum_required(VERSION 3.22)

project(
  Snake
  VERSION 0.0.1
  LANGUAGES CXX
  DESCRIPTION "Snake clone using SDL2"
  HOMEPAGE_URL "https://github.com/blazkowolf/Snake")

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

# Yoinked from https://wiki.libsdl.org/SDL2/README/cmake
find_package(SDL2 REQUIRED CONFIG REQUIRED COMPONENTS SDL2)
find_package(SDL2 REQUIRED CONFIG COMPONENTS SDL2main)
find_package(SDL2_image REQUIRED)

add_executable(
  snake
  ${CMAKE_CURRENT_SOURCE_DIR}/Snake/Display/Window.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Snake/Event/Event.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Snake/Game/Driver.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Snake/Game/Map.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Snake/Game/Player.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Snake/Game/Tile.cpp)

target_include_directories(snake PRIVATE ${SDL2_IMAGE_INCLUDE_DIRS})

if(TARGET SDL2::SDL2main)
  target_link_libraries(snake PRIVATE SDL2::SDL2main)
endif()

target_link_libraries(snake PRIVATE SDL2::SDL2-static ${SDL2_IMAGE_LIBRARIES})
