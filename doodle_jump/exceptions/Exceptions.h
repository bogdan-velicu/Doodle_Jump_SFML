#pragma once

#include <iostream>
#include <exception>

class DoodleJumpException : public std::exception {
public:
    [[nodiscard]] const char* what() const noexcept override;
};

class PlayerOutOfBoundException : public DoodleJumpException {
public:
    [[nodiscard]] const char* what() const noexcept override;
};

class InvalidGameStateException : public DoodleJumpException {
public:
    [[nodiscard]] const char* what() const noexcept override;
};

class DoodleVectorInvalidIndexException : public DoodleJumpException {
public:
    [[nodiscard]] const char* what() const noexcept override;
};