#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include "Main.h"

class Brick {
protected:
    float x, y;
    int level;
    float width, height;
    BRICK_TYPE type;
public:
    Brick(float x, float y, float width, float height);
    ~Brick() {}
    void Draw(std::shared_ptr <sf::RenderWindow> window, const std::array <sf::Color, MAX_BRICK_LEVEL> colorsForLevels);
    void virtual ReduceLevel();

    float GetXPos();
    float GetYPos();
    float GetWidth();
    float GetHeight();
    int GetLevel();
    BRICK_TYPE GetType();
};

