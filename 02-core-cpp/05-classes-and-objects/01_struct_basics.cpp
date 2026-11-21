#include <iostream>
#include <string>

using namespace std;

// Structs group related variables together.
// By default, everything in a struct is public.
struct Node {
    int data;
    Node* next; // A pointer to another Node (Crucial for Linked Lists!)
};

struct Point {
    int x;
    int y;

    // Structs can also have constructors and functions
    Point(int x_val, int y_val) {
        x = x_val;
        y = y_val;
    }

    void print() {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

int main() {
    Point p1(10, 20);
    p1.print();

    // Creating a basic linked structure
    Node n1;
    n1.data = 100;

    Node n2;
    n2.data = 200;
    n2.next = nullptr;

    n1.next = &n2;

    cout << "Node 1 data: " << n1.data << endl;
    cout << "Node 2 data (accessed via Node 1): " << n1.next->data << endl;

    return 0;
}
