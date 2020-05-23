#pragma once
#include "Brick.h"
class MovingBrick : public Brick {
private:
    float xSpeed;
    int xDirection;
public:
    MovingBrick(float x, float y, float width, float height);
    ~MovingBrick() {}
    void Move() override;
};

