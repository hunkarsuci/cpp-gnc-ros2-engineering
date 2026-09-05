#include <iostream>

int main()
{
    int counter{0};

    std::cout << "Basic do-while loop:\n";

    do
    {
        std::cout << "counter: "
                  << counter << '\n';

        ++counter;
    }
    while (counter < 5);

    int value{10};

    std::cout << "\nRuns at least once:\n";

    do
    {
        std::cout << "value: "
                  << value << '\n';
    }
    while (value < 5);

    bool missionComplete{false};
    int missionStep{0};

    std::cout << "\nMission loop:\n";

    do
    {
        ++missionStep;

        std::cout << "missionStep: "
                  << missionStep << '\n';

        if (missionStep >= 3)
        {
            missionComplete = true;
        }
    }
    while (!missionComplete);

    int command{};

    std::cout << "\nInput validation:\n";

    do
    {
        std::cout << "Enter command (1-3): ";
        std::cin >> command;
    }
    while (command < 1 || command > 3);

    std::cout << "Accepted command: "
              << command << '\n';

    return 0;
}