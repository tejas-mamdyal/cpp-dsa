# Independent practice

Use the corresponding lesson bounds. For each task provide the full input/output contract,a simple baseline,state definition,trace,proof,costs and normal/boundary/counterexample checks. Attempt without copying worked source.

## 1. Exercise 1

Cache one additive aggregate per position block. Domain:At most 30 elements/vertices; integer magnitudes<=1000 unless narrowed; indices/ranges satisfy the stated domain. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Use uneven final blocks and update the first and final elements.

## 2. Exercise 2

Delay full-block additions for later point access. Domain:Initially zero array, n<=30; valid half-open updates and point queries. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Mix negative and positive range operations and compare every point.

## 3. Exercise 3

Move one counted window through an offline query order. Domain:Static array<=30; valid half-open queries with IDs 0..Q-1 each used once. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Return answers in original query order after reordering work.

## 4. Exercise 4

Change the window aggregate to equal-value index pairs. Domain:At most 30 elements/vertices; integer magnitudes<=1000 unless narrowed; indices/ranges satisfy the stated domain. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Check duplicate values with frequencies1,2,3 and compare pair counts.

## 5. Exercise 5

Activate positions in descending value order. Domain:Static bounded array; queries specify valid half-open positions and distinct output IDs. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Resolve equal thresholds with strict versus non-strict policies.

## 6. Exercise 6

Keep one marker at each value last position in the processed prefix. Domain:Static array; queries are half-open with IDs 0..Q-1. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Include empty ranges and repeated queries.

## 7. Exercise 7

Copy only the modified root-to-leaf path. Domain:Bounded signed array; valid existing versions and point indices; half-open sums; old versions remain readable. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Branch two new versions from the same old version and verify the old one.

## 8. Exercise 8

Subtract two prefix histograms while descending value ranks. Domain:Static bounded array; valid position ranges, k 1-based; invalid rank returns absence. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Return all order statistics for each subrange,including duplicates.

## 9. Exercise 9

Count an inclusive value band inside a positional range. Domain:Static bounded array; valid positional ranges and inclusive numeric low/high; low>high returns 0. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Ask for a value band containing no compressed value.

## 10. Exercise 10

## 11. Exercise 11

Place edge-active time intervals on a segment tree and rollback between branches. Domain:Undirected simple graph, V<=30, T<=100; valid+,-,? events; no duplicate active add or inactive remove. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Remove then re-add the same edge at different times.

## 12. Exercise 12

Store sorted values for each disjoint position interval. Domain:Static bounded array; valid half-open ranges; count values<=threshold including duplicates. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Compare counts below and above both endpoint values.

