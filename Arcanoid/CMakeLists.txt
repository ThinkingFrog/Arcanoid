cmake_minimum_required(VERSION 3.15)
project(Arcanoid)

include_directories(include)
file(GLOB SRC src/*.cpp)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR ../SFML-2.5.1/lib/cmake/SFML)

find_package(SFML 2.5.1 COMPONENTS graphics REQUIRED)

add_executable(Arcanoid ${SRC})

target_link_libraries(Arcanoid sfml-graphics)