#include "PlayScreen.h"

PlayScreen::PlayScreen() {
    std::cout << "PlayScreen constructor called\n";
    setScreenType(ScreenType::PLAY);
}

PlayScreen::~PlayScreen() {
    std::cout << "PlayScreen destructor called\n";
}

void PlayScreen::handleInput(sf::Event& event, ScreenType& currentScreen) {
    std::cout << "PlayScreen handleInput called\n";
    switch (event.key.code) {
    case sf::Keyboard::Escape:
        currentScreen = ScreenType::MAIN_MENU;
        break;
    default:
        break;
    }
}