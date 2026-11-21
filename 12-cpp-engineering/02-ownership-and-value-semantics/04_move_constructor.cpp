/*
 Small deterministic in-memory examples; keep assertions enabled. No input or
external services.

This custom move transfers a unique_ptr, whose source becomes empty.

a 5 moves into b; then a can be reassigned 6.

unique_ptr transfer gives b exclusive ownership and prevents duplicate deletion.

O(1) time/storage.

A moved-from std:: string is valid but is not generally promised empty; this owner
has a narrower explicit guarantee.
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
    Owner a(5);
    Owner b(std::move(a));
    assert(b.get() == 5 && !a.get());
    a.set(6);
    assert(a.get() == 6);
    std::cout << "checks passed\n";
    return 0;
}
