/*
SPLIT ONE OWNER INTO TWO DISJOINT CHAINS PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Position0..length; second owner must initially be null; invalid positions leave
first unchanged. The caller owns every allocated node unless ownership is explicitly
transferred. Test fixtures reclaim all nodes. IDEA AND STATE: Locate the split predecessor
then detach its next link. TRACE: 1,2,3 split1 ->first1,second2,3. CORRECTNESS: Cutting one
link partitions the allocation set without duplication. COST: O(position+1) time,O(1) extra
space. PITFALL: Overwriting an already owning second pointer would leak its old chain.
PRACTICE: Change the example, predict each state update and add an empty/boundary case. No
input unless explicitly stated. Assertions are the teaching test harness and must remain
enabled; success prints checks passed. These bounds describe the helper, not a claim that a
fixed-data demonstration has growing runtime input.
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

bool split(Node*& head, int index, Node*& second) {
    assert(second == nullptr);
    if (index < 0) {
        return false;
    }
    if (index == 0) {
        second = head;
        head = nullptr;
        return true;
    }
    Node* previous = head;
    for (int i = 1; i < index && previous != nullptr; ++i) {
        previous = previous->next;
    }
    if (previous == nullptr) {
        return false;
    }
    second = previous->next;
    previous->next = nullptr;
    return true;
}

int main() {
    Node* head = build({1, 2, 3});
    Node* second = nullptr;
    assert(!split(head, 4, second));
    assert((view(head) == std::vector<int>{1, 2, 3}));
    assert(split(head, 1, second));
    assert((view(head) == std::vector<int>{1}));
    assert((view(second) == std::vector<int>{2, 3}));
    clear(head);
    clear(second);
    head = build({7});
    assert(split(head, 0, second));
    assert(head == nullptr);
    clear(second);
    assert(Node::live == 0);
    std::cout << "checks passed\n";
    return 0;
}
