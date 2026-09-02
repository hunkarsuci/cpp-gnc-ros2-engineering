#include <iostream> 

int main() 
{
    std::cout << std::boolalpha; 

    int arithmeticWithoutParentheses{
        2 + 3 * 4
    };

    int arithmeticWithParentheses{
        (2 + 3) * 4
    };

    std::cout << "Arithmetic precedence:\n";

    std::cout << "2 + 3 * 4: "
              << arithmeticWithoutParentheses << '\n';

    std::cout << "(2 + 3) * 4: "
              << arithmeticWithParentheses << '\n';
 
    int samePrecedence{
        20 / 5 * 2
    };

    std::cout << "\nAssociativity:\n";
    std::cout << "20 / 5 * 2: "
              << samePrecedence << '\n';

    int arithmeticValue{5};

    bool comparison{
        arithmeticValue + 3 > 6
    };

    std::cout << "\nArithmetic and comparison:\n";
    std::cout << "5 + 3 > 6: "
              << comparison << '\n';

    double altitude{1200.0};
    double velocity{20.0};

    const double minimumAltitude{1000.0};
    const double maximumVelocity{30.0};

    bool safeState{
        altitude >= minimumAltitude &&
        velocity <= maximumVelocity
    };

    std::cout << "\nComparison and logical AND:\n";
    std::cout << "safeState: "
              << safeState << '\n';

    bool a{true};
    bool b{false};
    bool c{false};

    bool withoutLogicalParentheses{
        a || b && c
    };

    bool withLogicalParentheses{
        (a || b) && c
    };

    std::cout << "\nLogical precedence:\n";

    std::cout << "a || b && c: "
              << withoutLogicalParentheses << '\n';

    std::cout << "(a || b) && c: "
              << withLogicalParentheses << '\n';

    int prefixValue{5};

    int prefixResult{
        ++prefixValue * 2
    };

    std::cout << "\nPrefix expression:\n";
    std::cout << "prefixValue: "
              << prefixValue << '\n';

    std::cout << "prefixResult: "
              << prefixResult << '\n';
    
    int first{};
    int second{};
    int source{10};

    first = second = source;

    std::cout << "\nAssignment associativity:\n";
    std::cout << "first: "
              << first << '\n';

    std::cout << "second: "
              << second << '\n';

    std::cout << "source: "
              << source << '\n';
              
    return 0;
}