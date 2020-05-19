#include "Field.h"

Field::Field(unsigned bricksInRow, unsigned bricksInColumn, float startingY, float fieldWidth, float fieldHeight) {
    this->fieldWidth = fieldWidth;
    this->fieldHeight = fieldHeight;
    this->bricksInRow = bricksInRow;
    this->bricksInColumn = bricksInColumn;
    this->startingY = startingY;
    GenerateField();
}

void Field::GenerateField(void) {
    for (unsigned i = 0; i < bricksInColumn; i++)
        for (unsigned j = 0; j < bricksInRow; j++)
            bricksArray.push_back({j * (float)fieldWidth / bricksInRow, startingY + i * (float)fieldHeight / bricksInColumn, (float)fieldWidth / bricksInRow, (float)fieldHeight / bricksInColumn});
}

void Field::Draw(std::shared_ptr <sf::RenderWindow> window) {
    for (auto brick : bricksArray)
        brick.Draw(window, colorsForLevels);
}