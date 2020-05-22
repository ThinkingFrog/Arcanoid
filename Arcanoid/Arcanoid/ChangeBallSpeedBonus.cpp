#include "ChangeBallSpeedBonus.h"

ChangeBallSpeedBonus::ChangeBallSpeedBonus(float x, float y, float radius, float ySpeed) : Bonus(x, y, radius, ySpeed) {
    color = sf::Color::Cyan;
    type = change_ball_speed;
    speedChange = BAR_SIZE_POSSIBLE_CHANGE;
}

void ChangeBallSpeedBonus::Trigger(std::shared_ptr <Field> field, std::shared_ptr <Bar> bar, std::shared_ptr <Ball> ball) {
    switch (rand() % 2) {
    case 0:
        ball->Accelerate(speedChange, speedChange);
        break;
    case 1:
        ball->Accelerate(-speedChange, -speedChange);
        break;
    }
}