#include "GameScreen.h"
#include <iostream>
#include <ostream>

GameScreen::GameScreen() {
    std::cout << "Screen constructor called\n";
    screenType = ScreenType::MAIN_MENU;
}

GameScreen::~GameScreen() {
    std::cout << "Screen destructor called\n";
}

GameScreen::GameScreen(ScreenType screenType_) {
    std::cout << "Screen constructor called\n";
    screenType = screenType_;
}

ScreenType GameScreen::getScreenType() const {
    return screenType;
}

void GameScreen::setScreenType(ScreenType screenType_) {
    screenType = screenType_;
}