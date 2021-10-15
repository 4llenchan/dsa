#include <algorithm>
#include <gtest/gtest.h>
#include <numeric>
#include <unordered_map>
#include <vector>

#include "Common.h"

using namespace std;

namespace lc215 {
/**
 * https://leetcode-cn.com/problems/kth-largest-element-in-an-array/
 *
 */
class Solution1 {
public:
    int findKthLargest(vector<int> &nums, int k) {
        int n = (int)nums.size();
        if (n == 1) {
            return nums[0];
        }
        int l = 0;
        int r = n - 1;
        while (l < r) {
            int mid = quickSearch(nums, l, r);
            if (mid == (k - 1)) {
                return nums[mid];
            } else if (mid > (k - 1)) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return nums[r];
    }

    int quickSearch(vector<int> &nums, int left, int right) {
        int key = nums[right];
        int start = left;
        int end = right;
        while (start < end) {
            while (nums[start] > key && start < end) {
                start++;
            }
            nums[end] = nums[start];
            while (nums[end] <= key && start < end) {
                end--;
            }
            nums[start] = nums[end];
        }
        nums[end] = key;
        return start;
    }
};
} // namespace lc215

class LC215Tests : public ::testing::Test {
protected:
    lc215::Solution1 solution1;
};

TEST_F(LC215Tests, case1) {
    vector<int> nums{3, 2, 1, 5, 6, 4};
    int k = 2;
    int expect = 5;
    EXPECT_EQ(solution1.findKthLargest(nums, k), expect);
}

TEST_F(LC215Tests, case2) {
    vector<int> nums{3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k = 4;
    int expect = 4;
    EXPECT_EQ(solution1.findKthLargest(nums, k), expect);
}
