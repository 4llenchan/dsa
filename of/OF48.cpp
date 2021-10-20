#include <gtest/gtest.h>

#include <algorithm>
#include <unordered_map>
#include <vector>

#include "Common.h"

using namespace std;

/**
 * 请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。
 * 动态规划
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        /* 题目要求是可见字符范畴，即ASCII128，用128长度数组表示字符出现在s中的位置 */
        /* 初始化为-1，表示尚未出现过 */
        vector<int> occurence(128, -1);
        int n = (int)s.size();
        int dp = 0;
        int start = 0;
        int result = 0;
        for (int i = 0; i < n; ++i) {
            int tmp = occurence[(int)s[i]];
            /*
             * 1. tmp为-1，即字符未出现过，长度+1
             * 2. tmp < start，表示字符在前面出现的位置已经超出了以s[i - 1]结尾的
             *    最长子串的左边，所以长度继续+1即可
             */
            if (tmp == -1 || tmp < start) {
                dp += 1;
            } else {
                /*
                 * 出现重复字符，长度更新为上一次出现位置的下一个位置到当前字符
                 * 同时记录新的OK起始位置
                 */
                dp = i - tmp;
                start = tmp;
            }
            /* 过程中记录最大值 */
            result = max(result, dp);
            /* 更新字符出现位置 */
            occurence[(int)s[i]] = i;
        }
        return result;
    }
};

class OF48Tests : public ::testing::Test {
protected:
    Solution solution;
};

TEST_F(OF48Tests, normal) {
    EXPECT_EQ(solution.lengthOfLongestSubstring("abcabcbb"), 3);
    EXPECT_EQ(solution.lengthOfLongestSubstring("bbbbb"), 1);
    EXPECT_EQ(solution.lengthOfLongestSubstring("pwwkew"), 3);
    EXPECT_EQ(solution.lengthOfLongestSubstring("abba"), 2);
}