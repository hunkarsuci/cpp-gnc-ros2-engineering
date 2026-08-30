#include <iostream>

int main()
{
    int copyInitialized = 10; // asignment
    int directInitialized(20);
    int braceInitialized{30}; // initialization

    std::cout << "copyInitialized: "
              << copyInitialized << '\n';

    std::cout << "directInitialized: "
              << directInitialized << '\n';

    std::cout << "braceInitialized: "
              << braceInitialized << '\n';

    int count{}; // initialization with 0 value
    double velocity{}; // initialization with 0 value 
    bool systemReady{}; 

    std::cout << "\nValue initialization:\n";
    std::cout << "count: " << count << '\n';
    std::cout << "velocity: " << velocity << '\n';

    std::cout << std::boolalpha; 
    std::cout << "systemReady: " << systemReady << '\n';

    double position{0.0}; 
    const double sampleTime{0.01}; 

    std::cout << "\nInitial state:\n"; 
    std::cout << "position: " << position << '\n'; 
    
    position = 10.0;

    std::cout << "updated position: " << position << '\n';
    std::cout << "sampleTime: " << sampleTime << '\n';

    // Narrowing examples: 
    //
    // int invalidValue{3.14};
    //
    // double preciseValue{3.9}; 
    // int truncatedValue{preciseValue};

    return 0;
}