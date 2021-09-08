#include <gtest/gtest.h>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        /* f(i) = max(f(i-1) + nums[i], nums[i]) */
        int dp = nums[0];
        int max = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (dp > 0) {
                dp += nums[i];
            } else {
                dp = nums[i];
            }
            if (dp > max) {
                max = dp;
            }
        }
        return max;
    }
};

class OF42Tests : public ::testing::Test {
protected:
    Solution solution;
};

TEST_F(OF42Tests, normal) {
    vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    EXPECT_EQ(6, solution.maxSubArray(nums));
}