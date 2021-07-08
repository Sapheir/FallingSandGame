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
    bool isHoldingLeft = false, isHoldingRight = false;
    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::MouseButtonPressed:
                    if (event.mouseButton.button == sf::Mouse::Left)
                        isHoldingLeft = true;
                    else if (event.mouseButton.button == sf::Mouse::Right)
                        isHoldingRight = true;
                    break;
                case sf::Event::MouseButtonReleased:
                    if (event.mouseButton.button == sf::Mouse::Left)
                        isHoldingLeft = false;
                    else if (event.mouseButton.button == sf::Mouse::Right)
                        isHoldingRight = false;
                    break;
                case sf::Event::KeyPressed:
                    handleKeyEvents(event);
                    break;
                default:
                    break;
            }
            if (isHoldingLeft) {
                handleAdd();
            }
            else if (isHoldingRight) {
                handleRemove();
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

void Game::handleAdd() {
    elementSystem.addElements(brush.getPositions(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y), selection.getSelected());
}

void Game::handleRemove() {
    elementSystem.removeElements(brush.getPositions(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y));
}

void Game::handleKeyEvents(sf::Event event) {
    switch (event.key.code) {
        case sf::Keyboard::Num1:
            selection.setElement(ElementType::SAND);
            break;
        case sf::Keyboard::Num2:
            selection.setElement(ElementType::STONE);
            break;
        case sf::Keyboard::Num3:
            selection.setElement(ElementType::WATER);
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
