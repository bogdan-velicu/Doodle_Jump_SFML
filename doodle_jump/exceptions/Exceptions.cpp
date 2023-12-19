#include "Exceptions.h"

const char* DoodleJumpException::what() const noexcept {
    return "DoodleJumpException";
}

const char* PlayerOutOfBoundException::what() const noexcept {
    return "PlayerOutOfBoundException";
}

const char* InvalidGameStateException::what() const noexcept {
    return "InvalidGameStateException";
}