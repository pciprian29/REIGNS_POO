#include "FestivalEvent.h"
#include "Kingdom.h"
#include <iostream>

FestivalEvent::FestivalEvent(int scale) : BaseEvent("Festival"), scale_(scale) {}

std::unique_ptr<BaseEvent> FestivalEvent::clone() const {
    return std::make_unique<FestivalEvent>(*this);
}

void FestivalEvent::apply(Kingdom &k) const {

    std::array<int,4> effect = { +scale_ / 5, +scale_ / 3, 0, -scale_ / 2 };
    k.changeStats(effect);
}

void FestivalEvent::doPrint(std::ostream &os) const {
    os << "FestivalEvent (scale=" << scale_ << ")\n";
}
