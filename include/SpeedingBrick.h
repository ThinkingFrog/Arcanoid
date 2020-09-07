#pragma once
#include "Brick.h"
#include "Ball.h"

class SpeedingBrick : public Brick {
private:
    float xAcc, yAcc;
public:
    SpeedingBrick(float x, float y, float width, float height);
    ~SpeedingBrick() {}

    /**Overrides default acceleration method to return xAcc and yAcc fields*/
    sf::Vector2f Accelerate() override; 
};

