#include "Renderer.hpp"

#include "Entities/Object.hpp"
#include <SFML/System.hpp>
#include <algorithm>
#include <cassert>

Renderer::Renderer(sf::Vector2i size, sf::Vector2i bounds)
    : m_size(size)
    , m_bounds(bounds)
    , m_grid(size.x * size.y)
{
    assert(size.x <= bounds.x);
    assert(size.y <= bounds.y);

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

void Renderer::renderScene(sf::RenderWindow& window, const GameState& gameState) {
    drawMap(window, gameState.map);
    drawEntities(window, gameState.entities);
}

void Renderer::centerScreen(sf::Vector2i position) {
    sf::Vector2i offset{m_size.x / 2, m_size.y / 2};
    sf::Vector2i new_position = position - offset;

    m_position = {
        std::clamp(new_position.x, 0, m_bounds.x - m_size.x),
        std::clamp(new_position.y, 0, m_bounds.y - m_size.y)
    };
}

void Renderer::drawMap(sf::RenderWindow& window, const Map& map) {
    assert(m_position.x + m_size.x <= map.getSize().x);
    assert(m_position.y + m_size.y <= map.getSize().y);

    for (int y = 0; y < m_size.y; y++) {
        for (int x = 0; x < m_size.x; x++) {
            sf::RectangleShape& rect = m_grid[y * m_size.x + x];

            const Tile& tile = map.getTile(sf::Vector2i{x + m_position.x, y + m_position.y});

            sf::Color color = getTileData(tile.type).color;
            rect.setFillColor(color);

            window.draw(rect);
        }
    }
}

void Renderer::drawEntities(sf::RenderWindow& window, const std::vector<std::unique_ptr<Entity>>& entities) {
    for (const auto& entity : entities) {
        const sf::Vector2f size = sf::Vector2f(entity->getSize() * TILE_SIZE);
        std::unique_ptr<sf::Shape> shape;

        if (dynamic_cast<Creature*>(entity.get())) {
            shape = std::make_unique<sf::CircleShape>(size.x / 2);
        } else {
            shape = std::make_unique<sf::RectangleShape>(size);
        }
        
        sf::Vector2f position = sf::Vector2f(entity->getPosition()) * static_cast<float>(TILE_SIZE);
        shape->setPosition(position);

        shape->setFillColor(entity->getColor());

        window.draw(*shape);
    }
}