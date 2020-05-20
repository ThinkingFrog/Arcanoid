#include <array>
#include "UnbreakableBrick.h"

UnbreakableBrick::UnbreakableBrick(float x, float y, float width, float height) : Brick(x, y, width, height) {
    level = -1;
    type = unbreakable;
}

void UnbreakableBrick::ReduceLevel() {
    level = level;
}