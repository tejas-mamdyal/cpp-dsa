# Independent practice

Use the corresponding lesson bounds. For each task provide the full input/output contract,a simple baseline,state definition,trace,proof,costs and normal/boundary/counterexample checks. Attempt without copying worked source.

## 1. Exercise 1

Classify turns using a signed cross product. Domain:Integer coordinate magnitudes<=1000 throughout this unit unless stated. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Reverse two orientation arguments and check the sign reversal.

## 2. Exercise 2

Combine collinearity with both coordinate bounds. Domain:At most 30 elements/vertices; integer magnitudes<=1000 unless narrowed; indices/ranges satisfy the stated domain. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Include a zero-length segment and an outside collinear query.

## 3. Exercise 3

Handle boundaries before testing strict straddling. Domain:At most 30 elements/vertices; integer magnitudes<=1000 unless narrowed; indices/ranges satisfy the stated domain. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Cover proper crossing,touching,overlapping and disjoint collinear segments.

## 4. Exercise 4

Retain twice the area to avoid truncating half units. Domain:Simple polygon with<=30 vertices; empty/degenerate inputs return 0. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Reverse polygon order and retain the same unsigned doubled area.

## 5. Exercise 5

Count ray crossings with a half-open vertex rule. Domain:Simple polygon<=30 vertices; integer query; returns an explicit boundary category. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Query every vertex,edge midpoint and a point outside a concave polygon.

## 6. Exercise 6

Remove turns that cannot lie on the outer boundary. Domain:At most 30 elements/vertices; integer magnitudes<=1000 unless narrowed; indices/ranges satisfy the stated domain. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Include duplicates and all-collinear points with an explicit hull policy.

## 7. Exercise 7

Enumerate pairs before optimizing spatial search. Domain:At most 30 elements/vertices; integer magnitudes<=1000 unless narrowed; indices/ranges satisfy the stated domain. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Return an actual closest index pair while preserving duplicate positions.

## 8. Exercise 8

Merge by y and inspect only the narrow middle strip. Domain:At most 30 elements/vertices; integer magnitudes<=1000 unless narrowed; indices/ranges satisfy the stated domain. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Compare optimized closest pair with exhaustive pairs on generated point sets.

## 9. Exercise 9

Advance antipodal support points on a convex hull. Domain:At most 30 elements/vertices; integer magnitudes<=1000 unless narrowed; indices/ranges satisfy the stated domain. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Compare diameter with all original point pairs.

## 10. Exercise 10

Divide exact determinants only at the final coordinate step. Domain:Two nondegenerate integer-endpoint lines; coordinate magnitudes<=1000; returned double values checked within 1e-9. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Distinguish parallel,coincident and unique line intersections.

## 11. Exercise 11

Integrate covered physical y-length between x events. Domain:<=30 axis-aligned rectangles with x 1<x 2, y 1<y 2; coordinates magnitude<=1000. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Compare rectangle union with integer unit-cell enumeration.

## 12. Exercise 12

Combine shoelace area with boundary gcd counts. Domain:Simple nondegenerate integer polygon,3..30 vertices, coordinates magnitude<=1000, no holes. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Enumerate boundary and interior lattice points on a tiny rectangle.

