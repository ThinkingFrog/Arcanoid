#pragma once
#include "Bonus.h"
class StickyBarBonus : public Bonus {
public:
    StickyBarBonus(float x, float y, float radius, float ySpeed);
    ~StickyBarBonus() {}
    void Trigger(std::shared_ptr <Field> field, std::shared_ptr <Bar> bar, std::shared_ptr <Ball> ball) override;
};

