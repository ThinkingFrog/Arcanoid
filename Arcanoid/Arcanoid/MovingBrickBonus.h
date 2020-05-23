#pragma once
#include "Bonus.h"
class MovingBrickBonus : public Bonus {
public:
    MovingBrickBonus(float x, float y, float radius, float ySpeed);
    ~MovingBrickBonus() {}
    void Trigger(std::shared_ptr <Field> field, std::shared_ptr <Bar> bar, std::shared_ptr <Ball> ball);
};

