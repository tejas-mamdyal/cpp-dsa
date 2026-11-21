#include <iostream>

using namespace std;

int main() {
    // 1. Stack Allocation (Automatic Memory)
    // Freed automatically when the function ends.
    int stack_var = 5;
    cout << "Automatic value: " << stack_var << endl;

    // 2. Heap Allocation (Dynamic Memory)
    // You control when it is created and destroyed using 'new' and 'delete'.
    int* heap_ptr = new int;
    *heap_ptr = 42;

    cout << "Value on heap: " << *heap_ptr << endl;

    // CRITICAL: You MUST free heap memory to prevent Memory Leaks!
    delete heap_ptr;

    // Best practice: Set to nullptr after deleting to avoid dangling pointers
    heap_ptr = nullptr;

    // 3. Dynamic Arrays
    int size = 3;
    int* dyn_array = new int[size];

    for (int i = 0; i < size; i++) {
        dyn_array[i] = i * 10;
        cout << dyn_array[i] << " ";
    }
    cout << endl;

    // Free dynamic arrays with delete[]
    delete[] dyn_array;
    dyn_array = nullptr;

    // For DSA, std::vector manages this heap allocation automatically for you!

    return 0;
}
