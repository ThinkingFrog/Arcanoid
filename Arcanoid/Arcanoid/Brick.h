#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include "Main.h"

class Brick {
private:
    float x, y;
    int level;
    float width, height;
public:
    Brick(float x, float y, float width, float height);
    ~Brick() {}
    void Draw(std::shared_ptr <sf::RenderWindow> window, const std::array <sf::Color, MAX_BRICK_LEVEL> colorsForLevels);
    float GetXPos();
    float GetYPos();
    float GetWidth();
    float GetHeight();
    void ReduceLevel();
    int GetLevel();
};

