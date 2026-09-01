# Types, Variables, and the Memory Model

This lesson introduces the built-in C++ types, safe initialization and
conversion practices, and the relationship between objects, scope, lifetime,
storage duration, and memory addresses. The examples use small guidance,
navigation, and control (GNC) values to connect the language rules to
engineering software.

## Learning objectives

After completing this lesson, you should be able to:

- choose an appropriate fundamental type for a value;
- explain the difference between signed and unsigned integer arithmetic;
- describe floating-point precision and compare floating-point values with an
  appropriate tolerance;
- distinguish character values, integer values, and Boolean states;
- use `const` and brace initialization to make intent explicit;
- identify implicit, explicit, and narrowing conversions;
- distinguish scope, lifetime, and storage duration;
- inspect an object's size, value, and address; and
- explain the practical difference between automatic and dynamic storage.

## Lesson sequence

1. [`01_fundamental_types.cpp`](01_fundamental_types.cpp) — introduces integer,
   floating-point, character, and Boolean types and inspects their sizes with
   `sizeof`.
2. [`02_signed_unsigned.cpp`](02_signed_unsigned.cpp) — compares signed and
   unsigned integers, their ranges, and unsigned wraparound.
3. [`03_floating_point.cpp`](03_floating_point.cpp) — explores precision,
   representation error, machine epsilon, accumulation, and approximate
   comparison.
4. [`04_bool_and_char.cpp`](04_bool_and_char.cpp) — demonstrates Boolean
   formatting, character codes, character arithmetic, and simple GNC state
   values.
5. [`05_const.cpp`](05_const.cpp) — separates values that must not change from
   mutable program state.
6. [`06_initialization.cpp`](06_initialization.cpp) — compares copy, direct,
   brace, and value initialization.
7. [`07_type_conversions.cpp`](07_type_conversions.cpp) — demonstrates implicit
   and explicit conversions, integer division, and `static_cast`.
8. [`08_narrowing_conversions.cpp`](08_narrowing_conversions.cpp) — examines
   conversions that can discard range, precision, or sign information.
9. [`09_scope_and_lifetime.cpp`](09_scope_and_lifetime.cpp) — introduces block
   scope, shadowing, loop scope, and automatic object lifetime.
10. [`10_memory_addresses.cpp`](10_memory_addresses.cpp) — observes object
    addresses, assignment, copies, and the lifetime of a scoped object.
11. [`11_stack_heap_intro.cpp`](11_stack_heap_intro.cpp) — previews automatic
    and dynamic storage before the later lessons on references, pointers, and
    resource management.

## Key ideas

### Fundamental types and sizes

C++ provides fundamental types including `bool`, `char`, signed and unsigned
integer types, and floating-point types. `sizeof(T)` reports the size of `T` in
C++ bytes. A `char` always occupies exactly one byte, but a byte is not required
to contain eight bits; `CHAR_BIT` reports the number of bits on the current
implementation. Most other type sizes and ranges are implementation-defined,
so do not assume that `int`, `long`, or a pointer has the same size everywhere.

Use `std::numeric_limits<T>` when code needs the properties of a type:

```cpp
std::numeric_limits<int>::min();
std::numeric_limits<int>::max();
std::numeric_limits<unsigned int>::max();
```

### Signed and unsigned arithmetic

Unsigned integer arithmetic is performed modulo \(2^N\), where `N` is the
number of value bits. Subtracting one from zero therefore produces the maximum
representable value for that unsigned type. Signed integer overflow is
different: it is undefined behavior and must not be used as a wraparound
mechanism.

Mixing signed and unsigned operands can also trigger conversions that produce
surprising comparisons or arithmetic. Prefer signed types for ordinary
quantities unless modular arithmetic, bit manipulation, or an interface gives
you a concrete reason to use an unsigned type.

### Floating-point values

`float` and `double` represent a finite set of values, so many decimal
fractions—including `0.1` and `0.2`—cannot be stored exactly. This is why a
calculated result should not usually be compared with `==` when small rounding
errors are acceptable.

The example introduces an absolute-tolerance comparison:

```cpp
const double tolerance{1e-12};

if (std::abs(sum - 0.3) < tolerance)
{
    std::cout << "Approximately equal\n";
}
```

A fixed absolute tolerance is suitable for values near a known scale. General
numerical code often needs a combination of absolute and relative tolerances
chosen from the units, magnitude, sensor accuracy, and numerical algorithm.
`std::numeric_limits<T>::epsilon()` describes spacing near `1`; it is not a
universal comparison tolerance.

### Initialization and constants

These examples show three common initialization forms:

```cpp
int copyInitialized = 10;
int directInitialized(20);
int braceInitialized{30};
```

Brace initialization is a good default because it rejects many narrowing
conversions. Empty braces value-initialize arithmetic types, producing zero for
the examples in this lesson:

```cpp
int count{};          // 0
double velocity{};    // 0.0
bool systemReady{};   // false
```

Use `const` when an object should not be modified after initialization. This
documents intent and lets the compiler reject accidental assignments.

### Conversions and narrowing

An implicit conversion happens without cast syntax. An explicit conversion
such as `static_cast<int>(value)` makes the conversion visible, but it does not
make a lossy conversion safe. The programmer must still check that the range,
precision, and sign behavior meet the program's requirements.

Pay particular attention to:

- floating-point to integer conversion, which discards the fractional part;
- `double` to `float`, which can lose range or precision;
- large integer to floating-point conversion, which can lose exactness;
- signed to unsigned conversion, which uses modulo arithmetic; and
- integer division, which occurs before assignment to a `double` unless at
  least one operand is converted first.

### Scope, lifetime, and storage duration

These concepts are related but distinct:

- **Scope** determines where a name can be used in source code.
- **Lifetime** is the period during execution when an object exists.
- **Storage duration** describes the minimum duration for which storage is
  retained for an object.

Most local variables in these examples have automatic storage duration. Their
lifetime normally begins when execution reaches their declaration and ends
when execution leaves their block. A nested declaration can shadow an outer
name, but shadowing does not modify or replace the outer object.

### Objects and addresses

The address-of operator (`&`) reveals where an object is stored. Assigning a
new value normally changes the object's value without changing its identity or
address. Initializing a second variable from the first creates a separate
object with its own address:

```cpp
int original{42};
int copy{original};
```

Addresses printed during different program runs may differ. Do not infer
portable layout rules from one run, and never use an address after the referred
object's lifetime has ended.

### “Stack” and “heap” terminology

The C++ standard specifies storage durations, not a required stack-and-heap
machine architecture. In typical implementations:

- local objects with automatic storage duration are commonly stored on a call
  stack and cleaned up automatically when their scope is exited; and
- dynamically allocated objects are commonly stored in a heap or free store
  and can outlive the scope in which they were created.

This lesson only previews dynamic storage. Manual allocation is intentionally
deferred until references, pointers, RAII, and smart pointers provide the
ownership concepts needed to manage it safely.

## Build and run the examples

From this lesson directory, compile an individual example with warnings
enabled:

```bash
mkdir -p build
g++ -std=c++20 -Wall -Wextra -Wpedantic \
    03_floating_point.cpp -o build/03_floating_point
./build/03_floating_point
```

Replace the source and output names to run another example. Address values and
some type sizes may vary across systems and runs; those differences are part
of the lesson.

To ask the compiler for additional conversion diagnostics, add:

```bash
-Wconversion -Wsign-conversion
```

These warnings are especially useful with
[`07_type_conversions.cpp`](07_type_conversions.cpp) and
[`08_narrowing_conversions.cpp`](08_narrowing_conversions.cpp).

## Suggested exercises

1. Print the minimum, maximum, and size of several integer types on your
   system. Record which properties are guaranteed by C++ and which are specific
   to your implementation.
2. Change the number of `0.1` additions in the floating-point example and
   observe how the accumulated error changes.
3. Uncomment the narrowing brace-initialization examples and inspect the
   compiler diagnostics.
4. Compare `5 / 2`, `5.0 / 2`, and `static_cast<double>(5) / 2`.
5. Print the addresses of an outer variable and a shadowing inner variable to
   confirm that they are distinct objects.
6. Compile the conversion examples with `-Wconversion -Wsign-conversion` and
   explain every warning before changing the code.

## Engineering takeaways

- Select types from the value's meaning, required range, precision, and units.
- Initialize every object and prefer brace initialization by default.
- Make immutable configuration and physical constants `const`.
- Treat every narrowing conversion as a deliberate engineering decision.
- Choose floating-point tolerances from the problem domain, not by habit.
- Keep scopes small, avoid unnecessary shadowing, and never access an object
  outside its lifetime.
- Prefer automatic lifetime and RAII-based ownership; dynamic allocation is a
  tool to learn after the ownership model is clear.
