/*
 At most 30 elements/vertices, integer magnitudes<=1000; valid structural inputs. No
input required.

A path through a node can use two child branches, while a path passed
upward can use only one.

3-2-4-6 sums 15.

Every simple tree path has a unique highest node joining its downward branches.

O(n) time, O(height) stack.

Initialize best below all legal nonempty path sums to preserve negative-only cases.
*/
#include <iostream>
#include <cassert>
#include <algorithm>
#include <optional>
#include <limits>
#include <memory>

struct Node {
    int value;
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;

    explicit Node(int x)
        : value(x) {
    }
};

std::unique_ptr<Node> sample() {
    auto root = std::make_unique<Node>(4);
    root->left = std::make_unique<Node>(2);
    root->right = std::make_unique<Node>(6);
    root->left->left = std::make_unique<Node>(1);
    root->left->right = std::make_unique<Node>(3);
    return root;
}

int gain(const Node* p, int& best) {
    if (!p) {
        return 0;
    }
    int a = std::max(0, gain(p->left.get(), best));
    int b = std::max(0, gain(p->right.get(), best));
    best = std::max(best, p->value + a + b);
    return p->value + std::max(a, b);
}

std::optional<int> maximum(const Node* p) {
    if (!p) {
        return std::nullopt;
    }
    int best = std::numeric_limits<int>::min();
    gain(p, best);
    return best;
}

int main() {
    auto root = sample();
    assert(maximum(root.get()) == 15);
    Node negative(-5);
    assert(maximum(&negative) == -5);
    std::cout << "checks passed\n";
    return 0;
}
