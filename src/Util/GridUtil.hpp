#pragma once

#include <SFML/System.hpp>
#include <vector>
#include <cassert>
#include <algorithm>

inline std::vector<sf::Vector2i> getOccupyingCells(sf::Vector2i position, sf::Vector2i size) {
    assert(size.x >= 0);
    assert(size.y >= 0);
    
    std::vector<sf::Vector2i> cells;

    for (int x = position.x; x < position.x + size.x; x++) {
        for (int y = position.y; y < size.y + size.y; y++) {
            cells.push_back(sf::Vector2i{x, y});
        }
    }

    return cells;
}

inline std::vector<sf::Vector2i> getNeighboringCells(sf::Vector2i position) {
    int x = position.x;
    int y = position.y;

    std::vector<sf::Vector2i> cells;
    cells.push_back(sf::Vector2i{x, y - 1});
    cells.push_back(sf::Vector2i{x, y + 1});
    cells.push_back(sf::Vector2i{x - 1, y});
    cells.push_back(sf::Vector2i{x + 1, y});

    return cells;
}