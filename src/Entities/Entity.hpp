#pragma once

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

class Entity {
public:
    Entity(sf::Vector2i position, sf::Vector2i size, sf::Color color);
    virtual ~Entity() = 0;

    sf::Vector2i getPosition() const;
    sf::Vector2i getSize() const;
    const sf::Color& getColor() const;

    void setPosition(sf::Vector2i position);
private:
    sf::Vector2i m_position;
    const sf::Vector2i m_size;
    const sf::Color m_color;
};