#pragma once
#include <SFML/Graphics.hpp>

enum class ElementType {
    SAND,
    STONE,
    WATER
};

struct EmptyPositions {
    bool upLeft = false, up = false, upRight = false;
    bool left = false, right = false;
    bool downLeft = false, down = false, downRight = false;
};

class Utils {
public:
    static const int WIDTH = 640, HEIGHT = 360, ABOVE_LIMIT = 20;
    static const int NR_ELEMENTS = 3;
    static sf::Color getColor(ElementType element);
    static bool insideInterval(int value, int leftBound, int rightBound);
    static bool insideWindow(int x, int y);
    static int getIndex(int x, int y);
};
