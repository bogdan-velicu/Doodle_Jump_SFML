#include "MainMenu.h"

MainMenu::MainMenu() {
    std::cout << "MainMenu constructor called\n";
    setScreenType(ScreenType::MAIN_MENU);
}

MainMenu::~MainMenu() {
    std::cout << "MainMenu destructor called\n";
}

void MainMenu::render(sf::RenderWindow& window) {
    sf::Font font;
    font.loadFromFile("fonts/Valoon.ttf");

    sf::Text text;
    text.setFont(font);
    text.setString("\nPress Enter to start the game\n\nPress Esc to exit");
    text.setCharacterSize(36);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);

    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    text.setPosition(sf::Vector2f((float)window.getSize().x / 2.0f, (float)window.getSize().y / 2.0f));

    window.clear(sf::Color::White);
    window.draw(text);
    window.display();
}

void MainMenu::handleInput(const sf::Event& event, ScreenType& currentScreen) {
    std::cout << "MainMenu handleInput called\n";
    switch (event.key.code) {
    case sf::Keyboard::Enter:
        currentScreen = ScreenType::PLAY;
        break;
    case sf::Keyboard::Escape:
        currentScreen = ScreenType::CLOSE;
        break;
    default:
        break;
    }
}