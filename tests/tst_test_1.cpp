#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include <limits>

#include "my_lib.hpp"

using namespace testing;

TEST(my_nan, 1)
{
    // ASSERT_THAT(my_nan(std::numeric_limits<double>::quiet_NaN()), Eq(true));
    ASSERT_EQ(my_nan(std::numeric_limits<double>::quiet_NaN()), true);
}
TEST(my_nan, 2)
{
    ASSERT_EQ(my_nan(std::numeric_limits<double>::signaling_NaN()), true);
}
TEST(my_nan, 3)
{
    ASSERT_EQ(my_nan(-std::numeric_limits<double>::epsilon()), false);
}
TEST(my_nan, 4)
{
    ASSERT_EQ(my_nan(std::numeric_limits<double>::infinity()), true);
}
TEST(my_nan, 5)
{
    ASSERT_EQ(my_nan(-std::numeric_limits<double>::infinity()), true);
}
TEST(my_nan, 6)
{
    ASSERT_EQ(my_nan(-300.676), false);
}
TEST(my_nan, 7)
{
    ASSERT_EQ(my_nan(100545513216800.676), false);
}
