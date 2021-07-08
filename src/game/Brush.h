#pragma once
#include <vector>
#include "Utils.h"

class Brush {
private:
    int minimumSize = 1, maximumSize = 30;
    int size;
public:
    Brush();
    void increaseSize();
    void decreaseSize();
    [[nodiscard]] int getSize() const;
    [[nodiscard]] std::vector< std::pair<int, int> > getPositions(int startX, int startY) const;
};
