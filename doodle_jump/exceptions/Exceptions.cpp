#include "Exceptions.h"

const char* PlayerOutOfBoundException::what() const noexcept {
    return "Player is out of bound";
}

const char* RandomException::what() const noexcept {
    return "Random exception";
}