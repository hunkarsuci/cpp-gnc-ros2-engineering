#include <iostream> 

int main() 
{
    std::cout << std::boolalpha;

    bool gpsHealthy{true};
    bool imuHealth{true};

    bool navigationReady{gpsHealthy && imuHealth};

    std::cout << "Logical AND:\n";
    std::cout << "gpsHealthy: " << gpsHealthy << '\n';

    std::cout << "imuHealthy: " << imuHealth << '\n';
    std::cout << "navigationReady: "
              << navigationReady << '\n';

    bool batteryCritical{false};
    bool motorFailure{true};

    bool emergency{
        batteryCritical || motorFailure
    };

    std::cout << "\nLogical OR:\n";
    std::cout << "batteryCritical: "
              << batteryCritical << '\n';

    std::cout << "motorFailure: "
              << motorFailure << '\n';
    
    std::cout << "emergency: "
              << emergency << '\n';

    bool systemReady{true};

    std::cout << "\nLogical NOT:\n";
    std::cout << "systemReady: "
              << systemReady << '\n';

    std::cout << "!systemReady: "
              << !systemReady << '\n';

    double altitude{1200.0};
    double velocity{20.0};

    const double minimumAltitude{1000.0};
    const double maximumVelocity{30.0};

    bool safeState{altitude >= minimumAltitude && velocity <= maximumVelocity};

    std::cout << "\nCombined comparisons:\n";
    std::cout << "safeState: " << safeState << '\n';

    double throttle{75.0};

    bool validThrottle{throttle >= 0.0 && throttle <= 100.0}; 

    std::cout << "\nRange check:\n";
    std::cout << "validThrottle: "
              << validThrottle << '\n';

    int denominator{0};

    bool validDivision{
        denominator != 0 &&
        10 / denominator > 2
    };

    std::cout << "\nShort-circuit example:\n";
    std::cout << "validDivision: "
              << validDivision << '\n';

    bool estimatorReady{true};
    bool emergencyStop{false};

    bool controlEnabled{safeState && estimatorReady && !emergencyStop}; 

    std::cout << "\nControl condition:\n";
    std::cout << "controlEnabled: " << controlEnabled << '\n';

    return 0;
}