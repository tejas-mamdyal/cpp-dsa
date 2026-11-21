/*
LINKS OBSERVE OBJECTS; OWNERSHIP CONTROLS DELETION PREREQUISITES: Phases1/2 C++ and STL,

README order, not old filenames.

 Automatic nodes and borrowed next pointers. The caller owns every allocated node
unless ownership is explicitly transferred. Test fixtures reclaim all nodes. IDEA AND STATE:
Connect local nodes without allocating and watch their scope end. TRACE: 10 points to20;
following next reads20. CORRECTNESS: The pointer designates the second live object; neither
next link automatically deletes another object. COST: O(1) operations and bounded automatic
storage. PITFALL: Never delete an automatic node or follow a link after its target lifetime
ends. PRACTICE: Change the example, predict each state update and add an empty/boundary case.
No input unless explicitly stated. Assertions are the teaching test harness and must remain
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

int main() {
    {
        Node first(10);
        Node second(20);
        first.next = &second;
        assert(first.next->value == 20);
        assert(second.next == nullptr);
        assert(Node::live == 2);
    }
    assert(Node::live == 0);
    std::cout << "checks passed\n";
    return 0;
}
