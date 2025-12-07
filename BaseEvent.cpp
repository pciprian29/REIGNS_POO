
#include "BaseEvent.h"
#include <iostream>

int BaseEvent::eventCount_ = 0;

BaseEvent::BaseEvent(std::string name) : name_(std::move(name)) {
    ++eventCount_;
}

BaseEvent::~BaseEvent() = default;

void BaseEvent::print() const {
    doPrint(std::cout);
}

void BaseEvent::doPrint(std::ostream &os) const {
    os << "Event: " << name_ << '\n';
}
