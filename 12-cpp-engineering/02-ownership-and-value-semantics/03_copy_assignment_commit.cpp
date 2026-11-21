/*
 Small deterministic in-memory examples; keep assertions enabled. No input or
external services.

Temporary copy is fully constructed before swapping into the destination.

a 2 assigned b 8 becomes 8; self-assignment retains 8.

If allocation throws during temporary construction, the original destination
remains untouched.

O(1) allocation and peak extra one-int resource.

Deleting old storage before allocating replacement loses the original value on
failure.
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
    Owner a(2);
    Owner b(8);
    a = b;
    b.set(4);
    assert(a.get() == 8 && b.get() == 4);
    a = a;
    assert(a.get() == 8);
    std::cout << "checks passed\n";
    return 0;
}
