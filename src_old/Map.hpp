#pragma once

#include "Tile.hpp"
#include <SFML/System.hpp>
#include <vector>

class Map {
public:
    Map(sf::Vector2i size);

    sf::Vector2i getSize() const;

    Tile& getTile(sf::Vector2i position);
    const Tile& getTile(sf::Vector2i position) const;

    bool inBounds(sf::Vector2i position) const;
    bool isOccupied(sf::Vector2i position, int size = 1) const;

    sf::Vector2i m_size;
    std::vector<Tile> m_tiles;
};