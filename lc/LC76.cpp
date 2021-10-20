#include <gtest/gtest.h>

#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <vector>

#include "Common.h"

using namespace std;

/**
 * https://leetcode-cn.com/problems/minimum-window-substring/
 * 双指针，滑动窗口
 */
class Solution1 {
public:
    string minWindow(string s, string t) {
        /* 题目限定输入均是英文字符，即ASCII表元素，用128数组即可记录t中字符的出现与否以及次数 */
        vector<int> counts(128, 0);
        vector<bool> flags(128, false);
        /* 统计t中出现了哪些字符 */
        for (char i : t) {
            flags[i] = true;
            counts[i]++;
        }

        int l = 0;     /* 窗口左端 */
        int minL = 0;  /* 最小窗口的左端，用于最后输出结果子串 */
        int count = 0; /* 用于记录窗口内已经匹配了t中的字符数量 */
        /* 记录过程中出现的最小值，使用一个比s长度大的值作为初始即可 */
        int min = (int)s.size() + 1;
        /* 滑动窗口先移动右端 */
        for (int r = 0; r < s.size(); ++r) {
            if (flags[s[r]]) {
                /* 先减1后如果还是大于或等于0，表示匹配了t中的一个字符 */
                if (--counts[s[r]] >= 0) {
                    count++;
                }
                /* 当窗口内已经全部匹配了t的字符，开始移动窗口左端以求当前的一个最小窗口 */
                while (count == t.size()) {
                    /* 当前窗口长度比已记录的窗口小 */
                    if (r - l + 1 < min) {
                        minL = l;
                        min = r - l + 1;
                    }
                    /*
                     * 移动左端，若值在t中，需要增加计数。
                     * counts变回正数后，代表该左端被移除后，窗口内已无法全部匹配t
                     */
                    if (flags[s[l]] && ++counts[s[l]] > 0) {
                        count--;
                    }
                    ++l;
                }
            }
        }
        return min > s.size() ? "" : s.substr(minL, min);
    }
};

class LC76Tests : public ::testing::Test {
protected:
    Solution1 solution1;
};

TEST_F(LC76Tests, case1) {
    string s = "ADOBECODEBANC";
    string t = "ABC";
    string expect = "BANC";
    EXPECT_EQ(solution1.minWindow(s, t), expect);
}