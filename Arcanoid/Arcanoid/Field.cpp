#include "Field.h"
#include "Main.h"
#include "UnbreakableBrick.h"
#include "SpeedingBrick.h"
#include "BonusBrick.h"
#include "MovingBrick.h"

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
        for (unsigned j = 0; j < bricksInRow; j++) {
            std::shared_ptr <Brick> brick;

            if (rand() % 100 < UNBREAKABLE_CHANCE)
                brick = std::make_shared <UnbreakableBrick>(j * (float)fieldWidth / bricksInRow, startingY + i * (float)fieldHeight / bricksInColumn, (float)fieldWidth / bricksInRow, (float)fieldHeight / bricksInColumn);
            else if (rand() % 100 < SPEEDING_CHANCE)
                brick = std::make_shared <SpeedingBrick>(j * (float)fieldWidth / bricksInRow, startingY + i * (float)fieldHeight / bricksInColumn, (float)fieldWidth / bricksInRow, (float)fieldHeight / bricksInColumn);
            else if (rand() % 100 < BONUS_CHANCE)
                brick = std::make_shared <BonusBrick>(j * (float)fieldWidth / bricksInRow, startingY + i * (float)fieldHeight / bricksInColumn, (float)fieldWidth / bricksInRow, (float)fieldHeight / bricksInColumn);
            else
                brick = std::make_shared<Brick>(j * (float)fieldWidth / bricksInRow, startingY + i * (float)fieldHeight / bricksInColumn, (float)fieldWidth / bricksInRow, (float)fieldHeight / bricksInColumn);
            
            bricksArray.push_back(brick);
        }
}

void Field::Draw(std::shared_ptr <sf::RenderWindow> window) {
    for (auto brick : bricksArray)
        brick->Draw(window, colorsForLevels);
}

std::vector<std::shared_ptr<Brick>> Field::GetBricksArray() {
    return bricksArray;
}

void Field::ReduceBrickLevel(unsigned num) {
    bricksArray[num]->ReduceLevel();
    if (bricksArray[num]->GetLevel() == 0)
        bricksArray.erase(bricksArray.begin() + num);
}

void Field::MoveAll() {
    for (auto& brick : bricksArray)
        brick->Move();
}

void Field::AddMovingBrick() {
    std::shared_ptr <Brick> brick = std::make_shared <MovingBrick>((float)(rand() % (int)fieldWidth), startingY + fieldHeight * (float)1.05, (float)fieldWidth / bricksInRow, (float)fieldHeight / bricksInColumn);
        bricksArray.push_back(brick);
}