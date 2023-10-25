#pragma once

#include <iostream>

enum class ScreenType {
    MAIN_MENU,
    PLAY,
    GAME_OVER,
    CLOSE
};

inline std::ostream& operator<<(std::ostream& out, const ScreenType& screenType) {
    switch(screenType) {
    case ScreenType::MAIN_MENU:
        out << "MAIN_MENU";
        break;
    case ScreenType::PLAY:
        out << "PLAY";
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
private:
    ScreenType screenType;
public:
    GameScreen();
    ~GameScreen();
    explicit GameScreen(ScreenType screenType);
    friend std::ostream& operator<<(std::ostream& out, const ScreenType& screenType);
    // ScreenType getScreenType() const;
    void setScreenType(ScreenType screenType);
    void render();
};