#pragma once
#include <string>
#include <array>
#include <iostream>

class Card {
private:
    int id_;
    std::string question_;
    std::string left_option_;
    std::string right_option_;
    std::array<int, 4> left_stat_update_;
    std::array<int, 4> right_stat_update_;

public:
    Card(int id, std::string const &question, std::string const &left_option, std::string const &right_option,
         std::array<int, 4> const &left_stat_update, std::array<int, 4> const &right_stat_update);

    void display_question() const;

    const std::array<int, 4> &getEffect(int choice) const;

    friend std::ostream &operator<<(std::ostream &os, const Card &c);

    ~Card() = default;
};