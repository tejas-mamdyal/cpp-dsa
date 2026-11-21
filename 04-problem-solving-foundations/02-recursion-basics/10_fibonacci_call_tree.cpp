/*
MANY CALLS ARE NOT THE SAME AS DEEP CALLS
PREREQUISITES
Phase1 functions/loops/validation, Phase2 references/strings/vectors, and Phase3
complexity. Follow this unit's README order; the first factorial lesson introduces
recursion and the later lessons build on it. No capturing lambda is required.

CONTRACT
No input. Count recursive calls for Fibonacci n=0,1,5,10, and compare answers with an independent iterative Fibonacci implementation for every n in0..10. Print n,value,calls.

IDEA AND STATE
fib(n) branches into fib(n-1) and fib(n-2). Count every entry, including base calls. Store the two recursive results separately to make evaluation order clear.

TRACE
fib(5)=5 uses15 calls; fib(10)=55 uses177. The maximum active path is only linear in n.

WHY IT WORKS AND TERMINATES
F(0)=0,F(1)=1 and the recurrence defines each later answer. Both child arguments are smaller for n>=2. The independent loop advances two previous values.

Naive recursion has O(2^n) time as a simple exponential upper bound and O(n+1) stack space. Total calls and maximum simultaneously live calls are different. The iterative oracle is O(n) time/O(1) extra space.

PITFALL AND PRACTICE
This deliberately inefficient algorithm illustrates repeated subproblems. Do not use it for large n; memoization is taught in DP later, while the known loop already avoids repeated work.
Predict a new small trace and test a boundary before changing the contract.
*/
#include <iostream>
#include <cassert>
#include <initializer_list>

long long fibonacci(int n, int& calls) {
    ++calls;
    if (n < 2) {
        return n;
    }
    long long first = fibonacci(n - 1, calls);
    long long second = fibonacci(n - 2, calls);
    return first + second;
}

long long loopFibonacci(int n) {
    if (n == 0) {
        return 0;
    }
    long long previous = 0;
    long long current = 1;
    for (int i = 1; i < n; ++i) {
        long long next = previous + current;
        previous = current;
        current = next;
    }
    return current;
}

int main() {
    for (int n = 0; n <= 10; ++n) {
        int calls = 0;
        assert(fibonacci(n, calls) == loopFibonacci(n));
    }
    for (int n : {0, 1, 5, 10}) {
        int calls = 0;
        long long answer = fibonacci(n, calls);
        std::cout << n << ' ' << answer << ' ' << calls << '\n';
    }
    return 0;
}
