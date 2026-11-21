# Campus route planner

[Source](01_campus_route_planner.cpp) combines graph input validation,algorithm selection,negative-cycle policy and route reconstruction. Complete all five graph units first.

## Input and behavior

Read `n m source target`,then m directed `from to weight` arcs. Building IDs are0..n-1;n1..30,m0..100,weights within +/-1000000. Document names alongside IDs (for example0 Library,1 Lab,2 Cafe). A two-way road needs two arcs. Loops and parallel arcs are retained. Malformed,incomplete,out-of-range or extra input prints ERROR without processing a partial graph.

Selection examines the whole graph:all weights1 uses BFS;otherwise all0/1 uses01BFS;otherwise all nonnegative uses DIJKSTRA;otherwise BELLMAN-FORD. Output begins `ALGORITHM name`. Then print UNREACHABLE,UNBOUNDED,or `DISTANCE value` followed by `PATH` and building IDs. A reachable negative cycle invalidates a destination only when the cycle can also reach it. The empty source-target route costs0 unless unbounded.

## Milestones and tests

1. Parse and validate all fields before constructing adjacency.
2. Implement unit-edge BFS with parent reconstruction.
3. Add0-1 and nonnegative heap variants with stale-entry guards.
4. Add signed Bellman-Ford and propagation of negative-cycle influence.
5. Select by proven domain and compare witnesses with direct references.
6. Test unreachable,source=target,parallel,zero-cost,negative and invalid cases.

The exact manifest includes10 cases covering all four branches and error policies. Independent generated DAG comparisons verify finite values and route costs;targeted cycle cases verify unboundedness. Complexity depends on the selected algorithm,as detailed in the source. A geographic map,live traffic and persistence are outside this bounded learning project's contract.

From the repository root:

Extension:map external building names to IDs,then add waypoints and closures with a fresh route computation. Explain why an undirected negative road creates an unbounded two-arc walk before admitting such a road into a cost model.

