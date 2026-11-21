/*
 Small deterministic in-memory examples; keep assertions enabled. No input or
external services.

decltype(item) is its declared reference type; decay_t removes
reference/const for the type trait.

An int active alternative invokes the integral conversion branch.

std:: visit invokes the visitor with exactly the active value type.

O(rendered length) time/output.

Every alternative must produce a compatible visitor result type.
*/
#include <iostream>
#include <cassert>
#include <string>
#include <type_traits>
#include <variant>

std::string render(const std::variant<int, std::string>& value) {
    return std::visit(
        [](const auto& item) -> std::string {
            if constexpr (std::is_integral_v<std::decay_t<decltype(item)>>) {
                return std::to_string(item);
            } else {
                return item;
            }
        },
        value);
}

int main() {
    assert(render(42) == "42" && render(std::string("ok")) == "ok");
    std::cout << "checks passed\n";
    return 0;
}
