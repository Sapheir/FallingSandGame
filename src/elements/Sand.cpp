#include "Sand.h"

Sand::Sand(int _positionX, int _positionY): Element{_positionX, _positionY, Utils::getColor(ElementType::SAND)} {
}

std::pair<int, int> Sand::getNextPosition(EmptyPositions emptyPositions) {
    falling = true;
    if (emptyPositions.down) {
        return {getPositionX(), getPositionY()+1};
    }
    else if (emptyPositions.downLeft) {
        return {getPositionX()-1, getPositionY()+1};
    }
    else if (emptyPositions.downRight) {
        return {getPositionX()+1, getPositionY()+1};
    }
    else {
        falling = false;
        return {getPositionX(), getPositionY()};
    }
}
