#pragma once
#include "../elements/ElementSystem.h"
#include "Selection.h"

class Game {
private:
    sf::RenderWindow window{sf::VideoMode(1024, 768), "Falling Sand"};
    ElementSystem elementSystem;
    Selection selection;

public:
    Game() = default;
    void handleMouseEvents(sf::Event event);
    void handleKeyEvents(sf::Event event);
    void run();
};
