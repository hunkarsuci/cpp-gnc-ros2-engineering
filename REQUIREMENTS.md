# Development Requirements

This repository combines C++, numerical computing, Python analysis, and ROS 2.
They use different dependency systems and should not all be placed in a Python
`requirements.txt` file.

Requirements are introduced progressively. You only need the dependencies for
the curriculum track you are currently studying; each later track builds on the
earlier ones.

## Requirements by curriculum area

| Curriculum path | Topics | Required tools and libraries | Typical files |
| --- | ---: | --- | --- |
| [`curriculum/01_cpp_language`](curriculum/01_cpp_language/) | 01–18 | C++20 compiler and standard library | `README.md`, `.cpp`, `.hpp` |
| [`curriculum/02_cpp_engineering`](curriculum/02_cpp_engineering/) | 19–23 | CMake, CTest, Ninja or Make, debugger, GoogleTest, formatting, static analysis, sanitizers | `CMakeLists.txt`, `include/`, `src/`, `tests/` |
| [`curriculum/03_gnc_cpp`](curriculum/03_gnc_cpp/) | 24–31 | Previous tools, Eigen, and Python analysis environment | C++ libraries and tests, Python validation scripts, result data |
| [`curriculum/04_advanced_systems`](curriculum/04_advanced_systems/) | 32–38 | Previous tools, threading support, profiling and benchmarking tools as introduced | Interfaces, implementations, tests, benchmarks |
| [`curriculum/05_ros2_gnc`](curriculum/05_ros2_gnc/) | 39–46 | Compatible ROS 2 distribution, `ament_cmake`, `colcon`, `rosdep`, `rclcpp`, message packages, and TF2 | `package.xml`, `CMakeLists.txt`, `src/`, `include/`, `launch/`, `config/`, `test/` |
| [`curriculum/06_portfolio`](curriculum/06_portfolio/) | 47–50 | All dependencies used by the selected project | Complete CMake or ROS 2 projects, tests, configuration, documentation, and validation assets |

The topic sequence and capability gates are defined in
[`ROADMAP.md`](ROADMAP.md). A topic's own `README.md` should document any
additional dependency, version constraint, data file, or run command that is
specific to that topic.

### Current repository state

The implemented examples in topics 01 and 02 are standalone C++20 source
files. They require only a C++20 compiler and the standard library and can be
compiled directly from their topic directories. The later curriculum folders
currently contain topic `README.md` placeholders; install their specialized
dependencies when implementation reaches those topics.

## Base environment

- A supported 64-bit Linux distribution
- Git
- A terminal and a C++-capable editor or IDE
- At least 10 GB of free space before installing ROS 2 and simulation tools

ROS 2 installation instructions must match the installed Linux distribution.
Do not install a ROS 2 distribution until that compatibility has been checked.

## Core C++ toolchain

- GCC 11+ or Clang 14+
- C++20 standard-library support
- CMake 3.22+
- Ninja or Make
- GDB or LLDB
- pkg-config

Typical Debian/Ubuntu packages:

```bash
sudo apt install build-essential cmake ninja-build gdb git pkg-config
```

For the current standalone examples, a typical command is:

```bash
g++ -std=c++20 -Wall -Wextra -Wpedantic example.cpp -o example
./example
```

Build executables and generated files outside the source tree when a topic
provides CMake. For direct, single-file exercises, use a local `build/`
directory and do not commit the generated executable.

## Code quality and diagnostics

- clang-format
- clang-tidy
- AddressSanitizer
- UndefinedBehaviorSanitizer
- gcov/lcov when coverage reporting is introduced

Typical Debian/Ubuntu packages:

```bash
sudo apt install clang clang-format clang-tidy lcov
```

The sanitizers are normally provided by the selected GCC or Clang toolchain.
These tools become explicit curriculum requirements in
[`curriculum/02_cpp_engineering`](curriculum/02_cpp_engineering/), but warnings
should be enabled for the earlier standalone examples as well.

## C++ libraries

- Eigen 3.4+
- GoogleTest

Typical Debian/Ubuntu packages:

```bash
sudo apt install libeigen3-dev libgtest-dev
```

Additional libraries will be introduced only when a curriculum topic requires
them. Every added dependency must be documented by the topic or project using
it.

Eigen first becomes a curriculum requirement in topic 24 under
[`curriculum/03_gnc_cpp`](curriculum/03_gnc_cpp/). GoogleTest becomes a formal
requirement in topic 22 under
[`curriculum/02_cpp_engineering`](curriculum/02_cpp_engineering/), although a
topic may introduce tests earlier if its README documents the dependency.

## Python analysis environment

Python is used for:

- reference implementations;
- plotting and result analysis;
- numerical cross-validation;
- test-vector generation;
- Monte Carlo studies; and
- optional Jupyter notebooks.

Create an isolated environment and install the Python dependencies:

```bash
python3 -m venv .venv
source .venv/bin/activate
python -m pip install --upgrade pip
python -m pip install -r requirements.txt
```

Python is not the build system for the C++ curriculum.

The root [`requirements.txt`](requirements.txt) is reserved for Python packages
used by numerical prototypes, plotting, validation, test-vector generation,
Monte Carlo studies, and notebooks. System packages, C++ libraries, and ROS 2
packages must not be added to it.

## ROS 2 environment

The ROS 2 phase requires:

- a ROS 2 distribution compatible with the host operating system;
- `ros-dev-tools`;
- `colcon`;
- `rosdep`;
- `ament_cmake`;
- `rclcpp`;
- common message packages;
- TF2; and
- optional visualization and simulation packages when their topics begin.

The exact package commands will be added after recording the host Linux version
and selecting the ROS 2 distribution. ROS dependencies should be declared in
each package's `package.xml` and resolved with `rosdep`.

ROS 2 is required only for
[`curriculum/05_ros2_gnc`](curriculum/05_ros2_gnc/) and ROS-based portfolio
projects. The language, engineering, numerical, and advanced-systems tracks
must remain usable without sourcing a ROS 2 installation unless a topic
explicitly states otherwise.

## Curriculum file and directory requirements

Curriculum content should use only the files and directories needed by the
topic. The expected roles are:

- `README.md` — concepts, prerequisites, build/run instructions, exercises,
  and completion criteria;
- `.cpp` — executable examples or implementation translation units;
- `.hpp` — declarations and reusable public interfaces;
- `CMakeLists.txt` — target-based build definitions once a topic moves beyond
  direct compilation;
- `include/` and `src/` — public interfaces and implementations for reusable
  libraries or larger projects;
- `tests/` or `test/` — automated unit, integration, numerical, or ROS tests;
- `examples/` — focused demonstrations of an API or concept;
- `exercises/` — learner-owned implementations;
- `bug_hunts/` — intentionally faulty programs used for diagnosis;
- `config/` — runtime configuration that is version-controlled;
- `launch/` — ROS 2 launch descriptions;
- `package.xml` — ROS 2 package metadata and dependency declarations; and
- Python files or notebooks — reference models, analysis, visualization, or
  validation rather than replacement C++ implementations.

Not every topic needs every directory. Early language topics may consist of a
README and standalone source files, while engineering, GNC, ROS 2, and
portfolio topics should adopt reproducible builds and automated tests as their
scope grows.

Generated executables, object files, CMake build trees, coverage reports,
plots, and simulation output must not be committed unless a topic explicitly
identifies a small artifact as required reference or verification data.

## Recommended build policy

- Use out-of-source builds.
- Configure C++20 per CMake target.
- Enable strict warnings during development.
- Run tests through CTest or `colcon test`.
- Use Debug or sanitizer builds while learning and diagnosing code.
- Use Release builds only when measuring representative performance.
- Keep dependencies attributable to the curriculum topic or project that uses
  them.
- Record any new dependency in the topic README and in this file when it
  applies across a curriculum track.
