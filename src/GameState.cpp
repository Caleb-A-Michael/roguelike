#include "GameState.hpp"
#include "MapLoader.hpp"

GameState::GameState(const std::string& mapPath) 
    : map(MapLoader::load(mapPath))
{
    auto p = std::make_unique<Player>(sf::Vector2i(2, 2), 2, sf::Color::Green);
    player = p.get();
    entities.push_back(std::move(p));
}