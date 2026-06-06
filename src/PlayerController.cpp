#include "PlayerController.hpp"

#include <iostream>

void PlayerController::handleInput(const sf::Event& event, GameState& state) {
    sf::Vector2i moveDirection;
    if (const auto* keyPressed = event.getIf<sf::Event::KeyPressed>()) {
        switch (keyPressed->code) {
            case sf::Keyboard::Key::W:
            case sf::Keyboard::Key::Up:
                moveDirection = {0, -1};
                break;
            case sf::Keyboard::Key::A:
            case sf::Keyboard::Key::Left:
                moveDirection = {-1, 0};
                break;
            case sf::Keyboard::Key::S:
            case sf::Keyboard::Key::Down:
                moveDirection = {0, 1};
                break;
            case sf::Keyboard::Key::D:
            case sf::Keyboard::Key::Right:
                moveDirection = {1, 0};
                break;
            default:
                moveDirection = {0, 0};
        }

        std::cout << moveDirection.x << " " << moveDirection.y << "\n";
        state.player->setPosition(state.map, state.player->getPosition() + moveDirection);
    }
}