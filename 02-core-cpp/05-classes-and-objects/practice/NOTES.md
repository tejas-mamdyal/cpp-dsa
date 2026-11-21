# Classes records and value semantics: notes

A class combines state with operations that preserve a rule called an invariant. Constructors establish that rule; validate before committing an update. Private data prevents unrelated code from silently breaking it. A const member function observes ordinary state without changing it. this refers to the current object and resolves member/parameter shadowing.

Composition means one object owns member objects. Standard string/vector members already manage copying and destruction: this is the rule of zero. A static member is class-wide, while each ordinary data member belongs to one instance. enum class provides scoped state names. Operator overloads should preserve familiar meaning, such as componentwise Point addition.

Namespaces qualify names with ::. Member pointers describe a member within a class object and use .* or ->*, unlike ordinary address dereferencing. They are catalogue-completeness examples after class fundamentals, not required machinery for simple record programs.

## Concepts in the worked programs

### 01 constructor initialization

Use a default constructor, explicit value constructor and initialization list.

Trace: default counter=0; explicit counter(5)=5. The initialization list constructs the member before any constructor-body statements run.

Cost: O(1) time and space. Pitfall: Members initialize in declaration order, not list order. explicit rejects unintended implicit conversion.

### 02 invariants

Keep an integer account balance nonnegative; deposits and withdrawals return success. Amounts are bounded to 1000 for this exercise.

Trace: deposit50 then withdraw20 leaves30; overdraft fails without mutation. Every successful update preserves 0<=balance<=1000000; rejected operations leave state unchanged.

Cost: O(1) time and space. Pitfall: Checking after mutation can break the invariant; validate before updating.

### 03 this and const methods

this points to the current object; const member functions can observe a const object.

Trace: set(7) stores7; a const counter initialized3 reports3. this->count names the member while count alone names the parameter.

Cost: O(1) time and space. Pitfall: A const method cannot modify ordinary members or call non-const methods on its own object.

### 04 composition

A Rectangle contains two Side values; construct members in declaration order.

Trace: width3,height4 ->area12. The rectangle owns both sides and their lifetimes follow its own.

Cost: O(1) time and space. Pitfall: The input precondition is nonnegative sides <=1000; composition is not inheritance.

### 05 copy semantics

A class containing string and vector gets safe independent copies automatically.

Trace: copy name and marks; editing the copy does not alter the original. Each standard container copies its owned elements.

Cost: O(name length + number of marks) time and storage for the copy. Pitfall: A class holding a raw owning pointer would need an ownership design; do not add manual copy/destructor code to this value-only record.

### 06 static members

An inline static data member is shared by objects; a static function has no this pointer.

Trace: constructing two tickets assigns consecutive IDs1,2. All objects increment the same class-wide counter.

Cost: O(1) time/space per construction. Pitfall: This tiny counter has no concurrent access or overflow handling; static member access uses Class::member.

### 07 enum class

enum class keeps named values scoped and avoids implicit int conversion.

Trace: Status::passed selects a passed message. A scoped enum gives the state a dedicated type and named alternatives.

Cost: O(1) time and space. Pitfall: Do not assume arbitrary integers represent valid enum states; validate external numeric input.

### 08 operator overloading

Define + and == for small 2D integer points. Each coordinate is within [-1000,1000].

Trace: (1,2)+(3,4)=(4,6); inputs are not changed. Componentwise addition returns a new Point without mutating either operand.

Cost: O(1) time and space. Pitfall: Overloading changes meaning for class operands, not operator precedence, arity or evaluation rules; do not invent surprising meanings.

### 09 member pointer operators

A pointer-to-data-member needs an object; it is not a normal int pointer.

Trace: member=&Score::points; object.*member and pointer->*member name the same field. The member pointer describes a member within a compatible class object.

Cost: O(1) time and space. Pitfall: Member function pointer calls require parentheses around object.*method. Keep the object alive.

### 10 namespaces scope

Use :: to select a global, namespace or class name.

Trace: global value1 and school::value2 remain different names. Qualified lookup selects the intended scope explicitly.

Cost: O(1) time/space. Pitfall: Avoid using namespace directives in shared headers; local shadowing can obscure which value is used.

### 11 record collection

Find a record by stable ID using a linear scan; update only the matching record.

Trace: ID2 has90 marks, becomes95; ID9 is absent. A unique ID selects exactly one record; other records remain unchanged.

Cost: O(n) search time and O(1) extra storage. Pitfall: Do not retain references into a vector across reallocation; use IDs and reacquire the record.


