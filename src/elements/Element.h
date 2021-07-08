#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "../game/Utils.h"

class Element {
private:
    int positionX{}, positionY{};
    sf::Color color{};

public:
    Element() = default;
    Element(int _positionX, int _positionY, sf::Color _color);

    [[nodiscard]] int getPositionX() const;

    [[nodiscard]] int getPositionY() const;

    [[nodiscard]] const sf::Color &getColor() const;

    void setPosition(std::pair<int, int> position);

    virtual std::pair<int, int> getNextPosition(bool downLeft, bool down, bool downRight) = 0;
};
