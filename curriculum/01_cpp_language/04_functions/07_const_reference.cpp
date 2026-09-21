#include <iostream> 

struct VehicleStates
{
    double position;
    double velocity;
    double acceleration;
};

void printVehicleState(const VehicleStates& state)
{
    std::cout << "position: "
              << state.position
              << ", velocity: "
              << state.velocity
              << ", acceleration: "
              << state.acceleration
              << '\n';
}

void updateVelocity(VehicleStates& state, double dt)
{
    state.velocity += state.acceleration * dt;
}

bool isVelocityWithinLimit(const VehicleStates& state, double maximumVelocity)
{
    return state.velocity <= maximumVelocity;
}

int main()
{
    VehicleStates state{
        0.0,
        0.0,
        2.0
    };

    const double dt{0.1}; 
    const double maximumVelocity{0.7};

    std::cout << "Initial state:\n";

    printVehicleState(state);

    std::cout << "\nSimulation:\n";

    for(int step{0}; step < 5; ++step)
    {
        updateVelocity(state,dt);
        std::cout << "step: " << step << '\n';

        printVehicleState(state); 

        if(!isVelocityWithinLimit(state, maximumVelocity))
        {
            std::cout << "Velocity limit exceeded.\n";
        }

    }

    return 0;

}