#pragma once
#include <vector>
#include <array>
#include "Brick.h"
#include "Main.h"

class Field {
private:
    unsigned bricksInRow, bricksInColumn;
    float startingY, fieldWidth, fieldHeight;
    std::vector <std::shared_ptr<Brick>> bricksArray;
    const std::array <sf::Color, MAX_BRICK_LEVEL> colorsForLevels = { sf::Color::Green, sf::Color::Yellow, sf::Color::Red };
public:
    Field(unsigned bricksInRow, unsigned bricksInColumn, float startingY, float fieldWidth, float fieldHeight);
    ~Field() {};
    
    void GenerateField(void);
    void Draw(std::shared_ptr <sf::RenderWindow> window);
    void MoveAll();
    
    std::vector <std::shared_ptr<Brick>> GetBricksArray();
    void ReduceBrickLevel(unsigned num);
    void AddMovingBrick();

    bool CheckXForNewMoving(float x, float y);
    bool CheckForGameEnd();
    void CheckForCollisionsBetweenBricks();
};

