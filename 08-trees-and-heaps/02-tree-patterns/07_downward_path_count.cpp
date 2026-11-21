/*
 Owned binary tree with at most 100 nodes; empty tree is a null unique_ptr; int values
may repeat. Unless narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive
examples assume valid acyclic owned structures; exponential searches use the smaller bounds
stated here. No input; keep assertions enabled. Success prints checks passed.

Prefix sums count downward paths ending at each node, not just
root-starting paths. Undo frequency before returning to siblings.

A chain 1,-1,1 has three target 1 paths: each 1 singleton and the full chain.

Earlier prefixes on the current route identify exactly ancestor starts; removing
the current prefix prevents cross-branch fictitious paths.

O(n log(n+1)) time with ordered map, O(height) active map/stack.

Keeping sibling prefixes would combine nodes from different routes.
*/
#include <iostream>
#include <cassert>
#include <memory>
#include <map>

// Each child is owned by exactly one unique_ptr. Raw Node* below only borrows.
struct Node {
    int value;
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;

    explicit Node(int x)
        : value(x) {
    }
};

using Tree = std::unique_ptr<Node>;

Tree node(int value) {
    return std::make_unique<Node>(value);
}

Tree sample() {
    auto root = node(4);
    root->left = node(2);
    root->right = node(6);
    root->left->left = node(1);
    root->left->right = node(3);
    root->right->left = node(5);
    root->right->right = node(7);
    return root;
}

long long
count(const Node* root, long long sum, long long target, std::map<long long, int>& frequency) {
    if (!root) {
        return 0;
    }
    sum += root->value;
    long long total = 0;
    auto found = frequency.find(sum - target);
    if (found != frequency.end()) {
        total += found->second;
    }
    ++frequency[sum];
    total += count(root->left.get(), sum, target, frequency);
    total += count(root->right.get(), sum, target, frequency);
    --frequency[sum]; // Remove this route prefix before exploring a sibling subtree.
    if (frequency[sum] == 0) {
        frequency.erase(sum);
    }
    return total;
}

long long downward(const Node* root, long long target) {
    std::map<long long, int> frequency{{0, 1}};
    return count(root, 0, target, frequency);
}

int main() {
    auto root = node(1);
    root->left = node(-1);
    root->left->left = node(1);
    assert(downward(root.get(), 1) == 3);
    assert(downward(nullptr, 0) == 0);
    root = node(0);
    root->left = node(0);
    root->right = node(0);
    assert(downward(root.get(), 0) == 5);
    std::cout << "checks passed\n";
    return 0;
}
