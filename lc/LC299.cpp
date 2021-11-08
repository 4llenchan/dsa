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
namespace lc299 {
/**
 * https://leetcode-cn.com/problems/bulls-and-cows/
 * 时间复杂度是2N，约为N；空间复杂度N
 */
class Solution1 {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> count;
        int n = (int)secret.size();
        int a_count = 0;
        int b_count = 0;
        for (char c : secret) {
            auto it = count.find(c);
            if (it == count.end()) {
                count[c] = 1;
            } else {
                it->second++;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (secret[i] == guess[i]) {
                a_count++;
                if (count[secret[i]] > 0) {
                    count[secret[i]]--;
                } else {
                    b_count--;
                }
            } else {
                auto it = count.find(guess[i]);
                if (it != count.end() && it->second > 0) {
                    it->second--;
                    b_count++;
                }
            }
        }
        return to_string(a_count) + "A" + to_string(b_count) + "B";
    }
};

/**
 * 时间复杂度是N+10，约等于N；空间复杂度是常数级；
 */
class Solution2 {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        int cows = 0;
        vector<int> a_count(10);
        vector<int> b_count(10);
        for (int i = 0; i < secret.length(); ++i) {
            if (secret[i] == guess[i]) {
                bulls++;
            } else {
                a_count[secret[i] - '0']++;
                b_count[guess[i] - '0']++;
            }
        }
        for (int i = 0; i < 10; ++i) {
            cows += min(a_count[i], b_count[i]);
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
} // namespace lc299

class LC299Tests : public ::testing::Test {
protected:
    lc299::Solution1 solution1;
    lc299::Solution2 solution2;
};

TEST_F(LC299Tests, case1) {
    string secret = "1807";
    string guess = "7810";
    string expect = "1A3B";
    auto result = solution1.getHint(secret, guess);
    auto result2 = solution2.getHint(secret, guess);
    EXPECT_EQ(expect, result);
    EXPECT_EQ(expect, result2);
}

TEST_F(LC299Tests, case2) {
    string secret = "1123";
    string guess = "0111";
    string expect = "1A1B";
    auto result = solution1.getHint(secret, guess);
    auto result2 = solution2.getHint(secret, guess);
    EXPECT_EQ(expect, result);
    EXPECT_EQ(expect, result2);
}

TEST_F(LC299Tests, case3) {
    string secret = "0001";
    string guess = "1111";
    string expect = "1A0B";
    auto result = solution1.getHint(secret, guess);
    auto result2 = solution2.getHint(secret, guess);
    EXPECT_EQ(expect, result);
    EXPECT_EQ(expect, result2);
}