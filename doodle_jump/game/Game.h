#include "./../platform/Platform.h"
#include "./../player/Player.h"
#include "./../screen/GameScreen.h"
#include "./../powerups/Powerups.h"

#include <queue>
#include <vector>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class Game {
    ScreenType currentScreen;
    sf::RenderWindow window;
    const std::string windowTitle = "Doodle Jump SFML";
    sf::Font font;
    float score;
    float maxScore;
    sf::Text scoreText;
    Player player;
    std::vector<sf::Texture> platformTextures;
    std::vector<Platform> platforms;
    std::vector<Powerups> powerups;
    GameObject *powerup;
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
    void initPlatformTextures();
    sf::Texture& pickTexture(PlatformType platformType);
    void displayScore();
    void checkCollision();
};