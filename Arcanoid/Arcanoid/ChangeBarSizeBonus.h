#pragma once
#include "Bonus.h"

/**
*Randomly multiply or divide bar's size by value specified in 'Main.h'
*/
class ChangeBarSizeBonus : public Bonus {
private:
    float sizeChange;
public:
    /**Default constructor*/
    ChangeBarSizeBonus(float x, float y, float radius, float ySpeed);   
    
    /**Default destructor*/
    ~ChangeBarSizeBonus() {}    

    /**
    *Calls bar's method to set width
    */
    void Trigger(std::shared_ptr <Field> field, std::shared_ptr <Bar> bar, std::shared_ptr <Ball> ball) override;
};

