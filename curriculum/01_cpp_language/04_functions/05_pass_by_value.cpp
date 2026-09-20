#include <iostream> 

void demonstrateCopy(int value)
{
    std::cout << "Inside function before changes: "
              << value << '\n';

    value = 100; 
    
    std::cout << "Inside function after changes: "
              << value << '\n';
}

int increment(int value)
{
    return value + 1;
}

double calculateVelocity(double velocity,
                         double acceleration,
                         double dt)
{
    return velocity + acceleration * dt;
}

int main()
{
    std::cout << "Pass-by<-value copy:\n";

    int number{5};

    std::cout << "Before function call: "
              << number << '\n';
    
    demonstrateCopy(number);

    std::cout << "After function call: "
              << number << '\n';
    
    std::cout << "\nReturning a modified value:\n";

    int counter{10};

    std::cout << "Before increment: " << counter << '\n';

    counter = increment(counter); 

    std::cout << "After increment: " << counter << '\n';

    std::cout << "\nVelocity simulation:\n"; 

    const double acceleration{2.0};
    const double dt{0.1}; 

    double velocity{0.0};

    for(int step{0}; step < 5; ++step)
    {
        velocity = calculateVelocity(
            velocity, acceleration, dt
        );

        std::cout << "step: "
                  << step 
                  << ", velocity: "
                  << velocity
                  << '\n';
    }

}
