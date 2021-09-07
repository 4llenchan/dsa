#include <gtest/gtest.h>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = (int)s.length();
        int m = (int)p.length();
        auto matches = [&](int i, int j) {
            if (i == 0) {
                return false;
            }
            if (p[j - 1] == '.') {
                return true;
            }
            return s[i - 1] == p[j - 1];
        };

        vector<vector<int>> f(n + 1, vector<int>(m + 1));
        f[0][0] = 1;
        /* i从0开始，是考虑s为空的情况 */
        for (int i = 0; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (p[j - 1] == '*') {
                    f[i][j] |= f[i][j - 2];
                    if (matches(i, j-1)) {
                        f[i][j] |= f[i - 1][j];
                    }
                } else {
                    if (matches(i, j)) {
                        f[i][j] |= f[i - 1][j - 1];
                    }
                }
            }
        }
        return f[n][m] == 1;
    }
};

struct LC10TestCase {
    string src;
    string pattern;
    bool match;
};

class LC10Tests : public ::testing::TestWithParam<LC10TestCase> {
protected:
    Solution solution;
};

TEST_P(LC10Tests, normal) {
    LC10TestCase tc = GetParam();
    EXPECT_EQ(tc.match, solution.isMatch(tc.src, tc.pattern));
}

INSTANTIATE_TEST_SUITE_P(cases, LC10Tests,
                         ::testing::Values(
                                 LC10TestCase{"aab", "c*a*b", true},
                                 LC10TestCase{"ab", ".*", true},
                                 LC10TestCase{"", "a*b*", true},
                                 LC10TestCase{"a", "a*a*", true}));