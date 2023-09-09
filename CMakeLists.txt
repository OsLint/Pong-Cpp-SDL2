cmake_minimum_required(VERSION 3.25)
project(PongSDL2)

set(CMAKE_CXX_STANDARD 20)

find_package(SDL2 REQUIRED COMPONENTS SDL2)
find_package(SDL2_ttf REQUIRED COMPONENTS SDL2)



add_executable(PongSDL2 main.cpp Player.h Player.cpp Game.cpp Game.h Ball.cpp Ball.h)



target_link_libraries(PongSDL2 PRIVATE SDL2::SDL2)
target_link_libraries(PongSDL2 PRIVATE SDL2_ttf::SDL2_ttf)


