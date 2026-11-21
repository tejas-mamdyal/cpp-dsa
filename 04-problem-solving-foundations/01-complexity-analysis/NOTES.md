# Derive a cost before optimizing

## 1. Start with a precise problem and constraints

Write down required input/output, allowed values, size limits, duplicates/order,
absence behavior and whether mutation is allowed. A correct algorithm outside its
stated domain is not automatically safe inside a different domain. A length bound
also controls arithmetic: summing1000 ints of magnitude1000 fits long long, whereas
squaring an arbitrary long long may overflow before a later comparison can help.

Start from a direct method whose correctness you can explain. For duplicate
checking, comparing every pair is simple and useful on small inputs. A hash-based
method changes its time/space tradeoff; it should be compared with the direct
version rather than accepted because it looks shorter.

Constraints suggest whether an approach is plausible. For n=100000, one full scan
uses100000 selected visits; all ordered pairs use10000000000. A specified model
budget can distinguish them without actually doing billions of iterations. There
is no universal rule equating a fixed number of operations with one second. I/O,
key length, allocations, hardware, optimization and constants affect elapsed time.

## 2. Choose an input size and a counted operation

n may mean elements, text characters or graph vertices; use the quantity that grows.
If two sequences have independent lengths n and m, retain both. A scan of each is
n+m visits; every cross-pair is n*m. Do not silently assume m=n.

State what is counted: value comparisons, additions, element moves or inner-body
visits. A measured inner-body count is not the exact count of every instruction.
For example, n outer iterations with zero inner iterations still perform outer-loop
control work. The rectangular program therefore distinguishes n*m selected visits
from Theta(1+n+n*m) total loop work.

Our fixed-width operation model treats bounded integer arithmetic/indexing as
constant-time. Arbitrarily large integers need a digit/bit complexity model. Printing
all n values requires at least n element outputs, and their digit lengths matter
when considering total characters. Avoid mixing model operations and milliseconds.

## 3. Big O, Omega and Theta are bounds

For sufficiently large n and fixed positive constants:

- O(g(n)) is an upper bound: work is at most C*g(n).
- Omega(g(n)) is a lower bound: work is at least c*g(n).
- Theta(g(n)) gives matching upper and lower bounds: growth has that order.

A count3n+7 is Theta(n). A linear scan is also O(n*n), but that loose upper bound
hides useful information. Say the tight bound when you know it. O(1) means bounded
work as input size grows, not literally one instruction or zero time.

Bounds and input cases are different axes. Best-case and worst-case functions can
each have O/Omega/Theta bounds; Omega does not mean best case and O does not mean
worst case. If a statement simply says a search is O(n), clarify that this is its
worst-case bound or an upper bound valid for every input of that size.

For empty inputs there is still setup/guard work. Notes sometimes write n+1 or
1+log(n+1) to include that boundary explicitly; conventional asymptotic labels
such as linear/logarithmic describe growth for larger n.

## 4. Derive loop costs

A loop doing one selected visit at each of n positions contributes n. Two sequential
loops contribute n+m, so with equal sizes2n remains Theta(n). Independent nested
bounds contribute n*m; when m=n, that is n squared.

Dependent bounds require a sum. For pairs i<j, rows contribute n-1,n-2,...,0, so the
selected count is n*(n-1)/2. Each unordered pair appears once. This enumeration is
quadratic, although evaluating the closed formula is constant arithmetic work.
A nested-looking loop is not automatically quadratic: a total that never resets
or an inner multiplicative progression can give a different result.

Repeated division by2 reduces n to floor(n/2), then floor(n/4), and so on. For n>0,
while(remaining>0) takes floor(log2(n))+1 iterations. With condition remaining>1,
it instead takes floor(log2(n)). Trace13 ->6 ->3 ->1 ->0 to see the distinction.
Repeated doubling1,2,4,... up to n has logarithmic iteration count too. Use an
integer type and bounds that keep the final doubling representable.

Reset a halving process of size n inside each of n iterations and its costs
multiply: n*floor(log2(n)) selected updates for n>=1. Total work also includes the
outer-loop overhead. Change the reset behavior and you must re-derive the count.

For orientation, common growth classes are constant, logarithmic, linear,
linearithmic n log n, quadratic, cubic, exponential and factorial. Recursion trees,
subset enumeration and permutation generation later derive the last classes; they
are vocabulary here, not unexplained algorithms that beginners must already know.

## 5. Best, worst and expected cases

A linear first-match search can finish after one equality comparison, or inspect
all n elements. Empty input makes zero element comparisons. For equal-probability
successful target positions, the expected count is(1+...+n)/n=(n+1)/2, still linear.
That calculation assumes a distribution; adding unsuccessful searches changes it.
Do not call an unexplained workload average a guarantee.

Hash lookup is expected constant-time per bounded key under usual hashing
assumptions and linear in the container size in the worst collision case. A hash
scan can therefore be expected linear overall yet quadratic in the worst case.
String keys add their hashing/comparison character cost. Keep those qualifications
when comparing the oracle and hash-based duplicate detectors.

## 6. Space: identify what owns the memory

Name input storage, output storage and additional working storage separately.
A copied vector retains n separate elements; an in-place update uses constant
working state but the input itself still occupies n elements. If a convention
includes the returned output in auxiliary space, state that copying uses O(n)
auxiliary; if it excludes the output, say O(1) working state plus O(n) output.
Both conventions can be consistent when made explicit.

Peak simultaneous live memory matters. A growth step may temporarily retain both
old and new buffers. Copying a vector by value adds an owned allocation, whereas a
const reference borrows existing storage. Future recursion also uses call-stack
frames; we will count their peak live depth in the recursion unit. A loop's iteration
count is not automatically its memory usage.

## 7. Use invariants to explain correctness

An invariant is a statement true at a particular loop boundary. For maximum:
"Before processing index i, best is the maximum of elements0 through i-1."
Initialization establishes it using the first element. Maintenance compares the
next value and restores it for the larger prefix. At termination the processed
prefix is the entire input, which yields the required answer.

Initialize from an actual element rather than0; otherwise all-negative input fails.
Handle empty input before reading that first element and define an absence policy.
An invariant must mean more than "the answer is correct"; it must identify which
part has been processed and what the state represents.

## 8. Amortized is not probabilistic average

Our explicit model doubles capacity1,2,4,8,... . Growth moves1+2+4+... elements.
Before n pushes finish, the geometric sum is less than2n for n>0. Including one
write per push gives less than3n total modeled work: constant amortized work per
push over the sequence, even though an individual growth takes linear work.

The simulator stores only counts and does not allocate an actual modeled array;
its O(1) scalar storage is different from the real array's O(n) element storage.
Actual std::vector growth factors/capacities are not specified by the language;
the interface provides amortized constant push_back, not a guaranteed exact
capacity sequence. Amortization needs no random-input distribution.

## 9. Use an independent small-input oracle

Keep the clearest brute-force implementation, then compare the optimized result
on normal, empty, duplicate-heavy and adversarial small cases. Exhaustive testing
is practical when the alphabet and lengths are small. The last program checks all
364 vectors of lengths0..5 over{-1,0,1}, including the empty vector, using base3
choices rather than introducing recursion early.

The pairwise oracle does not call the optimized set implementation. Different
methods are less likely to share a bug than two copies of one method. Agreement
on364 cases is useful evidence for that domain, not a proof for all integers and
sizes. Add boundary/overflow cases separately and use invariants/proofs to explain
general correctness.

## Before advancing

For any new program, state the contract, operation model, size variables, count or
bound, input/output/working memory, correctness invariant and smallest edge cases.
Then derive its cost again if a constraint, loop bound, ownership choice or output
requirement changes. Do not memorize Big-O labels from a list without that reasoning.

