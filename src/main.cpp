#include "Map.hpp"
#include "MapLoader.hpp"
#include "Renderer.hpp"
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window;
    window.create(sf::VideoMode({1920, 1080}), "Roguelike");

    Map map = MapLoader::load("assets/testMap.txt");
    Renderer renderer(32, 18);

    while (window.isOpen())
    {
        window.clear(sf::Color::Magenta);
        renderer.drawMap(map, window);
        window.display();

        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }
    }
}