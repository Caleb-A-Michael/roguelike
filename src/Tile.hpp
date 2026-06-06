#pragma once

#include <SFML/Graphics.hpp>

enum class TileType {
    Floor,
    Wall
};

struct TileData {
    bool isSolid;
    sf::Color color;
};

inline const TileData& getTileData(TileType type) {
    static const TileData data[] = {
        // Floor
        { false, sf::Color(100, 100, 100) },
        // Wall
        { true, sf::Color(50, 50, 50) },
    };
    return data[static_cast<int>(type)];
}

struct Tile {
    TileType type = TileType::Floor;
};