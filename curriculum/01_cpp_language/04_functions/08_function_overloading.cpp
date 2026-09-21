#include <cmath>
#include <iostream>

struct Vector2
{
    double x;
    double y;
};

void printValue(int value);
void printValue(double value);

double magnitude(double value);
double magnitude(const Vector2& vector);

int main()
{
    std::cout << "Function overloading:\n";

    printValue(10);
    printValue(3.5);

    std::cout << "\nMagnitude overloads:\n";

    const double scalar{-5.0};

    std::cout << "Scalar magnitude: "
              << magnitude(scalar)
              << '\n';

    const Vector2 velocity{
        3.0,
        4.0
    };

    std::cout << "Vector magnitude: "
              << magnitude(velocity)
              << '\n';

    return 0;
}

void printValue(int value)
{
    std::cout << "int value: "
              << value << '\n';
}

void printValue(double value)
{
    std::cout << "double value: "
              << value << '\n';
}

double magnitude(double value)
{
    if (value < 0.0)
    {
        return -value;
    }

    return value;
}

double magnitude(const Vector2& vector)
{
    return std::sqrt(
        vector.x * vector.x
        + vector.y * vector.y
    );
}