#pragma once
#include <memory>
#include "Element.h"
#include "../game/Utils.h"

class ElementSystem: public sf::Drawable, public sf::Transformable {
private:
    std::vector< std::shared_ptr<Element> > elements;
    sf::VertexArray vertices;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

public:
    ElementSystem() = default;
    void update();
    void addElements(const std::vector<std::pair<int,int>> &positions, ElementType type);
    void addElement(const std::shared_ptr<Element>& element);
    void removeElement(int positionX, int positionY);
};
