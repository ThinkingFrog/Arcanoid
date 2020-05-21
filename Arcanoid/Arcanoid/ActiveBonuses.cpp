#include "ActiveBonuses.h"

void ActiveBonuses::Draw(std::shared_ptr <sf::RenderWindow> window) {
    for (auto bonus : bonusesArray)
        bonus->Draw(window);
}

void ActiveBonuses::AddRandomBonus(float x, float y, float radius, float speed) {
    std::shared_ptr <Bonus> bonus = std::make_shared <Bonus>(x, y, radius, speed);
    bonusesArray.push_back(bonus);
}

void ActiveBonuses::MoveAll(std::shared_ptr <Bar> bar, std::shared_ptr <Field> field, std::shared_ptr <Ball> ball) {
    unsigned i = 0;
    for (auto bonus : bonusesArray) {
        bonus->Move();
        if (bonus->CaughtByBar(bar)) {
            bonus->Trigger(field, bar, ball);
            bonusesArray.erase(bonusesArray.begin() + i);
        }
        i++;
    }
}