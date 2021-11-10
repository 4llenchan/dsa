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
namespace lc495 {
/**
 * https://leetcode-cn.com/problems/teemo-attacking/
 */
class Solution1 {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int last = timeSeries[0];
        int total = duration;
        for (int i = 1; i < timeSeries.size(); ++i) {
            if (timeSeries[i] > last) {
                int gap = timeSeries[i] - last;
                if (gap < duration) {
                    total += gap;
                } else {
                    total += duration;
                }
            }
            last = timeSeries[i];
        }
        return total;
    }
};
} // namespace lc495

class LC495Tests : public ::testing::Test {
protected:
    lc495::Solution1 solution1;
};

TEST_F(LC495Tests, case1) {
    vector<int> timeSeries{1, 2};
    int duration = 2;
    int expect = 3;
    auto result = solution1.findPoisonedDuration(timeSeries, duration);
    EXPECT_EQ(expect, result);
}

TEST_F(LC495Tests, case2) {
    vector<int> timeSeries{1, 4};
    int duration = 2;
    int expect = 4;
    auto result = solution1.findPoisonedDuration(timeSeries, duration);
    EXPECT_EQ(expect, result);
}

TEST_F(LC495Tests, case3) {
    vector<int> timeSeries{1, 2, 3, 4, 5};
    int duration = 5;
    int expect = 9;
    auto result = solution1.findPoisonedDuration(timeSeries, duration);
    EXPECT_EQ(expect, result);
}