#include "ElementSystem.h"

void ElementSystem::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    states.texture = nullptr;
    target.draw(vertices, states);
}

void ElementSystem::update() {
    vertices.clear();
    for (auto &element: elements) {
        vertices.append(sf::Vertex(sf::Vector2f((float)element->getPositionX(), (float)element->getPositionY()), element->getColor()));
    }
}

void ElementSystem::addElement(const std::shared_ptr<Element>& element) {
    elements.push_back(element);
}

void ElementSystem::removeElement(int positionX, int positionY) {
    elements.erase(std::remove_if(elements.begin(), elements.end(), [&](std::shared_ptr<Element> &element){
        return element->getPositionX() == positionX and element->getPositionY() == positionY;
    }), elements.end());
}

