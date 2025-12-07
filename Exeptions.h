#pragma once
#include <exception>
#include <string>

class GameException : public std::exception {
protected:
    std::string msg_;
public:
    explicit GameException(std::string msg) : msg_(std::move(msg)) {}
    const char* what() const noexcept override { return msg_.c_str(); }
};

class EmptyDeckException : public GameException {
public:
    EmptyDeckException() : GameException("Deck is empty") {}
};

class InvalidChoiceException : public GameException {
public:
    InvalidChoiceException() : GameException("Invalid choice") {}
};

class StatOutOfRangeException : public GameException {
public:
    StatOutOfRangeException() : GameException("Stat out of allowed range") {}
}
;
