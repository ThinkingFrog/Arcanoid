#include "Ball.h"
#include "Main.h"

Ball::Ball(float x, float y, float radius) {
    ball = new sf::CircleShape(radius);
    ball->setPosition(x, y);
    ball->setFillColor(sf::Color::White);
    xStart = x;
    yStart = y;
    
    xSpeed = BALL_X_SPEED;
    ySpeed = BALL_Y_SPEED;
    xDirect = BALL_X_DIRECTION;
    yDirect = BALL_Y_DIRECTION;

    sticked = false;
    reflectBottom = false;
    randomReflection = false;
}

Ball::~Ball() {
    delete ball;
}

void Ball::Draw(std::shared_ptr <sf::RenderWindow> window) {
    window->draw(*ball);
}

void Ball::MoveWithBar() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        if (ball->getPosition().x >= 0)
            ball->move({-BAR_X_SPEED, 0});
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        if (ball->getPosition().x + 2 * ball->getRadius() <= defaultWindowWidth)
            ball->move({ BAR_X_SPEED, 0 });
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        sticked = false;
}

void Ball::RandomlyReflect() {
    if (rand() % 100 < CHANCE_TO_RANDOM_REFLECT_ON_EACH_FRAME) {
        switch (rand() % 2) {
        case 0:
            yDirect *= -1;
            break;
        case 1:
            xDirect *= -1;
            break;
        }
        randomReflection = false;
    }
}

void Ball::Move() {
    if (sticked)
        MoveWithBar();
    else {
        if (randomReflection)
            RandomlyReflect();
            
        ball->move({ xDirect * xSpeed, yDirect * ySpeed });
    }
}

void Ball::Reset() {
    ball->setPosition(xStart, yStart);
    xSpeed = BALL_X_SPEED;
    ySpeed = BALL_Y_SPEED;
    xDirect = BALL_X_DIRECTION;
    yDirect = BALL_Y_DIRECTION;
}

float Ball::GetYPos() {
    return ball->getPosition().y;
}

float Ball::GetXPos() {
    return ball->getPosition().x;
}

float Ball::GetRadius() {
    return ball->getRadius();
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
    ball->setFillColor(color);
}

void Ball::SetRandomReflection(bool reflection) {
    randomReflection = reflection;
}