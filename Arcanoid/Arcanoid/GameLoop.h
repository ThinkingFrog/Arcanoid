#pragma once

class GameLoop {
private:
    unsigned windowWidth;
    unsigned windowHeight;
    unsigned bricksInRow;
    unsigned bricksInColumn;
    unsigned scoreHeight;
    unsigned fieldHeight;
public:
    GameLoop();
    ~GameLoop();
    Start();
};