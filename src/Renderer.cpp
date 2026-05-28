#include "Renderer.hpp"

Renderer::Renderer(int width, int height)
    : m_width(width)
    , m_height(height)
    , m_grid(width * height)
{
    for (int y = 0; y < m_height; y++) {
        for (int x = 0; x < m_width; x++) {
            sf::RectangleShape& rect = m_grid[y * m_width + x];

            rect.setPosition(sf::Vector2f(x * TILE_SIZE, y * TILE_SIZE));
            rect.setSize(sf::Vector2f(TILE_SIZE, TILE_SIZE));
        }
    }
}

void Renderer::drawMap(const Map& map, sf::RenderWindow& window) {
    for (int y = 0; y < m_height; y++) {
        for (int x = 0; x < m_width; x++) {
            const Tile& tile = map.getTile(x, y);
            sf::RectangleShape& rect = m_grid[y * m_width + x];

            sf::Color color = getTileData(tile.type).color;
            rect.setFillColor(color);

            window.draw(rect);
        }
    }
}