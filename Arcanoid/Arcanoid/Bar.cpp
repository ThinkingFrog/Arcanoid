#include "Bar.h"

Bar::Bar(float x, float y, float width, float height) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    color = sf::Color::Blue;
}

void Bar::Draw(std::shared_ptr <sf::RenderWindow> window) {
    sf::RectangleShape shape(sf::Vector2f(width, height));
    shape.setPosition(x, y);
    shape.setFillColor(color);

    window->draw(shape);
}