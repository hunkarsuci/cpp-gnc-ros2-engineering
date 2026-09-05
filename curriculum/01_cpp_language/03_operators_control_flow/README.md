# Operators and Control Flow

This lesson introduces the operators that calculate and compare values and the
control structures that choose which statements run. Small guidance,
navigation, and control (GNC) examples connect these rules to state updates,
sensor checks, flight modes, and simulation loops.

## Learning objectives

After completing this lesson, you should be able to:

- use arithmetic, assignment, comparison, and logical operators;
- distinguish integer division from floating-point division;
- explain prefix and postfix increment and decrement;
- use precedence, associativity, and parentheses to read expressions;
- select branches with `if`, `else if`, `else`, and `switch`;
- choose between `while`, `do-while`, and `for` loops;
- trace the effects of `break` and `continue`; and
- combine loops and conditions while keeping state updates predictable.

## Lesson sequence

1. [`01_arithmetic_operators.cpp`](01_arithmetic_operators.cpp) — addition,
   subtraction, multiplication, division, remainder, unary minus, and a simple
   velocity and position update.
2. [`02_assignment_operators.cpp`](02_assignment_operators.cpp) — simple and
   compound assignment, including `+=`, `-=`, `*=`, `/=`, and `%=`.
3. [`03_comparison_operators.cpp`](03_comparison_operators.cpp) — equality and
   ordering, Boolean output, altitude checks, and floating-point tolerance.
4. [`04_logical_operators.cpp`](04_logical_operators.cpp) — AND, OR, NOT, range
   checks, short-circuit evaluation, and controller readiness.
5. [`05_increment_decrement.cpp`](05_increment_decrement.cpp) — prefix and
   postfix forms of `++` and `--`, plus a sample counter.
6. [`06_oprator_precedence.cpp`](06_oprator_precedence.cpp) — precedence,
   parentheses, and associativity in arithmetic, logical, and assignment
   expressions.
7. [`07_if_else.cpp`](07_if_else.cpp) — branches for altitude, battery status,
   throttle validation, controller enablement, and vertical motion.
8. [`08_switch.cpp`](08_switch.cpp) — integer and character selection, grouped
   case labels, `break`, and `default`.
9. [`09_while_loop.cpp`](09_while_loop.cpp) — counters, countdowns, simulation
   steps, and a mission-completion condition.
10. [`10_do_while_loop.cpp`](10_do_while_loop.cpp) — loops that run at least once
    and an interactive command-range check.
11. [`11_for_loop.cpp`](11_for_loop.cpp) — counted loops, different step sizes,
    simulation updates, and nested row/column traversal.
12. [`12_break_continue.cpp`](12_break_continue.cpp) — early exit, skipped
    iterations, a search, sensor filtering, and breaking an inner loop.
13. [`13_nested_control_flow.cpp`](13_nested_control_flow.cpp) — a simulation
    combining measurement validation, velocity updates, a limit check, and
    conditional reporting.

## Key ideas

### Arithmetic and assignment

For integer operands, `/` performs integer division, truncating toward zero,
and `%` gives the remainder. With `a = 10` and `b = 3`, `a / b` is `3` and
`a % b` is `1`. Convert an operand before division to retain a fractional part:

```cpp
double result{static_cast<double>(a) / b};
```

Assigning an integer quotient to a `double` afterward does not recover the
discarded fraction. Integer division or remainder by zero is undefined behavior.

`=` assigns a value; `==` compares values. Compound assignment updates a value
using its current contents. For the simple variables in these examples,
`velocity += acceleration * dt` expresses the same update as
`velocity = velocity + acceleration * dt`.

Statement order matters: the position update in the first two examples uses
the velocity that was just updated.

### Comparisons and logical conditions

Comparison operators produce a `bool`. `std::boolalpha` prints Boolean values
as `true` and `false` instead of `1` and `0`.

Use `&&` when both conditions must hold, `||` when either is sufficient, and
`!` to negate a condition. Write a range check as two comparisons:

```cpp
bool validThrottle{throttle >= 0.0 && throttle <= 100.0};
```

The built-in logical operators short-circuit: `&&` skips its right operand
when the left is false, and `||` skips its right operand when the left is true.
This makes the ordering in the following guard essential:

```cpp
bool validDivision{denominator != 0 && 10 / denominator > 2};
```

Floating-point calculations can introduce rounding error. The comparison
example uses `std::abs(x - expected) < tolerance` for approximate equality.
Choose a tolerance from the value's scale and required accuracy; the example's
`1e-12` is not a universal threshold.

### Increment, precedence, and associativity

Both `++value` and `value++` increment the variable. Prefix produces the updated
value; postfix produces the previous value. Decrement follows the same rule.
When used as a standalone statement, either increment form has the same effect
on the integer counter.

Precedence determines how operators group: `2 + 3 * 4` is `14`, whereas
`(2 + 3) * 4` is `20`. Associativity determines grouping at the same precedence:
`20 / 5 * 2` groups as `(20 / 5) * 2`, and `first = second = source` groups as
`first = (second = source)`.

`&&` has higher precedence than `||`, so `a || b && c` means `a || (b && c)`.
Use parentheses when they make intent easier to read. Precedence and
associativity describe grouping, not a general left-to-right evaluation order;
keep state-changing operations in separate statements when their order matters.

### Choosing branches and loops

An `if` / `else if` / `else` chain executes the first matching branch. Order
overlapping conditions carefully: the battery example checks the critical
threshold before the broader low-battery threshold.

A `switch` selects a case using an integral or enumeration value, including
`int` and `char`. Case labels are constant values. `default` handles values
without a matching case; `break` exits the switch. Without an exit, execution
can continue into the next case. Multiple labels can intentionally share one
body, as `'y'` and `'Y'` do in the example.

| Structure | Condition checked | Typical use |
| --- | --- | --- |
| `while` | Before each iteration | Repeat while a state or condition holds |
| `do-while` | After each iteration | Perform an action at least once |
| `for` | Before each iteration, after initialization | Keep a counter, condition, and update together |

A `while` or `for` loop can run zero times. A `do-while` loop runs at least once
and requires a semicolon after its final condition. Make sure a loop's state
can progress toward termination.

### Early exits and nested control flow

`break` exits the nearest enclosing loop or switch. In nested loops, breaking
the inner loop leaves the outer loop running.

`continue` skips the rest of the current iteration of the nearest enclosing
loop. In a `for` loop, the update expression still runs before the condition
is checked again. In a `while` loop, skipping a counter update can prevent the
loop from terminating.

In `13_nested_control_flow.cpp`, each iteration validates its measurement
before updating velocity. With the supplied constants:

- steps `0` through `6` process measurements and increase velocity by `0.2`
  per step, reaching approximately `1.4`;
- steps `7` through `9` have measurements above `10.0`, so `continue` skips
  both the velocity update and the emergency-stop check; and
- the `1.5` velocity limit is never exceeded, so the emergency-stop branch
  does not run.

This is a useful tracing exercise: the presence of a branch does not mean the
current inputs will reach it. Lowering `maximumVelocity` to `1.0` makes the
example reach its emergency-stop path during the valid measurements.

## Build and run the examples

From this lesson directory, compile an individual example with warnings enabled:

```bash
mkdir -p build
g++ -std=c++20 -Wall -Wextra -Wpedantic \
    13_nested_control_flow.cpp -o build/13_nested_control_flow
./build/13_nested_control_flow
```

Replace the source and output names to run another lesson. Each `.cpp` file has
its own `main`, so build each as a separate executable.

The `do-while` example requests an integer command from `1` to `3`:

```bash
g++ -std=c++20 -Wall -Wextra -Wpedantic \
    10_do_while_loop.cpp -o build/10_do_while_loop
./build/10_do_while_loop
```

Its input loop checks the numeric range only. It does not recover from
nonnumeric input or end-of-file, which can leave the loop repeating without
progress. Use integer input for this example; stream-error handling is a
separate improvement to explore.

## Suggested exercises

1. Predict `17 / 5`, `17 % 5`, and `static_cast<double>(17) / 5`, then verify
   the results by running the arithmetic example.
2. Trace the values produced by prefix and postfix increment before executing
   the program.
3. Change the readiness flags and explain which logical operands are evaluated.
4. Try battery levels exactly at `20.0` and `50.0`, then explain the selected
   branches. Try an unrecognized flight mode to exercise `default`.
5. Rewrite a counted `while` loop as a `for` loop while preserving its output.
6. Trace which row/column pairs print when the inner loop uses `break`, then
   replace it with `continue` and compare the results.
7. Lower the nested simulation's velocity limit to exercise the emergency stop.
   Predict the stopping step and which messages will print before running it.
