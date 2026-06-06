#pragma once

#include "Tile.hpp"
#include <SFML/System.hpp>
#include <vector>

class Map {
public:
    Map(int width, int height);

    Tile& getTile(int x, int y);
    const Tile& getTile(int x, int y) const;

    int getWidth() const;
    int getHeight() const;

    bool inBounds(int x, int y) const;

    bool isOccupied(int x, int y) const;
    bool isOccupied(int x, int y, int size) const;
    bool isOccupied(sf::Vector2i position) const;
    bool isOccupied(sf::Vector2i position, int size) const;
private:
    int m_width;
    int m_height;
    std::vector<Tile> m_tiles;
};