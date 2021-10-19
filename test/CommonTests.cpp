#include "Common.h"
#include <gtest/gtest.h>

using namespace std;

class CommonTests : public ::testing::Test {
};

TEST_F(CommonTests, convertDecimal) {
    EXPECT_EQ(MathUtils::convertDecimal(10), "a");
    EXPECT_EQ(MathUtils::convertDecimal(35), "z");
    EXPECT_EQ(MathUtils::convertDecimal(36), "10");
    EXPECT_EQ(MathUtils::convertDecimal(46), "1a");
    EXPECT_EQ(MathUtils::convertDecimal(100), "2s");
    EXPECT_EQ(MathUtils::convertDecimal(1000), "rs");
    EXPECT_EQ(MathUtils::convertDecimal(10000), "7ps");
}

TEST_F(CommonTests, convertThirtySix) {
    EXPECT_EQ(MathUtils::convertThirtySix("7ps"), 10000);
    EXPECT_EQ(MathUtils::convertThirtySix("rs"), 1000);
    EXPECT_EQ(MathUtils::convertThirtySix("10"), 36);
    EXPECT_EQ(MathUtils::convertThirtySix("z"), 35);
    EXPECT_EQ(MathUtils::convertThirtySix("a"), 10);
}