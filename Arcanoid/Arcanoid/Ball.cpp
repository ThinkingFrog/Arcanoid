#include "Ball.h"
#include "Main.h"

Ball::Ball(float x, float y, float radius) {
    this->x = x;
    this->y = y;
    xStart = x;
    yStart = y;
    this->radius = radius;
    color = sf::Color::White;
    xSpeed = BALL_X_SPEED;
    ySpeed = BALL_Y_SPEED;
    xDirect = BALL_X_DIRECTION;
    yDirect = BALL_Y_DIRECTION;
}

void Ball::Draw(std::shared_ptr <sf::RenderWindow> window) {
    sf::CircleShape shape(radius);
    shape.setPosition(x, y);
    shape.setFillColor(color);

    window->draw(shape);
}

void Ball::Move() {
    if (y >= defaultWindowHeight)
        Reset();

    x += xDirect * xSpeed;
    y += yDirect * ySpeed;
}

void Ball::Reset() {
    x = xStart;
    y = yStart;
    xSpeed = BALL_X_SPEED;
    ySpeed = BALL_Y_SPEED;
    xDirect = BALL_X_DIRECTION;
    yDirect = BALL_Y_DIRECTION;
}

