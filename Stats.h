#pragma once
#include <array>
#include <iostream>
#include <algorithm>

class Stats {
private:
    int Church, People, Army, Money;
    static int clamp(int x) { return std::max(0, std::min(100, x)); }
public:
    Stats();
    Stats(int c,int p,int a,int m);

    int getChurch() const { return Church; }
    int getPeople() const { return People; }
    int getArmy() const { return Army; }
    int getMoney() const { return Money; }

    void Apply_Effect(const std::array<int,4>& e);

    friend std::ostream &operator<<(std::ostream &os, const Stats &s);
};