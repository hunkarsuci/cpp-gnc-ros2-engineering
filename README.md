# Modern C++ for GNC, Robotics & ROS 2

A structured, project-driven curriculum for learning modern C++ and applying it
to guidance, navigation and control (GNC), robotics, simulation, and ROS 2
software.

The curriculum begins with the C++ compilation and memory model, progresses
through professional engineering practices, and finishes with production-style
GNC and autonomous-system projects.

## Objectives

By completing this repository, the learner should be able to:

- read, write, debug, and test modern C++20;
- reason about object lifetime, ownership, copy/move behavior, and performance;
- build reusable libraries with CMake;
- use Eigen for numerical and GNC software;
- implement simulation, control, estimation, and guidance components;
- design deterministic, testable engineering software;
- build ROS 2 systems using C++ and `rclcpp`;
- validate C++ algorithms against Python reference implementations; and
- deliver a documented production-style GNC or robotics capstone.

## Curriculum structure

```text
curriculum/
├── 01_cpp_language/       # Topics 01–18: language and modern C++ foundations
├── 02_cpp_engineering/    # Topics 19–23: build, debugging, testing, quality
├── 03_gnc_cpp/            # Topics 24–31: numerical methods and GNC algorithms
├── 04_advanced_systems/   # Topics 32–38: architecture, performance, real time
├── 05_ros2_gnc/           # Topics 39–46: ROS 2 and GNC system integration
└── 06_portfolio/          # Topics 47–50: progressively larger portfolio work
```

The complete sequence and completion criteria are listed in
[ROADMAP.md](ROADMAP.md).

## How each topic will be developed

Every topic begins with an empty `README.md). Content is added lecture by
lecture, and supporting directories are created only when needed:

```text
topic_name/
├── README.md       # concepts, mental models, and notes
├── examples/       # small working demonstrations
├── exercises/      # learner implementations
├── bug_hunts/      # intentionally broken programs
├── include/        # public headers when the topic needs a library
├── src/            # source files
├── tests/          # automated tests
└── CMakeLists.txt  # build definition when compilation is required
```

Not every topic needs every directory. Early subjects may contain only a README
and a few source files; engineering and portfolio topics will use full
project layouts.

## Learning method

Each topic follows the same progression:

1. Build the conceptual and runtime mental model.
2. Read and explain working code.
3. Predict program behavior before execution.
4. Implement examples from an empty file.
5. Diagnose compiler, linker, runtime, and logic failures.
6. Test and refactor the implementation.
7. Apply the concept to an engineering or GNC problem.
8. Identify how the concept appears in ROS 2 or production software.

A topic is complete when its concepts can be explained and applied without
copying an existing solution.

## Toolchain

The target language is C++20. The primary toolchain consists of:

- GCC or Clang;
- CMake and CTest;
- GDB or LLDB;
- GoogleTest;
- Eigen;
- compiler warnings and sanitizers;
- clang-format and clang-tidy;
- Python for reference models, validation, visualization, and Monte Carlo work;
- ROS 2 with `ament_cmake`, `colcon`, and `rclcpp`.

See [REQUIREMENTS.md](REQUIREMENTS.md) for environment requirements.
`requirements.txt` contains only optional Python analysis dependencies.

## Repository policy

- Source code, tests, and documentation evolve one curriculum topic at a time.
- Build products and generated results are not committed.
- C++ examples should compile with warnings enabled.
- Numerical algorithms require automated tests and stated tolerances.
- Portfolio code should separate interfaces, implementations, configuration,
  and verification.
- Python prototypes and C++ implementations should use shared test vectors when
  numerical equivalence matters.

## Status

The curriculum skeleton is complete. Lecture content has intentionally not been
pre-filled; each topic will be developed and reviewed in sequence.

## License

This repository is licensed under the MIT License. See [LICENSE](LICENSE).
