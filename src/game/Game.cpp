#include "Game.h"
#include <iostream>

Game::Game() {
    if (!textFont.loadFromFile("../assets/arial.ttf")) {
        throw std::runtime_error("Font was not found!");
    }
    brushText.setFont(textFont);
    brushText.setPosition(500, 15);
    brushText.setCharacterSize(20);
}

void Game::run() {
    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::MouseButtonPressed:
                    handleMouseEvents(event);
                    break;
                case sf::Event::KeyPressed:
                    handleKeyEvents(event);
                    break;
                default:
                    break;
            }
        }
        elementSystem.update();
        window.clear(sf::Color(135,206,250));
        window.draw(elementSystem);
        window.draw(selection);
        brushText.setString("Brush size: " + std::to_string(brush.getSize()));
        window.draw(brushText);
        window.display();
    }
}

void Game::handleMouseEvents(sf::Event event) {
    if (event.mouseButton.button == sf::Mouse::Left) {
        elementSystem.addElements(brush.getPositions(event.mouseButton.x, event.mouseButton.y), selection.getSelected());
    }
    else if (event.mouseButton.button == sf::Mouse::Right) {
        elementSystem.removeElements(brush.getPositions(event.mouseButton.x, event.mouseButton.y));
    }
}

void Game::handleKeyEvents(sf::Event event) {
    switch (event.key.code) {
        case sf::Keyboard::Num1:
            selection.setElement(ElementType::SAND);
            break;
        case sf::Keyboard::Num2:
            selection.setElement(ElementType::STONE);
            break;
        case sf::Keyboard::O:
            brush.decreaseSize();
            break;
        case sf::Keyboard::P:
            brush.increaseSize();
            break;
        default:
            break;
    }
}
