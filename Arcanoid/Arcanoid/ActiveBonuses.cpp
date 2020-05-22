#include "ActiveBonuses.h"
#include "ChangeBarSizeBonus.h"
#include "ChangeBallSpeedBonus.h"
#include "StickyBarBonus.h"
#include "BottomReflectionBonus.h"
#include "RandomDirectionBonus.h"

void ActiveBonuses::Draw(std::shared_ptr <sf::RenderWindow> window) {
    for (auto bonus : bonusesArray)
        bonus->Draw(window);
}

void ActiveBonuses::AddRandomBonus(float x, float y, float radius, float speed) {
    std::shared_ptr <Bonus> bonus;
    switch (rand() % bonus_types_amount) {
    case change_bar_size:
        bonus = std::make_shared <ChangeBarSizeBonus>(x, y, radius, speed);
        break;
    case change_ball_speed:
        bonus = std::make_shared <ChangeBallSpeedBonus>(x, y, radius, speed);
        break;
    case sticky_bar:
        bonus = std::make_shared <StickyBarBonus>(x, y, radius, speed);
        break;
    case bottom_reflect:
        bonus = std::make_shared <BottomReflectionBonus>(x, y, radius, speed);
        break;
    case random_direction:
        bonus = std::make_shared <RandomDirectionBonus>(x, y, radius, speed);
        break;
    }
    bonusesArray.push_back(bonus);
}

void ActiveBonuses::MoveAll(std::shared_ptr <Bar> bar, std::shared_ptr <Field> field, std::shared_ptr <Ball> ball) {
    unsigned i = 0;
    for (auto bonus : bonusesArray) {
        bonus->Move();

        if (bonus->CaughtByBar(bar)) {
            bonus->Trigger(field, bar, ball);
            bonusesArray.erase(bonusesArray.begin() + i);
            break;
        }
        
        if (bonus->GetYPos() >= defaultWindowHeight) {
            bonusesArray.erase(bonusesArray.begin() + i);
            break;
        }
        
        i++;
    }
}