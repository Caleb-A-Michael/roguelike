#include "Map/Tile.hpp"

#include <array>

static const std::array<TileData, 3> tileTable = {{
    // Floor
    { .color = sf::Color(100, 100, 100), .isSolid = false, .isWater = false },
    // Wall
    { .color = sf::Color(50, 50, 50), .isSolid = true, .isWater = false },
    // Water
    { .color = sf::Color(25, 25, 100), .isSolid = false, .isWater = true },
}};

const TileData& getTileData(TileType type) {
    return tileTable[static_cast<int>(type)];
}

Tile::Tile(TileType type) 
    : type(type)
{
}