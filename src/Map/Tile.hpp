#pragma once

#include <SFML/Graphics.hpp>

enum class TileType {
    Floor,
    Wall,
    Water,
};

struct TileData {
    sf::Color color;
    bool isSolid;
    bool isWater;
};

const TileData& getTileData(TileType type);

struct Tile {
    TileType type = TileType::Floor;

    explicit Tile(TileType type);
};