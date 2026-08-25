# Modern C++ for GNC, Robotics & ROS 2 Roadmap

This roadmap contains the complete 50-topic progression. Topic numbers are
stable: supporting material may grow, but the curriculum order remains
traceable.

## Track 1 — C++ Language and Modern C++

Goal: understand the language, compilation model, memory behavior, ownership,
and the standard-library tools needed to write deliberate modern C++.

- [ ] **01 — C++ Program Structure & Compilation [CORE]**  
  Source files, headers, `main()`, compiler and linker roles, warnings,
  terminal compilation, executables, and compile-time versus run-time behavior.

- [ ] **02 — Types, Variables & Memory Model [CORE]**  
  Fundamental types, signed and unsigned values, integer and floating-point
  behavior, `bool`, `char`, `const`, initialization, conversions,
  narrowing, scope, lifetime, and an introduction to stack and heap storage.

- [ ] **03 — Operators & Control Flow [CORE]**  
  Arithmetic, comparison and logical operators, `if`, `switch`, loops,
  `break`, `continue`, range-for, and maintainable control-flow design.

- [ ] **04 — Functions [CORE]**  
  Declarations, definitions, parameters, returns, value/reference semantics,
  const references, overloading, default arguments, inline functions, and API
  design.

- [ ] **05 — References & Pointers [CRITICAL]**  
  References, addresses, pointers, dereferencing, `nullptr`, limited pointer
  arithmetic, const forms, lifetime hazards, and dangling pointers/references.

- [ ] **06 — Arrays, Strings & Containers [CORE]**  
  Raw arrays, `std::array`, `std::vector`, `std::string`, indexing,
  bounds, iteration, contiguous storage, resizing, and container selection.

- [ ] **07 — Structs, Enums & Engineering Data Models [CORE]**  
  Structures, `enum`, `enum class`, nested data, state representation,
  sensor records, and configuration models.

- [ ] **08 — Classes & Object-Oriented C++ [CORE]**  
  Classes, access control, constructors, destructors, member functions, const
  members, encapsulation, composition, selective inheritance, polymorphism,
  and virtual functions.

- [ ] **09 — RAII & Resource Management [CRITICAL]**  
  Resource lifetime, ownership, constructors/destructors, deterministic
  cleanup, and the role of RAII in reliable C++.

- [ ] **10 — Smart Pointers [CORE]**  
  `std::unique_ptr`, `std::shared_ptr`, `std::weak_ptr`, ownership
  semantics, avoiding cycles, and recognizing when no dynamic allocation is
  needed.

- [ ] **11 — Copy & Move Semantics [CRITICAL]**  
  Copy/move construction and assignment, lvalues, rvalues, `std::move`,
  object lifetime, Rule of Zero, and Rule of Five.

- [ ] **12 — STL Containers [CORE]**  
  Vector, array, deque, limited list usage, ordered and unordered maps/sets,
  complexity, invalidation, and selecting containers from requirements.

- [ ] **13 — Iterators & STL Algorithms [CORE]**  
  Iterator models, begin/end, find, sort, transform, accumulate, predicates,
  and algorithm-oriented problem solving.

- [ ] **14 — Lambdas & Functional-Style C++ [MODERN C++]**  
  Lambda syntax, captures, predicates, callbacks, algorithm integration,
  and function objects.

- [ ] **15 — Modern C++ Language Features [CORE]**  
  `auto`, `constexpr`, structured bindings, `std::optional`,
  `std::variant`, tuples, spans, modern initialization, and avoiding
  unnecessary legacy patterns.

- [ ] **16 — Templates & Generic Programming [CORE → ADVANCED]**  
  Function and class templates, type parameters, compile-time polymorphism,
  specialization intuition, introductory concepts, and generic numerical code.

- [ ] **17 — Error Handling & Robust Code [ENGINEERING]**  
  Exceptions, standard/custom exceptions, error codes, assertions, validation,
  defensive programming, and environments where exceptions are inappropriate.

- [ ] **18 — File I/O & Configuration [ENGINEERING]**  
  Streams, text, CSV, introductory binary I/O, paths, configuration,
  serialization concepts, and telemetry/results handling.

### Track 1 capability gate

- Build and explain multi-file C++20 programs.
- Reason correctly about values, references, pointers, ownership, and lifetime.
- Select standard containers and algorithms intentionally.
- Design small classes and APIs with const correctness.
- Diagnose common compile, link, runtime, and undefined-behavior failures.

## Track 2 — Professional C++ Engineering

Goal: turn language knowledge into reproducible, testable, maintainable
software.

- [ ] **19 — CMake & Build Systems [CRITICAL]**  
  Targets, libraries, executables, include paths, linking, dependencies,
  configurations, multi-directory projects, and reusable libraries.

- [ ] **20 — Project Structure [ENGINEERING]**  
  Header/source separation, namespaces, interfaces, dependency direction,
  modularity, and conventional include/src/tests/config/examples layouts.

- [ ] **21 — Debugging [CORE]**  
  Compiler, linker, runtime and logic errors; segmentation faults; breakpoints;
  stack traces; variable inspection; and GDB/IDE workflows.

- [ ] **22 — Testing in C++ [CORE]**  
  GoogleTest, unit and integration tests, fixtures, parameterized cases,
  numerical tolerances, regression testing, and GNC verification fundamentals.

- [ ] **23 — Static Analysis & Code Quality [PROFESSIONAL]**  
  Strict warnings, AddressSanitizer, UndefinedBehaviorSanitizer, clang-tidy,
  formatting, review, and modern C++ quality practices.

### Track 2 capability gate

- Create a reusable target-based CMake project.
- Build and run tests from a clean checkout.
- Debug failures with a debugger and sanitizers.
- Apply formatting, static analysis, and warning policies consistently.

## Track 3 — GNC and Numerical C++

Goal: implement numerically sound, reusable GNC and simulation components.

- [ ] **24 — Eigen Library [GNC CORE]**  
  Fixed/dynamic vectors and matrices, arithmetic, decompositions, linear
  systems, norms, transforms, blocks, alignment, and performance basics.

- [ ] **25 — Numerical Computing in C++ [GNC CORE]**  
  Floating-point behavior, tolerances, integration, finite differences,
  stability, numerical linear algebra, and solver architecture.

- [ ] **26 — Coordinate Frames & Rotations in C++ [GNC CORE]**  
  Vectors, DCMs, Euler angles, rotation matrices, quaternions, Eigen quaternion
  tools, body/inertial/navigation frames, and frame-safe APIs.

- [ ] **27 — Dynamics Models in C++ [GNC CORE]**  
  State vectors, derivatives, translational and rotational dynamics,
  forces/moments, actuator models, disturbances, and six-DOF models.

- [ ] **28 — Simulation Engine Architecture [GNC CORE]**  
  Fixed-step propagation, model interfaces, simulation clocks, multi-rate
  scheduling, history logging, and deterministic execution.

- [ ] **29 — Control Algorithms in C++ [GNC CORE]**  
  PID, state feedback, LQR, observers, discrete control, saturation,
  anti-windup, controller classes, and reusable control interfaces.

- [ ] **30 — Estimation Algorithms in C++ [GNC CORE]**  
  Complementary filters, KF/EKF, covariance, propagation, measurement updates,
  numerical stability, and sensor fusion.

- [ ] **31 — Advanced GNC Algorithms in C++ [ADVANCED]**  
  LQR/LQG, robust and adaptive methods, nonlinear control, trajectory
  generation, optimization-based control, and MPC architecture.

### Track 3 capability gate

- Implement and test numerical algorithms with explicit tolerances.
- Represent frames and rotations without hidden convention changes.
- Build deterministic simulation, controller, and estimator interfaces.
- Validate C++ output against trusted reference data.

## Track 4 — Advanced and Flight-Oriented Systems

Goal: understand the architecture, performance, concurrency, determinism, and
assurance concerns of production engineering software.

- [ ] **32 — Interfaces & Abstract Architecture [PROFESSIONAL]**  
  Abstract interfaces, interchangeable controller/estimator implementations,
  dependency boundaries, and testable component design.

- [ ] **33 — Design Patterns for Engineering Software [SELECTIVE]**  
  Strategy, Factory, Observer, dependency injection, interfaces, and
  composition over inheritance—used only when they solve a concrete problem.

- [ ] **34 — Memory Layout & Performance [ADVANCED C++]**  
  Storage, cache behavior, contiguous memory, allocation, copies/moves, cache
  locality, data-oriented design, benchmarking, and profiling.

- [ ] **35 — Multithreading & Concurrency [ADVANCED]**  
  Threads, mutexes, locks, atomics, races, deadlocks, condition variables,
  producer/consumer systems, and thread safety.

- [ ] **36 — Real-Time Software Concepts [FLIGHT/ROBOTICS]**  
  Hard/soft real time, deadlines, latency, jitter, scheduling, allocation and
  blocking concerns, deterministic execution, and worst-case-time intuition.

- [ ] **37 — Embedded-Oriented C++ Concepts [AEROSPACE]**  
  Resource constraints, fixed-size storage, allocation avoidance,
  deterministic memory, low-level interfaces, hardware boundaries, and
  embedded design principles.

- [ ] **38 — Safety-Critical C++ Awareness [AEROSPACE]**  
  Undefined behavior, determinism, defensive coding, MISRA/AUTOSAR awareness,
  certification mindset, traceability, and verification concepts.

### Track 4 capability gate

- Define interchangeable components through narrow interfaces.
- Measure performance instead of guessing.
- identify concurrency and real-time hazards.
- Explain how assurance constraints change ordinary C++ design choices.

## Track 5 — ROS 2 and GNC Integration

Goal: deploy already-understood C++ and GNC components as robust ROS 2 systems.

- [ ] **39 — ROS 2 Fundamentals with C++ [CRITICAL ROBOTICS]**  
  Packages, `ament_cmake`, nodes, publishers, subscribers, services, actions,
  parameters, launch, and custom interfaces.

- [ ] **40 — rclcpp [ROS 2 CORE]**  
  Node classes, communication, callbacks, timers, executors, callback groups,
  QoS, parameters, and lifecycle nodes when appropriate.

- [ ] **41 — ROS 2 tf2 with C++ [ROS/GNC]**  
  Transform trees, quaternion/frame handling, timestamps, sensor-frame
  conversion, and body/world/navigation integration.

- [ ] **42 — ROS 2 Sensor & Estimation Nodes [ROS/GNC]**  
  IMU/GNSS interfaces, KF/EKF nodes, timestamps, multi-rate processing, and
  QoS-aware estimator pipelines.

- [ ] **43 — ROS 2 Control & Guidance Nodes [ROS/GNC]**  
  Controller nodes, trajectory tracking, waypoint guidance, state feedback,
  command generation, and actuator interfaces.

- [ ] **44 — ROS 2 Component Architecture [ADVANCED ROS]**  
  Composition, executors, intra-process communication, lifecycle, performance,
  component boundaries, and production architecture.

- [ ] **45 — Python ↔ C++ Interoperability [VERY USEFUL]**  
  Python prototypes, production C++, numerical equivalence, shared data,
  mixed-language ROS nodes, and optional pybind11.

- [ ] **46 — GNC Software Verification [PROFESSIONAL]**  
  Truth data, Monte Carlo testing, numerical regression, performance and
  boundary tests, fault cases, and Python-reference/C++ comparison.

### Track 5 capability gate

- Build and inspect a multi-package ROS 2 C++ workspace.
- Select communication patterns and QoS from system requirements.
- Handle transforms, timestamps, rates, and lifecycle explicitly.
- Verify ROS-wrapped algorithms independently of ROS communication code.

## Track 6 — Portfolio Projects

Goal: integrate the curriculum into documented systems that demonstrate
engineering depth rather than isolated tutorial completion.

- [ ] **47 — C++ GNC Library Project [PORTFOLIO]**  
  A reusable Eigen/CMake/GoogleTest library containing math, frames, dynamics,
  control, estimation, guidance, sensors, and simulation modules.

- [ ] **48 — High-Performance Six-DOF Simulator [PORTFOLIO]**  
  C++ dynamics, actuators, sensors, noise, control, estimation, logging,
  automated tests, profiling, and Python visualization.

- [ ] **49 — ROS 2 Autonomous Vehicle Architecture [PORTFOLIO]**  
  Simulation → sensors → estimation → navigation → guidance → control →
  actuators, with explicit node and component boundaries.

- [ ] **50 — Production-Style GNC / Flight Software Capstone [FINAL]**  
  Modern C++, Eigen, CMake, testing, ROS 2, real-time awareness, estimation,
  control, guidance, sensor simulation, Monte Carlo analysis, profiling,
  requirements, traceability, and complete documentation.

## Final completion standard

The roadmap is complete only when the learner can:

- explain major design and ownership decisions;
- reproduce clean builds and tests on a fresh environment;
- trace requirements into implementations and verification evidence;
- compare Python reference algorithms with production C++ results;
- diagnose numerical, memory, concurrency, and ROS integration failures;
- justify performance and real-time decisions with measurements; and
- present the final system as a coherent engineering portfolio.
