#include "Kingdom.h"
#include <algorithm>

Kingdom::Kingdom(std::string const &name, Stats const &stats) : name_(name), stats_(stats) {}

Kingdom::Kingdom(const Kingdom &other) : name_(other.name_), stats_(other.stats_) {}

Kingdom &Kingdom::operator=(const Kingdom &other) {
    if (this != &other) {
        name_ = other.name_;
        stats_ = other.stats_;
    }
    return *this;
}

void Kingdom::changeStats(const std::array<int,4> &delta) {
    stats_.Apply_Effect(delta);
}

bool Kingdom::isFallen() const {
    return (stats_.getChurch() == 0 || stats_.getPeople() == 0 ||
            stats_.getArmy() == 0 || stats_.getMoney() == 0 ||
            stats_.getChurch() == 100 || stats_.getPeople() == 100 ||
            stats_.getArmy() == 100 || stats_.getMoney() == 100);
}

void Kingdom::displayStatus(std::ostream &os) const {
    os << "Kingdom: " << name_ << " | " << stats_ << '\n';
}
