#pragma once

#include "Entity.hpp"

class Dummy : public Entity {
public:
    Dummy(sf::Vector2i position, int size, sf::Color color);
    ~Dummy() override;
};