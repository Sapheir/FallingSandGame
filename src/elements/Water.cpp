#include "Water.h"

Water::Water(int _positionX, int _positionY): Element{_positionX, _positionY, Utils::getColor(ElementType::WATER)} {
    liquid = true;
}

std::pair<int, int> Water::getNextPosition(EmptyPositions emptyPositions) {
    falling = false;
    if (emptyPositions.down) {
        falling = true;
        return {getPositionX(), getPositionY() + 1};
    }
    else if (rand()%2 && emptyPositions.left)
        return {getPositionX()-1, getPositionY()};
    else if (emptyPositions.right)
        return {getPositionX()+1, getPositionY()};
    else if (emptyPositions.downLeft)
        return {getPositionX()-1, getPositionY()+1};
    else if (emptyPositions.downRight)
        return {getPositionX()+1, getPositionY()+1};
    else
        return {getPositionX(), getPositionY()};
}
