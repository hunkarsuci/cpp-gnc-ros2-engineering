#include <iostream>

int main()
{
    int counter{0};

    std::cout << "Basic while loop:\n";

    while (counter < 5)
    {
        std::cout << "counter: "
                  << counter << '\n';

        ++counter;
    }

    int remainingSteps{3};

    std::cout << "\nCountdown:\n";

    while (remainingSteps > 0)
    {
        std::cout << "remainingSteps: "
                  << remainingSteps << '\n';

        --remainingSteps;
    }

    const double dt{0.1};
    const double acceleration{2.0};

    double velocity{0.0};
    int simulationStep{0};

    std::cout << "\nSimulation loop:\n";

    while (simulationStep < 10)
    {
        velocity += acceleration * dt;

        ++simulationStep;

        double time{
            simulationStep * dt
        };

        std::cout << "step: "
                  << simulationStep
                  << ", time: "
                  << time
                  << ", velocity: "
                  << velocity
                  << '\n';
    }

    bool missionComplete{false};
    int missionStep{0};

    std::cout << "\nState-driven loop:\n";

    while (!missionComplete)
    {
        ++missionStep;

        std::cout << "missionStep: "
                  << missionStep << '\n';

        if (missionStep >= 3)
        {
            missionComplete = true;
        }
    }

    return 0;
}