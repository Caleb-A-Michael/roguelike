#include "Object.hpp"

Object::Object(sf::Vector2i position, sf::Vector2i size, sf::Color color) 
    : Entity(position, size, color)
{
}

Object::~Object() = default;