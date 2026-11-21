# Reason about recursion before writing it

## 1. A recursive call is an ordinary function call

A function may call itself. Each active call has its own parameters, local variables
and return location, called a frame in the usual call-stack model. The caller pauses
while the child runs. After the child returns, the caller resumes at the statement
after that call; the caller's local n has not been replaced by the child's n.

For factorial(3), four calls are active at the deepest point:

| Frame | Waiting for | Work after child returns |
|---|---|---|
|factorial(3)|factorial(2)|multiply returned value by3|
|factorial(2)|factorial(1)|multiply returned value by2|
|factorial(1)|factorial(0)|multiply returned value by1|
|factorial(0)|nothing|return1 immediately|

Returns then carry1,1,2,6 upward. The base value is not the final result of every
caller; it is the starting answer that pending operations combine. Calling a helper
without returning/using its result does not propagate that result automatically.

The trace program separates enter messages before the call from leave messages
after it. Descending depths print before their children; leaving depths print in
reverse order. Returning from one call does not terminate main or all waiting calls.

## 2. State a contract, base and decreasing measure

Before implementation, write:

1. What exact subproblem does this function solve, and what result does it return?
2. Which input is already solved without another call? That is the base case.
3. What strictly decreases on every recursive path?
4. How do smaller correct answers combine into the current answer?
5. Are arithmetic, indices and maximum active depth safe under the chosen bounds?

Examples of decreasing measures: n toward0 for factorial/sum; exponent halved for
fast power; remaining decimal digits for digit sum; interval length for palindrome;
and the nonzero remainder for GCD. A program can have a base case and still never
reach it if the recursive argument fails to progress or starts outside the contract.

Factorial uses n=0 as its base, so zero works as well as positive inputs. Its int
parameter is copied into each frame; multiplying the long long returned value
produces long long arithmetic.20! fits signed64-bit,21! does not. This unit validates
before calling the helper. A type can hold a value while a huge recursion depth
still exhausts the runtime stack: numeric safety and stack safety are separate.

No portable C++ stack-depth limit can be promised. Use these deliberately bounded
examples to learn, then choose loops or explicit data structures for large depth.
Do not intentionally trigger stack overflow as an ordinary correctness test.

## 3. Correctness by the smaller-problem assumption

The reasoning resembles mathematical induction. Prove that the base result is
correct. Assume the function returns the promised answer for its smaller argument,
then show that the current combination gives the required answer. Finally justify
termination using the decreasing measure. The assumption is not circular when every
path moves to a smaller case and the base is established.

For sumTo(n), sumTo(n-1) includes1..n-1, so adding n completes1..n. For digit sum,
n%10 is the removed digit and n/10 is the remaining prefix. When n<10 the digit sum
is n itself, including0. The number of digits controls that recursion depth, not n
recursive decrements. The digit-sum example's19-digit maximum takes only a small
number of calls even though the numeric magnitude is large.

## 4. Separate time from maximum live stack space

Count total calls/work for time. Count maximum simultaneously active frames for
stack space. A long path and a broad branching tree are different shapes.

| Method | Time bound | Extra call-stack bound |
|---|---|---|
|factorial, natural sum|Theta(n+1)|O(n+1)|
|digit sum on d decimal digits|Theta(d)|O(d)|
|linear power exponent e|Theta(e+1)|O(e+1)|
|one-call power by squaring|Theta(1+log(e+1))|O(1+log(e+1))|
|recursive GCD|O(1+log(max(a,b)+1))|same upper bound|
|palindrome|O(n) worst; early mismatch O(1)|O(n) worst|
|recursive reversal|Theta(n+1)|O(n+1)|
|naive Fibonacci|O(2^n) simple upper bound|O(n+1)|
|tail-recursive sum, without relying on optimization|Theta(n+1)|O(n+1)|
|balanced range sum|Theta(n+1)|O(1+log(n+1))|
|Hanoi move generation|Theta(2^n)|O(n+1), plus stored output|

These bounds describe parameterized helpers, not a claim that every fixed-data
teaching main has an unbounded input. State the work of independent checking code
separately: an iterative oracle may cost more than the optimized helper it checks.
Do not count all completed frames as live memory after they have returned.

## 5. Linear versus fast exponentiation

Linear power removes one factor: P(e)=b*P(e-1), with P(0)=1. Our integer contract
defines0^0 as1 to make the empty-product base uniform; this is a programming
convention for the example, not a universal statement about every mathematical limit.
Negative exponents would need a different result/domain contract.

For e=2k, b^e=(b^k)^2. For e=2k+1, multiply that square by one extra b. Save a single
recursive half result in a local variable. The recurrence is then
T(e)=T(floor(e/2))+constant, logarithmic in e.

Writing two separate recursive half calls instead yields2*T(floor(e/2))+constant,
which is linear in e, despite both child arguments being halved. Avoid recomputing
a result you can reuse. The worked fast-power harness compares305 bounded base/
exponent combinations against a plain multiplication loop, including zeros and
negative bases. Those bounds keep both algorithms' intermediate products safe.

## 6. Euclid reduces a pair of arguments

The common divisors of a and b also divide a%b; conversely a divisor of b and the
remainder divides a. Hence gcd(a,b)=gcd(b,a%b) for b!=0. Stop at b=0 before taking
a remainder. Remainders shrink; the Euclidean process needs logarithmically many
fixed-width divisions as a safe upper bound. If one input starts at0, handle that
case through the same base/next-call logic rather than writing log(0).

Here gcd(0,0)=0 is explicitly chosen as an API convention. Negative inputs are
rejected, avoiding complications from signed remainder and negating a minimum int.
The recursive version teaches the recurrence; the Phase1 iterative version already
computes the same result without retaining frames.

## 7. Half-open intervals and borrowed strings

Use [left,right), where right is excluded. The length is right-left, an empty range
has left==right, and a singleton has right-left==1. Check those bases before reading
text[right-1]. The wrapper supplies left=0,right=text.size(), which naturally handles
an empty string without unsigned size()-1 underflow.

Palindrome borrows a const string& and returns a boolean. After endpoints match,
only the interior remains to be checked. A mismatch returns immediately. Reversal
borrows string& and swaps endpoints before solving the interior. It changes the same
owned string in every call; it does not build a fresh substring at each level.

A string-by-value recursive parameter or repeated substr can retain copied text
across frames and turn linear traversal into quadratic character copying/storage.
Even the index-only reversal is not constant auxiliary space overall: its frames
remain linear in the worst case. Iterative two-ended traversal uses constant working
state. These examples compare exact char units, not normalized Unicode graphemes.

## 8. Branching, overlapping work and divide-and-conquer

Naive Fibonacci uses F(n-1)+F(n-2). Its children overlap heavily: F(3) can be calculated
repeatedly while solving one larger input. F(10) has177 total calls even though the
largest active chain is only linear in10. The two-variable loop from Phase1 is much
more efficient. Memoization and tabulation address repeated subproblems later in DP;
this lesson deliberately exposes the cost before using those techniques.

Balanced range sum also makes two calls, but its halves partition the original range.
A nonempty n-element range has n singleton leaves and n-1 internal calls, so total
work is linear. Its longest path halves the interval each time, giving logarithmic
stack depth. No subvector is copied. This is useful preparation for merge sort,
whose extra merging work will change the time recurrence in the sorting unit.

Never classify a recursive method from the number of call expressions alone.
Include their argument sizes, repeated work and the nonrecursive work at every node.

## 9. Tail recursion and the equivalent loop

A call is in tail position when its result is returned with no pending combination.
sumTail(remaining,total) moves the next value into total before calling again. Its
invariant is that total plus the sum still remaining equals the original requested
sum. Reaching remaining0 means total is the whole answer.

A loop updates the same two state variables without keeping old frames. Some
compilers may eliminate tail calls, but C++ does not guarantee that optimization.
Do not promise constant recursive stack usage on that basis. Use an iterative
method when input depth can be large. Direct self-recursion is the focus here;
indirect/mutual recursion still needs a decreasing measure across the whole cycle.

## 10. Hanoi: why ordered recursive actions matter

To move n disks from source to destination:

1. Move n-1 smaller disks from source to spare, using destination as the spare.
2. Move disk n from source to destination.
3. Move n-1 smaller disks from spare to destination, using source as the spare.

For n=0 do nothing. At each step only the top disk may move and no larger disk may
be placed on a smaller one. The three phases are ordered side effects, unlike a
sum where only the final scalar result matters. Changing peg roles is essential.

T(n)=2*T(n-1)+constant gives2^n-1 moves. The largest disk cannot move until all
smaller disks are off it, and they must be moved back onto it afterward; that also
explains the minimal move count. The worked program stores Move records so an
independent simulator can enforce the actual game rules and final peg contents.
It checks every disk count0..5 and also rejects a deliberately illegal sequence.

Storing the generated sequence adds exponential output memory even though recursion
itself uses only linear stack depth. A streaming variant can avoid retaining all
moves, but cannot avoid the exponential number of output records. The small bound
keeps the output understandable; do not try a huge disk count just to observe it.

## Before searching

For each helper identify the complete subproblem, valid domain, base result,
decreasing measure, combination/order, total work, maximum live depth and owned
output. Compare a simple loop where appropriate. Predict empty, singleton and
largest permitted cases. Then use the practice/checkpoint to show the reasoning
without copying a worked function.

