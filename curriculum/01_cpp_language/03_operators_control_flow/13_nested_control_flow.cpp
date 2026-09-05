#include <iostream>

int main()
{
    const double dt{0.1};
    const double acceleration{2.0};
    const double maximumVelocity{1.5};

    double velocity{0.0};

    bool emergencyStop{false};

    std::cout << "Control simulation:\n";

    for (int step{0}; step < 10; ++step)
    {
        const double measurement{
            step * 1.5
        };

        std::cout << "\nStep: "
                  << step << '\n';

        if (measurement > 10.0)
        {
            std::cout << "Measurement invalid, skipping.\n";
            continue;
        }

        velocity += acceleration * dt;

        if (velocity > maximumVelocity)
        {
            std::cout << "Velocity limit exceeded.\n";
            emergencyStop = true;
        }

        if (emergencyStop)
        {
            std::cout << "Emergency stop activated.\n";
            break;
        }

        if (measurement > 5.0)
        {
            std::cout << "Measurement high: "
                      << measurement << '\n';
        }
        else
        {
            std::cout << "Measurement nominal: "
                      << measurement << '\n';
        }

        std::cout << "velocity: "
                  << velocity << '\n';
    }

    std::cout << "\nProgram finished.\n";

    return 0;
}