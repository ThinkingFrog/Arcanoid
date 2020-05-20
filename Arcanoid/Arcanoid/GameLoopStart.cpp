#include "GameLoop.h"
#include "Field.h"

void GameLoop::Start() {
    while (window->isOpen()) {
        CheckEvents();

        if (!hasFocus)
            continue;

        window->clear();

        ball->Move();
        ball->Reflect(bar, field);

        bar->Move();

        ShowScore();
        field->Draw(window);
        bar->Draw(window);
        ball->Draw(window);

        window->display();
    }
}