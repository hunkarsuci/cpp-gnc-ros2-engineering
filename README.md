# RF Space Systems Lab — C++ & ROS 2 Engineering Track

A hands-on engineering laboratory for becoming a strong C++ developer first, then applying that foundation to ROS 2 robotics and autonomous systems.

The repository is intentionally learning-driven: concepts are explained, implemented, debugged, tested, and then reused in progressively larger projects.

> **Core principle:** learn the language deeply enough to read unfamiliar code, write correct code from scratch, reason about memory and ownership, debug failures, and design maintainable systems before relying on ROS 2 abstractions.

## Current focus

**August 21–31, 2026:** intensive C++ → ROS 2 foundation bootcamp.

**September 2026:** project-driven expansion across modern C++, ROS 2, robotics tooling, simulation, testing, and system integration.

The detailed August schedule is in [AUGUST_2026_BOOTCAMP.md](AUGUST_2026_BOOTCAMP.md). The long-term progression is in [ROADMAP.md](ROADMAP.md).

## Learning model

Every topic follows the same loop:

```text
Concept
  ↓
Mental model
  ↓
Read code
  ↓
Predict behavior
  ↓
Write code
  ↓
Debug broken code
  ↓
Refactor
  ↓
Mini challenge
  ↓
ROS 2 connection
```

A topic is not considered complete merely because it has been read or watched. Completion means being able to explain it, use it without copying, identify common bugs, and recognize it inside real C++/ROS 2 code.

## Repository structure

```text
rf-space-systems-lab/
├── README.md
├── ROADMAP.md
├── AUGUST_2026_BOOTCAMP.md
├── .gitignore
│
├── 00_engineering_python/        # preserved legacy engineering notebooks
├── 01_cpp_foundations/           # notebook-first C++ fundamentals
├── 02_modern_cpp/                # ownership, STL, RAII, lambdas, templates
├── 03_cpp_projects/              # real .cpp/.hpp/CMake projects
├── 04_ros2_foundations/          # ROS 2 concepts and C++ packages
└── 05_ros2_projects/             # integrated robotics projects
```

Directories are populated only when work begins. Learning notebooks remain executable and concise; reusable code moves into normal C++ projects when the topic requires real compilation and build-system practice.

## Phase overview

### Phase 1 — C++ Foundations

Start from zero and build correct mental models for:

- program structure and compilation
- variables and fundamental types
- operators and expressions
- control flow
- functions and scope
- references and pointers
- stack, heap, lifetime, and `const`
- arrays, strings, and `std::vector`

Primary format: Jupyter-style C++ notebooks when practical.

### Phase 2 — Modern C++

Develop production-oriented language skills:

- classes, constructors, destructors, and composition
- inheritance and polymorphism
- STL containers and algorithms
- iterators, `auto`, range-for
- RAII and ownership
- `std::unique_ptr`, `std::shared_ptr`, `std::weak_ptr`
- copy/move semantics
- lambdas and callbacks
- templates and generic programming fundamentals
- exceptions and defensive programming

### Phase 3 — C++ Developer Workflow

Move from notebook experiments to real projects:

- `.hpp` / `.cpp` separation
- translation units
- compiler and linker behavior
- CMake
- GDB / IDE debugging
- unit testing
- warnings, sanitizers, and static analysis
- project organization and API design

### Phase 4 — ROS 2 Foundations

Apply C++ knowledge directly to ROS 2:

- workspaces and packages
- `rclcpp::Node`
- publishers and subscribers
- callbacks and timers
- messages
- services and clients
- actions
- parameters
- QoS
- launch systems
- TF2
- URDF / Xacro
- RViz and simulation tooling

### Phase 5 — ROS 2 Engineering Projects

Build multi-node systems that require architecture, debugging, and integration rather than isolated tutorials.

Examples:

- sensor processing pipeline
- robot safety controller
- differential-drive control stack
- TF/URDF robot model
- service/action based mission controller
- simulated autonomous robot application

## Notebook-first, project-second

Notebook-style execution is useful while learning expressions, functions, references, pointers, STL, and small classes because individual experiments can be run cell by cell.

However, real C++ and ROS 2 development cannot remain notebook-only. The transition is intentional:

```text
.ipynb experiments
      ↓
.cpp programs
      ↓
.hpp + .cpp modules
      ↓
CMake projects
      ↓
ROS 2 packages and workspaces
```

## Mastery standard

For each major subject, practice should include:

1. Concept explanation
2. Code reading
3. Output prediction
4. Writing code from an empty file
5. Bug finding
6. Refactoring
7. Small engineering task
8. Review of how the same concept appears in ROS 2

Example progression:

```cpp
void update_position(double& position, double velocity, double dt);
```

leads naturally to understanding code such as:

```cpp
subscription_ = this->create_subscription<sensor_msgs::msg::LaserScan>(
    "/scan",
    10,
    [this](const sensor_msgs::msg::LaserScan::SharedPtr msg)
    {
        process_scan(*msg);
    });
```

The goal is to understand every important C++ construct in that ROS 2 code rather than treating it as framework-specific syntax to memorize.

## Development environment

Target environment:

- Linux
- GCC / Clang
- CMake
- Git
- VS Code or another C++ IDE
- Jupyter-compatible C++ kernel when useful
- ROS 2 distribution compatible with the installed Linux distribution

Exact ROS 2 installation instructions will be selected after confirming the Linux distribution and version.

## Git workflow

Use small, descriptive commits tied to a learning milestone or project capability.

Examples:

```text
Add C++ function and scope exercises
Add pointer and reference notebook
Implement RAII ownership examples
Create first CMake C++ project
Add ROS 2 publisher subscriber exercise
Implement robot safety controller
```

## Legacy engineering material

The existing `00_engineering_python/` material is preserved as earlier engineering-study work. It is not part of the active August C++/ROS 2 track, but may later be reused for RF, DSP, simulation, or robotics data-analysis projects.

## License

MIT License. See [LICENSE](LICENSE).
