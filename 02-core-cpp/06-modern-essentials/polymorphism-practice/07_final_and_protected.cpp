/*
PROTECTED STATE AND FINAL OVERRIDES
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: A derived class can access protected base state; final closes an override to further overriding.
Trace: a doubled sensor reading3 reports6.
Why it works: The derived implementation reads inherited protected state through its own object.
Cost: O(1) time and space.
Common mistake: protected does not mean public. Prefer private state and protected/public accessors when an invariant needs protection.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>

class Sensor {
protected:
    int raw;

public:
    explicit Sensor(int value)
        : raw(value) {
    }

    virtual ~Sensor() = default;

    virtual int read() const {
        return raw;
    }
};

class Doubled final : public Sensor {
public:
    explicit Doubled(int value)
        : Sensor(value) {
    }

    int read() const override final {
        return raw * 2;
    }
};

int main() {
    Doubled sensor(3);
    assert(sensor.read() == 6);
    std::cout << "checks passed\n";
}
