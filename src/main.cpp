#include "Map.hpp"
#include "Renderer.hpp"
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window;
    window.create(sf::VideoMode({1280, 1080}), "Roguelike");

    Map map = Map(128, 108);
    Renderer renderer = Renderer(128, 108);

    while (window.isOpen())
    {
        window.clear();
        renderer.drawMap(map, window);
        window.display();

        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }
    }
}