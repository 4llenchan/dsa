#include <gtest/gtest.h>

#include <vector>

using namespace std;

class Solution {
public:
    int fib(int n) {
        if (n <= 1) {
            return n;
        }

        int o = 0;
        int p = 1;
        int q;
        for (int i = 2; i <= n; ++i) {
            q = (o + p) % 1000000007;
            o = p;
            p = q;
        }
        return q;
    }
};

class OF10_ITests : public ::testing::Test {
protected:
    Solution solution;
};

TEST_F(OF10_ITests, normal) {
    EXPECT_EQ(5, solution.fib(5));
    EXPECT_EQ(55, solution.fib(10));
}