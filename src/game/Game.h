#pragma once
#include "../elements/ElementSystem.h"
#include "Selection.h"
#include "Brush.h"
#include "Utils.h"

class Game {
private:
    sf::RenderWindow window{sf::VideoMode(Utils::WIDTH, Utils::HEIGHT), "Falling Sand", sf::Style::Titlebar | sf::Style::Close};
    ElementSystem elementSystem;
    Selection selection;
    Brush brush;
    sf::Font textFont;
    sf::Text brushText;

public:
    Game();
    void handleAdd();
    void handleRemove();
    void handleKeyEvents(sf::Event event);
    void run();
};
