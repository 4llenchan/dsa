#include <gtest/gtest.h>

#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <vector>

#include "Common.h"

using namespace std;


namespace lc221 {
/**
 * https://leetcode-cn.com/problems/maximal-square/
 * 动态规划
 */
class Solution1 {
public:
    int maximalSquare(vector<vector<char>> &matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        int m = (int)matrix.size();
        int n = (int)matrix[0].size();
        /* 多增加了一行一列，减少主体程序的边界条件判断，且不影响最终结果 */
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int maxSlide = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (matrix[i - 1][j - 1] == '1') {
                    dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
                } else {
                    dp[i][j] = 0;
                }
                maxSlide = max(maxSlide, dp[i][j]);
            }
        }
        return maxSlide * maxSlide;
    }
};
} // namespace lc221

class LC221Tests : public ::testing::Test {
protected:
    lc221::Solution1 solution1;
};

TEST_F(LC221Tests, case1) {
    vector<vector<char>> matrix{{'1', '0', '1', '0', '0'},
                                {'1', '0', '1', '1', '1'},
                                {'1', '1', '1', '1', '1'},
                                {'1', '0', '0', '1', '0'}};
    int expect = 4;
    int result = solution1.maximalSquare(matrix);
    EXPECT_EQ(expect, result);
}