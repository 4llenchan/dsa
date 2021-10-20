#include <gtest/gtest.h>

#include <algorithm>
#include <numeric>
#include <stack>
#include <unordered_map>
#include <vector>

#include "Common.h"

using namespace std;

namespace lc695 {
/**
 * https://leetcode-cn.com/problems/max-area-of-island/
 * DFS搜索+递归
 */
class Solution1 {
public:
    int maxAreaOfIsland(vector<vector<int>> &grid) {
        m_ = (int)grid.size();
        n_ = (int)grid[0].size();
        int result = 0;
        for (int i = 0; i < m_; ++i) {
            for (int j = 0; j < n_; ++j) {
                result = max(result, dfs(grid, i, j));
            }
        }
        return result;
    }

private:
    int m_ = 0;
    int n_ = 0;
    const vector<int> di_{0, 0, 1, -1};
    const vector<int> dj_{1, -1, 0, 0};

private:
    int dfs(vector<vector<int>> &grid, int i, int j) {
        if (i < 0 || j < 0 || i == m_ || j == n_ || grid[i][j] == 0) {
            return 0;
        }
        /* 遍历过的点置为0，防止重复遍历 */
        grid[i][j] = 0;
        int result = 1;
        /* 遍历当前节点的上下左右四个节点 */
        for (int k = 0; k < 4; ++k) {
            int nextI = i + di_[k];
            int nextJ = j + dj_[k];
            result += dfs(grid, nextI, nextJ);
        }
        return result;
    }
};

/**
 * https://leetcode-cn.com/problems/max-area-of-island/
 * DFS搜索+栈
 */
class Solution2 {
public:
    int maxAreaOfIsland(vector<vector<int>> &grid) {
        int m = (int)grid.size();
        int n = (int)grid[0].size();

        stack<pair<int, int>> stack;
        vector<pair<int, int>> d{{0, 1},
                                 {0, -1},
                                 {1, 0},
                                 {-1, 0}};

        auto adder = [](const pair<int, int> &p1, const pair<int, int> &p2) {
            return make_pair(p1.first + p2.first, p1.second + p2.second);
        };

        int result = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                stack.push(make_pair(i, j));
                int cur = 0;
                while (!stack.empty()) {
                    auto pair = stack.top();
                    int curI = pair.first;
                    int curJ = pair.second;
                    stack.pop();
                    if (curI < 0 || curJ < 0 || curI == m || curJ == n || grid[curI][curJ] == 0) {
                        continue;
                    }
                    grid[curI][curJ] = 0;
                    cur++;
                    for (auto next : d) {
                        stack.push(adder(next, pair));
                    }
                }
                result = max(result, cur);
            }
        }
        return result;
    }
};
} // namespace lc695

class LC695Tests : public ::testing::Test {
protected:
    lc695::Solution1 solution1;
    lc695::Solution2 solution2;
};

TEST_F(LC695Tests, case1) {
    vector<vector<int>> grid1{
            {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
            {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
            {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
    vector<vector<int>> grid2;
    grid2.assign(grid1.begin(), grid1.end());
    int expect = 6;
    int result1 = solution1.maxAreaOfIsland(grid1);
    int result2 = solution2.maxAreaOfIsland(grid2);
    EXPECT_EQ(result1, expect);
    EXPECT_EQ(result2, expect);
}