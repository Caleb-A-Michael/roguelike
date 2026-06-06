#include "Map.hpp"

#include "GridUtils.hpp"
#include <cassert>

Map::Map(sf::Vector2i size)
    : m_size(size)
    , m_tiles(size.x * size.y)
{
}

sf::Vector2i Map::getSize() const {
    return m_size;
}

Tile& Map::getTile(sf::Vector2i position) {
    assert(inBounds(position));
    return m_tiles[position.y * m_size.x + position.x];
}

const Tile& Map::getTile(sf::Vector2i position) const {
    assert(inBounds(position));
    return m_tiles[position.y * m_size.x + position.x];
}

bool Map::inBounds(sf::Vector2i position) const {
    int x = position.x;
    int y = position.y;

    if (x < 0 || x >= m_size.x) return false;
    if (y < 0 || y >= m_size.y) return false;

    return true;
}

bool Map::isOccupied(sf::Vector2i position, int size) const {
    if (!inBounds(position)) return true;

    std::vector<sf::Vector2i> cells = getOccupyingCells(position, size);
    for (const auto& cell : cells) {
        if (!inBounds(cell)) return true;

        TileData data = getTileData(getTile(cell).type);
        if (data.isSolid) return true;
    }

    return false;
}