#pragma once
#include <SFML/Graphics.hpp>
#include "Main.h"
#include "Bar.h"
#include "Field.h"
#include "Ball.h"

/**
*Base abstract class for all bonus types
*
*Defines common for all derived classes methods that draw bonus, move it down and check if it was caught
*
*Trigger method should be defined by each bonus separately
*/
class Bonus {
protected:
    float x, y; /**Current coordinates*/
    float ySpeed;   /**Falling speed*/
    float radius;   /**Size*/
    sf::Color color;    /**Bonus color*/
    BONUS_TYPE type;    /**Bonus type from special enum list*/
public:
    /**
    *Default constructor
    *
    *Sets coordinates, size and speed of bonus. Color and type get set by each bonus separately in its own constructor
    */
    Bonus(float x, float y, float radius, float ySpeed);

    /**
    *Default destructor
    */
    virtual ~Bonus() {}

    /**
    *Draw bonus in specified window
    */
    void Draw(std::shared_ptr <sf::RenderWindow> window);

    /**
    *Move bonus by Y axis accordingly to its speed
    */
    void Move();

    /**
    *Pure virtual function specified by each bonus
    */
    void virtual Trigger(std::shared_ptr <Field> field, std::shared_ptr <Bar> bar, std::shared_ptr <Ball> ball) = 0;
    
    /**
    *Check if bonus contacted with bar
    *
    *Return true if bonus is inside bar and false if not
    */
    bool CaughtByBar(std::shared_ptr <Bar> bar);
    
    /**
    *Return current y coordinate
    */
    float GetYPos();
};