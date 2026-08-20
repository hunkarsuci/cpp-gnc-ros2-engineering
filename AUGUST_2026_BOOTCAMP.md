# August 2026 C++ → ROS 2 Bootcamp

**Dates:** August 21–31, 2026  
**Duration:** 11 intensive days  
**Starting assumption:** zero reliable C++ knowledge  
**Learning objective:** establish a strong C++ foundation, become comfortable reading and writing non-trivial C++ syntax, and finish the month with first-principles ROS 2 C++ experience.

This is not a passive course-completion plan. Every day includes code reading, code writing, debugging, and a mastery check.

---

## Daily operating model

Each study day follows approximately this structure:

1. **Concept lesson** — build the mental model.
2. **Guided examples** — read and annotate working code.
3. **Notebook experiments** — modify small examples cell by cell.
4. **Code reading** — explain unfamiliar snippets line by line.
5. **Code writing** — implement from an empty cell/file.
6. **Bug hunt** — diagnose intentionally broken code.
7. **Engineering challenge** — solve a small robotics-flavored problem.
8. **Mastery check** — demonstrate understanding before moving on.
9. **ROS connection** — identify where the concept appears in ROS 2.

Recommended effort: several focused hours per day with breaks. Progress is measured by capability, not by time spent.

---

# Day 1 — C++ Program Fundamentals

## Topics

- [ ] What a C++ program is
- [ ] source code, compiler, executable
- [ ] `#include`
- [ ] `main`
- [ ] statements and expressions
- [ ] `std::cout`
- [ ] variables
- [ ] initialization
- [ ] `int`, `double`, `bool`, `char`
- [ ] `std::string`
- [ ] arithmetic and comparison operators
- [ ] basic `const`
- [ ] `if` / `else`
- [ ] `for` / `while`

## Notebook exercises

- distance = velocity × time
- Celsius/Kelvin conversion
- battery-state monitor
- obstacle-distance threshold
- simple loop-based sensor sampling

## Mastery check

Be able to write a small program from an empty cell/file using variables, conditions, loops, and output without copying an example.

---

# Day 2 — Functions, Scope, and Value Semantics

## Topics

- [ ] function declaration/definition
- [ ] return type
- [ ] parameters versus arguments
- [ ] `void`
- [ ] return values
- [ ] local variables
- [ ] block scope
- [ ] pass by value
- [ ] pass by reference
- [ ] pass by const reference
- [ ] introductory function overloading

## Core examples

```cpp
double calculate_distance(double velocity, double time);

void update_position(double& position, double velocity, double dt);

void print_robot_name(const std::string& name);
```

## Mastery check

Given a function call, explain which values are copied, which objects may be modified, and what disappears when the function returns.

---

# Day 3 — References, Pointers, and Memory Addresses

## Topics

- [ ] object identity
- [ ] memory address
- [ ] address-of operator `&`
- [ ] references
- [ ] pointer variables
- [ ] dereference operator `*`
- [ ] `nullptr`
- [ ] pointer versus reference
- [ ] `.` versus `->`
- [ ] modifying an object through a pointer
- [ ] common pointer mistakes

## Core mental model

```text
object
  ↓
has an address
  ↓
pointer may store that address
  ↓
dereference accesses the object
```

## Mastery check

For short programs containing values, references, and pointers, draw the object relationships and predict final values before execution.

---

# Day 4 — Lifetime, `const`, Strings, and Vectors

## Topics

- [ ] stack / automatic storage mental model
- [ ] dynamic storage concept
- [ ] object lifetime
- [ ] dangling pointer/reference
- [ ] why returning a pointer to a local variable is wrong
- [ ] `const T`
- [ ] `const T&`
- [ ] `const T*`
- [ ] `T* const`
- [ ] `std::string`
- [ ] `std::vector`
- [ ] indexing and iteration
- [ ] range-based loops
- [ ] `auto`

## Robotics-flavored challenge

Store sensor ranges in a vector and compute minimum, maximum, and average valid range while rejecting invalid values.

## Mastery check

Explain why `const std::vector<double>& values` is often preferable to passing a vector by value for read-only processing.

---

# Day 5 — Classes and Object Design

## Topics

- [ ] `struct` versus `class`
- [ ] object instances
- [ ] public/private
- [ ] data members
- [ ] member functions
- [ ] constructor
- [ ] initializer list
- [ ] `this`
- [ ] `const` member functions
- [ ] encapsulation
- [ ] composition

## Main exercise

Build a `Robot` class containing name, position, velocity, and update/status methods.

```cpp
class Robot
{
public:
    Robot(const std::string& name);
    void set_velocity(double velocity);
    void update(double dt);
    double position() const;

private:
    std::string name_;
    double position_{0.0};
    double velocity_{0.0};
};
```

## Mastery check

Create a class from an empty file and explain constructor execution, member access, and why internal state is private.

---

# Day 6 — Inheritance, Polymorphism, STL, and Lambdas

## Topics

- [ ] inheritance
- [ ] base/derived classes
- [ ] `virtual`
- [ ] `override`
- [ ] pure virtual functions
- [ ] abstract interfaces
- [ ] virtual destructors
- [ ] composition versus inheritance
- [ ] iterators conceptually
- [ ] common `<algorithm>` use
- [ ] lambda syntax
- [ ] capture lists
- [ ] `[this]`

## Main exercise

Create a `Sensor` interface and multiple sensor implementations, then process sensor data using standard library algorithms and lambdas.

## ROS connection

Understand why callbacks can be represented by functions, member functions, or lambdas.

---

# Day 7 — RAII, Smart Pointers, and Ownership

## Topics

- [ ] resource ownership
- [ ] RAII
- [ ] why raw `new`/`delete` should rarely appear in modern application code
- [ ] `std::unique_ptr`
- [ ] `std::make_unique`
- [ ] move-only ownership concept
- [ ] `std::shared_ptr`
- [ ] `std::make_shared`
- [ ] reference counting
- [ ] `std::weak_ptr`
- [ ] ownership cycles conceptually

## Main questions

For every dynamically managed object, answer:

```text
Who owns this object?
When will it be destroyed?
Can ownership be transferred?
Can multiple components share ownership?
Can a reference outlive the object?
```

## ROS connection

Read and explain constructs such as:

```cpp
auto node = std::make_shared<rclcpp::Node>("robot_node");
```

without treating them as memorized ROS syntax.

---

# Day 8 — Real C++ Project Workflow

Notebook-first learning ends here as the primary workflow.

## Topics

- [ ] declarations and definitions
- [ ] `.hpp` / `.cpp`
- [ ] include guards / `#pragma once`
- [ ] translation units
- [ ] compiler
- [ ] object files
- [ ] linker
- [ ] common compile/link errors
- [ ] project organization
- [ ] CMake fundamentals
- [ ] warnings
- [ ] GDB / IDE debugging
- [ ] introductory sanitizers

## Project structure

```text
03_cpp_projects/robot_core/
├── CMakeLists.txt
├── include/
│   └── robot_core/
│       └── robot.hpp
├── src/
│   ├── robot.cpp
│   └── main.cpp
└── tests/
```

## Mastery check

Build a multi-file C++ application with CMake, intentionally create one compile error and one linker error, diagnose both, then debug a runtime logic error.

---

# Day 9 — ROS 2 Foundations and First C++ Node

## Prerequisite

Confirm the installed Linux distribution before selecting the ROS 2 distribution and installation instructions.

## Topics

- [ ] ROS graph
- [ ] node
- [ ] topic
- [ ] message
- [ ] service
- [ ] action
- [ ] parameter
- [ ] DDS concept
- [ ] workspace layout
- [ ] package layout
- [ ] `colcon`
- [ ] sourcing
- [ ] `ament_cmake`
- [ ] `package.xml`
- [ ] ROS 2 CLI
- [ ] `rclcpp::Node`
- [ ] logging
- [ ] timers

## Main exercise

Create and build a C++ ROS 2 package containing a class-based node.

```cpp
class RobotNode : public rclcpp::Node
{
public:
    RobotNode()
        : Node("robot_node")
    {
    }
};
```

## C++ review

Explain inheritance, constructor chaining, access control, namespace usage, and object lifetime in the node implementation.

---

# Day 10 — Publishers, Subscribers, and Callbacks

## Topics

- [ ] publishers
- [ ] subscribers
- [ ] message types
- [ ] callback execution
- [ ] timers
- [ ] lambda callbacks
- [ ] member-function callbacks
- [ ] message `SharedPtr`
- [ ] QoS introduction
- [ ] parameters introduction
- [ ] service/client introduction

## Main system

```text
velocity_publisher
        │
        │ /velocity
        ▼
velocity_monitor
```

## Deep reading exercise

Explain every significant construct in:

```cpp
subscription_ = this->create_subscription<std_msgs::msg::Float64>(
    "/velocity",
    10,
    [this](const std_msgs::msg::Float64::SharedPtr msg)
    {
        velocity_ = msg->data;
    });
```

Including:

- `this`
- template argument syntax
- nested namespaces
- lambda capture
- callback parameter type
- shared pointer
- `->`
- member assignment

---

# Day 11 — C++ / ROS 2 Integration Project

## Project — Robot Safety Controller

```text
sensor_node
     │
     │ /distance
     ▼
safety_controller
     │
     │ /cmd_vel
     ▼
robot_node
```

Behavior:

```text
safe distance       → allow commanded velocity
unsafe distance     → command stop
invalid sensor data → enter safe state
```

## Required C++ concepts

- [ ] classes
- [ ] constructors
- [ ] private state
- [ ] functions
- [ ] references / const correctness
- [ ] smart pointers
- [ ] callbacks
- [ ] lambdas or member callbacks
- [ ] STL where appropriate
- [ ] CMake

## Required ROS 2 concepts

- [ ] package
- [ ] nodes
- [ ] publishers
- [ ] subscribers
- [ ] messages
- [ ] timers if useful
- [ ] logging
- [ ] CLI inspection
- [ ] basic QoS reasoning

## Final review

The project should be explainable line by line. Any framework construct that cannot be explained becomes a follow-up C++ or ROS lesson rather than something to memorize.

---

# End-of-August capability gate

Before moving into the September project phase, verify the following without notes where practical.

## C++

- [ ] Write functions and choose value/reference/const-reference intentionally.
- [ ] Read pointer and reference syntax without confusion.
- [ ] Explain stack-style lifetime and common dangling-reference bugs.
- [ ] Use `std::string` and `std::vector` comfortably.
- [ ] Write a basic class with constructor and private state.
- [ ] Understand inheritance and virtual dispatch at an introductory level.
- [ ] Explain RAII and choose between unique/shared ownership in simple cases.
- [ ] Read basic lambdas and templates.
- [ ] Build a `.hpp/.cpp` project with CMake.
- [ ] Use a debugger for simple failures.

## ROS 2

- [ ] Explain node/topic/message architecture.
- [ ] Create a C++ package.
- [ ] Build with `colcon`.
- [ ] Write a class-based node.
- [ ] Create publishers and subscribers.
- [ ] Read callback code as normal C++.
- [ ] Inspect a running system with ROS 2 CLI tools.
- [ ] Build and explain a small multi-node project.

---

# September preview

September is intentionally not fully scheduled yet. It will be revised from actual August mastery results.

Expected directions:

- modern STL and algorithms
- deeper copy/move semantics
- templates and generic programming
- robust CMake and libraries
- testing, sanitizers, static analysis
- concurrency
- ROS 2 services and actions
- parameters and QoS
- TF2
- URDF/Xacro
- launch
- RViz
- executors and callback groups
- simulation
- progressively larger robotics projects

The September objective is breadth through projects while continuing to deepen C++ fundamentals whenever a project exposes a gap.
