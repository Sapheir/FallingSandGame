#pragma once
#include <SFML/Graphics.hpp>

enum class ElementType {
    SAND,
    STONE,
    WATER,
    LAVA,
    COBBLESTONE
};

struct EmptyPositions {
    bool upLeft = false, up = false, upRight = false;
    bool left = false, right = false;
    bool downLeft = false, down = false, downRight = false;
};

class Utils {
public:
    static constexpr int WIDTH = 640, HEIGHT = 360, ABOVE_LIMIT = 20;
    static constexpr int NR_ELEMENTS = 5;
    static sf::Color getColor(ElementType element);
    static float getDensity(ElementType element);
    static bool insideInterval(int value, int leftBound, int rightBound);
    static bool insideWindow(int x, int y);
    static int getIndex(int x, int y);
};
