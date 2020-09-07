#include "GameLoop.h"
#include "Field.h"

void GameLoop::Start() {
    while (window->isOpen()) {

        //Check if window closed, gained or lost focus
        CheckEvents();

        //if window has no focus, do nothing
        if (!hasFocus)
            continue;

        //If no brciks are left or only unbreakable once are present, show GameOver screen
        if (CheckGameOver())
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                break;
            else
                continue;

        //Clean window
        window->clear();

        //Check if ball and bar should be reseted
        CheckBallFellDown();

        //Move all objects on the screen
        MoveAll();

        //Check all reflections and collisions possible on the screen after movement
        Reflect();
        
        //Draw all objects present on the screen
        DrawAll();

        //Display all drawn objects
        window->display();
    }
}