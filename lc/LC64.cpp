#include <algorithm>
#include <gtest/gtest.h>
#include <numeric>
#include <unordered_map>
#include <vector>

#include "Common.h"

using namespace std;


namespace lc64 {
/**
 * https://leetcode-cn.com/problems/minimum-path-sum/
 * 动态规划查找路径最小
 */
class Solution1 {
public:
    int minPathSum(vector<vector<int>> &grid) {
        int m = (int)grid.size();
        if (m == 0) {
            return 0;
        }
        int n = (int)grid[0].size();
        if (n == 0) {
            return 0;
        }
        for (int i = 1; i < m; ++i) {
            grid[i][0] += grid[i - 1][0];
        }
        for (int j = 1; j < n; ++j) {
            grid[0][j] += grid[0][j - 1];
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        return grid[m - 1][n - 1];
    }
};
} // namespace lc64

class LC64Tests : public ::testing::Test {
protected:
    lc64::Solution1 solution1;
};

TEST_F(LC64Tests, case1) {
    vector<vector<int>> grid{{1, 3, 1},
                             {1, 5, 1},
                             {4, 2, 1}};
    int expect = 7;
    int result = solution1.minPathSum(grid);
    EXPECT_EQ(result, expect);
}