#include <gtest/gtest.h>

#include <algorithm>
#include <deque>
#include <numeric>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

#include "Common.h"

using namespace std;
namespace lc77 {
/**
 * https://leetcode-cn.com/problems/combinations/
 * 深度遍历+回溯
 */
class Solution1 {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> combine(k);
        int count = 0; /* 表示当前的排列中的元素个数 */
        backtracking(result, combine, count, 1, n, k);
        return result;
    }

private:
    void backtracking(vector<vector<int>> &result, vector<int> &combine,
                      int &count, int pos, int n, int k) {
        if (count == k) {
            result.push_back(combine);
            return;
        }
        for (int i = pos; i <= n; ++i) {
            /* 将当前i指示的值加入到排列后，再进行递归 */
            combine[count++] = i;
            backtracking(result, combine, count, i + 1, n, k);
            count--;
        }
    }
};
} // namespace lc77

class LC77Tests : public ::testing::Test {
protected:
    lc77::Solution1 solution1;
};

TEST_F(LC77Tests, case1) {
    int n = 4;
    int k = 2;
    vector<vector<int>> expect{{2, 4},
                               {3, 4},
                               {2, 3},
                               {1, 2},
                               {1, 3},
                               {1, 4}};
    auto result = solution1.combine(n, k);
    EXPECT_EQ(expect.size(), result.size());
    for (const auto &e : expect) {
        bool found = false;
        for (const auto &r : result) {
            if (e == r) {
                found = true;
                break;
            }
        }
        EXPECT_TRUE(found);
    }
}