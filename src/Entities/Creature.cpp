#include "Creature.hpp"

Creature::Creature(sf::Vector2i position, int size, sf::Color color) 
    : Entity(position, {size, size}, color)
{
}

Creature::~Creature() = default;