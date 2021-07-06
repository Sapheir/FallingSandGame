#pragma once
#include <SFML/Graphics.hpp>

enum class ElementType {
    SAND,
    STONE
};

class Utils {
public:
    static const int WIDTH = 1024, HEIGHT = 768, ABOVE_LIMIT = 50;
    static const int NR_ELEMENTS = 2;
    static sf::Color getColor(ElementType element);
    static bool insideInterval(int value, int leftBound, int rightBound);
};
