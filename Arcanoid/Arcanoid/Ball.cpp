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
    sticked = false;
    reflectBottom = false;
}

void Ball::Draw(std::shared_ptr <sf::RenderWindow> window) {
    sf::CircleShape shape(radius);
    shape.setPosition(x, y);
    shape.setFillColor(color);

    window->draw(shape);
}

void Ball::Move() {
    if (sticked) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            if (x >= 0)
                x -= BAR_X_SPEED;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            if (x + 2 * radius <= defaultWindowWidth)
                x += BAR_X_SPEED;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            sticked = false;
    }
    else {
        x += xDirect * xSpeed;
        y += yDirect * ySpeed;
    }
}

void Ball::Reset() {
    x = xStart;
    y = yStart;
    xSpeed = BALL_X_SPEED;
    ySpeed = BALL_Y_SPEED;
    xDirect = BALL_X_DIRECTION;
    yDirect = BALL_Y_DIRECTION;
}

float Ball::GetYPos() {
    return y;
}

float Ball::GetXPos() {
    return x;
}

float Ball::GetRadius() {
    return radius;
}

void Ball::Accelerate(float x, float y) {
    if (xSpeed > x && ySpeed > y || x > 0 && y > 0) {
        xSpeed += x;
        ySpeed += y;
    }
}

void Ball::SetBottomReflection(bool reflection) {
    reflectBottom = reflection;
}

bool Ball::GetBottomReflection() {
    return reflectBottom;
}

void Ball::SetColor(sf::Color color) {
    this->color = color;
}