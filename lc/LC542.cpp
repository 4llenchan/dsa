#include <algorithm>
#include <gtest/gtest.h>
#include <numeric>
#include <unordered_map>
#include <vector>
#include <climits>

#include "Common.h"

using namespace std;


namespace lc542 {
/**
 * https://leetcode-cn.com/problems/01-matrix/
 * 动态规划
 */
class Solution1 {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        if (mat.empty() || mat[0].empty()) {
            return {};
        }
        int m = (int)mat.size();
        int n = (int)mat[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX - 1));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) {
                    dp[i][j] = 0;
                } else {
                    if (i > 0) {
                        dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j]);
                    }
                    if (j > 0) {
                        dp[i][j] = min(dp[i][j - 1] + 1, dp[i][j]);
                    }
                }
            }
        }
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (mat[i][j] == 1) {
                    if (i < m - 1) {
                        dp[i][j] = min(dp[i + 1][j] + 1, dp[i][j]);
                    }
                    if (j < n - 1) {
                        dp[i][j] = min(dp[i][j + 1] + 1, dp[i][j]);
                    }
                }
            }
        }
        return dp;
    }
};
} // namespace lc542

class LC542Tests : public ::testing::Test {
protected:
    lc542::Solution1 solution1;
};

TEST_F(LC542Tests, case1) {
    vector<vector<int>> mat{{0,0,0},{0,1,0},{0,0,0}};
    vector<vector<int>> expect{{0,0,0},{0,1,0},{0,0,0}};
    auto result = solution1.updateMatrix(mat);
    EXPECT_EQ(expect, result);
}