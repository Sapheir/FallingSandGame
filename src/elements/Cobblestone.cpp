#include "Cobblestone.h"


Cobblestone::Cobblestone(int _positionX, int _positionY): Element{_positionX, _positionY, Utils::getColor(ElementType::COBBLESTONE), Utils::getDensity(ElementType::COBBLESTONE)} {
    resistance = 0;
}

std::pair<int, int> Cobblestone::getNextPosition(EmptyPositions emptyPositions) {
    falling = false;
    return {getPositionX(), getPositionY()};
}
