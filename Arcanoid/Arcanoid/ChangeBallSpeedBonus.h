#pragma once
#include "Bonus.h"

/**
*Randomly increases or decreases ball's speed by value specified in 'Main.h'
*/
class ChangeBallSpeedBonus : public Bonus {
private:
    float speedChange;
public:
    /**Default constructor*/
    ChangeBallSpeedBonus(float x, float y, float radius, float ySpeed); 

    /**Default destructor*/
    ~ChangeBallSpeedBonus() {}  

    /**
    *Calls ball's speed changing method
    */
    void Trigger(std::shared_ptr <Field> field, std::shared_ptr <Bar> bar, std::shared_ptr <Ball> ball) override;
};

