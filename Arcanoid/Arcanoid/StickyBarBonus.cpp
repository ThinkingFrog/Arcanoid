#include "StickyBarBonus.h"

StickyBarBonus::StickyBarBonus(float x, float y, float radius, float ySpeed) : Bonus(x, y, radius, ySpeed) {
    bonus->setFillColor(sf::Color::Cyan);
}

void StickyBarBonus::Trigger(std::shared_ptr<Field> field, std::shared_ptr<Bar> bar, std::shared_ptr<Ball> ball) {
    bar->SetColor(sf::Color::Magenta);
    bar->SetStick(true);
}

