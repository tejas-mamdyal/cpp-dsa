/*
LEARNING NOTES
Scope is the region where a name can be used. Braces create a nested scope;
an inner declaration can hide an outer name without modifying the outer object.
Trace which declaration each use refers to, then observe the outer value again
after the inner block. Lifetime concerns when an object exists, not just name visibility.
Exercise: rename the inner variable and compare the output.
*/
#include <iostream>
using namespace std;
int a = 10;

int main() {
    int a = 14;
    cout << a << endl;   //more precedence for local variable
    cout << ::a << endl; //scope resolution operator is used to access global variable
    return 0;
}