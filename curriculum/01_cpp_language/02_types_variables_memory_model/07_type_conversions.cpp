#include <iostream>

int main()
{
    int integerValue{42};
    double convertedToDouble{integerValue};

    std::cout << "Integer to double:\n";
    std::cout << "integerValue: "
              << integerValue << '\n';

    std::cout << "convertedToDouble: "
              << convertedToDouble << '\n';

    double preciseValue{3.99};

    int implicitInteger = preciseValue;
    int explicitInteger{
        static_cast<int>(preciseValue)
    };

    std::cout << "\nDouble to integer:\n";
    std::cout << "preciseValue: "
              << preciseValue << '\n';

    std::cout << "implicitInteger: "
              << implicitInteger << '\n';

    std::cout << "explicitInteger: "
              << explicitInteger << '\n';

    int numerator{5};
    int denominator{2};

    double integerDivision{
        numerator / denominator
    };

    double floatingPointDivision{
        static_cast<double>(numerator) / denominator
    };

    std::cout << "\nDivision:\n";
    std::cout << "integer division: "
              << integerDivision << '\n';

    std::cout << "Sizeof: "<< sizeof(integerDivision) << '\n';

    std::cout << "floating-point division: "
              << floatingPointDivision << '\n';

    char letter{'A'};

    int characterCode{
        static_cast<int>(letter)
    };

    std::cout << "\nCharacter conversion:\n";
    std::cout << "letter: " << letter << '\n';
    std::cout << "numeric representation: "
              << characterCode << '\n';

    bool systemReady{true};

    int boolAsInteger{
        static_cast<int>(systemReady)
    };

    std::cout << "\nBool conversion:\n";
    std::cout << std::boolalpha;
    std::cout << "systemReady: "
              << systemReady << '\n';

    std::cout << "bool as integer: "
              << boolAsInteger << '\n';

    return 0;
}