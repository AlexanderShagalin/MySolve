#include <limits>

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



    return std::vector<double>(2);
}
