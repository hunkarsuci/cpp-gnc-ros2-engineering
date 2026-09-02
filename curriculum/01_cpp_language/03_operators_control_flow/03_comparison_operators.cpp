#include <iostream>
#include <cmath> 

int main()
{
    int a{10};
    int b{20};

    std::cout << std::boolalpha;

    std::cout << "a == b: " << (a == b) << '\n';
    std::cout << "a != b: " << (a != b) << '\n';
    std::cout << "a < b: " << (a < b) << '\n';
    std::cout << "a > b: " << (a > b) << '\n';
    std::cout << "a <= b: " << (a <= b) << '\n';
    std::cout << "a >= b: " << (a >= b) << '\n';


    double altitude{950.0};
    const double minimumAltitude{1000.0};

    bool belowMinimum{
        altitude < minimumAltitude
    };

    std::cout << "\nAltitude comparison:\n";
    std::cout << "altitude: "
              << altitude << '\n';

    std::cout << "minimumAltitude: "
              << minimumAltitude << '\n';

    std::cout << "belowMinimum: "
              << belowMinimum << '\n';

    char mode{'A'};

    bool autoMode{mode == 'A'};

    std::cout << "\nCharacter comparison:\n";
    std::cout << "mode: " << mode << '\n';
    std::cout << "autoMode: " << autoMode << '\n';

    double x{0.1 + 0.2}; 
    double expected{0.3}; 

    std::cout << "\nFloating-point comparison\n";
    std::cout << "exact equality: " << (x == expected) << '\n';

    const double tolerance{1e-12};

    bool approximatelyEqual{std::abs(x - expected) < tolerance}; 
    std::cout << "approximately equal: " << approximatelyEqual << '\n';
    
    return 0;
}