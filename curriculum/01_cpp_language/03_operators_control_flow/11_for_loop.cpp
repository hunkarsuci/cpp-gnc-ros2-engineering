#include <iostream>

int main()
{
    std::cout << "Basic for loop:\n";

    for (int i{0}; i < 5; ++i)
    {
        std::cout << "i: "
                  << i << '\n';
    }

    std::cout << "\nCountdown:\n";

    for (int i{5}; i > 0; --i)
    {
        std::cout << "i: "
                  << i << '\n';
    }

    std::cout << "\nStep size of two:\n";

    for (int i{0}; i <= 10; i += 2)
    {
        std::cout << "i: "
                  << i << '\n';
    }

    const double dt{0.1};
    const double acceleration{2.0};

    double velocity{0.0};

    std::cout << "\nSimulation loop:\n";

    for (int step{0}; step < 10; ++step)
    {
        velocity += acceleration * dt;

        const double time{
            (step + 1) * dt
        };

        std::cout << "step: "
                  << step
                  << ", time: "
                  << time
                  << ", velocity: "
                  << velocity
                  << '\n';
    }

    std::cout << "\nNested loops:\n";

    for (int row{0}; row < 2; ++row)
    {
        for (int column{0}; column < 3; ++column)
        {
            std::cout << "row: "
                      << row
                      << ", column: "
                      << column
                      << '\n';
        }
    }

    return 0;
}