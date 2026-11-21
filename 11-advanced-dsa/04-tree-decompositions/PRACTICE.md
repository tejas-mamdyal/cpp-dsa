# Independent practice

Use the corresponding lesson bounds. For each task provide the full input/output contract,a simple baseline,state definition,trace,proof,costs and normal/boundary/counterexample checks. Attempt without copying worked source.

## 1. Exercise 1

A preorder entry list stores every subtree contiguously. Domain:Valid undirected tree, V 1..30, root 0; adjacency order determines entry order. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Verify every descendant lies in its subtree half-open interval.

## 2. Exercise 2

Translate vertex updates into entry-position updates. Domain:Valid nonempty rooted tree<=30 with one signed value per vertex. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Update root and leaf values and query both subtrees.

## 3. Exercise 3

Use entry containment for constant-time ancestry. Domain:At most 30 elements/vertices; integer magnitudes<=1000 unless narrowed; indices/ranges satisfy the stated domain. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Test strict ancestor versus reflexive ancestor conventions.

## 4. Exercise 4

Compose two2^(j-1) jumps into one2^j jump. Domain:Valid nonempty tree<=30, root 0; valid vertices, steps may be invalid and return absence. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Ask for an ancestor beyond the root and define absence.

## 5. Exercise 5

Raise both nodes without crossing their shared ancestor. Domain:At most 30 elements/vertices; integer magnitudes<=1000 unless narrowed; indices/ranges satisfy the stated domain. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Validate LCA by independently intersecting parent chains.

## 6. Exercise 6

Subtract twice the shared-root depth. Domain:At most 30 elements/vertices; integer magnitudes<=1000 unless narrowed; indices/ranges satisfy the stated domain. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Return the actual route as well as its length.

## 7. Exercise 7

Moving across one edge changes two vertex groups oppositely. Domain:At most 30 elements/vertices; integer magnitudes<=1000 unless narrowed; indices/ranges satisfy the stated domain. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Compute every root sum by BFS as an oracle.

## 8. Exercise 8

Replace vertex counts by additive vertex weights. Domain:Valid tree<=30 with signed vertex weights; distances count edges, not edge weights. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Move one vertex weight and compare all root objectives.

## 9. Exercise 9

Choose vertices whose removal leaves no component larger than half. Domain:At most 30 elements/vertices; integer magnitudes<=1000 unless narrowed; indices/ranges satisfy the stated domain. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Show why a tree may have two centroids.

## 10. Exercise 10

Split a tree route into logarithmically many contiguous heavy chains. Domain:Valid nonempty tree<=30, root 0, one signed value per vertex; valid node path queries. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Update values before comparing every node path with BFS.

## 11. Exercise 11

Store an edge at its deeper endpoint and exclude the LCA slot. Domain:Rooted valid tree<=30; value[root]=0, other values describe parent edges. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Query a node against itself under the edge-weight convention.

## 12. Exercise 12

Compare updates and all-pair sums with direct BFS witnesses. Domain:At most 30 elements/vertices; integer magnitudes<=1000 unless narrowed; indices/ranges satisfy the stated domain. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Test a chain and a star rather than only a balanced tree.

