#include "Map.hpp"
#include <cassert>

Map::Map(int width, int height)
    : m_width(width)
    , m_height(height)
    , m_tiles(width * height)
{
}

Tile& Map::getTile(int x, int y) {
    assert(inBounds(x, y));
    return m_tiles[y * m_width + x];
}

const Tile& Map::getTile(int x, int y) const {
    assert(inBounds(x, y));
    return m_tiles[y * m_width + x];
}

int Map::getWidth() const {
    return m_width;
}

int Map::getHeight() const {
    return m_height;
}

bool Map::inBounds(int x, int y) const {
    if (x < 0 || x >= m_width) return false;
    if (y < 0 || y >= m_height) return false;

    return true;
}

bool Map::isOccupied(int x, int y) const {
    if (!inBounds(x, y)) return true;

    TileData data = getTileData(getTile(x, y).type);
    return (data.isSolid);
}

bool Map::isOccupied(int x, int y, int size) const {
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (isOccupied(i, j)) return true;
        }
    }

    return false;
}

bool Map::isOccupied(sf::Vector2i position) const {
    return isOccupied(position.x, position.y);
}

bool Map::isOccupied(sf::Vector2i position, int size) const {
    return isOccupied(position.x, position.y, size);
}