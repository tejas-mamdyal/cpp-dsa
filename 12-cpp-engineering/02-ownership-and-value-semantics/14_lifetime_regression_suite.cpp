/*
 Small deterministic in-memory examples; keep assertions enabled. No input or
external services.

A deterministic operation sequence exercises the public lifetime
invariants.

Copies retain prior values while moved-from custom owners are empty.

Independent expected scalar values detect aliasing and lost-resource state; RAII
releases remaining allocations.

O(n) operations/storage.

Runtime checks do not prove leak freedom alone; run sanitizers where supported.
*/
#include <iostream>
#include <cassert>
#include <vector>
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
    for (int x = 0; x < 20; ++x) {
        Owner a(x);
        Owner b = a;
        a.set(-1);
        assert(b.get() == x);
        Owner d(std::move(b));
        assert(!b.get() && d.get() == x);
        d = d;
        Owner* alias = &d;
        d = std::move(*alias);
        assert(d.get() == x);
    }
    std::vector<Owner> owners;
    for (int i = 0; i < 30; ++i) {
        owners.emplace_back(i);
    }
    for (int i = 0; i < 30; ++i) {
        assert(owners[i].get() == i);
    }
    std::cout << "checks passed\n";
    return 0;
}
