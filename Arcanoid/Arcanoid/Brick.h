#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include "Main.h"

/**
*Base class for all bricks on the field
*
*By default has 3 health levels signed randomly in constructor and colors set accordingly, but level and color can be set manually
*/
class Brick {
protected:
    float x, y; /**Current coordinates*/
    int level;  /**Current level*/
    float width, height;    /**Sizes*/
    BRICK_TYPE type;    /**Type specified by enum*/
    sf::Color color;    /**Color, transparent by default*/

    int xDirection; /**Movement direction, only needed for moving brick and SetDirection() method*/
public:
    /**Default constructor setting coords and sizes*/
    Brick(float x, float y, float width, float height); 

    /**Default destructor*/
    virtual ~Brick() {} 

    /**
    *Draw brick in specified window using it's color or an array of colors matching bricks levels
    */
    void Draw(std::shared_ptr <sf::RenderWindow> window, const std::array <sf::Color, MAX_BRICK_LEVEL> colorsForLevels);

    /**
    *Method drops brick level by 1
    *
    *May be overriden in derived classes
    */
    void virtual ReduceLevel();
    
    /**
    *Virtual function needed for speeding bricks
    *
    *Return an sf::Vector2f object with x and y accelerations
    */
    sf::Vector2f virtual Accelerate() { return { 0, 0 }; }

    /**
    *Virtual function needed for moving bricks
    */
    void virtual Move() {}

    /**Get x coordinate*/
    float GetXPos();   

    /**Get y coordinate*/
    float GetYPos();   

    /**Get horizontal size*/
    float GetWidth();   

    /**Get vertical size*/
    float GetHeight();  

    /**Get current level*/
    int GetLevel();     

    /**Get brick type as a BRICK_TYPE enum*/
    BRICK_TYPE GetType();   

    /**Set xDirection to either 1 or -1*/
    void SetDirection(int direct);  
};

