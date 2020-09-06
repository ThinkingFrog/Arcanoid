#include "Bar.h"
#include "Main.h"

Bar::Bar(float x, float y, float width, float height) {
    bar = new sf::RectangleShape({ width, height });
    bar->setPosition(x, y);
    bar->setFillColor(sf::Color::Blue);
    xStart = x;
    yStart = y;
    xSpeed = BAR_X_SPEED;
    stick = false;
}

Bar::~Bar() {
    delete bar;
}

void Bar::Draw(std::shared_ptr <sf::RenderWindow> window) {
    window->draw(*bar);
}

void Bar::Move() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        if (bar->getPosition().x >= 0)
            bar->move({ -xSpeed, 0 });
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        if (bar->getPosition().x + bar->getSize().x <= defaultWindowWidth)
            bar->move({ xSpeed, 0 });
    if (stick)
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            bar->setFillColor(sf::Color::Blue);
            stick = false;
        }
}

float Bar::GetXPos() {
    return bar->getPosition().x;
}

float Bar::GetYPos() {
    return bar->getPosition().y;
}

float Bar::GetWidth() {
    return bar->getSize().x;
}

float Bar::GetHeight() {
    return bar->getSize().y;
}

void Bar::SetWidth(float width) {
    bar->setSize({ width, bar->getSize().y});
}

void Bar::SetColor(sf::Color color) {
    bar->setFillColor(color);
}

void Bar::Reset() {
    bar->setPosition(xStart, yStart);
}

void Bar::SetStick(bool stick) {
    this->stick = stick;
}

bool Bar::GetStick() {
    return stick;
}