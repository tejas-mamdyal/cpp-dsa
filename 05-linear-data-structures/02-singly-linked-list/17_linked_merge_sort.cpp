/*
SORT A LIST BY SPLITTING AND MERGING OWNED NODES PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Acyclic uniquely owned list,n<=1000;return its new owning head. IDEA AND STATE:
Count length,split at the midpoint,recursively sort both disjoint halves and merge their
nodes. TRACE: 3,1,2 ->halves3 and1,2 ->merged1,2,3. CORRECTNESS: The split partitions the
nodes; sorted-head merge emits the smallest remaining node each step. COST: O(n log(n+1))
time,O(log(n+1)) recursive stack; no new data nodes. PITFALL: The old head is not a second
owner after relinking; assign the returned head and delete each final node once. PRACTICE:
Change the example, predict each state update and add an empty/boundary case. No input unless
explicitly stated. Assertions are the teaching test harness and must remain enabled; success
prints checks passed. These bounds describe the helper, not a claim that a fixed-data
demonstration has growing runtime input.
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
        Node* old = head;
        head = head->next;
        delete old;
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

Node* build(const std::vector<int>& a) {
    Node* head = nullptr;
    Node* tail = nullptr;
    try {
        for (int value : a) {
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

Node* mergeNodes(Node* a, Node* b) {
    Node dummy(0);
    Node* tail = &dummy;
    while (a != nullptr && b != nullptr) {
        if (a->value <= b->value) {
            tail->next = a;
            a = a->next;
        } else {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }
    if (a != nullptr) {
        tail->next = a;
    } else {
        tail->next = b;
    }
    return dummy.next;
}

Node* sortList(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    int length = 0;
    for (Node* p = head; p != nullptr; p = p->next) {
        ++length;
    }
    Node* split = head;
    for (int i = 1; i < length / 2; ++i) {
        split = split->next;
    }
    Node* second = split->next;
    split->next = nullptr;
    Node* left = sortList(head);
    Node* right = sortList(second);
    return mergeNodes(left, right);
}

int main() {
    for (int n = 0; n <= 5; ++n) {
        int total = 1;
        for (int i = 0; i < n; ++i) {
            total *= 3;
        }
        for (int code = 0; code < total; ++code) {
            int x = code;
            std::vector<int> a(static_cast<std::size_t>(n));
            for (int& value : a) {
                value = x % 3;
                x /= 3;
            }
            Node* head = build(a);
            int allocated = Node::live;
            head = sortList(head);
            assert(Node::live == allocated);
            std::sort(a.begin(), a.end());
            assert(view(head) == a);
            clear(head);
            assert(Node::live == 0);
        }
    }
    std::cout << "checks passed\n";
    return 0;
}
