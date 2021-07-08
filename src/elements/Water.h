#include "Element.h"

class Water: public Element {
public:
    Water(int _positionX, int _positionY);
    std::pair<int, int> getNextPosition(EmptyPositions emptyPositions) override;
};
