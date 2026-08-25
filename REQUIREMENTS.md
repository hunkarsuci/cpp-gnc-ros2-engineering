# Development Requirements

This repository combines C++, numerical computing, Python analysis, and ROS 2.
They use different dependency systems and should not all be placed in a Python
`requirements.txt` file.

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

## Recommended build policy

- Use out-of-source builds.
- Configure C++20 per CMake target.
- Enable strict warnings during development.
- Run tests through CTest or `colcon test`.
- Use Debug or sanitizer builds while learning and diagnosing code.
- Use Release builds only when measuring representative performance.
