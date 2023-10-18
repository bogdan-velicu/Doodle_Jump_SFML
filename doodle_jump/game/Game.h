#include "./../platform/Platform.h"
#include "./../player/Player.h"
#include "./../screen/GameScreen.h"
#include "./../coordinates/Coordinates.h"

#include <vector>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class Game {
    ScreenType currentScreen;
    sf::RenderWindow window;
    std::string windowTitle;
public:
    Game();
    ~Game();
    friend std::ostream& operator<<(std::ostream& out, const Game& game);
    void run();
    void changeScreen(ScreenType screenType);
    void handleInput(Player& player);
    void update(Player& player, std::vector<Platform>& platforms);
    void render(Player& player, std::vector<Platform>& platforms);
    void checkCollisions(Player& player, std::vector<Platform>& platforms);
};