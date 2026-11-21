# Matrix standard questions: notes

A matrix has a shape as well as values. Addition requires equal shapes; multiplication requires matching inner dimensions; transpose exchanges shape. Index mappings express rotations without guessing assignment order. Copying a result first is easier to verify than an in-place four-cell cycle.

Spiral traversal maintains a shrinking unvisited rectangle. Each boundary pass removes one edge; guards after shrinking prevent repeated visits when only a row or column remains. Row-major flattening uses row*columns+column and its inverse division/remainder. Store wider intermediate sums if element bounds can overflow int.

## Concepts in the worked programs

### 01 matrix multiplication

Multiply A[r][k] by B[k][c] and add over k. This 2x2 demonstration uses small int entries.

Trace: [1,2;3,4]*[5,6;7,8]=[19,22;43,50]. Each result cell is the dot product of exactly one A row and B column.

Cost: O(r*k*c) time and O(r*c) result storage. Pitfall: Matrix multiplication is not elementwise multiplication; compatible inner dimensions are required.

### 02 rotate square matrix

Copy source cell row,column to result[column][n-1-row].

Trace: [1,2;3,4] becomes[3,1;4,2]. The destination formula maps each input position to its rotated position uniquely.

Cost: O(n^2) time and O(n^2) result storage. Pitfall: For a rectangular matrix the output dimensions must be exchanged; this example deliberately uses a square.

### 03 spiral traversal

Track inclusive top,bottom,left,right boundaries; guard the final bottom and left passes. Matrix rows have equal size.

Trace: [1,2,3;4,5,6] emits1,2,3,6,5,4. Each pass consumes one remaining boundary, so no cell is visited twice.

Cost: O(rows*columns) time and O(rows*columns) output storage. Pitfall: Without guards a one-row or one-column remainder is emitted twice.


