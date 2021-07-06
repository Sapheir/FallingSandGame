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

void Element::setPositionX(int _positionX) {
    positionX = _positionX;
}

void Element::setPositionY(int _positionY) {
    positionY = _positionY;
}
