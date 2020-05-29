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
            float brickWidth = (float)fieldWidth / bricksInRow;
            float brickHeight = (float)fieldHeight / bricksInColumn;
            float brickX = j * brickWidth;
            float brickY = startingY + i * brickHeight;
            
            if (rand() % 100 < UNBREAKABLE_CHANCE)
                brick = std::make_shared <UnbreakableBrick>(brickX, brickY, brickWidth, brickHeight);
            else if (rand() % 100 < SPEEDING_CHANCE)
                brick = std::make_shared <SpeedingBrick>(brickX, brickY, brickWidth, brickHeight);
            else if (rand() % 100 < BONUS_CHANCE)
                brick = std::make_shared <BonusBrick>(brickX, brickY, brickWidth, brickHeight);
            else
                brick = std::make_shared<Brick>(brickX, brickY, brickWidth, brickHeight);
            
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

bool Field::CheckXForNewMoving(float x, float y) {
    for (auto brick : bricksArray)
        if (brick->GetYPos() == y)
            if ((x + brick->GetWidth() >= brick->GetXPos() && x <= brick->GetXPos() + brick->GetWidth()) || (x + brick->GetWidth() >= defaultWindowWidth))
                return false;
    return true;
}

void Field::AddMovingBrick() {
    float xRand; 
    float yMoving = startingY + fieldHeight * (float)1.05;
    float brickWidth = (float)fieldWidth / bricksInRow;
    float brickHeight = (float)fieldHeight / bricksInColumn;

    do
        xRand = (float)(rand() % (int)fieldWidth);
    while (!CheckXForNewMoving(xRand, yMoving));
    std::shared_ptr <Brick> brick = std::make_shared <MovingBrick>(xRand, yMoving, brickWidth, brickHeight);
        bricksArray.push_back(brick);
}

bool Field::CheckForGameEnd() {
    for (auto brick : bricksArray)
        if (brick->GetType() != unbreakable)
            return false;
    return true;
}