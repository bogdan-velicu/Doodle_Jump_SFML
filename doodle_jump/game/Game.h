#include "./../platform/Platform.h"
#include "./../player/Player.h"
#include "./../screen/GameScreen.h"

#include <queue>
#include <vector>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class Game {
    ScreenType currentScreen;
    sf::RenderWindow window;
    std::string windowTitle;
    sf::Font font;
    int score;
    int maxScore;
    sf::Text *scoreText;
    Player *player;
    std::vector<Platform*> platforms;
public:
    Game();
    ~Game();
    friend std::ostream& operator<<(std::ostream& out, const Game& game);
    void run();
    int getScore() const;
    void setScore(int score);
    void changeScreen(ScreenType screenType);
    void play();
    void reset();
    void displayDebugInfo();
    void displayScore();
    void checkCollision();
};