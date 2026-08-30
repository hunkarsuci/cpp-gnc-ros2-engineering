#include <iostream>
#include <limits>
#include <climits>

int main()
{
    bool systemReady = true;
    bool emergencyStop = false;

    char letter = 'A';
    char digit = '7';

    std::cout << "Bool values:\n";
    std::cout << "systemReady: " << systemReady << '\n';
    std::cout << "emergencyStop: " << emergencyStop << '\n';

    std::cout << "\nBool values with boolalpha:\n";
    std::cout << std::boolalpha; // this makes bool values true or false output

    std::cout << "systemReady: " << systemReady << '\n'; // 1
    std::cout << "emergencyStop: " << emergencyStop << '\n'; // 0

    std::cout << "\nChar values:\n";
    std::cout << "letter: " << letter << '\n';
    std::cout << "digit: " << digit << '\n';

    std::cout << "\nSizes:\n";
    std::cout << "sizeof(bool): " << sizeof(bool) << " byte(s)\n";
    std::cout << "sizeof(char): " << sizeof(char) << " byte(s)\n";

    bool a = 0; // zero = false
    bool b = 1; // nonzero = true
    bool c = -10; // nonzero = true
    bool d = 42; // nonzer = true

    std::cout << std::boolalpha; 

    std::cout << "a: " << a << '\n';
    std::cout << "b: " << b << '\n';
    std::cout << "c: " << c << '\n';
    std::cout << "d: " << d << '\n';

    // char 
    std::cout << letter << '\n'; // A is the output 

    // from char to int (ASCII table)
    std::cout << static_cast<int>(letter) << '\n'; // ASCII corresponding value 
    
    char lowerA = 'a'; 
    char zero = '0'; 

    std::cout << static_cast<int>(lowerA) << std::endl; 
    std::cout << static_cast<int>(zero) << '\n';  

    // Ex: '7' and 7 are not same because of ASCII 

    char characterSeven = '7'; 
    int integerSeven = 7; 

    std::cout << static_cast<int>(characterSeven) << '\n'; 
    std::cout << integerSeven << '\n'; 

    // Character Arithmetic 

    // recall char letter = 'A'; 

    letter = letter + 1; 
    std::cout << letter << '\n'; // B owing to ASCII compatible system 

    letter = static_cast<char>(letter + 1);
    std::cout << letter << '\n'; // C

    // ASCII 
    for (char letter ='A'; letter <= 'Z'; ++letter)
    {
        std::cout << letter << ' '; 
    }

    std::cout << '\n';

    // sizeof 

    std::cout << CHAR_BIT << '\n'; // the machine is 8 bits 

    // Example in GNC for bool and char 

    bool gpsAvailable = true; 
    bool imuHealthy = true; 
    char vehicleMode = 'A'; 

    std::cout << std::boolalpha; 

    std::cout << "GPS available: " << gpsAvailable << '\n'; 
    std::cout << "IMU healthy: " << imuHealthy << '\n'; 
    std::cout << "Vehicle mode: " << vehicleMode << '\n';

    // bool 
    // false / true 
    // logical state 
    // 0 false, non-zero true 

    // char 
    // character type 
    // numeric representation holds 
    // '7' and 7 or char and int are not same 
    // sizeof(char) is always 1 byte

    return 0;
}