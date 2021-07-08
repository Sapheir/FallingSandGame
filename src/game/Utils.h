#pragma once
#include <SFML/Graphics.hpp>

enum class ElementType {
    SAND,
    STONE
};

class Utils {
public:
    static const int WIDTH = 640, HEIGHT = 360, ABOVE_LIMIT = 20;
    static const int NR_ELEMENTS = 2;
    static sf::Color getColor(ElementType element);
    static bool insideInterval(int value, int leftBound, int rightBound);
    static bool insideWindow(int x, int y);
    static int getIndex(int x, int y);
};
