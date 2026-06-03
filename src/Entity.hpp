#pragma once

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class Entity {
public:
    Entity(sf::Vector2i position, int size, sf::Color color);
    virtual ~Entity() = 0;

    sf::Vector2i position;
    int size;
    const sf::Color color;
};