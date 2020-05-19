#include "Ball.h"

Ball::Ball(float x, float y, float radius) {
    this->x = x;
    this->y = y;
    this->radius = radius;
    color = sf::Color::White;
}

void Ball::Draw(std::shared_ptr <sf::RenderWindow> window) {
    sf::CircleShape shape(radius);
    shape.setPosition(x, y);
    shape.setFillColor(color);

    window->draw(shape);
}