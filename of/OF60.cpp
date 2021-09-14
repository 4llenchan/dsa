#include <gtest/gtest.h>
#include <algorithm>
#include <vector>
#include <unordered_map>

#include "Common.h"

using namespace std;

class Solution {
public:
    vector<double> dicesProbability(int n) {
        vector<double> result(5 * n + 1);
        return result;
    }
};

class OF60Tests : public ::testing::Test {
protected:
    Solution solution;
};

TEST_F(OF60Tests, normal) {
    vector<double> expect{0.02778,0.05556,0.08333,0.11111,0.13889,0.16667,0.13889,0.11111,0.08333,0.05556,0.02778};
    EXPECT_EQ(solution.dicesProbability(2), expect);
}