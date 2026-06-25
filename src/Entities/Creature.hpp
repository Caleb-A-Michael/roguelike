#pragma once

#include "Entity.hpp"

class Creature : public Entity {
public:
    Creature(sf::Vector2i position, int size, sf::Color color);
    virtual ~Creature() = 0;
};