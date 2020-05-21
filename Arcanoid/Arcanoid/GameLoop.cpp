#include "GameLoop.h"
#include "Main.h"

int score;

GameLoop::GameLoop() {
    hasFocus = true;

    windowWidth = defaultWindowWidth;
    windowHeight = defaultWindowHeight;
    window = std::make_shared <sf::RenderWindow>(sf::VideoMode(windowWidth, windowHeight), "Arcanoid");
    window->setFramerateLimit(FRAME_RATE);
    
    scoreWidth = windowWidth * (float)0.3;
    scoreHeight = windowHeight * (float)0.1;
    score = 0;
    scoreFont.loadFromFile("../../Resources/score_font.ttf");

    bricksInRow = defaultBricksInRow;
    bricksInColumn = defaultBricksInColumn;
    fieldWidth = (float)windowWidth;
    fieldHeight = windowHeight * (float)0.3;
    field = std::make_shared <Field>(bricksInRow, bricksInColumn, scoreHeight, fieldWidth, fieldHeight);

    barWidth = windowWidth / (float)4.0;
    barHeight = windowHeight / (float)20.0;
    barStartX = windowWidth / (float)2.0 - barWidth / (float)2.0;
    barStartY = windowHeight * (float)0.9;
    bar = std::make_shared <Bar>(barStartX, barStartY, barWidth, barHeight);

    ballRadius = (windowWidth + windowHeight) / (float)200.0;
    ballStartX = barStartX + barWidth / (float)2.0 - ballRadius / (float)2.0;
    ballStartY = barStartY - ballRadius * (float)3.0;
    ball = std::make_shared <Ball>(ballStartX, ballStartY, ballRadius);

    activeBonuses = std::make_shared <ActiveBonuses>();
}

void GameLoop::ShowScore() {
    sf::Text text;

    text.setFont(scoreFont);
    text.setString("Score: " + std::to_string(score));
    text.setCharacterSize((unsigned)(scoreHeight + scoreWidth) / 10);
    text.setStyle(sf::Text::Bold);

    window->draw(text);
}

void GameLoop::CheckEvents() {
    sf::Event event;

    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window->close();
        if (event.type == sf::Event::LostFocus)
            hasFocus = false;
        if (event.type == sf::Event::GainedFocus)
            hasFocus = true;
    }
}