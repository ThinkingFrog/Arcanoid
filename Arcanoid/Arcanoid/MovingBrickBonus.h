#pragma once
#include "Bonus.h"

/**
*Spawns special level-3 brick that moves under all stationary bricks
*/
class MovingBrickBonus : public Bonus {
public:
    /**Default constructor*/
    MovingBrickBonus(float x, float y, float radius, float ySpeed); 

    /**Default destructor*/
    ~MovingBrickBonus() {} 

    /**
    *Calls field's method to spawn new moving block
    */
    void Trigger(std::shared_ptr <Field> field, std::shared_ptr <Bar> bar, std::shared_ptr <Ball> ball);
};

