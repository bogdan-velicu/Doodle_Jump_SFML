#include <iostream>
#include <chrono>
#include <thread>
#include <time.h>

#include "./doodle_jump/game/Game.h"
#include "./doodle_jump/exceptions/Exceptions.h"

#ifdef __linux__
#include <X11/Xlib.h>
#endif

int main() {
    #ifdef __linux__
    XInitThreads();
    #endif

    srand(time(NULL));

    try {
        throw RandomException();
    } catch (const std::exception& e) {
        std::cout << e.what() << '\n';
    }

    Game game = Game();
    std::cout << game << '\n';

    game.run();

    return 0;
}