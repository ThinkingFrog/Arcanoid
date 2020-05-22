#include "RandomDirectionBonus.h"

RandomDirectionBonus::RandomDirectionBonus(float x, float y, float radius, float ySpeed) : Bonus(x, y, radius, ySpeed){
    color = sf::Color::Yellow;
    type = random_direction;
}

void RandomDirectionBonus::Trigger(std::shared_ptr<Field> field, std::shared_ptr<Bar> bar, std::shared_ptr<Ball> ball) {
    ball->SetRandomReflection(true);
}
