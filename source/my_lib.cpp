#include <limits>
#include <math.h>

#include "my_lib.hpp"

bool my_nan(double value)
{
    if(value < std::numeric_limits<double>::lowest())
        return true;
    if(value > std::numeric_limits<double>::max())
        return true;
    if(value != value)
        return true;
    return false;
}

std::vector<double> solve(double a, double b, double c)
{
    if(my_nan(a))
        return std::vector<double>();
    if(my_nan(b))
        return std::vector<double>();
    if(my_nan(c))
        return std::vector<double>();

    if(a < std::numeric_limits<double>::epsilon() && a > -std::numeric_limits<double>::epsilon())
        return std::vector<double>();

    auto d = b * b - 4 * a * c;

    if(d < -std::numeric_limits<double>::epsilon())
    {
        return std::vector<double>();
    }

    if(d < std::numeric_limits<double>::epsilon() && d > -std::numeric_limits<double>::epsilon())
    {
        return {-b/(2*a), -b/(2*a)};
    }

    return { (-b+sqrt(d)) / (2 * a), (-b-sqrt(d)) / (2 * a)};
}
