#include "Game.h"
#include "./../screen/MainMenu.h"
#include "./../screen/PlayScreen.h"
#include "./../screen/GameOver.h"
#include <iostream>
#include <memory>
#include <string>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

#define PLATFORM_TEXTURE "assets/platform.png"
#define PLATFORM_BREAK_TEXTURE "assets/platform_break.png"
#define PLATFORM_MOVING_TEXTURE "assets/platform_moving.png"
#define PLATFORM_BOOST_TEXTURE "assets/platform_boost.png"
#define POWERUP_JETPACK_TEXTURE "assets/powerup_jetpack.png"
#define POWERUP_SHIELD_TEXTURE "assets/powerup_shield.png"
#define POWERUP_ROCKET_TEXTURE "assets/powerup_rocket.png"

Game::Game() {
    std::cout << "Game constructor called\n";
    currentScreen = ScreenType::MAIN_MENU;
    score = 0;
    maxScore = 0;

    gameObject = &player;

    auto player_ = dynamic_cast<Player*>(gameObject);
    if (player_) {
        player_->setHealth(4);
    } else {
        std::cout << "gameObject is not a Player\n";
    }
    
    initTextures();

    platforms = std::vector<Platform>();
    powerups = std::vector<Powerups>();

    lastPlatform = new Platform();
    
    for (int i = 0; i < 20; i++) {
        auto platform = Platform();
        platform.useGenerator(lastPlatform->getSprite().getPosition());
        platform.assignTexture(pickTexture(platform.getType()));
        platforms.push_back(platform);
        lastPlatform = &platforms[i];
    }

    for (int i = 0; i < 20; i++) {
        auto power = Powerups();
        power.useGenerator(lastPlatform->getSprite().getPosition());
        power.assignTexture(pickTexture(power.getType()));
        powerups.push_back(power);
    }

    font = sf::Font();
    font.loadFromFile("fonts/Valoon.ttf");

    scoreText.setFont(font);
    scoreText.setString(std::to_string(score));
    scoreText.setCharacterSize(36);
    scoreText.setFillColor(sf::Color::Black);
    scoreText.setPosition(20, 20);

    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), windowTitle, sf::Style::Default);
    window.setFramerateLimit(100);
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

void Game::reset() {
    platforms.clear();

    player.setSpritePosition({400, 550});

    lastPlatform = new Platform();
    powerups.clear();

    for (int i = 0; i < 20; i++) {
        auto platform = Platform();
        platform.useGenerator(lastPlatform->getSprite().getPosition());
        platform.assignTexture(pickTexture(platform.getType()));
        platforms.push_back(platform);
        lastPlatform = &platforms[i];
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
            GameOver::render(window, maxScore);
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
    sf::FloatRect lowerPlayerBounds = player.getSprite().getGlobalBounds();
    lowerPlayerBounds.top += lowerPlayerBounds.height - 5;
    lowerPlayerBounds.height = 5;

    // Handle ground collision
    if (lowerPlayerBounds.getPosition().y > 600.0f) {
        if (score > 150) {
            changeScreen(ScreenType::GAME_OVER);
        }
        else
            player.jump();
    }

    // sf::FloatRect playerBounds = player->getSprite().getGlobalBounds();
    for (auto& platform : platforms) {
        // Get only upper part of platform sprite
        sf::FloatRect upperPlatformBounds = platform.getSprite().getGlobalBounds();
        upperPlatformBounds.height = 5;

        // sf::FloatRect platformBounds = platform->getSprite().getGlobalBounds();
        if (lowerPlayerBounds.intersects(upperPlatformBounds)) {
            if (player.getSprite().getPosition().y < platform.getSprite().getPosition().y) {
                // Jump only if player is falling
                if (player.getYVelocity() > 0.2f) {
                    player.jump();

                    if (platform.getType() == PlatformType::BREAKABLE) {
                        // delete platform;
                        auto plat = Platform();
                        plat.useGenerator(lastPlatform->getSprite().getPosition());
                        plat.assignTexture(pickTexture(plat.getType()));
                        platforms[&platform - &platforms[0]] = plat;
                        lastPlatform = &platforms[&platform - &platforms[0]];
                    }
                    else if (platform.getType() == PlatformType::BOOST) {
                        player.setYVelocity(-20.0f);
                    }
                }
            }
        }

        // Handle moving platforms
        if (platform.getType() == PlatformType::MOVING) {
            platform.animateMovement();
        }
    }
}

// void Game::displayDebugInfo() {
//     sf::Text debugText = sf::Text();
//     debugText.setFont(font);
//     sf::Vector2f velocity = player->getVelocity();
//     debugText.setString("xVelocity: " + std::to_string(velocity.x) + "\nyVelocity: " + std::to_string(velocity.y));
//     debugText.setCharacterSize(36);
//     debugText.setFillColor(sf::Color::Black);
//     debugText.setPosition(60, 60);

//     window.draw(debugText);
// }

void Game::play() {
    player.update();
    checkCollision();
    sf::Vector2f velocity = player.getVelocity();

    if (player.getSprite().getPosition().y < 300 && maxScore - score < 200) {
        for (auto& platform : platforms) {
            if (platform.getSprite().getPosition().y > 750.0f) {
                auto plat = Platform();
                plat.useGenerator(lastPlatform->getSprite().getPosition());
                plat.assignTexture(pickTexture(plat.getType()));
                platforms[&platform - &platforms[0]] = plat;
                lastPlatform = &platforms[&platform - &platforms[0]];
            }

            float yVelocity = player.getYVelocity();
            platform.moveSprite({0.0f, -yVelocity});
        }
        for (auto& powerup : powerups) {
            if (powerup.getSprite().getPosition().y > 750.0f) {
                auto power = Powerups();
                power.useGenerator(lastPlatform->getSprite().getPosition());
                power.assignTexture(pickTexture(power.getType()));
                powerups[&powerup - &powerups[0]] = power;

                // powerDrawer.setGameObject(&powerups[&powerup - &powerups[0]]);
                // powerDrawer.draw(window, powerups[&powerup - &powerups[0]].getSprite());
            }

            float yVelocity = player.getYVelocity();
            powerup.moveSprite({0.0f, -yVelocity});
        }
        for (auto& background : backgroundSprite) {
            if (background.getPosition().y > 565.0f) {
                background.setPosition(0, -565);
            }

            float yVelocity = player.getYVelocity();
            if (yVelocity < 0.0f)
                background.move({0.0f, -yVelocity / 5});
        }
    }
    else {
        // funcție virtuala apelata prin pointer
        gameObject->moveSprite({0.0f, velocity.y});
        // player.moveSprite({0.0f, velocity.y});
    }
    player.moveSprite({velocity.x, 0.0f});

    window.clear(sf::Color::White);

    window.draw(backgroundSprite[0]);
    window.draw(backgroundSprite[1]);
    
    player.draw(window);
    for (auto& platform : platforms) {
        platform.draw(window);
    }
    for (auto& powerup : powerups) {
        powerup.draw(window);
    }
    displayScore();
    // displayDebugInfo();

    window.display();
}

void Game::initTextures() {
    /// Platform textures
    platformTextures.emplace_back();
    platformTextures[0].loadFromFile(PLATFORM_TEXTURE);

    platformTextures.emplace_back();
    platformTextures[1].loadFromFile(PLATFORM_BREAK_TEXTURE);

    platformTextures.emplace_back();
    platformTextures[2].loadFromFile(PLATFORM_MOVING_TEXTURE);

    platformTextures.emplace_back();
    platformTextures[3].loadFromFile(PLATFORM_BOOST_TEXTURE);

    /// Powerups textures
    powerupsTextures.emplace_back();
    powerupsTextures[0].loadFromFile(POWERUP_JETPACK_TEXTURE);

    powerupsTextures.emplace_back();
    powerupsTextures[1].loadFromFile(POWERUP_SHIELD_TEXTURE);

    powerupsTextures.emplace_back();
    powerupsTextures[2].loadFromFile(POWERUP_ROCKET_TEXTURE);

    /// Background texture
    backgroundTexture.loadFromFile("assets/bg.jpg");
    backgroundSprite[0].setTexture(backgroundTexture);
    backgroundSprite[1].setTexture(backgroundTexture);
    backgroundSprite[0].setPosition(0, 0);
    backgroundSprite[1].setPosition(0, -565);
}

sf::Texture& Game::pickTexture(PowerupsType powerupsType) {
    switch (powerupsType) {
    case PowerupsType::JETPACK:
        return powerupsTextures[0];
    case PowerupsType::SHIELD:
        return powerupsTextures[1];
    case PowerupsType::ROCKET:
        return powerupsTextures[2];
    default:
        return powerupsTextures[0];
    }
}

sf::Texture& Game::pickTexture(PlatformType platformType) {
    switch (platformType) {
    case PlatformType::NORMAL:
        return platformTextures[0];
    case PlatformType::BREAKABLE:
        return platformTextures[1];
    case PlatformType::MOVING:
        return platformTextures[2];
    case PlatformType::BOOST:
        return platformTextures[3];
    default:
        return platformTextures[0];
    }
}

void Game::displayScore() {
    score -= player.getYVelocity();
    if (score > maxScore)
        maxScore = score;

    scoreText.setString("Score: " + std::to_string((int)maxScore));
    window.draw(scoreText);
}

void Game::changeScreen(ScreenType screenType) {
    currentScreen = screenType;
}