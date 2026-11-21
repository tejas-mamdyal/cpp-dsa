# Phase2 final assessment

60 points, without copying worked implementations. Supply runnable C++17 programs,
explain each data-structure choice and include independently chosen edge tests.
A completed repository is a teaching resource; passing this assessment is your
personal evidence of readiness for Phase3.

1. **Container and complexity decisions (15):** choose structures for a dynamic
   indexed mark list, unique sorted IDs, FIFO requests, top-priority jobs and byte
   frequency counts. Give normal and worst-case costs, ordering and invalidation.
   Rubric: five sensible choices5, justified operation costs5, lifetime/order caveats5.
2. **Value and lifetime reasoning (15):** demonstrate an independent vector copy,
   a borrowed const view, exclusive ownership transfer and weak expiration. Explain
   why returning a local reference and using a vector element after reallocation
   are invalid. Rubric: correct demonstrations6, explicit ownership5, boundaries4.
3. **Record application (15):** create encapsulated student records, validate marks,
   update by ID and produce descending-average reports with ascending-ID ties.
   Include empty, duplicate-ID, equal-average and malformed-input cases. Rubric:
   model4, complete validated operations5, ordering3, independent tests3.
4. **Persistent application (15):** implement contact CRUD and quoted save/load.
   Reject malformed and duplicate files without partially changing current state.
   Explain the difference between staged loading and crash-atomic saving. Rubric:
   full operations4, round trip4, malformed-load invariants4, cost/tradeoffs3.

Aim for48/60 and at least10 in each task. Reference answers are in the unit notes
and project implementations, but use them only after submitting your own attempt.
Complete the debugging lab and both [project rubrics](projects/README.md).

