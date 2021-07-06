#include "Selection.h"

Selection::Selection() {
    colorVertices.setPrimitiveType(sf::Quads);
    borderVertices.setPrimitiveType(sf::LineStrip);
    setElement(ElementType::SAND);
    for (int i = 0; i<Utils::NR_ELEMENTS; i++) {
        float left = static_cast<float>(40*i+15), right = static_cast<float>(40*i+45), up = 10, down = 40;
        colorVertices.append(sf::Vertex(sf::Vector2f(left, down), Utils::getColor(static_cast<ElementType>(i))));
        colorVertices.append(sf::Vertex(sf::Vector2f(left ,up), Utils::getColor(static_cast<ElementType>(i))));
        colorVertices.append(sf::Vertex(sf::Vector2f(right, up), Utils::getColor(static_cast<ElementType>(i))));
        colorVertices.append(sf::Vertex(sf::Vector2f(right, down), Utils::getColor(static_cast<ElementType>(i))));
    }
}

void Selection::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    states.texture = nullptr;
    target.draw(colorVertices, states);
    target.draw(borderVertices, states);
}

void Selection::setElement(ElementType element) {
    selectedElement = element;
    borderVertices.clear();
    int position = static_cast<int>(selectedElement);
    float left = static_cast<float>(40*position+15), right = static_cast<float>(40*position+45), up = 10, down = 40;
    borderVertices.append(sf::Vertex(sf::Vector2f(left, up), sf::Color::Red));
    borderVertices.append(sf::Vertex(sf::Vector2f(right, up), sf::Color::Red));
    borderVertices.append(sf::Vertex(sf::Vector2f(right, down), sf::Color::Red));
    borderVertices.append(sf::Vertex(sf::Vector2f(left, down), sf::Color::Red));
    borderVertices.append(sf::Vertex(sf::Vector2f(left, up), sf::Color::Red));
}

ElementType Selection::getSelected() {
    return selectedElement;
}
