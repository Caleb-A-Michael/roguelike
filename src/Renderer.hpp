#pragma once

#include "GameState.hpp"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

class Renderer {
public:
    Renderer(sf::Vector2i size, sf::Vector2i bounds);

    void renderScene(sf::RenderWindow& window, const GameState& gameState);
    void centerScreen(sf::Vector2i position);
private:
    static constexpr int TILE_SIZE = 80;

    void drawMap(sf::RenderWindow& window, const Map& map);
    void drawEntities(sf::RenderWindow& window, const std::vector<std::unique_ptr<Entity>>& entities);

    sf::Vector2i m_size;
    sf::Vector2i m_bounds;

    sf::Vector2i m_position;
    
    std::vector<sf::RectangleShape> m_grid;
};