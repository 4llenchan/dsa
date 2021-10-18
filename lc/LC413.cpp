#include <algorithm>
#include <gtest/gtest.h>
#include <numeric>
#include <unordered_map>
#include <vector>

#include "Common.h"

using namespace std;


namespace lc413 {
/**
 * https://leetcode-cn.com/problems/arithmetic-slices/
 * 类似于DP
 */
class Solution1 {
public:
    int numberOfArithmeticSlices(vector<int> &nums) {
        int n = (int)nums.size();
        if (n <= 1) {
            return 0;
        }
        int d = nums[1] - nums[0];
        int count = 0;
        int result = 0;
        for (int i = 2; i < n; ++i) {
            if (nums[i] - nums[i - 1] == d) {
                count++;
            } else {
                d = nums[i] - nums[i - 1];
                count = 0;
            }
            result += count;
        }
        return result;
    }
};
} // namespace lc413

class LC413Tests : public ::testing::Test {
protected:
    lc413::Solution1 solution1;
};

TEST_F(LC413Tests, case1) {
    vector<int> nums{1, 2, 3, 4};
    int expect = 3;
    int result = solution1.numberOfArithmeticSlices(nums);
    EXPECT_EQ(result, expect);
}

TEST_F(LC413Tests, case2) {
    vector<int> nums{1, 2, 3, 8, 9, 10};
    int expect = 2;
    int result = solution1.numberOfArithmeticSlices(nums);
    EXPECT_EQ(result, expect);
}