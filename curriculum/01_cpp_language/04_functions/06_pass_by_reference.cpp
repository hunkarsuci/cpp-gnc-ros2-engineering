#include <iostream>

void changeValue(int& value)
{
    value = 100;
}

void increment(int& value)
{
    ++value;
}

void updateVelocity(
    double& velocity,
    double acceleration,
    double dt)
{
    velocity += acceleration * dt;
}

void clampVelocity(
    double& velocity,
    double maximumVelocity)
{
    if (velocity > maximumVelocity)
    {
        velocity = maximumVelocity;
    }
}

int main()
{
    std::cout << "Basic pass-by-reference:\n";

    int number{5};

    std::cout << "Before function call: "
              << number << '\n';

    changeValue(number);

    std::cout << "After function call: "
              << number << '\n';

    std::cout << "\nIncrement by reference:\n";

    int counter{10};

    increment(counter);

    std::cout << "Counter: "
              << counter << '\n';

    std::cout << "\nVelocity simulation:\n";

    const double acceleration{2.0};
    const double dt{0.1};
    const double maximumVelocity{0.7};

    double velocity{0.0};

    for (int step{0}; step < 5; ++step)
    {
        updateVelocity(
            velocity,
            acceleration,
            dt
        );

        clampVelocity(
            velocity,
            maximumVelocity
        );

        std::cout << "step: "
                  << step
                  << ", velocity: "
                  << velocity
                  << '\n';
    }

    return 0;
}