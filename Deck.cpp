#include "Deck.h"
#include <iostream>

void Deck::addCard(const Card &card) {
    cards_.push_back(card);
}

const Card &Deck::draw_random_card() const {
    if (cards_.empty()) {
        throw EmptyDeckException();
    }
    int index = rand() % cards_.size();
    return cards_[index];
}
