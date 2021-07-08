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
                EmptyPositions emptyPositions = getEmptyPositions(posX, posY);
                std::pair<int, int> nextPosition = elements[index]->getNextPosition(emptyPositions);
                int newIndex = Utils::getIndex(nextPosition.first, nextPosition.second);
                if (elements[newIndex] && elements[index]->getDensity() > elements[newIndex]->getDensity()) {
                    elements[newIndex].swap(elements[index]);
                    elements[newIndex]->setPosition(nextPosition);
                    elements[index]->setPosition({posX, posY});
                }
                else {
                    elements[newIndex] = std::move(elements[index]);
                    elements[newIndex]->setPosition(nextPosition);
                }
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
            case ElementType::WATER:
                newElement = std::make_unique<Water>(it.first, it.second);
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

EmptyPositions ElementSystem::getEmptyPositions(int positionX, int positionY) {
    int index = Utils::getIndex(positionX, positionY);
    int indexDown = Utils::getIndex(positionX, positionY+1), indexDownLeft = Utils::getIndex(positionX-1, positionY+1), indexDownRight = Utils::getIndex(positionX+1, positionY+1);
    int indexLeft = Utils::getIndex(positionX-1, positionY), indexRight = Utils::getIndex(positionX+1, positionY);
    EmptyPositions emptyPositions;
    emptyPositions.down = Utils::insideWindow(positionX, positionY+1) && (!elements[indexDown] || (elements[index]->getDensity() > elements[indexDown]->getDensity()));
    emptyPositions.downLeft = Utils::insideWindow(positionX-1, positionY+1) && !elements[indexDownLeft];
    emptyPositions.downRight = Utils::insideWindow(positionX+1, positionY+1) && !elements[indexDownRight];
    if (Utils::insideWindow(positionX, positionY+1) && (!elements[indexDown] || !elements[indexDown]->isFalling())) {
        emptyPositions.left = Utils::insideWindow(positionX-1, positionY) && !elements[indexLeft];
        emptyPositions.right = Utils::insideWindow(positionX+1, positionY) && !elements[indexRight];
    }
    return emptyPositions;
}
