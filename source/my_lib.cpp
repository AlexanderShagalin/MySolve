#include <vector>

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

double solve(double a, double b, double c)
{



    return 0;
}
