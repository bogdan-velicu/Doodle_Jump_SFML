#include "Game.h"
#include "./../screen/MainMenu.h"
#include "./../screen/PlayScreen.h"
#include <iostream>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

Game::Game() {
    std::cout << "Game constructor called\n";
    currentScreen = ScreenType::MAIN_MENU;
    windowTitle = "Doodle Jump SFML";
    score = 0;
    player = new Player();
    platforms = std::vector<Platform>();
    // for (int i = 0; i < 10; i++) {
    //     platforms.push_back(Platform());
    // }

    font = sf::Font();
    font.loadFromFile("fonts/Valoon.ttf");

    scoreText = sf::Text();
    scoreText.setFont(font);
    scoreText.setString(std::to_string(score));
    scoreText.setCharacterSize(36);
    scoreText.setFillColor(sf::Color::Black);
    scoreText.setPosition(20, 20);

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

    while (window.isOpen()) {
        sf::Event e = sf::Event();
        while (window.pollEvent(e)) {
            switch (e.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::Resized:
                std::cout << "New width: " << window.getSize().x << '\n'
                          << "New height: " << window.getSize().y << '\n';
                break;
            case sf::Event::KeyPressed:
                switch (currentScreen) {
                case ScreenType::MAIN_MENU:
                    MainMenu::handleInput(e, currentScreen);
                    break;
                case ScreenType::PLAY:
                    PlayScreen::handleInput(e, currentScreen);
                    break;
                default:
                    break;
                }
                break;
            default:
                break;
            }
        }
        switch (currentScreen) {
        case ScreenType::MAIN_MENU:
            MainMenu::render(window);
            break;
        case ScreenType::PLAY:
            Game::play();
            break;
        case ScreenType::GAME_OVER:
            
            break;
        case ScreenType::CLOSE:
            window.close();
            break;
        default:
            break;
        }
        
    }
}

void Game::play() {
    player->update();

    window.clear(sf::Color::Yellow);

    window.draw(player->getSprite());
    // for (auto& platform : platforms) {
    //     window.draw(platform.getSprite());
    // }
    displayScore();

    window.display();
}

void Game::displayScore() {
    scoreText.setString("Score: " + std::to_string(score));
    window.draw(scoreText);
}

int Game::getScore() const {
    return score;
}

void Game::setScore(int score_) {
    score = score_;
}

void Game::changeScreen(ScreenType screenType) {
    currentScreen = screenType;
}