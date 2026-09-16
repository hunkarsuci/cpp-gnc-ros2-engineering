#include <iostream> 

int square(int value)
{
    return value * value;
}

double calculateVelocity(
    double velocity,
    double acceleartion,
    double dt)
{
    return velocity + acceleartion * dt;
}

bool isVelocityWithinLimit(double velocity, double maximumVelocity)
{
    return velocity <= maximumVelocity;
}

int main()
{
    std::cout << "Basic return value:\n";

    const int squaredValue{square(5)};

    std::cout << "5 squared: " << squaredValue << '\n';

    const double acceleration{2.0};
    const double dt{0.1};
    const double maximumVelocity{0.7};

    double velocity{0.0};

    std::cout << "\nControl Simulation:\n";

    for(int step{0}; step < 5; ++step)
    {
        velocity = calculateVelocity(velocity, acceleration, dt);

        std::cout << "step: " 
                  << step
                  << ", velocity: " 
                  << velocity 
                  << '\n';

        if(!isVelocityWithinLimit(velocity, maximumVelocity))
        {
            std::cout << "Velocity limit exceeded.\n";
        }

    }

    return 0;

}