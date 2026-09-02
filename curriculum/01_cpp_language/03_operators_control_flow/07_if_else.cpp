#include <iostream>

int main()
{
    double altitude{950.0};
    const double minimumAltitude{1000.0};

    std::cout << "Altitude check:\n";

    if (altitude < minimumAltitude)
    {
        std::cout << "Altitude is below minimum.\n";
    }
    else
    {
        std::cout << "Altitude is acceptable.\n";
    }

    double batteryLevel{35.0};

    std::cout << "\nBattery status:\n";

    if (batteryLevel < 20.0)
    {
        std::cout << "Battery critical.\n";
    }
    else if (batteryLevel < 50.0)
    {
        std::cout << "Battery low.\n";
    }
    else
    {
        std::cout << "Battery healthy.\n";
    }

    double throttle{75.0};

    std::cout << "\nThrottle validation:\n";

    if (
        throttle >= 0.0 &&
        throttle <= 100.0
    )
    {
        std::cout << "Throttle valid.\n";
    }
    else
    {
        std::cout << "Throttle invalid.\n";
    }

    bool estimatorReady{true};
    bool actuatorHealthy{true};
    bool emergencyStop{false};

    altitude = 1200.0; 

    std::cout << "\nController check:\n"; 

    if (
        estimatorReady && 
        actuatorHealthy && 
        !emergencyStop &&
        altitude >= minimumAltitude
    )
    {
        std::cout << "Controller enabled.\n";
    }
    else
    {
        std::cout << "Controller disabled.\n";

    }

    double verticalVelocity{-3.5};

    std::cout << "\nVertical motion:\n";

    if (verticalVelocity > 0.0)
    {
        std::cout << "Climbing.\n";
    }
    else if (verticalVelocity < 0.0)
    {
        std::cout << "Descending.\n";
    }
    else
    {
        std::cout << "Level.\n";
    }

    return 0;
}