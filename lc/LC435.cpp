#include <gtest/gtest.h>

#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <vector>

#include "Common.h"

using namespace std;

/**
 * https://leetcode-cn.com/problems/non-overlapping-intervals/
 * 贪心算法实现
 */
class Solution1 {
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals) {
        int n = (int)intervals.size();
        if (n <= 1) {
            return 0;
        }
        /* 根据右端点值进行排序 */
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[1] < b[1];
        });
        int count = 0;
        int right = intervals[0][1];
        for (int i = 1; i < n; ++i) {
            if (intervals[i][0] < right) {
                count++;
            } else {
                right = intervals[i][1];
            }
        }
        return count;
    }
};

class LC435Tests : public ::testing::Test {
protected:
    Solution1 solution1;
};

TEST_F(LC435Tests, case1) {
    vector<vector<int>> intervals{{1, 2},
                                  {2, 3},
                                  {3, 4},
                                  {1, 3}};
    EXPECT_EQ(solution1.eraseOverlapIntervals(intervals), 1);
}

TEST_F(LC435Tests, case2) {
    vector<vector<int>> intervals{{1, 2},
                                  {1, 2},
                                  {1, 2}};
    EXPECT_EQ(solution1.eraseOverlapIntervals(intervals), 2);
}

TEST_F(LC435Tests, case3) {
    vector<vector<int>> intervals{{1, 2},
                                  {2, 3}};
    EXPECT_EQ(solution1.eraseOverlapIntervals(intervals), 0);
}