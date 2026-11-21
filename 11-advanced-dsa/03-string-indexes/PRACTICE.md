# Independent practice

Use the corresponding lesson bounds. For each task provide the full input/output contract,a simple baseline,state definition,trace,proof,costs and normal/boundary/counterexample checks. Attempt without copying worked source.

## 1. Exercise 1

Follow proper-prefix borders after a mismatch. Domain:Arbitrary byte string, length<=1000; return prefix-function lengths. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:List all proper borders rather than only the longest.

## 2. Exercise 2

Retain a border after a full match to allow overlap. Domain:Byte strings, length<=1000; empty pattern matches all text boundaries. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Return all overlapping matches and declare the empty-pattern convention.

## 3. Exercise 3

Reuse matching-prefix information inside the rightmost window. Domain:Byte string, length<=1000; z[0]=0. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Compare every Z value to a direct character scan.

## 4. Exercise 4

Require whole copies rather than a weak partial period. Domain:At most 30 elements/vertices; integer magnitudes<=1000 unless narrowed; indices/ranges satisfy the stated domain. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Return the shortest repeating unit when the full word is periodic.

## 5. Exercise 5

Normalize a substring hash by canceling its preceding prefix. Domain:Byte strings<=1000; modulus 2..1000000007; intermediate products fit long long. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Construct a real collision under the small demonstration modulus.

## 6. Exercise 6

Confirm hash candidates by comparing the original characters. Domain:At most 30 elements/vertices; integer magnitudes<=1000 unless narrowed; indices/ranges satisfy the stated domain. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Verify every reported hash match by direct text comparison.

## 7. Exercise 7

Reuse a mirrored radius around a character center. Domain:Byte string<=1000; odd radius includes the center. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Return all maximal odd-palindrome intervals.

## 8. Exercise 8

Center the palindrome at a gap before an index. Domain:Byte string<=1000; empty even palindrome has radius 0. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Return all maximal even-palindrome intervals.

## 9. Exercise 9

Count all palindromes and reconstruct a longest one. Domain:At most 30 elements/vertices; integer magnitudes<=1000 unless narrowed; indices/ranges satisfy the stated domain. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Check palindrome occurrence counts by enumerating substrings.

## 10. Exercise 10

Rank twice-longer suffix prefixes from two shorter ranks. Domain:Byte string, length<=1000; sort suffix starting indices lexicographically. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Compare suffix order with sorting literal suffix strings.

## 11. Exercise 11

Reuse at least one fewer shared character at the next starting position. Domain:At most 30 elements/vertices; integer magnitudes<=1000 unless narrowed; indices/ranges satisfy the stated domain. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Compare every neighboring LCP with a direct scan.

## 12. Exercise 12

Subtract prefixes already contributed by the previous suffix. Domain:At most 30 elements/vertices; integer magnitudes<=1000 unless narrowed; indices/ranges satisfy the stated domain. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Return the set of distinct substrings on a short text as an oracle.

