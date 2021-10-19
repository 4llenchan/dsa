#include <algorithm>
#include <gtest/gtest.h>
#include <numeric>
#include <unordered_map>
#include <vector>

#include "Common.h"

using namespace std;


namespace lc416 {
/**
 * https://leetcode-cn.com/problems/partition-equal-subset-sum/
 * 动态规划背包问题
 */
class Solution1 {
public:
    bool canPartition(vector<int> &nums) {
        int sum = (int)accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2) {
            return false;
        }
        int n = (int)nums.size();
        int target = sum / 2;
        int maxNum = *max_element(nums.begin(), nums.end());
        if (maxNum > target) {
            return false;
        }
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = true;
        }
        for (int i = 1; i <= n; ++i) {
             for (int j = nums[i - 1]; j <= target; ++j) {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
            }
        }
        return dp[n][target];
    }
};

class Solution2 {
public:
    bool canPartition(vector<int> &nums) {
        int n = (int)nums.size();
        if (n < 2) {
            return false;
        }
        int sum = (int)accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2) {
            return false;
        }
        int target = sum / 2;
        int maxNum = *max_element(nums.begin(), nums.end());
        if (maxNum > target) {
            return false;
        }
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; ++i) {
            for (int j = target; j >= nums[i - 1]; --j) {
                dp[j] = dp[j] || dp[j - nums[i - 1]];
            }
        }
        return dp[target];
    }
};
} // namespace lc416

class LC416Tests : public ::testing::Test {
protected:
    lc416::Solution1 solution1;
    lc416::Solution2 solution2;
};

TEST_F(LC416Tests, case1) {
    vector<int> nums{1, 5, 11, 5};
    bool expect = true;
    auto result1 = solution1.canPartition(nums);
    auto result2 = solution2.canPartition(nums);
    EXPECT_EQ(result1, expect);
    EXPECT_EQ(result2, expect);
}