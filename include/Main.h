#pragma once

extern int score;

unsigned constexpr FRAME_RATE = 100;

unsigned constexpr defaultWindowWidth = 800;
unsigned constexpr defaultWindowHeight = 600;
unsigned constexpr defaultBricksInRow = 6;
unsigned constexpr defaultBricksInColumn = 4;

unsigned constexpr MAX_BRICK_LEVEL = 3;
float constexpr MOVING_BRICK_X_SPEED = (float)1;
float constexpr SPEEDING_BRICK_X_ACCELERATION = (float)1;
float constexpr SPEEDING_BRICK_Y_ACCELERATION = (float)1;

int constexpr BALL_X_DIRECTION = -1;
int constexpr BALL_Y_DIRECTION = -1;
float constexpr BALL_X_SPEED = (float)5;
float constexpr BALL_Y_SPEED = (float)5;
float constexpr BALL_SPEED_POSSIBLE_CHANGE = (float)0.5;

float constexpr BAR_X_SPEED = (float)10;
float constexpr BAR_SIZE_POSSIBLE_CHANGE = (float)1.2;

unsigned constexpr UNBREAKABLE_CHANCE = 5;
unsigned constexpr SPEEDING_CHANCE = 10;

unsigned constexpr BONUS_CHANCE = 40;
float constexpr BONUS_Y_SPEED = (float)1;
unsigned constexpr CHANCE_TO_RANDOM_REFLECT_ON_EACH_FRAME = 10;

enum BRICK_TYPE {
    casual,
    unbreakable,
    speeding,
    with_bonus,
    moving,
    brick_types_amount,
};

enum BONUS_TYPE {
    change_bar_size,
    change_ball_speed,
    sticky_bar,
    bottom_reflect,
    random_direction,
    moving_brick,
    bonus_types_amount,
};