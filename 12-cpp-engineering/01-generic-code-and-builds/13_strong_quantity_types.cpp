/*
 Small deterministic in-memory examples; keep assertions enabled. No input or
external services.

Distinct wrapper types encode units in the function signature.

Meters 20 divided by Seconds 4 yields whole speed 5.

Type distinctions prevent reversed arguments from matching; runtime validation
protects the denominator.

O(1) time/storage.

Integer division truncates; document whether a real-valued result is required.
*/
#include <iostream>
#include <cassert>
#include <stdexcept>

struct Meters {
    int value;
};

struct Seconds {
    int value;
};

int wholeSpeed(Meters distance, Seconds duration) {
    if (duration.value <= 0) {
        throw std::invalid_argument("duration");
    }
    return distance.value / duration.value;
}

int main() {
    assert(wholeSpeed(Meters{20}, Seconds{4}) == 5);
    bool rejected = false;
    try {
        wholeSpeed(Meters{2}, Seconds{0});
    } catch (const std::invalid_argument&) {
        rejected = true;
    }
    assert(rejected);
    std::cout << "checks passed\n";
    return 0;
}
