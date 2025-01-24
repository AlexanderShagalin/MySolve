#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include <limits>

#include "my_lib.hpp"

using namespace testing;



TEST(solve, 1) // x^2+1 = 0
{
    ASSERT_EQ(solve(7, 0, 1).size(), 0);
}

TEST(solve, 2) // для уравнения x^2-1 = 0 есть два корня кратности 1 (x1=1, x2=-1)
{
    auto data = std::vector<double>(2);
    data[0] = 1.0;
    data[1] = -1.0;
    auto result = solve(1, 0, -1);
    ASSERT_EQ(result.size(), 2);
    ASSERT_DOUBLE_EQ(result[0], 1);
    ASSERT_DOUBLE_EQ(result[1], -1);
}

TEST(solve, 3) // для уравнения x^2+2x+1 = 0 есть один корень кратности 2 (x1= x2 = -1)
{
    auto data = std::vector<double>(2);
    data[0] = 1.0;
    data[1] = -1.0;
    auto result = solve(1, 2, 1);
    ASSERT_EQ(result.size(), 2);
    ASSERT_DOUBLE_EQ(result[0], -1);
    ASSERT_DOUBLE_EQ(result[1], -1);
}

TEST(solve, 4) // a не может быть равен 0
{
    std::vector<double> result;
    ASSERT_ANY_THROW(result = solve(0.0, 2, 1));

    ASSERT_EQ(result.size(), 0);
}

TEST(solve, 10)
{
    ASSERT_EQ(solve(std::numeric_limits<double>::quiet_NaN(), 0, 0).size(), 0);
}

TEST(solve, 11)
{
    ASSERT_EQ(solve(0, std::numeric_limits<double>::quiet_NaN(), 0).size(), 0);
}

TEST(solve, 12)
{
    ASSERT_EQ(solve(0, 0, std::numeric_limits<double>::quiet_NaN()).size(), 0);
}
