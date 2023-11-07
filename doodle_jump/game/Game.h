#include "./../platform/Platform.h"
#include "./../player/Player.h"
#include "./../screen/GameScreen.h"
#include "./../powerups/Powerups.h"

#include <vector>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <memory>

class Game {
    ScreenType currentScreen;
    sf::RenderWindow window;
    const std::string windowTitle = "Doodle Jump SFML";
    sf::Font font;
    float score;
    float maxScore;
    sf::Text scoreText;
    Player player;

    sf::Sprite backgroundSprite[2] = { sf::Sprite(), sf::Sprite() };
    std::vector<sf::Texture> platformTextures = std::vector<sf::Texture>();
    std::vector<sf::Texture> powerupsTextures = std::vector<sf::Texture>();
    sf::Texture backgroundTexture = sf::Texture();

    std::vector<Platform> platforms;
    std::vector<Powerups> powerups;
    GameObject *gameObject;

    Platform *lastPlatform;
public:
    Game();
    ~Game();
    Game(const Game& game) = delete;
    Game& operator=(const Game& game) = delete;
    friend std::ostream& operator<<(std::ostream& out, const Game& game);
    void run();
    void changeScreen(ScreenType screenType);
    void play();
    void reset();
    // void displayDebugInfo();
    void initTextures();
    sf::Texture& pickTexture(PlatformType platformType);
    sf::Texture& pickTexture(PowerupsType powerupsType);
    void displayScore();
    void checkCollision();
};