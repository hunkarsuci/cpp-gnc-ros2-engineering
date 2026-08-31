#include <iostream> 
#include <cmath>
#include <iomanip>

int main() 
{
    double preciseValue{3.99};

    int implicitInteger = preciseValue;

    int explicitInteger{
        static_cast<int>(preciseValue)
    };

    int roundedInteger{
        static_cast<int>(
            std::round(preciseValue)
        )
    };

    std::cout << "Double to integer:\n";
    std::cout << "preciseValue: "
              << preciseValue << '\n';

    std::cout << "implicitInteger: "
              << implicitInteger << '\n';

    std::cout << "explicitInteger: "
              << explicitInteger << '\n';

    std::cout << "roundedInteger: "
              << roundedInteger << '\n';


    double highPrecision{
        3.141592653589793
    };

    float reducedPrecision{
        static_cast<float>(highPrecision)
    };

    std::cout << "\nDouble to float:\n";
    std::cout << std::setprecision(17);

    std::cout << "double: "
              << highPrecision << '\n';

    std::cout << "float: "
              << reducedPrecision << '\n';        

    long long largeInteger{
        9007199254740993LL
    };

    double convertedLargeInteger{
        static_cast<double>(largeInteger)
    };

    std::cout << "\nLarge integer to double:\n";
    std::cout << "largeInteger: "
              << largeInteger << '\n';

    std::cout << std::fixed
              << std::setprecision(0);

    std::cout << "converted: "
              << convertedLargeInteger << '\n';

    int signedValue{-1};

    unsigned int unsignedValue{
        static_cast<unsigned int>(signedValue)
    };

    std::cout << "\nSigned to unsigned:\n";
    std::cout << "signedValue: "
              << signedValue << '\n';

    std::cout << "unsignedValue: "
              << unsignedValue << '\n';
              
    // Brace initialization protects against
    // many narrowing conversions:
    //
    // int invalidInteger{3.99};
    //
    // double value{3.99};
    // int invalidFromVariable{value};
    //
    // double precise{3.14159};
    // float invalidFloat{precise};

    return 0;
}