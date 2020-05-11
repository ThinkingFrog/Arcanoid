#include <SFML/Graphics.hpp>

int main(void){
    sf::RenderWindow window(sf::VideoMode(800, 600), "Arcanoid");
    while (window.isOpen()) {
        sf::Event event;
        
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        sf::CircleShape shape(200.f);
        shape.setFillColor(sf::Color::Green);
        window.draw(shape);

        window.display();
    }
    return 0;
}