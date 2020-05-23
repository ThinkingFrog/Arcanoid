#pragma once
#include "Brick.h"

class UnbreakableBrick : public Brick {
public:
    UnbreakableBrick(float x, float y, float width, float height);
    ~UnbreakableBrick() {}
    void ReduceLevel() override;
};

