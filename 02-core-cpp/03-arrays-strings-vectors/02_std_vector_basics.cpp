#include <iostream>
#include <vector>

using namespace std;

// Use a reference for an alias/view when copying is unnecessary; pass by value when an independent copy is intended.
// Use const if you do not intend to modify the vector inside the function.
void printVector(const vector<int>& vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    // std::vector is a dynamic array. It grows automatically!
    vector<int> nums;

    // Adding elements: most appends are constant work; occasional growth copies
    // existing elements. Across many appends total work is linear (amortized O(1)).
    nums.push_back(10);
    nums.push_back(20);
    nums.push_back(30);

    cout << "Initial vector: ";
    printVector(nums);

    // Size and Capacity
    cout << "Current size: " << nums.size() << endl;

    // Accessing elements
    cout << "First element: " << nums[0] << endl;
    cout << "Last element: " << nums.back() << endl;

    // Removing the last element
    nums.pop_back();
    cout << "After pop_back: ";
    printVector(nums);

    return 0;
}
