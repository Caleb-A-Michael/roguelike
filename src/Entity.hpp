#pragma once

#include "Map.hpp"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

class Entity {
public:
    Entity(sf::Vector2i position, int size, sf::Color color);
    virtual ~Entity() = 0;

    sf::Vector2i getPosition() const;
    int getSize() const;
    const sf::Color& getColor() const;

    bool setPosition(const Map& map, sf::Vector2i position);
private:
    sf::Vector2i m_position;
    const int m_size;
    const sf::Color m_color;
};