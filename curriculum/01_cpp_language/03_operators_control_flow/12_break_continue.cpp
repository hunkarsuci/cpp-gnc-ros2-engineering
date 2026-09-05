#include <iostream> 

int main()
{
    std::cout << "Break example:\n"; 

    for (int i{0}; i < 10; ++i)
    {
        if (i == 5)
        {
            break; 
        }

        std::cout << "i: "
                  << i << '\n';
    }

    std::cout << "\nContinue example:\n";

    for(int i{0}; i < 10; ++i)
    {
        if(i % 2 != 0)
        {
            continue;
        }

        std::cout << "even value: "
                  << i << '\n';
    }

    std::cout << "\nSearch example:\n";

    for (int value{0}; value < 100; ++value)
    {
        if (value * value >= 50)
        {
            std::cout << "first matching value: "
                      << value << '\n';

            break;
        }
    }

    std::cout << "\nSensor processing:\n";

    for (int sample{0}; sample < 8; ++sample)
    {
        const double measurement{
            sample * 2.0
        };

        if (measurement > 10.0)
        {
            std::cout << "Skipping measurement: "
                      << measurement << '\n';

            continue;
        }

        std::cout << "Processing measurement: "
                  << measurement << '\n';
    }

    std::cout << "\nNested loop break:\n";

    for (int row{0}; row < 3; ++row)
    {
        for (int column{0}; column < 3; ++column)
        {
            if (column == 1)
            {
                break;
            }

            std::cout << "row: "
                      << row
                      << ", column: "
                      << column
                      << '\n';
        }
    }

    return 0;


}