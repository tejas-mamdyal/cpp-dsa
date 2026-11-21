/*
OPTIONAL EXPRESSES AN ORDINARY ABSENT RESULT
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Return optional<int> for a missing integer; check engagement before dereference.
Trace: nonempty vector minimum-2; empty input nullopt.
Why it works: An explicit absence state avoids inventing an int sentinel.
Cost: O(n) time in the length of the data; O(1) auxiliary space.
Common mistake: Never dereference a disengaged optional; absence is not necessarily an exception.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <optional>
#include <vector>

std::optional<int> minimum(const std::vector<int>& values) {
    if (values.empty()) {
        return std::nullopt;
    }
    int best = values[0];
    for (int value : values) {
        if (value < best) {
            best = value;
        }
    }
    return best;
}

int main() {
    auto found = minimum({3, -2, 7});
    assert(found.has_value());
    assert(*found == -2);
    assert(!minimum({}).has_value());
    assert(minimum({}).value_or(99) == 99);
    std::cout << "checks passed\n";
}
