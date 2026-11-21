# Interfaces inheritance and dispatch: notes

Public inheritance models substitutability through a base interface. Virtual calls through a reference or pointer use the actual object type; override asks the compiler to verify a matching override. A pure virtual function makes a class abstract. A virtual destructor is essential when objects may be deleted polymorphically through a base pointer.

Copying a derived object into a base value slices away derived state and behavior. Prefer borrowing references for polymorphic observations. dynamic_cast checks a polymorphic downcast and typeid can inspect dynamic type; prefer virtual operations over repeated type tests when an interface expresses the task. protected grants derived access; final prevents further deriving or overriding as specified.

## Concepts in the worked programs

### 01 public inheritance

A public derived object may be observed through its base interface.

Trace: Student Ada is-a Person with name Ada. Public inheritance makes the accessible base subobject available through a reference.

Cost: O(n) name construction; O(1) observation. Pitfall: This base is not used for polymorphic deletion; add a virtual destructor when deletion through a base pointer is possible.

### 02 override dispatch

Call a virtual function through a base reference; override checks the signature.

Trace: a Dog observed as Animal still says woof. A virtual call uses the final override associated with the actual object.

Cost: O(1) bounded demonstration. Pitfall: Dropping const from the override signature changes the function; override asks the compiler to reject that mismatch.

### 03 abstract interface

An abstract Shape cannot be instantiated; concrete implementations supply area.

Trace: rectangle3x4 and square5 produce12 and25. measure depends only on the interface, so each concrete shape supplies its own computation.

Cost: O(1) time and space. Pitfall: The example assumes dimensions0..1000. A pure virtual destructor, if declared, still needs a definition.

### 04 object slicing

Copying a Derived into Base creates only a Base object; references retain the original object.

Trace: derived.kind=2; sliced.kind=1; borrowed.kind=2. The sliced value owns no derived subobject, while the reference still denotes the complete Derived.

Cost: O(1) bounded example. Pitfall: Pass polymorphic objects by reference/pointer when you need virtual behavior.

### 05 dynamic cast typeid

dynamic_cast on a polymorphic pointer returns nullptr for a failed cast; typeid inspects dynamic type.

Trace: Dog pointer succeeds for Dog object and fails for plain Animal. The virtual base enables runtime type checking instead of guessing the derived type.

Cost: Runtime cast cost depends on implementation and hierarchy; O(1) example storage. Pitfall: A failed reference dynamic_cast throws bad_cast; a failed pointer cast yields nullptr. Prefer virtual methods when they express the operation directly.

### 06 virtual destructor

Observe a derived destructor through deletion by a base pointer. Raw new/delete appear only in this ownership bridge.

Trace: delete base pointer increments the derived destruction counter exactly once. The virtual base destructor dispatches destruction to the full dynamic object.

Cost: O(1) time/space excluding allocator overhead. Pitfall: Read dynamic memory first. Deleting a Derived through a Base without an appropriate virtual destructor is invalid.

### 07 final and protected

A derived class can access protected base state; final closes an override to further overriding.

Trace: a doubled sensor reading3 reports6. The derived implementation reads inherited protected state through its own object.

Cost: O(1) time and space. Pitfall: protected does not mean public. Prefer private state and protected/public accessors when an invariant needs protection.


