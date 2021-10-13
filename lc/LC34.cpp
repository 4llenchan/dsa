#include <gtest/gtest.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <numeric>

#include "Common.h"

using namespace std;

/**
 * https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/
 * 二分查找
 */
class Solution1 {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int lower = -1;
        int upper = -1;
        if (!nums.empty()) {
            lower = lowerBound(nums, target);
            upper = upperBound(nums, target);
        }
        return vector<int>{lower, upper};
    }

    int lowerBound(vector<int> &nums, int target) {
        int left = 0;
        int right = (int) nums.size() - 1;
        int result = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                result = mid;
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }

    int upperBound(vector<int> &nums, int target) {
        int left = 0;
        int right = (int) nums.size() - 1;
        int result = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                result = mid;
                left = mid + 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }
};

class LC34Tests : public ::testing::Test {
protected:
    Solution1 solution1;
};

TEST_F(LC34Tests, case1) {
    vector<int> nums{5, 7, 7, 8, 8, 10};
    int target = 8;
    vector<int> expect{3, 4};
    auto result = solution1.searchRange(nums, target);
    EXPECT_EQ(expect, result);
}

TEST_F(LC34Tests, case2) {
    vector<int> nums{5, 7, 7, 8, 8, 10};
    int target = 6;
    vector<int> expect{-1, -1};
    auto result = solution1.searchRange(nums, target);
    EXPECT_EQ(expect, result);
}

TEST_F(LC34Tests, case3) {
    vector<int> nums{};
    int target = 0;
    vector<int> expect{-1, -1};
    auto result = solution1.searchRange(nums, target);
    EXPECT_EQ(expect, result);
}