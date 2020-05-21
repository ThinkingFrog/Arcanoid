#include <vector>
#include "Ball.h"
#include "Bar.h"
#include "Field.h"
#include "ActiveBonuses.h"
#include "Main.h"
#include "UnbreakableBrick.h"
#include "GameLoop.h"

void GameLoop::Reflect(std::shared_ptr <Field> field, std::shared_ptr <Bar> bar, std::shared_ptr <Ball> ball, std::shared_ptr <ActiveBonuses> activeBonuses) {
    ball->ReflectWall();
    ball->ReflectBar(bar);
    BallReflectBricks(field, ball, activeBonuses);
}

void Ball::ReflectWall() {
    if (x <= 0 || x + 2 * radius >= defaultWindowWidth)
        xDirect *= -1;
    if (y <= 0)
        yDirect *= -1;
}

void Ball::ReflectBar(std::shared_ptr <Bar> bar) {
    if (fabs(y + 2 * radius - bar->GetYPos()) <  ySpeed && (x >= bar->GetXPos() && x <= bar->GetXPos() + bar->GetWidth()))
        yDirect *= -1;
}

bool Ball::ReflectFromBrick(std::shared_ptr<Brick> brick) {
    bool hit = false;
    float maxDiagDist = sqrt(ySpeed * ySpeed + xSpeed * xSpeed);
    
    //bottom edge
    if (fabs(y - (brick->GetYPos() + brick->GetHeight())) < ySpeed && (x > brick->GetXPos() && x < brick->GetXPos() + brick->GetWidth())) {
        yDirect *= -1;
        hit = true;
    }
    //upper edge
    else if (fabs(y + 2 * radius - brick->GetYPos()) < ySpeed && (x > brick->GetXPos() && x < brick->GetXPos() + brick->GetWidth())) {
        yDirect *= -1;
        hit = true;
    }
    //left edge
    else if (fabs(x + 2 * radius - brick->GetXPos()) < xSpeed && (y > brick->GetYPos() && y < brick->GetYPos() + brick->GetHeight())) {
        xDirect *= -1;
        hit = true;
    }
    //right edge
    else if (fabs(x - (brick->GetXPos() + brick->GetWidth())) < xSpeed && (y > brick->GetYPos() && y < brick->GetYPos() + brick->GetHeight())) {
        xDirect *= -1;
        hit = true;
    }
    //right bottom corner
    else if (fabs(x - (brick->GetXPos() + brick->GetWidth())) < maxDiagDist && fabs(y - (brick->GetYPos() + brick->GetHeight())) < maxDiagDist) {
        xDirect *= -1;
        yDirect *= -1;
        hit = true;
    }
    //right top corner
    else if (fabs(x - (brick->GetXPos() + brick->GetWidth())) < maxDiagDist && fabs(y + 2 * radius - brick->GetYPos()) < maxDiagDist) {
        xDirect *= -1;
        yDirect *= -1;
        hit = true;
    }
    //left top corner
    else if (fabs(x + 2 * radius - brick->GetXPos()) < maxDiagDist && fabs(y + 2 * radius - brick->GetYPos()) < maxDiagDist) {
        xDirect *= -1;
        yDirect *= -1;
        hit = true;
    }
    //left bottom corner
    else if (fabs(x + 2 * radius) < maxDiagDist && fabs(y - (brick->GetYPos() + brick->GetHeight())) < maxDiagDist) {
        xDirect *= -1;
        yDirect *= -1;
        hit = true;
    }

    return hit;
}

void GameLoop::BallReflectBricks(std::shared_ptr <Field> field, std::shared_ptr <Ball> ball, std::shared_ptr <ActiveBonuses> activeBonuses) {
    std::vector<std::shared_ptr<Brick>> bricksArray = field->GetBricksArray();
    unsigned i = 0;
    for (auto brick : bricksArray) {
        if (ball->ReflectFromBrick(brick)) {

            BRICK_TYPE brickType = brick->GetType();

            if (brickType != unbreakable)
                score += 1;

            if (brickType == speeding) {
                sf::Vector2f acceleration = brick->Accelerate();
                ball->Accelerate(acceleration.x, acceleration.y);
            }

            if (brickType == with_bonus && brick->GetLevel() == 1) {
                float bonusX = brick->GetXPos() + brick->GetWidth() / 2;
                float bonusY = brick->GetYPos() + brick->GetHeight() / 2;
                float bonusRadius = (brick->GetWidth() + brick->GetHeight()) / 20;
                activeBonuses->AddRandomBonus(bonusX, bonusY, bonusRadius, BONUS_Y_SPEED);
            }

            field->ReduceBrickLevel(i);

            break;
        }
        i++;
    }
}