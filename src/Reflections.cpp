#include <vector>
#include <cmath>
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
    bool FellToLeft = ball->getPosition().x <= maxDiagDist;
    bool FellToRight = fabs(ball->getPosition().x + 2 * ball->getRadius() - maxDiagDist) >= defaultWindowWidth;
    bool FellToTop = ball->getPosition().y <= maxDiagDist;
    bool FellToBottom = fabs(ball->getPosition().y - defaultWindowHeight) <= maxDiagDist;

    if (FellToLeft || FellToRight)
        xDirect *= -1;
    if (FellToTop)
        yDirect *= -1;
    if (reflectBottom && FellToBottom) {
        yDirect *= -1;
        ball->move({0, -ySpeed});
        reflectBottom = false;
        ball->setFillColor(sf::Color::White);
    }
}

void Ball::ReflectBar(std::shared_ptr <Bar> bar) {
    bool yLowerThanBarTop = fabs(ball->getPosition().y + 2 * ball->getRadius() - bar->GetYPos()) < ySpeed;
    bool xToRightFromBarLeft = ball->getPosition().x >= bar->GetXPos();
    bool xToLeftFromBarRight = ball->getPosition().x <= bar->GetXPos() + bar->GetWidth();

    if (yLowerThanBarTop && xToRightFromBarLeft && xToLeftFromBarRight) {
        yDirect *= -1;
        if (bar->GetStick()) {
            sticked = true;
            ball->setPosition(ball->getPosition().x, yStart);
        }
    }
}

bool Ball::ReflectFromBrick(std::shared_ptr<Brick> brick) {
    bool hit = false;
    float maxDiagDist = sqrt(ySpeed * ySpeed + xSpeed * xSpeed);

    bool yHigherThanBrickBottom = fabs(ball->getPosition().y - (brick->GetYPos() + brick->GetHeight())) < maxDiagDist;
    bool yLowerThanBrickTop = fabs(ball->getPosition().y + 2 * ball->getRadius() - brick->GetYPos()) < maxDiagDist;
    bool xToRightFromBrickLeft = fabs(ball->getPosition().x + 2 * ball->getRadius() - brick->GetXPos()) < maxDiagDist;
    bool xToLeftFromBrickRight = fabs(ball->getPosition().x - (brick->GetXPos() + brick->GetWidth())) < maxDiagDist;

    bool yHigherThanBrickBottomStrict = ball->getPosition().y > brick->GetYPos();
    bool yLowerThanBrickTopStrict = ball->getPosition().y < brick->GetYPos() + brick->GetHeight();
    bool xToRightFromBrickLeftStrict = ball->getPosition().x > brick->GetXPos();
    bool xToLeftFromBrickRightStrict = ball->getPosition().x < brick->GetXPos() + brick->GetWidth();

    //right bottom corner
    if (xToLeftFromBrickRight && yHigherThanBrickBottom) {
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
    //bottom edge
    else if (yHigherThanBrickBottom && xToRightFromBrickLeftStrict && xToLeftFromBrickRightStrict) {
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
    for (auto brick1 : bricksArray) {
        
        float brick1LeftX = brick1->GetXPos();
        float brick1RightX = brick1LeftX + brick1->GetWidth();
        float brick1TopY = brick1->GetYPos();
        BRICK_TYPE brick1Type = brick1->GetType();

        for (auto brick2 : bricksArray) {
        
            float brick2LeftX = brick2->GetXPos();
            float brick2RightX = brick2LeftX + brick2->GetWidth();
            float brick2TopY = brick2->GetYPos();
            BRICK_TYPE brick2Type = brick2->GetType();

            bool collisionOnFirstBrickLeft = fabs(brick1LeftX - brick2RightX) <= MOVING_BRICK_X_SPEED;
            bool collisionOnFirstBrickRight = fabs(brick1RightX - brick2LeftX) <= MOVING_BRICK_X_SPEED;
            bool sameY = brick1TopY == brick2TopY;
            bool bothAreMoving = brick1Type == moving && brick2Type == moving;

            if (collisionOnFirstBrickLeft && sameY && bothAreMoving)
                brick1->SetDirection(1);
            else if (collisionOnFirstBrickRight && sameY && bothAreMoving)
                brick1->SetDirection(-1);
        }
    }
}