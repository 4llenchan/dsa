#include <gtest/gtest.h>
#include <string>

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        int length = s.length();
        int count = std::count_if(s.begin(), s.end(), [](char c) { return c == ' '; });
        s.resize(length + 2 * count);
        for (int i = length - 1, j = s.size() - 1; i < j; i--, j--) {
            if (s[i] != ' ') {
                s[j] = s[i];
            } else {
                s[j] = '0';
                s[j - 1] = '2';
                s[j - 2] = '%';
                j -= 2;
            }
        }
        return s;
    }
};

class OF5Tests : public ::testing::Test {
protected:
    Solution solution;
};

TEST_F(OF5Tests, normal) {
    string s1 = "ab cd ef";
    auto result = solution.replaceSpace(s1);
    EXPECT_EQ(result, "ab%20cd%20ef");

    string s2 = " a  b ";
    result = solution.replaceSpace(s2);
    EXPECT_EQ(result, "%20a%20%20b%20");
}