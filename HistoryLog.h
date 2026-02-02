#pragma once
#include <vector>
#include <iostream>

template <typename T>
class HistoryLog {
private:
    std::vector<T> logs;
public:
    void addEntry(T entry) {
        logs.push_back(entry);
    }

    void showHistory() const {
        for (const auto& entry : logs) {
            std::cout << "[Log]: " << entry << std::endl;
        }
    }
};