#include "WarEvent.h"
#include "Kingdom.h"
#include <iostream>

WarEvent::WarEvent(int intensity) : BaseEvent("War"), intensity_(intensity) {}

std::unique_ptr<BaseEvent> WarEvent::clone() const {
    return std::make_unique<WarEvent>(*this);
}

void WarEvent::apply(Kingdom &k) const {
    std::array<int,4> effect = { 0, 0, -intensity_ / 2, -intensity_ / 3 };
    k.changeStats(effect);
}

void WarEvent::doPrint(std::ostream &os) const {
    os << "WarEvent (intensity=" << intensity_ << ")\n";
}
