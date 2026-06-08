#include "GameState.hpp"
#include "MapLoader.hpp"
#include "GridUtils.hpp"

#include "Dummy.hpp"

GameState::GameState(const std::string& mapPath) 
    : map(MapLoader::load(mapPath))
{
    auto p = std::make_unique<Player>(sf::Vector2i(2, 2), 2, sf::Color::Blue);
    player = p.get();
    entities.push_back(std::move(p));
}

std::vector<sf::Vector2i> GameState::getReachablePositions(sf::Vector2i position, int reach, int size = 1) const {
    assert(reach >= 0);
    assert(size > 0);  
  
    std::vector<sf::Vector2i> validCells;

    std::vector<sf::Vector2i> currSearchingCells = getNeighboringCells(position);
    std::vector<sf::Vector2i> nextSearchingCells;
    
    for (int i = 0; i < reach; i++) {
        int searchingCellsSize = currSearchingCells.size();
        for (int j = 0; j < searchingCellsSize; j++) {
            const auto& cell = currSearchingCells[j];
            if (map.isOccupied(cell, size)) continue;
            if (std::ranges::find(validCells, cell) != validCells.end()) continue;

            validCells.push_back(cell);

            const auto& neighbors = getNeighboringCells(cell);
            for (const auto& neighbor : neighbors) {
                nextSearchingCells.push_back(neighbor);
            }
        }

        currSearchingCells = nextSearchingCells;
        nextSearchingCells.clear();
    }

    return validCells;
 }