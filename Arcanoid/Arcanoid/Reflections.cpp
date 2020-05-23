#include <vector>
#include "Ball.h"
#include "Bar.h"
#include "Field.h"
#include "ActiveBonuses.h"
#include "Main.h"
#include "UnbreakableBrick.h"
#include "GameLoop.h"

void GameLoop::Reflect() {
    ball->ReflectWall();
    ball->ReflectBar(bar);
    BallReflectBricks();
    field->CheckForCollisionsBetweenBricks();
}

void Ball::ReflectWall() {
    float maxDiagDist = sqrt(ySpeed * ySpeed + xSpeed * xSpeed);
    bool FellToLeft = x <= maxDiagDist;
    bool FellToRight = fabs(x + 2 * radius - maxDiagDist) >= defaultWindowWidth;
    bool FellToTop = y <= maxDiagDist;
    bool FellToBottom = fabs(y - defaultWindowHeight) <= maxDiagDist;

    if (FellToLeft || FellToRight)
        xDirect *= -1;
    if (FellToTop)
        yDirect *= -1;
    if (reflectBottom && FellToBottom) {
        yDirect *= -1;
        y -= ySpeed; 
        reflectBottom = false;
        color = sf::Color::White;
    }
}

void Ball::ReflectBar(std::shared_ptr <Bar> bar) {
    bool yLowerThanBarTop = fabs(y + 2 * radius - bar->GetYPos()) < ySpeed;
    bool xToRightFromBarLeft = x >= bar->GetXPos();
    bool xToLeftFromBarRight = x <= bar->GetXPos() + bar->GetWidth();

    if (yLowerThanBarTop && xToRightFromBarLeft && xToLeftFromBarRight) {
        yDirect *= -1;
        if (bar->GetStick()) {
            sticked = true;
            y = yStart;
        }
    }
}

bool Ball::ReflectFromBrick(std::shared_ptr<Brick> brick) {
    bool hit = false;
    float maxDiagDist = sqrt(ySpeed * ySpeed + xSpeed * xSpeed);

    bool yHigherThanBrickBottom = fabs(y - (brick->GetYPos() + brick->GetHeight())) < maxDiagDist;
    bool yLowerThanBrickTop = fabs(y + 2 * radius - brick->GetYPos()) < maxDiagDist;
    bool xToRightFromBrickLeft = fabs(x + 2 * radius - brick->GetXPos()) < maxDiagDist;
    bool xToLeftFromBrickRight = fabs(x - (brick->GetXPos() + brick->GetWidth())) < maxDiagDist;

    bool yHigherThanBrickBottomStrict = y > brick->GetYPos();
    bool yLowerThanBrickTopStrict = y < brick->GetYPos() + brick->GetHeight();
    bool xToRightFromBrickLeftStrict = x > brick->GetXPos();
    bool xToLeftFromBrickRightStrict = x < brick->GetXPos() + brick->GetWidth();

    //bottom edge
    if (yHigherThanBrickBottom && xToRightFromBrickLeftStrict && xToLeftFromBrickRightStrict) {
        yDirect *= -1;
        hit = true;
    }
    //upper edge
    else if (yLowerThanBrickTop && xToRightFromBrickLeftStrict && xToLeftFromBrickRightStrict) {
        yDirect *= -1;
        hit = true;
    }
    //left edge
    else if (xToRightFromBrickLeft && yHigherThanBrickBottomStrict && yLowerThanBrickTopStrict) {
        xDirect *= -1;
        hit = true;
    }
    //right edge
    else if (xToLeftFromBrickRight && yHigherThanBrickBottomStrict && yLowerThanBrickTopStrict) {
        xDirect *= -1;
        hit = true;
    }
    //right bottom corner
    else if (xToLeftFromBrickRight && yHigherThanBrickBottom) {
        xDirect *= -1;
        yDirect *= -1;
        hit = true;
    }
    //right top corner
    else if (xToLeftFromBrickRight && yLowerThanBrickTop) {
        xDirect *= -1;
        yDirect *= -1;
        hit = true;
    }
    //left top corner
    else if (xToRightFromBrickLeft && yLowerThanBrickTop) {
        xDirect *= -1;
        yDirect *= -1;
        hit = true;
    }
    //left bottom corner
    else if (xToRightFromBrickLeft && yHigherThanBrickBottom) {
        xDirect *= -1;
        yDirect *= -1;
        hit = true;
    }

    return hit;
}

void GameLoop::BallReflectBricks() {
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

void Field::CheckForCollisionsBetweenBricks() {
    for (auto brick1 : bricksArray)
        for (auto brick2 : bricksArray)
            if (brick1->GetXPos() == brick2->GetXPos() + brick2->GetWidth() && brick1->GetYPos() == brick2->GetYPos())
                brick1->SetDirection(1);
            else if (brick1->GetXPos() + brick1->GetWidth() == brick2->GetXPos() && brick1->GetYPos() == brick2->GetYPos())
                brick1->SetDirection(-1);
}