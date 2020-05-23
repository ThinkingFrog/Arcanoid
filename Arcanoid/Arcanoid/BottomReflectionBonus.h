#pragma once
#include "Bonus.h"
class BottomReflectionBonus : public Bonus {
public:
    BottomReflectionBonus(float x, float y, float radius, float ySpeed);
    ~BottomReflectionBonus() {}
    void Trigger(std::shared_ptr <Field> field, std::shared_ptr <Bar> bar, std::shared_ptr <Ball> ball) override;
};