# Indexing and storage debugging lab

Faulty snippets stay in this document, not compilable teaching sources. Diagnose
by tracing indices; do not run undefined behavior to guess an expected output.

| Faulty idea | Why it fails | Repair/test |
|---|---|---|
| for(i=0;i<=n;++i) reads n elements | One extra index is visited | Use i<n; test n=capacity |
| Read n before validating n<=capacity | Input writes may exceed storage | Validate length first; test n=11 |
| max=0 for signed input | Zero may never occur | Initialize from first actual value; test[-9,-2] |
| Right-shift from left to right | Overwrites values still needed | Copy backward; insert at0 |
| n++ before checking room | Can exceed physical capacity | Reject full storage before shifts |
| Print capacity items after deletion | Includes inactive stale value | Print only new active length |
| Use rows for both matrix loop bounds | Nonsquare input is mishandled | Use columns for inner bound; test2x3 |
| Transpose to original output dimensions | Result shape is wrong | Print columns rows and rows columns |
| Add both diagonals unconditionally | Double-counts odd-square center | Add opposite only if distinct; test1x1 |
| Flatten with r*rows+c | Incorrect stride for nonsquare data | Use active column count; test2x3 |

Debugger task: pause before the first right-shift assignment and watch source and
destination indices. Predict the array after each step. For a matrix, inspect one
row at a time and compare the active rectangle with its larger physical capacity.

