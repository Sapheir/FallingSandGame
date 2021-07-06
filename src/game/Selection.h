#pragma once
#include "Utils.h"

class Selection: public sf::Drawable, public sf::Transformable {
private:
    ElementType selectedElement{};
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::VertexArray colorVertices, borderVertices;

public:
    Selection();
    void setElement(ElementType element);
    ElementType getSelected();
};

