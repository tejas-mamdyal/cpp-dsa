/*
ADD NUMBERS STORED LEAST-SIGNIFICANT DIGIT FIRST PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Input nodes contain digits0..9; empty represents0; output is newly owned. The caller
owns every allocated node unless ownership is explicitly transferred. Test fixtures reclaim
all nodes. IDEA AND STATE: Add current digits and carry, emitting one result digit per step.
TRACE: 2,4,3 plus5,6,4 ->7,0,8, representing342+465=807. CORRECTNESS: Each step fixes the next
decimal digit and carries only the overflow into the next position. COST: O(max(n,m)) time and
output storage,O(1) additional state. PITFALL: Do not mutate/delete borrowed inputs; preserve
final carry. PRACTICE: Change the example, predict each state update and add an empty/boundary
case. No input unless explicitly stated. Assertions are the teaching test harness and must
remain enabled; success prints checks passed. These bounds describe the helper, not a claim
that a fixed-data demonstration has growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

struct Node {
    int value;
    Node* next = nullptr;
    inline static int live = 0;

    explicit Node(int data)
        : value(data) {
        ++live;
    }

    ~Node() {
        --live;
    }

    Node(const Node&) = delete;
    Node& operator=(const Node&) = delete;
};

void clear(Node*& head) {
    while (head != nullptr) {
        Node* victim = head;
        head = head->next;
        delete victim;
    }
}

std::vector<int> view(const Node* head) {
    std::vector<int> out;
    while (head != nullptr) {
        out.push_back(head->value);
        head = head->next;
    }
    return out;
}

Node* build(const std::vector<int>& values) {
    Node* head = nullptr;
    Node* tail = nullptr;
    try {
        for (int value : values) {
            Node* node = new Node(value);
            if (tail == nullptr) {
                head = node;
            } else {
                tail->next = node;
            }
            tail = node;
        }
    } catch (...) {
        clear(head);
        throw;
    }
    return head;
}

Node* addDigits(const Node* a, const Node* b) {
    Node* head = nullptr;
    Node* tail = nullptr;
    int carry = 0;
    try {
        do {
            int sum = carry;
            if (a != nullptr) {
                assert(a->value >= 0 && a->value <= 9);
                sum += a->value;
                a = a->next;
            }
            if (b != nullptr) {
                assert(b->value >= 0 && b->value <= 9);
                sum += b->value;
                b = b->next;
            }
            Node* node = new Node(sum % 10);
            if (tail == nullptr) {
                head = node;
            } else {
                tail->next = node;
            }
            tail = node;
            carry = sum / 10;
        } while (a != nullptr || b != nullptr || carry != 0);
    } catch (...) {
        clear(head);
        throw;
    }
    return head;
}

int main() {
    Node* a = build({2, 4, 3});
    Node* b = build({5, 6, 4});
    Node* out = addDigits(a, b);
    assert((view(out) == std::vector<int>{7, 0, 8}));
    assert((view(a) == std::vector<int>{2, 4, 3}));
    clear(a);
    clear(b);
    clear(out);
    a = build({9, 9});
    b = build({1});
    out = addDigits(a, b);
    assert((view(out) == std::vector<int>{0, 0, 1}));
    clear(a);
    clear(b);
    clear(out);
    out = addDigits(nullptr, nullptr);
    assert((view(out) == std::vector<int>{0}));
    clear(out);
    assert(Node::live == 0);
    std::cout << "checks passed\n";
    return 0;
}
