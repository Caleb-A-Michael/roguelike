#pragma once

#include <SFML/System.hpp>
#include <vector>
#include <cassert>
#include <algorithm>

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

inline std::vector<sf::Vector2i> getNeighboringCells(const std::vector<sf::Vector2i>& positions) {
    std::vector<sf::Vector2i> cells; 

    for (const auto& cell : positions) {
        std::vector<sf::Vector2i> neighbors = getNeighboringCells(cell);
        for (const auto& neighbor : neighbors) {
            if (std::ranges::find(cells, neighbor) != cells.end()) continue;
            if (std::ranges::find(positions, neighbor) != positions.end()) continue;

            cells.push_back(neighbor);
        }
    }

    return cells;
}