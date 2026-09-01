#include <iostream> 

void updateState()
{
    double correction{2.5};
    bool updateValid{true};

    std::cout << "\nInside updateState:\n";

    std::cout << "correction value: "
              << correction << '\n';

    std::cout << "correction address: "
              << &correction << '\n';

    std::cout << std::boolalpha; 

    std::cout << "updateValid: "
              <<  updateValid << '\n'; 

    std::cout << "updateValid address: "
              << &updateValid  << '\n';

    // correction and updateValid have 
    //automatic storage duration. 
    // 
    // Their lifetimes end when 
    // updateState() returns
}

int main() 
{

    double position{100.0};
    double velocity{12.5};

    std::cout << "Inside main:\n";

    std::cout << "position value: "
              << position << '\n';

    std::cout << "position address: "
              << &position << '\n';

    std::cout << "velocity value: "
              << velocity << '\n';

    std::cout << "velocity address: "
              << &velocity << '\n';

    updateState(); 

    std::cout << "position: "
              << position << '\n';

    std::cout << "velocity: "
              << velocity << '\n';

    // Conceptual preview only:
    //
    // Dynamic objects have dynamic storage
    // duration and are commonly allocated
    // from the heap/free store.
    //
    // We will study dynamic allocation after
    // references and pointers.

    /*
    
    STACK / automatic
    -----------------
    local variables
    function-call related
    automatic lifetime cleanup
    related with scope


    HEAP / dynamic
    --------------
    runtime allocation
    lifetime can be independent from scope
    ownership management requires 
    pointer/reference abstractions are related

    */

    return 0;

}