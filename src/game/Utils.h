#pragma once
#include <SFML/Graphics.hpp>

enum class ElementType {
    SAND,
    STONE
};

class Utils {
public:
    static const int NR_ELEMENTS = 2;
    static sf::Color getColor(ElementType element);
};
