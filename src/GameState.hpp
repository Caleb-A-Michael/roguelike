#pragma once

#include "Map/Map.hpp"
#include "Entities/Entity.hpp"
#include "Entities/Creatures/Player.hpp"
#include <string>
#include <vector>

class GameState {
public:
    GameState(const std::string& mapPath);

    Map map;
    std::vector<std::unique_ptr<Entity>> entities;
    Player* player = nullptr;
};