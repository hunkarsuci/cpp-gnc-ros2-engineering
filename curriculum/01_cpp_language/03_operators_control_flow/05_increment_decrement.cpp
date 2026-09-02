#include <iostream>

int main()
{
    int counter{5};

    std::cout << "Basic increment/decrement:\n";
    std::cout << "initial: "
              << counter << '\n';

    ++counter;

    std::cout << "after ++counter: "
              << counter << '\n';

    --counter;

    std::cout << "after --counter: "
              << counter << '\n';

    int prefixValue{5};

    int prefixResult{++prefixValue};

    std::cout << "\nPrefix increment:\n";
    std::cout << "prefixValue: "
              << prefixValue << '\n';

    std::cout << "prefixResult: "
              << prefixResult << '\n';

    int postfixValue{5};

    int postfixResult{postfixValue++};

    std::cout << "\nPostfix increment:\n";
    std::cout << "postfixValue: "
              << postfixValue << '\n';

    std::cout << "postfixResult: "
              << postfixResult << '\n';

    int prefixDecrementValue{5};

    int prefixDecrementResult{
        --prefixDecrementValue
    };

    std::cout << "\nPrefix decrement:\n";
    std::cout << "value: "
              << prefixDecrementValue << '\n';

    std::cout << "result: "
              << prefixDecrementResult << '\n';

    int postfixDecrementValue{5};

    int postfixDecrementResult{
        postfixDecrementValue--
    };

    std::cout << "\nPostfix decrement:\n";
    std::cout << "value: "
              << postfixDecrementValue << '\n';

    std::cout << "result: "
              << postfixDecrementResult << '\n';

    int sampleCount{0};

    ++sampleCount;
    ++sampleCount;
    ++sampleCount;

    std::cout << "\nSample counter:\n";
    std::cout << "sampleCount: "
              << sampleCount << '\n';


    return 0;
}