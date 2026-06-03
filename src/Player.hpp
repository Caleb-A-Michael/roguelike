#pragma once

#include "Entity.hpp"

class Player : public Entity {
public:
    Player(sf::Vector2i position, int size, sf::Color color);
    ~Player() override;
};