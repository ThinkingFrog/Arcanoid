#pragma once
#include <SFML/Graphics.hpp>

class Ball {
private:
    float x, y;
    float radius;
    sf::Color color;
public:
    Ball(float x, float y, float radius);
    ~Ball() {}
    void Draw(std::shared_ptr <sf::RenderWindow> window);
};

