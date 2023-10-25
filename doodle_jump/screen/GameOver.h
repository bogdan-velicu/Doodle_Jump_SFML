#include "GameScreen.h"
#include <SFML/Graphics.hpp>

class GameOver : private GameScreen {
public:
    GameOver();
    ~GameOver();
    static void render(sf::RenderWindow& window);
    static void handleInput(const sf::Event& event, ScreenType& currentScreen);
};