#include "Stone.h"

Stone::Stone(int _positionX, int _positionY): Element{_positionX, _positionY, Utils::getColor(ElementType::STONE)} {
    density = 1602;
}

std::pair<int, int> Stone::getNextPosition(EmptyPositions emptyPositions) {
    return {getPositionX(), getPositionY()};
}
