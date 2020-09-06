#include "MovingBrickBonus.h"

MovingBrickBonus::MovingBrickBonus(float x, float y, float radius, float ySpeed) : Bonus(x, y, radius, ySpeed) {
    bonus->setFillColor(sf::Color::Green);
}

void MovingBrickBonus::Trigger(std::shared_ptr<Field> field, std::shared_ptr<Bar> bar, std::shared_ptr<Ball> ball) {
    field->AddMovingBrick();
}