#include <gtest/gtest.h>
#include <algorithm>
#include <vector>
#include <unordered_map>

#include "Common.h"

using namespace std;

/**
 * https://leetcode-cn.com/problems/assign-cookies/
 * 贪心算法
 */
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int gIndex = 0;
        int sIndex = 0;
        while (gIndex < g.size() && sIndex < s.size()) {
            if (g[gIndex] <= s[sIndex]) {
                ++gIndex;
            }
            ++sIndex;
        }
        return gIndex;
    }
};

class LC455Tests : public ::testing::Test {
protected:
    Solution solution;
};

TEST_F(LC455Tests, normal) {
    vector<int> g{1, 2, 3};
    vector<int> s{1, 1};
    EXPECT_EQ(solution.findContentChildren(g, s), 1);
}

TEST_F(LC455Tests, normal1) {
    vector<int> g{1, 2};
    vector<int> s{1, 2, 3};
    EXPECT_EQ(solution.findContentChildren(g, s), 2);
}