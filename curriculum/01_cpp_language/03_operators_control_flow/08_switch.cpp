#include <iostream>

int main()
{
    int flightMode{2};

    std::cout << "Flight mode:\n";

    switch (flightMode)
    {
        case 1:
        {
            std::cout << "Manual control\n";
            break;
        }

        case 2:
        {
            std::cout << "Position hold\n";
            break;
        }

        case 3: 
        {
            std::cout << "Return to home\n";
            break; 
        }

        case 4: 
        {
            std::cout << "Landing\n";
            break;
        }

        default:
        {
            std::cout << "Invalid Flight mode \n";
            break;
        }

    }

    char command{'Y'};
    
    std::cout << "\nCommand:\n";

    switch (command)
    {
        case 'y':
        case 'Y':
        {
            std::cout << "Command rejected\n";
            break;
        }

        default:
        {
            std::cout << "Unknown command\n";
            break;
        }

    }

    int systemState{1};

    std::cout << "\nSystem state:\n";

    switch (systemState)
    {
        case 0:
        {
            std::cout << "System offline\n";
            break;
        }

        case 1: 
        {
            std::cout << "System starting\n";
            break; 
        }
        case 2: 
        {
            std::cout << "System Running\n";
            break;
        }
        case 3: 
        {
            std::cout << "Unknown system state\n";
            break;
        }

        default:
        {
            std::cout << "Unknown system state\n";
            break;
        }
    
    }

    return 0;


}
