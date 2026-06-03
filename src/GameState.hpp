#pragma once

#include "Map.hpp"
#include "Entity.hpp"
#include "Player.hpp"
#include <string>
#include <vector>
#include <memory>

class GameState {
public:
    GameState(const std::string& mapPath);

    Map map;
    std::vector<std::unique_ptr<Entity>> entities;
    Player* player;
};