// This function is defined in 03_linker_example/hello_function.cpp.
// The declaration lets this source file compile without seeing the definition.
void sayHello();

int main()
{
    sayHello();
    return 0;
}

// Build the two source files separately, then link their object files:
//
// g++ -std=c++20 -Wall -Wextra -Wpedantic -c 02_two_file_linking.cpp -o build/two_file_main.o
// g++ -std=c++20 -Wall -Wextra -Wpedantic -c 03_linker_example/hello_function.cpp -o build/hello_function.o
// g++ build/two_file_main.o build/hello_function.o -o build/two_file_linking
