#pragma once

#include "Entities/Object.hpp"

class Door : public Object {
public:
    Door(sf::Vector2i position, sf::Vector2i size);
private:
    static constexpr sf::Color COLOR = sf::Color(175, 50, 0);
};