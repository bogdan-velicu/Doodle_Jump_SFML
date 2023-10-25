#include "Game.h"
#include "./../screen/MainMenu.h"
#include "./../screen/PlayScreen.h"
#include "./../screen/GameOver.h"
#include <iostream>
#include <string>
#include "./../platform/PlatformGenerator.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

Game::Game() {
    std::cout << "Game constructor called\n";
    currentScreen = ScreenType::MAIN_MENU;
    platformGenerator = PlatformGenerator();
    score = 0;
    maxScore = 0;
    player = new Player();
    platforms = std::vector<Platform*>();
    
    for (int i = 0; i < 15; i++) {
        auto platform = new Platform();
        platform->useGenerator(platformGenerator.getLastPlatformCoordinates());
        platformGenerator.setLastPlatform(platform);
        platforms.push_back(platform);
    }

    font = sf::Font();
    font.loadFromFile("bin/fonts/Valoon.ttf");

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

    platformGenerator.setLastPlatform(new Platform());

    for (int i = 0; i < 15; i++) {
        auto platform = new Platform();
        platform->useGenerator(platformGenerator.getLastPlatformCoordinates());
        platformGenerator.setLastPlatform(platform);
        platforms.push_back(platform);
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
                    if (currentScreen == ScreenType::PLAY)
                        reset();
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
        if (score > 150) {
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
                if (player->getYVelocity() > 0.2f) {
                    player->jump();

                    if (platform->getType() == PlatformType::BREAKABLE) {
                        delete platform;
                        auto plat = new Platform();
                        plat->useGenerator(platformGenerator.getLastPlatformCoordinates());
                        platformGenerator.setLastPlatform(plat);
                        platform = plat;
                    }
                    else if (platform->getType() == PlatformType::BOOST) {
                        player->setYVelocity(-20.0f);
                    }
                }
            }
        }

        // Handle moving platforms
        if (platform->getType() == PlatformType::MOVING) {
            platform->animateMovement();
        }
    }
}

void Game::displayDebugInfo() {
    sf::Text debugText = sf::Text();
    debugText.setFont(font);
    sf::Vector2f velocity = player->getVelocity();
    debugText.setString("xVelocity: " + std::to_string(velocity.x) + "\nyVelocity: " + std::to_string(velocity.y));
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
            if (platform->getSprite().getPosition().y > 750.0f) {
                delete platform;
                auto plat = new Platform();
                plat->useGenerator(platformGenerator.getLastPlatformCoordinates());
                platformGenerator.setLastPlatform(plat);
                platform = plat;
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
    score -= player->getYVelocity();
    if (score > maxScore)
        maxScore = score;

    scoreText->setString("Score: " + std::to_string((int)maxScore));
    window.draw(*scoreText);
}

// int Game::getScore() const {
//     return score;
// }

// void Game::setScore(int score_) {
//     score = score_;
// }

void Game::changeScreen(ScreenType screenType) {
    currentScreen = screenType;
}