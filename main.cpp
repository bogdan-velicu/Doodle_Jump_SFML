#include <iostream>
#include <chrono>
#include <thread>
#include <time.h>

#include "./doodle_jump/game/Game.h"

#ifdef __linux__
#include <X11/Xlib.h>
#endif

int main() {
    #ifdef __linux__
    XInitThreads();
    #endif

    srand(time(nullptr));

    Game game = Game();
    std::cout << game << '\n';

    game.run();

    return 0;
}