#pragma once
#include <vector>
#include <memory>
#include "Bonus.h"

class ActiveBonuses {
private:
    std::vector <std::shared_ptr <Bonus>> bonusesArray;
public:
    ActiveBonuses() {}
    ~ActiveBonuses() {}

    void AddRandomBonus(float x, float y, float radius, float speed);
    void Draw(std::shared_ptr <sf::RenderWindow> window);
    void MoveAll(std::shared_ptr <Bar> bar, std::shared_ptr <Field> field, std::shared_ptr <Ball> ball);
};