#include "Game.h"

void Game::run() {
    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    Element element(event.mouseButton.x, event.mouseButton.y, sf::Color::Yellow);
                    elementSystem.addElement(std::make_shared<Element>(element));
                }
                else if (event.mouseButton.button == sf::Mouse::Right) {
                    elementSystem.removeElement(event.mouseButton.x, event.mouseButton.y);
                }
            }
        }
        elementSystem.update();
        window.clear();
        window.draw(elementSystem);
        window.display();
    }
}
