cmake_minimum_required(VERSION 3.7)

project(sdl2-windows-native)

find_package(SDL2 CONFIG REQUIRED)
file(GLOB SOURCES "src/*.cpp")
add_executable(sdl2-windows-native ${SOURCES})

target_link_libraries(sdl2-windows-native PRIVATE SDL2::SDL2 SDL2::SDL2main)


