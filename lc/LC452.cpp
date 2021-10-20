#include <gtest/gtest.h>

#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <vector>

#include "Common.h"

using namespace std;

/**
 * https://leetcode-cn.com/problems/minimum-number-of-arrows-to-burst-balloons/
 */
class Solution {
public:
    int findMinArrowShots(vector<vector<int>> &points) {
        int n = static_cast<int>(points.size());
        if (n <= 1) {
            return n;
        }
        /* 根据end坐标排序 */
        sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b) {
            return a[1] < b[1];
        });
        int count = 1;
        /* 取排序后的第一个结束坐标作为起始 */
        int arrow = points[0][1];
        for (int i = 1; i < n; ++i) {
            /* 当前arrow已无法引爆 */
            if (points[i][0] > arrow) {
                arrow = points[i][1];
                ++count;
            }
        }
        return count;
    }
};

class LC452Tests : public ::testing::Test {
protected:
    Solution solution;
};

TEST_F(LC452Tests, case1) {
    vector<vector<int>> points{{10, 16},
                               {2, 8},
                               {1, 6},
                               {7, 12}};
    EXPECT_EQ(solution.findMinArrowShots(points), 2);
}

TEST_F(LC452Tests, case2) {
    vector<vector<int>> points{{1, 2},
                               {3, 4},
                               {5, 6},
                               {7, 8}};
    EXPECT_EQ(solution.findMinArrowShots(points), 4);
}

TEST_F(LC452Tests, case3) {
    vector<vector<int>> points{{1, 2}};
    EXPECT_EQ(solution.findMinArrowShots(points), 1);
}

TEST_F(LC452Tests, case4) {
    vector<vector<int>> points{{2, 3},
                               {2, 3}};
    EXPECT_EQ(solution.findMinArrowShots(points), 1);
}