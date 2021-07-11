#include "Utils.h"

sf::Color Utils::getColor(ElementType element) {
    switch (element) {
        case ElementType::SAND:
            return sf::Color(238,232,170);
        case ElementType::STONE:
            return sf::Color(105,105,105);
        case ElementType::WATER:
            return sf::Color(0, 0, 205);
        case ElementType::LAVA:
            return sf::Color(205, 0, 0);
        case ElementType::COBBLESTONE:
            return sf::Color(160,160,160);
        default:
            return sf::Color::White;
    }
}

float Utils::getDensity(ElementType element) {
    switch (element) {
        case ElementType::SAND:
            return 1500;
        case ElementType::STONE:
            return 1600;
        case ElementType::WATER:
        case ElementType::LAVA:
            return 1000;
        case ElementType::COBBLESTONE:
            return 2000;
        default:
            return 1;
    }
}

bool Utils::insideInterval(int value, int leftBound, int rightBound) {
    return value >= leftBound && value <= rightBound;
}

int Utils::getIndex(int x, int y) {
    return (HEIGHT-y)*WIDTH+x-1;
}

bool Utils::insideWindow(int x, int y) {
    return insideInterval(x, 1, WIDTH) && insideInterval(y, ABOVE_LIMIT, HEIGHT);
}

