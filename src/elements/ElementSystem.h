#pragma once
#include <memory>
#include "Sand.h"
#include "Stone.h"
#include "Water.h"
#include "Lava.h"
#include "Cobblestone.h"
#include "../game/Utils.h"

class ElementSystem: public sf::Drawable, public sf::Transformable {
private:
    std::vector< std::unique_ptr<Element> > elements;
    sf::VertexArray vertices;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

public:
    ElementSystem();
    void updateElements(int startHeight, int endHeight);
    void update();
    void addElements(const std::vector<std::pair<int,int>> &positions, ElementType type);
    void addElement(std::unique_ptr<Element> element);
    void removeElements(const std::vector<std::pair<int,int>> &positions);
    void removeElement(int positionX, int positionY);
    EmptyPositions getEmptyPositions(int positionX, int positionY);
    int getReceivingDamage(int positionX, int positionY);
};
