#pragma once

unsigned constexpr FRAME_RATE = 100;

unsigned constexpr defaultWindowWidth = 1280;
unsigned constexpr defaultWindowHeight = 720;
unsigned constexpr defaultBricksInRow = 6;
unsigned constexpr defaultBricksInColumn = 4;

unsigned constexpr MAX_BRICK_LEVEL = 3;

int constexpr BALL_X_DIRECTION = -1;
int constexpr BALL_Y_DIRECTION = -1;
float constexpr BALL_X_SPEED = (float)5;
float constexpr BALL_Y_SPEED = (float)5;

float constexpr BAR_X_SPEED = (float)10;

float constexpr SPEEDING_BRICK_X_ACCELERATION = (float)1;
float constexpr SPEEDING_BRICK_Y_ACCELERATION = (float)1;

extern int score;

unsigned constexpr UNBREAKABLE_CHANCE = 5;
unsigned constexpr SPEEDING_CHANCE = 10;
unsigned constexpr BONUS_CHANCE = 40;

float constexpr BONUS_Y_SPEED = (float)1;

enum BRICK_TYPE {
    casual,
    unbreakable,
    speeding,
    with_bonus,
    brick_types_amount,
};

enum BONUS_TYPE {
    bonus_types_amount,
    none,
};