#include <gtest/gtest.h>

#include <algorithm>
#include <climits>
#include <deque>
#include <list>
#include <numeric>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

#include "Common.h"

using namespace std;
namespace lc268 {
/**
 * https://leetcode-cn.com/problems/missing-number/
 */
class Solution1 {
public:
    int missingNumber(vector<int>& nums) {
        int missing = 0;
        for (int i = 0; i < nums.size(); ++i) {
            while (true) {
                if (nums[i] == 0) {
                    missing = i + 1;
                    break;
                } else {
                    int tmp = nums[i] - 1;
                    if (i != tmp) {
                        swap(nums[i], nums[tmp]);
                    } else {
                        break;
                    }
                }
            }
        }
        return missing;
    }
};

class Solution2 {
public:
    int missingNumber(vector<int>& nums) {
        int result = (int)nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            result += (i - nums[i]);
        }
        return result;
    }
};
} // namespace lc268

class LC268Tests : public ::testing::Test {
protected:
    lc268::Solution1 solution1;
    lc268::Solution2 solution2;
};

TEST_F(LC268Tests, case1) {
    vector<int> nums{9, 6, 4, 2, 3, 5, 7, 0, 1};
    const int expect = 8;
    auto result2 = solution2.missingNumber(nums);
    auto result = solution1.missingNumber(nums);
    EXPECT_EQ(expect, result);
    EXPECT_EQ(expect, result2);
}

TEST_F(LC268Tests, case2) {
    vector<int> nums{0, 1};
    const int expect = 2;
    auto result2 = solution2.missingNumber(nums);
    auto result = solution1.missingNumber(nums);
    EXPECT_EQ(expect, result);
    EXPECT_EQ(expect, result2);
}

TEST_F(LC268Tests, case3) {
    vector<int> nums{0};
    const int expect = 1;
    auto result2 = solution2.missingNumber(nums);
    auto result = solution1.missingNumber(nums);
    EXPECT_EQ(expect, result);
    EXPECT_EQ(expect, result2);
}

TEST_F(LC268Tests, case4) {
    vector<int> nums{1};
    const int expect = 0;
    auto result2 = solution2.missingNumber(nums);
    auto result = solution1.missingNumber(nums);
    EXPECT_EQ(expect, result);
    EXPECT_EQ(expect, result2);
}

TEST_F(LC268Tests, case5) {
    vector<int> nums{2, 0};
    const int expect = 1;
    auto result2 = solution2.missingNumber(nums);
    auto result = solution1.missingNumber(nums);
    EXPECT_EQ(expect, result);
    EXPECT_EQ(expect, result2);
}