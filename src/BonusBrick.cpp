#include "BonusBrick.h"

BonusBrick::BonusBrick(float x, float y, float width, float height) : Brick(x, y, width, height) {
    type = with_bonus;
}