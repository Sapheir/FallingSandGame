#pragma once
#include "Element.h"

class Lava: public Element {
public:
    Lava(int _positionX, int _positionY);
    std::pair<int, int> getNextPosition(EmptyPositions emptyPositions) override;
};
