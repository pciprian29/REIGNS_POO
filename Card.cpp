#include "Card.h"
#include <utility>

Card::Card(int id, std::string const &question, std::string const &left_option, std::string const &right_option,
           std::array<int, 4> const &left_stat_update, std::array<int, 4> const &right_stat_update)
    : id_(id),
      question_(question),
      left_option_(left_option),
      right_option_(right_option),
      left_stat_update_(left_stat_update),
      right_stat_update_(right_stat_update) {}

void Card::display_question() const {
    std::cout << question_ << '\n';
    std::cout << "1) " << left_option_ << '\n';
    std::cout << "2) " << right_option_ << '\n';
}

const std::array<int, 4> &Card::getEffect(int choice) const {

    if (choice == 1) return left_stat_update_;
    return right_stat_update_;
}

std::ostream &operator<<(std::ostream &os, const Card &c) {
    os << "ID: " << c.id_ << " | Question: " << c.question_ << '\n';
    os << "  1) " << c.left_option_ << '\n';
    os << "  2) " << c.right_option_ << '\n';
    return os;
}