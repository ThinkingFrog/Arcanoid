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
    void Reflect(std::shared_ptr<Bar> bar, std::shared_ptr<Field> field);
    void ReflectWall();
    void Reset();
    float GetYPos();
    float GetXPos();
    float GetRadius();
    void ReflectBar(std::shared_ptr <Bar> bar);
    bool ReflectFromBrick(Brick brick);
    void ReflectBricks(std::shared_ptr<Field> field);
};

