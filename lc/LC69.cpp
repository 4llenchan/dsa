#include <gtest/gtest.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <numeric>

#include "Common.h"

using namespace std;

/**
 * https://leetcode-cn.com/problems/sqrtx/
 * 二分查找
 */
class Solution1 {
public:
    int mySqrt(int x) {
        if (x == 0) {
            return x;
        }
        int l = 1;
        int r = x;
        /* 虽然x的范围是int，取中间值的平方会超过int，所以这里用long long */
        long long sqrt = 0;
        int result = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            sqrt = (long long)mid * mid;
            if (sqrt == x) {
                return mid;
            } else if (sqrt < x) {
                result = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return result;
    }
};

class LC69Tests : public ::testing::Test {
protected:
    Solution1 solution1;
};

TEST_F(LC69Tests, case1) {
    EXPECT_EQ(solution1.mySqrt(8), 2);
}