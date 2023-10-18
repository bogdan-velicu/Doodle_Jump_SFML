#include <iostream>
#include <chrono>
#include <thread>

#include "./doodle_jump/game/Game.h"

#ifdef __linux__
#include <X11/Xlib.h>
#endif

int main() {
    #ifdef __linux__
    XInitThreads();
    #endif

    Game game = Game();
    game.run();
    std::cout << game << '\n';

    // sf::RenderWindow window;
    // window.create(sf::VideoMode(800, 700), "Doodle Jump", sf::Style::Default);

    // while(window.isOpen()) {
    //     sf::Event e;
    //     while(window.pollEvent(e)) {
    //         switch(e.type) {
    //         case sf::Event::Closed:
    //             window.close();
    //             break;
    //         case sf::Event::Resized:
    //             std::cout << "New width: " << window.getSize().x << '\n'
    //                       << "New height: " << window.getSize().y << '\n';
    //             break;
    //         case sf::Event::KeyPressed:
    //             std::cout << "Received key " << (e.key.code == sf::Keyboard::X ? "X" : "(other)") << "\n";
    //             break;
    //         default:
    //             break;
    //         }
    //     }

    //     window.clear();
    //     window.display();
    // }

    return 0;
}