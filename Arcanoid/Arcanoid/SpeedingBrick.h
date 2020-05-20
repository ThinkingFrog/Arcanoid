#pragma once
#include "Brick.h"
#include "Ball.h"

class SpeedingBrick : public Brick {
private:
    float xAcc, yAcc;
public:
    SpeedingBrick(float x, float y, float width, float height);
    ~SpeedingBrick() {}
    sf::Vector2f Accelerate() override;
};

