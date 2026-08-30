#include <iostream> 

int main()
{
    const double gravity{9.81};
    const double sampleTime{0.01};
    const int maxIterations{100};
    const bool simulationMode{true};

    std::cout << std::boolalpha; 

    std::cout << "Constants:\n";
    std::cout << "gravity: " << gravity << '\n'; 
    std::cout << "sampleTime: " << sampleTime << '\n';
    std::cout << "maxIterations: " << maxIterations << '\n';

    double position{0.0}; 
    double velocity{10.0}; 

    std::cout << "\nInitial state:\n"; 
    std::cout << "position: " << position << '\n'; 
    std::cout << "velocity: " << velocity << '\n';

    position = position + velocity * sampleTime;
    velocity = 15.0; 

    std::cout << "\nUpdated state:\n"; 
    std::cout << "position: " << position << '\n';
    std::cout << "velocity: " << velocity << '\n';

    return 0; 

}