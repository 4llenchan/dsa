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
namespace lc547 {
/**
 * https://leetcode-cn.com/problems/number-of-provinces/
 * 广度优先遍历，使用queue（用stack来实现就是深度优先）
 */
class Solution1 {
public:
    int findCircleNum(vector<vector<int>> &isConnected) {
        int n = (int)isConnected.size();
        int count = 0;
        vector<bool> visited(n, false);
        queue<int> queue;
        for (int i = 0; i < n; ++i) {
            if (visited[i]) {
                continue;
            }
            queue.push(i);
            while (!queue.empty()) {
                int cur = queue.front();
                queue.pop();
                visited[cur] = true;
                for (int j = 0; j < n; ++j) {
                    if (isConnected[cur][j] && !visited[j]) {
                        queue.push(j);
                    }
                }
            }
            count++;
        }
        return count;
    }
};

/**
 * https://leetcode-cn.com/problems/number-of-provinces/
 * TODO: 并查集实现连通分量查找
 */
class Solution2 {
public:
    int findCircleNum(vector<vector<int>> &isConnected) {
        return 0;
    }
};
} // namespace lc547

class LC547Tests : public ::testing::Test {
protected:
    lc547::Solution1 solution1;
};

TEST_F(LC547Tests, case1) {
    vector<vector<int>> isConnected{{1, 1, 0},
                                    {1, 1, 0},
                                    {0, 0, 1}};
    int expect = 2;
    int result = solution1.findCircleNum(isConnected);
    EXPECT_EQ(expect, result);
}

TEST_F(LC547Tests, case2) {
    vector<vector<int>> isConnected{{1, 0, 0, 1},
                                    {0, 1, 1, 0},
                                    {0, 1, 1, 1},
                                    {1, 0, 1, 1}};
    int expect = 1;
    int result = solution1.findCircleNum(isConnected);
    EXPECT_EQ(expect, result);
}