/*
 Small deterministic in-memory examples; keep assertions enabled. No input or
external services.

A unique_ptr represents exactly one owning handle; custom copy allocates a
new int.

a 7 copied to b 7; changing b 9 leaves a 7.

Distinct allocations prevent aliasing of owned mutable state.

O(1) for this one-int resource.

Default-copying a raw owning pointer would cause shared mutation and double deletion.
*/
#include <iostream>
#include <cassert>
#include <optional>
#include <utility>
#include <memory>

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
    Owner a(7);
    Owner b(a);
    b.set(9);
    assert(a.get() == 7 && b.get() == 9);
    std::cout << "checks passed\n";
    return 0;
}
