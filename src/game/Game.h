#pragma once
#include "../elements/ElementSystem.h"

class Game {
private:
    sf::RenderWindow window{sf::VideoMode(1024, 768), "Falling Sand"};
    ElementSystem elementSystem;
public:
    void run();
};
