#include "Renderer.hpp"

#include <SFML/System.hpp>

Renderer::Renderer(sf::Vector2i size)
    : m_size(size)
    , m_grid(size.x * size.y)
{
    int width = m_size.x;
    int height = m_size.y;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            sf::RectangleShape& rect = m_grid[y * width + x];

            rect.setPosition(sf::Vector2f(x * TILE_SIZE, y * TILE_SIZE));
            rect.setSize(sf::Vector2f(TILE_SIZE, TILE_SIZE));
        }
    }
}

void Renderer::drawMap(const Map& map, sf::RenderWindow& window) {
    int width = m_size.x;
    int height = m_size.y;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            const Tile& tile = map.getTile(sf::Vector2i{x, y});
            sf::RectangleShape& rect = m_grid[y * width + x];

            sf::Color color = getTileData(tile.type).color;
            rect.setFillColor(color);

            window.draw(rect);
        }
    }
}

void Renderer::drawEntities(const std::vector<std::unique_ptr<Entity>>& entities, sf::RenderWindow& window ) {
    for (const auto& entity : entities) {
        int size = entity->getSize() * TILE_SIZE / 2;
        sf::CircleShape sprite(size);
        
        sf::Vector2f position = sf::Vector2f(entity->getPosition()) * static_cast<float>(TILE_SIZE);
        sprite.setPosition(position);

        sprite.setFillColor(entity->getColor());

        window.draw(sprite);
    }
}