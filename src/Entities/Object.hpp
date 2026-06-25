#pragma once

#include "Entity.hpp"

class Object : public Entity {
public:
    Object(sf::Vector2i position, sf::Vector2i size, sf::Color color);
    virtual ~Object() = 0;
};