#pragma once
#include <SFML/Graphics.hpp>
#include "Main.h"
#include "Bar.h"
#include "Field.h"
#include "Ball.h"

class Bonus {
protected:
    float x, y;
    float ySpeed;
    float radius;
    sf::Color color;
    BONUS_TYPE type;
public:
    Bonus(float x, float y, float radius, float ySpeed);
    ~Bonus() {}

    void Draw(std::shared_ptr <sf::RenderWindow> window);
    void Move();
    void virtual Trigger(std::shared_ptr <Field> field, std::shared_ptr <Bar> bar, std::shared_ptr <Ball> ball) = 0;
    
    bool CaughtByBar(std::shared_ptr <Bar> bar);
    
    float GetYPos();
    
};