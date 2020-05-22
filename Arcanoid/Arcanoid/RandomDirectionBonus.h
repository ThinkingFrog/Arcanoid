#pragma once
#include "Bonus.h"
class RandomDirectionBonus : public Bonus {
public:
    RandomDirectionBonus(float x, float y, float radius, float ySpeed);
    ~RandomDirectionBonus() {}
    void Trigger(std::shared_ptr <Field> field, std::shared_ptr <Bar> bar, std::shared_ptr <Ball> ball);
};