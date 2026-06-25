#pragma once

#include "Entities/Creature.hpp"

class Player : public Creature {
public:
    Player(sf::Vector2i position);
private:
    static constexpr int SIZE = 2;
    static constexpr sf::Color COLOR = sf::Color::Blue;
};