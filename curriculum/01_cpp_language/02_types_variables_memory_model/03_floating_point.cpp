#include <iomanip> 
#include <iostream> 
#include <limits> 
#include <cmath>

int main()
{
    float floatValue = 3.14159265358979323846f;
    double doubleValue = 3.14159265358979323846;

    std::cout << "Sizes:\n";
    std::cout << "float: " << sizeof(floatValue) << " bytes\n";
    std::cout << "double: " << sizeof(doubleValue) << " bytes\n";

    std::cout << "\nDefault output:\n";
    std::cout << "floatValue: " << floatValue << '\n';
    std::cout << "doubleValue: " << doubleValue << '\n';

    std::cout << "\nHigh precision output:\n";
    std::cout << std::setprecision(20);

    std::cout << "floatValue: " << floatValue << '\n';
    std::cout << "doubleValue: " << doubleValue << '\n';

    
 
    // float carries ~7 decimal significant digits 
    // double carries ~15-16 decimal significant digits 

    // flaoting point numbers do not represent real value of itself, it is close as approximation value 

    double a = 0.1; 
    double b = 0.2;
    double sum = a + b;
    
    std::cout << "\n0.1 + 0.2 experiment:\n";
    std::cout << std::setprecision(20); 

    std::cout << "a: " << a << '\n';
    std::cout << "b: " << b << '\n';
    std::cout << "sum: " << sum << '\n';
    std::cout << "expected 0.3: " << 0.3 << '\n';

    if (sum == 0.3)
    {
        std::cout << "sum is exactly 0.3\n";
    }
    else
    {
        std::cout << "sum is NOT exactly 0.3\n";
    }

    double difference = std::abs(sum - 0.3);

    if (difference < 1e-12)
    {
        std::cout << "sum is approximately 0.3\n";
    }

    const double tolerance = 1e-12;

    if (std::abs(sum - 0.3) < tolerance)
    {
        std::cout << "Approximately equal\n";
    }

     // tolerance
    std::cout << "\nMachine epsilon:\n";

    std::cout << "float epsilon: " << std::numeric_limits<float>::epsilon() << '\n';

    std::cout << "double epsilon: " << std::numeric_limits<double>::epsilon() << '\n';

    // precision and range are not same things 

    // precision: how many digits represent the number of details 
    // range: how much large or small maginitude represent 

    std::cout << "\nDigits of precision:\n";
    
    std::cout << "float digits10: "
              << std::numeric_limits<float>::digits10 << '\n';
    
    std::cout << "double digits10: " << std::numeric_limits<double>::digits10 << '\n';

    double accumulated = 0.0;

    for (int i = 0; i < 10; ++i)
    {
        accumulated += 0.1;
    }

    std::cout << "\nAccumulation experiment:\n";
    std::cout << std::setprecision(20);

    std::cout << "accumulated: " << accumulated << '\n';
    std::cout << "expected: " << 1.0 << '\n';
    


    return 0;
}