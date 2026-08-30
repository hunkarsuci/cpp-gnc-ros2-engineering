# Program Structure and Compilation

This lesson introduces the structure of a small C++ program and follows it
from source code to a running executable. It also distinguishes compiler,
linker, runtime, and warning diagnostics.

## Learning objectives

After completing this lesson, you should be able to:

- identify the preprocessor, function, statement, and return-value parts of a
  basic C++ program;
- describe the preprocessing, compilation, linking, and execution stages;
- compile one or more source files with warnings enabled;
- separate declarations into headers and definitions into source files; and
- recognize compiler errors, linker errors, runtime errors, and warnings.

## The build pipeline

```text
source files (.cpp) + headers (.hpp)
              |
              v
        preprocessing
              |
              v
          compilation
              |
              v
        object files (.o)
              |
              v
            linking
              |
              v
           executable
              |
              v
            runtime
```

The preprocessor handles directives such as `#include`. The compiler checks
the language rules and translates each source file into an object file. The
linker combines object files and libraries, resolving references between them.
Only then can the operating system run the executable.

## 1. Anatomy of a minimal program

Start with [`01_hello_world.cpp`](01_hello_world.cpp):

```cpp
#include <iostream>

int main()
{
    std::cout << "Hello, C++!" << std::endl;
    return 0;
}
```

- `#include <iostream>` makes the standard stream declarations available.
- `main` is the program's entry point.
- `std::cout` writes text to standard output.
- `return 0` reports successful completion to the operating system.

Compile and run it from this lesson directory:

```bash
mkdir -p build
g++ -std=c++20 -Wall -Wextra -Wpedantic 01_hello_world.cpp \
    -o build/hello_world
./build/hello_world
```

## 2. Compiler diagnostics

Use [`02_compile_error.cpp`](02_compile_error.cpp) as a valid starting point.
Compile it first, then deliberately introduce one error at a time—for example,
remove a semicolon or misspell `number`—and read the diagnostic from top to
bottom.

```bash
g++ -std=c++20 -Wall -Wextra -Wpedantic 02_compile_error.cpp \
    -o build/compile_error
```

A compiler error occurs while a single translation unit is being translated.
The executable is not produced. The first diagnostic is often the most useful,
because later messages may only be consequences of the first problem.

## 3. Compiling and linking multiple source files

The files in [`03_linker_example`](03_linker_example/) demonstrate separate
compilation:

- `main.cpp` declares and calls `sayHello`;
- `hello_function.cpp` defines `sayHello`.

Compile each source file, then link the object files:

```bash
g++ -std=c++20 -Wall -Wextra -Wpedantic -c \
    03_linker_example/main.cpp -o build/main.o
g++ -std=c++20 -Wall -Wextra -Wpedantic -c \
    03_linker_example/hello_function.cpp -o build/hello_function.o
g++ build/main.o build/hello_function.o -o build/linker_example
./build/linker_example
```

To observe a linker error, try linking only `build/main.o`. Compilation
succeeds because the declaration is visible, but linking fails because the
definition is missing.

## 4. Sharing declarations with headers

The [`04_headers`](04_headers/) example replaces the handwritten declaration
in `main.cpp` with a shared header:

```text
hello.hpp  -> declares sayHello
hello.cpp  -> defines sayHello
main.cpp   -> includes the declaration and calls sayHello
```

Build both source files together:

```bash
g++ -std=c++20 -Wall -Wextra -Wpedantic \
    04_headers/main.cpp 04_headers/hello.cpp -o build/headers_example
./build/headers_example
```

`hello.hpp` uses `#pragma once`, which prevents the header's contents from
being processed more than once in the same translation unit. The same behavior
can also be implemented with include guards.

[`07_multiple_includes.cpp`](07_multiple_includes.cpp) includes the header
twice to demonstrate this protection:

```bash
g++ -std=c++20 -Wall -Wextra -Wpedantic \
    07_multiple_includes.cpp 04_headers/hello.cpp \
    -o build/multiple_includes
./build/multiple_includes
```

## 5. Runtime errors

[`05_runtime_error.cpp`](05_runtime_error.cpp) compiles and links, but attempts
integer division by zero while running. This is undefined behavior: a
successful build does not guarantee a correct or safe program.

Sanitizers make many runtime failures easier to identify:

```bash
g++ -std=c++20 -Wall -Wextra -Wpedantic \
    -fsanitize=undefined -fno-sanitize-recover=all \
    05_runtime_error.cpp -o build/runtime_error
./build/runtime_error
```

This example is intentionally faulty and should be run only as a diagnostic
exercise.

## 6. Warnings

[`06_warnings.cpp`](06_warnings.cpp) contains an unused local variable. It is
valid C++, so compilation can succeed, but enabling warnings reveals the likely
mistake:

```bash
g++ -std=c++20 -Wall -Wextra -Wpedantic 06_warnings.cpp \
    -o build/warnings_example
```

Treat warnings as actionable engineering feedback. In production code, it is
often useful to add `-Werror` so warnings fail the build after the codebase is
warning-clean.

## Diagnostic summary

| Diagnostic | Stage | Typical cause | Executable produced? |
| --- | --- | --- | --- |
| Compiler error | Compilation | Invalid syntax, type mismatch, unknown name | No |
| Linker error | Linking | Missing definition, duplicate definition | No |
| Runtime error | Execution | Invalid operation, bad memory access | Yes |
| Warning | Usually compilation | Suspicious but valid code | Usually yes |

