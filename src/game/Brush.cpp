#include "Brush.h"

Brush::Brush() {
    size = (minimumSize+maximumSize)/2;
}

void Brush::increaseSize() {
    size = std::min(size+1, maximumSize);
}

void Brush::decreaseSize() {
    size = std::max(size-1, minimumSize);
}

int Brush::getSize() const {
    return size;
}

std::vector< std::pair<int, int> > Brush::getPositions(int startX, int startY) const {
    std::vector< std::pair<int,int> > positions;
    for (int i = -size; i<=size; i++)
        for (int j = -size; j<=size; j++) {
            int positionX = i+startX, positionY = j+startY;
            if (i*i+j*j>size*size) { // the current position is outside the circle
                continue;
            }
            if (Utils::insideInterval(positionX, 0, Utils::WIDTH) && Utils::insideInterval(positionY, Utils::ABOVE_LIMIT, Utils::HEIGHT)){
                positions.emplace_back(positionX, positionY);
            }
        }
    return positions;
}
