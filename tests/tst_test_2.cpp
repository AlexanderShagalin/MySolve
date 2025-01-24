#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include <limits>

#include "my_lib.hpp"

using namespace testing;

TEST(solve, 1)
{
    ASSERT_THAT(solve(std::numeric_limits<double>::quiet_NaN(), 0, 0), std::vector<double>());
}

TEST(solve, 2)
{
    ASSERT_THAT(solve(0, std::numeric_limits<double>::quiet_NaN(), 0), std::vector<double>());
}

TEST(solve, 3)
{
    ASSERT_THAT(solve(0, 0, std::numeric_limits<double>::quiet_NaN()), std::vector<double>());
}


TEST(solve, 4) // x^2+1 = 0
{
    ASSERT_THAT(solve(7, 0, 1), std::vector<double>());
}

