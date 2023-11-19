#include <iostream>

class PlayerOutOfBoundException : public std::exception {
public:
    [[nodiscard]] const char* what() const noexcept override;
};

class RandomException : public std::exception {
public:
    [[nodiscard]] const char* what() const noexcept override;
};