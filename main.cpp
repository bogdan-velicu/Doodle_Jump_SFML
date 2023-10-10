#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include <thread>

#ifdef __linux__
#include <X11/Xlib.h>
#endif

// g++ main.cpp -o doodle -I /usr/local/Cellar/sfml/2.6.0/include -L /usr/local/Cellar/sfml/2.6.0/lib -l sfml-graphics -l sfml-window -l sfml-system

int main() {
    #ifdef __linux__
    XInitThreads();
    #endif

    sf::RenderWindow window;
    window.create(sf::VideoMode(800, 700), "My Window", sf::Style::Default);
    sf::CircleShape shape(window.getSize().x / 2);
    shape.setFillColor(sf::Color::Green);
    window.setVerticalSyncEnabled(true);
    //window.setFramerateLimit(60);

    while(window.isOpen()) {
        sf::Event e;
        while(window.pollEvent(e)) {
            switch(e.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::Resized:
                std::cout << "New width: " << window.getSize().x << '\n'
                          << "New height: " << window.getSize().y << '\n';
                break;
            case sf::Event::KeyPressed:
                std::cout << "Received key " << (e.key.code == sf::Keyboard::X ? "X" : "(other)") << "\n";
                break;
            default:
                break;
            }
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}