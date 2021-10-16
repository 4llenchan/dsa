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
namespace lc46 {
/**
 * https://leetcode-cn.com/problems/permutations/
 * 回溯法搜
 */
class Solution1 {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        int n = (int)nums.size();
        vector<vector<int>> result;
        if (n <= 1) {
            result.push_back(nums);
        } else {
            backtracking(nums, 0, result);
        }
        return result;
    }

private:
    void backtracking(vector<int> &nums, int level, vector<vector<int>> &result) {
        if (level == nums.size() - 1) {
            result.push_back(nums);
            return;
        }
        for (int i = level; i < nums.size(); ++i) {
            swap(nums[i], nums[level]);
            backtracking(nums, level + 1, result);
            swap(nums[level], nums[i]);
        }
    }
};
} // namespace lc46

class LC46Tests : public ::testing::Test {
protected:
    lc46::Solution1 solution1;
};

TEST_F(LC46Tests, case1) {
    vector<int> nums{1, 2, 3};
    vector<vector<int>> expects{{1, 2, 3},
                                {1, 3, 2},
                                {2, 1, 3},
                                {2, 3, 1},
                                {3, 1, 2},
                                {3, 2, 1}};
    auto results = solution1.permute(nums);
    EXPECT_EQ(expects.size(), results.size());
    for (const auto &expect : expects) {
        bool found = false;
        for (const auto &result : results) {
            if (expect == result) {
                found = true;
                break;
            }
        }
        EXPECT_TRUE(found);
    }
}