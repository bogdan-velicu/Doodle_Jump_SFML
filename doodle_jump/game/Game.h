#include "./../platform/Platform.h"
#include "./../player/Player.h"
#include "./../coordinates/Coordinates.h"
#include "./../screen/GameScreen.h"

#include <vector>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class Game {
    ScreenType currentScreen;
    sf::RenderWindow window;
    std::string windowTitle;
    sf::Font font;
    int score;
    sf::Text scoreText;
    Player* player;
    std::vector<Platform> platforms;
public:
    Game();
    ~Game();
    friend std::ostream& operator<<(std::ostream& out, const Game& game);
    void run();
    int getScore() const;
    void setScore(int score);
    void changeScreen(ScreenType screenType);
    void play();
    void displayScore();
};