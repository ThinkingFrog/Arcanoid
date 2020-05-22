#include "Bonus.h"

Bonus::Bonus(float x, float y, float radius, float ySpeed) {
    this->x = x;
    this->y = y;
    this->radius = radius;
    this->ySpeed = ySpeed;
}

void Bonus::Draw(std::shared_ptr <sf::RenderWindow> window) {
    sf::CircleShape shape(radius);
    shape.setPosition(x, y);
    shape.setFillColor(color);

    window->draw(shape);
}

void Bonus::Move() {
    y += ySpeed;
}

bool Bonus::CaughtByBar(std::shared_ptr <Bar> bar) {
    return y + 2 * radius >= bar->GetYPos() && y <= bar->GetYPos() + bar->GetHeight() && (x >= bar->GetXPos() && x <= bar->GetXPos() + bar->GetWidth());
}

float Bonus::GetYPos() {
    return y;
}