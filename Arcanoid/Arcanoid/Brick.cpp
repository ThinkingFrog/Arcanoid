#include <array>
#include "Brick.h"
#include "Main.h"

Brick::Brick(float x, float y, float width, float height) {
    this->x = x;
    this->y = y;
    level = rand() % MAX_BRICK_LEVEL + 1;
    this->width = width;
    this->height = height;
}

void Brick::Draw(std::shared_ptr<sf::RenderWindow> window, const std::array <sf::Color, MAX_BRICK_LEVEL> colorsForLevels) {
    float outlineSize = (float)(-(width + height) / 2 * 0.035);

    sf::RectangleShape shape(sf::Vector2f(width, height));
    shape.setPosition(x, y);
    shape.setFillColor(colorsForLevels[level - 1]);
    shape.setOutlineThickness(outlineSize);
    shape.setOutlineColor(sf::Color::Black);

    window->draw(shape);
}
