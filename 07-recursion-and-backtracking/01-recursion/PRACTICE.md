# Decision trees: independent practice

Use C++17. Respect each small exponential bound. For every exercise submit an input/output contract,a drawn decision tree,a restoration invariant,code,costs separating output from auxiliary space,and normal/boundary tests. Attempt before reading hints.

## 1. Ternary strings

Generate strings of length n in [0,8] over a,b,c in lexicographic branch order;empty length has one empty result.

Include the smallest legal input and a case where the work buffer or result multiplicity is easy to mishandle.

## 2. Copied versus shared state

Implement ternary generation both by-value and by-reference;compare complete outputs for n=0..5.

Include the smallest legal input and a case where the work buffer or result multiplicity is easy to mishandle.

## 3. Exact subset order

Return positional subsets of [4,7,9] in exclude-first order;then implement include-first order.

Include the smallest legal input and a case where the work buffer or result multiplicity is easy to mishandle.

## 4. Subsequence multiplicity

Return all positional subsequences of aba and state how many distinct resulting strings exist.

Include the smallest legal input and a case where the work buffer or result multiplicity is easy to mishandle.

## 5. Instrumentation

For a full ternary decision tree of depth n<=8,measure calls,leaves and maximum frames.

Include the smallest legal input and a case where the work buffer or result multiplicity is easy to mishandle.

## 6. Choose k indices

Return combinations of k positions from a vector of length<=12,then map them to values.

Include the smallest legal input and a case where the work buffer or result multiplicity is easy to mishandle.

## 7. Signed witness count

Count subsets totaling target for signed values[-10,10],n<=12;include empty target-zero witness.

Include the smallest legal input and a case where the work buffer or result multiplicity is easy to mishandle.

## 8. Restoration on success

Write a first-witness subset search that guarantees its work buffer is empty after both success and failure.

Include the smallest legal input and a case where the work buffer or result multiplicity is easy to mishandle.

## 9. Bounded parentheses depth

Generate balanced strings with n<=6 pairs and maximum nesting depth D>=0.

Include the smallest legal input and a case where the work buffer or result multiplicity is easy to mishandle.

## 10. Custom mapping

Generate all strings selecting one symbol from each of up to8 input lists of size<=4. A zero-length list produces no results.

Include the smallest legal input and a case where the work buffer or result multiplicity is easy to mishandle.

## 11. Permutation oracle

For distinct vectors of length<=7,compare used-flag permutations with sorted input plus next_permutation.

Include the smallest legal input and a case where the work buffer or result multiplicity is easy to mishandle.

## 12. Break the count-only test

Create a deliberately wrong subset generator that emits the empty subset2^n times,and show why a size check misses it.

Include the smallest legal input and a case where the work buffer or result multiplicity is easy to mishandle.

