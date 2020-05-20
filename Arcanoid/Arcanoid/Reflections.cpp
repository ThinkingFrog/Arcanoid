#include <vector>
#include "Ball.h"
#include "Bar.h"
#include "Field.h"
#include "Main.h"
#include "UnbreakableBrick.h"

void Ball::Reflect(std::shared_ptr <Bar> bar, std::shared_ptr <Field> field) {
    ReflectWall();
    ReflectBar(bar);
    ReflectBricks(field);
}

void Ball::ReflectWall() {
    if (x <= 0 || x + 2 * radius >= defaultWindowWidth)
        xDirect *= -1;
    if (y <= 0)
        yDirect *= -1;
}

void Ball::ReflectBar(std::shared_ptr <Bar> bar) {
    if (fabs(y + 2 * radius - bar->GetYPos()) < ySpeed && (x >= bar->GetXPos() && x <= bar->GetXPos() + bar->GetWidth()))
        yDirect *= -1;
}

bool Ball::ReflectFromBrick(Brick* brick) {
    bool hit = false;
    
    if (fabs(y - (brick->GetYPos() + brick->GetHeight())) < ySpeed && (x >= brick->GetXPos() && x <= brick->GetXPos() + brick->GetWidth())) {
        yDirect *= -1;
        hit = true;
    }
    else if (fabs(y + 2 * radius - brick->GetYPos()) < ySpeed && (x >= brick->GetXPos() && x <= brick->GetXPos() + brick->GetWidth())) {
        yDirect *= -1;
        hit = true;
    }
    else if (fabs(x + 2 * radius - brick->GetXPos()) < xSpeed && (y >= brick->GetYPos() && y <= brick->GetYPos() + brick->GetHeight())) {
        xDirect *= -1;
        hit = true;
    }
    else if (fabs(x - (brick->GetXPos() + brick->GetWidth())) < xSpeed && (y >= brick->GetYPos() && y <= brick->GetYPos() + brick->GetHeight())) {
        xDirect *= -1;
        hit = true;
    }

    return hit;
}

void Ball::ReflectBricks(std::shared_ptr <Field> field) {
    std::vector<Brick*> bricksArray = field->GetBricksArray();
    for (unsigned i = 0; i < bricksArray.size(); ++i)
        if (ReflectFromBrick(bricksArray[i])) {
            field->ReduceBrickLevel(i);
            if (bricksArray[i]->GetType() != unbreakable)
                score += 1;
            if (bricksArray[i]->GetType() == speeding) {
                Accelerate(bricksArray[i]->Accelerate().x, bricksArray[i]->Accelerate().y);
            }
            break;
        }
}