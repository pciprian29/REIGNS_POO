#pragma once
#include <string>
#include <memory>
#include <ostream>

class Kingdom;

class BaseEvent {
protected:
    std::string name_;
    static int eventCount_;
public:
    explicit BaseEvent(std::string name);
    virtual ~BaseEvent();


    virtual void apply(Kingdom &k) const = 0;

    virtual std::unique_ptr<BaseEvent> clone() const = 0;

    void print() const;
protected:
    virtual void doPrint(std::ostream &os) const;
};
