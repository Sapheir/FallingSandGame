#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "../game/Utils.h"

class Element {
private:
    int positionX{}, positionY{};
    sf::Color color{};

protected:
    bool falling = false;
    bool liquid = false;

public:
    Element() = default;
    Element(int _positionX, int _positionY, sf::Color _color);

    [[nodiscard]] int getPositionX() const;

    [[nodiscard]] int getPositionY() const;

    [[nodiscard]] const sf::Color &getColor() const;

    void setPosition(std::pair<int, int> position);

    [[nodiscard]] bool isFalling() const;

    [[nodiscard]] bool isLiquid() const;

    virtual std::pair<int, int> getNextPosition(EmptyPositions emptyPositions) = 0;
};
