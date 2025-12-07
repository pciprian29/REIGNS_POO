#pragma once
#include "BaseEvent.h"
#include <array>

class FestivalEvent : public BaseEvent {
    int scale_;
public:
    explicit FestivalEvent(int scale = 20);
    ~FestivalEvent() override = default;

    void apply(Kingdom &k) const override;
    std::unique_ptr<BaseEvent> clone() const override;
protected:
    void doPrint(std::ostream &os) const override;
};
