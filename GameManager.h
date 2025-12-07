#pragma once
#include <vector>
#include <memory>
#include <random>
#include "BaseEvent.h"
#include "Deck.h"
#include "Kingdom.h"
#include "WarEvent.h"

class GameManager {
private:
    std::vector<std::unique_ptr<BaseEvent>> events_;
    std::mt19937 rng_;
public:
    GameManager();
    ~GameManager() = default;

    void addEvent(std::unique_ptr<BaseEvent> ev);
    void triggerRandomEvent(Kingdom &k);
    void listEvents() const;
};
