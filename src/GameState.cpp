#include "GameState.hpp"

#include "Map/MapLoader.hpp"

#include "Entities/Objects/Door.hpp"

GameState::GameState(const std::string& mapPath) 
    : map(MapLoader::load(mapPath))
{
    auto new_player = std::make_unique<Player>(sf::Vector2i(2, 2));
    player = new_player.get();
    entities.push_back(std::move(new_player));

    auto door = std::make_unique<Door>(sf::Vector2i(7, 2), sf::Vector2i(1, 2));
    entities.push_back(std::move(door));
}