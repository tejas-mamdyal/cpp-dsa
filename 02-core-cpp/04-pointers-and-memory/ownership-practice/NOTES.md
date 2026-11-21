# Ownership lifetime and RAII: notes

Automatic objects end at scope exit; dynamic objects need a responsible owner. Match new/delete and new[]/delete[] exactly. Clearing one pointer does not repair other dangling aliases. The raw allocation examples explain the mechanism; practical sequences should use vector and exclusive dynamic objects should use unique_ptr.

RAII ties resource release to object lifetime, including early return and exception propagation. unique_ptr owns exclusively and transfers ownership through move; shared_ptr shares a lifetime and weak_ptr observes without extending it. Shared cycles need non-owning weak edges. std::move enables a move operation and does not itself transfer anything.

The rule of zero favors standard owner members over custom cleanup. const_cast cannot make an originally const object mutable. reinterpret_cast is a low-level representation operation, not a substitute for numeric conversion or a way around lifetime/aliasing rules. The byte-inspection lesson is a limited safe example.

## Concepts in the worked programs

### 01 new delete scalar

Value-initialize one dynamically allocated int, modify it, and release it once.

Trace: new int(4) gives4; write9 then delete. Exactly one owner releases exactly one allocation.

Cost: O(1) payload storage; allocation cost is implementation-dependent. Pitfall: Do not dereference after deletion, delete twice, or use delete[] for scalar new. Prefer automatic storage unless dynamic lifetime is needed.

### 02 new delete array

Allocate three value-initialized ints and release with delete[].

Trace: zero-initialized values become2,4,6 and sum12. The allocation creates n ints; the matching array deletion ends their lifetimes.

Cost: O(n) initialization and O(n) allocated storage. Pitfall: delete and delete[] are not interchangeable. Prefer vector for resizable sequences.

### 03 destructor scope

Use a local scope and a destruction counter to observe deterministic cleanup.

Trace: counter0 inside scope; counter1 after leaving. The automatic object is destroyed at the closing brace.

Cost: O(1) time and space. Pitfall: The referenced counter must outlive the Guard. A destructor should not throw during stack unwinding.

### 04 unique owner

make_unique creates a resource with one owner; get borrows, reset destroys.

Trace: owned value7; reset produces an empty owner. unique_ptr automatically deletes its resource when reset or destroyed.

Cost: O(1) payload and ownership bookkeeping. Pitfall: Do not construct a second owner from owner.get() or call delete on the borrowed pointer.

### 05 move ownership

Move a unique_ptr to transfer the resource; the source unique_ptr becomes empty.

Trace: source owns12, then destination owns12 and source is null. unique_ptr move transfers its stored pointer and clears the source.

Cost: O(1) transfer, no int copy/allocation. Pitfall: std::move itself is a cast enabling a move operation. General moved-from objects are valid but have type-specific state guarantees.

### 06 shared and weak

shared_ptr shares a lifetime; weak_ptr observes without extending it. lock obtains a temporary owner.

Trace: two owners -> one -> expired weak observation. The last shared owner destroys the int; a weak observer alone does not keep it alive.

Cost: O(1) handles; reference-count updates and allocation add overhead. Pitfall: Shared cycles leak ownership; use weak links where ownership should not be circular. Counts are only illustrative in single-threaded code.

### 07 rule of zero

Use a vector-owned Buffer and copy it without defining a destructor or copy operation.

Trace: changing the copied buffer leaves original data intact. The vector member supplies its own correct value semantics and cleanup.

Cost: O(n) copy time and storage. Pitfall: Do not write a raw-pointer resource-owning class when a standard owner already meets the requirement.

### 08 cleanup on exception

Throw after constructing a guard and observe cleanup before catch.

Trace: active counter1 in try,0 by catch. Stack unwinding invokes destructors of fully constructed automatic objects.

Cost: O(1) demonstration state; exception runtime costs are implementation-dependent. Pitfall: Read exception basics before this bridge. A leaked raw new allocation has no automatic cleanup unless an owner was established.

### 09 const cast safe case

Remove const only from a view that actually refers to an originally mutable int.

Trace: mutable value3 observed through const int*, then restored mutable view writes4. The original object is mutable, so restoring a writable view here is permitted.

Cost: O(1) time and space. Pitfall: Writing through a cast to an actually const object is undefined; prefer fixing an API rather than using const_cast.

### 10 reinterpret object bytes

Read an int representation through const unsigned char*. Never assume byte order or write an unrelated typed object.

Trace: sizeof(int) bytes can be visited; the value remains42. Character-byte types may inspect object representation; no unrelated typed dereference is performed.

Cost: O(sizeof(int)) time, O(1) space. Pitfall: reinterpret_cast is not a numeric conversion and does not fix alignment, lifetime or aliasing violations. Prefer ordinary typed access.


