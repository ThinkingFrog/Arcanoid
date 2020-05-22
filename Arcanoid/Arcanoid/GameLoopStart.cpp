#include "GameLoop.h"
#include "Field.h"

void GameLoop::Start() {
    while (window->isOpen()) {
        CheckEvents();

        if (!hasFocus)
            continue;

        window->clear();

        if (ball->GetYPos() >= defaultWindowHeight) {
            ball->Reset();
            bar->Reset();
            score -= 5;
        }

        ball->Move();
        activeBonuses->MoveAll(bar, field, ball);
        bar->Move();

        Reflect(field, bar, ball, activeBonuses);
        
        field->Draw(window);
        bar->Draw(window);
        ball->Draw(window);
        activeBonuses->Draw(window);
        ShowScore();

        window->display();
    }
}