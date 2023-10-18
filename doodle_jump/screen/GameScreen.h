#include <iostream>

enum class ScreenType {
    MAIN_MENU,
    GAME,
    GAME_OVER
};

inline std::ostream& operator<<(std::ostream& out, const ScreenType& screenType) {
    switch(screenType) {
    case ScreenType::MAIN_MENU:
        out << "MAIN_MENU";
        break;
    case ScreenType::GAME:
        out << "GAME";
        break;
    case ScreenType::GAME_OVER:
        out << "GAME_OVER";
        break;
    default:
        out << "Invalid screen type";
        break;
    }
    return out;
}

class GameScreen {
public:
    GameScreen();
    friend std::ostream& operator<<(std::ostream& out, const ScreenType& screenType);
    void render();
};