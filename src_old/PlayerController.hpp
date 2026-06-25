#pragma once

#include "GameState.hpp"
#include <SFML/Window.hpp> 

namespace PlayerController {
    void handleInput(const sf::Event& event, GameState& state);
}