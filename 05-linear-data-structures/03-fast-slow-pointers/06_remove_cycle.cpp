/*
BREAK THE CYCLE WITHOUT LOSING A NODE PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Remove a cycle if present and preserve the chain reached from its original head. The
caller owns every allocated node unless ownership is explicitly transferred. Test fixtures
reclaim all nodes. IDEA AND STATE: Find entry, then find its predecessor within the cycle and
set that one link to null. TRACE: 1->2->3->2 becomes1->2->3->null. CORRECTNESS: Only the
repeated back-edge is removed; every distinct reachable node stays reachable once. COST: O(n)
time,O(1) space. PITFALL: Handle entry=head and a self-loop, not only a cycle after a prefix.
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

Node* meeting(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return slow;
        }
    }
    return nullptr;
}

Node* cycleEntry(Node* head) {
    Node* hit = meeting(head);
    if (hit == nullptr) {
        return nullptr;
    }
    Node* start = head;
    while (start != hit) {
        start = start->next;
        hit = hit->next;
    }
    return start;
}

bool removeCycle(Node* head) {
    Node* entry = cycleEntry(head);
    if (entry == nullptr) {
        return false;
    }
    Node* last = entry;
    while (last->next != entry) {
        last = last->next;
    }
    last->next = nullptr;
    return true;
}

int main() {
    for (int index = 0; index < 4; ++index) {
        Node* head = build({1, 2, 3, 4});
        Node* target = head;
        for (int i = 0; i < index; ++i) {
            target = target->next;
        }
        Node* tail = head;
        while (tail->next != nullptr) {
            tail = tail->next;
        }
        tail->next = target;
        assert(removeCycle(head));
        assert((view(head) == std::vector<int>{1, 2, 3, 4}));
        assert(!removeCycle(head));
        clear(head);
    }
    Node* one = build({9});
    one->next = one;
    assert(removeCycle(one));
    clear(one);
    assert(Node::live == 0);
    std::cout << "checks passed\n";
    return 0;
}
