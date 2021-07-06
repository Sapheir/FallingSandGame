#pragma once
#include <SFML/Graphics.hpp>

class Element {
private:
    int positionX, positionY;
    sf::Color color;

public:
    Element(int _positionX, int _positionY, sf::Color _color);

    [[nodiscard]] int getPositionX() const;

    [[nodiscard]] int getPositionY() const;

    [[nodiscard]] const sf::Color &getColor() const;

    void setPositionX(int _positionX);

    void setPositionY(int _positionY);
};
