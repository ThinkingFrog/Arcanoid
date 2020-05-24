#pragma once
#include "Bonus.h"

/**
*Allows ball to stick to bar once
*/
class StickyBarBonus : public Bonus {
public:
    /**Default constructor*/
    StickyBarBonus(float x, float y, float radius, float ySpeed);   

    /**Default destructor*/
    ~StickyBarBonus() {}    

    /**
    *Sets ball's special 'sticking' field to true
    */
    void Trigger(std::shared_ptr <Field> field, std::shared_ptr <Bar> bar, std::shared_ptr <Ball> ball) override;
};

