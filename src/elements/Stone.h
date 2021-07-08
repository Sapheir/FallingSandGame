#include "Element.h"

class Stone: public Element {
public:
    Stone(int _positionX, int _positionY);
    std::pair<int, int> getNextPosition(EmptyPositions emptyPositions) override;
};
