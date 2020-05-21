#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include "Field.h"
#include "Bar.h"
#include "Ball.h"
#include "ActiveBonuses.h"

class GameLoop {
private:
    bool hasFocus;

    std::shared_ptr <sf::RenderWindow> window;
    unsigned windowWidth;
    unsigned windowHeight;

    std::shared_ptr <Field> field;
    unsigned bricksInRow;
    unsigned bricksInColumn;
    float fieldHeight;
    float fieldWidth;

    float scoreHeight;
    float scoreWidth;
    sf::Font scoreFont;

    std::shared_ptr <Bar> bar;
    float barStartX;
    float barStartY;
    float barWidth;
    float barHeight;

    std::shared_ptr <Ball> ball;
    float ballStartX;
    float ballStartY;
    float ballRadius;

    std::shared_ptr <ActiveBonuses> activeBonuses;
public:
    GameLoop();
    ~GameLoop() {};
    void Start();
    void ShowScore();
    void CheckEvents();
    void Reflect(std::shared_ptr<Field> field, std::shared_ptr<Bar> bar, std::shared_ptr<Ball> ball, std::shared_ptr<ActiveBonuses> activeBonuses);
    void BallReflectBricks(std::shared_ptr<Field> field, std::shared_ptr<Ball> ball, std::shared_ptr<ActiveBonuses> activeBonuses);
};