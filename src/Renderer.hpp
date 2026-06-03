#pragma once

#include "Map.hpp"
#include "Entity.hpp"
#include "SFML/Graphics.hpp"
#include <vector>

const int TILE_SIZE = 60;

class Renderer {
public:
    Renderer(int width, int height);
    void drawMap(const Map& map, sf::RenderWindow& window);
    void drawEntities(const std::vector<std::unique_ptr<Entity>>& entities, sf::RenderWindow& window);
private:
    int m_width;
    int m_height;
    std::vector<sf::RectangleShape> m_grid;
};