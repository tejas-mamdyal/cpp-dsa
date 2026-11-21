# Directed dependencies and DAG applications

Phase 6 unit 3: 15 worked programs and 12 independent exercises. Complete earlier units first. Read [notes](NOTES.md),then numbered programs,then attempt [practice](PRACTICE.md) before [hints](HINTS.md). Keep assertions enabled. Every worked source is standalone C++17 and prints `checks passed` after its internal checks.

Core route: first two thirds of the numbered lessons. Reinforcement/challenge: remaining lessons;read their notes before attempting,then return before the final assessment. All lesson prerequisites still follow the full numeric reading sequence.

|Order|Worked program|
|---|---|
|01|[Release a dependency only after all incoming arcs are removed](01_kahn_order.cpp)|
|02|[Reverse finish order only after detecting cycles](02_dfs_topological.cpp)|
|03|[Audit a claimed topological order against every edge](03_validate_order.cpp)|
|04|[Orient prerequisites before testing schedulability](04_course_schedule.cpp)|
|05|[Freeze each ready layer to model simultaneous courses](05_parallel_semesters.cpp)|
|06|[Use a min-heap when several dependencies are ready](06_lexicographic_order.cpp)|
|07|[Backtrack over every currently legal next vertex](07_all_dependency_orders.cpp)|
|08|[Count dependency orders before introducing subset DP](08_count_orders_reference.cpp)|
|09|[Relax signed edges once in topological order](09_dag_shortest_paths.cpp)|
|10|[Replace minimum by maximum when acyclicity bounds routes](10_dag_longest_paths.cpp)|
|11|[Accumulate route counts only after predecessors are complete](11_count_dag_paths.cpp)|
|12|[Combine prerequisite finish times with task durations](12_critical_completion_time.cpp)|
|13|[Remove vertices whose remaining successors are all safe](13_eventual_safe_vertices.cpp)|
|14|[Extract only the first differing letter constraint](14_alien_dictionary.cpp)|
|15|[Uniqueness requires exactly one ready choice at every step](15_unique_topological_order.cpp)|

Complete debugging and [the checkpoint](CHECKPOINT.md). Return to [the phase guide](../README.md).

