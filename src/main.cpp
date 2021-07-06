#include "game/Game.h"
#include <iostream>

int main() {
    try {
        Game game;
        game.run();
    }
    catch (std::exception &exception) {
        std::cerr << exception.what() << "\n";
    }
    return 0;
}
