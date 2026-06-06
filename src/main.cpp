#include "GameState.hpp"
#include "Renderer.hpp"
#include "PlayerController.hpp"
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

int main()
{
    sf::RenderWindow window;
    window.create(sf::VideoMode({1920, 1080}), "Roguelike");

    GameState gameState("assets/testMap.txt");
    Renderer renderer(sf::Vector2i{32, 18});

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }

            PlayerController::handleInput(*event, gameState);
        }

        window.clear(sf::Color::Magenta);
        renderer.drawMap(gameState.map, window);
        renderer.drawEntities(gameState.entities, window);
        window.display();
    }
}