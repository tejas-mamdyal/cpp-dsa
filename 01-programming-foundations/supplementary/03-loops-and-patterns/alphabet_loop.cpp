/*
LEARNING NOTES
A for loop runs initialization once, checks its condition before each iteration,
then runs its update after the body. Count exact iterations by tracing first and
last values. An off-by-one error usually confuses < with <=.
Exercise: print 1..n and then n..1; test n=0 and n=1.
*/
#include <iostream>
using namespace std;

int main() {
    char ch;
    for (ch = 'a'; ch <= 'z'; ch = ch + 1) {
        cout << ch << " ";
    }
    return 0;
}