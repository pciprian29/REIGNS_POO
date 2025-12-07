#include "GameManager.h"
#include <iostream>
#include <chrono>

GameManager::GameManager() {
    auto seed = static_cast<unsigned>(std::chrono::high_resolution_clock::now().time_since_epoch().count());
    rng_.seed(seed);
}

void GameManager::addEvent(std::unique_ptr<BaseEvent> ev) {
    events_.push_back(std::move(ev));
}

void GameManager::triggerRandomEvent(Kingdom &k) {
    if (events_.empty()) return;
    std::uniform_int_distribution<std::size_t> dist(0, events_.size() - 1);
    std::size_t idx = dist(rng_);
    BaseEvent* ev = events_[idx].get();
    ev->print();
    ev->apply(k);

    if (auto const warEv = dynamic_cast<const WarEvent*>(ev)) {
    std::cout << "War Event cu intensitate: " << warEv->getIntensity() << "\n";
}
}






