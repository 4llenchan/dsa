#include <gtest/gtest.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <numeric>

#include "Common.h"

using namespace std;

/**
 * https://leetcode-cn.com/problems/longest-word-in-dictionary-through-deleting/
 * 双指针遍历两个字符数组
 */
class Solution1 {
public:
    string findLongestWord(string s, vector<string> &dictionary) {
        string result;
        for (auto &str: dictionary) {
            int i = 0;
            int j = 0;
            while (i < str.size() && j < s.size()) {
                if (str[i] == s[j]) {
                    i++;
                }
                j++;
            }
            if (i == str.size()) {
                if (result.size() < str.size()) {
                    result = str;
                } else if (result.size() == str.size()) {
                    result = min(result, str);
                }
            }
        }
        return result;
    }
};

class LC524Tests : public ::testing::Test {
protected:
    Solution1 solution1;
};

TEST_F(LC524Tests, case1) {
    string s = "abpcplea";
    vector<string> dictionary{"ale", "apple", "monkey", "plea"};
    string expect = "apple";
    EXPECT_EQ(solution1.findLongestWord(s, dictionary), expect);
}

TEST_F(LC524Tests, case2) {
    string s = "abpcplea";
    vector<string> dictionary{"a","b","c"};
    string expect = "a";
    EXPECT_EQ(solution1.findLongestWord(s, dictionary), expect);
}