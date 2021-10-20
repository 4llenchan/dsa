#include <gtest/gtest.h>

#include <algorithm>
#include <unordered_map>
#include <vector>

#include "Common.h"

using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>> &grid) {
        /* 利用原矩阵进行dp值的保存 */
        int m = grid.size(), n = grid[0].size();
        /* 初始化第一行 */
        for (int j = 1; j < n; j++) {
            grid[0][j] += grid[0][j - 1];
        }
        /* 初始化第一列 */
        for (int i = 1; i < m; i++) {
            grid[i][0] += grid[i - 1][0];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                grid[i][j] += max(grid[i][j - 1], grid[i - 1][j]);
            }
        }
        return grid[m - 1][n - 1];
    }
};

class OF47Tests : public ::testing::Test {
protected:
    Solution solution;
};

TEST_F(OF47Tests, normal) {
    vector<vector<int>> grid{
            {1, 3, 1},
            {1, 5, 1},
            {4, 2, 1}};
    EXPECT_EQ(solution.maxValue(grid), 12);
}