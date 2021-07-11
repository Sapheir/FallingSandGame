#include "Lava.h"

Lava::Lava(int _positionX, int _positionY): Element{_positionX, _positionY, Utils::getColor(ElementType::LAVA), Utils::getDensity(ElementType::LAVA)} {
    damage = 1;
    resistance = 0;
}

std::pair<int, int> Lava::getNextPosition(EmptyPositions emptyPositions) {
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
