#include <gtest/gtest.h>

#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <vector>

#include "Common.h"

using namespace std;

/**
 * https://leetcode-cn.com/problems/zigzag-conversion/
 */
class Solution1 {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) {
            return s;
        }
        int loop = 2 * numRows - 2;
        vector<string> results(numRows, "");
        for (int i = 0; i < s.size(); ++i) {
            int b = i % loop;
            int c = b / (numRows - 1);
            int d = b % (numRows - 1);
            if (c == 1) {
                results[numRows - 1 - d] += s[i];
            } else {
                results[d] += s[i];
            }
        }
        string result;
        for (int i = 0; i < numRows; ++i) {
            result += results[i];
        }
        return result;
    }
};

/**
 * 与solution1相比，运行时间相同，内存占用更少，除去结果，没有使用额外的空间，空间复杂度更低
 */
class Solution2 {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) {
            return s;
        }
        /*
         * 按行遍历，循环的以Z字的第一竖和斜线作为循环条件，如此存在一个重复的规律。
         * 即循环的数量为2n-2
         */
        int n = (int)s.size();
        int loop = 2 * numRows - 2;
        string result;

        for (int i = 0; i < numRows; ++i) {
            /* j + i < n的条件限制了Z的第一竖是有效的 */
            for (int j = 0; j + i < n; j += loop) {
                result += s[j + i];
                /* (j + loop - i) < n条件限制了Z的斜线是有效的 */
                if (i != 0 && i != (numRows - 1) && (j + loop - i) < n) {
                    result += s[j + loop - i];
                }
            }
        }
        return result;
    }
};

class LC6Tests : public ::testing::Test {
protected:
    Solution1 solution1;
    Solution2 solution2;
};

TEST_F(LC6Tests, case1) {
    string s = "PAYPALISHIRING";
    EXPECT_EQ(solution1.convert(s, 3), "PAHNAPLSIIGYIR");
    EXPECT_EQ(solution2.convert(s, 3), "PAHNAPLSIIGYIR");
}