#pragma once

#include <SFML/System.hpp>
#include <vector>
#include <cassert>

inline std::vector<sf::Vector2i> getOccupyingCells(sf::Vector2i position, int size) {
    assert(size >= 0);
    
    std::vector<sf::Vector2i> cells;
    
    int x = position.x;
    int y = position.y;
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            cells.push_back(sf::Vector2i{i, j});
        }
    }

    return cells;
}

inline std::vector<sf::Vector2i> getOccupyingCells(int x, int y, int size) {
    return getOccupyingCells(sf::Vector2i(x, y), size);
}