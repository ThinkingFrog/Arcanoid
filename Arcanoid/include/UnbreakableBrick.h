#pragma once
#include "Brick.h"

class UnbreakableBrick : public Brick {
public:
    UnbreakableBrick(float x, float y, float width, float height);
    ~UnbreakableBrick() {}

    /**Overrides default level reduction to do nothing*/
    void ReduceLevel() override;    
};

