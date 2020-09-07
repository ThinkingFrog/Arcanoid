#pragma once
#include "Bonus.h"

/**
*Allows ball to reflect from bottom of the screen once
*/
class BottomReflectionBonus : public Bonus {
public:
    /**Default constructor*/
    BottomReflectionBonus(float x, float y, float radius, float ySpeed);    

    /**Default destructor*/
    ~BottomReflectionBonus() {}

    /**
    *Sets ball's special 'bottom reflection' value to true
    */
    void Trigger(std::shared_ptr <Field> field, std::shared_ptr <Bar> bar, std::shared_ptr <Ball> ball) override;   
};