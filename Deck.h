#pragma once
#include <vector>
#include <cstdlib>
#include "Card.h"
#include "Exeptions.h" // Pentru EmptyDeckException
class Deck {
private:
    std::vector<Card> cards_;

public:
    Deck() = default;
    ~Deck() = default;

    void addCard(const Card &card);
    const Card &draw_random_card() const;
    void displaycards() const;
};