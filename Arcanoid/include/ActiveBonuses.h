#pragma once
#include <vector>
#include <memory>
#include "Bonus.h"

/**
*Class containing all currently active bonuses
*
*Bonuses are stored in a vector of pointers
*
*Class contains all methods to interact with this vector
*/
class ActiveBonuses {
private:
    std::vector <std::shared_ptr <Bonus>> bonusesArray; /**Vector of bonuses*/
public:
    /**Default constructor*/
    ActiveBonuses() {}  

    /**Default destructor*/
    ~ActiveBonuses() {} 

    /**
    *Add new element of random type chosen by (rand() % bonus_types_amount)
    */
    void AddRandomBonus(float x, float y, float radius, float speed);

    /**
    *Draw all objects in the vector by calling Draw() method for them
    */
    void Draw(std::shared_ptr <sf::RenderWindow> window);

    /**
    *Move all objects in the vector by calling Move() method for them
    */
    void MoveAll(std::shared_ptr <Bar> bar, std::shared_ptr <Field> field, std::shared_ptr <Ball> ball);
};