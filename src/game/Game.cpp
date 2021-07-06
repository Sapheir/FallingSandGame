#include "Game.h"

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
        window.draw(selection);
        window.draw(elementSystem);
        window.display();
    }
}

void Game::handleMouseEvents(sf::Event event) {
    if (event.mouseButton.button == sf::Mouse::Left) {
        Element element(event.mouseButton.x, event.mouseButton.y, Utils::getColor(selection.getSelected()));
        elementSystem.addElement(std::make_shared<Element>(element));
    }
    else if (event.mouseButton.button == sf::Mouse::Right) {
        elementSystem.removeElement(event.mouseButton.x, event.mouseButton.y);
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
        default:
            break;
    }
}
