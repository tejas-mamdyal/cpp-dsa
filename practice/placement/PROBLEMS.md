# Sixty interview problem cards

Use C++17. Unless narrowed:at most30 elements/vertices,integer magnitudes<=1000,ASCII text,and valid structural inputs. Define an interface and tie policy,derive a baseline,then improve when justified. Return full witnesses when requested. Statements precede the answer key.

## P01. Problem 1

Given integers and a target,return two distinct original indices whose values sum to target,or absence. Duplicate values at different positions are legal.

Submission:code,contract,one worked example,correctness argument,costs,and normal/boundary/counterexample tests.

## P02. Problem 2

Return all distinct value triples summing to zero. Each triple must use three distinct input positions;equal values are allowed when enough occurrences exist.

Submission:code,contract,one worked example,correctness argument,costs,and normal/boundary/counterexample tests.

## P03. Problem 3

Count nonempty contiguous subarrays with exactly k distinct values;k>=0.

Submission:code,contract,one worked example,correctness argument,costs,and normal/boundary/counterexample tests.

## P04. Problem 4

Count nonempty contiguous subarrays whose signed integer sum equals target. Zeros and negative values are allowed.

Submission:code,contract,one worked example,correctness argument,costs,and normal/boundary/counterexample tests.

## P05. Problem 5

Given strictly positive values and a positive target,return the shortest nonempty subarray length with sum at least target,or0.

Submission:code,contract,one worked example,correctness argument,costs,and normal/boundary/counterexample tests.

## P06. Problem 6

Merge overlapping closed intervals,including intervals sharing an endpoint. Return sorted disjoint intervals.

Submission:code,contract,one worked example,correctness argument,costs,and normal/boundary/counterexample tests.

## P07. Problem 7

Return the fewest rooms needed for nonempty half-open meeting intervals. A room ending at t can be reused at t.

Submission:code,contract,one worked example,correctness argument,costs,and normal/boundary/counterexample tests.

## P08. Problem 8

Modify a sequence into its next lexicographic permutation. If already greatest,reset to ascending and return false. Handle duplicates.

Submission:code,contract,one worked example,correctness argument,costs,and normal/boundary/counterexample tests.

## P09. Problem 9

Return the1-based kth multiset value in two sorted arrays without fully merging them. One array may be empty;the rank is valid.

Submission:code,contract,one worked example,correctness argument,costs,and normal/boundary/counterexample tests.

## P10. Problem 10

Return the median of two sorted arrays with nonempty combined length. Average the two middle values for even length. Give both a clear reference and a faster alternative.

Submission:code,contract,one worked example,correctness argument,costs,and normal/boundary/counterexample tests.

## P11. Problem 11

For each position return the product of all other values without division. n<=15,absolute values<=4;the empty product is1.

Submission:code,contract,one worked example,correctness argument,costs,and normal/boundary/counterexample tests.

## P12. Problem 12

Return a shortest substring covering every target-character occurrence. Return empty for no solution or an empty target;declare tie behavior.

Submission:code,contract,one worked example,correctness argument,costs,and normal/boundary/counterexample tests.

## P13. Problem 13

Group words that have identical character multiplicities. Keep every occurrence;state a deterministic group-output convention.

Submission:code,contract,one worked example,correctness argument,costs,and normal/boundary/counterexample tests.

## P14. Problem 14

Return the length of the longest substring without a repeated byte. Distinguish substring from subsequence.

Submission:code,contract,one worked example,correctness argument,costs,and normal/boundary/counterexample tests.

## P15. Problem 15

Decode lowercase-letter/positive-decimal-count groups,such as a2b3 to aabbb. Reject malformed groups or output over1000 characters.

Submission:code,contract,one worked example,correctness argument,costs,and normal/boundary/counterexample tests.

## P16. Problem 16

Return the longest common prefix of a word list,including an empty list and an empty word.

Submission:code,contract,one worked example,correctness argument,costs,and normal/boundary/counterexample tests.

## P17. Problem 17

Decide whether a byte string can become a palindrome after deleting at most one character.

Submission:code,contract,one worked example,correctness argument,costs,and normal/boundary/counterexample tests.

## P18. Problem 18

Split a string into nonempty dictionary words,returning one actual word sequence,or absence. Empty text has an empty decomposition.

Submission:code,contract,one worked example,correctness argument,costs,and normal/boundary/counterexample tests.

## P19. Problem 19

Decide whether a string over()[]{} is properly nested and matched. Empty is valid.

Submission:code,contract,one worked example,correctness argument,costs,and normal/boundary/counterexample tests.

## P20. Problem 20

Generate every balanced parenthesis string with n pairs once,for0<=n<=8. For n0 return the single empty sequence.

Submission:code,contract,one worked example,correctness argument,costs,and normal/boundary/counterexample tests.

## P21. Problem 21

Find the fewest single-letter changes from start to target using equal-length lowercase dictionary words. Return-1 if impossible;start==target needs0 changes.

Submission:code,contract,one worked example,correctness argument,costs,and normal/boundary/counterexample tests.

## P22. Problem 22

Find whether a word appears on a rectangular grid through four-neighbor moves without reusing a cell in a route. Grid<=4x4,word length<=8;empty word succeeds.

Submission:code,contract,one worked example,correctness argument,costs,and normal/boundary/counterexample tests.

## P23. Problem 23

Ship positive-weight packages in their fixed order within a given positive number of days. Find minimum daily capacity;empty shipment needs0.

Submission:code,contract,one worked example,correctness argument,costs,and normal/boundary/counterexample tests.

## P24. Problem 24

Return the valid1-based kth multiset entry of a nonempty matrix sorted by rows and columns,including duplicates and negative values.

Submission:code,contract,one worked example,correctness argument,costs,and normal/boundary/counterexample tests.

## P25. Problem 25

Return a farthest reachable vertex and its hop count from a source in an undirected graph;report unreachable vertices separately.

Submission:code,contract,one worked example,correctness argument,costs,and normal/boundary/counterexample tests.

## P26. Problem 26

Return an actual shortest unweighted route between two graph vertices,or an empty route if unreachable. Source==target is a one-vertex route.

Submission:code,contract,one worked example,correctness argument,costs,and normal/boundary/counterexample tests.

## P27. Problem 27

Courses take one semester each and have directed prerequisites. Return minimum semesters with unlimited parallel courses,or-1 for a cycle;empty graph needs0.

Submission:code,contract,one worked example,correctness argument,costs,and normal/boundary/counterexample tests.

## P28. Problem 28

Given undirected network cables,return minimum cable relocations needed to connect every vertex,or-1. A redundant cable can be moved to any endpoints.

Submission:code,contract,one worked example,correctness argument,costs,and normal/boundary/counterexample tests.

## P29. Problem 29

Decide whether every component of an undirected graph admits a two-coloring. Include self-loops and isolated vertices.

Submission:code,contract,one worked example,correctness argument,costs,and normal/boundary/counterexample tests.

## P30. Problem 30

For a directed nonnegative weighted graph,return minimum route costs from one source with an explicit unreachable convention. Explain why negative edges change the choice.

Submission:code,contract,one worked example,correctness argument,costs,and normal/boundary/counterexample tests.

## P31. Problem 31

Decide whether a binary tree is height-balanced at every node. Return a height with an explicit imbalance convention;empty height is0.

Submission:code,contract,one worked example,correctness argument,costs,and normal/boundary/counterexample tests.

## P32. Problem 32

Decide whether a binary tree has a root-to-leaf route summing to target. A matching internal-node prefix is insufficient;empty tree returns false.

Submission:code,contract,one worked example,correctness argument,costs,and normal/boundary/counterexample tests.

## P33. Problem 33

Return the1-based kth smallest key of a binary search tree,or absence for an invalid rank. Explain the improvement over collecting all keys.

Submission:code,contract,one worked example,correctness argument,costs,and normal/boundary/counterexample tests.

## P34. Problem 34

Return the maximum sum of a nonempty simple path in a signed binary tree,or absence for an empty tree. A path may start and end anywhere but cannot branch or repeat a node.

Submission:code,contract,one worked example,correctness argument,costs,and normal/boundary/counterexample tests.

## P35. Problem 35

Return the diameter in edges of a connected unweighted tree. Empty and singleton trees have diameter0;explain why a general cyclic graph changes the proof.

Submission:code,contract,one worked example,correctness argument,costs,and normal/boundary/counterexample tests.

## P36. Problem 36

Given directed priced flights and a maximum edge budget,return minimum source-to-target cost or absence. A cheaper route using too many edges is invalid.

Submission:code,contract,one worked example,correctness argument,costs,and normal/boundary/counterexample tests.

## P37. Problem 37

Return original indices of one longest strictly increasing subsequence. Check both increasing indices and values,including duplicate values.

Submission:code,contract,one worked example,correctness argument,costs,and normal/boundary/counterexample tests.

## P38. Problem 38

Choose nonoverlapping half-open jobs with signed profits to maximize total profit;empty selection is permitted.

Submission:code,contract,one worked example,correctness argument,costs,and normal/boundary/counterexample tests.

## P39. Problem 39

Return the minimum cuts splitting a text into palindromic substrings. Empty text needs0 cuts.

Submission:code,contract,one worked example,correctness argument,costs,and normal/boundary/counterexample tests.

## P40. Problem 40

With eggs that break above an unknown threshold,return minimum worst-case drops for a floor count<=1000. Zero eggs cannot resolve a positive floor count.

Submission:code,contract,one worked example,correctness argument,costs,and normal/boundary/counterexample tests.

## P41. Problem 41

Return the area of the largest all-one rectangle in a rectangular binary matrix,including empty input.

Submission:code,contract,one worked example,correctness argument,costs,and normal/boundary/counterexample tests.

## P42. Problem 42

Remove the fewest values to leave a strict increasing-then-decreasing mountain with a nonempty slope on each side. Return-1 if impossible.

Submission:code,contract,one worked example,correctness argument,costs,and normal/boundary/counterexample tests.

## P43. Problem 43

Return the longest word chain in which each next word inserts exactly one character while preserving all earlier characters in order.

Submission:code,contract,one worked example,correctness argument,costs,and normal/boundary/counterexample tests.

## P44. Problem 44

Partition the full signed array into blocks of length at most k. Replace each block by copies of its maximum and maximize the resulting total. No element may be skipped.

Submission:code,contract,one worked example,correctness argument,costs,and normal/boundary/counterexample tests.

## P45. Problem 45

Cut a positive-length stick at all given distinct internal positions. Each cut costs the length of its current segment. Minimize total cost.

Submission:code,contract,one worked example,correctness argument,costs,and normal/boundary/counterexample tests.

## P46. Problem 46

Cover strictly increasing travel days with1,7 or30-day passes of given nonnegative prices. Return minimum total cost.

Submission:code,contract,one worked example,correctness argument,costs,and normal/boundary/counterexample tests.

## P47. Problem 47

Count index subsequences of a source string equal to a target string. Source length<=30;the empty target has one choice.

Submission:code,contract,one worked example,correctness argument,costs,and normal/boundary/counterexample tests.

## P48. Problem 48

Decide whether a result string interleaves two source strings while preserving each source order,including empty strings.

Submission:code,contract,one worked example,correctness argument,costs,and normal/boundary/counterexample tests.

## P49. Problem 49

Return the largest rectangle under a histogram of nonnegative heights. Include equal heights and an empty histogram.

Submission:code,contract,one worked example,correctness argument,costs,and normal/boundary/counterexample tests.

## P50. Problem 50

Return total unit-width rainwater held by nonnegative heights. Include monotone and empty profiles.

Submission:code,contract,one worked example,correctness argument,costs,and normal/boundary/counterexample tests.

## P51. Problem 51

Support insertion into a stream and querying its median. Return absence before any insertion;average middle values for an even count.

Submission:code,contract,one worked example,correctness argument,costs,and normal/boundary/counterexample tests.

## P52. Problem 52

Select k values closest to target by absolute distance,breaking distance ties toward smaller values. Keep duplicate occurrences and return selections sorted numerically.

Submission:code,contract,one worked example,correctness argument,costs,and normal/boundary/counterexample tests.

## P53. Problem 53

Return the k most frequent distinct words,breaking frequency ties alphabetically. k is valid.

Submission:code,contract,one worked example,correctness argument,costs,and normal/boundary/counterexample tests.

## P54. Problem 54

Implement an LRU key/value cache with get and put. Hits and updates become most recent;overflow evicts least recent. Capacity0 stores nothing. State operation costs.

Submission:code,contract,one worked example,correctness argument,costs,and normal/boundary/counterexample tests.

## P55. Problem 55

Return the maximum simultaneous count of half-open intervals. Combine all changes at the same endpoint consistently.

Submission:code,contract,one worked example,correctness argument,costs,and normal/boundary/counterexample tests.

## P56. Problem 56

Schedule a subset of unit-duration jobs before their nonnegative integer deadlines to maximize total profit. Empty selection is permitted.

Submission:code,contract,one worked example,correctness argument,costs,and normal/boundary/counterexample tests.

## P57. Problem 57

Return any starting station allowing a complete circular route with nonnegative gas and costs,or-1. You cannot borrow gas;empty input has no start.

Submission:code,contract,one worked example,correctness argument,costs,and normal/boundary/counterexample tests.

## P58. Problem 58

Give each child at least one candy. A strictly higher rating than a neighbor requires more candies than that neighbor. Minimize the total.

Submission:code,contract,one worked example,correctness argument,costs,and normal/boundary/counterexample tests.

## P59. Problem 59

Merge k sorted integer streams into a sorted multiset output,including empty streams and duplicates.

Submission:code,contract,one worked example,correctness argument,costs,and normal/boundary/counterexample tests.

## P60. Problem 60

Evaluate a valid expression of nonnegative decimal integers with +,-,* and ordinary multiplication precedence. No unary operators,spaces,parentheses or division;at most8 operators,operands<=9 except a single10. Results fit64 bits.

Submission:code,contract,one worked example,correctness argument,costs,and normal/boundary/counterexample tests.

