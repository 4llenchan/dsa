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
namespace lc520 {
/**
 * https://leetcode-cn.com/problems/detect-capital/
 */
class Solution1 {
public:
    bool detectCapitalUse(string word) {
        bool isCapital = isUpperCase(word[0]);
        for (int i = 1; i < word.length(); ++i) {
            if (sameCase(word[i], word[i - 1]) || (i == 1 && isCapital)) {
                continue;
            } else {
                return false;
            }
        }
        return true;
    }

    bool sameCase(char a, char b) {
        return isUpperCase(a) == isUpperCase(b);
    }

    inline bool isUpperCase(char c) {
        return ('A' <= c && c <= 'Z');
    }
};
} // namespace lc520

class LC520Tests : public ::testing::Test {
protected:
    lc520::Solution1 solution1;
};

TEST_F(LC520Tests, case1) {
    string word = "FlaG";
    bool expect = false;
    auto result = solution1.detectCapitalUse(word);
    EXPECT_EQ(expect, result);
}

TEST_F(LC520Tests, case2) {
    string word = "USA";
    bool expect = true;
    auto result = solution1.detectCapitalUse(word);
    EXPECT_EQ(expect, result);
}