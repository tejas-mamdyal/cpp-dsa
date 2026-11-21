/*
COMPARE LIST HALVES AND RESTORE BORROWED INPUT PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Acyclic list; return a palindrome result without leaving the list reversed. The
caller owns every allocated node unless ownership is explicitly transferred. Test fixtures
reclaim all nodes. IDEA AND STATE: Find first-half end, reverse the second half, compare, then
reverse it back on every path. TRACE: 1,2,2,1 is true and remains1,2,2,1 afterward.
CORRECTNESS: Mirrored halves agree exactly for a palindrome; restoring links preserves the
observation-only API. COST: O(n) time,O(1) extra space. PITFALL: Do not return immediately on
a mismatch before restoring the second half. PRACTICE: Change the example, predict each state
update and add an empty/boundary case. No input unless explicitly stated. Assertions are the
teaching test harness and must remain enabled; success prints checks passed. These bounds
describe the helper, not a claim that a fixed-data demonstration has growing runtime input.
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

Node* reverse(Node* head) {
    Node* previous = nullptr;
    while (head != nullptr) {
        Node* next = head->next;
        head->next = previous;
        previous = head;
        head = next;
    }
    return previous;
}

bool palindrome(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return true;
    }
    Node* slow = head;
    Node* fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* half = reverse(slow->next);
    slow->next = half;
    bool equal = true;
    Node* left = head;
    for (Node* right = half; right != nullptr; right = right->next) {
        if (left->value != right->value) {
            equal = false;
        }
        left = left->next;
    }
    slow->next = reverse(half);
    return equal;
}

int main() {
    for (std::vector<int> a :
         std::vector<std::vector<int>>{{}, {1}, {1, 2, 1}, {1, 2, 2, 1}, {1, 2, 3}, {1, 2, 3, 1}}) {
        Node* head = build(a);
        bool expected = std::equal(a.begin(), a.end(), a.rbegin());
        assert(palindrome(head) == expected);
        assert(view(head) == a);
        clear(head);
    }
    assert(Node::live == 0);
    std::cout << "checks passed\n";
    return 0;
}
