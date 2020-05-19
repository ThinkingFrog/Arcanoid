#include "GameLoop.h"
#include "Field.h"

void GameLoop::Start() {
    while (window->isOpen()) {
        sf::Event event;

        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
            if (event.type == sf::Event::LostFocus)
                hasFocus = false;
            if (event.type == sf::Event::GainedFocus)
                hasFocus = true;
        }

        if (hasFocus == false)
            continue;

        window->clear();

        ShowScore();

        field->Draw(window);

        bar->Draw(window);

        ball->Draw(window);

        window->display();
    }
}