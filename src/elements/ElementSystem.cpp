#include "ElementSystem.h"
#include <thread>

ElementSystem::ElementSystem() {
    elements.resize(Utils::WIDTH*Utils::HEIGHT);
}

void ElementSystem::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    states.texture = nullptr;
    target.draw(vertices, states);
}

void ElementSystem::updateElements(const int startHeight, const int endHeight) {
    for (int posY = startHeight; posY >= endHeight; posY--)
        for (int posX = 1; posX <= Utils::WIDTH; posX++) {
            int index = Utils::getIndex(posX, posY);
            if (elements[index]) {
                EmptyPositions emptyPositions = getEmptyPositions(posX, posY);
                std::pair<int, int> nextPosition = elements[index]->getNextPosition(emptyPositions);
                int newIndex = Utils::getIndex(nextPosition.first, nextPosition.second);
                int resistance = elements[index]->getResistance(), receivedDamage = getReceivingDamage(posX, posY);
                elements[index]->applyDamage(receivedDamage);
                if (elements[index]->getResistance() <= 0 && resistance > 0) {
                    elements[index] = std::make_unique<Cobblestone>(posX, posY);
                }
                else if (elements[newIndex] && elements[index]->getDensity() > elements[newIndex]->getDensity()) {
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
    int noThreads = (int)std::thread::hardware_concurrency();
    std::vector< std::thread > elementThreads(noThreads);
    int totalRows = Utils::HEIGHT - Utils::ABOVE_LIMIT + 1;
    int amountPerThread = totalRows / noThreads;
    int currentThreadStart = Utils::HEIGHT, currentThreadEnd = std::max(Utils::ABOVE_LIMIT, currentThreadStart - amountPerThread);
    for (int i = 0; i < noThreads; i++) {
        elementThreads[i] = std::thread(&ElementSystem::updateElements, this, currentThreadStart, currentThreadEnd);
        currentThreadStart = currentThreadEnd - 1;
        currentThreadEnd = std::max(Utils::ABOVE_LIMIT, currentThreadStart - amountPerThread);
    }
    for (int i = 0; i < noThreads; i++) {
        elementThreads[i].join();
    }
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
            case ElementType::LAVA:
                newElement = std::make_unique<Lava>(it.first, it.second);
                break;
            case ElementType::COBBLESTONE:
                newElement = std::make_unique<Cobblestone>(it.first, it.second);
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

int ElementSystem::getReceivingDamage(int positionX, int positionY) {
    int damage = 0;
    int indexUp = Utils::getIndex(positionX, positionY-1), indexDown = Utils::getIndex(positionX, positionY+1);
    int indexLeft = Utils::getIndex(positionX-1, positionY), indexRight = Utils::getIndex(positionX+1, positionY);
    if (Utils::insideWindow(positionX, positionY-1) && elements[indexUp])
        damage += elements[indexUp]->getDamage();
    if (Utils::insideWindow(positionX, positionY+1) && elements[indexDown])
        damage += elements[indexDown]->getDamage();
    if (Utils::insideWindow(positionX-1, positionY) && elements[indexLeft])
        damage += elements[indexLeft]->getDamage();
    if (Utils::insideWindow(positionX+1, positionY) && elements[indexRight])
        damage += elements[indexRight]->getDamage();
    return damage;
}
