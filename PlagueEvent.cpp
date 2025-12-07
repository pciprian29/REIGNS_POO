#include "PlagueEvent.h"
#include "Kingdom.h"
#include <iostream>

PlagueEvent::PlagueEvent(int severity) : BaseEvent("Plague"), severity_(severity) {}

std::unique_ptr<BaseEvent> PlagueEvent::clone() const {
    return std::make_unique<PlagueEvent>(*this);
}

void PlagueEvent::apply(Kingdom &k) const {

    std::array<int,4> effect = { -severity_ / 5, -severity_ / 3, 0, -severity_ / 10 };
    k.changeStats(effect);
}

void PlagueEvent::doPrint(std::ostream &os) const {
    os << "PlagueEvent (severity=" << severity_ << ")\n";
}
