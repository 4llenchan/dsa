#include <gtest/gtest.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <numeric>

#include "Common.h"

using namespace std;

/**
 * https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/
 * 双指针遍历（前后）
 */
class Solution1 {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int left = 0;
        int right = (int)numbers.size() - 1;
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) {
                break;
            }
            if (sum > target) {
                right--;
            } else {
                left++;
            }
        }
        return vector<int>{left + 1, right + 1};
    }
};

class LC167Tests : public ::testing::Test {
protected:
    Solution1 solution1;
};

TEST_F(LC167Tests, case1) {
    vector<int> numbers{2, 7, 11, 15};
    vector<int> expect{1, 2};
    EXPECT_EQ(solution1.twoSum(numbers, 9), expect);
}

TEST_F(LC167Tests, case2) {
    vector<int> numbers{2, 3, 4};
    vector<int> expect{1, 3};
    EXPECT_EQ(solution1.twoSum(numbers, 6), expect);
}

TEST_F(LC167Tests, case3) {
    vector<int> numbers{-1, 0};
    vector<int> expect{1, 2};
    EXPECT_EQ(solution1.twoSum(numbers, -1), expect);
}