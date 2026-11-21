/*
A STACK DUMMY SIMPLIFIES HEAD DELETION PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Remove every occurrence and return removed count. The caller owns every allocated
node unless ownership is explicitly transferred. Test fixtures reclaim all nodes. IDEA AND
STATE: A temporary dummy borrows the head link so every victim has a predecessor. TRACE:
2,2,1,2 ->1 and removed3. CORRECTNESS: After a deletion the predecessor stays put to inspect
the new next node; nonmatches advance it. COST: O(n) time,O(1) extra space; removed nodes are
reclaimed. PITFALL: The dummy is automatic, its value is unused, and its destructor does not
own/delete next. PRACTICE: Change the example, predict each state update and add an
empty/boundary case. No input unless explicitly stated. Assertions are the teaching test
harness and must remain enabled; success prints checks passed. These bounds describe the
helper, not a claim that a fixed-data demonstration has growing runtime input.
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

int removeAll(Node*& head, int key) {
    Node dummy(0);
    dummy.next = head;
    Node* previous = &dummy;
    int removed = 0;
    while (previous->next != nullptr) {
        Node* current = previous->next;
        if (current->value == key) {
            previous->next = current->next;
            delete current;
            ++removed;
        } else {
            previous = current;
        }
    }
    head = dummy.next;
    return removed;
}

int main() {
    Node* head = build({2, 2, 1, 2});
    assert(removeAll(head, 2) == 3);
    assert((view(head) == std::vector<int>{1}));
    assert(removeAll(head, 1) == 1);
    assert(head == nullptr);
    assert(removeAll(head, 1) == 0);
    assert(Node::live == 0);
    std::cout << "checks passed\n";
    return 0;
}
