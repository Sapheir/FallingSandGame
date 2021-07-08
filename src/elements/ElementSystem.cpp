#include "ElementSystem.h"

ElementSystem::ElementSystem() {
    elements.resize(Utils::WIDTH*Utils::HEIGHT);
}

void ElementSystem::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    states.texture = nullptr;
    target.draw(vertices, states);
}

void ElementSystem::updateElements() {
    for (int posY = Utils::HEIGHT; posY >= Utils::ABOVE_LIMIT; posY--)
        for (int posX = 1; posX <= Utils::WIDTH; posX++) {
            int index = Utils::getIndex(posX, posY);
            if (elements[index]) {
                bool downLeft = Utils::insideWindow(posX-1, posY+1) && !elements[Utils::getIndex(posX-1, posY+1)];
                bool down = Utils::insideWindow(posX, posY+1) && !elements[Utils::getIndex(posX, posY+1)];
                bool downRight = Utils::insideWindow(posX+1, posY+1) && !elements[Utils::getIndex(posX+1, posY+1)];
                std::pair<int, int> nextPosition = elements[index]->getNextPosition(downLeft, down, downRight);
                int newIndex = Utils::getIndex(nextPosition.first, nextPosition.second);
                elements[newIndex] = std::move(elements[index]);
                elements[newIndex]->setPosition(nextPosition);
            }
        }
}

void ElementSystem::update() {
    vertices.clear();
    updateElements();
    for (const auto& element: elements) {
        if (element)
            vertices.append(sf::Vertex(sf::Vector2f((float)element->getPositionX(), (float)element->getPositionY()), element->getColor()));
    }
}

void ElementSystem::addElement(std::unique_ptr<Element> element) {
    int index = Utils::getIndex(element->getPositionX(), element->getPositionY());
    if (elements[index])
        return;
    elements[index] = std::move(element);
}

void ElementSystem::removeElement(int positionX, int positionY) {
    int index = Utils::getIndex(positionX, positionY);
    elements[index] = nullptr;
}

void ElementSystem::addElements(const std::vector<std::pair<int, int>> &positions, ElementType element) {
    for (auto it: positions) {
        std::unique_ptr<Element> newElement;
        switch (element) {
            case ElementType::SAND:
                newElement = std::make_unique<Sand>(it.first, it.second);
                break;
            case ElementType::STONE:
                newElement = std::make_unique<Stone>(it.first, it.second);
                break;
            default:
                break;
        }
        addElement(std::move(newElement));
    }
}

void ElementSystem::removeElements(const std::vector<std::pair<int, int>> &positions) {
    for (auto it: positions) {
        removeElement(it.first, it.second);
    }
}
