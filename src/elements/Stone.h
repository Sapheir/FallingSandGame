#include "Element.h"

class Stone: public Element {
public:
    Stone(int _positionX, int _positionY);
    std::pair<int, int> getNextPosition(bool downLeft, bool down, bool downRight) override;
};
