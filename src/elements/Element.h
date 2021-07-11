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
    float density{};
    int resistance = 1, damage{};

public:
    Element() = default;
    Element(int _positionX, int _positionY, sf::Color _color, float _density);

    [[nodiscard]] int getPositionX() const;

    [[nodiscard]] int getPositionY() const;

    [[nodiscard]] const sf::Color &getColor() const;

    void setPosition(std::pair<int, int> position);

    void applyDamage(int _damage);

    [[nodiscard]] int getResistance() const;

    [[nodiscard]] int getDamage() const;

    [[nodiscard]] bool isFalling() const;

    [[nodiscard]] float getDensity() const;

    virtual std::pair<int, int> getNextPosition(EmptyPositions emptyPositions) = 0;
};
