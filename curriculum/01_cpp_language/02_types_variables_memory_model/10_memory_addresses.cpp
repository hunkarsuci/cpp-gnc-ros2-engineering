#include <iostream>

int main()
{
    int altitude{1000};
    double velocity{12.5};
    bool systemReady{true};

    std::cout << std::boolalpha;

    std::cout << "Objects and addresses:\n";

    std::cout << "\nAltitude:\n";
    std::cout << "value: "
              << altitude << '\n';
    std::cout << "size: "
              << sizeof(altitude) << " bytes\n";
    std::cout << "address: "
              << &altitude << '\n';

    std::cout << "\nVelocity:\n";
    std::cout << "value: "
              << velocity << '\n';
    std::cout << "size: "
              << sizeof(velocity) << " bytes\n";
    std::cout << "address: "
              << &velocity << '\n';

    std::cout << "\nSystem ready:\n";
    std::cout << "value: "
              << systemReady << '\n';
    std::cout << "size: "
              << sizeof(systemReady) << " bytes\n";
    std::cout << "address: "
              << &systemReady << '\n';

    int value{10};

    std::cout << "\nBefore assignment:\n";
    std::cout << "value: "
              << value << '\n';
    std::cout << "address: "
              << &value << '\n';

    value = 20;

    std::cout << "\nAfter assignment:\n";
    std::cout << "value: "
              << value << '\n';
    std::cout << "address: "
              << &value << '\n';

    int original{42};
    int copy{original}; // this is different object, so different memory

    std::cout << "\nCopy experiment:\n";

    std::cout << "original value: "
              << original << '\n';
    std::cout << "original address: "
              << &original << '\n';

    std::cout << "copy value: "
              << copy << '\n';
    std::cout << "copy address: "
              << &copy << '\n';

    copy = 100; // update with new valuem but it is same meomory

    std::cout << "\nAfter modifying copy:\n";
    std::cout << "original: "
              << original << '\n';
    std::cout << "copy: "
              << copy << '\n';

    {
        int scopedValue{500}; // inner value 

        std::cout << "\nScoped object:\n";
        std::cout << "value: "
                  << scopedValue << '\n';
        std::cout << "address: "
                  << &scopedValue << '\n';
    } // memory is until here remained

    // scopedValue's lifetime has ended here.

    return 0;
}