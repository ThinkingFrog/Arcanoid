#include "Field.h"
#include "Main.h"
#include "UnbreakableBrick.h"
#include "SpeedingBrick.h"

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
            Brick* brick;

            if (rand() % 100 < UNBREAKABLE_CHANCE)
                brick = new UnbreakableBrick(j * (float)fieldWidth / bricksInRow, startingY + i * (float)fieldHeight / bricksInColumn, (float)fieldWidth / bricksInRow, (float)fieldHeight / bricksInColumn);
            else if (rand() % 100 < SPEEDING_CHANCE)
                brick = new SpeedingBrick(j * (float)fieldWidth / bricksInRow, startingY + i * (float)fieldHeight / bricksInColumn, (float)fieldWidth / bricksInRow, (float)fieldHeight / bricksInColumn);
            else
                brick = new Brick(j * (float)fieldWidth / bricksInRow, startingY + i * (float)fieldHeight / bricksInColumn, (float)fieldWidth / bricksInRow, (float)fieldHeight / bricksInColumn);
            
            bricksArray.push_back(brick);
        }
}

void Field::Draw(std::shared_ptr <sf::RenderWindow> window) {
    for (auto brick : bricksArray)
        brick->Draw(window, colorsForLevels);
}

std::vector<Brick*> Field::GetBricksArray() {
    return bricksArray;
}

void Field::ReduceBrickLevel(unsigned num) {
    bricksArray[num]->ReduceLevel();
    if (bricksArray[num]->GetLevel() == 0)
        bricksArray.erase(bricksArray.begin() + num);
}
