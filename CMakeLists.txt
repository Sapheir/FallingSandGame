cmake_minimum_required(VERSION 3.10)
project(FallingSandGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc")
set(SFML_STATIC_LIBRARIES TRUE)


## Set the path to your SFML directory here
set(SFML_DIR "D:\\SFML-2.5.1\\lib\\cmake\\SFML")

find_package(SFML 2.5.1 COMPONENTS audio graphics window system REQUIRED)

add_executable(FallingSandGame
        src/main.cpp
        src/elements/Element.cpp src/elements/Element.h
        src/elements/ElementSystem.cpp src/elements/ElementSystem.h
        src/game/Game.cpp src/game/Game.h
        src/game/Selection.cpp src/game/Selection.h
        src/game/Utils.cpp src/game/Utils.h
        src/game/Brush.cpp src/game/Brush.h
)

target_link_libraries(FallingSandGame sfml-audio sfml-graphics sfml-window sfml-system)
