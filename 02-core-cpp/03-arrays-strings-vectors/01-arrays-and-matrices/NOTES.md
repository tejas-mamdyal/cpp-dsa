# From individual variables to retained collections

Phase1 could find a total while reading values one at a time. That is enough when
only the total is needed. If you must later revisit the first value, update a chosen
position or show the original sequence, retaining the values becomes useful.

## Storage and indexing

`int values[5]` declares five contiguous int objects under one name. Square brackets
in the declaration specify capacity; square brackets in `values[i]` select one
element. Indices are zero-based: first0, last4. A loop using `i<5` visits each once.
An index outside the actual array is undefined behavior, not a guaranteed exception.

`int values[5]{}` initializes every int to0. `int values[5]={7,8}` initializes
the remaining three to0. `int values[5];` leaves local int values uninitialized:
do not read an element before assigning it. The program must not assume zeroing.

| Index |0|1|2|3|4|
|---|---:|---:|---:|---:|---:|
| After `{10,20,30,40,50}` |10|20|30|40|50|
| After `values[1]=99` |10|99|30|40|50|

A built-in array has fixed capacity. In this unit `const int capacity=10` is a
compile-time bound and `n` is the active length. When n=3, only indices0..2 are
application data even though ten objects exist. Validate the length before reading,
and an index before accessing. Spare capacity is not permission to access a value
outside the logical sequence. Insertion is different: it may fill a new slot after
checking capacity and may accept position==n.

Standard C++17 does not provide runtime-sized local arrays such as `int values[n]`.
Some compilers accept them as extensions; this course avoids them. Vectors in a
later unit support runtime growth while handling storage automatically.

## Repeated access and copies

After storing data, a second pass can calculate positions or compare against an
aggregate. A raw array cannot be assigned or copied as one object with `a=b`;
copy elements explicitly here. Vector/string copying later provides value semantics.
Array function-parameter rules involve pointers and are deferred to their unit;
do not assume an array passed to a function automatically carries its length.

## Make space without overwriting a source

To insert99 at position1 in `[10,20,30]`, shift right from the end:

| Step | active data / temporary gap |
|---|---|
| Start |10 20 30|
| Copy index2 to3 |10 20 30 30|
| Copy index1 to2 |10 20 20 30|
| Fill index1 and increase length |10 99 20 30|

Forward right-shifting would overwrite20 before copying it. Deletion shifts in
the opposite direction: copy later values left from the removed position onward,
then decrease active length. Unused former elements still exist in physical storage.

## Matrix indices and logical layout

`int matrix[4][4]{}` is an array of four rows, each an array of four ints.
`matrix[r][c]` selects a column inside a row. Use two loop bounds: rows and columns
need not be equal. Row-first traversal corresponds to the built-in row-major layout.

| Cell in a2x3 active matrix |(0,0)|(0,1)|(0,2)|(1,0)|(1,1)|(1,2)|
|---|---:|---:|---:|---:|---:|---:|
| Logical flattened index |0|1|2|3|4|5|

Logical flattening uses `r*columns+c`. This is not necessarily the physical offset
inside a4-column capacity matrix: the physical row stride remains4 even when the
active columns count is3. Explicit loops construct the compact logical sequence.
The inverse logical mapping is row=`index/columns`, column=`index%columns`.

Transpose changes dimensions from rows-by-columns to columns-by-rows and stores
original[r][c] at result[c][r]. Separate output storage handles nonsquare matrices.
For an n-by-n square, diagonal cells have c==r or c==n-1-r; odd n has one shared
center that should be counted only once when computing the union of diagonals.

## Explain costs honestly

A fixed calculation is O(1); traversing n active values is O(n); a rows-by-columns
matrix pass is O(rows*columns). Two passes add their work, not multiply it. Storage
allocated for capacityC costs O(C), even when only n<C elements are active. This
unit bounds capacities for learning; describe both its fixed allocation and the
generalized algorithm. Extra copy storage differs from an in-place modification.

## Tests before advancing

Use empty/one/full sequences; first/last index; index==n and negative index;
all-negative and duplicate extrema; absent target; insertion at beginning/end;
full-capacity insertion rejection; nonsquare matrices;1x1 diagonals; missing input.
Never deliberately run unchecked out-of-bounds code to infer a reliable result.

