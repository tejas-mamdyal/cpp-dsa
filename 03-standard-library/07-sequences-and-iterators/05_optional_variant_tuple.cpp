/*
UTILITY TYPES EXPRESS MULTIPLE RESULT SHAPES
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: A tuple groups fields, optional expresses absence, variant holds one of several types.
Trace: tuple score90, optional empty fallback-1, variant string Ada.
Why it works: Each type makes the result shape explicit instead of encoding it in a sentinel.
Cost: O(n) for stored string copies, O(1) bounded tags/handles.
Common mistake: get of the wrong variant alternative throws; inspect the active alternative first.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <tuple>
#include <optional>
#include <variant>
#include <string>

int main() {
    std::tuple<int, std::string> record{90, "Ada"};
    auto [score, name] = record;
    assert(score == 90 && name == "Ada");
    std::optional<int> absent;
    assert(absent.value_or(-1) == -1);
    std::variant<int, std::string> field = std::string("Ada");
    assert(std::holds_alternative<std::string>(field));
    assert(std::get<std::string>(field) == "Ada");
    std::cout << "checks passed\n";
}
