#include <iostream> 

double calculateVelocity(
    double velocity,
    double acceleration,
    double dt
);

bool isVelocityWithinLimit(
    double velocity,
    double maximumVelocity
);

void printControlState(
    int step,
    double velocity
);

int main()
{
    const double acceleration{2.0};
    const double dt{0.1};
    const double maximumVelocity{0.7};

    double velocity{0.0};

    std::cout << "Control simulation:\n";

    for (int step{0}; step < 5; ++step)
    {
        velocity = calculateVelocity(velocity, acceleration, dt);

        printControlState(step, velocity);

        if(!isVelocityWithinLimit(velocity, maximumVelocity))
        {
            std::cout << "Velocity limit exceeded.\n";
        }
    }

    return 0;
}


double calculateVelocity(
    double velocity,
    double acceleration,
    double dt)
{
    return velocity + acceleration * dt;
}

bool isVelocityWithinLimit(
    double velocity,
    double maximumVelocity)
{
    return velocity <= maximumVelocity;
}

void printControlState(
    int step,
    double velocity)
{
    std::cout << "step: "
              << step
              << ", velocity: "
              << velocity
              << '\n';
}