/*
 Small deterministic in-memory examples; keep assertions enabled. No input or
external services.

The type trait queries whether constructing from an rvalue is nonthrowing.

Vector growth can relocate Owner handles through noexcept move.

Moving handles does not allocate the resource, so the declared guarantee is
satisfied.

O(n) total handle relocations across growth, O(n) resource storage.

Declaring noexcept on an operation that actually throws terminates the program.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <optional>
#include <utility>
#include <memory>
#include <type_traits>

class Owner {
    std::unique_ptr<int> value;

public:
    explicit Owner(int x)
        : value(std::make_unique<int>(x)) {
    }

    Owner(const Owner& other)
        : value(other.value ? std::make_unique<int>(*other.value) : nullptr) {
    }

    Owner& operator=(const Owner& other) {
        if (this != &other) {
            Owner temporary(other);
            swap(temporary);
        }
        return *this;
    }

    Owner(Owner&& other) noexcept
        : value(std::move(other.value)) {
    }

    Owner& operator=(Owner&& other) noexcept {
        if (this != &other) {
            value = std::move(other.value);
        }
        return *this;
    }

    ~Owner() = default;

    void swap(Owner& other) noexcept {
        value.swap(other.value);
    }

    std::optional<int> get() const {
        if (!value) {
            return std::nullopt;
        }
        return *value;
    }

    void set(int x) {
        if (!value) {
            value = std::make_unique<int>(x);
        } else {
            *value = x;
        }
    }
};

int main() {
    static_assert(std::is_nothrow_move_constructible_v<Owner>, "owner move must not throw");
    std::vector<Owner> a;
    a.emplace_back(4);
    a.emplace_back(9);
    assert(a[0].get() == 4 && a[1].get() == 9);
    std::cout << "checks passed\n";
    return 0;
}
