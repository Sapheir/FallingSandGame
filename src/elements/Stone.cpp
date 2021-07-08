#include "Stone.h"

Stone::Stone(int _positionX, int _positionY): Element{_positionX, _positionY, Utils::getColor(ElementType::STONE)} {
}

std::pair<int, int> Stone::getNextPosition(bool downLeft, bool down, bool downRight) {
    return {getPositionX(), getPositionY()};
}
