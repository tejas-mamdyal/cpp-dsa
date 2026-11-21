/*
OWNING SINGLY LINKED LIST WITH HEAD AND TAIL PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Noncopyable owner; front/back insertion and safe front deletion. The caller owns
every allocated node unless ownership is explicitly transferred. Test fixtures reclaim all
nodes. IDEA AND STATE: Head owns the chain; tail observes the last node for O(1) append.
TRACE: Front2,front1,back3 ->1,2,3;drain ->both head/tail null. CORRECTNESS: Every update
preserves empty iff both endpoints are null and nonempty tail.next is null. COST: O(1)
front/back insertion and front erasure; O(n) cleanup/snapshot. PITFALL: Reset tail when
deleting the final node. PRACTICE: Change the example, predict each state update and add an
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

class LinkedList {
    Node* head = nullptr;
    Node* tail = nullptr;

public:
    LinkedList() = default;
    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;

    ~LinkedList() {
        clear(head);
    }

    void insertFront(int value) {
        Node* node = new Node(value);
        node->next = head;
        head = node;
        if (tail == nullptr) {
            tail = node;
        }
    }

    void insertBack(int value) {
        Node* node = new Node(value);
        if (tail == nullptr) {
            head = node;
        } else {
            tail->next = node;
        }
        tail = node;
    }

    bool deleteFront() {
        if (head == nullptr) {
            return false;
        }
        Node* old = head;
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        }
        delete old;
        return true;
    }

    std::vector<int> values() const {
        return view(head);
    }
};

int main() {
    {
        LinkedList list;
        assert(!list.deleteFront());
        list.insertFront(2);
        list.insertFront(1);
        list.insertBack(3);
        assert((list.values() == std::vector<int>{1, 2, 3}));
        assert(list.deleteFront());
        assert(list.deleteFront());
        assert(list.deleteFront());
        assert(list.values().empty());
        list.insertBack(7);
        assert((list.values() == std::vector<int>{7}));
    }
    assert(Node::live == 0);
    std::cout << "checks passed\n";
    return 0;
}
