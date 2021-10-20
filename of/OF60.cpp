#include <gtest/gtest.h>

#include <algorithm>
#include <unordered_map>
#include <vector>

#include "Common.h"

using namespace std;

/**
 * https://leetcode-cn.com/leetbook/read/illustration-of-algorithm/ozzl1r/
 */
class Solution {
public:
    vector<double> dicesProbability(int n) {
        /* 初始dp，即f(1)，因f(n)只与f(n-1)相关，也作为f(n-1)结果保存 */
        vector<double> dp(6, 1.0 / 6.0);
        for (int i = 2; i <= n; ++i) {
            /* 最小为n，最大为6n，个数为5n+1，表示的f(n) */
            vector<double> tmp(5 * i + 1, 0);
            /*
             * 从f(n-1)出发，找到f(n)中与相关的数值并计算概率
             * 数组下标0表示的是第一个数，即n
             */
            for (int j = 0; j < dp.size(); ++j) {
                for (int k = 0; k < 6; ++k) {
                    tmp[j + k] += dp[j] / 6.0;
                }
            }
            /* 将dp更新为f(n)，作为后续遍历的f(n-1) */
            dp = tmp;
        }
        return dp;
    }
};

class OF60Tests : public ::testing::Test {
protected:
    Solution solution;
};

/* double存储格式问题，不能直接判断相等 */
bool equal(double a, double b) {
    if (abs(a - b) < 0.00001) {
        return true;
    }
    return false;
}

TEST_F(OF60Tests, normal) {
    vector<double> expect{0.02778, 0.05556, 0.08333, 0.11111, 0.13889, 0.16667, 0.13889, 0.11111, 0.08333, 0.05556,
                          0.02778};
    auto output = solution.dicesProbability(2);
    for (int i = 0; i < expect.size(); ++i) {
        EXPECT_TRUE(equal(output[i], expect[i]));
    }
}