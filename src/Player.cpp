#include "Player.hpp"

Player::Player(sf::Vector2i position, int size, sf::Color color)
    : Entity(position,size, color)
{
}

Player::~Player() {}