#include <iostream>

int main()
{
    int value{10};

    std::cout << "Initial value:\n";
    std::cout << "value: "
              << value << '\n';

    value = 20;

    std::cout << "\nSimple assignment:\n";
    std::cout << "value: "
              << value << '\n';

    value += 5;

    std::cout << "\nAfter += 5:\n";
    std::cout << "value: "
              << value << '\n';

    value -= 3;

    std::cout << "\nAfter -= 3:\n";
    std::cout << "value: "
              << value << '\n';   
    
    value *= 2;

    std::cout << "\nAfter *= 2:\n";
    std::cout << "value: "
              << value << '\n';
              
    value /= 4;

    std::cout << "\nAfter /= 4:\n";
    std::cout << "value: "
              << value << '\n';

    value %= 3;

    std::cout << "\nAfter %= 3:\n";
    std::cout << "value: "
              << value << '\n';          

    const double dt{0.01};
    const double acceleration{2.0};

    double velocity{10.0};
    double position{100.0};

    velocity += acceleration * dt; 
    position += velocity * dt; 

    std::cout << "\nState update:\n";
    std::cout << "velocity: " << velocity << '\n';

    std::cout << "position: " << position << '\n'; 

    return 0;

}