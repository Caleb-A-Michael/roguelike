#include "Entity.hpp"

Entity::Entity(sf::Vector2i position, int size, sf::Color color)
    : m_position(position)
    , m_size(size)
    , m_color(color)
{
}

Entity::~Entity() {}

sf::Vector2i Entity::getPosition() const {
    return m_position;
}

int Entity::getSize() const {
    return m_size;
}

const sf::Color& Entity::getColor() const {
    return m_color;
}

bool Entity::setPosition(const Map& map, sf::Vector2i position) {
    if (map.isOccupied(position, m_size)) {
        return false;
    }

    m_position = position;
    return true;
}