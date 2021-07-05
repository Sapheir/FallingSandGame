cmake_minimum_required(VERSION 3.10)
project(FallingSandGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc")
set(SFML_STATIC_LIBRARIES TRUE)


## Set the path to your SFML directory here
set(SFML_DIR "D:\\SFML-2.5.1\\lib\\cmake\\SFML")

find_package(SFML 2.5.1 COMPONENTS audio graphics window system REQUIRED)

add_executable(FallingSandGame
        src/main.cpp)

target_link_libraries(FallingSandGame sfml-audio sfml-graphics sfml-window sfml-system)