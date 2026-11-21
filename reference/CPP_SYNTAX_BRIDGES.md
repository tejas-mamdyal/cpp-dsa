# Small syntax bridges used by the migrated examples

Read each section before its first linked example. These explain compact syntax;
they do not replace the dedicated pointer, ownership, class or recursion lessons.
The global route is in ../LEARNING_ORDER.md; source comments repeat relevant notes.

## Names and output

`std::` selects a name from the standard-library namespace. `using namespace std;`
allows unqualified names such as cout in its scope; it does not create objects or
include headers. Prefer explicit names in new code. `std::endl` prints a newline
and flushes buffered output; `'\n'` just prints a newline.

`1LL` is a long long integer literal; `1U` is unsigned; `1ULL` is unsigned long long.
Literal type affects arithmetic before the result is assigned. `++i` increments i;
`i++` also increments but yields the old value if its result is used. In standalone
loop updates that result is ignored. `--i` and `i--` similarly decrement.

## Type deduction and range loops

`auto x=expression;` asks the compiler to deduce the type from the initializer;
it is still a fixed compile-time type, not a dynamically changing value.
`for (char c : text)` visits each character by value in order. A reference form
such as `auto& x` aliases each element; read the reference lessons before using it.

## Standard template interfaces

`std::vector<int>` means a vector with int elements; the type between angle
brackets is a template argument. `std::array<int,3>` also supplies a fixed element
count. Using a library template does not require implementing one. User-defined
template declarations remain in the later C++ engineering chapter.

`.` accesses an object's member; parentheses call a member function. A string
stores text, `.size()` returns a length, and `[]` selects one character. A vector
has a similar interface but stores arbitrary typed elements. Their complete
interfaces and invalidation rules belong in Phase2 before algorithms use them.

## Constructors and class syntax

`Point(int x) : member(x) {}` initializes member before entering the body. Members
are initialized in their declaration order. A trailing `const` on a member
function promises it will not modify ordinary members of the current object.
`explicit` on a converting constructor prevents unintended implicit conversions.
`= default` requests the compiler's normal operation; `= delete` forbids an operation.

`ptr->field` means `(*ptr).field`: first follow a pointer, then access the field.
This notation must follow pointer and class lessons. `this->field` selects the
current object's member, often to distinguish it from a same-named parameter.

`using Item = SomeType;` gives an existing type another name. Braced construction
such as `Point{2,3}` initializes a compatible object from those values; for a simple
aggregate struct, values correspond to member declaration order. `return {};`
value-initializes the return type (an empty vector in the examples that use it).

## Iterator ranges and library operations

An iterator identifies a position in a collection; it is not necessarily a raw
pointer. `[begin,end)` includes begin and excludes end. The end position is not an
element and must not be dereferenced. `rbegin/rend` express reverse traversal;
they are boundary objects, not permission to create an invalid raw pointer.

`sort(begin,end)` reorders a range ascending by default; `reverse(begin,end)`
reverses it. Learning the callable API is separate from implementing sorting.
Read the iterator lesson before using them and the comparator lesson before
supplying a custom ordering. `min(a,b)`/`max(a,b)` return one smaller/larger value;
their two-value use does not require a sorting algorithm.

## Pairs, bindings and callable syntax

A pair stores two values as `.first` and `.second`. `auto [a,b]=pair;` introduces
two names initialized from those fields. `auto& [a,b]` instead refers to existing
members; use it only after references. A tuple generalizes this to more values.

A lambda has captures, parameters and body: `offset{return x+offset;}`.
`[]` captures nothing; `[&]` refers to used surrounding variables; `[=]` copies them.
Generic lambda parameters `auto a` deduce their type separately at a call. The
dedicated capture lesson explains this syntax; graph/backtracking examples use named helpers.
Do not let a reference capture outlive its original variable.

`std::function<R(Args...)>` holds a callable with a specified input/output signature.
In `std::function<void(int)> dfs; dfs=&{...dfs(v)...;};`, dfs must be
assigned before calling it; recursion and reference captures must already be taught.

## Stream and parser vocabulary

`std::ws` consumes leading whitespace in a stream. `getline` reads a line;
formatted `>>` may leave a newline, so mixing them requires an explicit policy.
`std::size_t` is an unsigned size/index type; `string::npos` denotes no found position.
`std::istringstream` reads values from a string using the same extraction syntax as
cin. Check extraction success, then try reading an extra character to reject trailing
junk. When reading a whole whitespace-separated line, consume whitespace and check
for EOF before attempting the next integer, so overflow is not mistaken for clean EOF.
`peek()` inspects the next character; `get()` consumes one. `std::quoted` reads quoted
fields, including embedded spaces. See the parsing unit for individual examples.

## Cost vocabulary before formal analysis

O(log n) grows with the number of repeated halvings:16→8→4→2→1 takes four
halvings. O(n log n) combines n-scale work with that many levels. O(sqrt(n))
checks candidates up to the square root. These are growth descriptions, not
measured seconds. Formal comparison and proofs follow in the complexity chapter.
An amortized O(1) append may occasionally cost O(n) when storage grows; averaged
across many appends the total work is linear, not every call individually constant.

