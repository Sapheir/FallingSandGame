#include "Element.h"

class Sand: public Element {
public:
    Sand(int _positionX, int _positionY);
    std::pair<int, int> getNextPosition(EmptyPositions emptyPositions) override;
};