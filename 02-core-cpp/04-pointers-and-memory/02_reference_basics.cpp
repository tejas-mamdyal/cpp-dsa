#include <iostream>

using namespace std;

int main() {
    int original = 50;

    // A reference is an ALIAS for another variable.
    // Must be initialized immediately when declared!
    int& ref = original;

    cout << "Original: " << original << endl;
    cout << "Reference: " << ref << endl;

    // Modifying the reference modifies the original
    ref = 100;

    cout << "After modification -> Original: " << original << endl;
    cout << "After modification -> Reference: " << ref << endl;

    return 0;
}
