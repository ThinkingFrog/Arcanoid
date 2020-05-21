#pragma once
#include <SFML/Graphics.hpp>
#include "Bar.h"
#include "Field.h"

class Ball {
private:
    float xStart, yStart;
    float x, y;
    float radius;
    sf::Color color;

    float xSpeed, ySpeed;
    int xDirect, yDirect;
public:
    Ball(float x, float y, float radius);
    ~Ball() {}
    
    void Draw(std::shared_ptr <sf::RenderWindow> window);
    void Move();
    void Reset();
    void Accelerate(float x, float y);

    void ReflectBar(std::shared_ptr <Bar> bar);
    void ReflectWall();
    bool ReflectFromBrick(std::shared_ptr <Brick> brick);

    float GetYPos();
    float GetXPos();
    float GetRadius();
};

