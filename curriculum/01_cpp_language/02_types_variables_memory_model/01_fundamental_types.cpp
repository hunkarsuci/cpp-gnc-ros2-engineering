#include <iostream> 

int main() 
{
    short shortNumber = 10; 
    int integerNumber = 20; 
    long longNumber = 30; 
    long long veryLongNumber = 40; 

    float floatNumber = 3.14f; 
    double doubleNumber = 3.1415926535; 

    char letter = 'A'; 
    bool isActive = true; 

    std::cout << "short: " << sizeof(shortNumber) << " bytes\n";
    std::cout << "int: " << sizeof(integerNumber) << " bytes\n";
    std::cout << "long: " << sizeof(longNumber) << " bytes\n"; 
    std::cout << "long long: " << sizeof(veryLongNumber) << " bytes\n";
    
    std::cout << "float: " << sizeof(floatNumber) << " bytes\n";
    std::cout << "double: " << sizeof(doubleNumber) << " bytes\n";

    std::cout << "char: " << sizeof(letter) << " bytes\n"; 
    std::cout << "bool: " << sizeof(isActive) << " bytes\n";

    std::cout << "\nvalues:\n"; 
    
    std::cout << "integerNumber: " << integerNumber << '\n';
    std::cout << "floatNumber: " << floatNumber << '\n';
    std::cout << "doubleNumber: " << doubleNumber << '\n';
    std::cout << "letter = " << letter << '\n';
    std::cout << "isActive = " << isActive << '\n';

    std::cout << sizeof(short) << '\n';
    std::cout << sizeof(int) << '\n';
    std::cout << sizeof(long) << '\n';
    std::cout << sizeof(long long) << '\n';
    std::cout << sizeof(float) << '\n';
    std::cout << sizeof(double) << '\n';
    std::cout << sizeof(char) << '\n';
    std::cout << sizeof(bool) << '\n';

    return 0;

}