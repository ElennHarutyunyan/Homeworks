#include <iostream>
#include <SFML/Graphics.hpp>

void CreateGraphicalBoard(sf::RenderWindow &window) {
    const int size = 100;
    for(int file = 0; file < 8; file++) {
        for(int rank = 0; rank < 8; rank++) {
            bool light = (file + rank) % 2 != 0;

            sf::RectangleShape square(sf::Vector2f(size, size));
            square.setPosition(rank * size, file * size);
            if(light)
                square.setFillColor(sf::Color::White);
            else
                square.setFillColor(sf::Color::Black);

            window.draw(square);
        }
    }
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "Chess Board");

    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        CreateGraphicalBoard(window);
        window.display();
    }

    return 0;
}
