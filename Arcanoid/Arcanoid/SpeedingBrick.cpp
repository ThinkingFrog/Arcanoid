#include "SpeedingBrick.h"
#include "Main.h"

SpeedingBrick::SpeedingBrick(float x, float y, float width, float height) : Brick(x, y, width, height) {
    level = 1;
    type = speeding;
    xAcc = SPEEDING_BRICK_X_ACCELERATION;
    yAcc = SPEEDING_BRICK_Y_ACCELERATION;
}

sf::Vector2f SpeedingBrick::Accelerate() {
    return { xAcc, yAcc };
}