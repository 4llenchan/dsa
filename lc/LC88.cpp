#include <gtest/gtest.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <numeric>

#include "Common.h"

using namespace std;

/**
 * https://leetcode-cn.com/problems/merge-sorted-array/
 * 双指针倒序遍历双数组
 */
class Solution1 {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        if (n == 0) {
            return;
        }
        if (m == 0) {
            nums1 = nums2;
            return;
        }
        int current = m + n - 1;
        int index1 = m - 1;
        int index2 = n - 1;
        while (index2 >= 0) {
            if (index1 < 0 || nums2[index2] > nums1[index1]) {
                nums1[current] = nums2[index2];
                index2--;
            } else {
                nums1[current] = nums1[index1];
                index1--;
            }
            current--;
        }
    }
};

class LC88Tests : public ::testing::Test {
protected:
    Solution1 solution1;
};

TEST_F(LC88Tests, case1) {
    vector<int> nums1{1, 2, 3, 0, 0, 0};
    int m = 3;
    vector<int> nums2{2, 5, 6};
    int n = 3;
    solution1.merge(nums1, m, nums2, n);
    vector<int> expect{1, 2, 2, 3, 5, 6};
    EXPECT_EQ(nums1, expect);
}

TEST_F(LC88Tests, case2) {
    vector<int> nums1{1};
    int m = 1;
    vector<int> nums2{};
    int n = 0;
    solution1.merge(nums1, m, nums2, n);
    vector<int> expect{1};
    EXPECT_EQ(nums1, expect);
}

TEST_F(LC88Tests, case3) {
    vector<int> nums1{0};
    int m = 0;
    vector<int> nums2{1};
    int n = 1;
    solution1.merge(nums1, m, nums2, n);
    vector<int> expect{1};
    EXPECT_EQ(nums1, expect);
}

TEST_F(LC88Tests, case4) {
    vector<int> nums1{2, 0};
    int m = 1;
    vector<int> nums2{1};
    int n = 1;
    solution1.merge(nums1, m, nums2, n);
    vector<int> expect{1, 2};
    EXPECT_EQ(nums1, expect);
}