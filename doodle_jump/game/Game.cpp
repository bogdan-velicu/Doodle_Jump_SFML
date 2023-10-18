#include "Game.h"
#include <iostream>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

Game::Game() {
    std::cout << "Game constructor called\n";
    currentScreen = ScreenType::MAIN_MENU;
    windowTitle = "Doodle Jump SFML";

    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), windowTitle, sf::Style::Default);
    window.setFramerateLimit(60);
}

Game::~Game() {
    std::cout << "Game destructor called\n";
}

std::ostream& operator<<(std::ostream& out, const Game& game) {
    out << "Game object\n"
        << "Current screen: " << game.currentScreen << '\n'
        << "Window: " << game.windowTitle << '\n';
    return out;
}

void Game::run() {
    std::cout << "Game run called\n";
    while(window.isOpen()) {
        switch(currentScreen) {
        case ScreenType::MAIN_MENU:
            break;
        case ScreenType::GAME:
            break;
        case ScreenType::GAME_OVER:
            break;
        }
    }
}

void Game::changeScreen(ScreenType screenType) {
    currentScreen = screenType;
}