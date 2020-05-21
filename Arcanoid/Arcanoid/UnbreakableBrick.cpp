#include <array>
#include "UnbreakableBrick.h"

UnbreakableBrick::UnbreakableBrick(float x, float y, float width, float height) : Brick(x, y, width, height) {
    level = -1;
    type = unbreakable;
    color = sf::Color::White;
}

void UnbreakableBrick::ReduceLevel() {
    level = level;
}