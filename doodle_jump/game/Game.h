#include "./../platform/Platform.h"
#include "./../platform/PlatformGenerator.h"
#include "./../player/Player.h"
#include "./../screen/GameScreen.h"

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
    sf::Text *scoreText;
    Player *player;
    std::vector<Platform*> platforms;
    PlatformGenerator platformGenerator = PlatformGenerator();
public:
    Game();
    ~Game();
    Game& operator=(const Game& game_);
    Game(const Game& game_);
    friend std::ostream& operator<<(std::ostream& out, const Game& game);
    void run();
    // int getScore() const;
    // void setScore(int score);
    void changeScreen(ScreenType screenType);
    void play();
    void reset();
    void displayDebugInfo();
    void displayScore();
    void checkCollision();
};