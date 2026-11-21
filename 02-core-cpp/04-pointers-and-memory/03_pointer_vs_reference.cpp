#include <iostream>

using namespace std;

void swapUsingPointers(int* a, int* b) {
    if (a == nullptr || b == nullptr) {
        return; // Safety check
    }
    int temp = *a;
    *a = *b;
    *b = temp;
}

// References are cleaner and generally preferred in C++ for function parameters
void swapUsingReferences(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 10;
    int y = 20;

    cout << "Initial: x = " << x << ", y = " << y << endl;

    // Pointers require passing addresses
    swapUsingPointers(&x, &y);
    cout << "After Pointer Swap: x = " << x << ", y = " << y << endl;

    // References just take the variables directly
    swapUsingReferences(x, y);
    cout << "After Reference Swap: x = " << x << ", y = " << y << endl;

    /*
* POINTER VS REFERENCE (KEY DIFFERENCES):
     * 1. Pointers can be reassigned to point to different memory. References cannot be reassigned.
     * 2. Pointers can be `nullptr`. References must always refer to a valid object.
     * 3. Pointers need manual dereferencing `*ptr`. References don't.
     * 
     * RULE OF THUMB: Use References when you can, Pointers when you have to 
     * (e.g., dynamic memory, optional parameters, building Linked Lists).
*/

    return 0;
}
