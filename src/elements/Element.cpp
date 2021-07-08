#include "Element.h"

Element::Element(int _positionX, int _positionY, sf::Color _color, float _density): positionX{_positionX}, positionY{_positionY}, color{_color}, density{_density} {
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

float Element::getDensity() const {
    return density;
}
