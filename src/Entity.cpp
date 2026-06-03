#include "Entity.hpp"

Entity::Entity(sf::Vector2i position, int size, sf::Color color)
    : position(position)
    , size(size)
    , color(color)
{
}

Entity::~Entity() {}