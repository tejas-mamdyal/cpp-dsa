/*
STABLE COUNTING SORT RETAINS RECORD ORDER PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Records have key[-3,3] and an arrival serial. IDEA AND STATE: Prefix counts identify
the first output position for each key; scatter input records left-to-right. TRACE: key1
IDs0,2 stay in that order after sorting. CORRECTNESS: Every key gets a disjoint output
interval; advancing its position preserves equal-key arrival order. COST: O(n+7) time,O(n+7)
auxiliary space. PITFALL: Signed keys need an offset; reconstructing only key values loses
attached records. PRACTICE: Change the example, predict each state update and add an
empty/boundary case. No input unless explicitly stated. Assertions are the teaching test
harness and must remain enabled; success prints checks passed. These bounds describe the
helper, not a claim that a fixed-data demonstration has growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

struct Item {
    int key;
    int serial;
};

std::vector<Item> stableCount(const std::vector<Item>& a) {
    int counts[7] = {};
    for (const Item& item : a) {
        assert(item.key >= -3 && item.key <= 3);
        ++counts[item.key + 3];
    }
    int position[7] = {};
    for (int i = 1; i < 7; ++i) {
        position[i] = position[i - 1] + counts[i - 1];
    }
    std::vector<Item> out(a.size());
    for (const Item& item : a) {
        out[position[item.key + 3]++] = item;
    }
    return out;
}

int main() {
    std::vector<Item> a = {{1, 0}, {-1, 1}, {1, 2}, {-3, 3}};
    auto expected = a;
    std::stable_sort(expected.begin(), expected.end(), [](const Item& x, const Item& y) {
        return x.key < y.key;
    });
    auto out = stableCount(a);
    for (std::size_t i = 0; i < a.size(); ++i) {
        assert(out[i].key == expected[i].key && out[i].serial == expected[i].serial);
    }
    assert(stableCount({}).empty());
    std::cout << "checks passed\n";
    return 0;
}
