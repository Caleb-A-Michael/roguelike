#pragma once

#include "GameState.hpp"
#include "Entity.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

#include <SFML/System.hpp>

const int TILE_SIZE = 60;

class Renderer {
public:
    Renderer(sf::Vector2i renderer);
    void drawMap(const GameState& gameState, sf::RenderWindow& window, sf::Vector2i playerPosition);
    void drawEntities(const std::vector<std::unique_ptr<Entity>>& entities, sf::RenderWindow& window);
private:
    sf::Vector2i m_size;
    std::vector<sf::RectangleShape> m_grid;
};