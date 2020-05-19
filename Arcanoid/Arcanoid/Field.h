#pragma once
#include <vector>
#include <array>
#include "Brick.h"
#include "Main.h"

class Field {
private:
    unsigned bricksInRow, bricksInColumn;
    float startingY, fieldWidth, fieldHeight;
    std::vector <Brick> bricksArray;
    const std::array <sf::Color, MAX_BRICK_LEVEL> colorsForLevels = { sf::Color::Green, sf::Color::Red, sf::Color::Yellow, sf::Color::Magenta };
public:
    Field(unsigned bricksInRow, unsigned bricksInColumn, float startingY, float fieldWidth, float fieldHeight);
    void GenerateField(void);
    void Draw(std::shared_ptr <sf::RenderWindow> window);
    ~Field() {};
};

