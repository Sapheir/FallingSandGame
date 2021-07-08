#include "Element.h"

Element::Element(int _positionX, int _positionY, sf::Color _color): positionX{_positionX}, positionY{_positionY}, color{_color} {
}

int Element::getPositionX() const {
    return positionX;
}

int Element::getPositionY() const {
    return positionY;
}

const sf::Color &Element::getColor() const {
    return color;
}

void Element::setPosition(std::pair<int, int> position) {
    positionX = position.first;
    positionY = position.second;
}

bool Element::isFalling() const {
    return falling;
}

bool Element::isLiquid() const {
    return liquid;
}
