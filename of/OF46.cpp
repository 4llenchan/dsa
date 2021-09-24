#include <gtest/gtest.h>
#include <vector>

using namespace std;

class Solution {
public:
    int translateNum(int num) {
        vector<int> nums;
        while (num != 0) {
            nums.insert(nums.begin(), num % 10);
            num /= 10;
        }
        int n = (int)nums.size();
        int a = 1;
        int b = 1;
        for (int i = 1; i < n; ++i) {
            int tmp = nums[i - 1] * 10 + nums[i];
            int c;
            if (tmp <= 25 && tmp >= 10) {
                c = a + b;
            } else {
                c = b;
            }
            a = b;
            b = c;
        }
        return b;
    }
};

class OF46Tests : public ::testing::Test {
protected:
    Solution solution;
};

TEST_F(OF46Tests, normal) {
    EXPECT_EQ(5, solution.translateNum(12258));
    EXPECT_EQ(9, solution.translateNum(123123));
}