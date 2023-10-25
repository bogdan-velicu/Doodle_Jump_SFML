#include "GameOver.h"

GameOver::GameOver() {
    std::cout << "GameOver constructor called\n";
}

GameOver::~GameOver() {
    std::cout << "GameOver destructor called\n";
}

void GameOver::render(sf::RenderWindow& window) {
    std::cout << "GameOver render called\n";
    sf::Font font;
    font.loadFromFile("bin/fonts/Valoon.ttf");

    sf::Text text;
    text.setFont(font);
    text.setString("Game Over \nPress Enter to play again\nPress Esc to exit");
    text.setCharacterSize(40);
    text.setFillColor(sf::Color::Red);
    text.setStyle(sf::Text::Bold);
    text.setPosition(100, 200);

    window.clear(sf::Color::Black);
    window.draw(text);
    window.display();
}

void GameOver::handleInput(const sf::Event& event, ScreenType& currentScreen) {
    std::cout << "GameOver handleInput called\n";
    switch (event.key.code) {
    case sf::Keyboard::Enter:
        currentScreen = ScreenType::PLAY;
        break;
    case sf::Keyboard::Escape:
        currentScreen = ScreenType::MAIN_MENU;
        break;
    default:
        break;
    }
}