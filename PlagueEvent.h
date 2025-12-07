#pragma once
#include "BaseEvent.h"
#include <array>

class PlagueEvent : public BaseEvent {
    int severity_;
public:
    explicit PlagueEvent(int severity = 30);
    ~PlagueEvent() override = default;

    void apply(Kingdom &k) const override;
    std::unique_ptr<BaseEvent> clone() const override;
protected:
    void doPrint(std::ostream &os) const override;
};
