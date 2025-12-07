#include "Stats.h"
#include <algorithm>
#include <iostream>

Stats::Stats()
    : Church(50), People(50), Army(50), Money(50) {}

Stats::Stats(int c, int p, int a, int m)
    : Church(c), People(p), Army(a), Money(m) {}

void Stats::Apply_Effect(const std::array<int,4>& e) {
    Church = clamp(Church + e[0]);
    People = clamp(People + e[1]);
    Army = clamp(Army + e[2]);
    Money = clamp(Money + e[3]);
}

std::ostream &operator<<(std::ostream &os, const Stats &s) {
    os << "Church: " << s.Church
       << ", People: " << s.People
       << ", Army: " << s.Army
       << ", Money: " << s.Money;
    return os;
}
