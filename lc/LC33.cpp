#include <gtest/gtest.h>

#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <vector>

#include "Common.h"

using namespace std;

/**
 * https://leetcode-cn.com/problems/search-in-rotated-sorted-array/
 * 二分查找旋转不重复数组
 */
class Solution1 {
public:
    int search(vector<int> &nums, int target) {
        int n = (int)nums.size();
        if (n == 1) {
            return nums[0] == target ? 0 : -1;
        }
        int l = 0;
        int r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            /* [l, mid-1)区间为递增 */
            if (nums[0] <= nums[mid]) {
                if (nums[0] <= target && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                /* (mid+1, r]区间为递增 */
                if (nums[mid] < target && target <= nums[n - 1]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};

class LC33Tests : public ::testing::Test {
protected:
    Solution1 solution1;
};

TEST_F(LC33Tests, case1) {
    vector<int> nums{4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    int expect = 4;
    auto result = solution1.search(nums, target);
    EXPECT_EQ(result, expect);
}