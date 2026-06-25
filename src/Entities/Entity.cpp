#include "Entity.hpp"

Entity::Entity(sf::Vector2i position, sf::Vector2i size, sf::Color color)
    : m_position(position)
    , m_size(size)
    , m_color(color)
{}

Entity::~Entity() = default;

sf::Vector2i Entity::getPosition() const {
    return m_position;
}

sf::Vector2i Entity::getSize() const {
    return m_size;
}

const sf::Color& Entity::getColor() const {
    return m_color;
}

void Entity::setPosition(sf::Vector2i position) {
    m_position = position;
}