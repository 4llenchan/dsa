#include <gtest/gtest.h>

#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <vector>

#include "Common.h"

using namespace std;

namespace lc152 {
/**
 * https://leetcode-cn.com/problems/maximum-product-subarray/
 * 动态规划，空间复杂度为2N
 */
class Solution1 {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> max(nums);
        vector<int> min(nums);
        for (int i = 1; i < nums.size(); ++i) {
            max[i] = std::max(nums[i], std::max(max[i - 1] * nums[i], min[i - 1] * nums[i]));
            min[i] = std::min(nums[i], std::min(max[i - 1] * nums[i], min[i - 1] * nums[i]));
        }
        return *max_element(max.begin(), max.end());
    }
};

/**
 * 空间复杂度降低常数级别
 */
class Solution2 {
public:
    int maxProduct(vector<int>& nums) {
        int dp_max = nums[0];
        int dp_min = nums[0];
        int result = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int cur_max = std::max(nums[i], std::max(dp_max * nums[i], dp_min * nums[i]));
            dp_min = std::min(nums[i], std::min(dp_max * nums[i], dp_min * nums[i]));
            dp_max = cur_max;
            result = std::max(result, cur_max);
        }
        return result;
    }
};
} // namespace lc152

class LC152Tests : public ::testing::Test {
protected:
    lc152::Solution1 solution1;
    lc152::Solution2 solution2;
};

TEST_F(LC152Tests, case1) {
    vector<int> nums{2, 3, -2, 4};
    int expect = 6;
    auto result1 = solution1.maxProduct(nums);
    auto result2 = solution2.maxProduct(nums);
    EXPECT_EQ(expect, result1);
    EXPECT_EQ(expect, result2);
}