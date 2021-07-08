#include "Stone.h"

Stone::Stone(int _positionX, int _positionY): Element{_positionX, _positionY, Utils::getColor(ElementType::STONE), Utils::getDensity(ElementType::STONE)} {
}

std::pair<int, int> Stone::getNextPosition(EmptyPositions emptyPositions) {
    return {getPositionX(), getPositionY()};
}
