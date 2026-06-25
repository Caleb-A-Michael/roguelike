#include "Dummy.hpp"

Dummy::Dummy(sf::Vector2i position, int size, sf::Color color)
    : Entity(position,size, color)
{
}

Dummy::~Dummy() {}