# Complete operator catalogue

The executable course targets C++17. This catalogue also names C++20 additions;
it does not make coroutines a prerequisite for a first programming lesson.
An operator combines operands into an expression. Unary uses one operand, binary
two, and the conditional operator uses three. A token can have different meanings
according to its operands and syntactic context: `*` multiplies numbers or
dereferences a pointer; `&` performs bitwise AND or takes an address.

## Scalar operators: learn now

| Family | Every spelling | Meaning and small example |
|---|---|---|
|Unary arithmetic|`+a`, `-a`|Unary plus performs numeric promotion; unary minus changes sign. `-5` is minus applied to literal5.|
|Arithmetic|`a+b`, `a-b`, `a*b`, `a/b`, `a%b`|`17/5==3`, `17%5==2`; `%` is integral remainder. Integer division truncates toward zero. `^` is XOR, not a power operator.|
|Increment/decrement|`++a`, `a++`, `--a`, `a--`|Prefix yields the updated value; postfix yields the previous value. Put modifications in separate statements.|
|Assignment|`a=b`|Stores a converted value in a modifiable object; `=` is different from `==`. Assignment associates right-to-left.|
|Arithmetic compound assignment|`+=`, `-=`, `*=`, `/=`, `%=`|`a+=3` updates a by addition; the left expression is evaluated once. Conversions still matter.|
|Equality/ordering|`==`, `!=`, `<`, `<=`, `>`, `>=`|Produces a bool. `a<b<c` does not check a range; write `a<b && b<c`. NaN has exceptional comparison behavior.|
|Logical|`!`, `&&`, `||`|Truth conversion; built-in AND/OR short circuit left-to-right. `d!=0 && n/d>2` guards division.|
|Bitwise|`~`, `&`, `^`, `\|`|Acts on promoted integral bits. `12^10==6`; `x^x==0`. Complement flips the whole promoted width, not just printed digits.|
|Shifts|`<<`, `>>`|`12U<<1` is24; `12U>>2` is3. Use unsigned values; count must be in `[0,width)`. Stream `<<`/`>>` are overloads, not bit shifts.|
|Bit compound assignment|`&=`, `^=`, `\|=`, `<<=`, `>>=`|Set/clear/toggle/update bit patterns. `flags &= ~mask` clears masked bits.|
|Conditional|`condition ? yes : no`|Only the chosen value expression is evaluated. Avoid complicated nested conditional expressions.|
|Comma|`(left, right)`|Built-in comma sequences left before right and yields the right result. `f(a,b)` argument separators are not comma operators.|
|Size|`sizeof(T)`, `sizeof expression`|Produces a `size_t` count of bytes; ordinary operand is unevaluated. `sizeof(char)==1`; use `CHAR_BIT` for bits per byte.|
|Alignment|`alignof(T)`|Reports the alignment requirement in bytes; useful for storage, not element count.|

Signed overflow and division/remainder by zero are undefined behavior. Also avoid
`INT_MIN/-1` and negating `INT_MIN`. Unsigned arithmetic wraps modulo its width,
which is defined but may still be a bug. C++17 right-shift of negative signed values
is implementation-defined; the beginner bit examples use nonnegative unsigned values.
Integer promotion means even small integer types may first become int.

## Object and pointer operators: learn in Phase2

| Family | Spellings | Explanation and working lesson |
|---|---|---|
|Address/dereference|unary `&`, unary `*`|`int* p=&x; *p=7;` borrows and accesses x. [Null access](../../../02-core-cpp/04-pointers-and-memory/reference-practice/03_null_and_optional_access.cpp) shows the necessary guard. `int& ref` and `int* p` in declarations declare types; they are not expression operators.|
|Subscript|`a[i]`|For a built-in array/pointer, `a[i]` means `*(a+i)`; i must be in bounds. Standard containers may overload it. [Array/pointer bounds](../../../02-core-cpp/04-pointers-and-memory/reference-practice/05_array_pointer_bounds.cpp).|
|Call|`f(args)`|Calls a function or callable object; [function pointers](../../../02-core-cpp/04-pointers-and-memory/reference-practice/07_function_pointers.cpp) and [callable objects](../../../03-standard-library/10-lambda-practice/05_functor_and_wrapper.cpp).|
|Members|`.`, `->`|`object.member`, `pointer->member`; the latter means `(*pointer).member`. [this and members](../../../02-core-cpp/05-classes-and-objects/practice/03_this_and_const_methods.cpp).|
|Pointer-to-member|`.*`, `->*`|Combine an object or pointer with a class member pointer; [working example](../../../02-core-cpp/05-classes-and-objects/practice/09_member_pointer_operators.cpp). They are distinct from ordinary pointer arithmetic.|
|Scope resolution|`::`|`std::cout`, `Class::member`, `::global`; qualifies a name rather than performing runtime arithmetic. [Scope example](../../../02-core-cpp/05-classes-and-objects/practice/10_namespaces_scope.cpp).|
|Allocation/deallocation|`new`, `new[]`, `delete`, `delete[]`|Allocate/construct and destroy/deallocate with matching forms. [Scalar](../../../02-core-cpp/04-pointers-and-memory/ownership-practice/01_new_delete_scalar.cpp), [array](../../../02-core-cpp/04-pointers-and-memory/ownership-practice/02_new_delete_array.cpp). Prefer automatic storage, vector or unique_ptr. `new T{}` value-initializes; nothrow new returns null on allocation failure.|
|Static conversion|`static_cast<T>(x)`|Explicit checked-at-compile-time conversion, not general runtime safety. [Scalar conversion](12_conversions.cpp).|
|Runtime conversion|`dynamic_cast<T>(x)`|Checked hierarchy conversion; failed pointer conversion is null, failed reference conversion throws. [RTTI example](../../../02-core-cpp/06-modern-essentials/polymorphism-practice/05_dynamic_cast_typeid.cpp).|
|Qualification conversion|`const_cast<T>(x)`|Adjusts const/volatile qualification; cannot make an originally const object safely writable. [Safe limited case](../../../02-core-cpp/04-pointers-and-memory/ownership-practice/09_const_cast_safe_case.cpp).|
|Representation conversion|`reinterpret_cast<T>(x)`|Low-level reinterpretation with strict lifetime/alignment/aliasing obligations. [Byte inspection](../../../02-core-cpp/04-pointers-and-memory/ownership-practice/10_reinterpret_object_bytes.cpp).|
|Other cast syntax|`(T)x`, `T(x)`|C-style and functional explicit conversion forms can conceal several different conversions. Prefer the named form explaining the intent.|
|Runtime type|`typeid(T)`, `typeid(expression)`|A type_info description; a dereferenced polymorphic object can reveal dynamic type. Included in the RTTI example.|
|Exception inspection|`noexcept(expression)`|An unevaluated compile-time boolean; distinct from a function noexcept specification. [Example](../../../02-core-cpp/08-error-handling/practice/04_noexcept_expression.cpp).|
|Throw expression|`throw value`, `throw`|Creates an exception or rethrows the active one from a handler. Often classified separately from the operator tables. [Throw/catch](../../../02-core-cpp/08-error-handling/practice/01_throw_and_catch.cpp).|
|Pack size|`sizeof...(Pack)`|Counts a template parameter pack. Example: `template<class... Ts> constexpr std::size_t count = sizeof...(Ts);` then `count<int,double>` is2. This requires variadic templates and belongs in the later engineering phase.|

Placement new, for example `new (buffer) Widget{}`, constructs in suitably aligned,
sufficient, already allocated storage. Destruction is explicit and ordinary delete
must not be applied to that buffer. This advanced lifetime technique is not needed
for DSA container use and should follow storage/lifetime engineering.

## Overloading does not change the grammar

Class operators are functions named `operator+`, `operator()`, and so on. [Point
addition/equality](../../../02-core-cpp/05-classes-and-objects/practice/08_operator_overloading.cpp)
shows a conventional value-type design. Operators cannot acquire new precedence or
arity. `.`, `.*`, `::`, `?:`, sizeof, alignof, typeid and noexcept cannot be overloaded.
At least one operand of ordinary overloaded operators must involve a class or enum.
Allocation functions have separate rules. Overloaded `&&`/`||` do not provide the
built-in short-circuit behavior: both function arguments must be evaluated.

## Precedence and associativity

Higher rows bind more tightly; parentheses express intent. Within a row, binary
operators generally associate left-to-right unless marked otherwise.

| High to low | Operators |
|---|---|
|Qualified names|`::`|
|Postfix|call, subscript, member access, postfix++/--|
|Unary (right-to-left)|prefix++/--, unary+/-, !, ~, *, &, casts, sizeof, alignof, noexcept, new/delete|
|Pointer-to-member|`.*`, `->*`|
|Multiplicative|`* / %`|
|Additive|`+ -`|
|Shift|`<< >>`|
|C++20 comparison|`<=>`|
|Relational|`< <= > >=`|
|Equality|`== !=`|
|Bitwise AND, XOR, OR (three levels)|`&`, then `^`, then `\|`|
|Logical AND, OR (two levels)|`&&`, then `\|\|`|
|Conditional/assignment (right-to-left)|`?:`, `=`, all compound assignments; throw expressions share this low binding context|
|Comma|`,`|

This is a practical grouping guide, not a replacement for the grammar: the middle
operand of ?: is parsed as if parenthesized. Associativity is not execution order.
Do not write puzzles such as `i++ + ++i`; separate the operations.

## Alternative tokens and lookalikes

`and &&`, `or ||`, `not !`, `bitand &`, `bitor |`, `xor ^`, `compl ~`,
`and_eq &=`, `or_eq |=`, `xor_eq ^=`, `not_eq !=` are equivalent spellings.
Digraph punctuators `<: :> <% %> %: %:%:` spell `[ ] { } # ##`; they are uncommon
and not additional runtime operators. Preprocessor `#` stringizes macro arguments,
`##` pastes tokens and `defined(NAME)` tests a macro in #if. `__has_include(<header>)`
is a C++17 preprocessing query. These belong to preprocessing, not arithmetic.
`decltype(expression)` determines a type and can preserve reference categories;
`alignas` specifies alignment, `static_assert` checks a compile-time condition,
`...` expands packs, and lambda capture brackets/initializer braces are related
syntax rather than new arithmetic operators. `&&` in a declaration can mean an
rvalue reference rather than logical AND. There is no exponentiation operator.

## C++20 additions and later syntax

`a <=> b` is three-way comparison, returning an ordering category rather than a
bool. Example with `<compare>`: `auto order = 3 <=> 5; bool less = order < 0;` gives
true. Floating comparison may be unordered for NaN. It has its own precedence row
between shifts and ordinary relational comparison. Compile such code with C++20.

`co_await expression` is a C++20 unary operator used in a coroutine. It obtains an
awaiter, checks await_ready, optionally suspends through await_suspend, and gets a
result through await_resume. A ready-only educational awaiter is:

```cpp
struct ReadyValue {
    bool await_ready() const noexcept { return true; }
    void await_suspend(std::coroutine_handle<>) const noexcept {}
    int await_resume() const noexcept { return 42; }
};
// Inside a coroutine with an appropriate promise_type:
// int answer = co_await ReadyValue{};  // immediately produces 42
```

This fragment is intentionally not a standalone first-year program: it needs
`<coroutine>` and a coroutine return/promise owner that manages the frame lifetime.
`co_yield value` is a related coroutine expression, not an ordinary arithmetic
operator; `co_return` is a coroutine statement. C++23 multidimensional overloaded
subscripts and static call/subscript operators extend overload declarations;
C++26 pack indexing is template syntax, not a new scalar operator. Advanced
version-specific material does not change this repository's C++17 baseline.

Primary language references: [C++ working-draft expressions](https://eel.is/c++draft/expr),
[operator overload rules](https://eel.is/c++draft/over.oper),
[three-way comparison](https://eel.is/c++draft/expr.spaceship), and
[await expressions](https://eel.is/c++draft/expr.await). The draft is newer than
C++17, which is why later features are labelled separately above.

