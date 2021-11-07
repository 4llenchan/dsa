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
namespace lc598 {
/**
 * https://leetcode-cn.com/problems/range-addition-ii/
 */
class Solution1 {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int min_m = m;
        int min_n = n;
        for (auto& op : ops) {
            min_m = min(op[0], min_m);
            min_n = min(op[1], min_n);
        }
        return min_m * min_n;
    }
};
} // namespace lc598

class LC598Tests : public ::testing::Test {
protected:
    lc598::Solution1 solution1;
};

TEST_F(LC598Tests, case1) {
    int m = 3;
    int n = 3;
    vector<vector<int>> operations{{2, 2}, {3, 3}};
    int expect = 4;
    auto result = solution1.maxCount(m, n, operations);
    EXPECT_EQ(expect, result);
}