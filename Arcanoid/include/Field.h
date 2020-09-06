#pragma once
#include <vector>
#include <array>
#include "Brick.h"
#include "Main.h"

class Field {
private:
    unsigned bricksInRow, bricksInColumn;   /**Size in bricks*/
    float fieldWidth, fieldHeight;   /*Size in pixels*/
    float startingY; /*Left upper point of field in pixels*/
    std::vector <std::shared_ptr<Brick>> bricksArray;   /**Vector of all bricks on field*/
    const std::array <sf::Color, MAX_BRICK_LEVEL> colorsForLevels = { sf::Color::Green, sf::Color::Yellow, sf::Color::Red };    /**Array of colors matching to bricks levels*/
public:
    Field(unsigned bricksInRow, unsigned bricksInColumn, float startingY, float fieldWidth, float fieldHeight);
    ~Field() {};
    
    /**Place random bricks of random type and level to vector*/
    void GenerateField(void);

    /**Call Draw() method for each brick*/
    void Draw(std::shared_ptr <sf::RenderWindow> window);   

    /**Call Move() method for every brick*/
    void MoveAll(); 
    
    /**Returns brickArray*/
    std::vector <std::shared_ptr<Brick>> GetBricksArray(); 

    /**Call ReduceLevel() method for a brick with given index*/
    void ReduceBrickLevel(unsigned num);    

    /**Add a moving brick on the bottom line under all stationary bricks with random X coordinates*/
    void AddMovingBrick();

    /**
    *Check if X coordinate for a new moving brick doesn't interupt with any other bricks or window edges
    */
    bool CheckXForNewMoving(float x, float y);
    
    /**Check if only bricks left in array are unbreakable ones*/
    bool CheckForGameEnd(); 

    /**Check if any moving bricks ran into each other and turn them into different directions*/
    void CheckForCollisionsBetweenBricks(); 
};

