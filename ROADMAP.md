# C++ & ROS 2 Engineering Roadmap

This roadmap starts from zero C++ assumptions and targets two connected outcomes:

1. Become a capable modern C++ developer who can read, write, debug, and structure non-trivial software.
2. Apply that foundation to ROS 2 robotics systems without treating framework syntax as magic.

The repository remains engineering-oriented, but the active track is now C++ → ROS 2. Existing Python/RF material is preserved as legacy study material and may later be integrated into robotics, signal-processing, and simulation projects.

---

## Learning philosophy

```text
Understand the concept
        ↓
Build a memory/runtime mental model
        ↓
Read unfamiliar code
        ↓
Predict behavior
        ↓
Write from scratch
        ↓
Debug broken code
        ↓
Refactor and explain trade-offs
        ↓
Use the same idea inside ROS 2
```

A lesson is complete only when the learner can explain the idea, use it independently, recognize typical bugs, and identify the same construct in real C++ or ROS 2 source code.

---

# Phase 0 — Development environment

## Goal

Establish a reproducible Linux C++ development workflow before adding framework complexity.

## Topics

- [ ] Confirm Linux distribution and version
- [ ] Install GCC or Clang
- [ ] Install GDB
- [ ] Install CMake
- [ ] Install Git
- [ ] Configure VS Code or preferred IDE
- [ ] Configure Jupyter-compatible C++ execution when practical
- [ ] Compile and run a basic `.cpp` program from the terminal
- [ ] Understand compiler warnings
- [ ] Understand the edit → compile → run → debug loop

## Completion criteria

- A C++ program can be compiled from the command line.
- Breakpoints and variable inspection work in a debugger.
- Notebook-style C++ cells can be used for early experiments if the selected environment supports them reliably.

---

# Phase 1 — C++ Foundations

## Goal

Learn the language from first principles while building correct execution and memory mental models.

## Module 1.1 — Program structure and fundamental types

- [ ] `main`
- [ ] statements and expressions
- [ ] comments
- [ ] `std::cout`
- [ ] integers
- [ ] floating-point types
- [ ] booleans
- [ ] characters
- [ ] `std::string`
- [ ] initialization styles
- [ ] `const`
- [ ] arithmetic, comparison, and logical operators
- [ ] basic type conversions

### Exercises

- velocity, distance, and time calculations
- battery threshold logic
- unit conversion
- numeric-output prediction

---

## Module 1.2 — Control flow

- [ ] `if` / `else`
- [ ] `switch`
- [ ] `for`
- [ ] `while`
- [ ] range-based `for`
- [ ] `break` and `continue`
- [ ] nested control flow

### Engineering applications

- battery-state decisions
- sensor-threshold checks
- actuator command limits
- simple state-machine logic

---

## Module 1.3 — Functions and scope

- [ ] function declaration and definition
- [ ] return types
- [ ] parameters and arguments
- [ ] `void`
- [ ] local variables
- [ ] scope
- [ ] pass by value
- [ ] pass by reference
- [ ] pass by const reference
- [ ] function overloading
- [ ] default arguments where appropriate

### Mastery examples

```cpp
double calculate_distance(double velocity, double time);

void update_position(double& position, double velocity, double dt);

void print_name(const std::string& name);
```

---

# Phase 2 — Memory, Lifetime, and Core C++

## Goal

Understand what C++ objects are, where they live, who owns them, and when they stop being valid.

## Module 2.1 — References and pointers

- [ ] addresses
- [ ] `&` address-of operator
- [ ] references
- [ ] pointer variables
- [ ] dereference operator `*`
- [ ] `nullptr`
- [ ] pointer versus reference semantics
- [ ] pointer-to-const versus const-pointer
- [ ] common pointer bugs

## Module 2.2 — Stack, heap, and lifetime

- [ ] automatic storage duration
- [ ] dynamic storage duration
- [ ] object lifetime
- [ ] dangling pointers/references
- [ ] why returning addresses of local variables is invalid
- [ ] introductory `new` / `delete` for understanding legacy code
- [ ] why RAII is preferred

## Module 2.3 — Arrays, strings, and vectors

- [ ] C-style arrays for language understanding
- [ ] `std::array`
- [ ] `std::string`
- [ ] `std::vector`
- [ ] indexing
- [ ] bounds awareness
- [ ] iteration
- [ ] references to container elements

---

# Phase 3 — Object-Oriented C++

## Goal

Design and reason about stateful components that will later map naturally to ROS 2 nodes and system components.

## Module 3.1 — Structures and classes

- [ ] `struct`
- [ ] `class`
- [ ] objects
- [ ] public/private/protected
- [ ] data members
- [ ] member functions
- [ ] constructors
- [ ] initializer lists
- [ ] `this`
- [ ] `const` member functions
- [ ] encapsulation
- [ ] composition

## Module 3.2 — Destruction and object semantics

- [ ] destructors
- [ ] object lifetime inside classes
- [ ] copy construction
- [ ] copy assignment
- [ ] move construction
- [ ] move assignment
- [ ] Rule of Zero
- [ ] Rule of Three/Five as explanatory models

## Module 3.3 — Inheritance and polymorphism

- [ ] base and derived classes
- [ ] virtual functions
- [ ] `override`
- [ ] pure virtual functions
- [ ] abstract interfaces
- [ ] virtual destructors
- [ ] composition versus inheritance

---

# Phase 4 — Modern C++ and STL

## Goal

Move from language syntax to idiomatic, maintainable C++.

## Module 4.1 — Standard library containers and algorithms

- [ ] `std::vector`
- [ ] `std::array`
- [ ] `std::map`
- [ ] `std::unordered_map`
- [ ] `std::set`
- [ ] iterators
- [ ] range-based loops
- [ ] `<algorithm>` fundamentals
- [ ] `std::find`
- [ ] `std::sort`
- [ ] `std::transform`
- [ ] `std::accumulate`

## Module 4.2 — Type deduction and expressive syntax

- [ ] `auto`
- [ ] `using`
- [ ] aliases
- [ ] scoped enums
- [ ] structured bindings
- [ ] namespaces

## Module 4.3 — RAII and smart pointers

- [ ] resource ownership
- [ ] RAII
- [ ] `std::unique_ptr`
- [ ] `std::make_unique`
- [ ] `std::shared_ptr`
- [ ] `std::make_shared`
- [ ] reference counting
- [ ] `std::weak_ptr`
- [ ] ownership trade-offs

## Module 4.4 — Lambdas and callbacks

- [ ] lambda syntax
- [ ] capture lists
- [ ] `[this]`
- [ ] capture by value/reference
- [ ] callable objects
- [ ] function pointers conceptually
- [ ] `std::function`
- [ ] callback design

## Module 4.5 — Templates

- [ ] function templates
- [ ] class templates conceptually
- [ ] template type parameters
- [ ] generic APIs
- [ ] reading nested template syntax

---

# Phase 5 — Professional C++ Development Workflow

## Goal

Build normal multi-file applications with the same tools and practices used by ROS 2 packages.

## Module 5.1 — Compilation model

- [ ] preprocessor
- [ ] headers
- [ ] declarations versus definitions
- [ ] translation units
- [ ] object files
- [ ] linker
- [ ] include guards / `#pragma once`
- [ ] common linker errors

## Module 5.2 — Project structure

```text
project/
├── CMakeLists.txt
├── include/
│   └── project/
│       └── robot.hpp
├── src/
│   ├── robot.cpp
│   └── main.cpp
└── tests/
```

## Module 5.3 — CMake

- [ ] `cmake_minimum_required`
- [ ] `project`
- [ ] `add_executable`
- [ ] `add_library`
- [ ] `target_include_directories`
- [ ] `target_link_libraries`
- [ ] target-based CMake
- [ ] out-of-source builds

## Module 5.4 — Debugging and correctness

- [ ] debugger workflow
- [ ] breakpoints
- [ ] stepping
- [ ] stack traces
- [ ] compiler warnings
- [ ] sanitizers
- [ ] assertions
- [ ] unit-test fundamentals
- [ ] undefined behavior awareness

---

# Phase 6 — ROS 2 Foundations

## Goal

Learn ROS 2 through already-understood C++ concepts.

## Module 6.1 — ROS 2 architecture

- [ ] ROS graph
- [ ] nodes
- [ ] topics
- [ ] messages
- [ ] services
- [ ] actions
- [ ] parameters
- [ ] discovery
- [ ] DDS overview

## Module 6.2 — Workspace and package workflow

- [ ] ROS 2 workspace layout
- [ ] package structure
- [ ] `colcon`
- [ ] environment sourcing
- [ ] `ament_cmake`
- [ ] dependencies
- [ ] `package.xml`
- [ ] ROS 2 CLI

## Module 6.3 — `rclcpp` nodes

- [ ] deriving from `rclcpp::Node`
- [ ] node constructors
- [ ] logging
- [ ] timers
- [ ] publishers
- [ ] subscribers
- [ ] callback signatures
- [ ] message shared pointers

### C++ mapping exercise

For code like:

```cpp
subscription_ = this->create_subscription<sensor_msgs::msg::LaserScan>(
    "/scan",
    10,
    [this](const sensor_msgs::msg::LaserScan::SharedPtr msg)
    {
        process_scan(*msg);
    });
```

be able to explain:

- [ ] member assignment
- [ ] `this`
- [ ] template argument
- [ ] nested namespaces
- [ ] lambda capture
- [ ] callback parameter
- [ ] shared ownership
- [ ] pointer dereference

## Module 6.4 — ROS 2 communication patterns

- [ ] publisher/subscriber design
- [ ] service/client
- [ ] actions
- [ ] timers
- [ ] parameters
- [ ] QoS fundamentals

---

# Phase 7 — ROS 2 Robot Modeling and Runtime

## Goal

Move beyond simple communication demos into robot-level system integration.

- [ ] TF2
- [ ] frames and transforms
- [ ] URDF
- [ ] Xacro
- [ ] RViz
- [ ] launch files
- [ ] rosbag
- [ ] sensor messages
- [ ] geometry messages
- [ ] odometry concepts
- [ ] lifecycle nodes
- [ ] executors
- [ ] callback groups
- [ ] threading fundamentals

---

# Phase 8 — Project-Based Engineering

## Goal

Use projects to broaden C++ and ROS 2 skill rather than collecting isolated tutorials.

Planned project families include:

### C++ projects

- [ ] command-line sensor statistics tool
- [ ] robot state model
- [ ] telemetry parser
- [ ] configurable control-loop simulator
- [ ] multithreaded producer/consumer exercise
- [ ] reusable library with tests and CMake

### ROS 2 projects

- [ ] velocity publisher/monitor
- [ ] robot safety controller
- [ ] multi-sensor processing pipeline
- [ ] service-based configuration node
- [ ] action-based mission controller
- [ ] TF/URDF robot model
- [ ] simulated differential-drive robot
- [ ] navigation-oriented integration project

---

# August 21–31, 2026 milestone

The immediate goal is not to claim complete mastery of professional C++ in eleven days. The goal is to create a strong foundation and reach the point where real C++ and introductory ROS 2 code can be read and written deliberately.

See [AUGUST_2026_BOOTCAMP.md](AUGUST_2026_BOOTCAMP.md) for the day-by-day schedule.

By the end of August, target capabilities are:

- [ ] write small C++ programs from scratch
- [ ] design and call functions correctly
- [ ] understand value/reference/pointer semantics
- [ ] reason about basic lifetime and ownership
- [ ] use strings, vectors, classes, and common STL patterns
- [ ] understand RAII and smart pointers
- [ ] read lambdas and basic templates
- [ ] organize a small `.hpp/.cpp` CMake project
- [ ] debug simple C++ failures
- [ ] create a ROS 2 C++ package
- [ ] write a node, publisher, subscriber, timer, and callback
- [ ] build a small multi-node ROS 2 exercise

---

# September 2026 direction

September will be updated as August progress becomes measurable. The provisional focus is:

- deeper STL and algorithms
- copy/move semantics and ownership design
- templates and generic programming
- robust CMake
- testing and sanitizers
- concurrency fundamentals
- ROS 2 services/actions/parameters/QoS
- TF2, URDF/Xacro, launch and RViz
- executors and callback groups
- simulation
- progressively larger C++ and ROS 2 projects

The September schedule should remain project-driven and should be revised from actual mastery results rather than fixed prematurely.
