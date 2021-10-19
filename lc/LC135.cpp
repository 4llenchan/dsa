#include <gtest/gtest.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <numeric>

#include "Common.h"

using namespace std;

/*
 * https://leetcode-cn.com/problems/candy/
 * 两次遍历的贪心算法
 */
class Solution {
public:
    int candy(vector<int> &ratings) {
        int size = ratings.size();
        if (size < 2) {
            return size;
        }
        vector<int> candies(size, 1);
        for (int i = 1; i < size; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }
        int right = candies[size - 1];
        int count = right;
        for (int i = size - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                /* 因为有前面一次的遍历，这里需要取max，才能保证前一轮遍历的结果仍然正确 */
                right = max(candies[i], right + 1);
            } else {
                right = candies[i];
            }
            count += right;
        }
        return count;
    }
};

class LC135Tests : public ::testing::Test {
protected:
    Solution solution;
};

TEST_F(LC135Tests, case1) {
    vector<int> ratings{1, 0, 2};
    EXPECT_EQ(solution.candy(ratings), 5);
}

TEST_F(LC135Tests, case2) {
    vector<int> ratings{1, 2, 2};
    EXPECT_EQ(solution.candy(ratings), 4);
}

TEST_F(LC135Tests, case3) {
    vector<int> ratings{1};
    EXPECT_EQ(solution.candy(ratings), 1);
}