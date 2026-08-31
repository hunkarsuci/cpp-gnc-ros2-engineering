#include <iostream>

int main()
{
    int outerValue{10};

    std::cout << "Outer scope:\n";
    std::cout << "outerValue: "
              << outerValue << '\n';

    {
        int innerValue{20};

        std::cout << "\nInner scope:\n";
        std::cout << "outerValue: "
                  << outerValue << '\n';

        std::cout << "innerValue: "
                  << innerValue << '\n';
    }

    std::cout << "\nBack in outer scope:\n";
    std::cout << "outerValue: "
              << outerValue << '\n';

    // innerValue no longer exists in this scope:
    // std::cout << innerValue << '\n';

    int value{100};

    std::cout << "\nBefore shadowing:\n";
    std::cout << "value: "
              << value << '\n';

    {
        int value{200};

        std::cout << "Inside shadowing scope:\n";
        std::cout << "value: " << value << '\n'; // the value is here 200
    }

    std::cout << "After shadowing scope:\n";
    std::cout << "value: " << value << '\n';

    std::cout << "\nLoop scope:\n";

    for (int i{0}; i < 3; ++i)
    {
        std::cout << "i: " << i << '\n';
    }

    // i is out of scope here:
    // std::cout << i << '\n';

    double estimatedPosition{100.0};

    {
        const double innovation{2.5};
        const double gain{0.4};

        const double correction{gain * innovation};

        estimatedPosition += correction;
    }

    std::cout << "\nUpdated position:\n";
    std::cout << "estimatedPosition: "
              << estimatedPosition << '\n';

    return 0;
}