#pragma once
#include "Bonus.h"

class ChangeBarSizeBonus : public Bonus {
private:
    float sizeChange;
public:
    ChangeBarSizeBonus(float x, float y, float radius, float ySpeed);
    ~ChangeBarSizeBonus() {}
    void Trigger(std::shared_ptr <Field> field, std::shared_ptr <Bar> bar, std::shared_ptr <Ball> ball) override;
};

