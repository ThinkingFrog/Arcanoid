#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include "Field.h"
#include "Bar.h"
#include "Ball.h"
#include "ActiveBonuses.h"

class GameLoop {
private:
    bool hasFocus;  /**Variable shows if window has focus or not*/

    std::shared_ptr <sf::RenderWindow> window;  /**Smart pointer to a window object used to draw other objects*/
    unsigned windowWidth;
    unsigned windowHeight;

    std::shared_ptr <Field> field;  /**Smart pointer to a field object containing all bricks objects*/
    unsigned bricksInRow;
    unsigned bricksInColumn;
    float fieldHeight;
    float fieldWidth;

    float scoreHeight;
    float scoreWidth;
    sf::Font scoreFont;

    std::shared_ptr <Bar> bar;  /**Smart pointer to a bar object used to reflect ball at the bottom of the screen*/
    float barStartX;
    float barStartY;
    float barWidth;
    float barHeight;

    std::shared_ptr <Ball> ball;    /**Smart pointer to a ball object used to hit bricks*/
    float ballStartX;
    float ballStartY;
    float ballRadius;

    std::shared_ptr <ActiveBonuses> activeBonuses;  /**Smart pointer to an ActiveBonuses object containing all bonus objects*/
    
    /**Draw current score*/
    void ShowScore();   

    /**Check window events like gaining/losing focus*/
    void CheckEvents(); 

    /**Check all possible reflections on the screen*/
    void Reflect();

    /**Check if ball hit any of the bricks in field*/
    void BallReflectBricks();

    /**Check if ball fell off screen and should be placed on starting point*/
    void CheckBallFellDown();

    /**Move all objects on the screen that can move*/
    void MoveAll();

    /**Draw all objects on the screen*/
    void DrawAll();
    
    /**Check if game is over*/
    bool CheckGameOver();
public:
    GameLoop();
    ~GameLoop() {};
    void Start();
};