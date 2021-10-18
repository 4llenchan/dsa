#include <algorithm>
#include <deque>
#include <gtest/gtest.h>
#include <numeric>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

#include "Common.h"

using namespace std;
namespace lc300 {
/**
 * https://leetcode-cn.com/problems/longest-increasing-subsequence/
 * 动态规划
 */
class Solution1 {
public:
    int lengthOfLIS(vector<int> &nums) {
        int n = (int)nums.size();
        if (n <= 1) {
            return n;
        }

        vector<int> dp;
        dp.push_back(nums[0]);
        for (int i = 1; i < n; ++i) {
            if (dp.back() < nums[i]) {
                dp.push_back(nums[i]);
            } else {
//                int l = 0;
//                int r = (int)dp.size() - 1;
//                while (l <= r) {
//                    int mid = (l + r) / 2;
//                    if (dp[mid] < nums[i]) {
//                        l = mid + 1;
//                    } else {
//                        r = mid - 1;
//                    }
//                }
//                dp[l] = nums[i];
                /* 找到第一个比nums[i]大的元素，内部使用二分查找 */
                auto itr = lower_bound(dp.begin(), dp.end(), nums[i]);
                *itr = nums[i];
            }
        }
        return (int)dp.size();
    }
};

class Solution2 {
public:
    int lengthOfLIS(vector<int> &nums) {
        int n = (int)nums.size();
        if (n <= 1) {
            return n;
        }
        vector<int> dp(n, 1);
        int result = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            result = max(result, dp[i]);
        }
        return result;
    }
};
} // namespace lc300

class LC300Tests : public ::testing::Test {
protected:
    lc300::Solution1 solution1;
    lc300::Solution2 solution2;
};

TEST_F(LC300Tests, case1) {
    vector<int> nums{10, 9, 2, 5, 3, 7, 101, 18};
    int expect = 4;
    auto result1 = solution1.lengthOfLIS(nums);
    auto result2 = solution2.lengthOfLIS(nums);
    EXPECT_EQ(expect, result1);
    EXPECT_EQ(expect, result2);
}