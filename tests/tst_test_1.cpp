
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "my_lib.hpp"

using namespace testing;

TEST(my_nan, 1)
{
    ASSERT_THAT(my_nan(std::numeric_limits<double>::quiet_NaN()), Eq(true));
}
TEST(my_nan, 2)
{
    ASSERT_THAT(my_nan(std::numeric_limits<double>::signaling_NaN()), Eq(true));
}
TEST(my_nan, 3)
{
    ASSERT_THAT(my_nan(-std::numeric_limits<double>::epsilon()), Eq(false));
}
TEST(my_nan, 4)
{
    ASSERT_THAT(my_nan(std::numeric_limits<double>::infinity()), Eq(true));
}
TEST(my_nan, 5)
{
    ASSERT_THAT(my_nan(-std::numeric_limits<double>::infinity()), Eq(true));
}
TEST(my_nan, 6)
{
    ASSERT_THAT(my_nan(-300.676), Eq(false));
}
TEST(my_nan, 7)
{
    ASSERT_THAT(my_nan(100545513216800.676), Eq(false));
}
