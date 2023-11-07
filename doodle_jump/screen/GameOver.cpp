#include "GameOver.h"

GameOver::GameOver() {
    std::cout << "GameOver constructor called\n";
}

GameOver::~GameOver() {
    std::cout << "GameOver destructor called\n";
}

void GameOver::render(sf::RenderWindow& window, float score) {
    std::cout << "GameOver render called\n";
    sf::Font font;
    font.loadFromFile("fonts/Valoon.ttf");

    sf::Text text = sf::Text{"Game Over \nPress Enter to play again\nPress Esc to exit", font, 40},
     scoreText = sf::Text{"Score: " + std::to_string((int)score), font, 50};

    scoreText.setFillColor(sf::Color::Red);
    scoreText.setStyle(sf::Text::Bold);
    scoreText.setOrigin(text.getGlobalBounds().getSize() / 2.f + text.getLocalBounds().getPosition());
    scoreText.setPosition((float)window.getSize().x / 2.f, (float)window.getSize().y / 2.f - 200.f);

    text.setFillColor(sf::Color::Red);
    text.setStyle(sf::Text::Bold);
    text.setOrigin(text.getGlobalBounds().getSize() / 2.f + text.getLocalBounds().getPosition());
    text.setPosition((float)window.getSize().x / 2.f, (float)window.getSize().y / 2.f);

    window.clear(sf::Color::Black);
    window.draw(text);
    window.draw(scoreText);
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