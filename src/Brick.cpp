#include <array>
#include "Brick.h"
#include "Main.h"

Brick::Brick(float x, float y, float width, float height) {
    brick = new sf::RectangleShape({ width, height });
    brick->setPosition(x, y);

    level = rand() % MAX_BRICK_LEVEL + 1;
    type = casual;
    color = sf::Color::Transparent;
}

Brick::~Brick() {
    delete brick;
}

void Brick::Draw(std::shared_ptr<sf::RenderWindow> window, const std::array <sf::Color, MAX_BRICK_LEVEL> colorsForLevels) {
    float outlineSize = (float)(-(brick->getSize().x + brick->getSize().y) / 2 * 0.035);

    if (color != sf::Color::Transparent)
        brick->setFillColor(color);
    else
        brick->setFillColor(colorsForLevels[level - 1]);
    brick->setOutlineThickness(outlineSize);
    brick->setOutlineColor(sf::Color::Black);

    window->draw(*brick);
}

float Brick::GetXPos() {
    return brick->getPosition().x;
}

float Brick::GetYPos() {
    return brick->getPosition().y;
}

float Brick::GetWidth() {
    return brick->getSize().x;
}

float Brick::GetHeight() {
    return brick->getSize().y;
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

void Brick::SetDirection(int direct) {
    if (direct == 1 || direct == -1)
        xDirection = direct;
}
