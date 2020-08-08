#include "MovingBrick.h"

MovingBrick::MovingBrick(float x, float y, float width, float height) : Brick(x, y, width, height) {
    level = 3;
    type = moving;
    xSpeed = MOVING_BRICK_X_SPEED;
    xDirection = rand() % 2 == 0 ? 1 : -1;
}

void MovingBrick::Move() {
    if (brick->getPosition().x <= 0 || brick->getPosition().x + brick->getSize().x >= defaultWindowWidth)
        xDirection *= -1;
    brick->move({ xDirection * xSpeed , 0});
}