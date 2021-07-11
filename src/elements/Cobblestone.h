#include "Element.h"

class Cobblestone: public Element {
public:
    Cobblestone(int _positionX, int _positionY);
    std::pair<int, int> getNextPosition(EmptyPositions emptyPositions) override;
};
