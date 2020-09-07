#include "Bonus.h"

Bonus::Bonus(float x, float y, float radius, float ySpeed) {
    bonus = new sf::CircleShape(radius);
    bonus->setPosition(x, y);
    this->ySpeed = ySpeed;
}

Bonus::~Bonus() {
    delete bonus;
}

void Bonus::Draw(std::shared_ptr <sf::RenderWindow> window) {
    window->draw(*bonus);
}

void Bonus::Move() {
    bonus->move({0, ySpeed });
}

bool Bonus::CaughtByBar(std::shared_ptr <Bar> bar) {
    bool yLowerThanBarTop = bonus->getPosition().y + 2 * bonus->getRadius() >= bar->GetYPos();
    bool yHigherThanBarBottom = bonus->getPosition().y <= bar->GetYPos() + bar->GetHeight();
    bool xRightToBarLeft = bonus->getPosition().x >= bar->GetXPos();
    bool xLeftToBarRight = bonus->getPosition().x <= bar->GetXPos() + bar->GetWidth();
    return yLowerThanBarTop && yHigherThanBarBottom && xRightToBarLeft && xLeftToBarRight;
}

float Bonus::GetYPos() {
    return bonus->getPosition().y;
}