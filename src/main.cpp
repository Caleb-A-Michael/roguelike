#include "GameState.hpp"
#include "Renderer.hpp"
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window;
    window.create(sf::VideoMode({1920, 1080}), "Roguelike");

    GameState gameState("assets/testMap.txt");
    Renderer renderer(32, 18);

    while (window.isOpen())
    {
        window.clear(sf::Color::Magenta);
        renderer.drawMap(gameState.map, window);
        renderer.drawEntities(gameState.entities, window);
        window.display();

        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }
    }
}