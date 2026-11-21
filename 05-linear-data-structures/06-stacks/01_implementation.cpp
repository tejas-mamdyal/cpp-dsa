/*
ARRAY AND UNIQUELY OWNED LINKED STACKS PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 push/pop/top use a consistent underflow exception policy. IDEA AND STATE: The vector
back and linked head both represent the top. TRACE: push1,push2,pop ->top1. CORRECTNESS: Both
representations add and remove the most recently pushed live value. COST: Vector push
amortized O(1),linked push/pop O(1); O(n) owned storage. PITFALL: Linked owners forbid copying
and clean every node; vector growth can invalidate observers. PRACTICE: Change the example,
predict each state update and add an empty/boundary case. No input unless explicitly stated.
Assertions are the teaching test harness and must remain enabled; success prints checks
passed. These bounds describe the helper, not a claim that a fixed-data demonstration has
growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <stdexcept>

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

class ArrayStack {
    std::vector<int> data;

public:
    void push(int value) {
        data.push_back(value);
    }

    void pop() {
        if (data.empty()) {
            throw std::underflow_error("empty stack");
        }
        data.pop_back();
    }

    int top() const {
        if (data.empty()) {
            throw std::underflow_error("empty stack");
        }
        return data.back();
    }
};

class LinkedListStack {
    Node* head = nullptr;

public:
    LinkedListStack() = default;
    LinkedListStack(const LinkedListStack&) = delete;
    LinkedListStack& operator=(const LinkedListStack&) = delete;

    ~LinkedListStack() {
        clear(head);
    }

    void push(int value) {
        Node* node = new Node(value);
        node->next = head;
        head = node;
    }

    void pop() {
        if (head == nullptr) {
            throw std::underflow_error("empty stack");
        }
        Node* old = head;
        head = head->next;
        delete old;
    }

    int top() const {
        if (head == nullptr) {
            throw std::underflow_error("empty stack");
        }
        return head->value;
    }
};

int main() {
    {
        ArrayStack array;
        LinkedListStack linked;
        for (int value = 0; value < 20; ++value) {
            array.push(value);
            linked.push(value);
            assert(array.top() == linked.top());
        }
        for (int value = 19; value >= 0; --value) {
            assert(linked.top() == value);
            array.pop();
            linked.pop();
        }
        bool arrayError = false;
        bool linkedError = false;
        try {
            array.pop();
        } catch (const std::underflow_error&) {
            arrayError = true;
        }
        try {
            linked.pop();
        } catch (const std::underflow_error&) {
            linkedError = true;
        }
        assert(arrayError && linkedError);
    }
    assert(Node::live == 0);
    std::cout << "checks passed\n";
    return 0;
}
