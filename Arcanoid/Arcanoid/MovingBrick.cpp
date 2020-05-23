#include "MovingBrick.h"

MovingBrick::MovingBrick(float x, float y, float width, float height) : Brick(x, y, width, height) {
    level = 3;
    type = moving;
    xSpeed = MOVING_BRICK_X_SPEED;
    xDirection = rand() % 2 == 0 ? 1 : -1;
}

void MovingBrick::Move() {
    if (x <= 0 || x + width >= defaultWindowWidth)
        xDirection *= -1;
    x += xDirection * xSpeed;
}