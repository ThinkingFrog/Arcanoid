#include "GameLoop.h"
#include "Field.h"

void GameLoop::Start() {
    while (window->isOpen()) {
        CheckEvents();

        if (!hasFocus)
            continue;

        if (CheckGameOver())
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                break;
            else
                continue;

        window->clear();

        CheckBallFellDown();

        MoveAll();

        Reflect();
        
        DrawAll();

        window->display();
    }
}