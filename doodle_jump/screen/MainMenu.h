#include "GameScreen.h"
#include <SFML/Graphics.hpp>

class MainMenu : private GameScreen {
public:
    MainMenu();
    ~MainMenu();
    static void render(sf::RenderWindow& window);
    static void handleInput(sf::Event& event, ScreenType& currentScreen);
};