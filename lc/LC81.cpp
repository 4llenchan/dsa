#include <algorithm>
#include <gtest/gtest.h>
#include <numeric>
#include <unordered_map>
#include <vector>

#include "Common.h"

using namespace std;

namespace lc81 {
/**
 * https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii/
 * 二分查找，需要注意特殊的边界条件
 */
class Solution1 {
public:
    bool search(vector<int> &nums, int target) {
        int n = (int) nums.size();
        int l = 0;
        int r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) {
                return true;
            }
            /* mid和l和r都相等，无法判断哪边是递增区间，两边都回缩一位再来判断 */
            if (nums[mid] == nums[l] && nums[mid] == nums[r]) {
                l++;
                r--;
            } else if (nums[mid] >= nums[l]) {
                /* 这里不能和nums[0]比较，因为上面if的情况，可能会出现相等 */
                /* [l, mid)是递增序列 */
                if (nums[l] <= target && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else { /* mid右侧是递增序列 */
                if (nums[mid] < target && target <= nums[r]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return false;
    }
};
} // namespace lc81

class LC81Tests : public ::testing::Test {
protected:
    lc81::Solution1 solution1;
};

TEST_F(LC81Tests, case1) {
    vector<int> nums{2, 5, 6, 0, 0, 1, 2};
    int target = 0;
    bool expect = true;
    EXPECT_EQ(solution1.search(nums, target), expect);
}

TEST_F(LC81Tests, case2) {
    vector<int> nums{1, 0, 1, 1, 1};
    int target = 0;
    bool expect = true;
    EXPECT_EQ(solution1.search(nums, target), expect);
}

TEST_F(LC81Tests, case3) {
    vector<int> nums{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1};
    int target = 2;
    bool expect = true;
    EXPECT_EQ(solution1.search(nums, target), expect);
}

TEST_F(LC81Tests, case4) {
    vector<int> nums{3, 1};
    int target = 1;
    bool expect = true;
    EXPECT_EQ(solution1.search(nums, target), expect);
}