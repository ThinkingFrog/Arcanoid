#include "ChangeBarSizeBonus.h"

ChangeBarSizeBonus::ChangeBarSizeBonus(float x, float y, float radius, float ySpeed) : Bonus(x, y, radius, ySpeed) { 
    color = sf::Color::Cyan; 
    type = change_bar_size;
    sizeChange = BAR_SIZE_POSSIBLE_CHANGE;
}

void ChangeBarSizeBonus::Trigger(std::shared_ptr <Field> field, std::shared_ptr <Bar> bar, std::shared_ptr <Ball> ball) {
    switch (rand() % 2) {
    case 0:
        bar->SetWidth(bar->GetWidth() * sizeChange);
        break;
    case 1:
        bar->SetWidth(bar->GetWidth() / sizeChange);
        break;
    }
}