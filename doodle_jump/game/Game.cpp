#include "Game.h"
#include "./../screen/MainMenu.h"
#include "./../screen/PlayScreen.h"
#include "./../screen/GameOver.h"
#include <iostream>
#include <string>
#include <sys/errno.h>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

Game::Game() {
    std::cout << "Game constructor called\n";
    currentScreen = ScreenType::MAIN_MENU;
    windowTitle = "Doodle Jump SFML";
    score = 0;
    maxScore = 0;
    player = new Player();
    platforms = std::vector<Platform*>();
    for (int i = 0; i < 3; i++) {
        platforms.push_back(new Platform());
    }
    for (int i = 0; i < 2; i++) {
        platforms.push_back(new Platform(false));
    }
    for (int i = 0; i < 2; i++) {
        platforms.push_back(new Platform(true));
    }

    font = sf::Font();
    font.loadFromFile("fonts/Valoon.ttf");

    scoreText = new sf::Text();
    scoreText->setFont(font);
    scoreText->setString(std::to_string(score));
    scoreText->setCharacterSize(36);
    scoreText->setFillColor(sf::Color::Black);
    scoreText->setPosition(20, 20);

    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), windowTitle, sf::Style::Default);
    window.setFramerateLimit(120);
}

Game::~Game() {
    std::cout << "Game destructor called\n";
    delete player;
    for (auto& platform : platforms) {
        delete platform;
    }
}

std::ostream& operator<<(std::ostream& out, const Game& game) {
    out << "Game object\n"
        << "Current screen: " << game.currentScreen << '\n'
        << "Window: " << game.windowTitle << '\n';
    return out;
}

void Game::reset() {
    delete player;
    player = new Player();
    for (auto& platform : platforms) {
        delete platform;
    }
    platforms.clear();
    for (int i = 0; i < 3; i++) {
        platforms.push_back(new Platform());
    }
    for (int i = 0; i < 2; i++) {
        platforms.push_back(new Platform(false));
    }
    for (int i = 0; i < 2; i++) {
        platforms.push_back(new Platform(true));
    }
    score = 0;
    maxScore = 0;
}

void Game::run() {
    std::cout << "Game run called\n";

    while (window.isOpen()) {
        sf::Event e = sf::Event();
        while (window.pollEvent(e)) {
            ScreenType screenCopy = currentScreen;
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
                case ScreenType::GAME_OVER:
                    GameOver::handleInput(e, currentScreen);
                    break;
                case ScreenType::PLAY:
                    PlayScreen::handleInput(e, currentScreen);
                    if (screenCopy != currentScreen)
                        reset();
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
            GameOver::render(window);
            break;
        case ScreenType::CLOSE:
            window.close();
            break;
        default:
            break;
        }
        
    }
}

void Game::checkCollision() {
    // Get only lower part of player sprite
    sf::FloatRect lowerPlayerBounds = player->getSprite().getGlobalBounds();
    lowerPlayerBounds.top += lowerPlayerBounds.height - 5;
    lowerPlayerBounds.height = 5;

    // Handle ground collision
    if (lowerPlayerBounds.getPosition().y > 600.0f) {
        if (score > 200) {
            reset();
            changeScreen(ScreenType::GAME_OVER);
        }
        else
            player->jump();
    }

    // sf::FloatRect playerBounds = player->getSprite().getGlobalBounds();
    for (auto& platform : platforms) {
        // Get only upper part of platform sprite
        sf::FloatRect upperPlatformBounds = platform->getSprite().getGlobalBounds();
        upperPlatformBounds.height = 5;

        // sf::FloatRect platformBounds = platform->getSprite().getGlobalBounds();
        if (lowerPlayerBounds.intersects(upperPlatformBounds)) {
            if (player->getSprite().getPosition().y < platform->getSprite().getPosition().y) {
                // Jump only if player is falling
                if (player->getYVelocity() > 0.0f)
                    player->jump();
                if (platform->getType() == PlatformType::BREAKABLE) {
                    delete platform;
                    // platform = new Platform();
                }
                else if (platform->getType() == PlatformType::BOOST) {
                    player->setYVelocity(-10.0f);
                }
            }
        }
    }
}

void Game::displayDebugInfo() {
    sf::Vector2f playerCoordinates = player->getSprite().getPosition();
    std::cout << "Player coordinates: (" << playerCoordinates.x << ", " << playerCoordinates.y << ")\n";
    std::cout << "Player velocity: (" << player->getXVelocity() << ", " << player->getYVelocity() << ")\n";
    for (auto& platform : platforms) {
        sf::Vector2f platformCoordinates = platform->getSprite().getPosition();
        std::cout << "Platform coordinates: (" << platformCoordinates.x << ", " << platformCoordinates.y << ")\n";
    }
    sf::Text debugText = sf::Text();
    debugText.setFont(font);
    debugText.setString(std::to_string(playerCoordinates.x) + ", " + std::to_string(playerCoordinates.y));
    debugText.setCharacterSize(36);
    debugText.setFillColor(sf::Color::Black);
    debugText.setPosition(60, 60);

    window.draw(debugText);
}

void Game::play() {
    player->update();
    checkCollision();
    sf::Vector2f velocity = player->getVelocity();

    if (player->getSprite().getPosition().y < 300 && maxScore - score < 200) {
        for (auto& platform : platforms) {
            if (platform->getSprite().getPosition().y > 600.0f) {
                delete platform;
                platform = new Platform(true);
            }

            float yVelocity = player->getYVelocity();
            platform->moveSprite({0.0f, -yVelocity});
        }
    }
    else {
        player->moveSprite({0.0f, velocity.y});
    }
    player->moveSprite({velocity.x, 0.0f});

    window.clear(sf::Color::White);

    window.draw(player->getSprite());
    for (auto& platform : platforms) {
        window.draw(platform->getSprite());
    }
    displayScore();
    displayDebugInfo();

    window.display();
}

void Game::displayScore() {
    score -= (int)player->getYVelocity();
    if (score > maxScore)
        maxScore = score;

    scoreText->setString("Score: " + std::to_string(maxScore));
    window.draw(*scoreText);
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