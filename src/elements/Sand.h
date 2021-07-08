#include "Element.h"

class Sand: public Element {
public:
    Sand(int _positionX, int _positionY);
    std::pair<int, int> getNextPosition(bool downLeft, bool down, bool downRight) override;
};