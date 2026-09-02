#include <iostream>

int main()
{
    int a{10};
    int b{3};

    std::cout << "Integer arithmetic:\n";
    std::cout << "a: " << a << '\n';
    std::cout << "b: " << b << '\n';

    std::cout << "a + b: "
              << a + b << '\n';

    std::cout << "a - b: "
              << a - b << '\n';

    std::cout << "a * b: "
              << a * b << '\n';

    std::cout << "a / b: "
              << a / b << '\n';

    std::cout << "a % b: "
              << a % b << '\n';

    double floatingDivision{
        static_cast<double>(a) / b
    };

    std::cout << "\nFloating-point division:\n";
    std::cout << "a / b: "
              << floatingDivision << '\n';

    int number{17};
    int divisor{5};

    std::cout << "\nDivision and remainder:\n";
    std::cout << number << " / "
              << divisor << " = "
              << number / divisor << '\n';

    std::cout << number << " % "
              << divisor << " = "
              << number % divisor << '\n';

    int positiveValue{10}; 
    int negativeValue{-positiveValue}; 

    std::cout << "\nUnary operator:\n";
    std::cout << "positiveValue: "
              << positiveValue << '\n';

    std::cout << "negativeValue: "
              << negativeValue << '\n';

    const double dt{0.01};
    const double acceleration{2.0};

    double velocity{10.0};
    double position{100.0};

    velocity = velocity + acceleration * dt;
    position = position + velocity * dt;

    std::cout <<"\nSimple state update:\n";
    std::cout <<"velocity: " << velocity << '\n';

    std::cout << "position: " << position << '\n';

    return 0;

}