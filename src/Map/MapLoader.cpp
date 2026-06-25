#include "MapLoader.hpp"
#include <fstream>
#include <stdexcept>
#include <SFML/System.hpp>

Map MapLoader::load(const std::string& path) {
    std::ifstream file(path);

    if (!file.is_open()) {
        throw std::runtime_error("Could not open: " + path);
    }

    int width, height;
    file >> width >> height;
    file.ignore();

    Map map(sf::Vector2i{width, height});

    for (int y = 0; y < height; y++) {
        std::string line;
        std::getline(file, line);

        if (line.size() != static_cast<size_t>(width)) {
            throw std::runtime_error("Map row width mismatch on line " + std::to_string(y));
        }

        for (int x = 0; x < width; x++) {
            char c = line [x];
            TileType type;

            switch(c) {
                case '.': type = TileType::Floor; break;
                case '#': type = TileType::Wall; break;
                case '~': type = TileType::Water; break;
                default:
                    throw std::runtime_error("Unknown tile character: " + std::string(1, c));
            }

            map.getTile(sf::Vector2i{x, y}).type = type;
        }
    }

    return map;
}