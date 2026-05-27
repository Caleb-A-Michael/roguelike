#include <SFML/Window.hpp>

int main()
{
    sf::Window window;
    window.create(sf::VideoMode({800, 600}), "Roguelike");

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }
    }
}