#include "GameScreen.h"
#include <SFML/Graphics.hpp>

class PlayScreen : private GameScreen {
public:
    PlayScreen();
    ~PlayScreen();
    static void handleInput(const sf::Event& event, ScreenType& currentScreen);
};