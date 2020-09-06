#pragma once
#include "Bonus.h"

/**
*Allows ball to randomly change direction once with a chance on each frame specified in 'Main.h'
*/
class RandomDirectionBonus : public Bonus {
public:
    /**Default constructor*/
    RandomDirectionBonus(float x, float y, float radius, float ySpeed); 

    /**Default destructor*/
    ~RandomDirectionBonus() {}  

    /**
    *Sets ball's special 'random reflection' field to true
    */
    void Trigger(std::shared_ptr <Field> field, std::shared_ptr <Bar> bar, std::shared_ptr <Ball> ball);
};