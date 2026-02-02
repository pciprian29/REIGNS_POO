#pragma once
#include <string>
#include <array>
#include <ostream>
#include "Stats.h"

class Kingdom {
private:
    std::string name_;
    Stats stats_;
public:
    Kingdom(std::string const &name, Stats const &stats);
    Kingdom(const Kingdom &other);
    Kingdom &operator=(const Kingdom &other);
    ~Kingdom() = default;

    void changeStats(const std::array<int,4> &delta);
    bool isFallen() const;
    void displayStatus(std::ostream &os) const;

    friend std::ostream &operator<<(std::ostream &os, const Kingdom &k) {
        k.displayStatus(os); return os;
    }
    const Stats& stats() const { return stats_; }

};


