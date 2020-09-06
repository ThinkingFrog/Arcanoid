#pragma once
#include <SFML/Graphics.hpp>
#include "Bar.h"
#include "Field.h"

/**
*Ball object class
*
*Performs all operations on ball such as movement, drawing, reflection from walls and so on
*/
class Ball {
private:
    float xStart, yStart;   /**Starting coords*/
    sf::CircleShape *ball;

    float xSpeed, ySpeed;   /**Speed on both axises*/
    int xDirect, yDirect;   /**Direction either 1 or -1*/

    bool sticked;   /**Stays sticked to bar once*/
    bool reflectBottom; /**Reflects from bottom of the screen once*/
    bool randomReflection;  /**Randomly changes direction once*/


public:
    /**Default constructor*/
    Ball(float x, float y, float radius);   
    
    /**Default desctructor*/
    ~Ball();
    
    /**Draw ball in given window*/
    void Draw(std::shared_ptr <sf::RenderWindow> window); 
    
    /**
    *Move accordingly to speed and direction on both axises
    *
    *Also includes operation of moving simultaneously with bar
    */
    void Move();    
    
    /**
    *Return to starting coordinates with default speed
    */
    void Reset();

    /**
    *Increase speed by x and y
    */
    void Accelerate(float x, float y);

    /**
    *Operation of moving simultaneously with bar
    */
    void MoveWithBar();

    void SetBottomReflection(bool reflection);
    void SetColor(sf::Color color);
    void SetRandomReflection(bool reflection);

    /**
    *Change direction at random time once
    */
    void RandomlyReflect();

    /**
    *Reflect from a bar if bump into its top side
    */
    void ReflectBar(std::shared_ptr <Bar> bar);

    /**
    *Reflect from sidewalls, ceil and, if reflectBottom == true, floor
    */
    void ReflectWall();

    /**
    *Reflect from an any type brick
    */
    bool ReflectFromBrick(std::shared_ptr <Brick> brick);

    bool GetBottomReflection();
    float GetYPos();
    float GetXPos();
    float GetRadius();
};

