#pragma once
#include "BaseEvent.h"
#include <array>

class WarEvent : public BaseEvent {
    int intensity_;
public:
    explicit WarEvent(int intensity = 25);
    int getIntensity() const { return intensity_; } // getter adaugat
    ~WarEvent() override = default;

    void apply(Kingdom &k) const override;
    std::unique_ptr<BaseEvent> clone() const override;
protected:
    void doPrint(std::ostream &os) const override;
};

