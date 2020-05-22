#pragma once
#include "Bonus.h"
class ChangeBallSpeedBonus : public Bonus {
private:
    float speedChange;
public:
    ChangeBallSpeedBonus(float x, float y, float radius, float ySpeed);
    ~ChangeBallSpeedBonus() {}
    void Trigger(std::shared_ptr <Field> field, std::shared_ptr <Bar> bar, std::shared_ptr <Ball> ball) override;
};

