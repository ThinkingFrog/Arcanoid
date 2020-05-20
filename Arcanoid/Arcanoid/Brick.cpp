#include <array>
#include "Brick.h"
#include "Main.h"

Brick::Brick(float x, float y, float width, float height) {
    this->x = x;
    this->y = y;
    level = rand() % MAX_BRICK_LEVEL + 1;
    this->width = width;
    this->height = height;
    type = casual;
}

void Brick::Draw(std::shared_ptr<sf::RenderWindow> window, const std::array <sf::Color, MAX_BRICK_LEVEL> colorsForLevels) {
    float outlineSize = (float)(-(width + height) / 2 * 0.035);

    sf::RectangleShape shape(sf::Vector2f(width, height));
    shape.setPosition(x, y);
    if (type == unbreakable)
        shape.setFillColor(sf::Color::White);
    else if (type == speeding)
        shape.setFillColor(sf::Color::Magenta);
    else
        shape.setFillColor(colorsForLevels[level - 1]);
    shape.setOutlineThickness(outlineSize);
    shape.setOutlineColor(sf::Color::Black);

    window->draw(shape);
}

float Brick::GetXPos() {
    return x;
}

float Brick::GetYPos() {
    return y;
}

float Brick::GetWidth() {
    return width;
}

float Brick::GetHeight() {
    return height;
}

void Brick::ReduceLevel() {
    --level;
}

int Brick::GetLevel() {
    return level;
}

BRICK_TYPE Brick::GetType() {
    return type;
}