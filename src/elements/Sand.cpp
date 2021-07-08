#include "Sand.h"

Sand::Sand(int _positionX, int _positionY): Element{_positionX, _positionY, Utils::getColor(ElementType::SAND)} {
}

std::pair<int, int> Sand::getNextPosition(bool downLeft, bool down, bool downRight) {
    if (down) {
        return {getPositionX(), getPositionY()+1};
    }
    else if (downLeft) {
        return {getPositionX()-1, getPositionY()+1};
    }
    else if (downRight) {
        return {getPositionX()+1, getPositionY()+1};
    }
    else {
        return {getPositionX(), getPositionY()};
    }
}
