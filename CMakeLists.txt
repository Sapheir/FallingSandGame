cmake_minimum_required(VERSION 3.23)
project(FallingSandGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

include(FetchContent)
set(BUILD_SHARED_LIBS OFF)

# SFML
FetchContent_Declare(
        SFML
        GIT_REPOSITORY "https://github.com/SFML/SFML.git"
        GIT_TAG        "2.5.1"
)
FetchContent_MakeAvailable(SFML)

add_executable(FallingSandGame
        src/main.cpp
        src/elements/Element.cpp src/elements/Element.h
        src/elements/ElementSystem.cpp src/elements/ElementSystem.h
        src/game/Game.cpp src/game/Game.h
        src/game/Selection.cpp src/game/Selection.h
        src/game/Utils.cpp src/game/Utils.h
        src/game/Brush.cpp src/game/Brush.h
        src/elements/Sand.cpp src/elements/Sand.h
        src/elements/Stone.cpp src/elements/Stone.h
        src/elements/Water.cpp src/elements/Water.h
        src/elements/Lava.cpp src/elements/Lava.h
        src/elements/Cobblestone.cpp src/elements/Cobblestone.h)

target_link_libraries(FallingSandGame sfml-audio sfml-graphics sfml-window sfml-system)
