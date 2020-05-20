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

extern int score;

unsigned constexpr UNBREAKABLE_CHANCE = 10;

enum BRICK_TYPE {
    casual,
    unbreakable,
    types_amount,
};