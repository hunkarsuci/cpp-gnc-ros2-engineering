#include <iostream>
#include <limits>

int main()
{
    signed int signedNumber = -42; // positive or negative 
    unsigned int unsignedNumber = 42; // positive

    std::cout << "signedNumber: " << signedNumber << '\n';
    std::cout << "unsignedNumber: " << unsignedNumber << '\n';

    std::cout << "\nSizes:\n";
    std::cout << "sizeof(signed int): "
              << sizeof(signed int) << " bytes\n";

    std::cout << "unsigned(unsigned int): "
              << sizeof(unsigned int) << "bytes\n";

    std::cout << "\nRanges:\n";

    std::cout << "signed int min: "
              << std::numeric_limits<int>::min() << '\n';
    
    std::cout << "signed int max: "
              << std::numeric_limits<int>::max() << '\n';
    
    std::cout << "unsigned int min: "
              << std::numeric_limits<int>::min() << '\n';
              
    std::cout << "unsigned int max: "
              << std::numeric_limits<int>::max() << '\n';

    unsigned int value = 0; 
    std::cout << "Before: " << value << '\n';
    value = value - 1; 
    std::cout << "After: " << value << '\n'; // 2^32 - 1

    unsigned int maxValue = std::numeric_limits<unsigned int>::max();
    std::cout << "maxValue: " << maxValue << '\n';
    maxValue = maxValue + 1;
    std::cout << "after + 1: " << maxValue << '\n'; // maxvalue is 0
    
    // unsigned is arithmetic modulo artihmetic and does wrap around
    // signed and unsigned values mixing conversion/comparison bugs cause

}